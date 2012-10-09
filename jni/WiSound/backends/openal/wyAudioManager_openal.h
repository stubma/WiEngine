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
#ifndef __wyAudioManager_openal_h__
#define __wyAudioManager_openal_h__

#if BACKEND_OPENAL

#include "wyObject.h"
#include "wyGlobal.h"
#include "wyScheduler.h"
#include "wyAudioManager.h"
#include "wyAudioPlayer.h"
#include <pthread.h>

/**
 * @class wyAudioManager_openal
 *
 * OpenAL后端实现, 基于OpenAL播放音乐. 但是在Android低端机上有较严重的卡顿问题.
 */
class wyAudioManager_openal : public wyAudioManager {
	friend class wyAudioPlayer;
	friend class wyAudioManager;
	
private:
	/// effect structure
	struct Effect {
		/// buffer
		char* buffer;
		
		/// length
		size_t length;
		
		/// resource id
		int resId;
		
		/// path
		const char* path;
		
		/// audio type
		int type;
	};

private:
	/// true means mute
	bool m_mute;

	/// volume of background music
	float m_backgroundVolume;

	/// volume of effect sound
	float m_effectVolume;

	/// current audio stream which is playing
	vector<wyAudioPlayer*>* m_audios;

	/// audio stream need to be removed
	vector<wyAudioPlayer*>* m_pendingRemoveAudios;

	/// effect preloaded
	vector<Effect*>* m_preloadEffects;

	/// update timer
	wyTimer* m_timer;

	/// mutex
	pthread_mutex_t m_mutex;

private:
	/**
	 * release effect
	 *
	 * @param effect effect structure pointer
	 */
	static void releaseEffect(Effect* effect);
	
	/**
	 * 当音频停止时被调用
	 *
	 * @param player audio player object
	 */
	void onAudioStop(wyAudioPlayer* player);

	/**
	 * 检查是否存在某个音频流了
	 *
	 * @param resId 要检查的资源id
	 * @return true表示这个音频资源已经在播放了
	 */
	bool hasAudio(int resId);

	/**
	 * 检查是否存在某个音频流了
	 *
	 * @param path 音频文件的路径
	 * @return true表示这个音频资源已经在播放了
	 */
	bool hasAudio(const char* path);

	/**
	 * 检查是否已经与预载入了某个音频流
	 *
	 * @param resId 要检查的资源id
	 * @return true表示这个音频资源已经预载入了
	 */
	bool hasPreloadedEffect(int resId);

	/**
	 * 检查是否已经与预载入了某个音频流
	 *
	 * @param path 音频文件的路径
	 * @return true表示这个音频资源已经预载入了
	 */
	bool hasPreloadedEffect(const char* path);

	/**
	 * 获得某个正在播放的音频流
	 *
	 * @param resId 音频文件资源id
	 * @return 返回找到的\link wyAudioPlayer wyAudioPlayer\endlink对象, 如果没找到返回NULL
	 */
	wyAudioPlayer* getAudio(int resId);

	/**
	 * 获得某个正在播放的音频流
	 *
	 * @param path 音频文件的路径
	 * @return 返回找到的\link wyAudioPlayer wyAudioPlayer\endlink对象, 如果没找到返回NULL
	 */
	wyAudioPlayer* getAudio(const char* path);

	/**
	 * 获得某个预载入的音频流
	 *
	 * @param resId 音频文件资源id
	 * @return 返回找到的\link Effect Effect\endlink对象, 如果没找到返回NULL
	 */
	Effect* getPreloadedEffect(int resId);

	/**
	 * 获得某个预载入的音频流
	 *
	 * @param path 音频文件的路径
	 * @return 返回找到的\link Effect Effect\endlink对象, 如果没找到返回NULL
	 */
	Effect* getPreloadedEffect(const char* path);

protected:
	wyAudioManager_openal();

	/// update sound
	void update(wyTargetSelector* ts);

public:
	virtual ~wyAudioManager_openal();

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

#endif // #if BACKEND_OPENAL

#endif // __wyAudioManager_openal_h__
