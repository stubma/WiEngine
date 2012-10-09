#include "com_wiyun_engine_actions_grid_GridFlipX.h"
#include "wyGridFlipX.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_actions_grid_GridFlipX_nativeInit
  (JNIEnv * env, jobject thiz, jfloat duration) {
	wyGridFlipX* g = WYNEW wyGridFlipX(duration);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)g);
	wyObjectAutoRelease(g);
}
