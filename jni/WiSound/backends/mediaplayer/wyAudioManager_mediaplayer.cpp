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


#if BACKEND_MEDIAPLAYER

#include <jni.h>
#include "wyAudioManager_mediaplayer.h"
#include "wyLog.h"
#include "wyTypes.h"
#include "wyUtils.h"
#include "wyJNI.h"

// singleton
wyAudioManager_mediaplayer* gAudioManager = NULL;

// audio effect hash
typedef struct wyEffectHash {
	int hash;
	int stream;
} wyEffectHash;

extern jclass gClass_AudioManager;
static jmethodID jmethodID_AudioManager_setupMediaPlayerBackend;
static jmethodID jmethodID_AudioManager_destroyMediaPlayerBackend;
static jmethodID jmethodID_AudioManager_mpPreloadBackgroundMusic_resId;
static jmethodID jmethodID_AudioManager_mpPreloadBackgroundMusic_path;
static jmethodID jmethodID_AudioManager_mpPlayBackgroundMusic_resId;
static jmethodID jmethodID_AudioManager_mpPlayBackgroundMusic_path;
static jmethodID jmethodID_AudioManager_mpSetBackgroundVolume;
static jmethodID jmethodID_AudioManager_mpSetEffectVolume;
static jmethodID jmethodID_AudioManager_mpStopBackgroundMusic;
static jmethodID jmethodID_AudioManager_mpPauseBackgroundMusic;
static jmethodID jmethodID_AudioManager_mpResumeBackgroundMusic;
static jmethodID jmethodID_AudioManager_mpIsBackgroundPlaying;
static jmethodID jmethodID_AudioManager_mpPreloadEffect_resId;
static jmethodID jmethodID_AudioManager_mpPreloadEffect_path;
static jmethodID jmethodID_AudioManager_mpPlayEffect_resId;
static jmethodID jmethodID_AudioManager_mpPlayEffect_path;
static jmethodID jmethodID_AudioManager_mpStopEffect_resId;
static jmethodID jmethodID_AudioManager_mpStopEffect_path;
static jmethodID jmethodID_AudioManager_mpRemoveAllEffects;
static jmethodID jmethodID_AudioManager_mpRemoveEffect_resId;
static jmethodID jmethodID_AudioManager_mpRemoveEffect_path;
static jmethodID jmethodID_AudioManager_mpSetMute;
static jmethodID jmethodID_AudioManager_mpIsMute;

