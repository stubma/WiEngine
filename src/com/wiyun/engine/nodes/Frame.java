package com.wiyun.engine.nodes;

import com.wiyun.engine.BaseWYObject;

/**
 * 动画帧的基类。
 */
public class Frame extends BaseWYObject {
	protected Frame() {
	}
	
	Frame(int pointer) {
		super(pointer);
	}

	public native float getDuration();
	
	public native void setDuration(float duration);
}