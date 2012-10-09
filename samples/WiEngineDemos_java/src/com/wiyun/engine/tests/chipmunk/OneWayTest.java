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

import java.util.ArrayList;

import com.wiyun.engine.WiEngineTestActivity;
import com.wiyun.engine.chipmunk.Arbiter;
import com.wiyun.engine.chipmunk.Body;
import com.wiyun.engine.chipmunk.Chipmunk;
import com.wiyun.engine.chipmunk.Circle;
import com.wiyun.engine.chipmunk.ICollisionHandler;
import com.wiyun.engine.chipmunk.Segment;
import com.wiyun.engine.chipmunk.Shape;
import com.wiyun.engine.chipmunk.Space;
import com.wiyun.engine.nodes.Director;
import com.wiyun.engine.nodes.Layer;
import com.wiyun.engine.types.WYPoint;
import com.wiyun.engine.types.WYSize;
import com.wiyun.engine.utils.TargetSelector;

public class OneWayTest extends WiEngineTestActivity {
	@Override
	protected Layer createLayer() {
		return new MyLayer();
	}

    class MyLayer extends Layer implements ICollisionHandler {
    	Space mSpace;
    	
		public MyLayer() {
			WYSize s = Director.getInstance().getWindowSize();
			Chipmunk chipmunk = Chipmunk.make();
			chipmunk.setDebugDraw(true);
			chipmunk.setPosition(s.width / 2, s.height / 2);
			addChild(chipmunk);
			
			Shape.resetShapeIdCounter();

			mSpace = chipmunk.getSpace();
			mSpace.setIterations(10);
			mSpace.setGravity(0, -100);
			
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
			
			shape = Segment.make(staticBody, -s.width / 2, s.height / 2, s.width / 2, s.height / 2, 2);
			shape.setRestitution(1);
			shape.setFriction(1);
			shape.setLayerMask(Chipmunk.NOT_GRABABLE_MASK);
			mSpace.addStaticShape(shape);
			
			shape = Segment.make(staticBody, -s.width / 2 + 60, -100, s.width / 2 - 60, -100, 10);
			shape.setRestitution(1);
			shape.setFriction(1);
			shape.setCollisionType(1);
			shape.setLayerMask(Chipmunk.NOT_GRABABLE_MASK);
			shape.setData(new ArrayList<Shape>());
			mSpace.addStaticShape(shape);
			
			float radius = 15f;
			Body body = Body.make(10f, Chipmunk.calculateMomentForCircle(10f, 0, radius, WYPoint.makeZero()));
			body.setPosition(0, -200);
			body.setVelocity(0, 170);
			mSpace.addBody(body);
			
			shape = Circle.make(body, radius);
			shape.setFriction(0.9f);
			shape.setCollisionType(2);
			mSpace.addShape(shape);
			
			mSpace.addCollisionHandler(1, 2, this, null);

			schedule(new TargetSelector(this, "update(float)", new Object[] { 0f }));
		}
		
		public void update(float delta) {
			mSpace.step(delta);
		}

		public int begin(int arbiterPointer, int spacePointer, Object data) {
			return 1;
		}

		public void postSolve(int arbiterPointer, int spacePointer, Object data) {
		}

		@SuppressWarnings("unchecked")
		public int preSolve(int arbiterPointer, int spacePointer, Object data) {
			Arbiter arbiter = Arbiter.from(arbiterPointer);
			Shape a = arbiter.getShapeA();
			Shape b = arbiter.getShapeB();
			ArrayList<Shape> passThruList = (ArrayList<Shape>)a.getData();
			if(passThruList.contains(b)) {
				return 0;
			} else {
				float dot = dot(arbiter.getNormal(0), WYPoint.make(0, 1));
				if(dot < 0) {
					passThruList.add(b);
					return 0;
				} else {
					return 1;
				}
			}
		}

		@SuppressWarnings("unchecked")
		public void separate(int arbiterPointer, int spacePointer, Object data) {
			Arbiter arbiter = Arbiter.from(arbiterPointer);
			Shape a = arbiter.getShapeA();
			Shape b = arbiter.getShapeB();
			ArrayList<Shape> passThruList = (ArrayList<Shape>)a.getData();
			passThruList.remove(b);
		}
    }
}
