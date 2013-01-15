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
package com.wiyun.engine.tests.performance;

import android.os.Bundle;
import android.view.MotionEvent;

import com.wiyun.engine.R;
import com.wiyun.engine.WiEngineTestActivity;
import com.wiyun.engine.nodes.Layer;
import com.wiyun.engine.opengl.Texture2D;
import com.wiyun.engine.tmx.TMXTileMap;

public class BigTMXTest extends WiEngineTestActivity {
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
    	TMXTileMap mMap;
    	
    	private float mLastX;
    	private float mLastY;
    	
    	public MyLayer() {
    		Texture2D tex1 = Texture2D.make(R.drawable.tileset0);
    		tex1.autoRelease();
    		mMap = TMXTileMap.make(R.raw.b0, tex1);
    		mMap.setDebugDrawObjects(true);
            addChild(mMap);
            
            setTouchEnabled(true);
		}
        
        @Override
        public boolean wyTouchesBegan(MotionEvent event) {
        	mLastX = event.getX();
        	mLastY = event.getY();
        	return true;
        }
        
        @Override
        public boolean wyTouchesMoved(MotionEvent event) {
        	// remember android event origin is not same as OpenGL
        	// you can use Director.getInstance().convertToGL(event.getX(), event.getY()) to convert it to GL coordinate
        	float x = event.getX();
        	float y = event.getY();
        	float deltaX = x - mLastX;
        	float deltaY = y - mLastY;
        	mLastX = x;
        	mLastY = y;
        	
        	mMap.translate(deltaX, -deltaY);
        	return true;
        }
    }
}
