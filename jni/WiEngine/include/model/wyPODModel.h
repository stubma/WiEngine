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
#ifndef __wyPODModel_h__
#define __wyPODModel_h__

#include "wyModel.h"

class CPVRTModelPOD;

/**
 * model of PowerVR Object Data, abbreviation is POD
 */
class WIENGINE_API wyPODModel : public wyModel {
protected:
    /// PowerVR pod model class
    CPVRTModelPOD* m_pod;
    
protected:
	wyPODModel();

public:
	/**
	 * loading a POD model from a resource file
	 *
	 * @param resId resource id of model file
	 * @return \link wyPODModel wyPODModel\endlink
	 */
	static wyPODModel* make(int resId);
    
    /**
     * loading a POD model from an asset file
     * 
     * @param path relative path in assets folder
     * @param \link wyPODModel wyPODModel\endlink
     */
    static wyPODModel* make(const char* path);
    
    /**
     * loading a POD model from a file in file system
     *
     * @param path model file absolute path
     * @param \link wyPODModel wyPODModel\endlink
     */
    static wyPODModel* makeFile(const char* path);
    
    /**
     * loading a POD model from a memory file
     *
     * @param mfsName memory file of model
     * @param \link wyPODModel wyPODModel\endlink
     */
    static wyPODModel* makeMemory(const char* mfsName);
    
    /**
     * loading a POD model from a raw data
     *
     * @param data raw data of model
     * @param len length of raw data
     * @param \link wyPODModel wyPODModel\endlink
     */
    static wyPODModel* makeMemory(const char* data, size_t len);

	virtual ~wyPODModel();

	/// @see wyLoadableObject::load
	virtual void load(int resId);

	/// @see wyLoadableObject::load
	virtual void load(const char* path);

	/// @see wyLoadableObject::loadFile
	virtual void loadFile(const char* path);

	/// @see wyLoadableObject::loadMemory
	virtual void loadMemory(const char* mfsName);

	/// @see wyLoadableObject::loadMemory
	virtual void loadMemory(const char* data, size_t len);

	/// @see wyModel::dump
	virtual void dump();
};

#endif // __wyPODModel_h__