wyAudioManager_mediaplayer::wyAudioManager_mediaplayer() :
		m_preloadedEffects(wyHashSetNew(20, effectHashEquals, buildEffectHash)),
		m_backgroundMusicPaused(false) {
	JNIEnv* env = getEnv();
	jmethodID_AudioManager_setupMediaPlayerBackend = env->GetStaticMethodID(gClass_AudioManager, "setupMediaPlayerBackend", "()V");
	jmethodID_AudioManager_destroyMediaPlayerBackend = env->GetStaticMethodID(gClass_AudioManager, "destroyMediaPlayerBackend", "()V");
	jmethodID_AudioManager_mpPreloadBackgroundMusic_resId = env->GetStaticMethodID(gClass_AudioManager, "mpPreloadBackgroundMusic", "(I)V");
	jmethodID_AudioManager_mpPreloadBackgroundMusic_path = env->GetStaticMethodID(gClass_AudioManager, "mpPreloadBackgroundMusic", "(Ljava/lang/String;Z)V");
	jmethodID_AudioManager_mpPlayBackgroundMusic_resId = env->GetStaticMethodID(gClass_AudioManager, "mpPlayBackgroundMusic", "(III)V");
	jmethodID_AudioManager_mpPlayBackgroundMusic_path = env->GetStaticMethodID(gClass_AudioManager, "mpPlayBackgroundMusic", "(Ljava/lang/String;ZI)V");
	jmethodID_AudioManager_mpSetBackgroundVolume = env->GetStaticMethodID(gClass_AudioManager, "mpSetBackgroundVolume", "(F)V");
	jmethodID_AudioManager_mpSetEffectVolume = env->GetStaticMethodID(gClass_AudioManager, "mpSetEffectVolume", "(F)V");
	jmethodID_AudioManager_mpStopBackgroundMusic = env->GetStaticMethodID(gClass_AudioManager, "mpStopBackgroundMusic", "()V");
	jmethodID_AudioManager_mpPauseBackgroundMusic = env->GetStaticMethodID(gClass_AudioManager, "mpPauseBackgroundMusic", "()V");
	jmethodID_AudioManager_mpResumeBackgroundMusic = env->GetStaticMethodID(gClass_AudioManager, "mpResumeBackgroundMusic", "()V");
	jmethodID_AudioManager_mpIsBackgroundPlaying = env->GetStaticMethodID(gClass_AudioManager, "mpIsBackgroundPlaying", "()Z");
	jmethodID_AudioManager_mpPreloadEffect_resId = env->GetStaticMethodID(gClass_AudioManager, "mpPreloadEffect", "(I)V");
	jmethodID_AudioManager_mpPreloadEffect_path = env->GetStaticMethodID(gClass_AudioManager, "mpPreloadEffect", "(Ljava/lang/String;Z)V");
	jmethodID_AudioManager_mpPlayEffect_resId = env->GetStaticMethodID(gClass_AudioManager, "mpPlayEffect", "(I)V");
	jmethodID_AudioManager_mpPlayEffect_path = env->GetStaticMethodID(gClass_AudioManager, "mpPlayEffect", "(Ljava/lang/String;Z)V");
	jmethodID_AudioManager_mpStopEffect_resId = env->GetStaticMethodID(gClass_AudioManager, "mpStopEffect", "(I)V");
	jmethodID_AudioManager_mpStopEffect_path = env->GetStaticMethodID(gClass_AudioManager, "mpStopEffect", "(Ljava/lang/String;)V");
	jmethodID_AudioManager_mpRemoveAllEffects = env->GetStaticMethodID(gClass_AudioManager, "mpRemoveAllEffects", "()V");
	jmethodID_AudioManager_mpRemoveEffect_resId = env->GetStaticMethodID(gClass_AudioManager, "mpRemoveEffect", "(I)V");
	jmethodID_AudioManager_mpRemoveEffect_path = env->GetStaticMethodID(gClass_AudioManager, "mpRemoveEffect", "(Ljava/lang/String;)V");
	jmethodID_AudioManager_mpSetMute = env->GetStaticMethodID(gClass_AudioManager, "mpSetMute", "(Z)V");
	jmethodID_AudioManager_mpIsMute = env->GetStaticMethodID(gClass_AudioManager, "mpIsMute", "()Z");

	env->CallStaticVoidMethod(gClass_AudioManager, jmethodID_AudioManager_setupMediaPlayerBackend);
}

wyAudioManager_mediaplayer::~wyAudioManager_mediaplayer() {
	wyHashSetFilter(m_preloadedEffects, releaseHash, NULL);
	wyHashSetDestroy(m_preloadedEffects);

	JNIEnv* env = getEnv();
	if(gClass_AudioManager) {
		env->CallStaticVoidMethod(gClass_AudioManager, jmethodID_AudioManager_destroyMediaPlayerBackend);
	}
}

wyAudioManager* wyAudioManager::getInstance() {
	if (gAudioManager == NULL) {
		gAudioManager = WYNEW wyAudioManager_mediaplayer();
	}

	return gAudioManager;
}

wyAudioManager* wyAudioManager::getInstanceNoCreate() {
	return gAudioManager;
}

void wyAudioManager::releaseInstance() {
	if(gAudioManager) {
		gAudioManager->release();
		gAudioManager = NULL;
	}
}

