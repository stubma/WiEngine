package com.wiyun.engine.chipmunk;

import com.wiyun.engine.types.WYPoint;

/**
 * 一个平面物体, 可以有厚度 
 */
public class Segment extends Shape {
	/**
	 * 创建segment实例
	 * 
	 * @param body 相关的刚体
	 * @param start 起始点
	 * @param end 结束点
	 * @param thickness 厚度
	 * @return {@link Segment}
	 */
	public static Segment make(Body body, WYPoint start, WYPoint end, float thickness) {
		return make(body, start.x, start.y, end.x, end.y, thickness);
	}
	
	/**
	 * 创建segment实例
	 * 
	 * @param body 相关的刚体
	 * @param startX 起点x坐标
	 * @param startY 起点y坐标
	 * @param endX 结束点x坐标
	 * @param endY 结束点y坐标
	 * @param thickness 厚度
	 * @return {@link Segment}
	 */
	public static Segment make(Body body, float startX, float startY, float endX, float endY, float thickness) {
		return new Segment(body, startX, startY, endX, endY, thickness);
	}
	
	/**
	 * 构造函数
	 * 
	 * @param body 相关的刚体
	 * @param startX 起点x坐标
	 * @param startY 起点y坐标
	 * @param endX 结束点x坐标
	 * @param endY 结束点y坐标
	 * @param thickness 厚度
	 */
	protected Segment(Body body, float startX, float startY, float endX, float endY, float thickness) {
		super(body);
		init(body, startX, startY, endX, endY, thickness);
	}
	
	/**
	 * 初始化Segment
	 * 
	 * @param body 相关的刚体
	 * @param startX 起点x坐标
	 * @param startY 起点y坐标
	 * @param endX 结束点x坐标
	 * @param endY 结束点y坐标
	 * @param thickness 厚度
	 */
	private native void init(Body body, float startX, float startY, float endX, float endY, float thickness);
	
	/**
	 * 设置线段物体的端点
	 * 
	 * @param a 端点a
	 * @param b 端点b
	 */
	public void setEndpoints(WYPoint a, WYPoint b) {
		setEndpoints(a.x, a.y, b.x, b.y);
	}
	
	/**
	 * 设置线段物体的端点，这个操作如果使用不当会造成问题，需要谨慎使用
	 * 
	 * @param aX 端点a的x位置
	 * @param aY 端点a的y位置
	 * @param bX 端点b的x位置
	 * @param bY 端点b的y位置
	 */
	public native void setEndpoints(float aX, float aY, float bX, float bY);
	
	/**
	 * 获得线段物体的原始端点，这个方法返回的坐标是相对于刚体的
	 * 
	 * @param endpoints 必须是一个长度为2的{@link WYPoint}数组
	 */
	public native void getEndpoints(WYPoint[] endpoints);
	
	/**
	 * 获得线段物体的法线，这个法线是针对原始端点的，如果端点不变则它也不变。
	 * 这个方法返回的坐标是相对于刚体的
	 * 
	 * @param normal {@link WYPoint}
	 */
	public native void getNormal(WYPoint normal);
	
	/**
	 * 获得线段物体的当前端点，这个方法返回的坐标是相对于全局的
	 * 
	 * @param endpoints 必须是一个长度为2的{@link WYPoint}数组
	 */
	public native void getTransformedEndpoints(WYPoint[] endpoints);
	
	/**
	 * 获得线段物体的当前法线，这个法线是针对当前端点的，因此可能是变化的。
	 * 这个方法返回的坐标是相对于全局的
	 * 
	 * @param normal {@link WYPoint}
	 */
	public native void getTransformedNormal(WYPoint normal);
	
	/**
	 * 设置线段物体的厚度，这个操作如果使用不当会造成问题，需要谨慎使用
	 * 
	 * @param thickness 厚度
	 */
	public native void setThickness(float thickness);
	
	/**
	 * 获得线段物体的厚度
	 * 
	 * @return 线段物体的厚度
	 */
	public native float getThickness();
}
