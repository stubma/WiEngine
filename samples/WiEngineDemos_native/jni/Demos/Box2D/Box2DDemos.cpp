#include "common.h"
#include "Box2DDemos.h"
#include "WiEngine.h"
#include "WiEngine-Box2D.h"
#include <math.h>

namespace Box2D {

class QueryCallback: public b2QueryCallback {
public:
	b2Vec2 m_point;
	b2Fixture* m_fixture;

public:
	QueryCallback(const b2Vec2& point) {
		m_point = point;
		m_fixture = NULL;
	}

	bool ReportFixture(b2Fixture* fixture) {
		b2Body* body = fixture->GetBody();
		if (body->GetType() == b2_dynamicBody) {
			bool inside = fixture->TestPoint(m_point);
			if (inside) {
				m_fixture = fixture;

				// We are done, terminate the query.
				return false;
			}
		}

		// Continue the query.
		return true;
	}
};

class wyBox2DTestLayer: public wyLayer {
protected:
	wyBox2D* m_box2d;
	b2Vec2 m_mouseWorld;
	b2MouseJoint* m_mouseJoint;
	b2Body* m_groundBody;
	int m_stepCount;

public:
	wyBox2DTestLayer() :
			wyLayer(),
			m_mouseJoint(NULL),
			m_stepCount(0) {
		m_box2d = new wyBox2D();
		m_box2d->setDebugDraw(true);
		addChildLocked(m_box2d);

		b2BodyDef bodyDef;
		m_groundBody = m_box2d->getWorld()->CreateBody(&bodyDef);

		setTouchEnabled(true);
	}

	virtual ~wyBox2DTestLayer() {
		m_box2d->release();
		m_box2d = NULL;
	}

	virtual void updateWorld(float dt) {
		m_box2d->getWorld()->Step(1.f / 60.f, 10, 10);
		m_box2d->getWorld()->ClearForces();
		m_stepCount++;
	}

	void onUpdateWorld(wyTargetSelector* ts) {
		updateWorld(ts->getDelta());
	}

	void startUpdateWorld() {
		wyTargetSelector* ts = wyTargetSelector::make(this, SEL(wyBox2DTestLayer::onUpdateWorld));
		wyTimer* t = wyTimer::make(ts);
		scheduleLocked(t);
	}

	virtual bool touchesBegan(wyMotionEvent& e) {
		wyPoint loc = m_box2d->worldToNodeSpace(wyp(e.x[0], e.y[0]));
		b2Vec2 p = b2Vec2(m_box2d->pixel2Meter(loc.x), m_box2d->pixel2Meter(loc.y));
		m_mouseWorld = p;

		if (m_mouseJoint != NULL) {
			return false;
		}

		// Make a small box.
		b2AABB aabb;
		b2Vec2 d;
		d.Set(0.001f, 0.001f);
		aabb.lowerBound = p - d;
		aabb.upperBound = p + d;

		// Query the world for overlapping shapes.
		QueryCallback callback(p);
		m_box2d->getWorld()->QueryAABB(&callback, aabb);

		if (callback.m_fixture) {
			b2Body* body = callback.m_fixture->GetBody();
			b2MouseJointDef md;
			md.bodyA = m_groundBody;
			md.bodyB = body;
			md.target = p;
			md.maxForce = 1000.0f * body->GetMass();
			m_mouseJoint = (b2MouseJoint*)m_box2d->getWorld()->CreateJoint(&md);
			body->SetAwake(true);

			return true;
		}

		return false;
	}

	virtual bool touchesMoved(wyMotionEvent& e) {
		wyPoint loc = m_box2d->worldToNodeSpace(wyp(e.x[0], e.y[0]));
		b2Vec2 p = b2Vec2(m_box2d->pixel2Meter(loc.x), m_box2d->pixel2Meter(loc.y));
		m_mouseWorld = p;

		if (m_mouseJoint) {
			m_mouseJoint->SetTarget(p);
		}

		return true;
	}

	virtual bool touchesEnded(wyMotionEvent& e) {
		if (m_mouseJoint) {
			m_box2d->getWorld()->DestroyJoint(m_mouseJoint);
			m_mouseJoint = NULL;
		}

		return true;
	}

	virtual bool touchesCancelled(wyMotionEvent& e) {
		if (m_mouseJoint) {
			m_box2d->getWorld()->DestroyJoint(m_mouseJoint);
			m_mouseJoint = NULL;
		}

		return true;
	}

	static float frand() {
		return (float) rand() / RAND_MAX;
	}

	static float frand_unit() {
		return 2.0f * rand() / RAND_MAX - 1.0f;
	}

	static float RandomFloat() {
		float r = (float)rand();
		r /= RAND_MAX;
		r = 2.0f * r - 1.0f;
		return r;
	}

	static float RandomFloat(float lo, float hi) {
		float r = (float) rand();
		r /= RAND_MAX;
		r = (hi - lo) * r + lo;
		return r;
	}
};

/////////////////////////////////////////////////////////////////////////////////////////

class wyApplyForceTestLayer : public wyBox2DTestLayer {
private:
	b2Body* m_body;

public:
	wyApplyForceTestLayer() {
		b2World* world = m_box2d->getWorld();

		// place box2d to center of bottom edge
		m_box2d->setPosition(wyDevice::winWidth / 2, 0);

		const float32 k_restitution = 0.4f;
		b2Body* ground;
		{
			b2BodyDef bd;
			ground = world->CreateBody(&bd);

			b2EdgeShape shape;

			b2FixtureDef sd;
			sd.shape = &shape;
			sd.density = 0.0f;
			sd.restitution = k_restitution;

			// Left vertical
			shape.Set(b2Vec2(-10.0f, 0.0f),
					b2Vec2(-10.0f, m_box2d->pixel2Meter(wyDevice::winHeight)));
			ground->CreateFixture(&sd);

			// Right vertical
			shape.Set(b2Vec2(10.0f, 0.0f),
					b2Vec2(10.0f, m_box2d->pixel2Meter(wyDevice::winHeight)));
			ground->CreateFixture(&sd);

			// Top horizontal
			shape.Set(b2Vec2(-10.0f, m_box2d->pixel2Meter(wyDevice::winHeight)),
					b2Vec2(10.0f, m_box2d->pixel2Meter(wyDevice::winHeight)));
			ground->CreateFixture(&sd);

			// Bottom horizontal
			shape.Set(b2Vec2(-10.0f, 0.0f), b2Vec2(10.0f, 0.0f));
			ground->CreateFixture(&sd);
		}

		{
			b2Transform xf1;
			xf1.q.Set(0.3524f * b2_pi);
			xf1.p = b2Mul(xf1.q, b2Vec2(1.0f, 0.0f));

			b2Vec2 vertices[3];
			vertices[0] = b2Mul(xf1, b2Vec2(-1.0f, 0.0f));
			vertices[1] = b2Mul(xf1, b2Vec2(1.0f, 0.0f));
			vertices[2] = b2Mul(xf1, b2Vec2(0.0f, 0.5f));

			b2PolygonShape poly1;
			poly1.Set(vertices, 3);

			b2FixtureDef sd1;
			sd1.shape = &poly1;
			sd1.density = 4.0f;

			b2Transform xf2;
			xf2.q.Set(-0.3524f * b2_pi);
			xf2.p = b2Mul(xf2.q, b2Vec2(-1.0f, 0.0f));

			vertices[0] = b2Mul(xf2, b2Vec2(-1.0f, 0.0f));
			vertices[1] = b2Mul(xf2, b2Vec2(1.0f, 0.0f));
			vertices[2] = b2Mul(xf2, b2Vec2(0.0f, 0.5f));

			b2PolygonShape poly2;
			poly2.Set(vertices, 3);

			b2FixtureDef sd2;
			sd2.shape = &poly2;
			sd2.density = 2.0f;

			b2BodyDef bd;
			bd.type = b2_dynamicBody;
			bd.angularDamping = 5.0f;
			bd.linearDamping = 0.1f;

			bd.position.Set(0.0f, 2.0);
			bd.angle = b2_pi;
			bd.allowSleep = false;
			m_body = world->CreateBody(&bd);
			m_body->CreateFixture(&sd1);
			m_body->CreateFixture(&sd2);
		}

		{
			b2PolygonShape shape;
			shape.SetAsBox(0.5f, 0.5f);

			b2FixtureDef fd;
			fd.shape = &shape;
			fd.density = 1.0f;
			fd.friction = 0.3f;

			for (int i = 0; i < 10; ++i)
			{
				b2BodyDef bd;
				bd.type = b2_dynamicBody;

				bd.position.Set(0.0f, 5.0f + 1.54f * i);
				b2Body* body = world->CreateBody(&bd);

				body->CreateFixture(&fd);

				float32 gravity = 10.0f;
				float32 I = body->GetInertia();
				float32 mass = body->GetMass();

				// For a circle: I = 0.5 * m * r * r ==> r = sqrt(2 * I / m)
				float32 radius = b2Sqrt(2.0f * I / mass);

				b2FrictionJointDef jd;
				jd.localAnchorA.SetZero();
				jd.localAnchorB.SetZero();
				jd.bodyA = ground;
				jd.bodyB = body;
				jd.collideConnected = true;
				jd.maxForce = mass * gravity;
				jd.maxTorque = mass * radius * gravity;

				world->CreateJoint(&jd);
			}
		}

		setKeyEnabled(true);

		// speed button
		wyNinePatchSprite* normal = wyNinePatchSprite::make(wyTexture2D::makePNG(RES("R.drawable.btn_normal")), wyr(DP(9), DP(7), DP(22), DP(28)));
		wyNinePatchSprite* pressed = wyNinePatchSprite::make(wyTexture2D::makePNG(RES("R.drawable.btn_pressed")), wyr(DP(9), DP(7), DP(22), DP(28)));
		normal->setContentSize(DP(100), DP(44));
		pressed->setContentSize(DP(100), DP(44));
		wyButton* button = new wyButton(normal, pressed, NULL, NULL, NULL, wyTargetSelector::make(this, SEL(wyApplyForceTestLayer::onSpeed)));
		button->setPosition(DP(55), wyDevice::winHeight - DP(30));
		addChildLocked(button, 1);
		button->release();

		// label for speed button
		wyBitmapFont* font = wyBitmapFont::loadFont(RES("R.raw.bitmapfont"));
		wyBitmapFontLabel* label = wyBitmapFontLabel::make(font, "Speed");
		label->setColor(wyc3b(255, 255, 0));
		label->setPosition(DP(55), wyDevice::winHeight - DP(30));
		addChildLocked(label, 1);

		// left button
		button = new wyButton(normal, pressed, NULL, NULL, NULL, wyTargetSelector::make(this, SEL(wyApplyForceTestLayer::onLeft)));
		button->setPosition(DP(160), wyDevice::winHeight - DP(30));
		addChildLocked(button, 1);
		button->release();

		// label for left button
		label = wyBitmapFontLabel::make(font, "Left");
		label->setColor(wyc3b(255, 255, 0));
		label->setPosition(DP(160), wyDevice::winHeight - DP(30));
		addChildLocked(label, 1);

		// right button
		button = new wyButton(normal, pressed, NULL, NULL, NULL, wyTargetSelector::make(this, SEL(wyApplyForceTestLayer::onRight)));
		button->setPosition(DP(265), wyDevice::winHeight - DP(30));
		addChildLocked(button, 1);
		button->release();

		// label for right button
		label = wyBitmapFontLabel::make(font, "Right");
		label->setColor(wyc3b(255, 255, 0));
		label->setPosition(DP(265), wyDevice::winHeight - DP(30));
		addChildLocked(label, 1);

		startUpdateWorld();
	}

	virtual ~wyApplyForceTestLayer() {
	}

	virtual bool keyDown(wyKeyEvent& event) {
		switch(event.keyCode) {
			case KEYCODE_DPAD_UP:
			{
				b2Vec2 f = m_body->GetWorldVector(b2Vec2(0.0f, -200.0f));
				b2Vec2 p = m_body->GetWorldPoint(b2Vec2(0.0f, 2.0f));
				m_body->ApplyForce(f, p);
				break;
			}
			case KEYCODE_DPAD_LEFT:
				m_body->ApplyTorque(50.0f);
				break;
			case KEYCODE_DPAD_RIGHT:
				m_body->ApplyTorque(-50.0f);
				break;
			case KEYCODE_BACK:
				wyDirector::getInstance()->popScene();
				break;
			default:
				return false;
		}

		return true;
	}

	void onRight(wyTargetSelector* ts) {
		m_body->ApplyTorque(-50.0f);
	}

	void onLeft(wyTargetSelector* ts) {
		m_body->ApplyTorque(50.0f);
	}

	void onSpeed(wyTargetSelector* ts) {
		b2Vec2 f = m_body->GetWorldVector(b2Vec2(0.0f, -200.0f));
		b2Vec2 p = m_body->GetWorldPoint(b2Vec2(0.0f, 2.0f));
		m_body->ApplyForce(f, p);
	}
};

///////////////////////////////////////////////////////////////////////////////////////

class wyBodyTypesTestLayer : public wyBox2DTestLayer {
private:
	b2Body* m_attachment;
	b2Body* m_platform;
	float32 m_speed;

public:
	wyBodyTypesTestLayer() {
		b2World* world = m_box2d->getWorld();

		// set gravity
		world->SetGravity(b2Vec2(0, -10));

		// place box2d to center of bottom edge
		m_box2d->setPosition(wyDevice::winWidth / 2, 0);

		b2Body* ground = NULL;
		{
			b2BodyDef bd;
			ground = world->CreateBody(&bd);

			b2EdgeShape shape;
			shape.Set(b2Vec2(-20.0f, 0.0f), b2Vec2(20.0f, 0.0f));

			b2FixtureDef fd;
			fd.shape = &shape;

			ground->CreateFixture(&fd);
		}

		// Define attachment
		{
			b2BodyDef bd;
			bd.type = b2_dynamicBody;
			bd.position.Set(0.0f, 3.0f);
			m_attachment = world->CreateBody(&bd);

			b2PolygonShape shape;
			shape.SetAsBox(0.5f, 2.0f);
			m_attachment->CreateFixture(&shape, 2.0f);
		}

		// Define platform
		{
			b2BodyDef bd;
			bd.type = b2_dynamicBody;
			bd.position.Set(-4.0f, 5.0f);
			m_platform = world->CreateBody(&bd);

			b2PolygonShape shape;
			shape.SetAsBox(0.5f, 4.0f, b2Vec2(4.0f, 0.0f), 0.5f * b2_pi);

			b2FixtureDef fd;
			fd.shape = &shape;
			fd.friction = 0.6f;
			fd.density = 2.0f;
			m_platform->CreateFixture(&fd);

			b2RevoluteJointDef rjd;
			rjd.Initialize(m_attachment, m_platform, b2Vec2(0.0f, 5.0f));
			rjd.maxMotorTorque = 50.0f;
			rjd.enableMotor = true;
			world->CreateJoint(&rjd);

			b2PrismaticJointDef pjd;
			pjd.Initialize(ground, m_platform, b2Vec2(0.0f, 5.0f), b2Vec2(1.0f, 0.0f));

			pjd.maxMotorForce = 1000.0f;
			pjd.enableMotor = true;
			pjd.lowerTranslation = -10.0f;
			pjd.upperTranslation = 10.0f;
			pjd.enableLimit = true;

			(b2PrismaticJoint*)world->CreateJoint(&pjd);

			m_speed = 3.0f;
		}

		// Create a payload
		{
			b2BodyDef bd;
			bd.type = b2_dynamicBody;
			bd.position.Set(0.0f, 8.0f);
			b2Body* body = world->CreateBody(&bd);

			b2PolygonShape shape;
			shape.SetAsBox(0.75f, 0.75f);

			b2FixtureDef fd;
			fd.shape = &shape;
			fd.friction = 0.6f;
			fd.density = 2.0f;

			body->CreateFixture(&fd);
		}

		setKeyEnabled(true);

		// dynamic button
		wyNinePatchSprite* normal = wyNinePatchSprite::make(wyTexture2D::makePNG(RES("R.drawable.btn_normal")), wyr(DP(9), DP(7), DP(22), DP(28)));
		wyNinePatchSprite* pressed = wyNinePatchSprite::make(wyTexture2D::makePNG(RES("R.drawable.btn_pressed")), wyr(DP(9), DP(7), DP(22), DP(28)));
		normal->setContentSize(DP(100), DP(44));
		pressed->setContentSize(DP(100), DP(44));
		wyButton* button = new wyButton(normal, pressed, NULL, NULL, NULL, wyTargetSelector::make(this, SEL(wyBodyTypesTestLayer::onDynamic)));
		button->setPosition(DP(55), wyDevice::winHeight - DP(30));
		addChildLocked(button, 1);
		button->release();

		// label for dynamic button
		wyBitmapFont* font = wyBitmapFont::loadFont(RES("R.raw.bitmapfont"));
		wyBitmapFontLabel* label = wyBitmapFontLabel::make(font, "Dynamic");
		label->setColor(wyc3b(255, 255, 0));
		label->setPosition(DP(55), wyDevice::winHeight - DP(30));
		addChildLocked(label, 1);

		// static button
		button = new wyButton(normal, pressed, NULL, NULL, NULL, wyTargetSelector::make(this, SEL(wyBodyTypesTestLayer::onStatic)));
		button->setPosition(DP(160), wyDevice::winHeight - DP(30));
		addChildLocked(button, 1);
		button->release();

		// label for static button
		label = wyBitmapFontLabel::make(font, "Static");
		label->setColor(wyc3b(255, 255, 0));
		label->setPosition(DP(160), wyDevice::winHeight - DP(30));
		addChildLocked(label, 1);

		// kinematic button
		button = new wyButton(normal, pressed, NULL, NULL, NULL, wyTargetSelector::make(this, SEL(wyBodyTypesTestLayer::onKinematic)));
		button->setPosition(DP(265), wyDevice::winHeight - DP(30));
		addChildLocked(button, 1);
		button->release();

		// label for kinematic button
		label = wyBitmapFontLabel::make(font, "Kinematic");
		label->setColor(wyc3b(255, 255, 0));
		label->setPosition(DP(265), wyDevice::winHeight - DP(30));
		addChildLocked(label, 1);

		startUpdateWorld();
	}

	virtual ~wyBodyTypesTestLayer() {
	}

	virtual void updateWorld(float delta) {
		// Drive the kinematic body.
		if (m_platform->GetType() == b2_kinematicBody)
		{
			b2Vec2 p = m_platform->GetTransform().p;
			b2Vec2 v = m_platform->GetLinearVelocity();

			if ((p.x < -10.0f && v.x < 0.0f) ||
				(p.x > 10.0f && v.x > 0.0f))
			{
				v.x = -v.x;
				m_platform->SetLinearVelocity(v);
			}
		}

		wyBox2DTestLayer::updateWorld(delta);
	}

	virtual bool keyDown(wyKeyEvent& event) {
		switch(event.keyCode) {
			case KEYCODE_DPAD_UP:
				m_platform->SetType(b2_dynamicBody);
				break;
			case KEYCODE_DPAD_LEFT:
				m_platform->SetType(b2_staticBody);
				break;
			case KEYCODE_DPAD_RIGHT:
				m_platform->SetType(b2_kinematicBody);
				m_platform->SetLinearVelocity(b2Vec2(-m_speed, 0.0f));
				m_platform->SetAngularVelocity(0.0f);
				break;
			case KEYCODE_BACK:
				wyDirector::getInstance()->popScene();
				break;
			default:
				return false;
		}

		return true;
	}

	void onKinematic(wyTargetSelector* ts) {
		m_platform->SetType(b2_kinematicBody);
		m_platform->SetLinearVelocity(b2Vec2(-m_speed, 0.0f));
		m_platform->SetAngularVelocity(0.0f);
	}

	void onStatic(wyTargetSelector* ts) {
		m_platform->SetType(b2_staticBody);
	}

	void onDynamic(wyTargetSelector* ts) {
		m_platform->SetType(b2_dynamicBody);
	}
};

/////////////////////////////////////////////////////////////////////////////////////////////////

class wyBounceTestLayer: public wyBox2DTestLayer {
public:
	wyBounceTestLayer() {
		b2World* world = m_box2d->getWorld();

		// place box2d to center of bottom edge
		m_box2d->setPosition(wyDevice::winWidth / 2, wyDevice::winHeight / 2);

		// meter size of screen
		float meterWidth = m_box2d->pixel2Meter(wyDevice::winWidth);
		float meterHeight = m_box2d->pixel2Meter(wyDevice::winHeight);

		// border
		b2Body* ground = NULL;
		{
			b2BodyDef bd;
			ground = world->CreateBody(&bd);

			// bottom edge
			b2EdgeShape bottom;
			bottom.Set(b2Vec2(-meterWidth / 2, -meterHeight / 2), b2Vec2(meterWidth / 2, -meterHeight / 2));
			b2FixtureDef fd;
			fd.shape = &bottom;
			ground->CreateFixture(&fd);

			// top edge
			b2EdgeShape top;
			top.Set(b2Vec2(-meterWidth / 2, meterHeight / 2), b2Vec2(meterWidth / 2, meterHeight / 2));
			fd.shape = &top;
			ground->CreateFixture(&fd);

			// left edge
			b2EdgeShape left;
			left.Set(b2Vec2(-meterWidth / 2, -meterHeight / 2), b2Vec2(-meterWidth / 2, meterHeight / 2));
			fd.shape = &left;
			ground->CreateFixture(&fd);

			// right edge
			b2EdgeShape right;
			right.Set(b2Vec2(meterWidth / 2, -meterHeight / 2), b2Vec2(meterWidth / 2, meterHeight / 2));
			fd.shape = &right;
			ground->CreateFixture(&fd);
		}

		// boxes
		for (int i = 0; i < 10; i++) {
			b2BodyDef bd;
			bd.type = b2_dynamicBody;
			bd.position.Set(frand_unit() * meterWidth / 2, frand_unit() * meterHeight / 2);
			bd.linearVelocity = b2Vec2(5 * frand_unit(), 5 * frand_unit());
			b2Body* body = world->CreateBody(&bd);
			body->SetTransform(bd.position, frand() * 2 * M_PI);

			b2PolygonShape box;
			box.SetAsBox(0.5, 0.5);
			b2FixtureDef fd;
			fd.shape = &box;
			fd.restitution = 1.0f;
			fd.friction = 0.0f;
			fd.density = 1.0f;
			body->CreateFixture(&fd);
		}

		// center stick
		{
			b2BodyDef bd;
			bd.type = b2_dynamicBody;
			bd.position.Set(0, 0);
			b2Body* stickBody = world->CreateBody(&bd);

			b2PolygonShape stick;
			stick.SetAsBox(meterWidth / 4, 0.4f);
			b2FixtureDef fd;
			fd.shape = &stick;
			fd.restitution = 1.0f;
			fd.friction = 0.0f;
			fd.density = 1.0f;
			stickBody->CreateFixture(&fd);

			b2RevoluteJointDef jd;
			jd.bodyA = ground;
			jd.bodyB = stickBody;
			jd.localAnchorA = b2Vec2(0, 0);
			jd.localAnchorB = b2Vec2(0, 0);
			world->CreateJoint(&jd);
		}

		startUpdateWorld();
	}

