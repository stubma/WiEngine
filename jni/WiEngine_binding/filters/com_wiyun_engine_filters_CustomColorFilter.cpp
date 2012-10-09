#include "com_wiyun_engine_filters_CustomColorFilter.h"
#include "wyCustomColorFilter.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_filters_CustomColorFilter_nativeInit
  (JNIEnv * env, jobject thiz, jobject delegate) {
	wyCustomColorFilter* f = wyCustomColorFilter::make(NULL, NULL);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)f);
	f->setDelegate(delegate);
	f->retain();
	f->lazyRelease();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_filters_CustomColorFilter_setDelegate
  (JNIEnv * env, jobject thiz, jobject delegate) {
	wyCustomColorFilter* f = (wyCustomColorFilter*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	f->setDelegate(delegate);
}
