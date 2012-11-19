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
 * A cross platform output stream implementation for writing resources
 */
class WIENGINE_API wyAssetOutputStream : public wyObject {
protected:
	/**
	 * true indicating append file
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
	 * static constructor
	 *
	 * @param path write file path
	 * @param append append file
	 * @return \link wyAssetOutputStream wyAssetOutputStream\endlink
	 */
	static wyAssetOutputStream* make(const char* path, bool append = false);

	virtual ~wyAssetOutputStream();

	/**
	 * open asset
	 *
	 * @return true means successful
	 */
	virtual bool open();

	/**
	 * close asset
	 */
	virtual void close() = 0;

	/**
	 * write char data
	 *
	 * @param data char data
	 * @param len character count in \c data
	 * @return byte write actually, -1 means error
	 */
	virtual ssize_t write(const char* data, size_t len) = 0;

	/**
	 * write int data
	 *
	 * @param data int data
	 * @param len count of integer in \c data
	 * @return byte write actually, -1 means error
	 */
	virtual ssize_t write(const int* data, size_t len) = 0;
    
    /**
	 * get offset from start to current position
	 *
	 * @return offset from start to current position
	 */
	virtual size_t getPosition() = 0;

	/**
	 * change pointer position
	 *
	 * @param offset offset
	 * @param mode seek mode
	 * @return new offset after changed
	 */
	virtual size_t seek(int offset, int mode) = 0;

	/**
	 * Get asset output path, caller should not release it
	 */
	const char* getPath() { return m_path; }
};

#endif // __wyAssetOutputStream_h__
