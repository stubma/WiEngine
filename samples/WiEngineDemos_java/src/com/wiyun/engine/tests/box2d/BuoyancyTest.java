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
import com.wiyun.engine.box2d.collision.PolygonShape;
import com.wiyun.engine.box2d.controllers.BuoyancyController;
import com.wiyun.engine.box2d.controllers.BuoyancyControllerDef;
import com.wiyun.engine.box2d.dynamics.Body;
import com.wiyun.engine.box2d.dynamics.BodyDef;
import com.wiyun.engine.box2d.dynamics.FixtureDef;
import com.wiyun.engine.nodes.BitmapFontLabel;
import com.wiyun.engine.nodes.Button;
import com.wiyun.engine.nodes.ColorLayer;
import com.wiyun.engine.nodes.Director;
import com.wiyun.engine.nodes.Layer;
import com.wiyun.engine.nodes.NinePatchSprite;
import com.wiyun.engine.opengl.Texture2D;
import com.wiyun.engine.types.WYColor3B;
import com.wiyun.engine.types.WYColor4B;
import com.wiyun.engine.types.WYPoint;
import com.wiyun.engine.types.WYRect;
import com.wiyun.engine.types.WYSize;
import com.wiyun.engine.utils.BitmapFont;
import com.wiyun.engine.utils.ResolutionIndependent;
import com.wiyun.engine.utils.TargetSelector;

public class BuoyancyTest extends WiEngineTestActivity {
	@Override
	protected Layer createLayer() {
		return new MyLayer();
	}

    class MyLayer extends Box2DLayer {
    	int e_maxBodies = 256;
    	int m_bodyIndex;
    	Body[] m_bodies = new Body[e_maxBodies];
    	PolygonShape[] m_polygons;
    	CircleShape m_circle = CircleShape.make();
    	BuoyancyController m_bc;
    	
		public MyLayer() {
			WYSize winSize = Director.getInstance().getWindowSize();

			// set gravity
			mWorld.setGravity(0, -10);

			// place box2d to center of bottom edge
			mBox2D.setPosition(winSize.width / 2, 0);
			
			// create shape
			m_polygons = new PolygonShape[4];
			m_polygons[0] = PolygonShape.make();
			m_polygons[1] = PolygonShape.make();
			m_polygons[2] = PolygonShape.make();
			m_polygons[3] = PolygonShape.make();
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
			
	        // create controller
	        BuoyancyControllerDef cd = BuoyancyControllerDef.make();
	        cd.setNormal(0, 1);
	        cd.setOffset(mBox2D.pixel2Meter(winSize.height / 2));
	        cd.setDensity(2);
	        cd.setUseWorldGravity(true);
	        cd.setUseDensity(true);
	        cd.setLinearDrag(2);
	        cd.setAngularDrag(1);
	        m_bc = BuoyancyController.from(mWorld.createController(cd));
	        cd.destroy();
	        
	        // add a layer for water surface
	        ColorLayer waterLayer = ColorLayer.make(WYColor4B.make(0, 0, 255, 100));
	        waterLayer.setContentSize(winSize.width, winSize.height / 2);
	        addChild(waterLayer, 1);
			
			// freq. down button
			NinePatchSprite normal = NinePatchSprite.make(Texture2D.makePNG(R.drawable.btn_normal), WYRect.make(DP(9), DP(7), DP(22), DP(28)));
			NinePatchSprite pressed = NinePatchSprite.make(Texture2D.makePNG(R.drawable.btn_pressed), WYRect.make(DP(9), DP(7), DP(22), DP(28)));
			normal.setContentSize(DP(150), DP(44));
			pressed.setContentSize(DP(150), DP(44));
			Button button = Button.make(normal, pressed, null, null, this, "onCreateShape");
			button.setPosition(DP(80), winSize.height - DP(30));
			addChild(button, 1);

			// label for freq. down button
			BitmapFont font = BitmapFont.loadFont(R.raw.bitmapfont);
			BitmapFontLabel label = BitmapFontLabel.make(font, "Create Shape");
			label.setColor(WYColor3B.make(255, 255, 0));
			label.setPosition(DP(80), winSize.height - DP(30));
			addChild(label, 1);

			// freq. up button
			button = Button.make(normal, pressed, null, null, this, "onDestroyShape");
			button.setPosition(DP(240), winSize.height - DP(30));
			addChild(button, 1);

			// label for freq. up button
			label = BitmapFontLabel.make(font, "Destroy Shape");
			label.setColor(WYColor3B.make(255, 255, 0));
			label.setPosition(DP(240), winSize.height - DP(30));
			addChild(label, 1);

			schedule(new TargetSelector(this, "update(float)", new Object[] { 0f }));
		}
		
		private float DP(float v) {
			return ResolutionIndependent.resolveDp(v);
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
				fd.setDensity(1.f);
				m_bodies[m_bodyIndex].createFixture(fd);
				fd.destroy();
			}
			else
			{
				FixtureDef fd = FixtureDef.make();
				fd.setShape(m_circle);
				fd.setFriction(0.3f);
				fd.setDensity(1.f);
				m_bodies[m_bodyIndex].createFixture(fd);
				fd.destroy();
			}

			m_bc.addBody(m_bodies[m_bodyIndex]);
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
		
		public void onCreateShape() {
			Create(Math.abs(mRandom.nextInt() % 5));
		}
		
		public void onDestroyShape() {
			DestroyBody();
		}
    }
}
