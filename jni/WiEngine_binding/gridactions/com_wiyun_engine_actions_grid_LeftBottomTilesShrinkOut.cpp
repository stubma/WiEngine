#include "com_wiyun_engine_actions_grid_LeftBottomTilesShrinkOut.h"
#include "wyLeftBottomTilesShrinkOut.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_actions_grid_LeftBottomTilesShrinkOut_nativeInit
  (JNIEnv * env, jobject thiz, jfloat duration, jint gridX, jint gridY) {
	wyLeftBottomTilesShrinkOut* g = WYNEW wyLeftBottomTilesShrinkOut(duration, gridX, gridY);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)g);
	wyObjectAutoRelease(g);
}
