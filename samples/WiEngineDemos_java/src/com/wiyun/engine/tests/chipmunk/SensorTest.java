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

import static com.wiyun.engine.types.WYPoint.mul;

import java.util.Random;

import com.wiyun.engine.WiEngineTestActivity;
import com.wiyun.engine.chipmunk.Arbiter;
import com.wiyun.engine.chipmunk.Body;
import com.wiyun.engine.chipmunk.Chipmunk;
import com.wiyun.engine.chipmunk.Circle;
import com.wiyun.engine.chipmunk.ICollisionHandler;
import com.wiyun.engine.chipmunk.Segment;
import com.wiyun.engine.chipmunk.Shape;
import com.wiyun.engine.chipmunk.Space;
import com.wiyun.engine.chipmunk.Space.IPostStepCallback;
import com.wiyun.engine.nodes.ColorLayer;
import com.wiyun.engine.nodes.Director;
import com.wiyun.engine.nodes.Layer;
import com.wiyun.engine.types.WYColor4B;
import com.wiyun.engine.types.WYPoint;
import com.wiyun.engine.types.WYSize;
import com.wiyun.engine.utils.TargetSelector;

public class SensorTest extends WiEngineTestActivity {
	@Override
	protected Layer createLayer() {
		return new MyLayer();
	}

    static final class Emitter {
    	int queue;
    	int blocked;
    	WYPoint position;
    }
    
    class MyLayer extends ColorLayer implements ICollisionHandler, IPostStepCallback {
    	Space mSpace;
    	
    	Random mRandom;
    	
    	Emitter emitter;
    	
    	static final int BALL_TYPE = 0;
    	static final int BLOCKING_SENSOR_TYPE = 1;
    	static final int CATCH_SENSOR_TYPE = 2;
    	
		public MyLayer() {
			super(new WYColor4B(0, 0, 255, 255));
			
			WYSize s = Director.getInstance().getWindowSize();
			Chipmunk chipmunk = Chipmunk.make();
			chipmunk.setDebugDraw(true);
			chipmunk.setPosition(s.width / 2, s.height / 2);
			addChild(chipmunk);
			
			mRandom = new Random();
			emitter = new Emitter();
			
			Shape.resetShapeIdCounter();

			mSpace = chipmunk.getSpace();
			mSpace.setIterations(10);
			mSpace.setGravity(0, -100);
			
			Body staticBody = Body.make(Float.MAX_VALUE, Float.MAX_VALUE);
			
			// Data structure for our ball emitter
			// We'll use two sensors for it, one to see if the emitter is blocked
			// a second to catch the balls and add them back to the emitter
			emitter.queue = 5;
			emitter.blocked = 0;
			emitter.position = WYPoint.make(0, 150);
			
			// Create our blocking sensor, so we know when the emitter is clear to emit another ball
			Shape shape = Circle.make(staticBody, 15f, 0, 150);
			shape.setIsSensor(true);
			shape.setCollisionType(BLOCKING_SENSOR_TYPE);
			shape.setData(emitter);
			mSpace.addStaticShape(shape);
			
			// Create our catch sensor to requeue the balls when they reach the bottom of the screen
			shape = Segment.make(staticBody, WYPoint.make(-2000, -200), WYPoint.make(2000, -200), 15f);
			shape.setIsSensor(true);
			shape.setCollisionType(CATCH_SENSOR_TYPE);
			shape.setData(emitter);
			mSpace.addStaticShape(shape);
			
			mSpace.addCollisionHandler(BLOCKING_SENSOR_TYPE, BALL_TYPE, this, null);
			mSpace.addCollisionHandler(CATCH_SENSOR_TYPE, BALL_TYPE, this, null);

			schedule(new TargetSelector(this, "update(float)", new Object[] { 0f }));
		}
		
		public void update(float delta) {
			if(emitter.blocked == 0 && emitter.queue != 0){
				emitter.queue--;
				
				float moment = Chipmunk.calculateMomentForCircle(1f, 15f, 0f, WYPoint.makeZero());
				Body body = Body.make(1f, moment);
				body.setPosition(emitter.position);
				body.setVelocity(mul(WYPoint.make(frand(), frand()), 100));
				mSpace.addBody(body);
				
				Shape shape = Circle.make(body, 15f);
				shape.setCollisionType(BALL_TYPE);
				mSpace.addShape(shape);
			}
			
			mSpace.step(delta);
		}

		private float frand() {
			return mRandom.nextFloat();
		}

		public void postStep(Object obj, Object data) {
			Shape shape = (Shape)obj;
			mSpace.removeAndDestroyBody(shape.getBody());
		}

		public int begin(int arbiterPointer, int spacePointer, Object data) {
			Arbiter arbiter = Arbiter.from(arbiterPointer);
			Shape a = arbiter.getShapeA();
			Shape b = arbiter.getShapeB();
			if(a.getCollisionType() == BLOCKING_SENSOR_TYPE) {
				Emitter e = (Emitter)a.getData();
				e.blocked++;
			} else if(a.getCollisionType() == CATCH_SENSOR_TYPE) {
				Emitter e = (Emitter)a.getData();
				e.queue++;
				mSpace.addPostStepCallback(this, b, null);
			}
			
			// Return values from sensors callbacks are ignored
			return 0;
		}

		public void postSolve(int arbiterPointer, int spacePointer, Object data) {
		}

		public int preSolve(int arbiterPointer, int spacePointer, Object data) {
			return 1;
		}

		public void separate(int arbiterPointer, int spacePointer, Object data) {
			Arbiter arbiter = Arbiter.from(arbiterPointer);
			Shape a = arbiter.getShapeA();
			if(a.getCollisionType() == BLOCKING_SENSOR_TYPE) {
				Emitter e = (Emitter)a.getData();
				e.blocked--;
			}
		}
    }
}
