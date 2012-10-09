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

import static java.lang.Math.PI;
import android.view.KeyEvent;

import com.wiyun.engine.WiEngineTestActivity;
import com.wiyun.engine.chipmunk.Body;
import com.wiyun.engine.chipmunk.Chipmunk;
import com.wiyun.engine.chipmunk.Circle;
import com.wiyun.engine.chipmunk.Constraint;
import com.wiyun.engine.chipmunk.GearJoint;
import com.wiyun.engine.chipmunk.PinJoint;
import com.wiyun.engine.chipmunk.PivotJoint;
import com.wiyun.engine.chipmunk.Poly;
import com.wiyun.engine.chipmunk.Segment;
import com.wiyun.engine.chipmunk.Shape;
import com.wiyun.engine.chipmunk.SimpleMotor;
import com.wiyun.engine.chipmunk.Space;
import com.wiyun.engine.nodes.Director;
import com.wiyun.engine.nodes.Layer;
import com.wiyun.engine.types.WYPoint;
import com.wiyun.engine.types.WYSize;
import com.wiyun.engine.utils.TargetSelector;

public class PumpTest extends WiEngineTestActivity {
	@Override
	protected Layer createLayer() {
		return new MyLayer();
	}

	class MyLayer extends Layer {
		Space mSpace;
		SimpleMotor mMotor;

		WYPoint mArrowDirection = WYPoint.makeZero();
		private Body[] mBalls = new Body[3];

