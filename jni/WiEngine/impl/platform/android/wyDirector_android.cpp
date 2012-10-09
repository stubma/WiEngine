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
#if ANDROID

#include <jni.h>
#include <pthread.h>
#include <dlfcn.h>
#include <unistd.h>
#include "wyDirector_android.h"
#include "wyThread.h"
#include "wyLog.h"
#include "wyTypes.h"
#include "wyUtils_android.h"
#include "wyInit.h"
#include "wyActionManager.h"
#include "wyJavaResourceDecoder.h"

#ifdef __cplusplus
extern "C" {
#endif

// extern methods
extern void globalInit(JNIEnv* env);
extern void globalDeInit(JNIEnv* env);
extern void wyInitAutoReleasePool();
extern void wyClearAutoReleasePool();
extern void wyDestroyAutoReleasePool();
extern void wyOutputLeakPool();

#ifdef __cplusplus
}
#endif

// mutex
extern pthread_mutex_t gCondMutex;

// other singleton
extern wyActionManager* gActionManager;
extern wyScheduler* gScheduler;
extern wyResourceDecoder* gResDecoder;

/// java virtual machine object
extern JavaVM* gVM;

// external jni definition
extern jclass gClass_Director;
extern jmethodID g_mid_Director_getInstance;
extern jmethodID g_mid_Director_internalEnd;
extern jmethodID g_mid_Director_setAccelerometerDelay;
extern jmethodID g_mid_Context_getResources;
extern jmethodID g_mid_Context_getPackageName;
extern jmethodID g_mid_WYGLSurfaceView_onPause;
extern jmethodID g_mid_WYGLSurfaceView_onResume;
extern jmethodID g_mid_Resources_getDisplayMetrics;
extern jfieldID g_fid_DisplayMetrics_density;
extern jfieldID g_fid_DisplayMetrics_scaledDensity;
extern jfieldID g_fid_DisplayMetrics_widthPixels;
extern jfieldID g_fid_DisplayMetrics_heightPixels;
extern jmethodID g_mid_IDirectorLifecycleListener_onSurfaceCreated;
extern jmethodID g_mid_IDirectorLifecycleListener_onSurfaceChanged;
extern jmethodID g_mid_IDirectorLifecycleListener_onSurfaceDestroyed;
extern jmethodID g_mid_IDirectorLifecycleListener_onDirectorPaused;
extern jmethodID g_mid_IDirectorLifecycleListener_onDirectorResumed;
extern jmethodID g_mid_IDirectorLifecycleListener_onDirectorEnded;
extern jmethodID g_mid_IDirectorLifecycleListener_onDirectorScreenCaptured;
extern jmethodID g_mid_View_getTop;
extern jmethodID g_mid_View_getLeft;
extern jmethodID g_mid_View_getParent;
extern jmethodID g_mid_View_getHeight;

// android adapter layer
static void* sAALHandler;
wyAAL gAAL;

/// singleton director
wyDirector_android* gDirector;

/// condition for background looper
static pthread_cond_t sBackgroundLooperCond;

wyDirector* wyDirector::getInstance() {
	if(gDirector == NULL) {
		/*
		 * because we print memory tracking in director deconstructor,
		 * so director will always be the leaked one. then we don't use
		 * WYNEW to track director
		 */
		gDirector = new wyDirector_android();
	}
	return gDirector;
}

wyDirector_android::wyDirector_android() :
		m_allowBackgroundRunning(false),
		m_backgroundRunning(false),
		m_originalMaxFrameRate(0),
		m_jLifecycleListeners(wyArrayNew(3)) {
}

