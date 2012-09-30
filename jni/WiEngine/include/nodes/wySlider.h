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
#ifndef __wySlider_h__
#define __wySlider_h__

#include "wyProgressTimer.h"
#if ANDROID
	#include <jni.h>
#endif

class wySlider;

/**
 * @struct wySliderCallback
 *
 * \link wySlider wySlider\endlink的回调接口定义
 */
typedef struct wySliderCallback {
	/**
	 * 当slider的值改变时调用
	 *
	 * @param slider 相关的\link wySlider wySlider\endlink对象
	 * @param data 附加数据指针
	 */
	void (*onValueChanged)(wySlider* slider, void* data);
} wySliderCallback;

/**
 * @class wySlider
 *
 * 可滑动的进度条, 由三个部分组成: 背景, 进度条和滑块. 滑动条和\link wyProgressTimer wyProgressTimer\endlink
 * 的主要区别在于其上有一个滑块可以拖动, 并且最大最小值可以设置.
 */
class WIENGINE_API wySlider : public wyNode {
private:
	/// min value, default is 0
	float m_min;

	/// max value, default is 100
	float m_max;

	/// current value
	float m_value;

	/// 背景图片
	wySprite* m_bg;

	/// progress timer
	wyProgressTimer* m_progressTimer;

	/// 滑块
	wySprite* m_thumb;

	/**
	 * false表示只显示滑块左边(或下边)的进度条, true表示显示全部的进度条, 即
	 * 进度条不随着当前值变化, 缺省是false
	 */
	bool m_showFullBar;

	/// true表示使用垂直模式, 缺省是false
	bool m_vertical;

	/// true表示正在拖动滑块
	bool m_dragging;

	/// callback
	wySliderCallback m_callback;

	/// 附加数据指针
	void* m_data;

#if ANDROID
	/// java端callback
	jobject m_jCallback;
#endif

private:
	/**
	 * 更新界面显示
	 */
	void updateUI();

	/**
	 * 更新滑块位置
	 *
	 * @param percent 当前值的百分比
	 */
	void updateThumbPosition(float percent);

	/**
	 * 根据触摸位置设置当前值
	 *
	 * @param loc 相对于节点本身的坐标
	 */
	void setValueFromLocation(wyPoint loc);

	/**
	 * 调用回调通知值改变事件
	 */
	void invokeOnValueChanged();

public:
	/**
	 * 静态构造函数
	 *
	 * @param bg 背景贴图, 它位于最下方, 会被进度条和滑块所覆盖. 在布局上, 背景贴图和进度条贴图会在中心点对其.
	 * 		可以为null
	 * @param bar 进度条贴图, 不能为null. 如果背景和滑块都为null, 则基本就相当于
	 * 		一个\link wyProgressTimer wyProgressTimer\endlink
	 * @param thumb 滑块贴图, 也可以为null, 如果为null, 则无拖动功能
	 * @param vertical 可选参数, true表示使用垂直的进度条
	 */
	static wySlider* make(wySprite* bg, wySprite* bar, wySprite* thumb, bool vertical = false);

	/**
	 * 构造函数
	 *
	 * @param bg 背景贴图, 它位于最下方, 会被进度条和滑块所覆盖. 在布局上, 背景贴图和进度条贴图会在中心点对其.
	 * 		可以为null
	 * @param bar 进度条贴图, 不能为null. 如果背景和滑块都为null, 则基本就相当于
	 * 		一个\link wyProgressTimer wyProgressTimer\endlink
	 * @param thumb 滑块贴图, 也可以为null, 如果为null, 则无拖动功能
	 * @param vertical 可选参数, true表示使用垂直的进度条
	 */
	wySlider(wySprite* bg, wySprite* bar, wySprite* thumb, bool vertical = false);

	virtual ~wySlider();

	/// @see wyNode::touchesBegan
	virtual bool touchesBegan(wyMotionEvent& e);

	/// @see wyNode::touchesMoved
	virtual bool touchesMoved(wyMotionEvent& e);

	/// @see wyNode::touchesEnded
	virtual bool touchesEnded(wyMotionEvent& e);

	/// @see wyNode::touchesCancelled
	virtual bool touchesCancelled(wyMotionEvent& e);

	/**
	 * 得到滑动范围的最小值
	 *
	 * @return 滑动范围的最小值
	 */
	float getMin() { return m_min; }

	/**
	 * 设置滑动范围的最小值
	 *
	 * @param min 滑动范围的最小值
	 */
	void setMin(float min);

	/**
	 * 得到滑动范围的最大值
	 *
	 * @return 滑动范围的最大值
	 */
	float getMax() { return m_max; }

	/**
	 * 设置滑动范围的最大值
	 *
	 * @param max 滑动范围的最大值
	 */
	void setMax(float max);

	/**
	 * 得到当前值
	 *
	 * @return 当前值
	 */
	float getValue() { return m_value; }

	/**
	 * 设置当前值
	 *
	 * @param value 当前值
	 */
	void setValue(float value);

	/**
	 * 是否显示全部的进度条
	 *
	 * @return 是否显示全部的进度条
	 */
	bool isShowFullBar() { return m_showFullBar; }

	/**
	 * 设置是否显示全部的进度条
	 *
	 * @param flag true表示显示全部的进度条
	 */
	void setShowFullBar(bool flag);

	/**
	 * 是否是垂直的
	 *
	 * @return true表示是垂直的
	 */
	bool isVertical() { return m_vertical; }

	/**
	 * 设置回调
	 *
	 * @param callback \link wySliderCallback wySliderCallback\endlink 结构指针, callback的内容
	 * 		会被复制，因此\link wySlider wySlider\endlink不会负责释放该指针。如果指针为NULL，表示清
	 * 		除之前设置的回调
	 * @param data 附加数据指针, \link wySlider wySlider\endlink不会负责释放该指针
	 */
	void setCallback(wySliderCallback* callback, void* data);

#if ANDROID
	/**
	 * 设置java端的回调
	 *
	 * @param callback java端实现了回调接口的类
	 */
	void setCallback(jobject callback);
#endif
};

#endif // __wySlider_h__
