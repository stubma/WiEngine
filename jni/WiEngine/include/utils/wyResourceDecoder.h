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
 * Decoder of resource, it will be called before WiEngine parses raw
 * data of a resource. You can install your decoder to protect your game
 * design from decompiling app package. To set a decoder, check \link wyDirector wyDirector\endlink
 * API doc.
 */
class WIENGINE_API wyResourceDecoder {
public:
	/**
	 * Decode flags
	 */
	enum Flags {
		/**
		 * resource file saved in res folder will be decoded
		 */
		DECODE_RES = 1,

		/**
		 * resource file saved in assets folder will be decoded
		 */
		DECODE_ASSETS = 1 << 1,

		/**
		 * resource file saved in file system will be decoded
		 */
		DECODE_FILE = 1 << 2,

		/**
		 * all resource file will be decoded
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
	 * Decode a resource data
	 *
	 * @param data encoded data
	 * @param length data byte size
	 * @param outLen it holds length of decoded data
	 * @return decoded data, WiEngine will be responsible for releasing it
	 */
	virtual const char* decode(const char* data, size_t length, size_t* outLen) = 0;

	/**
	 * Check whether a flag is set or not
	 *
	 * @return true if a flag is set
	 */
	bool hasFlag(Flags flag) { return (m_flags & flag) != 0; }

	/**
	 * Set decoder flags
	 *
	 * @param flags flags
	 */
	void setFlags(int flags) { m_flags = flags; }
};

#endif // __wyResourceDecoder_h__
