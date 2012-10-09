#include "com_wiyun_engine_actions_grid_RightLineShrinkOut.h"
#include "wyRightLineShrinkOut.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_actions_grid_RightLineShrinkOut_nativeInit
  (JNIEnv * env, jobject thiz, jfloat duration, jint gridX, jint gridY) {
	wyRightLineShrinkOut* g = WYNEW wyRightLineShrinkOut(duration, gridX, gridY);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)g);
	wyObjectAutoRelease(g);
}
