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
#ifndef __wyDirector_h__
#define __wyDirector_h__

#include "WiEngine-Classes.h"
#include <stdbool.h>
#include "wyObject.h"
#include "wyTypes.h"

/**
 * @typedef wyProjectionType
 * \if English
 * definitions of projection modes
 * \else
 * OpenGL投影方式
 * \endif
 */
typedef enum {
	/**
	 * \if English
	 * Orthographic projection
	 * \else
	 * 正交投影方式
	 * \endif
	 */
	PROJECTION_2D = 1,

	/**
	 * \if English
	 * Perspetive projection
	 * \else
	 * 3D投影方式，fovy=60, znear=0.5f, zfar=1500.
	 * \endif
	 */
	PROJECTION_3D,

	/**
	 * \if English
	 * user-customized projection
	 * \else
	 * 自定义投影方式，用户需要自己调用OpenGL接口设置投影方式
	 * \endif
	 */
	PROJECTION_CUSTOM
} wyProjectionType;

/// default projection is 3D
#define PROJECTION_DEFAULT PROJECTION_3D

/**
 * @typedef wySensorDelay
 * \if English
 * definitions of accelerometer level, different level stands for different frequency
 * the engine will use to listen the sensor event
 * \else
 * 加速器事件触发速度级别
 * \endif
 */
typedef enum {
	/**
	 * \if English
	 * get one event every 38 milliseconds
	 * \else
	 * 最快速度, 近似于每38毫秒一次事件
	 * \endif
	 */
	DELAY_FASTEST,

	/**
	 * \if English
	 * get one event every 62 milliseconds
	 * \else
	 * 较快速度, 近似于每62毫秒一次事件
	 * \endif
	 */
	DELAY_GAME,

	/**
	 * \if English
	 * get one event every 104 milliseconds
	 * \else
	 * 较慢速度, 近似于每104毫秒一次事件
	 * \endif
	 */
	DELAY_UI,

	/**
	 * \if English
	 * get one event every 254 milliseconds
	 * \else
	 * 最慢速度, 近似于每254毫秒一次事件
	 * \endif
	 */
	DELAY_NORMAL
} wySensorDelay;

#if MACOSX || WINDOWS

/**
 * @struct wyScreenConfig
 * 
 * \if English
 * In Mac OS X or Windows platform, you can designate screen info by pass
 * a screen config to director. But you must do it before first scene is created.
 * So, you can facilitate screen adaptation thru this handy feature: you don't
 * need to buy many hardware, just simulate it in PC!
 * \else
 * 在Mac OS X或Windows平台上, 你可以通过wyScreenConfig来指定屏幕的大小, 分辨率等信息.
 * 这样可以方便的测试屏幕适配, 你不需要购买各种不同屏幕分辨率的手机, 只要在PC上模拟测试就
 * 可以了
 * \endif
 */
typedef struct wyScreenConfig {
	/**
	 * \if English
	 * Density of current screen
	 * \else
	 * 当前设备的屏幕分辨率
	 * \endif
	 */
	float density;
	
	/**
	 * \if English
	 * Font ensity of current screen
	 * \else
	 * 当前设备屏幕的字体分辨率
	 * \endif
	 */
	float scaledDensity;
	
	/**
	 * \if English
	 * Surface width you expected
	 * \else
	 * 期望的surface宽度
	 * \endif
	 */
	int winWidth;
	
	/**
	 * \if English
	 * \par
	 * Expected surface height
	 * \else
	 * 期望的surface高度
	 * \endif
	 */
	int winHeight;
} wyScreenConfig;

#endif // #if MACOSX || WINDOWS

/**
 * @struct wyDirectorLifecycleListener
 *
 * \if English
 * Lifecycle event interface. You can install lifecycle listener thru \c addLifecycleListener method
 * \else
 * Director生命周期监听器接口, 通过\c addLifecycleListener方法可以添加生命周期监听器
 * \endif
 */
typedef struct wyDirectorLifecycleListener {
	/**
	 * \if English
	 * Invoked when surface created.
	 *
	 * @param data extra data pointer
	 * \else
	 * 在Surface被创建的时候调用
	 *
	 * @param data 附加数据指针
	 * \endif
	 */
	void (*onSurfaceCreated)(void* data);

	/**
	 * \if English
	 * Invoked when surface changed. Generally there is always a change event immediately after
	 * surface created. After this, game loop will be started.
	 *
	 * @param w new width of surface
	 * @param h new height of surface
	 * @param data extra data pointer
	 * \else
	 * 在Surface改变的时候被调用. 一般这个事件紧跟在surface创建之后. 这个事件发生后, 将开始
	 * 游戏循环
	 *
	 * @param w Surface新的宽度
	 * @param h Surface新的高度
	 * @param data 附加数据指针
	 * \endif
	 */
	void (*onSurfaceChanged)(int w, int h, void* data);

	/**
	 * \if English
	 * Invoked when surface destroyed, usually it is happened when game exited or
	 * switching to other activity
	 *
	 * @param data extra data pointer
	 * \else
	 * 在Surface销毁的时候调用, 一般这发生在游戏退出或切换到其它activity时
	 *
	 * @param data 附加数据指针
	 * \endif
	 */
	void (*onSurfaceDestroyed)(void* data);

	/**
	 * \if English
	 * Invoked when \c pause method is called. \c pause method must be called in
	 * activity onPause
	 *
	 * @param data extra data pointer
	 * \else
	 * 在Director的\c pause方法被调用后调用. \c pause方法必须在Activity的onPause中调用
	 *
	 * @param data 附加数据指针
	 * \endif
	 */
	void (*onDirectorPaused)(void* data);

	/**
	 * \if English
	 * Invoked when \c resume method is called. \c resume method must be called in
	 * activity onResume
	 *
	 * @param data extra data pointer
	 * \else
	 * 在Director的\c resume方法被调用后调用. \c resume方法必须在activity的onResume中调用.
	 *
	 * @param data 附加数据指针
	 * \endif
	 */
	void (*onDirectorResumed)(void* data);

	/**
	 * \if English
	 * Invoked when \c end method is called. \c end method must be called when game exited so
	 * this event means game ended
	 *
	 * @param data extra data pointer
	 * \else
	 * 在Director中止的时候被调用. Director中止是由于end方法被调用, 一般这意味着游戏已经退出
	 *
	 * @param data 附加数据指针
	 * \endif
	 */
	void (*onDirectorEnded)(void* data);

	/**
	 * \if English
	 * Invoked when a screenshot is captured.
	 *
	 * @param path path of screenshot file, maybe png or jpg and it is decided based on extension
	 * 		of file path when calling \c makeScreenshot method
	 * @param data extra data pointer
	 * \else
	 * 在一个截屏被保存后调用
	 *
	 * @param path 截屏保存后的图片路径, 可能是png或者jpg, 调用者应该清楚. 这是在调用\c makeScreenshot时
	 * 		通过路径的后缀名自动决定的.
	 * @param data 附加数据指针
	 * \endif
	 */
	void (*onDirectorScreenCaptured)(const char* path, void* data);
} wyDirectorLifecycleListener;

