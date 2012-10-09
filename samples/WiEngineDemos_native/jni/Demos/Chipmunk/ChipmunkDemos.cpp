#include "common.h"
#include "ChipmunkDemos.h"
#include "WiEngine.h"
#include "WiEngine-Chipmunk.h"
#include <math.h>
#include <time.h>
#include <stdio.h>

namespace Chipmunk {

#define GRABABLE_MASK_BIT (1<<31)
#define NOT_GRABABLE_MASK (~GRABABLE_MASK_BIT)

static cpSpace* space;
static cpBody* staticBody;
static cpConstraint *motor;

class wyChipmunkTestLayer: public wyColorLayer {
protected:
	wyChipmunk* chipmunk;

public:
	wyChipmunkTestLayer(wyColor4B color = wyc4bTransparent) :
		wyColorLayer(color) {
	}

	virtual ~wyChipmunkTestLayer() {
		chipmunk->release();
	}

	void onUpdateSpace(wyTargetSelector* ts) {
		updateSpace(ts->getDelta());
	}

	virtual void updateSpace(float delta) {
		cpSpaceStep(chipmunk->getSpace(), delta);
	}

	void startUpdateSpace() {
		wyTargetSelector* ts = wyTargetSelector::make(this, SEL(wyChipmunkTestLayer::onUpdateSpace));
		wyTimer* t = wyTimer::make(ts);
		scheduleLocked(t);
	}

	void createChipmunk() {
		chipmunk = new wyChipmunk();
		chipmunk->setDebugDraw(true);
		chipmunk->setPosition(wyDevice::winWidth / 2, wyDevice::winHeight / 2);
		addChildLocked(chipmunk);
	}

	static float frand() {
		return (float) rand() / RAND_MAX;
	}

	static float frand_unit() {
		return 2.0f * rand() / RAND_MAX - 1.0f;
	}
};
	
///////////////////////////////////////////////////////////////////////////////////////////////

	class wyBodyDraggingTestLayer: public wyChipmunkTestLayer {
	private:
		bool mDragging;
		cpBody* mBox;
		
	public:
		wyBodyDraggingTestLayer() {
			// screen size
			int w = wyDevice::winWidth;
			int h = wyDevice::winHeight;
			
			// add chipmunk node
			createChipmunk();
			chipmunk->setPosition(0, 0);
			chipmunk->setDebugDraw(false);
			
			// reset shape id count
			cpResetShapeIdCounter();
			
			// get space from chipmunk node
			cpSpace* space = chipmunk->getSpace();
			space->iterations = 10;
			space->gravity = cpv(0, -10);
			
			// add a static body, the cpSpaceAddStaticBody method
			// is added by WiEngine
			cpBody* staticBody = cpBodyNewStatic();
			
			// shape
			cpShape *shape;
			
			// Create segments around the edge of the screen.
			shape = cpSpaceAddStaticShape(space, cpSegmentShapeNew(staticBody, cpv(0, 0), cpv(0, h), 2.0f));
			shape->e = 1.0f;
			shape->u = 1.0f;
			shape->layers = NOT_GRABABLE_MASK;
			
			shape = cpSpaceAddStaticShape(space, cpSegmentShapeNew(staticBody, cpv(w, 0), cpv(w, h), 2.0f));
			shape->e = 1.0f;
			shape->u = 1.0f;
			shape->layers = NOT_GRABABLE_MASK;
			
			shape = cpSpaceAddStaticShape(space, cpSegmentShapeNew(staticBody, cpv(0, 0), cpv(w, 0), 2.0f));
			shape->e = 1.0f;
			shape->u = 1.0f;
			shape->layers = NOT_GRABABLE_MASK;
			
			shape = cpSpaceAddStaticShape(space, cpSegmentShapeNew(staticBody, cpv(0, h), cpv(w, h), 2.0f));
			shape->e = 1.0f;
			shape->u = 1.0f;
			shape->layers = NOT_GRABABLE_MASK;
			
			add_box();
			
			startUpdateSpace();
			setTouchEnabled(true);
		}
		
		virtual ~wyBodyDraggingTestLayer() {
		}
		
		void add_box() {
			// screen size
			int w = wyDevice::winWidth;
			int h = wyDevice::winHeight;
			
			const cpFloat size = DP(32.0f);
			const cpFloat mass = 1.0f;
			
			cpVect verts[] = { cpv(-size, -size), cpv(-size, size),
				cpv(size, size), cpv(size, -size) };
			
			cpSpace* space = chipmunk->getSpace();
			cpBody *body = cpSpaceAddBody(space, cpBodyNew(mass, cpMomentForPoly(
																				 mass, 4, verts, cpvzero)));
			body->p = cpv(w / 2, h / 2);
			body->v = cpvmult(cpv(2 * frand() - 1, 2 * frand() - 1), 200);
			
			cpShape *shape = cpSpaceAddShape(space, cpPolyShapeNew(body, 4, verts,
																   cpvzero));
			cpShapeSetTexture(shape, wyTexture2D::makePNG(RES("R.drawable.blocks")), false);
			shape->e = 1.0f;
			shape->u = 0.0f;
			
			mBox = body;
		}
		
		virtual bool touchesBegan(wyMotionEvent& event) {
			cpShape* shape = mBox->shapesList;
			wyRect rect = {
				shape->bb.l,
				shape->bb.b,
				shape->bb.r - shape->bb.l,
				shape->bb.t - shape->bb.b
			};
			if(wyrContains(rect, wyp(event.x[0], event.y[0]))) {
				mDragging = true;
			}
			return true;
		}
		
		virtual bool touchesMoved(wyMotionEvent& event) {
			if(mDragging) {
				mBox->p = cpv(event.x[0], event.y[0]);
			}
			
			return true;
		}
		
		virtual bool touchesEnded(wyMotionEvent& event) {
			mDragging = false;
			return true;
		}
		
		virtual bool touchesCancelled(wyMotionEvent& event) {
			mDragging = false;
			return true;
		}
	};
	
///////////////////////////////////////////////////////////////////////////////////////////////

	class wyBounceTestLayer: public wyChipmunkTestLayer {
	public:
		wyBounceTestLayer() {
			// screen size
			int w = wyDevice::winWidth;
			int h = wyDevice::winHeight;
			
			// add chipmunk node
			createChipmunk();
			
			// reset shape id count
			cpResetShapeIdCounter();
			
			// get space from chipmunk node
			space = chipmunk->getSpace();
			cpSpaceResizeActiveHash(space, 30.0f, 1000);
			space->iterations = 10;
			
			// add a static body, the cpSpaceAddStaticBody method
			// is added by WiEngine
			cpBody* staticBody = cpBodyNewStatic();
			
			// shape
			cpShape *shape;
			
			// Create segments around the edge of the screen.
			shape = cpSpaceAddStaticShape(space, cpSegmentShapeNew(staticBody, cpv(
																				   -w / 2, -h / 2), cpv(-w / 2, h / 2), 2.0f));
			shape->e = 1.0f;
			shape->u = 1.0f;
			shape->layers = NOT_GRABABLE_MASK;
			
			shape = cpSpaceAddStaticShape(space, cpSegmentShapeNew(staticBody, cpv(
																				   w / 2, -h / 2), cpv(w / 2, h / 2), 2.0f));
			shape->e = 1.0f;
			shape->u = 1.0f;
			shape->layers = NOT_GRABABLE_MASK;
			
			shape = cpSpaceAddStaticShape(space, cpSegmentShapeNew(staticBody, cpv(
																				   -w / 2, -h / 2), cpv(w / 2, -h / 2), 2.0f));
			shape->e = 1.0f;
			shape->u = 1.0f;
			shape->layers = NOT_GRABABLE_MASK;
			
			shape = cpSpaceAddStaticShape(space, cpSegmentShapeNew(staticBody, cpv(
																				   -w / 2, h / 2), cpv(w / 2, h / 2), 2.0f));
			shape->e = 1.0f;
			shape->u = 1.0f;
			shape->layers = NOT_GRABABLE_MASK;
			
			for (int i = 0; i < 10; i++)
				add_box();
			
			cpBody *body = cpSpaceAddBody(space, cpBodyNew(100.0f, 10000.0f));
			
			shape = cpSpaceAddShape(space, cpSegmentShapeNew(body, cpv(-75, 0),
															 cpv(75, 0), 5.0f));
			shape->e = 1.0f;
			shape->u = 1.0f;
			
			cpSpaceAddConstraint(space, cpPivotJointNew2(body, staticBody, cpvzero,
														 cpvzero));
			
			startUpdateSpace();
		}
		
		virtual ~wyBounceTestLayer() {
		}
		
		void add_box() {
			// screen size
			int w = wyDevice::winWidth;
			int h = wyDevice::winHeight;
			
			const cpFloat size = 10.0f;
			const cpFloat mass = 1.0f;
			
			cpVect verts[] = { cpv(-size, -size), cpv(-size, size),
				cpv(size, size), cpv(size, -size) };
			
			cpFloat radius = cpvlength(cpv(size, size));
			
			cpSpace* space = chipmunk->getSpace();
			cpBody *body = cpSpaceAddBody(space, cpBodyNew(mass, cpMomentForPoly(
																				 mass, 4, verts, cpvzero)));
			body->p = cpv(frand() * (w - 2 * radius) - (w / 2 - radius), frand()
						  * (h - 2 * radius) - (h / 2 - radius));
			body->v = cpvmult(cpv(2 * frand() - 1, 2 * frand() - 1), 200);
			
			cpShape *shape = cpSpaceAddShape(space, cpPolyShapeNew(body, 4, verts,
																   cpvzero));
			shape->e = 1.0f;
			shape->u = 0.0f;
		}
	};

///////////////////////////////////////////////////////////////////////////////////////////////
	
	class wyJointsTestLayer: public wyChipmunkTestLayer {
	public:
		wyJointsTestLayer() {
			// screen size
			int w = wyDevice::winWidth;
			int h = wyDevice::winHeight;
			
			// add chipmunk node
			createChipmunk();
			
			// get space from chipmunk node
			space = chipmunk->getSpace();
			cpSpaceResizeActiveHash(space, 30.0f, 1000);
			space->iterations = 10;
			space->gravity = cpv(0, -100);
			
			// add a static body, the cpSpaceAddStaticBody method
			// is added by WiEngine
			staticBody = cpBodyNewStatic();
			
			cpShape *shape;
			
			shape = cpSpaceAddStaticShape(space, cpSegmentShapeNew(staticBody, cpv(
																				   -w / 2, h / 2), cpv(w / 2, h / 2), 2.0f));
			shape->e = 1.0f;
			shape->u = 1.0f;
			shape->layers = NOT_GRABABLE_MASK;
			
			shape = cpSpaceAddStaticShape(space, cpSegmentShapeNew(staticBody, cpv(
																				   -w / 2, h / 4), cpv(w / 2, h / 4), 2.0f));
			shape->e = 1.0f;
			shape->u = 1.0f;
			shape->layers = NOT_GRABABLE_MASK;
			
			shape = cpSpaceAddStaticShape(space, cpSegmentShapeNew(staticBody, cpv(
																				   -w / 2, 0), cpv(w / 2, 0), 2.0f));
			shape->e = 1.0f;
			shape->u = 1.0f;
			shape->layers = NOT_GRABABLE_MASK;
			
			shape = cpSpaceAddStaticShape(space, cpSegmentShapeNew(staticBody, cpv(
																				   -w / 2, -h / 4), cpv(w / 2, -h / 4), 2.0f));
			shape->e = 1.0f;
			shape->u = 1.0f;
			shape->layers = NOT_GRABABLE_MASK;
			
			shape = cpSpaceAddStaticShape(space, cpSegmentShapeNew(staticBody, cpv(
																				   -w / 2, -h / 2), cpv(w / 2, -h / 2), 2.0f));
			shape->e = 1.0f;
			shape->u = 1.0f;
			shape->layers = NOT_GRABABLE_MASK;
			
			shape = cpSpaceAddStaticShape(space, cpSegmentShapeNew(staticBody, cpv(
																				   -w / 2, -h / 2), cpv(-w / 2, h / 2), 2.0f));
			shape->e = 1.0f;
			shape->u = 1.0f;
			shape->layers = NOT_GRABABLE_MASK;
			
			shape = cpSpaceAddStaticShape(space, cpSegmentShapeNew(staticBody, cpv(
																				   -w / 4, -h / 2), cpv(-w / 4, h / 2), 2.0f));
			shape->e = 1.0f;
			shape->u = 1.0f;
			shape->layers = NOT_GRABABLE_MASK;
			
			shape = cpSpaceAddStaticShape(space, cpSegmentShapeNew(staticBody, cpv(
																				   0, -h / 2), cpv(0, h / 2), 2.0f));
			shape->e = 1.0f;
			shape->u = 1.0f;
			shape->layers = NOT_GRABABLE_MASK;
			
			shape = cpSpaceAddStaticShape(space, cpSegmentShapeNew(staticBody, cpv(
																				   w / 4, -h / 2), cpv(w / 4, h / 2), 2.0f));
			shape->e = 1.0f;
			shape->u = 1.0f;
			shape->layers = NOT_GRABABLE_MASK;
			
			shape = cpSpaceAddStaticShape(space, cpSegmentShapeNew(staticBody, cpv(
																				   w / 2, -h / 2), cpv(w / 2, h / 2), 2.0f));
			shape->e = 1.0f;
			shape->u = 1.0f;
			shape->layers = NOT_GRABABLE_MASK;
			
			cpVect boxOffset;
			cpBody *body1, *body2;
			
			cpVect posA = cpv(50, 60);
			cpVect posB = cpv(110, 60);
			
#define POS_A cpvadd(boxOffset, posA)
#define POS_B cpvadd(boxOffset, posB)
			
			// Pin Joints - Link shapes with a solid bar or pin.
			// Keeps the anchor points the same distance apart from when the joint was created.
			boxOffset = cpv(-w / 2, -h / 2);
			body1 = addBall(posA, boxOffset);
			body2 = addBall(posB, boxOffset);
			cpSpaceAddConstraint(space, cpPinJointNew(body1, body2, cpv(15, 0),
													  cpv(-15, 0)));
			
			// Slide Joints - Like pin joints but with a min/max distance.
			// Can be used for a cheap approximation of a rope.
			boxOffset = cpv(-w / 4, -h / 2);
			body1 = addBall(posA, boxOffset);
			body2 = addBall(posB, boxOffset);
			cpSpaceAddConstraint(space, cpSlideJointNew(body1, body2, cpv(15, 0),
														cpv(-15, 0), 20.0f, 40.0f));
			
			// Pivot Joints - Holds the two anchor points together. Like a swivel.
			boxOffset = cpv(0, -h / 2);
			body1 = addBall(posA, boxOffset);
			body2 = addBall(posB, boxOffset);
			cpSpaceAddConstraint(space, cpPivotJointNew(body1, body2, cpvadd(
																			 boxOffset, cpv(80, 60))));
			// cpPivotJointNew() takes it's anchor parameter in world coordinates. The anchors are calculated from that
			// cpPivotJointNew2() lets you specify the two anchor points explicitly
			
			// Groove Joints - Like a pivot joint, but one of the anchors is a line segment that the pivot can slide in
			boxOffset = cpv(w / 4, -h / 2);
			body1 = addBall(posA, boxOffset);
			body2 = addBall(posB, boxOffset);
			cpSpaceAddConstraint(space, cpGrooveJointNew(body1, body2, cpv(30, 30),
														 cpv(30, -30), cpv(-30, 0)));
			
			// Damped Springs
			boxOffset = cpv(-w / 2, -h / 4);
			body1 = addBall(posA, boxOffset);
			body2 = addBall(posB, boxOffset);
			cpSpaceAddConstraint(space, cpDampedSpringNew(body1, body2, cpv(15, 0),
														  cpv(-15, 0), 20.0f, 5.0f, 0.3f));
			
			// Damped Rotary Springs
			boxOffset = cpv(-w / 4, -h / 4);
			body1 = addBar(posA, boxOffset);
			body2 = addBar(posB, boxOffset);
			// Add some pin joints to hold the circles in place.
			cpSpaceAddConstraint(space, cpPivotJointNew(body1, staticBody, POS_A));
			cpSpaceAddConstraint(space, cpPivotJointNew(body2, staticBody, POS_B));
			cpSpaceAddConstraint(space, cpDampedRotarySpringNew(body1, body2, 0.0f,
																3000.0f, 60.0f));
			
			// Rotary Limit Joint
			boxOffset = cpv(0, -h / 4);
			body1 = addLever(posA, boxOffset);
			body2 = addLever(posB, boxOffset);
			// Add some pin joints to hold the circles in place.
			cpSpaceAddConstraint(space, cpPivotJointNew(body1, staticBody, POS_A));
			cpSpaceAddConstraint(space, cpPivotJointNew(body2, staticBody, POS_B));
			// Hold their rotation within 90 degrees of each other.
			cpSpaceAddConstraint(space, cpRotaryLimitJointNew(body1, body2,
															  -(cpFloat) M_PI_2, (cpFloat) M_PI_2));
			
			// Ratchet Joint - A rotary ratchet, like a socket wrench
			boxOffset = cpv(w / 4, -h / 4);
			body1 = addLever(posA, boxOffset);
			body2 = addLever(posB, boxOffset);
			// Add some pin joints to hold the circles in place.
			cpSpaceAddConstraint(space, cpPivotJointNew(body1, staticBody, POS_A));
			cpSpaceAddConstraint(space, cpPivotJointNew(body2, staticBody, POS_B));
			// Ratchet every 90 degrees
			cpSpaceAddConstraint(space, cpRatchetJointNew(body1, body2, 0.0f,
														  (cpFloat) M_PI_2));
			
			// Gear Joint - Maintain a specific angular velocity ratio
			boxOffset = cpv(-w / 2, 0);
			body1 = addBar(posA, boxOffset);
			body2 = addBar(posB, boxOffset);
			// Add some pin joints to hold the circles in place.
			cpSpaceAddConstraint(space, cpPivotJointNew(body1, staticBody, POS_A));
			cpSpaceAddConstraint(space, cpPivotJointNew(body2, staticBody, POS_B));
			// Force one to sping 2x as fast as the other
			cpSpaceAddConstraint(space, cpGearJointNew(body1, body2, 0.0f, 2.0f));
			
			// Simple Motor - Maintain a specific angular relative velocity
			boxOffset = cpv(-w / 4, 0);
			body1 = addBar(posA, boxOffset);
			body2 = addBar(posB, boxOffset);
			// Add some pin joints to hold the circles in place.
			cpSpaceAddConstraint(space, cpPivotJointNew(body1, staticBody, POS_A));
			cpSpaceAddConstraint(space, cpPivotJointNew(body2, staticBody, POS_B));
			// Make them spin at 1/2 revolution per second in relation to each other.
			cpSpaceAddConstraint(space, cpSimpleMotorNew(body1, body2,
														 (cpFloat) M_PI));
			
			// Make a car with some nice soft suspension
			boxOffset = cpv(0, 0);
			cpBody *wheel1 = addWheel(posA, boxOffset);
			cpBody *wheel2 = addWheel(posB, boxOffset);
			cpBody *chassis = addChassis(cpv(80, 100), boxOffset);
			
			cpSpaceAddConstraint(space, cpGrooveJointNew(chassis, wheel1, cpv(-30,
																			  -10), cpv(-30, -40), cpvzero));
			cpSpaceAddConstraint(space, cpGrooveJointNew(chassis, wheel2, cpv(30,
																			  -10), cpv(30, -40), cpvzero));
			
			cpSpaceAddConstraint(space, cpDampedSpringNew(chassis, wheel1, cpv(-30,
																			   0), cpvzero, 50.0f, 20.0f, 1.5f));
			cpSpaceAddConstraint(space, cpDampedSpringNew(chassis, wheel2, cpv(30,
																			   0), cpvzero, 50.0f, 20.0f, 1.5f));
			
			startUpdateSpace();
		}
		
