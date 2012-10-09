package com.wiyun.engine.grid;

import com.wiyun.engine.BaseWYObject;


/**
 * 用于抓取缓冲区内容到贴图中 
 */
class Grabber extends BaseWYObject {
	/**
	 * 构造函数
	 */
	public Grabber() {
		nativeInit();
	}
	
	public static Grabber from(int pointer) {
		return pointer == 0 ? null : new Grabber(pointer);
	}
	
	protected Grabber(int pointer) {
		super(pointer);
	}
	
	private native void nativeInit();
}
