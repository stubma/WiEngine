#include "com_wiyun_engine_actions_Shake.h"
#include "wyShake.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_actions_Shake_nativeInit
  (JNIEnv * env, jobject thiz, jfloat duration, jfloat radius) {
	wyShake* s = wyShake::make(duration, radius);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)s);
	s->retain();
	s->lazyRelease();
}
