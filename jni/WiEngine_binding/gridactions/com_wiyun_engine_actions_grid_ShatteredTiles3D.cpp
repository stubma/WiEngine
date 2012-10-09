#include "com_wiyun_engine_actions_grid_ShatteredTiles3D.h"
#include "wyShatteredTiles3D.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_actions_grid_ShatteredTiles3D_nativeInit
  (JNIEnv * env, jobject thiz, jfloat duration, jint gridX, jint gridY, jint range, jboolean shatterZ) {
	wyShatteredTiles3D* g = WYNEW wyShatteredTiles3D(duration, gridX, gridY, range, shatterZ);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)g);
	wyObjectAutoRelease(g);
}
