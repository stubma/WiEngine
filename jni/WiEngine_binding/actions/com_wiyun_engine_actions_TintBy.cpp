#include "com_wiyun_engine_actions_TintBy.h"
#include "wyTintBy.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_actions_TintBy_nativeInit
  (JNIEnv * env, jobject thiz, jfloat duration, jint r, jint g, jint b) {
	wyTintBy* t = wyTintBy::make(duration, r, g, b);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)t);
	t->retain();
	t->lazyRelease();
}
