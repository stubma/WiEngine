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

import android.os.Build;
import android.view.MotionEvent;

import com.wiyun.engine.R;
import com.wiyun.engine.WiEngineTestActivity;
import com.wiyun.engine.nodes.Director;
import com.wiyun.engine.nodes.Layer;
import com.wiyun.engine.nodes.Sprite;
import com.wiyun.engine.types.WYPoint;
import com.wiyun.engine.types.WYSize;

public class MultiTouchTest extends WiEngineTestActivity {
	@Override
	protected Layer createLayer() {
		return new MyLayer();
	}
	
    @Override
    protected String checkPrecondition() {
    	return Build.VERSION.SDK_INT > 4 ? null : "This demo requires Android 2.0 or higher version";
    }

	class MyLayer extends Layer {
		Sprite mSprite;
		
		boolean mScaling;
		float mInitDistance;
		float mInitScale;

		public MyLayer() {
			WYSize s = Director.getInstance().getWindowSize();
			mSprite = Sprite.make(R.drawable.grossini);
			addChild(mSprite);
			mSprite.setPosition(s.width / 2, s.height / 2);
			
			setTouchEnabled(true);
		}
		
		@Override
		public boolean wyTouchesBegan(MotionEvent event) {
			return true;
		}

		@Override
		public boolean wyTouchesPointerBegan(MotionEvent event) {
			if(event.getPointerCount() == 2) {
				mScaling = true;
				mInitScale = mSprite.getScale();
				
				// remember init distance
				WYPoint loc1 = Director.getInstance().convertToGL(event.getX(0), event.getY(0));
				WYPoint loc2 = Director.getInstance().convertToGL(event.getX(1), event.getY(1));
				mInitDistance = WYPoint.distance(loc1, loc2);
			} else {
				mScaling = false;
			}
			
			return true;
		}
		
		@Override
		public boolean wyTouchesPointerEnded(MotionEvent event) {
			mScaling = event.getPointerCount() == 3;
			return true;
		}
		
		@Override
		public boolean wyTouchesMoved(MotionEvent event) {
			if(mScaling) {
				// get distance
				WYPoint loc1 = Director.getInstance().convertToGL(event.getX(0), event.getY(0));
				WYPoint loc2 = Director.getInstance().convertToGL(event.getX(1), event.getY(1));
				float distance = WYPoint.distance(loc1, loc2);
				
				// set scale factor
				mSprite.setScale(mInitScale * distance / mInitDistance);
			}
			
			return true;
		}
		
		@Override
		public boolean wyTouchesEnded(MotionEvent event) {
			mScaling = event.getPointerCount() == 3;
			return true;
		}
		
		@Override
		public boolean wyTouchesCancelled(MotionEvent event) {
			mScaling = event.getPointerCount() == 3;
			return true;
		}
	}
}