/**
 * @class wyDirector
 *
 * \if English
 * wyDirector is a singleton class which manages game flow, as well as providing
 * global API for upper layer
 * \else
 * wyDirector是一个控制游戏流程的单例类, 同时它也提供许多全局级别的API
 * \endif
 */
class WIENGINE_API wyDirector : public wyObject {
protected:
	/// render manager
	wyRenderManager* m_renderManager;

	/// main viewport
	wyViewport* m_mainViewport;

	/**
	 * \if English
	 * projection mode, by default it is PROJECTION_3D
	 * \else
	 * 投影类型，取值PROJECTION_3D，PROJECTION_2D,默认PROJECTION_DEFAULT
	 * \endif
	 */
	wyProjectionType m_projection;

	/**
	 * \if English
	 * interval between two consecutive frames, used to calculate frame rate
	 * \else
	 * 两帧之间的时间差，如果一秒平均60帧，则m_delta取值在17，16毫秒之间，取值样例为0.017，这个值根据当前帧率而变化
	 * \endif
	 */
	float m_delta;

	/**
	 * \if English
	 * time elapsed since the last frame rate calculation
	 * \else
	 * 自上一次帧率统计之后，已经绘制的帧用了的时间
	 * \endif
	 */
	float m_frameDelta;

	/**
	 * used to manually control tick interval, that will slow down or speed
	 * up game total behavior. zero means using real delta.
	 */
	float m_tickFactor;

	/**
	 * \if English
	 * frame rate, times per second
	 * \else
	 * 当前帧率
	 * \endif
	 */
	float m_frameRate;

	/**
	 * \if English
	 * frame count passed since the last frame rate calculation
	 * \else
	 * 自上一次帧率统计之后，已经显示的帧
	 * \endif
	 */
	int m_frames;

	/**
	 * \if English
	 * time point the last frame was updated
	 * \else
	 * 上一帧更新的时间
	 * \endif
	 */
	int64_t m_lastUpdateTime;

	/**
	 * \if English
	 * to mark whether it is needed to reload the underlying texture objects
	 * \else
	 * true表示需要在合适的时候检查底层的贴图对象是否被释放，如果是则要重新载入
	 * \endif
	 */
	bool m_needCheckTexture;

	/**
	 * \if English
	 * to mark paused state
	 * \else
	 * 标识当前场景是否暂停状态
	 * \endif
	 */
	bool m_paused;

	/**
	 * \if English
	 * to mark whether the UI is paused, a common case is that the player clicks the pause button
	 * \else
	 * 标识游戏当前是否被UI控制暂停或恢复
	 * \endif
	 */
	bool m_UIPaused;

	/**
	 * \if English
	 * to mark whether the focus state is enabled, true means enabled
	 * \else
	 * 标识游戏当前是否屏蔽wyNode焦点状态, 如果为true为可以用
	 * \endif
	 */
	bool m_focusEnabled;

	/**
	 * \if English
	 * to specify whether to display FPS label on the left bottom corner of the screen
	 * \else
	 * 标识是否显示FPS 在屏幕左下角
	 * \endif
	 */
	bool m_displayFPS;

	/**
	 * true means fps should be calculated even you don't want to display it
	 */
	bool m_calculateFPS;

	/**
	 * \if English
	 * to mark whether the surface view has been created
	 * \else
	 * 标识是否surface已经创建
	 * \endif
	 */
	bool m_surfaceCreated;

	/**
	 * \if English
	 * to mark whether it is needed to take a screen shot
	 * \else
	 * true表示下一帧要进行截图, 截图之后该标志重新设置为false
	 * \endif
	 */
	bool m_makeScreenshot;

	/**
	 * \if English
	 * the path to save the screen shot picture
	 * \else
	 * 截图文件保存的路径
	 * \endif
	 */
	const char* m_screenshotPath;

	/**
	 * \if English
	 * rectangle of screen shot
	 * \else
	 * 截图的范围
	 * \endif
	 */
	wyRect m_screenshotRect;

