package com.wiyun.engine.box2d.controllers;

import com.wiyun.engine.BaseObject;

/**
 * 代表了一个控制器和一个刚体之间的连接关系
 */
public class ControllerEdge extends BaseObject {
	public static ControllerEdge from(int pointer) {
		return pointer == 0 ? null : new ControllerEdge(pointer);
	}
	
	protected ControllerEdge() {
	}

	protected ControllerEdge(int pointer) {
		super(pointer);
	}

	/**
	 * 相关的controller底层指针
	 */
	public int controllerPointer;

	/**
	 * 相关的body底层指针
	 */
	public int bodyPointer;
	
	/**
	 * controller的上一个body和controller的链接
	 */
	public int prevBodyEdgePoniter;
	
	/**
	 * controller的下一个body和controller的链接
	 */
	public int nextBodyEdgePointer;

	/**
	 * body的上一个controller和body的链接
	 */
	public int prevControllerEdgePointer;
	
	/**
	 * body的下一个controller和body的链接
	 */
	public int nextControllerEdgePointer;
}
