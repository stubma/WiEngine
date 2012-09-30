#include "com_wiyun_engine_filters_DropShadowColorFilter.h"
#include "wyDropShadowColorFilter.h"
#include "wyUtils_android.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_filters_DropShadowColorFilter_nativeInit
  (JNIEnv * env, jobject thiz, jobject color, jint radius, jint highlightRadius, jint opacity) {
	wyColor3B c = wyUtils_android::to_wyColor3B( color);
	wyDropShadowColorFilter* f = wyDropShadowColorFilter::make(c, radius, highlightRadius, opacity);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)f);
	f->retain();
	f->lazyRelease();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_filters_DropShadowColorFilter_setRadius
  (JNIEnv * env, jobject thiz, jint radius) {
	wyDropShadowColorFilter* f = (wyDropShadowColorFilter*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	f->setRadius(radius);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_filters_DropShadowColorFilter_getRadius
  (JNIEnv * env, jobject thiz) {
	wyDropShadowColorFilter* f = (wyDropShadowColorFilter*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return f->getRadius();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_filters_DropShadowColorFilter_setOpacity
  (JNIEnv * env, jobject thiz, jint radius) {
	wyDropShadowColorFilter* f = (wyDropShadowColorFilter*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	f->setOpacity(radius);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_filters_DropShadowColorFilter_getOpacity
  (JNIEnv * env, jobject thiz) {
	wyDropShadowColorFilter* f = (wyDropShadowColorFilter*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return f->getOpacity();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_filters_DropShadowColorFilter_setHighlightRadius
  (JNIEnv * env, jobject thiz, jint radius) {
	wyDropShadowColorFilter* f = (wyDropShadowColorFilter*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	f->setHighlightRadius(radius);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_filters_DropShadowColorFilter_getHighlightRadius
  (JNIEnv * env, jobject thiz) {
	wyDropShadowColorFilter* f = (wyDropShadowColorFilter*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return f->getHighlightRadius();
}
