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

import java.util.Random;

import android.view.MotionEvent;

import com.wiyun.engine.R;
import com.wiyun.engine.WiEngineTestActivity;
import com.wiyun.engine.chipmunk.Body;
import com.wiyun.engine.chipmunk.Chipmunk;
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

public class BodyDraggingTest extends WiEngineTestActivity {
	@Override
	protected Layer createLayer() {
		return new MyLayer();
	}
	
    class MyLayer extends Layer {
    	Space mSpace;
    	Random mRandom;
    	Body mBody;
    	
    	boolean mDragging;
    	
		public MyLayer() {
			setTouchEnabled(true);
			
			WYSize s = Director.getInstance().getWindowSize();
			Chipmunk chipmunk = Chipmunk.make();
			addChild(chipmunk);
			
			mRandom = new Random();
			
			Shape.resetShapeIdCounter();

			mSpace = chipmunk.getSpace();
			mSpace.setIterations(10);
			mSpace.setGravity(0, -100);
			
			Body staticBody = Body.make(Float.MAX_VALUE, Float.MAX_VALUE);
			
			// Create A ground segment along the border of the screen
			Shape shape = Segment.make(staticBody, 0, 0, 0, s.height, 2);
			shape.setRestitution(1);
			shape.setFriction(1);
			shape.setLayerMask(Chipmunk.NOT_GRABABLE_MASK);
			mSpace.addStaticShape(shape);
			
			shape = Segment.make(staticBody, s.width, 0, s.width, s.height, 2);
			shape.setRestitution(1);
			shape.setFriction(1);
			shape.setLayerMask(Chipmunk.NOT_GRABABLE_MASK);
			mSpace.addStaticShape(shape);
			
			shape = Segment.make(staticBody, 0, 0, s.width, 0, 2);
			shape.setRestitution(1);
			shape.setFriction(1);
			shape.setLayerMask(Chipmunk.NOT_GRABABLE_MASK);
			mSpace.addStaticShape(shape);
			
			shape = Segment.make(staticBody, 0, s.height, s.width, s.height, 2);
			shape.setRestitution(1);
			shape.setFriction(1);
			shape.setLayerMask(Chipmunk.NOT_GRABABLE_MASK);
			mSpace.addStaticShape(shape);
			
			// add a box
			mBody = addBox();

			schedule(new TargetSelector(this, "update(float)", new Object[] { 0f }));
		}
		
		public void update(float delta) {
			mSpace.step(delta);
		}
		
		private Body addBox() {
			float size = ResolutionIndependent.resolveDp(32f);
			float mass = 1f;
			
			WYPoint[] verts = {
					WYPoint.make(-size, -size),
					WYPoint.make(-size, size),
					WYPoint.make(size, size),
					WYPoint.make(size, -size)
			};
			WYSize s = Director.getInstance().getWindowSize();
			float moment = Chipmunk.calculateMomentForPoly(mass, verts, WYPoint.makeZero());
			Body body = Body.make(mass, moment);
			body.setPosition(s.width / 2, s.height / 2);
			body.setVelocity((2 * frand() - 1) * 200, (2 * frand() - 1) * 200);
			mSpace.addBody(body);
			
			Shape shape = Poly.make(body, verts, WYPoint.makeZero());
			shape.setRestitution(1);
			shape.setFriction(0);
			shape.setTexture(Texture2D.makePNG(R.drawable.blocks));
			mSpace.addShape(shape);
			
			return body;
		}
		
		private float frand() {
			return mRandom.nextFloat();
		}
		
		@Override
		public boolean wyTouchesBegan(MotionEvent event) {
			WYRect rect = WYRect.makeZero();
			mSpace.getAnyShapeOfBody(mBody).getBoundingBox(rect);
			WYPoint loc = Director.getInstance().convertToGL(event.getX(), event.getY());
			if(rect.containsPoint(loc)) {
				mDragging = true;
			}
			return true;
		}
		
		@Override
		public boolean wyTouchesMoved(MotionEvent event) {
			if(mDragging) {
				WYPoint loc = Director.getInstance().convertToGL(event.getX(), event.getY());
				mBody.setPosition(loc);
			}

			return true;
		}
		
		@Override
		public boolean wyTouchesEnded(MotionEvent event) {
			mDragging = false;
			return true;
		}
		
		@Override
		public boolean wyTouchesCancelled(MotionEvent event) {
			mDragging = false;
			return true;
		}
    }
}
