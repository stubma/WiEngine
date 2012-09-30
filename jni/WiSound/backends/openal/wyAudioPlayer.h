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

#ifndef __wyAudioPlayer_h__
#define __wyAudioPlayer_h__

#include "wyAudioStream.h"
#if ANDROID || WINDOWS
    #include "AL/al.h"
    #include "AL/alc.h"
#elif IOS || MACOSX
    #import <OpenAL/al.h>
    #import <OpenAL/alc.h>
#endif

/**
 * @class wyAudioPlayer
 *
 * Audio player for background and effect music
 */
class wyAudioPlayer : public wyObject {
private:
    /// audio stream
    wyAudioStream* m_stream;
    
    /// loop count, 0 means no loop, -1 mean infinite, > 0 means loop count. by default it is zero
	int m_loop;
    
	/// true means playing
	bool m_playing;
    
	/// true means paused
	bool m_paused;
    
    /// OpenAL buffer id list
	ALuint* m_buffers;
    
    /// audio source id
	ALuint m_source;
    
	/// time elapsed after playing
	float m_renderedSeconds;
    
	/// capacity of audio buffer, in seconds
	float m_secondsPerBuffer;
    
	/// temp buffer, only used for multi-buffer mode
	char* m_tempBuffer;
    
protected:
    /**
     * Constructor
     *
     * @param stream audio stream
     */
    wyAudioPlayer(wyAudioStream* stream);
    
public:
    virtual ~wyAudioPlayer();
    
    /**
     * Create an audio player for a stream
     *
     * @param stream audio stream
     * @return audio player
     */
    static wyAudioPlayer* make(wyAudioStream* stream);
    
    /**
	 * 开始播放这个音频流
	 *
	 * @param volume 音量, 0表示最小, 1表示最大
	 */
	virtual void play(float volume);
    
	/**
	 * 停止播放这个音频流
	 */
	virtual void stop();
    
	/**
	 * 暂停播放
	 */
	virtual void pause();
    
	/**
	 * 恢复播放
	 */
	virtual void resume();
    
    /**
     * Get audio stream
     *
     * @return audio stream object
     */
    wyAudioStream* getStream() { return m_stream; }
    
    /**
	 * 是否正在播放
	 *
	 * @return true表示正在播放
	 */
	bool isPlaying() { return m_playing; }
    
	/**
	 * 是否暂停了
	 *
	 * @return true表示已经暂停
	 */
	bool isPaused() { return m_paused; }
    
	/**
	 * 是否需要循环
	 *
	 * @return true表示需要循环
	 */
	bool isLoop() { return m_loop != 0; }
    
	/**
	 * 设置音量
	 *
	 * @param volume 音量
	 */
	void setVolume(float volume);
    
    /**
	 * 填充一个缓冲区
	 *
	 * @param buffer 缓冲区id
	 * @return 成功返回true, 失败返回false
	 */
	bool fill(ALuint buffer);
    
    /**
	 * 根据音频信息得到OpenAL格式常量
	 *
	 * @return OpenAL格式常量
	 */
	ALenum getALFormat();
    
    /**
	 * 设置循环次数
	 *
	 * @param loop 0表示不循环, -1表示无限循环, 大于0表示循环次数
	 */
	void setLoopCount(int loop) { m_loop = loop; }
    
    /**
	 * 更新播放缓冲或其它状态
	 */
	void update();
};

#endif // __wyAudioPlayer_h__

#endif // #if BACKEND_OPENAL
