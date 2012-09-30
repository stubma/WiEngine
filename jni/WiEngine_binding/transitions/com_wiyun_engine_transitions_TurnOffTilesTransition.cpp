#include "com_wiyun_engine_transitions_TurnOffTilesTransition.h"
#include "wyTurnOffTilesTransition.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_transitions_TurnOffTilesTransition_nativeInit
  (JNIEnv * env, jobject thiz, jfloat duration, jobject inScene, jint rows, jint cols) {
	wyScene* in = inScene == NULL ? NULL : (wyScene*)env->GetIntField(inScene, g_fid_BaseObject_mPointer);
	wyTurnOffTilesTransition* trans = WYNEW wyTurnOffTilesTransition(duration, in, rows, cols);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)trans);
	wyObjectLazyRelease(trans);
}
