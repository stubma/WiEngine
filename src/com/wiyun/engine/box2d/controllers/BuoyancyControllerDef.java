package com.wiyun.engine.box2d.controllers;

import com.wiyun.engine.box2d.dynamics.World;
import com.wiyun.engine.types.WYPoint;

/**
 * 浮力控制器定义类
 */
public class BuoyancyControllerDef extends ControllerDef {
	/**
	 * 创建一个{@link BuoyancyControllerDef}实例
	 * 
	 * @return {@link BuoyancyControllerDef}
	 */
	public static BuoyancyControllerDef make() {
		return new BuoyancyControllerDef();
	}
	
	protected BuoyancyControllerDef() {
		nativeInit();
	}
	
	private native void nativeInit();
	
	public native void destroy();

	/**
	 * 设置出水面的法线方向 
	 * 
	 * @param x 出水面的法线x方向 
	 * @param y 出水面的法线y方向 
	 */
	public native void setNormal(float x, float y);
	
	/**
	 * 得到出水面的法线
	 * 
	 * @return {@link WYPoint}
	 */
	public WYPoint getNormal() {
		WYPoint n = WYPoint.makeZero();
		nativeGetNormal(n);
		return n;
	}
	
	private native void nativeGetNormal(WYPoint n);

	/**
	 * 得到水面在法线方向上的距离
	 * 
	 * @return 水面在法线方向上的距离
	 */
	public native float getOffset();
	
	/**
	 * 设置水面在法线方向上的距离
	 * 
	 * @param offset 水面在法线方向上的距离
	 */
	public native void setOffset(float offset);

	/**
	 * 得到水的密度
	 * 
	 * @return 水的密度
	 */
	public native float getDensity();
	
	/**
	 * 设置水的密度
	 * 
	 * @param density 水的密度
	 */
	public native void setDensity(float density);

	/**
	 * 设置水的流速
	 * 
	 * @param x 水的x方向流速
	 * @param y 水的y方向流速
	 */
	public native void setVelocity(float x, float y);
	
	/**
	 * 得到水的流速
	 * 
	 * @return {@link WYPoint}
	 */
	public WYPoint getVelocity() {
		WYPoint v = WYPoint.makeZero();
		nativeGetVelocity(v);
		return v;
	}
	
	private native void nativeGetVelocity(WYPoint v);

	/**
	 * 得到物体在水中线性运动时的阻尼系数
	 * 
	 * @return 物体在水中线性运动时的阻尼系数
	 */
	public native float getLinearDrag();
	
	/**
	 * 设置物体在水中线性运动时的阻尼系数
	 * 
	 * @param linearDrag 物体在水中线性运动时的阻尼系数
	 */
	public native void setLinearDrag(float linearDrag);

	/**
	 * 得到物体在水中角速度运动时的阻尼系数
	 * 
	 * @return 物体在水中角速度运动时的阻尼系数
	 */
	public native float getAngularDrag();
	
	/**
	 * 设置物体在水中角速度运动时的阻尼系数
	 * 
	 * @param angularDrag 物体在水中角速度运动时的阻尼系数
	 */
	public native void setAngularDrag(float angularDrag);

	/**
	 * 是否使用物体本身的密度
	 * 
	 * @return true表示使用物体本身的密度, false表示把所有物体看成具有一个同样的密度
	 */
	public native boolean isUseDensity();
	
	/**
	 * 设置是否使用物体本身的密度
	 * 
	 * @param flag true表示使用物体本身的密度, false表示把所有物体看成具有一个同样的密度
	 */
	public native void setUseDensity(boolean flag);

	/**
	 * 是否使用{@link World}中设置的重力
	 * 
	 * @return true表示使用{@link World}中设置的重力, false表示使用setGravity方法设置的重力
	 */
	public native boolean isUseWorldGravity();
	
	/**
	 * 设置是否使用{@link World}中设置的重力
	 * 
	 * @param flag true表示使用{@link World}中设置的重力, false表示使用setGravity方法设置的重力
	 */
	public native void setUseWorldGravity(boolean flag);
	
	/**
	 * 设置重力, 仅当useWorldGravity为true时有效
	 * 
	 * @param x 重力的x值
	 * @param y 重力的y值
	 */
	public native void setGravity(float x, float y);
	
	/**
	 * 得到当前为浮力系统设置的重力, 仅当useWorldGravity为true时有效
	 * 
	 * @return {@link WYPoint}
	 */
	public WYPoint getGravity() {
		WYPoint g = WYPoint.makeZero();
		nativeGetGravity(g);
		return g;
	}
	
	private native void nativeGetGravity(WYPoint g);
}
