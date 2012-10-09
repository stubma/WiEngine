package com.wiyun.engine.actions.ease;

import com.wiyun.engine.actions.IntervalAction;

/**
 * 非线性动作的封装, 是所有非线性动作的基类，负责把线性动作转换成非线性动作
 */
public abstract class EaseAction extends IntervalAction {
	protected EaseAction() {
	}
	
	protected EaseAction(IntervalAction action) {
	}
	
	protected EaseAction(int pointer) {
		super(pointer);
	}
	
	@Override
	public abstract EaseAction copy();

	@Override
	public abstract EaseAction reverse();
	
	/**
	 * 设置该EaseAction所包含的动作. 如果当前EaseAction正在运行, 则调用此方法无效. 在包含动作
	 * 被设置之前, 调用copy和reverse方法都是危险的.
	 *
	 * @param wrapped \link IntervalAction IntervalAction\endlink
	 */
	public native void setWrappedAction(IntervalAction wrapped);
}
