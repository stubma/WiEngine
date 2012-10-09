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
import com.wiyun.engine.box2d.Settings;
import com.wiyun.engine.box2d.collision.CircleShape;
import com.wiyun.engine.box2d.collision.EdgeShape;
import com.wiyun.engine.box2d.collision.PolygonShape;
import com.wiyun.engine.box2d.dynamics.Body;
import com.wiyun.engine.box2d.dynamics.BodyDef;
import com.wiyun.engine.box2d.dynamics.Fixture;
import com.wiyun.engine.box2d.dynamics.World.IContactListener;
import com.wiyun.engine.box2d.dynamics.contacts.Contact;
import com.wiyun.engine.nodes.Director;
import com.wiyun.engine.nodes.Label;
import com.wiyun.engine.nodes.Layer;
import com.wiyun.engine.types.WYPoint;
import com.wiyun.engine.types.WYSize;
import com.wiyun.engine.utils.TargetSelector;

public class OneWayTest extends WiEngineTestActivity {
	@Override
	protected Layer createLayer() {
		return new MyLayer();
	}

    class MyLayer extends Box2DLayer implements IContactListener {
    	int e_unknown = 0;
    	int e_above = 1;
    	int e_below = 2;

    	float m_radius, m_top, m_bottom;
    	int m_state;
    	Fixture m_platform;
    	Fixture m_character;
    	
		public MyLayer() {
			WYSize s = Director.getInstance().getWindowSize();
			
			// set gravity
			mWorld.setGravity(0, -10);

			// place box2d to center of bottom edge
			mBox2D.setPosition(s.width / 2, 0);
			
			// add contact listener
			mWorld.setContactListener(this);
			
			// Ground
			{
				BodyDef bd = BodyDef.make();
				Body ground = mWorld.createBody(bd);
				bd.destroy();

				EdgeShape shape = EdgeShape.make();
				shape.setEndpoints(-20.0f, 0.0f, 20.0f, 0.0f);
				ground.createFixture(shape, 0.0f);
			}

			// Platform
			{
				BodyDef bd = BodyDef.make();
				bd.setPosition(0.0f, 10.0f);
				Body body = mWorld.createBody(bd);
				bd.destroy();

				PolygonShape shape = PolygonShape.make();
				shape.setAsBox(3.0f, 0.5f);
				m_platform = body.createFixture(shape, 0.0f);

				m_bottom = 10.0f - 0.5f;
				m_top = 10.0f + 0.5f;
			}

			// Actor
			{
				BodyDef bd = BodyDef.make();
				bd.setType(Body.TYPE_DYNAMIC);
				bd.setPosition(0.0f, 12.0f);
				Body body = mWorld.createBody(bd);
				bd.destroy();

				m_radius = 0.5f;
				CircleShape shape = CircleShape.make();
				shape.setRadius(m_radius);
				m_character = body.createFixture(shape, 20.0f);

				body.setLinearVelocity(WYPoint.make(0.0f, -50.0f));

				m_state = e_unknown;
			}

			// add a hint label
			Label label = Label.make("try drag ball through platform",
					14);
			label.setPosition(s.width / 2, s.height - 30);
			addChild(label);
			
			schedule(new TargetSelector(this, "update(float)", new Object[] { 0f }));
		}

		public void beginContact(int contactPointer) {
        }

		public void endContact(int contactPointer) {
        }

		public void postSolve(int contactPointer, int impulsePointer) {
        }

		public void preSolve(int contactPointer, int oldManifoldPointer) {
			Contact contact = Contact.from(contactPointer);
			Fixture fixtureA = contact.getFixtureA();
			Fixture fixtureB = contact.getFixtureB();

			if(!fixtureA.equals(m_platform) && !fixtureA.equals(m_character)) {
				return;
			}

			if(!fixtureB.equals(m_platform) && !fixtureB.equals(m_character)) {
				return;
			}

			WYPoint position = m_character.getBody().getPosition();

			if(position.y < m_top + m_radius - 3.0f * Settings.linearSlop) {
				contact.setEnabled(false);
			}
        }
    }
}
