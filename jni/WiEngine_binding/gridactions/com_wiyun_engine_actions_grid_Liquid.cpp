#include "com_wiyun_engine_actions_grid_Liquid.h"
#include "wyLiquid.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_actions_grid_Liquid_nativeInit
  (JNIEnv * env, jobject thiz, jfloat duration, jint gridX, jint gridY, jfloat amplitude, jfloat deltaAmplitude, jfloat waves) {
	wyLiquid* g = WYNEW wyLiquid(duration, gridX, gridY, amplitude, deltaAmplitude, waves);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)g);
	wyObjectAutoRelease(g);
}
