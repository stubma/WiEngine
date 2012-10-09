package com.wiyun.engine.actions;


/**
 * \if English
 * execute actions one by one
 * \else
 * 按顺序执行一组动作的封装
 * \endif
 */
public class Sequence extends IntervalAction {
	/**
	 * \if English
	 * static factory method
	 *
	 * @param action1 first action, must be subclass of \link FiniteTimeAction FiniteTimeAction\endlink
	 * @param actions second action, must be subclass of \link FiniteTimeAction FiniteTimeAction\endlink, you can append more
	 * 		actions after this one
	 * @return \link Sequence Sequence\endlink
	 * \else
	 * 构造\link Sequence Sequence\endlink对象指针
	 *
	 * @param action1 要执行的动作\link FiniteTimeAction FiniteTimeAction \endlink对象
	 * @param actions 要执行的动作其它\link FiniteTimeAction FiniteTimeAction \endlink对象,
	 * 		后面还可以添加多个\link FiniteTimeAction FiniteTimeAction \endlink对象
	 * @return \link Sequence Sequence\endlink对象指针
	 * \endif
	 */
    public static Sequence make(FiniteTimeAction action1, FiniteTimeAction... actions) {
        FiniteTimeAction prev = action1;
        for (FiniteTimeAction now : actions) {
        	// need auto release it, but we don't release last one so place auto release before new
        	if(prev instanceof Sequence)
        		prev.autoRelease();
            prev = new Sequence(prev, now);
        }
        return (Sequence) prev;
    }

    protected Sequence(FiniteTimeAction one, FiniteTimeAction two) {
    	nativeInit(one, two);
    }
   
    public static Sequence from(int pointer) {
    	return pointer == 0 ? null : new Sequence(pointer);
    }
    
    protected Sequence(int pointer) {
    	super(pointer);
    }

	private native void nativeInit(FiniteTimeAction one, FiniteTimeAction two);
	
	@Override
	public IntervalAction copy() {
		return new Sequence(nativeCopy());
	}
	
	@Override
	public IntervalAction reverse() {
		return new Sequence(nativeReverse());
	}
}
