#include "com_wiyun_engine_actions_OrbitCamera.h"
#include "wyOrbitCamera.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_actions_OrbitCamera_nativeInit
  (JNIEnv * env, jobject thiz, jfloat duration, jfloat r, jfloat dr, jfloat z, jfloat dz, jfloat x, jfloat dx) {
	wyOrbitCamera* oc = wyOrbitCamera::make(duration, r, dr, z, dz, x, dx);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)oc);
	oc->retain();
	oc->lazyRelease();
}
