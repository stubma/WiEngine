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
package com.wiyun.engine.tests.box2d;

import java.util.Random;

import android.view.MotionEvent;

import com.wiyun.engine.box2d.Box2D;
import com.wiyun.engine.box2d.dynamics.Body;
import com.wiyun.engine.box2d.dynamics.BodyDef;
import com.wiyun.engine.box2d.dynamics.Fixture;
import com.wiyun.engine.box2d.dynamics.World;
import com.wiyun.engine.box2d.dynamics.World.IQueryCallback;
import com.wiyun.engine.box2d.dynamics.joints.MouseJoint;
import com.wiyun.engine.box2d.dynamics.joints.MouseJointDef;
import com.wiyun.engine.nodes.Director;
import com.wiyun.engine.nodes.Layer;
import com.wiyun.engine.types.WYPoint;

public class Box2DLayer extends Layer implements IQueryCallback {
	protected Box2D mBox2D;
	protected World mWorld;
	protected WYPoint mMouseWorld;
	protected MouseJoint mMouseJoint;
	protected Body mGroundBody;
	protected int mStepCount;
	
	protected int mFixturePointer;
	
	protected Random mRandom = new Random();

	public Box2DLayer() {
		mBox2D = Box2D.make();
		mBox2D.setDebugDraw(true);
		mWorld = mBox2D.getWorld();
		addChild(mBox2D);
		
		BodyDef bodyDef = BodyDef.make();
		mGroundBody = mBox2D.getWorld().createBody(bodyDef);
		bodyDef.destroy();

		setTouchEnabled(true);
	}
	
	public void update(float delta) {
		mWorld.step(1.f / 60.f, 10, 10);
		mWorld.clearForces();
		mStepCount++;
	}
	
	@Override
	public boolean wyTouchesBegan(MotionEvent event) {
		WYPoint loc = Director.getInstance().convertToGL(event.getX(), event.getY());
		loc = mBox2D.convertToNodeSpace(loc.x, loc.y);
		WYPoint p = WYPoint.make(mBox2D.pixel2Meter(loc.x), mBox2D.pixel2Meter(loc.y));
		mMouseWorld = p;

		if (mMouseJoint != null) {
			return false;
		}

		// Query the world for overlapping shapes.
		mFixturePointer = 0;
		mWorld.queryAABB(this, p.x - 0.001f, p.y - 0.001f, p.x + 0.001f, p.y + 0.001f);

		if (mFixturePointer != 0) {
			Fixture f = Fixture.from(mFixturePointer);
			Body body = f.getBody();
			MouseJointDef md = MouseJointDef.make();
			md.setBodyA(mGroundBody);
			md.setBodyB(body);
			md.setTarget(p.x, p.y);
			md.setMaxForce(1000.0f * body.getMass());
			mMouseJoint = MouseJoint.from(mWorld.createJoint(md));
			body.setAwake(true);
			
			return true;
		}
		
		return false;
	}
	
	@Override
	public boolean wyTouchesMoved(MotionEvent event) {
		WYPoint loc = Director.getInstance().convertToGL(event.getX(), event.getY());
		loc = mBox2D.convertToNodeSpace(loc.x, loc.y);
		WYPoint p = WYPoint.make(mBox2D.pixel2Meter(loc.x), mBox2D.pixel2Meter(loc.y));
		mMouseWorld = p;

		if (mMouseJoint != null) {
			mMouseJoint.setTarget(p.x, p.y);
		}
		
		return true;
	}
	
	@Override
	public boolean wyTouchesEnded(MotionEvent event) {
		if (mMouseJoint != null) {
			mWorld.destroyJoint(mMouseJoint);
			mMouseJoint = null;
		}

		return true;
	}
	
	@Override
	public boolean wyTouchesCancelled(MotionEvent event) {
		if (mMouseJoint != null) {
			mWorld.destroyJoint(mMouseJoint);
			mMouseJoint = null;
		}

		return true;
	}

	public boolean reportFixture(int fixturePointer) {
		Fixture f = Fixture.from(fixturePointer);
		Body body = f.getBody();
		if (body.getType() == Body.TYPE_DYNAMIC) {
			boolean inside = f.testPoint(mMouseWorld.x, mMouseWorld.y);
			if (inside) {
				mFixturePointer = fixturePointer;

				// We are done, terminate the query.
				return false;
			}
		}

		// Continue the query.
		return true;
	}
}
