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

import static com.wiyun.engine.types.WYPoint.*;

import java.util.ArrayList;
import java.util.List;

import android.view.KeyEvent;

import com.wiyun.engine.WiEngineTestActivity;
import com.wiyun.engine.chipmunk.Arbiter;
import com.wiyun.engine.chipmunk.Body;
import com.wiyun.engine.chipmunk.Chipmunk;
import com.wiyun.engine.chipmunk.Circle;
import com.wiyun.engine.chipmunk.ICollisionHandler;
import com.wiyun.engine.chipmunk.Segment;
import com.wiyun.engine.chipmunk.Shape;
import com.wiyun.engine.chipmunk.Space;
import com.wiyun.engine.chipmunk.Body.IVelocityUpdater;
import com.wiyun.engine.nodes.Director;
import com.wiyun.engine.nodes.Layer;
import com.wiyun.engine.types.WYPoint;
import com.wiyun.engine.types.WYSize;
import com.wiyun.engine.utils.TargetSelector;

public class PlayerTest extends WiEngineTestActivity {

	@Override
	protected Layer createLayer() {
		return new MyLayer();
	}

	static class Player {
		float u;
		Shape shape;
		WYPoint groundNormal = WYPoint.makeZero();
		List<Shape> groundShapes = new ArrayList<Shape>();
	}

	static boolean sLastJumpState = false;
	
	class MyLayer extends Layer implements ICollisionHandler, IVelocityUpdater {
		Space mSpace;
		Player mPlayer;

		WYPoint mArrowDirection = WYPoint.makeZero();

		public MyLayer() {
			setKeyEnabled(true);

			WYSize s = Director.getInstance().getWindowSize();
			Chipmunk chipmunk = Chipmunk.make();
			chipmunk.setDebugDraw(true);
			chipmunk.setPosition(s.width / 2, s.height / 2);
			addChild(chipmunk);

			Shape.resetShapeIdCounter();

			mSpace = chipmunk.getSpace();
			mSpace.setIterations(10);
			mSpace.setGravity(0, -1500);

			Body staticBody = Body.make(Float.MAX_VALUE, Float.MAX_VALUE);

			// Create segments around the edge of the screen.
			Shape shape = Segment.make(staticBody, -s.width / 2, -s.height / 2, -s.width / 2, s.height / 2, 2);
			shape.setRestitution(1);
			shape.setFriction(1);
			shape.setLayerMask(Chipmunk.NOT_GRABABLE_MASK);
			shape.setCollisionType(2);
			mSpace.addStaticShape(shape);

			shape = Segment.make(staticBody, s.width / 2, -s.height / 2, s.width / 2, s.height / 2, 2);
			shape.setRestitution(1);
			shape.setFriction(1);
			shape.setLayerMask(Chipmunk.NOT_GRABABLE_MASK);
			shape.setCollisionType(2);
			mSpace.addStaticShape(shape);

			shape = Segment.make(staticBody, -s.width / 2, -s.height / 2, s.width / 2, -s.height / 2, 2);
			shape.setRestitution(1);
			shape.setFriction(1);
			shape.setLayerMask(Chipmunk.NOT_GRABABLE_MASK);
			shape.setCollisionType(2);
			mSpace.addStaticShape(shape);

			shape = Segment.make(staticBody, -s.width / 2, s.height / 2, s.width / 2, s.height / 2, 2);
			shape.setRestitution(1);
			shape.setFriction(1);
			shape.setLayerMask(Chipmunk.NOT_GRABABLE_MASK);
			shape.setCollisionType(2);
			mSpace.addStaticShape(shape);

			// add some other segments to play with
			shape = Segment.make(staticBody, -200, -60, 200, 240, 2);
			shape.setRestitution(1);
			shape.setFriction(1);
			shape.setLayerMask(Chipmunk.NOT_GRABABLE_MASK);
			shape.setCollisionType(2);
			mSpace.addStaticShape(shape);

			shape = Segment.make(staticBody, 0, -240, 240, -180, 2);
			shape.setRestitution(1);
			shape.setFriction(1);
			shape.setLayerMask(Chipmunk.NOT_GRABABLE_MASK);
			shape.setCollisionType(2);
			mSpace.addStaticShape(shape);

			shape = Segment.make(staticBody, -220, -80, 200, -160, 2);
			shape.setRestitution(1);
			shape.setFriction(1);
			shape.setLayerMask(Chipmunk.NOT_GRABABLE_MASK);
			shape.setCollisionType(2);
			mSpace.addStaticShape(shape);

			// Set up the player
			float radius = 15f;
			Body body = Body.make(10f, Float.MAX_VALUE);
			body.setPosition(0, -220);
			body.setVelocityUpdater(this);
			mSpace.addBody(body);

			shape = Circle.make(body, radius);
			shape.setFriction(2f);
			shape.setCollisionType(1);
			Player player = new Player();
			player.u = 2f;
			player.shape = shape;
			shape.setData(player);
			mPlayer = player;
			mSpace.addShape(shape);

			mSpace.addCollisionHandler(1, 2, this, null);

			schedule(new TargetSelector(this, "update(float)", new Object[] { 0f }));
		}

