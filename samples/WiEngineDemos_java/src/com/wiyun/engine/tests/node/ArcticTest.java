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
import com.wiyun.engine.afcanim.ArcticSprite;
import com.wiyun.engine.afcanim.AFCSprite.IAFCSpriteCallback;
import com.wiyun.engine.nodes.Director;
import com.wiyun.engine.nodes.Layer;
import com.wiyun.engine.opengl.Texture2D;
import com.wiyun.engine.types.WYSize;
import com.wiyun.engine.utils.TargetSelector;

public class ArcticTest extends WiEngineTestActivity {
	@Override
	protected Layer createLayer() {
		return new MyLayer();
	}
    
    class MyLayer extends Layer implements IAFCSpriteCallback {
    	ArcticSprite m_sprite1;
    	ArcticSprite m_sprite2;
    	ArcticSprite m_sprite3;
    	
    	public MyLayer() {
    		// get texture
    		WYSize s = Director.getInstance().getWindowSize();
    		Texture2D tex1 = Texture2D.makePNG(R.drawable.fighterboby001);
    		tex1.autoRelease();
    		Texture2D tex2 = Texture2D.makePNG(R.drawable.fighterarmor001);
    		tex2.autoRelease();
    		Texture2D tex3 = Texture2D.makePNG(R.drawable.fighterweapon001);
    		tex1.autoRelease();
    		
    		// sprite 1
    		m_sprite1 = ArcticSprite.make(R.raw.fighter, 0, tex1, tex2, tex3);
    		m_sprite1.setLoopCount(-1);
    		m_sprite1.setPosition(s.width / 2, s.height * 3 / 4);
    		m_sprite1.setUnitInterval(0.1f);
    		m_sprite1.setDebugDrawFrameRect(true);
    		m_sprite1.setDebugDrawCollisionRect(true);
    		addChild(m_sprite1);
    		m_sprite1.setAFCSpriteCallback(this);
    		
    		// sprite 2
    		m_sprite2 = ArcticSprite.make(R.raw.fighter, 1, tex1, tex2, tex3);
    		m_sprite2.setLoopCount(-1);
    		m_sprite2.setPosition(s.width / 2, s.height / 2);
    		m_sprite2.setUnitInterval(0.1f);
    		m_sprite2.setDebugDrawFrameRect(true);
    		m_sprite2.setDebugDrawCollisionRect(true);
    		addChild(m_sprite2);
    		
    		// sprite 3
    		m_sprite3 = ArcticSprite.make(R.raw.fighter, 2, tex1, tex2, tex3);
    		m_sprite3.setLoopCount(-1);
    		m_sprite3.setPosition(s.width / 2, s.height / 4);
    		m_sprite3.setUnitInterval(0.1f);
    		m_sprite3.setDebugDrawFrameRect(true);
    		m_sprite3.setDebugDrawCollisionRect(true);
    		addChild(m_sprite3);
    		
    		schedule(new TargetSelector(this, "tick(float)", new Object[] { 0f }));
    		setTouchEnabled(true);
		}
    	
    	public void tick(float delta) {
    		m_sprite1.tick(delta);
    		m_sprite2.tick(delta);
    		m_sprite3.tick(delta);
    	}
    	
    	@Override
    	public boolean wyTouchesBegan(MotionEvent event) {
    		m_sprite1.setPaused(!m_sprite1.isPaused());
    		m_sprite2.setPaused(!m_sprite2.isPaused());
    		m_sprite3.setPaused(!m_sprite3.isPaused());
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
