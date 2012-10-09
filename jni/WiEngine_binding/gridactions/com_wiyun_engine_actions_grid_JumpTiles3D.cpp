#include "com_wiyun_engine_actions_grid_JumpTiles3D.h"
#include "wyJumpTiles3D.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_actions_grid_JumpTiles3D_nativeInit
  (JNIEnv * env, jobject thiz, jfloat duration, jint gridX, jint gridY, jfloat amplitude, jint jumps) {
	wyJumpTiles3D* g = WYNEW wyJumpTiles3D(duration, gridX, gridY, amplitude, jumps);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)g);
	wyObjectAutoRelease(g);
}