wyDirector_android::~wyDirector_android() {
	// if background running is enabled
	if(m_allowBackgroundRunning) {
		pthread_mutex_lock(&gCondMutex);
		if(m_backgroundRunning) {
			if(pthread_cond_init(&sBackgroundLooperCond, NULL) == 0) {
				m_backgroundRunning = false;
				pthread_cond_wait(&sBackgroundLooperCond, &gCondMutex);
				pthread_cond_destroy(&sBackgroundLooperCond);
			}
		}
		pthread_mutex_unlock(&gCondMutex);
	}

	// call gl view
	JNIEnv* env = wyUtils::getJNIEnv();
	if(env != NULL) {
		if(m_glView != NULL) {
			if(!m_paused)
				env->CallVoidMethod(m_glView, g_mid_WYGLSurfaceView_onPause);
			env->DeleteGlobalRef(m_glView);
			m_glView = NULL;
		}
	}

	// if resource decoder is set, check whether it is wyJavaResourceDecoder
	if(gResDecoder) {
		wyJavaResourceDecoder* jrd = dynamic_cast<wyJavaResourceDecoder*>(gResDecoder);
		if(jrd)
			delete jrd;
	}

	// common destroy
	commonDestroy();

	// release listener
	wyArrayEach(m_jLifecycleListeners, j_releaseListener, NULL);
	wyArrayDestroy(m_jLifecycleListeners);

	// deinit aal
	if(gAAL.deinit)
		gAAL.deinit();

	// delete context ref
	if(env != NULL) {
		if(m_context != NULL) {
			env->DeleteGlobalRef(m_context);
			m_context = NULL;
		}
	}

	// global deinit
	globalDeInit(env);

	// unload aal lib
	if(sAALHandler != NULL) {
		/*
		 * don't close the library handler because Android may have a bug that may
		 * leak it. That bug will crash engine after loading 45 times, yes exactly
		 * 45 times, at least on some model. Meanwhile Android dlopen doesn't support
		 * RTLD_NODELETE flag, so just not close it
		 */
//		dlclose(sAALHandler);
		sAALHandler = NULL;
	}

	// nullify gVM
	gVM = NULL;

	// free my self
	gDirector = NULL;
}

void wyDirector_android::attachContext(wyGLContext context) {
    if (m_context != context) {
    	// get env
    	JNIEnv* env = wyUtils::getJNIEnv();

        // global init
        globalInit(env);

        // delete old reference
        if(m_context != NULL) {
            env->DeleteGlobalRef(m_context);
            m_context = NULL;
        }

        // save context reference
        if(context != NULL)
        	m_context = env->NewGlobalRef(context);

        // setup sal
        setupAAL();

		// get resources
		jobject res = env->CallObjectMethod(m_context, g_mid_Context_getResources);

		// get display metrics
		jobject dm = env->CallObjectMethod(res, g_mid_Resources_getDisplayMetrics);
		env->DeleteLocalRef(res);

		// set surface size
		wyDevice::realWidth = env->GetIntField(dm, g_fid_DisplayMetrics_widthPixels);
		wyDevice::realHeight = env->GetIntField(dm, g_fid_DisplayMetrics_heightPixels);
		if(SCALE_MODE_BY_DENSITY == wyDevice::scaleMode) {
			wyDevice::winWidth = wyDevice::realWidth;
			wyDevice::winHeight = wyDevice::realHeight;
		}

		// save other parameters
		wyDevice::density = env->GetFloatField(dm, g_fid_DisplayMetrics_density);
		wyDevice::scaledDensity = env->GetFloatField(dm, g_fid_DisplayMetrics_scaledDensity);

		// set density to aal
		if(gAAL.setDensity)
			gAAL.setDensity(wyDevice::density);

		// delete display metrics ref
		env->DeleteLocalRef(dm);
    }
}

void wyDirector_android::attachInView(wyGLSurfaceView glView) {
	if(m_glView != glView) {
		JNIEnv* env = wyUtils::getJNIEnv();

		// delete old reference
		if(m_glView != NULL) {
			env->DeleteGlobalRef(m_glView);
			m_glView = NULL;
		}

		// save gl view reference
		if(glView != NULL)
			m_glView = env->NewGlobalRef(glView);
	}
}

