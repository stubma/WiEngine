package com.wiyun.engine.livewallpaper;

import net.rbgrn.opengl.GLWallpaperService;
import android.view.GestureDetector;
import android.view.MotionEvent;
import android.view.SurfaceHolder;

import com.wiyun.engine.events.EventDispatcher;
import com.wiyun.engine.nodes.Director;

public class WiEngineLiveWallpaperService extends GLWallpaperService {
	/*
	 * 3.6中必须显式载入native库 
	 */
	static {
		System.loadLibrary("wiskia");
		System.loadLibrary("xml2");
		System.loadLibrary("wiengine");
		System.loadLibrary("wiengineskeleton");
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
				nativeStart();
			}
			sRefCount++;
		}
		
		private native void nativeStart();
		
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
}