		virtual ~wyJointsTestLayer() {
		}
		
		static cpBody* addBall(cpVect pos, cpVect boxOffset) {
			cpFloat radius = 15.0f;
			cpFloat mass = 1.0f;
			cpBody *body = cpSpaceAddBody(space, cpBodyNew(mass, cpMomentForCircle(
																				   mass, 0.0f, radius, cpvzero)));
			body->p = cpvadd(pos, boxOffset);
			
			cpShape *shape = cpSpaceAddShape(space, cpCircleShapeNew(body, radius,
																	 cpvzero));
			shape->e = 0.0f;
			shape->u = 0.7f;
			
			return body;
		}
		
		static cpBody*	addLever(cpVect pos, cpVect boxOffset) {
			cpFloat mass = 1.0f;
			cpVect a = cpv(0, 15);
			cpVect b = cpv(0, -15);
			
			cpBody *body = cpSpaceAddBody(space, cpBodyNew(mass,
														   cpMomentForSegment(mass, a, b)));
			body->p = cpvadd(pos, cpvadd(boxOffset, cpv(0, -15)));
			
			cpShape *shape = cpSpaceAddShape(space, cpSegmentShapeNew(body, a, b,
																	  5.0f));
			shape->e = 0.0f;
			shape->u = 0.7f;
			
			return body;
		}
		
		static cpBody*	addBar(cpVect pos, cpVect boxOffset) {
			cpFloat mass = 2.0f;
			cpVect a = cpv(0, 30);
			cpVect b = cpv(0, -30);
			
			cpBody *body = cpSpaceAddBody(space, cpBodyNew(mass,
														   cpMomentForSegment(mass, a, b)));
			body->p = cpvadd(pos, boxOffset);
			
			cpShape *shape = cpSpaceAddShape(space, cpSegmentShapeNew(body, a, b,
																	  5.0f));
			shape->e = 0.0f;
			shape->u = 0.7f;
			
			return body;
		}
		
		static cpBody*	addWheel(cpVect pos, cpVect boxOffset) {
			cpFloat radius = 15.0f;
			cpFloat mass = 1.0f;
			cpBody *body = cpSpaceAddBody(space, cpBodyNew(mass, cpMomentForCircle(
																				   mass, 0.0f, radius, cpvzero)));
			body->p = cpvadd(pos, boxOffset);
			
			cpShape *shape = cpSpaceAddShape(space, cpCircleShapeNew(body, radius,
																	 cpvzero));
			shape->e = 0.0f;
			shape->u = 0.7f;
			shape->group = 1; // use a group to keep the car parts from colliding
			
			return body;
		}
		
		static cpBody*	addChassis(cpVect pos, cpVect boxOffset) {
			int num = 4;
			cpVect verts[] = { cpv(-40, -15), cpv(-40, 15), cpv(40, 15), cpv(40,
																			 -15), };
			
			cpFloat mass = 5.0f;
			cpBody *body = cpSpaceAddBody(space, cpBodyNew(mass, cpMomentForPoly(
																				 mass, num, verts, cpvzero)));
			body->p = cpvadd(pos, boxOffset);
			
			cpShape *shape = cpSpaceAddShape(space, cpPolyShapeNew(body, num,
																   verts, cpvzero));
			shape->e = 0.0f;
			shape->u = 0.7f;
			shape->group = 1; // use a group to keep the car parts from colliding
			
			return body;
		}
	};
	
///////////////////////////////////////////////////////////////////////////////////////////////
	
	static const int image_width = 188;
	static const int image_height = 35;
	static const int image_row_length = 24;
	
	static const unsigned char image_bitmap[] = {
		15,-16,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,-64,15,63,-32,-2,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,31,-64,15,127,-125,-1,-128,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,127,-64,15,127,15,-1,-64,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,-1,-64,15,-2,
		31,-1,-64,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,-1,-64,0,-4,63,-1,-32,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,1,-1,-64,15,-8,127,-1,-32,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		1,-1,-64,0,-8,-15,-1,-32,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,-31,-1,-64,15,-8,-32,
		-1,-32,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,-15,-1,-64,9,-15,-32,-1,-32,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,31,-15,-1,-64,0,-15,-32,-1,-32,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,63,-7,-1,-64,9,-29,-32,127,-61,-16,63,15,-61,-1,-8,31,-16,15,-8,126,7,-31,
		-8,31,-65,-7,-1,-64,9,-29,-32,0,7,-8,127,-97,-25,-1,-2,63,-8,31,-4,-1,15,-13,
		-4,63,-1,-3,-1,-64,9,-29,-32,0,7,-8,127,-97,-25,-1,-2,63,-8,31,-4,-1,15,-13,
		-2,63,-1,-3,-1,-64,9,-29,-32,0,7,-8,127,-97,-25,-1,-1,63,-4,63,-4,-1,15,-13,
		-2,63,-33,-1,-1,-32,9,-25,-32,0,7,-8,127,-97,-25,-1,-1,63,-4,63,-4,-1,15,-13,
		-1,63,-33,-1,-1,-16,9,-25,-32,0,7,-8,127,-97,-25,-1,-1,63,-4,63,-4,-1,15,-13,
		-1,63,-49,-1,-1,-8,9,-57,-32,0,7,-8,127,-97,-25,-8,-1,63,-2,127,-4,-1,15,-13,
		-1,-65,-49,-1,-1,-4,9,-57,-32,0,7,-8,127,-97,-25,-8,-1,63,-2,127,-4,-1,15,-13,
		-1,-65,-57,-1,-1,-2,9,-57,-32,0,7,-8,127,-97,-25,-8,-1,63,-2,127,-4,-1,15,-13,
		-1,-1,-57,-1,-1,-1,9,-57,-32,0,7,-1,-1,-97,-25,-8,-1,63,-1,-1,-4,-1,15,-13,-1,
		-1,-61,-1,-1,-1,-119,-57,-32,0,7,-1,-1,-97,-25,-8,-1,63,-1,-1,-4,-1,15,-13,-1,
		-1,-61,-1,-1,-1,-55,-49,-32,0,7,-1,-1,-97,-25,-8,-1,63,-1,-1,-4,-1,15,-13,-1,
		-1,-63,-1,-1,-1,-23,-49,-32,127,-57,-1,-1,-97,-25,-1,-1,63,-1,-1,-4,-1,15,-13,
		-1,-1,-63,-1,-1,-1,-16,-49,-32,-1,-25,-1,-1,-97,-25,-1,-1,63,-33,-5,-4,-1,15,
		-13,-1,-1,-64,-1,-9,-1,-7,-49,-32,-1,-25,-8,127,-97,-25,-1,-1,63,-33,-5,-4,-1,
		15,-13,-1,-1,-64,-1,-13,-1,-32,-49,-32,-1,-25,-8,127,-97,-25,-1,-2,63,-49,-13,
		-4,-1,15,-13,-1,-1,-64,127,-7,-1,-119,-17,-15,-1,-25,-8,127,-97,-25,-1,-2,63,
		-49,-13,-4,-1,15,-13,-3,-1,-64,127,-8,-2,15,-17,-1,-1,-25,-8,127,-97,-25,-1,
		-8,63,-49,-13,-4,-1,15,-13,-3,-1,-64,63,-4,120,0,-17,-1,-1,-25,-8,127,-97,-25,
		-8,0,63,-57,-29,-4,-1,15,-13,-4,-1,-64,63,-4,0,15,-17,-1,-1,-25,-8,127,-97,
		-25,-8,0,63,-57,-29,-4,-1,-1,-13,-4,-1,-64,31,-2,0,0,103,-1,-1,-57,-8,127,-97,
		-25,-8,0,63,-57,-29,-4,-1,-1,-13,-4,127,-64,31,-2,0,15,103,-1,-1,-57,-8,127,
		-97,-25,-8,0,63,-61,-61,-4,127,-1,-29,-4,127,-64,15,-8,0,0,55,-1,-1,-121,-8,
		127,-97,-25,-8,0,63,-61,-61,-4,127,-1,-29,-4,63,-64,15,-32,0,0,23,-1,-2,3,-16,
		63,15,-61,-16,0,31,-127,-127,-8,31,-1,-127,-8,31,-128,7,-128,0,0
	};
	
	class wyLogoSmashTestLayer: public wyChipmunkTestLayer {
	public:
		wyLogoSmashTestLayer() {
			// add chipmunk node
			createChipmunk();
			
			space = chipmunk->getSpace();
			cpSpaceResizeActiveHash(space, 2.0f, 10000);
			space->iterations = 1;
			
			cpBody *body;
			cpShape *shape;
			
			for (int y = 0; y < image_height; y++) {
				for (int x = 0; x < image_width; x++) {
					if (!get_pixel(x, y))
						continue;
					
					cpFloat x_jitter = 0.05f * frand();
					cpFloat y_jitter = 0.05f * frand();
					
					shape = make_ball(2 * (x - image_width / 2 + x_jitter), 2
									  * (image_height / 2 - y + y_jitter));
					cpSpaceAddBody(space, shape->body);
					cpSpaceAddShape(space, shape);
				}
			}
			
			body = cpSpaceAddBody(space, cpBodyNew(INFINITY, INFINITY));
			body->p = cpv(-1000.0f, -10.0f);
			body->v = cpv(400.0f, 0.0f);
			
			shape = cpSpaceAddShape(space, cpCircleShapeNew(body, 8.0f, cpvzero));
			shape->e = 0.0f;
			shape->u = 0.0f;
			shape->layers = NOT_GRABABLE_MASK;
			
			startUpdateSpace();
		}
		
		virtual ~wyLogoSmashTestLayer() {
		}
		
		static inline int get_pixel(int x, int y) {
			return (image_bitmap[(x >> 3) + y * image_row_length] >> (~x & 0x7))
			& 1;
		}
		
		virtual void updateSpace(float delta) {
			int steps = 1;
			cpFloat dt = 1.0f / 60.0f / (cpFloat) steps;
			
			for (int i = 0; i < steps; i++) {
				cpSpaceStep(space, dt);
			}
		}
		
		static cpShape *
		make_ball(cpFloat x, cpFloat y) {
			cpBody *body = cpBodyNew(1.0f, INFINITY);
			body->p = cpv(x, y);
			
			cpShape *shape = cpCircleShapeNew(body, 0.95f, cpvzero);
			shape->e = 0.0f;
			shape->u = 0.0f;
			
			return shape;
		}
	};
	
///////////////////////////////////////////////////////////////////////////////////////////////
	
	#define SINGMAX 10 // Maximum number of singularities per body
	#define NMAG 10 // Number of magnets
	#define NCHG 10 // Number of charged bodies
	#define NMIX 10 // Number of charged magnets
	#define COU_MKS  8.987551787e9 // Some physical constants
	#define MAG_MKS 1e-7
	
	// Prototypes
	struct DataforForce;
	typedef void (*SingForceFunc)(struct DataforForce* data);
	
	// Structures
	// Singularities
	typedef struct ActorSingularity {
		// Number of singularities
		int Nsing;
		// Value of the singularities
		cpFloat value[SINGMAX];
		// Type of the singularities
		char type[SINGMAX][100];
		// Global position of the singularities
		cpVect Gpos[SINGMAX];
		// Local position of the singularities
		cpVect position[SINGMAX];
		// Angle of the singularities measured in the body axes
		cpFloat angle[SINGMAX];
		// Angle of the singularities measured from x
		cpFloat Gangle[SINGMAX];
		// Force function
		SingForceFunc force_func[SINGMAX];
		// Force function
		SingForceFunc torque_func[SINGMAX];
	} Sing;
	
	// Data for the force functions
	typedef struct DataforForce {
		//Everything in global coordinates
		// Position of the source
		cpVect p0;
		// Observed position
		cpVect p;
		// Relative position source-observed
		cpVect relp;
		// distance, disntace^2, ditance ^3
		cpFloat r[3];
		// angle of the source
		cpFloat ang0;
		// angle of the observed singularity
		cpFloat ang;
		// Foce value
		cpVect F;
		// Torque value
		cpFloat T;
	} ForceData;
	
	class wyMagnetsElectricTestLayer: public wyChipmunkTestLayer {
	public:
		wyMagnetsElectricTestLayer() {
			// screen size
			int w = wyDevice::winWidth;
			int h = wyDevice::winHeight;
			
			// add chipmunk node
			createChipmunk();
			chipmunk->setPosition(0, 0);
			
			cpResetShapeIdCounter();
			space = chipmunk->getSpace();
			space->iterations = 5;
			cpSpaceResizeActiveHash(space, 30, 2999);
			
			// add a static body, the cpSpaceAddStaticBody method
			// is added by WiEngine
			staticBody = cpBodyNewStatic();
			
			srand(time(NULL));
			cpVect p;
			cpFloat ang;
			
			// Create magnets
			for (int i = 0; i < NMAG; i++) {
				p.x = frand() * w;
				p.y = frand() * h;
				ang = frand() * 3.1415f;
				make_mag(p, ang, (cpFloat) 1.0e7);
			}
			
			// Create charged objects
			for (int i = 0; i < NCHG; i++) {
				p.x = frand() * w;
				p.y = frand() * h;
				ang = frand() * 3.1415f;
				make_charged(p, (cpFloat) 1.0e-3 * cpfpow((double)-1, i % 2));
			}
			
			// Create charged magnets objects
			for (int i = 0; i < NMIX; i++) {
				p.x = frand() * w;
				p.y = frand() * h;
				ang = frand() * 3.1415f;
				make_mix(p, ang, (cpFloat) 1.0e7 * cpfpow((double)-1, i % 2),
						 (cpFloat) 1.0e-3 * cpfpow((double)-1, i % 2));
			}
			
			startUpdateSpace();
		}
		
		virtual ~wyMagnetsElectricTestLayer() {
		}
		
		// **** Forces ****** //
		// Calculate the forces between two bodies. all this functions requieres
		// a pointer to an structure with the necessary fields.
		
		// forces between charges
		static void CoulombForce(ForceData* data) {
			data->F = cpvmult(cpvnormalize(data->relp), (cpFloat) COU_MKS
							  / data->r[1]);
		}
		
		// forces between magnets
		static void MagDipoleForce(ForceData* data) {
			static cpFloat phi, alpha, beta, Fr, Fphi;
			
			// Angle of the relative position vector
			phi = cpvtoangle(data->relp);
			alpha = data->ang0;
			beta = data->ang;
			
			alpha = phi - alpha;
			beta = phi - beta;
			
			// Components in polar coordinates
			Fr = ((cpFloat) 2.0e0 * cpfcos(alpha) * cpfcos(beta) - cpfsin(alpha)
				  * cpfsin(beta));
			Fphi = cpfsin(alpha + beta);
			//	printf("%g %g %g %g %g\n",phi,alpha,beta,Fphi);
			
			// Cartesian coordinates
			data->F = cpv(Fr * cpfcos(phi) - Fphi * cpfsin(phi), Fr * cpfsin(phi)
						  + Fphi * cpfcos(phi));
			data->F = cpvmult(data->F, (cpFloat) - 3.e0 * (cpFloat) MAG_MKS
							  / (data->r[1] * data->r[1]));
		}
		
		static void MagDipoleTorque(ForceData* data) {
			static cpFloat phi, alpha, beta;
			
			phi = cpvtoangle(data->relp);
			alpha = data->ang0;
			beta = data->ang;
			alpha = phi - alpha;
			beta = phi - beta;
			
			// Torque. Though we could use a component of F to save some space,
			// we use another variables for the sake of clarity.
			
			data->T = ((cpFloat) MAG_MKS / data->r[2]) * ((cpFloat) 3.0e0 * cpfcos(
																				   alpha) * cpfsin(beta) + cpfsin(alpha - beta));
		}
		
		// This function fills the data structure for the force functions
		// The structure Sing has the information about the singularity (charge or magnet)
		static void FillForceData(Sing* source, int inds, Sing* obs, int indo,
								  ForceData* data) {
			// Global Position and orientation of the source singularity
			data->p0 = source->Gpos[inds];
			data->ang0 = source->Gangle[inds];
			
			// Global Position and orientation of the observed singularity
			data->p = obs->Gpos[indo];
			data->ang = obs->Gangle[indo];
			
			// Derived magnitudes
			data->relp = cpvsub(data->p, data->p0); //Relative position
			data->r[0] = cpvlength(data->relp); // Distance
			data->r[1] = cpvlengthsq(data->relp); // Square Distance
			data->r[2] = data->r[0] * data->r[1]; // Cubic distance
			
			source->force_func[inds](data); // The value of the force
			data->F = cpvmult(data->F, source->value[inds] * obs->value[indo]);
		}
		
		// Calculation of the interaction
		static void LRangeForceApply(cpBody *a, cpBody *b) {
			Sing* aux = (Sing*) a->data;
			Sing* aux2 = (Sing*) b->data;
			cpVect delta;
			// General data needed to calculate interaction
			static ForceData fdata;
			fdata.F = cpvzero;
			
			// Calculate the forces between the charges of different bodies
			for (int i = 0; i < aux->Nsing; i++) {
				for (int j = 0; j < aux2->Nsing; j++) {
					if (!strcmp(aux->type[i], aux2->type[j])) {
						//printf("%s %s\n",aux->type[i],aux2->type[j]);
						FillForceData(aux2, j, aux, i, &fdata);
						
						//Force applied to body A
						delta = cpvsub(aux->Gpos[i], a->p);
						cpBodyApplyForce(a, fdata.F, delta);
						
						if (aux->torque_func[i] != NULL) {
							//Torque on A
							aux->torque_func[i](&fdata);
							a->t += aux->value[i] * aux2->value[j] * fdata.T;
						}
					}
				}
			}
		}
		
		// function for the integration of the positions
		// The following functions are variations to the starndrd integration in Chipmunk
		// you can go ack to the standard ones by doing the appropiate changes.
		static void ChargedBodyUpdatePositionVerlet(cpBody *body, cpFloat dt) {
			// Long range interaction
			cpArray *bodies = space->bodies;
			static cpBody* B;
			Sing* aux = (Sing*) body->data;
			Sing* aux2;
			
			// General data needed to calculate interaction
			static ForceData fdata;
			fdata.F = cpvzero;
			
			for (int i = 0; i < bodies->num; i++) {
				B = (cpBody*) bodies->arr[i];
				aux2 = (Sing*) B->data;
				
				if (B != body) {
					// Calculate the forces between the singularities of different bodies
					LRangeForceApply(body, B);
				}
			}
			
			cpVect dp = cpvmult(cpvadd(body->v, body->v_bias), dt);
			dp = cpvadd(dp, cpvmult(cpvmult(body->f, body->m_inv), (cpFloat) 0.5e0
									* dt * dt));
			body->p = cpvadd(body->p, dp);
			
			cpBodySetAngle(body, body->a + (body->w + body->w_bias) * dt + 0.5f
						   * body->t * body->i_inv * dt * dt);
			
			// Update position of the singularities
			aux = (Sing*) body->data;
			for (int i = 0; i < aux->Nsing; i++) {
				aux->Gpos[i] = cpvadd(body->p, cpvrotate(cpv(aux->position[i].x,
															 aux->position[i].y), body->rot));
				aux->Gangle[i] = aux->angle[i] + body->a;
			}
			
			body->v_bias = cpvzero;
			body->w_bias = 0.0f;
		}
		