void wyDirector_android::addLifecycleListener(jobject l) {
	if(l != NULL) {
		JNIEnv* env = wyUtils::getJNIEnv();
		jobject listener = env->NewGlobalRef(l);
		wyArrayPush(m_jLifecycleListeners, listener);
	}
}

void wyDirector_android::stopRender() {
	// call gl view
	if(m_glView != NULL) {
		JNIEnv* env = wyUtils::getJNIEnv();
		if(env != NULL)
			env->CallVoidMethod(m_glView, g_mid_WYGLSurfaceView_onPause);
	}
}

void wyDirector_android::startRender() {
	if(m_glView != NULL) {
		JNIEnv* env = wyUtils::getJNIEnv();
		if(env != NULL)
			env->CallVoidMethod(m_glView, g_mid_WYGLSurfaceView_onResume);
	}
}

inline void wyDirector_android::setAllowBackgroundRunning(bool flag) {
	m_allowBackgroundRunning = flag;
}

inline bool wyDirector_android::isAllowBackgroundRunning() {
	return m_allowBackgroundRunning;
}

void wyDirector_android::end() {
	JNIEnv* env = wyUtils::getJNIEnv();
	jobject director = env->CallStaticObjectMethod(gClass_Director, g_mid_Director_getInstance);
	env->CallVoidMethod(director, g_mid_Director_internalEnd);
	env->DeleteLocalRef(director);
}

void wyDirector_android::setAccelerometerDelay(wySensorDelay delay) {
	JNIEnv* env = wyUtils::getJNIEnv();
	jobject director = env->CallStaticObjectMethod(gClass_Director, g_mid_Director_getInstance);
	env->CallVoidMethod(director, g_mid_Director_setAccelerometerDelay, delay);
	env->DeleteLocalRef(director);
}

void wyDirector_android::notifySurfaceCreated() {
	wyDirector::notifySurfaceCreated();
	wyArrayEach(m_jLifecycleListeners, j_notifySurfaceCreated, NULL);
}

void wyDirector_android::notifySurfaceChanged() {
	wyDirector::notifySurfaceChanged();
	wyArrayEach(m_jLifecycleListeners, j_notifySurfaceChanged, NULL);
}

void wyDirector_android::notifySurfaceDestroyed() {
	wyDirector::notifySurfaceDestroyed();
	wyArrayEach(m_jLifecycleListeners, j_notifySurfaceDestroyed, NULL);
}

void wyDirector_android::notifyDirectorPaused() {
	wyDirector::notifyDirectorPaused();
	wyArrayEach(m_jLifecycleListeners, j_notifyDirectorPaused, NULL);
}

void wyDirector_android::notifyDirectorResumed() {
	wyDirector::notifyDirectorResumed();
	wyArrayEach(m_jLifecycleListeners, j_notifyDirectorResumed, NULL);
}

void wyDirector_android::notifyDirectorEnded() {
	wyDirector::notifyDirectorEnded();
	wyArrayEach(m_jLifecycleListeners, j_notifyDirectorEnded, NULL);
}

void wyDirector_android::notifyDirectorScreenCaptured() {
	wyDirector::notifyDirectorScreenCaptured();
	wyArrayEach(m_jLifecycleListeners, j_notifyDirectorScreenCaptured, NULL);
}

void wyDirector_android::setScaleMode(wyScaleMode mode) {
	wyDirector::setScaleMode(mode);

	// need update AAL
	if(gAAL.setScaleMode)
		gAAL.setScaleMode((int)mode);
}

