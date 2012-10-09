package com.wiyun.engine.nodes;

/**
 * 虚拟摇杆类. 虚拟摇杆是一个组合式节点, 创建时需要提供两个节点, 一个代表虚拟摇杆的背景盘,
 * 一个代表摇杆. 通过设置, 可以指定摇杆触发5方向, 或9方向, 或360度方向的事件. 这两个节点都会
 * 被加为\link VirtualJoystick VirtualJoystick\endlink, 并且摇杆节点会居中放置.
 *
 * \par
 * 摇杆节点可以移动的范围是可以设置的, 范围呈圆形, 因此设置一个半径即可.
 */
public class VirtualJoystick extends Node {
	/**
	 * 虚拟摇杆节点的回调接口定义
	 */
	public static interface IVirtualJoystickCallback {
		/**
		 * 当用户开始使用虚拟摇杆时触发, 也就相当于虚拟摇杆已经收到了触摸事件
		 *
		 * @param vjPointer 底层对象指针
		 */
		void onVJNavigationStarted(int vjPointer);

		/**
		 * 当用户停止使用虚拟摇杆时触发, 也就相当于虚拟摇杆已经收到了触摸结束事件
		 *
		 * @param vjPointer 底层对象指针
		 */
		void onVJNavigationEnded(int vjPointer);

		/**
		 * 当方向发生变化时调用
		 *
		 * @param vjPointer 底层对象指针
		 * @param newDirection 新的方向, 如果小于0, 则是预先定义的方向常量. 如果在0到359之间, 0表示
		 * 		正东方向, 以逆时针增大
		 */
		void onVJDirectionChanged(int vjPointer, int newDirection);
	}
	
	/*
	 * 虚拟摇杆的方向定义
	 */

	public static final int VJD_CENTER = -1;
	public static final int VJD_NORTH = -2;
	public static final int VJD_SOUTH = -3;
	public static final int VJD_EAST = -4;
	public static final int VJD_WEST = -5;
	public static final int VJD_NORTH_EAST = -6;
	public static final int VJD_NORTH_WEST = -7;
	public static final int VJD_SOUTH_EAST = -8;
	public static final int VJD_SOUTH_WEST = -9;
	
	/**
	 * 摇杆将触发5个方向的事件, 即东南西北中. 这是缺省的类型
	 */
	public static final int VJS_FIVE_DIRECTIONS = 0;

	/**
	 * 摇杆将触发9个方向的事件, 即东南西北中, 以及东南, 东北, 西南, 西北
	 */
	public static final int VJS_NINE_DIRECTIONS = 1;

	/**
	 * 摇杆将触发360度方向的事件
	 */
	public static final int VJS_FULL_DIRECTIONS = 2;
	
	public static VirtualJoystick make(Node bg, Node rocker) {
		return new VirtualJoystick(bg, rocker);
	}
	
	public static VirtualJoystick from(int pointer) {
		return pointer == 0 ? null : new VirtualJoystick(pointer);
	}
	
	protected VirtualJoystick(int pointer) {
		super(pointer);
	}
	
	protected VirtualJoystick(Node bg, Node rocker) {
		nativeInit(bg, rocker);
	}
	
	private native void nativeInit(Node bg, Node rocker);

	@Override
	protected void doNativeInit() {
	}
	
	/**
	 * 得到事件触发类型
	 *
	 * @return 事件触发类型
	 */
	public native int getEventStyle();

	/**
	 * 设置事件触发类型
	 *
	 * @param style 事件触发类型
	 */
	public native void setEventStyle(int style);

	/**
	 * 设置是否触摸事件结束时自动把摇杆节点置回中心
	 *
	 * @param flag true表示当触摸事件结束时自动把摇杆节点置回中心, 缺省是true
	 */
	public native void setAutoReset(boolean flag);

	/**
	 * 是否触摸事件结束时自动把摇杆节点置回中心
	 *
	 * @return true表示当触摸事件结束时自动把摇杆节点置回中心, 缺省是true
	 */
	public native boolean isAutoReset();

	/**
	 * 设置回调
	 *
	 * @param callback \link IVirtualJoystickCallback IVirtualJoystickCallback\endlink实现类
	 */
	public native void setCallback(IVirtualJoystickCallback callback);
}
