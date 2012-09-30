#include "com_wiyun_engine_actions_grid_ShuffleTiles.h"
#include "wyShuffleTiles.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_actions_grid_ShuffleTiles_nativeInit
  (JNIEnv * env, jobject thiz, jfloat duration, jint gridX, jint gridY) {
	wyShuffleTiles* g = WYNEW wyShuffleTiles(duration, gridX, gridY);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)g);
	wyObjectAutoRelease(g);
}
