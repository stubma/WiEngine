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

#ifndef __wyAudioStream_h__
#define __wyAudioStream_h__

#include "wyObject.h"
#include "wyAssetInputStream.h"

class wyAudioStream : public wyObject {
protected:
	/// 音频文件数据流
	wyAssetInputStream* m_stream;

	/// 每个采样点的位数
	int m_bitsPerSample;

	/// 声道数
	int m_channel;

	/// 采样率
	int m_sampleRate;

protected:
	/**
	 * 跳过指定字节
	 *
	 * @param length 跳过的字节数
	 */
	virtual void skip(size_t length);

	/**
	 * 获得音频文件的一些信息, 会被setup调用, 子类必须实现这个方法以初始化类成员或进行
	 * 特定的检查
	 */
	virtual void initInfo() = 0;

public:
	/**
	 * 通过资源id创建音频流
	 *
	 * @param resId 音频文件的资源id
	 */
	wyAudioStream(int resId);

	/**
	 * 通过路径创建音频流
	 *
	 * @param path 音频文件的路径
	 * @param isFile false表示path是一个assets下的相对路径, true表示path是一个文件系统路径
	 */
	wyAudioStream(const char* path, bool isFile = false);

	/**
	 * 析构函数
	 */
	virtual ~wyAudioStream();

	/**
	 * 读指定长度的数据
	 *
	 * @param buffer 缓冲区
	 * @param length 读取的最大长度
	 * @return 实际读取长度
	 */
	virtual int read(char* buffer, size_t length);

	/**
	 * 回到数据起点
	 */
	virtual void reset();

	/**
	 * 进行初始化, 在播放音频流前必须调用一次, 该方法会调用
	 * initInfo, 子类可以在initInfo中进行特定的初始化逻辑
	 */
	void setup();

	/**
	 * Get bits per sample
	 *
	 * @return bits per sample
	 */
	int getBitsPerSample() { return m_bitsPerSample; }

	/**
	 * Get channel count
	 *
	 * @return channel count
	 */
	int getChannel() { return m_channel; }

	/**
	 * Get sample rate
	 *
	 * @return sample rate
	 */
	int getSampleRate() { return m_sampleRate; }
};

#endif // __wyAudioStream_h__

#endif // #if BACKEND_OPENSL
