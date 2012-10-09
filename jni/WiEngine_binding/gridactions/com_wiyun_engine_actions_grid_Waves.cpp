#include "com_wiyun_engine_actions_grid_Waves.h"
#include "wyWaves.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_actions_grid_Waves_nativeInit
  (JNIEnv * env, jobject thiz, jfloat duration, jint gridX, jint gridY, jfloat amplitude, jint waves, jboolean vertical, jboolean horizontal) {
	wyWaves* g = WYNEW wyWaves(duration, gridX, gridY, amplitude, waves, vertical, horizontal);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)g);
	wyObjectAutoRelease(g);
}
