package com.wiyun.engine.actions;


/**
 * \if English
 * Opposite to instant action, it is the base class of actions who will last for some while.
 * \else
 * 是所有非瞬间动作的基类, 用来表示一定时间内完成且在完成时间内持续更新的动作 
 * \endif
 */
public abstract class IntervalAction extends FiniteTimeAction {
	protected IntervalAction() {
	}
	
	protected IntervalAction(int pointer) {
		super(pointer);
	}
	
	protected IntervalAction(float duration) {
	}
	
	@Override
	public abstract IntervalAction copy();

	@Override
	public abstract IntervalAction reverse();
}