void wyDirector_android::setupAAL() {
	JNIEnv* env = wyUtils::getJNIEnv();
	if(env != NULL) {
		// get package name
		jstring pkg = (jstring)env->CallObjectMethod(m_context, g_mid_Context_getPackageName);

		// build lib path
		const char* cPkg = env->GetStringUTFChars(pkg, NULL);

		// open android adapter layer so
		char buf[128];
		if(wyDevice::apiLevel > 15) {
			sprintf(buf, "/data/data/%s/lib/libaal_jellybean.so", cPkg);
		} else if(wyDevice::apiLevel > 10) {
			sprintf(buf, "/data/data/%s/lib/libaal_honeycomb.so", cPkg);
		} else {
			sprintf(buf, "/data/data/%s/lib/libaal.so", cPkg);
		}
		sAALHandler = dlopen(buf, RTLD_LAZY);

		// release pkg
		env->ReleaseStringUTFChars(pkg, cPkg);

		// if failed to open sal in app data folder, try find them in system lib
		if(!sAALHandler) {
			if(wyDevice::apiLevel > 15) {
				sprintf(buf, "/system/lib/libaal_jellybean.so");
			} else if(wyDevice::apiLevel > 10) {
				sprintf(buf, "/system/lib/libaal_honeycomb.so");
			} else {
				sprintf(buf, "/system/lib/libaal.so");
			}
			sAALHandler = dlopen(buf, RTLD_LAZY);
		}

		// check
	    if (!sAALHandler) {
	    	LOGE("Cannot open android adapter layer");
	    	exit(1);
	    }

	    // find functions
	    gAAL.scaleImage = (scaleImageFunc)dlsym(sAALHandler, "scaleImage");
	    if(gAAL.scaleImage == NULL) {
	    	LOGE("Cannot load symbol 'scaleImage'");
	    	dlclose(sAALHandler);
	    	exit(1);
	    }
	    gAAL.scalePVR = (scalePVRFunc)dlsym(sAALHandler, "scalePVR");
	    if(gAAL.scalePVR == NULL) {
	    	LOGE("Cannot load symbol 'scalePVR'");
	    	dlclose(sAALHandler);
	    	exit(1);
	    }
	    gAAL.calculateTextSizeWithFont = (calculateTextSizeWithFontFunc)dlsym(sAALHandler, "calculateTextSizeWithFont");
	    if(gAAL.calculateTextSizeWithFont == NULL) {
	    	LOGE("Cannot load symbol 'calculateTextSizeWithFont'");
	    	dlclose(sAALHandler);
	    	exit(1);
	    }
	    gAAL.calculateTextSizeWithCustomFont = (calculateTextSizeWithCustomFontFunc)dlsym(sAALHandler, "calculateTextSizeWithCustomFont");
	    if(gAAL.calculateTextSizeWithCustomFont == NULL) {
	    	LOGE("Cannot load symbol 'calculateTextSizeWithCustomFont'");
	    	dlclose(sAALHandler);
	    	exit(1);
	    }
	    gAAL.createLabelBitmapWithFont = (createLabelBitmapWithFontFunc)dlsym(sAALHandler, "createLabelBitmapWithFont");
	    if(gAAL.createLabelBitmapWithFont == NULL) {
	    	LOGE("Cannot load symbol 'createLabelBitmapWithFont'");
	    	dlclose(sAALHandler);
	    	exit(1);
	    }
	    gAAL.createLabelBitmapWithCustomFont = (createLabelBitmapWithCustomFontFunc)dlsym(sAALHandler, "createLabelBitmapWithCustomFont");
	    if(gAAL.createLabelBitmapWithCustomFont == NULL) {
	    	LOGE("Cannot load symbol 'createLabelBitmapWithCustomFont'");
	    	dlclose(sAALHandler);
	    	exit(1);
	    }
	    gAAL.deinit = (deinitFunc)dlsym(sAALHandler, "deinit");
	    if(gAAL.deinit == NULL) {
	    	LOGE("Cannot load symbol 'deinit'");
	    	dlclose(sAALHandler);
	    	exit(1);
	    }
	    gAAL.setEnv = (setEnvFunc)dlsym(sAALHandler, "setEnv");
	    if(gAAL.setEnv == NULL) {
	    	LOGE("Cannot load symbol 'setEnv'");
	    	dlclose(sAALHandler);
	    	exit(1);
	    }
	    gAAL.setContext = (setContextFunc)dlsym(sAALHandler, "setContext");
	    if(gAAL.setContext == NULL) {
	    	LOGE("Cannot load symbol 'setContext'");
	    	dlclose(sAALHandler);
	    	exit(1);
	    }
	    gAAL.setDensity = (setDensityFunc)dlsym(sAALHandler, "setDensity");
	    if(gAAL.setDensity == NULL) {
	    	LOGE("Cannot load symbol 'setDensity'");
	    	dlclose(sAALHandler);
	    	exit(1);
	    }
	    gAAL.setScaleMode = (setScaleModeFunc)dlsym(sAALHandler, "setScaleMode");
	    if(gAAL.setScaleMode == NULL) {
	    	LOGE("Cannot load symbol 'setScaleMode'");
	    	dlclose(sAALHandler);
	    	exit(1);
	    }
	    gAAL.getAsset = (getAssetFunc)dlsym(sAALHandler, "getAsset");
	    if(gAAL.getAsset == NULL) {
	    	LOGE("Cannot load symbol 'getAsset'");
	    	dlclose(sAALHandler);
	    	exit(1);
	    }
	    gAAL.getAssetByResId = (getAssetByResIdFunc)dlsym(sAALHandler, "getAssetByResId");
	    if(gAAL.getAssetByResId == NULL) {
	    	LOGE("Cannot load symbol 'getAssetByResId'");
	    	dlclose(sAALHandler);
	    	exit(1);
	    }
	    gAAL.getAssetBuffer = (getAssetBufferFunc)dlsym(sAALHandler, "getAssetBuffer");
	    if(gAAL.getAssetBuffer == NULL) {
	    	LOGE("Cannot load symbol 'getAssetBuffer'");
	    	dlclose(sAALHandler);
	    	exit(1);
	    }
	    gAAL.getAssetLength = (getAssetLengthFunc)dlsym(sAALHandler, "getAssetLength");
	    if(gAAL.getAssetLength == NULL) {
	    	LOGE("Cannot load symbol 'getAssetLength'");
	    	dlclose(sAALHandler);
	    	exit(1);
	    }
	    gAAL.getAssetRemainingLength = (getAssetRemainingLengthFunc)dlsym(sAALHandler, "getAssetRemainingLength");
	    if(gAAL.getAssetRemainingLength == NULL) {
	    	LOGE("Cannot load symbol 'getAssetRemainingLength'");
	    	dlclose(sAALHandler);
	    	exit(1);
	    }
	    gAAL.readAsset = (readAssetFunc)dlsym(sAALHandler, "readAsset");
	    if(gAAL.readAsset == NULL) {
	    	LOGE("Cannot load symbol 'readAsset'");
	    	dlclose(sAALHandler);
	    	exit(1);
	    }
	    gAAL.seekAsset = (seekAssetFunc)dlsym(sAALHandler, "seekAsset");
	    if(gAAL.seekAsset == NULL) {
	    	LOGE("Cannot load symbol 'seekAsset'");
	    	dlclose(sAALHandler);
	    	exit(1);
	    }
	    gAAL.closeAsset = (closeAssetFunc)dlsym(sAALHandler, "closeAsset");
	    if(gAAL.closeAsset == NULL) {
	    	LOGE("Cannot load symbol 'closeAsset'");
	    	dlclose(sAALHandler);
	    	exit(1);
	    }
	    gAAL.getResFD = (getResFDFunc)dlsym(sAALHandler, "getResFD");
	    if(gAAL.getResFD == NULL) {
	    	LOGE("Cannot load symbol 'getResFD'");
	    	dlclose(sAALHandler);
	    	exit(1);
	    }
	    gAAL.getAssetFD = (getAssetFDFunc)dlsym(sAALHandler, "getAssetFD");
	    if(gAAL.getAssetFD == NULL) {
	    	LOGE("Cannot load symbol 'getAssetFD'");
	    	dlclose(sAALHandler);
	    	exit(1);
	    }
	    gAAL.utf16toutf8 = (utf16toutf8Func)dlsym(sAALHandler, "utf16toutf8");
	    if(gAAL.utf16toutf8 == NULL) {
	    	LOGE("Cannot load symbol 'utf16toutf8'");
	    	dlclose(sAALHandler);
	    	exit(1);
	    }
	    gAAL.toUTF16 = (toUTF16Func)dlsym(sAALHandler, "toUTF16");
	    if(gAAL.toUTF16 == NULL) {
	    	LOGE("Cannot load symbol 'toUTF16'");
	    	dlclose(sAALHandler);
	    	exit(1);
	    }
	    gAAL.wctoutf8 = (wctoutf8Func)dlsym(sAALHandler, "wctoutf8");
	    if(gAAL.wctoutf8 == NULL) {
	    	LOGE("Cannot load symbol 'wctoutf8'");
	    	dlclose(sAALHandler);
	    	exit(1);
	    }

	    // set env to aal
	    if(gAAL.setEnv)
	    	gAAL.setEnv(env);

	    // set context to aal
	    if(gAAL.setContext)
	    	gAAL.setContext(m_context);
	}
}

