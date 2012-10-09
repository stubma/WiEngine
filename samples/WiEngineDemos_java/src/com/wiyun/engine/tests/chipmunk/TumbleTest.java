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
import com.wiyun.engine.chipmunk.Poly;
import com.wiyun.engine.chipmunk.Segment;
import com.wiyun.engine.chipmunk.Shape;
import com.wiyun.engine.chipmunk.Space;
import com.wiyun.engine.nodes.Director;
import com.wiyun.engine.nodes.Layer;
import com.wiyun.engine.types.WYPoint;
import com.wiyun.engine.types.WYSize;
import com.wiyun.engine.utils.TargetSelector;

public class TumbleTest extends WiEngineTestActivity {
	@Override
	protected Layer createLayer() {
		return new MyLayer();
	}

	class MyLayer extends Layer {
		Space mSpace;
		Body staticBody;

		public MyLayer() {
			WYSize s = Director.getInstance().getWindowSize();
			Chipmunk chipmunk = Chipmunk.make();
			chipmunk.setDebugDraw(true);
			chipmunk.setPosition(s.width / 2, s.height / 2);
			addChild(chipmunk);

			Shape.resetShapeIdCounter();

			mSpace = chipmunk.getSpace();
			mSpace.resizeActiveHash(40f, 999);
			mSpace.resizeStaticHash(40f, 99);
			mSpace.setGravity(0, -600);

			staticBody = Body.make(Float.MAX_VALUE, Float.MAX_VALUE);

			// Vertexes for the bricks
			WYPoint[] verts = {
					WYPoint.make(-30, -15), WYPoint.make(-30, 15), WYPoint.make(30, 15), WYPoint.make(30, -15),
			};

			// Set up the static box.
			WYPoint a = WYPoint.make(-200, -200);
			WYPoint b = WYPoint.make(-200, 200);
			WYPoint c = WYPoint.make(200, 200);
			WYPoint d = WYPoint.make(200, -200);

			Shape shape = Segment.make(staticBody, a, b, 2f);
			shape.setRestitution(1f);
			shape.setFriction(1f);
			shape.setLayerMask(Chipmunk.NOT_GRABABLE_MASK);
			mSpace.addShape(shape);

			shape = Segment.make(staticBody, b, c, 2f);
			shape.setRestitution(1f);
			shape.setFriction(1f);
			shape.setLayerMask(Chipmunk.NOT_GRABABLE_MASK);
			mSpace.addShape(shape);

			shape = Segment.make(staticBody, c, d, 2f);
			shape.setRestitution(1f);
			shape.setFriction(1f);
			shape.setLayerMask(Chipmunk.NOT_GRABABLE_MASK);
			mSpace.addShape(shape);

			shape = Segment.make(staticBody, d, a, 2f);
			shape.setRestitution(1f);
			shape.setFriction(1f);
			shape.setLayerMask(Chipmunk.NOT_GRABABLE_MASK);
			mSpace.addShape(shape);

			// Give the box a little spin.
			// Because staticBody is never added to the space, we will need to
			// update it ourselves. (see above).
			// NOTE: Normally you would want to add the segments as normal and not static shapes.
			// I'm just doing it to demonstrate the cpSpaceRehashStatic() function.
			staticBody.setAngularVelocity(0.4f);

			// Add the bricks.
			for(int i = 0; i < 3; i++) {
				for(int j = 0; j < 7; j++) {
					Body body = Body.make(1f, Chipmunk.calculateMomentForPoly(1.0f, verts, WYPoint.makeZero()));
					body.setPosition(i * 60 - 150, j * 30 - 150);
					mSpace.addBody(body);

					shape = Poly.make(body, verts, WYPoint.makeZero());
					shape.setFriction(0.7f);
					mSpace.addShape(shape);
				}
			}

			schedule(new TargetSelector(this, "update(float)", new Object[] { 0f }));
		}

		public void update(float delta) {
			int steps = 3;
			float dt = delta / steps;

			for(int i = 0; i < steps; i++) {
				mSpace.step(dt);

				// Manually update the position of the static shape so that
				// the box rotates.
				staticBody.updatePosition(dt);

				// Because the box was added as a static shape and we moved it
				// we need to manually rehash the static spatial hash.
				mSpace.rehashStatic();
			}
		}
	}
}
