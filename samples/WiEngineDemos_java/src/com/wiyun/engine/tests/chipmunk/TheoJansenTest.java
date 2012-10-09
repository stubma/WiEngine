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

import static com.wiyun.engine.types.WYPoint.makeByRadian;
import static com.wiyun.engine.types.WYPoint.mul;
import static java.lang.Math.PI;
import static java.lang.Math.sqrt;
import android.view.KeyEvent;

import com.wiyun.engine.WiEngineTestActivity;
import com.wiyun.engine.chipmunk.Body;
import com.wiyun.engine.chipmunk.Chipmunk;
import com.wiyun.engine.chipmunk.Circle;
import com.wiyun.engine.chipmunk.GearJoint;
import com.wiyun.engine.chipmunk.PinJoint;
import com.wiyun.engine.chipmunk.PivotJoint;
import com.wiyun.engine.chipmunk.Segment;
import com.wiyun.engine.chipmunk.Shape;
import com.wiyun.engine.chipmunk.SimpleMotor;
import com.wiyun.engine.chipmunk.Space;
import com.wiyun.engine.nodes.Director;
import com.wiyun.engine.nodes.Layer;
import com.wiyun.engine.types.WYPoint;
import com.wiyun.engine.types.WYSize;
import com.wiyun.engine.utils.TargetSelector;

public class TheoJansenTest extends WiEngineTestActivity {
	@Override
	protected Layer createLayer() {
		return new MyLayer();
	}

	static float sSegRadius = 3.0f;
	
	class MyLayer extends Layer {
		Space mSpace;
		SimpleMotor mMotor;
		WYPoint mArrowDirection = WYPoint.makeZero();

		public MyLayer() {
			WYSize s = Director.getInstance().getWindowSize();
			Chipmunk chipmunk = Chipmunk.make();
			chipmunk.setDebugDraw(true);
			chipmunk.setPosition(s.width / 2, s.height / 2);
			addChild(chipmunk);

			Shape.resetShapeIdCounter();

			mSpace = chipmunk.getSpace();
			mSpace.setIterations(20);
			mSpace.setGravity(0, -500);

			Body staticBody = Body.make(Float.MAX_VALUE, Float.MAX_VALUE);

			// Create segments around the edge of the screen.
			Shape shape = Segment.make(staticBody, -s.width / 2, -s.height / 2, -s.width / 2, s.height / 2, 2);
			shape.setRestitution(1);
			shape.setFriction(1);
			shape.setLayerMask(Chipmunk.NOT_GRABABLE_MASK);
			mSpace.addStaticShape(shape);

			shape = Segment.make(staticBody, s.width / 2, -s.height / 2, s.width / 2, s.height / 2, 2);
			shape.setRestitution(1);
			shape.setFriction(1);
			shape.setLayerMask(Chipmunk.NOT_GRABABLE_MASK);
			mSpace.addStaticShape(shape);

			shape = Segment.make(staticBody, -s.width / 2, -s.height / 2, s.width / 2, -s.height / 2, 2);
			shape.setRestitution(1);
			shape.setFriction(1);
			shape.setLayerMask(Chipmunk.NOT_GRABABLE_MASK);
			mSpace.addStaticShape(shape);

			float offset = 30.0f;

			// make chassis
			float chassis_mass = 2.0f;
			WYPoint a = WYPoint.make(-offset, 0.0f), b = WYPoint.make(offset, 0.0f);
			Body chassis = Body.make(chassis_mass, Chipmunk.calculateMomentForSegment(chassis_mass, a, b));
			mSpace.addBody(chassis);
			shape = Segment.make(chassis, a, b, sSegRadius);
			shape.setGroup(1);
			mSpace.addShape(shape);

			// make crank
			float crank_mass = 1.0f;
			float crank_radius = 13.0f;
			Body crank = Body.make(crank_mass, Chipmunk.calculateMomentForCircle(crank_mass, crank_radius, 0.0f, WYPoint.makeZero()));
			mSpace.addBody(crank);
			shape = Circle.make(crank, crank_radius, 0, 0);
			shape.setGroup(1);
			mSpace.addShape(shape);
			mSpace.addConstraint(PivotJoint.make(chassis, crank, WYPoint.makeZero(), WYPoint.makeZero()));

			float side = 30.0f;
			int numOfLegs = 2;
			for(int i = 0; i < numOfLegs; i++) {
				makeLeg(side, offset, chassis, crank, mul(makeByRadian((2 * i + 0) / numOfLegs * (float)PI), crank_radius));
				makeLeg(side, -offset, chassis, crank, mul(makeByRadian((2 * i + 1) / numOfLegs * (float)PI), crank_radius));
			}

			mMotor = SimpleMotor.make(chassis, crank, 6.0f);
			mSpace.addConstraint(mMotor);

			schedule(new TargetSelector(this, "update(float)", new Object[] { 0f }));
			setKeyEnabled(true);
		}

