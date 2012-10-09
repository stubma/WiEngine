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

import com.wiyun.engine.WiEngineTestActivity;
import com.wiyun.engine.chipmunk.Body;
import com.wiyun.engine.chipmunk.Chipmunk;
import com.wiyun.engine.chipmunk.Circle;
import com.wiyun.engine.chipmunk.Poly;
import com.wiyun.engine.chipmunk.Segment;
import com.wiyun.engine.chipmunk.Shape;
import com.wiyun.engine.chipmunk.Space;
import com.wiyun.engine.nodes.Director;
import com.wiyun.engine.nodes.Layer;
import com.wiyun.engine.types.WYPoint;
import com.wiyun.engine.types.WYSize;
import com.wiyun.engine.utils.TargetSelector;

public class PyramidStackTest extends WiEngineTestActivity {
	@Override
	protected Layer createLayer() {
		return new MyLayer();
	}

	class MyLayer extends Layer {
		Space mSpace;

		public MyLayer() {
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
			mSpace.setGravity(0, -100);
			mSpace.resizeActiveHash(40f, 1000);
			mSpace.resizeStaticHash(40f, 1000);

			// add static body
			Body staticBody = Body.make(Float.MAX_VALUE, Float.MAX_VALUE);

			WYPoint[] verts = {
					WYPoint.make(-15, -15), WYPoint.make(-15, 15), WYPoint.make(15, 15), WYPoint.make(15, -15)
			};

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

			shape = Segment.make(staticBody, -s.width / 2, s.height / 2, s.width / 2, s.height / 2, 2);
			shape.setRestitution(1);
			shape.setFriction(1);
			shape.setLayerMask(Chipmunk.NOT_GRABABLE_MASK);
			mSpace.addStaticShape(shape);

			// Add lots of boxes.
			float moment = Chipmunk.calculateMomentForPoly(1f, verts, WYPoint.makeZero());
			for(int i = 0; i < 6; i++) {
				for(int j = 0; j <= i; j++) {
					Body body = Body.make(1f, moment);
					body.setPosition(j * 32 - i * 16, 300 - i * 32);
					mSpace.addBody(body);
					shape = Poly.make(body, verts, WYPoint.makeZero());
					shape.setFriction(0.8f);
					mSpace.addShape(shape);
				}
			}

			// Add a ball to make things more interesting
			float radius = 15.0f;
			moment = Chipmunk.calculateMomentForCircle(10f, 0f, radius, WYPoint.makeZero());
			Body body = Body.make(10f, moment);
			mSpace.addBody(body);
			body.setPosition(0, -240 + radius + 5);
			shape = Circle.make(body, radius);
			mSpace.addShape(shape);
			shape.setFriction(0.9f);

			schedule(new TargetSelector(this, "update(float)", new Object[] { 0f }));
		}

		public void update(float delta) {
			float steps = 3f;
			float dt = delta / steps;
			for(int i = 0; i < steps; i++)
				mSpace.step(dt);
		}
	}
}
