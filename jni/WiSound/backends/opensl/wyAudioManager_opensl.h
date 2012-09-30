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

#ifndef __wyAudioManager_opensl_h__
#define __wyAudioManager_opensl_h__

#if BACKEND_OPENSL

#include "wyObject.h"
#include "wyGlobal.h"
#include "wyAudioManager.h"
#include "wyAudioStream.h"
#include <pthread.h>
#include <SLES/OpenSLES.h>
#include <SLES/OpenSLES_Android.h>

/**
 * @class wyAudioManager_opensl
 *
 * OpenSL backend, but it can only be used in Android 2.3 or above version
 */
class wyAudioManager_opensl : public wyAudioManager {
	friend class wyAudioManager;

private:
	/// effect
	struct Effect {
		/// if effect is a resource, this will not be zero
		int resId;

		/// if effect is a file, this will not be NULL
		const char* path;

		/// audio data buffer, capacity is 16K
		const void* buffer;

		/// actual data in buffer
		int length;

		/// bits per sample
		int bitsPerSample;

		/// audio channel count
		int channel;

		/// sample rate
		int sampleRate;
	};

	/// player object needed by an effect
	struct EffectPlayer {
		// related effect
		Effect* effect;

		/// player object
		SLObjectItf playerObj;

		/// player
		SLPlayItf player;

		/// buffer queue
		SLAndroidSimpleBufferQueueItf queue;

		/// volumer
		SLVolumeItf volumer;
	};

private:
	/// true means mute
	bool m_mute;

	/// volume of background music
	float m_backgroundVolume;

	/// volume of effect sound
	float m_effectVolume;

	/// mutex
	pthread_mutex_t m_mutex;

	/// OpenSL engine object
	SLObjectItf m_engineObj;

	/// OpenSL engine interface
	SLEngineItf m_engine;

	/// mixer object
	SLObjectItf m_mixerObj;

	/// mixer interface
	SLEnvironmentalReverbItf m_mixer;

	/// background music player object, only one
	SLObjectItf m_bgPlayerObj;

	/// background music player interface
	SLPlayItf m_bgPlayer;

	/// background music seeker interface
	SLSeekItf m_bgSeeker;

	/// volume control of background music
	SLVolumeItf m_bgVolumer;

	/// current background music resource id
	int m_bgResId;

	/// current background music path
	const char* m_bgPath;

	/// true means background music is playing
	bool m_playing;

	/// true means background music is paused
	bool m_paused;

	/**
	 * repeat times of background music
	 * 0: no loop
	 * > 0: loop times
	 * < 0: forever loop
	 */
	int m_repeatCount;

	/// all effects is in playing
	vector<EffectPlayer*>* m_effectPlayers;

	/// effect player cache
	vector<EffectPlayer*>* m_effectPlayerCache;

	/// max allowed effects can be played simultaneously
	int m_maxEffects;

	/// preloaded effects
	vector<Effect*>* m_effects;

private:
	/**
	 * callback of background music playing
	 */
	static void bgPlayCallback(SLPlayItf caller, void* pContext, SLuint32 event);

	/**
	 * callback of effect player
	 */
	static void effectPlayCallback(SLAndroidSimpleBufferQueueItf queue, void* context);

	/**
	 * Release effect player
	 *
	 * @param player structure of effect player
	 */
	static void releaseEffectPlayer(EffectPlayer* player);

	/**
	 * Release effect
	 *
	 * @param effect effect structure
	 */
	static void releaseEffect(Effect* effect);

	/**
	 * Setup OpenSL engine
	 */
	void createEngine();

	/**
	 * Release engine
	 */
	void releaseEngine();

	/**
	 * Create background music player
	 *
	 * @param resourceId resource id of background music file
	 * @param type background music type
	 */
	void createBgPlayer(int resourceId, int type);

	/**
	 * Create background music player
	 *
	 * @param path path of audio file
	 * @param isFile path is in file system or assets
	 */
	void createBgPlayer(const char* path, bool isFile);

	/**
	 * Create background music player
	 *
	 * @param fd file descriptor
	 * @param start start offset
	 * @param length length of byte
	 * @param type audio type
	 */
	void createBgPlayer(size_t fd, size_t start, size_t length, SLuint32 type);

	/**
	 * Release background music player
	 */
	void releaseBgPlayer();

