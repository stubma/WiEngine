#include "com_wiyun_engine_actions_FadeIn.h"
#include "wyFadeIn.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_actions_FadeIn_nativeInit
  (JNIEnv * env, jobject thiz, jfloat duration, jboolean includeChildren) {
	wyFadeIn* a = wyFadeIn::make(duration, includeChildren);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)a);
	a->retain();
	a->lazyRelease();
}
