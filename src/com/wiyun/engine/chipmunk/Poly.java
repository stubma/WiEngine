package com.wiyun.engine.chipmunk;

import com.wiyun.engine.types.WYPoint;

/**
 * 一个多边形物体 
 */
public class Poly extends Shape {
	/**
	 * 创建一个多边形物体
	 * 
	 * @param body 相关的刚体
	 * @param verts 多边形的顶点
	 * @param offset 重心位置
	 * @return {@link Poly}
	 */
	public static Poly make(Body body, WYPoint[] verts, WYPoint offset) {
		return new Poly(body, verts, offset);
	}
	
	/**
	 * 创建一个矩形物体
	 * 
	 * @param body 相关的刚体
	 * @param width 矩形的宽
	 * @param height 矩形的高
	 * @return {@link Poly}
	 */
	public static Poly makeBox(Body body, float width, float height) {
		float hw = width / 2.0f;
		float hh = height / 2.0f;

		WYPoint[] verts = {
				WYPoint.make(-hw, -hh), 
				WYPoint.make(-hw, hh), 
				WYPoint.make(hw, hh), 
				WYPoint.make(hw, -hh),
		};

		return make(body, verts, WYPoint.makeZero());
	}
	
	/**
	 * 构造函数
	 * 
	 * @param body 相关的刚体
	 * @param verts 多边形的顶点
	 * @param offset 重心位置
	 */
	protected Poly(Body body, WYPoint[] verts, WYPoint offset) {
		super(body);
		init(body, verts, offset);
	}
	
	/**
	 * 初始化Poly
	 * 
	 * @param body 相关的刚体
	 * @param verts 多边形的顶点
	 * @param offset 重心位置
	 */
	private native void init(Body body, WYPoint[] verts, WYPoint offset);
	
	/**
	 * 设置多边形物体的顶点和偏移，这个操作如果使用不当会造成问题，需要谨慎使用
	 * 
	 * @param verts 顶点数组
	 * @param offset 中心位置相对于刚体坐标系的偏移
	 */
	public native void setVertices(WYPoint[] verts, WYPoint offset);
	
	/**
	 * 得到多边形物体的顶点个数
	 * 
	 * @return 多边形物体的顶点个数
	 */
	public native int getVertexCount();
	
	/**
	 * 得到多边形顶点
	 * 
	 * @param vertices 必须是一个{@link WYPoint}数组，长度必须等于getVertexCount()返回的值
	 */
	public native void getVertices(WYPoint[] vertices);
	
	/**
	 * 得到中心相对于刚体坐标系的偏移的x位置
	 * 
	 * @return 中心x位置
	 */
	public native float getOffsetX();
	
	/**
	 * 得到中心相对于刚体坐标系的偏移的y位置
	 * 
	 * @return 中心y位置
	 */
	public native float getOffsetY();
	
	/**
	 * 得到中心相对于刚体坐标系的偏移
	 * 
	 * @return 中心相对于刚体坐标系的偏移
	 */
	public WYPoint getOffset() {
		return WYPoint.make(getOffsetX(), getOffsetY());
	}
	
	/**
	 * 得到物体的初始宽度，所谓初始宽度是指在原始顶点的基础上进行计算的。
	 * 由于物体可能会有旋转，所以一个物体的边框矩形可能会有变化，从而导致
	 * 实际宽度也可能变化。而初始宽度是有原始顶点决定的，所以不会变化，除非
	 * 顶点被重新设置
	 * 
	 * @return 初始宽度
	 */
	public native float getOriginWidth();
	
	/**
	 * 得到物体的初始高度，所谓初始高度是指在原始顶点的基础上进行计算的。
	 * 由于物体可能会有旋转，所以一个物体的边框矩形可能会有变化，从而导致
	 * 实际高度也可能变化。而初始高度是有原始顶点决定的，所以不会变化，除非
	 * 顶点被重新设置
	 * 
	 * @return 初始高度
	 */
	public native float getOriginHeight();
}
