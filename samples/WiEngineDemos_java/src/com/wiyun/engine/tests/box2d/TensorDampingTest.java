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

import com.wiyun.engine.R;
import com.wiyun.engine.WiEngineTestActivity;
import com.wiyun.engine.box2d.collision.PolygonShape;
import com.wiyun.engine.box2d.common.Transform;
import com.wiyun.engine.box2d.controllers.TensorDampingController;
import com.wiyun.engine.box2d.controllers.TensorDampingControllerDef;
import com.wiyun.engine.box2d.dynamics.Body;
import com.wiyun.engine.box2d.dynamics.BodyDef;
import com.wiyun.engine.box2d.dynamics.FixtureDef;
import com.wiyun.engine.box2d.dynamics.joints.PrismaticJointDef;
import com.wiyun.engine.box2d.dynamics.joints.RevoluteJoint;
import com.wiyun.engine.box2d.dynamics.joints.RevoluteJointDef;
import com.wiyun.engine.nodes.BitmapFontLabel;
import com.wiyun.engine.nodes.Button;
import com.wiyun.engine.nodes.Director;
import com.wiyun.engine.nodes.Layer;
import com.wiyun.engine.nodes.NinePatchSprite;
import com.wiyun.engine.opengl.Texture2D;
import com.wiyun.engine.types.WYColor3B;
import com.wiyun.engine.types.WYPoint;
import com.wiyun.engine.types.WYRect;
import com.wiyun.engine.types.WYSize;
import com.wiyun.engine.utils.BitmapFont;
import com.wiyun.engine.utils.ResolutionIndependent;
import com.wiyun.engine.utils.TargetSelector;

public class TensorDampingTest extends WiEngineTestActivity {
	@Override
	protected Layer createLayer() {
		return new MyLayer();
	}

	// control variables
	static float HORSEPOWER = 40;
	static float SIDEWAY_FRICTION_FORCE = 10;
	static float STEER_SPEED = 1.5f;
	static float MAX_STEER_ANGLE = (float)Math.PI / 3;
	
    class MyLayer extends Box2DLayer {
    	Body m_car;
    	Body m_leftRearWheel;
    	Body m_leftFrontWheel;
    	Body m_rightRearWheel;
    	Body m_rightFrontWheel;
    	RevoluteJoint m_leftJoint;
    	RevoluteJoint m_rightJoint;

    	float m_engineSpeed;
    	float m_steeringAngle;

