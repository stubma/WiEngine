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

public class NinePatchButtonTest extends WiEngineTestActivity {
	@Override
	protected Layer createLayer() {
		return new MyLayer();
	}

    class MyLayer extends Layer {
        public MyLayer() {
    		// sprite for button1
    		NinePatchSprite normal1 = NinePatchSprite.make(Texture2D.makePNG(R.drawable.btn_normal), 
    				ResolutionIndependent.resolve(WYRect.make(9, 7, 22, 28)));
    		NinePatchSprite pressed1 = NinePatchSprite.make(Texture2D.makePNG(R.drawable.btn_pressed), 
    				ResolutionIndependent.resolve(WYRect.make(9, 7, 22, 28)));
    		normal1.setContentSize(ResolutionIndependent.resolveDp(300), ResolutionIndependent.resolveDp(44));
    		pressed1.setContentSize(ResolutionIndependent.resolveDp(300), ResolutionIndependent.resolveDp(44));

    		// sprite for button2
    		NinePatchSprite normal2 = NinePatchSprite.make(Texture2D.makePNG(R.drawable.btn_normal), 
    				ResolutionIndependent.resolve(WYRect.make(9, 7, 22, 28)));
    		NinePatchSprite pressed2 = NinePatchSprite.make(Texture2D.makePNG(R.drawable.btn_pressed), 
    				ResolutionIndependent.resolve(WYRect.make(9, 7, 22, 28)));
    		normal2.setContentSize(ResolutionIndependent.resolveDp(100), ResolutionIndependent.resolveDp(44));
    		pressed2.setContentSize(ResolutionIndependent.resolveDp(100), ResolutionIndependent.resolveDp(44));

    		// button 1
    		WYSize s = Director.getInstance().getWindowSize();
    		Button button1 = Button.make(normal1, pressed1, null, null, this, "onButtonClicked");
    		button1.setPosition(s.width / 2, s.height / 2 + ResolutionIndependent.resolveDp(40));

    		// button 2
    		Button button2 = Button.make(normal2, pressed2, null, null, this, "onButtonClicked");
    		button2.setPosition(s.width / 2, s.height / 2 - ResolutionIndependent.resolveDp(40));

    		// label for button 1
    		BitmapFont font = BitmapFont.loadFont(R.raw.bitmapfont);
            BitmapFontLabel label1 = BitmapFontLabel.make(font, "Long Long Long Long");
            label1.setColor(new WYColor3B(255, 255, 0));
            label1.setPosition(s.width / 2, s.height / 2 + ResolutionIndependent.resolveDp(40));
            
    		// label for button 2
            BitmapFontLabel label2 = BitmapFontLabel.make(font, "Short");
            label2.setColor(new WYColor3B(255, 0, 255));
            label2.setPosition(s.width / 2, s.height / 2 - ResolutionIndependent.resolveDp(40));

    		// add
    		addChild(button1);
    		addChild(button2);
    		addChild(label1);
    		addChild(label2);
        }

        public void onButtonClicked() {
        	runOnUiThread(new Runnable() {
				public void run() {
					Toast.makeText(NinePatchButtonTest.this, "button clicked", Toast.LENGTH_SHORT).show();
				}
			});
        }
    }
}
