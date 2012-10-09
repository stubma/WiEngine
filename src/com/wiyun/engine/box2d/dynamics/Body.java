package com.wiyun.engine.box2d.dynamics;

import com.wiyun.engine.BaseObject;
import com.wiyun.engine.box2d.collision.MassData;
import com.wiyun.engine.box2d.collision.Shape;
import com.wiyun.engine.box2d.common.Transform;
import com.wiyun.engine.box2d.dynamics.contacts.ContactEdge;
import com.wiyun.engine.box2d.dynamics.joints.JointEdge;
import com.wiyun.engine.types.WYPoint;

public class Body extends BaseObject {
	/**
	 * 零质量，零速度，只能通过程序手动设置位置
	 */
	public static final int TYPE_STATIC = 0;
	
	/**
	 * 零质量，可以有速度，由box2d计算位置
	 */
	public static final int TYPE_KINEMATIC = 1;
	
	/**
	 * 可以有质量和速度，由box2d计算位置
	 */
	public static final int TYPE_DYNAMIC = 2;
	
	public static Body from(int pointer) {
		return pointer == 0 ? null : new Body(pointer);
	}

	protected Body() {
	}

	protected Body(int pointer) {
		super(pointer);
	}

	/**
	 * 创建一个Fixture
	 * 
	 * @param fd {@link FixtureDef}
	 * @return {@link Fixture}
	 */
	public Fixture createFixture(FixtureDef fd) {
		return Fixture.from(nativeCreateFixture(fd));
	}
	
	/**
	 * 创建一个Fixture
	 * 
	 * @param shape 和fixture关联的shape
	 * @param density 密度
	 * @return {@link Fixture}
	 */
	public Fixture createFixture(Shape shape, float density) {
		return Fixture.from(nativeCreateFixture(shape, density));
	}
	
	private native int nativeCreateFixture(FixtureDef fd);
	
	private native int nativeCreateFixture(Shape shape, float density);
	
	/**
	 * 得到质量
	 * 
	 * @return 质量
	 */
	public native float getMass();
	
	/**
	 * 设置刚体是否睡眠
	 * 
	 * @param flag false表示进入睡眠状态, true表示唤醒刚体
	 */
	public native void setAwake(boolean flag);
	
	/**
	 * 获得刚体类型
	 * 
	 * @return 刚体类型
	 */
	public native int getType();
	
	/**
	 * 设置刚体类型
	 * 
	 * @param type 刚体类型
	 */
	public native void setType(int type);
	
	/**
	 * 获得物体惯量
	 * 
	 * @return 惯量
	 */
	public native float getInertia();
	
	/**
	 * 给刚体施加一个力矩 
	 * 
	 * @param torque 力矩
	 */
	public native void applyTorque(float torque);
	
	/**
	 * 给刚体施加一个力
	 * 
	 * @param force 力
	 * @param point 力施加的点
	 */
	public native void applyForce(WYPoint force, WYPoint point);
	
	/**
	 * Apply a force to the center of mass. This wakes up the body.
	 * 
	 * @param force the world force vector, usually in Newtons (N).
	 */
	public native void applyForceToCenter(WYPoint force);
	
	/**
	 * 施加一个线性瞬间冲力
	 * 
	 * @param impulse 冲力大小
	 * @param point 着力点
	 */
	public native void applyLinearImpulse(WYPoint impulse, WYPoint point);
	
	/**
	 * 施加一个角速度瞬间力
	 * 
	 * @param impulse 力度
	 */
	public native void applyAngularImpulse(float impulse);
	
	/**
	 * 把相对于刚体的一个向量转换为相同方向的全局向量
	 * 
	 * @param x 局部向量x
	 * @param y 局部向量y
	 * @return {@link WYPoint}
	 */
	public WYPoint getWorldVector(float x, float y) {
		WYPoint ret = WYPoint.makeZero();
		nativeGetWorldVector(ret, x, y);
		return ret;
	}
	
	/**
	 * 把相对于刚体的一个向量转换为相同方向的全局向量
	 * 
	 * @param p 局部向量
	 * @return {@link WYPoint}
	 */
	public WYPoint getWorldVector(WYPoint p) {
		return getWorldVector(p.x, p.y);
	}
	
	private native void nativeGetWorldVector(WYPoint ret, float x, float y);
	
	/**
	 * 把一个刚体局部坐标转换成为全局坐标
	 * 
	 * @param x 局部坐标x
	 * @param y 局部坐标y
	 * @return {@link WYPoint}
	 */
	public WYPoint getWorldPoint(float x, float y) {
		WYPoint ret = WYPoint.makeZero();
		nativeGetWorldPoint(ret, x, y);
		return ret;
	}
	
	/**
	 * 把一个刚体局部坐标转换成为全局坐标
	 * 
	 * @param p {@link WYPoint}, 局部坐标
	 * @return {@link WYPoint}
	 */
	public WYPoint getWorldPoint(WYPoint p) {
		return getWorldPoint(p.x, p.y);
	}
	
	private native void nativeGetWorldPoint(WYPoint ret, float x, float y);
	
