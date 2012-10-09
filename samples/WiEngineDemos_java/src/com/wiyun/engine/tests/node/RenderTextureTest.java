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

import android.graphics.Typeface;
import android.view.MotionEvent;

import com.wiyun.engine.R;
import com.wiyun.engine.WiEngineTestActivity;
import com.wiyun.engine.nodes.Director;
import com.wiyun.engine.nodes.Label;
import com.wiyun.engine.nodes.Layer;
import com.wiyun.engine.nodes.RenderTexture;
import com.wiyun.engine.nodes.Sprite;
import com.wiyun.engine.types.WYSize;
import com.wiyun.engine.utils.ResolutionIndependent;

public class RenderTextureTest extends WiEngineTestActivity {
	@Override
	protected Layer createLayer() {
		return new MyLayer();
	}

	class MyLayer extends Layer {
		public MyLayer() {
			setTouchEnabled(true);
			
			WYSize s = Director.getInstance().getWindowSize();
            Label label = Label.make("Click to add a masked sprite", 14, Typeface.BOLD);
            label.setPosition(s.width / 2, DP(70));
            addChild(label);
		}

		@Override
		public boolean wyTouchesBegan(MotionEvent event) {
			// prepare src image and mask image, blend function must be set
			// correctly
			Sprite src = Sprite.make(R.drawable.grossini);
			src.autoRelease();
			src.setAnchor(0, 0);
			src.setBlendMode(BlendMode.MODULATE);
			Sprite mask = Sprite.make(R.drawable.mask);
			mask.autoRelease();
			mask.setAnchor(0, 0);

			// use a rendertexture to combine two images, mask first
			WYSize s = Director.getInstance().getWindowSize();
			RenderTexture rt = RenderTexture.make((int)DP(85), (int)DP(121));
			rt.autoRelease();
			rt.beginRender();
			mask.visit();
			src.visit();
			rt.endRender();
			
			// add render texture
			rt.setPosition(s.width / 2, s.height / 2);
			addChild(rt);

			return super.wyTouchesBegan(event);
		}

		private float DP(float v) {
			return ResolutionIndependent.resolveDp(v);
		}
	}
}
