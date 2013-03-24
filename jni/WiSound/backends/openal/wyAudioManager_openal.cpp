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
#if BACKEND_OPENAL

#include "wyDirector.h"
#include "wyAudioManager_openal.h"
#include <stdio.h>
#include "wyTypes.h"
#include "wyUtils.h"
#include "wyLog.h"
#include "wyOpenAL.h"
#include "wyAudioPlayer.h"
#include "wyAudioStream.h"
#include "wyMp3Stream.h"
#include "wyOggStream.h"
#include "wyWavStream.h"

// singleton
wyAudioManager_openal* gAudioManager = NULL;

wyAudioManager_openal::wyAudioManager_openal() :
		m_backgroundVolume(1.f),
		m_effectVolume(1.f),
		m_audios(NULL),
		m_pendingRemoveAudios(NULL),
		m_preloadEffects(NULL),
		m_timer(NULL),
		m_mute(false) {
	// init OpenAL
	wyOpenAL::init();

	// create mutex
	pthread_mutexattr_t attr;
	pthread_mutexattr_init(&attr);
	pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE);
	pthread_mutex_init(&m_mutex, &attr);
	pthread_mutexattr_destroy(&attr);
			
	// init other members
	m_preloadEffects = new vector<Effect*>();
	m_preloadEffects->reserve(10);
	m_audios = new vector<wyAudioPlayer*>();
	m_audios->reserve(10);
	m_pendingRemoveAudios = new vector<wyAudioPlayer*>();
	m_pendingRemoveAudios->reserve(10);
			
	// init mpg123
	mpg123_init();

	// schedule update timer
	wyTargetSelector* ts = wyTargetSelector::make(this, SEL(wyAudioManager_openal::update));
	m_timer = wyTimer::make(ts);
	wyScheduler::getInstance()->scheduleLocked(m_timer);
}

wyAudioManager_openal::~wyAudioManager_openal() {
	wyScheduler::getInstance()->unscheduleLocked(m_timer);
	
	for(vector<wyAudioPlayer*>::iterator iter = m_audios->begin(); iter != m_audios->end(); iter++) {
		wyObjectRelease(*iter);
	}
	WYDELETE(m_audios);
	WYDELETE(m_pendingRemoveAudios);
	for(vector<Effect*>::iterator iter = m_preloadEffects->begin(); iter != m_preloadEffects->end(); iter++) {
		releaseEffect(*iter);
	}
	WYDELETE(m_preloadEffects);

	pthread_mutex_destroy(&m_mutex);

	mpg123_exit();
	wyOpenAL::destroy();
}

