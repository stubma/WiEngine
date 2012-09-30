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
	
	/**
	 * 得到事件派发标志
	 * 
	 * @return 事件派发标志
	 */
	public native boolean getDispatchEvents();

	/**
	 * 设置是否派发事件 
	 * 
	 * @param b true表示派发事件，false表示停止派发事件
	 */
	public native void setDispatchEvents(boolean b);
	
	/**
	 * 添加双击事件处理器
	 * 
	 * @param listener {@link OnDoubleTapListener}
	 */
	public void addDoubleTapHandler(OnDoubleTapListener listener) {
		addDoubleTapHandler(listener, 0);
	}

	/**
	 * 添加双击事件处理器
	 * 
	 * @param listener {@link OnDoubleTapListener}
	 * @param prio 优先级，优先级越高的handler会先获得事件的处理机会
	 */
	public native void addDoubleTapHandler(OnDoubleTapListener listener, int prio);
	
	/**
	 * 添加手势事件处理器
	 * 
	 * @param listener {@link OnGestureListener}
	 */
	public void addGestureHandler(OnGestureListener listener) {
		addGestureHandler(listener, 0);
	}

	/**
	 * 添加手势事件处理器
	 * 
	 * @param listener {@link OnGestureListener}
	 * @param prio 优先级，优先级越高的handler会先获得事件的处理机会
	 */
	public native void addGestureHandler(OnGestureListener listener, int prio);
	
	/**
	 * 添加触摸事件处理器
	 * 
	 * @param handler {@link ITouchHandler}
	 */
	public void addTouchHandler(ITouchHandler handler) {
		addTouchHandler(handler, 0);
	}

	/**
	 * 添加触摸事件处理器
	 * 
	 * @param handler {@link ITouchHandler}
	 * @param prio 优先级，优先级越高的handler会先获得事件的处理机会
	 */
	public native void addTouchHandler(ITouchHandler handler, int prio);
	
	/**
	 * 添加按键事件处理器
	 * 
	 * @param handler {@link IKeyHandler}
	 */
	public void addKeyHandler(IKeyHandler handler) {
		addKeyHandler(handler, 0);
	}
	
	/**
	 * 添加按键事件处理器
	 * 
	 * @param handler {@link IKeyHandler}
	 * @param prio 优先级，优先级越高的handler会先获得事件的处理机会
	 */
	public native void addKeyHandler(IKeyHandler handler, int prio);
	
	/**
	 * 添加加速器事件处理器
	 * 
	 * @param handler {@link IAccelerometerHandler}
	 * @param prio 优先级，优先级越高的handler会先获得事件的处理机会
	 */
	public native void addAccelHandler(IAccelerometerHandler handler, int prio);
	
	/**
	 * 添加加速器事件处理器
	 * 
	 * @param handler {@link IAccelerometerHandler}
	 */
	public void addAccelHandler(IAccelerometerHandler handler) {
		addAccelHandler(handler, 0);
	}

	/**
	 * 移除双击事件处理器
	 * 
	 * @param h {@link OnDoubleTapListener}
	 */
	public native void removeDoubleTapHandler(OnDoubleTapListener h);
	
	/**
	 * 移除手势事件处理器
	 * 
	 * @param h {@link OnGestureListener}
	 */
	public native void removeGestureHandler(OnGestureListener h);

	/**
	 * 移除触摸事件处理器
	 * 
	 * @param h {@link ITouchHandler}
	 */
	public native void removeTouchHandler(ITouchHandler h);
	
	/**
	 * 移除按钮事件处理器
	 * 
	 * @param h {@link IKeyHandler}
	 */
	public native void removeKeyHandler(IKeyHandler h);
	
	/**
	 * 移除加速器事件处理器
	 * 
	 * @param h {@link IAccelerometerHandler}
	 */
	public native void removeAccelHandler(IAccelerometerHandler h);

	/**
	 * 删除所有事件处理器
	 */
	public native void removeAllHandlers();
	
	/**
	 * 修改双击事件处理器优先级
	 * 
	 * @param h {@link OnDoubleTapListener}
	 * @param priority 新优先级
	 */
	public native void setDoubleTapPriority(OnDoubleTapListener h, int priority);

	/**
	 * 修改手势事件处理器优先级
	 * 
	 * @param h {@link OnGestureListener}
	 * @param priority 新优先级
	 */
	public native void setGesturePriority(OnGestureListener h, int priority);

	/**
	 * 修改触摸事件处理器优先级
	 * 
	 * @param h {@link ITouchHandler}
	 * @param priority 新优先级
	 */
	public native void setTouchPriority(ITouchHandler h, int priority);

	/**
	 * 修改按键事件处理器优先级
	 * 
	 * @param h {@link IKeyHandler}
	 * @param priority 新优先级
	 */
	public native void setKeyPriority(IKeyHandler h, int priority);
	
	/**
	 * 修改加速器事件处理器优先级
	 * 
	 * @param h {@link IAccelerometerHandler}
	 * @param priority 新优先级
	 */
	public native void setAccelerometerPriority(IAccelerometerHandler h, int priority);
	
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
