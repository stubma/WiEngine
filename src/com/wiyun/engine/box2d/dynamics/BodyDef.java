package com.wiyun.engine.box2d.dynamics;

import com.wiyun.engine.BaseObject;
import com.wiyun.engine.types.WYPoint;

public class BodyDef extends BaseObject {
	public static BodyDef make() {
		return new BodyDef();
	}
	
	protected BodyDef() {
		nativeNew();
	}

	protected BodyDef(int pointer) {
		super(pointer);
	}
	
	private native void nativeNew();
	
	/**
	 * 设置位置
	 * 
	 * @param x x坐标
	 * @param y y坐标
	 */
	public native void setPosition(float x, float y);
	
	/**
	 * 设置刚体类型, 常量定义在Body中
	 * 
	 * @param type 刚体类型
	 */
	public native void setType(int type);
	
	/**
	 * 得到刚体类型
	 * 
	 * @return 刚体类型
	 */
	public native int getType();
	
	/**
	 * 销毁这个刚体描述对象
	 */
	public native void destroy();
	
	/**
	 * 设置角速度阻尼
	 * 
	 * @param damping 角速度阻尼
	 */
	public native void setAngularDamping(float damping);
	
	/**
	 * 获得角速度阻尼
	 * 
	 * return 角速度阻尼
	 */
	public native float getAngularDamping();
	
	/**
	 * 设置线性阻尼
	 * 
	 * @param damping 线性阻尼
	 */
	public native void setLinearDamping(float damping);
	
	/**
	 * 获得线性阻尼
	 * 
	 * @return 线性阻尼
	 */
	public native float getLinearDamping();
	
	/**
	 * 设置线性速度
	 * 
	 * @param v {@link WYPoint}
	 */
	public void setLinearVelocity(WYPoint v) {
		setLinearVelocity(v.x, v.y);
	}
	
	/**
	 * 设置线性速度
	 * 
	 * @param x 线性速度x分量
	 * @param y 线性速度y分量
	 */
	public native void setLinearVelocity(float x, float y);
	
	/**
	 * 设置角速度
	 * 
	 * @param v 角速度
	 */
	public native void setAngularVelocity(float v);
	
	/**
	 * 设置刚体方向
	 * 
	 * @param angle 刚体方向，单位是弧度 
	 */
	public native void setAngle(float angle);
	
	/**
	 * 获得刚体方向
	 * 
	 * @return 刚体方向，单位是弧度 
	 */
	public native float getAngle();
	
	/**
	 * 设置是否允许刚体睡眠
	 * 
	 * @param flag true表示允许睡眠
	 */
	public native void setAllowSleep(boolean flag);
	
	/**
	 * 是否允许刚体睡眠
	 * 
	 * @return true表示允许睡眠
	 */
	public native boolean isAllowSleep();

	/**
	 * 设置刚体位置
	 * 
	 * @param position {@link WYPoint}
	 */
	public native void setPosition(WYPoint position);
	
	/**
	 * 设置刚体是否具有子弹属性，子弹属性表示这个刚体运动非常快，这样box2d
	 * 会阻止出现穿越现象。
	 * 
	 * @param flag true表示这是一个子弹刚体
	 */
	public native void setBullet(boolean flag);
	
	/**
	 * 刚体是否具有子弹属性，子弹属性表示这个刚体运动非常快，这样box2d
	 * 会阻止出现穿越现象。
	 * 
	 * @return true表示这是一个子弹刚体
	 */
	public native boolean isBullet();
	
	/**
	 * 设置重力缩放比例
	 * 
	 * @param gravityScale 重力缩放比例
	 */
	public native void setGravityScale(float gravityScale);
	
	/**
	 * 获得重力缩放比例
	 * 
	 * @return 重力缩放比例
	 */
	public native float getGravityScale();
	
	/**
	 * 设置是否刚体可以旋转
	 * 
	 * @param flag true表示不旋转，false表示可以旋转
	 */
	public native void setFixedRotation(boolean flag);
	
	/**
	 * 刚体可以旋转
	 * 
	 * @return true表示不旋转，false表示可以旋转
	 */
	public native boolean isFixedRotation();

	/**
	 * 获得位置
	 * 
	 * @return {@link WYPoint}
	 */
	public WYPoint getPosition() {
		WYPoint p = WYPoint.makeZero();
		nativeGetPosition(p);
		return p;
	}
	
	private native void nativeGetPosition(WYPoint p);
	
	/**
	 * 得到用户自定义数据对象
	 * 
	 * @return {@link Object}
	 */
	public native Object getUserData();
	
	/**
	 * 设置用户自定义数据对象
	 * 
	 * @param obj {@link Object}
	 */
	public native void setUserData(Object obj);
}
