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

import static com.wiyun.engine.types.WYPoint.dot;
import static com.wiyun.engine.types.WYPoint.length;
import static com.wiyun.engine.types.WYPoint.near;
import static com.wiyun.engine.types.WYPoint.rotate;
import static com.wiyun.engine.types.WYPoint.sub;
import static com.wiyun.engine.types.WYPoint.toRadian;
import static com.wiyun.engine.types.WYPoint.unrotate;

import java.util.Random;

import android.view.MotionEvent;

import com.wiyun.engine.WiEngineTestActivity;
import com.wiyun.engine.chipmunk.Body;
import com.wiyun.engine.chipmunk.Chipmunk;
import com.wiyun.engine.chipmunk.Constraint;
import com.wiyun.engine.chipmunk.GearJoint;
import com.wiyun.engine.chipmunk.PivotJoint;
import com.wiyun.engine.chipmunk.Poly;
import com.wiyun.engine.chipmunk.Segment;
import com.wiyun.engine.chipmunk.Shape;
import com.wiyun.engine.chipmunk.Space;
import com.wiyun.engine.nodes.Director;
import com.wiyun.engine.nodes.Layer;
import com.wiyun.engine.types.WYPoint;
import com.wiyun.engine.types.WYSize;
import com.wiyun.engine.utils.TargetSelector;

public class TankTest extends WiEngineTestActivity {
	@Override
	protected Layer createLayer() {
		return new MyLayer();
	}

	class MyLayer extends Layer {
		Space mSpace;
		Body tankBody, tankControlBody;
		WYPoint mousePoint;

		Random mRandom;

		public MyLayer() {
			setTouchEnabled(true);
			mRandom = new Random();
			mousePoint = WYPoint.makeZero();

			// create and add chipmunk
			WYSize s = Director.getInstance().getWindowSize();
			Chipmunk chipmunk = Chipmunk.make();
			chipmunk.setDebugDraw(true);
			chipmunk.setPosition(s.width / 2, s.height / 2);
			addChild(chipmunk);

			Shape.resetShapeIdCounter();

			// create space
			mSpace = chipmunk.getSpace();
			mSpace.setIterations(10);
			mSpace.resizeActiveHash(30f, 1000);

			// add static body
			Body staticBody = Body.make(Float.MAX_VALUE, Float.MAX_VALUE);

			// Create segments around the edge of the screen.
			Segment shape = Segment.make(staticBody, -s.width / 2, -s.height / 2, -s.width / 2, s.height / 2, 2);
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

			shape = Segment.make(staticBody, -s.width / 2, s.height / 2, s.width / 2, s.height / 2, 2);
			shape.setRestitution(1);
			shape.setFriction(1);
			shape.setLayerMask(Chipmunk.NOT_GRABABLE_MASK);
			mSpace.addStaticShape(shape);

			for(int i = 0; i < 50; i++) {
				Body body = addBox(10.0f, 1.0f);

				Constraint constraint = PivotJoint.make(staticBody, body, WYPoint.makeZero(), WYPoint.makeZero());
				constraint.setBias(0f);
				constraint.setMaxForce(1000f);
				mSpace.addConstraint(constraint);

				constraint = GearJoint.make(staticBody, body, 0f, 1f);
				constraint.setBias(0f);
				constraint.setMaxForce(5000f);
				mSpace.addConstraint(constraint);
			}

			// We joint the tank to the control body and control the tank indirectly by modifying the control body.
			tankControlBody = Body.make(Float.MAX_VALUE, Float.MAX_VALUE);
			tankBody = addBox(15.0f, 10.0f);

			Constraint constraint = PivotJoint.make(tankControlBody, tankBody, WYPoint.makeZero(), WYPoint.makeZero());
			constraint.setBias(0f);
			constraint.setMaxForce(10000f);
			mSpace.addConstraint(constraint);

			constraint = GearJoint.make(tankControlBody, tankBody, 0f, 1f);
			constraint.setBias(1f);
			constraint.setMaxBias(1f);
			constraint.setMaxForce(500000f);
			mSpace.addConstraint(constraint);

			schedule(new TargetSelector(this, "update(float)", new Object[] { 0f }));
		}

		private float frand() {
			return mRandom.nextFloat();
		}

		public void update(float delta) {
			// turn the control body based on the angle relative to the actual body
			WYPoint mouseDelta = sub(mousePoint, tankBody.getPosition());
			float turn = toRadian(unrotate(tankBody.getAngleUnitVector(), mouseDelta));
			tankControlBody.setAngle(tankBody.getAngle() - turn);

			// drive the tank towards the mouse
			if(near(mousePoint, tankBody.getPosition(), 30.0f)) {
				// stop
				tankControlBody.setVelocity(0, 0);
			} else {
				float direction = (dot(mouseDelta, tankBody.getAngleUnitVector()) > 0.0f ? 1.0f : -1.0f);
				tankControlBody.setVelocity(rotate(tankBody.getAngleUnitVector(), WYPoint.make(30.0f * direction, 0.0f)));
			}

			mSpace.step(delta);
		}

		private Body addBox(float size, float mass) {
			WYPoint[] verts = {
					WYPoint.make(-size, -size), WYPoint.make(-size, size), WYPoint.make(size, size), WYPoint.make(size, -size)
			};

			WYSize s = Director.getInstance().getWindowSize();
			float radius = length(WYPoint.make(size, size));

			Body body = Body.make(mass, Chipmunk.calculateMomentForPoly(mass, verts, WYPoint.makeZero()));
			body.setPosition(frand() * (s.width - 2 * radius) - (s.width / 2 - radius), frand() * (s.height - 2 * radius) - (s.height / 2 - radius));
			mSpace.addBody(body);

			Shape shape = Poly.make(body, verts, WYPoint.makeZero());
			shape.setFriction(0.7f);
			mSpace.addShape(shape);

			return body;
		}

		@Override
		public boolean wyTouchesBegan(MotionEvent event) {
			mousePoint = Director.getInstance().convertToGL(event.getX(), event.getY());
			WYSize s = Director.getInstance().getWindowSize();
			mousePoint = sub(mousePoint, WYPoint.make(s.width / 2, s.height / 2));
			return super.wyTouchesBegan(event);
		}

		@Override
		public boolean wyTouchesMoved(MotionEvent event) {
			mousePoint = Director.getInstance().convertToGL(event.getX(), event.getY());
			WYSize s = Director.getInstance().getWindowSize();
			mousePoint = sub(mousePoint, WYPoint.make(s.width / 2, s.height / 2));
			return super.wyTouchesMoved(event);
		}

		@Override
		public boolean wyTouchesEnded(MotionEvent event) {
			mousePoint = Director.getInstance().convertToGL(event.getX(), event.getY());
			WYSize s = Director.getInstance().getWindowSize();
			mousePoint = sub(mousePoint, WYPoint.make(s.width / 2, s.height / 2));
			return super.wyTouchesEnded(event);
		}

		@Override
		public boolean wyTouchesCancelled(MotionEvent event) {
			mousePoint = Director.getInstance().convertToGL(event.getX(), event.getY());
			WYSize s = Director.getInstance().getWindowSize();
			mousePoint = sub(mousePoint, WYPoint.make(s.width / 2, s.height / 2));
			return super.wyTouchesCancelled(event);
		}
	}
}