int wyAudioManager_mediaplayer::effectHashEquals(void* ptr, void* elt) {
	int hash = (int)ptr;
	wyEffectHash* h = (wyEffectHash*)elt;
	return h->hash == hash;
}

void* wyAudioManager_mediaplayer::buildEffectHash(void* ptr, void* data) {
	return ptr;
}

bool wyAudioManager_mediaplayer::releaseHash(void* elt, void* data) {
	// release actions
	wyFree(elt);
	return false;
}

bool wyAudioManager_mediaplayer::hasPreloadedEffect(int resId) {
	return wyHashSetFind(m_preloadedEffects, resId, (void*)resId) != NULL;
}

bool wyAudioManager_mediaplayer::hasPreloadedEffect(const char* path) {
	int hash = wyUtils::strHash(path);
	return wyHashSetFind(m_preloadedEffects, hash, (void*)hash) != NULL;
}

int wyAudioManager_mediaplayer::getEffectStreamId(int resId) {
	wyEffectHash* h = (wyEffectHash*)wyHashSetFind(m_preloadedEffects, resId, (void*)resId);
	return h == NULL ? -1 : h->stream;
}

int wyAudioManager_mediaplayer::getEffectStreamId(const char* path) {
	int hash = wyUtils::strHash(path);
	wyEffectHash* h = (wyEffectHash*)wyHashSetFind(m_preloadedEffects, hash, (void*)hash);
	return h == NULL ? -1 : h->stream;
}

void wyAudioManager_mediaplayer::setBackgroundVolume(float volume) {
	JNIEnv* env = getEnv();
	env->CallStaticVoidMethod(gClass_AudioManager, jmethodID_AudioManager_mpSetBackgroundVolume, volume);
}

void wyAudioManager_mediaplayer::setEffectVolume(float volume) {
	JNIEnv* env = getEnv();
	env->CallStaticVoidMethod(gClass_AudioManager, jmethodID_AudioManager_mpSetEffectVolume, volume);
}

void wyAudioManager_mediaplayer::preloadBackgroundMusic(int resId, int type) {
	JNIEnv* env = getEnv();
	env->CallStaticVoidMethod(gClass_AudioManager, jmethodID_AudioManager_mpPreloadBackgroundMusic_resId, resId);
}

void wyAudioManager_mediaplayer::preloadBackgroundMusic(const char* path, bool isFile) {
	JNIEnv* env = getEnv();
	jstring p = env->NewStringUTF(path);
	env->CallStaticVoidMethod(gClass_AudioManager, jmethodID_AudioManager_mpPreloadBackgroundMusic_path, p, isFile);
	env->DeleteLocalRef(p);
}

void wyAudioManager_mediaplayer::playBackgroundMusic(int resId, int type, int repeatCount) {
	JNIEnv* env = getEnv();
	env->CallStaticVoidMethod(gClass_AudioManager, jmethodID_AudioManager_mpPlayBackgroundMusic_resId, resId, type, repeatCount);
	m_backgroundMusicPaused = false;
}

void wyAudioManager_mediaplayer::playBackgroundMusic(const char* path, bool isFile, int repeatCount) {
	JNIEnv* env = getEnv();
	jstring p = env->NewStringUTF(path);
	env->CallStaticVoidMethod(gClass_AudioManager, jmethodID_AudioManager_mpPlayBackgroundMusic_path, p, isFile, repeatCount);
	env->DeleteLocalRef(p);
	m_backgroundMusicPaused = false;
}

void wyAudioManager_mediaplayer::stopBackgroundMusic() {
	JNIEnv* env = getEnv();
	env->CallStaticVoidMethod(gClass_AudioManager, jmethodID_AudioManager_mpStopBackgroundMusic);
	m_backgroundMusicPaused = false;
}

bool wyAudioManager_mediaplayer::isBackgroundMusicPaused() {
	return m_backgroundMusicPaused;
}