	/**
	 * Create effect player
	 *
	 * @param effect effect to be played
	 * @return created effect player structure
	 */
	EffectPlayer* createEffectPlayer(Effect* effect);

	/**
	 * Recycle effect player
	 *
	 * @param ep effect player structure pointer
	 */
	void recycleEffectPlayer(EffectPlayer* ep);

	/**
	 * Recycle effect player, by a iterator
	 *
	 * @param iter iterator of effect player
	 */
	void recycleEffectPlayer(vector<EffectPlayer*>::iterator iter);

	/**
	 * Get effect
	 *
	 * @param resId resource id of audio file
	 * @return if found, return effect, or NULL if not found
	 */
	Effect* getEffect(int resId);

	/**
	 * Get effect player
	 *
	 * @param path file path of audio file
	 * @param isFile indicating path is in file system or assets
	 * @return if found, return effect, or NULL if not found
	 */
	Effect* getEffect(const char* path);

	/**
	 * Get effect player
	 *
	 * @param queue buffer queue pointer
	 * @return if found, return player of effect, or NULL if not found
	 */
	EffectPlayer* getEffectPlayer(SLAndroidSimpleBufferQueueItf queue);

	/**
	 * Get OpenSL constant of sample rate
	 *
	 * @param sample rate
	 * @return OpenSL sample rate constant
	 */
	SLuint32 getSampleRate(int sampleRate);

	/**
	 * Get bits per sample in OpenSL constant
	 *
	 * @param bps bits per sample
	 * @return OpenSL constant for bits per sample
	 */
	SLuint32 getBitsPerSample(int bps);

protected:
	wyAudioManager_opensl();

public:
	virtual ~wyAudioManager_opensl();

	/// @see wyAudioManager::preloadBackgroundMusic
	virtual void preloadBackgroundMusic(int resId, int type = FORMAT_MP3);

	/// @see wyAudioManager::preloadBackgroundMusic
	virtual void preloadBackgroundMusic(const char* path, bool isFile = false);

	/// @see wyAudioManager::playBackgroundMusic
	virtual void playBackgroundMusic(int resourceId, int type = FORMAT_MP3, int repeatCount = 0);

	/// @see wyAudioManager::playBackgroundMusic
	virtual void playBackgroundMusic(const char* path, bool isFile, int repeatCount = 0);

	/// @see wyAudioManager::stopBackgroundMusic
	virtual void stopBackgroundMusic();

	/// @see wyAudioManager::isBackgroundPlaying
	virtual bool isBackgroundPlaying();

	/// @see wyAudioManager::isBackgroundMusicPaused
	virtual bool isBackgroundMusicPaused();

	/// @see wyAudioManager::pauseBackgroundMusic
	virtual void pauseBackgroundMusic();

	/// @see wyAudioManager::resumeBackgroundMusic
	virtual void resumeBackgroundMusic();

	/// @see wyAudioManager::setBackgroundVolume
	virtual void setBackgroundVolume(float volume);

	/// @see wyAudioManager::setEffectVolume
	virtual void setEffectVolume(float volume);

	/// @see wyAudioManager::playEffect
	virtual void playEffect(int resId, int type = FORMAT_MP3);

	/// @see wyAudioManager::playEffect
	virtual void playEffect(const char* path, bool isFile = false);

	/// @see wyAudioManager::preloadEffect
	virtual void preloadEffect(int resId, int type = FORMAT_MP3);

	/// @see wyAudioManager::preloadEffect
	virtual void preloadEffect(const char* path, bool isFile = false);

	/// @see wyAudioManager::stopEffect
	virtual void stopEffect(int resourceId);

	/// @see wyAudioManager::stopEffect
	virtual void stopEffect(const char* path, bool isFile = false);

	/// @see wyAudioManager::removeAllEffects
	virtual void removeAllEffects();

	/// @see wyAudioManager::removeEffect
	virtual void removeEffect(int resId);

	/// @see wyAudioManager::removeEffect
	virtual void removeEffect(const char* path);

	/// @see wyAudioManager::setMute
	virtual void setMute(bool mute);

	/// @see wyAudioManager::isMuted
	virtual bool isMuted();
};

#endif // #if BACKEND_OPENSL

#endif // __wyAudioManager_opensl_h__
