#include "com_wiyun_engine_transitions_PageTurn3DTransition.h"
#include "wyPageTurn3DTransition.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_transitions_PageTurn3DTransition_nativeInit
  (JNIEnv * env, jobject thiz, jfloat duration, jobject inScene) {
	wyScene* in = inScene == NULL ? NULL : (wyScene*)env->GetIntField(inScene, g_fid_BaseObject_mPointer);
	wyPageTurn3DTransition* trans = WYNEW wyPageTurn3DTransition(duration, in);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)trans);
	wyObjectLazyRelease(trans);
}
