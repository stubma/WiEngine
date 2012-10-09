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
#ifndef __wyDirector_android_h__
#define __wyDirector_android_h__

#if ANDROID

#include "wyDirector.h"

/**
 * @class wyDirector_android
 *
 * \if English
 * Android specific director implementation
 * \else
 * Android平台特定的director实现
 * \endif
 */
class wyDirector_android : public wyDirector {
	friend class wyDirector;

private:
	/**
	 * \if English
	 * used to store the listeners created on the java end
	 * \else
	 * java端的生命周期监听器
	 * \endif
	 */
	wyArray* m_jLifecycleListeners;

	/**
	 * \if English
	 * to mark whether the game still runs when it is put background,
	 * by default the value is false
	 * \else
	 *  true表示在游戏退到后台时仍然保持游戏逻辑运行, 缺省是不保持游戏运行
	 * \endif
	 */
	bool m_allowBackgroundRunning;

	/**
	 * \if English
	 * to make whether the game is running in the background
	 * \else
	 * true表示游戏当前正在后台运行
	 * \endif
	 */
	bool m_backgroundRunning;

	/**
	 * \if English
	 * backup of the max frame rate
	 * \else
	 * 最大帧率值备份
	 * \endif
	 */
	int m_originalMaxFrameRate;

private:
	static bool j_notifySurfaceCreated(wyArray* arr, void* ptr, int index, void* data);
	static bool j_notifySurfaceChanged(wyArray* arr, void* ptr, int index, void* data);
	static bool j_notifySurfaceDestroyed(wyArray* arr, void* ptr, int index, void* data);
	static bool j_notifyDirectorPaused(wyArray* arr, void* ptr, int index, void* data);
	static bool j_notifyDirectorResumed(wyArray* arr, void* ptr, int index, void* data);
	static bool j_notifyDirectorEnded(wyArray* arr, void* ptr, int index, void* data);
	static bool j_notifyDirectorScreenCaptured(wyArray* arr, void* ptr, int index, void* data);
	static bool j_releaseListener(wyArray* arr, void* ptr, int index, void* data);

	/// background looper for background running
	void backgroundLooper(wyTargetSelector* sel);

	/**
	 * \if English
	 * set up the android adapter layer
	 * \else
	 * 初始化SAL
	 * \endif
	 */
	void setupAAL();

protected:
	wyDirector_android();

	/// @see wyDirector::stopRender
	virtual void stopRender();

	/// @see wyDirector::startRender
	virtual void startRender();

	/// @see wyDirector::end
	virtual void end();

	/*
	 * callback trigger
	 */

	virtual void notifySurfaceCreated();
	virtual void notifySurfaceChanged();
	virtual void notifySurfaceDestroyed();
	virtual void notifyDirectorPaused();
	virtual void notifyDirectorResumed();
	virtual void notifyDirectorEnded();
	virtual void notifyDirectorScreenCaptured();

public:
	virtual ~wyDirector_android();

	/// @see wyDirector::attachContext
	virtual void attachContext(wyGLContext context);

	/// @see wyDirector::attachInView
	virtual void attachInView(wyGLSurfaceView glView);

	/// @see wyDirector::setScaleMode
	virtual void setScaleMode(wyScaleMode mode);

	/// @see wyDirector::onSurfaceCreated
	virtual void onSurfaceCreated();

	/// @see wyDirector::onSurfaceDestroyed
	virtual void onSurfaceDestroyed();

	/// @see wyDirector::setAllowBackgroundRunning
	virtual void setAllowBackgroundRunning(bool flag);

	/// @see wyDirector::isAllowBackgroundRunning
	virtual bool isAllowBackgroundRunning();

	/// @see wyDirector::setAccelerometerDelay
	virtual void setAccelerometerDelay(wySensorDelay delay);

	/**
	 * \if English
	 * invoked when add a life cycle listener from the java end
	 *
	 * @param l java object implementing IDirectorLifecycleListener interface
	 * \else
	 * 添加一个java端的生命周期监听器
	 *
	 * @param l java端声明周期监听器，需要是一个实现了IDirectorLifecycleListener接口的对象
	 * \endif
	 */
	void addLifecycleListener(jobject l);
};

#endif // #if ANDROID

#endif // __wyDirector_android_h__
