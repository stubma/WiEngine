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

import android.os.Build;
import android.view.MotionEvent;

import com.wiyun.engine.R;
import com.wiyun.engine.WiEngineTestActivity;
import com.wiyun.engine.nodes.Director;
import com.wiyun.engine.nodes.Layer;
import com.wiyun.engine.nodes.TiledSprite;
import com.wiyun.engine.opengl.Texture2D;
import com.wiyun.engine.types.WYPoint;
import com.wiyun.engine.utils.ResolutionIndependent;

public class TiledSpriteTest extends WiEngineTestActivity {
	@Override
	protected Layer createLayer() {
		return new MyLayer();
	}
	
    @Override
    protected String checkPrecondition() {
    	return Build.VERSION.SDK_INT > 4 ? null : "This demo requires Android 2.0 or higher version";
    }

    class MyLayer extends Layer {
    	private WYPoint mLast;
    	private TiledSprite mTS;
    	
    	public MyLayer() {
    		mTS = TiledSprite.make(Texture2D.makeJPG(R.drawable.test_jpg));
    		mTS.setTileDirection(true, true); // 可以设置平铺的方向, 缺省就是x, y方向都平铺S
    		mTS.setSpacing(DP(10), DP(20));
    		addChild(mTS);
    		
    		setTouchEnabled(true);
    		setGestureEnabled(true);
		}
    	
        private float DP(float v) {
        	return ResolutionIndependent.resolveDp(v);
        }
    	
    	@Override
    	public boolean wyTouchesBegan(MotionEvent event) {
    		mTS.stopFling();
    		mLast = Director.getInstance().convertToGL(event.getX(), event.getY());
    		return true;
    	}
    	
    	@Override
    	public boolean wyTouchesMoved(MotionEvent event) {
    		WYPoint loc = Director.getInstance().convertToGL(event.getX(), event.getY());
    		mTS.offsetBy((int)(loc.x - mLast.x), (int)(loc.y - mLast.y));
    		mLast = loc;
    		return true;
    	}
    	
    	@Override
    	public boolean wyTouchesEnded(MotionEvent event) {
    		return true;
    	}
    	
    	@Override
    	public boolean wyTouchesCancelled(MotionEvent event) {
    		return true;
    	}
    	
    	@Override
    	public boolean onFling(MotionEvent e1, MotionEvent e2, float velocityX,
    			float velocityY) {
    		mTS.fling(velocityX, velocityY);
    		return true;
    	}
    }
}
