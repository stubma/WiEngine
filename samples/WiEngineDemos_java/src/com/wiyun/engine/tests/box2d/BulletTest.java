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
import com.wiyun.engine.nodes.Director;
import com.wiyun.engine.nodes.Layer;
import com.wiyun.engine.types.WYPoint;
import com.wiyun.engine.types.WYSize;
import com.wiyun.engine.utils.TargetSelector;

public class BulletTest extends WiEngineTestActivity {
	@Override
	protected Layer createLayer() {
		return new MyLayer();
	}

    class MyLayer extends Box2DLayer {
    	Body m_body;
    	Body m_bullet;
    	float m_x;
    	
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

				EdgeShape edge = EdgeShape.make();
				edge.setEndpoints(-10.0f, 0.0f, 10.0f, 0.0f);
				body.createFixture(edge, 0.0f);

				PolygonShape shape = PolygonShape.make();
				shape.setAsBox(0.2f, 1.0f, 0.5f, 1.0f, 0.0f);
				body.createFixture(shape, 0.0f);
			}
			
			{
				BodyDef bd = BodyDef.make();
				bd.setType(Body.TYPE_DYNAMIC);
				bd.setPosition(0.0f, 4.0f);

				PolygonShape box = PolygonShape.make();
				box.setAsBox(2.0f, 0.1f);

				m_body = mWorld.createBody(bd);
				m_body.createFixture(box, 1.0f);

				box.setAsBox(0.25f, 0.25f);

				m_x = 0.20352793f;
				bd.setPosition(m_x, 10.0f);
				bd.setBullet(true);

				m_bullet = mWorld.createBody(bd);
				m_bullet.createFixture(box, 100.0f);

				m_bullet.setLinearVelocity(WYPoint.make(0.0f, -50.0f));
				bd.destroy();
			}
			
			schedule(new TargetSelector(this, "update(float)", new Object[] { 0f }));
		}
		
		void Launch() {
			m_body.setTransform(0.0f, 4.0f, 0.0f);
			m_body.setLinearVelocity(WYPoint.makeZero());
			m_body.setAngularVelocity(0.0f);

			m_x = mRandom.nextFloat();
			m_bullet.setTransform(m_x, 10.0f, 0.0f);
			m_bullet.setLinearVelocity(WYPoint.make(0.0f, -50.0f));
			m_bullet.setAngularVelocity(0.0f);
		}
		
		@Override
		public void update(float delta) {
			super.update(delta);
			
			if(mStepCount % 60 == 0) {
				Launch();
			}
		}
    }
}
