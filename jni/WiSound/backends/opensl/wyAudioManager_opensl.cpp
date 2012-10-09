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
#if BACKEND_OPENSL

#include "wyAudioManager_opensl.h"
#include "wyInit.h"
#include "wyLog.h"
#include "wyTypes.h"
#include "wyUtils.h"
#include <fcntl.h>
#include "wyMp3Stream.h"
#include "wyOggStream.h"
#include "wyWavStream.h"

// singleton
wyAudioManager_opensl* gAudioManager = NULL;

// AAL interface
extern wyAAL gAAL;

// chunk size to read
#define BUFFER_SIZE 40960

wyAudioManager_opensl::wyAudioManager_opensl() :
		m_backgroundVolume(1.f),
		m_effectVolume(1.f),
		m_mute(false),
		m_playing(false),
		m_paused(false),
		m_bgResId(0),
		m_repeatCount(0),
		m_bgPath(NULL),
		m_engineObj(NULL),
		m_engine(NULL),
		m_mixerObj(NULL),
		m_mixer(NULL),
		m_bgPlayerObj(NULL),
		m_bgPlayer(NULL),
		m_bgSeeker(NULL),
		m_bgVolumer(NULL),
		m_maxEffects(5) {
	// create mutex
	pthread_mutexattr_t attr;
	pthread_mutexattr_init(&attr);
	pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE);
	pthread_mutex_init(&m_mutex, &attr);
	pthread_mutexattr_destroy(&attr);

	// create engine
	createEngine();

	// other member
	m_effectPlayers = WYNEW vector<EffectPlayer*>();
	m_effectPlayers->reserve(m_maxEffects);
	m_effectPlayerCache = WYNEW vector<EffectPlayer*>();
	m_effectPlayerCache->reserve(m_maxEffects);
	m_effects = WYNEW vector<Effect*>();
	m_effects->reserve(30);

	// init mpg123
	mpg123_init();
}

wyAudioManager_opensl::~wyAudioManager_opensl() {
	// free bg path string
	if(m_bgPath) {
		wyFree((void*)m_bgPath);
		m_bgPath = NULL;
	}

	// release player
	releaseBgPlayer();

	// release effect players
	for(vector<EffectPlayer*>::iterator iter = m_effectPlayerCache->begin(); iter != m_effectPlayerCache->end(); iter++) {
		releaseEffectPlayer(*iter);
	}
	WYDELETE(m_effectPlayerCache);
	for(vector<EffectPlayer*>::iterator iter = m_effectPlayers->begin(); iter != m_effectPlayers->end(); iter++) {
		releaseEffectPlayer(*iter);
	}
	WYDELETE(m_effectPlayers);

	// release effects
	for(vector<Effect*>::iterator iter = m_effects->begin(); iter != m_effects->end(); iter++) {
		releaseEffect(*iter);
	}
	WYDELETE(m_effects);

	// release engine
	releaseEngine();

	// clear mpg123
	mpg123_exit();

	// destroy mutex
	pthread_mutex_destroy(&m_mutex);
}

