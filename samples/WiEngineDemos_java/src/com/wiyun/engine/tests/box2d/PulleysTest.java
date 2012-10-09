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
import com.wiyun.engine.box2d.dynamics.joints.PulleyJoint;
import com.wiyun.engine.box2d.dynamics.joints.PulleyJointDef;
import com.wiyun.engine.nodes.Director;
import com.wiyun.engine.nodes.Layer;
import com.wiyun.engine.types.WYPoint;
import com.wiyun.engine.types.WYSize;
import com.wiyun.engine.utils.TargetSelector;

public class PulleysTest extends WiEngineTestActivity {
	@Override
	protected Layer createLayer() {
		return new MyLayer();
	}
    
    class MyLayer extends Box2DLayer {
    	PulleyJoint m_joint1;
    	
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
				float a = 2.0f;
				float b = 4.0f;
				float y = 10.0f;
				float L = 8.0f;

				PolygonShape shape = PolygonShape.make();
				shape.setAsBox(a, b);

				BodyDef bd = BodyDef.make();
				bd.setType(Body.TYPE_DYNAMIC);

				bd.setPosition(-4.0f, y);
				Body body1 = mWorld.createBody(bd);
				body1.createFixture(shape, 5.0f);

				bd.setPosition(4.0f, y);
				Body body2 = mWorld.createBody(bd);
				body2.createFixture(shape, 5.0f);

				PulleyJointDef pulleyDef = PulleyJointDef.make();
				WYPoint anchor1 = WYPoint.make(-4.0f, y + b);
				WYPoint anchor2 = WYPoint.make(4.0f, y + b);
				WYPoint groundAnchor1 = WYPoint.make(-4.0f, y + b + L);
				WYPoint groundAnchor2 = WYPoint.make(4.0f, y + b + L);
				pulleyDef.initialize(body1, body2, groundAnchor1, groundAnchor2, anchor1, anchor2, 2.0f);

				m_joint1 = PulleyJoint.from(mWorld.createJoint(pulleyDef));
			}
			
			schedule(new TargetSelector(this, "update(float)", new Object[] { 0f }));
		}
    }
}
