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
import com.wiyun.engine.chipmunk.Segment;
import com.wiyun.engine.chipmunk.Shape;
import com.wiyun.engine.chipmunk.Space;
import com.wiyun.engine.nodes.Director;
import com.wiyun.engine.nodes.Layer;
import com.wiyun.engine.types.WYPoint;
import com.wiyun.engine.types.WYSize;
import com.wiyun.engine.utils.TargetSelector;

public class SimpleTest extends WiEngineTestActivity {
	@Override
	protected Layer createLayer() {
		return new MyLayer();
	}

    class MyLayer extends Layer {
    	Space mSpace;
    	
		public MyLayer() {
			WYSize s = Director.getInstance().getWindowSize();
			Chipmunk chipmunk = Chipmunk.make();
			chipmunk.setDebugDraw(true);
			chipmunk.setPosition(s.width / 2, s.height / 2);
			addChild(chipmunk);
			
			Shape.resetShapeIdCounter();

			mSpace = chipmunk.getSpace();
			mSpace.resizeActiveHash(30f, 1000);
			mSpace.resizeStaticHash(30f, 1000);
			mSpace.setIterations(10);
			mSpace.setGravity(0, -100);
			
			Body staticBody = Body.make(Float.MAX_VALUE, Float.MAX_VALUE);
			
			// Create A ground segment along the bottom of the screen
			// Add the shape to the space as a static shape
			// If a shape never changes position, add it as static so Chipmunk knows it only needs to
			// calculate collision information for it once when it is added.
			// Do not change the postion of a static shape after adding it.
			Shape shape = Segment.make(staticBody, WYPoint.make(-s.width / 2, -s.height / 2), WYPoint.make(s.width / 2, -s.height / 2), 2f);
			shape.setRestitution(1f);
			shape.setFriction(1f);
			shape.setLayerMask(Chipmunk.NOT_GRABABLE_MASK);
			mSpace.addStaticShape(shape);
			
			// Add a moving circle object.
			// This time we need to give a mass and moment of inertia when creating the circle.
			// Set some parameters of the body:
			// For more info: http://code.google.com/p/chipmunk-physics/wiki/cpBody
			// Add the body to the space so it will be simulated and move around.
			float radius = 15.0f;
			float mass = 10.0f;
			float moment = Chipmunk.calculateMomentForCircle(mass, 0, radius, WYPoint.makeZero());
			Body body = Body.make(mass, moment);
			body.setPosition(WYPoint.make(0, s.height / 2));
			mSpace.addBody(body);

			// Add a circle shape for the ball.
			// Shapes are always defined relative to the center of gravity of the body they are attached to.
			// When the body moves or rotates, the shape will move with it.
			// Additionally, all of the cpSpaceAdd*() functions return the thing they added so you can create and add in one go.
			shape = Circle.make(body, radius);
			shape.setRestitution(0.5f);
			shape.setFriction(0.9f);
			mSpace.addShape(shape);
			
			schedule(new TargetSelector(this, "update(float)", new Object[] { 0f }));
		}
		
		public void update(float delta) {
			mSpace.step(delta);
		}
    }
}
