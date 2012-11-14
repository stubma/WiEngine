package com.wiyun.engine.utils;

import com.wiyun.engine.BaseWYObject;

public class ZwoptexFrame extends BaseWYObject {
	protected ZwoptexFrame(int pointer) {
		super(pointer);
	}
	
	public static ZwoptexFrame from(int pointer) {
		return pointer == 0 ? null : new ZwoptexFrame(pointer);
	}
}
