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

import android.view.KeyEvent;

import com.wiyun.engine.WiEngineTestActivity;
import com.wiyun.engine.box2d.collision.EdgeShape;
import com.wiyun.engine.box2d.collision.PolygonShape;
import com.wiyun.engine.box2d.dynamics.Body;
import com.wiyun.engine.box2d.dynamics.BodyDef;
import com.wiyun.engine.box2d.dynamics.FixtureDef;
import com.wiyun.engine.box2d.dynamics.joints.PrismaticJointDef;
import com.wiyun.engine.box2d.dynamics.joints.RevoluteJointDef;
import com.wiyun.engine.nodes.Director;
import com.wiyun.engine.nodes.Label;
import com.wiyun.engine.nodes.Layer;
import com.wiyun.engine.types.WYPoint;
import com.wiyun.engine.types.WYSize;
import com.wiyun.engine.utils.TargetSelector;

public class BodyTypesTest extends WiEngineTestActivity {
	@Override
	protected Layer createLayer() {
		return new MyLayer();
	}

    class MyLayer extends Box2DLayer {
    	Body m_attachment;
    	Body m_platform;
    	float m_speed;
    	
		public MyLayer() {
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
				shape.setEndpoints(-20.0f, 0.0f, 20.0f, 0.0f);

				FixtureDef fd = FixtureDef.make();
				fd.setShape(shape);

				ground.createFixture(fd);
				fd.destroy();
			}
			
			// Define attachment
			{
				BodyDef bd = BodyDef.make();
				bd.setType(Body.TYPE_DYNAMIC);
				bd.setPosition(0.0f, 3.0f);
				m_attachment = mWorld.createBody(bd);
				bd.destroy();

				PolygonShape shape = PolygonShape.make();
				shape.setAsBox(0.5f, 2.0f);
				m_attachment.createFixture(shape, 2.0f);
			}
			
			// Define platform
			{
				BodyDef bd = BodyDef.make();
				bd.setType(Body.TYPE_DYNAMIC);
				bd.setPosition(-4.0f, 5.0f);
				m_platform = mWorld.createBody(bd);
				bd.destroy();

				PolygonShape shape = PolygonShape.make();
				shape.setAsBox(0.5f, 4.0f, 4.0f, 0.0f, 0.5f * (float)Math.PI);

				FixtureDef fd = FixtureDef.make();
				fd.setShape(shape);
				fd.setFriction(0.6f);
				fd.setDensity(2.0f);
				m_platform.createFixture(fd);
				fd.destroy();

				RevoluteJointDef rjd = RevoluteJointDef.make();
				rjd.initialize(m_attachment, m_platform, 0.0f, 5.0f);
				rjd.setMaxMotorTorque(50.0f);
				rjd.setEnableMotor(true);
				mWorld.createJoint(rjd);
				rjd.destroy();

				PrismaticJointDef pjd = PrismaticJointDef.make();
				pjd.initialize(ground, m_platform, 0.0f, 5.0f, 1.0f, 0.0f);
				pjd.setMaxMotorForce(1000.0f);
				pjd.setEnableMotor(true);
				pjd.setLowerTranslation(-10.0f);
				pjd.setUpperTranslation(10.0f);
				pjd.setEnableLimit(true);
				mWorld.createJoint(pjd);
				pjd.destroy();

				m_speed = 3.0f;
			}
			
			// Create a payload
			{
				BodyDef bd = BodyDef.make();
				bd.setType(Body.TYPE_DYNAMIC);
				bd.setPosition(0.0f, 8.0f);
				Body body = mWorld.createBody(bd);
				bd.destroy();

				PolygonShape shape = PolygonShape.make();
				shape.setAsBox(0.75f, 0.75f);

				FixtureDef fd = FixtureDef.make();
				fd.setShape(shape);
				fd.setFriction(0.6f);
				fd.setDensity(2.0f);
				body.createFixture(fd);
				fd.destroy();
			}
			
			// add a hint label
			Label label = Label.make("(Up)dynamic, (Left)static, (Right)kinematic",	14);
			label.setPosition(s.width / 2, s.height - 30);
			addChild(label);

			setKeyEnabled(true);
			
			schedule(new TargetSelector(this, "update(float)", new Object[] { 0f }));
		}
		
		@Override
		public void update(float delta) {
			// Drive the kinematic body.
			if (m_platform.getType() == Body.TYPE_DYNAMIC)
			{
				WYPoint p = m_platform.getTransform().p;
				WYPoint v = m_platform.getLinearVelocity();

				if ((p.x < -10.0f && v.x < 0.0f) ||
					(p.x > 10.0f && v.x > 0.0f))
				{
					v.x = -v.x;
					m_platform.setLinearVelocity(v);
				}
			}

			super.update(delta);
		}
		
		@Override
		public boolean wyKeyDown(KeyEvent event) {
			switch(event.getKeyCode()) {
				case KeyEvent.KEYCODE_DPAD_UP:
					m_platform.setType(Body.TYPE_DYNAMIC);
					break;
				case KeyEvent.KEYCODE_DPAD_LEFT:
					m_platform.setType(Body.TYPE_STATIC);
					break;
				case KeyEvent.KEYCODE_DPAD_RIGHT:
					m_platform.setType(Body.TYPE_KINEMATIC);
					m_platform.setLinearVelocity(WYPoint.make(-m_speed, 0.0f));
					m_speed = -m_speed;
					m_platform.setAngularVelocity(0.0f);
					break;
				default:
					return false;
			}

			return true;
		}
    }
}
