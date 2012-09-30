/*
 * Copyright (c) 2010 WiYun Inc.

 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:

 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.

 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
#ifndef __wyProgressTimer_h__
#define __wyProgressTimer_h__

#include "wyNode.h"
#include "wySprite.h"
#include "wyGlobal.h"

/**
 * @typedef wyProgressTimerStyle
 *
 * 进度条样式
 */
typedef enum {
	/**
	 * 扇形，逆时针
	 */
	RADIAL_CCW = 1,

	/**
	 * 扇形，顺时针
	 */
	RADIAL_CW,

	/**
	 * 水平条形，从左到右
	 */
	HORIZONTAL_BAR_LR,

	/**
	 * 水平条形，从右到左
	 */
	HORIZONTAL_BAR_RL,

	/**
	 * 垂直条形，从下到上
	 */
	VERTICAL_BAR_BT,

	/**
	 * 垂直条形，从上到下
	 */
	VERTICAL_BAR_TB
} wyProgressTimerStyle;

/**
 * @class wyProgressTimer
 *
 * 进度条节点对象，可以包装任意图片对象，实现只显示百分之0到100的效果。
 * 进度条的样式可以为条型或者扇形
 */
class WIENGINE_API wyProgressTimer : public wyNode {
protected:
	/// 进度样式
	wyProgressTimerStyle m_style;

	/// 显示百分之0到100的效果
	float m_percentage;

	/// 图片\link wySprite wySprite对象指针\endlink
	wySprite* m_sprite;

	// buffers
	GLfloat* m_vertices;
	GLfloat* m_texCoords;
	GLfloat* m_colors;
	int m_vertexCount;

private:
	void updateProgress();
	void updateBar();
	void updateRadial();
	void updateColor();
	void resetCapacity(int c);
	wyPoint boundaryTexCoord(int index);
	wyPoint vertexFromTexCoord(float u, float v);

public:
	/**
	 * 通过一个\link wyTexture2D wyTexture2D\endlink 对象构造一个
	 * 进度条，通过这种方式构造的进度条将使用这个贴图的完整大小.
	 *
	 * @param tex 贴图\link wyTexture2D wyTexture2D对象指针\endlink
	 */
	static wyProgressTimer* make(wyTexture2D* tex);

	/**
	 * 通过一个\link wySprite wySprite\endlink 构造一个进度条.
	 * 进度条可能只使用相关贴图的一部分，因为sprite也许是个图片集贴图。
	 *
	 * @param sprite \link wySprite wySprite\endlink 指针
	 */
	static wyProgressTimer* make(wySprite* sprite);

	/**
	 * 构造函数, 通过一个\link wyTexture2D wyTexture2D\endlink 对象构造一个
	 * 进度条，通过这种方式构造的进度条将使用这个贴图的完整大小.
	 *
	 * @param tex 贴图\link wyTexture2D wyTexture2D对象指针\endlink
	 */
	wyProgressTimer(wyTexture2D* tex);

	/**
	 * 构造函数, 通过一个\link wySprite wySprite\endlink 构造一个进度条.
	 * 进度条可能只使用相关贴图的一部分，因为sprite也许是个图片集贴图。
	 *
	 * @param sprite \link wySprite wySprite\endlink 指针
	 */
	wyProgressTimer(wySprite* sprite);

	/**
	 * 析构函数
	 */
	virtual ~wyProgressTimer();

	/// @see wyNode::draw
	virtual void draw();

	/**
	 * 设置进度，从0到100
	 *
	 * @param percentage 进度
	 */
	void setPercentage(float percentage);

	/**
	 * 得到进度，从0到100
	 *
	 * @return 进度
	 */
	float getPercentage() { return m_percentage; }

	/**
	 * 增加指定值, 如果超过100, 则当前值改为100
	 *
	 * @param delta 要变化的值
	 */
	void increase(float delta);

	/**
	 * 设置图片
	 *
	 * @param sprite \link wySprite wySprite对象指针\endlink
	 */
	void setSprite(wySprite* sprite);

	/**
	 * 设置进度样式
	 *
	 * @param style 样式
	 */
	void setStyle(wyProgressTimerStyle style);
};

#endif // __wyProgressTimer_h__
