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
#ifndef __wyVerletRope_h__
#define __wyVerletRope_h__

#include "wyObject.h"
#include "wyVerletStick.h"
#include "wyTypes.h"
#include "wyTexture2D.h"
#include "WiEngine-Classes.h"

/**
 * @class wyVerletRope
 *
 * \if English
 * Rope simulated by verlet integral
 * \else
 * 使用Verlet积分模拟一条绳子, 可以传入一个贴图对象，以这个贴图渲染绳子。这个类需要一般需要
 * 结合物理引擎使用。
 * \endif
 */
class WIENGINE_API wyVerletRope : public wyObject {
private:
	/// texture of rope stick
	wyTexture2D* m_tex;

	/// array of all points
	wyArray* m_points;

	/// array of all segments
	wyArray* m_sticks;

	/// quad list mesh of this rope
	wyQuadList* m_mesh;

	/// material
	wyMaterial* m_material;

	/// true means mesh need to be updated
	bool m_dirty;

	/// a adjustable variable to avoid stick gap
	float m_antiSagHack;

	/// orignal length of rope
	float m_length;

	/// original length of stick
	float m_stickLength;

	/// extra data pointer
	void* m_data;

	/// color of rope
	wyColor4B m_color;

private:
	static bool releaseObject(wyArray* arr, void* ptr, int index, void* data);

protected:
	/**
	 * \if English
	 * Create a sub rope from other rope
	 *
	 * @param rope original rope
	 * @param startPoint start point index
	 * @param endPoint end point, inclusive
	 * \else
	 * 从其它的绳子中构造一条子绳
	 *
	 * @param rope 原始的绳子
	 * @param startPoint 新绳子的起始点索引
	 * @param endPoint 新绳子的结束点索引, 新绳子包含结束点. 结束点必须比startPoint要大
	 * \endif
	 */
	wyVerletRope(wyVerletRope* rope, int startPoint, int endPoint);

	/**
	 * \if English
	 * Update rope atlas quad
	 * \else
	 * 更新atlas数据
	 * \endif
	 */
	void updateQuads();

	/**
	 * \if English
	 * According to two points, calculate a quad to insert into atlas
	 *
	 * @param a \link wyVerletPoint wyVerletPoint\endlink
	 * @param b \link wyVerletPoint wyVerletPoint\endlink
	 * \else
	 * 根据两个点的坐标，插入一段绳子贴图坐标
	 *
	 * @param a \link wyVerletPoint wyVerletPoint\endlink
	 * @param b \link wyVerletPoint wyVerletPoint\endlink
	 * \endif
	 */
	void appendQuad(wyVerletPoint* a, wyVerletPoint* b);

	/**
	 * \if English
	 * Set original length
	 *
	 * @param length original length
	 * \else
	 * 设置原始长度
	 *
	 * @param length 原始长度
	 * \endif
	 */
	void setLength(float length) { m_length = length; }

public:
	/**
	 * \if English
	 * Constructor
	 *
	 * @param a start point of rope
	 * @param b end point of rope
	 * @param tex texture of rope segment
	 * @param length length of rope, if zero, the rope length is distance between \c a and \c b
	 * \else
	 * 构造函数
	 *
	 * @param a 绳子起始点a
	 * @param b 绳子起始点b
	 * @param tex \link wyTexture2D wyTexture2D\endlink
	 * @param length 绳子长度，缺省为0，也就是以a和b之间的距离为长度
	 * \endif
	 */
	wyVerletRope(wyPoint a, wyPoint b, wyTexture2D* tex, size_t length = 0);

	virtual ~wyVerletRope();

	/**
	 * \if English
	 * Reset a rope with two endpoints
	 *
	 * @param a new start point
	 * @param b new end point
	 * \else
	 * 重置这条绳子
	 *
	 * @param a 新的起点
	 * @param b 新的终点
	 * \endif
	 */
	void reset(wyPoint a, wyPoint b);

	/**
	 * \if English
	 * Update rope state
	 *
	 * @param a new start point
	 * @param b new end point
	 * @param dt time since last \c update calling
	 * \else
	 * 更新绳子的形态
	 *
	 * @param a 新的起点
	 * @param b 新的终点
	 * @param dt 过去的时间
	 * \endif
	 */
	void update(wyPoint a, wyPoint b, float dt);

