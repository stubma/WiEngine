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
package com.wiyun.engine.box2d.dynamics.contacts;

import com.wiyun.engine.BaseObject;
import com.wiyun.engine.box2d.collision.Manifold;
import com.wiyun.engine.box2d.common.Transform;
import com.wiyun.engine.box2d.dynamics.Fixture;

public class Contact extends BaseObject {
	public static Contact from(int pointer) {
		return pointer == 0 ? null : new Contact(pointer);
	}
	
	protected Contact() {
	}

	protected Contact(int pointer) {
		super(pointer);
	}
	
	/**
	 * 得到Manifold
	 * 
	 * @return {@link Manifold}
	 */
	public Manifold getManifold() {
		return Manifold.from(nativeGetManifold());
	}
	
	private native int nativeGetManifold();

	/**
	 * 得到碰撞的fixture A
	 * 
	 * @return {@link Fixture}
	 */
	public Fixture getFixtureA() {
		return Fixture.from(nativeGetFixtureA());
    }
	
	private native int nativeGetFixtureA();

	/**
	 * 得到碰撞的fixture B
	 * 
	 * @return {@link Fixture}
	 */
	public Fixture getFixtureB() {
		return Fixture.from(nativeGetFixtureB());
    }
	
	private native int nativeGetFixtureB();

	/**
	 * 设置接触点的enable状态, 可以用在碰撞监听器中设置是否处理这个碰撞
	 * 
	 * @param flag true表示enable, false表示disable
	 */
	public native void setEnabled(boolean flag);
	
	/**
	 * Is this contact touching?
	 */
	public native boolean isTouching();
	
	/**
	 * Has this contact been disabled?
	 */
	public native boolean isEnabled();
	
	/**
	 * 得到下一个碰撞点
	 * 
	 * @return {@link Contact}
	 */
	public Contact getNext() {
		return Contact.from(nativeGetNext());
	}
	
	private native int nativeGetNext();
	
	/**
	 * Get the child primitive index for fixture A.
	 */
	public native int getChildIndexA();
	
	/**
	 * Get the child primitive index for fixture B.
	 */
	public native int getChildIndexB();
	
	/**
	 * Evaluate this contact with your own manifold and transforms.
	 * Caller should be responsible for destroy returned manifold object
	 */
	public Manifold evaluate(Transform xfA, Transform xfB) {
		return Manifold.from(nativeEvaluate(xfA, xfB));
	}
	
	private native int nativeEvaluate(Transform xfA, Transform xfB);
	
	/**
	 * Override the default friction mixture. You can call this in b2ContactListener::PreSolve.
	 * This value persists until set or reset.
	 */
	public native void setFriction(float friction);

	/**
	 * Get the friction.
	 */
	public native float getFriction();

	/**
	 * Reset the friction mixture to the default value.
	 */
	public native void resetFriction();

	/**
	 * Override the default restitution mixture. You can call this in b2ContactListener::PreSolve
	 * The value persists until you set or reset.
	 */
	public native void setRestitution(float restitution);

	/**
	 * Get the restitution.
	 */
	public native float getRestitution();

	/**
	 * Reset the restitution to the default value.
	 */
	public native void resetRestitution();
}
