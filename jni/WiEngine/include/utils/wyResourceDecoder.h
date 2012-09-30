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
#ifndef __wyResourceDecoder_h__
#define __wyResourceDecoder_h__

#include "wyObject.h"

/**
 * @class wyResourceDecoder
 *
 * \if English
 * Decoder of resource, it will be called before WiEngine parses raw
 * data of a resource. You can install your decoder to protect your game
 * design from decompiling app package. To set a decoder, check \link wyDirector wyDirector\endlink
 * API doc.
 * \else
 * 资源解码器, 它会在WiEngine开始解析一个资源的数据之前调用. 这是一个虚基类, 如果你需要
 * 保护自己游戏的资源, 你可以对资源文件进行处理, 然后实现自己的解码器将资源解密出来. 可以
 * 通过\link wyDirector wyDirector\endlink设置解码器
 * \endif
 */
class WIENGINE_API wyResourceDecoder {
public:
	/**
	 * \if English
	 * Decode flags
	 * \else
	 * 可以设置的标志
	 * \endif
	 */
	enum Flags {
		/**
		 * \if English
		 * resource file saved in res folder will be decoded
		 * \else
		 * 存放在res目录下的资源会被解码
		 * \endif
		 */
		DECODE_RES = 1,

		/**
		 * \if English
		 * resource file saved in assets folder will be decoded
		 * \else
		 * 存放在assets目录下的资源会被解码
		 * \endif
		 */
		DECODE_ASSETS = 1 << 1,

		/**
		 * \if English
		 * resource file saved in file system will be decoded
		 * \else
		 * 存放在文件系统上的资源会被解码
		 * \endif
		 */
		DECODE_FILE = 1 << 2,

		/**
		 * \if English
		 * all resource file will be decoded
		 * \else
		 * 不管资源文件保存在什么地方都要解码
		 * \endif
		 */
		DECODE_ALL = DECODE_RES | DECODE_ASSETS | DECODE_FILE
	};

private:
	/// decoder flags
	int m_flags;

protected:
	wyResourceDecoder();

public:
	virtual ~wyResourceDecoder();

	/**
	 * \if English
	 * Decode a resource data
	 *
	 * @param data encoded data
	 * @param length data byte size
	 * @param outLen it holds length of decoded data
	 * @return decoded data, WiEngine will be responsible for releasing it
	 * \else
	 * 解码一个资源数据
	 *
	 * @param data 被编码的数据
	 * @param length 数据字节长度
	 * @param outLen 用于返回解码后的数据长度
	 * @return 解码后的数据, WiEngine会负责释放
	 * \endif
	 */
	virtual const char* decode(const char* data, size_t length, size_t* outLen) = 0;

	/**
	 * \if English
	 * Check whether a flag is set or not
	 *
	 * @return true if a flag is set
	 * \else
	 * 检查某个标志是否设置
	 *
	 * @return true表示标志已设置
	 * \endif
	 */
	bool hasFlag(Flags flag) { return (m_flags & flag) != 0; }

	/**
	 * \if English
	 * Set decoder flags
	 *
	 * @param flags flags
	 * \else
	 * 设置解码器标志
	 *
	 * @param flags 标志
	 * \endif
	 */
	void setFlags(int flags) { m_flags = flags; }
};

#endif // __wyResourceDecoder_h__
