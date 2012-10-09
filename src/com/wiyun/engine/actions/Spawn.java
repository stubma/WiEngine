package com.wiyun.engine.actions;


/**
 * \if English
 * Execute two actions simultaneously. The duration time will be the longer-lived action's time
 * \else
 * 同时执行两个动作的封装
 * \endif
 */
public class Spawn extends IntervalAction {
	/**
	 * \if English
	 * static factory method
	 *
	 * @param action1 first action, must be subclass of \link FiniteTimeAction FiniteTimeAction\endlink
	 * @param params other actions, must be subclass of \link FiniteTimeAction FiniteTimeAction\endlink
	 * \else
	 * 静态构造函数
	 *
	 * @param action1 要执行的动作 \link FiniteTimeAction FiniteTimeAction\endlink对象指针
	 * @param params 其它要执行的动作 \link FiniteTimeAction FiniteTimeAction\endlink对象指针
	 * \endif
	 */
	public static IntervalAction make(FiniteTimeAction action1, FiniteTimeAction... params) {
		FiniteTimeAction prev = action1;

		if(action1 != null) {
			for(FiniteTimeAction now : params) {
				if(prev instanceof Spawn) 
					prev.autoRelease();
				prev = new Spawn(prev, now);
			}
		}
		return (IntervalAction)prev;
	}
	
	/**
	 * \if English
	 * static factory method
	 *
	 * @param one first action, must be subclass of \link wyFiniteTimeAction wyFiniteTimeAction \endlink
	 * @param two second action, must be subclass of \link wyFiniteTimeAction wyFiniteTimeAction \endlink
	 * \else
	 * 静态构造函数
	 *
	 * @param one 要执行的动作 \link wyFiniteTimeAction wyFiniteTimeAction \endlink对象指针
	 * @param two 要执行的动作 \link wyFiniteTimeAction wyFiniteTimeAction \endlink对象指针
	 * \endif
	 */
	public static Spawn make(FiniteTimeAction one, FiniteTimeAction two) {
		return new Spawn(one, two);
	}

	protected Spawn(FiniteTimeAction one, FiniteTimeAction two) {
		nativeInit(one, two);
	}

	public static Spawn from(int pointer) {
    	return pointer == 0 ? null : new Spawn(pointer);
    }
    
	protected Spawn(int pointer) {
		super(pointer);
	}

	private native void nativeInit(FiniteTimeAction one, FiniteTimeAction two);

	@Override
	public IntervalAction copy() {
		return new Spawn(nativeCopy());
	}

	@Override
	public IntervalAction reverse() {
		return new Spawn(nativeReverse());
	}
}
