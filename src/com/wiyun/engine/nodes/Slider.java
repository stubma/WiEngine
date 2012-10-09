package com.wiyun.engine.nodes;

/**
 * @class Slider
 *
 * 可滑动的进度条, 由三个部分组成: 背景, 进度条和滑块. 滑动条和\link ProgressTimer ProgressTimer\endlink
 * 的主要区别在于其上有一个滑块可以拖动, 并且最大最小值可以设置.
 */
public class Slider extends Node {
	public static interface ISliderCallback {
		/**
		 * 当slider的值改变时调用
		 *
		 * @param pointer slider对象的底层指针
		 * @param value 新的值
		 */
		public void onSliderValueChanged(int pointer, float value);
	}
	
	public static Slider from(int pointer) {
		return pointer == 0 ? null : new Slider(pointer);
	}
	
	/**
	 * 创建一个水平{@link Slider}
	 *
	 * @param bg 背景贴图, 它位于最下方, 会被进度条和滑块所覆盖. 在布局上, 背景贴图和进度条贴图会在中心点对其.
	 * 		可以为null
	 * @param bar 进度条贴图, 不能为null. 如果背景和滑块都为null, 则基本就相当于
	 * 		一个\link ProgressTimer ProgressTimer\endlink
	 * @param thumb 滑块贴图, 也可以为null, 如果为null, 则无拖动功能
	 * @return {@link Slider}
	 */
	public static Slider make(Sprite bg, Sprite bar, Sprite thumb) {
		return make(bg, bar, thumb, false);
	}
	
	/**
	 * 创建一个{@link Slider}
	 *
	 * @param bg 背景贴图, 它位于最下方, 会被进度条和滑块所覆盖. 在布局上, 背景贴图和进度条贴图会在中心点对其.
	 * 		可以为null
	 * @param bar 进度条贴图, 不能为null. 如果背景和滑块都为null, 则基本就相当于
	 * 		一个\link ProgressTimer ProgressTimer\endlink
	 * @param thumb 滑块贴图, 也可以为null, 如果为null, 则无拖动功能
	 * @param vertical 可选参数, true表示使用垂直的进度条
	 * @return {@link Slider}
	 */
	public static Slider make(Sprite bg, Sprite bar, Sprite thumb, boolean vertical) {
		return new Slider(bg, bar, thumb, vertical);
	}
	
	/**
	 * 构造函数
	 *
	 * @param bg 背景贴图, 它位于最下方, 会被进度条和滑块所覆盖. 在布局上, 背景贴图和进度条贴图会在中心点对其.
	 * 		可以为null
	 * @param bar 进度条贴图, 不能为null. 如果背景和滑块都为null, 则基本就相当于
	 * 		一个\link ProgressTimer ProgressTimer\endlink
	 * @param thumb 滑块贴图, 也可以为null, 如果为null, 则无拖动功能
	 * @param vertical 可选参数, true表示使用垂直的进度条
	 */
	protected Slider(Sprite bg, Sprite bar, Sprite thumb, boolean vertical) {
		nativeInit(bg, bar, thumb, vertical);
	}

	protected Slider(int pointer) {
		super(pointer);
	}
	
	@Override
	protected void doNativeInit() {
	}
	
	private native void nativeInit(Sprite bg, Sprite bar, Sprite thumb, boolean vertical);
	
	/**
	 * 得到滑动范围的最小值
	 *
	 * @return 滑动范围的最小值
	 */
	public native float getMin();

	/**
	 * 设置滑动范围的最小值
	 *
	 * @param min 滑动范围的最小值
	 */
	public native void setMin(float min);

	/**
	 * 得到滑动范围的最大值
	 *
	 * @return 滑动范围的最大值
	 */
	public native float getMax();

	/**
	 * 设置滑动范围的最大值
	 *
	 * @param max 滑动范围的最大值
	 */
	public native void setMax(float max);

	/**
	 * 得到当前值
	 *
	 * @return 当前值
	 */
	public native float getValue();

	/**
	 * 设置当前值
	 *
	 * @param value 当前值
	 */
	public native void setValue(float value);

	/**
	 * 是否显示全部的进度条
	 *
	 * @return 是否显示全部的进度条
	 */
	public native boolean isShowFullBar();

	/**
	 * 设置是否显示全部的进度条
	 *
	 * @param flag true表示显示全部的进度条
	 */
	public native void setShowFullBar(boolean flag);

	/**
	 * 是否是垂直的
	 *
	 * @return true表示是垂直的
	 */
	public native boolean isVertical();
	
	/**
	 * 设置java端的回调
	 *
	 * @param callback java端实现了回调接口的类
	 */
	public native void setCallback(ISliderCallback callback);
}
