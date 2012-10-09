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

import android.os.Bundle;
import android.view.KeyEvent;

import com.wiyun.engine.WiEngineTestActivity;
import com.wiyun.engine.box2d.collision.EdgeShape;
import com.wiyun.engine.box2d.collision.PolygonShape;
import com.wiyun.engine.box2d.dynamics.Body;
import com.wiyun.engine.box2d.dynamics.BodyDef;
import com.wiyun.engine.box2d.dynamics.joints.PrismaticJoint;
import com.wiyun.engine.box2d.dynamics.joints.PrismaticJointDef;
import com.wiyun.engine.box2d.dynamics.joints.RevoluteJoint;
import com.wiyun.engine.box2d.dynamics.joints.RevoluteJointDef;
import com.wiyun.engine.nodes.Director;
import com.wiyun.engine.nodes.Label;
import com.wiyun.engine.nodes.Layer;
import com.wiyun.engine.types.WYSize;
import com.wiyun.engine.utils.TargetSelector;

public class SliderCrankTest extends WiEngineTestActivity {
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        mGLSurfaceView.disableSystemHandleMenuKey();
    }
    
	@Override
	protected Layer createLayer() {
		return new MyLayer();
	}

    class MyLayer extends Box2DLayer {
    	RevoluteJoint m_joint1;
    	PrismaticJoint m_joint2;
    	
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
				shape.setEndpoints(-40.0f, 0.0f, 40.0f, 0.0f);
				ground.createFixture(shape, 0.0f);
			}

			{
				Body prevBody = ground;

				// Define crank.
				{
					PolygonShape shape = PolygonShape.make();
					shape.setAsBox(0.5f, 2.0f);

					BodyDef bd = BodyDef.make();
					bd.setType(Body.TYPE_DYNAMIC);
					bd.setPosition(0.0f, 7.0f);
					Body body = mWorld.createBody(bd);
					body.createFixture(shape, 2.0f);
					bd.destroy();

					RevoluteJointDef rjd = RevoluteJointDef.make();
					rjd.initialize(prevBody, body, 0.0f, 5.0f);
					rjd.setMotorSpeed(1.0f * (float)Math.PI);
					rjd.setMaxMotorTorque(10000.0f);
					rjd.setEnableMotor(true);
					m_joint1 = RevoluteJoint.from(mWorld.createJoint(rjd));
					rjd.destroy();

					prevBody = body;
				}

				// Define follower.
				{
					PolygonShape shape = PolygonShape.make();
					shape.setAsBox(0.5f, 4.0f);

					BodyDef bd = BodyDef.make();
					bd.setType(Body.TYPE_DYNAMIC);
					bd.setPosition(0.0f, 13.0f);
					Body body = mWorld.createBody(bd);
					body.createFixture(shape, 2.0f);
					bd.destroy();

					RevoluteJointDef rjd = RevoluteJointDef.make();
					rjd.initialize(prevBody, body, 0.0f, 9.0f);
					rjd.setEnableMotor(false);
					mWorld.createJoint(rjd);
					rjd.destroy();

					prevBody = body;
				}

				// Define piston
				{
					PolygonShape shape = PolygonShape.make();
					shape.setAsBox(1.5f, 1.5f);

					BodyDef bd = BodyDef.make();
					bd.setType(Body.TYPE_DYNAMIC);
					bd.setFixedRotation(true);
					bd.setPosition(0.0f, 17.0f);
					Body body = mWorld.createBody(bd);
					body.createFixture(shape, 2.0f);
					bd.destroy();

					RevoluteJointDef rjd = RevoluteJointDef.make();
					rjd.initialize(prevBody, body, 0.0f, 17.0f);
					mWorld.createJoint(rjd);
					rjd.destroy();

					PrismaticJointDef pjd = PrismaticJointDef.make();
					pjd.initialize(ground, body, 0.0f, 17.0f, 0.0f, 1.0f);
					pjd.setMaxMotorForce(1000.0f);
					pjd.setEnableMotor(true);
					m_joint2 = PrismaticJoint.from(mWorld.createJoint(pjd));
					pjd.destroy();
				}

				// Create a payload
				{
					PolygonShape shape = PolygonShape.make();
					shape.setAsBox(1.5f, 1.5f);

					BodyDef bd = BodyDef.make();
					bd.setType(Body.TYPE_DYNAMIC);
					bd.setPosition(0.0f, 23.0f);
					Body body = mWorld.createBody(bd);
					body.createFixture(shape, 2.0f);
				}
			}

			// add a hint label
			Label label = Label.make("(Menu)Toggle friction, (Search)Toggle motor", 14);
			label.setPosition(s.width / 2, s.height - 30);
			addChild(label);

			setKeyEnabled(true);
			
			schedule(new TargetSelector(this, "update(float)", new Object[] { 0f }));
		}
		
		@Override
		public boolean wyKeyDown(KeyEvent event) {
			switch(event.getKeyCode()) {
				case KeyEvent.KEYCODE_MENU:
					m_joint2.enableMotor(!m_joint2.isMotorEnabled());
					m_joint2.getBodyB().setAwake(true);
					break;
				case KeyEvent.KEYCODE_SEARCH:
					m_joint1.enableMotor(!m_joint1.isMotorEnabled());
					m_joint1.getBodyB().setAwake(true);
					break;
				default:
					return false;
			}

			return true;
		}
    }
}