	virtual ~wyBounceTestLayer() {
	}
};

//////////////////////////////////////////////////////////////////////////////////

class wyBreakableTestLayer : public wyBox2DTestLayer, public b2ContactListener {
private:
	b2Body* m_body1;
	b2Vec2 m_velocity;
	float32 m_angularVelocity;
	b2PolygonShape m_shape1;
	b2PolygonShape m_shape2;
	b2Fixture* m_piece1;
	b2Fixture* m_piece2;

	bool m_broke;
	bool m_break;

public:
	wyBreakableTestLayer() {
		b2World* world = m_box2d->getWorld();

		// place box2d to center of bottom edge
		m_box2d->setPosition(wyDevice::winWidth / 2, 0);

		// set gravity
		world->SetGravity(b2Vec2(0, -10));

		// set contact listener
		world->SetContactListener(this);

		// Ground body
		{
			b2BodyDef bd;
			b2Body* ground = world->CreateBody(&bd);

			b2EdgeShape shape;
			shape.Set(b2Vec2(-40.0f, 0.0f), b2Vec2(40.0f, 0.0f));
			ground->CreateFixture(&shape, 0.0f);
		}

		// Breakable dynamic body
		{
			b2BodyDef bd;
			bd.type = b2_dynamicBody;
			bd.position.Set(0, m_box2d->pixel2Meter(wyDevice::winHeight));
			bd.angle = 0.25f * b2_pi;
			m_body1 = world->CreateBody(&bd);

			m_shape1.SetAsBox(0.5f, 0.5f, b2Vec2(-0.5f, 0.0f), 0.0f);
			m_piece1 = m_body1->CreateFixture(&m_shape1, 1.0f);

			m_shape2.SetAsBox(0.5f, 0.5f, b2Vec2(0.5f, 0.0f), 0.0f);
			m_piece2 = m_body1->CreateFixture(&m_shape2, 1.0f);
		}

		m_break = false;
		m_broke = false;

		startUpdateWorld();
	}

	virtual ~wyBreakableTestLayer() {
	}

	virtual void updateWorld(float delta) {
		if(m_break) {
			Break();
			m_broke = true;
			m_break = false;
		}

		// Cache velocities to improve movement on breakage.
		if(m_broke == false) {
			m_velocity = m_body1->GetLinearVelocity();
			m_angularVelocity = m_body1->GetAngularVelocity();
		}

		wyBox2DTestLayer::updateWorld(delta);
	}

	virtual void PostSolve(b2Contact* contact, const b2ContactImpulse* impulse) {
		if(m_broke) {
			// The body already broke.
			return;
		}

		// Should the body break?
		int32 count = contact->GetManifold()->pointCount;

		float32 maxImpulse = 0.0f;
		for(int32 i = 0; i < count; ++i) {
			maxImpulse = b2Max(maxImpulse, impulse->normalImpulses[i]);
		}

		if(maxImpulse > 40.0f) {
			// Flag the body for breaking.
			m_break = true;
		}
	}

	void Break() {
		// Create two bodies from one.
		b2Body* body1 = m_piece1->GetBody();
		b2Vec2 center = body1->GetWorldCenter();

		body1->DestroyFixture(m_piece2);
		m_piece2 = NULL;

		b2BodyDef bd;
		bd.type = b2_dynamicBody;
		bd.position = body1->GetPosition();
		bd.angle = body1->GetAngle();

		b2Body* body2 = m_box2d->getWorld()->CreateBody(&bd);
		m_piece2 = body2->CreateFixture(&m_shape2, 1.0f);

		// Compute consistent velocities for new bodies based on
		// cached velocity.
		b2Vec2 center1 = body1->GetWorldCenter();
		b2Vec2 center2 = body2->GetWorldCenter();

		b2Vec2 velocity1 = m_velocity + b2Cross(m_angularVelocity, center1 - center);
		b2Vec2 velocity2 = m_velocity + b2Cross(m_angularVelocity, center2 - center);

		body1->SetAngularVelocity(m_angularVelocity);
		body1->SetLinearVelocity(velocity1);

		body2->SetAngularVelocity(m_angularVelocity);
		body2->SetLinearVelocity(velocity2);
	}
};

///////////////////////////////////////////////////////////////////////////////////////

class wyBridgeTestLayer : public wyBox2DTestLayer {
private:
	b2Body* m_middle;

public:
	enum
	{
		e_count = 30,
	};

	wyBridgeTestLayer() {
		// get world
		b2World* world = m_box2d->getWorld();

		// set gravity
		world->SetGravity(b2Vec2(0, -10));

		// place box2d to center of bottom edge
		m_box2d->setPosition(wyDevice::winWidth / 2, 0);

		b2Body* ground = NULL;
		{
			b2BodyDef bd;
			ground = world->CreateBody(&bd);

			b2EdgeShape shape;
			shape.Set(b2Vec2(-40.0f, 0.0f), b2Vec2(40.0f, 0.0f));
			ground->CreateFixture(&shape, 0.0f);
		}

		{
			b2PolygonShape shape;
			shape.SetAsBox(0.5f, 0.125f);

			b2FixtureDef fd;
			fd.shape = &shape;
			fd.density = 20.0f;
			fd.friction = 0.2f;

			b2RevoluteJointDef jd;

			b2Body* prevBody = ground;
			for (int32 i = 0; i < e_count; ++i)
			{
				b2BodyDef bd;
				bd.type = b2_dynamicBody;
				bd.position.Set(-14.5f + 1.0f * i, 5.0f);
				b2Body* body = world->CreateBody(&bd);
				body->CreateFixture(&fd);

				b2Vec2 anchor(-15.0f + 1.0f * i, 5.0f);
				jd.Initialize(prevBody, body, anchor);
				world->CreateJoint(&jd);

				if (i == (e_count >> 1))
				{
					m_middle = body;
				}
				prevBody = body;
			}

			b2Vec2 anchor(-15.0f + 1.0f * e_count, 5.0f);
			jd.Initialize(prevBody, ground, anchor);
			world->CreateJoint(&jd);
		}

		for (int32 i = 0; i < 2; ++i)
		{
			b2Vec2 vertices[3];
			vertices[0].Set(-0.5f, 0.0f);
			vertices[1].Set(0.5f, 0.0f);
			vertices[2].Set(0.0f, 1.5f);

			b2PolygonShape shape;
			shape.Set(vertices, 3);

			b2FixtureDef fd;
			fd.shape = &shape;
			fd.density = 1.0f;

			b2BodyDef bd;
			bd.type = b2_dynamicBody;
			bd.position.Set(-8.0f + 8.0f * i, 12.0f);
			b2Body* body = world->CreateBody(&bd);
			body->CreateFixture(&fd);
		}

		for (int32 i = 0; i < 3; ++i)
		{
			b2CircleShape shape;
			shape.m_radius = 0.5f;

			b2FixtureDef fd;
			fd.shape = &shape;
			fd.density = 1.0f;

			b2BodyDef bd;
			bd.type = b2_dynamicBody;
			bd.position.Set(-6.0f + 6.0f * i, 10.0f);
			b2Body* body = world->CreateBody(&bd);
			body->CreateFixture(&fd);
		}

		startUpdateWorld();
	}

	virtual ~wyBridgeTestLayer() {
	}
};

//////////////////////////////////////////////////////////////////////////////////////

class wyBulletTestLayer : public wyBox2DTestLayer {
private:
	b2Body* m_body;
	b2Body* m_bullet;
	float32 m_x;

public:
	wyBulletTestLayer() {
		b2World* world = m_box2d->getWorld();

		// set gravity
		world->SetGravity(b2Vec2(0, -10));

		// place box2d to center of bottom edge
		m_box2d->setPosition(wyDevice::winWidth / 2, 0);

		{
			b2BodyDef bd;
			bd.position.Set(0.0f, 0.0f);
			b2Body* body = world->CreateBody(&bd);

			b2EdgeShape edge;

			edge.Set(b2Vec2(-10.0f, 0.0f), b2Vec2(10.0f, 0.0f));
			body->CreateFixture(&edge, 0.0f);

			b2PolygonShape shape;
			shape.SetAsBox(0.2f, 1.0f, b2Vec2(0.5f, 1.0f), 0.0f);
			body->CreateFixture(&shape, 0.0f);
		}

		{
			b2BodyDef bd;
			bd.type = b2_dynamicBody;
			bd.position.Set(0.0f, 4.0f);

			b2PolygonShape box;
			box.SetAsBox(2.0f, 0.1f);

			m_body = world->CreateBody(&bd);
			m_body->CreateFixture(&box, 1.0f);

			box.SetAsBox(0.25f, 0.25f);

			m_x = 0.20352793f;
			bd.position.Set(m_x, 10.0f);
			bd.bullet = true;

			m_bullet = world->CreateBody(&bd);
			m_bullet->CreateFixture(&box, 100.0f);

			m_bullet->SetLinearVelocity(b2Vec2(0.0f, -50.0f));
		}

		startUpdateWorld();
	}

	virtual ~wyBulletTestLayer() {
	}

	void Launch() {
		m_body->SetTransform(b2Vec2(0.0f, 4.0f), 0.0f);
		m_body->SetLinearVelocity(b2Vec2_zero);
		m_body->SetAngularVelocity(0.0f);

		m_x = frand_unit();
		m_bullet->SetTransform(b2Vec2(m_x, 10.0f), 0.0f);
		m_bullet->SetLinearVelocity(b2Vec2(0.0f, -50.0f));
		m_bullet->SetAngularVelocity(0.0f);
	}

	virtual void updateWorld(float delta) {
		wyBox2DTestLayer::updateWorld(delta);

		if(m_stepCount % 60 == 0) {
			Launch();
		}
	}
};

////////////////////////////////////////////////////////////////////////////////

class wyBuoyancyTestLayer : public wyBox2DTestLayer {
private:
    enum
	{
		e_maxBodies = 256,
	};

	int32 m_bodyIndex;
	b2Body* m_bodies[e_maxBodies];
    b2PolygonShape m_polygons[4];
	b2CircleShape m_circle;
    b2BuoyancyController* m_bc;

public:
	wyBuoyancyTestLayer() {
		// get world
		b2World* world = m_box2d->getWorld();

		// set gravity
		world->SetGravity(b2Vec2(0, -10));

		// place box2d to center of bottom edge
		m_box2d->setPosition(wyDevice::winWidth / 2, 0);

        // create shapes
        {
			b2Vec2 vertices[3];
			vertices[0].Set(-0.5f, 0.0f);
			vertices[1].Set(0.5f, 0.0f);
			vertices[2].Set(0.0f, 1.5f);
			m_polygons[0].Set(vertices, 3);
		}
		{
			b2Vec2 vertices[3];
			vertices[0].Set(-0.1f, 0.0f);
			vertices[1].Set(0.1f, 0.0f);
			vertices[2].Set(0.0f, 1.5f);
			m_polygons[1].Set(vertices, 3);
		}
		{
			float32 w = 1.0f;
			float32 b = w / (2.0f + b2Sqrt(2.0f));
			float32 s = b2Sqrt(2.0f) * b;

			b2Vec2 vertices[8];
			vertices[0].Set(0.5f * s, 0.0f);
			vertices[1].Set(0.5f * w, b);
			vertices[2].Set(0.5f * w, b + s);
			vertices[3].Set(0.5f * s, w);
			vertices[4].Set(-0.5f * s, w);
			vertices[5].Set(-0.5f * w, b + s);
			vertices[6].Set(-0.5f * w, b);
			vertices[7].Set(-0.5f * s, 0.0f);

			m_polygons[2].Set(vertices, 8);
		}
		{
			m_polygons[3].SetAsBox(0.5f, 0.5f);
		}
		{
			m_circle.m_radius = 0.5f;
		}
		m_bodyIndex = 0;
		memset(m_bodies, 0, sizeof(m_bodies));

        // create controller
        b2BuoyancyControllerDef cd;
        cd.normal = b2Vec2(0, 1);
        cd.offset = m_box2d->pixel2Meter(wyDevice::winHeight / 2);
        cd.density = 2;
        cd.useWorldGravity = true;
        cd.useDensity = true;
        cd.linearDrag = 2;
        cd.angularDrag = 1;
        m_bc = (b2BuoyancyController*)world->CreateController(&cd);

        // add a layer for water surface
        wyColorLayer* waterLayer = wyColorLayer::make(wyc4b(0, 0, 255, 100));
        waterLayer->setContentSize(wyDevice::winWidth, wyDevice::winHeight / 2);
        addChildLocked(waterLayer, 1);

        // create button
		wyNinePatchSprite* normal = wyNinePatchSprite::make(wyTexture2D::makePNG(RES("R.drawable.btn_normal")), wyr(DP(9), DP(7), DP(22), DP(28)));
		wyNinePatchSprite* pressed = wyNinePatchSprite::make(wyTexture2D::makePNG(RES("R.drawable.btn_pressed")), wyr(DP(9), DP(7), DP(22), DP(28)));
		normal->setContentSize(DP(150), DP(44));
		pressed->setContentSize(DP(150), DP(44));
		wyButton* button = new wyButton(normal, pressed, NULL, NULL, NULL, wyTargetSelector::make(this, SEL(wyBuoyancyTestLayer::onCreate)));
		button->setPosition(DP(80), wyDevice::winHeight - DP(30));
		addChildLocked(button, 1);
		button->release();

		// label for create button
		wyBitmapFont* font = wyBitmapFont::loadFont(RES("R.raw.bitmapfont"));
		wyBitmapFontLabel* label = wyBitmapFontLabel::make(font, "Create Shape");
		label->setColor(wyc3b(255, 255, 0));
		label->setPosition(DP(80), wyDevice::winHeight - DP(30));
		addChildLocked(label, 1);

		// destroy button
		button = new wyButton(normal, pressed, NULL, NULL, NULL, wyTargetSelector::make(this, SEL(wyBuoyancyTestLayer::onDestroy)));
		button->setPosition(DP(240), wyDevice::winHeight - DP(30));
		addChildLocked(button, 1);
		button->release();

		// label for destroy button
		label = wyBitmapFontLabel::make(font, "Destroy Shape");
		label->setColor(wyc3b(255, 255, 0));
		label->setPosition(DP(240), wyDevice::winHeight - DP(30));
		addChildLocked(label, 1);

		startUpdateWorld();
	}

	virtual ~wyBuoyancyTestLayer() {
	}

    void Create(int32 index)
	{
		// get world
		b2World* world = m_box2d->getWorld();

		if (m_bodies[m_bodyIndex] != NULL)
		{
			world->DestroyBody(m_bodies[m_bodyIndex]);
			m_bodies[m_bodyIndex] = NULL;
		}

		b2BodyDef bd;

		float32 x = RandomFloat(-10.0f, 10.0f);
		float32 y = RandomFloat(10.0f, 20.0f);
		bd.position.Set(x, y);
		bd.angle = RandomFloat(-b2_pi, b2_pi);
		bd.type = b2_dynamicBody;

		if (index == 4)
		{
			bd.angularDamping = 0.02f;
		}

		m_bodies[m_bodyIndex] = world->CreateBody(&bd);

		if (index < 4)
		{
			b2FixtureDef fd;
			fd.shape = m_polygons + index;
			fd.friction = 0.3f;
			fd.density = 1;
			m_bodies[m_bodyIndex]->CreateFixture(&fd);
		}
		else
		{
			b2FixtureDef fd;
			fd.shape = &m_circle;
			fd.friction = 0.3f;
			fd.density = 1;
			m_bodies[m_bodyIndex]->CreateFixture(&fd);
		}

        // add to controller
        m_bc->AddBody(m_bodies[m_bodyIndex]);

		m_bodyIndex = (m_bodyIndex + 1) % e_maxBodies;
	}

	void DestroyBody()
	{
		for (int32 i = 0; i < e_maxBodies; ++i)
		{
			if (m_bodies[i] != NULL)
			{
				m_box2d->getWorld()->DestroyBody(m_bodies[i]);
				m_bodies[i] = NULL;
				return;
			}
		}
	}

    void onDestroy(wyTargetSelector* ts) {
    	DestroyBody();
    }

    void onCreate(wyTargetSelector* ts) {
    	Create(rand() % 5);
    }
};

/////////////////////////////////////////////////////////////////////////////////

class wyCantileverTestLayer : public wyBox2DTestLayer {
private:
	b2Body* m_middle;

public:
	wyCantileverTestLayer() {
		enum
		{
			e_count = 8,
		};

		b2World* world = m_box2d->getWorld();

		// set gravity
		world->SetGravity(b2Vec2(0, -10));

		// place box2d to center of bottom edge
		m_box2d->setPosition(wyDevice::winWidth / 2, 0);

		b2Body* ground = NULL;
		{
			b2BodyDef bd;
			ground = world->CreateBody(&bd);

			b2EdgeShape shape;
			shape.Set(b2Vec2(-40.0f, 0.0f), b2Vec2(40.0f, 0.0f));
			ground->CreateFixture(&shape, 0.0f);
		}

		{
			b2PolygonShape shape;
			shape.SetAsBox(0.5f, 0.125f);

			b2FixtureDef fd;
			fd.shape = &shape;
			fd.density = 20.0f;

			b2WeldJointDef jd;

			b2Body* prevBody = ground;
			for (int32 i = 0; i < e_count; ++i)
			{
				b2BodyDef bd;
				bd.type = b2_dynamicBody;
				bd.position.Set(-14.5f + 1.0f * i, 5.0f);
				b2Body* body = world->CreateBody(&bd);
				body->CreateFixture(&fd);

				b2Vec2 anchor(-15.0f + 1.0f * i, 5.0f);
				jd.Initialize(prevBody, body, anchor);
				world->CreateJoint(&jd);

				prevBody = body;
			}
		}

		{
			b2PolygonShape shape;
			shape.SetAsBox(0.5f, 0.125f);

			b2FixtureDef fd;
			fd.shape = &shape;
			fd.density = 20.0f;

			b2WeldJointDef jd;

			b2Body* prevBody = ground;
			for (int32 i = 0; i < e_count; ++i)
			{
				b2BodyDef bd;
				bd.type = b2_dynamicBody;
				bd.position.Set(-14.5f + 1.0f * i, 15.0f);
				b2Body* body = world->CreateBody(&bd);
				body->CreateFixture(&fd);

				b2Vec2 anchor(-15.0f + 1.0f * i, 15.0f);
				jd.Initialize(prevBody, body, anchor);
				world->CreateJoint(&jd);

				prevBody = body;
			}
		}

		{
			b2PolygonShape shape;
			shape.SetAsBox(0.5f, 0.125f);

			b2FixtureDef fd;
			fd.shape = &shape;
			fd.density = 20.0f;

			b2WeldJointDef jd;

			b2Body* prevBody = ground;
			for (int32 i = 0; i < e_count; ++i)
			{
				b2BodyDef bd;
				bd.type = b2_dynamicBody;
				bd.position.Set(-4.5f + 1.0f * i, 5.0f);
				b2Body* body = world->CreateBody(&bd);
				body->CreateFixture(&fd);

				if (i > 0)
				{
					b2Vec2 anchor(-5.0f + 1.0f * i, 5.0f);
					jd.Initialize(prevBody, body, anchor);
					world->CreateJoint(&jd);
				}

				prevBody = body;
			}
		}

		{
			b2PolygonShape shape;
			shape.SetAsBox(0.5f, 0.125f);

			b2FixtureDef fd;
			fd.shape = &shape;
			fd.density = 20.0f;

			b2WeldJointDef jd;

			b2Body* prevBody = ground;
			for (int32 i = 0; i < e_count; ++i)
			{
				b2BodyDef bd;
				bd.type = b2_dynamicBody;
				bd.position.Set(5.5f + 1.0f * i, 10.0f);
				b2Body* body = world->CreateBody(&bd);
				body->CreateFixture(&fd);

				if (i > 0)
				{
					b2Vec2 anchor(5.0f + 1.0f * i, 10.0f);
					jd.Initialize(prevBody, body, anchor);
					world->CreateJoint(&jd);
				}

				prevBody = body;
			}
		}

		for (int32 i = 0; i < 2; ++i)
		{
			b2Vec2 vertices[3];
			vertices[0].Set(-0.5f, 0.0f);
			vertices[1].Set(0.5f, 0.0f);
			vertices[2].Set(0.0f, 1.5f);

			b2PolygonShape shape;
			shape.Set(vertices, 3);

			b2FixtureDef fd;
			fd.shape = &shape;
			fd.density = 1.0f;

			b2BodyDef bd;
			bd.type = b2_dynamicBody;
			bd.position.Set(-8.0f + 8.0f * i, 12.0f);
			b2Body* body = world->CreateBody(&bd);
			body->CreateFixture(&fd);
		}

		for (int32 i = 0; i < 2; ++i)
		{
			b2CircleShape shape;
			shape.m_radius = 0.5f;

			b2FixtureDef fd;
			fd.shape = &shape;
			fd.density = 1.0f;

			b2BodyDef bd;
			bd.type = b2_dynamicBody;
			bd.position.Set(-6.0f + 6.0f * i, 10.0f);
			b2Body* body = world->CreateBody(&bd);
			body->CreateFixture(&fd);
		}

		startUpdateWorld();
	}

	virtual ~wyCantileverTestLayer() {
	}
};

//////////////////////////////////////////////////////////////////////////////////

class wyCarTestLayer : public wyBox2DTestLayer {
private:
	b2Body* m_car;
	b2Body* m_wheel1;
	b2Body* m_wheel2;

