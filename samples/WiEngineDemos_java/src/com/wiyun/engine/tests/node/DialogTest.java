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

import android.app.Activity;
import android.widget.Toast;

import com.wiyun.engine.R;
import com.wiyun.engine.WiEngineTestActivity;
import com.wiyun.engine.dialog.Dialog;
import com.wiyun.engine.dialog.DialogPopupTransition;
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

public class DialogTest extends WiEngineTestActivity {
	@Override
	protected Layer createLayer() {
		return new MyLayer();
	}
    
    class MyLayer extends Layer {
    	public MyLayer() {
    		WYSize s = Director.getInstance().getWindowSize();
    		createButton("Alert Dialog", this, s.width / 2, s.height / 2,
    				new TargetSelector(this, "onAlertDialog(float)", new Object[] { 0f }));
		}
    	
    	void createButton(String label, Layer layer, float x, float y, TargetSelector ts) {
    		NinePatchSprite normal1 = NinePatchSprite.make(Texture2D.makePNG(R.drawable.btn_normal), WYRect.make(DP(9), DP(7), DP(22), DP(28)));
    		NinePatchSprite pressed1 = NinePatchSprite.make(Texture2D.makePNG(R.drawable.btn_pressed), WYRect.make(DP(9), DP(7), DP(22), DP(28)));
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
    	
    	float DP(float v) {
    		return ResolutionIndependent.resolveDp(v);
    	}
    	
    	float SP(float v) {
    		return ResolutionIndependent.resolveSp(v);
    	}
    	
    	public void onAlertDialog(float delta) {
    		// title and message node for dialog
    		BitmapFontLabel title = BitmapFontLabel.make(BitmapFont.loadFont(R.raw.bitmapfont2_angelcode_xml, BitmapFont.BFF_ANGELCODE_XML), "Alert");
    		BitmapFontLabel content = BitmapFontLabel.make(BitmapFont.loadFont(R.raw.bitmapfont), "Hello this is a dialog demo\n\nHave fun!");
    		content.setColor(new WYColor3B(0, 0, 0));
    		content.setAlignment(BitmapFontLabel.CENTER);
    		title.autoRelease();
    		content.autoRelease();

    		// background of dialog
    		NinePatchSprite bg = NinePatchSprite.make(Texture2D.makePNG(R.drawable.dialog_bg), WYRect.make(DP(130), DP(20), DP(1), DP(1)));
    		bg.autoRelease();

    		// ok button
    		Sprite okBtn = Sprite.make(Texture2D.makePNG(R.drawable.dialog_btn));
    		Label okLabel = Label.make("OK", 20);
    		okLabel.setColor(new WYColor3B(96, 56, 19));
    		okBtn.autoRelease();
    		okLabel.autoRelease();

    		// cancel button
    		Sprite cancelBtn = Sprite.make(Texture2D.makePNG(R.drawable.dialog_btn));
    		Label cancelLabel = Label.make("Cancel", 20);
    		cancelLabel.setColor(new WYColor3B(96, 56, 19));
    		cancelBtn.autoRelease();
    		cancelLabel.autoRelease();

    		// create dialog and show
    		Dialog dialog = Dialog.make();
    		dialog.setBackground(bg)
    				.setBackgroundPadding(DP(20), DP(20), DP(20), DP(15))
    				.setTitle(title)
    				.setContent(content)
    				.addTwoColumnsButton(okBtn, okLabel, new TargetSelector(this, "onOKButton(float,Object)", new Object[] { 0f, dialog }),
    						cancelBtn, cancelLabel, null)
    				// Button can be layouted in one column or two columns, you must ensure button size is fine
//    				.addButton(okBtn, okLabel, new TargetSelector(this, "onOKButton(float,Object)", new Object[] { 0f, dialog }))
//    				.addButton(cancelBtn, cancelLabel, null)
    				.setTransition(DialogPopupTransition.make())
    				.setBackKeyEquivalentButtonIndex(1)
    				.show(true);
    		dialog.autoRelease();
    	}
    	
    	public void onOKButton(float delta, Object d) {
    		Dialog dialog = (Dialog)d;
    		((Activity)Director.getInstance().getContext()).runOnUiThread(new Runnable() {
				public void run() {
					Toast.makeText(Director.getInstance().getContext(), "OK button clicked", Toast.LENGTH_SHORT).show();
				}
			});
    		dialog.dismiss(true);
    	}
    }
}
