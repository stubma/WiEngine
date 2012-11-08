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
#ifndef __wyVirtualJoystick_h__
#define __wyVirtualJoystick_h__

#include "wyNode.h"

class wyVirtualJoystick;

/*
 * 虚拟摇杆的方向定义
 */

#define VJD_CENTER -1
#define VJD_NORTH -2
#define VJD_SOUTH -3
#define VJD_EAST -4
#define VJD_WEST -5
#define VJD_NORTH_EAST -6
#define VJD_NORTH_WEST -7
#define VJD_SOUTH_EAST -8
#define VJD_SOUTH_WEST -9

/**
 * @typedef wyVirtualJoystickEventStyle
 *
 * 摇杆触发的事件类型
 */
typedef enum {
	/**
	 * 摇杆将触发5个方向的事件, 即东南西北中. 这是缺省的类型
	 */
	VJS_FIVE_DIRECTIONS,

	/**
	 * 摇杆将触发9个方向的事件, 即东南西北中, 以及东南, 东北, 西南, 西北
	 */
	VJS_NINE_DIRECTIONS,

	/**
	 * 摇杆将触发360度方向的事件
	 */
	VJS_FULL_DIRECTIONS
} wyVirtualJoystickEventStyle;

/**
 * @typedef wyVirtualJoystickCallback
 *
 * 虚拟摇杆节点的回调接口定义
 */
class WIENGINE_API wyVirtualJoystickCallback {
public:
	/**
	 * 当用户开始使用虚拟摇杆时触发, 也就相当于虚拟摇杆已经收到了触摸事件
	 *
	 * @param vj \link wyVirtualJoystick wyVirtualJoystick\endlink
	 */
	virtual void onVirtualJoystickNavigationStarted(wyVirtualJoystick* vj) = 0;

	/**
	 * 当用户停止使用虚拟摇杆时触发, 也就相当于虚拟摇杆已经收到了触摸结束事件
	 *
	 * @param vj \link wyVirtualJoystick wyVirtualJoystick\endlink
	 */
	virtual void onVirtualJoystickNavigationEnded(wyVirtualJoystick* vj) = 0;

	/**
	 * 当方向发生变化时调用
	 *
	 * @param vj \link wyVirtualJoystick wyVirtualJoystick\endlink
	 * @param newDirection 新的方向, 如果小于0, 则是预先定义的方向常量. 如果在0到359之间, 0表示
	 * 		正东方向, 以逆时针增大
	 */
	virtual void onVirtualJoystickDirectionChanged(wyVirtualJoystick* vj, int newDirection) = 0;
};

/**
 * @class wyVirtualJoystick
 *
 * 虚拟摇杆类. 虚拟摇杆是一个组合式节点, 创建时需要提供两个节点, 一个代表虚拟摇杆的背景盘,
 * 一个代表摇杆. 通过设置, 可以指定摇杆触发5方向, 或9方向, 或360度方向的事件. 这两个节点都会
 * 被加为\link wyVirtualJoystick wyVirtualJoystick\endlink, 并且摇杆节点会居中放置.
 *
 * \par
 * 摇杆节点可以移动的范围是可以设置的, 范围呈圆形, 因此设置一个半径即可.
 */
class WIENGINE_API wyVirtualJoystick : public wyNode {
private:
	/**
	 * 背景节点
	 */
	wyNode* m_bg;

	/**
	 * 摇杆节点
	 */
	wyNode* m_rocker;

	/**
	 * 摇杆事件类型
	 */
	wyVirtualJoystickEventStyle m_eventStyle;

	/**
	 * true表示用户正在使用虚拟摇杆
	 */
	bool m_navigating;

	/**
	 * 触摸的pid
	 */
	int m_pid;

	/**
	 * true表示当触摸事件结束时自动把摇杆节点置回中心, 缺省是true
	 */
	bool m_autoReset;

	/**
	 * \c m_rocker 可以移动的圆形范围半径, 其缺省大小是\link wyVirtualJoystick wyVirtualJoystick\endlink
	 * 节点高或宽(最小的那个)的一半
	 */
	float m_rockerRangeRadius;

