package com.wiyun.engine.box2d.dynamics;

import com.wiyun.engine.BaseObject;
import com.wiyun.engine.box2d.collision.AABB;
import com.wiyun.engine.box2d.collision.MassData;
import com.wiyun.engine.box2d.collision.RayCastInput;
import com.wiyun.engine.box2d.collision.RayCastOutput;
import com.wiyun.engine.types.WYPoint;

public class Fixture extends BaseObject {
	public static Fixture from(int pointer) {
		return pointer == 0 ? null : new Fixture(pointer);
	}
	
	protected Fixture() {
	}

	protected Fixture(int pointer) {
		super(pointer);
	}
	
	public Body getBody() {
		return Body.from(nativeGetBody());
	}
	
	private native int nativeGetBody();

	/**
	 * 检查某点是否落在fixture范围内
	 * 
	 * @param x 点的x坐标
	 * @param y 点的y坐标
	 * @return true表示点在fixture范围内
	 */
	public native boolean testPoint(float x, float y);
	
	/**
	 * 检查某点是否落在fixture范围内
	 * 
	 * @param p {@link WYPoint}
	 * @return true表示点在fixture范围内
	 */
	public boolean testPoint(WYPoint p) {
		return testPoint(p.x, p.y);
	}
	
	/**
	 * 获得底层shape指针
	 * 
	 * @return 底层shape指针
	 */
	public native int getShape();
	
	/**
	 * Set if this fixture is a sensor.
	 */
	public native void setSensor(boolean sensor);

	/**
	 * Is this fixture a sensor (non-solid)?
	 * 
	 * @return the true if the shape is a sensor.
	 */
	public native boolean isSensor();
	
	/**
	 * Set the contact filtering data. This will not update contacts until the next time
	 * step when either parent body is active and awake.
	 * 
	 * @param filter {@link Filter}
	 */
	public native void setFilterData(Filter filter);
	
	/**
	 * 得到碰撞过滤设置
	 * 
	 * @return {@link Filter}
	 */
	public Filter getFilterData() {
		Filter f = new Filter();
		nativeGetFilterData(f);
		return f;
	}

	/**
	 * Get the contact filtering data.
	 */
	private native void nativeGetFilterData(Filter filter);
	
	/**
	 * 得到同一个刚体上的下一个fixture
	 * 
	 * @return {@link Fixture}
	 */
	public Fixture getNext() {
		return Fixture.from(nativeGetNext());
	}
	
	private native int nativeGetNext();
	
	/**
	 * 对fixture做一个光线测试
	 * 
	 * @param input {@link RayCastInput}
	 * @param childIndex child index
	 * @return {@link RayCastOutput}
	 */
	public RayCastOutput rayCast(RayCastInput input, int childIndex) {
		RayCastOutput o = new RayCastOutput();
		nativeRayCast(o, input, childIndex);
		return o;
	}
	
	private native void nativeRayCast(RayCastOutput output, RayCastInput input, int childIndex);
	
	/**
	 * Get the mass data of the fixture.
	 * 
	 * @return a struct containing the mass, inertia and center of the fixture.
	 */
	public MassData getMassData() {
		MassData d = new MassData();
		nativeGetMassData(d);
		return d;
	}
	
	private native void nativeGetMassData(MassData d);
	
	/**
	 * Set the density of this fixture. This will _not_ automatically adjust the mass
	 * of the body. You must call b2Body::ResetMassData to update the body's mass.
	 */
	public native void setDensity(float density);

	/**
	 * Get the density of this fixture.
	 */
	public native float getDensity();
	
	/**
	 * Get the coefficient of friction.
	 */
	public native float getFriction();

	/**
	 * Set the coefficient of friction. This will immediately update the mixed friction
	 * on all associated contacts.
	 */
	public native void setFriction(float friction);
	
	/**
	 * Get the coefficient of restitution.
	 */
	public native float getRestitution();

	/**
	 * Set the coefficient of restitution. This will immediately update the mixed restitution
	 * on all associated contacts.
	 */
	public native void setRestitution(float restitution);
	
	/**
	 * Get the fixture's AABB. This AABB may be enlarge and/or stale.
	 * If you need a more accurate AABB, compute it using the shape and
	 * the body transform.
	 */
	public AABB getAABB(int childIndex) {
		AABB aabb = new AABB();
		nativeGetAABB(aabb, childIndex);
		return aabb;
	}
	
	private native void nativeGetAABB(AABB aabb, int childIndex);
	
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
