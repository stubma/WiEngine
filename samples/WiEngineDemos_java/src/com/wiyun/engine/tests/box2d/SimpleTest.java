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
import com.wiyun.engine.box2d.dynamics.Body;
import com.wiyun.engine.box2d.dynamics.BodyDef;
import com.wiyun.engine.box2d.dynamics.FixtureDef;
import com.wiyun.engine.nodes.Director;
import com.wiyun.engine.nodes.Layer;
import com.wiyun.engine.types.WYSize;
import com.wiyun.engine.utils.TargetSelector;

public class SimpleTest extends WiEngineTestActivity {
	@Override
	protected Layer createLayer() {
		return new MyLayer();
	}

    class MyLayer extends Box2DLayer {
		public MyLayer() {
			WYSize s = Director.getInstance().getWindowSize();
			
			// set gravity
			mWorld.setGravity(0, -10);
			
			// create ground body
			BodyDef bd = BodyDef.make();
			bd.setPosition(0, 0);
			Body ground = mWorld.createBody(bd);
			bd.destroy();
			
			// create bottom edge
			EdgeShape es = EdgeShape.make();
			FixtureDef fixDef = FixtureDef.make();
			fixDef.setShape(es);
			fixDef.setDensity(0.0f);
			fixDef.setRestitution(0.5f);
			es.setEndpoints(0, 0, mBox2D.pixel2Meter(s.width), 0);
			ground.createFixture(fixDef);
			fixDef.destroy();
			
			// create circle body
			bd = BodyDef.make();
			bd.setType(Body.TYPE_DYNAMIC);
			bd.setPosition(mBox2D.pixel2Meter(s.width / 2),
					mBox2D.pixel2Meter(s.height));
			Body ball = mWorld.createBody(bd);
			bd.destroy();
			
			// create circle shape for ball
			CircleShape cs = CircleShape.make();
			fixDef = FixtureDef.make();
			fixDef.setShape(cs);
			fixDef.setRestitution(0.5f);
			fixDef.setDensity(1.0f);
			cs.setRadius(0.5f);
			ball.createFixture(fixDef);
			fixDef.destroy();
			
			schedule(new TargetSelector(this, "update(float)", new Object[] { 0f }));
		}
    }
}