	/**
	 * \if English
	 * to guarantee the animation starts from its first frame
	 * \else
	 * true表示下一个delta时间设为0, 这主要用来避免因为资源载入导致的游戏体验不连续问题. 例如有一个场景中一开始就要执行动画,
	 * 但是由于场景载入需要耗费一定时间, 因此可能导致动画的前面几帧被跳过. 那么可以设置这个标志强制使下一个delta时间为0, 这样
	 * 动画将从第一帧开始.
	 * \endif
	 */
	bool m_nextDeltaTimeZero;

	/**
	 * \if English
	 * the maximum frame rate limit, 0 means no limit is set
	 * \else
	 * 最大帧率，如果为0，表示不限制, 缺省是0
	 * \endif
	 */
	int m_maxFrameRate;

	/**
	 * \if English
	 * the time cost by the last frame, in milliseconds
	 * \else
	 * 上一帧的绘制时间，单位是毫秒
	 * \endif
	 */
	int64_t m_lastFrameTime;

	/**
	 * \if English
	 * used in condition that the max frame rate is set
	 * \else
	 * 最小帧间隔，当最大帧率被设置时配合使用
	 * \endif
	 */
	int64_t m_minFrameInterval;

	/**
	 * \if English
	 * used in condition that the max frame rate is set
	 * \else
	 * 仅当最大帧率不为0时才有意义, 用于控制帧率的辅助变量
	 * \endif
	 */
	int64_t m_savedDelta;

	/**
	 * \if English
	 * the next scene to be activated, \link wyScene wyScene\endlink
	 * \else
	 * 下一场景\link wyScene wyScene对象\endlink 的指针
	 * \endif
	 */
	wyScene* m_nextScene;

	/**
	 * \if English
	 * the scene being running, \link wyScene wyScene\endlink
	 * \else
	 * 正在显示场景\link wyScene wyScene对象\endlink 的指针
	 * \endif
	 */
	wyScene* m_runningScene;

	/**
	 * \if English
	 * the label to display FPS, \link wyLabel wyLabel\endlink
	 * \else
	 * 用来显示FPS的\link wyLabel wyLabel对象\endlink 的指针
	 * \endif
	 */
	wyLabel* m_fpsLabel;

	/**
	 * \if English
	 * acts as a stack to push or pop scenes to, \link wyArray wyArray\endlink
	 * \else
	 * 场景堆栈 \link wyArray wyArray对象\endlink 的指针
	 * \endif
	 */
	wyArray* m_scenesStack;

	/**
	 * \if English
	 * array to store life cycle listeners
	 * \else
	 * Director生命周期事件监听器
	 * \endif
	 */
	wyArray* m_lifecycleListeners;

	/**
	 * \if English
	 * user data used in the life cycle listener
	 * \else
	 * 生命周期监听器的附加数据指针
	 * \endif
	 */
	void* m_lifecycleData;
	
	/**
	 * \if English
	 * \link wyGLSurfaceView wyGLSurfaceView\endlink
	 * \else
	 * OpenGlView的java对象
	 * \endif
	 */
	wyGLSurfaceView m_glView;

	/**
	 * \if English
	 * \link wyGLContext wyGLContext\endlink
	 * \else
	 * Android Context的java对象
	 * \endif
	 */
	wyGLContext m_context;

protected:
    /**
     * \if English
     * constructor
     * \else
	 * 构造函数
	 * \endif
	 */
	wyDirector();

	/**
	 * \if English
	 * calculate the time interval between 2 consecutive frames
	 * \else
	 * 计算两帧之间的时间差
	 * \endif
	 */
	void calculateDeltaTime();

	/**
	 * \if English
	 * draw the FPS label
	 * \else
	 * 显示FPS
	 * \endif
	 */
	void showFPS();

	/**
	 * Calculate FPS, can be enabled by \c setCalculateFPS
	 */
	void calculateFPS();

	/**
	 * \if English
	 * to set the running scene
	 *
	 * @param scene \link wyScene wyScene\endlink
	 * \else
	 * 设置当前的场景
	 *
	 * @param scene 场景\link wyScene wyScene对象\endlink 的指针
	 * \endif
	 */
	void setRunningScene(wyScene* scene);

	/**
	 * \if English
	 * to set the next scene
	 *
	 * @param scene \link wyScene wyScene\endlink
	 * \else
	 * 设置下一场景
	 *
	 * @param scene 场景\link wyScene wyScene对象\endlink 的指针
	 * \endif
	 */
	void setNextScene(wyScene* scene);

	/**
	 * \if English
	 * goto the next scene
	 * \else
	 * 切换至下一场景
	 * \endif
	 */
	void gotoNextScene();

	/**
	 * \if English
	 * Destroy common members which shared by all platforms
	 * \else
	 * 销毁成员
	 * \endif
	 */
	void commonDestroy();

	/**
	 * \if English
	 * Stop render when game paused
	 * \else
	 * 暂停渲染
	 * \endif
	 */
	virtual void stopRender() = 0;

	/**
	 * \if English
	 * Start render when game resumed
	 * \else
	 * 开始渲染
	 * \endif
	 */
	virtual void startRender() = 0;

	/**
	 * \if English
	 * End director, so end game and everything
	 * \else
	 * 结束Director, 结束一切
	 * \endif
	 */
	virtual void end() = 0;

	/*
	 * callback triggers
	 */

	virtual void notifySurfaceCreated();
	virtual void notifySurfaceChanged();
	virtual void notifySurfaceDestroyed();
	virtual void notifyDirectorPaused();
	virtual void notifyDirectorResumed();
	virtual void notifyDirectorEnded();
	virtual void notifyDirectorScreenCaptured();

