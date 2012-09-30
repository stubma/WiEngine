#include "com_wiyun_engine_transitions_FlipXTransition.h"
#include "wyFlipXTransition.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_transitions_FlipXTransition_nativeInit
  (JNIEnv * env, jobject thiz, jfloat duration, jobject inScene, jboolean toLeft) {
	wyScene* in = inScene == NULL ? NULL : (wyScene*)env->GetIntField(inScene, g_fid_BaseObject_mPointer);
	wyFlipXTransition* trans = WYNEW wyFlipXTransition(duration, in, toLeft);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)trans);
	wyObjectLazyRelease(trans);
}
