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
import com.wiyun.engine.box2d.collision.CircleShape;
import com.wiyun.engine.box2d.collision.EdgeShape;
import com.wiyun.engine.box2d.collision.PolygonShape;
import com.wiyun.engine.box2d.dynamics.Body;
import com.wiyun.engine.box2d.dynamics.BodyDef;
import com.wiyun.engine.box2d.dynamics.Fixture;
import com.wiyun.engine.nodes.Director;
import com.wiyun.engine.nodes.Label;
import com.wiyun.engine.nodes.Layer;
import com.wiyun.engine.types.WYSize;
import com.wiyun.engine.utils.TargetSelector;

public class ShapeEditingTest extends WiEngineTestActivity {
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
    	Body m_body;
    	Fixture m_fixture1;
    	Fixture m_fixture2;
    	
		public MyLayer() {
			WYSize s = Director.getInstance().getWindowSize();
			
			// set gravity
			mWorld.setGravity(0, -10);

			// place box2d to center of bottom edge
			mBox2D.setPosition(s.width / 2, 0);
			
			{
				BodyDef bd = BodyDef.make();
				Body ground = mWorld.createBody(bd);
				bd.destroy();

				EdgeShape shape = EdgeShape.make();
				shape.setEndpoints(-40.0f, 0.0f, 40.0f, 0.0f);
				ground.createFixture(shape, 0.0f);
			}

			BodyDef bd = BodyDef.make();
			bd.setType(Body.TYPE_DYNAMIC);
			bd.setPosition(0.0f, 10.0f);
			m_body = mWorld.createBody(bd);
			bd.destroy();

			PolygonShape shape = PolygonShape.make();
			shape.setAsBox(4.0f, 4.0f, 0.0f, 0.0f, 0.0f);
			m_fixture1 = m_body.createFixture(shape, 10.0f);

			m_fixture2 = null;

			// add a hint label
			Label label = Label.make("(Menu)Create shape, (Search)Destroy shape", 14);
			label.setPosition(s.width / 2, s.height - 30);
			addChild(label);

			setKeyEnabled(true);
			
			schedule(new TargetSelector(this, "update(float)", new Object[] { 0f }));
		}
		
		@Override
		public boolean wyKeyDown(KeyEvent event) {
			switch(event.getKeyCode()) {
				case KeyEvent.KEYCODE_MENU:
					if (m_fixture2 == null)
					{
						CircleShape shape = CircleShape.make();
						shape.setRadius(3.0f);
						shape.setPosition(0.5f, -4.0f);
						m_fixture2 = m_body.createFixture(shape, 10.0f);
						m_body.setAwake(true);
					}
					break;
				case KeyEvent.KEYCODE_SEARCH:
					if (m_fixture2 != null)
					{
						m_body.destroyFixture(m_fixture2);
						m_fixture2 = null;
						m_body.setAwake(true);
					}
					break;
				default:
					return false;
			}

			return true;
		}
    }
}
