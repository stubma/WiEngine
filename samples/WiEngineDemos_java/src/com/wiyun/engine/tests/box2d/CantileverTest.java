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
import com.wiyun.engine.box2d.dynamics.joints.WeldJointDef;
import com.wiyun.engine.nodes.Director;
import com.wiyun.engine.nodes.Layer;
import com.wiyun.engine.types.WYPoint;
import com.wiyun.engine.types.WYSize;
import com.wiyun.engine.utils.TargetSelector;

public class CantileverTest extends WiEngineTestActivity {
	@Override
	protected Layer createLayer() {
		return new MyLayer();
	}

    class MyLayer extends Box2DLayer {
    	Body m_middle;
    	
		public MyLayer() {
			int e_count = 8;
			WYSize s = Director.getInstance().getWindowSize();
			
			// set gravity
			mWorld.setGravity(0, -10);

			// place box2d to center of bottom edge
			mBox2D.setPosition(s.width / 2, 0);
			
			Body ground = null;
			{
				BodyDef bd = BodyDef.make();
				ground = mWorld.createBody(bd);
				bd.destroy();

				EdgeShape shape = EdgeShape.make();
				shape.setEndpoints(-40.0f, 0.0f, 40.0f, 0.0f);
				ground.createFixture(shape, 0.0f);
			}
			
			{
				PolygonShape shape = PolygonShape.make();
				shape.setAsBox(0.5f, 0.125f);

				FixtureDef fd = FixtureDef.make();
				fd.setShape(shape);
				fd.setDensity(20.0f);

				WeldJointDef jd = WeldJointDef.make();

				Body prevBody = ground;
				for (int i = 0; i < e_count; ++i)
				{
					BodyDef bd = BodyDef.make();
					bd.setType(Body.TYPE_DYNAMIC);
					bd.setPosition(-14.5f + 1.0f * i, 5.0f);
					Body body = mWorld.createBody(bd);
					body.createFixture(fd);
					bd.destroy();

					jd.initialize(prevBody, body, -15.0f + 1.0f * i, 5.0f);
					mWorld.createJoint(jd);

					prevBody = body;
				}
				jd.destroy();
				fd.destroy();
			}
			
			{
				PolygonShape shape = PolygonShape.make();
				shape.setAsBox(0.5f, 0.125f);

				FixtureDef fd = FixtureDef.make();
				fd.setShape(shape);
				fd.setDensity(20.0f);

				WeldJointDef jd = WeldJointDef.make();

				Body prevBody = ground;
				for (int i = 0; i < e_count; ++i)
				{
					BodyDef bd = BodyDef.make();
					bd.setType(Body.TYPE_DYNAMIC);
					bd.setPosition(-14.5f + 1.0f * i, 15.0f);
					Body body = mWorld.createBody(bd);
					body.createFixture(fd);
					bd.destroy();

					jd.initialize(prevBody, body, -15.0f + 1.0f * i, 15.0f);
					mWorld.createJoint(jd);

					prevBody = body;
				}
				jd.destroy();
				fd.destroy();
			}
			
			{
				PolygonShape shape = PolygonShape.make();
				shape.setAsBox(0.5f, 0.125f);

				FixtureDef fd = FixtureDef.make();
				fd.setShape(shape);
				fd.setDensity(20.0f);

				WeldJointDef jd = WeldJointDef.make();

				Body prevBody = ground;
				for (int i = 0; i < e_count; ++i)
				{
					BodyDef bd = BodyDef.make();
					bd.setType(Body.TYPE_DYNAMIC);
					bd.setPosition(-4.5f + 1.0f * i, 5.0f);
					Body body = mWorld.createBody(bd);
					body.createFixture(fd);
					bd.destroy();

					if (i > 0)
					{
						jd.initialize(prevBody, body, -5.0f + 1.0f * i, 5.0f);
						mWorld.createJoint(jd);
					}

					prevBody = body;
				}
				jd.destroy();
				fd.destroy();
			}
			
			{
				PolygonShape shape = PolygonShape.make();
				shape.setAsBox(0.5f, 0.125f);

				FixtureDef fd = FixtureDef.make();
				fd.setShape(shape);
				fd.setDensity(20.0f);

				WeldJointDef jd = WeldJointDef.make();

				Body prevBody = ground;
				for (int i = 0; i < e_count; ++i)
				{
					BodyDef bd = BodyDef.make();
					bd.setType(Body.TYPE_DYNAMIC);
					bd.setPosition(5.5f + 1.0f * i, 10.0f);
					Body body = mWorld.createBody(bd);
					body.createFixture(fd);
					bd.destroy();

					if (i > 0)
					{
						jd.initialize(prevBody, body, 5.0f + 1.0f * i, 10.0f);
						mWorld.createJoint(jd);
					}

					prevBody = body;
				}
				jd.destroy();
				fd.destroy();
			}
			
			for (int i = 0; i < 2; ++i)
			{
				WYPoint[] vertices = new WYPoint[3];
				vertices[0] = WYPoint.make(-0.5f, 0.0f);
				vertices[1] = WYPoint.make(0.5f, 0.0f);
				vertices[2] = WYPoint.make(0.0f, 1.5f);

				PolygonShape shape = PolygonShape.make();
				shape.setVertices(vertices);

				FixtureDef fd = FixtureDef.make();
				fd.setShape(shape);
				fd.setDensity(1.0f);

				BodyDef bd = BodyDef.make();
				bd.setType(Body.TYPE_DYNAMIC);
				bd.setPosition(-8.0f + 8.0f * i, 12.0f);
				Body body = mWorld.createBody(bd);
				body.createFixture(fd);
				fd.destroy();
				bd.destroy();
			}
			
			for (int i = 0; i < 2; ++i)
			{
				CircleShape shape = CircleShape.make();
				shape.setRadius(0.5f);

				FixtureDef fd = FixtureDef.make();
				fd.setShape(shape);
				fd.setDensity(1.0f);

				BodyDef bd = BodyDef.make();
				bd.setType(Body.TYPE_DYNAMIC);
				bd.setPosition(-6.0f + 6.0f * i, 10.0f);
				Body body = mWorld.createBody(bd);
				body.createFixture(fd);
			}
			
			schedule(new TargetSelector(this, "update(float)", new Object[] { 0f }));
		}
    }
}
