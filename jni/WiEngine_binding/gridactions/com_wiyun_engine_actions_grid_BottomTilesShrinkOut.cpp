#include "com_wiyun_engine_actions_grid_BottomTilesShrinkOut.h"
#include "wyBottomTilesShrinkOut.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_actions_grid_BottomTilesShrinkOut_nativeInit
  (JNIEnv * env, jobject thiz, jfloat duration, jint gridX, jint gridY) {
	wyBottomTilesShrinkOut* g = WYNEW wyBottomTilesShrinkOut(duration, gridX, gridY);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)g);
	wyObjectAutoRelease(g);
}