	float m_hz;
	float m_zeta;
	float m_speed;
	b2WheelJoint* m_spring1;
	b2WheelJoint* m_spring2;

public:
	wyCarTestLayer() {
		m_hz = 4.0f;
		m_zeta = 0.7f;
		m_speed = 50.0f;

		// get world
		b2World* world = m_box2d->getWorld();

		// set gravity
		world->SetGravity(b2Vec2(0, -10));

		// place box2d to center of bottom edge
		m_box2d->setPosition(wyDevice::winWidth / 2, 0);

		// create ground
		b2Body* ground = NULL;
		{
			// create ground body
			b2BodyDef bd;
			ground = world->CreateBody(&bd);

			// create ground shape
			b2EdgeShape shape;
			b2FixtureDef fd;
			fd.shape = &shape;
			fd.density = 0.0f;
			fd.friction = 0.6f;
			shape.Set(b2Vec2(-20.0f, 0.0f), b2Vec2(20.0f, 0.0f));
			ground->CreateFixture(&fd);

			float hs[10] = {0.25f, 1.0f, 4.0f, 0.0f, 0.0f, -1.0f, -2.0f, -2.0f, -1.25f, 0.0f};
			float x = 20.0f, y1 = 0.0f, dx = 5.0f;
			for (int i = 0; i < 10; ++i)
			{
				float y2 = hs[i];
				shape.Set(b2Vec2(x, y1), b2Vec2(x + dx, y2));
				ground->CreateFixture(&fd);
				y1 = y2;
				x += dx;
			}
			for (int i = 0; i < 10; ++i)
			{
				float y2 = hs[i];
				shape.Set(b2Vec2(x, y1), b2Vec2(x + dx, y2));
				ground->CreateFixture(&fd);
				y1 = y2;
				x += dx;
			}

			shape.Set(b2Vec2(x, 0.0f), b2Vec2(x + 40.0f, 0.0f));
			ground->CreateFixture(&fd);

			x += 80.0f;
			shape.Set(b2Vec2(x, 0.0f), b2Vec2(x + 40.0f, 0.0f));
			ground->CreateFixture(&fd);

			x += 40.0f;
			shape.Set(b2Vec2(x, 0.0f), b2Vec2(x + 10.0f, 5.0f));
			ground->CreateFixture(&fd);

			x += 20.0f;
			shape.Set(b2Vec2(x, 0.0f), b2Vec2(x + 40.0f, 0.0f));
			ground->CreateFixture(&fd);

			x += 40.0f;
			shape.Set(b2Vec2(x, 0.0f), b2Vec2(x, 20.0f));
			ground->CreateFixture(&fd);
		}

		// Teeter
		{
			b2BodyDef bd;
			bd.position.Set(140.0f, 1.0f);
			bd.type = b2_dynamicBody;
			b2Body* body = world->CreateBody(&bd);

			b2PolygonShape box;
			box.SetAsBox(10.0f, 0.25f);
			body->CreateFixture(&box, 1.0f);

			b2RevoluteJointDef jd;
			jd.Initialize(ground, body, body->GetPosition());
			jd.lowerAngle = -8.0f * b2_pi / 180.0f;
			jd.upperAngle = 8.0f * b2_pi / 180.0f;
			jd.enableLimit = true;
			world->CreateJoint(&jd);

			body->ApplyAngularImpulse(100.0f);
		}

		// Bridge
		{
			int N = 20;
			b2PolygonShape shape;
			shape.SetAsBox(1.0f, 0.125f);

			b2FixtureDef fd;
			fd.shape = &shape;
			fd.density = 1.0f;
			fd.friction = 0.6f;

			b2RevoluteJointDef jd;

			b2Body* prevBody = ground;
			for (int i = 0; i < N; ++i)
			{
				b2BodyDef bd;
				bd.type = b2_dynamicBody;
				bd.position.Set(161.0f + 2.0f * i, -0.125f);
				b2Body* body = world->CreateBody(&bd);
				body->CreateFixture(&fd);

				b2Vec2 anchor(160.0f + 2.0f * i, -0.125f);
				jd.Initialize(prevBody, body, anchor);
				world->CreateJoint(&jd);

				prevBody = body;
			}

			b2Vec2 anchor(160.0f + 2.0f * N, -0.125f);
			jd.Initialize(prevBody, ground, anchor);
			world->CreateJoint(&jd);
		}

		// Boxes
		{
			b2PolygonShape box;
			box.SetAsBox(0.5f, 0.5f);

			b2Body* body = NULL;
			b2BodyDef bd;
			bd.type = b2_dynamicBody;

			bd.position.Set(230.0f, 0.5f);
			body = world->CreateBody(&bd);
			body->CreateFixture(&box, 0.5f);

			bd.position.Set(230.0f, 1.5f);
			body = world->CreateBody(&bd);
			body->CreateFixture(&box, 0.5f);

			bd.position.Set(230.0f, 2.5f);
			body = world->CreateBody(&bd);
			body->CreateFixture(&box, 0.5f);

			bd.position.Set(230.0f, 3.5f);
			body = world->CreateBody(&bd);
			body->CreateFixture(&box, 0.5f);

			bd.position.Set(230.0f, 4.5f);
			body = world->CreateBody(&bd);
			body->CreateFixture(&box, 0.5f);
		}

		// Car
		{
			b2PolygonShape chassis;
			b2Vec2 vertices[8];
			vertices[0].Set(-1.5f, -0.5f);
			vertices[1].Set(1.5f, -0.5f);
			vertices[2].Set(1.5f, 0.0f);
			vertices[3].Set(0.0f, 0.9f);
			vertices[4].Set(-1.15f, 0.9f);
			vertices[5].Set(-1.5f, 0.2f);
			chassis.Set(vertices, 6);

			b2CircleShape circle;
			circle.m_radius = 0.4f;

			b2BodyDef bd;
			bd.type = b2_dynamicBody;
			bd.position.Set(0.0f, 1.0f);
			m_car = world->CreateBody(&bd);
			m_car->CreateFixture(&chassis, 1.0f);

			b2FixtureDef fd;
			fd.shape = &circle;
			fd.density = 1.0f;
			fd.friction = 0.9f;

			bd.position.Set(-1.0f, 0.35f);
			m_wheel1 = world->CreateBody(&bd);
			m_wheel1->CreateFixture(&fd);

			bd.position.Set(1.0f, 0.4f);
			m_wheel2 = world->CreateBody(&bd);
			m_wheel2->CreateFixture(&fd);

			b2WheelJointDef jd;
			b2Vec2 axis(0.0f, 1.0f);

			jd.Initialize(m_car, m_wheel1, m_wheel1->GetPosition(), axis);
			jd.motorSpeed = 0.0f;
			jd.maxMotorTorque = 20.0f;
			jd.enableMotor = true;
			jd.frequencyHz = m_hz;
			jd.dampingRatio = m_zeta;
			m_spring1 = (b2WheelJoint*)world->CreateJoint(&jd);

			jd.Initialize(m_car, m_wheel2, m_wheel2->GetPosition(), axis);
			jd.motorSpeed = 0.0f;
			jd.maxMotorTorque = 10.0f;
			jd.enableMotor = false;
			jd.frequencyHz = m_hz;
			jd.dampingRatio = m_zeta;
			m_spring2 = (b2WheelJoint*)world->CreateJoint(&jd);
		}

		// backward button
		wyNinePatchSprite* normal = wyNinePatchSprite::make(wyTexture2D::makePNG(RES("R.drawable.btn_normal")), wyr(DP(9), DP(7), DP(22), DP(28)));
		wyNinePatchSprite* pressed = wyNinePatchSprite::make(wyTexture2D::makePNG(RES("R.drawable.btn_pressed")), wyr(DP(9), DP(7), DP(22), DP(28)));
		normal->setContentSize(DP(100), DP(44));
		pressed->setContentSize(DP(100), DP(44));
		wyButton* button = new wyButton(normal, pressed, NULL, NULL, NULL, wyTargetSelector::make(this, SEL(wyCarTestLayer::onBackward)));
		button->setPosition(DP(55), wyDevice::winHeight - DP(30));
		addChildLocked(button, 1);
		button->release();

		// label for backward button
		wyBitmapFont* font = wyBitmapFont::loadFont(RES("R.raw.bitmapfont"));
		wyBitmapFontLabel* label = wyBitmapFontLabel::make(font, "Backward");
		label->setColor(wyc3b(255, 255, 0));
		label->setPosition(DP(55), wyDevice::winHeight - DP(30));
		addChildLocked(label, 1);

		// stop button
		button = new wyButton(normal, pressed, NULL, NULL, NULL, wyTargetSelector::make(this, SEL(wyCarTestLayer::onStop)));
		button->setPosition(DP(160), wyDevice::winHeight - DP(30));
		addChildLocked(button, 1);
		button->release();

		// label for stop button
		label = wyBitmapFontLabel::make(font, "Stop");
		label->setColor(wyc3b(255, 255, 0));
		label->setPosition(DP(160), wyDevice::winHeight - DP(30));
		addChildLocked(label, 1);

		// forward button
		button = new wyButton(normal, pressed, NULL, NULL, NULL, wyTargetSelector::make(this, SEL(wyCarTestLayer::onForward)));
		button->setPosition(DP(265), wyDevice::winHeight - DP(30));
		addChildLocked(button, 1);
		button->release();

		// label for forward button
		label = wyBitmapFontLabel::make(font, "Forward");
		label->setColor(wyc3b(255, 255, 0));
		label->setPosition(DP(265), wyDevice::winHeight - DP(30));
		addChildLocked(label, 1);

		// freq. down button
		normal = wyNinePatchSprite::make(wyTexture2D::makePNG(RES("R.drawable.btn_normal")), wyr(DP(9), DP(7), DP(22), DP(28)));
		pressed = wyNinePatchSprite::make(wyTexture2D::makePNG(RES("R.drawable.btn_pressed")), wyr(DP(9), DP(7), DP(22), DP(28)));
		normal->setContentSize(DP(150), DP(44));
		pressed->setContentSize(DP(150), DP(44));
		button = new wyButton(normal, pressed, NULL, NULL, NULL, wyTargetSelector::make(this, SEL(wyCarTestLayer::onFreqDown)));
		button->setPosition(DP(80), wyDevice::winHeight - DP(80));
		addChildLocked(button, 1);
		button->release();

		// label for freq. down button
		label = wyBitmapFontLabel::make(font, "Freq. Down");
		label->setColor(wyc3b(255, 255, 0));
		label->setPosition(DP(80), wyDevice::winHeight - DP(80));
		addChildLocked(label, 1);

		// freq. up button
		button = new wyButton(normal, pressed, NULL, NULL, NULL, wyTargetSelector::make(this, SEL(wyCarTestLayer::onFreqUp)));
		button->setPosition(DP(240), wyDevice::winHeight - DP(80));
		addChildLocked(button, 1);
		button->release();

		// label for freq. up button
		label = wyBitmapFontLabel::make(font, "Freq. Up");
		label->setColor(wyc3b(255, 255, 0));
		label->setPosition(DP(240), wyDevice::winHeight - DP(80));
		addChildLocked(label, 1);

		startUpdateWorld();
	}

	virtual ~wyCarTestLayer() {
	}

	void onBackward(wyTargetSelector* ts) {
		m_spring1->SetMotorSpeed(m_speed);
	}

	void onStop(wyTargetSelector* ts) {
		m_spring1->SetMotorSpeed(0.0f);
	}

	void onForward(wyTargetSelector* ts) {
		m_spring1->SetMotorSpeed(-m_speed);
	}

	void onFreqDown(wyTargetSelector* ts) {
		m_hz = b2Max(0.0f, m_hz - 1.0f);
		m_spring1->SetSpringFrequencyHz(m_hz);
		m_spring2->SetSpringFrequencyHz(m_hz);
	}

	void onFreqUp(wyTargetSelector* ts) {
		m_hz += 1.0f;
		m_spring1->SetSpringFrequencyHz(m_hz);
		m_spring2->SetSpringFrequencyHz(m_hz);
	}

	virtual void updateWorld(float delta) {
		wyBox2DTestLayer::updateWorld(delta);

		// move the scene, keep the car center
		const b2Vec2& carPos = m_car->GetPosition();
		float pX = m_box2d->meter2Pixel(carPos.x);
		m_box2d->setPosition(-pX + wyDevice::winWidth / 2, DP(100));
	}
};

///////////////////////////////////////////////////////////////////////////

class wyChainTestLayer : public wyBox2DTestLayer {
public:
	wyChainTestLayer() {
		// get world
		b2World* world = m_box2d->getWorld();

		// set gravity
		world->SetGravity(b2Vec2(0, -10));

		// place box2d to center of bottom edge
		m_box2d->setPosition(wyDevice::winWidth / 2, 0);

		b2Body* ground = NULL;
		{
			b2BodyDef bd;
			ground = world->CreateBody(&bd);

			b2EdgeShape shape;
			shape.Set(b2Vec2(-40.0f, 0.0f), b2Vec2(40.0f, 0.0f));
			ground->CreateFixture(&shape, 0.0f);
		}

		{
			b2PolygonShape shape;
			shape.SetAsBox(0.6f, 0.125f);

			b2FixtureDef fd;
			fd.shape = &shape;
			fd.density = 20.0f;
			fd.friction = 0.2f;

			b2RevoluteJointDef jd;
			jd.collideConnected = false;

			const float32 y = 25.0f;
			b2Body* prevBody = ground;
			for (int32 i = 0; i < 30; ++i)
			{
				b2BodyDef bd;
				bd.type = b2_dynamicBody;
				bd.position.Set(0.5f + i, y);
				b2Body* body = world->CreateBody(&bd);
				body->CreateFixture(&fd);

				b2Vec2 anchor(float32(i), y);
				jd.Initialize(prevBody, body, anchor);
				world->CreateJoint(&jd);

				prevBody = body;
			}
		}

		startUpdateWorld();
	}

	virtual ~wyChainTestLayer() {
	}
};

/////////////////////////////////////////////////////////////////////////////

class wyChainShapeTestLayer : public wyBox2DTestLayer {
public:
	wyChainShapeTestLayer() {
		b2World* world = m_box2d->getWorld();

		// place box2d in center
		m_box2d->setPosition(wyDevice::winWidth / 2, wyDevice::winHeight / 2);

		// create body
		b2Body* body = NULL;
		{
			b2BodyDef bd;
			bd.type = b2_dynamicBody;
			bd.position.Set(0.0f, 0.0f);
			bd.angularVelocity = 0.2f;
			body = world->CreateBody(&bd);
		}

		// create chain shape
		{
			b2Vec2 vertices[] = {
					b2Vec2(-2.0f, 0.0f),
					b2Vec2(0.0f, 2.0f),
					b2Vec2(2.0f, 2.0f),
					b2Vec2(2.0f, -2.0f),
					b2Vec2(-2.0f, -2.0f)
			};
			b2ChainShape* ls = new b2ChainShape();
			ls->CreateLoop(vertices, 5);
			b2FixtureDef fixDef;
			fixDef.shape = ls;
			body->CreateFixture(&fixDef);
		}

		// start update world
		startUpdateWorld();
	}

	virtual ~wyChainShapeTestLayer() {
	}
};

/////////////////////////////////////////////////////////////////////////////

class wyCollisionDetectionTestLayer : public wyLayer {
private:
	wySprite* m_sprite1;
	wySprite* m_sprite2;
	wyBox2DCollisionDetector* m_detector;
	wyBox2DCDResult m_result;

public:
	wyCollisionDetectionTestLayer() {
		// create sprite1
		float size = DP(32.0f);
		wyTexture2D* tex = wyTexture2D::makePNG(RES("R.drawable.blocks"));
		m_sprite1 = wySprite::make(tex, wyr(wyMath::randMax(1) * size, wyMath::randMax(1) * size, size, size));
		addChildLocked(m_sprite1, -1);

		// create sprite2
		m_sprite2 = wySprite::make(tex, wyr(wyMath::randMax(1) * size, wyMath::randMax(1) * size, size, size));
		addChildLocked(m_sprite2, -1);

		// init and begin
		reset();

		// create collision detector
		m_detector = wyBox2DCollisionDetector::make();
		m_detector->retain();

		// schedule a timer to check collision
		wyTargetSelector* ts = wyTargetSelector::make(this, SEL(wyCollisionDetectionTestLayer::checkCollision));
		wyTimer* t = wyTimer::make(ts);
		scheduleLocked(t);

		// touch enable
		setTouchEnabled(true);
	}

	virtual ~wyCollisionDetectionTestLayer() {
		m_detector->release();
	}

	void reset() {
		// clear result
		memset(&m_result, 0, sizeof(wyBox2DCDResult));

		// relocate sprite
		m_sprite1->setRotation(wyMath::randMax(360));
		m_sprite1->setPosition(0, 0);
		m_sprite2->setRotation(wyMath::randMax(360));
		m_sprite2->setPosition(wyDevice::winWidth, wyDevice::winHeight);

		// re-run actions
		wyMoveBy* move1 = wyMoveBy::make(4, wyDevice::winWidth, wyDevice::winHeight);
		wyRotateBy* rotate1 = wyRotateBy::make(4, wyMath::randMax(360));
		m_sprite1->runAction(move1);
		m_sprite1->runAction(rotate1);
		wyMoveBy* move2 = wyMoveBy::make(4, -wyDevice::winWidth, -wyDevice::winHeight);
		m_sprite2->runAction(move2);
		wyRotateBy* rotate2 = wyRotateBy::make(4, wyMath::randMax(360));
		m_sprite2->runAction(rotate2);
	}

	void checkCollision(wyTargetSelector* ts) {
		if(m_result.pointCount == 0) {
			if(m_detector->isCollided(m_sprite1, m_sprite2, &m_result)) {
				m_sprite1->stopAllActions();
				m_sprite2->stopAllActions();
			}
		}
	}

	virtual void draw() {
		// TODO gles2
		//if(m_result.pointCount > 0) {
		//	// draw collision point
  //      	glColor4f(1, 0, 0, 1);
  //      	glPointSize(5);
		//	wyDrawPoints((float*)m_result.points, m_result.pointCount * 2);

  //      	// draw normal
		//	wyDrawLine(m_result.points[0].x, m_result.points[0].y,
		//			   m_result.points[0].x + m_result.normal.x * 50, m_result.points[0].y + m_result.normal.y * 50);

  //      	glColor4f(1, 1, 1, 1);
		//}
	}

	virtual bool touchesBegan(wyMotionEvent& e) {
		if(m_result.pointCount > 0) {
			reset();
		}
		return wyLayer::touchesBegan(e);
	}
};

///////////////////////////////////////////////////////////////////////////////////

class wyCollisionFilteringTestLayer : public wyBox2DTestLayer {
public:
	// This is a test of collision filtering.
	// There is a triangle, a box, and a circle.
	// There are 6 shapes. 3 large and 3 small.
	// The 3 small ones always collide.
	// The 3 large ones never collide.
	// The boxes don't collide with triangles (except if both are small).
	static const int16	k_smallGroup = 1;
	static const int16 k_largeGroup = -1;

	static const uint16 k_defaultCategory = 0x0001;
	static const uint16 k_triangleCategory = 0x0002;
	static const uint16 k_boxCategory = 0x0004;
	static const uint16 k_circleCategory = 0x0008;

	static const uint16 k_triangleMask = 0xFFFF;
	static const uint16 k_boxMask = 0xFFFF ^ k_triangleCategory;
	static const uint16 k_circleMask = 0xFFFF;

	wyCollisionFilteringTestLayer() {
		// get world
		b2World* world = m_box2d->getWorld();

		// set gravity
		world->SetGravity(b2Vec2(0, -10));

		// place box2d to center of bottom edge
		m_box2d->setPosition(wyDevice::winWidth / 2, 0);

		// Ground body
		{
			b2EdgeShape shape;
			shape.Set(b2Vec2(-40.0f, 0.0f), b2Vec2(40.0f, 0.0f));

			b2FixtureDef sd;
			sd.shape = &shape;
			sd.friction = 0.3f;

			b2BodyDef bd;
			b2Body* ground = world->CreateBody(&bd);
			ground->CreateFixture(&sd);
		}

		// Small triangle
		b2Vec2 vertices[3];
		vertices[0].Set(-1.0f, 0.0f);
		vertices[1].Set(1.0f, 0.0f);
		vertices[2].Set(0.0f, 2.0f);
		b2PolygonShape polygon;
		polygon.Set(vertices, 3);

		b2FixtureDef triangleShapeDef;
		triangleShapeDef.shape = &polygon;
		triangleShapeDef.density = 1.0f;

		triangleShapeDef.filter.groupIndex = k_smallGroup;
		triangleShapeDef.filter.categoryBits = k_triangleCategory;
		triangleShapeDef.filter.maskBits = k_triangleMask;

		b2BodyDef triangleBodyDef;
		triangleBodyDef.type = b2_dynamicBody;
		triangleBodyDef.position.Set(-5.0f, 2.0f);

		b2Body* body1 = world->CreateBody(&triangleBodyDef);
		body1->CreateFixture(&triangleShapeDef);

		// Large triangle (recycle definitions)
		vertices[0] *= 2.0f;
		vertices[1] *= 2.0f;
		vertices[2] *= 2.0f;
		polygon.Set(vertices, 3);
		triangleShapeDef.filter.groupIndex = k_largeGroup;
		triangleBodyDef.position.Set(-5.0f, 6.0f);
		triangleBodyDef.fixedRotation = true; // look at me!

		b2Body* body2 = world->CreateBody(&triangleBodyDef);
		body2->CreateFixture(&triangleShapeDef);

		{
			b2BodyDef bd;
			bd.type = b2_dynamicBody;
			bd.position.Set(-5.0f, 10.0f);
			b2Body* body = world->CreateBody(&bd);

			b2PolygonShape p;
			p.SetAsBox(0.5f, 1.0f);
			body->CreateFixture(&p, 1.0f);

			b2PrismaticJointDef jd;
			jd.bodyA = body2;
			jd.bodyB = body;
			jd.enableLimit = true;
			jd.localAnchorA.Set(0.0f, 4.0f);
			jd.localAnchorB.SetZero();
			jd.localAxisA.Set(0.0f, 1.0f);
			jd.lowerTranslation = -1.0f;
			jd.upperTranslation = 1.0f;

			world->CreateJoint(&jd);
		}

		// Small box
		polygon.SetAsBox(1.0f, 0.5f);
		b2FixtureDef boxShapeDef;
		boxShapeDef.shape = &polygon;
		boxShapeDef.density = 1.0f;
		boxShapeDef.restitution = 0.1f;

		boxShapeDef.filter.groupIndex = k_smallGroup;
		boxShapeDef.filter.categoryBits = k_boxCategory;
		boxShapeDef.filter.maskBits = k_boxMask;

		b2BodyDef boxBodyDef;
		boxBodyDef.type = b2_dynamicBody;
		boxBodyDef.position.Set(0.0f, 2.0f);

		b2Body* body3 = world->CreateBody(&boxBodyDef);
		body3->CreateFixture(&boxShapeDef);

		// Large box (recycle definitions)
		polygon.SetAsBox(2.0f, 1.0f);
		boxShapeDef.filter.groupIndex = k_largeGroup;
		boxBodyDef.position.Set(0.0f, 6.0f);

		b2Body* body4 = world->CreateBody(&boxBodyDef);
		body4->CreateFixture(&boxShapeDef);

		// Small circle
		b2CircleShape circle;
		circle.m_radius = 1.0f;

		b2FixtureDef circleShapeDef;
		circleShapeDef.shape = &circle;
		circleShapeDef.density = 1.0f;

		circleShapeDef.filter.groupIndex = k_smallGroup;
		circleShapeDef.filter.categoryBits = k_circleCategory;
		circleShapeDef.filter.maskBits = k_circleMask;

		b2BodyDef circleBodyDef;
		circleBodyDef.type = b2_dynamicBody;
		circleBodyDef.position.Set(5.0f, 2.0f);

		b2Body* body5 = world->CreateBody(&circleBodyDef);
		body5->CreateFixture(&circleShapeDef);

		// Large circle
		circle.m_radius *= 2.0f;
		circleShapeDef.filter.groupIndex = k_largeGroup;
		circleBodyDef.position.Set(5.0f, 6.0f);

		b2Body* body6 = world->CreateBody(&circleBodyDef);
		body6->CreateFixture(&circleShapeDef);

		startUpdateWorld();
	}

