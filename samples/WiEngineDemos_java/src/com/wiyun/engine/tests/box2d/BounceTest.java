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

import com.wiyun.engine.WiEngineTestActivity;
import com.wiyun.engine.box2d.collision.EdgeShape;
import com.wiyun.engine.box2d.collision.PolygonShape;
import com.wiyun.engine.box2d.dynamics.Body;
import com.wiyun.engine.box2d.dynamics.BodyDef;
import com.wiyun.engine.box2d.dynamics.FixtureDef;
import com.wiyun.engine.box2d.dynamics.joints.RevoluteJointDef;
import com.wiyun.engine.nodes.Director;
import com.wiyun.engine.nodes.Layer;
import com.wiyun.engine.types.WYSize;
import com.wiyun.engine.utils.TargetSelector;

public class BounceTest extends WiEngineTestActivity {
	@Override
	protected Layer createLayer() {
		return new MyLayer();
	}

    class MyLayer extends Box2DLayer {
    	Random mRandom;
    	
		public MyLayer() {
			mRandom = new Random();
			WYSize s = Director.getInstance().getWindowSize();
			
			// place box2d to center of bottom edge
			mBox2D.setPosition(s.width / 2, s.height / 2);
			
			// meter size of screen
			float meterWidth = mBox2D.pixel2Meter(s.width);
			float meterHeight = mBox2D.pixel2Meter(s.height);
			
			Body ground = null;
			{
				BodyDef bd = BodyDef.make();
				ground = mWorld.createBody(bd);
				bd.destroy();

				// bottom edge
				EdgeShape bottom = EdgeShape.make();
				bottom.setEndpoints(-meterWidth / 2, -meterHeight / 2, meterWidth / 2, -meterHeight / 2);
				FixtureDef fd = FixtureDef.make();
				fd.setShape(bottom);
				ground.createFixture(fd);
				fd.destroy();

				// top edge
				EdgeShape top = EdgeShape.make();
				top.setEndpoints(-meterWidth / 2, meterHeight / 2, meterWidth / 2, meterHeight / 2);
				fd = FixtureDef.make();
				fd.setShape(top);
				ground.createFixture(fd);
				fd.destroy();

				// left edge
				EdgeShape left = EdgeShape.make();
				left.setEndpoints(-meterWidth / 2, -meterHeight / 2, -meterWidth / 2, meterHeight / 2);
				fd = FixtureDef.make();
				fd.setShape(left);
				ground.createFixture(fd);
				fd.destroy();

				// right edge
				EdgeShape right = EdgeShape.make();
				right.setEndpoints(meterWidth / 2, -meterHeight / 2, meterWidth / 2, meterHeight / 2);
				fd = FixtureDef.make();
				fd.setShape(right);
				ground.createFixture(fd);
				fd.destroy();
			}
			
			// boxes
			for (int i = 0; i < 10; i++) {
				BodyDef bd = BodyDef.make();
				bd.setType(Body.TYPE_DYNAMIC);
				bd.setLinearVelocity(5 * frand_unit(), 5 * frand_unit());
				Body body = mWorld.createBody(bd);
				body.setTransform(frand_unit() * meterWidth / 2, frand_unit() * meterHeight / 2, frand() * 2 * (float)Math.PI);
				bd.destroy();

				PolygonShape box = PolygonShape.make();
				box.setAsBox(0.5f, 0.5f);
				FixtureDef fd = FixtureDef.make();
				fd.setShape(box);
				fd.setRestitution(1.0f);
				fd.setFriction(0.0f);
				fd.setDensity(1.0f);
				body.createFixture(fd);
				fd.destroy();
			}
			
			// center stick
			{
				BodyDef bd = BodyDef.make();
				bd.setType(Body.TYPE_DYNAMIC);
				bd.setPosition(0, 0);
				Body stickBody = mWorld.createBody(bd);
				bd.destroy();

				PolygonShape stick = PolygonShape.make();
				stick.setAsBox(meterWidth / 4, 0.4f);
				FixtureDef fd = FixtureDef.make();
				fd.setShape(stick);
				fd.setRestitution(1.0f);
				fd.setFriction(0.0f);
				fd.setDensity(1.0f);
				stickBody.createFixture(fd);
				fd.destroy();

				RevoluteJointDef jd = RevoluteJointDef.make();
				jd.setBodyA(ground);
				jd.setBodyB(stickBody);
				jd.setLocalAnchorA(0, 0);
				jd.setLocalAnchorB(0, 0);
				mWorld.createJoint(jd);
				jd.destroy();
			}
			
			schedule(new TargetSelector(this, "update(float)", new Object[] { 0f }));
		}
		
		private float frand() {
			return mRandom.nextFloat();
		}
		
		private float frand_unit() {
			return mRandom.nextFloat() * -2.0f + 1.0f;
		}
    }
}
