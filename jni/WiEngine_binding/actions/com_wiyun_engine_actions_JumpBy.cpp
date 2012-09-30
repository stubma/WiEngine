#include "com_wiyun_engine_actions_JumpBy.h"
#include "wyJumpBy.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_actions_JumpBy_nativeInit
  (JNIEnv * env, jobject thiz, jfloat duration, jfloat x, jfloat y, jfloat height, jint jumps) {
	wyJumpBy* a = wyJumpBy::make(duration, x, y, height, jumps);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)a);
	a->retain();
	a->lazyRelease();
}
