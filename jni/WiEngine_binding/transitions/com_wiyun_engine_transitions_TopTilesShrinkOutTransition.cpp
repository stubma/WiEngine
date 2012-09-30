#include "com_wiyun_engine_transitions_TopTilesShrinkOutTransition.h"
#include "wyTopTilesShrinkOutTransition.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_transitions_TopTilesShrinkOutTransition_nativeInit
  (JNIEnv * env, jobject thiz, jfloat duration, jobject inScene, int rows, int cols) {
	wyScene* in = inScene == NULL ? NULL : (wyScene*)env->GetIntField(inScene, g_fid_BaseObject_mPointer);
	wyTopTilesShrinkOutTransition* trans = WYNEW wyTopTilesShrinkOutTransition(duration, in, rows, cols);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)trans);
	wyObjectLazyRelease(trans);
}
