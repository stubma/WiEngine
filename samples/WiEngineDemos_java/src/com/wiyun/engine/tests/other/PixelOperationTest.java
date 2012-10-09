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

import java.nio.IntBuffer;

import com.wiyun.engine.R;
import com.wiyun.engine.WiEngineTestActivity;
import com.wiyun.engine.nodes.BitmapFontLabel;
import com.wiyun.engine.nodes.Button;
import com.wiyun.engine.nodes.Director;
import com.wiyun.engine.nodes.INodeVirtualMethods;
import com.wiyun.engine.nodes.Layer;
import com.wiyun.engine.nodes.NinePatchSprite;
import com.wiyun.engine.nodes.Sprite;
import com.wiyun.engine.opengl.Texture2D;
import com.wiyun.engine.opengl.TextureManager;
import com.wiyun.engine.types.WYColor3B;
import com.wiyun.engine.types.WYRect;
import com.wiyun.engine.types.WYSize;
import com.wiyun.engine.utils.BitmapFont;
import com.wiyun.engine.utils.BitmapRawData;
import com.wiyun.engine.utils.ResolutionIndependent;
import com.wiyun.engine.utils.Utilities;

public class PixelOperationTest extends WiEngineTestActivity {
	@Override
	protected Layer createLayer() {
		return new MyLayer();
	}

	public class MyLayer extends Layer implements INodeVirtualMethods {
		BitmapRawData mRawData;
		IntBuffer mRawBuffer;
		Texture2D mTex;
		int mLine;
		
		MyLayer() {
			WYSize s = Director.getInstance().getWindowSize();
			
			// load raw data and create texture from raw data
			mRawData = Utilities.loadPNG(R.drawable.grossini);
			mRawBuffer = mRawData.asIntBuffer();
			mTex = Texture2D.make(mRawData);
			mTex.autoRelease();
			Sprite sprite = Sprite.make(mTex);
			sprite.setPosition(s.width / 2, s.height / 2);
			addChild(sprite);
			
			// add a button to manipulate line
    		NinePatchSprite normal = NinePatchSprite.make(Texture2D.makePNG(R.drawable.btn_normal), 
    				ResolutionIndependent.resolve(WYRect.make(9, 7, 22, 28)));
    		NinePatchSprite pressed = NinePatchSprite.make(Texture2D.makePNG(R.drawable.btn_pressed), 
    				ResolutionIndependent.resolve(WYRect.make(9, 7, 22, 28)));
    		normal.setContentSize(DP(300), DP(44));
    		pressed.setContentSize(DP(300), DP(44));
    		
    		// button
    		Button button = Button.make(normal, pressed, null, null, this, "onButtonClicked");
    		button.setPosition(s.width / 2, DP(70));
    		
    		// label for button
    		BitmapFont font = BitmapFont.loadFont(R.raw.bitmapfont);
            BitmapFontLabel label = BitmapFontLabel.make(font, "Make a Line Blue");
            label.setColor(new WYColor3B(255, 255, 0));
            label.setPosition(s.width / 2, DP(70));
            
    		// add
    		addChild(button);
    		addChild(label);
		}
		
        public void onButtonClicked() {
        	/*
        	 * 把一行变为蓝色, 这里我们用得到的IntBuffer来操作, 写起来
        	 * 简单一些
        	 */
        	int start = mLine * mRawData.width;
        	mRawBuffer.position(start);
        	for(int x = 0; x < mRawData.width; x++) {
        		mRawBuffer.put(0x0000ffff);
        	}
        	
        	/*
        	 * 这是不用IntBuffer时, 直接用byte字节数组操作的方式, 会烦琐一些,
        	 * 列在这里做个对比
        	 */
//        	int start = mLine * mRawData.width * 4;
//        	for(int x = 0; x < mRawData.width * 4; x += 4) {
//        		mRawData.data[start + x] = 0x00; // R
//        		mRawData.data[start + x + 1] = 0x00; // G
//        		mRawData.data[start + x + 2] = (byte)0xFF; // B
//        		mRawData.data[start + x + 3] = (byte)0xFF; // A
//        	}
        	
        	mLine++;
        	mTex.updateRaw(mRawData);
        }
		
		private float DP(float v) {
			return ResolutionIndependent.resolveDp(v);
		}

		@Override
		public void jDraw() {
		}

		@Override
		public void jOnEnter() {
		}

		@Override
		public void jOnEnterTransitionDidFinish() {
		}

		@Override
		public void jOnExit() {
			mRawData.destroy();
			TextureManager.getInstance().removeTexture(mTex, true);
		}
	}
}
