package com.wiyun.engine.nodes;

import com.wiyun.engine.types.WYColor3B;
import com.wiyun.engine.types.WYColor4B;

/**
 * 渐变色的层。它是{@link Layer}子类，支持设置背景色。
 */
public class GradientColorLayer extends Layer {
	/**
	 * 创建层
	 * 
	 * @param fromColor
	 *            层背景色
	 * @param toColor
	 *            层背景色
	 * @param degree
	 *            渐变角度,0标识从左到右水平变化，大于0为顺时针
	 * @return 层实例
	 */
	public static GradientColorLayer make(WYColor4B fromColor,
			WYColor4B toColor, int degree) {
		return new GradientColorLayer(fromColor, toColor, degree);
	}

	/**
	 * 构造函数
	 * 
	 * @param fromColor
	 *            层背景色
	 * @param toColor
	 *            层背景色
	 * @param degree
	 *            渐变角度,0标识从左到右水平变化，大于0为顺时针
	 */
	protected GradientColorLayer(WYColor4B fromColor, WYColor4B toColor,
			int degree) {
		nativeInit(fromColor, toColor, degree);
	}

	/**
	 * 从底层指针获得一个ColorLayer的Java对象
	 * 
	 * @param pointer
	 *            底层指针
	 * @return {@link GradientColorLayer}
	 */
	public static GradientColorLayer from(int pointer) {
		return pointer == 0 ? null : new GradientColorLayer(pointer);
	}

	protected GradientColorLayer(int pointer) {
		super(pointer);
	}

	private native void nativeInit(WYColor4B fromColor, WYColor4B toColor,
			int degree);

	@Override
	protected void doNativeInit() {
	}

	public native int getDegree();

	public native void setDegree(int degree);

	public native void getFromColor(WYColor3B color);

	public native void setFromColor(int r, int g, int b);

	public native void getToColor(WYColor3B color);

	public native void setToColor(int r, int g, int b);

}