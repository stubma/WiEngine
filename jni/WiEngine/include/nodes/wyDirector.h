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
 * definitions of projection modes
 */
typedef enum {
	/**
	 * Orthographic projection
	 */
	PROJECTION_2D = 1,

	/**
	 * Perspetive projection
	 */
	PROJECTION_3D,

	/**
	 * user-customized projection
	 */
	PROJECTION_CUSTOM
} wyProjectionType;

/// default projection is 3D
#define PROJECTION_DEFAULT PROJECTION_3D

/**
 * @typedef wySensorDelay
 * definitions of accelerometer level, different level stands for different frequency
 * the engine will use to listen the sensor event
 */
typedef enum {
	/**
	 * get one event every 38 milliseconds
	 */
	DELAY_FASTEST,

	/**
	 * get one event every 62 milliseconds
	 */
	DELAY_GAME,

	/**
	 * get one event every 104 milliseconds
	 */
	DELAY_UI,

	/**
	 * get one event every 254 milliseconds
	 */
	DELAY_NORMAL
} wySensorDelay;

#if MACOSX || WINDOWS

/**
 * @struct wyScreenConfig
 * 
 * In Mac OS X or Windows platform, you can designate screen info by pass
 * a screen config to director. But you must do it before first scene is created.
 * So, you can facilitate screen adaptation thru this handy feature: you don't
 * need to buy many hardware, just simulate it in PC!
 */
typedef struct wyScreenConfig {
	/**
	 * Density of current screen
	 */
	float density;
	
	/**
	 * Font ensity of current screen
	 */
	float scaledDensity;
	
	/**
	 * Surface width you expected
	 */
	int winWidth;
	
	/**
	 * \par
	 * Expected surface height
	 */
	int winHeight;
} wyScreenConfig;

#endif // #if MACOSX || WINDOWS

/**
 * @struct wyDirectorLifecycleListener
 *
 * Lifecycle event interface. You can install lifecycle listener thru \c addLifecycleListener method
 */
typedef struct wyDirectorLifecycleListener {
	/**
	 * Invoked when surface created.
	 *
	 * @param data extra data pointer
	 */
	void (*onSurfaceCreated)(void* data);

	/**
	 * Invoked when surface changed. Generally there is always a change event immediately after
	 * surface created. After this, game loop will be started.
	 *
	 * @param w new width of surface
	 * @param h new height of surface
	 * @param data extra data pointer
	 */
	void (*onSurfaceChanged)(int w, int h, void* data);

	/**
	 * Invoked when surface destroyed, usually it is happened when game exited or
	 * switching to other activity
	 *
	 * @param data extra data pointer
	 */
	void (*onSurfaceDestroyed)(void* data);

	/**
	 * Invoked when \c pause method is called. \c pause method must be called in
	 * activity onPause
	 *
	 * @param data extra data pointer
	 */
	void (*onDirectorPaused)(void* data);

	/**
	 * Invoked when \c resume method is called. \c resume method must be called in
	 * activity onResume
	 *
	 * @param data extra data pointer
	 */
	void (*onDirectorResumed)(void* data);

	/**
	 * Invoked when \c end method is called. \c end method must be called when game exited so
	 * this event means game ended
	 *
	 * @param data extra data pointer
	 */
	void (*onDirectorEnded)(void* data);

	/**
	 * Invoked when a screenshot is captured.
	 *
	 * @param path path of screenshot file, maybe png or jpg and it is decided based on extension
	 * 		of file path when calling \c makeScreenshot method
	 * @param data extra data pointer
	 */
	void (*onDirectorScreenCaptured)(const char* path, void* data);
} wyDirectorLifecycleListener;

/**
 * @class wyDirector
 *
 * wyDirector is a singleton class which manages game flow, as well as providing
 * global API for upper layer
 */
class WIENGINE_API wyDirector : public wyObject {
protected:
	/// render manager
	wyRenderManager* m_renderManager;

	/// main viewport
	wyViewport* m_mainViewport;

	/**
	 * projection mode, by default it is PROJECTION_3D
	 */
	wyProjectionType m_projection;

	/**
	 * interval between two consecutive frames, used to calculate frame rate
	 */
	float m_delta;

	/**
	 * time elapsed since the last frame rate calculation
	 */
	float m_frameDelta;

	/**
	 * used to manually control tick interval, that will slow down or speed
	 * up game total behavior. zero means using real delta.
	 */
	float m_tickFactor;

	/**
	 * frame rate, times per second
	 */
	float m_frameRate;

	/**
	 * frame count passed since the last frame rate calculation
	 */
	int m_frames;

	/**
	 * time point the last frame was updated
	 */
	int64_t m_lastUpdateTime;

	/**
	 * to mark whether it is needed to reload the underlying texture objects
	 */
	bool m_needCheckTexture;