		// function for the integration of the velocities
		static void ChargedBodyUpdateVelocityVerlet(cpBody *body, cpVect gravity,
													cpFloat damping, cpFloat dt) {
			body->v = cpvadd(body->v, cpvmult(cpvadd(gravity, cpvmult(body->f,
																	  body->m_inv)), (cpFloat) 0.5e0 * dt));
			body->w = body->w + body->t * body->i_inv * (cpFloat) 0.5e0 * dt;
			
			body->f = cpvzero;
			body->t = 0;
			
			// Long range interaction
			cpArray *bodies = space->bodies;
			static cpBody* B;
			
			// General data needed to calculate interaction
			static ForceData fdata;
			fdata.F = cpvzero;
			
			for (int i = 0; i < bodies->num; i++) {
				B = (cpBody*) bodies->arr[i];
				
				if (B != body) {
					// Calculate the forces between the singularities of different bodies
					LRangeForceApply(body, B);
				}
			}
			body->v = cpvadd(cpvmult(body->v, damping), cpvmult(cpvadd(gravity,
																	   cpvmult(body->f, body->m_inv)), (cpFloat) 0.5e0 * dt));
			body->w = body->w * damping + body->t * body->i_inv * (cpFloat) 0.5e0
			* dt;
		}
		
		virtual void updateSpace(float delta) {
			cpArray *bodies = space->bodies;
			
			for (int i = 0; i < bodies->num; i++)
				cpBodyResetForces((cpBody*) bodies->arr[i]);
			
			cpSpaceStep(chipmunk->getSpace(), delta);
		}
		
		static void make_mag(cpVect p, cpFloat ang, cpFloat mag) {
			int nverts = 6;
			cpVect verts[] = { cpv(-10, -10), cpv(-10, 10), cpv(10, 10),
				cpv(15, 5), cpv(15, -5), cpv(10, -10) };
			
			cpBody *body = cpBodyNew(1, cpMomentForPoly(1, nverts, verts, cpvzero));
			body->p = p;
			body->v = cpvzero;
			cpBodySetAngle(body, ang);
			body->w = 0;
			
			// Load the singularities
			Sing *magnet = (Sing*) cpmalloc(sizeof(Sing));
			magnet->Nsing = 1;
			magnet->value[0] = mag;
			sprintf(magnet->type[0], "magdipole");
			
			// The position and angle could be different form the one of the body
			magnet->position[0] = cpvzero;
			magnet->Gpos[0] = cpvadd(p, magnet->position[0]);
			magnet->angle[0] = 0.0f;
			magnet->Gangle[0] = ang;
			
			magnet->force_func[0] = MagDipoleForce;
			magnet->torque_func[0] = MagDipoleTorque;
			
			body->data = magnet;
			
			body->position_func = ChargedBodyUpdatePositionVerlet;
			body->velocity_func = ChargedBodyUpdateVelocityVerlet;
			cpSpaceAddBody(space, body);
			
			cpShape *shape = cpPolyShapeNew(body, nverts, verts, cpvzero);
			shape->e = 0;
			shape->u = 0.7f;
			cpSpaceAddShape(space, shape);
		}
		
		static void make_charged(cpVect p, cpFloat chg) {
			int nverts = 4;
			cpVect verts[] = { cpv(-10, -10), cpv(-10, 10), cpv(10, 10), cpv(10,
																			 -10) };
			
			cpBody *body = cpBodyNew(1, cpMomentForPoly(1, nverts, verts, cpvzero));
			body->p = p;
			body->v = cpvzero;
			cpBodySetAngle(body, 0);
			body->w = 0;
			
			// Load the singularities
			Sing *charge = (Sing*) cpmalloc(sizeof(Sing));
			;
			charge->Nsing = 1;
			charge->value[0] = chg;
			sprintf(charge->type[0], "electrical");
			
			// The position and angle could be different form the one of the body
			charge->position[0] = cpvzero;
			charge->Gpos[0] = cpvadd(p, charge->position[0]);
			charge->Gangle[0] = 0;
			
			charge->force_func[0] = CoulombForce;
			charge->torque_func[0] = NULL;
			
			body->data = charge;
			
			body->position_func = ChargedBodyUpdatePositionVerlet;
			body->velocity_func = ChargedBodyUpdateVelocityVerlet;
			cpSpaceAddBody(space, body);
			
			cpShape *shape = cpPolyShapeNew(body, nverts, verts, cpvzero);
			shape->e = 0;
			shape->u = 0.7f;
			cpSpaceAddShape(space, shape);
		}
		
		static void make_mix(cpVect p, cpFloat ang, cpFloat mag, cpFloat chg) {
			int nverts = 5;
			cpVect verts[] = { cpv(-10, -10), cpv(-10, 10), cpv(10, 10),
				cpv(20, 0), cpv(10, -10) };
			
			cpBody *body = cpBodyNew(1, cpMomentForPoly(1, nverts, verts, cpvzero));
			body->p = p;
			body->v = cpvzero;
			cpBodySetAngle(body, ang);
			body->w = 0;
			
			// Load the singularities
			Sing *mix = (Sing*) cpmalloc(sizeof(Sing));
			;
			mix->Nsing = 2;
			mix->value[0] = mag;
			mix->value[1] = chg;
			sprintf(mix->type[0], "magdipole");
			sprintf(mix->type[1], "electrical");
			
			// The position and angle could be different form the one of the body
			mix->position[0] = cpvzero;
			mix->Gpos[0] = cpvadd(p, mix->position[0]);
			mix->position[1] = cpvzero;
			mix->Gpos[1] = cpvadd(p, mix->position[1]);
			mix->Gangle[0] = ang;
			mix->Gangle[1] = ang;
			
			mix->force_func[0] = MagDipoleForce;
			mix->force_func[1] = CoulombForce;
			mix->torque_func[0] = MagDipoleTorque;
			mix->torque_func[1] = NULL;
			
			body->data = mix;
			
			body->position_func = ChargedBodyUpdatePositionVerlet;
			body->velocity_func = ChargedBodyUpdateVelocityVerlet;
			cpSpaceAddBody(space, body);
			
			cpShape *shape = cpPolyShapeNew(body, nverts, verts, cpvzero);
			shape->e = 0;
			shape->u = 0.7f;
			cpSpaceAddShape(space, shape);
		}
	};

///////////////////////////////////////////////////////////////////////////////////////////////
	
    typedef struct OneWayPlatform {
		cpVect n; // direction objects may pass through
		cpArray *passThruList; // list of objects passing through
	} OneWayPlatform;
	static OneWayPlatform platformInstance;
	
	class wyOneWayTestLayer: public wyChipmunkTestLayer {
	public:
		wyOneWayTestLayer() {
			// screen size
			int w = wyDevice::winWidth;
			int h = wyDevice::winHeight;
			
			// add chipmunk node
			createChipmunk();
			
			// reset shape id count
			cpResetShapeIdCounter();
			
			// get space from chipmunk node
			cpSpace* space = chipmunk->getSpace();
			space->iterations = 10;
			space->gravity = cpv(0, -100);
			
			// add a static body, the cpSpaceAddStaticBody method
			// is added by WiEngine
			staticBody = cpBodyNewStatic();
			
			cpBody *body;
			cpShape *shape;
			
			// Create segments around the edge of the screen.
			shape = cpSpaceAddStaticShape(space, cpSegmentShapeNew(staticBody, cpv(
																				   -w / 2, -h / 2), cpv(-w / 2, h / 2), 2.0f));
			shape->e = 1.0f;
			shape->u = 1.0f;
			shape->layers = NOT_GRABABLE_MASK;
			
			shape = cpSpaceAddStaticShape(space, cpSegmentShapeNew(staticBody, cpv(
																				   w / 2, -h / 2), cpv(w / 2, h / 2), 2.0f));
			shape->e = 1.0f;
			shape->u = 1.0f;
			shape->layers = NOT_GRABABLE_MASK;
			
			shape = cpSpaceAddStaticShape(space, cpSegmentShapeNew(staticBody, cpv(
																				   -w / 2, -h / 2), cpv(w / 2, -h / 2), 2.0f));
			shape->e = 1.0f;
			shape->u = 1.0f;
			shape->layers = NOT_GRABABLE_MASK;
			
			// Add our one way segment
			shape = cpSpaceAddStaticShape(space, cpSegmentShapeNew(staticBody, cpv(
																				   -w / 2 + 60, -100), cpv(w / 2 - 60, -100), 10.0f));
			shape->e = 1.0f;
			shape->u = 1.0f;
			shape->collision_type = 1;
			shape->layers = NOT_GRABABLE_MASK;
			
			// We'll use the data pointer for the OneWayPlatform struct
			platformInstance.n = cpv(0, 1); // let objects pass upwards
			platformInstance.passThruList = cpArrayNew(0);
			shape->data = &platformInstance;
			
			// Add a ball to make things more interesting
			cpFloat radius = 15.0f;
			body = cpSpaceAddBody(space, cpBodyNew(10.0f, cpMomentForCircle(10.0f,
																			0.0f, radius, cpvzero)));
			body->p = cpv(0, -200);
			body->v = cpv(0, 170);
			
			shape = cpSpaceAddShape(space, cpCircleShapeNew(body, radius, cpvzero));
			shape->e = 0.0f;
			shape->u = 0.9f;
			shape->collision_type = 2;
			
			cpSpaceAddCollisionHandler(space, 1, 2, NULL, preSolve, NULL, separate,
									   NULL);
			
			startUpdateSpace();
		}
		
		virtual ~wyOneWayTestLayer() {
		}
		
		static int preSolve(cpArbiter *arb, cpSpace *space, void *ignore) {
			CP_ARBITER_GET_SHAPES(arb, a, b);
			OneWayPlatform *platform = (OneWayPlatform*)a->data;
			
			if (cpArrayContains(platform->passThruList, b)) {
				// The object is in the pass thru list, ignore it until separates.
				return 0;
			} else {
				cpFloat dot = cpvdot(cpArbiterGetNormal(arb, 0), platform->n);
				
				if (dot < 0) {
					// Add the object to the pass thrru list
					cpArrayPush(platform->passThruList, b);
					return 0;
				} else {
					return 1;
				}
			}
		}
		
		static void separate(cpArbiter *arb, cpSpace *space, void *ignore) {
			CP_ARBITER_GET_SHAPES(arb, a, b);
			
			// remove the object from the pass thru list
			cpArrayDeleteObj(((OneWayPlatform *) a->data)->passThruList, b);
		}
	};

///////////////////////////////////////////////////////////////////////////////////////////////
	
	class wyPhysicsEditorTestLayer : public wyChipmunkTestLayer {
	private:
		wyChipmunk* m_chipmunk;
		wyChipmunkPELoader* m_bodyLoader;
		
		wyArray* m_arrayBodies;
		
	public:
		wyPhysicsEditorTestLayer() {
			// screen size
			int w = wyDevice::winWidth;
			int h = wyDevice::winHeight;
			
			m_arrayBodies = wyArrayNew(20);	         
			
			setTouchEnabled(true);
			createChipmunk();    
			m_chipmunk = chipmunk;
			chipmunk->setDebugDraw(false);
			
			cpSpace* space = m_chipmunk->getSpace();
			cpSpaceResizeStaticHash(space, 400.0f, 40);
			cpSpaceResizeActiveHash(space, 100, 600);
			space->gravity = cpv(0.0, -100.0f);
			space->iterations = 10;
			space->elasticIterations = space->iterations;
			
			m_bodyLoader = new wyChipmunkPELoader(RES("R.raw.shapedefs_chipmunk"));
			
			cpBody* staticBody = cpBodyNewStatic();
			
			// Create A ground segment along the bottom of the screen
			cpShape *ground = cpSegmentShapeNew(staticBody, cpv(-w / 2, -h / 2), cpv(w / 2, -h / 2), 2.0f);
			ground->e = 1.0f; ground->u = 1.0f;
			cpSpaceAddStaticShape(space, ground);
			startUpdateSpace();
			
			wyToast::make("touch to add body", 3.0f)->show();
		}
		
		virtual ~wyPhysicsEditorTestLayer() {
			wyArrayDestroy(m_arrayBodies);
			wyObjectRelease(m_bodyLoader);
		}
		
		virtual bool touchesBegan(wyMotionEvent& e) {	
			int randNum = rand() % 7;
			float radian = wyMath::d2r(wyMath::randMinusOneToOne() * 360);
			
			cpBody* body = NULL;
			wySprite* sprite = NULL;
			wyPoint anchorPercent;
			switch(randNum) {
				case 0:
					body = m_bodyLoader->createBodyByName(m_chipmunk, "drink");
					sprite = wySprite::make(wyTexture2D::makePNG(wyUtils::getResId("drink", "drawable", NULL)));
					anchorPercent = m_bodyLoader->getAnchorPercent("drink");
					break;
				case 1:
					body = m_bodyLoader->createBodyByName(m_chipmunk, "hamburger");
					sprite = wySprite::make(wyTexture2D::makePNG(wyUtils::getResId("hamburger", "drawable", NULL)));
					anchorPercent = m_bodyLoader->getAnchorPercent("hamburger");
					break;            
				case 2:
					body = m_bodyLoader->createBodyByName(m_chipmunk, "hotdog");
					sprite = wySprite::make(wyTexture2D::makePNG(wyUtils::getResId("hotdog", "drawable", NULL)));
					anchorPercent = m_bodyLoader->getAnchorPercent("hotdog");
					break;
				case 3:
					body = m_bodyLoader->createBodyByName(m_chipmunk, "icecream");
					sprite = wySprite::make(wyTexture2D::makePNG(wyUtils::getResId("icecream", "drawable", NULL)));
					anchorPercent = m_bodyLoader->getAnchorPercent("icecream");
					break;            
				case 4:
					body = m_bodyLoader->createBodyByName(m_chipmunk, "icecream2");
					sprite = wySprite::make(wyTexture2D::makePNG(wyUtils::getResId("icecream2", "drawable", NULL)));
					anchorPercent = m_bodyLoader->getAnchorPercent("icecream2");
					break;
				case 5:
					body = m_bodyLoader->createBodyByName(m_chipmunk, "icecream3");
					sprite = wySprite::make(wyTexture2D::makePNG(wyUtils::getResId("icecream3", "drawable", NULL)));
					anchorPercent = m_bodyLoader->getAnchorPercent("icecream3");
					break;
				case 6:
					body = m_bodyLoader->createBodyByName(m_chipmunk, "orange");
					sprite = wySprite::make(wyTexture2D::makePNG(wyUtils::getResId("orange", "drawable", NULL)));
					anchorPercent = m_bodyLoader->getAnchorPercent("orange");
					break;
			} 
			
			cpBodySetPos(body, cpv(e.x[0] - m_chipmunk->getPositionX(), e.y[0] - m_chipmunk->getPositionY()));
			cpBodySetAngle(body, radian);
			
			sprite->setAnchor(anchorPercent.x, anchorPercent.y);
			m_chipmunk->addChildLocked(sprite);
			sprite->setVisible(false);
			body->data = sprite;
			
			wyArrayPush(m_arrayBodies, body); 
			return true;
		}
		
		virtual void updateSpace(float delta) {
			wyChipmunkTestLayer::updateSpace(delta);
			
			for(int i = 0; i < m_arrayBodies->num; ++i) {
				cpBody* body = (cpBody*)m_arrayBodies->arr[i];
				wySprite* sprite = (wySprite*)body->data;
				if(body) {
					//update sprite
					if(sprite) {
						sprite->setPosition(body->p.x, body->p.y);
						sprite->setRotation(-wyMath::r2d(body->a));
						sprite->setVisible(true);
					}
					
					if(body->p.y < -wyDevice::winHeight / 2) {
						if(sprite)
							m_chipmunk->removeChildLocked(sprite,true);
						
						cpShape* shape = body->shapesList;
						while(shape) {
							cpSpaceRemoveShape(m_chipmunk->getSpace(), shape);
							shape = shape->next;
						}
						cpSpaceRemoveBody(m_chipmunk->getSpace(), body);
						cpBodyDestroy(body);
						cpBodyFree(body);
						m_arrayBodies->arr[i] = NULL;
					}
				}
			}
			
			for(int i = m_arrayBodies->num - 1; i >= 0; --i) {
				if(m_arrayBodies->arr[i] == NULL) {
					wyArrayDeleteIndex(m_arrayBodies, i);
				}
			}	
		}
	};
	
///////////////////////////////////////////////////////////////////////////////////////////////

	class wyPlanetTestLayer: public wyChipmunkTestLayer {
	public:
		wyPlanetTestLayer() {
			// add chipmunk node
			createChipmunk();
			
			cpResetShapeIdCounter();
			
			space = chipmunk->getSpace();
			cpSpaceResizeActiveHash(space, 30.0f, 10000);
			space->iterations = 20;
			
			// add a static body, the cpSpaceAddStaticBody method
			// is added by WiEngine
			staticBody = cpBodyNewStatic();
			
			for (int i = 0; i < 30; i++)
				add_box();
			
			cpShape *shape = cpSpaceAddStaticShape(space, cpCircleShapeNew(
																		   staticBody, 70.0f, cpvzero));
			shape->e = 1.0f;
			shape->u = 1.0f;
			shape->layers = NOT_GRABABLE_MASK;
			
			startUpdateSpace();
		}
		
		virtual ~wyPlanetTestLayer() {
		}
		
		virtual void updateSpace(float delta) {
			cpSpaceStep(space, delta);
			
			// Update the static body spin so that it looks like it's rotating.
			cpBodyUpdatePosition(staticBody, delta);
		}
		
		static void planetGravityVelocityFunc(cpBody *body, cpVect gravity,
											  cpFloat damping, cpFloat dt) {
			cpVect p = body->p;
			cpVect g = cpvmult(p, -50000.0f / cpvdot(p, p));
			
			cpBodyUpdateVelocity(body, g, damping, dt);
		}
		
		static cpVect rand_pos(cpFloat radius) {
			cpVect v;
			do {
				v = cpv(frand() * (640 - 2 * radius) - (320 - radius), frand()
						* (480 - 2 * radius) - (240 - radius));
			} while (cpvlength(v) < 100.0f);
			
			return v;
		}
		
		static void add_box() {
			const cpFloat size = 10.0f;
			const cpFloat mass = 1.0f;
			
			cpVect verts[] = { cpv(-size, -size), cpv(-size, size),
				cpv(size, size), cpv(size, -size), };
			
			cpFloat radius = cpvlength(cpv(size, size));
			
			cpBody *body = cpSpaceAddBody(space, cpBodyNew(mass, cpMomentForPoly(
																				 mass, 4, verts, cpvzero)));
			body->velocity_func = planetGravityVelocityFunc;
			body->p = rand_pos(radius);
			body->v = cpvmult(cpv(2 * frand() - 1, 2 * frand() - 1), 200);
			
			cpShape *shape = cpSpaceAddShape(space, cpPolyShapeNew(body, 4, verts,
																   cpvzero));
			shape->e = 0.0f;
			shape->u = 0.7f;
		}
	};
	
///////////////////////////////////////////////////////////////////////////////////////////////

