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

import static com.wiyun.engine.types.WYPoint.mul;
import static java.lang.Math.max;

import java.util.Random;

import android.util.Log;
import android.view.KeyEvent;

import com.wiyun.engine.WiEngine;
import com.wiyun.engine.WiEngineTestActivity;
import com.wiyun.engine.chipmunk.Body;
import com.wiyun.engine.chipmunk.Chipmunk;
import com.wiyun.engine.chipmunk.Circle;
import com.wiyun.engine.chipmunk.Segment;
import com.wiyun.engine.chipmunk.Shape;
import com.wiyun.engine.chipmunk.Space;
import com.wiyun.engine.nodes.Director;
import com.wiyun.engine.nodes.Layer;
import com.wiyun.engine.types.WYPoint;
import com.wiyun.engine.types.WYSize;
import com.wiyun.engine.utils.TargetSelector;

public class UnsafeOpsTest extends WiEngineTestActivity {
	@Override
	protected Layer createLayer() {
		return new MyLayer();
	}

	class MyLayer extends Layer {
		Space mSpace;
		WYPoint mArrowDirection = WYPoint.makeZero();
		Random mRandom;

		Circle[] mCircles = new Circle[30];
		float mCircleRadius = 30f;

		public MyLayer() {
			WYSize s = Director.getInstance().getWindowSize();
			Chipmunk chipmunk = Chipmunk.make();
			chipmunk.setDebugDraw(true);
			chipmunk.setPosition(s.width / 2, s.height / 2);
			addChild(chipmunk);

			mRandom = new Random();

			Shape.resetShapeIdCounter();

			mSpace = chipmunk.getSpace();
			mSpace.setIterations(5);
			mSpace.setGravity(0, -100);
			mSpace.resizeActiveHash(30f, 2999);
			mSpace.resizeStaticHash(40f, 999);

			Body staticBody = Body.make(Float.MAX_VALUE, Float.MAX_VALUE);

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

			for(int i = 0; i < mCircles.length; i++) {
				Body body = Body.make(1f, Chipmunk.calculateMomentForCircle(1.0f, 0.0f, mCircleRadius, WYPoint.makeZero()));
				body.setPosition(mul(WYPoint.make(frand() * 2.0f - 1.0f, frand() * 2.0f - 1.0f), mCircleRadius * 5.0f));
				mSpace.addBody(body);

				mCircles[i] = Circle.make(body, mCircleRadius);
				mCircles[i].setFriction(1f);
				mSpace.addShape(mCircles[i]);
			}

			Log.w(WiEngine.LOG, "chipmunk_unsafe.h Contains functions for changing shapes, but they can cause severe stability problems if used incorrectly.\n"
					+ "Shape changes occur as instantaneous changes to position without an accompanying velocity change. USE WITH CAUTION!");

			schedule(new TargetSelector(this, "update(float)", new Object[] { 0f }));
			setKeyEnabled(true);
		}

		public void update(float delta) {
			if(mArrowDirection.y != 0) {
				mCircleRadius = max(10.0f, mCircleRadius + mArrowDirection.y);

				for(int i = 0; i < mCircles.length; i++) {
					mCircles[i].getBody().setMass(Chipmunk.calculateMomentForCircle(1.0f, 0.0f, mCircleRadius, WYPoint.makeZero()));
					mCircles[i].setRadius(mCircleRadius);
				}
			}

			mSpace.step(delta);
		}

		private float frand() {
			return mRandom.nextFloat();
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
