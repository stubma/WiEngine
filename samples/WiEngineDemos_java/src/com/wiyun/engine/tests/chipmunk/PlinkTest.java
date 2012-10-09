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

import static java.lang.Math.abs;
import static java.lang.Math.cos;
import static java.lang.Math.sin;

import java.util.Random;

import com.wiyun.engine.WiEngineTestActivity;
import com.wiyun.engine.chipmunk.Body;
import com.wiyun.engine.chipmunk.Chipmunk;
import com.wiyun.engine.chipmunk.Poly;
import com.wiyun.engine.chipmunk.Shape;
import com.wiyun.engine.chipmunk.Space;
import com.wiyun.engine.chipmunk.Space.IBodyVisitor;
import com.wiyun.engine.nodes.Director;
import com.wiyun.engine.nodes.Layer;
import com.wiyun.engine.types.WYPoint;
import com.wiyun.engine.types.WYSize;
import com.wiyun.engine.utils.TargetSelector;

public class PlinkTest extends WiEngineTestActivity {
	private static final int NUM_VERTS = 5;

	@Override
	protected Layer createLayer() {
		return new MyLayer();
	}

	class MyLayer extends Layer implements IBodyVisitor {
		Space mSpace;

		Random mRandom;

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
			mSpace.resizeActiveHash(40f, 999);
			mSpace.resizeStaticHash(30f, 2999);

			Body staticBody = Body.make(Float.MAX_VALUE, Float.MAX_VALUE);

			// Create vertexes for a pentagon shape.
			WYPoint[] verts = new WYPoint[5];
			for(int i = 0; i < NUM_VERTS; i++) {
				float angle = -2 * (float)Math.PI * i / (NUM_VERTS);
				verts[i] = WYPoint.make(10 * (float)cos(angle), 10 * (float)sin(angle));
			}

			// Vertexes for a triangle shape.
			WYPoint tris[] = {
					WYPoint.make(-15, -15), WYPoint.make(0, 10), WYPoint.make(15, -15)
			};

			// Create the static triangles.
			for(int i = 0; i < 9; i++) {
				for(int j = 0; j < 6; j++) {
					float stagger = (j % 2) * 40;
					WYPoint offset = WYPoint.make(i * 80 - s.width / 2 + stagger, j * 70 - s.width / 2);
					Poly shape = Poly.make(staticBody, tris, offset);
					shape.setRestitution(1f);
					shape.setFriction(1f);
					shape.setLayerMask(Chipmunk.NOT_GRABABLE_MASK);
					mSpace.addStaticShape(shape);
				}
			}

			// Add lots of pentagons
			float moment = Chipmunk.calculateMomentForPoly(1f, verts, WYPoint.makeZero());
			for(int i = 0; i < 50; i++) {
				Body body = Body.make(1f, moment);
				float x = frand() * s.width - s.width / 2;
				body.setPosition(x, s.height / 2 * 5 / 7);
				mSpace.addBody(body);

				Poly shape = Poly.make(body, verts, WYPoint.makeZero());
				shape.setFriction(0.4f);
				mSpace.addShape(shape);
			}

			schedule(new TargetSelector(this, "update(float)", new Object[] { 0f }));
		}

		public void update(float delta) {
			mSpace.step(delta);
			mSpace.visitBody(this, null);
		}

		private float frand() {
			return mRandom.nextFloat();
		}

		public void visit(int bodyPointer, Object data) {
			Body body = Body.from(bodyPointer);
			if(body.getPositionY() < -260 || abs(body.getPositionX()) > 240) {
				WYSize s = Director.getInstance().getWindowSize();
				float x = frand() * s.width - s.width / 2;
				body.setPosition(x, 260);
			}
        }
	}
}
