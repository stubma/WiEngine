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
#ifndef __wyFixtureAnimation_h__
#define __wyFixtureAnimation_h__

#include "wyObject.h"
#include "wyArray.h"
#include "wyScheduler.h"
#include "wyTexture2D.h"
#include <Box2D/Box2D.h>
#include <stdbool.h>
#if ANDROID
	#include <jni.h>
#endif

class wyBox2DRender;

/**
 * @struct wyFixtureAnimationCallback
 *
 * \if English
 * callback of fixture animation
 * \else
 * Fixture动画的回调函数
 * \endif
 */
typedef struct BOX2D_API wyFixtureAnimationCallback {
	/**
	 * \if English
	 * invoked when animation ended
	 *
	 * @param fixture b2Fixture object
	 * \else
	 * 动画结束时被调用
	 *
	 * @param fixture b2Fixture类, 该类在box2d代码中定义, 不是WiEngine原生结构
	 * \endif
	 */
	void (*onAnimationEnd)(b2Fixture* fixture);

	/**
	 * \if English
	 * invoked when animation aborted
	 *
	 * @param fixture b2Fixture object
	 * \else
	 * 动画中止是被调用
	 *
	 * @param fixture b2Fixture类, 该类在box2d代码中定义, 不是WiEngine原生结构
	 * \endif
	 */
	void (*onAnimationAborted)(b2Fixture* fixture);
} wyFixtureAnimationCallback;

/**
 * @class wyFixtureAnimation
 *
 * \if English
 * do animation on a b2Fixture
 * \else
 * 封装在Fixture上执行动画的逻辑
 * \endif
 */
class BOX2D_API wyFixtureAnimation : public wyObject {
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
	 * b2Fixture object
	 * \else
	 * 相关的box2d的b2Fixture类
	 * \endif
	 */
	b2Fixture* m_fixture;

	/**
	 * \if English
	 * animation timer
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
	 * duration of all frames
	 * \else
	 * 动画播放一次的总时间
	 * \endif
	 */
	float m_frameTotalDuration;

	/**
	 * \if English
	 * true indicating loop play
	 * \else
	 * true表示是否循环播放
	 * \endif
	 */
	bool m_loop;

	/**
	 * \if English
	 * time elapsed
	 * \else
	 * 已经过去的时间
	 * \endif
	 */
	float m_elapsed;

	/**
	 * \if English
	 * animation callback
	 * \else
	 * 回调
	 * \endif
	 */
	wyFixtureAnimationCallback* m_callback;

#if ANDROID
	/**
	 * \if English
	 * callback in java side
	 * \else
	 * java端的回调
	 * \endif
	 */
	jobject m_jCallback;
#endif

private:
	static bool releaseFrame(wyArray* arr, void* ptr, int index, void* data);

protected:
	void invokeOnEnd();
	void invokeOnAborted();

	wyBox2DRender* getBox2DRender();

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
	static wyFixtureAnimation* make(float duration, ...);

	wyFixtureAnimation();
	virtual ~wyFixtureAnimation();

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
	 * start the animation on a fixture
	 *
	 * @param fixture the fixture which animation will be performed
	 * \else
	 * 开始在某个fixture上执行动画
	 *
	 * @param fixture 想要运行动画的box2d的b2Fixture类
	 * \endif
	 */
	void start(b2Fixture* fixture);

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
	 * set loop or not
	 *
	 * @param loop true means looping
	 * \else
	 * 设置是否循环播放
	 *
	 * @param loop true表示循环播放
	 * \endif
	 */
	void setLoop(bool loop);

	/**
	 * \if English
	 * is loop or not?
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
	 * set java side callback, native developer should not call it
	 *
	 * @param callback java side callback object
	 * \else
	 * 设置java端的回调对象, 这个方法仅用于支持java端编程, 在native端不应该使用
	 *
	 * @param callback java端的实现了回调接口的对象
	 * \endif
	 */
	void setJavaCallback(jobject callback);

	/**
	 * \if English
	 * get java side callback
	 *
	 * @return java side callback
	 * \else
	 * 获得java端的回调对象
	 *
	 * @return java端的实现了回调接口的对象
	 * \endif
	 */
	jobject getJavaCallback() { return m_jCallback; }
#endif
	
	/**
	 * \if English
	 * set duration time
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
	 * get duration time
	 *
	 * @return duration of animation
	 * \else
	 * 获得播放时间
	 *
	 * @return 播放时间
	 * \endif
	 */
	float getDuration() { return m_duration; }
};

#endif // __wyFixtureAnimation_h__