	/**
	 * to mark paused state
	 */
	bool m_paused;

	/**
	 * to mark whether the UI is paused, a common case is that the player clicks the pause button
	 */
	bool m_UIPaused;

	/**
	 * to mark whether the focus state is enabled, true means enabled
	 */
	bool m_focusEnabled;

	/**
	 * to specify whether to display FPS label on the left bottom corner of the screen
	 */
	bool m_displayFPS;

	/**
	 * true means fps should be calculated even you don't want to display it
	 */
	bool m_calculateFPS;

	/**
	 * to mark whether the surface view has been created
	 */
	bool m_surfaceCreated;

	/**
	 * to mark whether it is needed to take a screen shot
	 */
	bool m_makeScreenshot;

	/**
	 * the path to save the screen shot picture
	 */
	const char* m_screenshotPath;

	/**
	 * rectangle of screen shot
	 */
	wyRect m_screenshotRect;

	/**
	 * to guarantee the animation starts from its first frame
	 */
	bool m_nextDeltaTimeZero;

	/**
	 * the maximum frame rate limit, 0 means no limit is set
	 */
	int m_maxFrameRate;

	/**
	 * the time cost by the last frame, in milliseconds
	 */
	int64_t m_lastFrameTime;

	/**
	 * used in condition that the max frame rate is set
	 */
	int64_t m_minFrameInterval;

	/**
	 * used in condition that the max frame rate is set
	 */
	int64_t m_savedDelta;

	/**
	 * the next scene to be activated, \link wyScene wyScene\endlink
	 */
	wyScene* m_nextScene;

	/**
	 * the scene being running, \link wyScene wyScene\endlink
	 */
	wyScene* m_runningScene;

	/**
	 * the label to display FPS, \link wyLabel wyLabel\endlink
	 */
	wyLabel* m_fpsLabel;

	/**
	 * acts as a stack to push or pop scenes to, \link wyArray wyArray\endlink
	 */
	wyArray* m_scenesStack;

	/// array to store life cycle listeners
	vector<wyDirectorLifecycleListener*>* m_lifecycleListeners;

	/**
	 * user data used in the life cycle listener
	 */
	void* m_lifecycleData;
	
	/**
	 * \link wyGLSurfaceView wyGLSurfaceView\endlink
	 */
	wyGLSurfaceView m_glView;

	/**
	 * \link wyGLContext wyGLContext\endlink
	 */
	wyGLContext m_context;

protected:
    /**
     * constructor
	 */
	wyDirector();

	/**
	 * calculate the time interval between 2 consecutive frames
	 */
	void calculateDeltaTime();

	/**
	 * draw the FPS label
	 */
	void showFPS();

	/**
	 * Calculate FPS, can be enabled by \c setCalculateFPS
	 */
	void calculateFPS();

	/**
	 * to set the running scene
	 *
	 * @param scene \link wyScene wyScene\endlink
	 */
	void setRunningScene(wyScene* scene);

	/**
	 * to set the next scene
	 *
	 * @param scene \link wyScene wyScene\endlink
	 */
	void setNextScene(wyScene* scene);

	/**
	 * goto the next scene
	 */
	void gotoNextScene();

	/**
	 * Destroy common members which shared by all platforms
	 */
	void commonDestroy();

	/**
	 * Stop render when game paused
	 */
	virtual void stopRender() = 0;

	/**
	 * Start render when game resumed
	 */
	virtual void startRender() = 0;

	/**
	 * End director, so end game and everything
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
	
public:
	/**
	 * get the singleton instance
	 *
	 * @return singleton of director
	 */
	static wyDirector* getInstance();
	
	/**
	 * Get the singleton instance, but don't create it if not exist
	 * 
	 * @return singleton of director, or NULL if not created yet
	 */
	static wyDirector* getInstanceNoCreate();

	/**
	 * check whether the director is performing ending phase.
	 *
	 * @return true means the director is ending now, it is strong suggested that
	 * no engine-related operations be made during this phase.
	 */
	static bool isEnding();

	/**
	 * Set a resource decoder used to decode obfuscated resource file. Director won't
	 * take care decoder lifecycle, you must release it if needed
	 *
	 * @param decoder \link wyResourceDecoder wyResourceDecoder\endlink implementation, NULL
	 * 		will disable resource decoding
	 */
	static void setResourceDecoder(wyResourceDecoder* decoder);

#if MACOSX || WINDOWS
	/**
	 * Set a custom screen config, it is a handy way to test against different screens
	 * without buying hardware device.
	 *
	 * \note
	 * This method must be called very early, such as before first scene is created
	 * 
	 * @param c \link wyScreenConfig wyScreenConfig\endlink
	 */
	static void setScreenConfig(wyScreenConfig c);

	/**
	 * Get current screen config
	 */
	static wyScreenConfig& getScreenConfig();
#endif // #if MACOSX || WINDOWS
	