	/*
	 * iterator functions
	 */

	static bool releaseScene(wyArray* arr, void* ptr, int index, void* data);
	static bool notifySurfaceCreated(wyArray* arr, void* ptr, int index, void* data);
	static bool notifySurfaceChanged(wyArray* arr, void* ptr, int index, void* data);
	static bool notifySurfaceDestroyed(wyArray* arr, void* ptr, int index, void* data);
	static bool notifyDirectorPaused(wyArray* arr, void* ptr, int index, void* data);
	static bool notifyDirectorResumed(wyArray* arr, void* ptr, int index, void* data);
	static bool notifyDirectorEnded(wyArray* arr, void* ptr, int index, void* data);
	static bool notifyDirectorScreenCaptured(wyArray* arr, void* ptr, int index, void* data);
	
public:
	/**
	 * \if English
	 * get the singleton instance
	 *
	 * @return singleton of director
	 * \else
	 * 获得\link wyDirector wyDirector对象指针\endlink
	 *
	 * @return \link wyDirector wyDirector对象指针\endlink
	 * \endif
	 */
	static wyDirector* getInstance();
	
	/**
	 * \if English
	 * Get the singleton instance, but don't create it if not exist
	 * 
	 * @return singleton of director, or NULL if not created yet
	 * \else
	 * 得到director的单一实例, 但是如果实例尚未创建, 则不会自动创建
	 * 
	 * @return director的单一实例, 如果还没有创建, 返回NULL
	 * \endif
	 */
	static wyDirector* getInstanceNoCreate();

	/**
	 * \if English
	 * check whether the director is performing ending phase.
	 *
	 * @return true means the director is ending now, it is strong suggested that
	 * no engine-related operations be made during this phase.
	 * \else
	 * 检查是否Director正在结束中. 这个方法可以用来在某些不确定的情况下, 检查进行某个操作是否安全.
	 * 比如, 正准备调用一个方法, 但是这个时候可能程序正在退出, 正在退出意味着底层的对象可能正在处于
	 * 释放过程中或者已经释放, 如果不做检查就调用, 则可能因为调用一个已销毁对象而导致程序崩溃.
	 *
	 * @return true表示Director正在销毁, 在此期间最好不要再做任何事.
	 * \endif
	 */
	static bool isEnding();

	/**
	 * \if English
	 * Set a resource decoder used to decode obfuscated resource file. Director won't
	 * take care decoder lifecycle, you must release it if needed
	 *
	 * @param decoder \link wyResourceDecoder wyResourceDecoder\endlink implementation, NULL
	 * 		will disable resource decoding
	 * \else
	 * 设置一个资源解码器. Director不会负责释放解码器, 你必须自己处理
	 *
	 * @param decoder \link wyResourceDecoder wyResourceDecoder\endlink的具体实现, NULL
	 * 		表示取消资源解码器
	 * \endif
	 */
	static void setResourceDecoder(wyResourceDecoder* decoder);

#if MACOSX || WINDOWS
	/**
	 * \if English
	 * Set a custom screen config, it is a handy way to test against different screens
	 * without buying hardware device.
	 *
	 * \note
	 * This method must be called very early, such as before first scene is created
	 * 
	 * @param c \link wyScreenConfig wyScreenConfig\endlink
	 * \else
	 * 设置一个自定义的屏幕设置, 可以用于模拟测试不同的屏幕适配. 
	 *
	 * \note
	 * 这个方法必须在很早的时候调用, 比如在第一个场景创建之前.
	 * 
	 * @param c \link wyScreenConfig wyScreenConfig\endlink
	 * \endif
	 */
	static void setScreenConfig(wyScreenConfig c);

	/**
	 * \if English
	 * Get current screen config
	 * \else
	 * 得到当前的屏幕配置
	 * \endif
	 */
	static wyScreenConfig& getScreenConfig();
#endif // #if MACOSX || WINDOWS
	
	/**
	 * \if English
	 * Print all objects which is not released yet. It it a way to check
	 * possible object leak. For example, call it in a scene onEnter to check
	 * objects of previous scene are leaked or not.
	 * \else
	 * 打印当前还没有被释放的所有对象, 这可以用来检查内存泄露. 一般可以在一个场景的
	 * onEnter方法里调用这个方法查看前一个场景的对象是否都已经被释放
	 * \endif
	 */
	static void printUnreleasedObjects();

	/**
	 * \if English
	 * Print all memory blocks which is not released yet. The memory block
	 * must be allocated by WiEngine custom macro, such as wyMalloc, WYNEW etc.
	 * Otherwise the memory block can not be tracked.
	 *
	 * \note
	 * this method is only available for memory debug version. It just print a
	 * warning in release version
	 *
	 * @param fullLog true means including memory log in WiEngine, or false means just
	 * 		print memory log in app layer. default is false
	 * \else
	 * 打印所有还未分配的内存. 分配内存时必须使用WiEngine定义的宏, 如wyMalloc, WYNEW等.
	 * 否则分配的内存无法被跟踪
	 *
	 * \note
	 * 这个方法仅在内存调试版本中有效, 如果是正式发布的WiEngine版本, 仅打印一条警告
	 *
	 * @param fullLog true表示把WiEngine底层的未释放内存也都打印出来, false表示只打印
	 * 		应用层的未释放内存. 缺省是false
	 * \endif
	 */
	static void printUnreleasedMemory(bool fullLog = false);

