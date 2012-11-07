package com.wiyun.engine.events;

import com.wiyun.engine.BaseWYObject;

import android.view.KeyEvent;
import android.view.MotionEvent;
import android.view.GestureDetector.OnDoubleTapListener;
import android.view.GestureDetector.OnGestureListener;

/**
 * 系统事件派发器 
 */
public class EventDispatcher extends BaseWYObject implements OnGestureListener, OnDoubleTapListener {
	private static EventDispatcher sInstance;

	/**
	 * 获得派发器单一实例
	 * 
	 * @return 派发器单一实例
	 */
	public static EventDispatcher getInstance() {
		synchronized(EventDispatcher.class) {
			if(sInstance == null) {
				sInstance = new EventDispatcher();
			} else {
				sInstance.setPointer(nativeGetInstance());
			}
			return sInstance;
		}
	}
	
	protected EventDispatcher() {
		nativeInit();
	}
	
	private native static int nativeGetInstance();
	
	private native void nativeInit();
	
	public native boolean keyDown(KeyEvent event);
	
	public native boolean keyUp(KeyEvent event);
	
	public native boolean keyMultiple(KeyEvent event);
	
	public native boolean touchesBegan(MotionEvent event);
	
	public native boolean touchesMoved(MotionEvent event);

	public native boolean touchesEnded(MotionEvent event);
	
	public native boolean touchesPointerBegan(MotionEvent event);

	public native boolean touchesPointerEnded(MotionEvent event);

	public native boolean touchesCancelled(MotionEvent event);
	
	public native boolean onDoubleTap(MotionEvent e);

	public native boolean onDoubleTapEvent(MotionEvent e);

	public native boolean onSingleTapConfirmed(MotionEvent e);

	public native boolean onDown(MotionEvent e);
	
	public native boolean onFling(MotionEvent e1, MotionEvent e2, float velocityX, float velocityY);

	public native void onLongPress(MotionEvent e);

	public native boolean onScroll(MotionEvent e1, MotionEvent e2, float distanceX, float distanceY);

	public native void onShowPress(MotionEvent e);

	public native boolean onSingleTapUp(MotionEvent e);
}
