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
#ifndef __wyShapeAnimation_h__
#define __wyShapeAnimation_h__

#include "wyObject.h"
#include "chipmunk.h"
#include "cpShape.h"
#include "wyArray.h"
#include "wyScheduler.h"
#include "wyTexture2D.h"
#include "wySpriteFrame.h"
#include <stdbool.h>
#if ANDROID
	#include <jni.h>
#endif

/**
 * @struct wyShapeAnimationCallback
 *
 * \if English
 * callback of shape animation event
 * \else
 * Shape动画的回调函数
 * \endif
 */
typedef struct CHIPMUNK_API wyShapeAnimationCallback {
	/**
	 * \if English
	 * invoked when animation ended
	 *
	 * @param shape cpSpace structure of chipmunk
	 * \else
	 * 动画结束时被调用
	 *
	 * @param shape cpShape结构, 该结构在chipmunk代码中定义, 不是WiEngine原生结构
	 * \endif
	 */
	void (*onAnimationEnd)(cpShape* shape);

	/**
	 * \if English
	 * invoked when animation is aborted
	 *
	 * @param shape cpSpace structure in chipmunk
	 * \else
	 * 动画中止是被调用
	 *
	 * @param shape cpShape结构, 该结构在chipmunk代码中定义, 不是WiEngine原生结构
	 * \endif
	 */
	void (*onAnimationAborted)(cpShape* shape);
} wyShapeAnimationCallback;

/**
 * @class wyShapeAnimation
 *
 * \if English
 * execute an animation on a chipmunk shape
 * \else
 * 封装在Shape上执行动画的逻辑
 * \endif
 */
class CHIPMUNK_API wyShapeAnimation : public wyObject {
protected:
	/**
	 * \if English
	 * frame list
	 * \else
	 * 动画帧列表
	 * \endif
	 */
	wyArray* m_frames;

	/**
	 * \if English
	 * related cpSpace structure
	 * \else
	 * 相关的chipmunk的cpShape结构
	 * \endif
	 */
	cpShape* m_shape;

	/**
	 * \if English
	 * timer to perform animation
	 * \else
	 * 执行动画的定时器
	 * \endif
	 */
	wyTimer* m_timer;

	/**
	 * \if English
	 * duration of animation
	 * \else
	 * 动画想要播放的时间
	 * \endif
	 */
	float m_duration;

	/**
	 * \if English
	 * total time of frames' duration
	 * \else
	 * 动画播放一次的总时间
	 * \endif
	 */
	float m_frameTotalDuration;

	/**
	 * \if English
	 * true indicating playing repeatly
	 * \else
	 * true表示是否循环播放
	 * \endif
	 */
	bool m_loop;

	/**
	 * \if English
	 * time alreay past
	 * \else
	 * 已经过去的时间
	 * \endif
	 */
	float m_elapsed;

	/**
	 * \if English
	 * callback
	 * \else
	 * 回调
	 * \endif
	 */
	wyShapeAnimationCallback* m_callback;

#if ANDROID
	/**
	 * \if English
	 * java side callback
	 * \else
	 * java端的回调
	 * \endif
	 */
	jobject m_jCallback;
#endif

	/**
	 * \if English
	 * true indicating adjust shape size to frame size, default is false
	 * \else
	 * true表示shape的大小会随着帧的大小改变, 缺省是false
	 * \endif
	 */
	bool m_autoSize;

private:
	static bool releaseFrame(wyArray* arr, void* ptr, int index, void* data);

protected:
	void invokeOnEnd();
	void invokeOnAborted();

	/// update single step
	void update(wyTargetSelector* ts);

public:
	/**
	 * \if English
	 * static factory method
	 *
	 * @param duration duration of a single frame
	 * \else
	 * 创建一个实例
	 *
	 * @param duration 每帧的持续时间
	 * \endif
	 */
	static wyShapeAnimation* make(float duration, ...);

	wyShapeAnimation();
	virtual ~wyShapeAnimation();

