package com.wiyun.engine.actions;


/**
 * \if English
 * scale a node
 * \else
 * 缩放动作。目标会缩放相应的比例，如果在执行动作时，目标已经具有一定的缩放比例，则最终比例是
 * 当前缩放比例和将要缩放比例的乘积。比如目标一开始已经是2倍大小，如果再用ScaleBy放大2倍，则
 * 最后会变成4倍大小。 
 * \endif
 */
public class ScaleBy extends IntervalAction {
	/**
	 * \if English
	 * static factory method
	 *
	 * @param duration duration of action in second
	 * @param scale delta scale
	 * @return \link wyScaleBy wyScaleBy\endlink
	 * \else
	 * 静态构造函数
	 *
	 * @param duration 动作持续的时间
	 * @param scale 缩放变化的缩放比
	 * @return \link wyScaleBy wyScaleBy\endlink
	 * \endif
	 */
    public static ScaleBy make(float duration, float scale) {
        return new ScaleBy(duration, scale, scale);
    }

	/**
	 * \if English
	 * static factory method
	 *
	 * @param duration duration of action in second
	 * @param scaleX delta x scale
	 * @param scaleY delta y scale
	 * @return \link ScaleBy ScaleBy\endlink
	 * \else
	 * 静态构造函数
	 *
	 * @param duration 动作持续的时间
	 * @param scaleX 缩放变化的x轴缩放比
	 * @param scaleY 缩放变化的y轴缩放比
	 * @return \link ScaleBy ScaleBy\endlink
	 * \endif
	 */
    public static ScaleBy make(float duration, float scaleX, float scaleY) {
        return new ScaleBy(duration, scaleX, scaleY);
    }

    protected ScaleBy(float duration, float scale) {
        this(duration, scale, scale);
    }

    protected ScaleBy(float duration, float scaleX, float scaleY) {
    	nativeInit(duration, scaleX, scaleY);
    }
   
    public static ScaleBy from(int pointer) {
    	return pointer == 0 ? null : new ScaleBy(pointer);
    }
    
    protected ScaleBy(int pointer) {
    	super(pointer);
	}

	private native void nativeInit(float duration, float scaleX, float scaleY);

    @Override
    public IntervalAction copy() {
        return new ScaleBy(nativeCopy());
    }

    @Override
    public IntervalAction reverse() {
        return new ScaleBy(nativeReverse());
    }
}
