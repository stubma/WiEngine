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
import com.wiyun.engine.box2d.dynamics.FixtureDef;
import com.wiyun.engine.box2d.dynamics.joints.Joint;
import com.wiyun.engine.box2d.dynamics.joints.RevoluteJointDef;
import com.wiyun.engine.box2d.dynamics.joints.RopeJoint;
import com.wiyun.engine.box2d.dynamics.joints.RopeJointDef;
import com.wiyun.engine.nodes.Director;
import com.wiyun.engine.nodes.Label;
import com.wiyun.engine.nodes.Layer;
import com.wiyun.engine.types.WYPoint;
import com.wiyun.engine.types.WYSize;
import com.wiyun.engine.utils.TargetSelector;

public class RopeTest extends WiEngineTestActivity {
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
    	RopeJointDef m_ropeDef = RopeJointDef.make();
    	Joint m_rope;
    	Label m_label;
    	
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
				PolygonShape shape = PolygonShape.make();
				shape.setAsBox(0.5f, 0.125f);

				FixtureDef fd = FixtureDef.make();
				fd.setShape(shape);
				fd.setDensity(20.0f);
				fd.setFriction(0.2f);
				fd.setFilterCategory(0x0001);
				fd.setFilterMask(0xFFFF & ~0x0002);

				RevoluteJointDef jd = RevoluteJointDef.make();
				jd.setCollideConnected(false);

				int N = 10;
				float y = 15.0f;
				m_ropeDef.setLocalAnchorA(WYPoint.make(0.0f, y));

				Body prevBody = ground;
				for (int i = 0; i < N; ++i)
				{
					BodyDef bd = BodyDef.make();
					bd.setType(Body.TYPE_DYNAMIC);
					bd.setPosition(0.5f + 1.0f * i, y);
					if (i == N - 1)
					{
						shape.setAsBox(1.5f, 1.5f);
						fd.setDensity(100.0f);
						fd.setFilterCategory(0x0002);
						bd.setPosition(1.0f * i, y);
						bd.setAngularDamping(0.4f);
					}

					Body body = mWorld.createBody(bd);
					bd.destroy();

					body.createFixture(fd);

					jd.initialize(prevBody, body, i, y);
					mWorld.createJoint(jd);

					prevBody = body;
				}
				fd.destroy();
				jd.destroy();

				m_ropeDef.setLocalAnchorB(WYPoint.makeZero());

				float extraLength = 0.01f;
				m_ropeDef.setMaxLength(N - 1.0f + extraLength);
				m_ropeDef.setBodyB(prevBody);
			}

			{
				m_ropeDef.setBodyA(ground);
				m_rope = RopeJoint.from(mWorld.createJoint(m_ropeDef));
			}

			// add a hint label
			m_label = Label.make("(Menu)Toggle the rope joint (Rope ON)", 14);
			m_label.setPosition(s.width / 2, s.height - 30);
			addChild(m_label);

			setKeyEnabled(true);
			schedule(new TargetSelector(this, "update(float)", new Object[] { 0f }));
		}
		
		@Override
		public boolean wyKeyDown(KeyEvent event) {
			switch(event.getKeyCode()) {
				case KeyEvent.KEYCODE_MENU:
				{
					if(m_rope != null) {
						mWorld.destroyJoint(m_rope);
						m_rope = null;
						m_label.setText("(Menu)Toggle the rope joint (Rope OFF)");
					} else {
						m_rope = RopeJoint.from(mWorld.createJoint(m_ropeDef));
						m_label.setText("(Menu)Toggle the rope joint (Rope ON)");
					}
					break;
				}
				default:
					return false;
			}

			return true;
		}
    }
}