	/**
	 * \if English
	 * add a frame
	 *
	 * @param duration frame duration
	 * @param tex \link wyTexture2D wyTexture2D\endlink
	 * \else
	 * 添加一帧
	 *
	 * @param duration 该帧的持续时间
	 * @param tex 帧的贴图\link wyTexture2D wyTexture2D\endlink 对象
	 * \endif
	 */
	void addFrame(float duration, wyTexture2D* tex);

	/**
	 * \if English
	 * add a frame
	 *
	 * @param frame \link wySpriteFrame wySpriteFrame\endlink
	 * \else
	 * 添加一帧
	 *
	 * @param frame \link wySpriteFrame wySpriteFrame\endlink
	 * \endif
	 */
	void addFrame(wySpriteFrame* frame);

	/**
	 * \if English
	 * start animation on a shape
	 *
	 * @param shape the shape on which animation will be played
	 * \else
	 * 开始在某个shape上执行动画
	 *
	 * @param shape 想要运行动画的chipmunk的cpShape结构
	 * \endif
	 */
	void start(cpShape* shape);

	/**
	 * \if English
	 * stop animation
	 * \else
	 * 停止动画
	 * \endif
	 */
	void stop();

	/**
	 * \if English
	 * set looping or not
	 *
	 * @param loop true indicating loop
	 * \else
	 * 设置是否循环播放
	 *
	 * @param loop true表示循环播放
	 * \endif
	 */
	void setLoop(bool loop);

	/**
	 * \if English
	 * is looping or not
	 *
	 * @return true means looping
	 * \else
	 * 是否循环播放
	 *
	 * @return true表示循环播放
	 * \endif
	 */
	bool isLoop() { return m_loop; }

#if ANDROID
	/**
	 * \if English
	 * set java side callback, only available for Android platform
	 *
	 * @param callback the java side object which implements callback interface
	 * \else
	 * 设置java端的回调对象, 这个方法仅用于支持java端编程, 在native端不应该使用
	 *
	 * @param callback java端的实现了回调接口的对象
	 * \endif
	 */
	void setJavaCallback(jobject callback);

	/**
	 * \if English
	 * get java side callback object
	 *
	 * @return the java side object which implements callback interface
	 * \else
	 * 获得java端的回调对象
	 *
	 * @return java端的实现了回调接口的对象
	 * \endif
	 */
	jobject getJavaCallback() { return m_jCallback; }
#endif // #if ANDROID

	/**
	 * \if English
	 * should adjust shape size based on frame size. if true, shape size will be set to
	 * same size as frame. if false and frame size is not equal with shape size, then frame
	 * texture will be scaled
	 *
	 * @param autoSize true means auto sizing
	 * \else
	 * 设置是否自动改变大小. 如果是true, 则shape的大小会变成和当前动画帧
	 * 一样大. 如果是false, 则动画贴图会被缩放到shape那么大, 所以如果比例不一致,
	 * 则会出现变形.
	 *
	 * @param autoSize true表示自动调整shape大小
	 * \endif
	 */
	void setAutoSize(bool autoSize) { m_autoSize = autoSize; }

	/**
	 * \if English
	 * should adjust shape size based on frame size
	 *
	 * @return true means auto sizing is enabled
	 * \else
	 * 是否自动改变大小
	 *
	 * @return true表示自动改变大小
	 * \endif
	 */
	bool isAutoSize() { return m_autoSize; }

	/**
	 * \if English
	 * set duration time of animation
	 *
	 * @param duration duration of animation
	 * \else
	 * 设置播放时间
	 *
	 * @param duration 播放时间
	 * \endif
	 */
	void setDuration(float duration) { m_duration = duration; }

	/**
	 * \if English
	 * get duration of animation
	 *
	 * @return duration of animation
	 * \else
	 * 获得播放时间
	 *
	 * @return 播放时间
	 * \endif
	 */
	float getDuration() { return m_duration; }
    
	/**
	 * \if English
	 * set callback
	 * \else
	 * 设置回调
	 * \endif
	 */
    void setCallback(wyShapeAnimationCallback* cb);
};

#endif // __wyShapeAnimation_h__
