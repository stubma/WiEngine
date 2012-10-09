#include "com_wiyun_engine_actions_grid_ShakyTiles3D.h"
#include "wyShakyTiles3D.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_actions_grid_ShakyTiles3D_nativeInit
  (JNIEnv * env, jobject thiz, jfloat duration, jint gridX, jint gridY, jint range, jint deltaRange, jboolean shakeZ) {
	wyShakyTiles3D* g = WYNEW wyShakyTiles3D(duration, gridX, gridY, range, deltaRange, shakeZ);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)g);
	wyObjectAutoRelease(g);
}
