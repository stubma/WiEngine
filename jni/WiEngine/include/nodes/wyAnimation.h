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
#ifndef __wyAnimation_h__
#define __wyAnimation_h__

#include "wyArray.h"
#include "wyFrame.h"
#include "wyTexture2D.h"
#if ANDROID
	#include <jni.h>
#endif

class wyAnimate;
class wyAnimation;

/**
 * @struct wyAnimationCallback
 * \if English
 * callback which will be called as animation runs.
 * Notice, \link wyAnimation wyAnimation\endlink is not an action, instead, you should use
 * \link wyAnimate wyAnimate\endlink to execute an animation. This callback is called from
 * \link wyAnimate wyAnimate\endlink.
 * \else
 * 动画回调定义。\link wyAnimation wyAnimation\endlink 本身并不会
 * 自动运行，需要结合\link wyAnimate wyAnimate\endlink 使用时，这些
 * 回调会被\link wyAnimate wyAnimate\endlink 调用。
 * \endif
 */
typedef struct wyAnimationCallback {
	/**
	 * \if English
	 * called when the displaying frame changes
	 *
	 * @param anim \link wyAnimation wyAnimation\endlink object
	 * @param index the index of the displaying frame
	 * @param data data pointer passed when you call wyAnimation::setCallback
	 * \else
	 * 帧变化时调用
	 *
	 * @param anim \link wyAnimation wyAnimation\endlink 对象
	 * @param index 当前帧索引
	 * @param data 额外数据指针
	 * \endif
	 */
	void (*onAnimationFrameChanged)(wyAnimation* anim, int index, void* data);

	/**
	 * \if English
	 * called when the animation ends.
	 * If \link wyAnimate wyAnimate\endlink runs inside a \link wyRepeat wyRepeat\endlink action,
	 * this method will be called every time wyAnimate is repeated.
	 * @param anim \link wyAnimation wyAnimation\endlink object
	 * @param data data pointer passed when you call wyAnimation::setCallback
	 * \else
	 * 动画结束时调用，如果\link wyAnimate wyAnimate\endlink 被包含在一个
	 * repeat动作中执行，则每执行一遍这个方法都会被调用一次
	 *
	 * @param anim \link wyAnimation wyAnimation\endlink 对象
	 * @param data 额外数据指针
	 * \endif
	 */
	void (*onAnimationEnded)(wyAnimation* anim, void* data);
} wyAnimationCallback;

/**
 * @class wyAnimation
 * \if English
 * The animation consists of frames with each frame has a duration.
 * \else
 * 动画的封装, 设置动画的帧和持续时间
 * \endif
 */
class WIENGINE_API wyAnimation : public wyObject {
	friend class wyAnimate;

private:
	/**
	 * \if English
	 * identifier of the animation
	 * \else
	 * 动画id
	 * \endif
	 */
	int m_id;

	/**
	 * \if English
	 * \link wyArray wyArray\endlink object, used to store frames
	 * \else
	 * 帧列表的\link wyArray wyArray对象 \endlink 指针
	 * \endif
	 */
	wyArray* m_frames;

	/**
	 * \if English
	 * duration of the whole animation
	 * \else
	 * 动画持续的时间
	 * \endif
	 */
	float m_duration;

	/// \link wyAniamtionCallback wyAnimationCallback\endlink
	wyAnimationCallback m_callback;

#if ANDROID
	/// java端回调
	jobject m_jCallback;
#endif

	/**
	 * \if English
	 * used to store the data pointer passed in setCallback
	 * \else
	 * 额外用户数据指针
	 * \endif
	 */
	void* m_data;

private:
	/**
	 * \if English
	 * to release a frame
	 *
	 * @param arr the pointer to frame \link wyArray array\endlink
	 * @param ptr the current frame
	 * @param index index of the frame to be released
	 * @param data user data
	 * \else
	 * 释放某一帧动画资源，枚举函数指针
	 *
	 * @param arr 帧列表的\link wyArray wyArray对象 \endlink 指针
	 * @param ptr 当前帧的指针
	 * @param index 该帧在wyArray中的索引位置
	 * @param data 参数
	 * \endif
	 */
	static bool releaseFrame(wyArray* arr, void* ptr, int index, void* data);

protected:
	/**
	 * \if Englsih
	 * called when the frame changes
	 *
	 * @param index the index of the current frame
	 * \else
	 * 通知回调方法，帧已经变化
	 *
	 * @param index 当前帧索引
	 * \endif
	 */
	void notifyAnimationFrameChanged(int index);

