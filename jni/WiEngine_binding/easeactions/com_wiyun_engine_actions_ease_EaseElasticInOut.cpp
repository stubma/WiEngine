#include "com_wiyun_engine_actions_ease_EaseElasticInOut.h"
#include "wyEaseElasticInOut.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_actions_ease_EaseElasticInOut_nativeInit
  (JNIEnv * env, jobject thiz, jobject action, jfloat period) {
	wyIntervalAction* wrapped = action == NULL ? NULL : (wyIntervalAction*)env->GetIntField(action, g_fid_BaseObject_mPointer);
	wyEaseElasticInOut* ease = WYNEW wyEaseElasticInOut(period, wrapped);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)ease);
	wyObjectLazyRelease(ease);
}