	/**
	 * 当前的方向角度度数, 范围从0到359, 如果在中心则是-1
	 */
	int m_degree;

	/**
	 * 当前映射的方向, 范围从0到359, 如果当前的事件模式不是FULL, 则应该是负值
	 */
	int m_direction;

	/**
	 * 摇杆的当前x位置
	 */
	float m_rockerX;

	/**
	 * 摇杆的当前y位置
	 */
	float m_rockerY;

	/// callback
	wyVirtualJoystickCallback* m_callback;

private:
	void invokeOnVJNavigationStarted();
	void invokeOnVJNavigationEnded();
	void invokeOnVJDirectionChanged();
	void invokeOnVJDirectionChanged(int newDirection);

protected:
	/**
	 * 构造函数
	 *
	 * @param bg 背景节点, 可以为NULL
	 * @param rocker 摇杆节点, 可以为NULL
	 */
	wyVirtualJoystick(wyNode* bg, wyNode* rocker);

	/**
	 * 调整摇杆节点位置
	 *
	 * @param x 当前触摸x位置
	 * @param y 当前触摸y位置
	 */
	void adjustRockerPosition(float x, float y);

	/**
	 * 根据当前的角度和事件触发模式, 把角度转换为方向
	 *
	 * @return 方向
	 */
	int degree2Direction();

public:
	/**
	 * 静态构造函数, 创建后, \link wyVirtualJoystick wyVirtualJoystick\endlink节点的大小将
	 * 设置成为正好包含背景和摇杆节点
	 *
	 * @param bg 背景节点, 可以为NULL
	 * @param rocker 摇杆节点, 可以为NULL
	 * @return \link wyVirtualJoystick wyVirtualJoystick\endlink
	 */
	static wyVirtualJoystick* make(wyNode* bg, wyNode* rocker);

	virtual ~wyVirtualJoystick();

	/// @see wyNode::touchesBegan
	virtual bool touchesBegan(wyMotionEvent& e);

	/// @see wyNode::touchesMoved
	virtual bool touchesMoved(wyMotionEvent& e);

	/// @see wyNode::touchesEnded
	virtual bool touchesEnded(wyMotionEvent& e);

	/// @see wyNode::touchesCancelled
	virtual bool touchesCancelled(wyMotionEvent& e);

	/// @see wyNode::touchesPointerBegan
	virtual bool touchesPointerBegan(wyMotionEvent& e);

	/// @see wyNode::touchesPointerEnded
	virtual bool touchesPointerEnded(wyMotionEvent& e);

	/*
	 * setter and getter
	 */

	/**
	 * 得到事件触发类型
	 *
	 * @return 事件触发类型
	 */
	wyVirtualJoystickEventStyle getEventStyle() { return m_eventStyle; }

	/**
	 * 设置事件触发类型
	 *
	 * @param style 事件触发类型
	 */
	void setEventStyle(wyVirtualJoystickEventStyle style) { m_eventStyle = style; }

	/**
	 * 设置是否触摸事件结束时自动把摇杆节点置回中心
	 *
	 * @param flag true表示当触摸事件结束时自动把摇杆节点置回中心, 缺省是true
	 */
	void setAutoReset(bool flag) { m_autoReset = flag; }

	/**
	 * 是否触摸事件结束时自动把摇杆节点置回中心
	 *
	 * @return true表示当触摸事件结束时自动把摇杆节点置回中心, 缺省是true
	 */
	bool isAutoReset() { return m_autoReset; }

	/**
	 * 设置回调
	 *
	 * @param callback \link wyVirtualJoystickCallback wyVirtualJoystickCallback\endlink 结构指针, callback的内容
	 * 		会被复制，因此\link wyVirtualJoystick wyVirtualJoystick\endlink不会负责释放该指针。如果指针为NULL，表示清
	 * 		除之前设置的回调
	 */
	void setCallback(wyVirtualJoystickCallback* callback);
};

#endif // __wyVirtualJoystick_h__
