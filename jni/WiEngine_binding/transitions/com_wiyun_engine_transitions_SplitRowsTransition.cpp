#include "com_wiyun_engine_transitions_SplitRowsTransition.h"
#include "wySplitRowsTransition.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_transitions_SplitRowsTransition_nativeInit
  (JNIEnv * env, jobject thiz, jfloat duration, jobject inScene, jint rows) {
	wyScene* in = inScene == NULL ? NULL : (wyScene*)env->GetIntField(inScene, g_fid_BaseObject_mPointer);
	wySplitRowsTransition* trans = WYNEW wySplitRowsTransition(duration, in, rows);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)trans);
	wyObjectLazyRelease(trans);
}
