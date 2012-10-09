#include "com_wiyun_engine_actions_grid_WavesTiles3D.h"
#include "wyWavesTiles3D.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_actions_grid_WavesTiles3D_nativeInit
  (JNIEnv * env, jobject thiz, jfloat duration, jint gridX, jint gridY, jfloat amplitude, jint waves) {
	wyWavesTiles3D* g = WYNEW wyWavesTiles3D(duration, gridX, gridY, amplitude, waves);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)g);
	wyObjectAutoRelease(g);
}
