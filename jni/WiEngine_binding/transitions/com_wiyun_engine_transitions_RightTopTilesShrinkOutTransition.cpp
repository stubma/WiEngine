#include "com_wiyun_engine_transitions_RightTopTilesShrinkOutTransition.h"
#include "wyRightTopTilesShrinkOutTransition.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_transitions_RightTopTilesShrinkOutTransition_nativeInit
  (JNIEnv * env, jobject thiz, jfloat duration, jobject inScene, int rows, int cols) {
	wyScene* in = inScene == NULL ? NULL : (wyScene*)env->GetIntField(inScene, g_fid_BaseObject_mPointer);
	wyRightTopTilesShrinkOutTransition* trans = WYNEW wyRightTopTilesShrinkOutTransition(duration, in, rows, cols);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)trans);
	wyObjectLazyRelease(trans);
}
