#include "com_wiyun_engine_actions_ReverseTime.h"
#include "wyReverseTime.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_actions_ReverseTime_nativeInit
  (JNIEnv * env, jobject thiz, jobject other) {
	wyFiniteTimeAction* otherAction = (wyFiniteTimeAction*)env->GetIntField(other, g_fid_BaseObject_mPointer);
	wyReverseTime* r = wyReverseTime::make(otherAction);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)r);
	r->retain();
	r->lazyRelease();
}