	typedef struct PlayerStruct {
		cpFloat u;
		cpShape *shape;
		cpVect groundNormal;
		cpArray *groundShapes;
	} PlayerStruct;
	
	PlayerStruct playerInstance;
	
	class wyPlayerTestLayer: public wyChipmunkTestLayer {
	private:
		wyPoint mArrowDirection;
		
	public:
		wyPlayerTestLayer() {
			mArrowDirection = wypZero;
			
			// screen size
			int w = wyDevice::winWidth;
			int h = wyDevice::winHeight;
			
			// add chipmunk node
			createChipmunk();
			
			cpResetShapeIdCounter();
			
			space = chipmunk->getSpace();
			space->iterations = 10;
			space->gravity = cpv(0, -1500);
			
			// add a static body, the cpSpaceAddStaticBody method
			// is added by WiEngine
			staticBody = cpBodyNewStatic();
			
			cpBody *body;
			cpShape *shape;
			
			// Create segments around the edge of the screen.
			shape = cpSpaceAddStaticShape(space, cpSegmentShapeNew(staticBody, cpv(
																				   -w / 2, -h / 2), cpv(-w / 2, h / 2), 2.0f));
			shape->e = 1.0f;
			shape->u = 1.0f;
			shape->layers = NOT_GRABABLE_MASK;
			shape->collision_type = 2;
			
			shape = cpSpaceAddStaticShape(space, cpSegmentShapeNew(staticBody, cpv(
																				   w / 2, -h / 2), cpv(w / 2, h / 2), 2.0f));
			shape->e = 1.0f;
			shape->u = 1.0f;
			shape->layers = NOT_GRABABLE_MASK;
			shape->collision_type = 2;
			
			shape = cpSpaceAddStaticShape(space, cpSegmentShapeNew(staticBody, cpv(
																				   -w / 2, -h / 2), cpv(w / 2, -h / 2), 2.0f));
			shape->e = 1.0f;
			shape->u = 1.0f;
			shape->layers = NOT_GRABABLE_MASK;
			shape->collision_type = 2;
			
			shape = cpSpaceAddStaticShape(space, cpSegmentShapeNew(staticBody, cpv(
																				   -w / 2, h / 2), cpv(w / 2, h / 2), 2.0f));
			shape->e = 1.0f;
			shape->u = 1.0f;
			shape->layers = NOT_GRABABLE_MASK;
			shape->collision_type = 2;
			
			// add some other segments to play with
			shape = cpSpaceAddStaticShape(space, cpSegmentShapeNew(staticBody, cpv(
																				   -220, -200), cpv(-220, h / 2), 2.0f));
			shape->e = 1.0f;
			shape->u = 1.0f;
			shape->layers = NOT_GRABABLE_MASK;
			shape->collision_type = 2;
			
			shape = cpSpaceAddStaticShape(space, cpSegmentShapeNew(staticBody, cpv(
																				   0, -h / 2), cpv(w / 2, -200), 2.0f));
			shape->e = 1.0f;
			shape->u = 1.0f;
			shape->layers = NOT_GRABABLE_MASK;
			shape->collision_type = 2;
			
			shape = cpSpaceAddStaticShape(space, cpSegmentShapeNew(staticBody, cpv(
																				   200, -h / 2), cpv(w / 2, -100), 2.0f));
			shape->e = 1.0f;
			shape->u = 1.0f;
			shape->layers = NOT_GRABABLE_MASK;
			shape->collision_type = 2;
			
			shape = cpSpaceAddStaticShape(space, cpSegmentShapeNew(staticBody, cpv(
																				   -220, -80), cpv(200, -80), 2.0f));
			shape->e = 1.0f;
			shape->u = 1.0f;
			shape->layers = NOT_GRABABLE_MASK;
			shape->collision_type = 2;
			
			// Set up the player
			cpFloat radius = 15.0f;
			body = cpSpaceAddBody(space, cpBodyNew(10.0f, INFINITY));
			body->p = cpv(0, -220);
			body->velocity_func = playerUpdateVelocity;
			
			shape = cpSpaceAddShape(space, cpCircleShapeNew(body, radius, cpvzero));
			shape->e = 0.0f;
			shape->u = 2.0f;
			shape->collision_type = 1;
			
			playerInstance.u = shape->u;
			playerInstance.shape = shape;
			playerInstance.groundShapes = cpArrayNew(0);
			shape->data = &playerInstance;
			
			cpSpaceAddCollisionHandler(space, 1, 2, begin, preSolve, NULL,
									   separate, NULL);
			
			startUpdateSpace();
			
			setKeyEnabled(true);
			
			// up button
			wyNinePatchSprite* normal = wyNinePatchSprite::make(wyTexture2D::makePNG(RES("R.drawable.btn_normal")), wyr(DP(9), DP(7), DP(22), DP(28)));
			wyNinePatchSprite* pressed = wyNinePatchSprite::make(wyTexture2D::makePNG(RES("R.drawable.btn_pressed")), wyr(DP(9), DP(7), DP(22), DP(28)));
			normal->setContentSize(DP(78), DP(44));
			pressed->setContentSize(DP(78), DP(44));
			wyButton* button = new wyButton(normal, pressed, NULL, NULL, NULL,
					wyTargetSelector::make(this, SEL(wyPlayerTestLayer::onUp)));
			button->setPosition(DP(40), wyDevice::winHeight - DP(30));
			addChildLocked(button, 1);
			button->release();
			
			// label for up button
			wyBitmapFont* font = wyBitmapFont::loadFont(RES("R.raw.bitmapfont"));
			wyBitmapFontLabel* label = wyBitmapFontLabel::make(font, "Up");
			label->setColor(wyc3b(255, 255, 0));
			label->setPosition(DP(40), wyDevice::winHeight - DP(30));
			addChildLocked(label, 1);
			
			// down button
			button = new wyButton(normal, pressed, NULL, NULL, NULL,
					wyTargetSelector::make(this, SEL(wyPlayerTestLayer::onDown)));
			button->setPosition(DP(120), wyDevice::winHeight - DP(30));
			addChildLocked(button, 1);
			button->release();
			
			// label for down button
			label = wyBitmapFontLabel::make(font, "Down");
			label->setColor(wyc3b(255, 255, 0));
			label->setPosition(DP(120), wyDevice::winHeight - DP(30));
			addChildLocked(label, 1);
			
			// left button
			button = new wyButton(normal, pressed, NULL, NULL, NULL,
					wyTargetSelector::make(this, SEL(wyPlayerTestLayer::onLeft)));
			button->setPosition(DP(200), wyDevice::winHeight - DP(30));
			addChildLocked(button, 1);
			button->release();
			
			// label for left button
			label = wyBitmapFontLabel::make(font, "Left");
			label->setColor(wyc3b(255, 255, 0));
			label->setPosition(DP(200), wyDevice::winHeight - DP(30));
			addChildLocked(label, 1);
			
			// right button
			button = new wyButton(normal, pressed, NULL, NULL, NULL,
					wyTargetSelector::make(this, SEL(wyPlayerTestLayer::onRight)));
			button->setPosition(DP(280), wyDevice::winHeight - DP(30));
			addChildLocked(button, 1);
			button->release();
			
			// label for right button
			label = wyBitmapFontLabel::make(font, "Right");
			label->setColor(wyc3b(255, 255, 0));
			label->setPosition(DP(280), wyDevice::winHeight - DP(30));
			addChildLocked(label, 1);
		}
		
		virtual ~wyPlayerTestLayer() {
			cpArrayFree(playerInstance.groundShapes);
		}
		
		static int begin(cpArbiter *arb, cpSpace *space, void *ignore) {
			CP_ARBITER_GET_SHAPES(arb, a, b);
			PlayerStruct *player = (PlayerStruct*)a->data;
			
			cpVect n = cpvneg(cpArbiterGetNormal(arb, 0));
			if (n.y > 0.0f) {
				cpArrayPush(player->groundShapes, b);
			}
			
			return 1;
		}
		
		static int preSolve(cpArbiter *arb, cpSpace *space, void *ignore) {
			CP_ARBITER_GET_SHAPES(arb, a, b);
			PlayerStruct *player = (PlayerStruct*)a->data;
			
			if (arb->stamp > 0) {
				a->u = player->u;
				
				// pick the most upright jump normal each frame
				cpVect n = cpvneg(cpArbiterGetNormal(arb, 0));
				if (n.y >= player->groundNormal.y) {
					player->groundNormal = n;
				}
			}
			
			return 1;
		}
		
		static void separate(cpArbiter *arb, cpSpace *space, void *ignore) {
			CP_ARBITER_GET_SHAPES(arb, a, b);
			PlayerStruct *player = (PlayerStruct*)a->data;
			
			cpArrayDeleteObj(player->groundShapes, b);
			
			if (player->groundShapes->num == 0) {
				a->u = 0.0f;
			}
		}
		
		static void playerUpdateVelocity(cpBody *body, cpVect gravity,
										 cpFloat damping, cpFloat dt) {
			cpBodyUpdateVelocity(body, gravity, damping, dt);
			body->v.y = cpfmax(body->v.y, -700);
			body->v.x = cpfclamp(body->v.x, -400, 400);
		}
		
		virtual void updateSpace(float delta) {
			static int lastJumpState = 0;
			int jumpState = (mArrowDirection.y > 0.0f);
			
			cpVect groundNormal = playerInstance.groundNormal;
			if (groundNormal.y > 0.0f) {
				playerInstance.shape->surface_v = cpvmult(cpvperp(groundNormal),
														  400.0f * mArrowDirection.x);
			} else {
				playerInstance.shape->surface_v = cpvzero;
			}
			
			cpBody *body = playerInstance.shape->body;
			
			// apply jump
			if (jumpState && !lastJumpState && cpvlengthsq(groundNormal)) {
				body->v = cpvadd(body->v, cpvmult(cpvslerp(groundNormal, cpv(0.0f,
																			 1.0f), 0.75f), 500.0f));
			}
			
			if (playerInstance.groundShapes->num == 0) {
				cpFloat air_accel = body->v.x + mArrowDirection.x * (2000.0f);
				body->f.x = body->m * air_accel;
			}
			
			int steps = 3;
			cpFloat dt = 1.0f / 60.0f / (cpFloat) steps;
			
			playerInstance.groundNormal = cpvzero;
			for (int i = 0; i < steps; i++) {
				cpSpaceStep(space, dt);
			}
			
			lastJumpState = jumpState;
		}
		
		virtual bool keyDown(wyKeyEvent& event) {
			mArrowDirection.x = 0;
			mArrowDirection.y = 0;
			switch(event.keyCode) {
				case KEYCODE_DPAD_UP:
					mArrowDirection.y++;
					break;
				case KEYCODE_DPAD_DOWN:
					mArrowDirection.y--;
					break;
				case KEYCODE_DPAD_RIGHT:
					mArrowDirection.x++;
					break;
				case KEYCODE_DPAD_LEFT:
					mArrowDirection.x--;
					break;
				default:
					return false;
			}
			
			return true;
		}
		
		void onUp(wyTargetSelector* ts) {
			mArrowDirection.x = 0;
			mArrowDirection.y = 0;
			mArrowDirection.y++;
		}

		void onDown(wyTargetSelector* ts) {
			mArrowDirection.x = 0;
			mArrowDirection.y = 0;
			mArrowDirection.y--;
		}

		void onLeft(wyTargetSelector* ts) {
			mArrowDirection.x = 0;
			mArrowDirection.y = 0;
			mArrowDirection.x--;
		}

		void onRight(wyTargetSelector* ts) {
			mArrowDirection.x = 0;
			mArrowDirection.y = 0;
			mArrowDirection.x++;
		}
	};
	
///////////////////////////////////////////////////////////////////////////////////////////////

	#define NUM_VERTS 5
	
	class wyPlinkTestLayer: public wyChipmunkTestLayer {
	public:
		wyPlinkTestLayer() {
			// add chipmunk node
			createChipmunk();
			
			cpResetShapeIdCounter();
			
			space = chipmunk->getSpace();
			space->iterations = 5;
			space->gravity = cpv(0, -100);
			
			// add a static body, the cpSpaceAddStaticBody method
			// is added by WiEngine
			staticBody = cpBodyNewStatic();
			
			cpSpaceResizeStaticHash(space, 40.0f, 999);
			cpSpaceResizeActiveHash(space, 30.0f, 2999);
			
			cpBody *body;
			cpShape *shape;
			
			// Create vertexes for a pentagon shape.
			cpVect verts[NUM_VERTS];
			for (int i = 0; i < NUM_VERTS; i++) {
				cpFloat angle = -2 * (cpFloat) M_PI * i / ((cpFloat) NUM_VERTS);
				verts[i] = cpv(10 * cpfcos(angle), 10 * cpfsin(angle));
			}
			
			// Vertexes for a triangle shape.
			cpVect tris[] = { cpv(-15, -15), cpv(0, 10), cpv(15, -15), };
			
			// Create the static triangles.
			for (int i = 0; i < 9; i++) {
				for (int j = 0; j < 6; j++) {
					cpFloat stagger = (j % 2) * 40;
					cpVect offset = cpv(i * 80 - 320 + stagger, j * 70 - 240);
					shape = cpSpaceAddStaticShape(space, cpPolyShapeNew(staticBody,
																		3, tris, offset));
					shape->e = 1.0f;
					shape->u = 1.0f;
					shape->layers = NOT_GRABABLE_MASK;
				}
			}
			
			// Add lots of pentagons.
			for (int i = 0; i < 50; i++) {
				body = cpSpaceAddBody(space, cpBodyNew(1.0f, cpMomentForPoly(1.0f,
																			 NUM_VERTS, verts, cpvzero)));
				cpFloat x = frand() * 640 - 320;
				body->p = cpv(x, 350);
				
				shape = cpSpaceAddShape(space, cpPolyShapeNew(body, NUM_VERTS,
															  verts, cpvzero));
				shape->e = 0.0f;
				shape->u = 0.4f;
			}
			
			startUpdateSpace();
		}
		
		virtual ~wyPlinkTestLayer() {
		}
		
		virtual void updateSpace(float delta) {
			cpSpaceStep(space, delta);
			cpSpaceEachBody(space, &eachBody, NULL);
		}
		
		static void eachBody(cpBody *body, void *unused) {
			if (body->p.y < -260 || fabsf(body->p.x) > 340) {
				cpFloat x = frand() * 640 - 320;
				body->p = cpv(x, 260);
			}
		}
	};
	
///////////////////////////////////////////////////////////////////////////////////////////////

	#define numBalls 5
	static cpBody *balls[numBalls];
	
	class wyPumpTestLayer: public wyChipmunkTestLayer {
	private:
		wyPoint mArrowDirection;
		
