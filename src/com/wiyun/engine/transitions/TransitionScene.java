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
package com.wiyun.engine.transitions;

import com.wiyun.engine.actions.IntervalAction;
import com.wiyun.engine.actions.ease.EaseAction;
import com.wiyun.engine.nodes.Node;
import com.wiyun.engine.nodes.Scene;
import com.wiyun.engine.utils.TargetSelector;

/**
 * 场景切换效果的封装, 是所有场景切换的基类
 */
public class TransitionScene extends Scene {
	public static TransitionScene make(float duration, Scene inScene) {
		return new TransitionScene(duration, inScene);
	}
	
	public static TransitionScene from(int pointer) {
		return pointer == 0 ? null : new TransitionScene(pointer);
	}
	
	protected TransitionScene() {
	}
	
	protected TransitionScene(float duration, Scene inScene) {
		nativeInit(duration, inScene);
	}
	
    private native void nativeInit(float duration, Scene inScene);

	protected TransitionScene(int pointer) {
    	super(pointer);
    }

	@Override
	protected void doNativeInit() {
	}

	public native float getDuration();
	
	public Scene getInScene() {
		return Scene.from(nativeGetInScene());
	}
	
	public native int nativeGetInScene();
	
	/**
	 * 设置载入场景, 只能在运行前设置.
	 *
	 * @param scene 需要载入的场景
	 */
	public native void setInScene(Scene scene);
	
	public Scene getOutScene() {
		return Scene.from(nativeGetOutScene());
	}
	
	public native int nativeGetOutScene();
	
	/**
	 * 设置载出场景, 只能在运行前设置.
	 *
	 * @param scene 需要载出的场景
	 */
	public native void setOutScene(Scene scene);
	
	/**
	 * Subclass can initial in/out scene here 
	 */
	protected void initScenes() {
	}
	
	/**
	 * Get in action target, normally it is the scene which will be shown
	 * But subclass can specify a different node
	 * 
	 * @return action target, should be {@link Node} object
	 */
	protected Node getInActionTarget() {
		return getInScene();
	}
	
	/**
	 * Get out action target, normally it is the scene which will be hiden
	 * But subclass can specify a different node
	 * 
	 * @return action target, should be {@link Node} object
	 */
	protected Node getOutActionTarget() {
		return getOutScene();
	}
	
	/**
	 * returns the action that will be performed on in scene
	 */
	protected IntervalAction getInAction() {
		return null;
	}
	
	/**
	 * returns the action that will be performed on out scene
	 */
	protected IntervalAction getOutAction() {
		return null;
	}
	
	/**
	 * 设置入场效果的ease动作. 内置的转换效果都是线性的, 如果想给它们设置一个非线性效果, 则
	 * 必须在转换开始之前设置. 不过给转换动画设置非线性效果需要适当的运用, 不然出入场动画不匹配
	 * 则会比较难看.
	 *
	 * @param inEase \link EaseAction EaseAction\endlink的子类
	 */
	public native void setInEaseAction(EaseAction inEase);

	/**
	 * 设置出场效果的ease动作. 内置的转换效果都是线性的, 如果想给它们设置一个非线性效果, 则
	 * 必须在转换开始之前设置. 不过给转换动画设置非线性效果需要适当的运用, 不然出入场动画不匹配
	 * 则会比较难看.
	 *
	 * @param outEase \link EaseAction EaseAction\endlink的子类
	 */
	public native void setOutEaseAction(EaseAction outEase);
	
	/**
	 * called after finish is invoked
	 */
	protected void postFinish() {
		// subclass can implement this 
    }
	
	/**
	 * Return a flag indicating in scene will be on top of out scene. Subclass
	 * should override this method to change in scene z order
	 * 
	 * @return flag indicating in scene will be on top of out scene
	 */
	protected boolean shouldInSceneOnTop() {
		return true;
	}
	
	/**
	 * \if English
	 * Set a target selector which is called when transition is finished
	 *
	 * @param ts target selector object
	 * \else
	 * 设置一个选择子用于在转场结束时调用
	 *
	 * @param ts 被调用的选择子
	 * \endif
	 */
	public native void setFinishCallback(TargetSelector ts);
}
