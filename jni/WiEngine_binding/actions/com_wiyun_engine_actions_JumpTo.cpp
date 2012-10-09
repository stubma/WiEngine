#include "com_wiyun_engine_actions_JumpTo.h"
#include "wyJumpTo.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_actions_JumpTo_nativeInit
  (JNIEnv * env, jobject thiz, jfloat duration, jfloat startX, jfloat startY, jfloat endX, jfloat endY, jfloat height, jint jumps) {
	wyJumpTo* a = wyJumpTo::make(duration, startX, startY, endX, endY, height, jumps);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)a);
	a->retain();
	a->lazyRelease();
}