	/**
	 * \if English
	 * Print memory usage summary. The memory block
	 * must be allocated by WiEngine custom macro, such as wyMalloc, WYNEW etc.
	 * Otherwise the memory block can not be tracked.
	 *
	 * \note
	 * this method is only available for memory debug version. It just print a
	 * warning in release version
	 * \else
	 * 打印出内存使用情况. 分配内存时必须使用WiEngine定义的宏, 如wyMalloc, WYNEW等.
	 * 否则分配的内存无法被跟踪
	 *
	 * \note
	 * 这个方法仅在内存调试版本中有效, 如果是正式发布的WiEngine版本, 仅打印一条警告
	 * \endif
	 */
	static void printMemoryUsage();

	/**
	 * \if English
	 * destructor
	 * \else
	 * 析构函数
	 * \endif
	 */
	virtual ~wyDirector();

	/**
	 * \if English
	 * set the surface view
	 *
	 * @param glView wyGLSurfaceView object
	 * \else
	 * 设置WYGLSurfaceView对象, 应该由java层调用。如果将WiEngine用于动态壁纸，则
	 * 这个方法不需要被调用。
	 *
	 * @param glView WYGLSurfaceView对象
	 * \endif
	 */
	virtual void attachInView(wyGLSurfaceView glView) = 0;

	/**
	 * \if English
	 * invoked from platform end, to set the context
	 *
	 * @param context platform dependent context object
	 * \else
	 * 设置特定平台的上下文对象
	 *
	 * @param context 特定平台的上下文对象
	 * \endif
	 */
	virtual void attachContext(wyGLContext context) = 0;

	/**
	 * \if English
	 * set the accelerometer level
	 *
	 * @param delay \link wySensorDelay wySensorDelay \endlink
	 * \else
	 * 设置加速器事件的触发速度, 目前有四个级别. 常量定义在wySensorDelay枚举中
	 *
	 * @param delay 触发速度, 可以是DELAY_FASTEST(最快),
	 * 		DELAY_GAME(较快), DELAY_UI(适合UI, 较慢),
	 * 		DELAY_NORMAL(最慢)
	 * \endif
	 */
	virtual void setAccelerometerDelay(wySensorDelay delay) = 0;

#if ANDROID
	/**
	 * \if English
	 * set whether to allow the game runs in background. This only applies on android platform.
	 *
	 * Normally, when the application enters background, the surface will be destroyed, the
	 * director will also be stopped, thus your game can't render anything to the screen,
	 * and the sound is also stopped. So, normally, you don't need it at all.
	 *
	 * The lucky thing is that your game logics is sill running. So, fully up to you. :)
	 *
	 * @param flag true means allow
	 * \else
	 * <p>设置是否允许游戏在后台运行. 缺省情况下, 游戏退到后台后, surface被销毁, 游戏主循环也将停止, 所以
	 * 游戏通常是不会在后台运行的. 不过可以设置这个标志让游戏在后台仍然保持运行, 当然这个运行只是指游戏
	 * 的逻辑继续在运行, 渲染是肯定不会继续的, 声音也不会继续播放. 好吧, 这功能有啥用呢? 如果您的游戏有
	 * 类似于挂机这样的概念, 那也许就用的上了. 不过, 如果在后台游戏还跑着, 那是肯定会加大电量消耗的, 所以
	 * 要慎重.<br></p>
	 *
	 * <p>这个API仅能在Android平台使用, iOS只允许一些特定的任务在后台运行. 使用这个api会使您的应用增加移植
	 * 难度.</p>
	 *
	 * @param flag true表示允许游戏在后台运行
	 * \endif
	 */
	virtual void setAllowBackgroundRunning(bool flag) = 0;

	/**
	 * \if English
	 * get whether to allow game runs in background
	 *
	 * @return true means allowed
	 * \else
	 * 是否允许游戏在后台运行
	 *
	 * @return true表示允许游戏在后台运行
	 * \endif
	 */
	virtual bool isAllowBackgroundRunning() = 0;
#endif // #if ANDROID

	/**
	 * \if English
	 * Invoked when surface is created
	 * \else
	 * Surface被创建时被调用
	 * \endif
	 */
	virtual void onSurfaceCreated();

	/**
	 * \if English
	 * Invoked when surface size is changed
	 *
	 * @param w new width of surface
	 * @param h new height of surface
	 * \else
	 * Surface大小发生变化时被调用
	 *
	 * @param w surface的新宽度
	 * @param h surface的新高度
	 * \endif
	 */
	virtual void onSurfaceChanged(int w, int h);

	/**
	 * \if English
	 * Invoked when surface is destroyed
	 * \else
	 * Surface被销毁时被调用
	 * \endif
	 */
	virtual void onSurfaceDestroyed();

	/**
	 * \if English
	 * set the screen adapting mode
	 *
	 * @param mode \link wyScaleMode wyScaleMode\endlink
	 * \else
	 * 设置屏幕适配模式. 这个方法必须要在surface创建之前调用.
	 *
	 * @param mode 屏幕适配模式
	 * \endif
	 */
	virtual void setScaleMode(wyScaleMode mode);

	/**
	 * \if English
	 * set the base size, this is the size where your games really lives in.
	 * Notice that this function must be called before creating surface.
	 *
	 * For more information about base size mode, read the tutorials
	 * @param w base width pixel
	 * @param h base height pixel
	 * \else
	 * 设置基础大小，仅当屏幕适配模式是基础大小适配模式时有效. 这个方法必须要在surface创建之前调用.
	 *
	 * @param w 游戏画面基础宽度
	 * @param h 游戏画面基础高度
	 * \endif
	 */
	virtual void setBaseSize(int w, int h);

