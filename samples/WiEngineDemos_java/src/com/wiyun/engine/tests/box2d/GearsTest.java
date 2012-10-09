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
import com.wiyun.engine.box2d.collision.PolygonShape;
import com.wiyun.engine.box2d.dynamics.Body;
import com.wiyun.engine.box2d.dynamics.BodyDef;
import com.wiyun.engine.box2d.dynamics.joints.GearJoint;
import com.wiyun.engine.box2d.dynamics.joints.GearJointDef;
import com.wiyun.engine.box2d.dynamics.joints.PrismaticJoint;
import com.wiyun.engine.box2d.dynamics.joints.PrismaticJointDef;
import com.wiyun.engine.box2d.dynamics.joints.RevoluteJoint;
import com.wiyun.engine.box2d.dynamics.joints.RevoluteJointDef;
import com.wiyun.engine.nodes.Director;
import com.wiyun.engine.nodes.Layer;
import com.wiyun.engine.types.WYPoint;
import com.wiyun.engine.types.WYSize;
import com.wiyun.engine.utils.TargetSelector;

public class GearsTest extends WiEngineTestActivity {
	@Override
	protected Layer createLayer() {
		return new MyLayer();
	}
	
    class MyLayer extends Box2DLayer {
    	RevoluteJoint m_joint1;
    	RevoluteJoint m_joint2;
    	PrismaticJoint m_joint3;
    	GearJoint m_joint4;
    	GearJoint m_joint5;
    	
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
				shape.setEndpoints(50.0f, 0.0f, -50.0f, 0.0f);
				ground.createFixture(shape, 0.0f);
			}

			{
				CircleShape circle1 = CircleShape.make();
				circle1.setRadius(1.0f);

				CircleShape circle2 = CircleShape.make();
				circle2.setRadius(2.0f);

				PolygonShape box = PolygonShape.make();
				box.setAsBox(0.5f, 5.0f);

				BodyDef bd1 = BodyDef.make();
				bd1.setType(Body.TYPE_DYNAMIC);
				bd1.setPosition(-3.0f, 12.0f);
				Body body1 = mWorld.createBody(bd1);
				body1.createFixture(circle1, 5.0f);

				RevoluteJointDef jd1 = RevoluteJointDef.make();
				jd1.setBodyA(ground);
				jd1.setBodyB(body1);
				jd1.setLocalAnchorA(ground.getLocalPoint(bd1.getPosition()));
				jd1.setLocalAnchorB(body1.getLocalPoint(bd1.getPosition()));
				jd1.setReferenceAngle(body1.getAngle() - ground.getAngle());
				m_joint1 = RevoluteJoint.from(mWorld.createJoint(jd1));

				BodyDef bd2 = BodyDef.make();
				bd2.setType(Body.TYPE_DYNAMIC);
				bd2.setPosition(0.0f, 12.0f);
				Body body2 = mWorld.createBody(bd2);
				body2.createFixture(circle2, 5.0f);

				RevoluteJointDef jd2 = RevoluteJointDef.make();
				WYPoint p = bd2.getPosition();
				jd2.initialize(ground, body2, p.x, p.y);
				m_joint2 = RevoluteJoint.from(mWorld.createJoint(jd2));

				BodyDef bd3 = BodyDef.make();
				bd3.setType(Body.TYPE_DYNAMIC);
				bd3.setPosition(2.5f, 12.0f);
				Body body3 = mWorld.createBody(bd3);
				body3.createFixture(box, 5.0f);

				PrismaticJointDef jd3 = PrismaticJointDef.make();
				p = bd3.getPosition();
				jd3.initialize(ground, body3, p.x, p.y, 0.0f, 1.0f);
				jd3.setLowerTranslation(-5.0f);
				jd3.setUpperTranslation(5.0f);
				jd3.setEnableLimit(true);

				m_joint3 = PrismaticJoint.from(mWorld.createJoint(jd3));

				GearJointDef jd4 = GearJointDef.make();
				jd4.setBodyA(body1);
				jd4.setBodyB(body2);
				jd4.setJoint1(m_joint1);
				jd4.setJoint2(m_joint2);
				jd4.setRatio(circle2.getRadius() / circle1.getRadius());
				m_joint4 = GearJoint.from(mWorld.createJoint(jd4));

				GearJointDef jd5 = GearJointDef.make();
				jd5.setBodyA(body2);
				jd5.setBodyB(body3);
				jd5.setJoint1(m_joint2);
				jd5.setJoint2(m_joint3);
				jd5.setRatio(-1.0f / circle2.getRadius());
				m_joint5 = GearJoint.from(mWorld.createJoint(jd5));
				
				bd1.destroy();
				bd2.destroy();
				bd3.destroy();
				jd1.destroy();
				jd2.destroy();
				jd3.destroy();
				jd4.destroy();
				jd5.destroy();
			}
			
			schedule(new TargetSelector(this, "update(float)", new Object[] { 0f }));
		}
    }
}
