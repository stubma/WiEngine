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
package com.wiyun.engine.tests.node;

import javax.microedition.khronos.opengles.GL10;

import android.os.Bundle;
import android.view.KeyEvent;
import android.view.MotionEvent;

import com.wiyun.engine.R;
import com.wiyun.engine.WiEngineTestActivity;
import com.wiyun.engine.nodes.ArrayTileMapAtlas;
import com.wiyun.engine.nodes.Director;
import com.wiyun.engine.nodes.INodeVirtualMethods;
import com.wiyun.engine.nodes.Label;
import com.wiyun.engine.nodes.Layer;
import com.wiyun.engine.opengl.Primitives;
import com.wiyun.engine.opengl.Texture2D;
import com.wiyun.engine.types.WYPoint;
import com.wiyun.engine.types.WYRect;
import com.wiyun.engine.types.WYSize;
import com.wiyun.engine.utils.ResolutionIndependent;

public class ArrayTileMapAtlasTest extends WiEngineTestActivity {
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		
		mGLSurfaceView.disableSystemHandleMenuKey();
	}
	
	@Override
	protected Layer createLayer() {
		return new MyLayer();
	}

    class MyLayer extends Layer implements INodeVirtualMethods {
    	ArrayTileMapAtlas mTileMap;
    	
    	private float mLastX;
    	private float mLastY;
    	
		private boolean mHasViewport;
    	
        public MyLayer() {
            // init tile values
            int[][] tiles = new int[20][20];
            for(int x = 0; x < 20; x++) {
            	tiles[x][0] = 1;
            	tiles[x][19] = 1;
            }
            for(int y = 0; y < 20; y++) {
            	tiles[0][y] = 1;
            	tiles[19][y] = 1;
            }
            for(int x = 1; x < 19; x++) {
            	tiles[x][1] = 121;
            	tiles[x][18] = 121;
            }
            for(int y = 1; y < 19; y++) {
            	tiles[1][y] = 121;
            	tiles[18][y] = 121;
            }

            // create tile map
            mTileMap = ArrayTileMapAtlas.make(Texture2D.make(R.drawable.tiles), 
            	(int)ResolutionIndependent.resolveDp(16), (int)ResolutionIndependent.resolveDp(16),
            	20, 20);
            mTileMap.setTiles(tiles);
            mTileMap.getTexture().setAntiAlias(false);
            
            // add tile map as child
            addChild(mTileMap, -1);
            
    		// add a hint label
            WYSize s = Director.getInstance().getWindowSize();
    		Label label = Label.make("(Menu)Switch Viewport", 16);
    		label.setPosition(s.width / 2, s.height - 30);
    		addChild(label);
            
            setTouchEnabled(true);
            setKeyEnabled(true);
            setJavaVirtualMethods(this);
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
        	
        	mTileMap.translate(deltaX, -deltaY);
        	return true;
        }
        
        @Override
        public boolean wyKeyDown(KeyEvent event) {
    		switch(event.getKeyCode()) {
    			case KeyEvent.KEYCODE_MENU:
    				mHasViewport = !mHasViewport;
    				if(mHasViewport) {
    					WYSize s = Director.getInstance().getWindowSize();
    					mTileMap.setClipRect(WYRect.make(50, 50, s.width - 100, s.width - 100));
    				} else {
    					mTileMap.clearClipRect();
    				}
    				break;
    		}

    		return false;
        }

		public void jDraw() {
			if(mHasViewport) {
				WYSize s = Director.getInstance().getWindowSize();
				GL10 gl = Director.getInstance().gl;
				gl.glColor4f(0.0f, 1.0f, 0.0f, 1.0f);
				gl.glLineWidth(1);
				WYPoint[] vertices = {
					WYPoint.make(50, 50),
					WYPoint.make(s.width - 50, 50),
					WYPoint.make(s.width - 50, s.width - 50),
					WYPoint.make(50, s.width - 50)
				};
				Primitives.drawPoly(vertices, true);
			}
		}

		public void jOnEnter() {
		}

		public void jOnEnterTransitionDidFinish() {
		}

		public void jOnExit() {
		}
    }
}