	/**
	 * \if English
	 * called when the animation ends
	 * \else
	 * 通知回调方法，动画已经结束, 如果\link wyAnimate wyAnimate\endlink 被包含在一个
	 * repeat动作中执行，则每执行一遍这个方法都会被调用一次
	 * \endif
	 */
	void notifyAnimationEnded();

protected:
	/**
	 * constructor
	 *
	 * @param id identifier
	 */
	wyAnimation(int id);

public:
	/**
	 * \if English
	 * factory function, used to created a new instance with autoRelease enabled
	 *
	 * @param id identifier
	 * \else
	 * 静态构造函数
	 *
	 * @param id 动画id
	 * \endif
	 */
	static wyAnimation* make(int id);

	/**
	 * \if Englsih
	 * destructor
	 * \else
	 * 析构函数
	 * \endif
	 */
	virtual ~wyAnimation();

	/**
	 * \if English
	 * getter, get the total duration of the whole animation
	 * \else
	 * 动画接口实现: 得到动画总持续时间
	 *
	 * @return 动画总持续时间
	 * \endif
	 */
	float getDuration() { return m_duration; }

	/**
	 * \if English
	 * getter, get the frame array
	 * \else
	 * 动画接口实现: 获得帧列表
	 *
	 * @return 帧对象数组
	 * \endif
	 */
	wyArray* getFrames() { return m_frames; }

	/**
	 * \if English
	 * getter, get the identifier of the animation
	 * \else
	 * 动画接口实现: 得到动画id。为了区分动画，可以给动画一个id
	 *
	 * @return 动画id
	 * \endif
	 */
	int getId() { return m_id; }

	/**
	 * \if English
	 * to add a frame to the animation
	 *
	 * @param frameDuration duration of the frame to be added
	 * @param tex \link wyTexture2D wyTexture2D object\endlink
	 * \else
	 * 添加一帧动画
	 *
	 * @param frameDuration 所添加的帧持续的时间
	 * @param tex \link wyTexture2D wyTexture2D对象 \endlink 指针
	 * \endif
	 */
	void addFrame(float frameDuration, wyTexture2D* tex);

	/**
	 * \if English
	 * to add a frame to the animation
	 *
	 * @param frameDuration duration of the frame to be added
	 * @param rect the rectangle of the frame in the atlas picture
	 * \else
	 * 添加一帧动画, 帧的图片是图片集中的一部分
	 *
	 * @param frameDuration 所添加的帧持续的时间
	 * @param rect 帧图片在图片集中的矩形
	 * \endif
	 */
	void addFrame(float frameDuration, wyRect rect);

	/**
	 * \if English
	 * to add a frame
	 *
	 * @param f \link wyFrame wyFrame\endlink
	 * \else
	 * 添加一帧动画
	 *
	 * @param f \link wyFrame wyFrame\endlink
	 * \endif
	 */
	void addFrame(wyFrame* f);

	/**
	 * \if English
	 * to set the callback
	 *
	 * @param callback \link wyAnimationCallback wyAnimationCallback\endlink
	 * @param data user data
	 * \else
	 * 设置回调
	 *
	 * @param callback \link wyAnimationCallback wyAnimationCallback\endlink 结构指针
	 * @param data 额外数据指针
	 * \endif
	 */
	void setCallback(wyAnimationCallback* callback, void* data);

#if ANDROID
	/**
	 * \if Englsih
	 * to set the callback on the java end
	 *
	 * @param jCallback a java object
	 * \else
	 * 设置java端回调
	 *
	 * @param jCallback java回调接口的实现对象
	 * \endif
	 */
	void setCallback(jobject jCallback);
#endif
};

#endif //__wyAnimation_h__