	/**
	 * \if English
	 * Change the base size during game running. If current mode is not base size mode,
	 * this method will switch to it.
	 *
	 * @param w new base width pixel
	 * @param h new base height pixel
	 * \else
	 * 改变基础大小, 如果当前模式不是是基础大小模式, 则该方法会切换至基础大小模式. 这个方法可以让你在
	 * 游戏运行中动态的改变基础大小, 但必须以场景为单位.
	 *
	 * @param w 新的基础宽度像素
	 * @param h 新的基础高度像素
	 * \endif
	 */
	virtual void changeBaseSize(int w, int h);

	/**
	 * \if English
	 * pause the director. Once paused, the frame rendering, event dispatching are all paused.
	 * A common case is to call this function from android acticity's onPause()
	 * \else
	 * 暂停当前场景,返回true为设置成功,如果返回false说明已经是暂停状态，一般在android onPause事件中调用
	 * \endif
	 */
	bool pause();

	/**
	 * \if English
	 * resume the paused director
	 * \else
	 * 恢复当前场景,返回true为设置成功,如果返回false说明已经是恢复状态
	 * \endif
	 */
	bool resume();

	/**
	 * \if English
	 * get the window size
	 *
	 * @return \link wySize wySize\endlink
	 * \else
	 * 获得窗口尺寸\link wySize wySize结构\endlink
	 *
	 * @return \link wySize wySize结构\endlink
	 * \endif
	 */
	wySize getWindowSize();

	/**
	 * \if English
	 * get the window width, in pixels
	 * \else
	 * 获得窗口宽度
	 *
	 * @return 窗口宽度
	 * \endif
	 */
	int getWindowWidth();

	/**
	 * \if English
	 * get the window height
	 * \else
	 * 获得窗口高度
	 *
	 * @return 窗口高度
	 * \endif
	 */
	int getWindowHeight();

	/**
	 * \if English
	 * to add a life cycle listener
	 *
	 * @param l \link wyDirectorLifecycleListener wyDirectorLifecycleListener\endlink
	 * @param data user defined data
	 * \else
	 * 添加一个生命周期监听器
	 *
	 * @param l \link wyDirectorLifecycleListener wyDirectorLifecycleListener\endlink
	 * @param data 附加数据指针
	 * \endif
	 */
	void addLifecycleListener(const wyDirectorLifecycleListener* l, void* data);

	/**
	 * \if English
	 * getter, to get the surface view
	 * \else
	 * 获得WYGLSurfaceView对象
	 *
	 * @return WYGLSurfaceView对象
	 * \endif
	 */
	wyGLSurfaceView getGLView() { return m_glView; }
	
	/**
	 * \if English
	 * to get the context passed by attachContext
	 * \else
	 * 获得context对象
	 *
	 * @return 之前由attachContext传入的context
	 * \endif
	 */
	wyGLContext getContext() { return m_context; }

	/**
	 * \if English
	 * to set whether to display the FPS label
	 *
	 * @param show true means to display
	 * \else
	 * 设置是否显示FPS标签
	 *
	 * @param show true为显示
	 * \endif
	 */
	void setShowFPS(bool show);

	/**
	 * \if English
	 * Set flag indicating fps should be calculated or not, if true, you
	 * can retrieve current frame rate by \c getCurrentFrameRate. However,
	 * enable this feature will introduce a little cpu cost, but may be not
	 * much
	 *
	 * \note
	 * if you call setShowFPS(true), then it implied fps will be calculated
	 * \else
	 * 设置是否打开fps计算功能, 如果为true, 则可以通过\c getCurrentFrameRate获得当前
	 * 帧率. 但是打开这个功能肯定会消耗一些cpu资源, 但是应该不大.
	 *
	 * \note
	 * 如果调用了\c setShowFPS(true), 则fps计算也将打开
	 * \endif
	 */
	void setCalculateFPS(bool flag) { m_calculateFPS = flag; }

	/**
	 * \if English
	 * called to draw the next frame
	 * \else
	 * 该方法负责画下一帧场景
	 * \endif
	 */
	void drawFrame();

	/**
	 * \if English
	 * Set max frame rate
	 *
	 * @param maxFrameRate max frame rate
	 * \else
	 * 设置最大帧率
	 *
	 * @param maxFrameRate 最大帧率
	 * \endif
	 */
	void setMaxFrameRate(int maxFrameRate);

	/**
	 * \if English
	 * to run a scene
	 *
	 * @param scene \link wyScene wyScene \endlink
	 * \else
	 * 运行场景
	 *
	 * @param scene 需要运行的\link wyScene wyScene对象指针\endlink
	 * \endif
	 */
	void runWithScene(wyScene* scene);

	/**
	 * \if English
	 * pop the top from the stack, the next scene in the stack will become the active scene
	 * \else
	 * 弹出栈顶的场景, 切换到当前场景在栈中的上一个场景
	 * \endif
	 */
	void popScene();

	/**
	 * \if English
	 * perform scene transition from the current scene to the next scene in the stack
	 *
	 * @param trans \link wyTransitionScene wyTransitionScene\endlink
	 * \else
	 * 弹出栈顶的场景, 同时附带一个转场效果
	 *
	 * @param trans \link wyTransitionScene wyTransitionScene\endlink
	 * \endif
	 */
	void popSceneWithTransition(wyTransitionScene* trans);

