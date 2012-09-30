#include "com_wiyun_engine_filters_LightingColorFilter.h"
#include "wyLightingColorFilter.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_filters_LightingColorFilter_nativeInit
  (JNIEnv * env, jobject thiz, jint mul, jint add) {
	wyLightingColorFilter* f = wyLightingColorFilter::make(mul, add);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)f);
	f->retain();
	f->lazyRelease();
}
