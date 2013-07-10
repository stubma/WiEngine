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
package com.wiyun.engine.livewallpaper;

import net.rbgrn.opengl.GLWallpaperService;
import android.view.GestureDetector;
import android.view.MotionEvent;
import android.view.SurfaceHolder;

import com.wiyun.engine.events.EventDispatcher;
import com.wiyun.engine.nodes.Director;
import com.wiyun.engine.nodes.Layer;
import com.wiyun.engine.nodes.Scene;
import com.wiyun.engine.nodes.Director.IDirectorLifecycleListener;
import com.wiyun.engine.particle.ParticleSystem;
import com.wiyun.engine.types.WYPoint;
import com.wiyun.engine.types.WYSize;

public class WiEngineLiveWallpaperService extends GLWallpaperService {
	static {
		System.loadLibrary("wiengine");
		System.loadLibrary("wiengine_binding");
	}
	
	/**
	 * 由于WiEngien的Director类是单例模式，在动态壁纸中使用时会出现一些调用时序上
	 * 的问题，因此可以用一个引用计数来控制Director的生命周期，避免Director被意外
	 * 终止掉。
	 */
	static int sRefCount = 0;
	
	@Override
	public Engine onCreateEngine() {
		return new SnowEngine();
	}

	class SnowEngine extends GLEngine {
	    private EventDispatcher mDispatcher;

		// gesture detector
		private GestureDetector mGestureDetector;
		
		SnowEngine() {
		}
		
		@Override
		public void onCreate(SurfaceHolder surfaceHolder) {
			super.onCreate(surfaceHolder);
			
			// attachContext可以调用多次，是安全的
			// setRenderer是必须要调用的，用来设定渲染器
			Director d = Director.getInstance();
			d.attachContext(WiEngineLiveWallpaperService.this);
			setRenderer(d);
			
	        // get dispatcher
	        mDispatcher = EventDispatcher.getInstance();
	        
	        // setup gesture detector
	        mGestureDetector = new GestureDetector(WiEngineLiveWallpaperService.this, mDispatcher);
	        mGestureDetector.setIsLongpressEnabled(true);
	        
	        // enable touch event
	        setTouchEventsEnabled(true);
			
			// 只有当引用计数为0时才运行
			if(sRefCount == 0) {
				// create scene
				Scene scene = Scene.make();
				scene.addChild(new MyLayer());
				
				// Make the Scene active
				d.runWithScene(scene);
			}
			sRefCount++;
		}
		
		@Override
		public void onResume() {
			Director.getInstance().resume();
			super.onResume();
		}
		
		@Override
		public void onPause() {
			Director.getInstance().pause();
			super.onPause();
		}
		
		@Override
		public void onDestroy() {
			// 只有当引用计数小于等于1才真正销毁Director
			if(sRefCount <= 1) {
				Director.getInstance().end();
				sRefCount = 0;
			} else {
				sRefCount--;
			}
			
			super.onDestroy();
		}
		
		@Override
		public void onTouchEvent(MotionEvent event) {
			// Give everything to the gesture detector
			// it will call gesture or double tap listener
			mGestureDetector.onTouchEvent(event);
			
			MotionEvent e = MotionEvent.obtain(event);
	        switch (e.getAction()) {
	            case MotionEvent.ACTION_CANCEL:
	            case MotionEvent.ACTION_OUTSIDE:
	                mDispatcher.touchesCancelled(e);
	                break;
	            case MotionEvent.ACTION_DOWN:
	                mDispatcher.touchesBegan(e);
	                break;
	            case MotionEvent.ACTION_MOVE:
	                mDispatcher.touchesMoved(e);
	                break;
	            case MotionEvent.ACTION_UP:
	                mDispatcher.touchesEnded(e);
	                break;
	            default:
	            	// XXX: use number so that it can be integrated by 1.6
	        		switch(e.getAction() & 0xFF) {
	        			case 5: // MotionEvent.ACTION_POINTER_DOWN:
	        				mDispatcher.touchesPointerBegan(e);
	        				break;
	        			case 6: // MotionEvent.ACTION_POINTER_UP:
	        				mDispatcher.touchesPointerEnded(e);
	        				break;
	        		}
	            	break;
	        }
		}
	}
	
	static class MyLayer extends Layer implements IDirectorLifecycleListener {
		private ParticleSystem emitter;
		private ParticleSystem clickEmitter;

		public MyLayer() {
			// create particle system
			emitter = ParticleSnow.make();
			addChild(emitter);
			
			// create click emitter
			clickEmitter = ParticleFlower.make();
			clickEmitter.stopSystem();
			addChild(clickEmitter);

			// set emitter position
			setEmitterPosition();
			
			/*
			 * 需要监听surface相关事件，以便在surface大小改变时修改粒子释放位置
			 * surface大小改变一般是发生在屏幕朝向改变时 
			 */
			Director.getInstance().addLifecycleListener(this);
			
			// enable touch
			setTouchEnabled(true);
		}

		private void setEmitterPosition() {
			if(WYPoint.isEqual(emitter.getCenterOfGravity(), WYPoint.makeZero())) {
				WYSize s = Director.getInstance().getWindowSize();
				emitter.setPosition(s.width / 2, s.height);
			}
		}

		public void onDirectorEnded() {
		}

		public void onSurfaceChanged(int w, int h) {
			emitter.setPosition(w / 2, h);
		}

		public void onSurfaceCreated() {
		}

		public void onSurfaceDestroyed() {
		}

		public void onDirectorPaused() {
        }

		public void onDirectorResumed() {
        }
		
		public void onDirectorScreenCaptured(String path) {
		}
		
		@Override
		public boolean wyTouchesBegan(MotionEvent event) {
			WYPoint loc = Director.getInstance().convertToGL(event.getX(), event.getY());
			clickEmitter.setPosition(loc);
			clickEmitter.resetSystem();
			return false;
		}
	}
}
