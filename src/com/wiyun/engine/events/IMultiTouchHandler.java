package com.wiyun.engine.events;

import android.view.MotionEvent;

/**
 * 多重触摸事件处理器接口。如果应用运行在Android 2.0以上版本，可以考虑实现
 * 多点触摸支持。
 */
public interface IMultiTouchHandler extends ITouchHandler {
    /**
     * 当其他非主要触点产生时调用，这个方法会在OpenGL线程中调用。
     * 
     * @param event {@link MotionEvent}
     * @return 如果这个事件被处理了，返回true，否则返回false
     */
	public boolean wyTouchesPointerBegan(MotionEvent event);
	
    /**
     * 当其他非主要触点结束时调用，这个方法会在OpenGL线程中调用。
     * 
     * @param event {@link MotionEvent}
     * @return 如果这个事件被处理了，返回true，否则返回false
     */
	public boolean wyTouchesPointerEnded(MotionEvent event);
}