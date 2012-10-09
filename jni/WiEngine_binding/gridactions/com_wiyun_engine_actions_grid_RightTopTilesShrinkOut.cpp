#include "com_wiyun_engine_actions_grid_RightTopTilesShrinkOut.h"
#include "wyRightTopTilesShrinkOut.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_actions_grid_RightTopTilesShrinkOut_nativeInit
  (JNIEnv * env, jobject thiz, jfloat duration, jint gridX, jint gridY) {
	wyRightTopTilesShrinkOut* g = WYNEW wyRightTopTilesShrinkOut(duration, gridX, gridY);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)g);
	wyObjectAutoRelease(g);
}
