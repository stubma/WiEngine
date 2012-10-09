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
package com.wiyun.engine.tests.node;

import android.util.Log;
import android.view.MotionEvent;

import com.wiyun.engine.R;
import com.wiyun.engine.WiEngineTestActivity;
import com.wiyun.engine.afcanim.SPX3Sprite;
import com.wiyun.engine.afcanim.AFCSprite.IAFCSpriteCallback;
import com.wiyun.engine.nodes.Director;
import com.wiyun.engine.nodes.Layer;
import com.wiyun.engine.opengl.Texture2D;
import com.wiyun.engine.types.WYSize;
import com.wiyun.engine.utils.TargetSelector;

public class SpriteX2011Test extends WiEngineTestActivity {
	@Override
	protected Layer createLayer() {
		return new MyLayer();
	}
    
    class MyLayer extends Layer implements IAFCSpriteCallback {
    	SPX3Sprite m_sprite1;
    	SPX3Sprite m_sprite2;
    	SPX3Sprite m_sprite3;
    	SPX3Sprite m_sprite4;
    	SPX3Sprite m_sprite5;
    	SPX3Sprite m_sprite6;
    	SPX3Sprite m_sprite7;
    	
    	public MyLayer() {
    		// animation 1
    		// SpriteX是不支持tick模式播放的, 但是可以使用setForceTickMode强行设置使用tick模式
    		// 为了看效果, 把unit interval设置的比较大, 这样可以看到动画变慢了
    		WYSize s = Director.getInstance().getWindowSize();
    		Texture2D tex1 = Texture2D.makePNG(R.drawable.spx3_test);
    		tex1.autoRelease();
    		m_sprite1 = SPX3Sprite.make(R.raw.spx3_test, 0, tex1);
    		m_sprite1.setLoopCount(-1);
    		m_sprite1.setPosition(s.width / 2, s.height * 7 / 8);
    		m_sprite1.setForceTickMode(true);
    		m_sprite1.setUnitInterval(0.5f);
    		addChild(m_sprite1);
    		m_sprite1.setAFCSpriteCallback(this);
    		
    		// animation 2, 这个动画本来有旋转90度, 但是可以通过setIgnoreActionTransform忽略掉
    		m_sprite2 = SPX3Sprite.make(R.raw.spx3_test, 1, tex1);
    		m_sprite2.setLoopCount(-1);
    		m_sprite2.setPosition(s.width / 2, s.height * 6 / 8);
    		addChild(m_sprite2);
    		
    		// animation 3, 反着放
    		m_sprite3 = SPX3Sprite.make(R.raw.spx3_test, 2, tex1);
    		m_sprite3.setLoopCount(-1);
    		m_sprite3.setPosition(s.width / 2, s.height * 5 / 8);
    		m_sprite3.setReverse(true);
    		addChild(m_sprite3);
    		
    		// animation 4
    		m_sprite4 = SPX3Sprite.make(R.raw.spx3_test, 3, tex1);
    		m_sprite4.setLoopCount(-1);
    		m_sprite4.setPosition(s.width / 2, s.height * 4 / 8);
    		addChild(m_sprite4);
    		
    		// animation 5, 忽略动画本身的转换, y轴倒转播放
    		m_sprite5 = SPX3Sprite.make(R.raw.spx3_test, 4, tex1);
    		m_sprite5.setLoopCount(-1);
    		m_sprite5.setPosition(s.width / 2, s.height * 3 / 8);
    		m_sprite5.setFlipY(true);
    		addChild(m_sprite5);
    		
    		// animation 6
    		m_sprite6 = SPX3Sprite.make(R.raw.spx3_test, 5, tex1);
    		m_sprite6.setLoopCount(-1);
    		m_sprite6.setPosition(s.width / 2, s.height * 2 / 8);
    		addChild(m_sprite6);
    		
    		// animation 7
    		m_sprite7 = SPX3Sprite.make(R.raw.spx3_test, 6, tex1);
    		m_sprite7.setLoopCount(-1);
    		m_sprite7.setPosition(s.width / 2, s.height / 8);
    		addChild(m_sprite7);
    		
    		schedule(new TargetSelector(this, "tick(float)", new Object[] { 0f }));
    		setTouchEnabled(true);
		}
    	
    	public void tick(float delta) {
    		m_sprite1.tick(delta);
    		m_sprite2.tick(delta);
    		m_sprite3.tick(delta);
    		m_sprite4.tick(delta);
    		m_sprite5.tick(delta);
    		m_sprite6.tick(delta);
    		m_sprite7.tick(delta);
    	}
    	
    	@Override
    	public boolean wyTouchesBegan(MotionEvent event) {
    		m_sprite1.setPaused(!m_sprite1.isPaused());
    		m_sprite2.setPaused(!m_sprite2.isPaused());
    		m_sprite3.setPaused(!m_sprite3.isPaused());
    		m_sprite4.setPaused(!m_sprite4.isPaused());
    		m_sprite5.setPaused(!m_sprite5.isPaused());
    		m_sprite6.setPaused(!m_sprite6.isPaused());
    		m_sprite7.setPaused(!m_sprite7.isPaused());
    		return true;
    	}

		@Override
		public void onAFCAnimationEnded(int pointer) {
			Log.d("libwiengine", "onAFCAnimationEnded");
		}

		@Override
		public void onAFCAnimationFrameChanged(int pointer) {
			Log.d("libwiengine", "onAFCAnimationFrameChanged");
		}
    }
}
