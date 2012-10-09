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
package com.wiyun.engine.tests.event;

import android.content.Context;
import android.view.MotionEvent;
import android.widget.Toast;

import com.wiyun.engine.R;
import com.wiyun.engine.WiEngineTestActivity;
import com.wiyun.engine.nodes.Director;
import com.wiyun.engine.nodes.Layer;
import com.wiyun.engine.nodes.Sprite;
import com.wiyun.engine.opengl.Texture2D;
import com.wiyun.engine.types.WYSize;
import com.wiyun.engine.utils.Utilities;

public class DoubleTapTest extends WiEngineTestActivity {
	@Override
	protected Layer createLayer() {
		return new MyLayer();
	}
	
	@Override
	protected void onStart() {
		super.onStart();
		
		Toast.makeText(this, "Double tap it", Toast.LENGTH_SHORT).show();
	}

	class MyLayer extends Layer {
		private Sprite mSprite;
		
		public MyLayer() {
			WYSize s = Director.getInstance().getWindowSize();
			mSprite = Sprite.make(R.drawable.grossini);
			mSprite.setPosition(s.width / 2, s.height / 2);
            addChild(mSprite);
            
            setDoubleTapEnabled(true);
		}
		
		@Override
		public boolean onDoubleTap(MotionEvent e) {
        	int idx = Utilities.rand(14) + 1;
        	Context context = Director.getInstance().getContext();
        	int id = context.getResources().getIdentifier(String.format("grossini_dance_%02d", idx), "drawable", context.getPackageName());
			mSprite.setTexture(Texture2D.makePNG(id));
			return true;
		}
	}
}
