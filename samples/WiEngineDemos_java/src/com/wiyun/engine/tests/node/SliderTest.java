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

public class SliderTest extends WiEngineTestActivity {
	@Override
	protected Layer createLayer() {
		return new MyLayer();
	}

    class MyLayer extends Layer implements ISliderCallback {
    	private Label mLabel;
    	
        public MyLayer() {
        	WYSize s = Director.getInstance().getWindowSize();
        	
    		// slider 1
    		Sprite bar = Sprite.make(R.drawable.bar);
    		Sprite thumb1 = Sprite.make(R.drawable.thumb);
    		Slider slider1 = Slider.make(null, bar, thumb1);
    		slider1.setValue(50);
    		slider1.setShowFullBar(true);
    		slider1.setAnchor(0, 0);
    		slider1.setPosition(DP(20), s.height * 2 / 3);
    		slider1.setCallback(this);
    		addChild(slider1);

    		// slider2
    		Sprite thumb2 = Sprite.make(R.drawable.thumb);
    		Slider slider2 = Slider.make(null, bar, thumb2);
    		slider2.setValue(50);
    		slider2.setAnchor(0, 0);
    		slider2.setPosition(DP(20), s.height / 3);
    		slider2.setCallback(this);
    		addChild(slider2);

    		// slider3
    		Sprite vbar = Sprite.make(R.drawable.vbar);
    		Sprite thumb3 = Sprite.make(R.drawable.thumb);
    		Slider slider3 = Slider.make(null, vbar, thumb3, true);
    		slider3.setValue(50);
    		slider3.setShowFullBar(true);
    		slider3.setPosition(s.width - DP(50), s.height * 3 / 4);
    		slider3.setCallback(this);
    		addChild(slider3);

    		// slider4
    		Sprite thumb4 = Sprite.make(R.drawable.thumb);
    		Slider slider4 = Slider.make(null, vbar, thumb4, true);
    		slider4.setValue(50);
    		slider4.setPosition(s.width - DP(50), s.height / 4);
    		slider4.setCallback(this);
    		addChild(slider4);
    		
    		// create hint label
    		mLabel = Label.make("hint label");
    		mLabel.setPosition(s.width / 2, s.height / 2);
    		addChild(mLabel);
        }
        
        private float DP(float v) {
        	return ResolutionIndependent.resolveDp(v);
        }

		@Override
		public void onSliderValueChanged(int pointer, float value) {
			Slider slider = Slider.from(pointer);
			mLabel.setText(String.format("%.2f", slider.getValue()));
		}
    }
}