		private void makeLeg(float side, float offset, Body chassis, Body crank, WYPoint anchor) {
			float legMass = 1.0f;

			// make leg
			WYPoint a = WYPoint.makeZero(), b = WYPoint.make(0.0f, side);
			Body upperLeg = Body.make(legMass, Chipmunk.calculateMomentForSegment(legMass, a, b));
			upperLeg.setPosition(offset, 0.0f);
			mSpace.addBody(upperLeg);
			mSpace.addShape(Segment.make(upperLeg, a, b, sSegRadius));
			mSpace.addConstraint(PivotJoint.make(chassis, upperLeg, WYPoint.make(offset, 0.0f), WYPoint.makeZero()));

			// lower leg
			a = WYPoint.makeZero();
			b = WYPoint.make(0.0f, -1.0f * side);
			Body lowerLeg = Body.make(legMass, Chipmunk.calculateMomentForSegment(legMass, a, b));
			lowerLeg.setPosition(offset, -side);
			mSpace.addBody(lowerLeg);
			Shape shape = Segment.make(lowerLeg, a, b, sSegRadius);
			shape.setGroup(1);
			mSpace.addShape(shape);
			shape = Circle.make(lowerLeg, sSegRadius * 2.0f, b.x, b.y);
			shape.setGroup(1);
			shape.setFriction(1f);
			mSpace.addShape(shape);
			mSpace.addConstraint(PinJoint.make(chassis, lowerLeg, WYPoint.make(offset, 0.0f), WYPoint.makeZero()));

			mSpace.addConstraint(GearJoint.make(upperLeg, lowerLeg, 0.0f, 1.0f));

			float diag = (float)sqrt(side * side + offset * offset);

			PinJoint pj = PinJoint.make(crank, upperLeg, anchor, WYPoint.make(0.0f, side));
			pj.setDistance(diag);
			mSpace.addConstraint(pj);
			pj = PinJoint.make(crank, lowerLeg, anchor, WYPoint.makeZero());
			pj.setDistance(diag);
			mSpace.addConstraint(pj);
		}

		public void update(float delta) {
			float coef = (2.0f + mArrowDirection.y) / 3.0f;
			float rate = mArrowDirection.x * 10.0f * coef;
			mMotor.setRate(rate);
			mMotor.setMaxForce(rate != 0 ? 100000f : 0f);

			int steps = 3;
			float dt = delta / steps;

			for(int i = 0; i < steps; i++) {
				mSpace.step(dt);
			}
		}

		@Override
		public boolean wyKeyDown(KeyEvent event) {
			mArrowDirection.x = 0;
			mArrowDirection.y = 0;
			switch(event.getKeyCode()) {
				case KeyEvent.KEYCODE_DPAD_UP:
					mArrowDirection.y++;
					break;
				case KeyEvent.KEYCODE_DPAD_DOWN:
					mArrowDirection.y--;
					break;
				case KeyEvent.KEYCODE_DPAD_RIGHT:
					mArrowDirection.x++;
					break;
				case KeyEvent.KEYCODE_DPAD_LEFT:
					mArrowDirection.x--;
					break;
				default:
					return false;
			}

			return true;
		}
	}
}
