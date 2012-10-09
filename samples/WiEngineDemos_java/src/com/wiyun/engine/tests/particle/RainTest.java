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
package com.wiyun.engine.tests.particle;

import android.view.MotionEvent;

import com.wiyun.engine.WiEngineTestActivity;
import com.wiyun.engine.nodes.ColorLayer;
import com.wiyun.engine.nodes.Director;
import com.wiyun.engine.nodes.Layer;
import com.wiyun.engine.particle.ParticleSystem;
import com.wiyun.engine.types.WYColor4B;
import com.wiyun.engine.types.WYPoint;
import com.wiyun.engine.types.WYSize;

public class RainTest extends WiEngineTestActivity {
	@Override
	protected Layer createLayer() {
		return new MyLayer();
	}

	class MyLayer extends ColorLayer {
		private ParticleSystem emitter;

		public MyLayer() {
			super(new WYColor4B(0, 0, 0, 255));
			setTouchEnabled(true);

			// create particle system
			emitter = ParticleRain.make();
			addChild(emitter);

			setEmitterPosition();
		}

		private void setEmitterPosition() {
			WYSize s = Director.getInstance().getWindowSize();
			emitter.setPosition(s.width / 2, s.height / 2);
		}
		
		@Override
		public boolean wyTouchesBegan(MotionEvent event) {
			WYPoint loc = Director.getInstance().convertToGL(event.getX(), event.getY());
			emitter.setPosition(loc.x, loc.y);
			return true;
		}
	}
}
