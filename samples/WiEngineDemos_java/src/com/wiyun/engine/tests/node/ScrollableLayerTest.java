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

import android.widget.Toast;

import com.wiyun.engine.R;
import com.wiyun.engine.WiEngineTestActivity;
import com.wiyun.engine.nodes.BitmapFontLabel;
import com.wiyun.engine.nodes.Button;
import com.wiyun.engine.nodes.Director;
import com.wiyun.engine.nodes.Label;
import com.wiyun.engine.nodes.Layer;
import com.wiyun.engine.nodes.NinePatchSprite;
import com.wiyun.engine.nodes.ScrollableLayer;
import com.wiyun.engine.nodes.ScrollableLayer.IScrollableLayerCallback;
import com.wiyun.engine.opengl.Texture2D;
import com.wiyun.engine.types.WYColor3B;
import com.wiyun.engine.types.WYColor4B;
import com.wiyun.engine.types.WYRect;
import com.wiyun.engine.types.WYSize;
import com.wiyun.engine.utils.BitmapFont;
import com.wiyun.engine.utils.ResolutionIndependent;
import com.wiyun.engine.utils.TargetSelector;


public class ScrollableLayerTest extends WiEngineTestActivity {
	@Override
	protected Layer createLayer() {
		return new MyLayer();
	}
    
    class MyLayer extends Layer implements IScrollableLayerCallback {
    	private Label mLabel;
    	
        public MyLayer() {
    		// create scrollable layer
        	WYSize s = Director.getInstance().getWindowSize();
    		ScrollableLayer layer = ScrollableLayer.make(WYColor4B.make(255, 0, 0, 60));
    		layer.setContentSize(s.width - DP(60), s.height - DP(60));
    		layer.setRelativeAnchorPoint(true);
    		layer.setPosition(s.width / 2, s.height / 2);
    		layer.setVertical(true);
    		layer.setHorizontal(true);
    		layer.setLeftMargin(DP(30));
    		layer.setRightMargin(DP(30));
    		layer.setTopMargin(DP(20));
    		layer.setBottomMargin(DP(20));
    		layer.setCallback(this);
    		addChild(layer);
    		
    		// create thumb bar
    		NinePatchSprite hThumb = NinePatchSprite.make(Texture2D.makePNG(R.drawable.horizontal_thumb), WYRect.make(DP(7), DP(5), DP(1), DP(1)));
    		NinePatchSprite vThumb = NinePatchSprite.make(Texture2D.makePNG(R.drawable.vertical_thumb), WYRect.make(DP(5), DP(7), DP(1), DP(1)));
    		
    		// set thumb bar
    		layer.setHorizontalThumb(hThumb);
    		layer.setVerticalThumb(vThumb);
    		layer.setThumbFadeOutTime(2.f);

    		// add scrollable item to layer, you can't use addChild
    		BitmapFont font = BitmapFont.loadFont(R.raw.bitmapfont);
    		NinePatchSprite normal1 = NinePatchSprite.make(Texture2D.makePNG(R.drawable.btn_normal), WYRect.make(DP(9), DP(7), DP(22), DP(28)));
    		NinePatchSprite pressed1 = NinePatchSprite.make(Texture2D.makePNG(R.drawable.btn_pressed), WYRect.make(DP(9), DP(7), DP(22), DP(28)));
    		normal1.setContentSize(DP(300), DP(44));
    		pressed1.setContentSize(DP(300), DP(44));
    		for(int i = 0; i < 100; i++) {
    			// button
    			Button button = Button.make(normal1, pressed1, null, null, 
    					new TargetSelector(this, "onButtonClicked(int)", new Object[] { 100 - i }));
    			button.setPosition(0, DP(60) * i);

    			// label for button 1
    	        BitmapFontLabel label = BitmapFontLabel.make(font, "Button " + (100 - i));
    	        label.setColor(WYColor3B.make(255, 255, 0));
    	        label.setPosition(0, DP(60) * i);

    			// add
    			layer.addScrollableChild(button);
    			layer.addScrollableChild(label);
    		}
    		
    		// create hint label
    		mLabel = Label.make("hint label", 20);
    		mLabel.setPosition(s.width / 2, s.height / 2);
    		addChild(mLabel);
        }
        
		private float DP(float v) {
			return ResolutionIndependent.resolveDp(v);
		}
		
		public void onButtonClicked(final int index) {
			runOnUiThread(new Runnable() {
				public void run() {
					Toast.makeText(ScrollableLayerTest.this, "Button " + index + " clicked", Toast.LENGTH_SHORT).show();
				}
			});
		}

		public void onEndFling(int layerPointer) {
			mLabel.setText("onEndFling");
		}

		public void onScrollOffsetChanged(int layerPointer) {
			ScrollableLayer layer = ScrollableLayer.from(layerPointer);
			mLabel.setText(String.format("Offset Changed: %.1f, %.1f", layer.getOffsetX(), layer.getOffsetY()));
		}

		public void onStartFling(int layerPointer) {
			mLabel.setText("onStartFling");
		}

		@Override
        public void onScrollableChildNotVisible(int layerPointer, int childPointer) {
        }
    }
}
