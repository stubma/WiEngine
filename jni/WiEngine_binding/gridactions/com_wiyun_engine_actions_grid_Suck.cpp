#include "com_wiyun_engine_actions_grid_Suck.h"
#include "wySuck.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_actions_grid_Suck_nativeInit
  (JNIEnv * env, jobject thiz, jfloat duration, jint gridX, jint gridY, jfloat suckX, jfloat suckY) {
	wySuck* g = wySuck::make(duration, gridX, gridY, suckX, suckY);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)g);
	g->retain();
	g->lazyRelease();
}
