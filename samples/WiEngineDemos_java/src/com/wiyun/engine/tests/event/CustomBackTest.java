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

import android.app.AlertDialog;
import android.app.AlertDialog.Builder;
import android.content.DialogInterface;
import android.content.DialogInterface.OnClickListener;
import android.graphics.Typeface;

import com.wiyun.engine.WiEngineTestActivity;
import com.wiyun.engine.nodes.Director;
import com.wiyun.engine.nodes.Label;
import com.wiyun.engine.nodes.Scene;
import com.wiyun.engine.types.WYSize;

public class CustomBackTest extends WiEngineTestActivity {
	@Override
	protected void createScene() {
		mScene = new MyScene();
	}
	
	void showExitConfirm() {
		runOnUiThread(new Runnable() {
			public void run() {
				AlertDialog.Builder builder = new Builder(CustomBackTest.this);
				builder.setMessage("Do you really want to exit current demo?")
				.setNegativeButton("No", null)
				.setPositiveButton("Yes", new OnClickListener() {
					public void onClick(DialogInterface dialog, int which) {
						finish();
					}
				}).show();
			}
		});
	}

	class MyScene extends Scene {
		public MyScene() {
			/*
			 * Scene类缺省是处理back键的，但是我们有很多方式可以自定义处理back键
			 * 1. 继承Scene，覆盖onBackButton
			 * 2. 禁止Scene处理key事件(setKeyEnabled(false))，让其它节点处理
			 * 3. 添加一个优先级比Scene高的key事件处理器，相当于不让Scene处理, Scene缺省的优先级是0，指定一个
			 * 比0大的数就行
			 *
			 * 这个demo用第一种方式
			 */
			
            // add labels
            WYSize s = Director.getInstance().getWindowSize();
            Label label = Label.make("Please press back key", 16, Typeface.BOLD);
            label.setPosition(s.width / 2, s.height / 2);
            addChild(label);
            
            //　必须调用一次，使事件重定向到java端
            setKeyEnabled(true);
            
            autoRelease(true);
		}
		
		@Override
		protected boolean onBackButton() {
			showExitConfirm();
			return true;
		}
	}
}
