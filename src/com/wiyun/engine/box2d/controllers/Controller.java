package com.wiyun.engine.box2d.controllers;

import com.wiyun.engine.BaseObject;
import com.wiyun.engine.box2d.dynamics.Body;
import com.wiyun.engine.box2d.dynamics.World;

/**
 * 其它控制器的基类. 控制器是Box2D中的扩展模块, 用来封装一些常用的功能.
 */
public abstract class Controller extends BaseObject {
	protected Controller() {
	}

	protected Controller(int pointer) {
		super(pointer);
	}

	/**
	 * 添加一个{@link Body}到{@link Controller}
	 * 
	 * @param body {@link Body}
	 */
	public native void addBody(Body body);

	/**
	 * 从{@link Controller}删除一个{@link Body}
	 * 
	 * @param body {@link Body}
	 */
	public native void removeBody(Body body);

	/**
	 * 删除{@link Controller}中所有的{@link Body}
	 */
	public native void clear();

	/**
	 * 获得下一个{@link Controller}的底层指针
	 * 
	 * @return {@link Controller}的底层指针, 可以通过具体子类的from方法得到java端实例
	 */
	public native int getNext();

	/**
	 * 获得{@link World}的底层指针
	 * 
	 * @return {@link World}的底层指针, 可以通过from方法得到java端实例
	 */
	public native int getWorld();

	/**
	 * 得到第一个{@link ControllerEdge}的底层指针
	 * 
	 * @return 第一个{@link ControllerEdge}的底层指针, 可以通过from方法得到java端实例
	 */
	public native int getBodyList();
}
