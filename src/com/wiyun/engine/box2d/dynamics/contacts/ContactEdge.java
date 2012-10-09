package com.wiyun.engine.box2d.dynamics.contacts;

import com.wiyun.engine.BaseObject;
import com.wiyun.engine.box2d.dynamics.Body;

public class ContactEdge extends BaseObject {
	public static ContactEdge from(int pointer) {
		return pointer == 0 ? null : new ContactEdge(pointer);
	}

	protected ContactEdge() {
	}

	protected ContactEdge(int pointer) {
		super(pointer);
	}
	
	public Body getBody() {
		return Body.from(nativeGetBody());
	}
	
	private native int nativeGetBody();
	
	public Contact getContact() {
		return Contact.from(nativeGetContact());
	}
	
	private native int nativeGetContact();
	
	public ContactEdge getNext() {
		return ContactEdge.from(nativeGetNext());
	}
	
	private native int nativeGetNext();
	
	public ContactEdge getPrev() {
		return ContactEdge.from(nativeGetPrev());
	}
	
	private native int nativeGetPrev();
}
