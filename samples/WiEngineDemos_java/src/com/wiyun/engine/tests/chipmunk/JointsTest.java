/*
 * Copyright (c) 2010 WiYun Inc.

 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:

 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.

 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
package com.wiyun.engine.tests.chipmunk;

import static com.wiyun.engine.types.WYPoint.add;
import static java.lang.Math.PI;

import com.wiyun.engine.WiEngineTestActivity;
import com.wiyun.engine.chipmunk.Body;
import com.wiyun.engine.chipmunk.Chipmunk;
import com.wiyun.engine.chipmunk.Circle;
import com.wiyun.engine.chipmunk.Constraint;
import com.wiyun.engine.chipmunk.DampedRotarySpring;
import com.wiyun.engine.chipmunk.DampedSpring;
import com.wiyun.engine.chipmunk.GearJoint;
import com.wiyun.engine.chipmunk.GrooveJoint;
import com.wiyun.engine.chipmunk.PinJoint;
import com.wiyun.engine.chipmunk.PivotJoint;
import com.wiyun.engine.chipmunk.Poly;
import com.wiyun.engine.chipmunk.RatchetJoint;
import com.wiyun.engine.chipmunk.RotaryLimitJoint;
import com.wiyun.engine.chipmunk.Segment;
import com.wiyun.engine.chipmunk.Shape;
import com.wiyun.engine.chipmunk.SimpleMotor;
import com.wiyun.engine.chipmunk.SlideJoint;
import com.wiyun.engine.chipmunk.Space;
import com.wiyun.engine.nodes.Director;
import com.wiyun.engine.nodes.Layer;
import com.wiyun.engine.types.WYPoint;
import com.wiyun.engine.types.WYSize;
import com.wiyun.engine.utils.TargetSelector;

public class JointsTest extends WiEngineTestActivity {
	@Override
	protected Layer createLayer() {
		return new MyLayer();
	}

	class MyLayer extends Layer {
		Space mSpace;

		public MyLayer() {
			WYSize s = Director.getInstance().getWindowSize();
			Chipmunk chipmunk = Chipmunk.make();
			chipmunk.setDebugDraw(true);
			chipmunk.setPosition(s.width / 2, s.height / 2);
			addChild(chipmunk);

			mSpace = chipmunk.getSpace();
			mSpace.setIterations(10);
			mSpace.setGravity(0, -100);

			Body staticBody = Body.make(Float.MAX_VALUE, Float.MAX_VALUE);

			Shape shape = Segment.make(staticBody, WYPoint.make(-s.width / 2, s.height / 2), WYPoint.make(s.width / 2, s.height / 2), 2);
			shape.setRestitution(1f);
			shape.setFriction(1f);
			shape.setLayerMask(Chipmunk.NOT_GRABABLE_MASK);
			mSpace.addStaticShape(shape);

			shape = Segment.make(staticBody, WYPoint.make(-s.width / 2, s.height / 4), WYPoint.make(s.width / 2, s.height / 4), 2);
			shape.setRestitution(1f);
			shape.setFriction(1f);
			shape.setLayerMask(Chipmunk.NOT_GRABABLE_MASK);
			mSpace.addStaticShape(shape);

			shape = Segment.make(staticBody, WYPoint.make(-s.width / 2, 0), WYPoint.make(s.width / 2, 0), 2);
			shape.setRestitution(1f);
			shape.setFriction(1f);
			shape.setLayerMask(Chipmunk.NOT_GRABABLE_MASK);
			mSpace.addStaticShape(shape);

			shape = Segment.make(staticBody, WYPoint.make(-s.width / 2, -s.height / 4), WYPoint.make(s.width / 2, -s.height / 4), 2);
			shape.setRestitution(1f);
			shape.setFriction(1f);
			shape.setLayerMask(Chipmunk.NOT_GRABABLE_MASK);
			mSpace.addStaticShape(shape);

			shape = Segment.make(staticBody, WYPoint.make(-s.width / 2, -s.height / 2), WYPoint.make(s.width / 2, -s.height / 2), 2);
			shape.setRestitution(1f);
			shape.setFriction(1f);
			shape.setLayerMask(Chipmunk.NOT_GRABABLE_MASK);
			mSpace.addStaticShape(shape);

			shape = Segment.make(staticBody, WYPoint.make(-s.width / 2, -s.height / 2), WYPoint.make(-s.width / 2, s.height / 2), 2);
			shape.setRestitution(1f);
			shape.setFriction(1f);
			shape.setLayerMask(Chipmunk.NOT_GRABABLE_MASK);
			mSpace.addStaticShape(shape);

			shape = Segment.make(staticBody, WYPoint.make(-s.width / 4, -s.height / 2), WYPoint.make(-s.width / 4, s.height / 2), 2);
			shape.setRestitution(1f);
			shape.setFriction(1f);
			shape.setLayerMask(Chipmunk.NOT_GRABABLE_MASK);
			mSpace.addStaticShape(shape);

			shape = Segment.make(staticBody, WYPoint.make(0, -s.height / 2), WYPoint.make(0, s.height / 2), 2);
			shape.setRestitution(1f);
			shape.setFriction(1f);
			shape.setLayerMask(Chipmunk.NOT_GRABABLE_MASK);
			mSpace.addStaticShape(shape);

			shape = Segment.make(staticBody, WYPoint.make(s.width / 4, -s.height / 2), WYPoint.make(s.width / 4, s.height / 2), 2);
			shape.setRestitution(1f);
			shape.setFriction(1f);
			shape.setLayerMask(Chipmunk.NOT_GRABABLE_MASK);
			mSpace.addStaticShape(shape);

			shape = Segment.make(staticBody, WYPoint.make(s.width / 2, -s.height / 2), WYPoint.make(s.width / 2, s.height / 2), 2);
			shape.setRestitution(1f);
			shape.setFriction(1f);
			shape.setLayerMask(Chipmunk.NOT_GRABABLE_MASK);
			mSpace.addStaticShape(shape);

			WYPoint posA = WYPoint.make(50, 60);
			WYPoint posB = WYPoint.make(110, 60);

			// Pin Joints - Link shapes with a solid bar or pin.
			// Keeps the anchor points the same distance apart from when the joint was created.
			WYPoint boxOffset = WYPoint.make(-s.width / 2, -s.height / 2);
			Body body1 = addBall(posA, boxOffset);
			Body body2 = addBall(posB, boxOffset);
			Constraint constraint = PinJoint.make(body1, body2, WYPoint.make(15, 0), WYPoint.make(-15, 0));
			mSpace.addConstraint(constraint);

			// Slide Joints - Like pin joints but with a min/max distance.
			// Can be used for a cheap approximation of a rope.
			boxOffset = WYPoint.make(-s.width / 4, -s.height / 2);
			body1 = addBall(posA, boxOffset);
			body2 = addBall(posB, boxOffset);
			constraint = SlideJoint.make(body1, body2, WYPoint.make(15, 0), WYPoint.make(-15, 0), 20, 40);
			mSpace.addConstraint(constraint);

			// Pivot Joints - Holds the two anchor points together. Like a swivel.
			// cpPivotJointNew() takes it's anchor parameter in world coordinates. The anchors are calculated from that
			// cpPivotJointNew2() lets you specify the two anchor points explicitly
			boxOffset = WYPoint.make(0, -s.height / 2);
			body1 = addBall(posA, boxOffset);
			body2 = addBall(posB, boxOffset);
			constraint = PivotJoint.make(body1, body2, add(boxOffset, WYPoint.make(80, 60)));
			mSpace.addConstraint(constraint);

			// Groove Joints - Like a pivot joint, but one of the anchors is a line segment that the pivot can slide in
			boxOffset = WYPoint.make(s.width / 4, -s.height / 2);
			body1 = addBall(posA, boxOffset);
			body2 = addBall(posB, boxOffset);
			constraint = GrooveJoint.make(body1, body2, WYPoint.make(30, 30), WYPoint.make(30, -30), WYPoint.make(-30, 0));
			mSpace.addConstraint(constraint);

			// Damped Springs
			boxOffset = WYPoint.make(-s.width / 2, -s.height / 4);
			body1 = addBall(posA, boxOffset);
			body2 = addBall(posB, boxOffset);
			constraint = DampedSpring.make(body1, body2, WYPoint.make(15, 0), WYPoint.make(-15, 0), 20f, 5f, 0.3f);
			mSpace.addConstraint(constraint);

			// Damped Rotary Springs
			// Add some pin joints to hold the circles in place.
			boxOffset = WYPoint.make(-s.width / 4, -s.height / 4);
			body1 = addBar(posA, boxOffset);
			body2 = addBar(posB, boxOffset);
			constraint = PivotJoint.make(body1, staticBody, add(boxOffset, posA));
			mSpace.addConstraint(constraint);
			constraint = PivotJoint.make(body2, staticBody, add(boxOffset, posB));
			mSpace.addConstraint(constraint);
			constraint = DampedRotarySpring.make(body1, body2, 0f, 3000f, 60f);
			mSpace.addConstraint(constraint);

			// Rotary Limit Joint
			// Add some pin joints to hold the circles in place.
			// Hold their rotation within 90 degrees of each other.
			boxOffset = WYPoint.make(0, -s.height / 4);
			body1 = addLever(posA, boxOffset);
			body2 = addLever(posB, boxOffset);
			constraint = PivotJoint.make(body1, staticBody, add(boxOffset, posA));
			mSpace.addConstraint(constraint);
			constraint = PivotJoint.make(body2, staticBody, add(boxOffset, posB));
			mSpace.addConstraint(constraint);
			constraint = RotaryLimitJoint.make(body1, body2, -(float)PI / 2, -(float)PI / 2);
			mSpace.addConstraint(constraint);
			
			// Ratchet Joint - A rotary ratchet, like a socket wrench
			// Add some pin joints to hold the circles in place.
			// Ratchet every 90 degrees
			boxOffset = WYPoint.make(s.width / 4, -s.height / 4);
			body1 = addLever(posA, boxOffset);
			body2 = addLever(posB, boxOffset);
			constraint = PivotJoint.make(body1, staticBody, add(boxOffset, posA));
			mSpace.addConstraint(constraint);
			constraint = PivotJoint.make(body2, staticBody, add(boxOffset, posB));
			mSpace.addConstraint(constraint);
			constraint = RatchetJoint.make(body1, body2, 0f, (float)PI / 2);
			mSpace.addConstraint(constraint);
			
			// Gear Joint - Maintain a specific angular velocity ratio
			// Add some pin joints to hold the circles in place.
			// Force one to sping 2x as fast as the other
			boxOffset = WYPoint.make(-s.width / 2, 0);
			body1 = addBar(posA, boxOffset);
			body2 = addBar(posB, boxOffset);
			constraint = PivotJoint.make(body1, staticBody, add(boxOffset, posA));
			mSpace.addConstraint(constraint);
			constraint = PivotJoint.make(body2, staticBody, add(boxOffset, posB));
			mSpace.addConstraint(constraint);
			constraint = GearJoint.make(body1, body2, 0f, 2f);
			
			// Simple Motor - Maintain a specific angular relative velocity
			// Add some pin joints to hold the circles in place.
			// Make them spin at 1/2 revolution per second in relation to each other.
			boxOffset = WYPoint.make(-s.width / 4, 0);
			body1 = addBar(posA, boxOffset);
			body2 = addBar(posB, boxOffset);
			constraint = PivotJoint.make(body1, staticBody, add(boxOffset, posA));
			mSpace.addConstraint(constraint);
			constraint = PivotJoint.make(body2, staticBody, add(boxOffset, posB));
			mSpace.addConstraint(constraint);
			constraint = SimpleMotor.make(body1, body2, (float)PI);
			mSpace.addConstraint(constraint);
			
			// Make a car with some nice soft suspension
			boxOffset = WYPoint.make(0, 0);
			Body wheel1 = addWheel(posA, boxOffset);
			Body wheel2 = addWheel(posB, boxOffset);
			Body chassis = addChassis(WYPoint.make(80, 100), boxOffset);
			constraint = GrooveJoint.make(chassis, wheel1, WYPoint.make(-30, 10), WYPoint.make(-30, -40), WYPoint.makeZero());
			mSpace.addConstraint(constraint);
			constraint = GrooveJoint.make(chassis, wheel2, WYPoint.make(30, -10), WYPoint.make(30, -40), WYPoint.makeZero());
			mSpace.addConstraint(constraint);
			constraint = DampedSpring.make(chassis, wheel1, WYPoint.make(-30, 0), WYPoint.makeZero(), 50f, 20f, 1.5f);
			mSpace.addConstraint(constraint);
			constraint = DampedSpring.make(chassis, wheel1, WYPoint.make(30, 0), WYPoint.makeZero(), 50f, 20f, 1.5f);
			mSpace.addConstraint(constraint);
			
			schedule(new TargetSelector(this, "update(float)", new Object[] { 0f }));
		}

		private Body addBall(WYPoint pos, WYPoint boxOffset) {
			float radius = 15.0f;
			float mass = 1.0f;
			float moment = Chipmunk.calculateMomentForCircle(mass, 0f, radius, WYPoint.makeZero());
			Body body = Body.make(mass, moment);
			body.setPosition(add(pos, boxOffset));
			mSpace.addBody(body);

			Shape shape = Circle.make(body, radius);
			shape.setFriction(0.7f);
			mSpace.addShape(shape);
			return body;
		}

		private Body addLever(WYPoint pos, WYPoint boxOffset) {
			float mass = 1.0f;
			WYPoint a = WYPoint.make(0, 15);
			WYPoint b = WYPoint.make(0, -15);

			float moment = Chipmunk.calculateMomentForSegment(mass, a, b);
			Body body = Body.make(mass, moment);
			body.setPosition(add(pos, add(boxOffset, b)));
			mSpace.addBody(body);

			Shape shape = Segment.make(body, a, b, 5f);
			shape.setFriction(0.7f);
			mSpace.addShape(shape);

			return body;
		}

		private Body addBar(WYPoint pos, WYPoint boxOffset) {
			float mass = 2.0f;
			WYPoint a = WYPoint.make(0, 30);
			WYPoint b = WYPoint.make(0, -30);

			float moment = Chipmunk.calculateMomentForSegment(mass, a, b);
			Body body = Body.make(mass, moment);
			body.setPosition(add(pos, boxOffset));
			mSpace.addBody(body);

			Shape shape = Segment.make(body, a, b, 5f);
			shape.setFriction(0.7f);
			mSpace.addShape(shape);

			return body;
		}

		private Body addWheel(WYPoint pos, WYPoint boxOffset) {
			float radius = 15.0f;
			float mass = 1.0f;
			float moment = Chipmunk.calculateMomentForCircle(mass, 0f, radius, WYPoint.makeZero());
			Body body = Body.make(mass, moment);
			body.setPosition(add(pos, boxOffset));
			mSpace.addBody(body);

			// use a group to keep the car parts from colliding
			Shape shape = Circle.make(body, radius);
			shape.setFriction(0.7f);
			shape.setGroup(1);
			mSpace.addShape(shape);

			return body;
		}

		private Body addChassis(WYPoint pos, WYPoint boxOffset) {
			WYPoint[] verts = {
					WYPoint.make(-40, -15), WYPoint.make(-40, 15), WYPoint.make(40, 15), WYPoint.make(40, -15),
			};

			float mass = 5.0f;
			float moment = Chipmunk.calculateMomentForPoly(mass, verts, WYPoint.makeZero());
			Body body = Body.make(mass, moment);
			body.setPosition(add(pos, boxOffset));
			mSpace.addBody(body);

			Shape shape = Poly.make(body, verts, WYPoint.makeZero());
			shape.setFriction(0.7f);
			shape.setGroup(1);
			mSpace.addShape(shape);

			return body;
		}

		public void update(float delta) {
			mSpace.step(delta);
		}
	}
}
