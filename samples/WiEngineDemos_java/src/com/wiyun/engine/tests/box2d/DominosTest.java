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

import com.wiyun.engine.WiEngineTestActivity;
import com.wiyun.engine.box2d.collision.CircleShape;
import com.wiyun.engine.box2d.collision.EdgeShape;
import com.wiyun.engine.box2d.collision.PolygonShape;
import com.wiyun.engine.box2d.dynamics.Body;
import com.wiyun.engine.box2d.dynamics.BodyDef;
import com.wiyun.engine.box2d.dynamics.FixtureDef;
import com.wiyun.engine.box2d.dynamics.joints.DistanceJointDef;
import com.wiyun.engine.box2d.dynamics.joints.RevoluteJointDef;
import com.wiyun.engine.nodes.Director;
import com.wiyun.engine.nodes.Layer;
import com.wiyun.engine.types.WYPoint;
import com.wiyun.engine.types.WYSize;
import com.wiyun.engine.utils.TargetSelector;

public class DominosTest extends WiEngineTestActivity {
	@Override
	protected Layer createLayer() {
		return new MyLayer();
	}

    class MyLayer extends Box2DLayer {
		public MyLayer() {
			WYSize s = Director.getInstance().getWindowSize();
			
			// set gravity
			mWorld.setGravity(0, -10);

			// place box2d to center of bottom edge
			mBox2D.setPosition(s.width / 2, 0);
			
			Body b1 = null;
			{
				EdgeShape shape = EdgeShape.make();
				shape.setEndpoints(-40.0f, 0.0f, 40.0f, 0.0f);

				BodyDef bd = BodyDef.make();
				b1 = mWorld.createBody(bd);
				b1.createFixture(shape, 0.0f);
				bd.destroy();
			}

			{
				PolygonShape shape = PolygonShape.make();
				shape.setAsBox(6.0f, 0.25f);

				BodyDef bd = BodyDef.make();
				bd.setPosition(-1.5f, 10.0f);
				Body ground = mWorld.createBody(bd);
				ground.createFixture(shape, 0.0f);
				bd.destroy();
			}

			{
				PolygonShape shape = PolygonShape.make();
				shape.setAsBox(0.1f, 1.0f);

				FixtureDef fd = FixtureDef.make();
				fd.setShape(shape);
				fd.setDensity(20.0f);
				fd.setFriction(0.1f);

				for (int i = 0; i < 10; ++i)
				{
					BodyDef bd = BodyDef.make();
					bd.setType(Body.TYPE_DYNAMIC);
					bd.setPosition(-6.0f + 1.0f * i, 11.25f);
					Body body = mWorld.createBody(bd);
					body.createFixture(fd);
					bd.destroy();
				}
				fd.destroy();
			}

			{
				PolygonShape shape = PolygonShape.make();
				shape.setAsBox(7.0f, 0.25f, 0, 0, 0.3f);

				BodyDef bd = BodyDef.make();
				bd.setPosition(1.0f, 6.0f);
				Body ground = mWorld.createBody(bd);
				ground.createFixture(shape, 0.0f);
				bd.destroy();
			}

			Body b2 = null;
			{
				PolygonShape shape = PolygonShape.make();
				shape.setAsBox(0.25f, 1.5f);

				BodyDef bd = BodyDef.make();
				bd.setPosition(-7.0f, 4.0f);
				b2 = mWorld.createBody(bd);
				b2.createFixture(shape, 0.0f);
				bd.destroy();
			}

			Body b3 = null;
			{
				PolygonShape shape = PolygonShape.make();
				shape.setAsBox(6.0f, 0.125f);

				BodyDef bd = BodyDef.make();
				bd.setType(Body.TYPE_DYNAMIC);
				bd.setPosition(-0.9f, 1.0f);
				bd.setAngle(-0.15f);

				b3 = mWorld.createBody(bd);
				b3.createFixture(shape, 10.0f);
				bd.destroy();
			}

			RevoluteJointDef jd = RevoluteJointDef.make();
			jd.initialize(b1, b3, -2.0f, 1.0f);
			jd.setCollideConnected(true);
			mWorld.createJoint(jd);

			Body b4 = null;
			{
				PolygonShape shape = PolygonShape.make();
				shape.setAsBox(0.25f, 0.25f);

				BodyDef bd = BodyDef.make();
				bd.setType(Body.TYPE_DYNAMIC);
				bd.setPosition(-10.0f, 15.0f);
				b4 = mWorld.createBody(bd);
				b4.createFixture(shape, 10.0f);
				bd.destroy();
			}

			jd.initialize(b2, b4, -7.0f, 15.0f);
			mWorld.createJoint(jd);

			Body b5 = null;
			{
				BodyDef bd = BodyDef.make();
				bd.setType(Body.TYPE_DYNAMIC);
				bd.setPosition(6.5f, 3.0f);
				b5 = mWorld.createBody(bd);
				bd.destroy();

				PolygonShape shape = PolygonShape.make();
				FixtureDef fd = FixtureDef.make();

				fd.setShape(shape);
				fd.setDensity(10.0f);
				fd.setFriction(0.1f);

				shape.setAsBox(1.0f, 0.1f, 0.0f, -0.9f, 0.0f);
				b5.createFixture(fd);

				shape.setAsBox(0.1f, 1.0f, -0.9f, 0.0f, 0.0f);
				b5.createFixture(fd);

				shape.setAsBox(0.1f, 1.0f, 0.9f, 0.0f, 0.0f);
				b5.createFixture(fd);
				fd.destroy();
			}

			jd.initialize(b1, b5, 6.0f, 2.0f);
			mWorld.createJoint(jd);

			Body b6 = null;
			{
				PolygonShape shape = PolygonShape.make();
				shape.setAsBox(1.0f, 0.1f);

				BodyDef bd = BodyDef.make();
				bd.setType(Body.TYPE_DYNAMIC);
				bd.setPosition(6.5f, 4.1f);
				b6 = mWorld.createBody(bd);
				b6.createFixture(shape, 30.0f);
				bd.destroy();
			}

			jd.initialize(b5, b6, 7.5f, 4.0f);
			mWorld.createJoint(jd);
			jd.destroy();

			Body b7 = null;
			{
				PolygonShape shape = PolygonShape.make();
				shape.setAsBox(0.1f, 1.0f);

				BodyDef bd = BodyDef.make();
				bd.setType(Body.TYPE_DYNAMIC);
				bd.setPosition(7.4f, 1.0f);

				b7 = mWorld.createBody(bd);
				b7.createFixture(shape, 10.0f);
				bd.destroy();
			}

			DistanceJointDef djd = DistanceJointDef.make();
			djd.setBodyA(b3);
			djd.setBodyB(b7);
			djd.setLocalAnchorA(6.0f, 0.0f);
			djd.setLocalAnchorB(0.0f, -1.0f);
			WYPoint d = WYPoint.sub(b7.getWorldPoint(0.0f, -1.0f), b3.getWorldPoint(6.0f, 0.0f));
			djd.setLength(WYPoint.length(d));
			mWorld.createJoint(djd);
			djd.destroy();

			{
				float radius = 0.2f;

				CircleShape shape = CircleShape.make();
				shape.setRadius(radius);

				for (int i = 0; i < 4; ++i)
				{
					BodyDef bd = BodyDef.make();
					bd.setType(Body.TYPE_DYNAMIC);
					bd.setPosition(5.9f + 2.0f * radius * i, 2.4f);
					Body body = mWorld.createBody(bd);
					body.createFixture(shape, 10.0f);
					bd.destroy();
				}
			}
			
			schedule(new TargetSelector(this, "update(float)", new Object[] { 0f }));
		}
    }
}