bool wyDirector_android::j_notifySurfaceCreated(wyArray* arr, void* ptr, int index, void* data) {
	jobject l = (jobject)ptr;
	JNIEnv* env = wyUtils::getJNIEnv();
	if(env != NULL)
		env->CallVoidMethod(l, g_mid_IDirectorLifecycleListener_onSurfaceCreated);
	return true;
}

bool wyDirector_android::j_notifySurfaceChanged(wyArray* arr, void* ptr, int index, void* data) {
	jobject l = (jobject)ptr;
	JNIEnv* env = wyUtils::getJNIEnv();
	if(env != NULL)
		env->CallVoidMethod(l, g_mid_IDirectorLifecycleListener_onSurfaceChanged, wyDevice::winWidth, wyDevice::winHeight);
	return true;
}

bool wyDirector_android::j_notifySurfaceDestroyed(wyArray* arr, void* ptr, int index, void* data) {
	jobject l = (jobject)ptr;
	JNIEnv* env = wyUtils::getJNIEnv();
	if(env != NULL)
		env->CallVoidMethod(l, g_mid_IDirectorLifecycleListener_onSurfaceDestroyed);
	return true;
}

bool wyDirector_android::j_notifyDirectorPaused(wyArray* arr, void* ptr, int index, void* data) {
	jobject l = (jobject)ptr;
	JNIEnv* env = wyUtils::getJNIEnv();
	if(env != NULL)
		env->CallVoidMethod(l, g_mid_IDirectorLifecycleListener_onDirectorPaused);
	return true;
}

