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
package com.wiyun.engine.tests.other;

import com.wiyun.engine.R;
import com.wiyun.engine.WiEngineTestActivity;
import com.wiyun.engine.nodes.Director;
import com.wiyun.engine.nodes.Layer;
import com.wiyun.engine.nodes.Sprite;
import com.wiyun.engine.opengl.Texture2D;
import com.wiyun.engine.types.WYSize;
import com.wiyun.engine.utils.ResourceDecoder;

public class ResourceDecoderTest extends WiEngineTestActivity {
	MyLayer mLayer;
	
	@Override
	protected Layer createLayer() {
		mLayer =  new MyLayer();
		return mLayer;
	}

	public class MyLayer extends Layer implements ResourceDecoder {
		public MyLayer() {
			Director.setResourceDecoder(this);
			
			WYSize s = Director.getInstance().getWindowSize();
			Sprite sprite = Sprite.make(Texture2D.make(R.drawable.grossini_encoded));
			sprite.setPosition(s.width / 2, s.height / 2);
		    addChild(sprite);
		    
		    autoRelease(true);
		}
		
		@Override
	    public byte[] decode(byte[] data) {
			byte[] ret = new byte[data.length];
			for(int i = 0; i < data.length; i++) {
				ret[i] = (byte)(~data[i] & 0xFF);
			}
			return ret;
	    }
	}
}
