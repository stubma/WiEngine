#include "com_wiyun_engine_actions_grid_Shaky3D.h"
#include "wyShaky3D.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_actions_grid_Shaky3D_nativeInit
  (JNIEnv * env, jobject thiz, jfloat duration, jint gridX, jint gridY, jint range, jint deltaRange, jboolean shakeZ) {
	wyShaky3D* g = WYNEW wyShaky3D(duration, gridX, gridY, range, deltaRange, shakeZ);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)g);
	wyObjectAutoRelease(g);
}