	/**
	 * \if English
	 * push one scene to the stack, the pushed scene will become the active scene
	 *
	 * @param scene \link wyScene wyScene\endlink
	 * \else
	 * 切换场景,该方法会保留当前的场景在栈中,在下一场景按back键回回到当前场景
	 *
	 * @param scene 需要切换的\link wyScene wyScene对象指针\endlink
	 * \endif
	 */
	void pushScene(wyScene* scene);

	/**
	 * \if English
	 * replace the current active scene with the passed scene
	 *
	 * @param scene \link wyScene wyScene\endlink
	 * \else
	 * 切换场景,替换当前的运行场景,该方法不会保留当前的场景在栈中
	 *
	 * @param scene 需要切换的\link wyScene wyScene对象指针\endlink
	 * \endif
	 */
	void replaceScene(wyScene* scene);

	/**
	 * \if Englich
	 * Set checking texture flag so that all textures will be invalidate to make them reload
	 *
	 * @param flag true means all texture should be revalidate
	 * \else
	 * 设置检查贴图标志, 从而所有贴图都会被重新载入
	 *
	 * @param flag true表示所有贴图都会被重新载入
	 * \endif
	 */
	void setNeedCheckTexture(bool flag) { m_needCheckTexture = flag; }

	/**
	 * \if English
	 * to get the previous scene of the current scene
	 * \else
	 * 获得当前场景的上一个场景\link wyScene wyScene对象指针\endlink
	 *
	 * @return 当前场景的上一个场景\link wyScene wyScene对象指针\endlink
	 * \endif
	 */
	wyScene* getPreviousScene();

	/**
	 * \if English
	 * get the current scene
	 * \else
	 * 获得当前场景\link wyScene wyScene对象指针\endlink
	 *
	 * @return 当前场景\link wyScene wyScene对象指针\endlink
	 * \endif
	 */
	wyScene* getRunningScene() { return m_runningScene; }

	/**
	 * \if English
	 * get whether the director is paused
	 *
	 * @return true means paused
	 * \else
	 * 获得当前是否为暂停状态,true为暂停
	 *
	 * @return 当前暂停状态
	 * \endif
	 */
	bool isPaused() { return m_paused; }

	/**
	 * \if English
	 * get if the UI is paused
	 *
	 * @return true means UI is paused
	 * \else
	 * 获得当前是否被UI设置为暂停状态,true为暂停
	 *
	 * @return 当前暂停状态
	 * \endif
	 */
	bool isUIPaused() { return m_UIPaused; }

	/**
	 * \if English
	 * pause UI, once paused, all the running actions will stopped,
	 * but the event dispatching is still alive
	 * \else
	 * 暂停游戏，此方法只负责暂停游戏的调度器调度和动作管理，事件需要游戏实现者自行判断
	 * \endif
	 */
	void pauseUI() { m_UIPaused = true; }

	/**
	 * \if English
	 * resume UI from paused state
	 * \else
	 * 恢复游戏，此方法只负责恢复游戏的调度器调度和动作管理，事件需要游戏实现者自行判断
	 * \endif
	 */
	void resumeUI() { m_UIPaused = false; }

	/**
	 * \if English
	 * Get max frame rate. Zero means no limitation.
	 *
	 * @return max frame rate
	 * \else
	 * 得到允许的最大帧率, 游戏将确保以不超过该帧率的速度运行, 为0表示不限制
	 *
	 * @return 允许的最大帧率
	 * \endif
	 */
	int getMaxFrameRate() { return m_maxFrameRate; }

	/**
	 * \if English
	 * get the projection mode being used
	 * \else
	 * 返回当前的投影方式
	 *
	 * @return 当前的投影方式
	 * \endif
	 */
	wyProjectionType getProjection() { return m_projection; }

	/**
	 * \if English
	 * test whether a specified opengl extension is supported
	 *
	 * @param name name of the extension
	 * \else
	 * 测试是否某个OpenGL扩展被支持
	 *
	 * @param name 扩展名称
	 * \endif
	 */
	bool isExtensionSupported(const char* name);

	/**
	 * \if English
	 * check whether the surface has been created
	 *
	 * @return true means created
	 * \else
	 * 检查surface是否已经创建
	 *
	 * @return true表示surface已经创建，false表示没有或者已经被销毁
	 * \endif
	 */
	bool isSurfaceCreated() { return m_surfaceCreated; }

	/**
	 * \if English
	 * make a screen shot, the picture will be saved as a png file at
	 * the location specified by path.
	 *
	 * \par
	 * Notice:
	 * This function may not work on some devices of low configuration
	 * due to opengl supporting.
	 * With regard to iOS, the path to save the file is relative to
	 * the sand box of your application.
	 *
	 * @param path where to save the png file. The directory will be
	 * created automatically if not exist
	 * \else
	 * 抓取当前帧, 保存为png图片. 这个方法会将图片保存到指定路径，由于牵涉到文件
	 * 写操作, 因此速度较慢, 另外使用的OpenGL接口可能在低版本Android系统上没有
	 * 实现. 如果保存的路径在sd卡上, 则应用需要有写sd卡的权限.
	 *
	 * 在iOS平台上截图时, 传入的路径会被认为是相对于应用沙箱的Documents目录.
	 *
	 * @param path 截图保存的目标路径, 如果指定的路径不存在, 则会自动创建目录. 如果为NULL, 则不做任何事
	 * \endif
	 */
	void makeScreenshot(const char* path);

