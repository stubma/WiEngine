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

public class PyramidToppleTest extends WiEngineTestActivity {
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
			mSpace.setIterations(20);
			mSpace.setGravity(0, -300);
			mSpace.resizeActiveHash(30f, 2999);
			mSpace.resizeStaticHash(30f, 999);

			// add static body
			Body staticBody = Body.make(Float.MAX_VALUE, Float.MAX_VALUE);

			WYPoint[] verts = {
					WYPoint.make(-3, -20), WYPoint.make(-3, 20), WYPoint.make(3, 20), WYPoint.make(3, -20)
			};

			// Add a floor.
			Shape shape = Segment.make(staticBody, WYPoint.make(-240, -240), WYPoint.make(240, -240), 2);
			shape.setRestitution(1f);
			shape.setFriction(1f);
			shape.setLayerMask(Chipmunk.NOT_GRABABLE_MASK);
			mSpace.addStaticShape(shape);

			// Shared friction constant.
			float u = 0.6f;

			// Add the dominoes. Skim over this. It doesn't do anything fancy, and it's hard to follow.
			int n = 4;
			float moment = Chipmunk.calculateMomentForPoly(1f, verts, WYPoint.makeZero());
			for(int i = 1; i <= n; i++) {
				WYPoint offset = WYPoint.make(-i * 60 / 2.0f, (n - i) * 52);

				for(int j = 0; j < i; j++) {
					Body body = Body.make(1f, moment);
					body.setPosition(add(WYPoint.make(j * 60, -220), offset));
					mSpace.addBody(body);

					shape = Poly.make(body, verts, WYPoint.makeZero());
					shape.setFriction(u);
					mSpace.addShape(shape);

					body = Body.make(1f, moment);
					body.setPosition(add(WYPoint.make(j * 60, -197), offset));
					body.setAngle((float)Math.PI / 2f);
					mSpace.addBody(body);

					shape = Poly.make(body, verts, WYPoint.makeZero());
					shape.setFriction(u);
					mSpace.addShape(shape);

					if(j == (i - 1))
						continue;

					body = Body.make(1f, moment);
					body.setPosition(add(WYPoint.make(j * 60 + 30, -191), offset));
					body.setAngle((float)Math.PI / 2f);
					mSpace.addBody(body);

					shape = Poly.make(body, verts, WYPoint.makeZero());
					shape.setFriction(u);
					mSpace.addShape(shape);
				}

				Body body = Body.make(1f, moment);
				body.setPosition(add(WYPoint.make(-17, -174), offset));
				mSpace.addBody(body);

				shape = Poly.make(body, verts, WYPoint.makeZero());
				shape.setFriction(u);
				mSpace.addShape(shape);

				body = Body.make(1f, moment);
				body.setPosition(add(WYPoint.make((i - 1) * 60 + 17, -174), offset));
				mSpace.addBody(body);

				shape = Poly.make(body, verts, WYPoint.makeZero());
				shape.setFriction(u);
				mSpace.addShape(shape);

				shape = Poly.make(body, verts, WYPoint.makeZero());
				shape.setFriction(u);
				mSpace.addShape(shape);
			}

			schedule(new TargetSelector(this, "update(float)", new Object[] { 0f }));
		}

		public void update(float delta) {
			float steps = 2f;
			float dt = delta / steps;
			for(int i = 0; i < steps; i++)
				mSpace.step(dt);
		}
	}
}
