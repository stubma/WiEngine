#include "com_wiyun_engine_actions_grid_TurnOffTiles.h"
#include "wyTurnOffTiles.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_actions_grid_TurnOffTiles_nativeInit
  (JNIEnv * env, jobject thiz, jfloat duration, jint gridX, jint gridY) {
	wyTurnOffTiles* g = WYNEW wyTurnOffTiles(duration, gridX, gridY);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)g);
	wyObjectAutoRelease(g);
}
