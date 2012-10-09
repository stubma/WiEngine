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
import com.wiyun.engine.box2d.common.Transform;
import com.wiyun.engine.box2d.dynamics.Body;
import com.wiyun.engine.box2d.dynamics.BodyDef;
import com.wiyun.engine.nodes.Director;
import com.wiyun.engine.nodes.Layer;
import com.wiyun.engine.types.WYPoint;
import com.wiyun.engine.types.WYSize;
import com.wiyun.engine.utils.TargetSelector;

public class CompoundShapesTest extends WiEngineTestActivity {
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
			
			{
				BodyDef bd = BodyDef.make();
				bd.setPosition(0.0f, 0.0f);
				Body body = mWorld.createBody(bd);
				bd.destroy();

				EdgeShape shape = EdgeShape.make();
				shape.setEndpoints(50.0f, 0.0f, -50.0f, 0.0f);

				body.createFixture(shape, 0.0f);
			}
			
			{
				CircleShape circle1 = CircleShape.make();
				circle1.setRadius(0.5f);
				circle1.setPosition(-0.5f, 0.5f);

				CircleShape circle2 = CircleShape.make();
				circle2.setRadius(0.5f);
				circle2.setPosition(0.5f, 0.5f);

				for (int i = 0; i < 10; ++i)
				{
					float x = mRandom.nextFloat() * 2.f - 1.f;
					BodyDef bd = BodyDef.make();
					bd.setType(Body.TYPE_DYNAMIC);
					bd.setPosition(x + 5.0f, 1.05f + 2.5f * i);
					bd.setAngle(mRandom.nextFloat() * (float)(2 * Math.PI) - (float)Math.PI);
					Body body = mWorld.createBody(bd);
					body.createFixture(circle1, 2.0f);
					body.createFixture(circle2, 0.0f);
					bd.destroy();
				}
			}
			
			{
				PolygonShape polygon1 = PolygonShape.make();
				polygon1.setAsBox(0.25f, 0.5f);

				PolygonShape polygon2 = PolygonShape.make();
				polygon2.setAsBox(0.25f, 0.5f, 0.0f, -0.5f, 0.5f * (float)Math.PI);

				for (int i = 0; i < 10; ++i)
				{
					float x = mRandom.nextFloat() * 2.f - 1.f;
					BodyDef bd = BodyDef.make();
					bd.setType(Body.TYPE_DYNAMIC);
					bd.setPosition(x - 5.0f, 1.05f + 2.5f * i);
					bd.setAngle(mRandom.nextFloat() * (float)(2 * Math.PI) - (float)Math.PI);
					Body body = mWorld.createBody(bd);
					body.createFixture(polygon1, 2.0f);
					body.createFixture(polygon2, 2.0f);
					bd.destroy();
				}
			}
			
			{
				Transform xf1 = Transform.make();
				xf1.q.set(0.3524f * (float)Math.PI);
				xf1.p = xf1.q.mul(WYPoint.make(1.0f, 0.0f));

				WYPoint[] vertices = new WYPoint[3];

				PolygonShape triangle1 = PolygonShape.make();
				vertices[0] = xf1.mul(WYPoint.make(-1.0f, 0.0f));
				vertices[1] = xf1.mul(WYPoint.make(1.0f, 0.0f));
				vertices[2] = xf1.mul(WYPoint.make(0.0f, 0.5f));
				triangle1.setVertices(vertices);

				Transform xf2 = Transform.make();
				xf2.q.set(-0.3524f * (float)Math.PI);
				xf2.p = xf2.q.mul(WYPoint.make(-1.0f, 0.0f));

				PolygonShape triangle2 = PolygonShape.make();
				vertices[0] = xf2.mul(WYPoint.make(-1.0f, 0.0f));
				vertices[1] = xf2.mul(WYPoint.make(1.0f, 0.0f));
				vertices[2] = xf2.mul(WYPoint.make(0.0f, 0.5f));
				triangle2.setVertices(vertices);

				for (int i = 0; i < 10; ++i)
				{
					float x = mRandom.nextFloat() * 2.f - 1.f;
					BodyDef bd = BodyDef.make();
					bd.setType(Body.TYPE_DYNAMIC);
					bd.setPosition(x, 2.05f + 2.5f * i);
					bd.setAngle(0.0f);
					Body body = mWorld.createBody(bd);
					body.createFixture(triangle1, 2.0f);
					body.createFixture(triangle2, 2.0f);
					bd.destroy();
				}
			}
			
			{
				PolygonShape bottom = PolygonShape.make();
				bottom.setAsBox( 1.5f, 0.15f );

				PolygonShape left = PolygonShape.make();
				left.setAsBox(0.15f, 2.7f, -1.45f, 2.35f, 0.2f);

				PolygonShape right = PolygonShape.make();
				right.setAsBox(0.15f, 2.7f, 1.45f, 2.35f, -0.2f);

				BodyDef bd = BodyDef.make();
				bd.setType(Body.TYPE_DYNAMIC);
				bd.setPosition(0.0f, 2.0f );
				Body body = mWorld.createBody(bd);
				body.createFixture(bottom, 4.0f);
				body.createFixture(left, 4.0f);
				body.createFixture(right, 4.0f);
			}
			
			schedule(new TargetSelector(this, "update(float)", new Object[] { 0f }));
		}
    }
}
