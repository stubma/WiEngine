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

import static com.wiyun.engine.types.WYPoint.length;

import java.util.Random;

import com.wiyun.engine.R;
import com.wiyun.engine.WiEngineTestActivity;
import com.wiyun.engine.chipmunk.Body;
import com.wiyun.engine.chipmunk.Chipmunk;
import com.wiyun.engine.chipmunk.Constraint;
import com.wiyun.engine.chipmunk.PivotJoint;
import com.wiyun.engine.chipmunk.Poly;
import com.wiyun.engine.chipmunk.Segment;
import com.wiyun.engine.chipmunk.Shape;
import com.wiyun.engine.chipmunk.Space;
import com.wiyun.engine.nodes.Director;
import com.wiyun.engine.nodes.Layer;
import com.wiyun.engine.opengl.Texture2D;
import com.wiyun.engine.types.WYPoint;
import com.wiyun.engine.types.WYRect;
import com.wiyun.engine.types.WYSize;
import com.wiyun.engine.utils.ResolutionIndependent;
import com.wiyun.engine.utils.TargetSelector;

public class TexturedBounceTest extends WiEngineTestActivity {
	@Override
	protected Layer createLayer() {
		return new MyLayer();
	}

    class MyLayer extends Layer {
    	Space mSpace;
    	
    	Random mRandom;
    	
		public MyLayer() {
			WYSize s = Director.getInstance().getWindowSize();
			Chipmunk chipmunk = Chipmunk.make();
			chipmunk.setPosition(s.width / 2, s.height / 2);
			addChild(chipmunk);
			
			mRandom = new Random();
			
			Shape.resetShapeIdCounter();

			mSpace = chipmunk.getSpace();
			mSpace.resizeActiveHash(30f, 1000);
			mSpace.setIterations(10);
			
			Body staticBody = Body.make(Float.MAX_VALUE, Float.MAX_VALUE);
			
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
			
			for(int i = 0; i < 10; i++) {
				addBox();
			}
			
			Body body = Body.make(100, 10000);
			mSpace.addBody(body);
			
			shape = Segment.make(body, -150, 0, 150, 0, 15);
			shape.setRestitution(1);
			shape.setFriction(1);
			shape.setTexture(Texture2D.makePNG(R.drawable.bar));
			mSpace.addShape(shape);
			
			Constraint joint = PivotJoint.make(body, staticBody, WYPoint.makeZero(), WYPoint.makeZero());
			mSpace.addConstraint(joint);
			
			schedule(new TargetSelector(this, "update(float)", new Object[] { 0f }));
		}
		
		private void addBox() {
			float size = ResolutionIndependent.resolveDp(32f) / 2f;
			float mass = 1f;
			
			WYPoint[] verts = {
					WYPoint.make(-size, -size),
					WYPoint.make(-size, size),
					WYPoint.make(size, size),
					WYPoint.make(size, -size)
			};
			
			float radius = length(verts[2]);
			
			WYSize s = Director.getInstance().getWindowSize();
			float moment = Chipmunk.calculateMomentForPoly(mass, verts, WYPoint.makeZero());
			Body body = Body.make(mass, moment);
			body.setPosition(frand() * (s.width - 2 * radius) - (s.width / 2 - radius), frand() * (s.height - 2 * radius) - (s.height / 2 - radius));
			body.setVelocity((2 * frand() - 1) * 200, (2 * frand() - 1) * 200);
			mSpace.addBody(body);
			
			Random random = new Random();
			Shape shape = Poly.make(body, verts, WYPoint.makeZero());
			shape.setRestitution(1);
			shape.setFriction(0);
			shape.setTexture(Texture2D.makePNG(R.drawable.blocks),
				WYRect.make(random.nextInt(2) * size * 2, random.nextInt(2) * size * 2, size * 2, size * 2));
			mSpace.addShape(shape);
		}

		public void update(float delta) {
			mSpace.step(delta);
		}

		private float frand() {
			return mRandom.nextFloat();
		}
    }
}
