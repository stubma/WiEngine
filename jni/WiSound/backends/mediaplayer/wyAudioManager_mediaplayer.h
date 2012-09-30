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


#ifndef __wyAudioManager_mediaplayer_h__
#define __wyAudioManager_mediaplayer_h__

#if BACKEND_MEDIAPLAYER

#include "wyHashSet.h"
#include "wyAudioManager.h"

/**
 * @class wyAudioManager_mediaplayer
 *
 * MediaPlayer后端实现, 基于Androdi自带的MediaPlayer和SoundPool播放音乐. 在
 * Android上有较好的性能.
 */
class wyAudioManager_mediaplayer : public wyAudioManager {
	friend class wyAudioManager;

private:
	/// 预载入音效哈希表
	wyHashSet* m_preloadedEffects;

	/// true表示已暂停播放背景音
	bool m_backgroundMusicPaused;

private:
	static int effectHashEquals(void* ptr, void* elt);
	static void* buildEffectHash(void* ptr, void* data);
	static bool releaseHash(void* elt, void* data);

	/**
	 * 检查是否某个特效音频文件已经预先载入了
	 *
	 * @param resId 特效音乐文件的资源id
	 * @return true表示已经预先载入了
	 */
	bool hasPreloadedEffect(int resId);

	/**
	 * 检查是否某个特效音频文件已经预先载入了
	 *
	 * @param path 特效音乐文件的路径
	 * @return true表示已经预先载入了
	 */
	bool hasPreloadedEffect(const char* path);

	/**
	 * 得到特效的soundpool流id
	 *
	 * @param resId 特效音乐文件的资源id
	 * @return 流id, 如果没有找到, 返回-1
	 */
	int getEffectStreamId(int resId);

	/**
	 * 得到特效的soundpool流id
	 *
	 * @param path 特效音乐文件的路径
	 * @return 流id, 如果没有找到, 返回-1
	 */
	int getEffectStreamId(const char* path);

protected:
	wyAudioManager_mediaplayer();

public:
	virtual ~wyAudioManager_mediaplayer();

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

#endif // #if BACKEND_MEDIAPLAYER

#endif // __wyAudioManager_mediaplayer_h__
