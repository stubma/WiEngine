#include "com_wiyun_engine_actions_FadeTo.h"
#include "wyFadeTo.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_actions_FadeTo_nativeInit
  (JNIEnv * env, jobject thiz, jfloat duration, jint fromAlpha, jint toAlpha, jboolean includeChildren) {
	wyFadeTo* a = wyFadeTo::make(duration, fromAlpha, toAlpha, includeChildren);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)a);
	a->retain();
	a->lazyRelease();
}
