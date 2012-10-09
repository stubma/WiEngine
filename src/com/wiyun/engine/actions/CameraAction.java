package com.wiyun.engine.actions;


/**
 * \if English
 * Base class for camera action
 * \else
 * 相机类动作的基类。相机类动作通过移动视点来产生特殊效果
 * \endif
 */
public abstract class CameraAction extends IntervalAction {
    protected CameraAction(float duration) {
    }
    
    protected CameraAction() {
    }
    
	protected CameraAction(int pointer) {
		super(pointer);
	}
    
    @Override
    public IntervalAction reverse() {
    	return new ReverseTime(nativeReverse());
    }
}
