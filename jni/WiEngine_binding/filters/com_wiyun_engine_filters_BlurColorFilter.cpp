#include "com_wiyun_engine_filters_BlurColorFilter.h"
#include "wyBlurColorFilter.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_filters_BlurColorFilter_nativeInit
  (JNIEnv * env, jobject thiz, jint radius) {
	wyBlurColorFilter* f = wyBlurColorFilter::make(radius);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)f);
	f->retain();
	f->lazyRelease();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_filters_BlurColorFilter_setRadius
  (JNIEnv * env, jobject thiz, jint radius) {
	wyBlurColorFilter* f = (wyBlurColorFilter*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	f->setRadius(radius);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_filters_BlurColorFilter_getRadius
  (JNIEnv * env, jobject thiz) {
	wyBlurColorFilter* f = (wyBlurColorFilter*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return f->getRadius();
}
