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
import com.wiyun.engine.box2d.dynamics.Body;
import com.wiyun.engine.box2d.dynamics.BodyDef;
import com.wiyun.engine.box2d.dynamics.FixtureDef;
import com.wiyun.engine.nodes.Director;
import com.wiyun.engine.nodes.Label;
import com.wiyun.engine.nodes.Layer;
import com.wiyun.engine.types.WYSize;
import com.wiyun.engine.utils.TargetSelector;

public class ConfinedTest extends WiEngineTestActivity {
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
		public MyLayer() {
			// place box2d to center of bottom edge
			WYSize s = Director.getInstance().getWindowSize();
			mBox2D.setPosition(s.width / 2, 0);
			
			{
				BodyDef bd = BodyDef.make();
				Body ground = mWorld.createBody(bd);
				bd.destroy();

				EdgeShape shape = EdgeShape.make();

				// Floor
				shape.setEndpoints(-10.0f, 0.0f, 10.0f, 0.0f);
				ground.createFixture(shape, 0.0f);

				// Left wall
				shape.setEndpoints(-10.0f, 0.0f, -10.0f, 20.0f);
				ground.createFixture(shape, 0.0f);

				// Right wall
				shape.setEndpoints(10.0f, 0.0f, 10.0f, 20.0f);
				ground.createFixture(shape, 0.0f);

				// Roof
				shape.setEndpoints(-10.0f, 20.0f, 10.0f, 20.0f);
				ground.createFixture(shape, 0.0f);
			}

			// add a hint label
			Label label = Label.make("Press menu to create a circle", 14);
			label.setPosition(s.width / 2, s.height - 30);
			addChild(label);

			setKeyEnabled(true);
			schedule(new TargetSelector(this, "update(float)", new Object[] { 0f }));
		}
		
		void CreateCircle() {
			float radius = 2.0f;
			CircleShape shape = CircleShape.make();
			shape.setPosition(0, 0);
			shape.setRadius(radius);

			FixtureDef fd = FixtureDef.make();
			fd.setShape(shape);
			fd.setDensity(1.f);
			fd.setFriction(0.0f);

			BodyDef bd = BodyDef.make();
			bd.setType(Body.TYPE_DYNAMIC);
			bd.setPosition(mRandom.nextFloat(), 3.0f + mRandom.nextFloat());
			Body body = mWorld.createBody(bd);
			bd.destroy();

			body.createFixture(fd);
			fd.destroy();
		}
		
		@Override
		public boolean wyKeyDown(KeyEvent event) {
			switch(event.getKeyCode()) {
				case KeyEvent.KEYCODE_MENU:
					CreateCircle();
					break;
				default:
					return false;
			}

			return true;
		}
    }
}