void wyAudioManager_mediaplayer::pauseBackgroundMusic() {
	JNIEnv* env = getEnv();
	env->CallStaticVoidMethod(gClass_AudioManager, jmethodID_AudioManager_mpPauseBackgroundMusic);
	m_backgroundMusicPaused = true;
}

void wyAudioManager_mediaplayer::resumeBackgroundMusic() {
	JNIEnv* env = getEnv();
	env->CallStaticVoidMethod(gClass_AudioManager, jmethodID_AudioManager_mpResumeBackgroundMusic);
	m_backgroundMusicPaused = false;
}

bool wyAudioManager_mediaplayer::isBackgroundPlaying() {
	JNIEnv* env = getEnv();
	return env->CallStaticBooleanMethod(gClass_AudioManager, jmethodID_AudioManager_mpIsBackgroundPlaying);
}

void wyAudioManager_mediaplayer::playEffect(int resId, int type) {
	JNIEnv* env = getEnv();
	env->CallStaticVoidMethod(gClass_AudioManager, jmethodID_AudioManager_mpPlayEffect_resId, resId);
}

void wyAudioManager_mediaplayer::playEffect(const char* path, bool isFile) {
	JNIEnv* env = getEnv();
	jstring p = env->NewStringUTF(path);
	env->CallStaticVoidMethod(gClass_AudioManager, jmethodID_AudioManager_mpPlayEffect_path, p, isFile);
	env->DeleteLocalRef(p);
}

void wyAudioManager_mediaplayer::preloadEffect(int resId, int type) {
	JNIEnv* env = getEnv();
	env->CallStaticVoidMethod(gClass_AudioManager, jmethodID_AudioManager_mpPreloadEffect_resId, resId);
}

void wyAudioManager_mediaplayer::preloadEffect(const char* path, bool isFile) {
	JNIEnv* env = getEnv();
	jstring p = env->NewStringUTF(path);
	env->CallStaticVoidMethod(gClass_AudioManager, jmethodID_AudioManager_mpPreloadEffect_path, p, isFile);
	env->DeleteLocalRef(p);
}

void wyAudioManager_mediaplayer::stopEffect(int resId) {
	JNIEnv* env = getEnv();
	env->CallStaticVoidMethod(gClass_AudioManager, jmethodID_AudioManager_mpStopEffect_resId, resId);
}

void wyAudioManager_mediaplayer::stopEffect(const char* path, bool isFile) {
	JNIEnv* env = getEnv();
	jstring p = env->NewStringUTF(path);
	env->CallStaticVoidMethod(gClass_AudioManager, jmethodID_AudioManager_mpStopEffect_path, p);
	env->DeleteLocalRef(p);
}

void wyAudioManager_mediaplayer::removeAllEffects() {
	JNIEnv* env = getEnv();
	env->CallStaticVoidMethod(gClass_AudioManager, jmethodID_AudioManager_mpRemoveAllEffects);
}

void wyAudioManager_mediaplayer::removeEffect(int resId) {
	JNIEnv* env = getEnv();
	env->CallStaticVoidMethod(gClass_AudioManager, jmethodID_AudioManager_mpRemoveEffect_resId, resId);
}

void wyAudioManager_mediaplayer::removeEffect(const char* path) {
	JNIEnv* env = getEnv();
	jstring p = env->NewStringUTF(path);
	env->CallStaticVoidMethod(gClass_AudioManager, jmethodID_AudioManager_mpRemoveEffect_path, p);
	env->DeleteLocalRef(p);
}

void wyAudioManager_mediaplayer::setMute(bool mute) {
	JNIEnv* env = getEnv();
	env->CallStaticVoidMethod(gClass_AudioManager, jmethodID_AudioManager_mpSetMute, mute);
}

bool wyAudioManager_mediaplayer::isMuted() {
	JNIEnv* env = getEnv();
	return env->CallStaticBooleanMethod(gClass_AudioManager, jmethodID_AudioManager_mpIsMute);
}

#endif // #if BACKEND_MEDIAPLAYER
