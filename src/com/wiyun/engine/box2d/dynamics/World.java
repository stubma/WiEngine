/*
 * Copyright (c) 2010 WiYun Inc.
 * Author: luma(stubma@gmail.com)
 *
 * For all entities this program is free software; you can redistribute
 * it and/or modify it under the terms of the 'WiEngine' license with
 * the additional provision that 'WiEngine' must be credited in a manner
 * that can be be observed by end users, for example, in the credits or during
 * start up. (please find WiEngine logo in sdk's logo folder)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
package com.wiyun.engine.box2d.dynamics;

import com.wiyun.engine.BaseObject;
import com.wiyun.engine.box2d.controllers.Controller;
import com.wiyun.engine.box2d.controllers.ControllerDef;
import com.wiyun.engine.box2d.dynamics.contacts.Contact;
import com.wiyun.engine.box2d.dynamics.joints.Joint;
import com.wiyun.engine.box2d.dynamics.joints.JointDef;
import com.wiyun.engine.types.WYPoint;

public class World extends BaseObject {
	/**
	 * 查询AABB结果的回调接口
	 */
	public static interface IQueryCallback {
		/**
		 * 找到了一个匹配的Fixture
		 * 
		 * @param fixturePointer {@link Fixture}底层指针
		 * @return false表示中止查询, true表示继续查询下一个匹配
		 */
		public boolean reportFixture(int fixturePointer);
	}
	
	/**
	 * Implement this class to get contact information. You can use these results for
	 * things like sounds and game logic. You can also get contact results by
	 * traversing the contact lists after the time step. However, you might miss
	 * some contacts because continuous physics leads to sub-stepping.
	 * Additionally you may receive multiple callbacks for the same contact in a
	 * single time step.
	 * You should strive to make your callbacks efficient because there may be
	 * many callbacks per time step.
	 */
	public static interface IContactListener {
		/**
		 * Called when two fixtures begin to touch.
		 */
		public void beginContact(int contactPointer);

		/**
		 * Called when two fixtures cease to touch.
		 */
		public void endContact(int contactPointer);

		/**
		 * This is called after a contact is updated. This allows you to inspect a
		 * contact before it goes to the solver. If you are careful, you can modify the
		 * contact manifold (e.g. disable contact).
		 * A copy of the old manifold is provided so that you can detect changes.
		 * Note: this is called only for awake bodies.
		 * Note: this is called even when the number of contact points is zero.
		 * Note: this is not called for sensors.
		 * Note: if you set the number of contact points to zero, you will not
		 * get an EndContact callback. However, you may get a BeginContact callback
		 * the next step.
		 */
		public void preSolve(int contactPointer, int oldManifoldPointer);

		/**
		 * This lets you inspect a contact after the solver is finished. This is useful
		 * for inspecting impulses.
		 * Note: the contact manifold does not include time of impact impulses, which can be
		 * arbitrarily large if the sub-step is small. Hence the impulse is provided explicitly
		 * in a separate data structure.
		 * Note: this is only called for contacts that are touching, solid, and awake.
		 */
		public void postSolve(int contactPointer, int impulsePointer);
	}
	
	/**
	 * Callback class for ray casts.
	 */
	public static interface IRayCastCallback {
		/**
		 * Called for each fixture found in the query. You control how the ray cast
		 * proceeds by returning a float:
		 * return -1: ignore this fixture and continue
		 * return 0: terminate the ray cast
		 * return fraction: clip the ray to this point
		 * return 1: don't clip the ray and continue
		 * 
		 * @param fixturePointer the fixture hit by the ray
		 * @param pointX the x point of initial intersection
		 * @param pointY the y point of initial intersection
		 * @param normalX the x normal vector at the point of intersection
		 * @param normalY the y normal vector at the point of intersection
		 * @param fraction the cut point of ray
		 * @return -1 to filter, 0 to terminate, fraction to clip the ray for
		 * closest hit, 1 to continue
		 */
		public float reportFixture(int fixturePointer, float pointX, float pointY, float normalX, float normalY, float fraction);
	}
	
	/**
	 * Joints and fixtures are destroyed when their associated
	 * body is destroyed. Implement this listener so that you
	 * may nullify references to these joints and shapes.
	 */
	public static interface IDestructionListener {
		/**
		 * Called when any joint is about to be destroyed due
		 * to the destruction of one of its attached bodies.
		 */
		public void jointSayGoodbye(int jointPointer);

		/**
		 * Called when any fixture is about to be destroyed due
		 * to the destruction of its parent body.
		 */
		public void fixtureSayGoodbye(int fixturePointer);
	}
	
	public static World from(int pointer) {
		return pointer == 0 ? null : new World(pointer);
	}
	
	protected World() {
	}

	protected World(int pointer) {
		super(pointer);
	}
	
	/**
	 * 设置碰撞监听器
	 * 
	 * @param listener {@link IContactListener}实现类
	 */
	public native void setContactListener(IContactListener listener);
	
	/**
	 * 修改重力
	 * 
	 * @param x x方向重力
	 * @param y y方向重力
	 */
	public native void setGravity(float x, float y);
	
	/**
	 * 通过BodyDef创建一个Body
	 * 
	 * @param bd {@link BodyDef}
	 * @return {@link Body}
	 */
	public Body createBody(BodyDef bd) {
		return Body.from(nativeCreateBody(bd));
	}
	
	private native int nativeCreateBody(BodyDef bd);
	
	/**
	 * 通过{@link ControllerDef}子类创建一个{@link Controller}子类
	 * 
	 * @param cd {@link ControllerDef}
	 * @return {@link Controller}
	 */
	public native int createController(ControllerDef cd);
	
	/**
	 * 销毁一个controller
	 * 
	 * @param c {@link Controller}子类
	 */
	public native void destroyController(Controller c);
	
	/**
	 * 根据JointDef创建一个Joint
	 * 
	 * @param jd {@link JointDef}的子类
	 * @return 底层Joint对象的指针，需要用具体的类的from方法得到一个相应的java对象
	 */
	public native int createJoint(JointDef jd);

	/**
	 * 更新world
	 * 
	 * @param timeStep 步长
	 * @param velocityIterations 速率迭代计算次数
	 * @param positionIterations 位置迭代计算次数
	 */
	public native void step(float timeStep, int velocityIterations, int positionIterations);

	/**
	 * 清除刚体上的力
	 */
	public native void clearForces(); 
	
	/**
	 * 查询AABB树
	 * 
	 * @param callback 查询结果回调
	 * @param lbX 查询矩形的下边界x值
	 * @param lbY 查询矩形的下边界y值
	 * @param ubX 查询矩形的上边界x值
	 * @param ubY 查询矩形的上边界y值
	 */
	public native void queryAABB(IQueryCallback callback, float lbX, float lbY, float ubX, float ubY);

	/**
	 * 销毁一个连结点
	 *  
	 * @param joint {@link Joint}的子类
	 */
	public native void destroyJoint(Joint joint);
	
	/**
	 * 得到刚体列表的第一个刚体, 可以通过Body.getNext遍历所有刚体
	 * 
	 * @return {@link Body}
	 */
	public Body getFirstBody() {
		return Body.from(nativeGetFirstBody());
	}
	
	private native int nativeGetFirstBody();
	
	/**
	 * 进行光线测试
	 * 
	 * @param callback {@link IRayCastCallback}
	 * @param startX 光线起始点x值
	 * @param startY 光线起始点y值
	 * @param endX 光线结束点x值
	 * @param endY 光线结束点y值
	 */
	public native void rayCast(IRayCastCallback callback, float startX, float startY, float endX, float endY);

	/**
	 * 销毁一个刚体
	 * 
	 * @param body {@link Body}
	 */
	public native void destroyBody(Body body);
	
	/**
	 * 设置析构事件监听器
	 * 
	 * @param listener {@link IDestructionListener}
	 */
	public native void setDestructionListener(IDestructionListener listener);
	
	/**
	 * 得到连接列表的第一个连接, 可以通过Joint.getNext遍历所有连接
	 * 
	 * @return {@link Joint}
	 */
	public Joint getFirstJoint() {
		return Joint.from(nativeGetFirstJoint());
	}
	
	private native int nativeGetFirstJoint();
	
	/**
	 * 得到碰撞点列表的第一个碰撞点, 可以通过Contact.getNext遍历所有连接碰撞点
	 * 
	 * @return {@link Contact}
	 */
	public Contact getFirstContact() {
		return Contact.from(nativeGetFirstContact());
	}
	
	private native int nativeGetFirstContact();
	
	/**
	 * Enable/disable warm starting. For testing.
	 */
	public native void setWarmStarting(boolean flag);
	
	/**
	 * is warm starting enabled or disabled. For testing.
	 */
	public native boolean getWarmStarting();

	/**
	 * Enable/disable continuous physics. For testing.
	 */
	public native void setContinuousPhysics(boolean flag);

	/**
	 * Enable/disable single stepped continuous physics. For testing.
	 */
	public native void setSubStepping(boolean flag);
	
	/**
	 * is single stepped continuous physics enabled/disabled. For testing.
	 */
	public native boolean getSubStepping();
	
	/**
	 * Get the number of broad-phase proxies.
	 */
	public native int getProxyCount();

	/**
	 * Get the number of bodies.
	 */
	public native int getBodyCount();

	/**
	 * Get the number of joints.
	 */
	public native int getJointCount();

	/**
	 * Get the number of contacts (each may have 0 or more contact points).
	 */
	public native int getContactCount();
	
	/**
	 * Get the global gravity vector.
	 */
	public WYPoint getGravity() {
		WYPoint p = WYPoint.makeZero();
		nativeGetGravity(p);
		return p;
	}
	
	private native void nativeGetGravity(WYPoint p);

	/**
	 * Is the world locked (in the middle of a time step).
	 */
	public native boolean isLocked();

	/**
	 * Set flag to control automatic clearing of forces after each time step.
	 */
	public native void setAutoClearForces(boolean flag);

	/**
	 * Get the flag that controls automatic clearing of forces after each time step.
	 */
	public native boolean getAutoClearForces();

	/**
	 * 设置是否在调试渲染模式时允许填充shape, 这个标志缺省是false.
	 * 
	 * @param flag true表示不填充fixture, 所有的fixtur都只会画一个轮廓. false表示根据fixture类型决定,
	 * 		如果fixture是一个传感器, 则只画轮廓, 否则填充. 
	 */
	public native void setNoSolidDraw(boolean flag);

	/**
	 * Enable sleep or not
	 * 
	 * @param flag true means allow sleeping
	 */
	public native void setAllowSleeping(boolean flag);
	
	/**
	 * Is sleeping allowed?
	 * 
	 * @return true means sleeping is allowed
	 */
	public native boolean getAllowSleeping();
}