	public:
		wyPumpTestLayer() {
			mArrowDirection = wypZero;
			
			// add chipmunk node
			createChipmunk();
			
			space = chipmunk->getSpace();
			space->gravity = cpv(0, -600);
			
			// add a static body, the cpSpaceAddStaticBody method
			// is added by WiEngine
			staticBody = cpBodyNewStatic();
			
			cpShape *shape;
			
			// beveling all of the line segments helps prevent things from getting stuck on cracks
			shape = cpSpaceAddStaticShape(space, cpSegmentShapeNew(staticBody, cpv(
																				   -256, 16), cpv(-256, 240), 2.0f));
			shape->e = 0.0f;
			shape->u = 0.5f;
			shape->layers = 1;
			shape->layers = NOT_GRABABLE_MASK;
			
			shape = cpSpaceAddStaticShape(space, cpSegmentShapeNew(staticBody, cpv(
																				   -256, 16), cpv(-192, 0), 2.0f));
			shape->e = 0.0f;
			shape->u = 0.5f;
			shape->layers = 1;
			shape->layers = NOT_GRABABLE_MASK;
			
			shape = cpSpaceAddStaticShape(space, cpSegmentShapeNew(staticBody, cpv(
																				   -192, 0), cpv(-192, -64), 2.0f));
			shape->e = 0.0f;
			shape->u = 0.5f;
			shape->layers = 1;
			shape->layers = NOT_GRABABLE_MASK;
			
			shape = cpSpaceAddStaticShape(space, cpSegmentShapeNew(staticBody, cpv(
																				   -128, -64), cpv(-128, 144), 2.0f));
			shape->e = 0.0f;
			shape->u = 0.5f;
			shape->layers = 1;
			shape->layers = NOT_GRABABLE_MASK;
			
			shape = cpSpaceAddStaticShape(space, cpSegmentShapeNew(staticBody, cpv(
																				   -192, 80), cpv(-192, 176), 2.0f));
			shape->e = 0.0f;
			shape->u = 0.5f;
			shape->layers = 1;
			shape->layers = NOT_GRABABLE_MASK;
			
			shape = cpSpaceAddStaticShape(space, cpSegmentShapeNew(staticBody, cpv(
																				   -192, 176), cpv(-128, 240), 2.0f));
			shape->e = 0.0f;
			shape->u = 0.5f;
			shape->layers = 1;
			shape->layers = NOT_GRABABLE_MASK;
			
			shape = cpSpaceAddStaticShape(space, cpSegmentShapeNew(staticBody, cpv(
																				   -128, 144), cpv(192, 64), 2.0f));
			shape->e = 0.0f;
			shape->u = 0.5f;
			shape->layers = 1;
			shape->layers = NOT_GRABABLE_MASK;
			
			cpVect verts[] = { cpv(-30, -80), cpv(-30, 80), cpv(30, 64), cpv(30,
																			 -80), };
			
			cpBody *plunger = cpSpaceAddBody(space, cpBodyNew(1.0f, INFINITY));
			plunger->p = cpv(-160, -80);
			
			shape = cpSpaceAddShape(space, cpPolyShapeNew(plunger, 4, verts,
														  cpvzero));
			shape->e = 1.0f;
			shape->u = 0.5f;
			shape->layers = 1;
			
			// add balls to hopper
			for (int i = 0; i < numBalls; i++)
				balls[i] = add_ball(cpv(-224, 80 + 64 * i));
			
			// add small gear
			cpBody *smallGear = cpSpaceAddBody(space, cpBodyNew(10.0f,
																cpMomentForCircle(10.0f, 80, 0, cpvzero)));
			smallGear->p = cpv(-160, -160);
			cpBodySetAngle(smallGear, (cpFloat) - M_PI_2);
			
			shape = cpSpaceAddShape(space, cpCircleShapeNew(smallGear, 80.0f,
															cpvzero));
			shape->layers = 0;
			
			cpSpaceAddConstraint(space, cpPivotJointNew2(staticBody, smallGear,
														 cpv(-160, -160), cpvzero));
			
			// add big gear
			cpBody *bigGear = cpSpaceAddBody(space, cpBodyNew(40.0f,
															  cpMomentForCircle(40.0f, 160, 0, cpvzero)));
			bigGear->p = cpv(80, -160);
			cpBodySetAngle(bigGear, (cpFloat) M_PI_2);
			
			shape = cpSpaceAddShape(space, cpCircleShapeNew(bigGear, 160.0f,
															cpvzero));
			shape->layers = 0;
			
			cpSpaceAddConstraint(space, cpPivotJointNew2(staticBody, bigGear, cpv(
																				  80, -160), cpvzero));
			
			// connect the plunger to the small gear.
			cpSpaceAddConstraint(space, cpPinJointNew(smallGear, plunger,
													  cpv(80, 0), cpv(0, 0)));
			// connect the gears.
			cpSpaceAddConstraint(space, cpGearJointNew(smallGear, bigGear,
													   (cpFloat) - M_PI_2, -2.0f));
			
			// feeder mechanism
			cpFloat bottom = -300.0f;
			cpFloat top = 32.0f;
			cpBody *feeder = cpSpaceAddBody(space, cpBodyNew(1.0f,
															 cpMomentForSegment(1.0f, cpv(-224.0f, bottom),
																				cpv(-224.0f, top))));
			feeder->p = cpv(-224, (bottom + top) / 2.0f);
			
			cpFloat len = top - bottom;
			cpSpaceAddShape(space, cpSegmentShapeNew(feeder, cpv(0.0f, len / 2.0f),
													 cpv(0.0f, -len / 2.0f), 20.0f));
			
			cpSpaceAddConstraint(space, cpPivotJointNew2(staticBody, feeder, cpv(
																				 -224.0f, bottom), cpv(0.0f, -len / 2.0f)));
			cpVect anchr = cpBodyWorld2Local(feeder, cpv(-224.0f, -160.0f));
			cpSpaceAddConstraint(space, cpPinJointNew(feeder, smallGear, anchr,
													  cpv(0.0f, 80.0f)));
			
			// motorize the second gear
			motor = cpSpaceAddConstraint(space, cpSimpleMotorNew(staticBody,
																 bigGear, 3.0f));
			
			startUpdateSpace();
			
			setKeyEnabled(true);
			
			// up button
			wyNinePatchSprite* normal = wyNinePatchSprite::make(wyTexture2D::makePNG(RES("R.drawable.btn_normal")), wyr(DP(9), DP(7), DP(22), DP(28)));
			wyNinePatchSprite* pressed = wyNinePatchSprite::make(wyTexture2D::makePNG(RES("R.drawable.btn_pressed")), wyr(DP(9), DP(7), DP(22), DP(28)));
			normal->setContentSize(DP(78), DP(44));
			pressed->setContentSize(DP(78), DP(44));
			wyButton* button = new wyButton(normal, pressed, NULL, NULL, NULL,
					wyTargetSelector::make(this, SEL(wyPumpTestLayer::onUp)));
			button->setPosition(DP(40), wyDevice::winHeight - DP(30));
			addChildLocked(button, 1);
			button->release();
			
			// label for up button
			wyBitmapFont* font = wyBitmapFont::loadFont(RES("R.raw.bitmapfont"));
			wyBitmapFontLabel* label = wyBitmapFontLabel::make(font, "Up");
			label->setColor(wyc3b(255, 255, 0));
			label->setPosition(DP(40), wyDevice::winHeight - DP(30));
			addChildLocked(label, 1);
			
			// down button
			button = new wyButton(normal, pressed, NULL, NULL, NULL,
					wyTargetSelector::make(this, SEL(wyPumpTestLayer::onDown)));
			button->setPosition(DP(120), wyDevice::winHeight - DP(30));
			addChildLocked(button, 1);
			button->release();
			
			// label for down button
			label = wyBitmapFontLabel::make(font, "Down");
			label->setColor(wyc3b(255, 255, 0));
			label->setPosition(DP(120), wyDevice::winHeight - DP(30));
			addChildLocked(label, 1);
			
			// left button
			button = new wyButton(normal, pressed, NULL, NULL, NULL,
					wyTargetSelector::make(this, SEL(wyPumpTestLayer::onLeft)));
			button->setPosition(DP(200), wyDevice::winHeight - DP(30));
			addChildLocked(button, 1);
			button->release();
			
			// label for left button
			label = wyBitmapFontLabel::make(font, "Left");
			label->setColor(wyc3b(255, 255, 0));
			label->setPosition(DP(200), wyDevice::winHeight - DP(30));
			addChildLocked(label, 1);
			
			// right button
			button = new wyButton(normal, pressed, NULL, NULL, NULL,
					wyTargetSelector::make(this, SEL(wyPumpTestLayer::onRight)));
			button->setPosition(DP(280), wyDevice::winHeight - DP(30));
			addChildLocked(button, 1);
			button->release();
			
			// label for right button
			label = wyBitmapFontLabel::make(font, "Right");
			label->setColor(wyc3b(255, 255, 0));
			label->setPosition(DP(280), wyDevice::winHeight - DP(30));
			addChildLocked(label, 1);
		}
		
		virtual ~wyPumpTestLayer() {
		}
		
		virtual void updateSpace(float delta) {
			cpFloat coef = (2.0f + mArrowDirection.y) / 3.0f;
			cpFloat rate = mArrowDirection.x * 30.0f * coef;
			cpSimpleMotorSetRate(motor, rate);
			motor->maxForce = (rate) ? 1000000.0f : 0.0f;
			
			int steps = 2;
			cpFloat dt = 1.0f / 60.0f / (cpFloat) steps;
			
			for (int i = 0; i < steps; i++) {
				cpSpaceStep(space, dt);
				
				for (int i = 0; i < numBalls; i++) {
					cpBody *ball = balls[i];
					if (ball->p.x > 320.0f) {
						ball->v = cpvzero;
						ball->p = cpv(-224.0f, 200.0f);
					}
				}
			}
		}
		
		static cpBody *
		add_ball(cpVect pos) {
			cpBody *body = cpSpaceAddBody(space, cpBodyNew(1.0f, cpMomentForCircle(
																				   1.0f, 30, 0, cpvzero)));
			body->p = pos;
			
			cpShape *shape = cpSpaceAddShape(space, cpCircleShapeNew(body, 30,
																	 cpvzero));
			shape->e = 0.0f;
			shape->u = 0.5f;
			
			return body;
		}
		
		virtual bool keyDown(wyKeyEvent& event) {
			mArrowDirection.x = 0;
			mArrowDirection.y = 0;
			switch(event.keyCode) {
				case KEYCODE_DPAD_UP:
					mArrowDirection.y++;
					break;
				case KEYCODE_DPAD_DOWN:
					mArrowDirection.y--;
					break;
				case KEYCODE_DPAD_RIGHT:
					mArrowDirection.x++;
					break;
				case KEYCODE_DPAD_LEFT:
					mArrowDirection.x--;
					break;
				default:
					return false;
			}
			
			return true;
		}
		
		void onUp(wyTargetSelector* ts) {
			mArrowDirection.x = 0;
			mArrowDirection.y = 0;
			mArrowDirection.y++;
		}

		void onDown(wyTargetSelector* ts) {
			mArrowDirection.x = 0;
			mArrowDirection.y = 0;
			mArrowDirection.y--;
		}

		void onLeft(wyTargetSelector* ts) {
			mArrowDirection.x = 0;
			mArrowDirection.y = 0;
			mArrowDirection.x--;
		}

		void onRight(wyTargetSelector* ts) {
			mArrowDirection.x = 0;
			mArrowDirection.y = 0;
			mArrowDirection.x++;
		}
	};

///////////////////////////////////////////////////////////////////////////////////////////////
	
	class wyPyramidStackTestLayer: public wyChipmunkTestLayer {
	public:
		wyPyramidStackTestLayer() {
			// screen size
			int w = wyDevice::winWidth;
			int h = wyDevice::winHeight;
			
			// add chipmunk node
			createChipmunk();
			
			cpResetShapeIdCounter();
			
			space = chipmunk->getSpace();
			space->iterations = 20;
			cpSpaceResizeStaticHash(space, 40.0f, 1000);
			cpSpaceResizeActiveHash(space, 40.0f, 1000);
			space->gravity = cpv(0, -100);
			
			// add a static body, the cpSpaceAddStaticBody method
			// is added by WiEngine
			staticBody = cpBodyNewStatic();
			
			cpBody *body;
			cpShape *shape;
			
			int num = 4;
			cpVect verts[] = { cpv(-15, -15), cpv(-15, 15), cpv(15, 15), cpv(15,
																			 -15), };
			
			// Create segments around the edge of the screen.
			shape = cpSpaceAddStaticShape(space, cpSegmentShapeNew(staticBody, cpv(
																				   -w / 2, -h / 2), cpv(-w / 2, h / 2), 2.0f));
			shape->e = 1.0f;
			shape->u = 1.0f;
			shape->layers = NOT_GRABABLE_MASK;
			
			shape = cpSpaceAddStaticShape(space, cpSegmentShapeNew(staticBody, cpv(
																				   w / 2, -h / 2), cpv(w / 2, h / 2), 2.0f));
			shape->e = 1.0f;
			shape->u = 1.0f;
			shape->layers = NOT_GRABABLE_MASK;
			
			shape = cpSpaceAddStaticShape(space, cpSegmentShapeNew(staticBody, cpv(
																				   -w / 2, -h / 2), cpv(w / 2, -h / 2), 2.0f));
			shape->e = 1.0f;
			shape->u = 1.0f;
			shape->layers = NOT_GRABABLE_MASK;
			
			// Add lots of boxes.
			for (int i = 0; i < 8; i++) {
				for (int j = 0; j <= i; j++) {
					body = cpBodyNew(1.0f, cpMomentForPoly(1.0f, num, verts,
														   cpvzero));
					body->p = cpv(j * 32 - i * 16, 300 - i * 32);
					cpSpaceAddBody(space, body);
					shape = cpPolyShapeNew(body, num, verts, cpvzero);
					shape->e = 0.0f;
					shape->u = 0.8f;
					cpSpaceAddShape(space, shape);
				}
			}
			
			// Add a ball to make things more interesting
			cpFloat radius = 15.0f;
			body = cpSpaceAddBody(space, cpBodyNew(10.0f, cpMomentForCircle(10.0f,
																			0.0f, radius, cpvzero)));
			body->p = cpv(0, -h / 2 + radius + 5);
			
			shape = cpSpaceAddShape(space, cpCircleShapeNew(body, radius, cpvzero));
			shape->e = 0.0f;
			shape->u = 0.9f;
			
			startUpdateSpace();
		}
		
		virtual ~wyPyramidStackTestLayer() {
		}
	};
	
///////////////////////////////////////////////////////////////////////////////////////////////

	class wyPyramidToppleTestLayer: public wyChipmunkTestLayer {
	public:
		wyPyramidToppleTestLayer() {
			// add chipmunk node
			createChipmunk();
			
			cpResetShapeIdCounter();
			
			space = chipmunk->getSpace();
			space->iterations = 20;
			cpSpaceResizeActiveHash(space, 30.0f, 2999);
			cpSpaceResizeStaticHash(space, 30.0f, 999);
			space->gravity = cpv(0, -300);
			
			// add a static body, the cpSpaceAddStaticBody method
			// is added by WiEngine
			staticBody = cpBodyNewStatic();
			
			cpBody *body;
			
			cpShape *shape;
			
			// Vertexes for the dominos.
			int num = 4;
			cpVect
			verts[] = { cpv(-3, -20), cpv(-3, 20), cpv(3, 20), cpv(3, -20), };
			
			// Add a floor.
			shape = cpSpaceAddStaticShape(space, cpSegmentShapeNew(staticBody, cpv(
																				   -600, -240), cpv(600, -240), 2.0f));
			shape->e = 1.0f;
			shape->u = 1.0f;
			shape->layers = NOT_GRABABLE_MASK;
			
			// Shared friction constant.
			cpFloat u = 0.6f;
			
			// Add the dominoes. Skim over this. It doesn't do anything fancy, and it's hard to follow.
			int n = 4;
			for (int i = 1; i <= n; i++) {
				cpVect offset = cpv(-i * 60 / 2.0f, (n - i) * 52);
				
				for (int j = 0; j < i; j++) {
					body = cpSpaceAddBody(space, cpBodyNew(1.0f, cpMomentForPoly(
																				 1.0f, num, verts, cpvzero)));
					body->p = cpvadd(cpv(j * 60, -220), offset);
					
					shape = cpSpaceAddShape(space, cpPolyShapeNew(body, num, verts,
																  cpvzero));
					shape->e = 0.0f;
					shape->u = u;
					
					body = cpSpaceAddBody(space, cpBodyNew(1.0f, cpMomentForPoly(
																				 1.0f, num, verts, cpvzero)));
					body->p = cpvadd(cpv(j * 60, -197), offset);
					cpBodySetAngle(body, (cpFloat) M_PI / 2.0f);
					
					shape = cpSpaceAddShape(space, cpPolyShapeNew(body, num, verts,
																  cpvzero));
					shape->e = 0.0f;
					shape->u = u;
					
					if (j == (i - 1))
						continue;
					body = cpSpaceAddBody(space, cpBodyNew(1.0f, cpMomentForPoly(
																				 1.0f, num, verts, cpvzero)));
					body->p = cpvadd(cpv(j * 60 + 30, -191), offset);
					cpBodySetAngle(body, (cpFloat) M_PI / 2.0f);
					
					shape = cpSpaceAddShape(space, cpPolyShapeNew(body, num, verts,
																  cpvzero));
					shape->e = 0.0f;
					shape->u = u;
				}
				
				body = cpSpaceAddBody(space, cpBodyNew(1.0f, cpMomentForPoly(1.0f,
																			 num, verts, cpvzero)));
				body->p = cpvadd(cpv(-17, -174), offset);
				
				shape = cpSpaceAddShape(space, cpPolyShapeNew(body, num, verts,
															  cpvzero));
				shape->e = 0.0f;
				shape->u = u;
				
				body = cpSpaceAddBody(space, cpBodyNew(1.0f, cpMomentForPoly(1.0f,
																			 num, verts, cpvzero)));
				body->p = cpvadd(cpv((i - 1) * 60 + 17, -174), offset);
				
				shape = cpSpaceAddShape(space, cpPolyShapeNew(body, num, verts,
															  cpvzero));
				shape->e = 0.0f;
				shape->u = u;
			}
			
			startUpdateSpace();
		}
		
		virtual ~wyPyramidToppleTestLayer() {
		}
	};
	
///////////////////////////////////////////////////////////////////////////////////////////////

	static cpShape *querySeg = NULL;
	class wyQueryTestLayer: public wyChipmunkTestLayer {
	private:
		cpVect mousePoint;
		
	public:
		wyQueryTestLayer() {
			mousePoint = cpvzero;
			
			// screen size
			int w = wyDevice::winWidth;
			int h = wyDevice::winHeight;
			
			// add chipmunk node
			createChipmunk();
			
			cpResetShapeIdCounter();
			
			space = chipmunk->getSpace();
			space->elasticIterations = 0;
			space->iterations = 5;
			
			// add a static body, the cpSpaceAddStaticBody method
			// is added by WiEngine
			staticBody = cpBodyNewStatic();
			
			cpSpaceResizeStaticHash(space, 40.0f, 999);
			cpSpaceResizeActiveHash(space, 30.0f, 2999);
			
			cpShape *shape;
			
			// add a non-collidable segment as a quick and dirty way to draw the query line
			shape = cpSegmentShapeNew(staticBody, cpvzero, cpv(100.0f, 0.0f), 4.0f);
			cpSpaceAddStaticShape(space, shape);
			shape->layers = 0;
			querySeg = shape;
			
			// add a fat segment
			cpFloat mass = 1.0f;
			cpFloat length = 100.0f;
			cpVect a = cpv(-length / 2.0f, 0.0f), b = cpv(length / 2.0f, 0.0f);
			cpBody *body = cpSpaceAddBody(space, cpBodyNew(mass,
														   cpMomentForSegment(mass, a, b)));
			body->p = cpv(0.0f, 100.0f);
			cpSpaceAddShape(space, cpSegmentShapeNew(body, a, b, 20.0f));
			
			// add a static segment
			cpSpaceAddStaticShape(space, cpSegmentShapeNew(staticBody, cpv(0, h
																		   / 2), cpv(w / 2, 0), 2.0f));
			
			// add a pentagon
			mass = 1.0f;
			cpVect verts[5];
			for (int i = 0; i < 5; i++) {
				cpFloat angle = -2 * (cpFloat) M_PI * i / 5.f;
				verts[i] = cpv(30 * cpfcos(angle), 30 * cpfsin(angle));
			}
			body = cpSpaceAddBody(space, cpBodyNew(mass,
												   cpMomentForPoly(mass, 5, verts, cpvzero)));
			body->p = cpv(150.0f, 50.0f);
			cpSpaceAddShape(space, cpPolyShapeNew(body, 5, verts,
												  cpvzero));
			
			// add a circle
			mass = 1.0f;
			cpFloat r = 20.0f;
			body = cpSpaceAddBody(space, cpBodyNew(mass,
												   cpMomentForCircle(mass, 0.0f, r, cpvzero)));
			body->p = cpv(100.0f, 100.0f);
			cpSpaceAddShape(space, cpCircleShapeNew(body, r, cpvzero));
			
			startUpdateSpace();
			setTouchEnabled(true);
		}
		
		virtual ~wyQueryTestLayer() {
		}
		
		virtual void updateSpace(float delta) {
			cpVect start = cpvzero;
			cpVect end = mousePoint;
			cpVect lineEnd = end;
			
			cpSegmentQueryInfo info = { };
			if (cpSpaceSegmentQueryFirst(space, start, end, -1, 0, &info)) {
				cpVect point = cpSegmentQueryHitPoint(start, end, info);
				lineEnd = cpvadd(point, cpvzero);
			}
			
			cpSegmentShapeSetEndpoints(querySeg, cpvzero, lineEnd);
			
			cpSpaceStep(space, delta);
		}
		
		virtual bool touchesBegan(wyMotionEvent& event) {
			mousePoint = cpv(event.x[0], event.y[0]);
			mousePoint = cpvsub(mousePoint, cpv(wyDevice::winWidth / 2,
												wyDevice::winHeight / 2));
			return wyChipmunkTestLayer::touchesBegan(event);
		}
		
		virtual bool touchesMoved(wyMotionEvent& event) {
			mousePoint = cpv(event.x[0], event.y[0]);
			mousePoint = cpvsub(mousePoint, cpv(wyDevice::winWidth / 2,
												wyDevice::winHeight / 2));
			return wyChipmunkTestLayer::touchesMoved(event);
		}
		
		virtual bool touchesEnded(wyMotionEvent& event) {
			mousePoint = cpv(event.x[0], event.y[0]);
			mousePoint = cpvsub(mousePoint, cpv(wyDevice::winWidth / 2,
												wyDevice::winHeight / 2));
			return wyChipmunkTestLayer::touchesEnded(event);
		}
		
		virtual bool touchesCancelled(wyMotionEvent& event) {
			mousePoint = cpv(event.x[0], event.y[0]);
			mousePoint = cpvsub(mousePoint, cpv(wyDevice::winWidth / 2,
												wyDevice::winHeight / 2));
			return wyChipmunkTestLayer::touchesCancelled(event);
		}
	};
	
///////////////////////////////////////////////////////////////////////////////////////////////

	typedef enum {
		BALL_TYPE, BLOCKING_SENSOR_TYPE, CATCH_SENSOR_TYPE,
	} CollisionTypes;
	
	typedef struct Emitter {
		int queue;
		int blocked;
		cpVect position;
	} Emitter;
	
	static Emitter emitterInstance;
	
