package com.wiyun.engine.nodes;

import com.wiyun.engine.BaseWYObject;

public class Node extends BaseWYObject {
	public static Node from(int pointer) {
		return pointer == 0 ? null : new Node(pointer);
	}
	
	protected Node(int pointer) {
		super(pointer);
	}
}