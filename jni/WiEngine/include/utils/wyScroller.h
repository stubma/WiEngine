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
#ifndef __wyScroller_h__
#define __wyScroller_h__

#include "wyObject.h"

/**
 * @class wyScroller
 *
 * \if English
 * it calculates scrolling position and do nothing without UI. It is a
 * great helper class for scroll or fling implmementation.
 * \else
 * 负责计算滚动和惯性移动的位置，并不涉及任何界面上的操作。需要提供滚动和惯性移动
 * 支持的时候，可以使用该类进行位置计算，在刷新时从该类得到当前位置，进行界面更新。
 * \endif
 */
class WIENGINE_API wyScroller : public wyObject {
private:
    /**
     * \if English
     * friction coefficient, default is 0.015
     * \else
     * 应用在滚动和fling上的摩擦力系数，缺省值是0.015
     * \endif
     */
	float m_scrollFriction;

	/**
	 * \if English
	 * current mode, scroll or fling
	 * \else
	 * 当前模式，是滚动还是fling
	 * \endif
	 */
	int m_mode;

	/**
	 * \if English
	 * start x position
	 * \else
	 * 起始x位置
	 * \endif
	 */
	float m_startX;

	/**
	 * \if English
	 * start y position
	 * \else
	 * 起始y位置
	 * \endif
	 */
	float m_startY;

	/**
	 * \if English
	 * end x position
	 * \else
	 * 结束x位置
	 * \endif
	 */
	float m_finalX;

	/**
	 * \if English
	 * end y position
	 * \else
	 * 结束y位置
	 * \endif
	 */
	float m_finalY;

	/**
	 * \if English
	 * minimum x position
	 * \else
	 * 最小x位置
	 * \endif
	 */
	float m_minX;

	/**
	 * \if English
	 * maximum x position
	 * \else
	 * 最大x位置
	 * \endif
	 */
	float m_maxX;

	/**
	 * \if English
	 * minimum y position
	 * \else
	 * 最小y位置
	 * \endif
	 */
	float m_minY;

	/**
	 * \if English
	 * maximum y position
	 * \else
	 * 最大y位置
	 * \endif
	 */
	float m_maxY;

	/**
	 * \if English
	 * current x position
	 * \else
	 * 当前x位置
	 * \endif
	 */
	float m_currX;

	/**
	 * \if English
	 * current y position
	 * \else
	 * 当前y位置
	 * \endif
	 */
	float m_currY;

	/**
	 * \if English
	 * start time in millisecond
	 * \else
	 * 开始时间
	 * \endif
	 */
	int m_startTime;

	/**
	 * \if English
	 * fling duration time
	 * \else
	 * 持续时间
	 * \endif
	 */
	int m_duration;

	/**
	 * \if English
	 * reciprocal of duartion time
	 * \else
	 * 持续时间的倒数
	 * \endif
	 */
	float m_durationReciprocal;

	/**
	 * \if English
	 * x offset to scroll
	 * \else
	 * 滚动的x偏移量，相当于m_finalX - m_startX
	 * \endif
	 */
	float m_deltaX;

	/**
	 * \if English
	 * y offset to scroll
	 * \else
	 * 滚动的y偏移量，相当于m_finalY - m_startY
	 * \endif
	 */
	float m_deltaY;

	/**
	 * \if English
	 * viscous fluid coefficient
	 * \else
	 * scroller会模拟粘性流体来模拟滚动和fling，这是粘性流体系数
	 * \endif
	 */
	float m_viscousFluidScale;

	/**
	 * \if English
	 * viscous fluid normalization value
	 * \else
	 * 粘性流体规范化值
	 * \endif
	 */
	float m_viscousFluidNormalize;

	/**
	 * \if English
	 * is scroll or fling finished
	 * \else
	 * 是否已经完成滚动或fling
	 * \endif
	 */
	bool m_finished;

	/**
	 * \if English
	 * proportion of x velocity and total velocity
	 * \else
	 * x方向速度和fling总速度的比例
	 * \endif
	 */
	float m_coeffX;

	/**
	 * \if English
	 * proportion of y velocity and total velocity
	 * \else
	 * y方向速度和fling总速度的比例
	 * \endif
	 */
	float m_coeffY;

	/**
	 * \if English
	 * velocity of fling
	 * \else
	 * fling的总速度
	 * \endif
	 */
	float m_velocity;

	/**
	 * \if English
	 * deceleration of fling
	 * \else
	 * fling的减速度
	 * \endif
	 */
	float m_deceleration;

private:
	/**
	 * \if English
	 * based on viscous fluid coefficient, convert linear time to non-linear
	 * time
	 *
	 * @param x from 0 to 1, means a linear time range
	 * @return the non-linear time converted
	 * \else
	 * 根据粘性流体将线性时间转换为非线性时间，类似于Ease Action所做的事
	 *
	 * @param x 从0到1的值，代表一个线性时间范围
	 * @return 经过粘性流体转换后的新值，0到1之间
	 * \endif
	 */
    float viscousFluid(float x);

public:
    static wyScroller* make();

	wyScroller();
	virtual ~wyScroller();

    /**
     * \if English
     * is scroll or fling finished
     *
     * @return true means scroll or fling finished
     * \else
     * 检查是否已经完成了滚动
     *
     * @return true表示已经完成了滚动
     * \endif
     */
    bool isFinished() const { return m_finished; }

    /**
     * \if English
     * force scrolling or flinging finish
     *
     * @param finished true means finish scrolling or flinging, or false if not
     * \else
     * 强制结束滚动或强制不结束
     *
     * @param finished true表示结束滚动，false表示不结束
     * \endif
     */
    void forceFinished(bool finished) { m_finished = finished; }

