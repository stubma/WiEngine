#include "com_wiyun_engine_actions_FadeOut.h"
#include "wyFadeOut.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_actions_FadeOut_nativeInit
  (JNIEnv * env, jobject thiz, jfloat duration, jboolean includeChildren) {
	wyFadeOut* a = wyFadeOut::make(duration, includeChildren);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)a);
	a->retain();
	a->lazyRelease();
}
