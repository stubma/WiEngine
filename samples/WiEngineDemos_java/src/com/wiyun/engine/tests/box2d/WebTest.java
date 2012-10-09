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
import com.wiyun.engine.box2d.dynamics.World.IDestructionListener;
import com.wiyun.engine.box2d.dynamics.joints.DistanceJointDef;
import com.wiyun.engine.box2d.dynamics.joints.Joint;
import com.wiyun.engine.nodes.Director;
import com.wiyun.engine.nodes.Label;
import com.wiyun.engine.nodes.Layer;
import com.wiyun.engine.types.WYPoint;
import com.wiyun.engine.types.WYSize;
import com.wiyun.engine.utils.TargetSelector;

public class WebTest extends WiEngineTestActivity {
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        mGLSurfaceView.disableSystemHandleMenuKey();
    }
    
	@Override
	protected Layer createLayer() {
		return new MyLayer();
	}

    class MyLayer extends Box2DLayer implements IDestructionListener {
    	Body[] m_bodies = new Body[4];
    	Joint[] m_joints = new Joint[8];
    	
		public MyLayer() {
			WYSize s = Director.getInstance().getWindowSize();
			
			// set gravity
			mWorld.setGravity(0, -10);

			// place box2d to center of bottom edge
			mBox2D.setPosition(s.width / 2, 0);
			
			// set destruction listener
			mWorld.setDestructionListener(this);
			
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
				shape.setAsBox(0.5f, 0.5f);

				BodyDef bd = BodyDef.make();
				bd.setType(Body.TYPE_DYNAMIC);
				bd.setPosition(-5.0f, 5.0f);
				m_bodies[0] = mWorld.createBody(bd);
				m_bodies[0].createFixture(shape, 5.0f);

				bd.setPosition(5.0f, 5.0f);
				m_bodies[1] = mWorld.createBody(bd);
				m_bodies[1].createFixture(shape, 5.0f);

				bd.setPosition(5.0f, 15.0f);
				m_bodies[2] = mWorld.createBody(bd);
				m_bodies[2].createFixture(shape, 5.0f);

				bd.setPosition(-5.0f, 15.0f);
				m_bodies[3] = mWorld.createBody(bd);
				m_bodies[3].createFixture(shape, 5.0f);

				DistanceJointDef jd = DistanceJointDef.make();
				WYPoint p1, p2, d;

				jd.setFrequencyHz(4.0f);
				jd.setDampingRatio(0.5f);
				jd.setBodyA(ground);
				jd.setBodyB(m_bodies[0]);
				jd.setLocalAnchorA(-10.0f, 0.0f);
				jd.setLocalAnchorB(-0.5f, -0.5f);
				p1 = jd.getBodyA().getWorldPoint(jd.getLocalAnchorA());
				p2 = jd.getBodyB().getWorldPoint(jd.getLocalAnchorB());
				d = WYPoint.sub(p2, p1);
				jd.setLength(WYPoint.length(d));
				m_joints[0] = Joint.from(mWorld.createJoint(jd));

				jd.setBodyA(ground);
				jd.setBodyB(m_bodies[1]);
				jd.setLocalAnchorA(10.0f, 0.0f);
				jd.setLocalAnchorB(0.5f, -0.5f);
				p1 = jd.getBodyA().getWorldPoint(jd.getLocalAnchorA());
				p2 = jd.getBodyB().getWorldPoint(jd.getLocalAnchorB());
				d = WYPoint.sub(p2, p1);
				jd.setLength(WYPoint.length(d));
				m_joints[1] = Joint.from(mWorld.createJoint(jd));

				jd.setBodyA(ground);
				jd.setBodyB(m_bodies[2]);
				jd.setLocalAnchorA(10.0f, 20.0f);
				jd.setLocalAnchorB(0.5f, 0.5f);
				p1 = jd.getBodyA().getWorldPoint(jd.getLocalAnchorA());
				p2 = jd.getBodyB().getWorldPoint(jd.getLocalAnchorB());
				d = WYPoint.sub(p2, p1);
				jd.setLength(WYPoint.length(d));
				m_joints[2] = Joint.from(mWorld.createJoint(jd));

				jd.setBodyA(ground);
				jd.setBodyB(m_bodies[3]);
				jd.setLocalAnchorA(-10.0f, 20.0f);
				jd.setLocalAnchorB(-0.5f, 0.5f);
				p1 = jd.getBodyA().getWorldPoint(jd.getLocalAnchorA());
				p2 = jd.getBodyB().getWorldPoint(jd.getLocalAnchorB());
				d = WYPoint.sub(p2, p1);
				jd.setLength(WYPoint.length(d));
				m_joints[3] = Joint.from(mWorld.createJoint(jd));

				jd.setBodyA(m_bodies[0]);
				jd.setBodyB(m_bodies[1]);
				jd.setLocalAnchorA(0.5f, 0.0f);
				jd.setLocalAnchorB(-0.5f, 0.0f);;
				p1 = jd.getBodyA().getWorldPoint(jd.getLocalAnchorA());
				p2 = jd.getBodyB().getWorldPoint(jd.getLocalAnchorB());
				d = WYPoint.sub(p2, p1);
				jd.setLength(WYPoint.length(d));
				m_joints[4] = Joint.from(mWorld.createJoint(jd));

				jd.setBodyA(m_bodies[1]);
				jd.setBodyB(m_bodies[2]);
				jd.setLocalAnchorA(0.0f, 0.5f);
				jd.setLocalAnchorB(0.0f, -0.5f);
				p1 = jd.getBodyA().getWorldPoint(jd.getLocalAnchorA());
				p2 = jd.getBodyB().getWorldPoint(jd.getLocalAnchorB());
				d = WYPoint.sub(p2, p1);
				jd.setLength(WYPoint.length(d));
				m_joints[5] = Joint.from(mWorld.createJoint(jd));

				jd.setBodyA(m_bodies[2]);
				jd.setBodyB(m_bodies[3]);
				jd.setLocalAnchorA(-0.5f, 0.0f);
				jd.setLocalAnchorB(0.5f, 0.0f);
				p1 = jd.getBodyA().getWorldPoint(jd.getLocalAnchorA());
				p2 = jd.getBodyB().getWorldPoint(jd.getLocalAnchorB());
				d = WYPoint.sub(p2, p1);
				jd.setLength(WYPoint.length(d));
				m_joints[6] = Joint.from(mWorld.createJoint(jd));

				jd.setBodyA(m_bodies[3]);
				jd.setBodyB(m_bodies[0]);
				jd.setLocalAnchorA(0.0f, -0.5f);
				jd.setLocalAnchorB(0.0f, 0.5f);
				p1 = jd.getBodyA().getWorldPoint(jd.getLocalAnchorA());
				p2 = jd.getBodyB().getWorldPoint(jd.getLocalAnchorB());
				d = WYPoint.sub(p2, p1);
				jd.setLength(WYPoint.length(d));
				m_joints[7] = Joint.from(mWorld.createJoint(jd));
				
				bd.destroy();
				jd.destroy();
			}

			// add a hint label
			Label label = Label.make("(Menu)Delete a body, (Search)Delete a joint", 14);
			label.setPosition(s.width / 2, s.height - 30);
			addChild(label);

			setKeyEnabled(true);
			
			schedule(new TargetSelector(this, "update(float)", new Object[] { 0f }));
		}

		public void fixtureSayGoodbye(int fixturePointer) {
        }

		public void jointSayGoodbye(int jointPointer) {
			if(mMouseJoint != null && mMouseJoint.getPointer() == jointPointer) {
				mMouseJoint.setPointer(0);
			} else {
				JointDestroyed(jointPointer);
			}
        }
		
		@Override
		public boolean wyKeyDown(KeyEvent event) {
			switch(event.getKeyCode()) {
				case KeyEvent.KEYCODE_MENU:
					for(int i = 0; i < 4; ++i) {
						if(m_bodies[i] != null) {
							mWorld.destroyBody(m_bodies[i]);
							m_bodies[i] = null;
							break;
						}
					}
					break;
				case KeyEvent.KEYCODE_SEARCH:
					for(int i = 0; i < 8; ++i) {
						if(m_joints[i] != null) {
							mWorld.destroyJoint(m_joints[i]);
							m_joints[i] = null;
							break;
						}
					}
					break;
				default:
					return false;
			}

			return true;
		}
		
		void JointDestroyed(int jointPointer) {
			for(int i = 0; i < 8; ++i) {
				if(m_joints[i] != null && m_joints[i].getPointer() == jointPointer) {
					m_joints[i] = null;
					break;
				}
			}
		}
    }
}
