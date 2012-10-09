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

import static android.view.KeyEvent.KEYCODE_BACK;
import static android.view.KeyEvent.KEYCODE_DPAD_CENTER;
import static android.view.KeyEvent.KEYCODE_DPAD_DOWN;
import static android.view.KeyEvent.KEYCODE_DPAD_LEFT;
import static android.view.KeyEvent.KEYCODE_DPAD_RIGHT;
import static android.view.KeyEvent.KEYCODE_DPAD_UP;
import static android.view.KeyEvent.KEYCODE_MENU;
import static android.view.KeyEvent.KEYCODE_SEARCH;
import android.os.Bundle;
import android.view.KeyEvent;

import com.wiyun.engine.WiEngineTestActivity;
import com.wiyun.engine.nodes.Director;
import com.wiyun.engine.nodes.Label;
import com.wiyun.engine.nodes.Layer;
import com.wiyun.engine.types.WYSize;

public class KeyTest extends WiEngineTestActivity {
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);

		mGLSurfaceView.disableSystemHandleMenuKey();
	}
	
	@Override
	protected Layer createLayer() {
		return new MyLayer();
	}

	class MyLayer extends Layer {
		static final int TAG_SPRITE = 1;
		
		private Label mLabel;

		public MyLayer() {
			WYSize s = Director.getInstance().getWindowSize();
			mLabel = Label.make("KeyEvent Test", 32);
			addChild(mLabel);
			mLabel.setPosition(s.width / 2, s.height / 2);
			
			setKeyEnabled(true);
		}
		
		@Override
		public boolean wyKeyDown(KeyEvent event) {
			mLabel.setText(getKeyCodeString(event) + " Event Down");
			
			// don't handle back key
			if(event.getKeyCode() == KEYCODE_BACK)
				return false;
			else
				return true;
		}
		
		@Override
		public boolean wyKeyUp(KeyEvent event) {
			mLabel.setText(getKeyCodeString(event) + " Event Up");
			return super.wyKeyUp(event);
		}
		
		private String getKeyCodeString(KeyEvent event) {
			int kc = event.getKeyCode();
			switch(kc) {
				case KEYCODE_BACK:
					return "Back";
				case KEYCODE_MENU:
					return "Menu";
				case KEYCODE_SEARCH:
					return "Search";
				case KEYCODE_DPAD_DOWN:
					return "Down";
				case KEYCODE_DPAD_UP:
					return "Up";
				case KEYCODE_DPAD_LEFT:
					return "Left";
				case KEYCODE_DPAD_RIGHT:
					return "Right";
				case KEYCODE_DPAD_CENTER:
					return "Center";
				default:
					return "Key";
			}
		}
	}
}
