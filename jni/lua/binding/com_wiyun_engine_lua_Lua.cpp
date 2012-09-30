#include "com_wiyun_engine_lua_Lua.h"
#include "wyLua.h"
#include "wyLog.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_lua_Lua_init
  (JNIEnv * env, jclass clazz) {
	wyLua::init();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_lua_Lua_destroy
  (JNIEnv * env, jclass clazz) {
	wyLua::destroy();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_lua_Lua_execute__I
  (JNIEnv * env, jclass clazz, jint resId) {
	wyLua::execute(resId);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_lua_Lua_execute__Ljava_lang_String_2Z
  (JNIEnv * env, jclass clazz, jstring path, jboolean isFile) {
	const char* p = (const char*)env->GetStringUTFChars(path, NULL);
	wyLua::execute(p, isFile);
	env->ReleaseStringUTFChars(path, p);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_lua_Lua_execute__Ljava_lang_String_2
  (JNIEnv * env, jclass clazz, jstring s) {
	const char* str = (const char*)env->GetStringUTFChars(s, NULL);
	wyLua::executeMemory(str);
	env->ReleaseStringUTFChars(s, str);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_lua_Lua_setGlobal__Ljava_lang_String_2Ljava_lang_Object_2Ljava_lang_String_2
  (JNIEnv * env, jclass clazz, jstring name, jobject obj, jstring type) {
	const char* n = (const char*)env->GetStringUTFChars(name, NULL);
	char* t = type == NULL ? NULL : (char*)env->GetStringUTFChars(type, NULL);
	if(t == NULL || !strcmp(t, "_jobject")) {
		wyLua::setGlobal(n, obj, (const char*)t);
	} else {
		wyObject* o = (wyObject*)env->GetIntField(obj, g_fid_BaseObject_mPointer);
		wyLua::setGlobal(n, o, (const char*)t);
	}
	env->ReleaseStringUTFChars(name, n);
	if(type)
		env->ReleaseStringUTFChars(type, t);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_lua_Lua_setGlobal__Ljava_lang_String_2I
  (JNIEnv * env, jclass clazz, jstring name, jint value) {
	const char* n = (const char*)env->GetStringUTFChars(name, NULL);
	wyLua::setGlobal(n, value);
	env->ReleaseStringUTFChars(name, n);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_lua_Lua_setGlobal__Ljava_lang_String_2F
  (JNIEnv * env, jclass clazz, jstring name, jfloat value) {
	const char* n = (const char*)env->GetStringUTFChars(name, NULL);
	wyLua::setGlobal(n, value);
	env->ReleaseStringUTFChars(name, n);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_lua_Lua_setGlobal__Ljava_lang_String_2Ljava_lang_String_2
  (JNIEnv * env, jclass clazz, jstring name, jstring value) {
	const char* n = (const char*)env->GetStringUTFChars(name, NULL);
	const char* v = (const char*)env->GetStringUTFChars(value, NULL);
	wyLua::setGlobal(n, v);
	env->ReleaseStringUTFChars(name, n);
	env->ReleaseStringUTFChars(value, v);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_lua_Lua_getGlobalObject
  (JNIEnv * env, jclass clazz, jstring name) {
	const char* n = (const char*)env->GetStringUTFChars(name, NULL);
	void* obj = wyLua::getGlobalObject(n);
	env->ReleaseStringUTFChars(name, n);
	return (jint)obj;
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_lua_Lua_getGlobalInt
  (JNIEnv * env, jclass clazz, jstring name, jint def) {
	const char* n = (const char*)env->GetStringUTFChars(name, NULL);
	int ret = wyLua::getGlobalInt(n, def);
	env->ReleaseStringUTFChars(name, n);
	return ret;
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_lua_Lua_getGlobalFloat
  (JNIEnv * env, jclass clazz, jstring name, jfloat def) {
	const char* n = (const char*)env->GetStringUTFChars(name, NULL);
	float ret = wyLua::getGlobalFloat(n, def);
	env->ReleaseStringUTFChars(name, n);
	return ret;
}

JNIEXPORT jstring JNICALL Java_com_wiyun_engine_lua_Lua_getGlobalString
  (JNIEnv * env, jclass clazz, jstring name) {
	const char* n = (const char*)env->GetStringUTFChars(name, NULL);
	const char* s = wyLua::getGlobalString(n);
	env->ReleaseStringUTFChars(name, n);

	jstring js = env->NewStringUTF(s);
	free((void*)s);
	return js;
}
