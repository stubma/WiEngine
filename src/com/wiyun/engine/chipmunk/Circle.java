package com.wiyun.engine.chipmunk;

import com.wiyun.engine.types.WYPoint;

/**
 * 一个圆形物体 
 */
public class Circle extends Shape {
	/**
	 * 创建一个圆形
	 * 
	 * @param body 相关刚体
	 * @param radius 半径
	 * @return {@link Circle}对象
	 */
	public static Circle make(Body body, float radius) {
		return make(body, radius, 0, 0);
	}
	
	/**
	 * 创建一个圆形
	 * 
	 * @param body 相关刚体
	 * @param radius 半径
	 * @param centerX 圆心的x位置，相对于自身坐标系
	 * @param centerY 圆心的y位置，相对于自身坐标系
	 * @return {@link Circle}对象
	 */
	public static Circle make(Body body, float radius, float centerX, float centerY) {
		return new Circle(body, radius, centerX, centerY);
	}
	
	/**
	 * 构造函数
	 * 
	 * @param body 相关刚体
	 * @param radius 半径
	 * @param centerX 圆心的x位置，相对于自身坐标系
	 * @param centerY 圆心的y位置，相对于自身坐标系
	 */
	protected Circle(Body body, float radius, float centerX, float centerY) {
		super(body);
		init(body, radius, centerX, centerY);
	}
	
	/**
	 * 得到圆心相对于刚体坐标系的偏移
	 * 
	 * @return 圆心坐标
	 */
	public WYPoint getOffset() {
		return WYPoint.make(getOffsetX(), getOffsetY());
	}
	
	/**
	 * 初始化Circle对象
	 * 
	 * @param body 相关刚体
	 * @param radius 半径
	 * @param centerX 圆心的x位置，相对于自身坐标系
	 * @param centerY 圆心的y位置，相对于自身坐标系
	 */
	private native void init(Body body, float radius, float centerX, float centerY);
	
	/**
	 * 设置半径，这个操作如果使用不当会造成问题，需要谨慎使用
	 * 
	 * @param r 半径
	 */
	public native void setRadius(float r);
	
	/**
	 * 得到半径
	 * 
	 * @return 半径
	 */
	public native float getRadius();
	
	/**
	 * 设置圆心相对于刚体坐标系的偏移，这个操作如果使用不当会造成问题，需要谨慎使用
	 * 
	 * @param x 圆心x位置
	 * @param y 圆心y位置
	 */
	public native void setOffset(float x, float y);
	
	/**
	 * 得到圆心相对于刚体坐标系的偏移的x位置
	 * 
	 * @return 圆心x位置
	 */
	public native float getOffsetX();
	
	/**
	 * 得到圆心相对于刚体坐标系的偏移的y位置
	 * 
	 * @return 圆心y位置
	 */
	public native float getOffsetY();
}
