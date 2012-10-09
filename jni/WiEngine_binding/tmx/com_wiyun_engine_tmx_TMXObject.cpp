#include "com_wiyun_engine_tmx_TMXObject.h"
#include "wyTMXObject.h"
#include "wyUtils_android.h"

extern jfieldID g_fid_BaseObject_mPointer;
extern jmethodID g_mid_WYPointList_addPoint_xy;

JNIEXPORT void JNICALL Java_com_wiyun_engine_tmx_TMXObject_nativeInit
  (JNIEnv * env, jobject thiz) {
	wyTMXObject* g = wyTMXObject::make();
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)g);
	g->retain();
	g->lazyRelease();
}

JNIEXPORT jstring JNICALL Java_com_wiyun_engine_tmx_TMXObject_getProperty
  (JNIEnv * env, jobject thiz, jstring name) {
	wyTMXObject* to = (wyTMXObject*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	const char* n = env->GetStringUTFChars(name, NULL);
	const char* v = to->getProperty(n);
	env->ReleaseStringUTFChars(name, n);
	return env->NewStringUTF(v);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_tmx_TMXObject_nativeGetType
  (JNIEnv * env, jobject thiz) {
	wyTMXObject* to = (wyTMXObject*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return (jint)to->getType();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_tmx_TMXObject_nativeGetPosition
  (JNIEnv * env, jobject thiz, jobject p) {
	wyTMXObject* to = (wyTMXObject*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyPoint np = to->getPosition();
	wyUtils_android::to_WYPoint(np, p);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_tmx_TMXObject_nativeGetSize
  (JNIEnv * env, jobject thiz, jobject s) {
	wyTMXObject* to = (wyTMXObject*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wySize ns = to->getSize();
	wyUtils_android::to_WYSize(ns, s);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_tmx_TMXObject_nativeGetPoints
  (JNIEnv * env, jobject thiz, jobject plist) {
	wyTMXObject* to = (wyTMXObject*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyPointList& nplist = to->getPoints();
	wyPoint* buffer = nplist.getBuffer();
	int count = nplist.getCount();
	for(int i = 0; i < count; i++) {
		env->CallVoidMethod(plist, g_mid_WYPointList_addPoint_xy, buffer[i].x, buffer[i].y);
	}
}
