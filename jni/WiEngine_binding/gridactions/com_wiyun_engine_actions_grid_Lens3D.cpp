#include "com_wiyun_engine_actions_grid_Lens3D.h"
#include "wyLens3D.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_actions_grid_Lens3D_nativeInit
  (JNIEnv * env, jobject thiz, jfloat duration, jint gridX, jint gridY, jfloat centerX, jfloat centerY,
		  jfloat deltaX, jfloat deltaY, jfloat radius, jfloat deltaRadius, jfloat lensEffect) {
	wyLens3D* g = WYNEW wyLens3D(duration, gridX, gridY, centerX, centerY,
			deltaX, deltaY, radius, deltaRadius, lensEffect);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)g);
	wyObjectAutoRelease(g);
}