wyAudioManager* wyAudioManager::getInstance() {
	if (gAudioManager == NULL) {
		gAudioManager = WYNEW wyAudioManager_openal();
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

void wyAudioManager_openal::releaseEffect(Effect* effect) {
	if(effect->buffer)
		wyFree(effect->buffer);
	if(effect->path)
		wyFree((void*)effect->path);
	wyFree((void*)effect);
}

void wyAudioManager_openal::onAudioStop(wyAudioPlayer* player) {
	pthread_mutex_lock(&m_mutex);
	
	m_pendingRemoveAudios->push_back(player);
	
	pthread_mutex_unlock(&m_mutex);
}

bool wyAudioManager_openal::hasAudio(int resId) {
	for(vector<wyAudioPlayer*>::iterator iter = m_audios->begin(); iter != m_audios->end(); iter++) {
		if((*iter)->getStream()->isSame(resId)) {
			return true;
		}
	}

	return false;
}

bool wyAudioManager_openal::hasAudio(const char* path) {
	for(vector<wyAudioPlayer*>::iterator iter = m_audios->begin(); iter != m_audios->end(); iter++) {
		if((*iter)->getStream()->isSame(path)) {
			return true;
		}
	}
	
	return false;
}

bool wyAudioManager_openal::hasPreloadedEffect(int resId) {
	for(vector<Effect*>::iterator iter = m_preloadEffects->begin(); iter != m_preloadEffects->end(); iter++) {
		if((*iter)->resId == resId) {
			return true;
		}
	}
	
	return false;
}

bool wyAudioManager_openal::hasPreloadedEffect(const char* path) {
	for(vector<Effect*>::iterator iter = m_preloadEffects->begin(); iter != m_preloadEffects->end(); iter++) {
		if((*iter)->path && !strcmp(path, (*iter)->path)) {
			return true;
		}
	}
	
	return false;
}

wyAudioPlayer* wyAudioManager_openal::getAudio(int resId) {
	for(vector<wyAudioPlayer*>::iterator iter = m_audios->begin(); iter != m_audios->end(); iter++) {
		if((*iter)->getStream()->isSame(resId)) {
			return *iter;
		}
	}
	return NULL;
}

wyAudioPlayer* wyAudioManager_openal::getAudio(const char* path)  {
	for(vector<wyAudioPlayer*>::iterator iter = m_audios->begin(); iter != m_audios->end(); iter++) {
		if((*iter)->getStream()->isSame(path)) {
			return *iter;
		}
	}
	return NULL;
}

wyAudioManager_openal::Effect* wyAudioManager_openal::getPreloadedEffect(int resId) {
	for(vector<Effect*>::iterator iter = m_preloadEffects->begin(); iter != m_preloadEffects->end(); iter++) {
		if((*iter)->resId == resId) {
			return *iter;
		}
	}
	
	return NULL;
}

wyAudioManager_openal::Effect* wyAudioManager_openal::getPreloadedEffect(const char* path)  {
	for(vector<Effect*>::iterator iter = m_preloadEffects->begin(); iter != m_preloadEffects->end(); iter++) {
		if((*iter)->path && !strcmp(path, (*iter)->path)) {
			return *iter;
		}
	}
	
	return NULL;
}

void wyAudioManager_openal::update(wyTargetSelector* ts) {
	pthread_mutex_lock(&m_mutex);

	// remove pending audios
	for(vector<wyAudioPlayer*>::iterator iter1 = m_pendingRemoveAudios->begin(); iter1 != m_pendingRemoveAudios->end(); iter1++) {
		for(vector<wyAudioPlayer*>::iterator iter2 = m_audios->begin(); iter2 != m_audios->end(); iter2++) {
			if(*iter1 == *iter2) {
				// must remember, erase will let iter move forward so release should
				// be called first
				wyObjectRelease(*iter2);
				m_audios->erase(iter2);
				break;
			}
		}
	}

	// clear pending remove list
	m_pendingRemoveAudios->clear();

	// update every player
	for(vector<wyAudioPlayer*>::iterator iter = m_audios->begin(); iter != m_audios->end(); iter++) {
		(*iter)->update();
	}

	pthread_mutex_unlock(&m_mutex);
}

void wyAudioManager_openal::setBackgroundVolume(float volume) {
	m_backgroundVolume = volume;

	pthread_mutex_lock(&m_mutex);

	for(vector<wyAudioPlayer*>::iterator iter = m_audios->begin(); iter != m_audios->end(); iter++) {
		if(!(*iter)->getStream()->isSingleBuffer())
			(*iter)->setVolume(volume);
	}

	pthread_mutex_unlock(&m_mutex);
}

void wyAudioManager_openal::setEffectVolume(float volume) {
	m_effectVolume = volume;

	pthread_mutex_lock(&m_mutex);

	for(vector<wyAudioPlayer*>::iterator iter = m_audios->begin(); iter != m_audios->end(); iter++) {
		if((*iter)->getStream()->isSingleBuffer())
			(*iter)->setVolume(volume);
	}

	pthread_mutex_unlock(&m_mutex);
}

void wyAudioManager_openal::preloadBackgroundMusic(int resId, int type) {
	// do nothing
}

void wyAudioManager_openal::preloadBackgroundMusic(const char* path, bool isFile) {
	// do nothing
}

void wyAudioManager_openal::playBackgroundMusic(int resId, int type, int repeatCount) {
	pthread_mutex_lock(&m_mutex);

	if(!hasAudio(resId)) {
		wyAudioStream* audio = NULL;
		switch(type) {
			case FORMAT_MP3:
				audio = wyMp3Stream::make(resId);
				break;
			case FORMAT_WAV:
				audio = wyWavStream::make(resId);
				break;
			case FORMAT_OGG:
				audio = wyOggStream::make(resId);
				break;
			default:
				LOGW("playBackgroundMusic: Unsupported audio type: %d", type);
				break;
		}

		if(audio) {
			audio->setup();
            wyAudioPlayer* player = wyAudioPlayer::make(audio);
            player->retain();
			player->setLoopCount(repeatCount);
			player->play(m_backgroundVolume);
			m_audios->push_back(player);
		}
	}

	pthread_mutex_unlock(&m_mutex);
}

void wyAudioManager_openal::playBackgroundMusic(const char* path, bool isFile, int repeatCount) {
	pthread_mutex_lock(&m_mutex);

	if(!hasAudio(path)) {
		wyAudioStream* audio = NULL;
		if(wyUtils::endsWith(path, ".wav") || wyUtils::endsWith(path, ".WAV")) {
			audio = wyWavStream::make(path, isFile);
		} else if(wyUtils::endsWith(path, ".mp3") || wyUtils::endsWith(path, ".MP3")) {
			audio = wyMp3Stream::make(path, isFile);
		} else if(wyUtils::endsWith(path, ".ogg") || wyUtils::endsWith(path, ".OGG")) {
			audio = wyOggStream::make(path, isFile);
		} else {
			LOGW("playBackgroundMusic: Unsupported audio type: %s", path);
		}

		if(audio) {
			audio->setup();
            wyAudioPlayer* player = wyAudioPlayer::make(audio);
            player->retain();
			player->setLoopCount(repeatCount);
			player->play(m_backgroundVolume);
			m_audios->push_back(player);
		}
	}

	pthread_mutex_unlock(&m_mutex);
}

void wyAudioManager_openal::stopBackgroundMusic() {
	pthread_mutex_lock(&m_mutex);
	
	for(vector<wyAudioPlayer*>::iterator iter = m_audios->begin(); iter != m_audios->end(); iter++) {
		if(!(*iter)->getStream()->isSingleBuffer())
			(*iter)->stop();
	}
	
	pthread_mutex_unlock(&m_mutex);
}

bool wyAudioManager_openal::isBackgroundMusicPaused() {
	pthread_mutex_lock(&m_mutex);
	
	for(vector<wyAudioPlayer*>::iterator iter = m_audios->begin(); iter != m_audios->end(); iter++) {
		if(!(*iter)->getStream()->isSingleBuffer())
			(*iter)->isPaused();
	}
	
	pthread_mutex_unlock(&m_mutex);
	
	return false;
}

void wyAudioManager_openal::pauseBackgroundMusic() {
	pthread_mutex_lock(&m_mutex);
	
	for(vector<wyAudioPlayer*>::iterator iter = m_audios->begin(); iter != m_audios->end(); iter++) {
		if(!(*iter)->getStream()->isSingleBuffer())
			(*iter)->pause();
	}
	
	pthread_mutex_unlock(&m_mutex);
}

void wyAudioManager_openal::resumeBackgroundMusic() {
	pthread_mutex_lock(&m_mutex);
	
	for(vector<wyAudioPlayer*>::iterator iter = m_audios->begin(); iter != m_audios->end(); iter++) {
		if(!(*iter)->getStream()->isSingleBuffer())
			(*iter)->resume();
	}
	
	pthread_mutex_unlock(&m_mutex);
}

bool wyAudioManager_openal::isBackgroundPlaying() {
	pthread_mutex_lock(&m_mutex);
	
	bool ret = false;
	for(vector<wyAudioPlayer*>::iterator iter = m_audios->begin(); iter != m_audios->end(); iter++) {
		if(!(*iter)->getStream()->isSingleBuffer() && (*iter)->isPlaying())
			ret = true;
	}
	
	pthread_mutex_unlock(&m_mutex);

	return ret;
}

void wyAudioManager_openal::playEffect(int resId, int type) {
	pthread_mutex_lock(&m_mutex);

	// get effect info
	Effect* effect = getPreloadedEffect(resId);
	if(!effect) {
		preloadEffect(resId, type);
		effect = getPreloadedEffect(resId);
	}
	
	// if fail to load effect, return
	// if ok, create audio stream and player
	if(!effect) {
		LOGW("Failed to load effect res id: %d", resId);
	} else {
		wyAudioStream* audio = NULL;
		switch(effect->type) {
			case FORMAT_MP3:
				audio = wyMp3Stream::make(effect->buffer, effect->length);
				break;
			case FORMAT_WAV:
				audio = wyWavStream::make(effect->buffer, effect->length);
				break;
			case FORMAT_OGG:
				audio = wyOggStream::make(effect->buffer, effect->length);
				break;
			default:
				LOGW("preloadEffect: Unsupported audio type: %d", effect->type);
				break;
		}
		
		if(audio) {
			audio->setup();
			wyAudioPlayer* player = wyAudioPlayer::make(audio);
			player->retain();
			player->play(m_effectVolume);
			m_audios->push_back(player);
		}
	}

	pthread_mutex_unlock(&m_mutex);
}

void wyAudioManager_openal::playEffect(const char* path, bool isFile) {
	pthread_mutex_lock(&m_mutex);

	// get effect
	Effect* effect = getPreloadedEffect(path);
	if(!effect) {
		preloadEffect(path, isFile);
		effect = getPreloadedEffect(path);
	}
	
	// if fail to load effect, return
	// if ok, create audio stream and player
	if(!effect) {
		LOGW("Failed to load effect path: %s", path);
	} else {
		wyAudioStream* audio = NULL;
		switch(effect->type) {
			case FORMAT_MP3:
				audio = wyMp3Stream::make(effect->buffer, effect->length);
				break;
			case FORMAT_WAV:
				audio = wyWavStream::make(effect->buffer, effect->length);
				break;
			case FORMAT_OGG:
				audio = wyOggStream::make(effect->buffer, effect->length);
				break;
			default:
				LOGW("preloadEffect: Unsupported audio type: %d", effect->type);
				break;
		}
		
		if(audio) {
			audio->setup();
            wyAudioPlayer* player = wyAudioPlayer::make(audio);
            player->retain();
			player->play(m_effectVolume);
			m_audios->push_back(player);
		}
	}

	pthread_mutex_unlock(&m_mutex);
}

void wyAudioManager_openal::preloadEffect(int resId, int type) {
	pthread_mutex_lock(&m_mutex);

	if(!hasPreloadedEffect(resId)) {
		// load effect raw data
		size_t length;
		char* buf = wyUtils::loadRaw(resId, &length, NULL, true);
		
		// create effect
		Effect* effect = (Effect*)wyCalloc(1, sizeof(Effect));
		effect->buffer = buf;
		effect->length = length;
		effect->resId = resId;
		effect->type = type;
		
		// add effect
		m_preloadEffects->push_back(effect);
	}

	pthread_mutex_unlock(&m_mutex);
}

void wyAudioManager_openal::preloadEffect(const char* path, bool isFile) {
	pthread_mutex_lock(&m_mutex);

	if(!hasPreloadedEffect(path)) {
		// load effect raw data
		size_t length;
		char* buf = wyUtils::loadRaw(path, isFile, &length, true);
		
		// create effect
		Effect* effect = (Effect*)wyCalloc(1, sizeof(Effect));
		effect->buffer = buf;
		effect->length = length;
		effect->path = wyUtils::copy(path);
		if(wyUtils::endsWith(path, ".wav") || wyUtils::endsWith(path, ".WAV")) {
			effect->type = FORMAT_WAV;
		} else if(wyUtils::endsWith(path, ".mp3") || wyUtils::endsWith(path, ".MP3")) {
			effect->type = FORMAT_MP3;
		} else if(wyUtils::endsWith(path, ".ogg") || wyUtils::endsWith(path, ".OGG")) {
			effect->type = FORMAT_OGG;
		}
		
		// add effect
		m_preloadEffects->push_back(effect);
	}

	pthread_mutex_unlock(&m_mutex);
}

void wyAudioManager_openal::stopEffect(int resId) {
	pthread_mutex_lock(&m_mutex);

	wyAudioPlayer* audio = getAudio(resId);
	if(audio)
		audio->stop();

	pthread_mutex_unlock(&m_mutex);
}

void wyAudioManager_openal::stopEffect(const char* path, bool isFile) {
	pthread_mutex_lock(&m_mutex);

	wyAudioPlayer* audio = getAudio(path);
	if(audio)
		audio->stop();

	pthread_mutex_unlock(&m_mutex);
}

void wyAudioManager_openal::removeAllEffects() {
	pthread_mutex_lock(&m_mutex);

	for(vector<Effect*>::iterator iter = m_preloadEffects->begin(); iter != m_preloadEffects->end(); iter++) {
		releaseEffect(*iter);
	}
	m_preloadEffects->clear();

	pthread_mutex_unlock(&m_mutex);
}

void wyAudioManager_openal::removeEffect(int resId) {
	pthread_mutex_lock(&m_mutex);

	for(vector<Effect*>::iterator iter = m_preloadEffects->begin(); iter != m_preloadEffects->end(); iter++) {
		if((*iter)->resId == resId) {
			releaseEffect(*iter);
			m_preloadEffects->erase(iter);
			break;
		}
	}

	pthread_mutex_unlock(&m_mutex);
}

void wyAudioManager_openal::removeEffect(const char* path) {
	pthread_mutex_lock(&m_mutex);

	for(vector<Effect*>::iterator iter = m_preloadEffects->begin(); iter != m_preloadEffects->end(); iter++) {
		if((*iter)->path && !strcmp((*iter)->path, path)) {
			releaseEffect(*iter);
			m_preloadEffects->erase(iter);
			break;
		}
	}

	pthread_mutex_unlock(&m_mutex);
}

void wyAudioManager_openal::setMute(bool mute) {
	m_mute = mute;

	pthread_mutex_lock(&m_mutex);
	if(m_mute) {
		for(vector<wyAudioPlayer*>::iterator iter = m_audios->begin(); iter != m_audios->end(); iter++) {
			if((*iter)->getStream()->isSingleBuffer())
				(*iter)->stop();
			else
				(*iter)->pause();
		}
	} else {
		for(vector<wyAudioPlayer*>::iterator iter = m_audios->begin(); iter != m_audios->end(); iter++) {
			if(!(*iter)->getStream()->isSingleBuffer())
				(*iter)->resume();
		}
	}
	pthread_mutex_unlock(&m_mutex);
}

bool wyAudioManager_openal::isMuted() {
	return m_mute;
}

#endif // #if BACKEND_OPENAL
