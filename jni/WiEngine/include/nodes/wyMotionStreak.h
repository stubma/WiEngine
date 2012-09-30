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
#ifndef __wyMotionStreak_h__
#define __wyMotionStreak_h__

#include "wyNode.h"
#include "wyRibbon.h"

/**
 * @typedef wyMotionStreakStyle
 * \if English
 * enumeration of motion streak styles
 * \else
 * motion streak中轨迹的样式常量
 * \endif
 */
typedef enum {
	/**
	 * \if English
	 * the streak shows as a strip, \link wyStripRibbon wyStripRibbon\endlink is used to implement this effect
	 * \else
	 * 条状贴图带，连续，等宽，对应的ribbon子类是\link wyStripRibbon wyStripRibbon\endlink
	 * \endif
	 */
	MS_STYLE_STRIP,

	/**
	 * \if English
	 * the steak shows as a dotted line, \link wySpotRibbon wySpotRibbon\endlink is used
	 * \else
	 * 点状贴图带，不连续，一次全图显示, 类似愤怒小鸟的轨迹效果，对应的ribbon
	 * 子类是\link wySpotRibbon wySpotRibbon\endlink
	 * \endif
	 */
	MS_STYLE_SPOT,

	/**
	 * \if English
	 * the steak shows as a blade stripe, as fruit ninja's, \link wyBladeRibbon wyBladeRibbon\endlink is used
	 * \else
	 * 刀痕状，连续，不等宽，类似于水果忍者的效果，对应的ribbon类是\link wyBladeRibbon wyBladeRibbon\endlink
	 * \endif
	 */
	MS_STYLE_BLADE,

	/**
	 * \if English
	 * the steak show as a solid bold line, \link wyLineRibbon wyLineRibbon\endlink is used
	 * \else
	 * 连续的线段, 用来渲染一条粗线, 对应的ribbon类是\link wyLineRibbon wyLineRibbon\endlink.
	 * 该式样不支持淡出效果.
	 * \endif
	 */
	MS_STYLE_LINE
} wyMotionStreakStyle;

/**
 * @class wyMotionStreak
 *
 * \if English
 * To record the sport track of an object. By default, node of this type is located at the (0,0)
 * position of its parent space. Changing its size by setContentSize has no effect.
 * \else
 * 动作跟踪对象。动作跟踪对象可以设置不同的轨迹样式，还可以指定淡出效果。动作跟踪
 * 对象的尺寸为0且不能设置大小，其缺省位置在父节点的左下角. \link wyMotionStreak wyMotionStreak\endlink使用
 * 了\link wyRibbon wyRibbon\endlink来进行轨迹渲染，直接使用\link wyRibbon wyRibbon\endlink也是可以的。
 * \link wyMotionStreak wyMotionStreak\endlink只是把\link wyRibbon wyRibbon\endlink封装的更加容易使用。
 * \endif
 */
class WIENGINE_API wyMotionStreak : public wyNode {
private:
	/// pending point need to be added to ribbon
	struct PendingPoint {
		/// position
		wyPoint p;

		/// true means this point is a start of a new segment
		bool newSegment;
	};

protected:
	/**
	 * \if English
	 * \link wyRibbon wyRibbon object\endlink, used for rending purpose
	 * \else
	 * 包含的\link wyRibbon wyRibbon\endlink 对象
	 * \endif
	 */
	wyRibbon* m_ribbon;

	/**
	 * \if English
	 * the threshold, in pixels, if the node moved beyond this value, new segment will be generated
	 * \else
	 * 段阈值，表示移动超过多少像素才增加新段, 缺省是3个像素
	 * \endif
	 */
	float m_segThreshold;

	/**
	 * \if English
	 * last position
	 * \else
	 * 上一次位置
	 * \endif
	 */
	wyPoint m_lastLocation;

	/**
	 * \if English
	 * current position
	 * \else
	 * 当前最后添加的一个点
	 * \endif
	 */
	wyPoint m_currentLocation;

	/**
	 * \if English
	 * flag to mark whether to stop tracking
	 * \else
	 * true表示暂停更新motion streak
	 * \endif
	 */
	bool m_paused;

	/**
	 * \if English
	 * style, \link wyMotionStreakStyle wyMotionStreakStyle\endlink
	 * \else
	 * 样式
	 * \endif
	 */
	wyMotionStreakStyle m_style;

	/// pending point list
	vector<PendingPoint>* m_pendingPoints;

protected:
	/**
	 * do updating
	 *
	 * @param ts related target selector which triggered this method
	 */
	void update(wyTargetSelector* ts);

public:
	/**
	 * \if English
	 * factory function, used to create a new instance with autoRelease enabled
	 *
	 * @param fade duration, in seconds, after this given time, the ribbon will fade out. 0 means no fading out.
	 * @param tex \link wyTexture2D wyTexture2D object\endlink
	 * @param color \link wyColor4B wyColor4B object\endlink
	 * @param style \link wyMotionStreakStyle wyMotionStreakStyle\endlink
	 * \else
	 * 创建位置跟踪对象. 位置之间的轨迹以指定贴图画出, 轨迹的宽度和贴图宽度一致.
	 *
	 * @param fade Ribbon段的淡出时间, 传入0表示不淡出一直保持，直到用reset清除
	 * @param tex 图片资源\link wyTexture2D wyTexture2D对象指针\endlink
	 * @param color 贴图的颜色
	 * @param style motion streak轨迹的样式，缺省是条状
	 * \endif
	 */
	static wyMotionStreak* make(float fade, wyTexture2D* tex, wyColor4B color, wyMotionStreakStyle style = MS_STYLE_STRIP);