	/**
	 * \if English
	 * The only thing it is different from makeScreenshot(const char*) is that this function
	 * won't capture the full screen, it just capture the screen specified by rect.
	 *
	 * @param path see makeScreenshot(const char*)
	 * @param rect \link wyRect wyRect\endlink
	 * \else
	 * 抓取当前帧的一部分, 保存为png图片. 这个方法会将图片保存到指定路径，由于牵涉到文件
	 * 写操作, 因此速度较慢, 另外使用的OpenGL接口可能在低版本Android系统上没有
	 * 实现. 如果保存的路径在sd卡上, 则应用需要有写sd卡的权限.
	 *
	 * 在iOS平台上截图时, 传入的路径会被认为是相对于应用沙箱的Documents目录.
	 *
	 * @param path 截图保存的目标路径, 如果指定的路径不存在, 则会自动创建目录. 如果为NULL, 则不做任何事
	 * @param rect 需要截取的屏幕矩形范围
	 * \endif
	 */
	void makeScreenshot(const char* path, wyRect rect);

	/**
	 * \if English
	 * Be equal to calling makeScreenshot(path, node->getBoundingBoxRelativeToWorld)
	 *
	 * @param path see makeScreenshot(const char*)
	 * @param node \link wyNode wyNode\endlink
	 * \else
	 * 单独抓取某个节点范围内的内容, 节点范围会考虑到节点的缩放和旋转, 因此实际上是获得节点的
	 * getBoundingBoxRelativeToWorld的范围进行抓取.
	 *
	 * \note
	 * \c node的状态并不影响截图的结果, 因为只是获取\c node的矩形范围, 其它并无作用, 这个调用
	 * 实际上等同于makeScreenshot(path, node->getBoundingBoxRelativeToWorld())
	 *
	 * @param path 截图保存的目标路径, 如果指定的路径不存在, 则会自动创建目录. 如果为NULL, 则不做任何事
	 * @param node 需要抓取的节点
	 * \endif
	 */
	void makeScreenshot(const char* path, wyNode* node);

	/**
	 * \if English
	 * get the current frame rate
	 *
	 * @return the frame rate, per second
	 * \else
	 * 得到当前的帧率, 这个帧率其实是最近一次计算出的帧率, 因此不能说完全是当前的帧率. 不过基本和当前帧率是一致的.
	 *
	 * @return 最近的帧率
	 * \endif
	 */
	float getCurrentFrameRate() { return m_frameRate; }

	/**
	 * \if English
	 * check whether node has focus state
	 *
	 * @return true means enabled
	 * \else
	 * 检查节点是否具有焦点态
	 *
	 * @return true为可用
	 * \endif
	 */
	bool isFocusEnabled() { return m_focusEnabled; }

	/**
	 * \if English
	 * set whether to enable the node to have focus state, by default the focus state
	 * is disabled. One common case the focus state may be useful is a game operated by
	 * hard d-pad keyboard, where the player can easily know where the focus is now at and
	 * what would happen if he/she push down the OK key.
	 *
	 * @param flag true means to enable
	 * \else
	 * 设置节点是否具有焦点态, true为有, 缺省为false. 如果一个节点具有焦点态, 则其可以在获得输入焦点时
	 * 显示不同的样子. 这比较适合于某些需要通过实体键盘操作的游戏, 这样的话显示焦点态是有意义的. 对于无
	 * 实体键盘的机型, 焦点态的用处不明显, 因此可以根据您的需要设置是否打开这个功能. 如果这个标志是false,
	 * 则wyNode::setFocused方法没有任何效果. 如果是true, 则wyNode::setFocused会修改节点的焦点标志.
	 *
	 * @param flag 设置节点是否具有焦点态, true为可用
	 * \endif
	 */
	void setFocusEnabled(bool flag) { m_focusEnabled = flag; }

	/**
	 * \if English
	 * once the flag is set true, the time elapsed since the last frame will be set to zero.
	 * Normally, you don't need to call this function manually.
	 *
	 * The flag will be reset to false automatically by the engine.
	 *
	 * This just applies a occasion that some certain operations such as resource loading
	 * takes such a long time that the animation may miss its first few frames.
	 *
	 * @param flag
	 * \else
	 * 设置下一个delta时间是否为0. 这个方法会在每个场景载入后自动调用, 因此通常情况下您不需要调用此方法.
	 *
	 * @param flag true表示下一个delta时间设为0, 这主要用来避免因为资源载入导致的游戏体验不连续问题. 例如有一个场景中一开始就要执行动画,
	 * 			但是由于场景载入需要耗费一定时间, 因此可能导致动画的前面几帧被跳过. 那么可以设置这个标志强制使下一个delta时间为0, 这样
	 * 			动画将从第一帧开始.
	 * \endif
	 */
	void setNextDeltaTimeZero(bool flag) { m_nextDeltaTimeZero = flag; }

	/**
	 * \if English
	 * Set frame tick delta scaling factor, this can be used to control game
	 * total behavior. A smaller value than 1 will slow down game
	 * speed, or a larger value than one will speed up.
	 * \else
	 * 设置帧间隔的缩放因子, 这个方法可以用来控制游戏的整体运行速度. 如果该值比1小, 则
	 * 游戏整体上会呈现慢动作的状态, 如果比1大, 则整体呈现快动作. 1表示正常速度.
	 * \endif
	 */
	void setTickFactor(float r) { m_tickFactor = r; }

	/**
	 * \if English
	 * Get frame tick scaling factor
	 * \else
	 * 得到帧间隔缩放因子
	 * \endif
	 */
	float getTickFactor() { return m_tickFactor; }

	/**
	 * \if English
	 * Get render manager
	 * \else
	 * 得到渲染管理器
	 * \endif
	 */
	wyRenderManager* getRenderManager() { return m_renderManager; }
};

#endif // __wyDirector_h__
