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
import static com.wiyun.engine.types.WYPoint.mul;

import java.util.Random;

import com.wiyun.engine.WiEngineTestActivity;
import com.wiyun.engine.chipmunk.Body;
import com.wiyun.engine.chipmunk.Chipmunk;
import com.wiyun.engine.chipmunk.Circle;
import com.wiyun.engine.chipmunk.Poly;
import com.wiyun.engine.chipmunk.Shape;
import com.wiyun.engine.chipmunk.Space;
import com.wiyun.engine.chipmunk.Body.IVelocityUpdater;
import com.wiyun.engine.nodes.Director;
import com.wiyun.engine.nodes.Layer;
import com.wiyun.engine.types.WYPoint;
import com.wiyun.engine.types.WYSize;
import com.wiyun.engine.utils.TargetSelector;

public class PlanetTest extends WiEngineTestActivity {
	@Override
	protected Layer createLayer() {
		return new MyLayer();
	}

    class MyLayer extends Layer implements IVelocityUpdater {
    	Space mSpace;
    	Random mRandom;
    	
		public MyLayer() {
			mRandom = new Random();
			
			// create chipmunk node
			WYSize s = Director.getInstance().getWindowSize();
			Chipmunk chipmunk = Chipmunk.make();
			chipmunk.setDebugDraw(true);
			chipmunk.setPosition(s.width / 2, s.height / 2);
			addChild(chipmunk);
			
			// reset shape id
			Shape.resetShapeIdCounter();

			// create space
			mSpace = chipmunk.getSpace();
			mSpace.setIterations(20);
			mSpace.resizeActiveHash(30, 10000);
			
			// create static body
			Body staticBody = Body.make(Float.MAX_VALUE, Float.MAX_VALUE);
			staticBody.setAngularVelocity(0.2f);
			mSpace.addBody(staticBody);
			
			for(int i = 0; i < 30; i++)
				addBox();
			
			// create planet
			Shape shape = Circle.make(staticBody, 70);
			shape.setFriction(1f);
			shape.setRestitution(1f);
			shape.setLayerMask(Chipmunk.NOT_GRABABLE_MASK);
			mSpace.addShape(shape);
			
			// schedule space update
			schedule(new TargetSelector(this, "update(float)", new Object[] { 0f }));
		}
		
		public void update(float delta) {
			mSpace.step(delta);
		}
		
		private WYPoint randPos(float radius) {
			WYPoint v = WYPoint.makeZero();
			WYSize s = Director.getInstance().getWindowSize();
			do {
				v.x = frand() * (s.width - 2 * radius) - (s.width / 2 - radius);
				v.y = frand() * (s.height - 2 * radius) - (s.height / 2 - radius);
			} while(length(v) < 100.0f);

			return v;
		}
		
		private void addBox() {
			float size = 10f;
			float mass = 1f;
			
			WYPoint[] verts = {
					WYPoint.make(-size, -size),
					WYPoint.make(-size, size),
					WYPoint.make(size, size),
					WYPoint.make(size, -size)
			};
			
			float radius = length(verts[2]);
			
			float moment = Chipmunk.calculateMomentForPoly(mass, verts, WYPoint.makeZero());
			Body body = Body.make(mass, moment);
			body.setPosition(randPos(radius));
			body.setVelocity((2 * frand() - 1) * 200, (2 * frand() - 1) * 200);
			body.setVelocityUpdater(this);
			mSpace.addBody(body);
			
			Shape shape = Poly.make(body, verts, WYPoint.makeZero());
			shape.setRestitution(0);
			shape.setFriction(0.7f);
			mSpace.addShape(shape);
		}
		
		private float frand() {
			return mRandom.nextFloat();
		}

		public void updateVelocity(int bodyPointer, float gravityX, float gravityY, float damping, float delta) {
			Body body = Body.from(bodyPointer);
			WYPoint p = WYPoint.make(body.getPositionX(), body.getPositionY());
			WYPoint g = mul(p, -50000f / dot(p, p));
			body.updateVelocity(g.x, g.y, damping, delta);
        }
    }
}
