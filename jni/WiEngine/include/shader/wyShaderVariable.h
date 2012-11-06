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
#ifndef __wyShaderVariable_h__
#define __wyShaderVariable_h__

#include "wyObject.h"
#include "wyTypes.h"
#include "wyUtils.h"
#include "wyBuffer.h"

/**
 * Base class for shader variable
 */
class WIENGINE_API wyShaderVariable : public wyObject {
public:
	/// Type of shader variables
	enum Type {
		/// boolean
	    BOOLEAN,

	    /// int
	    INT,

	    /// float
	    FLOAT,

	    /// 2d vector
	    VEC2,

	    /// 3d vector
	    VEC3,

	    /// 4d vector
	    VEC4,

	    /// 3d matrix
	    MAT3,

	    /// 4d matrix
	    MAT4,

	    /// float array
	    FLOAT_ARRAY,

	    /// 2d vector array
	    VEC2_ARRAY,

	    /// 3d vector array
	    VEC3_ARRAY,

	    /// 4d vector array
	    VEC4_ARRAY,

	    /// 3d matrix array
	    MAT3_ARRAY,

	    /// 4d matrix array
	    MAT4_ARRAY,

	    /// sampler 2d
	    TEXTURE_2D,

	    /// sampler 3d
	    TEXTURE_3D,

	    /// texture cubemap
	    TEXTURE_CUBEMAP,

	    /// interleaved buffer
	    INTERLEAVED_BUFFER
	};

	/// Value of a shader variable, an union so it can used for any type
	union Value {
		/// boolean
		bool b;

		/// int
		int i;

		/// float
		float f;

		/// vector 2d
		kmVec2 v2;

		/// vector 3d
		kmVec3 v3;

		/// vector 4d
		kmVec4 v4;

		/// matrix 3d
		kmMat3 m3;

		/// matrix 4d
		kmMat4 m4;

		/// array
		struct {
			/// count of floats
			int size;

			/// float buffer
			float* p;
		} a;

		/// interleave buffer
		struct {
			/// buffer object
			wyBuffer* buf;

			/// start data offset in \c m_data
			int offset;

			/// data components
			int components;
		} ib;
	};

protected:
	/// type of variable
	Type m_type;

	/// variable name
	const char* m_name;

	/// value
	Value m_value;

	/// location in shader
	GLint m_location;

	/**
	 * set flag used to mark this variable is already bound by
	 * current render process
	 */
	bool m_set;

	/// true means shader variable value need to be set to program
	/// however, currently it is only used for uniform
	bool m_needSync;

protected:
	/**
	 * Constructor
	 *
	 * @param type variable type
	 * @param name variable name
	 */
	wyShaderVariable(Type type, const char* name);

public:
	virtual ~wyShaderVariable();

	/**
	 * Get parameter location in shader
	 *
	 * @return location
	 */
	virtual GLint getLocation() { return m_location; }

	/**
	 * Get name of variable
	 *
	 * @return name string, caller should not release it
	 */
	const char* getName() { return m_name; }

	/**
	 * Get type of variable
	 *
	 * @return variable type
	 */
	Type getType() { return m_type; }

	/**
	 * Get shader variable value
	 *
	 * @return value
	 */
	const Value& getValue() { return m_value; }

	/**
	 * Set shader variable value. If type is array, caller should not release
	 * array data
	 *
	 * @param v value
	 */
	void setValue(const Value& v);

	/**
	 * Reset value to zero
	 */
	void clearValue();

	/**
	 * Is this variable set?
	 *
	 * @return true means variable is already set
	 */
	bool isSet() { return m_set; }

	/**
	 * True means this variable value should be sync to current program
	 */
	bool isNeedSync() { return m_needSync; }

	/**
	 * Flag variable need to be set to program
	 */
	void setNeedSync(bool flag) { m_needSync = flag; }
};

#endif // __wyShaderVariable_h__
