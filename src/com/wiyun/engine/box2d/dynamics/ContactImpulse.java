package com.wiyun.engine.box2d.dynamics;

import com.wiyun.engine.BaseObject;

public class ContactImpulse extends BaseObject {
	public static ContactImpulse from(int pointer) {
		return pointer == 0 ? null : new ContactImpulse(pointer);
	}
	
	protected ContactImpulse() {
	}

	protected ContactImpulse(int pointer) {
		super(pointer);
	}
	
	public native float getNormalImpulse(int index);
	
	public native float getTangentImpulse(int index);
}