	virtual ~wyCollisionFilteringTestLayer() {
	}
};

////////////////////////////////////////////////////////////////////////////////

class wyCompoundShapesTestLayer : public wyBox2DTestLayer {
public:
	wyCompoundShapesTestLayer() {
		// get world
		b2World* world = m_box2d->getWorld();

		// set gravity
		world->SetGravity(b2Vec2(0, -10));

		// place box2d to center of bottom edge
		m_box2d->setPosition(wyDevice::winWidth / 2, 0);

		{
			b2BodyDef bd;
			bd.position.Set(0.0f, 0.0f);
			b2Body* body = world->CreateBody(&bd);

			b2EdgeShape shape;
			shape.Set(b2Vec2(50.0f, 0.0f), b2Vec2(-50.0f, 0.0f));

			body->CreateFixture(&shape, 0.0f);
		}

		{
			b2CircleShape circle1;
			circle1.m_radius = 0.5f;
			circle1.m_p.Set(-0.5f, 0.5f);

			b2CircleShape circle2;
			circle2.m_radius = 0.5f;
			circle2.m_p.Set(0.5f, 0.5f);

			for (int i = 0; i < 10; ++i)
			{
				float32 x = RandomFloat(-0.1f, 0.1f);
				b2BodyDef bd;
				bd.type = b2_dynamicBody;
				bd.position.Set(x + 5.0f, 1.05f + 2.5f * i);
				bd.angle = RandomFloat(-b2_pi, b2_pi);
				b2Body* body = world->CreateBody(&bd);
				body->CreateFixture(&circle1, 2.0f);
				body->CreateFixture(&circle2, 0.0f);
			}
		}

		{
			b2PolygonShape polygon1;
			polygon1.SetAsBox(0.25f, 0.5f);

			b2PolygonShape polygon2;
			polygon2.SetAsBox(0.25f, 0.5f, b2Vec2(0.0f, -0.5f), 0.5f * b2_pi);

			for (int i = 0; i < 10; ++i)
			{
				float32 x = RandomFloat(-0.1f, 0.1f);
				b2BodyDef bd;
				bd.type = b2_dynamicBody;
				bd.position.Set(x - 5.0f, 1.05f + 2.5f * i);
				bd.angle = RandomFloat(-b2_pi, b2_pi);
				b2Body* body = world->CreateBody(&bd);
				body->CreateFixture(&polygon1, 2.0f);
				body->CreateFixture(&polygon2, 2.0f);
			}
		}

		{
			b2Transform xf1;
			xf1.q.Set(0.3524f * b2_pi);
			xf1.p = b2Mul(xf1.q, b2Vec2(1.0f, 0.0f));

			b2Vec2 vertices[3];

			b2PolygonShape triangle1;
			vertices[0] = b2Mul(xf1, b2Vec2(-1.0f, 0.0f));
			vertices[1] = b2Mul(xf1, b2Vec2(1.0f, 0.0f));
			vertices[2] = b2Mul(xf1, b2Vec2(0.0f, 0.5f));
			triangle1.Set(vertices, 3);

			b2Transform xf2;
			xf2.q.Set(-0.3524f * b2_pi);
			xf2.p = b2Mul(xf2.q, b2Vec2(-1.0f, 0.0f));

			b2PolygonShape triangle2;
			vertices[0] = b2Mul(xf2, b2Vec2(-1.0f, 0.0f));
			vertices[1] = b2Mul(xf2, b2Vec2(1.0f, 0.0f));
			vertices[2] = b2Mul(xf2, b2Vec2(0.0f, 0.5f));
			triangle2.Set(vertices, 3);

			for (int32 i = 0; i < 10; ++i)
			{
				float32 x = RandomFloat(-0.1f, 0.1f);
				b2BodyDef bd;
				bd.type = b2_dynamicBody;
				bd.position.Set(x, 2.05f + 2.5f * i);
				bd.angle = 0.0f;
				b2Body* body = world->CreateBody(&bd);
				body->CreateFixture(&triangle1, 2.0f);
				body->CreateFixture(&triangle2, 2.0f);
			}
		}

		{
			b2PolygonShape bottom;
			bottom.SetAsBox( 1.5f, 0.15f );

			b2PolygonShape left;
			left.SetAsBox(0.15f, 2.7f, b2Vec2(-1.45f, 2.35f), 0.2f);

			b2PolygonShape right;
			right.SetAsBox(0.15f, 2.7f, b2Vec2(1.45f, 2.35f), -0.2f);

			b2BodyDef bd;
			bd.type = b2_dynamicBody;
			bd.position.Set( 0.0f, 2.0f );
			b2Body* body = world->CreateBody(&bd);
			body->CreateFixture(&bottom, 4.0f);
			body->CreateFixture(&left, 4.0f);
			body->CreateFixture(&right, 4.0f);
		}

		startUpdateWorld();
	}

	virtual ~wyCompoundShapesTestLayer() {
	}
};

////////////////////////////////////////////////////////////////////////////////////

class wyConfinedTestLayer : public wyBox2DTestLayer {
public:
	wyConfinedTestLayer() {
		b2World* world = m_box2d->getWorld();

		// place box2d to center of bottom edge
		m_box2d->setPosition(wyDevice::winWidth / 2, 0);

		{
			b2BodyDef bd;
			b2Body* ground = world->CreateBody(&bd);

			b2EdgeShape shape;

			// Floor
			shape.Set(b2Vec2(-10.0f, 0.0f), b2Vec2(10.0f, 0.0f));
			ground->CreateFixture(&shape, 0.0f);

			// Left wall
			shape.Set(b2Vec2(-10.0f, 0.0f), b2Vec2(-10.0f, 20.0f));
			ground->CreateFixture(&shape, 0.0f);

			// Right wall
			shape.Set(b2Vec2(10.0f, 0.0f), b2Vec2(10.0f, 20.0f));
			ground->CreateFixture(&shape, 0.0f);

			// Roof
			shape.Set(b2Vec2(-10.0f, 20.0f), b2Vec2(10.0f, 20.0f));
			ground->CreateFixture(&shape, 0.0f);
		}

		setKeyEnabled(true);

		// create circle button
		wyNinePatchSprite* normal = wyNinePatchSprite::make(wyTexture2D::makePNG(RES("R.drawable.btn_normal")), wyr(DP(9), DP(7), DP(22), DP(28)));
		wyNinePatchSprite* pressed = wyNinePatchSprite::make(wyTexture2D::makePNG(RES("R.drawable.btn_pressed")), wyr(DP(9), DP(7), DP(22), DP(28)));
		normal->setContentSize(DP(200), DP(44));
		pressed->setContentSize(DP(200), DP(44));
		wyButton* button = new wyButton(normal, pressed, NULL, NULL, NULL, wyTargetSelector::make(this, SEL(wyConfinedTestLayer::onCreate)));
		button->setPosition(wyDevice::winWidth / 2, wyDevice::winHeight - DP(30));
		addChildLocked(button, 1);
		button->release();

		// label for create circle button
		wyBitmapFont* font = wyBitmapFont::loadFont(RES("R.raw.bitmapfont"));
		wyBitmapFontLabel* label = wyBitmapFontLabel::make(font, "Create Circle");
		label->setColor(wyc3b(255, 255, 0));
		label->setPosition(wyDevice::winWidth / 2, wyDevice::winHeight - DP(30));
		addChildLocked(label, 1);

		startUpdateWorld();
	}

	virtual ~wyConfinedTestLayer() {
	}

	void CreateCircle() {
		float32 radius = 2.0f;
		b2CircleShape shape;
		shape.m_p.SetZero();
		shape.m_radius = radius;

		b2FixtureDef fd;
		fd.shape = &shape;
		fd.density = 1.0f;
		fd.friction = 0.0f;

		b2Vec2 p(RandomFloat(), 3.0f + RandomFloat());
		b2BodyDef bd;
		bd.type = b2_dynamicBody;
		bd.position = p;
		b2Body* body = m_box2d->getWorld()->CreateBody(&bd);

		body->CreateFixture(&fd);
	}

	virtual bool keyDown(wyKeyEvent& event) {
		switch(event.keyCode) {
			case KEYCODE_MENU:
				CreateCircle();
				break;
			default:
				return false;
		}

		return true;
	}

	void onCreate(wyTargetSelector* ts) {
		CreateCircle();
	}
};

////////////////////////////////////////////////////////////////////////////

class wyDominosTestLayer : public wyBox2DTestLayer {
public:
	wyDominosTestLayer() {
		// get world
		b2World* world = m_box2d->getWorld();

		// set gravity
		world->SetGravity(b2Vec2(0, -10));

		// place box2d to center of bottom edge
		m_box2d->setPosition(wyDevice::winWidth / 2, 0);

		b2Body* b1;
		{
			b2EdgeShape shape;
			shape.Set(b2Vec2(-40.0f, 0.0f), b2Vec2(40.0f, 0.0f));

			b2BodyDef bd;
			b1 = world->CreateBody(&bd);
			b1->CreateFixture(&shape, 0.0f);
		}

		{
			b2PolygonShape shape;
			shape.SetAsBox(6.0f, 0.25f);

			b2BodyDef bd;
			bd.position.Set(-1.5f, 10.0f);
			b2Body* ground = world->CreateBody(&bd);
			ground->CreateFixture(&shape, 0.0f);
		}

		{
			b2PolygonShape shape;
			shape.SetAsBox(0.1f, 1.0f);

			b2FixtureDef fd;
			fd.shape = &shape;
			fd.density = 20.0f;
			fd.friction = 0.1f;

			for (int i = 0; i < 10; ++i)
			{
				b2BodyDef bd;
				bd.type = b2_dynamicBody;
				bd.position.Set(-6.0f + 1.0f * i, 11.25f);
				b2Body* body = world->CreateBody(&bd);
				body->CreateFixture(&fd);
			}
		}

		{
			b2PolygonShape shape;
			shape.SetAsBox(7.0f, 0.25f, b2Vec2_zero, 0.3f);

			b2BodyDef bd;
			bd.position.Set(1.0f, 6.0f);
			b2Body* ground = world->CreateBody(&bd);
			ground->CreateFixture(&shape, 0.0f);
		}

		b2Body* b2;
		{
			b2PolygonShape shape;
			shape.SetAsBox(0.25f, 1.5f);

			b2BodyDef bd;
			bd.position.Set(-7.0f, 4.0f);
			b2 = world->CreateBody(&bd);
			b2->CreateFixture(&shape, 0.0f);
		}

		b2Body* b3;
		{
			b2PolygonShape shape;
			shape.SetAsBox(6.0f, 0.125f);

			b2BodyDef bd;
			bd.type = b2_dynamicBody;
			bd.position.Set(-0.9f, 1.0f);
			bd.angle = -0.15f;

			b3 = world->CreateBody(&bd);
			b3->CreateFixture(&shape, 10.0f);
		}

		b2RevoluteJointDef jd;
		b2Vec2 anchor;

		anchor.Set(-2.0f, 1.0f);
		jd.Initialize(b1, b3, anchor);
		jd.collideConnected = true;
		world->CreateJoint(&jd);

		b2Body* b4;
		{
			b2PolygonShape shape;
			shape.SetAsBox(0.25f, 0.25f);

			b2BodyDef bd;
			bd.type = b2_dynamicBody;
			bd.position.Set(-10.0f, 15.0f);
			b4 = world->CreateBody(&bd);
			b4->CreateFixture(&shape, 10.0f);
		}

		anchor.Set(-7.0f, 15.0f);
		jd.Initialize(b2, b4, anchor);
		world->CreateJoint(&jd);

		b2Body* b5;
		{
			b2BodyDef bd;
			bd.type = b2_dynamicBody;
			bd.position.Set(6.5f, 3.0f);
			b5 = world->CreateBody(&bd);

			b2PolygonShape shape;
			b2FixtureDef fd;

			fd.shape = &shape;
			fd.density = 10.0f;
			fd.friction = 0.1f;

			shape.SetAsBox(1.0f, 0.1f, b2Vec2(0.0f, -0.9f), 0.0f);
			b5->CreateFixture(&fd);

			shape.SetAsBox(0.1f, 1.0f, b2Vec2(-0.9f, 0.0f), 0.0f);
			b5->CreateFixture(&fd);

			shape.SetAsBox(0.1f, 1.0f, b2Vec2(0.9f, 0.0f), 0.0f);
			b5->CreateFixture(&fd);
		}

		anchor.Set(6.0f, 2.0f);
		jd.Initialize(b1, b5, anchor);
		world->CreateJoint(&jd);

		b2Body* b6;
		{
			b2PolygonShape shape;
			shape.SetAsBox(1.0f, 0.1f);

			b2BodyDef bd;
			bd.type = b2_dynamicBody;
			bd.position.Set(6.5f, 4.1f);
			b6 = world->CreateBody(&bd);
			b6->CreateFixture(&shape, 30.0f);
		}

		anchor.Set(7.5f, 4.0f);
		jd.Initialize(b5, b6, anchor);
		world->CreateJoint(&jd);

		b2Body* b7;
		{
			b2PolygonShape shape;
			shape.SetAsBox(0.1f, 1.0f);

			b2BodyDef bd;
			bd.type = b2_dynamicBody;
			bd.position.Set(7.4f, 1.0f);

			b7 = world->CreateBody(&bd);
			b7->CreateFixture(&shape, 10.0f);
		}

		b2DistanceJointDef djd;
		djd.bodyA = b3;
		djd.bodyB = b7;
		djd.localAnchorA.Set(6.0f, 0.0f);
		djd.localAnchorB.Set(0.0f, -1.0f);
		b2Vec2 d = djd.bodyB->GetWorldPoint(djd.localAnchorB) - djd.bodyA->GetWorldPoint(djd.localAnchorA);
		djd.length = d.Length();
		world->CreateJoint(&djd);

		{
			float32 radius = 0.2f;

			b2CircleShape shape;
			shape.m_radius = radius;

			for (int32 i = 0; i < 4; ++i)
			{
				b2BodyDef bd;
				bd.type = b2_dynamicBody;
				bd.position.Set(5.9f + 2.0f * radius * i, 2.4f);
				b2Body* body = world->CreateBody(&bd);
				body->CreateFixture(&shape, 10.0f);
			}
		}

		startUpdateWorld();
	}

	virtual ~wyDominosTestLayer() {
	}
};

///////////////////////////////////////////////////////////////////////////////

class EdgeShapesCallback : public b2RayCastCallback
{
public:
	b2Fixture* m_fixture;
	b2Vec2 m_point;
	b2Vec2 m_normal;

public:
	EdgeShapesCallback() {
		m_fixture = NULL;
	}

	virtual ~EdgeShapesCallback() {
	}

	float32 ReportFixture(b2Fixture* fixture, const b2Vec2& point, const b2Vec2& normal, float32 fraction) {
		m_fixture = fixture;
		m_point = point;
		m_normal = normal;

		return fraction;
	}
};

class wyEdgeShapesTestLayer : public wyBox2DTestLayer {
private:
	enum
	{
		e_maxBodies = 256,
	};

	int32 m_bodyIndex;
	b2Body* m_bodies[e_maxBodies];
	b2PolygonShape m_polygons[4];
	b2CircleShape m_circle;

	float32 m_angle;

public:
	wyEdgeShapesTestLayer() {
		// get world
		b2World* world = m_box2d->getWorld();

		// set gravity
		world->SetGravity(b2Vec2(0, -10));

		// place box2d to center of bottom edge
		m_box2d->setPosition(wyDevice::winWidth / 2, wyDevice::winHeight / 4);

		// Ground body
		{
			b2BodyDef bd;
			b2Body* ground = world->CreateBody(&bd);

			float32 x1 = -20.0f;
			float32 y1 = 2.0f * cosf(x1 / 10.0f * b2_pi);
			for (int32 i = 0; i < 80; ++i)
			{
				float32 x2 = x1 + 0.5f;
				float32 y2 = 2.0f * cosf(x2 / 10.0f * b2_pi);

				b2EdgeShape shape;
				shape.Set(b2Vec2(x1, y1), b2Vec2(x2, y2));
				ground->CreateFixture(&shape, 0.0f);

				x1 = x2;
				y1 = y2;
			}
		}

		{
			b2Vec2 vertices[3];
			vertices[0].Set(-0.5f, 0.0f);
			vertices[1].Set(0.5f, 0.0f);
			vertices[2].Set(0.0f, 1.5f);
			m_polygons[0].Set(vertices, 3);
		}

		{
			b2Vec2 vertices[3];
			vertices[0].Set(-0.1f, 0.0f);
			vertices[1].Set(0.1f, 0.0f);
			vertices[2].Set(0.0f, 1.5f);
			m_polygons[1].Set(vertices, 3);
		}

		{
			float32 w = 1.0f;
			float32 b = w / (2.0f + b2Sqrt(2.0f));
			float32 s = b2Sqrt(2.0f) * b;

			b2Vec2 vertices[8];
			vertices[0].Set(0.5f * s, 0.0f);
			vertices[1].Set(0.5f * w, b);
			vertices[2].Set(0.5f * w, b + s);
			vertices[3].Set(0.5f * s, w);
			vertices[4].Set(-0.5f * s, w);
			vertices[5].Set(-0.5f * w, b + s);
			vertices[6].Set(-0.5f * w, b);
			vertices[7].Set(-0.5f * s, 0.0f);

			m_polygons[2].Set(vertices, 8);
		}

		{
			m_polygons[3].SetAsBox(0.5f, 0.5f);
		}

		{
			m_circle.m_radius = 0.5f;
		}

		m_bodyIndex = 0;
		memset(m_bodies, 0, sizeof(m_bodies));

		m_angle = 0.0f;

		setKeyEnabled(true);

		// create button
		wyNinePatchSprite* normal = wyNinePatchSprite::make(wyTexture2D::makePNG(RES("R.drawable.btn_normal")), wyr(DP(9), DP(7), DP(22), DP(28)));
		wyNinePatchSprite* pressed = wyNinePatchSprite::make(wyTexture2D::makePNG(RES("R.drawable.btn_pressed")), wyr(DP(9), DP(7), DP(22), DP(28)));
		normal->setContentSize(DP(150), DP(44));
		pressed->setContentSize(DP(150), DP(44));
		wyButton* button = new wyButton(normal, pressed, NULL, NULL, NULL, wyTargetSelector::make(this, SEL(wyEdgeShapesTestLayer::onCreate)));
		button->setPosition(DP(80), wyDevice::winHeight - DP(30));
		addChildLocked(button, 1);
		button->release();

		// label for create button
		wyBitmapFont* font = wyBitmapFont::loadFont(RES("R.raw.bitmapfont"));
		wyBitmapFontLabel* label = wyBitmapFontLabel::make(font, "Create Shape");
		label->setColor(wyc3b(255, 255, 0));
		label->setPosition(DP(80), wyDevice::winHeight - DP(30));
		addChildLocked(label, 1);

		// destroy button
		button = new wyButton(normal, pressed, NULL, NULL, NULL, wyTargetSelector::make(this, SEL(wyEdgeShapesTestLayer::onDestroy)));
		button->setPosition(DP(240), wyDevice::winHeight - DP(30));
		addChildLocked(button, 1);
		button->release();

		// label for destroy button
		label = wyBitmapFontLabel::make(font, "Destroy Shape");
		label->setColor(wyc3b(255, 255, 0));
		label->setPosition(DP(240), wyDevice::winHeight - DP(30));
		addChildLocked(label, 1);

		startUpdateWorld();
	}

	virtual ~wyEdgeShapesTestLayer() {
	}

	virtual void updateWorld(float delta) {
		wyBox2DTestLayer::updateWorld(delta);

		float32 L = 25.0f;
		b2Vec2 point1(0.0f, 10.0f);
		b2Vec2 d(L * cosf(m_angle), -L * b2Abs(sinf(m_angle)));
		b2Vec2 point2 = point1 + d;

		EdgeShapesCallback callback;

		m_box2d->getWorld()->RayCast(&callback, point1, point2);

		// TODO gles2
		//glPushMatrix();
		//{
		//	m_box2d->transformAncestors();
		//	m_box2d->transform();

		//	b2Draw* dd = m_box2d->getDebugDrawImpl();
		//	if(callback.m_fixture) {
		//		dd->DrawPoint(callback.m_point, 5.0f, b2Color(0.4f, 0.9f, 0.4f));

		//		dd->DrawSegment(point1, callback.m_point, b2Color(0.8f, 0.8f, 0.8f));

		//		b2Vec2 head = callback.m_point + 0.5f * callback.m_normal;
		//		dd->DrawSegment(callback.m_point, head, b2Color(0.9f, 0.9f, 0.4f));
		//	} else {
		//		dd->DrawSegment(point1, point2, b2Color(0.8f, 0.8f, 0.8f));
		//	}
		//}
		//glPopMatrix();

		m_angle += 0.25f * b2_pi / 180.0f;
	}

	void Create(int32 index)
	{
		// get world
		b2World* world = m_box2d->getWorld();

		if (m_bodies[m_bodyIndex] != NULL)
		{
			world->DestroyBody(m_bodies[m_bodyIndex]);
			m_bodies[m_bodyIndex] = NULL;
		}

		b2BodyDef bd;

		float32 x = RandomFloat(-10.0f, 10.0f);
		float32 y = RandomFloat(10.0f, 20.0f);
		bd.position.Set(x, y);
		bd.angle = RandomFloat(-b2_pi, b2_pi);
		bd.type = b2_dynamicBody;

		if (index == 4)
		{
			bd.angularDamping = 0.02f;
		}

		m_bodies[m_bodyIndex] = world->CreateBody(&bd);

		if (index < 4)
		{
			b2FixtureDef fd;
			fd.shape = m_polygons + index;
			fd.friction = 0.3f;
			fd.density = 20.0f;
			m_bodies[m_bodyIndex]->CreateFixture(&fd);
		}
		else
		{
			b2FixtureDef fd;
			fd.shape = &m_circle;
			fd.friction = 0.3f;
			fd.density = 20.0f;
			m_bodies[m_bodyIndex]->CreateFixture(&fd);
		}

		m_bodyIndex = (m_bodyIndex + 1) % e_maxBodies;
	}