	/**
	 * \if English
	 * constructor
	 *
	 * @param fade duration, in seconds, after this given time, the ribbon will fade out. 0 means no fading out.
	 * @param tex \link wyTexture2D wyTexture2D object\endlink
	 * @param color \link wyColor4B wyColor4B object\endlink
	 * @param style \link wyMotionStreakStyle wyMotionStreakStyle\endlink
	 * \else
	 * 创建位置跟踪对象. 位置之间的轨迹以指定贴图画出, 轨迹的宽度和贴图宽度一致.
	 *
	 * @param fade Ribbon段的淡出时间, 传入0表示不淡出一直保持，直到用reset清除
	 * @param tex 图片资源\link wyTexture2D wyTexture2D对象指针\endlink
	 * @param color 贴图的颜色
	 * @param style motion streak轨迹的样式，缺省是条状
	 * \endif
	 */
	wyMotionStreak(float fade, wyTexture2D* tex, wyColor4B color, wyMotionStreakStyle style = MS_STYLE_STRIP);

	/**
	 * \if English
	 * destructor
	 * \else
	 * 析构函数
	 * \endif
	 */
	virtual ~wyMotionStreak();

	/// @see wyNode::setContentSize
	virtual void setContentSize(float w, float h);

	/// @see wyNode::getBlendFunc
	virtual wyBlendFunc getBlendFunc() { return m_ribbon->getBlendFunc(); }

	/// @see wyNode::setBlendFunc
	virtual void setBlendFunc(wyBlendFunc func) { m_ribbon->setBlendFunc(func); }

	/// @see wyNode::getTexture
	virtual wyTexture2D* getTexture() { return m_ribbon->getTexture(); }

	/// @see wyNode::setTexture
	virtual void setTexture(wyTexture2D* tex) { m_ribbon->setTexture(tex); }

	/**
	 * \if English
	 * get the ribbon object being used, \link wyRibbon wyRibbon\endlink
	 * \else
	 * 获得包含的\link wyRibbon wyRibbon\endlink 对象
	 *
	 * @return \link wyRibbon wyRibbon\endlink
	 * \endif
	 */
	wyRibbon* getRibbon() { return m_ribbon; }

	/**
	 * \if English
	 * getter
	 *
	 * @return \link wyPoint wyPoint\endlink (-1,-1) means the lastLocation is invalid
	 * \else
	 * 得到上一个点的位置, 为全局坐标. 如果返回的坐标是(-1, -1), 说明lastLocation还不存在，
	 * 有可能motion streak处于一个新线段的开始，还没有超过两个点，所以并无线段存在。
	 *
	 * @return \link wyPoint wyPoint\endlink
	 * \endif
	 */
	wyPoint getLastLocation() { return m_lastLocation; }

	/**
	 * \if English
	 * getter
	 *
	 * @return \link wyPoint wyPoint\endlink, (-1, 1) means currentLocation is invalid
	 * \else
	 * 得到当前点的位置, 为全局坐标, 如果返回的坐标是(-1, -1), 说明当前点还不存在，也就是对于
	 * 当前线段来说，一个点也没有。
	 *
	 * @return \link wyPoint wyPoint\endlink
	 * \endif
	 */
	wyPoint getCurrentLocation() { return m_currentLocation; }

	/**
	 * \if English
	 * set to pause tracking or not
	 *
	 * @param flag true means pause
	 * \else
	 * 设置暂停更新标志
	 *
	 * @param flag true表示暂停更新streak
	 * \endif
	 */
	void setPaused(bool flag) { m_paused = flag; }

	/**
	 * \if English
	 * getter
	 * \else
	 * 得到暂停更新标志
	 *
	 * @return true表示暂停更新streak
	 * \endif
	 */
	bool isPaused() { return m_paused; }

	/**
	 * \if English
	 * add one point
	 *
	 * @param x x coordinate, relative to the position of the node
	 * @param y y coordinate, relative to the position of the node
	 * @param newSegment true means a new segment is generated
	 * \else
	 * 添加一个点到轨迹中
	 *
	 * @param x 点的x值，这个值是相对于\link wyMotionStreak wyMotionStreak\endlink自身位置的
	 * @param y 点的y值，这个值是相对于\link wyMotionStreak wyMotionStreak\endlink自身位置的
	 * @param newSegment true表示强制结束当前分段，另起一个分段。另起一个分段的意思试在一个新
	 * 		的位置开始渲染，而不是上一个位置自动和新位置连接。缺省是false
	 * \endif
	 */
	void addPoint(float x, float y, bool newSegment = false);

	/**
	 * \if English
	 * this operation will clear all the tracks and restore the node to its original state
	 * \else
	 * 重置，立刻清除当前所有的轨迹点, 回到初始状态
	 * \endif
	 */
	void reset();

	/**
	 * \if English
	 * get the style being used
	 *
	 * @return \link wyMotionStreakStyle wyMotionStreakStyle\endlink
	 * \else
	 * motion streak中轨迹渲染的样式
	 *
	 * @return 样式常量
	 * \endif
	 */
	wyMotionStreakStyle getStyle() { return m_style; }

	/**
	 * \if English
	 * set the threshold value
	 *
	 * @param threshold, in pixels, if the node moved beyond this value, new segment will be generated
	 * \else
	 * 设置段阈值
	 *
	 * @param threshold 段阈值
	 * \endif
	 */
	void setSegmentThreshold(float threshold) { m_segThreshold = threshold; }

	/**
	 * \if English
	 * getter
	 * \else
	 * 得到段阈值
	 *
	 * @return 段阈值
	 * \endif
	 */
	float getSegmentThreshold() { return m_segThreshold; }
};

#endif // __wyMotionStreak_h__
