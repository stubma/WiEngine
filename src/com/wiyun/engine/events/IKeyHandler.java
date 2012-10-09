package com.wiyun.engine.events;

import android.view.KeyEvent;

/**
 * 按键事件处理器接口 
 */
public interface IKeyHandler {
    /**
     * 当按键按下时被调用，这个方法会在OpenGL线程中调用。
     * 
     * @param event {@link KeyEvent}
     * @return 如果这个事件被处理了，返回true，否则返回false
     */
	public boolean wyKeyDown(KeyEvent event);
	
    /**
     * 当按键松开时被调用，这个方法会在OpenGL线程中调用。
     * 
     * @param event {@link KeyEvent}
     * @return 如果这个事件被处理了，返回true，否则返回false
     */
	public boolean wyKeyUp(KeyEvent event);

    /**
     * 当按键持续按下时被调用，这个方法会在OpenGL线程中调用。
     * 
     * @param event {@link KeyEvent}
     * @return 如果这个事件被处理了，返回true，否则返回false
     */
	public boolean wyKeyMultiple(KeyEvent event);
}
