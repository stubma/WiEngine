package com.wiyun.engine.astar;

import com.wiyun.engine.BaseWYObject;

/**
 * A*地图状况父类封装
 */
public class AStarMap extends BaseWYObject {
	protected AStarMap() {
	}
	
	protected AStarMap(int pointer) {
		super(pointer);
	}
	
	/**
	 * 设置tile为block状态
	 *
	 * @param x tile　x值
	 * @param y tile　y值
	 */
	public native final void blockTile(int x, int y);

	/**
	 * 设置tile为free状态
	 *
	 * @param x tile　x值
	 * @param y tile　y值
	 */
	public native final void freeTile(int x, int y);

	/**
	 * 返回tile是否为block状态
	 *
	 * @param x tile　x值
	 * @param y tile　y值
	 * @return　true为block状态
	 */
	public native final boolean isBlockedAt(int x, int y);

	/**
	 * 返回\link AStarTile AStarTile\endlink对象指针
	 *
	 * @param x tile　x值
	 * @param y tile　y值
	 * @return　\link AStarTile AStarTile\endlink对象指针
	 */
	public final AStarTile getTileAt(int x, int y) {
		int pointer = nativeGetTileAt(x, y);
		return new AStarTile(pointer);
	}
	
	public native final int nativeGetTileAt(int x, int y);

	/**
	 * 验证tile是否有效,子类需要实现
	 *
	 * @param x tile　x值
	 * @param y tile　y值
	 * @return　true为有效
	 */
	public native boolean isValidTile(int x, int y);

	/**
	 * 返回两个tile之间的g(实际代价)值,子类需要实现
	 *
	 * @param t1 \link AStarTile AStarTile\endlink对象指针
	 * @param t2 \link AStarTile AStarTile\endlink对象指针
	 * @return　g(实际代价)值
	 */
	public native float getStepG(AStarTile t1, AStarTile t2);
}
