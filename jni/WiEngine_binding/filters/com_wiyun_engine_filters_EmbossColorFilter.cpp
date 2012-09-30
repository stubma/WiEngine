#include "com_wiyun_engine_filters_EmbossColorFilter.h"
#include "wyEmbossColorFilter.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_filters_EmbossColorFilter_nativeInit
  (JNIEnv * env, jobject thiz, jint grayLevel) {
	wyEmbossColorFilter* f = wyEmbossColorFilter::make(grayLevel);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)f);
	f->retain();
	f->lazyRelease();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_filters_EmbossColorFilter_setGrayLevel
  (JNIEnv * env, jobject thiz, jint grayLevel) {
	wyEmbossColorFilter* f = (wyEmbossColorFilter*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	f->setGrayLevel(grayLevel);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_filters_EmbossColorFilter_getGrayLevel
  (JNIEnv * env, jobject thiz) {
	wyEmbossColorFilter* f = (wyEmbossColorFilter*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return f->getGrayLevel();
}
