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

import android.widget.Toast;

import com.wiyun.engine.R;
import com.wiyun.engine.WiEngineTestActivity;
import com.wiyun.engine.nodes.Button;
import com.wiyun.engine.nodes.Sprite;
import com.wiyun.engine.nodes.Director;
import com.wiyun.engine.nodes.Layer;
import com.wiyun.engine.opengl.Texture2D;
import com.wiyun.engine.types.WYRect;
import com.wiyun.engine.types.WYSize;
import com.wiyun.engine.utils.ResolutionIndependent;

public class AtlasButtonTest extends WiEngineTestActivity {
    public static final int kTagMenu = 1;
    public static final int kTagMenu0 = 0;
    public static final int kTagMenu1 = 1;

    public static final int kTagSpriteManager = 1;

	@Override
	protected Layer createLayer() {
		return new MyLayer();
	}

    class MyLayer extends Layer {
        public MyLayer() {
        	WYSize s = Director.getInstance().getWindowSize();
            
            // create sprites
            Texture2D tex = Texture2D.makePNG(R.drawable.menuitemsprite);
            Sprite spriteNormal = Sprite.make(tex,
            		ResolutionIndependent.resolve(WYRect.make(0, 23 * 2, 115, 23)));
            Sprite spriteSelected = Sprite.make(tex,
            		ResolutionIndependent.resolve(WYRect.make(0, 23 * 1, 115, 23)));
            Sprite spriteDisabled = Sprite.make(tex,
            		ResolutionIndependent.resolve(WYRect.make(0, 23 * 0, 115, 23)));
            
            // create atlas button
            Button button2 = Button.make(spriteNormal, spriteSelected, spriteDisabled, null, this, "onButtonClicked");
            button2.setClickScale(1.4f);
            button2.setPosition(s.width / 2, s.height / 2);

            addChild(button2);
        }

        public void onButtonClicked() {
        	runOnUiThread(new Runnable() {
				public void run() {
					Toast.makeText(AtlasButtonTest.this, "button clicked", Toast.LENGTH_SHORT).show();
				}
			});
        }
    }
}
