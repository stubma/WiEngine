#include "com_wiyun_engine_actions_ScaleTo.h"
#include "wyScaleTo.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_actions_ScaleTo_nativeInit
  (JNIEnv * env, jobject thiz, jfloat duration, jfloat startScaleX, jfloat startScaleY, jfloat endScaleX, jfloat endScaleY) {
	wyScaleTo* st = wyScaleTo::make(duration, startScaleX, startScaleY, endScaleX, endScaleY);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)st);
	st->retain();
	st->lazyRelease();
}
