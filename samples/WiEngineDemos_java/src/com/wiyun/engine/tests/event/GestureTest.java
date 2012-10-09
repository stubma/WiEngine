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

import android.util.Log;
import android.view.MotionEvent;
import android.widget.Toast;

import com.wiyun.engine.WiEngine;
import com.wiyun.engine.WiEngineTestActivity;
import com.wiyun.engine.nodes.Layer;

public class GestureTest extends WiEngineTestActivity {
	@Override
	protected Layer createLayer() {
		return new MyLayer();
	}
	
	@Override
	protected void onStart() {
		super.onStart();
		
        // show hint
        Toast.makeText(this, "This demo prints log, please use 'adb logcat' to view", Toast.LENGTH_SHORT).show();
	}

	class MyLayer extends Layer {
		public MyLayer() {
            setGestureEnabled(true);
		}
		
		@Override
		public boolean onDown(MotionEvent e) {
			Log.d(WiEngine.LOG, "down");
			return true;
		}
		
		@Override
		public void onLongPress(MotionEvent e) {
			Log.d(WiEngine.LOG, "Long press");
		}
		
		@Override
		public boolean onScroll(MotionEvent e1, MotionEvent e2, float distanceX, float distanceY) {
			Log.d(WiEngine.LOG, String.format("onScroll, distanceX: %f, distanceY: %f", distanceX, distanceY));
			return true;
		}
		
		@Override
		public boolean onFling(MotionEvent e1, MotionEvent e2, float velocityX, float velocityY) {
			Log.d(WiEngine.LOG, String.format("onFling, velocityX: %f, velocityY: %f", velocityX, velocityY));
			return true;
		}
		
		@Override
		public void onShowPress(MotionEvent e) {
			Log.d(WiEngine.LOG, "Show press");
		}
	}
}
