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
import com.wiyun.engine.box2d.collision.CircleShape;
import com.wiyun.engine.box2d.collision.EdgeShape;
import com.wiyun.engine.box2d.collision.PolygonShape;
import com.wiyun.engine.box2d.dynamics.Body;
import com.wiyun.engine.box2d.dynamics.BodyDef;
import com.wiyun.engine.box2d.dynamics.FixtureDef;
import com.wiyun.engine.box2d.dynamics.joints.RevoluteJointDef;
import com.wiyun.engine.box2d.dynamics.joints.WheelJoint;
import com.wiyun.engine.box2d.dynamics.joints.WheelJointDef;
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

public class CarTest extends WiEngineTestActivity {
	@Override
	protected Layer createLayer() {
		return new MyLayer();
	}

    class MyLayer extends Box2DLayer {
    	Body m_car;
    	Body m_wheel1;
    	Body m_wheel2;

    	float m_hz;
    	float m_zeta;
    	float m_speed;
    	WheelJoint m_spring1;
    	WheelJoint m_spring2;
    	
		public MyLayer() {
			WYSize s = Director.getInstance().getWindowSize();
			m_hz = 4.0f;
			m_zeta = 0.7f;
			m_speed = 50.0f;
			
			// set gravity
			mWorld.setGravity(0, -10);

			// place box2d to center of bottom edge
			mBox2D.setPosition(s.width / 2, 0);
			
			// create ground
			Body ground = null;
			{
				// create ground body
				BodyDef bd = BodyDef.make();
				ground = mWorld.createBody(bd);
				bd.destroy();

				// create ground shape
				EdgeShape shape = EdgeShape.make();
				FixtureDef fd = FixtureDef.make();
				fd.setShape(shape);
				fd.setDensity(0.0f);
				fd.setFriction(0.6f);
				shape.setEndpoints(-20.0f, 0.0f, 20.0f, 0.0f);
				ground.createFixture(fd);

				float[] hs = {0.25f, 1.0f, 4.0f, 0.0f, 0.0f, -1.0f, -2.0f, -2.0f, -1.25f, 0.0f};
				float x = 20.0f, y1 = 0.0f, dx = 5.0f;
				for (int i = 0; i < 10; ++i)
				{
					float y2 = hs[i];
					shape.setEndpoints(x, y1, x + dx, y2);
					ground.createFixture(fd);
					y1 = y2;
					x += dx;
				}
				for (int i = 0; i < 10; ++i)
				{
					float y2 = hs[i];
					shape.setEndpoints(x, y1, x + dx, y2);
					ground.createFixture(fd);
					y1 = y2;
					x += dx;
				}

				shape.setEndpoints(x, 0.0f, x + 40.0f, 0.0f);
				ground.createFixture(fd);

				x += 80.0f;
				shape.setEndpoints(x, 0.0f, x + 40.0f, 0.0f);
				ground.createFixture(fd);

				x += 40.0f;
				shape.setEndpoints(x, 0.0f, x + 10.0f, 5.0f);
				ground.createFixture(fd);

				x += 20.0f;
				shape.setEndpoints(x, 0.0f, x + 40.0f, 0.0f);
				ground.createFixture(fd);

				x += 40.0f;
				shape.setEndpoints(x, 0.0f, x, 20.0f);
				ground.createFixture(fd);
				
				fd.destroy();
			}
			
			// Teeter
			{
				BodyDef bd = BodyDef.make();
				bd.setPosition(140.0f, 1.0f);
				bd.setType(Body.TYPE_DYNAMIC);
				Body body = mWorld.createBody(bd);
				bd.destroy();

				PolygonShape box = PolygonShape.make();
				box.setAsBox(10.0f, 0.25f);
				body.createFixture(box, 1.0f);

				RevoluteJointDef jd = RevoluteJointDef.make();
				WYPoint pos = body.getPosition();
				jd.initialize(ground, body, pos.x, pos.y);
				jd.setLowerAngle(-8.0f * (float)Math.PI / 180.0f);
				jd.setUpperAngle(8.0f * (float)Math.PI / 180.0f);
				jd.setEnableLimit(true);
				mWorld.createJoint(jd);
				jd.destroy();
				
				body.applyAngularImpulse(100.0f);
			}
			
			// Bridge
			{
				int N = 20;
				PolygonShape shape = PolygonShape.make();
				shape.setAsBox(1.0f, 0.125f);

				FixtureDef fd = FixtureDef.make();
				fd.setShape(shape);
				fd.setDensity(1.0f);
				fd.setFriction(0.6f);

				RevoluteJointDef jd = RevoluteJointDef.make();

				BodyDef bd = BodyDef.make();
				bd.setType(Body.TYPE_DYNAMIC);
				Body prevBody = ground;
				for (int i = 0; i < N; ++i)
				{
					bd.setPosition(161.0f + 2.0f * i, -0.125f);
					Body body = mWorld.createBody(bd);
					body.createFixture(fd);

					jd.initialize(prevBody, body, 160.0f + 2.0f * i, -0.125f);
					mWorld.createJoint(jd);

					prevBody = body;
				}
				fd.destroy();
				bd.destroy();

				jd.initialize(prevBody, ground, 160.0f + 2.0f * N, -0.125f);
				mWorld.createJoint(jd);
				jd.destroy();
			}
			
			// Boxes
			{
				PolygonShape box = PolygonShape.make();
				box.setAsBox(0.5f, 0.5f);

				Body body = null;
				BodyDef bd = BodyDef.make();
				bd.setType(Body.TYPE_DYNAMIC);

				bd.setPosition(230.0f, 0.5f);
				body = mWorld.createBody(bd);
				body.createFixture(box, 0.5f);

				bd.setPosition(230.0f, 1.5f);
				body = mWorld.createBody(bd);
				body.createFixture(box, 0.5f);

				bd.setPosition(230.0f, 2.5f);
				body = mWorld.createBody(bd);
				body.createFixture(box, 0.5f);

				bd.setPosition(230.0f, 3.5f);
				body = mWorld.createBody(bd);
				body.createFixture(box, 0.5f);

				bd.setPosition(230.0f, 4.5f);
				body = mWorld.createBody(bd);
				body.createFixture(box, 0.5f);
				
				bd.destroy();
			}
			
			// Car
			{
				PolygonShape chassis = PolygonShape.make();
				WYPoint[] vertices = new WYPoint[6];
				vertices[0] = WYPoint.make(-1.5f, -0.5f);
				vertices[1] = WYPoint.make(1.5f, -0.5f);
				vertices[2] = WYPoint.make(1.5f, 0.0f);
				vertices[3] = WYPoint.make(0.0f, 0.9f);
				vertices[4] = WYPoint.make(-1.15f, 0.9f);
				vertices[5] = WYPoint.make(-1.5f, 0.2f);
				chassis.setVertices(vertices);

				CircleShape circle = CircleShape.make();
				circle.setRadius(0.4f);

				BodyDef bd = BodyDef.make();
				bd.setType(Body.TYPE_DYNAMIC);
				bd.setPosition(0.0f, 1.0f);
				m_car = mWorld.createBody(bd);
				m_car.createFixture(chassis, 1.0f);

				FixtureDef fd = FixtureDef.make();
				fd.setShape(circle);
				fd.setDensity(1.0f);
				fd.setFriction(0.9f);

				bd.setPosition(-1.0f, 0.35f);
				m_wheel1 = mWorld.createBody(bd);
				m_wheel1.createFixture(fd);

				bd.setPosition(1.0f, 0.4f);
				m_wheel2 = mWorld.createBody(bd);
				m_wheel2.createFixture(fd);

				WheelJointDef jd = WheelJointDef.make();
				WYPoint axis = WYPoint.make(0.0f, 1.0f);
				WYPoint w1Pos = m_wheel1.getPosition();
				WYPoint w2Pos = m_wheel2.getPosition();

				jd.initialize(m_car, m_wheel1, w1Pos.x, w1Pos.y, axis.x, axis.y);
				jd.setMotorSpeed(0.0f);
				jd.setMaxMotorTorque(20.0f);
				jd.setEnableMotor(true);
				jd.setFrequency(m_hz);
				jd.setDampingRatio(m_zeta);
				m_spring1 = WheelJoint.from(mWorld.createJoint(jd));

				jd.initialize(m_car, m_wheel2, w2Pos.x, w2Pos.y, axis.x, axis.y);
				jd.setMotorSpeed(0.0f);
				jd.setMaxMotorTorque(10.0f);
				jd.setEnableMotor(false);
				jd.setFrequency(m_hz);
				jd.setDampingRatio(m_zeta);
				m_spring2 = WheelJoint.from(mWorld.createJoint(jd));
				
				fd.destroy();
				bd.destroy();
				jd.destroy();
			}
			
			NinePatchSprite normal = NinePatchSprite.make(Texture2D.makePNG(R.drawable.btn_normal), WYRect.make(DP(9), DP(7), DP(22), DP(28)));
			NinePatchSprite pressed = NinePatchSprite.make(Texture2D.makePNG(R.drawable.btn_pressed), WYRect.make(DP(9), DP(7), DP(22), DP(28)));
			normal.setContentSize(DP(100), DP(44));
			pressed.setContentSize(DP(100), DP(44));
			Button button = Button.make(normal, pressed, null, null, this, "onBackward");
			button.setPosition(DP(55), s.height - DP(30));
			addChild(button, 1);
			
			// label for backward button
			BitmapFont font = BitmapFont.loadFont(R.raw.bitmapfont);
			BitmapFontLabel label = BitmapFontLabel.make(font, "Backward");
			label.setColor(WYColor3B.make(255, 255, 0));
			label.setPosition(DP(55), s.height - DP(30));
			addChild(label, 1);

			// stop button
			button = Button.make(normal, pressed, null, null, this, "onStop");
			button.setPosition(DP(160), s.height - DP(30));
			addChild(button, 1);

			// label for stop button
			label = BitmapFontLabel.make(font, "Stop");
			label.setColor(WYColor3B.make(255, 255, 0));
			label.setPosition(DP(160), s.height - DP(30));
			addChild(label, 1);

			// forward button
			button = Button.make(normal, pressed, null, null, this, "onForward");
			button.setPosition(DP(265), s.height - DP(30));
			addChild(button, 1);

			// label for forward button
			label = BitmapFontLabel.make(font, "Forward");
			label.setColor(WYColor3B.make(255, 255, 0));
			label.setPosition(DP(265), s.height - DP(30));
			addChild(label, 1);

			// freq. down button
			normal = NinePatchSprite.make(Texture2D.makePNG(R.drawable.btn_normal), WYRect.make(DP(9), DP(7), DP(22), DP(28)));
			pressed = NinePatchSprite.make(Texture2D.makePNG(R.drawable.btn_pressed), WYRect.make(DP(9), DP(7), DP(22), DP(28)));
			normal.setContentSize(DP(150), DP(44));
			pressed.setContentSize(DP(150), DP(44));
			button = Button.make(normal, pressed, null, null, this, "onFreqDown");
			button.setPosition(DP(80), s.height - DP(80));
			addChild(button, 1);

			// label for freq. down button
			label = BitmapFontLabel.make(font, "Freq. Down");
			label.setColor(WYColor3B.make(255, 255, 0));
			label.setPosition(DP(80), s.height - DP(80));
			addChild(label, 1);

			// freq. up button
			button = Button.make(normal, pressed, null, null, this, "onFreqUp");
			button.setPosition(DP(240), s.height - DP(80));
			addChild(button, 1);

			// label for freq. up button
			label = BitmapFontLabel.make(font, "Freq. Up");
			label.setColor(WYColor3B.make(255, 255, 0));
			label.setPosition(DP(240), s.height - DP(80));
			addChild(label, 1);

			schedule(new TargetSelector(this, "update(float)", new Object[] { 0f }));
		}
		
		public void onForward() {
			m_spring1.setMotorSpeed(-m_speed);
		}
		
		public void onBackward() {
			m_spring1.setMotorSpeed(m_speed);
		}
		
		public void onStop() {
			m_spring1.setMotorSpeed(0.0f);
		}
		
		public void onFreqDown() {
			m_hz = Math.max(0.0f, m_hz - 1.0f);
			m_spring1.setSpringFrequencyHz(m_hz);
			m_spring2.setSpringFrequencyHz(m_hz);
		}
		
		public void onFreqUp() {
			m_hz += 1.0f;
			m_spring1.setSpringFrequencyHz(m_hz);
			m_spring2.setSpringFrequencyHz(m_hz);
		}
		
		private float DP(float v) {
			return ResolutionIndependent.resolveDp(v);
		}
		
		public void update(float delta) {
			super.update(delta);
			
			// move the scene, keep the car center
			WYSize s = Director.getInstance().getWindowSize();
			WYPoint carPos = m_car.getPosition();
			float pX = mBox2D.meter2Pixel(carPos.x);
			mBox2D.setPosition(-pX + s.width / 2, ResolutionIndependent.resolveDp(100));
		}
    }
}
