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
import com.wiyun.engine.nodes.Director;
import com.wiyun.engine.nodes.INodeVirtualMethods;
import com.wiyun.engine.nodes.Label;
import com.wiyun.engine.nodes.Layer;
import com.wiyun.engine.nodes.Sprite;
import com.wiyun.engine.opengl.Primitives;
import com.wiyun.engine.opengl.Texture2D;
import com.wiyun.engine.tmx.TMXLayer;
import com.wiyun.engine.tmx.TMXTileMap;
import com.wiyun.engine.types.WYDimension;
import com.wiyun.engine.types.WYPoint;
import com.wiyun.engine.types.WYRect;
import com.wiyun.engine.types.WYSize;
import com.wiyun.engine.utils.ResolutionIndependent;

public class TMXOrthogonalTest extends WiEngineTestActivity {
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
    	TMXTileMap mMap;
    	Sprite mSprite;
    	
		private boolean mHasViewport;
		
    	private float mLastX;
    	private float mLastY;
    	
    	public MyLayer() {
    		Texture2D tex1 = Texture2D.makePNG(R.drawable.ortho_test1);
    		tex1.autoRelease();
    		Texture2D tex2 = Texture2D.makePNG(R.drawable.ortho_test1_bw);
    		tex2.autoRelease();
    		mMap = TMXTileMap.make(R.raw.orthogonal_test5, tex1, tex2);
            addChild(mMap);
            
    		// add click feedback sprite
    		Texture2D tex = Texture2D.makePNG(R.drawable.blocks);
    		mSprite = Sprite.make(tex, ResolutionIndependent.resolve(WYRect.make(0, 0, 32, 32)));
    		mSprite.setVisible(false);
    		mMap.addChild(mSprite, 10);
    		
    		// add a hint label
            WYSize s = Director.getInstance().getWindowSize();
    		Label label = Label.make("(Menu)Switch Clip", 16);
    		label.setPosition(s.width / 2, s.height - 30);
    		addChild(label);

            setTouchEnabled(true);
            setKeyEnabled(true);
            setJavaVirtualMethods(this);
		}
        
        @Override
        public boolean wyTouchesBegan(MotionEvent event) {
    		TMXLayer layer = mMap.getTMXLayerAt(0);
    		WYPoint loc = Director.getInstance().convertToGL(event.getX(), event.getY());
    		loc = layer.convertToNodeSpace(loc.x, loc.y);
    		WYDimension d = layer.getTileCoordinateAt(loc.x, loc.y);
    		WYPoint pos = layer.getPositionAt(d.x, d.y);
    		if(d.x != -1) {
    			mSprite.setVisible(true);
    			mSprite.setPosition(pos.x + layer.getTileWidth() / 2, pos.y + layer.getTileHeight() / 2);
    		} else {
    			mSprite.setVisible(false);
    		}
    		
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

        @Override
        public boolean wyKeyDown(KeyEvent event) {
    		switch(event.getKeyCode()) {
    			case KeyEvent.KEYCODE_MENU:
    				mHasViewport = !mHasViewport;
    				if(mHasViewport) {
    					WYSize s = Director.getInstance().getWindowSize();
    					mMap.setClipRect(WYRect.make(50, 50, s.width - 100, s.width - 100));
    				} else {
    					mMap.clearClipRect();
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