	void DestroyBody()
	{
		for (int32 i = 0; i < e_maxBodies; ++i)
		{
			if (m_bodies[i] != NULL)
			{
				m_box2d->getWorld()->DestroyBody(m_bodies[i]);
				m_bodies[i] = NULL;
				return;
			}
		}
	}

	virtual bool keyDown(wyKeyEvent& event) {
		switch(event.keyCode) {
			case KEYCODE_MENU:
				Create(rand() % 5);
				break;
			case KEYCODE_SEARCH:
				DestroyBody();
				break;
			default:
				return false;
		}

		return true;
	}

	void onCreate(wyTargetSelector* ts) {
		Create(rand() % 5);
	}

	void onDestroy(wyTargetSelector* ts) {
		DestroyBody();
	}
};

///////////////////////////////////////////////////////////////////////////////

class wyBodyAnimationTestLayer : public wyBox2DTestLayer {
public:
	wyBodyAnimationTestLayer() {
		b2World* world = m_box2d->getWorld();
		m_box2d->setDebugDraw(false);

		// set gravity
		world->SetGravity(b2Vec2(0, -10));

		// create ground body
		b2BodyDef* bd = new b2BodyDef();
		bd->position.Set(0.0f, 0.0f);
		b2Body* ground = world->CreateBody(bd);
		delete bd;
		bd = NULL;

		// create bottom edge
		b2EdgeShape* es = new b2EdgeShape();
		b2FixtureDef* fixDef = new b2FixtureDef();
		fixDef->shape = es;
		fixDef->density = 0.0f;
		fixDef->restitution = 0.5f;
		es->Set(b2Vec2(0, 0), b2Vec2(m_box2d->pixel2Meter(wyDevice::winWidth), 0));
		ground->CreateFixture(fixDef);
		delete fixDef;
		fixDef = NULL;

		// create circle body
		bd = new b2BodyDef();
		bd->type = b2_dynamicBody;
		bd->position.Set(m_box2d->pixel2Meter(wyDevice::winWidth / 2),
				m_box2d->pixel2Meter(wyDevice::winHeight));
		b2Body* ball = world->CreateBody(bd);
		delete bd;
		bd = NULL;

		// create circle shape for ball
		b2PolygonShape* ps = new b2PolygonShape();
		ps->SetAsBox(m_box2d->pixel2Meter(DP(85) / 2), m_box2d->pixel2Meter(DP(121) / 2));
		fixDef = new b2FixtureDef();
		fixDef->shape = ps;
		fixDef->restitution = 0.5f;
		fixDef->density = 1.0f;
		b2Fixture* fixture = ball->CreateFixture(fixDef);
		delete fixDef;
		fixDef = NULL;

		// add a sprite for animation, its tag is 1000
		wyUserData ud;
		ud.p = ball;
		wySprite* sprite = wySprite::make(NULL);
		sprite->setUserData(ud);
		addChildLocked(sprite, 0, 1000);

		// create fixture animation
		wyAnimation* anim = wyAnimation::make(0);
		anim->addFrame(1.0f, wyTexture2D::makePNG(RES("R.drawable.grossini_dance_01")));
		anim->addFrame(1.0f, wyTexture2D::makePNG(RES("R.drawable.grossini_dance_02")));
		anim->addFrame(1.0f, wyTexture2D::makePNG(RES("R.drawable.grossini_dance_03")));
		anim->addFrame(1.0f, wyTexture2D::makePNG(RES("R.drawable.grossini_dance_04")));
		anim->addFrame(1.0f, wyTexture2D::makePNG(RES("R.drawable.grossini_dance_05")));
		anim->addFrame(1.0f, wyTexture2D::makePNG(RES("R.drawable.grossini_dance_06")));
		anim->addFrame(1.0f, wyTexture2D::makePNG(RES("R.drawable.grossini_dance_07")));
		anim->addFrame(1.0f, wyTexture2D::makePNG(RES("R.drawable.grossini_dance_08")));
		anim->addFrame(1.0f, wyTexture2D::makePNG(RES("R.drawable.grossini_dance_09")));
		anim->addFrame(1.0f, wyTexture2D::makePNG(RES("R.drawable.grossini_dance_10")));
		anim->addFrame(1.0f, wyTexture2D::makePNG(RES("R.drawable.grossini_dance_11")));
		anim->addFrame(1.0f, wyTexture2D::makePNG(RES("R.drawable.grossini_dance_12")));
		anim->addFrame(1.0f, wyTexture2D::makePNG(RES("R.drawable.grossini_dance_13")));
		anim->addFrame(1.0f, wyTexture2D::makePNG(RES("R.drawable.grossini_dance_14")));
		wyAnimate* a = wyAnimate::make(anim);
		wyRepeatForever* rf = wyRepeatForever::make(a);
		sprite->runAction(rf);

		// start update world
		startUpdateWorld();
	}

	virtual ~wyBodyAnimationTestLayer() {
	}

	virtual void updateWorld(float dt) {
		wyBox2DTestLayer::updateWorld(dt);

		// update sprite position
		wySprite* sprite = (wySprite*)getChildByTagLocked(1000);
		b2Body* b = (b2Body*)(sprite->getUserData().p);
        const b2Vec2& bodyPos = b->GetPosition();
        sprite->setPosition(m_box2d->meter2Pixel(bodyPos.x), m_box2d->meter2Pixel(bodyPos.y));
		sprite->setRotation(wyMath::r2d(-b->GetAngle()));
	}
};

//////////////////////////////////////////////////////////////////////////////////////

class wyGearsTestLayer : public wyBox2DTestLayer {
private:
	b2RevoluteJoint* m_joint1;
	b2RevoluteJoint* m_joint2;
	b2PrismaticJoint* m_joint3;
	b2GearJoint* m_joint4;
	b2GearJoint* m_joint5;

public:
	wyGearsTestLayer() {
		// get world
		b2World* world = m_box2d->getWorld();

		// set gravity
		world->SetGravity(b2Vec2(0, -10));

		// place box2d to center of bottom edge
		m_box2d->setPosition(wyDevice::winWidth / 2, 0);

		b2Body* ground = NULL;
		{
			b2BodyDef bd;
			ground = world->CreateBody(&bd);

			b2EdgeShape shape;
			shape.Set(b2Vec2(50.0f, 0.0f), b2Vec2(-50.0f, 0.0f));
			ground->CreateFixture(&shape, 0.0f);
		}

		{
			b2CircleShape circle1;
			circle1.m_radius = 1.0f;

			b2CircleShape circle2;
			circle2.m_radius = 2.0f;

			b2PolygonShape box;
			box.SetAsBox(0.5f, 5.0f);

			b2BodyDef bd1;
			bd1.type = b2_dynamicBody;
			bd1.position.Set(-3.0f, 12.0f);
			b2Body* body1 = world->CreateBody(&bd1);
			body1->CreateFixture(&circle1, 5.0f);

			b2RevoluteJointDef jd1;
			jd1.bodyA = ground;
			jd1.bodyB = body1;
			jd1.localAnchorA = ground->GetLocalPoint(bd1.position);
			jd1.localAnchorB = body1->GetLocalPoint(bd1.position);
			jd1.referenceAngle = body1->GetAngle() - ground->GetAngle();
			m_joint1 = (b2RevoluteJoint*)world->CreateJoint(&jd1);

			b2BodyDef bd2;
			bd2.type = b2_dynamicBody;
			bd2.position.Set(0.0f, 12.0f);
			b2Body* body2 = world->CreateBody(&bd2);
			body2->CreateFixture(&circle2, 5.0f);

			b2RevoluteJointDef jd2;
			jd2.Initialize(ground, body2, bd2.position);
			m_joint2 = (b2RevoluteJoint*)world->CreateJoint(&jd2);

			b2BodyDef bd3;
			bd3.type = b2_dynamicBody;
			bd3.position.Set(2.5f, 12.0f);
			b2Body* body3 = world->CreateBody(&bd3);
			body3->CreateFixture(&box, 5.0f);

			b2PrismaticJointDef jd3;
			jd3.Initialize(ground, body3, bd3.position, b2Vec2(0.0f, 1.0f));
			jd3.lowerTranslation = -5.0f;
			jd3.upperTranslation = 5.0f;
			jd3.enableLimit = true;

			m_joint3 = (b2PrismaticJoint*)world->CreateJoint(&jd3);

			b2GearJointDef jd4;
			jd4.bodyA = body1;
			jd4.bodyB = body2;
			jd4.joint1 = m_joint1;
			jd4.joint2 = m_joint2;
			jd4.ratio = circle2.m_radius / circle1.m_radius;
			m_joint4 = (b2GearJoint*)world->CreateJoint(&jd4);

			b2GearJointDef jd5;
			jd5.bodyA = body2;
			jd5.bodyB = body3;
			jd5.joint1 = m_joint2;
			jd5.joint2 = m_joint3;
			jd5.ratio = -1.0f / circle2.m_radius;
			m_joint5 = (b2GearJoint*)world->CreateJoint(&jd5);
		}

		startUpdateWorld();
	}

	virtual ~wyGearsTestLayer() {
	}
};

/////////////////////////////////////////////////////////////////////////

class wyOneWayTestLayer : public wyBox2DTestLayer, public b2ContactListener {
private:
	enum State
	{
		e_unknown,
		e_above,
		e_below,
	};

	float32 m_radius, m_top, m_bottom;
	State m_state;
	b2Fixture* m_platform;
	b2Fixture* m_character;

public:
	wyOneWayTestLayer() {
		// get world
		b2World* world = m_box2d->getWorld();

		// set gravity
		world->SetGravity(b2Vec2(0, -10));

		// set contact listener
		world->SetContactListener(this);

		// place box2d to center of bottom edge
		m_box2d->setPosition(wyDevice::winWidth / 2, 0);

		// Ground
		{
			b2BodyDef bd;
			b2Body* ground = world->CreateBody(&bd);

			b2EdgeShape shape;
			shape.Set(b2Vec2(-20.0f, 0.0f), b2Vec2(20.0f, 0.0f));
			ground->CreateFixture(&shape, 0.0f);
		}

		// Platform
		{
			b2BodyDef bd;
			bd.position.Set(0.0f, 10.0f);
			b2Body* body = world->CreateBody(&bd);

			b2PolygonShape shape;
			shape.SetAsBox(3.0f, 0.5f);
			m_platform = body->CreateFixture(&shape, 0.0f);

			m_bottom = 10.0f - 0.5f;
			m_top = 10.0f + 0.5f;
		}

		// Actor
		{
			b2BodyDef bd;
			bd.type = b2_dynamicBody;
			bd.position.Set(0.0f, 12.0f);
			b2Body* body = world->CreateBody(&bd);

			m_radius = 0.5f;
			b2CircleShape shape;
			shape.m_radius = m_radius;
			m_character = body->CreateFixture(&shape, 20.0f);

			body->SetLinearVelocity(b2Vec2(0.0f, -50.0f));

			m_state = e_unknown;
		}

		// add a hint label
		wyLabel* label = wyLabel::make("try drag ball through platform",
				SP(14));
		label->setPosition(wyDevice::winWidth / 2, wyDevice::winHeight - DP(60));
		addChildLocked(label);

		startUpdateWorld();
	}

	virtual ~wyOneWayTestLayer() {
	}

	virtual void PreSolve(b2Contact* contact, const b2Manifold* oldManifold) {
		b2Fixture* fixtureA = contact->GetFixtureA();
		b2Fixture* fixtureB = contact->GetFixtureB();

		if(fixtureA != m_platform && fixtureA != m_character) {
			return;
		}

		if(fixtureB != m_platform && fixtureB != m_character) {
			return;
		}

		b2Vec2 position = m_character->GetBody()->GetPosition();

		if(position.y < m_top + m_radius - 3.0f * b2_linearSlop) {
			contact->SetEnabled(false);
		}
	}
};

/////////////////////////////////////////////////////////////////////////////

class wyPhysicsEditorTestLayer : public wyLayer {
private:
    wyBox2D* m_box2d;
    wyBox2DPELoader* m_bodyLoader;

    wyArray* m_arrayBodies;

public:
    wyPhysicsEditorTestLayer() {
    	m_arrayBodies = wyArrayNew(20);
	    setTouchEnabled(true);

	    m_bodyLoader = new wyBox2DPELoader(RES("R.raw.shapedefs_box2d"));
	    m_box2d = new wyBox2D();
	    m_box2d->setMeterPixels(m_bodyLoader->getMeterPixels());
	    m_box2d->setDebugDraw(false);

	    m_box2d->getWorld()->SetGravity(b2Vec2(0, -10.0));
	    m_box2d->autoRelease();

	    b2BodyDef bd;
	    bd.type = b2_staticBody;
	    bd.position = b2Vec2(m_box2d->pixel2Meter(wyDevice::winWidth / 2), m_box2d->pixel2Meter(10.0f));
	    b2FixtureDef fd;
	    b2PolygonShape* shape = new b2PolygonShape();
	    shape->SetAsBox(m_box2d->pixel2Meter(wyDevice::winWidth), m_box2d->pixel2Meter(2.0f));
	    fd.shape = shape;
	    b2Body* body = m_box2d->getWorld()->CreateBody(&bd);
	    body->CreateFixture(&fd);
	    delete shape;

	    addChildLocked(m_box2d);

		wyTargetSelector* ts = wyTargetSelector::make(this, SEL(wyPhysicsEditorTestLayer::onUpdate));
		wyTimer* t = wyTimer::make(ts);
		scheduleLocked(t);

		wyToast::make("touch to add body", 3.0f)->show();
	}

    virtual ~wyPhysicsEditorTestLayer() {
	    wyArrayDestroy(m_arrayBodies);
	    wyObjectRelease(m_bodyLoader);
	}