bool wyDirector_android::j_notifyDirectorResumed(wyArray* arr, void* ptr, int index, void* data) {
	jobject l = (jobject)ptr;
	JNIEnv* env = wyUtils::getJNIEnv();
	if(env != NULL)
		env->CallVoidMethod(l, g_mid_IDirectorLifecycleListener_onDirectorResumed);
	return true;
}

bool wyDirector_android::j_notifyDirectorEnded(wyArray* arr, void* ptr, int index, void* data) {
	jobject l = (jobject)ptr;
	JNIEnv* env = wyUtils::getJNIEnv();
	if(env != NULL)
		env->CallVoidMethod(l, g_mid_IDirectorLifecycleListener_onDirectorEnded);
	return true;
}

bool wyDirector_android::j_notifyDirectorScreenCaptured(wyArray* arr, void* ptr, int index, void* data) {
	jobject l = (jobject)ptr;
	JNIEnv* env = wyUtils::getJNIEnv();
	if(env != NULL) {
		jstring path = env->NewStringUTF(gDirector->m_screenshotPath);
		env->CallVoidMethod(l, g_mid_IDirectorLifecycleListener_onDirectorScreenCaptured, path);
		env->DeleteLocalRef(path);
	}
	return true;
}

bool wyDirector_android::j_releaseListener(wyArray* arr, void* ptr, int index, void* data) {
	jobject l = (jobject)ptr;
	JNIEnv* env = wyUtils::getJNIEnv();
	if(env != NULL)
		env->DeleteGlobalRef(l);
	return true;
}

