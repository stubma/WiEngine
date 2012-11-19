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
#ifndef __wyLua_h__
#define __wyLua_h__

#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
#include "wyObject.h"

// export definition
#if WINDOWS
	#if LIBLUA_EXPORTS
		#define WYLUA_API __declspec(dllexport)
	#else
		#define WYLUA_API __declspec(dllimport)
	#endif
#else
	#define WYLUA_API
#endif

/**
 * @class wyLua
 * \par
 * Wrapper of lua, providing some common Apis to facilitate programming with lua.
 *
 * \par
 * If you choose to use lua apis directly instead of wyLua, wyLua::init must be called before
 * you can use WiEgine Apis in lua.
 *
 * \par
 * Also, in this case, do not forget to call wyLua::destroy if lua is not needed anymore.
 */
class WYLUA_API wyLua {
private:
	static lua_State* s_state;

public:
	/**
	 * Used to do initialization. The first function to be called once before
	 * starting with lua, and it is safe to be called multiple times.
	 */
	static void init();

	/**
	 * Used to initialize a lua state machine.
	 *
	 * @param state pointer to the lua state machine
	 */
	static void init(lua_State* state);

	/**
	 * Used to release resources occupied the lua. The function must be called once before
	 * program exits, and it is safe to be called multiple times.
	 */
	static void destroy();

	/**
	 * getter, get the lua state machine
	 *
	 * @return pointer to the lua state machine
	 */
	static lua_State* getState() { return s_state; }

	/**
	 * Used to execute a lua script.
	 *
	 * @param resId the resource Id of lua script file
	 */
	static void execute(int resId);

	/**
	 * Used to execute a lua script
	 *
	 * @param path the file path of the lua script file
	 * @param isFile true means parameter path is absolute file path, false means relative path under assets.
	 */
	static void execute(const char* path, bool isFile = false);

	/**
	 * Used to execute a lua script
	 *
	 * @param s  c string ended with null which points to the start of the lua script
	 */
	static void executeMemory(const char* s);

	/**
	 * Used to set a global environment variable in the state machine
	 *
	 * @param name the name of the global
	 * @param obj pointer to the global
	 * @param type type of the global, will be regarded as type of userdata if not specified
	 */
	static void setGlobal(const char* name, void* obj, const char* type = NULL);

	/**
	 * Used to set a global environment variable of integer type.
	 *
	 * @param name name of the global
	 * @param value value of the global
	 */
	static void setGlobal(const char* name, int value);

	/**
	 * Used to set a global environment variable of float type.
	 *
	 * @param name name of the global
	 * @param value value of the global
	 */
	static void setGlobal(const char* name, float value);

	/**
	 * Used to set a global environment variable of c string type.
	 *
	 * @param name name of the global
	 * @param value value of the global, a copy of value will be retained.
	 */
	static void setGlobal(const char* name, const char* value);

	/**
	 * \if Enlgish
	 * Used to get a global environment variable
	 *
	 * @param name name of the global
	 * @return pointer to the global, NULL if fail
	 */
	static void* getGlobalObject(const char* name);

	/**
	 * Used to get a global environment variable of integer type
	 *
	 * @param name name of the global
	 * @param def the default value to be returned
	 * @return the value of the global, def will be returned if fail
	 */
	static int getGlobalInt(const char* name, int def = -1);

	/**
	 * Used to get a global environment variable of float type
	 *
	 * @param name name of the global
	 * @param def the default value to be returned
	 * @return the value of the global, def will be returned if fail
	 */
	static float getGlobalFloat(const char* name, float def = 0.f);

	/**
	 * Used to get a global environment variable of c string type
	 *
	 * @param name name of the global
	 * @return a pointer to a null-terminated c string, or NULL if fail. The caller is responsible to free this string if not needed
	 */
	static const char* getGlobalString(const char* name);
};

#endif // __wyLua_h__