wyAudioManager* wyAudioManager::getInstance() {
	if (gAudioManager == NULL) {
		gAudioManager = WYNEW wyAudioManager_opensl();
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

void wyAudioManager_opensl::createEngine() {
	// create engine object
    SLresult result;
    result = slCreateEngine(&m_engineObj, 0, NULL, 0, NULL, NULL);
    if(SL_RESULT_SUCCESS != result) {
    	LOGE("Failed to create OpenSL engine object");
    	return;
    }

    // realize the engine
    result = (*m_engineObj)->Realize(m_engineObj, SL_BOOLEAN_FALSE);
    if(SL_RESULT_SUCCESS != result) {
    	LOGE("Failed to realize OpenSL engine object");
    	return;
    }

    // get the engine interface, which is needed in order to create other objects
    result = (*m_engineObj)->GetInterface(m_engineObj, SL_IID_ENGINE, &m_engine);
    if(SL_RESULT_SUCCESS != result) {
    	LOGE("Failed to get OpenSL engine interface");
    	return;
    }

    // create output mix object, with environmental reverb specified as a non-required interface
    const SLInterfaceID ids[1] = { SL_IID_ENVIRONMENTALREVERB };
    const SLboolean req[1] = { SL_BOOLEAN_FALSE };
    result = (*m_engine)->CreateOutputMix(m_engine, &m_mixerObj, 1, ids, req);
    if(SL_RESULT_SUCCESS != result) {
    	LOGE("Failed to create OpenSL mixer object");
    	return;
    }

    // realize the output mix
    result = (*m_mixerObj)->Realize(m_mixerObj, SL_BOOLEAN_FALSE);
    if(SL_RESULT_SUCCESS != result) {
    	LOGE("Failed to realize OpenSL mixer object");
    	return;
    }

    // get the environmental reverb interface
    // this could fail if the environmental reverb effect is not available,
    // either because the feature is not present, excessive CPU load, or
    // the required MODIFY_AUDIO_SETTINGS permission was not requested and granted
    result = (*m_mixerObj)->GetInterface(m_mixerObj, SL_IID_ENVIRONMENTALREVERB, &m_mixer);
    if (SL_RESULT_SUCCESS == result) {
    	SLEnvironmentalReverbSettings reverbSettings = SL_I3DL2_ENVIRONMENT_PRESET_STONECORRIDOR;
        result = (*m_mixer)->SetEnvironmentalReverbProperties(m_mixer, &reverbSettings);
    }
}

void wyAudioManager_opensl::releaseEngine() {
    // destroy output mix object, and invalidate all associated interfaces
    if (m_mixerObj) {
        (*m_mixerObj)->Destroy(m_mixerObj);
        m_mixerObj = NULL;
        m_mixer = NULL;
    }

    // destroy engine object, and invalidate all associated interfaces
    if (m_engineObj) {
        (*m_engineObj)->Destroy(m_engineObj);
        m_engineObj = NULL;
        m_engine = NULL;
    }
}

void wyAudioManager_opensl::createBgPlayer(int resourceId, int type) {
	if(m_bgPlayerObj)
		return;

	size_t fd = 0;
	size_t length;
	size_t start;
	float scale;
	gAAL.getResFD(resourceId, &fd, &start, &length, &scale);

	// if success, create player
	// if failed, nothing
	if(fd != 0) {
		SLresult result;

		// what type?
		SLuint32 sltype;
		switch(type) {
			case FORMAT_MP3:
				sltype = SL_CONTAINERTYPE_MP3;
				break;
			case FORMAT_OGG:
				sltype = SL_CONTAINERTYPE_OGG;
				break;
			case FORMAT_WAV:
				sltype = SL_CONTAINERTYPE_WAV;
				break;
		}

		// create
		createBgPlayer(fd, start, length, sltype);
	}
}

void wyAudioManager_opensl::createBgPlayer(const char* path, bool isFile) {
	if(m_bgPlayerObj)
		return;

	size_t fd = 0;
	size_t length;
	size_t start;
	if(isFile) {
		int tmpfd = open(path, O_RDONLY);
		if(tmpfd == -1) {
			LOGE("Failed to open file %s", path);
			return;
		}

		start = 0;
		length = lseek(tmpfd, 0, SEEK_END);
		fd = dup(tmpfd);
		close(tmpfd);
	} else {
		gAAL.getAssetFD(path, &fd, &start, &length);
	}

	SLuint32 type;
	if(wyUtils::endsWith(path, ".wav") || wyUtils::endsWith(path, ".WAV")) {
		type = SL_CONTAINERTYPE_WAV;
	} else if(wyUtils::endsWith(path, ".mp3") || wyUtils::endsWith(path, ".MP3")) {
		type = SL_CONTAINERTYPE_MP3;
	} else if(wyUtils::endsWith(path, ".ogg") || wyUtils::endsWith(path, ".OGG")) {
		type = SL_CONTAINERTYPE_OGG;
	} else {
		LOGW("Unsupported audio type: %s", path);
		return;
	}

	// create
	createBgPlayer(fd, start, length, type);
}

void wyAudioManager_opensl::createBgPlayer(size_t fd, size_t start, size_t length, SLuint32 type) {
    // configure audio source
    SLDataLocator_AndroidFD slFD = { SL_DATALOCATOR_ANDROIDFD, fd, start, length};
    SLDataFormat_MIME slMime = { SL_DATAFORMAT_MIME, NULL, type };
    SLDataSource slSource = { &slFD, &slMime };

    // configure audio sink
    SLDataLocator_OutputMix slMix = { SL_DATALOCATOR_OUTPUTMIX, m_mixerObj };
    SLDataSink slSink = { &slMix, NULL };

    // create audio player
    const SLInterfaceID ids[2] = { SL_IID_SEEK, SL_IID_VOLUME };
    const SLboolean req[2] = {SL_BOOLEAN_TRUE, SL_BOOLEAN_TRUE};
    SLresult result = (*m_engine)->CreateAudioPlayer(m_engine, &m_bgPlayerObj, &slSource, &slSink, 2, ids, req);
    if(SL_RESULT_SUCCESS != result) {
    	m_bgPlayerObj = NULL;
    	LOGE("Failed to create background music player object");
    	return;
    }

    // realize the player
    result = (*m_bgPlayerObj)->Realize(m_bgPlayerObj, SL_BOOLEAN_FALSE);
    if(SL_RESULT_SUCCESS != result) {
    	releaseBgPlayer();
    	LOGE("Failed to realize background music player object");
    	return;
    }

    // get the play interface
    result = (*m_bgPlayerObj)->GetInterface(m_bgPlayerObj, SL_IID_PLAY, &m_bgPlayer);
    if(SL_RESULT_SUCCESS != result) {
    	releaseBgPlayer();
    	LOGE("Failed to get background music player interface");
    	return;
    }

    // register callback
    result = (*m_bgPlayer)->RegisterCallback(m_bgPlayer, bgPlayCallback, this);
    if(SL_RESULT_SUCCESS != result) {
    	releaseBgPlayer();
    	LOGE("Failed to register background playing callback");
    	return;
    }

    // set event mask, we want receive playing completed event
    result = (*m_bgPlayer)->SetCallbackEventsMask(m_bgPlayer, SL_PLAYEVENT_HEADATEND);
    if(SL_RESULT_SUCCESS != result) {
    	releaseBgPlayer();
    	LOGE("Failed to set background playing callback event mask");
    	return;
    }

    // get seek interface
    result = (*m_bgPlayerObj)->GetInterface(m_bgPlayerObj, SL_IID_SEEK, &m_bgSeeker);
    if(SL_RESULT_SUCCESS != result) {
    	releaseBgPlayer();
    	LOGE("Failed to get background player seek interface");
    	return;
    }

    // enable looping
    result = (*m_bgSeeker)->SetLoop(m_bgSeeker, SL_BOOLEAN_TRUE, 0, SL_TIME_UNKNOWN);
    if(SL_RESULT_SUCCESS != result) {
    	releaseBgPlayer();
    	LOGE("Failed to set loop of background player");
    	return;
    }

    // get volume interface
    result = (*m_bgPlayerObj)->GetInterface(m_bgPlayerObj, SL_IID_VOLUME, &m_bgVolumer);
    if(SL_RESULT_SUCCESS != result) {
    	releaseBgPlayer();
    	LOGE("Failed to get background player volume interface");
    	return;
    }
}

void wyAudioManager_opensl::releaseBgPlayer() {
	if(m_bgPlayerObj) {
		(*m_bgPlayerObj)->Destroy(m_bgPlayerObj);
		m_bgPlayerObj = NULL;
		m_bgPlayer = NULL;
		m_bgSeeker = NULL;
		m_bgVolumer = NULL;
	}
}

SLuint32 wyAudioManager_opensl::getSampleRate(int sampleRate) {
	switch(sampleRate) {
		case 8000:
			return SL_SAMPLINGRATE_8;
		case 11025:
			return SL_SAMPLINGRATE_11_025;
		case 12000:
			return SL_SAMPLINGRATE_12;
		case 16000:
			return SL_SAMPLINGRATE_16;
		case 22050:
			return SL_SAMPLINGRATE_22_05;
		case 24000:
			return SL_SAMPLINGRATE_24;
		case 32000:
			return SL_SAMPLINGRATE_32;
		case 44100:
			return SL_SAMPLINGRATE_44_1;
		case 48000:
			return SL_SAMPLINGRATE_48;
		case 64000:
			return SL_SAMPLINGRATE_64;
		case 88200:
			return SL_SAMPLINGRATE_88_2;
		case 96000:
			return SL_SAMPLINGRATE_96;
		case 192000:
			return SL_SAMPLINGRATE_192;
		default:
			return SL_SAMPLINGRATE_8;
	}
}

SLuint32 wyAudioManager_opensl::getBitsPerSample(int bps) {
	switch(bps) {
		case 8:
			return SL_PCMSAMPLEFORMAT_FIXED_8;
		case 16:
			return SL_PCMSAMPLEFORMAT_FIXED_16;
		case 20:
			return SL_PCMSAMPLEFORMAT_FIXED_20;
		case 24:
			return SL_PCMSAMPLEFORMAT_FIXED_24;
		case 28:
			return SL_PCMSAMPLEFORMAT_FIXED_28;
		case 32:
			return SL_PCMSAMPLEFORMAT_FIXED_32;
		default:
			return SL_PCMSAMPLEFORMAT_FIXED_16;
	}
}

wyAudioManager_opensl::EffectPlayer* wyAudioManager_opensl::createEffectPlayer(Effect* effect) {
    SLresult result;

    // get cached effect player
    EffectPlayer* ep = NULL;
	if(m_effectPlayerCache->size() > 0) {
		ep = m_effectPlayerCache->back();
		m_effectPlayerCache->pop_back();
	}

	// if no cached player, create it
	if(!ep) {
		// allocate memory
		ep = (EffectPlayer*)wyCalloc(1, sizeof(EffectPlayer));

	    // configure audio source
	    SLDataLocator_AndroidSimpleBufferQueue slQueue = { SL_DATALOCATOR_ANDROIDSIMPLEBUFFERQUEUE, 2 };
	    SLDataFormat_PCM slFormat = {
	    		SL_DATAFORMAT_PCM,
	    		1, // XXX: if we use 2, opensl fails, don't know why
	    		getSampleRate(effect->sampleRate),
	    		getBitsPerSample(effect->bitsPerSample),
	    		getBitsPerSample(effect->bitsPerSample),
	    		SL_SPEAKER_FRONT_CENTER,
	    		SL_BYTEORDER_LITTLEENDIAN
	    };
	    SLDataSource slSource = { &slQueue, &slFormat };

	    // configure audio sink
	    SLDataLocator_OutputMix slMix = { SL_DATALOCATOR_OUTPUTMIX, m_mixerObj };
	    SLDataSink slSink = { &slMix, NULL };

	    // create audio player
	    const SLInterfaceID ids[2] = { SL_IID_BUFFERQUEUE, SL_IID_VOLUME };
	    const SLboolean req[2] = { SL_BOOLEAN_TRUE, SL_BOOLEAN_TRUE };
	    result = (*m_engine)->CreateAudioPlayer(m_engine, &ep->playerObj, &slSource, &slSink, 2, ids, req);
	    if(SL_RESULT_SUCCESS != result) {
	    	LOGE("Failed to create effect player object: %d", result);
	    	releaseEffectPlayer(ep);
	    	return NULL;
	    }

	    // realize the player
	    result = (*ep->playerObj)->Realize(ep->playerObj, SL_BOOLEAN_FALSE);
	    if(SL_RESULT_SUCCESS != result) {
	    	LOGE("Failed to realize effect player object: %d", result);
	    	releaseEffectPlayer(ep);
	    	return NULL;
	    }

	    // get the play interface
	    result = (*ep->playerObj)->GetInterface(ep->playerObj, SL_IID_PLAY, &ep->player);
	    if(SL_RESULT_SUCCESS != result) {
	    	LOGE("Failed to get effect player interface: %d", result);
	    	releaseEffectPlayer(ep);
	    	return NULL;
	    }

	    // get the buffer queue interface
	    result = (*ep->playerObj)->GetInterface(ep->playerObj, SL_IID_BUFFERQUEUE, &ep->queue);
	    if(SL_RESULT_SUCCESS != result) {
	    	LOGE("Failed to get effect player buffer queue interface: %d", result);
	    	releaseEffectPlayer(ep);
	    	return NULL;
	    }

	    // register callback on the buffer queue
	    result = (*ep->queue)->RegisterCallback(ep->queue, effectPlayCallback, this);
	    if(SL_RESULT_SUCCESS != result) {
	    	LOGE("Failed to register effect player callback: %d", result);
	    	releaseEffectPlayer(ep);
	    	return NULL;
	    }

	    // get the volume interface
	    result = (*ep->playerObj)->GetInterface(ep->playerObj, SL_IID_VOLUME, &ep->volumer);
	    if(SL_RESULT_SUCCESS != result) {
	    	LOGE("Failed to get effect player volume interface: %d", result);
	    	releaseEffectPlayer(ep);
	    	return NULL;
	    }
	}

	// set info
	ep->effect = effect;

    // enqueue buffer
    result = (*ep->queue)->Enqueue(ep->queue, effect->buffer, effect->length);
    if(SL_RESULT_SUCCESS != result) {
    	LOGE("Failed to enqueue effect data buffer: %d", result);
    	releaseEffectPlayer(ep);
    	return NULL;
    }

    // set volume
    float attenuation = 100 - m_effectVolume * 100;
    float millibel = attenuation * -50;
	result = (*ep->volumer)->SetVolumeLevel(ep->volumer, (int)millibel);
    if(SL_RESULT_SUCCESS != result) {
    	LOGE("Failed to set effect volume: %d", result);
    	releaseEffectPlayer(ep);
    	return NULL;
    }

    // playing
    result = (*ep->player)->SetPlayState(ep->player, SL_PLAYSTATE_PLAYING);
    if(SL_RESULT_SUCCESS != result) {
    	LOGE("Failed to play effect: %d", result);
    	releaseEffectPlayer(ep);
    	return NULL;
    }

    return ep;
}

void wyAudioManager_opensl::releaseEffectPlayer(EffectPlayer* player) {
	if(player->playerObj) {
		(*player->playerObj)->Destroy(player->playerObj);
	}
	wyFree(player);
}

void wyAudioManager_opensl::releaseEffect(Effect* effect) {
	if(effect->path) {
		wyFree((void*)effect->path);
	}
	if(effect->buffer) {
		wyFree((void*)effect->buffer);
	}
	wyFree(effect);
}

wyAudioManager_opensl::Effect* wyAudioManager_opensl::getEffect(int resId) {
	for(vector<Effect*>::iterator iter = m_effects->begin(); iter != m_effects->end(); iter++) {
		if((*iter)->resId == resId) {
			return *iter;
		}
	}

	return NULL;
}

wyAudioManager_opensl::Effect* wyAudioManager_opensl::getEffect(const char* path) {
	for(vector<Effect*>::iterator iter = m_effects->begin(); iter != m_effects->end(); iter++) {
		if((*iter)->path && !strcmp(path, (*iter)->path)) {
			return *iter;
		}
	}

	return NULL;
}

wyAudioManager_opensl::EffectPlayer* wyAudioManager_opensl::getEffectPlayer(SLAndroidSimpleBufferQueueItf queue) {
	for(vector<EffectPlayer*>::iterator iter = m_effectPlayers->begin(); iter != m_effectPlayers->end(); iter++) {
		if((*iter)->queue == queue) {
			return *iter;
		}
	}

	return NULL;
}

void wyAudioManager_opensl::preloadBackgroundMusic(int resId, int type) {
	// do nothing
}

void wyAudioManager_opensl::preloadBackgroundMusic(const char* path, bool isFile) {
	// do nothing
}

void wyAudioManager_opensl::bgPlayCallback(SLPlayItf caller, void* pContext, SLuint32 event) {
	wyAudioManager_opensl* am = (wyAudioManager_opensl*)pContext;
	switch(event) {
		case SL_PLAYEVENT_HEADATEND:
			if(am->m_repeatCount > 0) {
				am->m_repeatCount--;
			} else if(am->m_repeatCount == 0) {
				am->stopBackgroundMusic();
			}
			break;
	}
}

void wyAudioManager_opensl::playBackgroundMusic(int resourceId, int type, int repeatCount) {
	pthread_mutex_lock(&m_mutex);

	// is this background music already in playing?
	if(m_bgResId == resourceId) {
		// yes, so is it playing?
		if(m_bgPlayerObj && !m_playing) {
			SLresult result = (*m_bgPlayer)->SetPlayState(m_bgPlayer, SL_PLAYSTATE_PLAYING);
	        m_playing = SL_RESULT_SUCCESS == result;
	        if(m_playing)
	        	m_paused = false;
		}

		pthread_mutex_unlock(&m_mutex);
		return;
	}

	// ok, not playing, now reset cached background music info
	m_bgResId = 0;
	if(m_bgPath) {
		wyFree((void*)m_bgPath);
		m_bgPath = NULL;
	}

	// then, we need release old player object
	releaseBgPlayer();

	// reset flag
	m_playing = false;
	m_paused = false;

	// create new player for the new background music
	createBgPlayer(resourceId, type);

	// if success, play
	if(m_bgPlayerObj) {
        // set the player's state
		SLresult result = (*m_bgPlayer)->SetPlayState(m_bgPlayer, SL_PLAYSTATE_PLAYING);
        m_playing = SL_RESULT_SUCCESS == result;

        // if in playing, cache info
        if(m_playing) {
        	m_bgResId = resourceId;
        	m_repeatCount = repeatCount;
        }
	}

	pthread_mutex_unlock(&m_mutex);
}

void wyAudioManager_opensl::playBackgroundMusic(const char* path, bool isFile, int repeatCount) {
	pthread_mutex_lock(&m_mutex);

	// is this background music already in playing?
	if(m_bgPath && !strcmp(path, m_bgPath)) {
		// yes, so is it playing?
		if(m_bgPlayerObj && !m_playing) {
			SLresult result = (*m_bgPlayer)->SetPlayState(m_bgPlayer, SL_PLAYSTATE_PLAYING);
	        m_playing = SL_RESULT_SUCCESS == result;
	        if(m_playing)
	        	m_paused = false;
		}

		pthread_mutex_unlock(&m_mutex);
		return;
	}

	// ok, not playing, now reset cached background music info
	m_bgResId = 0;
	if(m_bgPath) {
		wyFree((void*)m_bgPath);
		m_bgPath = NULL;
	}

	// then, we need release old player object
	releaseBgPlayer();

	// reset flag
	m_playing = false;
	m_paused = false;

	// create new player for the new background music
	createBgPlayer(path, isFile);

	// if success, play
	if(m_bgPlayerObj) {
        // set the player's state
		SLresult result = (*m_bgPlayer)->SetPlayState(m_bgPlayer, SL_PLAYSTATE_PLAYING);
        m_playing = SL_RESULT_SUCCESS == result;

        // if in playing, cache info
        if(m_playing) {
        	m_bgPath = wyUtils::copy(path);
        	m_repeatCount = repeatCount;
        }
	}

	pthread_mutex_unlock(&m_mutex);
}

void wyAudioManager_opensl::stopBackgroundMusic() {
	pthread_mutex_lock(&m_mutex);

	// if is playing, stop it
	if(m_bgPlayerObj && m_playing) {
		SLresult result = (*m_bgPlayer)->SetPlayState(m_bgPlayer, SL_PLAYSTATE_STOPPED);
        m_playing = SL_RESULT_SUCCESS != result;
        if(!m_playing)
        	m_paused = false;
	}

	pthread_mutex_unlock(&m_mutex);
}

bool wyAudioManager_opensl::isBackgroundPlaying() {
	return m_playing;
}

bool wyAudioManager_opensl::isBackgroundMusicPaused() {
	return m_paused;
}

void wyAudioManager_opensl::pauseBackgroundMusic() {
	pthread_mutex_lock(&m_mutex);

	if(m_bgPlayerObj && m_playing && !m_paused) {
		SLresult result = (*m_bgPlayer)->SetPlayState(m_bgPlayer, SL_PLAYSTATE_PAUSED);
        m_paused = SL_RESULT_SUCCESS == result;
	}

	pthread_mutex_unlock(&m_mutex);
}

void wyAudioManager_opensl::resumeBackgroundMusic() {
	pthread_mutex_lock(&m_mutex);

	if(m_bgPlayerObj && m_playing && m_paused) {
		SLresult result = (*m_bgPlayer)->SetPlayState(m_bgPlayer, SL_PLAYSTATE_PLAYING);
        m_paused = SL_RESULT_SUCCESS != result;
	}

	pthread_mutex_unlock(&m_mutex);
}

void wyAudioManager_opensl::setBackgroundVolume(float volume) {
	pthread_mutex_lock(&m_mutex);

	if(m_bgVolumer) {
		if(m_mute) {
			m_backgroundVolume = volume;
		} else {
			// calculate mB and set it
			SLresult result;
	        float attenuation = 100 - volume * 100;
	        float millibel = attenuation * -50;
			result = (*m_bgVolumer)->SetVolumeLevel(m_bgVolumer, (int)millibel);
			if(result == SL_RESULT_SUCCESS)
				m_backgroundVolume = volume;
		}
	}

	pthread_mutex_unlock(&m_mutex);
}

void wyAudioManager_opensl::setEffectVolume(float volume) {
	pthread_mutex_lock(&m_mutex);

	if(m_effectVolume != volume) {
		m_effectVolume = volume;
	}

	pthread_mutex_unlock(&m_mutex);
}

void wyAudioManager_opensl::recycleEffectPlayer(EffectPlayer* ep) {
	Effect* effect = ep->effect;

	// remove from vector
	for(vector<EffectPlayer*>::iterator iter = m_effectPlayers->begin(); iter != m_effectPlayers->end(); iter++) {
		if(*iter == ep) {
			m_effectPlayers->erase(iter);
			break;
		}
	}

	// reset player
	ep->effect = NULL;

	// clear buffer in queue
	(*ep->queue)->Clear(ep->queue);

	// push back to cache
	m_effectPlayerCache->push_back(ep);
}

void wyAudioManager_opensl::recycleEffectPlayer(vector<EffectPlayer*>::iterator iter) {
	EffectPlayer* ep = (EffectPlayer*)*iter;
	Effect* effect = ep->effect;

	// remove from vector
	m_effectPlayers->erase(iter);

	// reset player
	ep->effect = NULL;

	// clear buffer in queue
	(*ep->queue)->Clear(ep->queue);

	// push back to cache
	m_effectPlayerCache->push_back(ep);
}

void wyAudioManager_opensl::effectPlayCallback(SLAndroidSimpleBufferQueueItf queue, void* context) {
	wyAudioManager_opensl* am = (wyAudioManager_opensl*)context;

	pthread_mutex_lock(&am->m_mutex);

	// remove player from current list
	EffectPlayer* ep = am->getEffectPlayer(queue);
	if(ep) {
		am->recycleEffectPlayer(ep);
	}

	pthread_mutex_unlock(&am->m_mutex);
}

void wyAudioManager_opensl::playEffect(int resId, int type) {
	pthread_mutex_lock(&m_mutex);

	// ensure effect is loaded
	preloadEffect(resId, type);

	// go ahead if it doesn't reach max allowed effects
	if(m_effectPlayers->size() < m_maxEffects) {
		// get effect
		Effect* effect = getEffect(resId);

		// create effect player
		EffectPlayer* ep = createEffectPlayer(effect);

		// add to vector
		if(ep)
			m_effectPlayers->push_back(ep);
	}

	pthread_mutex_unlock(&m_mutex);
}

void wyAudioManager_opensl::playEffect(const char* path, bool isFile) {
	pthread_mutex_lock(&m_mutex);

	// ensure effect is loaded
	preloadEffect(path, isFile);

	// go ahead if it doesn't reach max allowed effects
	if(m_effectPlayers->size() < m_maxEffects) {
		// get effect
		Effect* effect = getEffect(path);

		// create effect player
		EffectPlayer* ep = createEffectPlayer(effect);

		// add to vector
		if(ep)
			m_effectPlayers->push_back(ep);
	}

	pthread_mutex_unlock(&m_mutex);
}

void wyAudioManager_opensl::preloadEffect(int resId, int type) {
	pthread_mutex_lock(&m_mutex);

	// is preloaded already?
	Effect* effect = getEffect(resId);
	if(!effect) {
		// create effect
		effect = (Effect*)wyCalloc(1, sizeof(Effect));

		// get stream
		wyAudioStream* stream = NULL;
		switch(type) {
			case FORMAT_MP3:
				stream = WYNEW wyMp3Stream(resId);
				break;
			case FORMAT_OGG:
				stream = WYNEW wyOggStream(resId);
				break;
			case FORMAT_WAV:
				stream = WYNEW wyWavStream(resId);
				break;
			default:
				LOGW("Unsupported audio type: %d", type);
				pthread_mutex_unlock(&m_mutex);
				return;
		}

		// setup stream
		stream->setup();

		// read until no data
		char* buf = (char*)wyMalloc(BUFFER_SIZE * sizeof(char));
		int bufSize = BUFFER_SIZE;
		int total = 0;
		int readLen = 0;
		while((readLen = stream->read(buf + total, BUFFER_SIZE)) > 0) {
			total += readLen;
			if(total + BUFFER_SIZE > bufSize) {
				buf = (char*)wyRealloc(buf, bufSize * 2);
				bufSize *= 2;
			}
		}

		// save in effect
		effect->resId = resId;
		effect->buffer = buf;
		effect->length = total;
		effect->channel = stream->getChannel();
		effect->sampleRate = stream->getSampleRate();
		effect->bitsPerSample = stream->getBitsPerSample();

		// close stream
		stream->release();

		// add to vector
		m_effects->push_back(effect);
	}

	pthread_mutex_unlock(&m_mutex);
}

void wyAudioManager_opensl::preloadEffect(const char* path, bool isFile) {
	pthread_mutex_lock(&m_mutex);

	// is preloaded already?
	Effect* effect = getEffect(path);
	if(!effect) {
		// create effect
		effect = (Effect*)wyCalloc(1, sizeof(Effect));

		// get stream
		wyAudioStream* stream = NULL;
		if(wyUtils::endsWith(path, ".wav") || wyUtils::endsWith(path, ".WAV")) {
			stream = WYNEW wyWavStream(path, isFile);
		} else if(wyUtils::endsWith(path, ".mp3") || wyUtils::endsWith(path, ".MP3")) {
			stream = WYNEW wyMp3Stream(path, isFile);
		} else if(wyUtils::endsWith(path, ".ogg") || wyUtils::endsWith(path, ".OGG")) {
			stream = WYNEW wyOggStream(path, isFile);
		} else {
			LOGW("Unsupported audio type: %s", path);
			pthread_mutex_unlock(&m_mutex);
			return;
		}

		// setup stream
		stream->setup();

		// read until no data
		char* buf = (char*)wyMalloc(BUFFER_SIZE * sizeof(char));
		int bufSize = BUFFER_SIZE;
		int total = 0;
		int readLen = 0;
		while((readLen = stream->read(buf + total, BUFFER_SIZE)) > 0) {
			total += readLen;
			if(total + BUFFER_SIZE > bufSize) {
				buf = (char*)wyRealloc(buf, bufSize * 2);
				bufSize *= 2;
			}
		}

		// save in effect
		effect->path = wyUtils::copy(path);
		effect->buffer = buf;
		effect->length = total;
		effect->channel = stream->getChannel();
		effect->sampleRate = stream->getSampleRate();
		effect->bitsPerSample = stream->getBitsPerSample();

		// close stream
		stream->release();

		// add to vector
		m_effects->push_back(effect);
	}

	pthread_mutex_unlock(&m_mutex);
}

void wyAudioManager_opensl::stopEffect(int resourceId) {
	pthread_mutex_lock(&m_mutex);

	for(vector<EffectPlayer*>::iterator iter = m_effectPlayers->begin(); iter != m_effectPlayers->end();) {
		EffectPlayer* ep = (EffectPlayer*)*iter;
		if(ep->effect->resId == resourceId) {
		    (*ep->player)->SetPlayState(ep->player, SL_PLAYSTATE_STOPPED);
		    recycleEffectPlayer(iter);
		} else {
			iter++;
		}
	}

	pthread_mutex_unlock(&m_mutex);
}

void wyAudioManager_opensl::stopEffect(const char* path, bool isFile) {
	pthread_mutex_lock(&m_mutex);

	for(vector<EffectPlayer*>::iterator iter = m_effectPlayers->begin(); iter != m_effectPlayers->end();) {
		EffectPlayer* ep = (EffectPlayer*)*iter;
		if(ep->effect->path && !strcmp(ep->effect->path, path)) {
		    (*ep->player)->SetPlayState(ep->player, SL_PLAYSTATE_STOPPED);
		    recycleEffectPlayer(iter);
		} else {
			iter++;
		}
	}

	pthread_mutex_unlock(&m_mutex);
}

void wyAudioManager_opensl::removeAllEffects() {
	pthread_mutex_lock(&m_mutex);

	// stop all effects first
	for(vector<EffectPlayer*>::iterator iter = m_effectPlayers->begin(); iter != m_effectPlayers->end(); iter++) {
		releaseEffectPlayer(*iter);
	}
	m_effectPlayers->clear();

	// remove effect then
	for(vector<Effect*>::iterator iter = m_effects->begin(); iter != m_effects->end(); iter++) {
		releaseEffect(*iter);
	}
	m_effects->clear();

	pthread_mutex_unlock(&m_mutex);
}

void wyAudioManager_opensl::removeEffect(int resId) {
	pthread_mutex_lock(&m_mutex);

	// stop first
	stopEffect(resId);

	// remove effect then
	for(vector<Effect*>::iterator iter = m_effects->begin(); iter != m_effects->end(); iter++) {
		if((*iter)->resId == resId) {
			releaseEffect(*iter);
			m_effects->erase(iter);
			break;
		}
	}

	pthread_mutex_unlock(&m_mutex);
}

void wyAudioManager_opensl::removeEffect(const char* path) {
	pthread_mutex_lock(&m_mutex);

	// stop first
	stopEffect(path);

	// remove effect then
	for(vector<Effect*>::iterator iter = m_effects->begin(); iter != m_effects->end(); iter++) {
		if((*iter)->path && !strcmp(path, (*iter)->path)) {
			releaseEffect(*iter);
			m_effects->erase(iter);
			break;
		}
	}

	pthread_mutex_unlock(&m_mutex);
}

void wyAudioManager_opensl::setMute(bool mute) {
	pthread_mutex_lock(&m_mutex);

	if(m_bgVolumer) {
		if(m_mute != mute) {
			// calculate mB and set it
			SLresult result;
	        float attenuation = 100 - (mute ? 0 : m_backgroundVolume) * 100;
	        float millibel = attenuation * -50;
			result = (*m_bgVolumer)->SetVolumeLevel(m_bgVolumer, (int)millibel);
			if(result == SL_RESULT_SUCCESS)
				m_mute = mute;
		}
	}

	pthread_mutex_unlock(&m_mutex);
}

bool wyAudioManager_opensl::isMuted() {
	return m_mute;
}

#endif // #if BACKEND_OPENSL
