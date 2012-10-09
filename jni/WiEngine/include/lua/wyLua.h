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
 * \if English
 * \par
 * Wrapper of lua, providing some common Apis to facilitate programming with lua.
 *
 * \par
 * If you choose to use lua apis directly instead of wyLua, wyLua::init must be called before
 * you can use WiEgine Apis in lua.
 *
 * \par
 * Also, in this case, do not forget to call wyLua::destroy if lua is not needed anymore.
 * \else
 * \par
 * WiEngine的Lua封装类, 这个类封装了一个lua_State实例. 当然你也可以直接lua的
 * api. wyLua提供了较为简单的接口, 封装了lua的常用操作
 *
 * \par
 * 如果使用wyLua执行lua脚本, WiEngine的所有API都可以从lua中访问. 如果您自己创建
 * lua_State, 则只要调用wyLua的init方法对state初始化后就可以访问WiEngine的API
 *
 * \par
 * 使用wyLua之前必须调用wyLua::init方法, 不再使用时必须调用wyLua::destroy方法.
 * \endif
 */
class WYLUA_API wyLua {
private:
	static lua_State* s_state;

public:
	/**
	 * \if English
	 * Used to do initialization. The first function to be called once before
	 * starting with lua, and it is safe to be called multiple times.
	 * \else
	 * 初始化wyLua. 使用wyLua之前必须调用此方法. 该方法会进行有效性检查, 因此
	 * 多次调用是安全的.
	 * \endif
	 */
	static void init();

	/**
	 * \if English
	 * Used to initialize a lua state machine.
	 *
	 * @param state pointer to the lua state machine
	 * \else
	 * 用于初始化开发者自己创建的lua_State
	 *
	 * @param state lua_State指针
	 * \endif
	 */
	static void init(lua_State* state);

	/**
	 * \if English
	 * Used to release resources occupied the lua. The function must be called once before
	 * program exits, and it is safe to be called multiple times.
	 * \else
	 * 释放wyLua维护的单一lua_State实例, 程序退出之前必须调用此方法. 该方法会进行有效性检查, 因此
	 * 多次调用是安全的.
	 * \endif
	 */
	static void destroy();

	/**
	 * \if English
	 * getter, get the lua state machine
	 *
	 * @return pointer to the lua state machine
	 * \else
	 * 获得lua_State
	 *
	 * @return lua_State指针
	 * \endif
	 */
	static lua_State* getState() { return s_state; }

	/**
	 * \if English
	 * Used to execute a lua script.
	 *
	 * @param resId the resource Id of lua script file
	 * \else
	 * 执行一个lua脚本
	 *
	 * @param resId lua脚本的资源id
	 * \endif
	 */
	static void execute(int resId);

	/**
	 * \if English
	 * Used to execute a lua script
	 *
	 * @param path the file path of the lua script file
	 * @param isFile true means parameter path is absolute file path, false means relative path under assets.
	 * \else
	 * 执行一个lua脚本
	 *
	 * @param path lua脚本的路径
	 * @param isFile true表示path是一个文件系统路径, false表示path是一个assets下的相对路径
	 * \endif
	 */
	static void execute(const char* path, bool isFile = false);

	/**
	 * \if English
	 * Used to execute a lua script
	 *
	 * @param s  c string ended with null which points to the start of the lua script
	 * \else
	 * 执行一个lua脚本
	 *
	 * @param s 已经被载入内存的lua脚本的c字符串, 调用者要负责释放指针
	 * \endif
	 */
	static void executeMemory(const char* s);

	/**
	 * \if English
	 * Used to set a global environment variable in the state machine
	 *
	 * @param name the name of the global
	 * @param obj pointer to the global
	 * @param type type of the global, will be regarded as type of userdata if not specified
	 * \else
	 * 设置一个全局对象, 完成后可以在lua脚本中可以访问这个对象
	 *
	 * @param name 全局对象名
	 * @param obj 对象指针
	 * @param type 对象类型, 如果不指定类型则当成lua中的userdata处理
	 * \endif
	 */
	static void setGlobal(const char* name, void* obj, const char* type = NULL);

	/**
	 * \if English
	 * Used to set a global environment variable of integer type.
	 *
	 * @param name name of the global
	 * @param value value of the global
	 * \else
	 * 设置一个全局整数参数
	 *
	 * @param name 参数名称
	 * @param value 参数值
	 * \endif
	 */
	static void setGlobal(const char* name, int value);

	/**
	 * \if English
	 * Used to set a global environment variable of float type.
	 *
	 * @param name name of the global
	 * @param value value of the global
	 * \else
	 * 设置一个全局浮点参数
	 *
	 * @param name 参数名称
	 * @param value 参数值
	 * \endif
	 */
	static void setGlobal(const char* name, float value);

	/**
	 * \if English
	 * Used to set a global environment variable of c string type.
	 *
	 * @param name name of the global
	 * @param value value of the global, a copy of value will be retained.
	 * \else
	 * 设置一个全局字符串参数
	 *
	 * @param name 参数名称
	 * @param value 字符串, lua底层会拷贝一份, 所以该方法返回后该字符串可以被释放掉.
	 * \endif
	 */
	static void setGlobal(const char* name, const char* value);

	/**
	 * \if Enlgish
	 * Used to get a global environment variable
	 *
	 * @param name name of the global
	 * @return pointer to the global, NULL if fail
	 * \else
	 * 获得一个全局对象
	 *
	 * @param name 参数名称
	 * @return 对象指针, 如果失败返回NULL
	 * \endif
	 */
	static void* getGlobalObject(const char* name);

	/**
	 * \if English
	 * Used to get a global environment variable of integer type
	 *
	 * @param name name of the global
	 * @param def the default value to be returned
	 * @return the value of the global, def will be returned if fail
	 * \else
	 * 获得一个全局整数参数
	 *
	 * @param name 参数名称
	 * @param def 如果不存在这个参数或者其它原因导致失败, 返回这个缺省值, 缺省值是-1
	 * @return 整数值, 如果失败返回传入的缺省值
	 * \endif
	 */
	static int getGlobalInt(const char* name, int def = -1);

	/**
	 * \if English
	 * Used to get a global environment variable of float type
	 *
	 * @param name name of the global
	 * @param def the default value to be returned
	 * @return the value of the global, def will be returned if fail
	 * \else
	 * 获得一个全局浮点参数
	 *
	 * @param name 参数名称
	 * @param def 如果不存在这个参数或者其它原因导致失败, 返回这个缺省值, 缺省值是0
	 * @return 整数值, 如果失败返回传入的缺省值
	 * \endif
	 */
	static float getGlobalFloat(const char* name, float def = 0.f);

	/**
	 * \if English
	 * Used to get a global environment variable of c string type
	 *
	 * @param name name of the global
	 * @return a pointer to a null-terminated c string, or NULL if fail. The caller is responsible to free this string if not needed
	 * \else
	 * 获得一个全局字符串参数
	 *
	 * @param name 参数名称
	 * @return 字符串, 调用者要负责释放字符串内存. 如果失败, 返回NULL
	 * \endif
	 */
	static const char* getGlobalString(const char* name);
};

#endif // __wyLua_h__
