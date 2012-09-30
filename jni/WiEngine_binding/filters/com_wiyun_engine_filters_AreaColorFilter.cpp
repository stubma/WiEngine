#include "com_wiyun_engine_filters_AreaColorFilter.h"
#include "wyAreaColorFilter.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_filters_AreaColorFilter_nativeInit
  (JNIEnv * env, jobject thiz) {
	wyAreaColorFilter* f = wyAreaColorFilter::make();
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)f);
	f->retain();
	f->lazyRelease();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_filters_AreaColorFilter_mapPoint
  (JNIEnv * env, jobject thiz, jint x, jint y, jint from, jint to, jint fromMask, jint toMask) {
	wyAreaColorFilter* f = (wyAreaColorFilter*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	f->mapPoint(x, y, from, to, fromMask, toMask);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_filters_AreaColorFilter_removePoint
  (JNIEnv * env, jobject thiz, jint x, jint y) {
	wyAreaColorFilter* f = (wyAreaColorFilter*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	f->removePoint(x, y);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_filters_AreaColorFilter_mapLine
  (JNIEnv * env, jobject thiz, jint x1, jint y1, jint x2, jint y2, jint from, jint to, jint fromMask, jint toMask) {
	wyAreaColorFilter* f = (wyAreaColorFilter*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	f->mapLine(x1, y1, x2, y2, from, to, fromMask, toMask);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_filters_AreaColorFilter_removeLine
  (JNIEnv * env, jobject thiz, jint x1, jint y1, jint x2, jint y2) {
	wyAreaColorFilter* f = (wyAreaColorFilter*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	f->removeLine(x1, y1, x2, y2);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_filters_AreaColorFilter_mapRect
  (JNIEnv * env, jobject thiz, jint x, jint y, jint w, jint h, jint from, jint to, jint fromMask, jint toMask) {
	wyAreaColorFilter* f = (wyAreaColorFilter*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	f->mapRect(x, y, w, h, from, to, fromMask, toMask);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_filters_AreaColorFilter_removeRect
  (JNIEnv * env, jobject thiz, jint x, jint y, jint w, jint h) {
	wyAreaColorFilter* f = (wyAreaColorFilter*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	f->removeRect(x, y, w, h);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_filters_AreaColorFilter_mapCircle
  (JNIEnv * env, jobject thiz, jint centerX, jint centerY, jint radius, jint from, jint to, jint fromMask, jint toMask) {
	wyAreaColorFilter* f = (wyAreaColorFilter*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	f->mapCircle(centerX, centerY, radius, from, to, fromMask, toMask);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_filters_AreaColorFilter_removeCircle
  (JNIEnv * env, jobject thiz, jint centerX, jint centerY, jint radius) {
	wyAreaColorFilter* f = (wyAreaColorFilter*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	f->removeCircle(centerX, centerY, radius);
}
