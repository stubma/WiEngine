package com.wiyun.engine.box2d;

import com.wiyun.engine.box2d.dynamics.World;
import com.wiyun.engine.chipmunk.Chipmunk;
import com.wiyun.engine.nodes.Node;

/**
 * 对Box2D的节点式封装，使得Box2D可以被当作一个节点被添加到场景中。
 */
public class Box2D extends Node {
	/**
	 * 创建一个Box2D节点
	 * 
	 * @return {@link Chipmunk}
	 */
	public static Box2D make() {
		return new Box2D();
	}
	
	/**
	 * 构造函数
	 */
	protected Box2D() {
		nativeInit();
	}
	
	/**
	 * 初始化box2d, 在使用box2d之前必须调用这个方法
	 */
	private native void nativeInit();
	
    /**
     * 从底层指针获得一个Box2D的Java对象
     * 
     * @param pointer 底层指针
     * @return {@link Box2D}
     */
    public static Box2D from(int pointer) {
    	return pointer == 0 ? null : new Box2D(pointer);
    }
    
    protected Box2D(int pointer) {
    	super(pointer);
    }
	
	@Override
	protected void doNativeInit() {
	}
	
	/**
	 * 得到世界对象指针，世界对象在wyBox2D对象初始化时被创建
	 *
	 * @return b2World对象指针
	 */
	public World getWorld() {
		return World.from(nativeGetWorld());
	}
	
	private native int nativeGetWorld();

	/**
	 * 得到是否是debug draw模式的标志
	 *
	 * @return debug draw模式的标志, true表示是debug draw模式
	 */
	public native boolean isDebugDraw();

	/**
	 * 设置是否debug draw. Debug draw模式下使用简单的线条和色块渲染物体。
	 *
	 * @param flag true表示使用debug draw
	 */
	public native void setDebugDraw(boolean flag);

	/**
	 * 根据当前的box2d放缩比例，把像素数转换成米数
	 *
	 * @param pixel 像素数
	 * @return 米数
	 */
	public native float pixel2Meter(float pixel);

	/**
	 * 根据当前的box2d放缩比例, 把米数转换成像素数
	 *
	 * @param meter 米数
	 * @return 像素数
	 */
	public native float meter2Pixel(float meter);

	/**
	 * 得到1米对应的像素数
	 *
	 * @return 1米对应的像素数
	 */
	public native float getMeterPixels();

	/**
	 * 设置1米对应的像素数
	 *
	 * @param mp 1米对应的像素数
	 */
	public native void setMeterPixels(float mp);
}