	/**
	 * Print all objects which is not released yet. It it a way to check
	 * possible object leak. For example, call it in a scene onEnter to check
	 * objects of previous scene are leaked or not.
	 */
	static void printUnreleasedObjects();

	/**
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
	 */
	static void printUnreleasedMemory(bool fullLog = false);

	/**
	 * Print memory usage summary. The memory block
	 * must be allocated by WiEngine custom macro, such as wyMalloc, WYNEW etc.
	 * Otherwise the memory block can not be tracked.
	 *
	 * \note
	 * this method is only available for memory debug version. It just print a
	 * warning in release version
	 */
	static void printMemoryUsage();

	/**
	 * destructor
	 */
	virtual ~wyDirector();

	/**
	 * set the surface view
	 *
	 * @param glView wyGLSurfaceView object
	 */
	virtual void attachInView(wyGLSurfaceView glView) = 0;

	/**
	 * invoked from platform end, to set the context
	 *
	 * @param context platform dependent context object
	 */
	virtual void attachContext(wyGLContext context) = 0;

	/**
	 * set the accelerometer level
	 *
	 * @param delay \link wySensorDelay wySensorDelay \endlink
	 */
	virtual void setAccelerometerDelay(wySensorDelay delay) = 0;

#if ANDROID
	/**
	 * set whether to allow the game runs in background. This only applies on android platform.
	 *
	 * Normally, when the application enters background, the surface will be destroyed, the
	 * director will also be stopped, thus your game can't render anything to the screen,
	 * and the sound is also stopped. So, normally, you don't need it at all.
	 *
	 * The lucky thing is that your game logics is sill running. So, fully up to you. :)
	 *
	 * @param flag true means allow
	 */
	virtual void setAllowBackgroundRunning(bool flag) = 0;

	/**
	 * get whether to allow game runs in background
	 *
	 * @return true means allowed
	 */
	virtual bool isAllowBackgroundRunning() = 0;
#endif // #if ANDROID

	/**
	 * Invoked when surface is created
	 */
	virtual void onSurfaceCreated();

	/**
	 * Invoked when surface size is changed
	 *
	 * @param w new width of surface
	 * @param h new height of surface
	 */
	virtual void onSurfaceChanged(int w, int h);

	/**
	 * Invoked when surface is destroyed
	 */
	virtual void onSurfaceDestroyed();

	/**
	 * set the screen adapting mode
	 *
	 * @param mode \link wyScaleMode wyScaleMode\endlink
	 */
	virtual void setScaleMode(wyScaleMode mode);

	/**
	 * set the base size, this is the size where your games really lives in.
	 * Notice that this function must be called before creating surface.
	 *
	 * For more information about base size mode, read the tutorials
	 * @param w base width pixel
	 * @param h base height pixel
	 */
	virtual void setBaseSize(int w, int h);

	/**
	 * Change the base size during game running. If current mode is not base size mode,
	 * this method will switch to it.
	 *
	 * @param w new base width pixel
	 * @param h new base height pixel
	 */
	virtual void changeBaseSize(int w, int h);

	/**
	 * pause the director. Once paused, the frame rendering, event dispatching are all paused.
	 * A common case is to call this function from android acticity's onPause()
	 */
	bool pause();

	/**
	 * resume the paused director
	 */
	bool resume();

	/**
	 * get the window size
	 *
	 * @return \link wySize wySize\endlink
	 */
	wySize getWindowSize();

	/**
	 * get the window width, in pixels
	 */
	int getWindowWidth();

	/**
	 * get the window height
	 */
	int getWindowHeight();

	/**
	 * to add a life cycle listener
	 *
	 * @param l \link wyDirectorLifecycleListener wyDirectorLifecycleListener\endlink
	 * @param data user defined data
	 */
	void addLifecycleListener(wyDirectorLifecycleListener* l, void* data);

	/**
	 * getter, to get the surface view
	 */
	wyGLSurfaceView getGLView() { return m_glView; }
	
	/**
	 * to get the context passed by attachContext
	 */
	wyGLContext getContext() { return m_context; }

	/**
	 * to set whether to display the FPS label
	 *
	 * @param show true means to display
	 */
	void setShowFPS(bool show);

	/**
	 * Set flag indicating fps should be calculated or not, if true, you
	 * can retrieve current frame rate by \c getCurrentFrameRate. However,
	 * enable this feature will introduce a little cpu cost, but may be not
	 * much
	 *
	 * \note
	 * if you call setShowFPS(true), then it implied fps will be calculated
	 */
	void setCalculateFPS(bool flag) { m_calculateFPS = flag; }

	/**
	 * called to draw the next frame
	 */
	void drawFrame();

	/**
	 * Set max frame rate
	 *
	 * @param maxFrameRate max frame rate
	 */
	void setMaxFrameRate(int maxFrameRate);

