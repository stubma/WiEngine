package com.wiyun.engine.actions;


/**
 * \if English
 * Base class for actions whose time is definite
 * \else
 * 用于表示在有限时间内可以完成的动作
 * \endif
 */
public abstract class FiniteTimeAction extends Action {
	protected FiniteTimeAction() {
	}
    
    protected FiniteTimeAction(float duration) {
    }
    
    protected FiniteTimeAction(int pointer) {
    	super(pointer);
    }
    
	/**
	 * \if English
	 * Get elapsed time of this action
	 *
	 * @return elapsed time in second
	 * \else
	 * 获得动作已经持续的时间
	 *
	 * @return 动作已经持续的时间
	 * \endif
	 */
	public native float getElapsed();
    
	/**
	 * \if English
	 * Get duration time of action
	 *
	 * @return duration time of action
	 * \else
	 * 获得动作持续时间长度
	 *
	 * @return 动作持续时间长度
	 * \endif
	 */
    public native float getDuration();

	/**
	 * \if English
	 * Set duration time of action, no effect if action is started
	 *
	 * @param duration duration time of action
	 * \else
	 * 设置动作持续时间长度, 如果动作已经开始执行, 设置不会有效果
	 *
	 * @param duration 动作持续时间长度
	 * \endif
	 */
    public native void setDuration(float duration);
}