	/**
	 * 设置速度
	 * 
	 * @param v {@link WYPoint}
	 */
	public native void setLinearVelocity(WYPoint v);
	
	/**
	 * 得到速度
	 * 
	 * @return {@link WYPoint}
	 */
	public WYPoint getLinearVelocity() {
		WYPoint v = WYPoint.makeZero();
		nativeGetLinearVelocity(v);
		return v;
	}
	
	private native void nativeGetLinearVelocity(WYPoint v);
	
	/**
	 * 获得刚体上的当前转换矩阵
	 * 
	 * @return {@link Transform}
	 */
	public Transform getTransform() {
		Transform t = Transform.make();
		nativeGetTransform(t);
		return t;
	}
	
	private native void nativeGetTransform(Transform t);
	
	/**
	 * 设置角速度
	 * 
	 * @param v 角速度
	 */
	public native void setAngularVelocity(float v);
	
	/**
	 * 获得角速度
	 * 
	 * @return 角速度
	 */
	public native float getAngularVelocity();

	/**
	 * 得到刚体中心在全局的坐标
	 * 
	 * @return 刚体中心在全局的坐标
	 */
	public WYPoint getWorldCenter() {
		WYPoint c = WYPoint.makeZero();
		nativeGetWorldCenter(c);
		return c;
	}
	
	private native void nativeGetWorldCenter(WYPoint c);
	
	/**
	 * 得到刚体中心在局部的坐标
	 * 
	 * @return 刚体中心在局部的坐标
	 */
	public WYPoint getLocalCenter() {
		WYPoint c = WYPoint.makeZero();
		nativeGetLocalCenter(c);
		return c;
	}
	
	private native void nativeGetLocalCenter(WYPoint c);

	/**
	 * 销毁fixture
	 * 
	 * @param f {@link Fixture}
	 */
	public native void destroyFixture(Fixture f);

	/**
	 * 得到刚体位置
	 * 
	 * @return 刚体位置
	 */
	public WYPoint getPosition() {
		WYPoint p = WYPoint.makeZero();
		nativeGetPosition(p);
		return p;
	}
	
	private native void nativeGetPosition(WYPoint p);

	/**
	 * 获得刚体角度
	 * 
	 * @return 刚体角度
	 */
	public native float getAngle();
	
	/**
	 * 设置转换矩阵
	 * 
	 * @param px x坐标
	 * @param py y坐标
	 * @param angle 角度
	 */
	public native void setTransform(float px, float py, float angle);

	/**
	 * 检查刚体是否在睡眠
	 * 
	 * @return false表示正在睡眠
	 */
	public native boolean isAwake();
	
	/**
	 * 得到链表中下一个刚体
	 * 
	 * @return {@link Body}
	 */
	public Body getNext() {
		return Body.from(nativeGetNext());
	}
	
	private native int nativeGetNext();

	/**
	 * 将全局坐标转换为刚体坐标
	 * 
	 * @param position {@link WYPoint}
	 * @return {@link WYPoint}
	 */
	public WYPoint getLocalPoint(WYPoint position) {
		return getLocalPoint(position.x, position.y);
	}
	
	/**
	 * 将全局坐标转换为刚体坐标
	 * 
	 * @param x 全局x坐标
	 * @param y 全局y坐标
	 * @return {@link WYPoint}
	 */
	public WYPoint getLocalPoint(float x, float y) {
		WYPoint p = WYPoint.makeZero();
		nativeGetLocalPoint(p, x, y);
		return p;
	}
	
	private native void nativeGetLocalPoint(WYPoint p, float x, float y);
	
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
	
	/**
	 * Get the mass data of the body.
	 * 
	 * @return a struct containing the mass, inertia and center of the body.
	 */
	public MassData getMassData() {
		MassData d = new MassData();
		nativeGetMassData(d);
		return d;
	}
	
	private native void nativeGetMassData(MassData d);
	
	/**
	 * Set the mass properties to override the mass properties of the fixtures.
	 * Note that this changes the center of mass position.
	 * Note that creating or destroying fixtures can also alter the mass.
	 * This function has no effect if the body isn't dynamic.
	 * 
	 * @param d the mass data object.
	 */
	public native void setMassData(MassData d);
	
	/**
	 * This resets the mass properties to the sum of the mass properties of the fixtures.
	 * This normally does not need to be called unless you called SetMassData to override
	 * the mass and you later want to reset the mass.
	 */
	public native void resetMassData();
	
	/**
	 * 把一个全局向量转换为局部向量
	 * 
	 * @param worldVector 全局坐标向量
	 * @return 局部坐标向量
	 */
	public WYPoint getLocalVector(WYPoint worldVector) {
		return getLocalVector(worldVector.x, worldVector.y);
	}
	
	/**
	 * 把一个全局向量转换为局部向量
	 * 
	 * @param x 全局坐标向量x值
	 * @param y 全局坐标向量y值
	 * @return 局部坐标向量
	 */
	public WYPoint getLocalVector(float x, float y) {
		WYPoint v = WYPoint.makeZero();
		nativeGetLocalVector(v, x, y);
		return v;
	}
	
	private native void nativeGetLocalVector(WYPoint p, float x, float y);
	
