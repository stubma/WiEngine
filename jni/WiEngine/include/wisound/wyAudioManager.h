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
#ifndef __wyAudioManager_h__
#define __wyAudioManager_h__

#include "wyObject.h"

#define FORMAT_MP3 1
#define FORMAT_WAV 2
#define FORMAT_OGG 3

// export definition
#if WINDOWS
	#if LIBWISOUND_EXPORTS
		#define WISOUND_API __declspec(dllexport)
	#else
		#define WISOUND_API __declspec(dllimport)
	#endif
#else
	#define WISOUND_API
#endif

/**
 * @class wyAudioManager
 *
 * Audio manager interface
 */
class WISOUND_API wyAudioManager : public wyObject {
private:
	static wyAudioManager* s_instance;

protected:
	wyAudioManager();

public:
	/**
	 * Get shared instance of audio manager
	 *
	 * @return \link wyAudioManager wyAudioManager\endlink
	 */
	static wyAudioManager* getInstance();

	/**
	 * Get shared instance of audio manager, but don't create it if it doesn't
	 * exist yet
	 *
	 * @return \link wyAudioManager wyAudioManager\endlink, or NULL if it is not
	 * 		created yet
	 */
	static wyAudioManager* getInstanceNoCreate();

	/**
	 * Release shared instance, if exists, of audio manager
	 */
	static void releaseInstance();

public:
	virtual ~wyAudioManager();

	/**
	 * load background music by resource id, asynchronously
	 *
	 * @param resId resource id of audio file
	 * @param type audio format, default is MP3
	 */
	virtual void preloadBackgroundMusic(int resId, int type = FORMAT_MP3) = 0;

	/**
	 * load background music by path, asynchronously
	 *
	 * @param path path of audio file
	 * @param isFile true means \c path is an absolute path in file system, false means \c path
	 * 			is relative path in assets
	 */
	virtual void preloadBackgroundMusic(const char* path, bool isFile = false) = 0;

	/**
	 * play audio by resource id
	 *
	 * @param resourceId resource id of audio file
	 * @param type audio file format, default is MP3
	 * @param repeatCount loop count, 0 means not loop, < 0 means loop forever, > 0 means loop times
	 */
	virtual void playBackgroundMusic(int resourceId, int type = FORMAT_MP3, int repeatCount = 0) = 0;

	/**
	 * play audio by path
	 *
	 * @param path path of audio file
	 * @param isFile true means \c path is an absolute path in file system, false means \c path
	 * 			is relative path in assets
	 * @param repeatCount loop count, 0 means not loop, < 0 means loop forever, > 0 means loop times
	 */
	virtual void playBackgroundMusic(const char* path, bool isFile = false, int repeatCount = 0) = 0;

	/**
	 * stop playing background music
	 */
	virtual void stopBackgroundMusic() = 0;

	/**
	 * is background music playing?
	 */
	virtual bool isBackgroundPlaying() = 0;

	/**
	 * is background music paused
	 */
	virtual bool isBackgroundMusicPaused() = 0;

	/**
	 * pause background music
	 */
	virtual void pauseBackgroundMusic() = 0;

	/**
	 * resume background music playing
	 */
	virtual void resumeBackgroundMusic() = 0;

	/**
	 * set volume of background music
	 *
	 * @param volume volume, from 0 to 1
	 */
	virtual void setBackgroundVolume(float volume) = 0;

	/**
	 * set volume of effect sound
	 *
	 * @param volume volume, from 0 to 1
	 */
	virtual void setEffectVolume(float volume) = 0;

	/**
	 * play effect sound by resource id
	 *
	 * @param resId resource id of audio file
	 * @param type audio file format, default is MP3
	 */
	virtual void playEffect(int resId, int type = FORMAT_MP3) = 0;

	/**
	 * play effect sound by resource id
	 *
	 * @param path path of audio file
	 * @param isFile true means \c path is an absolute path in file system, false means \c path
	 * 			is relative path in assets
	 */
	virtual void playEffect(const char* path, bool isFile = false) = 0;

	/**
	 * preload effect sound file by resource id, that will decrease effect playing delay
	 * at first time
	 *
	 * @param resId resource id of effect sound
	 * @param type audio format, default is MP3
	 */
	virtual void preloadEffect(int resId, int type = FORMAT_MP3) = 0;

	/**
	 * preload effect sound file by path, that will decrease effect playing delay at first
	 * time
	 *
	 * @param path path of audio file
	 * @param isFile true means \c path is an absolute path in file system, false means \c path
	 * 			is relative path in assets
	 */
	virtual void preloadEffect(const char* path, bool isFile = false) = 0;

	/**
	 * stop effect sound by resource id
	 *
	 * @param resourceId resource id of audio file
	 */
	virtual void stopEffect(int resourceId) = 0;

	/**
	 * stop effect sound by path
	 *
	 * @param path path of audio file
	 * @param isFile true means \c path is an absolute path in file system, false means \c path
	 * 			is relative path in assets
	 */
	virtual void stopEffect(const char* path, bool isFile = false) = 0;

	/**
	 * remove all preloaded effect sound
	 */
	virtual void removeAllEffects() = 0;

	/**
	 * remove one effect by resource id
	 *
	 * @param resId resource id of effect file
	 */
	virtual void removeEffect(int resId) = 0;

	/**
	 * Remove one effect by effect path
	 *
	 * @param path of effect file
	 */
	virtual void removeEffect(const char* path) = 0;

	/**
	 * set mute on or off
	 */
	virtual void setMute(bool mute) = 0;

	/**
	 * is mute on or off?
	 */
	virtual bool isMuted() = 0;
};

#endif // __wyAudioManager_h__
