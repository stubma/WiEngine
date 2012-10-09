package com.wiyun.engine.astar;

import com.wiyun.engine.BaseWYObject;

/**
 * A*查找路径返回的节点封装
 */
public class AStarStep extends BaseWYObject {
	/**
	 * 构造函数
	 *
	 * @param x tile x值
	 * @param y tile y值
	 */
	public static AStarStep make(int x, int y) {
		return new AStarStep(x, y);
	}
	
	protected AStarStep(int x, int y) {
		doNativeInit(x, y);
	}

	public static AStarStep from(int pointer) {
		return pointer == 0 ? null : new AStarStep(pointer);
	}

	protected AStarStep(int pointer) {
		super(pointer);
	}

	protected void doNativeInit(int x, int y) {
		nativeInit(x, y);
	}

	private native void nativeInit(int x, int y);
	
	/**
	 * 设置tile x值
	 *
	 * @param x tile x值
	 */
	public native final void setX(int x);

	/**
	 * 返回tile x值
	 *
	 * @return tile x值
	 */
	public native final int getX();

	/**
	 * 设置tile y值
	 *
	 * @param y tile y值
	 */
	public native final void setY(int y);

	/**
	 * 返回tile y值
	 *
	 * @return tile y值
	 */
	public native final int getY();

	/**
	 * 设置节点f值
	 *
	 * @param f 节点f值
	 */
	public native final void setF(float f);

	/**
	 * 返回节点f值
	 *
	 * @return 节点f值
	 */
	public native final float getF();

	/**
	 * 设置节点 h值
	 *
	 * @param h 节点h值
	 */
	public native final void setH(float h);

	/**
	 * 返回节点h值
	 *
	 * @return 节点h值
	 */
	public native final float getH();

	/**
	 * 设置节点 g值
	 *
	 * @param g 节点g值
	 */
	public native final void setG(float g);

	/**
	 * 返回节点h值
	 *
	 * @return 节点g值
	 */
	public native final float getG();
}
