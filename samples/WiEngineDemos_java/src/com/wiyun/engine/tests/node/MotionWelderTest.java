/*
 * Copyright (c) 2010 WiYun Inc.
 * Author: luma(stubma@gmail.com)
 *
 * For all entities this program is free software; you can redistribute
 * it and/or modify it under the terms of the 'WiEngine' license with
 * the additional provision that 'WiEngine' must be credited in a manner
 * that can be be observed by end users, for example, in the credits or during
 * start up. (please find WiEngine logo in sdk's logo folder)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
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
import com.wiyun.engine.afcanim.MWSprite;
import com.wiyun.engine.afcanim.AFCSprite.IAFCSpriteCallback;
import com.wiyun.engine.nodes.Director;
import com.wiyun.engine.nodes.Layer;
import com.wiyun.engine.opengl.Texture2D;
import com.wiyun.engine.types.WYSize;
import com.wiyun.engine.utils.TargetSelector;

public class MotionWelderTest extends WiEngineTestActivity {
	@Override
	protected Layer createLayer() {
		return new MyLayer();
	}
    
    class MyLayer extends Layer implements IAFCSpriteCallback {
    	MWSprite m_sprite1;
    	MWSprite m_sprite2;
    	MWSprite m_sprite3;
    	MWSprite m_sprite4;
    	MWSprite m_sprite5;
    	
    	public MyLayer() {
    		// animation 1
    		WYSize s = Director.getInstance().getWindowSize();
    		Texture2D tex1 = Texture2D.makePNG(R.drawable.mongo);
    		m_sprite1 = MWSprite.make(R.raw.test_motion_welder, 0, tex1);
    		m_sprite1.setLoopCount(-1);
    		m_sprite1.setPosition(s.width / 2, s.height * 5 / 6);
    		m_sprite1.setUnitInterval(0.1f);
    		m_sprite1.setDebugDrawFrameRect(true);
    		m_sprite1.setDebugDrawCollisionRect(true);
    		addChild(m_sprite1);
    		m_sprite1.setAFCSpriteCallback(this);
    		
    		// animation 2
    		m_sprite2 = MWSprite.make(R.raw.test_motion_welder, 1, tex1);
    		m_sprite2.setLoopCount(-1);
    		m_sprite2.setPosition(s.width / 2, s.height * 4 / 6);
    		m_sprite2.setUnitInterval(0.1f);
    		m_sprite2.setDebugDrawFrameRect(true);
    		m_sprite2.setDebugDrawCollisionRect(true);
    		addChild(m_sprite2);
    		
    		// animation 2 but flip x
    		m_sprite3 = MWSprite.make(R.raw.test_motion_welder, 1, tex1);
    		m_sprite3.setLoopCount(-1);
    		m_sprite3.setFlipX(true);
    		m_sprite3.setPosition(s.width / 2, s.height * 3 / 6);
    		m_sprite3.setUnitInterval(0.1f);
    		m_sprite3.setDebugDrawFrameRect(true);
    		m_sprite3.setDebugDrawCollisionRect(true);
    		addChild(m_sprite3);
    		
    		// animation 2 but ignore frame offset
    		m_sprite4 = MWSprite.make(R.raw.test_motion_welder, 1, tex1);
    		m_sprite4.setLoopCount(-1);
    		m_sprite4.setIgnoreFrameOffset(true);
    		m_sprite4.setPosition(s.width / 2, s.height * 2 / 6);
    		m_sprite4.setUnitInterval(0.1f);
    		m_sprite4.setDebugDrawFrameRect(true);
    		m_sprite4.setDebugDrawCollisionRect(true);
    		addChild(m_sprite4);
    		
    		// animation 2 but ignore frame offset, and flip x
    		m_sprite5 = MWSprite.make(R.raw.test_motion_welder, 1, tex1);
    		m_sprite5.setLoopCount(-1);
    		m_sprite5.setIgnoreFrameOffset(true);
    		m_sprite5.setFlipX(true);
    		m_sprite5.setPosition(s.width / 2, s.height / 6);
    		m_sprite5.setUnitInterval(0.1f);
    		m_sprite5.setDebugDrawFrameRect(true);
    		m_sprite5.setDebugDrawCollisionRect(true);
    		addChild(m_sprite5);
    		
    		schedule(new TargetSelector(this, "tick(float)", new Object[] { 0f }));
    		setTouchEnabled(true);
		}
    	
    	public void tick(float delta) {
    		m_sprite1.tick(delta);
    		m_sprite2.tick(delta);
    		m_sprite3.tick(delta);
    		m_sprite4.tick(delta);
    		m_sprite5.tick(delta);
    	}
    	
    	@Override
    	public boolean wyTouchesBegan(MotionEvent event) {
    		m_sprite1.setPaused(!m_sprite1.isPaused());
    		m_sprite2.setPaused(!m_sprite2.isPaused());
    		m_sprite3.setPaused(!m_sprite3.isPaused());
    		m_sprite4.setPaused(!m_sprite4.isPaused());
    		m_sprite5.setPaused(!m_sprite5.isPaused());
    		return true;
    	}

		public void onAFCAnimationEnded(int pointer) {
			Log.d("libwiengine", "onAFCAnimationEnded");
		}

		public void onAFCAnimationFrameChanged(int pointer) {
			Log.d("libwiengine", "onAFCAnimationFrameChanged");
		}
    }
}
