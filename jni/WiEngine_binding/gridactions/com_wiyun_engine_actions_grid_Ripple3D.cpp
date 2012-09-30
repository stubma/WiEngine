#include "com_wiyun_engine_actions_grid_Ripple3D.h"
#include "wyRipple3D.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_actions_grid_Ripple3D_nativeInit
  (JNIEnv * env, jobject thiz, jfloat duration, jint gridX, jint gridY, jfloat centerX, jfloat centerY,
			jfloat deltaX, jfloat deltaY, jfloat radius, jfloat deltaRadius, jfloat amplitude, jfloat deltaAmplitude, jfloat waves) {
	wyRipple3D* g = WYNEW wyRipple3D(duration, gridX, gridY, centerX, centerY,
			deltaX, deltaY, radius, deltaRadius, amplitude, deltaAmplitude, waves);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)g);
	wyObjectAutoRelease(g);
}