	class wySensorTestLayer: public wyChipmunkTestLayer {
	public:
		wySensorTestLayer() :
		wyChipmunkTestLayer(wyc4bBlue) {
			// add chipmunk node
			createChipmunk();
			
			cpResetShapeIdCounter();
			
			space = chipmunk->getSpace();
			space->iterations = 10;
			space->gravity = cpv(0, -100);
			
			// add a static body, the cpSpaceAddStaticBody method
			// is added by WiEngine
			staticBody = cpBodyNewStatic();
			
			cpShape *shape;
			
			// Data structure for our ball emitter
			// We'll use two sensors for it, one to see if the emitter is blocked
			// a second to catch the balls and add them back to the emitter
			emitterInstance.queue = 5;
			emitterInstance.blocked = 0;
			emitterInstance.position = cpv(0, 150);
			
			// Create our blocking sensor, so we know when the emitter is clear to emit another ball
			shape = cpSpaceAddStaticShape(space, cpCircleShapeNew(staticBody,
																  15.0f, emitterInstance.position));
			shape->sensor = 1;
			shape->collision_type = BLOCKING_SENSOR_TYPE;
			shape->data = &emitterInstance;
			
			// Create our catch sensor to requeue the balls when they reach the bottom of the screen
			shape = cpSpaceAddStaticShape(space, cpSegmentShapeNew(staticBody, cpv(
																				   -2000, -200), cpv(2000, -200), 15.0f));
			shape->sensor = 1;
			shape->collision_type = CATCH_SENSOR_TYPE;
			shape->data = &emitterInstance;
			
			cpSpaceAddCollisionHandler(space, BLOCKING_SENSOR_TYPE, BALL_TYPE,
									   blockerBegin, NULL, NULL, blockerSeparate, NULL);
			cpSpaceAddCollisionHandler(space, CATCH_SENSOR_TYPE, BALL_TYPE,
									   catcherBarBegin, NULL, NULL, NULL, NULL);
			
			startUpdateSpace();
		}
		
		virtual ~wySensorTestLayer() {
		}
		
		static int blockerBegin(cpArbiter *arb, cpSpace *space, void *unused) {
			CP_ARBITER_GET_SHAPES(arb, a, b);
			Emitter *emitter = (Emitter*) a->data;
			
			emitter->blocked++;
			
			return 0; // Return values from sensors callbacks are ignored,
		}
		
		static void blockerSeparate(cpArbiter *arb, cpSpace *space, void *unused) {
			CP_ARBITER_GET_SHAPES(arb, a, b);
			Emitter *emitter = (Emitter*) a->data;
			
			emitter->blocked--;
		}
		
		static void postStepRemove(cpSpace *space, cpShape *shape, void *unused) {
			cpBody* body = shape->body;;
			
			cpSpaceRemoveShape(space, shape);
			cpShapeFree(shape);

			cpSpaceRemoveBody(space, body);
			cpBodyFree(body);
		}
		
		static int catcherBarBegin(cpArbiter *arb, cpSpace *space, void *unused) {
			cpShape *a, *b;
			cpArbiterGetShapes(arb, &a, &b);
			Emitter *emitter = (Emitter*) a->data;
			
			emitter->queue++;
			cpSpaceAddPostStepCallback(space, (cpPostStepFunc) postStepRemove, b,
									   NULL);
			
			return 0;
		}
		
		virtual void updateSpace(float delta) {
			if (!emitterInstance.blocked && emitterInstance.queue) {
				emitterInstance.queue--;
				
				cpBody *body = cpSpaceAddBody(space, cpBodyNew(1.0f,
															   cpMomentForCircle(1.0f, 15.0f, 0.0f, cpvzero)));
				body->p = emitterInstance.position;
				body->v = cpvmult(cpv(frand_unit(), frand_unit()), 100.0f);
				
				cpShape *shape = cpSpaceAddShape(space, cpCircleShapeNew(body,
																		 15.0f, cpvzero));
				shape->collision_type = BALL_TYPE;
			}
			
			cpSpaceStep(space, delta);
		}
	};
	
///////////////////////////////////////////////////////////////////////////////////////////////

	class wyShapeAnimationTestLayer: public wyChipmunkTestLayer {
	public:
		wyShapeAnimationTestLayer() {
			// screen size
			int w = wyDevice::winWidth;
			int h = wyDevice::winHeight;
			
			// add chipmunk node
			createChipmunk();
			chipmunk->setDebugDraw(false);
			
			// reset shape id count
			cpResetShapeIdCounter();
			
			// get space from chipmunk node
			space = chipmunk->getSpace();
			cpSpaceResizeActiveHash(space, 30.0f, 100);
			space->iterations = 10;
			space->gravity = cpv(0, -100);
			
			// add a static body, the cpSpaceAddStaticBody method
			// is added by WiEngine
			staticBody = cpBodyNewStatic();
			
			// Create segments around the edge of the screen.
			cpShape* shape = cpSpaceAddStaticShape(space, cpSegmentShapeNew(staticBody, cpv(
																							-w / 2, -h / 2), cpv(-w / 2, h / 2), 2.0f));
			shape->e = 1.0f;
			shape->u = 1.0f;
			shape->layers = NOT_GRABABLE_MASK;
			
			shape = cpSpaceAddStaticShape(space, cpSegmentShapeNew(staticBody, cpv(
																				   w / 2, -h / 2), cpv(w / 2, h / 2), 2.0f));
			shape->e = 1.0f;
			shape->u = 1.0f;
			shape->layers = NOT_GRABABLE_MASK;
			
			shape = cpSpaceAddStaticShape(space, cpSegmentShapeNew(staticBody, cpv(
																				   -w / 2, -h / 2), cpv(w / 2, -h / 2), 2.0f));
			shape->e = 1.0f;
			shape->u = 1.0f;
			shape->layers = NOT_GRABABLE_MASK;
			
			add_box();
			
			startUpdateSpace();
		}
		
		virtual ~wyShapeAnimationTestLayer() {
		}
		
		void add_box() {
			float w = DP(85.f);
			float h = DP(121.f);
			cpVect verts[] = {
				cpv(-w / 2, -h / 2),
				cpv(-w / 2, h / 2),
				cpv(w / 2, h / 2),
				cpv(w / 2, -h / 2)
			};
			const cpFloat mass = 10.0f;
			
			cpBody *body = cpSpaceAddBody(space, cpBodyNew(mass, cpMomentForPoly(
																				 mass, 4, verts, cpvzero)));
			body->p = cpv(w / 2, h / 2);
			body->v = cpvmult(cpv(2 * frand() - 1, 2 * frand() - 1), 200);
			
			cpShape *shape = cpSpaceAddShape(space, cpPolyShapeNew(body, 4, verts,
																   cpvzero));
			shape->e = 0.5f;
			shape->u = 0.9f;
			
			// create shape animation
			wyShapeAnimation* anim = wyShapeAnimation::make(1.f,
															RES("R.drawable.grossini_dance_01"),
															RES("R.drawable.grossini_dance_02"),
															RES("R.drawable.grossini_dance_03"),
															RES("R.drawable.grossini_dance_04"),
															RES("R.drawable.grossini_dance_05"),
															RES("R.drawable.grossini_dance_06"),
															RES("R.drawable.grossini_dance_07"),
															RES("R.drawable.grossini_dance_08"),
															RES("R.drawable.grossini_dance_09"),
															RES("R.drawable.grossini_dance_10"),
															RES("R.drawable.grossini_dance_11"),
															RES("R.drawable.grossini_dance_12"),
															RES("R.drawable.grossini_dance_13"),
															RES("R.drawable.grossini_dance_14"),
															NULL);
			anim->setLoop(true);
			anim->start(shape);
		}
	};
	
///////////////////////////////////////////////////////////////////////////////////////////////

	class wySimpleTestLayer: public wyChipmunkTestLayer {
	public:
		wySimpleTestLayer() {
			// screen size
			int w = wyDevice::winWidth;
			int h = wyDevice::winHeight;
			
			// add chipmunk node
			createChipmunk();
			
			// Create a space, a space is a simulation world. It simulates the motions of rigid bodies,
			// handles collisions between them, and simulates the joints between them.
			space = chipmunk->getSpace();
			
			// Lets set some parameters of the space:
			// More iterations make the simulation more accurate but slower
			space->iterations = 10;
			// These parameters tune the efficiency of the collision detection.
			// For more info: http://code.google.com/p/chipmunk-physics/wiki/cpSpace
			cpSpaceResizeStaticHash(space, 30.0f, 1000);
			cpSpaceResizeActiveHash(space, 30.0f, 1000);
			// Give it some gravity
			space->gravity = cpv(0, -100);
			
			// add a static body, the cpSpaceAddStaticBody method
			// is added by WiEngine
			staticBody = cpBodyNewStatic();
			
			// Create A ground segment along the bottom of the screen
			cpShape *ground = cpSegmentShapeNew(staticBody, cpv(-w / 2,-h / 2), cpv(w / 2,-h / 2), 2.0f);
			// Set some parameters of the shape.
			// For more info: http://code.google.com/p/chipmunk-physics/wiki/cpShape
			ground->e = 1.0f; ground->u = 1.0f;
			ground->layers = NOT_GRABABLE_MASK; // Used by the Demo mouse grabbing code
			// Add the shape to the space as a static shape
			// If a shape never changes position, add it as static so Chipmunk knows it only needs to
			// calculate collision information for it once when it is added.
			// Do not change the postion of a static shape after adding it.
			cpSpaceAddStaticShape(space, ground);
			
			// Add a moving circle object.
			cpFloat radius = 15.0f;
			cpFloat mass = 10.0f;
			// This time we need to give a mass and moment of inertia when creating the circle.
			cpBody *ballBody = cpBodyNew(mass, cpMomentForCircle(mass, 0.0f, radius, cpvzero));
			// Set some parameters of the body:
			// For more info: http://code.google.com/p/chipmunk-physics/wiki/cpBody
			ballBody->p = cpv(0, h / 2 + radius+5);
			
			// Add the body to the space so it will be simulated and move around.
			cpSpaceAddBody(space, ballBody);
			
			
			// Add a circle shape for the ball.
			// Shapes are always defined relative to the center of gravity of the body they are attached to.
			// When the body moves or rotates, the shape will move with it.
			// Additionally, all of the cpSpaceAdd*() functions return the thing they added so you can create and add in one go.
			cpShape *ballShape = cpSpaceAddShape(space, cpCircleShapeNew(ballBody, radius, cpvzero));
			ballShape->e = 0.5f; ballShape->u = 0.9f;
			
			startUpdateSpace();
		}
		
		virtual ~wySimpleTestLayer() {
		}
	};

///////////////////////////////////////////////////////////////////////////////////////////////
	
	class wySpringTestLayer: public wyChipmunkTestLayer {
	public:
		wySpringTestLayer() :
		wyChipmunkTestLayer(wyc4bBlue) {
			// add chipmunk node
			createChipmunk();
			
			space = chipmunk->getSpace();
			
			// add a static body, the cpSpaceAddStaticBody method
			// is added by WiEngine
			staticBody = cpBodyNewStatic();
			
			cpBody *body1 = add_bar(cpv(-240, 160), cpv(-160, 80), 1);
			cpBody *body2 = add_bar(cpv(-160, 80), cpv(-80, 160), 1);
			cpBody *body3 = add_bar(cpv(0, 160), cpv(80, 0), 0);
			cpBody *body4 = add_bar(cpv(160, 160), cpv(240, 160), 0);
			cpBody *body5 = add_bar(cpv(-240, 0), cpv(-160, -80), 2);
			cpBody *body6 = add_bar(cpv(-160, -80), cpv(-80, 0), 2);
			cpBody *body7 = add_bar(cpv(-80, 0), cpv(0, 0), 2);
			cpBody *body8 = add_bar(cpv(0, -80), cpv(80, -80), 0);
			cpBody *body9 = add_bar(cpv(240, 80), cpv(160, 0), 3);
			cpBody *body10 = add_bar(cpv(160, 0), cpv(240, -80), 3);
			cpBody *body11 = add_bar(cpv(-240, -80), cpv(-160, -160), 4);
			cpBody *body12 = add_bar(cpv(-160, -160), cpv(-80, -160), 0);
			cpBody *body13 = add_bar(cpv(0, -160), cpv(80, -160), 0);
			cpBody *body14 = add_bar(cpv(160, -160), cpv(240, -160), 0);
			
			cpSpaceAddConstraint(space, cpPivotJointNew2(body1, body2,
														 cpv(40, -40), cpv(-40, -40)));
			cpSpaceAddConstraint(space, cpPivotJointNew2(body5, body6,
														 cpv(40, -40), cpv(-40, -40)));
			cpSpaceAddConstraint(space, cpPivotJointNew2(body6, body7, cpv(40, 40),
														 cpv(-40, 0)));
			cpSpaceAddConstraint(space, cpPivotJointNew2(body9, body10, cpv(-40,
																			-40), cpv(-40, 40)));
			cpSpaceAddConstraint(space, cpPivotJointNew2(body11, body12, cpv(40,
																			 -40), cpv(-40, 0)));
			
			cpFloat stiff = 100.0f;
			cpFloat damp = 0.5f;
			cpSpaceAddConstraint(space, new_spring(staticBody, body1,
												   cpv(-320, 240), cpv(-40, 40), 0.0f, stiff, damp));
			cpSpaceAddConstraint(space, new_spring(staticBody, body1,
												   cpv(-320, 80), cpv(-40, 40), 0.0f, stiff, damp));
			cpSpaceAddConstraint(space, new_spring(staticBody, body1,
												   cpv(-160, 240), cpv(-40, 40), 0.0f, stiff, damp));
			
			cpSpaceAddConstraint(space, new_spring(staticBody, body2,
												   cpv(-160, 240), cpv(40, 40), 0.0f, stiff, damp));
			cpSpaceAddConstraint(space, new_spring(staticBody, body2, cpv(0, 240),
												   cpv(40, 40), 0.0f, stiff, damp));
			
			cpSpaceAddConstraint(space, new_spring(staticBody, body3, cpv(80, 240),
												   cpv(-40, 80), 0.0f, stiff, damp));
			
			cpSpaceAddConstraint(space, new_spring(staticBody, body4, cpv(80, 240),
												   cpv(-40, 0), 0.0f, stiff, damp));
			cpSpaceAddConstraint(space, new_spring(staticBody, body4,
												   cpv(320, 240), cpv(40, 0), 0.0f, stiff, damp));
			
			cpSpaceAddConstraint(space, new_spring(staticBody, body5,
												   cpv(-320, 80), cpv(-40, 40), 0.0f, stiff, damp));
			
			cpSpaceAddConstraint(space, new_spring(staticBody, body9, cpv(320, 80),
												   cpv(40, 40), 0.0f, stiff, damp));
			
			cpSpaceAddConstraint(space, new_spring(staticBody, body10, cpv(320, 0),
												   cpv(40, -40), 0.0f, stiff, damp));
			cpSpaceAddConstraint(space, new_spring(staticBody, body10, cpv(320,
																		   -160), cpv(40, -40), 0.0f, stiff, damp));
			
			cpSpaceAddConstraint(space, new_spring(staticBody, body11, cpv(-320,
																		   -160), cpv(-40, 40), 0.0f, stiff, damp));
			
			cpSpaceAddConstraint(space, new_spring(staticBody, body12, cpv(-240,
																		   -240), cpv(-40, 0), 0.0f, stiff, damp));
			cpSpaceAddConstraint(space, new_spring(staticBody, body12,
												   cpv(0, -240), cpv(40, 0), 0.0f, stiff, damp));
			
			cpSpaceAddConstraint(space, new_spring(staticBody, body13,
												   cpv(0, -240), cpv(-40, 0), 0.0f, stiff, damp));
			cpSpaceAddConstraint(space, new_spring(staticBody, body13,
												   cpv(80, -240), cpv(40, 0), 0.0f, stiff, damp));
			
			cpSpaceAddConstraint(space, new_spring(staticBody, body14,
												   cpv(80, -240), cpv(-40, 0), 0.0f, stiff, damp));
			cpSpaceAddConstraint(space, new_spring(staticBody, body14, cpv(240,
																		   -240), cpv(40, 0), 0.0f, stiff, damp));
			cpSpaceAddConstraint(space, new_spring(staticBody, body14, cpv(320,
																		   -160), cpv(40, 0), 0.0f, stiff, damp));
			
			cpSpaceAddConstraint(space, new_spring(body1, body5, cpv(40, -40), cpv(
																				   -40, 40), 0.0f, stiff, damp));
			cpSpaceAddConstraint(space, new_spring(body1, body6, cpv(40, -40), cpv(
																				   40, 40), 0.0f, stiff, damp));
			cpSpaceAddConstraint(space, new_spring(body2, body3, cpv(40, 40), cpv(
																				  -40, 80), 0.0f, stiff, damp));
			cpSpaceAddConstraint(space, new_spring(body3, body4, cpv(-40, 80), cpv(
																				   -40, 0), 0.0f, stiff, damp));
			cpSpaceAddConstraint(space, new_spring(body3, body4, cpv(40, -80), cpv(
																				   -40, 0), 0.0f, stiff, damp));
			cpSpaceAddConstraint(space, new_spring(body3, body7, cpv(40, -80), cpv(
																				   40, 0), 0.0f, stiff, damp));
			cpSpaceAddConstraint(space, new_spring(body3, body7, cpv(-40, 80), cpv(
																				   -40, 0), 0.0f, stiff, damp));
			cpSpaceAddConstraint(space, new_spring(body3, body8, cpv(40, -80), cpv(
																				   40, 0), 0.0f, stiff, damp));
			cpSpaceAddConstraint(space, new_spring(body3, body9, cpv(40, -80), cpv(
																				   -40, -40), 0.0f, stiff, damp));
			cpSpaceAddConstraint(space, new_spring(body4, body9, cpv(40, 0), cpv(
																				 40, 40), 0.0f, stiff, damp));
			cpSpaceAddConstraint(space, new_spring(body5, body11, cpv(-40, 40),
												   cpv(-40, 40), 0.0f, stiff, damp));
			cpSpaceAddConstraint(space, new_spring(body5, body11, cpv(40, -40),
												   cpv(40, -40), 0.0f, stiff, damp));
			cpSpaceAddConstraint(space, new_spring(body7, body8, cpv(40, 0), cpv(
																				 -40, 0), 0.0f, stiff, damp));
			cpSpaceAddConstraint(space, new_spring(body8, body12, cpv(-40, 0), cpv(
																				   40, 0), 0.0f, stiff, damp));
			cpSpaceAddConstraint(space, new_spring(body8, body13, cpv(-40, 0), cpv(
																				   -40, 0), 0.0f, stiff, damp));
			cpSpaceAddConstraint(space, new_spring(body8, body13, cpv(40, 0), cpv(
																				  40, 0), 0.0f, stiff, damp));
			cpSpaceAddConstraint(space, new_spring(body8, body14, cpv(40, 0), cpv(
																				  -40, 0), 0.0f, stiff, damp));
			cpSpaceAddConstraint(space, new_spring(body10, body14, cpv(40, -40),
												   cpv(-40, 0), 0.0f, stiff, damp));
			cpSpaceAddConstraint(space, new_spring(body10, body14, cpv(40, -40),
												   cpv(-40, 0), 0.0f, stiff, damp));
			
			startUpdateSpace();
		}
		
