#include "com_wiyun_engine_transitions_FlipAngularTransition.h"
#include "wyFlipAngularTransition.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_transitions_FlipAngularTransition_nativeInit
  (JNIEnv * env, jobject thiz, jfloat duration, jobject inScene, jboolean toLeft) {
	wyScene* in = inScene == NULL ? NULL : (wyScene*)env->GetIntField(inScene, g_fid_BaseObject_mPointer);
	wyFlipAngularTransition* trans = WYNEW wyFlipAngularTransition(duration, in, toLeft);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)trans);
	wyObjectLazyRelease(trans);
}
