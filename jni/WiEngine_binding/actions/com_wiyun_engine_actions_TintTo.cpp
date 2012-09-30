#include "com_wiyun_engine_actions_TintTo.h"
#include "wyTintTo.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_actions_TintTo_nativeInit
  (JNIEnv * env, jobject thiz, jfloat duration, jint fromR, jint fromG, jint fromB, jint toR, jint toG, jint toB) {
	wyTintTo* t = wyTintTo::make(duration, fromR, fromG, fromB, toR, toG, toB);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)t);
	t->retain();
	t->lazyRelease();
}