		virtual ~wySpringTestLayer() {
		}
		
		static cpBody *
		add_bar(cpVect a, cpVect b, int group) {
			cpVect center = cpvmult(cpvadd(a, b), 1.0f / 2.0f);
			cpFloat length = cpvlength(cpvsub(b, a));
			cpFloat mass = length / 160.0f;
			
			cpBody *body = cpSpaceAddBody(space, cpBodyNew(mass, mass * length
														   * length / 12.0f));
			body->p = center;
			
			cpShape *shape = cpSpaceAddShape(space, cpSegmentShapeNew(body, cpvsub(
																				   a, center), cpvsub(b, center), 10.0f));
			shape->group = group;
			
			return body;
		}
		
		static cpFloat springForce(cpConstraint *spring, cpFloat dist) {
			cpFloat clamp = 20.0f;
			return cpfclamp(cpDampedSpringGetRestLength(spring) - dist, -clamp,
							clamp) * cpDampedSpringGetStiffness(spring);
		}
		
		static cpConstraint *
		new_spring(cpBody *a, cpBody *b, cpVect anchr1, cpVect anchr2,
				   cpFloat restLength, cpFloat stiff, cpFloat damp) {
			cpConstraint *spring = cpDampedSpringNew(a, b, anchr1, anchr2,
													 restLength, stiff, damp);
			cpDampedSpringSetSpringForceFunc(spring, springForce);
			
			return spring;
		}
	};
	
///////////////////////////////////////////////////////////////////////////////////////////////

	static cpBody *tankBody, *tankControlBody;
	class wyTankTestLayer: public wyChipmunkTestLayer {
	private:
		cpVect mousePoint;
		
	public:
		wyTankTestLayer() {
			// screen size
			int w = wyDevice::winWidth;
			int h = wyDevice::winHeight;
			
			// add chipmunk node
			createChipmunk();
			
			cpResetShapeIdCounter();
			
			space = chipmunk->getSpace();
			cpSpaceResizeActiveHash(space, 30.0f, 1000);
			space->iterations = 10;
			
			// add a static body, the cpSpaceAddStaticBody method
			// is added by WiEngine
			staticBody = cpBodyNewStatic();
			
			cpShape *shape;
			
			// Create segments around the edge of the screen.
			shape = cpSpaceAddShape(space, cpSegmentShapeNew(staticBody, cpv(
																			 -w / 2, -h / 2), cpv(-w / 2, h / 2), 2.0f));
			shape->e = 1.0f;
			shape->u = 1.0f;
			shape->layers = NOT_GRABABLE_MASK;
			
			shape = cpSpaceAddShape(space, cpSegmentShapeNew(staticBody, cpv(w / 2,
																			 -h / 2), cpv(w / 2, h / 2), 2.0f));
			shape->e = 1.0f;
			shape->u = 1.0f;
			shape->layers = NOT_GRABABLE_MASK;
			
			shape = cpSpaceAddShape(space, cpSegmentShapeNew(staticBody, cpv(
																			 -w / 2, -h / 2), cpv(w / 2, -h / 2), 2.0f));
			shape->e = 1.0f;
			shape->u = 1.0f;
			shape->layers = NOT_GRABABLE_MASK;
			
			shape = cpSpaceAddShape(space, cpSegmentShapeNew(staticBody, cpv(
																			 -w / 2, h / 2), cpv(w / 2, h / 2), 2.0f));
			shape->e = 1.0f;
			shape->u = 1.0f;
			shape->layers = NOT_GRABABLE_MASK;
			
			for (int i = 0; i < 50; i++) {
				cpBody *body = add_box(10.0f, 1.0f);
				
				cpConstraint *pivot = cpSpaceAddConstraint(space, cpPivotJointNew2(
																				   staticBody, body, cpvzero, cpvzero));
				pivot->biasCoef = 0.0f; // disable joint correction
				pivot->maxForce = 1000.0f; // emulate linear friction
				
				cpConstraint *gear = cpSpaceAddConstraint(space, cpGearJointNew(
																				staticBody, body, 0.0f, 1.0f));
				gear->biasCoef = 0.0f; // disable joint correction
				gear->maxForce = 5000.0f; // emulate angular friction
			}
			
			// We joint the tank to the control body and control the tank indirectly by modifying the control body.
			tankControlBody = cpBodyNew(INFINITY, INFINITY);
			tankBody = add_box(15.0f, 10.0f);
			
			cpConstraint *pivot = cpSpaceAddConstraint(space, cpPivotJointNew2(
																			   tankControlBody, tankBody, cpvzero, cpvzero));
			pivot->biasCoef = 0.0f; // disable joint correction
			pivot->maxForce = 10000.0f; // emulate linear friction
			
			cpConstraint *gear = cpSpaceAddConstraint(space, cpGearJointNew(
																			tankControlBody, tankBody, 0.0f, 1.0f));
			gear->biasCoef = 1.0f; // limit angular correction rate
			gear->maxBias = 1.0f; // limit angular correction rate
			gear->maxForce = 500000.0f; // emulate angular friction
			
			startUpdateSpace();
			setTouchEnabled(true);
		}
		
		virtual ~wyTankTestLayer() {
		}
		
		virtual void updateSpace(float delta) {
			// turn the control body based on the angle relative to the actual body
			cpVect mouseDelta = cpvsub(mousePoint, tankBody->p);
			cpFloat turn = cpvtoangle(cpvunrotate(tankBody->rot, mouseDelta));
			cpBodySetAngle(tankControlBody, tankBody->a - turn);
			
			// drive the tank towards the mouse
			if (cpvnear(mousePoint, tankBody->p, 30.0f)) {
				tankControlBody->v = cpvzero; // stop
			} else {
				cpFloat direction =
				(cpvdot(mouseDelta, tankBody->rot) > 0.0f ? 1.0f : -1.0f);
				tankControlBody->v = cpvrotate(tankBody->rot, cpv(
																  30.0f * direction, 0.0f));
			}
			
			cpSpaceStep(space, delta);
		}
		
		static cpBody *
		add_box(cpFloat size, cpFloat mass) {
			// screen size
			int w = wyDevice::winWidth;
			int h = wyDevice::winHeight;
			
			cpVect verts[] = { cpv(-size, -size), cpv(-size, size),
				cpv(size, size), cpv(size, -size), };
			
			cpFloat radius = cpvlength(cpv(size, size));
			
			cpBody *body = cpSpaceAddBody(space, cpBodyNew(mass, cpMomentForPoly(
																				 mass, 4, verts, cpvzero)));
			body->p = cpv(frand() * (w - 2 * radius) - (w / 2 - radius), frand()
						  * (h - 2 * radius) - (h / 2 - radius));
			
			cpShape *shape = cpSpaceAddShape(space, cpPolyShapeNew(body, 4, verts,
																   cpvzero));
			shape->e = 0.0f;
			shape->u = 0.7f;
			
			return body;
		}
		
		virtual bool touchesBegan(wyMotionEvent& event) {
			mousePoint = cpv(event.x[0], event.y[0]);
			mousePoint = cpvsub(mousePoint, cpv(wyDevice::winWidth / 2,
												wyDevice::winHeight / 2));
			return wyChipmunkTestLayer::touchesBegan(event);
		}
		
		virtual bool touchesMoved(wyMotionEvent& event) {
			mousePoint = cpv(event.x[0], event.y[0]);
			mousePoint = cpvsub(mousePoint, cpv(wyDevice::winWidth / 2,
												wyDevice::winHeight / 2));
			return wyChipmunkTestLayer::touchesMoved(event);
		}
		
		virtual bool touchesEnded(wyMotionEvent& event) {
			mousePoint = cpv(event.x[0], event.y[0]);
			mousePoint = cpvsub(mousePoint, cpv(wyDevice::winWidth / 2,
												wyDevice::winHeight / 2));
			return wyChipmunkTestLayer::touchesEnded(event);
		}
		
		virtual bool touchesCancelled(wyMotionEvent& event) {
			mousePoint = cpv(event.x[0], event.y[0]);
			mousePoint = cpvsub(mousePoint, cpv(wyDevice::winWidth / 2,
												wyDevice::winHeight / 2));
			return wyChipmunkTestLayer::touchesCancelled(event);
		}
	};

///////////////////////////////////////////////////////////////////////////////////////////////
	
	class wyTexturedBounceTestLayer: public wyChipmunkTestLayer {
	public:
		wyTexturedBounceTestLayer() {
			// screen size
			int w = wyDevice::winWidth;
			int h = wyDevice::winHeight;
			
			// add chipmunk node
			createChipmunk();
			chipmunk->setDebugDraw(false);
			
			// reset shape id count
			cpResetShapeIdCounter();
			
			// get space from chipmunk node
			cpSpace* space = chipmunk->getSpace();
			cpSpaceResizeActiveHash(space, 30.0f, 1000);
			space->iterations = 10;
			
			// add a static body, the cpSpaceAddStaticBody method
			// is added by WiEngine
			staticBody = cpBodyNewStatic();
			
			// shape
			cpShape *shape;
			
			// Create segments around the edge of the screen.
			shape = cpSpaceAddStaticShape(space, cpSegmentShapeNew(staticBody, cpv(
																				   -w / 2, -h / 2), cpv(-w / 2, h / 2), 2.0f));
			shape->e = 1.0f;
			shape->u = 1.0f;
			shape->layers = NOT_GRABABLE_MASK;
			
			shape = cpSpaceAddStaticShape(space, cpSegmentShapeNew(staticBody, cpv(
																				   w / 2, -h / 2), cpv(w / 2, h / 2), 2.0f));
			shape->e = 1.0f;
			shape->u = 1.0f;
			shape->layers = NOT_GRABABLE_MASK;
			
			shape = cpSpaceAddStaticShape(space, cpSegmentShapeNew(staticBody, cpv(
																				   -w / 2, -h / 2), cpv(w / 2, -h / 2), 2.0f));
			shape->e = 1.0f;
			shape->u = 1.0f;
			shape->layers = NOT_GRABABLE_MASK;
			
			shape = cpSpaceAddStaticShape(space, cpSegmentShapeNew(staticBody, cpv(
																				   -w / 2, h / 2), cpv(w / 2, h / 2), 2.0f));
			shape->e = 1.0f;
			shape->u = 1.0f;
			shape->layers = NOT_GRABABLE_MASK;
			
			for (int i = 0; i < 10; i++)
				add_box();
			
			cpBody *body = cpSpaceAddBody(space, cpBodyNew(100.0f, 10000.0f));
			
			shape = cpSpaceAddShape(space, cpSegmentShapeNew(body, cpv(-150, 0),
															 cpv(150, 0), 15.0f));
			shape->e = 1.0f;
			shape->u = 1.0f;
			cpShapeSetTexture(shape, wyTexture2D::makePNG(RES("R.drawable.bar")), false);
			
			cpSpaceAddConstraint(space, cpPivotJointNew2(body, staticBody, cpvzero,
														 cpvzero));
			
			startUpdateSpace();
		}
		
		virtual ~wyTexturedBounceTestLayer() {
		}
		
		void add_box() {
			// screen size
			int w = wyDevice::winWidth;
			int h = wyDevice::winHeight;
			
			const cpFloat size = DP(32.0f) / 2;
			const cpFloat mass = 1.0f;
			
			cpVect verts[] = { cpv(-size, -size), cpv(-size, size),
				cpv(size, size), cpv(size, -size) };
			
			cpFloat radius = cpvlength(cpv(size, size));
			
			cpSpace* space = chipmunk->getSpace();
			cpBody *body = cpSpaceAddBody(space, cpBodyNew(mass, cpMomentForPoly(
																				 mass, 4, verts, cpvzero)));
			body->p = cpv(frand() * (w - 2 * radius) - (w / 2 - radius), frand()
						  * (h - 2 * radius) - (h / 2 - radius));
			body->v = cpvmult(cpv(2 * frand() - 1, 2 * frand() - 1), 200);
			
			cpShape *shape = cpSpaceAddShape(space, cpPolyShapeNew(body, 4, verts,
																   cpvzero));
			cpShapeSetTexture2(shape, wyTexture2D::makePNG(RES("R.drawable.blocks")),
							   wyr(wyMath::randMax(1) * size * 2, wyMath::randMax(1) * size * 2, size * 2, size * 2), false);
			shape->e = 1.0f;
			shape->u = 0.0f;
		}
	};

///////////////////////////////////////////////////////////////////////////////////////////////
	
	class wyTexturedOneWayTestLayer: public wyChipmunkTestLayer {
	public:
		wyTexturedOneWayTestLayer() {
			// screen size
			int w = wyDevice::winWidth;
			int h = wyDevice::winHeight;
			
			// add chipmunk node
			createChipmunk();
			chipmunk->setDebugDraw(false);
			
			// reset shape id count
			cpResetShapeIdCounter();
			
			// get space from chipmunk node
			cpSpace* space = chipmunk->getSpace();
			space->iterations = 10;
			space->gravity = cpv(0, -100);
			
			// add a static body, the cpSpaceAddStaticBody method
			// is added by WiEngine
			staticBody = cpBodyNewStatic();
			
			cpBody *body;
			cpShape *shape;
			
			// Create segments around the edge of the screen.
			shape = cpSpaceAddStaticShape(space, cpSegmentShapeNew(staticBody, cpv(
																				   -w / 2, -h / 2), cpv(-w / 2, h / 2), 2.0f));
			shape->e = 1.0f;
			shape->u = 1.0f;
			shape->layers = NOT_GRABABLE_MASK;
			
			shape = cpSpaceAddStaticShape(space, cpSegmentShapeNew(staticBody, cpv(
																				   w / 2, -h / 2), cpv(w / 2, h / 2), 2.0f));
			shape->e = 1.0f;
			shape->u = 1.0f;
			shape->layers = NOT_GRABABLE_MASK;
			
			shape = cpSpaceAddStaticShape(space, cpSegmentShapeNew(staticBody, cpv(
																				   -w / 2, -h / 2), cpv(w / 2, -h / 2), 2.0f));
			shape->e = 1.0f;
			shape->u = 1.0f;
			shape->layers = NOT_GRABABLE_MASK;
			
			// Add our one way segment
			shape = cpSpaceAddStaticShape(space, cpSegmentShapeNew(staticBody, cpv(
																				   -w / 2 + 60, -100), cpv(w / 2 - 60, -100), 10.0f));
			shape->e = 1.0f;
			shape->u = 1.0f;
			shape->collision_type = 1;
			shape->layers = NOT_GRABABLE_MASK;
			cpShapeSetTexture(shape, wyTexture2D::makePNG(RES("R.drawable.bar")), false);
			
			// We'll use the data pointer for the OneWayPlatform struct
			platformInstance.n = cpv(0, 1); // let objects pass upwards
			platformInstance.passThruList = cpArrayNew(0);
			shape->data = &platformInstance;
			
			// Add a ball to make things more interesting
			cpFloat radius = DP(32.f) / 2.f;
			body = cpSpaceAddBody(space, cpBodyNew(10.0f, cpMomentForCircle(10.0f,
																			0.0f, radius, cpvzero)));
			body->p = cpv(0, -200);
			body->v = cpv(0, 170);
			
			shape = cpSpaceAddShape(space, cpCircleShapeNew(body, radius, cpvzero));
			shape->e = 0.0f;
			shape->u = 0.9f;
			shape->collision_type = 2;
			cpShapeSetTexture2(shape, wyTexture2D::makePNG(RES("R.drawable.blocks")),
							   wyr(wyMath::randMax(1) * radius * 2, wyMath::randMax(1) * radius * 2, radius * 2, radius * 2), false);
			
			cpSpaceAddCollisionHandler(space, 1, 2, NULL, preSolve, NULL, separate,
									   NULL);
			
			startUpdateSpace();
		}
		
		virtual ~wyTexturedOneWayTestLayer() {
		}
		
		static int preSolve(cpArbiter *arb, cpSpace *space, void *ignore) {
			CP_ARBITER_GET_SHAPES(arb, a, b);
			OneWayPlatform *platform = (OneWayPlatform*)a->data;
			
			if (cpArrayContains(platform->passThruList, b)) {
				// The object is in the pass thru list, ignore it until separates.
				return 0;
			} else {
				cpFloat dot = cpvdot(cpArbiterGetNormal(arb, 0), platform->n);
				
				if (dot < 0) {
					// Add the object to the pass thrru list
					cpArrayPush(platform->passThruList, b);
					return 0;
				} else {
					return 1;
				}
			}
		}
		
		static void separate(cpArbiter *arb, cpSpace *space, void *ignore) {
			CP_ARBITER_GET_SHAPES(arb, a, b);
			
			// remove the object from the pass thru list
			cpArrayDeleteObj(((OneWayPlatform *) a->data)->passThruList, b);
		}
	};
	
///////////////////////////////////////////////////////////////////////////////////////////////

	static cpFloat seg_radius = 3.0f;
	class wyTheoJansenTestLayer: public wyChipmunkTestLayer {
	private:
		wyPoint mArrowDirection;
		
