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
#ifndef __wyShaderManager_h__
#define __wyShaderManager_h__

#include "wyShaderProgram.h"

/**
 * @class wyShaderManager
 *
 * Singleton shader manager
 */
class WIENGINE_API wyShaderManager : public wyObject {
public:
	/**
	 * Key for builtin shader program
	 */
	enum ProgramKey {
		/// Program which handle position, color and texture
		PROG_PCT = 0x10000000,

		/// program which handle position and color
		PROG_PC = 0x10000001,

		/**
		 * external program loaded by application, the id of external will be added
		 * to this key
		 */
		EXTERNAL = 0x20000000
	};

	/// Default program used to render material
	static const ProgramKey DEFAULT_PROGRAM = PROG_PCT;

private:
	/// list of all loaded shader programs
	map<int, wyShaderProgram*>* m_programs;

protected:
	wyShaderManager();

	/**
	 * Load built-in shaders and cache it
	 */
	void loadBuiltinShaders();

	/**
	 * Add a shader program to cache
	 *
	 * @param programKey final id of program
	 * @param vsh vertex shader object
	 * @param fsh fragment shader object
	 * @return added \link wyShaderProgram wyShaderProgram\endlink object
	 */
	wyShaderProgram* addProgram(int programKey, wyShader* vsh, wyShader* fsh);

public:
	static wyShaderManager* getInstance();
	virtual ~wyShaderManager();

	/**
	 * Get a cached program by key
	 *
	 * @param key program key
	 * @return \link wyShaderProgram wyShaderProgram\endlink object, or NULL if not found
	 */
	wyShaderProgram* getProgram(int key);

	/**
	 * Add a custom shader program
	 *
	 * @param programKey key assigned to this program
	 * @param vshResId resource id of vertex shader file
	 * @param fshResId resource id of fragment shader file
	 * @return added \link wyShaderProgram wyShaderProgram\endlink object
	 */
	wyShaderProgram* addProgram(int programKey, int vshResId, int fshResId);

	/**
	 * Add a custom shader program
	 *
	 * @param programKey key assigned to this program
	 * @param vshPath path of vertex shader file
	 * @param vshIsFile true means \c vshPath is an absolute path in file system, or false if
	 * 		\c vshPath is a relative path under assets
	 * @param fshPath path of fragment shader file
	 * @param fshIsFile true means \c fshPath is an absolute path in file system, or false if
	 * 		\c fshPath is a relative path under assets
	 * @return \link wyShaderProgram wyShaderProgram\endlink
	 */
	wyShaderProgram* addProgram(int programKey, const char* vshPath, bool vshIsFile, const char* fshPath, bool fshIsFile);

	/**
	 * Add a custom shader program
	 *
	 * @param programKey key assigned to this program
	 * @param vshSrc vertex shader source code
	 * @param fshSrc fragment shader source code
	 * @return added \link wyShaderProgram wyShaderProgram\endlink object
	 */
	wyShaderProgram* addProgram(int programKey, const char* vshSrc, const char* fshSrc);
};

#endif // __wyShaderManager_h__