		public MyLayer() {
			WYSize s = Director.getInstance().getWindowSize();
		
			// don't draw solid
			mWorld.setNoSolidDraw(true);
			
			// init
			m_engineSpeed = 0;
			m_steeringAngle = 0;
			
			// position
			WYPoint carPos = WYPoint.make(10, 10);
			WYPoint leftRearPos = WYPoint.make(-1.5f, -1.9f);
			WYPoint rightRearPos = WYPoint.make(1.5f, -1.9f);
			WYPoint leftFrontPos = WYPoint.make(-1.5f, 1.9f);
			WYPoint rightFrontPos = WYPoint.make(1.5f, 1.9f);

			// create controller for wheel
			TensorDampingControllerDef cd = TensorDampingControllerDef.make();
			cd.setAxisAligned(10, 5);
			TensorDampingController tdc = TensorDampingController.from(mWorld.createController(cd));
			cd.destroy();
			
			// car
			{
				BodyDef bd = BodyDef.make();
				bd.setLinearDamping(1);
				bd.setAngularDamping(1);
				bd.setType(Body.TYPE_DYNAMIC);
				bd.setPosition(carPos);
				m_car = mWorld.createBody(bd);
				bd.destroy();

				PolygonShape shape = PolygonShape.make();
				shape.setAsBox(1.5f, 2.5f);
				FixtureDef fd = FixtureDef.make();
				fd.setShape(shape);
				fd.setDensity(1);
				m_car.createFixture(fd);
				fd.destroy();
			}

			// left-rear wheel
			{
				BodyDef bd = BodyDef.make();
				bd.setType(Body.TYPE_DYNAMIC);
				bd.setPosition(WYPoint.add(carPos, leftRearPos));
				m_leftRearWheel = mWorld.createBody(bd);
				bd.destroy();

				PolygonShape shape = PolygonShape.make();
				shape.setAsBox(0.2f, 0.5f);
				FixtureDef fd = FixtureDef.make();
				fd.setShape(shape);
				fd.setDensity(1);
				m_leftRearWheel.createFixture(fd);
				fd.destroy();
				
				PrismaticJointDef jd = PrismaticJointDef.make();
				jd.initialize(m_car, m_leftRearWheel, m_leftRearWheel.getWorldCenter().x, m_leftRearWheel.getWorldCenter().y, 1, 0);
				jd.setEnableLimit(true);
				jd.setLowerTranslation(0);
				jd.setUpperTranslation(0);
				mWorld.createJoint(jd);
				jd.destroy();

				tdc.addBody(m_leftRearWheel);
			}

			// right-rear wheel
			{
				BodyDef bd = BodyDef.make();
				bd.setType(Body.TYPE_DYNAMIC);
				bd.setPosition(WYPoint.add(carPos, rightRearPos));
				m_rightRearWheel = mWorld.createBody(bd);
				bd.destroy();

				PolygonShape shape = PolygonShape.make();
				shape.setAsBox(0.2f, 0.5f);
				FixtureDef fd = FixtureDef.make();
				fd.setShape(shape);
				fd.setDensity(1);
				m_rightRearWheel.createFixture(fd);
				fd.destroy();

				PrismaticJointDef jd = PrismaticJointDef.make();
				jd.initialize(m_car, m_rightRearWheel, m_rightRearWheel.getWorldCenter().x, m_rightRearWheel.getWorldCenter().y, 1, 0);
				jd.setEnableLimit(true);
				jd.setLowerTranslation(0);
				jd.setUpperTranslation(0);
				mWorld.createJoint(jd);
				jd.destroy();

				tdc.addBody(m_rightRearWheel);
			}

			// left-front wheel
			{
				BodyDef bd = BodyDef.make();
				bd.setType(Body.TYPE_DYNAMIC);
				bd.setPosition(WYPoint.add(carPos, leftFrontPos));
				m_leftFrontWheel = mWorld.createBody(bd);
				bd.destroy();

				PolygonShape shape = PolygonShape.make();
				shape.setAsBox(0.2f, 0.5f);
				FixtureDef fd = FixtureDef.make();
				fd.setShape(shape);
				fd.setDensity(1);
				m_leftFrontWheel.createFixture(fd);
				fd.destroy();

				RevoluteJointDef jd = RevoluteJointDef.make();
				jd.initialize(m_car, m_leftFrontWheel, m_leftFrontWheel.getWorldCenter().x, m_leftFrontWheel.getWorldCenter().y);
				jd.setEnableMotor(true);
				jd.setMaxMotorTorque(100);
				m_leftJoint = RevoluteJoint.from(mWorld.createJoint(jd));
				jd.destroy();

				tdc.addBody(m_leftFrontWheel);
			}

			// right-front wheel
			{
				BodyDef bd = BodyDef.make();
				bd.setType(Body.TYPE_DYNAMIC);
				bd.setPosition(WYPoint.add(carPos, rightFrontPos));
				m_rightFrontWheel = mWorld.createBody(bd);
				bd.destroy();

				PolygonShape shape = PolygonShape.make();
				shape.setAsBox(0.2f, 0.5f);
				FixtureDef fd = FixtureDef.make();
				fd.setShape(shape);
				fd.setDensity(1);
				m_rightFrontWheel.createFixture(fd);
				fd.destroy();

				RevoluteJointDef jd = RevoluteJointDef.make();
				jd.initialize(m_car, m_rightFrontWheel, m_rightFrontWheel.getWorldCenter().x, m_rightFrontWheel.getWorldCenter().y);
				jd.setEnableMotor(true);
				jd.setMaxMotorTorque(100);
				m_rightJoint = RevoluteJoint.from(mWorld.createJoint(jd));
				jd.destroy();

				tdc.addBody(m_rightFrontWheel);
			}
			
			// left button
			NinePatchSprite normal = NinePatchSprite.make(Texture2D.makePNG(R.drawable.btn_normal), WYRect.make(DP(9), DP(7), DP(22), DP(28)));
			NinePatchSprite pressed = NinePatchSprite.make(Texture2D.makePNG(R.drawable.btn_pressed), WYRect.make(DP(9), DP(7), DP(22), DP(28)));
			normal.setContentSize(DP(80), DP(44));
			pressed.setContentSize(DP(80), DP(44));
			Button button = Button.make(normal, pressed, null, null, new TargetSelector(this, "onLeftPressed", null), new TargetSelector(this, "onLeftReleased", null));
			button.setPosition(DP(40), s.height - DP(30));
			addChild(button, 1);
			
			// label for left button
			BitmapFont font = BitmapFont.loadFont(R.raw.bitmapfont);
			BitmapFontLabel label = BitmapFontLabel.make(font, "Left");
			label.setColor(WYColor3B.make(255, 255, 0));
			label.setPosition(DP(40), s.height - DP(30));
			addChild(label, 1);

			// up button
			button = Button.make(normal, pressed, null, null, new TargetSelector(this, "onUpPressed", null), new TargetSelector(this, "onUpReleased", null));
			button.setPosition(DP(120), s.height - DP(30));
			addChild(button, 1);

			// label for up button
			label = BitmapFontLabel.make(font, "Forward");
			label.setColor(WYColor3B.make(255, 255, 0));
			label.setPosition(DP(120), s.height - DP(30));
			addChild(label, 1);

			// down button
			button = Button.make(normal, pressed, null, null, new TargetSelector(this, "onDownPressed", null), new TargetSelector(this, "onDownReleased", null));
			button.setPosition(DP(200), s.height - DP(30));
			addChild(button, 1);

			// label for down button
			label = BitmapFontLabel.make(font, "Back");
			label.setColor(WYColor3B.make(255, 255, 0));
			label.setPosition(DP(200), s.height - DP(30));
			addChild(label, 1);
			
			// right button
			button = Button.make(normal, pressed, null, null, new TargetSelector(this, "onRightPressed", null), new TargetSelector(this, "onRightReleased", null));
			button.setPosition(DP(280), s.height - DP(30));
			addChild(button, 1);

			// label for right button
			label = BitmapFontLabel.make(font, "Right");
			label.setColor(WYColor3B.make(255, 255, 0));
			label.setPosition(DP(280), s.height - DP(30));
			addChild(label, 1);

			schedule(new TargetSelector(this, "update(float)", new Object[] { 0f }));
		}
		
