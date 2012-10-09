#include "com_wiyun_engine_filters_MappingColorFilter.h"
#include "wyMappingColorFilter.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_filters_MappingColorFilter_nativeInit
  (JNIEnv * env, jobject thiz) {
	wyMappingColorFilter* f = wyMappingColorFilter::make();
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)f);
	f->retain();
	f->lazyRelease();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_filters_MappingColorFilter_mapColor
  (JNIEnv * env, jobject thiz, jint from, jint to, jint fromMask, jint toMask) {
	wyMappingColorFilter* f = (wyMappingColorFilter*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	f->mapColor(from, to, fromMask, toMask);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_filters_MappingColorFilter_unmapColor
  (JNIEnv * env, jobject thiz, jint from) {
	wyMappingColorFilter* f = (wyMappingColorFilter*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	f->unmapColor(from);
}