	/**
	 * Update rope mesh
	 */
	void updateMesh();

	/**
	 * Get material
	 */
	wyMaterial* getMaterial() { return m_material; }

	/**
	 * Get mesh
	 */
	wyMesh* getMesh();

	/**
	 * \if English
	 * Get all rope segments
	 *
	 * @return array of all \link wyVerletStick wyVerletStick\endlink objects
	 * \else
	 * 获得所有的\link wyVerletStick wyVerletStick\endlink对象
	 *
	 * @return 包含所有\link wyVerletStick wyVerletStick对象\endlink 的\link wyArray wyArray对象\endlink
	 * \endif
	 */
	wyArray* getSticks() { return m_sticks; }

	/**
	 * \if English
	 * Get segment at specified position
	 *
	 * @return \link wyVerletStick wyVerletStick\endlink, or NULL if index is invalid
	 * \else
	 * 得到指定位置处的\link wyVerletStick wyVerletStick\endlink 对象
	 *
	 * @return \link wyVerletStick wyVerletStick\endlink 对象, 如果index超出范围, 返回NULL
	 * \endif
	 */
	wyVerletStick* getStickAt(int index) { return (wyVerletStick*)wyArrayGet(m_sticks, index); }

	/**
	 * \if English
	 * Get total number of rope segments
	 *
	 * @return number of \link wyVerletStick wyVerletStick\endlink
	 * \else
	 * 得到\link wyVerletStick wyVerletStick\endlink 的个数
	 *
	 * @return \link wyVerletStick wyVerletStick\endlink 的个数
	 * \endif
	 */
	int getStickCount() { return m_sticks->num; }

	/**
	 * \if English
	 * Get all points in rope path
	 *
	 * @return an array contains all \link wyVerletPoint wyVerletPoint\endlink objects
	 * \else
	 * 获得所有的点, 每两个相邻的点就构成了一个\link wyVerletStick wyVerletStick\endlink
	 *
	 * @return 包含所有\link wyVerletPoint wyVerletPoint对象\endlink 的\link wyArray wyArray对象\endlink
	 * \endif
	 */
	wyArray* getPoints() { return m_points; }

	/**
	 * \if English
	 * Get point at specified position
	 *
	 * @return \link wyVerletPoint wyVerletPoint\endlink object or NULL if index is invalid
	 * \else
	 * 得到指定位置处的\link wyVerletPoint wyVerletPoint\endlink 对象
	 *
	 * @return \link wyVerletPoint wyVerletPoint\endlink 对象, 如果index超出范围, 返回NULL
	 * \endif
	 */
	wyVerletPoint* getPointAt(int index) { return (wyVerletPoint*)wyArrayGet(m_points, index); }

	/**
	 * \if English
	 * Get total number of points
	 *
	 * @return total number of points
	 * \else
	 * 获得点数
	 *
	 * @return 点数
	 * \endif
	 */
	int getPointCount() { return m_points->num; }

	/**
	 * \if English
	 * Get current length of rope and it may be larger than rope original length
	 *
	 * @return current length
	 * \else
	 * 得到绳子的当前长度，有可能比实际长度稍大
	 *
	 * @return 当前长度
	 * \endif
	 */
	float getCurrentLength();

	/**
	 * \if English
	 * Ray cast
	 *
	 * @param s start of ray
	 * @param e end of ray
	 * @return if ray intersects with rope and return index of \link wyVerletStick wyVerletStick\endlink
	 * 		object. Or returns -1 if no intersection. If more than one stick is crossed, only returns
	 * 		first
	 * \else
	 * 光线测试
	 *
	 * @param s 光线的起始点
	 * @param e 光线的结束点
	 * @return 如果光线和某个\link wyVerletStick wyVerletStick\endlink 相交,
	 * 		则返回这个\link wyVerletStick wyVerletStick\endlink 的索引, 如果没有
	 * 		相交, 返回-1. 如果有两个相交, 则只会返回第一个\link wyVerletStick wyVerletStick\endlink
	 * 		的索引.
	 * \endif
	 */
	int rayCast(wyPoint s, wyPoint e);

