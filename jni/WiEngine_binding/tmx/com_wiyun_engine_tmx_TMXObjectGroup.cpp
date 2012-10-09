#include "com_wiyun_engine_tmx_TMXObjectGroup.h"
#include "wyTMXObjectGroup.h"
#include <stdlib.h>
#include "wyTypes.h"
#include "wyUtils_android.h"
#include "wyLog.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_tmx_TMXObjectGroup_nativeInit
  (JNIEnv * env, jobject thiz) {
	wyTMXObjectGroup* g = wyTMXObjectGroup::make();
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)g);
	g->retain();
	g->lazyRelease();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_tmx_TMXObjectGroup_addProperty
  (JNIEnv * env, jobject thiz, jstring key, jstring value) {
	wyTMXObjectGroup* g = (wyTMXObjectGroup*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	const char* k = env->GetStringUTFChars(key, NULL);
	const char* v = env->GetStringUTFChars(value, NULL);
	g->addProperty(k, v);
	env->ReleaseStringUTFChars(key, k);
	env->ReleaseStringUTFChars(value, v);
}

JNIEXPORT jstring JNICALL Java_com_wiyun_engine_tmx_TMXObjectGroup_getProperty
  (JNIEnv * env, jobject thiz, jstring name) {
	wyTMXObjectGroup* g = (wyTMXObjectGroup*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	const char* n = env->GetStringUTFChars(name, NULL);
	const char* v = g->getProperty(n);
	jstring s = env->NewStringUTF(v);
	env->ReleaseStringUTFChars(name, n);
	return s;
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_tmx_TMXObjectGroup_nativeGetObject
  (JNIEnv * env, jobject thiz, jstring name) {
	wyTMXObjectGroup* g = (wyTMXObjectGroup*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	const char* n = env->GetStringUTFChars(name, NULL);
	wyTMXObject* to = g->getObject(n);
	env->ReleaseStringUTFChars(name, n);
	return (jint)to;
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_tmx_TMXObjectGroup_nativeGetObjectAt
  (JNIEnv * env, jobject thiz, jint index) {
	wyTMXObjectGroup* g = (wyTMXObjectGroup*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyTMXObject* to = g->getObjectAt(index);
	return (jint)to;
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_tmx_TMXObjectGroup_getObjectCount
  (JNIEnv * env, jobject thiz) {
	wyTMXObjectGroup* g = (wyTMXObjectGroup*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return g->getObjectCount();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_tmx_TMXObjectGroup_setName
  (JNIEnv * env, jobject thiz, jstring name) {
	wyTMXObjectGroup* g = (wyTMXObjectGroup*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	const char* n = env->GetStringUTFChars(name, NULL);
	g->setName(n);
	env->ReleaseStringUTFChars(name, n);
}

JNIEXPORT jstring JNICALL Java_com_wiyun_engine_tmx_TMXObjectGroup_getName
  (JNIEnv * env, jobject thiz) {
	wyTMXObjectGroup* g = (wyTMXObjectGroup*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	const char* name = g->getName();
	return env->NewStringUTF(name);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_tmx_TMXObjectGroup_setOffsetX
  (JNIEnv * env, jobject thiz, jfloat x) {
	wyTMXObjectGroup* g = (wyTMXObjectGroup*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	g->setOffsetX(x);
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_tmx_TMXObjectGroup_getOffsetX
  (JNIEnv * env, jobject thiz) {
	wyTMXObjectGroup* g = (wyTMXObjectGroup*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return g->getOffsetX();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_tmx_TMXObjectGroup_setOffsetY
  (JNIEnv * env, jobject thiz, jfloat y) {
	wyTMXObjectGroup* g = (wyTMXObjectGroup*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	g->setOffsetY(y);
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_tmx_TMXObjectGroup_getOffsetY
  (JNIEnv * env, jobject thiz) {
	wyTMXObjectGroup* g = (wyTMXObjectGroup*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return g->getOffsetY();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_tmx_TMXObjectGroup_setColor
  (JNIEnv * env, jobject thiz, jint c) {
	wyTMXObjectGroup* g = (wyTMXObjectGroup*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	g->setColor(c);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_tmx_TMXObjectGroup_getColor
  (JNIEnv * env, jobject thiz) {
	wyTMXObjectGroup* g = (wyTMXObjectGroup*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return g->getColor();
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_tmx_TMXObjectGroup_getOpacity
  (JNIEnv * env, jobject thiz) {
	wyTMXObjectGroup* g = (wyTMXObjectGroup*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return g->getOpacity();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_tmx_TMXObjectGroup_setOpacity
  (JNIEnv * env, jobject thiz, jfloat o) {
	wyTMXObjectGroup* g = (wyTMXObjectGroup*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	g->setOpacity(o);
}