		public MyLayer() {
			setKeyEnabled(true);

			WYSize s = Director.getInstance().getWindowSize();
			Chipmunk chipmunk = Chipmunk.make();
			chipmunk.setDebugDraw(true);
			chipmunk.setPosition(s.width / 2, s.height / 2);
			addChild(chipmunk);

			mSpace = chipmunk.getSpace();
			mSpace.setGravity(0, -600);

			Body staticBody = Body.make(Float.MAX_VALUE, Float.MAX_VALUE);

			// beveling all of the line segments helps prevent things from getting stuck on cracks
			Shape shape = Segment.make(staticBody, WYPoint.make(-230, 16), WYPoint.make(-230, 240), 2f);
			shape.setFriction(0.5f);
			shape.setLayerMask(Chipmunk.NOT_GRABABLE_MASK);
			mSpace.addStaticShape(shape);

			shape = Segment.make(staticBody, WYPoint.make(-230, 16), WYPoint.make(-166, 0), 2f);
			shape.setFriction(0.5f);
			shape.setLayerMask(Chipmunk.NOT_GRABABLE_MASK);
			mSpace.addStaticShape(shape);

			shape = Segment.make(staticBody, WYPoint.make(-166, 0), WYPoint.make(-166, -64), 2f);
			shape.setFriction(0.5f);
			shape.setLayerMask(Chipmunk.NOT_GRABABLE_MASK);
			mSpace.addStaticShape(shape);

			shape = Segment.make(staticBody, WYPoint.make(-102, -64), WYPoint.make(-102, 144), 2f);
			shape.setFriction(0.5f);
			shape.setLayerMask(Chipmunk.NOT_GRABABLE_MASK);
			mSpace.addStaticShape(shape);

			shape = Segment.make(staticBody, WYPoint.make(-166, 80), WYPoint.make(-166, 176), 2f);
			shape.setFriction(0.5f);
			shape.setLayerMask(Chipmunk.NOT_GRABABLE_MASK);
			mSpace.addStaticShape(shape);

			shape = Segment.make(staticBody, WYPoint.make(-166, 176), WYPoint.make(-102, 240), 2f);
			shape.setFriction(0.5f);
			shape.setLayerMask(Chipmunk.NOT_GRABABLE_MASK);
			mSpace.addStaticShape(shape);

			shape = Segment.make(staticBody, WYPoint.make(-102, 144), WYPoint.make(218, 64), 2f);
			shape.setFriction(0.5f);
			shape.setLayerMask(Chipmunk.NOT_GRABABLE_MASK);
			mSpace.addStaticShape(shape);

			WYPoint[] verts = {
					WYPoint.make(-30, -80), WYPoint.make(-30, 80), WYPoint.make(30, 64), WYPoint.make(30, -80),
			};

			Body plunger = Body.make(1f, Float.MAX_VALUE);
			plunger.setPosition(-134, -80);
			mSpace.addBody(plunger);

			shape = Poly.make(plunger, verts, WYPoint.makeZero());
			shape.setRestitution(1f);
			shape.setFriction(0.5f);
			shape.setLayerMask(1);
			mSpace.addShape(shape);

			// add balls to hopper
			for(int i = 0; i < mBalls.length; i++)
				mBalls[i] = addBall(WYPoint.make(-198, 80 + 64 * i));

			// add small gear
			float moment = Chipmunk.calculateMomentForCircle(10f, 80, 0, WYPoint.makeZero());
			Body smallGear = Body.make(10f, moment);
			smallGear.setPosition(-134, -160);
			smallGear.setAngle((float)-PI / 2);
			mSpace.addBody(smallGear);

			shape = Circle.make(smallGear, 80);
			shape.setLayerMask(0);
			mSpace.addShape(shape);

			Constraint constraint = PivotJoint.make(staticBody, smallGear, WYPoint.make(-134, -160), WYPoint.makeZero());
			mSpace.addConstraint(constraint);

			// add big gear
			moment = Chipmunk.calculateMomentForCircle(40f, 160, 0, WYPoint.makeZero());
			Body bigGear = Body.make(40f, moment);
			bigGear.setPosition(106, -160);
			bigGear.setAngle((float)PI / 2);
			mSpace.addBody(bigGear);

			shape = Circle.make(bigGear, 160);
			shape.setLayerMask(0);
			mSpace.addShape(shape);

			constraint = PivotJoint.make(staticBody, bigGear, WYPoint.make(106, -160), WYPoint.makeZero());
			mSpace.addConstraint(constraint);

			// connect the plunger to the small gear.
			constraint = PinJoint.make(smallGear, plunger, WYPoint.make(106, 0), WYPoint.makeZero());
			mSpace.addConstraint(constraint);

			// connect the gears.
			constraint = GearJoint.make(smallGear, bigGear, (float)-PI / 2, -2f);
			mSpace.addConstraint(constraint);

			// feeder mechanism
			float bottom = -300.0f;
			float top = 32.0f;
			moment = Chipmunk.calculateMomentForSegment(1f, WYPoint.make(-198, bottom), WYPoint.make(-198, top));
			Body feeder = Body.make(1f, moment);
			feeder.setPosition(-198, (bottom + top) / 2f);
			mSpace.addBody(feeder);

			float len = top - bottom;
			shape = Segment.make(feeder, WYPoint.make(0, len / 2), WYPoint.make(0, -len / 2), 20f);
			mSpace.addShape(shape);

			constraint = PivotJoint.make(staticBody, feeder, WYPoint.make(-198, bottom), WYPoint.make(0f, -len / 2));
			mSpace.addConstraint(constraint);
			WYPoint anchr = feeder.convertWorldToLocal(WYPoint.make(-198, -160));
			constraint = PinJoint.make(feeder, smallGear, anchr, WYPoint.make(26, 80));
			mSpace.addConstraint(constraint);

			// motorize the second gear
			mMotor = SimpleMotor.make(staticBody, bigGear, 3f);
			mSpace.addConstraint(mMotor);

			schedule(new TargetSelector(this, "update(float)", new Object[] { 0f }));
		}

		private Body addBall(WYPoint p) {
			float moment = Chipmunk.calculateMomentForCircle(1f, 30, 0, WYPoint.makeZero());
			Body body = Body.make(1f, moment);
			body.setPosition(p);
			mSpace.addBody(body);

			Shape shape = Circle.make(body, 30);
			shape.setFriction(0.5f);
			mSpace.addShape(shape);
			return body;
		}

		public void update(float delta) {
			float coef = (2.0f + mArrowDirection.y) / 3.0f;
			float rate = mArrowDirection.x * 30.0f * coef;
			mMotor.setRate(rate);
			mMotor.setMaxForce(rate != 0f ? 1000000f : 0f);

			int steps = 2;
			float dt = delta / steps;

			for(int j = 0; j < steps; j++) {
				mSpace.step(dt);

				for(int i = 0; i < mBalls.length; i++) {
					if(mBalls[i].getPositionX() > 240.0f) {
						mBalls[i].setVelocity(0, 0);
						mBalls[i].setPosition(WYPoint.make(-198, 200));
					}
				}
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