		public synchronized void update(float delta) {
			boolean jumpState = mArrowDirection.y > 0.0f;

			WYPoint groundNormal = mPlayer.groundNormal;
			if(groundNormal.y > 0.0f) {
				WYPoint v = mul(perp(groundNormal), 400.0f * mArrowDirection.x);
				mPlayer.shape.setSurfaceVelocity(v.x, v.y);
			} else {
				mPlayer.shape.setSurfaceVelocity(0, 0);
			}

			Body body = mPlayer.shape.getBody();

			// apply jump
			if(jumpState && !sLastJumpState && lengthsq(groundNormal) != 0) {
				WYPoint v = WYPoint.make(body.getVelocityX(), body.getVelocityY());
				v = add(v, mul(slerp(groundNormal, WYPoint.make(0.0f, 1.0f), 0.75f), 500.0f));
				body.setVelocity(v.x, v.y);
			}

			if(mPlayer.groundShapes.isEmpty()) {
				float air_accel = body.getVelocityX() + mArrowDirection.x * (2000.0f);
				body.setForce(body.getMass() * air_accel, 0);
			}

			mPlayer.groundNormal.x = 0;
			mPlayer.groundNormal.y = 0;
			int steps = 3;
			float stepDelta = delta / steps;
			for(int i = 0; i < steps; i++) {
				mSpace.step(stepDelta);
			}

			sLastJumpState = jumpState;
		}

		@Override
		public synchronized boolean wyKeyDown(KeyEvent event) {
			mArrowDirection.x = 0;
			mArrowDirection.y = 0;
			switch(event.getKeyCode()) {
				case KeyEvent.KEYCODE_DPAD_UP:
					mArrowDirection.y++;
					break;
				case KeyEvent.KEYCODE_DPAD_DOWN:
					mArrowDirection.y--;
					break;
				case KeyEvent.KEYCODE_DPAD_RIGHT:
					mArrowDirection.x++;
					break;
				case KeyEvent.KEYCODE_DPAD_LEFT:
					mArrowDirection.x--;
					break;
				default:
					return false;
			}
			
			return true;
		}

		public void updateVelocity(int bodyPointer, float gravityX, float gravityY, float damping, float delta) {
			Body body = Body.from(bodyPointer);
			body.updateVelocity(gravityX, gravityY, damping, delta);
			float vy = Math.max(body.getVelocityY(), -700);
			float vx = Math.min(Math.max(body.getVelocityX(), -400), 400);
			body.setVelocity(vx, vy);	        
        }

		public int begin(int arbiterPointer, int spacePointer, Object data) {
			Arbiter arbiter = Arbiter.from(arbiterPointer);
			Shape a = arbiter.getShapeA();
			Shape b = arbiter.getShapeB();
			Player player = (Player)a.getData();
			WYPoint normal = arbiter.getNormal(0);
			WYPoint n = negate(normal);
			if(n.y > 0f) {
				player.groundShapes.add(b);
			}

			return 1;
		}

		public void postSolve(int arbiterPointer, int spacePointer, Object data) {
		}

		public int preSolve(int arbiterPointer, int spacePointer, Object data) {
			Arbiter arbiter = Arbiter.from(arbiterPointer);
			Shape a = arbiter.getShapeA();
			Player player = (Player)a.getData();
			if(arbiter.getTimeStamp() > 0) {
				a.setFriction(player.u);

				// pick the most upright jump normal each frame
				WYPoint normal = arbiter.getNormal(0);
				WYPoint n = negate(normal);
				if(n.y >= player.groundNormal.y) {
					player.groundNormal = n;
				}
			}

			return 1;
		}

		public void separate(int arbiterPointer, int spacePointer, Object data) {
			Arbiter arbiter = Arbiter.from(arbiterPointer);
			Shape a = arbiter.getShapeA();
			Shape b = arbiter.getShapeB();
			Player player = (Player)a.getData();
			player.groundShapes.remove(b);

			if(player.groundShapes.isEmpty())
				a.setFriction(0f);
		}
	}
}