	/**
	 * \if English
	 * Get current color
	 *
	 * @return \link wyColor3B wyColor3B\endlink
	 * \else
	 * 得到当前颜色
	 *
	 * @return \link wyColor3B wyColor3B\endlink 结构
	 * \endif
	 */
	wyColor3B getColor();

	/**
	 * \if English
	 * Set rope color
	 *
	 * @param color \link wyColor3B wyColor3B\endlink
	 * \else
	 * 设置渲染颜色
	 *
	 * @param color \link wyColor3B wyColor3B\endlink 结构
	 * \endif
	 */
	void setColor(wyColor3B color);

	/**
	 * \if English
	 * Set rope color
	 *
	 * @param color \link wyColor4B wyColor4B\endlink
	 * \else
	 * 设置颜色
	 *
	 * @param color \link wyColor4B wyColor4B结构\endlink
	 * \endif
	 */
	void setColor(wyColor4B color);

	/**
	 * \if English
	 * Get current alpha value
	 *
	 * @return alpha value
	 * \else
	 * 得到当前alpha值
	 *
	 * @return alpha值
	 * \endif
	 */
	int getAlpha() { return m_color.a; }

	/**
	 * \if English
	 * Set rope alpha
	 *
	 * @param alpha alpha value
	 * \else
	 * 设置alpha值
	 *
	 * @param alpha alpha值
	 * \endif
	 */
	void setAlpha(int alpha) { m_color.a = MAX(MIN(255, alpha), 0); }

	/**
	 * \if English
	 * Get original length of rope. Original length is the length when rope is
	 * created
	 *
	 * @return original length
	 * \else
	 * 获得绳子的原始长度，原始长度是绳子创建时的长度，但是绳子可能会有一定的形变导致当前
	 * 长度不等于原始长度
	 *
	 * @return 原始长度
	 * \endif
	 */
	float getLength() { return m_length; }

	/**
	 * \if English
	 * Get user data pointer
	 *
	 * @return user data pointer
	 * \else
	 * 获得附加数据指针
	 *
	 * @return 附加数据指针
	 * \endif
	 */
	void* getUserData() { return m_data; }

	/**
	 * \if English
	 * Set user data pointer
	 *
	 * @param data user data pointer
	 * \else
	 * 设置附加数据指针
	 *
	 * @param data 附加数据指针
	 * \endif
	 */
	void setUserData(void* data) { m_data = data; }

	/**
	 * \if English
	 * Create a sub rope in parent rope range. Or NULL if index range
	 * is invalid
	 *
	 * @param startPoint start point index of sub rope
	 * @param endPoint end point index of sub rope
	 * @return \link wyVerletRope wyVerletRope\endlink object
	 * \else
	 * 以指定的点索引范围，获得一条绳子的部分，这个部分生成一个新的绳子实例.
	 * 如果指定的索引范围不合法，则返回NULL
	 *
	 * @param startPoint 新绳子的起始点索引
	 * @param endPoint 新绳子的结束点索引, 新绳子包含结束点. 结束点必须比startPoint要大
	 * @return \link wyVerletRope wyVerletRope\endlink 对象，已经被autoRelease
	 * \endif
	 */
	wyVerletRope* subRope(int startPoint, int endPoint);

	/**
	 * \if English
	 * Is rope stretched. When rope length exceeds original length, it is stretched
	 *
	 * @return true means rope length exceeds original length
	 * \else
	 * 检查绳子的当前长度是否已经超过了最大长度
	 *
	 * @return true表示绳子的当前长度已经超过了最大长度, 绳子处于被拉伸状态
	 * \endif
	 */
	bool isStretched();

	/**
	 * \if English
	 * Change rope length
	 *
	 * @param delta delta length to be added to current rope length
	 * \else
	 * 动态修改绳子长度
	 *
	 * @param delta 修改值，正值表示加长绳子，负值表示缩短绳子
	 * \endif
	 */
	void changeLength(float delta);

	/**
	 * \if English
	 * Get texture of rope
	 * \else
	 * 得到绳子的贴图
	 * \endif
	 */
	wyTexture2D* getTexture() { return m_tex; }

	/**
	 * \if English
	 * Set texture
	 * \else
	 * 设置绳子贴图
	 * \endif
	 */
	void setTexture(wyTexture2D* tex);
};

#endif // __wyVerletRope_h__
