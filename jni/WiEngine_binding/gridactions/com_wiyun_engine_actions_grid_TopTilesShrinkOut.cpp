#include "com_wiyun_engine_actions_grid_TopTilesShrinkOut.h"
#include "wyTopTilesShrinkOut.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_actions_grid_TopTilesShrinkOut_nativeInit
  (JNIEnv * env, jobject thiz, jfloat duration, jint gridX, jint gridY) {
	wyTopTilesShrinkOut* g = WYNEW wyTopTilesShrinkOut(duration, gridX, gridY);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)g);
	wyObjectAutoRelease(g);
}
