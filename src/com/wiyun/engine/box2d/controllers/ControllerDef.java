package com.wiyun.engine.box2d.controllers;

import com.wiyun.engine.BaseObject;

/**
 * 其它控制器定义类的基类
 */
public abstract class ControllerDef extends BaseObject {
	protected ControllerDef() {
	}

	protected ControllerDef(int pointer) {
		super(pointer);
	}
}