		public void onLeftPressed() {
			m_steeringAngle = MAX_STEER_ANGLE;
		}
		
		public void onLeftReleased() {
			m_steeringAngle = 0;
		}
		
		public void onRightPressed() {
			m_steeringAngle = -MAX_STEER_ANGLE;
		}
		
		public void onRightReleased() {
			m_steeringAngle = 0;
		}
		
		public void onUpPressed() {
			m_car.setAwake(false);
			m_engineSpeed = HORSEPOWER;
		}
		
		public void onUpReleased() {
			m_engineSpeed = 0;
		}
		
		public void onDownPressed() {
			m_engineSpeed = -HORSEPOWER;
		}
		
		public void onDownReleased() {
			m_engineSpeed = 0;
		}
		
		private float DP(float v) {
			return ResolutionIndependent.resolveDp(v);
		}
		
		public void update(float delta) {
			super.update(delta);
			
			// driving
			Transform t = m_leftFrontWheel.getTransform();
			WYPoint ldirection = WYPoint.make(-t.q.s, t.q.c);
			ldirection = WYPoint.mul(ldirection, m_engineSpeed);
			t = m_rightFrontWheel.getTransform();
			WYPoint rdirection = WYPoint.make(-t.q.s, t.q.c);
			rdirection = WYPoint.mul(rdirection, m_engineSpeed);
			m_leftFrontWheel.applyForce(ldirection, m_leftFrontWheel.getPosition());
			m_rightFrontWheel.applyForce(rdirection, m_rightFrontWheel.getPosition());

			// steering
			float mspeed = m_steeringAngle - m_leftJoint.getJointAngle();
			m_leftJoint.setMotorSpeed(mspeed * STEER_SPEED);
			mspeed = m_steeringAngle - m_rightJoint.getJointAngle();
			m_rightJoint.setMotorSpeed(mspeed * STEER_SPEED);
		}
    }
}
