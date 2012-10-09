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

import javax.microedition.khronos.opengles.GL10;

import android.os.Bundle;
import android.view.KeyEvent;

import com.wiyun.engine.WiEngineTestActivity;
import com.wiyun.engine.box2d.DebugDraw;
import com.wiyun.engine.box2d.collision.CircleShape;
import com.wiyun.engine.box2d.collision.EdgeShape;
import com.wiyun.engine.box2d.collision.PolygonShape;
import com.wiyun.engine.box2d.dynamics.Body;
import com.wiyun.engine.box2d.dynamics.BodyDef;
import com.wiyun.engine.box2d.dynamics.FixtureDef;
import com.wiyun.engine.box2d.dynamics.World.IRayCastCallback;
import com.wiyun.engine.nodes.Director;
import com.wiyun.engine.nodes.Label;
import com.wiyun.engine.nodes.Layer;
import com.wiyun.engine.types.WYColor3F;
import com.wiyun.engine.types.WYPoint;
import com.wiyun.engine.types.WYSize;
import com.wiyun.engine.utils.TargetSelector;

public class EdgeShapesTest extends WiEngineTestActivity {
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        mGLSurfaceView.disableSystemHandleMenuKey();
    }
    
	@Override
	protected Layer createLayer() {
		return new MyLayer();
	}

    class MyLayer extends Box2DLayer implements IRayCastCallback {
    	int e_maxBodies = 256;
    	int m_bodyIndex;
    	Body[] m_bodies = new Body[e_maxBodies];
    	PolygonShape[] m_polygons;
    	CircleShape m_circle = CircleShape.make();
    	float m_angle;
    	
    	WYPoint m_point = WYPoint.makeZero();
    	WYPoint m_normal = WYPoint.makeZero();
    	
		public MyLayer() {
			WYSize size = Director.getInstance().getWindowSize();
			
			// set gravity
			mWorld.setGravity(0, -10);

			// place box2d to center of bottom edge
			mBox2D.setPosition(size.width / 2, size.height / 4);
			
			// init
			m_polygons = new PolygonShape[4];
			m_polygons[0] = PolygonShape.make();
			m_polygons[1] = PolygonShape.make();
			m_polygons[2] = PolygonShape.make();
			m_polygons[3] = PolygonShape.make();
			
			// Ground body
			{
				BodyDef bd = BodyDef.make();
				Body ground = mWorld.createBody(bd);
				bd.destroy();

				float x1 = -20.0f;
				float y1 = 2.0f * (float)Math.cos(x1 / 10.0f * Math.PI);
				for (int i = 0; i < 80; ++i)
				{
					float x2 = x1 + 0.5f;
					float y2 = 2.0f * (float)Math.cos(x2 / 10.0f * Math.PI);

					EdgeShape shape = EdgeShape.make();
					shape.setEndpoints(x1, y1, x2, y2);
					ground.createFixture(shape, 0.0f);

					x1 = x2;
					y1 = y2;
				}
			}

			{
				WYPoint[] vertices = new WYPoint[3];
				vertices[0] = WYPoint.make(-0.5f, 0.0f);
				vertices[1] = WYPoint.make(0.5f, 0.0f);
				vertices[2] = WYPoint.make(0.0f, 1.5f);
				m_polygons[0].setVertices(vertices);
			}

			{
				WYPoint[] vertices = new WYPoint[3];
				vertices[0] = WYPoint.make(-0.1f, 0.0f);
				vertices[1] = WYPoint.make(0.1f, 0.0f);
				vertices[2] = WYPoint.make(0.0f, 1.5f);
				m_polygons[1].setVertices(vertices);
			}

			{
				float w = 1.0f;
				float b = w / (2.0f + (float)Math.sqrt(2.0f));
				float s = (float)Math.sqrt(2.0f) * b;

				WYPoint[] vertices = new WYPoint[8];
				vertices[0] = WYPoint.make(0.5f * s, 0.0f);
				vertices[1] = WYPoint.make(0.5f * w, b);
				vertices[2] = WYPoint.make(0.5f * w, b + s);
				vertices[3] = WYPoint.make(0.5f * s, w);
				vertices[4] = WYPoint.make(-0.5f * s, w);
				vertices[5] = WYPoint.make(-0.5f * w, b + s);
				vertices[6] = WYPoint.make(-0.5f * w, b);
				vertices[7] = WYPoint.make(-0.5f * s, 0.0f);

				m_polygons[2].setVertices(vertices);
			}

			{
				m_polygons[3].setAsBox(0.5f, 0.5f);
			}

			{
				m_circle.setRadius(0.5f);
			}

			m_bodyIndex = 0;
			m_angle = 0.0f;

			// add a hint label
			Label label = Label.make("(Menu)Create shape, (Search)Destroy shape", 14);
			label.setPosition(size.width / 2, size.height - 30);
			addChild(label);

			setKeyEnabled(true);
			
			schedule(new TargetSelector(this, "update(float)", new Object[] { 0f }));
		}
		
		@Override
		public void update(float delta) {
			super.update(delta);
			
			float L = 25.0f;
			WYPoint point1 = WYPoint.make(0.0f, 10.0f);
			WYPoint d = WYPoint.make(L * (float)Math.cos(m_angle), -L * (float)Math.abs(Math.sin(m_angle)));
			WYPoint point2 = WYPoint.add(point1, d);

			mWorld.rayCast(this, point1.x, point1.y, point2.x, point2.y);

			GL10 gl = Director.getInstance().gl;
			gl.glPushMatrix();
			{
				mBox2D.transformAncestors();
				mBox2D.transform();

				DebugDraw dd = mBox2D.getDebugDraw();
				if(mFixturePointer != 0) {
					dd.drawPoint(m_point, 5.0f, WYColor3F.make(0.4f, 0.9f, 0.4f));

					dd.drawSegment(point1, m_point, WYColor3F.make(0.8f, 0.8f, 0.8f));

					WYPoint head = WYPoint.add(m_point, WYPoint.mul(m_normal, 0.5f));
					dd.drawSegment(m_point, head, WYColor3F.make(0.9f, 0.9f, 0.4f));
				} else {
					dd.drawSegment(point1, point2, WYColor3F.make(0.8f, 0.8f, 0.8f));
				}
			}
			gl.glPopMatrix();

			m_angle += 0.25f * (float)Math.PI / 180.0f;
		}

		public float reportFixture(int fixturePointer, float pointX,
				float pointY, float normalX, float normalY, float fraction) {
			mFixturePointer = fixturePointer;
			m_point = WYPoint.make(pointX, pointY);
			m_normal = WYPoint.make(normalX, normalY);

			return fraction;
		}
		
		void Create(int index)
		{
			if (m_bodies[m_bodyIndex] != null)
			{
				mWorld.destroyBody(m_bodies[m_bodyIndex]);
				m_bodies[m_bodyIndex] = null;
			}

			BodyDef bd = BodyDef.make();

			float x = mRandom.nextFloat() * 20.f - 10.f;
			float y = mRandom.nextFloat() * 10.f + 10.f;
			bd.setPosition(x, y);
			bd.setAngle(mRandom.nextFloat() * (float)Math.PI * 2.f - (float)Math.PI);
			bd.setType(Body.TYPE_DYNAMIC);

			if (index == 4)
			{
				bd.setAngularDamping(0.02f);
			}

			m_bodies[m_bodyIndex] = mWorld.createBody(bd);
			bd.destroy();

			if (index < 4)
			{
				FixtureDef fd = FixtureDef.make();
				fd.setShape(m_polygons[index]);
				fd.setFriction(0.3f);
				fd.setDensity(20.0f);
				m_bodies[m_bodyIndex].createFixture(fd);
				fd.destroy();
			}
			else
			{
				FixtureDef fd = FixtureDef.make();
				fd.setShape(m_circle);
				fd.setFriction(0.3f);
				fd.setDensity(20.0f);
				m_bodies[m_bodyIndex].createFixture(fd);
				fd.destroy();
			}

			m_bodyIndex = (m_bodyIndex + 1) % e_maxBodies;
		}
		
		void DestroyBody()
		{
			for (int i = 0; i < e_maxBodies; ++i)
			{
				if (m_bodies[i] != null)
				{
					mWorld.destroyBody(m_bodies[i]);
					m_bodies[i] = null;
					return;
				}
			}
		}
		
		@Override
		public boolean wyKeyDown(KeyEvent event) {
			switch(event.getKeyCode()) {
				case KeyEvent.KEYCODE_MENU:
					Create(Math.abs(mRandom.nextInt() % 5));
					break;
				case KeyEvent.KEYCODE_SEARCH:
					DestroyBody();
					break;
				default:
					return false;
			}

			return true;
		}
    }
}
