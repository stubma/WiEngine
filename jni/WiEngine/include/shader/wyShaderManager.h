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
 * \if English
 * Singleton shader manager
 * \else
 * 单例模式的shader程序管理器
 * \endif
 */
class WIENGINE_API wyShaderManager : public wyObject {
public:
	/**
	 * \if English
	 * Key for builtin shader program
	 * \else
	 * 内置的shader程序的标识名称
	 * \endif
	 */
	enum ProgramKey {
		/**
		 * \if English
		 * Program which handle position, color and texture
		 * \else
		 * 最常用的程序类型, 负责位置, 颜色与贴图的渲染
		 * \endif
		 */
		PROG_PCT = 0x10000000,

		/**
		 * \if English
		 * external program loaded by application, the id of external will be added
		 * to this key
		 * \else
		 * 应用使用的自定义shader程序, 会加上这个数值以表示这是一个外部shader程序
		 * \endif
		 */
		EXTERNAL = 0x20000000
	};

	/**
	 * \if English
	 * Default program used to render material
	 * \else
	 * 缺省的shader key
	 * \endif
	 */
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
	 * \if English
	 * Add a shader program to cache
	 *
	 * @param programKey final id of program
	 * @param vsh vertex shader object
	 * @param fsh fragment shader object
	 * @return added \link wyShaderProgram wyShaderProgram\endlink object
	 * \else
	 * 添加一个shader程序
	 *
	 * @param programKey shader程序的最终id
	 * @param vsh vertex shader对象
	 * @param fsh fragment shader对象
	 * @return 添加的\link wyShaderProgram wyShaderProgram\endlink对象
	 * \endif
	 */
	wyShaderProgram* addProgram(int programKey, wyShader* vsh, wyShader* fsh);

public:
	static wyShaderManager* getInstance();
	virtual ~wyShaderManager();

	/**
	 * \if English
	 * Get a cached program by key
	 *
	 * @param key program key
	 * @return \link wyShaderProgram wyShaderProgram\endlink object, or NULL if not found
	 * \else
	 * 根据id得到一个缓存的shader程序对象
	 *
	 * @param key 程序id
	 * @return \link wyShaderProgram wyShaderProgram\endlink, 没有找到则返回NULL
	 * \endif
	 */
	wyShaderProgram* getProgram(int key);

	/**
	 * \if English
	 * Add a custom shader program
	 *
	 * @param programKey key assigned to this program
	 * @param vshResId resource id of vertex shader file
	 * @param fshResId resource id of fragment shader file
	 * @return added \link wyShaderProgram wyShaderProgram\endlink object
	 * \else
	 * 添加一个外部shader程序
	 *
	 * @param programKey 这个shader程序的唯一id, 载入后可以通过这个id来引用该shader程序
	 * @param vshResId vertex shader文件的资源id
	 * @param fshResId fragment shader文件的资源id
	 * @return 添加的\link wyShaderProgram wyShaderProgram\endlink对象
	 * \endif
	 */
	wyShaderProgram* addProgram(int programKey, int vshResId, int fshResId);

	/**
	 * \if English
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
	 * \else
	 * 添加一个外部shader程序
	 *
	 * @param programKey 这个shader程序的唯一id, 载入后可以通过这个id来引用该shader程序
	 * @param vshPath vertex shader文件的路径
	 * @param vshIsFile true表示\c vshPath是一个文件系统的绝对路径, 或者false表示\c vshPath是一个相对于assets
	 * 		的相对路径
	 * @param fshPath fragment shader文件的路径
	 * @param fshIsFile true表示\c fshPath是一个文件系统的绝对路径, 或者false表示\c fshPath是一个相对于assets
	 * 		的相对路径
	 * @return \link wyShaderProgram wyShaderProgram\endlink
	 * \endif
	 */
	wyShaderProgram* addProgram(int programKey, const char* vshPath, bool vshIsFile, const char* fshPath, bool fshIsFile);

	/**
	 * \if English
	 * Add a custom shader program
	 *
	 * @param programKey key assigned to this program
	 * @param vshSrc vertex shader source code
	 * @param fshSrc fragment shader source code
	 * @return added \link wyShaderProgram wyShaderProgram\endlink object
	 * \else
	 * 添加一个外部shader程序
	 *
	 * @param programKey 这个shader程序的唯一id, 载入后可以通过这个id来引用该shader程序
	 * @param vshSrc vertex shader的源代码
	 * @param fshSrc fragment shader的源代码
	 * @return 添加的\link wyShaderProgram wyShaderProgram\endlink对象
	 * \endif
	 */
	wyShaderProgram* addProgram(int programKey, const char* vshSrc, const char* fshSrc);
};

#endif // __wyShaderManager_h__