	/**
	 * to run a scene
	 *
	 * @param scene \link wyScene wyScene \endlink
	 */
	void runWithScene(wyScene* scene);

	/**
	 * pop the top from the stack, the next scene in the stack will become the active scene
	 */
	void popScene();

	/**
	 * perform scene transition from the current scene to the next scene in the stack
	 *
	 * @param trans \link wyTransitionScene wyTransitionScene\endlink
	 */
	void popSceneWithTransition(wyTransitionScene* trans);

	/**
	 * push one scene to the stack, the pushed scene will become the active scene
	 *
	 * @param scene \link wyScene wyScene\endlink
	 */
	void pushScene(wyScene* scene);

	/**
	 * replace the current active scene with the passed scene
	 *
	 * @param scene \link wyScene wyScene\endlink
	 */
	void replaceScene(wyScene* scene);

	/**
	 * \if Englich
	 * Set checking texture flag so that all textures will be invalidate to make them reload
	 *
	 * @param flag true means all texture should be revalidate
	 */
	void setNeedCheckTexture(bool flag) { m_needCheckTexture = flag; }

	/**
	 * to get the previous scene of the current scene
	 */
	wyScene* getPreviousScene();

	/**
	 * get the current scene
	 */
	wyScene* getRunningScene() { return m_runningScene; }

	/**
	 * get whether the director is paused
	 *
	 * @return true means paused
	 */
	bool isPaused() { return m_paused; }

	/**
	 * get if the UI is paused
	 *
	 * @return true means UI is paused
	 */
	bool isUIPaused() { return m_UIPaused; }

	/**
	 * pause UI, once paused, all the running actions will stopped,
	 * but the event dispatching is still alive
	 */
	void pauseUI() { m_UIPaused = true; }

	/**
	 * resume UI from paused state
	 */
	void resumeUI() { m_UIPaused = false; }

	/**
	 * Get max frame rate. Zero means no limitation.
	 *
	 * @return max frame rate
	 */
	int getMaxFrameRate() { return m_maxFrameRate; }

	/**
	 * get the projection mode being used
	 */
	wyProjectionType getProjection() { return m_projection; }

	/**
	 * test whether a specified opengl extension is supported
	 *
	 * @param name name of the extension
	 */
	bool isExtensionSupported(const char* name);

	/**
	 * check whether the surface has been created
	 *
	 * @return true means created
	 */
	bool isSurfaceCreated() { return m_surfaceCreated; }

	/**
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
	 */
	void makeScreenshot(const char* path);

	/**
	 * The only thing it is different from makeScreenshot(const char*) is that this function
	 * won't capture the full screen, it just capture the screen specified by rect.
	 *
	 * @param path see makeScreenshot(const char*)
	 * @param rect \link wyRect wyRect\endlink
	 */
	void makeScreenshot(const char* path, wyRect rect);

	/**
	 * Be equal to calling makeScreenshot(path, node->getBoundingBoxRelativeToWorld)
	 *
	 * @param path see makeScreenshot(const char*)
	 * @param node \link wyNode wyNode\endlink
	 */
	void makeScreenshot(const char* path, wyNode* node);

	/**
	 * get the current frame rate
	 *
	 * @return the frame rate, per second
	 */
	float getCurrentFrameRate() { return m_frameRate; }

	/**
	 * check whether node has focus state
	 *
	 * @return true means enabled
	 */
	bool isFocusEnabled() { return m_focusEnabled; }

	/**
	 * set whether to enable the node to have focus state, by default the focus state
	 * is disabled. One common case the focus state may be useful is a game operated by
	 * hard d-pad keyboard, where the player can easily know where the focus is now at and
	 * what would happen if he/she push down the OK key.
	 *
	 * @param flag true means to enable
	 */
	void setFocusEnabled(bool flag) { m_focusEnabled = flag; }

	/**
	 * once the flag is set true, the time elapsed since the last frame will be set to zero.
	 * Normally, you don't need to call this function manually.
	 *
	 * The flag will be reset to false automatically by the engine.
	 *
	 * This just applies a occasion that some certain operations such as resource loading
	 * takes such a long time that the animation may miss its first few frames.
	 *
	 * @param flag
	 */
	void setNextDeltaTimeZero(bool flag) { m_nextDeltaTimeZero = flag; }

	/**
	 * Set frame tick delta scaling factor, this can be used to control game
	 * total behavior. A smaller value than 1 will slow down game
	 * speed, or a larger value than one will speed up.
	 */
	void setTickFactor(float r) { m_tickFactor = r; }

	/**
	 * Get frame tick scaling factor
	 */
	float getTickFactor() { return m_tickFactor; }

	/**
	 * Get render manager
	 */
	wyRenderManager* getRenderManager() { return m_renderManager; }
};

#endif // __wyDirector_h__