    /**
     * \if English
     * return the duration time of scrolling
     *
     * @return scroll duration, in millisceond
     * \else
     * 返回滚动持续的时间，单位毫秒
     *
     * @return 滚动持续的时间，单位毫秒
     * \endif
     */
    int getDuration() const { return m_duration; }

    /**
     * \if English
     * return current x position
     *
     * @return current x position
     * \else
     * 返回当前的x位置
     *
     * @return 当前x位置
     * \endif
     */
    int getCurrX() const { return m_currX; }

    /**
     * \if English
     * return current y position
     *
     * @return current y position
     * \else
     * 返回当前的y位置
     *
     * @return 当前y位置
     * \endif
     */
    int getCurrY() const { return m_currY; }

    /**
     * \if English
     * get current velocity
     *
     * @return current velocity, maybe negative
     * \else
     * 得到当前速度
     *
     * @return 当前速度，可能为负
     * \endif
     */
    float getCurrVelocity() const { return m_velocity - m_deceleration * timePassed() / 2000.0f; }

    /**
     * \if English
     * get current velocity
     *
     * @return current velocity, maybe negative
     * \else
     * 得到起始x位置
     *
     * @return 起始x位置
     * \endif
     */
    float getStartX() const { return m_startX; }

    /**
     * \if English
     * get start y position
     *
     * @return start y position
     * \else
     * 得到起始y位置
     *
     * @return 起始y位置
     * \endif
     */
    float getStartY() const { return m_startY; }

    /**
     * \if English
     * get final x position, only used for flinging
     *
     * @return final x position of flinging
     * \else
     * 得到结束x位置，这个只用于fling
     *
     * @return fling的结束x位置
     * \endif
     */
    float getFinalX() const { return m_finalX; }

    /**
     * \if English
     * get final y position of flinging
     *
     * @return final y position of flinging
     * \else
     * 得到结束y位置，这个只用于fling
     *
     * @return fling的结束y位置
     * \endif
     */
    float getFinalY() const { return m_finalY; }

    /**
     * \if English
     * get current scrolling position
     *
     * @return true means scrolling is not over, false means finished
     * \else
     * 得到当前的滚动位置，用于想更新界面时。
     *
     * @return true表示滚动还未结束，false表示已经结束
     * \endif
     */
    bool computeScrollOffset();

    /**
     * \if English
     * start scrolling, duration time is 0.25 second
     *
     * @param startX start x position
     * @param startY start y position
     * @param dx x offset to scroll
     * @param dy y offset to scroll
     * \else
     * 开始滚动，持续250毫秒
     *
     * @param startX 起始x位置
     * @param startY 起始y位置
     * @param dx x方向滚动量
     * @param dy y方向滚动量
     * \endif
     */
    void startScroll(float startX, float startY, float dx, float dy);

    /**
     * \if English
     * start scrolling
     *
     * @param startX start x position
     * @param startY start y position
     * @param dx x offset to scroll
     * @param dy y offset to scroll
     * @param duration duration time of scroll
     * \else
     * 开始滚动
     *
     * @param startX 起始x位置
     * @param startY 起始y位置
     * @param dx x方向滚动量
     * @param dy y方向滚动量
     * @param duration 期望的滚动持续时间, 单位是毫秒
     * \endif
     */
    void startScroll(float startX, float startY, float dx, float dy, int duration);

    /**
     * \if English
     * start fling. duration time of fling is computed.
     *
     * @param startX start x position
     * @param startY start y position
     * @param velocityX initial x velocity
     * @param velocityY initial y velocity
     * @param minX minimum x position
     * @param maxX maximum x position
     * @param minY minimum y position
     * @param maxY maximum y position
     * \else
     * 开始fling。Fling的持续持续时间是计算出来的，不像滚动的持续时间是指定的。
     *
     * @param startX 起始x位置
     * @param startY 起始y位置
     * @param velocityX 初始x速度，单位是像素/秒
     * @param velocityY 初始y速度，单位是像素/秒
     * @param minX 最小x位置
     * @param maxX 最大x位置
     * @param minY 最小y位置
     * @param maxY 最大y位置
     * \endif
     */
    void fling(float startX, float startY, float velocityX, float velocityY,
    		float minX, float maxX, float minY, float maxY);

    /**
     * \if English
     * stop fling
     * \else
     * 停止滚动
     * \endif
     */
    void abortAnimation();

    /**
     * \if English
     * extend duration time of scrolling
     *
     * @param extend time to be extended
     * \else
     * 扩展滚动持续时间，一般结合setFinalX或setFinalY使用
     *
     * @param extend 需要扩展的时间，单位毫秒
     * \endif
     */
    void extendDuration(int extend);

    /**
     * \if English
     * get time passed from scrolling start to now, in millisecond
     *
     * @return time passed from scrolling start to now, in millisecond
     * \else
     * 得到从开始滚动到现在已经过去的时间，单位毫秒
     *
     * @return 从开始滚动到现在已经过去的时间，单位毫秒
     * \endif
     */
    int timePassed() const;

    /**
     * \if English
     * set final x position
     *
     * @param newX final x position
     * \else
     * 设置滚动结束x位置
     *
     * @param newX 结束x位置
     * \endif
     */
    void setFinalX(float newX);

    /**
     * \if English
     * set final y position
     *
     * @param newY final y position
     * \else
     * 设置滚动结束y位置
     *
     * @param newY 滚动结束y位置
     * \endif
     */
    void setFinalY(float newY);

    /**
     * \if English
     * friction coefficient, default is 0.0.15
     *
     * @param friction friction coefficient
     * \else
     * 设置滚动摩擦系数，如果不设置，缺省值是0.015
     *
     * @param friction 摩擦系数
     * \endif
     */
    void setScrollFriction(float friction) { m_scrollFriction = friction; }
};

#endif // __wyScroller_h__
