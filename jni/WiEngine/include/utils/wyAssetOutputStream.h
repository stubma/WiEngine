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
#ifndef __wyAssetOutputStream_h__
#define __wyAssetOutputStream_h__

#include "wyObject.h"

/**
 * @class wyAssetOutputStream
 *
 * \if English
 * A cross platform output stream implementation for writing resources
 * \else
 * 封装写文件操作
 * \endif
 */
class WIENGINE_API wyAssetOutputStream : public wyObject {
protected:
	/**
	 * \if English
	 * true indicating append file
	 * \else
	 * true表示附加文件写入
	 * \endif
	 */
	bool m_append;

	/// path
	const char* m_path;

protected:
	/**
	 * Default constructor
	 */
	wyAssetOutputStream();

	/**
	 * constructor
	 *
	 * @param path write file path
	 * @param append append file
	 */
	wyAssetOutputStream(const char* path, bool append = false);

public:
	/**
	 * \if English
	 * static constructor
	 *
	 * @param path write file path
	 * @param append append file
	 * @return \link wyAssetOutputStream wyAssetOutputStream\endlink
	 * \else
	 * 静态构造函数
	 *
	 * @param path 写入文件完整路径
	 * @param append true为追加模式,默认false
	 * @return \link wyAssetOutputStream wyAssetOutputStream\endlink
	 * \endif
	 */
	static wyAssetOutputStream* make(const char* path, bool append = false);

	virtual ~wyAssetOutputStream();

	/**
	 * \if English
	 * open asset
	 *
	 * @return true means successful
	 * \else
	 * 打开相关的Asset资源
	 *
	 * @return true表示打开成功
	 * \endif
	 */
	virtual bool open();

	/**
	 * \if English
	 * close asset
	 * \else
	 * 关闭Asset
	 * \endif
	 */
	virtual void close() = 0;

	/**
	 * \if English
	 * write char data
	 *
	 * @param data char data
	 * @param len character count in \c data
	 * @return byte write actually, -1 means error
	 * \else
	 * 写入内容
	 *
	 * @param data 写入内容
	 * @param len \c data中字节个数
	 * @return 实际写入的字节块数, -1表示出错
	 * \endif
	 */
	virtual ssize_t write(const char* data, size_t len) = 0;

	/**
	 * \if English
	 * write int data
	 *
	 * @param data int data
	 * @param len count of integer in \c data
	 * @return byte write actually, -1 means error
	 * \else
	 * 写入int内容
	 *
	 * @param data 写入int内容
	 * @param len \c data中整数的个数
	 * @return 实际写入的字节块数, -1表示出错
	 * \endif
	 */
	virtual ssize_t write(const int* data, size_t len) = 0;
    
    /**
	 * \if English
	 * get offset from start to current position
	 *
	 * @return offset from start to current position
	 * \else
	 * 得到当前读取位置相对于头部的偏移
	 *
	 * @return 当前读取位置相对于头部的偏移
	 * \endif
	 */
	virtual size_t getPosition() = 0;

	/**
	 * \if English
	 * change pointer position
	 *
	 * @param offset offset
	 * @param mode seek mode
	 * @return new offset after changed
	 * \else
	 * 改变指针位置
	 *
	 * @param offset 偏移
	 * @param mode SEEK_CUR表示从当前位置计算, SEEK_SET表示从开头计算, SEEK_END表示从结尾处计算
	 * @return 修改后的实际位置
	 * \endif
	 */
	virtual size_t seek(int offset, int mode) = 0;

	/**
	 * \if English
	 * Get asset output path, caller should not release it
	 * \else
	 * 得到资源输出路径, 调用者不需要负责释放
	 * \endif
	 */
	const char* getPath() { return m_path; }
};

#endif // __wyAssetOutputStream_h__