	void onUpdate(wyTargetSelector* ts) {
	    m_box2d->getWorld()->Step(1.0f / 60, 10, 10);
	    m_box2d->getWorld()->ClearForces();

	    for(int i = 0; i < m_arrayBodies->num; ++i) {
	        b2Body* body = (b2Body*)m_arrayBodies->arr[i];
	        if(body) {
			    b2Vec2 pos = body->GetPosition();
			    float angle = body->GetAngle();

				wySprite* sprite = (wySprite*)body->GetUserData();
			    sprite->setPosition(m_box2d->meter2Pixel(pos.x), m_box2d->meter2Pixel(pos.y));
			    sprite->setRotation(-wyMath::r2d(angle));
			    sprite->setVisible(true);

			    if(pos.y < 0) {
				    m_box2d->getWorld()->DestroyBody(body);
				    m_box2d->removeChildLocked(sprite, NULL);
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

    virtual bool touchesBegan(wyMotionEvent& e) {
	    int randNum = rand() % 7;
	    float radian = wyMath::d2r(wyMath::randMinusOneToOne() * 360);

	    b2Body* body = NULL;
	    wySprite* sprite = NULL;
	    wyPoint anchorPercent;
	    switch(randNum) {
	        case 0:
	            body = m_bodyLoader->createBodyByName(m_box2d, "drink");
	            sprite = wySprite::make(wyTexture2D::makePNG(wyUtils::getResId("drink", "drawable", NULL)));
	            anchorPercent = m_bodyLoader->getAnchorPercent("drink");
	            break;
	        case 1:
	            body = m_bodyLoader->createBodyByName(m_box2d, "hamburger");
	            sprite = wySprite::make(wyTexture2D::makePNG(wyUtils::getResId("hamburger", "drawable", NULL)));
	            anchorPercent = m_bodyLoader->getAnchorPercent("hamburger");
	            break;
	        case 2:
	            body = m_bodyLoader->createBodyByName(m_box2d, "hotdog");
	            sprite = wySprite::make(wyTexture2D::makePNG(wyUtils::getResId("hotdog", "drawable", NULL)));
	            anchorPercent = m_bodyLoader->getAnchorPercent("hotdog");
	            break;
	        case 3:
	            body = m_bodyLoader->createBodyByName(m_box2d, "icecream");
	            sprite = wySprite::make(wyTexture2D::makePNG(wyUtils::getResId("icecream", "drawable", NULL)));
	            anchorPercent = m_bodyLoader->getAnchorPercent("icecream");
	            break;
	        case 4:
	            body = m_bodyLoader->createBodyByName(m_box2d, "icecream2");
	            sprite = wySprite::make(wyTexture2D::makePNG(wyUtils::getResId("icecream2", "drawable", NULL)));
	            anchorPercent = m_bodyLoader->getAnchorPercent("icecream2");
	            break;
	        case 5:
	            body = m_bodyLoader->createBodyByName(m_box2d, "icecream3");
	            sprite = wySprite::make(wyTexture2D::makePNG(wyUtils::getResId("icecream3", "drawable", NULL)));
	            anchorPercent = m_bodyLoader->getAnchorPercent("icecream3");
	            break;
	        case 6:
	            body = m_bodyLoader->createBodyByName(m_box2d, "orange");
	            sprite = wySprite::make(wyTexture2D::makePNG(wyUtils::getResId("orange", "drawable", NULL)));
	            anchorPercent = m_bodyLoader->getAnchorPercent("orange");
	            break;
	    }

	    body->SetTransform(b2Vec2(m_box2d->pixel2Meter(e.x[0]), m_box2d->pixel2Meter(e.y[0])), radian);

	    sprite->setAnchor(anchorPercent.x, anchorPercent.y);
	    m_box2d->addChildLocked(sprite);
	    sprite->setVisible(false);
	    body->SetUserData(sprite);

	    wyArrayPush(m_arrayBodies, body);
        return true;
	}
};

///////////////////////////////////////////////////////////////////////////////////////

class wyPulleysTestLayer : public wyBox2DTestLayer {
private:
	b2PulleyJoint* m_joint1;

public:
	wyPulleysTestLayer() {
		// get world
		b2World* world = m_box2d->getWorld();

		// set gravity
		world->SetGravity(b2Vec2(0, -10));

		// place box2d to center of bottom edge
		m_box2d->setPosition(wyDevice::winWidth / 2, 0);

		b2Body* ground = NULL;
		{
			b2BodyDef bd;
			ground = world->CreateBody(&bd);

			b2EdgeShape shape;
			shape.Set(b2Vec2(-40.0f, 0.0f), b2Vec2(40.0f, 0.0f));
			ground->CreateFixture(&shape, 0.0f);
		}

		{
			float32 a = 2.0f;
			float32 b = 4.0f;
			float32 y = 10.0f;
			float32 L = 8.0f;

			b2PolygonShape shape;
			shape.SetAsBox(a, b);

			b2BodyDef bd;
			bd.type = b2_dynamicBody;

			bd.position.Set(-4.0f, y);
			b2Body* body1 = world->CreateBody(&bd);
			body1->CreateFixture(&shape, 5.0f);

			bd.position.Set(4.0f, y);
			b2Body* body2 = world->CreateBody(&bd);
			body2->CreateFixture(&shape, 5.0f);

			b2PulleyJointDef pulleyDef;
			b2Vec2 anchor1(-4.0f, y + b);
			b2Vec2 anchor2(4.0f, y + b);
			b2Vec2 groundAnchor1(-4.0f, y + b + L);
			b2Vec2 groundAnchor2(4.0f, y + b + L);
			pulleyDef.Initialize(body1, body2, groundAnchor1, groundAnchor2, anchor1, anchor2, 2.0f);

			m_joint1 = (b2PulleyJoint*)world->CreateJoint(&pulleyDef);
		}

		startUpdateWorld();
	}

	virtual ~wyPulleysTestLayer() {
	}
};

////////////////////////////////////////////////////////////////////

class wyPyramidTestLayer : public wyBox2DTestLayer {
public:
	enum
	{
		e_count = 15,
	};

	wyPyramidTestLayer() {
		// get world
		b2World* world = m_box2d->getWorld();

		// set gravity
		world->SetGravity(b2Vec2(0, -10));

		// place box2d to center of bottom edge
		m_box2d->setPosition(wyDevice::winWidth / 2, 0);

		{
			b2BodyDef bd;
			b2Body* ground = world->CreateBody(&bd);

			b2EdgeShape shape;
			shape.Set(b2Vec2(-40.0f, 0.0f), b2Vec2(40.0f, 0.0f));
			ground->CreateFixture(&shape, 0.0f);
		}

		{
			float32 a = 0.5f;
			b2PolygonShape shape;
			shape.SetAsBox(a, a);

			b2Vec2 x(-7.0f, 0.75f);
			b2Vec2 y;
			b2Vec2 deltaX(0.5625f, 1.25f);
			b2Vec2 deltaY(1.125f, 0.0f);

			for (int32 i = 0; i < e_count; ++i)
			{
				y = x;

				for (int32 j = i; j < e_count; ++j)
				{
					b2BodyDef bd;
					bd.type = b2_dynamicBody;
					bd.position = y;
					b2Body* body = world->CreateBody(&bd);
					body->CreateFixture(&shape, 5.0f);

					y += deltaY;
				}

				x += deltaX;
			}
		}

		startUpdateWorld();
	}

	virtual ~wyPyramidTestLayer() {
	}
};

///////////////////////////////////////////////////////////////////////////////////

class wyRopeTestLayer : public wyBox2DTestLayer {
private:
	b2RopeJointDef m_ropeDef;
	b2Joint* m_rope;

	wyBitmapFontLabel* m_label;

public:
	wyRopeTestLayer() {
		// get world
		b2World* world = m_box2d->getWorld();

		// set gravity
		world->SetGravity(b2Vec2(0, -10));

		// place box2d to center of bottom edge
		m_box2d->setPosition(wyDevice::winWidth / 2, 0);

		b2Body* ground = NULL;
		{
			b2BodyDef bd;
			ground = world->CreateBody(&bd);

			b2EdgeShape shape;
			shape.Set(b2Vec2(-40.0f, 0.0f), b2Vec2(40.0f, 0.0f));
			ground->CreateFixture(&shape, 0.0f);
		}

		{
			b2PolygonShape shape;
			shape.SetAsBox(0.5f, 0.125f);

			b2FixtureDef fd;
			fd.shape = &shape;
			fd.density = 20.0f;
			fd.friction = 0.2f;
			fd.filter.categoryBits = 0x0001;
			fd.filter.maskBits = 0xFFFF & ~0x0002;

			b2RevoluteJointDef jd;
			jd.collideConnected = false;

			const int32 N = 10;
			const float32 y = 15.0f;
			m_ropeDef.localAnchorA.Set(0.0f, y);

			b2Body* prevBody = ground;
			for (int32 i = 0; i < N; ++i)
			{
				b2BodyDef bd;
				bd.type = b2_dynamicBody;
				bd.position.Set(0.5f + 1.0f * i, y);
				if (i == N - 1)
				{
					shape.SetAsBox(1.5f, 1.5f);
					fd.density = 100.0f;
					fd.filter.categoryBits = 0x0002;
					bd.position.Set(1.0f * i, y);
					bd.angularDamping = 0.4f;
				}

				b2Body* body = world->CreateBody(&bd);

				body->CreateFixture(&fd);

				b2Vec2 anchor(float32(i), y);
				jd.Initialize(prevBody, body, anchor);
				world->CreateJoint(&jd);

				prevBody = body;
			}

			m_ropeDef.localAnchorB.SetZero();

			float32 extraLength = 0.01f;
			m_ropeDef.maxLength = N - 1.0f + extraLength;
			m_ropeDef.bodyB = prevBody;
		}

		{
			m_ropeDef.bodyA = ground;
			m_rope = world->CreateJoint(&m_ropeDef);
		}

		setKeyEnabled(true);

		// toggle button
		wyNinePatchSprite* normal = wyNinePatchSprite::make(wyTexture2D::makePNG(RES("R.drawable.btn_normal")), wyr(DP(9), DP(7), DP(22), DP(28)));
		wyNinePatchSprite* pressed = wyNinePatchSprite::make(wyTexture2D::makePNG(RES("R.drawable.btn_pressed")), wyr(DP(9), DP(7), DP(22), DP(28)));
		normal->setContentSize(DP(300), DP(44));
		pressed->setContentSize(DP(300), DP(44));
		wyButton* button = new wyButton(normal, pressed, NULL, NULL, NULL, wyTargetSelector::make(this, SEL(wyRopeTestLayer::onUpdate)));
		button->setPosition(wyDevice::winWidth / 2, wyDevice::winHeight - DP(30));
		addChildLocked(button, 1);
		button->release();

		// label for toggle button
		wyBitmapFont* font = wyBitmapFont::loadFont(RES("R.raw.bitmapfont"));
		m_label = wyBitmapFontLabel::make(font, "Toggle Rope Joint ON");
		m_label->setColor(wyc3b(255, 255, 0));
		m_label->setPosition(wyDevice::winWidth / 2, wyDevice::winHeight - DP(30));
		addChildLocked(m_label, 1);

		startUpdateWorld();
	}

	virtual ~wyRopeTestLayer() {
	}

	virtual bool keyDown(wyKeyEvent& event) {
		switch(event.keyCode) {
			case KEYCODE_MENU:
			{
				// get world
				b2World* world = m_box2d->getWorld();

				if(m_rope) {
					world->DestroyJoint(m_rope);
					m_rope = NULL;
					m_label->setText("(Menu)Toggle the rope joint (Rope OFF)");
				} else {
					m_rope = world->CreateJoint(&m_ropeDef);
					m_label->setText("(Menu)Toggle the rope joint (Rope ON)");
				}
				break;
			}
			default:
				return false;
		}

		return true;
	}

	void onUpdate(wyTargetSelector* ts) {
		// get world
		b2World* world = m_box2d->getWorld();

		if(m_rope) {
			world->DestroyJoint(m_rope);
			m_rope = NULL;
			m_label->setText("Toggle Rope Joint OFF");
		} else {
			m_rope = world->CreateJoint(&m_ropeDef);
			m_label->setText("Toggle Rope Joint ON");
		}
	}
};

/////////////////////////////////////////////////////////////////////////////////

class wySensorTestLayer : public wyBox2DTestLayer, public b2ContactListener {
private:
	enum
	{
		e_count = 7
	};

	b2Fixture* m_sensor;
	b2Body* m_bodies[e_count];
	bool m_touching[e_count];

public:
	wySensorTestLayer() {
		b2World* world = m_box2d->getWorld();

		// set gravity
		world->SetGravity(b2Vec2(0, -10));

		// set contact listener
		world->SetContactListener(this);

		// place box2d to center of bottom edge
		m_box2d->setPosition(wyDevice::winWidth / 2, 0);

		{
			b2BodyDef bd;
			b2Body* ground = world->CreateBody(&bd);

			{
				b2EdgeShape shape;
				shape.Set(b2Vec2(-40.0f, 0.0f), b2Vec2(40.0f, 0.0f));
				ground->CreateFixture(&shape, 0.0f);
			}

			{
				b2CircleShape shape;
				shape.m_radius = 5.0f;
				shape.m_p.Set(0.0f, 10.0f);

				b2FixtureDef fd;
				fd.shape = &shape;
				fd.isSensor = true;
				m_sensor = ground->CreateFixture(&fd);
			}
		}

		{
			b2CircleShape shape;
			shape.m_radius = 1.0f;

			for (int32 i = 0; i < e_count; ++i)
			{
				b2BodyDef bd;
				bd.type = b2_dynamicBody;
				bd.position.Set(-10.0f + 3.0f * i, 20.0f);
				bd.userData = m_touching + i;

				m_touching[i] = false;
				m_bodies[i] = world->CreateBody(&bd);

				m_bodies[i]->CreateFixture(&shape, 1.0f);
			}
		}

		startUpdateWorld();
	}

	virtual ~wySensorTestLayer() {
	}

	// Implement contact listener.
	virtual void BeginContact(b2Contact* contact)
	{
		b2Fixture* fixtureA = contact->GetFixtureA();
		b2Fixture* fixtureB = contact->GetFixtureB();

		if (fixtureA == m_sensor)
		{
			void* userData = fixtureB->GetBody()->GetUserData();
			if (userData)
			{
				bool* touching = (bool*)userData;
				*touching = true;
			}
		}

		if (fixtureB == m_sensor)
		{
			void* userData = fixtureA->GetBody()->GetUserData();
			if (userData)
			{
				bool* touching = (bool*)userData;
				*touching = true;
			}
		}
	}

	// Implement contact listener.
	virtual void EndContact(b2Contact* contact)
	{
		b2Fixture* fixtureA = contact->GetFixtureA();
		b2Fixture* fixtureB = contact->GetFixtureB();

		if (fixtureA == m_sensor)
		{
			void* userData = fixtureB->GetBody()->GetUserData();
			if (userData)
			{
				bool* touching = (bool*)userData;
				*touching = false;
			}
		}

		if (fixtureB == m_sensor)
		{
			void* userData = fixtureA->GetBody()->GetUserData();
			if (userData)
			{
				bool* touching = (bool*)userData;
				*touching = false;
			}
		}
	}

	virtual void updateWorld(float delta)
	{
		wyBox2DTestLayer::updateWorld(delta);

		// Traverse the contact results. Apply a force on shapes
		// that overlap the sensor.
		for (int32 i = 0; i < e_count; ++i)
		{
			if (m_touching[i] == false)
			{
				continue;
			}

			b2Body* body = m_bodies[i];
			b2Body* ground = m_sensor->GetBody();

			b2CircleShape* circle = (b2CircleShape*)m_sensor->GetShape();
			b2Vec2 center = ground->GetWorldPoint(circle->m_p);

			b2Vec2 position = body->GetPosition();

			b2Vec2 d = center - position;
			if (d.LengthSquared() < FLT_EPSILON * FLT_EPSILON)
			{
				continue;
			}

			d.Normalize();
			b2Vec2 F = 100.0f * d;
			body->ApplyForce(F, position);
		}
	}
};

////////////////////////////////////////////////////////////////////////////

class wyShapeEditingTestLayer : public wyBox2DTestLayer {
private:
	b2Body* m_body;
	b2Fixture* m_fixture1;
	b2Fixture* m_fixture2;

public:
	wyShapeEditingTestLayer() {
		b2World* world = m_box2d->getWorld();

		// set gravity
		world->SetGravity(b2Vec2(0, -10));

		// place box2d to center of bottom edge
		m_box2d->setPosition(wyDevice::winWidth / 2, 0);

		{
			b2BodyDef bd;
			b2Body* ground = world->CreateBody(&bd);

			b2EdgeShape shape;
			shape.Set(b2Vec2(-40.0f, 0.0f), b2Vec2(40.0f, 0.0f));
			ground->CreateFixture(&shape, 0.0f);
		}

		b2BodyDef bd;
		bd.type = b2_dynamicBody;
		bd.position.Set(0.0f, 10.0f);
		m_body = world->CreateBody(&bd);

		b2PolygonShape shape;
		shape.SetAsBox(4.0f, 4.0f, b2Vec2(0.0f, 0.0f), 0.0f);
		m_fixture1 = m_body->CreateFixture(&shape, 10.0f);

		m_fixture2 = NULL;

		setKeyEnabled(true);

		// create button
		wyNinePatchSprite* normal = wyNinePatchSprite::make(wyTexture2D::makePNG(RES("R.drawable.btn_normal")), wyr(DP(9), DP(7), DP(22), DP(28)));
		wyNinePatchSprite* pressed = wyNinePatchSprite::make(wyTexture2D::makePNG(RES("R.drawable.btn_pressed")), wyr(DP(9), DP(7), DP(22), DP(28)));
		normal->setContentSize(DP(150), DP(44));
		pressed->setContentSize(DP(150), DP(44));
		wyButton* button = new wyButton(normal, pressed, NULL, NULL, NULL, wyTargetSelector::make(this, SEL(wyShapeEditingTestLayer::onCreate)));
		button->setPosition(DP(80), wyDevice::winHeight - DP(30));
		addChildLocked(button, 1);
		button->release();

		// label for create button
		wyBitmapFont* font = wyBitmapFont::loadFont(RES("R.raw.bitmapfont"));
		wyBitmapFontLabel* label = wyBitmapFontLabel::make(font, "Create Shape");
		label->setColor(wyc3b(255, 255, 0));
		label->setPosition(DP(80), wyDevice::winHeight - DP(30));
		addChildLocked(label, 1);

		// destroy button
		button = new wyButton(normal, pressed, NULL, NULL, NULL, wyTargetSelector::make(this, SEL(wyShapeEditingTestLayer::onDestroy)));
		button->setPosition(DP(240), wyDevice::winHeight - DP(30));
		addChildLocked(button, 1);
		button->release();

		// label for destroy button
		label = wyBitmapFontLabel::make(font, "Destroy Shape");
		label->setColor(wyc3b(255, 255, 0));
		label->setPosition(DP(240), wyDevice::winHeight - DP(30));
		addChildLocked(label, 1);

		startUpdateWorld();
	}

	virtual ~wyShapeEditingTestLayer() {
	}

	virtual bool keyDown(wyKeyEvent& event) {
		switch(event.keyCode) {
			case KEYCODE_MENU:
				if (m_fixture2 == NULL) {
					b2CircleShape shape;
					shape.m_radius = 3.0f;
					shape.m_p.Set(0.5f, -4.0f);
					m_fixture2 = m_body->CreateFixture(&shape, 10.0f);
					m_body->SetAwake(true);
				}
				break;
			case KEYCODE_SEARCH:
				if (m_fixture2 != NULL) {
					m_body->DestroyFixture(m_fixture2);
					m_fixture2 = NULL;
					m_body->SetAwake(true);
				}
				break;
			default:
				return false;
		}

		return true;
	}

	void onCreate(wyTargetSelector* ts) {
		if (m_fixture2 == NULL) {
			b2CircleShape shape;
			shape.m_radius = 3.0f;
			shape.m_p.Set(0.5f, -4.0f);
			m_fixture2 = m_body->CreateFixture(&shape, 10.0f);
			m_body->SetAwake(true);
		}
	}

	void onDestroy(wyTargetSelector* ts) {
		if (m_fixture2 != NULL) {
			m_body->DestroyFixture(m_fixture2);
			m_fixture2 = NULL;
			m_body->SetAwake(true);
		}
	}
};

//////////////////////////////////////////////////////////////////////////

class wySimpleTestLayer : public wyBox2DTestLayer {
public:
	wySimpleTestLayer() {
		b2World* world = m_box2d->getWorld();

		// set gravity
		world->SetGravity(b2Vec2(0, -10));

		// create ground body
		b2BodyDef bd;
		bd.position.Set(0.0f, 0.0f);
		b2Body* ground = world->CreateBody(&bd);

		// create bottom edge
		b2EdgeShape* es = new b2EdgeShape();
		b2FixtureDef fixDef;
		fixDef.shape = es;
		fixDef.density = 0.0f;
		fixDef.restitution = 0.5f;
		es->Set(b2Vec2(0, 0), b2Vec2(m_box2d->pixel2Meter(wyDevice::winWidth), 0));
		ground->CreateFixture(&fixDef);

		// create circle body
		bd.type = b2_dynamicBody;
		bd.position.Set(m_box2d->pixel2Meter(wyDevice::winWidth / 2),
				m_box2d->pixel2Meter(wyDevice::winHeight));
		b2Body* ball = world->CreateBody(&bd);

		// create circle shape for ball
		b2CircleShape* cs = new b2CircleShape();
		fixDef.shape = cs;
		fixDef.restitution = 0.5f;
		fixDef.density = 1.0f;
		cs->m_radius = 0.5f;
		ball->CreateFixture(&fixDef);

		// start update world
		startUpdateWorld();
	}

	virtual ~wySimpleTestLayer() {
	}
};

//////////////////////////////////////////////////////////////////////////////

class wySliderCrankTestLayer : public wyBox2DTestLayer {
private:
	b2RevoluteJoint* m_joint1;
	b2PrismaticJoint* m_joint2;

public:
	wySliderCrankTestLayer() {
		b2World* world = m_box2d->getWorld();

		// set gravity
		world->SetGravity(b2Vec2(0, -10));

		// place box2d to center of bottom edge
		m_box2d->setPosition(wyDevice::winWidth / 2, 0);

		b2Body* ground = NULL;
		{
			b2BodyDef bd;
			ground = world->CreateBody(&bd);

			b2EdgeShape shape;
			shape.Set(b2Vec2(-40.0f, 0.0f), b2Vec2(40.0f, 0.0f));
			ground->CreateFixture(&shape, 0.0f);
		}

		{
			b2Body* prevBody = ground;

			// Define crank.
			{
				b2PolygonShape shape;
				shape.SetAsBox(0.5f, 2.0f);

				b2BodyDef bd;
				bd.type = b2_dynamicBody;
				bd.position.Set(0.0f, 7.0f);
				b2Body* body = world->CreateBody(&bd);
				body->CreateFixture(&shape, 2.0f);

				b2RevoluteJointDef rjd;
				rjd.Initialize(prevBody, body, b2Vec2(0.0f, 5.0f));
				rjd.motorSpeed = 1.0f * b2_pi;
				rjd.maxMotorTorque = 10000.0f;
				rjd.enableMotor = true;
				m_joint1 = (b2RevoluteJoint*)world->CreateJoint(&rjd);

				prevBody = body;
			}

			// Define follower.
			{
				b2PolygonShape shape;
				shape.SetAsBox(0.5f, 4.0f);

				b2BodyDef bd;
				bd.type = b2_dynamicBody;
				bd.position.Set(0.0f, 13.0f);
				b2Body* body = world->CreateBody(&bd);
				body->CreateFixture(&shape, 2.0f);

				b2RevoluteJointDef rjd;
				rjd.Initialize(prevBody, body, b2Vec2(0.0f, 9.0f));
				rjd.enableMotor = false;
				world->CreateJoint(&rjd);

				prevBody = body;
			}

			// Define piston
			{
				b2PolygonShape shape;
				shape.SetAsBox(1.5f, 1.5f);

				b2BodyDef bd;
				bd.type = b2_dynamicBody;
				bd.fixedRotation = true;
				bd.position.Set(0.0f, 17.0f);
				b2Body* body = world->CreateBody(&bd);
				body->CreateFixture(&shape, 2.0f);

				b2RevoluteJointDef rjd;
				rjd.Initialize(prevBody, body, b2Vec2(0.0f, 17.0f));
				world->CreateJoint(&rjd);

				b2PrismaticJointDef pjd;
				pjd.Initialize(ground, body, b2Vec2(0.0f, 17.0f), b2Vec2(0.0f, 1.0f));

				pjd.maxMotorForce = 1000.0f;
				pjd.enableMotor = true;

				m_joint2 = (b2PrismaticJoint*)world->CreateJoint(&pjd);
			}

			// Create a payload
			{
				b2PolygonShape shape;
				shape.SetAsBox(1.5f, 1.5f);

				b2BodyDef bd;
				bd.type = b2_dynamicBody;
				bd.position.Set(0.0f, 23.0f);
				b2Body* body = world->CreateBody(&bd);
				body->CreateFixture(&shape, 2.0f);
			}
		}

		setKeyEnabled(true);

		// toggle friction button
		wyNinePatchSprite* normal = wyNinePatchSprite::make(wyTexture2D::makePNG(RES("R.drawable.btn_normal")), wyr(DP(9), DP(7), DP(22), DP(28)));
		wyNinePatchSprite* pressed = wyNinePatchSprite::make(wyTexture2D::makePNG(RES("R.drawable.btn_pressed")), wyr(DP(9), DP(7), DP(22), DP(28)));
		normal->setContentSize(DP(150), DP(44));
		pressed->setContentSize(DP(150), DP(44));
		wyButton* button = new wyButton(normal, pressed, NULL, NULL,  NULL, wyTargetSelector::make(this, SEL(wySliderCrankTestLayer::onToggleFriction)));
		button->setPosition(DP(80), wyDevice::winHeight - DP(30));
		addChildLocked(button, 1);
		button->release();

		// label for toggle friction button
		wyBitmapFont* font = wyBitmapFont::loadFont(RES("R.raw.bitmapfont"));
		wyBitmapFontLabel* label = wyBitmapFontLabel::make(font, "Toggle friction");
		label->setColor(wyc3b(255, 255, 0));
		label->setPosition(DP(80), wyDevice::winHeight - DP(30));
		addChildLocked(label, 1);

		// toggle motor button
		button = new wyButton(normal, pressed, NULL, NULL, NULL, wyTargetSelector::make(this, SEL(wySliderCrankTestLayer::onToggleMotor)));
		button->setPosition(DP(240), wyDevice::winHeight - DP(30));
		addChildLocked(button, 1);
		button->release();

		// label for toggle motor button
		label = wyBitmapFontLabel::make(font, "Toggle motor");
		label->setColor(wyc3b(255, 255, 0));
		label->setPosition(DP(240), wyDevice::winHeight - DP(30));
		addChildLocked(label, 1);

		startUpdateWorld();
	}

	virtual ~wySliderCrankTestLayer() {
	}

	virtual bool keyDown(wyKeyEvent& event) {
		switch(event.keyCode) {
			case KEYCODE_MENU:
				m_joint2->EnableMotor(!m_joint2->IsMotorEnabled());
				m_joint2->GetBodyB()->SetAwake(true);
				break;
			case KEYCODE_SEARCH:
				m_joint1->EnableMotor(!m_joint1->IsMotorEnabled());
				m_joint1->GetBodyB()->SetAwake(true);
				break;
			default:
				return false;
		}

		return true;
	}

	void onToggleFriction(wyTargetSelector* ts) {
		m_joint2->EnableMotor(!m_joint2->IsMotorEnabled());
		m_joint2->GetBodyB()->SetAwake(true);
	}

	void onToggleMotor(wyTargetSelector* ts) {
		m_joint1->EnableMotor(!m_joint1->IsMotorEnabled());
		m_joint1->GetBodyB()->SetAwake(true);
	}
};

//////////////////////////////////////////////////////////////////////////////////

class wySphereStackTestLayer : public wyBox2DTestLayer {
private:
	enum
	{
		e_count = 10
	};

	b2Body* m_bodies[e_count];

public:
	wySphereStackTestLayer() {
		b2World* world = m_box2d->getWorld();

		// set gravity
		world->SetGravity(b2Vec2(0, -10));

		// place box2d to center of bottom edge
		m_box2d->setPosition(wyDevice::winWidth / 2, 0);

		{
			b2BodyDef bd;
			b2Body* ground = world->CreateBody(&bd);

			b2EdgeShape shape;
			shape.Set(b2Vec2(-40.0f, 0.0f), b2Vec2(40.0f, 0.0f));
			ground->CreateFixture(&shape, 0.0f);
		}

		{
			b2CircleShape shape;
			shape.m_radius = 1.0f;

			for (int32 i = 0; i < e_count; ++i)
			{
				b2BodyDef bd;
				bd.type = b2_dynamicBody;
				bd.position.Set(0.0, 4.0f + 3.0f * i);

				m_bodies[i] = world->CreateBody(&bd);

				m_bodies[i]->CreateFixture(&shape, 1.0f);
			}
		}

		startUpdateWorld();
	}

	virtual ~wySphereStackTestLayer() {
	}
};

/////////////////////////////////////////////////////////////////////////

// control variables
static const float HORSEPOWER = 40;
static const float SIDEWAY_FRICTION_FORCE = 10;
static const float STEER_SPEED = 1.5f;
static const float MAX_STEER_ANGLE = b2_pi / 3;

class wyTensorDampingTestLayer : public wyBox2DTestLayer {
private:
	b2Body* m_car;
	b2Body* m_leftRearWheel;
	b2Body* m_leftFrontWheel;
	b2Body* m_rightRearWheel;
	b2Body* m_rightFrontWheel;
	b2RevoluteJoint* m_leftJoint;
	b2RevoluteJoint* m_rightJoint;

	float m_engineSpeed;
	float m_steeringAngle;

public:
	wyTensorDampingTestLayer() {
		// get world
		b2World* world = m_box2d->getWorld();

		// don't draw solid
		world->SetNoSolidDraw(true);

		// place box2d to center of bottom edge
		m_box2d->setPosition(0, 0);

		// init
		m_engineSpeed = 0;
		m_steeringAngle = 0;

		// position
		b2Vec2 carPos = b2Vec2(10, 10);
		b2Vec2 leftRearPos = b2Vec2(-1.5f, -1.9f);
		b2Vec2 rightRearPos = b2Vec2(1.5f, -1.9f);
		b2Vec2 leftFrontPos = b2Vec2(-1.5f, 1.9f);
		b2Vec2 rightFrontPos = b2Vec2(1.5f, 1.9f);

		// create controller for wheel
		b2TensorDampingControllerDef cd;
		cd.SetAxisAligned(10, 5);
		b2TensorDampingController* tdc = (b2TensorDampingController*)world->CreateController(&cd);

		// car
		{
			b2BodyDef bd;
			bd.linearDamping = 1;
			bd.angularDamping = 1;
			bd.type = b2_dynamicBody;
			bd.position = carPos;
			m_car = world->CreateBody(&bd);

			b2PolygonShape shape;
			shape.SetAsBox(1.5f, 2.5f);
			b2FixtureDef fd;
			fd.shape = &shape;
			fd.density = 1;
			m_car->CreateFixture(&fd);
		}

		// left-rear wheel
		{
			b2BodyDef bd;
			bd.type = b2_dynamicBody;
			bd.position = carPos;
			bd.position += leftRearPos;
			m_leftRearWheel = world->CreateBody(&bd);

			b2PolygonShape shape;
			shape.SetAsBox(0.2f, 0.5f);
			b2FixtureDef fd;
			fd.shape = &shape;
			fd.density = 1;
			m_leftRearWheel->CreateFixture(&fd);

			b2PrismaticJointDef jd;
			jd.Initialize(m_car, m_leftRearWheel, m_leftRearWheel->GetWorldCenter(), b2Vec2(1, 0));
			jd.enableLimit = true;
			jd.lowerTranslation = jd.upperTranslation = 0;
			world->CreateJoint(&jd);

			tdc->AddBody(m_leftRearWheel);
		}

		// right-rear wheel
		{
			b2BodyDef bd;
			bd.type = b2_dynamicBody;
			bd.position = carPos;
			bd.position += rightRearPos;
			m_rightRearWheel = world->CreateBody(&bd);

			b2PolygonShape shape;
			shape.SetAsBox(0.2f, 0.5f);
			b2FixtureDef fd;
			fd.shape = &shape;
			fd.density = 1;
			m_rightRearWheel->CreateFixture(&fd);

			b2PrismaticJointDef jd;
			jd.Initialize(m_car, m_rightRearWheel, m_rightRearWheel->GetWorldCenter(), b2Vec2(1, 0));
			jd.enableLimit = true;
			jd.lowerTranslation = jd.upperTranslation = 0;
			world->CreateJoint(&jd);

			tdc->AddBody(m_rightRearWheel);
		}

		// left-front wheel
		{
			b2BodyDef bd;
			bd.type = b2_dynamicBody;
			bd.position = carPos;
			bd.position += leftFrontPos;
			m_leftFrontWheel = world->CreateBody(&bd);

			b2PolygonShape shape;
			shape.SetAsBox(0.2f, 0.5f);
			b2FixtureDef fd;
			fd.shape = &shape;
			fd.density = 1;
			m_leftFrontWheel->CreateFixture(&fd);

			b2RevoluteJointDef jd;
			jd.Initialize(m_car, m_leftFrontWheel, m_leftFrontWheel->GetWorldCenter());
			jd.enableMotor = true;
			jd.maxMotorTorque = 100;
			m_leftJoint = (b2RevoluteJoint*)world->CreateJoint(&jd);

			tdc->AddBody(m_leftFrontWheel);
		}

		// right-front wheel
		{
			b2BodyDef bd;
			bd.type = b2_dynamicBody;
			bd.position = carPos;
			bd.position += rightFrontPos;
			m_rightFrontWheel = world->CreateBody(&bd);

			b2PolygonShape shape;
			shape.SetAsBox(0.2f, 0.5f);
			b2FixtureDef fd;
			fd.shape = &shape;
			fd.density = 1;
			m_rightFrontWheel->CreateFixture(&fd);

			b2RevoluteJointDef jd;
			jd.Initialize(m_car, m_rightFrontWheel, m_rightFrontWheel->GetWorldCenter());
			jd.enableMotor = true;
			jd.maxMotorTorque = 100;
			m_rightJoint = (b2RevoluteJoint*)world->CreateJoint(&jd);

			tdc->AddBody(m_rightFrontWheel);
		}

		// left button
		wyNinePatchSprite* normal = wyNinePatchSprite::make(wyTexture2D::makePNG(RES("R.drawable.btn_normal")), wyr(DP(9), DP(7), DP(22), DP(28)));
		wyNinePatchSprite* pressed = wyNinePatchSprite::make(wyTexture2D::makePNG(RES("R.drawable.btn_pressed")), wyr(DP(9), DP(7), DP(22), DP(28)));
		normal->setContentSize(DP(80), DP(44));
		pressed->setContentSize(DP(80), DP(44));
		wyButton* button = new wyButton(normal, pressed, NULL, NULL,
				wyTargetSelector::make(this, SEL(wyTensorDampingTestLayer::onLeft)),
				wyTargetSelector::make(this, SEL(wyTensorDampingTestLayer::onResetAngle)));
		button->setPosition(DP(40), wyDevice::winHeight - DP(30));
		addChildLocked(button, 1);
		button->release();

		// label for left button
		wyBitmapFont* font = wyBitmapFont::loadFont(RES("R.raw.bitmapfont"));
		wyBitmapFontLabel* label = wyBitmapFontLabel::make(font, "Left");
		label->setColor(wyc3b(255, 255, 0));
		label->setPosition(DP(40), wyDevice::winHeight - DP(30));
		addChildLocked(label, 1);

		// up button
		button = new wyButton(normal, pressed, NULL, NULL,
				wyTargetSelector::make(this, SEL(wyTensorDampingTestLayer::onUp)),
				wyTargetSelector::make(this, SEL(wyTensorDampingTestLayer::onResetSpeed)));
		button->setPosition(DP(120), wyDevice::winHeight - DP(30));
		addChildLocked(button, 1);
		button->release();

		// label for up button
		label = wyBitmapFontLabel::make(font, "Up");
		label->setColor(wyc3b(255, 255, 0));
		label->setPosition(DP(120), wyDevice::winHeight - DP(30));
		addChildLocked(label, 1);

		// down button
		button = new wyButton(normal, pressed, NULL, NULL,
				wyTargetSelector::make(this, SEL(wyTensorDampingTestLayer::onDown)),
				wyTargetSelector::make(this, SEL(wyTensorDampingTestLayer::onResetSpeed)));
		button->setPosition(DP(200), wyDevice::winHeight - DP(30));
		addChildLocked(button, 1);
		button->release();

		// label for down button
		label = wyBitmapFontLabel::make(font, "Down");
		label->setColor(wyc3b(255, 255, 0));
		label->setPosition(DP(200), wyDevice::winHeight - DP(30));
		addChildLocked(label, 1);

		// right button
		button = new wyButton(normal, pressed, NULL, NULL,
				wyTargetSelector::make(this, SEL(wyTensorDampingTestLayer::onRight)),
				wyTargetSelector::make(this, SEL(wyTensorDampingTestLayer::onResetAngle)));
		button->setPosition(DP(280), wyDevice::winHeight - DP(30));
		addChildLocked(button, 1);
		button->release();

		// label for right button
		label = wyBitmapFontLabel::make(font, "Right");
		label->setColor(wyc3b(255, 255, 0));
		label->setPosition(DP(280), wyDevice::winHeight - DP(30));
		addChildLocked(label, 1);

		startUpdateWorld();
	}

	virtual ~wyTensorDampingTestLayer() {
	}

	void onLeft(wyTargetSelector* ts) {
		m_steeringAngle = MAX_STEER_ANGLE;
	}

	void onRight(wyTargetSelector* ts) {
		m_steeringAngle = -MAX_STEER_ANGLE;
	}

	void onResetAngle(wyTargetSelector* ts) {
		m_steeringAngle = 0;
	}

	void onResetSpeed(wyTargetSelector* ts) {
		m_engineSpeed = 0;
	}

	void onUp(wyTargetSelector* ts) {
		m_car->SetAwake(false);
		m_engineSpeed = HORSEPOWER;
	}

	void onDown(wyTargetSelector* ts) {
		m_engineSpeed = -HORSEPOWER;
	}

	virtual void updateWorld(float delta) {
		wyBox2DTestLayer::updateWorld(delta);

		// driving
		const b2Transform& tl = m_leftFrontWheel->GetTransform();
		b2Vec2 ldirection = b2Vec2(-tl.q.s, tl.q.c);
		ldirection *= m_engineSpeed;
		const b2Transform& tr = m_rightFrontWheel->GetTransform();
		b2Vec2 rdirection = b2Vec2(-tr.q.s, tr.q.c);
		rdirection *= m_engineSpeed;
		m_leftFrontWheel->ApplyForce(ldirection, m_leftFrontWheel->GetPosition());
		m_rightFrontWheel->ApplyForce(rdirection, m_rightFrontWheel->GetPosition());

		// steering
		float mspeed = m_steeringAngle - m_leftJoint->GetJointAngle();
		m_leftJoint->SetMotorSpeed(mspeed * STEER_SPEED);
		mspeed = m_steeringAngle - m_rightJoint->GetJointAngle();
		m_rightJoint->SetMotorSpeed(mspeed * STEER_SPEED);
	}
};

/////////////////////////////////////////////////////////////////////////////////

class wyTexturedBounceTestLayer: public wyBox2DTestLayer {
public:
	wyTexturedBounceTestLayer() {
		b2World* world = m_box2d->getWorld();
		m_box2d->setDebugDraw(false);

	   /*
		 place box2d node in bottom left, you can place box2d node anywhere and the position
		 will affect origin of box2d rendering because wyBox2D is a node and it will perform
		 translate/rotation/scale before drawing.
		 */
		m_box2d->setPosition(0, 0);

		/*
		 get meter size of screen. wyDevice saves pixel size of screen, but box2d uses meter so we need convert it
		 */
		float meterWidth = m_box2d->pixel2Meter(wyDevice::winWidth);
		float meterHeight = m_box2d->pixel2Meter(wyDevice::winHeight);

		// create border in four sides
		b2Body* ground = NULL;
		{
			b2BodyDef bd;
			bd.position.Set(meterWidth / 2, meterHeight / 2);
			ground = world->CreateBody(&bd);

			// bottom edge
			b2EdgeShape bottom;
			bottom.Set(b2Vec2(-meterWidth / 2, -meterHeight / 2), b2Vec2(meterWidth / 2, -meterHeight / 2));
			b2FixtureDef fd;
			fd.shape = &bottom;
			ground->CreateFixture(&fd);

			// top edge
			b2EdgeShape top;
			top.Set(b2Vec2(-meterWidth / 2, meterHeight / 2), b2Vec2(meterWidth / 2, meterHeight / 2));
			fd.shape = &top;
			ground->CreateFixture(&fd);

			// left edge
			b2EdgeShape left;
			left.Set(b2Vec2(-meterWidth / 2, -meterHeight / 2), b2Vec2(-meterWidth / 2, meterHeight / 2));
			fd.shape = &left;
			ground->CreateFixture(&fd);

			// right edge
			b2EdgeShape right;
			right.Set(b2Vec2(meterWidth / 2, -meterHeight / 2), b2Vec2(meterWidth / 2, meterHeight / 2));
			fd.shape = &right;
			ground->CreateFixture(&fd);
		}

		/*
		 now we create ten boxes, DP is macro defined by WiEngine to convert point to pixel,
		 in iOS, point can be 1 pixel in iPhone/iPad or 2 pixels in iPhone Retain
		 */
		float size = DP(32.0f) / 2;
		float meterSize = m_box2d->pixel2Meter(size);
		for (int i = 0; i < 10; i++) {
			b2BodyDef bd;
			bd.type = b2_dynamicBody;
			bd.position.Set(frand() * meterWidth, frand() * meterHeight);
			bd.linearVelocity = b2Vec2(5 * frand_unit(), 5 * frand_unit());
			b2Body* body = world->CreateBody(&bd);
			body->SetTransform(bd.position, frand() * 2 * M_PI);

			b2PolygonShape box;
			box.SetAsBox(meterSize, meterSize);
			b2FixtureDef fd;
			fd.shape = &box;
			fd.restitution = 1.0f;
			fd.friction = 0.0f;
			fd.density = 1.0f;
			b2Fixture* f = body->CreateFixture(&fd);

			/*
			 create a sprite for every box and save it in body data
			 here we use wySprite, WiEngine also has a wySpriteEx class which is similar with CCSprite.
			 wySprite is an old implementation but we still keep it for some performance reason.
			 wySpriteEx can be used with wySpriteBatchNode or independently.

			 To create a wySprite, first we create a wyTexture2D object. It references a resource by a
			 resource id. Resource id is a concept of Android and WiEngine maps the resource id to iOS resource file
			 so that the code doesn't need to be changed when compile in iOS.
			 */
			wyTexture2D* tex = wyTexture2D::makePNG(RES("R.drawable.blocks"));
			wySprite* sprite = wySprite::make(tex,
											  wyr(wyMath::randMax(1) * size * 2, wyMath::randMax(1) * size * 2, size * 2, size * 2));
			const b2Vec2& bodyPos = body->GetPosition();
			sprite->setPosition(m_box2d->meter2Pixel(bodyPos.x), m_box2d->meter2Pixel(bodyPos.y));
			sprite->setRotation(wyMath::r2d(-body->GetAngle()));
			addChildLocked(sprite);
			body->SetUserData(sprite);
		}

		// center stick
		{
			/*
			 calculate meter size of stick, based on bar image size
			 bar image size is 224x15 pixels, we need use point
			 */
			float barW = DP(112);
			float barH = DP(7.5f);
			float barMW = m_box2d->pixel2Meter(barW);
			float barMH = m_box2d->pixel2Meter(barH);

			b2BodyDef bd;
			bd.type = b2_dynamicBody;
			bd.position.Set(meterWidth / 2, meterHeight / 2);
			b2Body* stickBody = world->CreateBody(&bd);

			b2PolygonShape stick;
			stick.SetAsBox(barMW, barMH);
			b2FixtureDef fd;
			fd.shape = &stick;
			fd.restitution = 1.0f;
			fd.friction = 0.0f;
			fd.density = 1.0f;
			b2Fixture* f = stickBody->CreateFixture(&fd);

			b2RevoluteJointDef jd;
			jd.bodyA = ground;
			jd.bodyB = stickBody;
			jd.localAnchorA = b2Vec2(0, 0);
			jd.localAnchorB = b2Vec2(0, 0);
			world->CreateJoint(&jd);

			// bind a bar sprite to it
			wyTexture2D* tex = wyTexture2D::makePNG(RES("R.drawable.bar"));
			wySprite* sprite = wySprite::make(tex);
			const b2Vec2& bodyPos = stickBody->GetPosition();
			sprite->setPosition(m_box2d->meter2Pixel(bodyPos.x), m_box2d->meter2Pixel(bodyPos.y));
			sprite->setRotation(wyMath::r2d(-stickBody->GetAngle()));
			addChildLocked(sprite);
			stickBody->SetUserData(sprite);
		}

		startUpdateWorld();
	}

	virtual ~wyTexturedBounceTestLayer() {
	}

	virtual void updateWorld(float dt) {
		wyBox2DTestLayer::updateWorld(dt);

        // sync position and angle between sprite and body
		b2World* world = m_box2d->getWorld();
        for(b2Body* body = world->GetBodyList(); body != NULL; body = body->GetNext()) {
            wySprite* sprite = (wySprite*)body->GetUserData();
            if(sprite != NULL) {
                const b2Vec2& bodyPos = body->GetPosition();
                sprite->setPosition(m_box2d->meter2Pixel(bodyPos.x), m_box2d->meter2Pixel(bodyPos.y));
				sprite->setRotation(wyMath::r2d(-body->GetAngle()));
            }
        }
	}
};

////////////////////////////////////////////////////////////////////////

class wyTexturedChainShapeTestLayer : public wyBox2DTestLayer {
public:
	wyTexturedChainShapeTestLayer() {
		b2World* world = m_box2d->getWorld();

		// place box2d in center
		m_box2d->setPosition(wyDevice::winWidth / 2, wyDevice::winHeight / 2);

		// set render
		m_box2d->setDebugDraw(false);

		// create body
		b2Body* body = NULL;
		{
			b2BodyDef bd;
			bd.type = b2_dynamicBody;
			bd.position.Set(0.0f, 0.0f);
			bd.angularVelocity = 0.2f;
			body = world->CreateBody(&bd);
		}

		// create chain shape
		{
			b2Vec2 vertices[] = {
					b2Vec2(-2.0f, 0.0f),
					b2Vec2(0.0f, 2.0f),
					b2Vec2(2.0f, 2.0f),
					b2Vec2(2.0f, -2.0f),
					b2Vec2(-2.0f, -2.0f)
			};
			b2ChainShape* ls = new b2ChainShape();
			ls->CreateLoop(vertices, 5);
			b2FixtureDef fixDef;
			fixDef.shape = ls;
			b2Fixture* f = body->CreateFixture(&fixDef);

			wyTexture2D* tex = wyTexture2D::makePNG(RES("R.drawable.rope"));
			// TODO
//			render->bindTexture(f, tex);
		}

		// start update world
		startUpdateWorld();
	}

	virtual ~wyTexturedChainShapeTestLayer() {
	}
};

///////////////////////////////////////////////////////////////////////////////////

class wyTexturedEdgeShapesTestLayer : public wyBox2DTestLayer {
private:
	enum
	{
		e_maxBodies = 256,
	};

	int32 m_bodyIndex;
	b2Body* m_bodies[e_maxBodies];
	b2PolygonShape m_polygons[3];
	b2CircleShape m_circle;

	float32 m_angle;

public:
	wyTexturedEdgeShapesTestLayer() {
		// get world
		b2World* world = m_box2d->getWorld();
		m_box2d->setDebugDraw(false);

		// set gravity
		world->SetGravity(b2Vec2(0, -10));

		// place box2d to center of bottom edge
		m_box2d->setPosition(wyDevice::winWidth / 2, wyDevice::winHeight / 4);

		// Ground body
		{
			b2BodyDef bd;
			b2Body* ground = world->CreateBody(&bd);

			float32 x1 = -20.0f;
			float32 y1 = 2.0f * cosf(x1 / 10.0f * b2_pi);
			wyTexture2D* tex = wyTexture2D::makePNG(RES("R.drawable.rope"));
			for (int32 i = 0; i < 80; ++i)
			{
				float32 x2 = x1 + 0.5f;
				float32 y2 = 2.0f * cosf(x2 / 10.0f * b2_pi);

				b2EdgeShape shape;
				shape.Set(b2Vec2(x1, y1), b2Vec2(x2, y2));
				b2Fixture* f = ground->CreateFixture(&shape, 0.0f);
				// TODO
//				render->bindTexture(f, tex);

				x1 = x2;
				y1 = y2;
			}
		}

		{
			b2Vec2 vertices[3];
			vertices[0].Set(-0.5f, 0.0f);
			vertices[1].Set(0.5f, 0.0f);
			vertices[2].Set(0.0f, 1.5f);
			m_polygons[0].Set(vertices, 3);
		}

		{
			float32 w = 1.0f;
			float32 b = w / (2.0f + b2Sqrt(2.0f));
			float32 s = b2Sqrt(2.0f) * b;

			b2Vec2 vertices[8];
			vertices[0].Set(0.5f * s, 0.0f);
			vertices[1].Set(0.5f * w, b);
			vertices[2].Set(0.5f * w, b + s);
			vertices[3].Set(0.5f * s, w);
			vertices[4].Set(-0.5f * s, w);
			vertices[5].Set(-0.5f * w, b + s);
			vertices[6].Set(-0.5f * w, b);
			vertices[7].Set(-0.5f * s, 0.0f);

			m_polygons[1].Set(vertices, 8);
		}

		{
			m_polygons[2].SetAsBox(0.5f, 0.5f);
		}

		{
			m_circle.m_radius = 0.5f;
		}

		m_bodyIndex = 0;
		memset(m_bodies, 0, sizeof(m_bodies));

		m_angle = 0.0f;

		setKeyEnabled(true);

		// create button
		wyNinePatchSprite* normal = wyNinePatchSprite::make(wyTexture2D::makePNG(RES("R.drawable.btn_normal")), wyr(DP(9), DP(7), DP(22), DP(28)));
		wyNinePatchSprite* pressed = wyNinePatchSprite::make(wyTexture2D::makePNG(RES("R.drawable.btn_pressed")), wyr(DP(9), DP(7), DP(22), DP(28)));
		normal->setContentSize(DP(150), DP(44));
		pressed->setContentSize(DP(150), DP(44));
		wyButton* button = new wyButton(normal, pressed, NULL, NULL, NULL, wyTargetSelector::make(this, SEL(wyTexturedEdgeShapesTestLayer::onCreate)));
		button->setPosition(DP(80), wyDevice::winHeight - DP(30));
		addChildLocked(button, 1);
		button->release();

		// label for create button
		wyBitmapFont* font = wyBitmapFont::loadFont(RES("R.raw.bitmapfont"));
		wyBitmapFontLabel* label = wyBitmapFontLabel::make(font, "Create Shape");
		label->setColor(wyc3b(255, 255, 0));
		label->setPosition(DP(80), wyDevice::winHeight - DP(30));
		addChildLocked(label, 1);

		// destroy button
		button = new wyButton(normal, pressed, NULL, NULL, NULL, wyTargetSelector::make(this, SEL(wyTexturedEdgeShapesTestLayer::onDestroy)));
		button->setPosition(DP(240), wyDevice::winHeight - DP(30));
		addChildLocked(button, 1);
		button->release();

		// label for destroy button
		label = wyBitmapFontLabel::make(font, "Destroy Shape");
		label->setColor(wyc3b(255, 255, 0));
		label->setPosition(DP(240), wyDevice::winHeight - DP(30));
		addChildLocked(label, 1);

		startUpdateWorld();
	}

	virtual ~wyTexturedEdgeShapesTestLayer() {
	}

	virtual void updateWorld(float delta) {
		wyBox2DTestLayer::updateWorld(delta);

		float32 L = 25.0f;
		b2Vec2 point1(0.0f, 10.0f);
		b2Vec2 d(L * cosf(m_angle), -L * b2Abs(sinf(m_angle)));
		b2Vec2 point2 = point1 + d;

		EdgeShapesCallback callback;

		m_box2d->getWorld()->RayCast(&callback, point1, point2);

		// TODO gles2
		//glPushMatrix();
		//{
		//	m_box2d->transformAncestors();
		//	m_box2d->transform();

		//	b2Draw* dd = m_box2d->getDebugDrawImpl();
		//	if(callback.m_fixture) {
		//		dd->DrawPoint(callback.m_point, 5.0f, b2Color(0.4f, 0.9f, 0.4f));

		//		dd->DrawSegment(point1, callback.m_point, b2Color(0.8f, 0.8f, 0.8f));

		//		b2Vec2 head = callback.m_point + 0.5f * callback.m_normal;
		//		dd->DrawSegment(callback.m_point, head, b2Color(0.9f, 0.9f, 0.4f));
		//	} else {
		//		dd->DrawSegment(point1, point2, b2Color(0.8f, 0.8f, 0.8f));
		//	}
		//}
		//glPopMatrix();

		m_angle += 0.25f * b2_pi / 180.0f;
	}

	void Create(int32 index)
	{
		// get world
		b2World* world = m_box2d->getWorld();

		if (m_bodies[m_bodyIndex] != NULL)
		{
			world->DestroyBody(m_bodies[m_bodyIndex]);
			m_bodies[m_bodyIndex] = NULL;
		}

		b2BodyDef bd;

		float32 x = RandomFloat(-10.0f, 10.0f);
		float32 y = RandomFloat(10.0f, 20.0f);
		bd.position.Set(x, y);
		bd.angle = RandomFloat(-b2_pi, b2_pi);
		bd.type = b2_dynamicBody;

		if (index == 3)
		{
			bd.angularDamping = 0.02f;
		}

		m_bodies[m_bodyIndex] = world->CreateBody(&bd);

		b2Fixture* f = NULL;
		if (index < 3)
		{
			b2FixtureDef fd;
			fd.shape = m_polygons + index;
			fd.friction = 0.3f;
			fd.density = 20.0f;
			f = m_bodies[m_bodyIndex]->CreateFixture(&fd);
		}
		else
		{
			b2FixtureDef fd;
			fd.shape = &m_circle;
			fd.friction = 0.3f;
			fd.density = 20.0f;
			f = m_bodies[m_bodyIndex]->CreateFixture(&fd);
		}

		// bind texture
		wyTexture2D* tex = wyTexture2D::makePNG(RES("R.drawable.blocks"));
		float size = DP(32.0f) / 2;
		// TODO
//		m_box2d->getBox2DRender()->bindTexture(f, tex, wyr(wyMath::randMax(1) * size * 2, wyMath::randMax(1) * size * 2, size * 2, size * 2));

		m_bodyIndex = (m_bodyIndex + 1) % e_maxBodies;
	}

	void DestroyBody()
	{
		for (int32 i = 0; i < e_maxBodies; ++i)
		{
			if (m_bodies[i] != NULL)
			{
				m_box2d->getWorld()->DestroyBody(m_bodies[i]);
				m_bodies[i] = NULL;
				return;
			}
		}
	}

	virtual bool keyDown(wyKeyEvent& event) {
		switch(event.keyCode) {
			case KEYCODE_MENU:
				Create(rand() % 4);
				break;
			case KEYCODE_SEARCH:
				DestroyBody();
				break;
			default:
				return false;
		}

		return true;
	}

	void onCreate(wyTargetSelector* ts) {
		Create(rand() % 4);
	}

	void onDestroy(wyTargetSelector* ts) {
		DestroyBody();
	}
};

//////////////////////////////////////////////////////////////////////////////////

class wyTexturedOneWayTestLayer : public wyBox2DTestLayer, public b2ContactListener {
private:
	enum State
	{
		e_unknown,
		e_above,
		e_below,
	};

	float32 m_radius, m_top, m_bottom;
	State m_state;
	b2Fixture* m_platform;
	b2Fixture* m_character;

public:
	wyTexturedOneWayTestLayer() {
		// get world
		b2World* world = m_box2d->getWorld();
		m_box2d->setDebugDraw(false);

		// set gravity
		world->SetGravity(b2Vec2(0, -10));

		// set contact listener
		world->SetContactListener(this);

		// place box2d to center of bottom edge
		m_box2d->setPosition(wyDevice::winWidth / 2, 0);

		// Ground
		{
			b2BodyDef bd;
			b2Body* ground = world->CreateBody(&bd);

			b2EdgeShape shape;
			shape.Set(b2Vec2(-20.0f, 0.0f), b2Vec2(20.0f, 0.0f));
			ground->CreateFixture(&shape, 0.0f);
		}

		// Platform
		{
			b2BodyDef bd;
			bd.position.Set(0.0f, 10.0f);
			b2Body* body = world->CreateBody(&bd);

			b2PolygonShape shape;
			shape.SetAsBox(3.0f, 0.5f);
			m_platform = body->CreateFixture(&shape, 0.0f);

			m_bottom = 10.0f - 0.5f;
			m_top = 10.0f + 0.5f;

			// bind texture
			wyTexture2D* tex = wyTexture2D::makePNG(RES("R.drawable.bar"));
			// TODO
//			render->bindTexture(m_platform, tex);
		}

		// Actor
		{
			b2BodyDef bd;
			bd.type = b2_dynamicBody;
			bd.position.Set(0.0f, 12.0f);
			b2Body* body = world->CreateBody(&bd);

			float size = DP(32.0f) / 2;
			m_radius = m_box2d->pixel2Meter(size);
			b2CircleShape shape;
			shape.m_radius = m_radius;
			m_character = body->CreateFixture(&shape, 20.0f);

			body->SetLinearVelocity(b2Vec2(0.0f, -50.0f));

			m_state = e_unknown;

			// bind texture
			wyTexture2D* tex = wyTexture2D::makePNG(RES("R.drawable.blocks"));
			// TODO
//			render->bindTexture(m_character, tex, wyr(wyMath::randMax(1) * size * 2, wyMath::randMax(1) * size * 2, size * 2, size * 2));
		}

		// add a hint label
		wyLabel* label = wyLabel::make("try drag ball through platform",
				SP(14));
		label->setPosition(wyDevice::winWidth / 2, wyDevice::winHeight - DP(60));
		addChildLocked(label);

		startUpdateWorld();
	}

	virtual ~wyTexturedOneWayTestLayer() {
	}

	virtual void PreSolve(b2Contact* contact, const b2Manifold* oldManifold) {
		b2Fixture* fixtureA = contact->GetFixtureA();
		b2Fixture* fixtureB = contact->GetFixtureB();

		if(fixtureA != m_platform && fixtureA != m_character) {
			return;
		}

		if(fixtureB != m_platform && fixtureB != m_character) {
			return;
		}

		b2Vec2 position = m_character->GetBody()->GetPosition();

		if(position.y < m_top + m_radius - 3.0f * b2_linearSlop) {
			contact->SetEnabled(false);
		}
	}
};

///////////////////////////////////////////////////////////////////////////////////////

class wyVaryingFrictionTestLayer : public wyBox2DTestLayer {
public:
	wyVaryingFrictionTestLayer() {
		b2World* world = m_box2d->getWorld();

		// set gravity
		world->SetGravity(b2Vec2(0, -10));

		// place box2d to center of bottom edge
		m_box2d->setPosition(wyDevice::winWidth / 2, 0);

		{
			b2BodyDef bd;
			b2Body* ground = world->CreateBody(&bd);

			b2EdgeShape shape;
			shape.Set(b2Vec2(-40.0f, 0.0f), b2Vec2(40.0f, 0.0f));
			ground->CreateFixture(&shape, 0.0f);
		}

		{
			b2PolygonShape shape;
			shape.SetAsBox(13.0f, 0.25f);

			b2BodyDef bd;
			bd.position.Set(-4.0f, 22.0f);
			bd.angle = -0.25f;

			b2Body* ground = world->CreateBody(&bd);
			ground->CreateFixture(&shape, 0.0f);
		}

		{
			b2PolygonShape shape;
			shape.SetAsBox(0.25f, 1.0f);

			b2BodyDef bd;
			bd.position.Set(10.5f, 19.0f);

			b2Body* ground = world->CreateBody(&bd);
			ground->CreateFixture(&shape, 0.0f);
		}

		{
			b2PolygonShape shape;
			shape.SetAsBox(13.0f, 0.25f);

			b2BodyDef bd;
			bd.position.Set(4.0f, 14.0f);
			bd.angle = 0.25f;

			b2Body* ground = world->CreateBody(&bd);
			ground->CreateFixture(&shape, 0.0f);
		}

		{
			b2PolygonShape shape;
			shape.SetAsBox(0.25f, 1.0f);

			b2BodyDef bd;
			bd.position.Set(-10.5f, 11.0f);

			b2Body* ground = world->CreateBody(&bd);
			ground->CreateFixture(&shape, 0.0f);
		}

		{
			b2PolygonShape shape;
			shape.SetAsBox(13.0f, 0.25f);

			b2BodyDef bd;
			bd.position.Set(-4.0f, 6.0f);
			bd.angle = -0.25f;

			b2Body* ground = world->CreateBody(&bd);
			ground->CreateFixture(&shape, 0.0f);
		}

		{
			b2PolygonShape shape;
			shape.SetAsBox(0.5f, 0.5f);

			b2FixtureDef fd;
			fd.shape = &shape;
			fd.density = 25.0f;

			float friction[5] = {0.75f, 0.5f, 0.35f, 0.1f, 0.0f};

			for (int i = 0; i < 5; ++i)
			{
				b2BodyDef bd;
				bd.type = b2_dynamicBody;
				bd.position.Set(-15.0f + 4.0f * i, 28.0f);
				b2Body* body = world->CreateBody(&bd);

				fd.friction = friction[i];
				body->CreateFixture(&fd);
			}
		}

		startUpdateWorld();
	}

	virtual ~wyVaryingFrictionTestLayer() {
	}
};

/////////////////////////////////////////////////////////////////////////////////

class wyVaryingRestitutionTestLayer : public wyBox2DTestLayer {
public:
	wyVaryingRestitutionTestLayer() {
		b2World* world = m_box2d->getWorld();

		// set gravity
		world->SetGravity(b2Vec2(0, -10));

		// place box2d to center of bottom edge
		m_box2d->setPosition(wyDevice::winWidth / 2, 0);

		{
			b2BodyDef bd;
			b2Body* ground = world->CreateBody(&bd);

			b2EdgeShape shape;
			shape.Set(b2Vec2(-40.0f, 0.0f), b2Vec2(40.0f, 0.0f));
			ground->CreateFixture(&shape, 0.0f);
		}

		{
			b2CircleShape shape;
			shape.m_radius = 1.0f;

			b2FixtureDef fd;
			fd.shape = &shape;
			fd.density = 1.0f;

			float32 restitution[7] = {0.0f, 0.1f, 0.3f, 0.5f, 0.75f, 0.9f, 1.0f};

			for (int32 i = 0; i < 7; ++i)
			{
				b2BodyDef bd;
				bd.type = b2_dynamicBody;
				bd.position.Set(-10.0f + 3.0f * i, 20.0f);

				b2Body* body = world->CreateBody(&bd);

				fd.restitution = restitution[i];
				body->CreateFixture(&fd);
			}
		}

		startUpdateWorld();
	}

	virtual ~wyVaryingRestitutionTestLayer() {
	}
};

/////////////////////////////////////////////////////////////////////////////////////

class wyWebTestLayer : public wyBox2DTestLayer, public b2DestructionListener {
private:
	b2Body* m_bodies[4];
	b2Joint* m_joints[8];

public:
	wyWebTestLayer() {
		// get world
		b2World* world = m_box2d->getWorld();

		// set gravity
		world->SetGravity(b2Vec2(0, -10));

		// set self as destruction listener
		world->SetDestructionListener(this);

		// place box2d to center of bottom edge
		m_box2d->setPosition(wyDevice::winWidth / 2, 0);

		b2Body* ground = NULL;
		{
			b2BodyDef bd;
			ground = world->CreateBody(&bd);

			b2EdgeShape shape;
			shape.Set(b2Vec2(-40.0f, 0.0f), b2Vec2(40.0f, 0.0f));
			ground->CreateFixture(&shape, 0.0f);
		}

		{
			b2PolygonShape shape;
			shape.SetAsBox(0.5f, 0.5f);

			b2BodyDef bd;
			bd.type = b2_dynamicBody;

			bd.position.Set(-5.0f, 5.0f);
			m_bodies[0] = world->CreateBody(&bd);
			m_bodies[0]->CreateFixture(&shape, 5.0f);

			bd.position.Set(5.0f, 5.0f);
			m_bodies[1] = world->CreateBody(&bd);
			m_bodies[1]->CreateFixture(&shape, 5.0f);

			bd.position.Set(5.0f, 15.0f);
			m_bodies[2] = world->CreateBody(&bd);
			m_bodies[2]->CreateFixture(&shape, 5.0f);

			bd.position.Set(-5.0f, 15.0f);
			m_bodies[3] = world->CreateBody(&bd);
			m_bodies[3]->CreateFixture(&shape, 5.0f);

			b2DistanceJointDef jd;
			b2Vec2 p1, p2, d;

			jd.frequencyHz = 4.0f;
			jd.dampingRatio = 0.5f;

			jd.bodyA = ground;
			jd.bodyB = m_bodies[0];
			jd.localAnchorA.Set(-10.0f, 0.0f);
			jd.localAnchorB.Set(-0.5f, -0.5f);
			p1 = jd.bodyA->GetWorldPoint(jd.localAnchorA);
			p2 = jd.bodyB->GetWorldPoint(jd.localAnchorB);
			d = p2 - p1;
			jd.length = d.Length();
			m_joints[0] = world->CreateJoint(&jd);

			jd.bodyA = ground;
			jd.bodyB = m_bodies[1];
			jd.localAnchorA.Set(10.0f, 0.0f);
			jd.localAnchorB.Set(0.5f, -0.5f);
			p1 = jd.bodyA->GetWorldPoint(jd.localAnchorA);
			p2 = jd.bodyB->GetWorldPoint(jd.localAnchorB);
			d = p2 - p1;
			jd.length = d.Length();
			m_joints[1] = world->CreateJoint(&jd);

			jd.bodyA = ground;
			jd.bodyB = m_bodies[2];
			jd.localAnchorA.Set(10.0f, 20.0f);
			jd.localAnchorB.Set(0.5f, 0.5f);
			p1 = jd.bodyA->GetWorldPoint(jd.localAnchorA);
			p2 = jd.bodyB->GetWorldPoint(jd.localAnchorB);
			d = p2 - p1;
			jd.length = d.Length();
			m_joints[2] = world->CreateJoint(&jd);

			jd.bodyA = ground;
			jd.bodyB = m_bodies[3];
			jd.localAnchorA.Set(-10.0f, 20.0f);
			jd.localAnchorB.Set(-0.5f, 0.5f);
			p1 = jd.bodyA->GetWorldPoint(jd.localAnchorA);
			p2 = jd.bodyB->GetWorldPoint(jd.localAnchorB);
			d = p2 - p1;
			jd.length = d.Length();
			m_joints[3] = world->CreateJoint(&jd);

			jd.bodyA = m_bodies[0];
			jd.bodyB = m_bodies[1];
			jd.localAnchorA.Set(0.5f, 0.0f);
			jd.localAnchorB.Set(-0.5f, 0.0f);;
			p1 = jd.bodyA->GetWorldPoint(jd.localAnchorA);
			p2 = jd.bodyB->GetWorldPoint(jd.localAnchorB);
			d = p2 - p1;
			jd.length = d.Length();
			m_joints[4] = world->CreateJoint(&jd);

			jd.bodyA = m_bodies[1];
			jd.bodyB = m_bodies[2];
			jd.localAnchorA.Set(0.0f, 0.5f);
			jd.localAnchorB.Set(0.0f, -0.5f);
			p1 = jd.bodyA->GetWorldPoint(jd.localAnchorA);
			p2 = jd.bodyB->GetWorldPoint(jd.localAnchorB);
			d = p2 - p1;
			jd.length = d.Length();
			m_joints[5] = world->CreateJoint(&jd);

			jd.bodyA = m_bodies[2];
			jd.bodyB = m_bodies[3];
			jd.localAnchorA.Set(-0.5f, 0.0f);
			jd.localAnchorB.Set(0.5f, 0.0f);
			p1 = jd.bodyA->GetWorldPoint(jd.localAnchorA);
			p2 = jd.bodyB->GetWorldPoint(jd.localAnchorB);
			d = p2 - p1;
			jd.length = d.Length();
			m_joints[6] = world->CreateJoint(&jd);

			jd.bodyA = m_bodies[3];
			jd.bodyB = m_bodies[0];
			jd.localAnchorA.Set(0.0f, -0.5f);
			jd.localAnchorB.Set(0.0f, 0.5f);
			p1 = jd.bodyA->GetWorldPoint(jd.localAnchorA);
			p2 = jd.bodyB->GetWorldPoint(jd.localAnchorB);
			d = p2 - p1;
			jd.length = d.Length();
			m_joints[7] = world->CreateJoint(&jd);
		}

		setKeyEnabled(true);

		// delete body button
		wyNinePatchSprite* normal = wyNinePatchSprite::make(wyTexture2D::makePNG(RES("R.drawable.btn_normal")), wyr(DP(9), DP(7), DP(22), DP(28)));
		wyNinePatchSprite* pressed = wyNinePatchSprite::make(wyTexture2D::makePNG(RES("R.drawable.btn_pressed")), wyr(DP(9), DP(7), DP(22), DP(28)));
		normal->setContentSize(DP(150), DP(44));
		pressed->setContentSize(DP(150), DP(44));
		wyButton* button = new wyButton(normal, pressed, NULL, NULL, NULL, wyTargetSelector::make(this, SEL(wyWebTestLayer::onDestroyBody)));
		button->setPosition(DP(80), wyDevice::winHeight - DP(30));
		addChildLocked(button, 1);
		button->release();

		// label for delete body button
		wyBitmapFont* font = wyBitmapFont::loadFont(RES("R.raw.bitmapfont"));
		wyBitmapFontLabel* label = wyBitmapFontLabel::make(font, "Delete Body");
		label->setColor(wyc3b(255, 255, 0));
		label->setPosition(DP(80), wyDevice::winHeight - DP(30));
		addChildLocked(label, 1);

		// delete joint button
		button = new wyButton(normal, pressed, NULL, NULL, NULL, wyTargetSelector::make(this, SEL(wyWebTestLayer::onDestroyJoint)));
		button->setPosition(DP(240), wyDevice::winHeight - DP(30));
		addChildLocked(button, 1);
		button->release();

		// label for delete joint button
		label = wyBitmapFontLabel::make(font, "Delete Joint");
		label->setColor(wyc3b(255, 255, 0));
		label->setPosition(DP(240), wyDevice::winHeight - DP(30));
		addChildLocked(label, 1);

		startUpdateWorld();
	}

	virtual ~wyWebTestLayer() {
	}

	void JointDestroyed(b2Joint* joint) {
		for(int32 i = 0; i < 8; ++i) {
			if(m_joints[i] == joint) {
				m_joints[i] = NULL;
				break;
			}
		}
	}

	/// Called when any joint is about to be destroyed due
	/// to the destruction of one of its attached bodies.
	virtual void SayGoodbye(b2Joint* joint) {
		if(m_mouseJoint == joint) {
			m_mouseJoint = NULL;
		} else {
			JointDestroyed(joint);
		}
	}

	/// Called when any fixture is about to be destroyed due
	/// to the destruction of its parent body.
	virtual void SayGoodbye(b2Fixture* fixture) {
	}

	virtual bool keyDown(wyKeyEvent& event) {
		// get world
		b2World* world = m_box2d->getWorld();

		switch(event.keyCode) {
			case KEYCODE_MENU:
				for(int32 i = 0; i < 4; ++i) {
					if(m_bodies[i]) {
						world->DestroyBody(m_bodies[i]);
						m_bodies[i] = NULL;
						break;
					}
				}
				break;
			case KEYCODE_SEARCH:
				for(int32 i = 0; i < 8; ++i) {
					if(m_joints[i]) {
						world->DestroyJoint(m_joints[i]);
						m_joints[i] = NULL;
						break;
					}
				}
				break;
			default:
				return false;
		}

		return true;
	}

	void onDestroyBody(wyTargetSelector* ts) {
		b2World* world = m_box2d->getWorld();
		for(int32 i = 0; i < 4; ++i) {
			if(m_bodies[i]) {
				world->DestroyBody(m_bodies[i]);
				m_bodies[i] = NULL;
				break;
			}
		}
	}

	void onDestroyJoint(wyTargetSelector* ts) {
		b2World* world = m_box2d->getWorld();
		for(int32 i = 0; i < 8; ++i) {
			if(m_joints[i]) {
				world->DestroyJoint(m_joints[i]);
				m_joints[i] = NULL;
				break;
			}
		}
	}
};

////////////////////////////////////////////////////////////////////////////

}

using namespace Box2D;

#if ANDROID
	#define DEMO_ENTRY_IMPL(CLASSNAME) JNIEXPORT void JNICALL Java_com_wiyun_engine_tests_box2d_##CLASSNAME##_nativeStart \
		(JNIEnv *, jobject) { \
			wyLayer* layer = new wy##CLASSNAME##Layer(); \
			runDemo(layer, NULL); \
			wyObjectRelease(layer); \
		}
#elif IOS || MACOSX || WINDOWS
	#define DEMO_ENTRY_IMPL(CLASSNAME) void _box2d_##CLASSNAME##Launcher() { \
			wyLayer* layer = new wy##CLASSNAME##Layer(); \
			runDemo(layer, NULL); \
			wyObjectRelease(layer); \
		}
#endif

DEMO_ENTRY_IMPL(ApplyForceTest);
DEMO_ENTRY_IMPL(BodyAnimationTest);
DEMO_ENTRY_IMPL(BodyTypesTest);
DEMO_ENTRY_IMPL(BounceTest);
DEMO_ENTRY_IMPL(BreakableTest);
DEMO_ENTRY_IMPL(BridgeTest);
DEMO_ENTRY_IMPL(BulletTest);
DEMO_ENTRY_IMPL(BuoyancyTest);
DEMO_ENTRY_IMPL(CantileverTest);
DEMO_ENTRY_IMPL(CarTest);
DEMO_ENTRY_IMPL(ChainTest);
DEMO_ENTRY_IMPL(ChainShapeTest);
DEMO_ENTRY_IMPL(CollisionDetectionTest);
DEMO_ENTRY_IMPL(CollisionFilteringTest);
DEMO_ENTRY_IMPL(CompoundShapesTest);
DEMO_ENTRY_IMPL(ConfinedTest);
DEMO_ENTRY_IMPL(DominosTest);
DEMO_ENTRY_IMPL(EdgeShapesTest);
DEMO_ENTRY_IMPL(GearsTest);
DEMO_ENTRY_IMPL(OneWayTest);
DEMO_ENTRY_IMPL(PulleysTest);
DEMO_ENTRY_IMPL(PyramidTest);
DEMO_ENTRY_IMPL(RopeTest);
DEMO_ENTRY_IMPL(SensorTest);
DEMO_ENTRY_IMPL(ShapeEditingTest);
DEMO_ENTRY_IMPL(SliderCrankTest);
DEMO_ENTRY_IMPL(SphereStackTest);
DEMO_ENTRY_IMPL(TensorDampingTest);
DEMO_ENTRY_IMPL(TexturedBounceTest);
DEMO_ENTRY_IMPL(TexturedEdgeShapesTest);
DEMO_ENTRY_IMPL(TexturedChainShapeTest);
DEMO_ENTRY_IMPL(TexturedOneWayTest);
DEMO_ENTRY_IMPL(VaryingFrictionTest);
DEMO_ENTRY_IMPL(VaryingRestitutionTest);
DEMO_ENTRY_IMPL(WebTest);
DEMO_ENTRY_IMPL(SimpleTest);
DEMO_ENTRY_IMPL(PhysicsEditorTest);