	/**
	 * Get the world linear velocity of a world point attached to this body.
	 * 
	 * @param worldPoint point in world coordinates.
	 * @return the world velocity of a point.
	 */
	public WYPoint getLinearVelocityFromWorldPoint(WYPoint worldPoint) {
		return getLinearVelocityFromWorldPoint(worldPoint.x, worldPoint.y);
	}
	
	/**
	 * Get the world linear velocity of a world point attached to this body.
	 * 
	 * @param x x point in world coordinates.
	 * @param y y point in world coordinates.
	 * @return the world velocity of a point.
	 */
	public WYPoint getLinearVelocityFromWorldPoint(float x, float y) {
		WYPoint p = WYPoint.makeZero();
		nativeGetLinearVelocityFromWorldPoint(p, x, y);
		return p;
	}
	
	private native void nativeGetLinearVelocityFromWorldPoint(WYPoint p, float x, float y);
	
	/**
	 * Get the world velocity of a local point.
	 * 
	 * @param localPoint point in local coordinates.
	 * @return the world velocity of a point.
	 */
	public WYPoint getLinearVelocityFromLocalPoint(WYPoint localPoint) {
		return getLinearVelocityFromLocalPoint(localPoint.x, localPoint.y);
	}
	
	/**
	 * Get the world velocity of a local point.
	 * 
	 * @param x x point in local coordinates.
	 * @param y y point in local coordinates.
	 * @return the world velocity of a point.
	 */
	public WYPoint getLinearVelocityFromLocalPoint(float x, float y) {
		WYPoint p = WYPoint.makeZero();
		nativeGetLinearVelocityFromLocalPoint(p, x, y);
		return p;
	}
	
	private native void nativeGetLinearVelocityFromLocalPoint(WYPoint p, float x, float y);
	
	/**
	 * Get the linear damping of the body.
	 */
	public native float getLinearDamping();

	/**
	 * Set the linear damping of the body.
	 */
	public native void setLinearDamping(float linearDamping);
	
	/**
	 * Get the angular damping of the body.
	 */
	public native float getAngularDamping();

	/**
	 * Set the angular damping of the body.
	 */
	public native void setAngularDamping(float angularDamping);
	
	/**
	 * Should this body be treated like a bullet for continuous collision detection?
	 */
	public native void setBullet(boolean flag);

	/**
	 * Is this body treated like a bullet for continuous collision detection?
	 */
	public native boolean isBullet();
	
	/**
	 * You can disable sleeping on this body. If you disable sleeping, the
	 * body will be woken.
	 */
	public native void setSleepingAllowed(boolean flag);

	/**
	 * Is this body allowed to sleep
	 */
	public native boolean isSleepingAllowed();
	
	/**
	 * Set the active state of the body. An inactive body is not
	 * simulated and cannot be collided with or woken up.
	 * If you pass a flag of true, all fixtures will be added to the
	 * broad-phase.
	 * If you pass a flag of false, all fixtures will be removed from
	 * the broad-phase and all contacts will be destroyed.
	 * Fixtures and joints are otherwise unaffected. You may continue
	 * to create/destroy fixtures and joints on inactive bodies.
	 * Fixtures on an inactive body are implicitly inactive and will
	 * not participate in collisions, ray-casts, or queries.
	 * Joints connected to an inactive body are implicitly inactive.
	 * An inactive body is still owned by a b2World object and remains
	 * in the body list.
	 */
	public native void setActive(boolean flag);

	/**
	 * Get the active state of the body.
	 */
	public native boolean isActive();
	
	/**
	 * Set this body to have fixed rotation. This causes the mass
	 * to be reset.
	 */
	public native void setFixedRotation(boolean flag);

	/**
	 * Does this body have fixed rotation?
	 */
	public native boolean isFixedRotation();
	
	/**
	 * 得到第一个fixture, 可以通过Fixture.getNext()方法遍历刚体
	 * 上的所有fixture
	 * 
	 * @return {@link Fixture}, 如果没有fixture则返回null
	 */
	public Fixture getFirstFixture() {
		return Fixture.from(nativeGetFirstFixture());
	}
	
	private native int nativeGetFirstFixture();
	
	/**
	 * 获得第一个连接点, 可以通过JointEdge.getNext()遍历连接
	 * 
	 * @return {@link JointEdge}, 如果没有连接则返回null
	 */
	public JointEdge getFirstJointEdge() {
		return JointEdge.from(nativeGetFirstJointEdge());
	}
	
	private native int nativeGetFirstJointEdge();
	
	/**
	 * 获得第一个碰撞点, 可以通过ContactEdge.getNext()遍历所有碰撞点
	 * 
	 * @return {@link ContactEdge}, 如果没有碰撞点则返回null
	 */
	public ContactEdge getFirstContactEdge() {
		return ContactEdge.from(nativeGetContactEdge());
	}
	
	private native int nativeGetContactEdge();
	
	/**
	 * 获得world
	 * 
	 * @return {@link World}
	 */
	public World getWorld() {
		return World.from(nativeGetWorld());
	}
	
	private native int nativeGetWorld();
}
