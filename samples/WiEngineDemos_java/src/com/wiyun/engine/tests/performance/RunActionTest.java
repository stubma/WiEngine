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
package com.wiyun.engine.tests.performance;

import java.util.Random;

import com.wiyun.engine.R;
import com.wiyun.engine.WiEngineTestActivity;
import com.wiyun.engine.actions.RepeatForever;
import com.wiyun.engine.actions.RotateBy;
import com.wiyun.engine.nodes.BitmapFontLabel;
import com.wiyun.engine.nodes.Button;
import com.wiyun.engine.nodes.Director;
import com.wiyun.engine.nodes.Label;
import com.wiyun.engine.nodes.Layer;
import com.wiyun.engine.nodes.NinePatchSprite;
import com.wiyun.engine.nodes.Sprite;
import com.wiyun.engine.opengl.Texture2D;
import com.wiyun.engine.types.WYColor3B;
import com.wiyun.engine.types.WYRect;
import com.wiyun.engine.types.WYSize;
import com.wiyun.engine.utils.BitmapFont;
import com.wiyun.engine.utils.ResolutionIndependent;
import com.wiyun.engine.utils.TargetSelector;

public class RunActionTest extends WiEngineTestActivity {
	MyLayer mLayer;
	
	@Override
	protected Layer createLayer() {
		mLayer =  new MyLayer();
		return mLayer;
	}
	
	public class MyLayer extends Layer {
		Label m_countLabel;
		int m_count;
			
		MyLayer() {
			// add sprite button
			WYSize s = Director.getInstance().getWindowSize();
			createButton("Add 50 Sprites", this, s.width / 2, s.height - DP(40),
					  new TargetSelector(this, "onAddSprite", null));

			// count label
			m_countLabel = Label.make("0 Sprites", SP(16));
			m_countLabel.setPosition(s.width / 2, s.height - DP(80));
			m_countLabel.setColor(new WYColor3B(255, 0, 0));
			addChild(m_countLabel);
			m_count = 0;
		}
		
		private float DP(float v) {
			return ResolutionIndependent.resolveDp(v);
		}
		
		private float SP(float v) {
			return ResolutionIndependent.resolveSp(v);
		}
		
	    void createButton(String label, Layer layer, float x, float y, TargetSelector ts) {
	    	Texture2D normalTex = Texture2D.make(R.drawable.btn_normal);
	    	normalTex.autoRelease();
	    	Texture2D pressedTex = Texture2D.make(R.drawable.btn_pressed);
	    	pressedTex.autoRelease();
			NinePatchSprite normal1 = NinePatchSprite.make(normalTex, WYRect.make(DP(9), DP(7), DP(22), DP(28)));
			NinePatchSprite pressed1 = NinePatchSprite.make(pressedTex, WYRect.make(DP(9), DP(7), DP(22), DP(28)));
			normal1.setContentSize(DP(300), DP(44));
			pressed1.setContentSize(DP(300), DP(44));
	        
			Button button1 = Button.make(normal1, pressed1, null, null, null, ts);
			button1.setPosition(x, y);
	        
			BitmapFont font = BitmapFont.loadFont(R.raw.bitmapfont);
			BitmapFontLabel label1 = BitmapFontLabel.make(font, label);
			label1.setColor(new WYColor3B(255, 255, 0));
			label1.setPosition(x, y);
	        
			layer.addChild(button1);
			layer.addChild(label1);
		}
	    
		public void onAddSprite() {
			WYSize s = Director.getInstance().getWindowSize();
			Random r = new Random();
			Texture2D tex = Texture2D.make(R.drawable.blocks);
			tex.autoRelease();
			float size = DP(32.0f);
			for(int i = 0; i < 50; i++) {
				Sprite sp = Sprite.make(tex, WYRect.make(r.nextInt(2) * size, r.nextInt(2) * size, size, size));
				sp.setPosition(r.nextInt((int)s.width), r.nextInt((int)s.height));
				RotateBy rotate = RotateBy.make(r.nextInt(11), 360);
				rotate.autoRelease();
				RepeatForever rf = RepeatForever.make(rotate);
				rf.autoRelease();
				sp.runAction(rf);
				addChild(sp, -1);
			}

			// update count label
			m_count += 50;
			m_countLabel.setText(String.format("%d Sprites", m_count));
		}
	}
}