	public:
		wyTheoJansenTestLayer() {
			mArrowDirection = wypZero;
			
			// screen size
			int w = wyDevice::winWidth;
			int h = wyDevice::winHeight;
			
			// add chipmunk node
			createChipmunk();
			
			cpResetShapeIdCounter();
			
			space = chipmunk->getSpace();
			space->iterations = 20;
			space->gravity = cpv(0, -500);
			
			// add a static body, the cpSpaceAddStaticBody method
			// is added by WiEngine
			staticBody = cpBodyNewStatic();
			
			cpShape *shape;
			cpVect a, b;
			
			// Create segments around the edge of the screen.
			shape = cpSegmentShapeNew(staticBody, cpv(-w / 2, -h / 2), cpv(-w / 2, h / 2),
									  2.0f);
			shape->e = 1.0f;
			shape->u = 1.0f;
			shape->layers = NOT_GRABABLE_MASK;
			cpSpaceAddShape(space, shape);
			
			shape = cpSegmentShapeNew(staticBody, cpv(w / 2, -h / 2), cpv(w / 2, h / 2),
									  2.0f);
			shape->e = 1.0f;
			shape->u = 1.0f;
			shape->layers = NOT_GRABABLE_MASK;
			cpSpaceAddShape(space, shape);
			
			shape = cpSegmentShapeNew(staticBody, cpv(-w / 2, -h / 2), cpv(w / 2, -h / 2),
									  2.0f);
			shape->e = 1.0f;
			shape->u = 1.0f;
			shape->layers = NOT_GRABABLE_MASK;
			cpSpaceAddShape(space, shape);
			
			cpFloat offset = 30.0f;
			
			// make chassis
			cpFloat chassis_mass = 2.0f;
			a = cpv(-offset, 0.0f), b = cpv(offset, 0.0f);
			cpBody *chassis = cpBodyNew(chassis_mass, cpMomentForSegment(
																		 chassis_mass, a, b));
			cpSpaceAddBody(space, chassis);
			shape = cpSegmentShapeNew(chassis, a, b, seg_radius);
			shape->group = 1;
			cpSpaceAddShape(space, shape);
			
			// make crank
			cpFloat crank_mass = 1.0f;
			cpFloat crank_radius = 13.0f;
			cpBody *crank = cpBodyNew(crank_mass, cpMomentForCircle(crank_mass,
																	crank_radius, 0.0f, cpvzero));
			cpSpaceAddBody(space, crank);
			shape = cpCircleShapeNew(crank, crank_radius, cpvzero);
			shape->group = 1;
			cpSpaceAddShape(space, shape);
			cpSpaceAddConstraint(space, cpPivotJointNew2(chassis, crank, cpvzero,
														 cpvzero));
			
			cpFloat side = 30.0f;
			
			int num_legs = 2;
			for (int i = 0; i < num_legs; i++) {
				make_leg(side, offset, chassis, crank, cpvmult(cpvforangle(
																		   (cpFloat)(2 * i + 0) / num_legs * (cpFloat) M_PI),
															   crank_radius));
				make_leg(side, -offset, chassis, crank, cpvmult(cpvforangle(
																			(cpFloat)(2 * i + 1) / num_legs * (cpFloat) M_PI),
																crank_radius));
			}
			
			motor = cpSimpleMotorNew(chassis, crank, 6.0f);
			cpSpaceAddConstraint(space, motor);
			
			startUpdateSpace();
			
			setKeyEnabled(true);
			
			// left button
			wyNinePatchSprite* normal = wyNinePatchSprite::make(wyTexture2D::makePNG(RES("R.drawable.btn_normal")), wyr(DP(9), DP(7), DP(22), DP(28)));
			wyNinePatchSprite* pressed = wyNinePatchSprite::make(wyTexture2D::makePNG(RES("R.drawable.btn_pressed")), wyr(DP(9), DP(7), DP(22), DP(28)));
			normal->setContentSize(DP(150), DP(44));
			pressed->setContentSize(DP(150), DP(44));
			wyButton* button = new wyButton(normal, pressed, NULL, NULL, NULL,
					wyTargetSelector::make(this, SEL(wyTheoJansenTestLayer::onLeft)));
			button->setPosition(DP(80), wyDevice::winHeight - DP(30));
			addChildLocked(button, 1);
			button->release();
			
			// label for left button
			wyBitmapFont* font = wyBitmapFont::loadFont(RES("R.raw.bitmapfont"));
			wyBitmapFontLabel* label = wyBitmapFontLabel::make(font, "Left");
			label->setColor(wyc3b(255, 255, 0));
			label->setPosition(DP(80), wyDevice::winHeight - DP(30));
			addChildLocked(label, 1);
			
			// right button
			button = new wyButton(normal, pressed, NULL, NULL, NULL,
					wyTargetSelector::make(this, SEL(wyTheoJansenTestLayer::onRight)));
			button->setPosition(DP(240), wyDevice::winHeight - DP(30));
			addChildLocked(button, 1);
			button->release();
			
			// label for right button
			label = wyBitmapFontLabel::make(font, "Right");
			label->setColor(wyc3b(255, 255, 0));
			label->setPosition(DP(240), wyDevice::winHeight - DP(30));
			addChildLocked(label, 1);
		}
		
		virtual ~wyTheoJansenTestLayer() {
		}
		
		virtual bool keyDown(wyKeyEvent& event) {
			mArrowDirection.x = 0;
			mArrowDirection.y = 0;
			switch(event.keyCode) {
				case KEYCODE_DPAD_RIGHT:
					mArrowDirection.x++;
					break;
				case KEYCODE_DPAD_LEFT:
					mArrowDirection.x--;
					break;
				default:
					return false;
			}
			
			return true;
		}
		
		void onLeft(wyTargetSelector* ts) {
			mArrowDirection.x = 0;
			mArrowDirection.y = 0;
			mArrowDirection.x--;
		}

		void onRight(wyTargetSelector* ts) {
			mArrowDirection.x = 0;
			mArrowDirection.y = 0;
			mArrowDirection.x++;
		}
		
		virtual void updateSpace(float delta) {
			cpFloat coef = (2.0f + mArrowDirection.y) / 3.0f;
			cpFloat rate = mArrowDirection.x * 10.0f * coef;
			cpSimpleMotorSetRate(motor, rate);
			motor->maxForce = (rate) ? 100000.0f : 0.0f;
			
			int steps = 3;
			cpFloat dt = 1.0f / 60.0f / (cpFloat) steps;
			
			for (int i = 0; i < steps; i++) {
				cpSpaceStep(space, dt);
			}
		}
		
		static void make_leg(cpFloat side, cpFloat offset, cpBody *chassis,
							 cpBody *crank, cpVect anchor) {
			cpVect a, b;
			cpShape *shape;
			
			cpFloat leg_mass = 1.0f;
			
			// make leg
			a = cpvzero, b = cpv(0.0f, side);
			cpBody *upper_leg = cpBodyNew(leg_mass, cpMomentForSegment(leg_mass, a,
																	   b));
			upper_leg->p = cpv(offset, 0.0f);
			cpSpaceAddBody(space, upper_leg);
			cpSpaceAddShape(space, cpSegmentShapeNew(upper_leg, a, b, seg_radius));
			cpSpaceAddConstraint(space, cpPivotJointNew2(chassis, upper_leg, cpv(
																				 offset, 0.0f), cpvzero));
			
			// lower leg
			a = cpvzero, b = cpv(0.0f, -1.0f * side);
			cpBody *lower_leg = cpBodyNew(leg_mass, cpMomentForSegment(leg_mass, a,
																	   b));
			lower_leg->p = cpv(offset, -side);
			cpSpaceAddBody(space, lower_leg);
			shape = cpSegmentShapeNew(lower_leg, a, b, seg_radius);
			shape->group = 1;
			cpSpaceAddShape(space, shape);
			shape = cpCircleShapeNew(lower_leg, seg_radius * 2.0f, b);
			shape->group = 1;
			shape->e = 0.0f;
			shape->u = 1.0f;
			cpSpaceAddShape(space, shape);
			cpSpaceAddConstraint(space, cpPinJointNew(chassis, lower_leg, cpv(
																			  offset, 0.0f), cpvzero));
			
			cpSpaceAddConstraint(space, cpGearJointNew(upper_leg, lower_leg, 0.0f,
													   1.0f));
			
			cpConstraint *constraint;
			cpFloat diag = cpfsqrt(side * side + offset * offset);
			
			constraint = cpPinJointNew(crank, upper_leg, anchor, cpv(0.0f, side));
			cpPinJointSetDist(constraint, diag);
			cpSpaceAddConstraint(space, constraint);
			constraint = cpPinJointNew(crank, lower_leg, anchor, cpvzero);
			cpPinJointSetDist(constraint, diag);
			cpSpaceAddConstraint(space, constraint);
		}
	};
	
///////////////////////////////////////////////////////////////////////////////////////////////

	class wyTumbleTestLayer: public wyChipmunkTestLayer {
	public:
		wyTumbleTestLayer() {
			// add chipmunk node
			createChipmunk();
			
			cpResetShapeIdCounter();
			
			space = chipmunk->getSpace();
			cpSpaceResizeActiveHash(space, 40.0f, 999);
			cpSpaceResizeStaticHash(space, 40.0f, 99);
			space->gravity = cpv(0, -600);
			
			// add a static body, the cpSpaceAddStaticBody method
			// is added by WiEngine
			staticBody = cpBodyNewStatic();
			
			cpBody *body;
			cpShape *shape;
			
			// Vertexes for the bricks
			int num = 4;
			cpVect verts[] = { cpv(-30, -15), cpv(-30, 15), cpv(30, 15), cpv(30,
																			 -15), };
			
			// Set up the static box.
			cpVect a = cpv(-200, -200);
			cpVect b = cpv(-200, 200);
			cpVect c = cpv(200, 200);
			cpVect d = cpv(200, -200);
			
			shape = cpSpaceAddShape(space,
									cpSegmentShapeNew(staticBody, a, b, 2.0f));
			shape->e = 1.0f;
			shape->u = 1.0f;
			shape->layers = NOT_GRABABLE_MASK;
			
			shape = cpSpaceAddShape(space,
									cpSegmentShapeNew(staticBody, b, c, 2.0f));
			shape->e = 1.0f;
			shape->u = 1.0f;
			shape->layers = NOT_GRABABLE_MASK;
			
			shape = cpSpaceAddShape(space,
									cpSegmentShapeNew(staticBody, c, d, 2.0f));
			shape->e = 1.0f;
			shape->u = 1.0f;
			shape->layers = NOT_GRABABLE_MASK;
			
			shape = cpSpaceAddShape(space,
									cpSegmentShapeNew(staticBody, d, a, 2.0f));
			shape->e = 1.0f;
			shape->u = 1.0f;
			shape->layers = NOT_GRABABLE_MASK;
			
			// Give the box a little spin.
			// Because staticBody is never added to the space, we will need to
			// update it ourselves. (see above).
			// NOTE: Normally you would want to add the segments as normal and not static shapes.
			// I'm just doing it to demonstrate the cpSpaceRehashStatic() function.
			staticBody->w = 0.4f;
			
			// Add the bricks.
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 7; j++) {
					body = cpSpaceAddBody(space, cpBodyNew(1.0f, cpMomentForPoly(
																				 1.0f, num, verts, cpvzero)));
					body->p = cpv(i * 60 - 150, j * 30 - 150);
					
					shape = cpSpaceAddShape(space, cpPolyShapeNew(body, num, verts,
																  cpvzero));
					shape->e = 0.0f;
					shape->u = 0.7f;
				}
			}
			
			startUpdateSpace();
		}
		
		virtual ~wyTumbleTestLayer() {
		}
		
		virtual void updateSpace(float delta) {
			cpSpaceStep(space, delta);
			
			// Manually update the position of the static shape so that
			// the box rotates.
			cpBodyUpdatePosition(staticBody, delta);
			
			// Because the box was added as a static shape and we moved it
			// we need to manually rehash the static spatial hash.
			cpSpaceRehashStatic(space);
		}
	};
	
///////////////////////////////////////////////////////////////////////////////////////////////

	#define NUM_CIRCLES 30
	static cpShape *circles[NUM_CIRCLES];
	static cpFloat circleRadius = 30.0f;
	
	class wyUnsafeOpsTestLayer: public wyChipmunkTestLayer {
	private:
		wyPoint mArrowDirection;
		
	public:
		wyUnsafeOpsTestLayer() {
			mArrowDirection = wypZero;
			
			// screen size
			int w = wyDevice::winWidth;
			int h = wyDevice::winHeight;
			
			// add chipmunk node
			createChipmunk();
			
			cpResetShapeIdCounter();
			
			space = chipmunk->getSpace();
			space->iterations = 5;
			space->gravity = cpv(0, -100);
			
			cpSpaceResizeStaticHash(space, 40.0f, 999);
			cpSpaceResizeActiveHash(space, 30.0f, 2999);
			
			// add a static body, the cpSpaceAddStaticBody method
			// is added by WiEngine
			staticBody = cpBodyNewStatic();
			
			cpShape *shape;
			
			shape = cpSpaceAddStaticShape(space, cpSegmentShapeNew(staticBody, cpv(
																				   -w / 2, -h / 2), cpv(-w / 2, h / 2), 2.0f));
			shape->e = 1.0f;
			shape->u = 1.0f;
			shape->layers = NOT_GRABABLE_MASK;
			
			shape = cpSpaceAddStaticShape(space, cpSegmentShapeNew(staticBody, cpv(
																				   w / 2, -h / 2), cpv(w / 2, h / 2), 2.0f));
			shape->e = 1.0f;
			shape->u = 1.0f;
			shape->layers = NOT_GRABABLE_MASK;
			
			shape = cpSpaceAddStaticShape(space, cpSegmentShapeNew(staticBody, cpv(
																				   -w / 2, -h / 2), cpv(w / 2, -h / 2), 2.0f));
			shape->e = 1.0f;
			shape->u = 1.0f;
			shape->layers = NOT_GRABABLE_MASK;
			
			for (int i = 0; i < NUM_CIRCLES; i++) {
				cpBody* body = cpSpaceAddBody(space, cpBodyNew(1.0f, cpMomentForCircle(
																					   1.0f, 0.0f, circleRadius, cpvzero)));
				body->p = cpvmult(
								  cpv(frand() * 2.0f - 1.0f, frand() * 2.0f - 1.0f),
								  circleRadius * 5.0f);
				
				circles[i] = shape = cpSpaceAddShape(space, cpCircleShapeNew(body,
																			 circleRadius, cpvzero));
				shape->e = 0.0f;
				shape->u = 1.0f;
			}
			
			startUpdateSpace();
			
			setKeyEnabled(true);
			
			// up button
			wyNinePatchSprite* normal = wyNinePatchSprite::make(wyTexture2D::makePNG(RES("R.drawable.btn_normal")), wyr(DP(9), DP(7), DP(22), DP(28)));
			wyNinePatchSprite* pressed = wyNinePatchSprite::make(wyTexture2D::makePNG(RES("R.drawable.btn_pressed")), wyr(DP(9), DP(7), DP(22), DP(28)));
			normal->setContentSize(DP(78), DP(44));
			pressed->setContentSize(DP(78), DP(44));
			wyButton* button = new wyButton(normal, pressed, NULL, NULL, NULL,
					wyTargetSelector::make(this, SEL(wyUnsafeOpsTestLayer::onUp)));
			button->setPosition(DP(40), wyDevice::winHeight - DP(30));
			addChildLocked(button, 1);
			button->release();
			
			// label for up button
			wyBitmapFont* font = wyBitmapFont::loadFont(RES("R.raw.bitmapfont"));
			wyBitmapFontLabel* label = wyBitmapFontLabel::make(font, "Up");
			label->setColor(wyc3b(255, 255, 0));
			label->setPosition(DP(40), wyDevice::winHeight - DP(30));
			addChildLocked(label, 1);
			
			// down button
			button = new wyButton(normal, pressed, NULL, NULL, NULL,
					wyTargetSelector::make(this, SEL(wyUnsafeOpsTestLayer::onDown)));
			button->setPosition(DP(120), wyDevice::winHeight - DP(30));
			addChildLocked(button, 1);
			button->release();
			
			// label for down button
			label = wyBitmapFontLabel::make(font, "Down");
			label->setColor(wyc3b(255, 255, 0));
			label->setPosition(DP(120), wyDevice::winHeight - DP(30));
			addChildLocked(label, 1);
			
			// left button
			button = new wyButton(normal, pressed, NULL, NULL, NULL,
					wyTargetSelector::make(this, SEL(wyUnsafeOpsTestLayer::onLeft)));
			button->setPosition(DP(200), wyDevice::winHeight - DP(30));
			addChildLocked(button, 1);
			button->release();
			
			// label for left button
			label = wyBitmapFontLabel::make(font, "Left");
			label->setColor(wyc3b(255, 255, 0));
			label->setPosition(DP(200), wyDevice::winHeight - DP(30));
			addChildLocked(label, 1);
			
			// right button
			button = new wyButton(normal, pressed, NULL, NULL, NULL,
					wyTargetSelector::make(this, SEL(wyUnsafeOpsTestLayer::onRight)));
			button->setPosition(DP(280), wyDevice::winHeight - DP(30));
			addChildLocked(button, 1);
			button->release();
			
			// label for right button
			label = wyBitmapFontLabel::make(font, "Right");
			label->setColor(wyc3b(255, 255, 0));
			label->setPosition(DP(280), wyDevice::winHeight - DP(30));
			addChildLocked(label, 1);
		}
		
		virtual ~wyUnsafeOpsTestLayer() {
		}
		
		virtual void updateSpace(float delta) {
			if (mArrowDirection.y) {
				circleRadius = cpfmax(10.0f, circleRadius + mArrowDirection.y);
				
				for (int i = 0; i < NUM_CIRCLES; i++) {
					circles[i]->body->m = cpMomentForCircle(1.0f, 0.0f,
															circleRadius, cpvzero);
					cpCircleShapeSetRadius(circles[i], circleRadius);
				}
			}
			
			cpSpaceStep(space, delta);
		}
		
		virtual bool keyDown(wyKeyEvent& event) {
			mArrowDirection.x = 0;
			mArrowDirection.y = 0;
			switch (event.keyCode) {
				case KEYCODE_DPAD_UP:
					mArrowDirection.y++;
					break;
				case KEYCODE_DPAD_DOWN:
					mArrowDirection.y--;
					break;
				case KEYCODE_DPAD_RIGHT:
					mArrowDirection.x++;
					break;
				case KEYCODE_DPAD_LEFT:
					mArrowDirection.x--;
					break;
				default:
					return false;
			}
			
			return true;
		}
		
		void onUp(wyTargetSelector* ts) {
			mArrowDirection.x = 0;
			mArrowDirection.y = 0;
			mArrowDirection.y++;
		}

		void onDown(wyTargetSelector* ts) {
			mArrowDirection.x = 0;
			mArrowDirection.y = 0;
			mArrowDirection.y--;
		}

		void onLeft(wyTargetSelector* ts) {
			mArrowDirection.x = 0;
			mArrowDirection.y = 0;
			mArrowDirection.x--;
		}

		void onRight(wyTargetSelector* ts) {
			mArrowDirection.x = 0;
			mArrowDirection.y = 0;
			mArrowDirection.x++;
		}
	};
	
///////////////////////////////////////////////////////////////////////////////////////////////

}

using namespace Chipmunk;

#if ANDROID
	#define DEMO_ENTRY_IMPL(CLASSNAME) JNIEXPORT void JNICALL Java_com_wiyun_engine_tests_chipmunk_##CLASSNAME##_nativeStart \
		(JNIEnv *, jobject){ \
			wyLayer* layer = new wy##CLASSNAME##Layer(); \
			runDemo(layer, NULL); \
			wyObjectRelease(layer); \
		}
#elif IOS || MACOSX || WINDOWS
	#define DEMO_ENTRY_IMPL(CLASSNAME) void _chipmunk_##CLASSNAME##Launcher() { \
			wyLayer* layer = new wy##CLASSNAME##Layer(); \
			runDemo(layer, NULL); \
			wyObjectRelease(layer); \
		}
#endif

DEMO_ENTRY_IMPL(BodyDraggingTest);
DEMO_ENTRY_IMPL(BounceTest);
DEMO_ENTRY_IMPL(JointsTest);
#if MACOSX || WINDOWS
	DEMO_ENTRY_IMPL(LogoSmashTest);
#endif
DEMO_ENTRY_IMPL(MagnetsElectricTest);
DEMO_ENTRY_IMPL(OneWayTest);
DEMO_ENTRY_IMPL(PlanetTest);
DEMO_ENTRY_IMPL(PlayerTest);
DEMO_ENTRY_IMPL(PlinkTest);
DEMO_ENTRY_IMPL(PumpTest);
DEMO_ENTRY_IMPL(PyramidStackTest);
DEMO_ENTRY_IMPL(PyramidToppleTest);
DEMO_ENTRY_IMPL(QueryTest);
DEMO_ENTRY_IMPL(SensorTest);
DEMO_ENTRY_IMPL(ShapeAnimationTest);
DEMO_ENTRY_IMPL(SimpleTest);
DEMO_ENTRY_IMPL(SpringTest);
DEMO_ENTRY_IMPL(TankTest);
DEMO_ENTRY_IMPL(TexturedBounceTest);
DEMO_ENTRY_IMPL(TexturedOneWayTest);
DEMO_ENTRY_IMPL(TheoJansenTest);
DEMO_ENTRY_IMPL(TumbleTest);
DEMO_ENTRY_IMPL(UnsafeOpsTest);
DEMO_ENTRY_IMPL(PhysicsEditorTest);
