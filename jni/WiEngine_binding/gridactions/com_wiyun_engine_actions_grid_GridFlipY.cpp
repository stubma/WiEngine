#include "com_wiyun_engine_actions_grid_GridFlipY.h"
#include "wyGridFlipY.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_actions_grid_GridFlipY_nativeInit
  (JNIEnv * env, jobject thiz, jfloat duration) {
	wyGridFlipY* g = WYNEW wyGridFlipY(duration);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)g);
	wyObjectAutoRelease(g);
}
