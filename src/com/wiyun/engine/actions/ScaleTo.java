package com.wiyun.engine.actions;


/**
 * \if English
 * scale node
 * \else
 * 节点缩放的动作封装,根据设置起始缩放比进行缩放操作
 * \endif
 */
public class ScaleTo extends IntervalAction {
	/**
	 * \if English
	 * static factory method
	 *
	 * @param duration duration time of action in second
	 * @param startScale initial scale
	 * @param endScale end scale
	 * \else
	 * 静态构造函数
	 *
	 * @param duration 动作持续的时间
	 * @param startScale 初始缩放比
	 * @param endScale 目标缩放比
	 * \endif
	 */
    public static ScaleTo make(float duration, float startScale, float endScale) {
        return new ScaleTo(duration, startScale, startScale, endScale, endScale);
    }

	/**
	 * \if English
	 * static factory method
	 *
	 * @param duration duration time of action in second
	 * @param startScaleX initial x scale
	 * @param startScaleY initial y scale
	 * @param endScaleX end x scale
	 * @param endScaleY end y scale
	 * \else
	 * 静态构造函数
	 *
	 * @param duration 动作持续的时间
	 * @param startScaleX 初始x轴缩放比，取值大于0
	 * @param startScaleY 初始y轴缩放比，取值大于0
	 * @param endScaleX 目标x轴缩放比，取值大于0
	 * @param endScaleY 目标y轴缩放比，取值大于0
	 * \endif
	 */
    public static ScaleTo make(float duration, float startScaleX, float startScaleY, float endScaleX, float endScaleY) {
        return new ScaleTo(duration, startScaleX, startScaleY, endScaleX, endScaleY);
    }

    protected ScaleTo(float duration, float startScaleX, float startScaleY, float endScaleX, float endScaleY) {
    	nativeInit(duration, startScaleX, startScaleY, endScaleX, endScaleY);
    }
    
    private native void nativeInit(float duration, float startScaleX, float startScaleY, float endScaleX, float endScaleY);
    
    public static ScaleTo from(int pointer) {
    	return pointer == 0 ? null : new ScaleTo(pointer);
    }
    
	protected ScaleTo(int pointer) {
		super(pointer);
	}
	
	@Override
	public IntervalAction copy() {
		return new ScaleTo(nativeCopy());
	}
	
	@Override
	public IntervalAction reverse() {
		return new ScaleTo(nativeReverse());
	}
}
