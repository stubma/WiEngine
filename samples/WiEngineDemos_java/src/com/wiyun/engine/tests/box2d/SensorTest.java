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
import com.wiyun.engine.box2d.dynamics.Body;
import com.wiyun.engine.box2d.dynamics.BodyDef;
import com.wiyun.engine.box2d.dynamics.Fixture;
import com.wiyun.engine.box2d.dynamics.FixtureDef;
import com.wiyun.engine.box2d.dynamics.World.IContactListener;
import com.wiyun.engine.box2d.dynamics.contacts.Contact;
import com.wiyun.engine.nodes.Director;
import com.wiyun.engine.nodes.Layer;
import com.wiyun.engine.types.WYPoint;
import com.wiyun.engine.types.WYSize;
import com.wiyun.engine.utils.TargetSelector;

public class SensorTest extends WiEngineTestActivity {
	@Override
	protected Layer createLayer() {
		return new MyLayer();
	}
	
    class MyLayer extends Box2DLayer implements IContactListener {
    	int e_count = 7;
    	Fixture m_sensor;
    	Body[] m_bodies = new Body[e_count];
    	boolean[] m_touching = new boolean[e_count];
    	
		public MyLayer() {
			WYSize s = Director.getInstance().getWindowSize();
			
			// set gravity
			mWorld.setGravity(0, -10);

			// place box2d to center of bottom edge
			mBox2D.setPosition(s.width / 2, 0);
			
			// add contact listener
			mWorld.setContactListener(this);
			
			{
				BodyDef bd = BodyDef.make();
				Body ground = mWorld.createBody(bd);
				bd.destroy();

				{
					EdgeShape shape = EdgeShape.make();
					shape.setEndpoints(-40.0f, 0.0f, 40.0f, 0.0f);
					ground.createFixture(shape, 0.0f);
				}

				{
					CircleShape shape = CircleShape.make();
					shape.setRadius(5.0f);
					shape.setPosition(0.0f, 10.0f);

					FixtureDef fd = FixtureDef.make();
					fd.setShape(shape);
					fd.setSensor(true);
					m_sensor = ground.createFixture(fd);
					fd.destroy();
				}
			}

			{
				CircleShape shape = CircleShape.make();
				shape.setRadius(1.0f);

				for (int i = 0; i < e_count; ++i)
				{
					BodyDef bd = BodyDef.make();
					bd.setType(Body.TYPE_DYNAMIC);
					bd.setPosition(-10.0f + 3.0f * i, 20.0f);
					bd.setUserData(i);

					m_touching[i] = false;
					m_bodies[i] = mWorld.createBody(bd);

					m_bodies[i].createFixture(shape, 1.0f);
					bd.destroy();
				}
			}
			
			schedule(new TargetSelector(this, "update(float)", new Object[] { 0f }));
		}

		public void beginContact(int contactPointer) {
			Contact contact = Contact.from(contactPointer);
			Fixture fixtureA = contact.getFixtureA();
			Fixture fixtureB = contact.getFixtureB();

			if (fixtureA.equals(m_sensor))
			{
				int i = (Integer)fixtureB.getBody().getUserData();
				m_touching[i] = true;
			}

			if (fixtureB.equals(m_sensor))
			{
				int i = (Integer)fixtureA.getBody().getUserData();
				m_touching[i] = true;
			}
        }

		public void endContact(int contactPointer) {
			Contact contact = Contact.from(contactPointer);
			Fixture fixtureA = contact.getFixtureA();
			Fixture fixtureB = contact.getFixtureB();

			if (fixtureA.equals(m_sensor))
			{
				int i = (Integer)fixtureB.getBody().getUserData();
				m_touching[i] = false;
			}

			if (fixtureB.equals(m_sensor))
			{
				int i = (Integer)fixtureA.getBody().getUserData();
				m_touching[i] = false;
			}
        }

		public void postSolve(int contactPointer, int impulsePointer) {
        }

		public void preSolve(int contactPointer, int oldManifoldPointer) {
        }
		
		@Override
		public void update(float delta) {
		    super.update(delta);
		    
			// Traverse the contact results. Apply a force on shapes
			// that overlap the sensor.
			for (int i = 0; i < e_count; ++i)
			{
				if (m_touching[i] == false)
				{
					continue;
				}

				Body body = m_bodies[i];
				Body ground = m_sensor.getBody();

				CircleShape circle = CircleShape.from(m_sensor.getShape());
				WYPoint center = ground.getWorldPoint(circle.getPosition());

				WYPoint position = body.getPosition();

				WYPoint d = WYPoint.sub(center, position);
				if (WYPoint.lengthsq(d) < Math.E * Math.E)
				{
					continue;
				}

				d = WYPoint.normalize(d);
				WYPoint F = WYPoint.mul(d, 100.f);
				body.applyForce(F, position);
			}
		}
    }
}
