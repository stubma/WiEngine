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
#include "wyLua.h"
#include "WiEngine.h"
#include "tolua++.h"
#include "wyLog.h"

extern int tolua_actions_open(lua_State* tolua_S);
extern int tolua_afcanim_open(lua_State* tolua_S);
extern int tolua_astar_open(lua_State* tolua_S);
extern int tolua_bitmapfont_open(lua_State* tolua_S);
extern int tolua_common_open(lua_State* tolua_S);
extern int tolua_dialog_open(lua_State* tolua_S);
extern int tolua_easeactions_open(lua_State* tolua_S);
extern int tolua_events_open(lua_State* tolua_S);
extern int tolua_filters_open(lua_State* tolua_S);
extern int tolua_grid_open(lua_State* tolua_S);
extern int tolua_gridactions_open(lua_State* tolua_S);
extern int tolua_nodes_open(lua_State* tolua_S);
extern int tolua_opengl_open(lua_State* tolua_S);
extern int tolua_particle_open(lua_State* tolua_S);
extern int tolua_tmx_open(lua_State* tolua_S);
extern int tolua_transitions_open(lua_State* tolua_S);
extern int tolua_types_open(lua_State* tolua_S);
extern int tolua_utils_open(lua_State* tolua_S);
extern int tolua_persistence_open(lua_State* tolua_S);

lua_State* wyLua::s_state = NULL;

void wyLua::init() {
	if(!s_state) {
		s_state = lua_open();
		luaL_openlibs(s_state);
		tolua_open(s_state);
		init(s_state);
	}
}

void wyLua::init(lua_State* state) {
	tolua_actions_open(state);
	tolua_afcanim_open(state);
	tolua_astar_open(state);
	tolua_bitmapfont_open(state);
	tolua_common_open(state);
	tolua_dialog_open(state);
	tolua_easeactions_open(state);
	tolua_events_open(state);
	tolua_filters_open(state);
	tolua_grid_open(state);
	tolua_gridactions_open(state);
	tolua_nodes_open(state);
	tolua_opengl_open(state);
	tolua_particle_open(state);
	tolua_tmx_open(state);
	tolua_transitions_open(state);
	tolua_types_open(state);
	tolua_utils_open(state);
	tolua_persistence_open(state);
}

void wyLua::destroy() {
	if(s_state) {
		lua_close(s_state);
		s_state = NULL;
	}
}

void wyLua::execute(int resId) {
	if(!s_state) {
		LOGW("calling wyLua::execute without call init first!");
		return;
	}

	char* script = wyUtils::loadCString(resId);
	luaL_dostring(s_state, script);
	wyFree(script);
}

void wyLua::execute(const char* path, bool isFile) {
	if(!s_state) {
		LOGW("calling wyLua::execute without call init first!");
		return;
	}

	char* script = wyUtils::loadCString(path, isFile);
	luaL_dostring(s_state, script);
	wyFree(script);
}

void wyLua::executeMemory(const char* s) {
	if(!s_state) {
		LOGW("calling wyLua::executeMemory without call init first!");
		return;
	}

	luaL_dostring(s_state, s);
}

void wyLua::setGlobal(const char* name, void* obj, const char* type) {
	if(type)
		tolua_pushusertype(s_state, obj, type);
	else
		lua_pushlightuserdata(s_state, obj);
	lua_setglobal(s_state, name);
}

void wyLua::setGlobal(const char* name, int value) {
	tolua_pushnumber(s_state, value);
	lua_setglobal(s_state, name);
}

void wyLua::setGlobal(const char* name, float value) {
	tolua_pushnumber(s_state, value);
	lua_setglobal(s_state, name);
}

void wyLua::setGlobal(const char* name, const char* value) {
	tolua_pushstring(s_state, value);
	lua_setglobal(s_state, name);
}

void* wyLua::getGlobalObject(const char* name) {
	lua_getglobal(s_state, name);
	void* ret = NULL;
	if(lua_isuserdata(s_state, -1)) {
		if(lua_islightuserdata(s_state, -1))
			ret = lua_touserdata(s_state, -1);
		else 
			ret = tolua_tousertype(s_state, -1, NULL);
	}

	lua_remove(s_state, -1);
	return ret;
}

int wyLua::getGlobalInt(const char* name, int def) {
	lua_getglobal(s_state, name);
	int ret = def;
	if(lua_isnumber(s_state, -1)) {
		ret = lua_tonumber(s_state, -1);
	}

	lua_remove(s_state, -1);
	return ret;
}

float wyLua::getGlobalFloat(const char* name, float def) {
	lua_getglobal(s_state, name);
	float ret = def;
	if(lua_isnumber(s_state, -1)) {
		ret = lua_tonumber(s_state, -1);
	}

	lua_remove(s_state, -1);
	return ret;
}

const char* wyLua::getGlobalString(const char* name) {
	lua_getglobal(s_state, name);
	const char* ret = NULL;
	if(lua_isstring(s_state, -1)) {
		const char* s = lua_tostring(s_state, -1);
		ret = wyUtils::copy(s);
	}

	lua_remove(s_state, -1);
	return ret;
}
