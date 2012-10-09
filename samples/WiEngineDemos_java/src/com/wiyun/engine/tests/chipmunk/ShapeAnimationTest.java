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

import com.wiyun.engine.R;
import com.wiyun.engine.WiEngineTestActivity;
import com.wiyun.engine.chipmunk.Body;
import com.wiyun.engine.chipmunk.Chipmunk;
import com.wiyun.engine.chipmunk.Poly;
import com.wiyun.engine.chipmunk.Segment;
import com.wiyun.engine.chipmunk.Shape;
import com.wiyun.engine.chipmunk.ShapeAnimation;
import com.wiyun.engine.chipmunk.Space;
import com.wiyun.engine.nodes.Director;
import com.wiyun.engine.nodes.Layer;
import com.wiyun.engine.types.WYPoint;
import com.wiyun.engine.types.WYSize;
import com.wiyun.engine.utils.ResolutionIndependent;
import com.wiyun.engine.utils.TargetSelector;

public class ShapeAnimationTest extends WiEngineTestActivity {
	@Override
	protected Layer createLayer() {
		return new MyLayer();
	}

    class MyLayer extends Layer {
    	Space mSpace;
    	
		public MyLayer() {
			WYSize s = Director.getInstance().getWindowSize();
			Chipmunk chipmunk = Chipmunk.make();
			chipmunk.setPosition(s.width / 2, s.height / 2);
			addChild(chipmunk);
			
			Shape.resetShapeIdCounter();

			mSpace = chipmunk.getSpace();
			mSpace.resizeActiveHash(30f, 1000);
			mSpace.resizeStaticHash(30f, 1000);
			mSpace.setIterations(10);
			mSpace.setGravity(0, -100);
			
			Body staticBody = Body.make(Float.MAX_VALUE, Float.MAX_VALUE);
			
			// add borders except for top
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
			
			// Add a moving poly object.
			// This time we need to give a mass and moment of inertia when creating the poly.
			float w = ResolutionIndependent.resolveDp(85);
			float h = ResolutionIndependent.resolveDp(121);
			WYPoint[] verts = {
					WYPoint.make(-w / 2, -h / 2),
					WYPoint.make(-w / 2, h / 2),
					WYPoint.make(w / 2, h / 2),
					WYPoint.make(w / 2, -h / 2)
			};
			float mass = 10.0f;
			float moment = Chipmunk.calculateMomentForPoly(mass, verts, WYPoint.makeZero());
			Body body = Body.make(mass, moment);
			body.setPosition(WYPoint.make(0, s.height / 2));
			mSpace.addBody(body);

			// Add a poly shape.
			shape = Poly.makeBox(body, w, h);
			shape.setRestitution(0.5f);
			shape.setFriction(0.9f);
			mSpace.addShape(shape);
			
			// create shape animation
			ShapeAnimation anim = ShapeAnimation.make(1f, 
				R.drawable.grossini_dance_01,
				R.drawable.grossini_dance_02,
				R.drawable.grossini_dance_03,
				R.drawable.grossini_dance_04,
				R.drawable.grossini_dance_05,
				R.drawable.grossini_dance_06,
				R.drawable.grossini_dance_07,
				R.drawable.grossini_dance_08,
				R.drawable.grossini_dance_09,
				R.drawable.grossini_dance_10,
				R.drawable.grossini_dance_11,
				R.drawable.grossini_dance_12,
				R.drawable.grossini_dance_13,
				R.drawable.grossini_dance_14);
			anim.setLoop(true);
			shape.startAnimation(anim);
			
			schedule(new TargetSelector(this, "update(float)", new Object[] { 0f }));
		}
		
		public void update(float delta) {
			mSpace.step(delta);
		}
    }
}
