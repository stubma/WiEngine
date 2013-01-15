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

import android.view.MotionEvent;

import com.wiyun.engine.R;
import com.wiyun.engine.WiEngineTestActivity;
import com.wiyun.engine.afcanim.AFCClipMapping;
import com.wiyun.engine.afcanim.AuroraSprite;
import com.wiyun.engine.nodes.BitmapFontLabel;
import com.wiyun.engine.nodes.Button;
import com.wiyun.engine.nodes.Director;
import com.wiyun.engine.nodes.Layer;
import com.wiyun.engine.nodes.NinePatchSprite;
import com.wiyun.engine.opengl.Texture2D;
import com.wiyun.engine.types.WYColor3B;
import com.wiyun.engine.types.WYRect;
import com.wiyun.engine.types.WYSize;
import com.wiyun.engine.utils.BitmapFont;
import com.wiyun.engine.utils.ResolutionIndependent;
import com.wiyun.engine.utils.TargetSelector;

public class ClipMappingAuroraGTTest extends WiEngineTestActivity {
	@Override
	protected Layer createLayer() {
		return new MyLayer();
	}

	public class MyLayer extends Layer {
    	AuroraSprite m_sprite1;
		int m_nextMapping;
		
		MyLayer() {
			m_nextMapping = 1;
			
    		// animation 1
    		WYSize s = Director.getInstance().getWindowSize();
    		Texture2D tex1 = Texture2D.make(R.drawable.prince, 0x00ff00ff);
    		tex1.autoRelease();
    		m_sprite1 = AuroraSprite.make(R.raw.prince, 78, tex1);
    		m_sprite1.setLoopCount(-1);
    		m_sprite1.setPosition(s.width / 2, s.height / 2);
    		m_sprite1.setUnitInterval(0.1f);
    		m_sprite1.setDebugDrawFrameRect(true);
    		m_sprite1.setDebugDrawCollisionRect(true);
    		addChild(m_sprite1);

    		// create clip mapping and add them to sprite
    		AFCClipMapping mapping = AFCClipMapping.makeAurora(1, R.raw.prince_m00);
    		mapping.autoRelease();
    		m_sprite1.addClipMapping(mapping);
    		mapping = AFCClipMapping.makeAurora(2, R.raw.prince_m01);
    		mapping.autoRelease();
    		m_sprite1.addClipMapping(mapping);
    		mapping = AFCClipMapping.makeAurora(3, R.raw.prince_m02);
    		mapping.autoRelease();
    		m_sprite1.addClipMapping(mapping);
    		mapping = AFCClipMapping.makeAurora(4, R.raw.prince_m03);
    		mapping.autoRelease();
    		m_sprite1.addClipMapping(mapping);
    		mapping = AFCClipMapping.makeAurora(5, R.raw.prince_m04);
    		mapping.autoRelease();
    		m_sprite1.addClipMapping(mapping);
    		mapping = AFCClipMapping.makeAurora(6, R.raw.prince_m05);
    		mapping.autoRelease();
    		m_sprite1.addClipMapping(mapping);
    		mapping = AFCClipMapping.makeAurora(7, R.raw.prince_m06);
    		mapping.autoRelease();
    		m_sprite1.addClipMapping(mapping);
    		mapping = AFCClipMapping.makeAurora(8, R.raw.prince_m07);
    		mapping.autoRelease();
    		m_sprite1.addClipMapping(mapping);
			
			// add a button to manipulate line
    		NinePatchSprite normal = NinePatchSprite.make(Texture2D.make(R.drawable.btn_normal), 
    				ResolutionIndependent.resolve(WYRect.make(9, 7, 22, 28)));
    		NinePatchSprite pressed = NinePatchSprite.make(Texture2D.make(R.drawable.btn_pressed), 
    				ResolutionIndependent.resolve(WYRect.make(9, 7, 22, 28)));
    		normal.setContentSize(DP(300), DP(44));
    		pressed.setContentSize(DP(300), DP(44));
    		
    		// button
    		Button button = Button.make(normal, pressed, null, null, this, "onSwitchClipMapping");
    		button.setPosition(s.width / 2, DP(70));
    		
    		// label for button
    		BitmapFont font = BitmapFont.loadFont(R.raw.bitmapfont);
            BitmapFontLabel label = BitmapFontLabel.make(font, "Switch Clip Mapping");
            label.setColor(new WYColor3B(255, 255, 0));
            label.setPosition(s.width / 2, DP(70));
            
    		// add
    		addChild(button);
    		addChild(label);
    		
    		schedule(new TargetSelector(this, "tick(float)", new Object[] { 0f }));
    		setTouchEnabled(true);
		}
		
        public void onSwitchClipMapping() {
        	switch(m_nextMapping) {
        		case 0:
        			m_sprite1.playAnimation(78);
        			break;
    			default:
    				m_sprite1.playAnimation(78, m_nextMapping);
    				break;
        	}
        	
        	m_nextMapping++;
        	m_nextMapping %= 9;
        }
        
    	public void tick(float delta) {
    		m_sprite1.tick(delta);
    	}
    	
    	@Override
    	public boolean wyTouchesBegan(MotionEvent event) {
    		m_sprite1.setPaused(!m_sprite1.isPaused());
    		return true;
    	}
		
		private float DP(float v) {
			return ResolutionIndependent.resolveDp(v);
		}
	}
}
