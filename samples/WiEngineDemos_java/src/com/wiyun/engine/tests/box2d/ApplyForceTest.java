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
import com.wiyun.engine.box2d.common.Transform;
import com.wiyun.engine.box2d.dynamics.Body;
import com.wiyun.engine.box2d.dynamics.BodyDef;
import com.wiyun.engine.box2d.dynamics.FixtureDef;
import com.wiyun.engine.box2d.dynamics.joints.FrictionJointDef;
import com.wiyun.engine.nodes.Director;
import com.wiyun.engine.nodes.Label;
import com.wiyun.engine.nodes.Layer;
import com.wiyun.engine.types.WYPoint;
import com.wiyun.engine.types.WYSize;
import com.wiyun.engine.utils.TargetSelector;

public class ApplyForceTest extends WiEngineTestActivity {
	@Override
	protected Layer createLayer() {
		return new MyLayer();
	}

    class MyLayer extends Box2DLayer {
    	Body mBody;
    	
		public MyLayer() {
			// place box2d to center of bottom edge
			WYSize s = Director.getInstance().getWindowSize();
			mBox2D.setPosition(s.width / 2, 0);
			
			float k_restitution = 0.4f;
			Body ground = null;
			{
				BodyDef bd = BodyDef.make();
				ground = mWorld.createBody(bd);

				EdgeShape shape = EdgeShape.make();

				FixtureDef sd = FixtureDef.make();
				sd.setShape(shape);
				sd.setDensity(0);
				sd.setRestitution(k_restitution);

				// Left vertical
				shape.setEndpoints(-10.0f, 0.0f,
						-10.0f, mBox2D.pixel2Meter(s.height));
				ground.createFixture(sd);

				// Right vertical
				shape.setEndpoints(10.0f, 0.0f,
						10.0f, mBox2D.pixel2Meter(s.height));
				ground.createFixture(sd);

				// Top horizontal
				shape.setEndpoints(-10.0f, mBox2D.pixel2Meter(s.height),
						10.0f, mBox2D.pixel2Meter(s.height));
				ground.createFixture(sd);

				// Bottom horizontal
				shape.setEndpoints(-10.0f, 0.0f, 10.0f, 0.0f);
				ground.createFixture(sd);
			}
			
			{
				Transform xf1 = Transform.make();
				xf1.q.set(0.3524f * (float)Math.PI);
				xf1.p = xf1.q.mul(WYPoint.make(1.0f, 0.0f));

				WYPoint[] vertices = new WYPoint[3];
				vertices[0] = xf1.mul(WYPoint.make(-1.0f, 0.0f));
				vertices[1] = xf1.mul(WYPoint.make(1.0f, 0.0f));
				vertices[2] = xf1.mul(WYPoint.make(0.0f, 0.5f));

				PolygonShape poly1 = PolygonShape.make();
				poly1.setVertices(vertices);

				FixtureDef sd1 = FixtureDef.make();
				sd1.setShape(poly1);
				sd1.setDensity(4.0f);

				Transform xf2 = Transform.make();
				xf2.q.set(-0.3524f * (float)Math.PI);
				xf2.p = xf2.q.mul(WYPoint.make(-1.0f, 0.0f));

				vertices[0] = xf2.mul(WYPoint.make(-1.0f, 0.0f));
				vertices[1] = xf2.mul(WYPoint.make(1.0f, 0.0f));
				vertices[2] = xf2.mul(WYPoint.make(0.0f, 0.5f));

				PolygonShape poly2 = PolygonShape.make();
				poly2.setVertices(vertices);

				FixtureDef sd2 = FixtureDef.make();
				sd2.setShape(poly2);
				sd2.setDensity(2.0f);

				BodyDef bd = BodyDef.make();
				bd.setType(Body.TYPE_DYNAMIC);
				bd.setAngularDamping(5.0f);
				bd.setLinearDamping(0.1f);
				bd.setPosition(0.0f, 2.0f);
				bd.setAngle((float)Math.PI);
				bd.setAllowSleep(false);
				mBody = mWorld.createBody(bd);
				bd.destroy();
				
				mBody.createFixture(sd1);
				mBody.createFixture(sd2);
				sd1.destroy();
				sd2.destroy();
			}
			
			{
				PolygonShape shape = PolygonShape.make();
				shape.setAsBox(0.5f, 0.5f);

				FixtureDef fd = FixtureDef.make();
				fd.setShape(shape);
				fd.setDensity(1.0f);
				fd.setFriction(0.3f);

				for (int i = 0; i < 10; ++i)
				{
					BodyDef bd = BodyDef.make();
					bd.setType(Body.TYPE_DYNAMIC);

					bd.setPosition(0.0f, 5.0f + 1.54f * i);
					Body body = mWorld.createBody(bd);

					body.createFixture(fd);

					float gravity = 10.0f;
					float I = body.getInertia();
					float mass = body.getMass();

					// For a circle: I = 0.5 * m * r * r ==> r = sqrt(2 * I / m)
					float radius = (float)Math.sqrt(2.0f * I / mass);

					FrictionJointDef jd = FrictionJointDef.make();
					jd.setLocalAnchorA(0, 0);
					jd.setLocalAnchorB(0, 0);
					jd.setBodyA(ground);
					jd.setBodyB(body);
					jd.setCollideConnected(true);
					jd.setMaxForce(mass * gravity);
					jd.setMaxTorque(mass * radius * gravity);

					mWorld.createJoint(jd);
					jd.destroy();
					
					bd.destroy();
				}
				
				fd.destroy();
			}
			
			// add a hint label
			Label label = Label.make("(Up)Speed, (Left)Turn Left, (Right)Turn Right", 14);
			label.setPosition(s.width / 2, s.height - 30);
			addChild(label);
			
			setKeyEnabled(true);
			schedule(new TargetSelector(this, "update(float)", new Object[] { 0f }));
		}
		
		@Override
		public boolean wyKeyDown(KeyEvent event) {
			switch(event.getKeyCode()) {
				case KeyEvent.KEYCODE_DPAD_UP:
				{
					WYPoint f = mBody.getWorldVector(0.0f, -200.0f);
					WYPoint p = mBody.getWorldPoint(0.0f, 2.0f);
					mBody.applyForce(f, p);
					break;
				}
				case KeyEvent.KEYCODE_DPAD_LEFT:
					mBody.applyTorque(50.0f);
					break;
				case KeyEvent.KEYCODE_DPAD_RIGHT:
					mBody.applyTorque(-50.0f);
					break;
				default:
					return false;
			}
			
			return true;
		}
    }
}
