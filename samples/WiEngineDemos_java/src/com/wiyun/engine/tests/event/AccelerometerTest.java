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
package com.wiyun.engine.tests.event;

import com.wiyun.engine.R;
import com.wiyun.engine.WiEngineTestActivity;
import com.wiyun.engine.actions.Action;
import com.wiyun.engine.actions.FadeIn;
import com.wiyun.engine.actions.FadeOut;
import com.wiyun.engine.actions.IntervalAction;
import com.wiyun.engine.actions.RepeatForever;
import com.wiyun.engine.actions.Sequence;
import com.wiyun.engine.nodes.ColorLayer;
import com.wiyun.engine.nodes.Director;
import com.wiyun.engine.nodes.Layer;
import com.wiyun.engine.nodes.Node;
import com.wiyun.engine.nodes.Sprite;
import com.wiyun.engine.types.WYColor4B;
import com.wiyun.engine.types.WYSize;

public class AccelerometerTest extends WiEngineTestActivity {
	@Override
	protected Layer createLayer() {
		return new MyLayer();
	}

	class MyLayer extends Layer {
		static final int TAG_SPRITE = 1;
		float m_X = 0;
		float m_Y = 0;

		public MyLayer() {
			WYSize s = Director.getInstance().getWindowSize();
			Sprite sprite = Sprite.make(R.drawable.grossini);
			
			Layer layer = ColorLayer.make(new WYColor4B(255, 255, 0, 255));
			addChild(layer);

			addChild(sprite, 0, TAG_SPRITE);
			sprite.setPosition(s.width / 2, s.height / 2);
			
			layer.runAction((Action)RepeatForever.make(
					(IntervalAction)Sequence.make(
							(IntervalAction)FadeIn.make(1).autoRelease(), 
							(IntervalAction)FadeOut.make(1).autoRelease()).autoRelease()).autoRelease());
			
			setAccelerometerEnabled(true);
		}
		
		@Override
		public void wyAccelerometerChanged(float accelX, float accelY, float accelZ) {
			/*
			 * 请注意Android上的加速器事件是以设备的正向为标准的, 在XOOM上landscape才是正向, 
			 * 由于这个demo运行在portrait模式, 所以移动的时候会不正确. 这不是bug, 具体做游戏
			 * 时请根据游戏的朝向自己处理加速器的值.
			 */
			
			float x = accelX * -10;
			float y = accelY * -10;
			
			m_X = (m_X + x)/2;
			m_Y = (m_Y + y)/2;
			
			Node s = getChild(TAG_SPRITE);
			
			x = s.getPositionX();
			y = s.getPositionY();
			float width = s.getWidth();
			float height = s.getHeight();

			x += m_X;
			y += m_Y;
			
			if (m_X + x < width/2){
				x = width/2;
			}
			if (m_X + x > getWidth() - width/2){
				x = getWidth() - width/2;
			}

			if (m_Y + y < height/2){
				y = height/2;
			}
			if (m_Y + y > getHeight() - height/2){
				y = getHeight() - height/2;
			}
			s.setPosition(x, y);
		}
	}
}
