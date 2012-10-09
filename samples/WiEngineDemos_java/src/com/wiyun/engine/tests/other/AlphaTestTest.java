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
package com.wiyun.engine.tests.other;

import javax.microedition.khronos.opengles.GL10;

import android.view.Menu;
import android.view.MenuItem;

import com.wiyun.engine.R;
import com.wiyun.engine.WiEngineTestActivity;
import com.wiyun.engine.nodes.Director;
import com.wiyun.engine.nodes.Label;
import com.wiyun.engine.nodes.Layer;
import com.wiyun.engine.nodes.Slider;
import com.wiyun.engine.nodes.Sprite;
import com.wiyun.engine.nodes.Slider.ISliderCallback;
import com.wiyun.engine.types.WYSize;
import com.wiyun.engine.utils.ResolutionIndependent;

public class AlphaTestTest extends WiEngineTestActivity {
	MyLayer mLayer;
	
	@Override
	protected Layer createLayer() {
		mLayer =  new MyLayer();
		return mLayer;
	}
	
	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		menu.add(0, GL10.GL_NEVER, 0, "GL_NEVER");
		menu.add(0, GL10.GL_LESS, 0, "GL_LESS");
		menu.add(0, GL10.GL_LEQUAL, 0, "GL_LEQUAL");
		menu.add(0, GL10.GL_EQUAL, 0, "GL_EQUAL");
		menu.add(0, GL10.GL_GEQUAL, 0, "GL_GEQUAL");
		menu.add(0, GL10.GL_GREATER, 0, "GL_GREATER");
		menu.add(0, GL10.GL_NOTEQUAL, 0, "GL_NOTEQUAL");
	    return super.onCreateOptionsMenu(menu);
	}
	
	@Override
	public boolean onOptionsItemSelected(MenuItem item) {
		mLayer.setAlphaFunc(item.getItemId());
		return true;
	}

	public class MyLayer extends Layer implements ISliderCallback {
		Sprite m_sprite;
		Slider m_slider;
		Label m_hint;
		int m_alphaFunc;
		
		MyLayer() {
			WYSize s = Director.getInstance().getWindowSize();
			
			// init member
			m_alphaFunc = GL10.GL_GEQUAL;

			// create
			m_sprite = Sprite.make(R.drawable.alpha_test);
			m_sprite.setPosition(s.width / 2, s.height / 2 + DP(80));
			addChild(m_sprite);

			// create a hint label
			m_hint = Label.make("press menu/drag slider", 18);
			m_hint.setPosition(s.width / 2, DP(80));
			addChild(m_hint);
			
    		// slider
    		Sprite bar = Sprite.make(R.drawable.bar);
    		Sprite thumb = Sprite.make(R.drawable.thumb);
    		m_slider = Slider.make(null, bar, thumb);
    		m_slider.setMax(255);
    		m_slider.setShowFullBar(true);
    		m_slider.setPosition(s.width / 2, DP(50));
    		m_slider.setCallback(this);
    		addChild(m_slider);
		}
		
		private float DP(float v) {
			return ResolutionIndependent.resolveDp(v);
		}

		@Override
        public void onSliderValueChanged(int pointer, float value) {
			m_sprite.setAlphaFunc(m_alphaFunc, value / 255.f);
			m_hint.setText(String.valueOf((int)value));
        }
		
		public void setAlphaFunc(int func) {
			m_alphaFunc = func;
			m_sprite.setAlphaFunc(func, m_slider.getValue() / 255.f);
		}
	}
}