void wyDirector_android::backgroundLooper(wyTargetSelector* sel) {
	while(gDirector->m_backgroundRunning) {
		// process auto release pool
		wyClearAutoReleasePool();

		// check frame rate setting, but neglect it if in screenshot mode
#ifndef WY_CFLAG_SCREENSHOT_MODE
		if(gDirector->m_maxFrameRate > 0) {
			int64_t now = wyUtils::currentTimeMillis();
			gDirector->m_savedDelta += now - gDirector->m_lastFrameTime;
			gDirector->m_lastFrameTime = now;
			if(gDirector->m_savedDelta < gDirector->m_minFrameInterval) {
				// sleep to save power
				usleep((gDirector->m_minFrameInterval - gDirector->m_savedDelta) * 1000);

				// recalculate saved delta
				now = wyUtils::currentTimeMillis();
				gDirector->m_savedDelta += now - gDirector->m_lastFrameTime;
				gDirector->m_lastFrameTime = now;
				gDirector->m_savedDelta %= gDirector->m_minFrameInterval;
			} else {
				gDirector->m_savedDelta %= gDirector->m_minFrameInterval;
			}
		}
#endif

		// calculate global delta
		gDirector->calculateDeltaTime();

		// update scheduler
		gScheduler->tickLocked(gDirector->m_delta);

		// update actions
		gActionManager->tick(gDirector->m_delta);
	}

	// notify anybody wait on m_backgroundRunning flag
	pthread_mutex_lock(&gCondMutex);
	gDirector->setMaxFrameRate(gDirector->m_originalMaxFrameRate);
	gDirector->setNextDeltaTimeZero(true);
	pthread_cond_signal(&sBackgroundLooperCond);
	pthread_mutex_unlock(&gCondMutex);
}

void wyDirector_android::onSurfaceCreated() {
	wyDirector::onSurfaceCreated();

	// if background running is enabled, stop it
	if(m_allowBackgroundRunning) {
		pthread_mutex_lock(&gCondMutex);
		if(m_backgroundRunning) {
			if(pthread_cond_init(&sBackgroundLooperCond, NULL) == 0) {
				m_backgroundRunning = false;
				pthread_cond_wait(&sBackgroundLooperCond, &gCondMutex);
				pthread_cond_destroy(&sBackgroundLooperCond);
			}
		}
		pthread_mutex_unlock(&gCondMutex);
	}
}

void wyDirector_android::onSurfaceDestroyed() {
	if(m_surfaceCreated) {
		wyDirector::onSurfaceDestroyed();

		// if allow background running and has scene
		if(m_allowBackgroundRunning && m_scenesStack->num > 0) {
			pthread_mutex_lock(&gCondMutex);
			m_backgroundRunning = true;
			pthread_mutex_unlock(&gCondMutex);

			// ensure next delta is zero
			setNextDeltaTimeZero(true);

			// change max frame rate
			m_originalMaxFrameRate = m_maxFrameRate;
			setMaxFrameRate(60);

			// create wyThread
			wyThread::runThread(wyTargetSelector::make(this, SEL(wyDirector_android::backgroundLooper)));
		}
	}
}

#endif // #if ANDROID
