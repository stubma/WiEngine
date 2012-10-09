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
import com.wiyun.engine.box2d.dynamics.ContactImpulse;
import com.wiyun.engine.box2d.dynamics.Fixture;
import com.wiyun.engine.box2d.dynamics.World.IContactListener;
import com.wiyun.engine.box2d.dynamics.contacts.Contact;
import com.wiyun.engine.nodes.Director;
import com.wiyun.engine.nodes.Layer;
import com.wiyun.engine.types.WYPoint;
import com.wiyun.engine.types.WYSize;
import com.wiyun.engine.utils.TargetSelector;

public class BreakableTest extends WiEngineTestActivity {
	@Override
	protected Layer createLayer() {
		return new MyLayer();
	}
    
    class MyLayer extends Box2DLayer implements IContactListener {
    	Body m_body1;
    	WYPoint m_velocity = WYPoint.makeZero();
    	float m_angularVelocity;
    	PolygonShape m_shape1 = PolygonShape.make();
    	PolygonShape m_shape2 = PolygonShape.make();
    	Fixture m_piece1;
    	Fixture m_piece2;

    	boolean m_broke;
    	boolean m_break;
    	
		public MyLayer() {
			WYSize s = Director.getInstance().getWindowSize();
			
			// place box2d to center of bottom edge
			mBox2D.setPosition(s.width / 2, 0);
			
			// set gravity
			mWorld.setGravity(0, -10);
			
			// set contact listener
			mWorld.setContactListener(this);
			
			// Ground body
			{
				BodyDef bd = BodyDef.make();
				Body ground = mWorld.createBody(bd);
				bd.destroy();

				EdgeShape shape = EdgeShape.make();
				shape.setEndpoints(-40.0f, 0.0f, 40.0f, 0.0f);
				ground.createFixture(shape, 0.0f);
			}

			// Breakable dynamic body
			{
				BodyDef bd = BodyDef.make();
				bd.setType(Body.TYPE_DYNAMIC);
				bd.setPosition(0, mBox2D.pixel2Meter(s.height));
				bd.setAngle(0.25f * (float)Math.PI);
				m_body1 = mWorld.createBody(bd);
				bd.destroy();

				m_shape1.setAsBox(0.5f, 0.5f, -0.5f, 0.0f, 0.0f);
				m_piece1 = m_body1.createFixture(m_shape1, 1.0f);

				m_shape2.setAsBox(0.5f, 0.5f, 0.5f, 0.0f, 0.0f);
				m_piece2 = m_body1.createFixture(m_shape2, 1.0f);
			}

			m_break = false;
			m_broke = false;
			
			schedule(new TargetSelector(this, "update(float)", new Object[] { 0f }));
		}
		
		void Break() {
			// Create two bodies from one.
			Body body1 = m_piece1.getBody();
			WYPoint center = body1.getWorldCenter();

			body1.destroyFixture(m_piece2);
			m_piece2 = null;

			BodyDef bd = BodyDef.make();
			bd.setType(Body.TYPE_DYNAMIC);
			bd.setPosition(body1.getPosition());
			bd.setAngle(body1.getAngle());

			Body body2 = mWorld.createBody(bd);
			bd.destroy();
			m_piece2 = body2.createFixture(m_shape2, 1.0f);

			// Compute consistent velocities for new bodies based on
			// cached velocity.
			WYPoint center1 = body1.getWorldCenter();
			WYPoint center2 = body2.getWorldCenter();

			WYPoint velocity1 = WYPoint.add(m_velocity, WYPoint.cross(m_angularVelocity, WYPoint.sub(center1, center)));
			WYPoint velocity2 = WYPoint.add(m_velocity, WYPoint.cross(m_angularVelocity, WYPoint.sub(center2, center)));

			body1.setAngularVelocity(m_angularVelocity);
			body1.setLinearVelocity(velocity1);

			body2.setAngularVelocity(m_angularVelocity);
			body2.setLinearVelocity(velocity2);
		}
		
		@Override
		public void update(float delta) {
			if(m_break) {
				Break();
				m_broke = true;
				m_break = false;
			}

			// Cache velocities to improve movement on breakage.
			if(m_broke == false) {
				m_velocity = m_body1.getLinearVelocity();
				m_angularVelocity = m_body1.getAngularVelocity();
			}
			
			super.update(delta);
		}

		public void beginContact(int contactPointer) {
		}

		public void endContact(int contactPointer) {
		}

		public void postSolve(int contactPointer, int impulsePointer) {
			if(m_broke) {
				// The body already broke.
				return;
			}

			// Should the body break?
			Contact contact = Contact.from(contactPointer);
			int count = contact.getManifold().getPointCount();

			ContactImpulse impulse = ContactImpulse.from(impulsePointer);
			float maxImpulse = 0.0f;
			for(int i = 0; i < count; ++i) {
				maxImpulse = Math.max(maxImpulse, impulse.getNormalImpulse(i));
			}

			if(maxImpulse > 40.0f) {
				// Flag the body for breaking.
				m_break = true;
			}
		}

		public void preSolve(int contactPointer, int oldManifoldPointer) {
		}
    }
}
