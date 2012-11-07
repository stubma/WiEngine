package com.wiyun.engine;

/**
 * It is java counterpart of C++ wyObject class
 */
public abstract class BaseWYObject extends BaseObject {
	protected BaseWYObject() {
	}
	
	protected BaseWYObject(int pointer) {
		super(pointer);
	}
}
