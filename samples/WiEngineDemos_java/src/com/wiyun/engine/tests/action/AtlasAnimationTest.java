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
package com.wiyun.engine.tests.action;

import com.wiyun.engine.R;
import com.wiyun.engine.WiEngineTestActivity;
import com.wiyun.engine.actions.Animate;
import com.wiyun.engine.nodes.Animation;
import com.wiyun.engine.nodes.Animation.IAnimationCallback;
import com.wiyun.engine.nodes.Director;
import com.wiyun.engine.nodes.Label;
import com.wiyun.engine.nodes.Layer;
import com.wiyun.engine.nodes.Sprite;
import com.wiyun.engine.nodes.SpriteFrame;
import com.wiyun.engine.opengl.Texture2D;
import com.wiyun.engine.types.WYSize;
import com.wiyun.engine.utils.ZwoptexManager;

public class AtlasAnimationTest extends WiEngineTestActivity {
    @Override
    protected Layer createLayer() {
    	return new MyLayer();
    }
    
    class MyLayer extends Layer implements IAnimationCallback {
    	public static final int TAG_SPRITE_MANAGER = 1;
    	
    	private Label mLabel;
    	
        public MyLayer() {
            WYSize s = Director.getInstance().getWindowSize();

            // add sprite
			ZwoptexManager.addZwoptex("grossini", R.raw.grossini_dance_atlas, Texture2D.makePNG(R.drawable.grossini_dance_atlas));
            Sprite sprite = ZwoptexManager.makeSprite("grossini_dance_01.png");
            addChild(sprite);
            sprite.setPosition(s.width / 2, s.height / 2);
            
            // create animation and add it to atlas sprite
            Animation anim = new Animation(0);
            for(int i = 1; i <= 14; i++) {
    			SpriteFrame f = ZwoptexManager.getSpriteFrame(String.format("grossini_dance_%02d.png", i));
    			f.setDuration(0.2f);
				anim.addFrame(f);
            }
            anim.setCallback(this);
            
            Animate a = (Animate)Animate.make(anim).autoRelease();
            sprite.runAction(a);
            
            // hint label
            mLabel = Label.make("callback display label", 20);
            mLabel.setPosition(s.width / 2, 100);
            addChild(mLabel);
        }
        
		public void onAnimationEnded(int animPointer) {
			mLabel.setText("animation ended");
		}

		public void onAnimationFrameChanged(int animPointer, int index) {
			mLabel.setText("frame changed: " + index);
		}
    }
}
