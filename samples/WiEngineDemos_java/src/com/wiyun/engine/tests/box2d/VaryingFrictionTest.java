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
import com.wiyun.engine.box2d.collision.EdgeShape;
import com.wiyun.engine.box2d.collision.PolygonShape;
import com.wiyun.engine.box2d.dynamics.Body;
import com.wiyun.engine.box2d.dynamics.BodyDef;
import com.wiyun.engine.box2d.dynamics.FixtureDef;
import com.wiyun.engine.nodes.Director;
import com.wiyun.engine.nodes.Layer;
import com.wiyun.engine.types.WYSize;
import com.wiyun.engine.utils.TargetSelector;

public class VaryingFrictionTest extends WiEngineTestActivity {
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
				Body ground = mWorld.createBody(bd);
				bd.destroy();

				EdgeShape shape = EdgeShape.make();
				shape.setEndpoints(-40.0f, 0.0f, 40.0f, 0.0f);
				ground.createFixture(shape, 0.0f);
			}

			{
				PolygonShape shape = PolygonShape.make();
				shape.setAsBox(13.0f, 0.25f);

				BodyDef bd = BodyDef.make();
				bd.setPosition(-4.0f, 22.0f);
				bd.setAngle(-0.25f);

				Body ground = mWorld.createBody(bd);
				ground.createFixture(shape, 0.0f);
				bd.destroy();
			}

			{
				PolygonShape shape = PolygonShape.make();
				shape.setAsBox(0.25f, 1.0f);

				BodyDef bd = BodyDef.make();
				bd.setPosition(10.5f, 19.0f);

				Body ground = mWorld.createBody(bd);
				ground.createFixture(shape, 0.0f);
				bd.destroy();
			}

			{
				PolygonShape shape = PolygonShape.make();
				shape.setAsBox(13.0f, 0.25f);

				BodyDef bd = BodyDef.make();
				bd.setPosition(4.0f, 14.0f);
				bd.setAngle(0.25f);

				Body ground = mWorld.createBody(bd);
				ground.createFixture(shape, 0.0f);
				bd.destroy();
			}

			{
				PolygonShape shape = PolygonShape.make();
				shape.setAsBox(0.25f, 1.0f);

				BodyDef bd = BodyDef.make();
				bd.setPosition(-10.5f, 11.0f);

				Body ground = mWorld.createBody(bd);
				ground.createFixture(shape, 0.0f);
				bd.destroy();
			}

			{
				PolygonShape shape = PolygonShape.make();
				shape.setAsBox(13.0f, 0.25f);

				BodyDef bd = BodyDef.make();
				bd.setPosition(-4.0f, 6.0f);
				bd.setAngle(-0.25f);

				Body ground = mWorld.createBody(bd);
				ground.createFixture(shape, 0.0f);
				bd.destroy();
			}

			{
				PolygonShape shape = PolygonShape.make();
				shape.setAsBox(0.5f, 0.5f);

				FixtureDef fd = FixtureDef.make();
				fd.setShape(shape);
				fd.setDensity(25.0f);

				float[] friction = {0.75f, 0.5f, 0.35f, 0.1f, 0.0f};

				for (int i = 0; i < friction.length; ++i)
				{
					BodyDef bd = BodyDef.make();
					bd.setType(Body.TYPE_DYNAMIC);
					bd.setPosition(-15.0f + 4.0f * i, 28.0f);
					Body body = mWorld.createBody(bd);
					bd.destroy();

					fd.setFriction(friction[i]);
					body.createFixture(fd);
				}
				fd.destroy();
			}
			
			schedule(new TargetSelector(this, "update(float)", new Object[] { 0f }));
		}
    }
}
