package com.wiyun.engine.events;

import android.view.MotionEvent;

/**
 * 触摸事件处理器接口
 */
public interface ITouchHandler {
    /**
     * 当触摸事件开始时调用，这个方法会在OpenGL线程中调用。
     * 
     * @param event {@link MotionEvent}
     * @return 如果这个事件被处理了，返回true，否则返回false
     */
    public boolean wyTouchesBegan(MotionEvent event);

    /**
     * 当发生触点移动事件时调用，这个方法会在OpenGL线程中调用。
     * 
     * @param event {@link MotionEvent}
     * @return 如果这个事件被处理了，返回true，否则返回false
     */
    public boolean wyTouchesMoved(MotionEvent event);

    /**
     * 当触摸事件结束时调用，这个方法会在OpenGL线程中调用。
     * 
     * @param event {@link MotionEvent}
     * @return 如果这个事件被处理了，返回true，否则返回false
     */
    public boolean wyTouchesEnded(MotionEvent event);

    /**
     * 当触摸事件取消时调用，这个方法会在OpenGL线程中调用。
     * 
     * @param event {@link MotionEvent}
     * @return 如果这个事件被处理了，返回true，否则返回false
     */
    public boolean wyTouchesCancelled(MotionEvent event);
}
