#include "com_wiyun_engine_actions_ease_EaseElasticOut.h"
#include "wyEaseElasticOut.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_actions_ease_EaseElasticOut_nativeInit
  (JNIEnv * env, jobject thiz, jobject action, jfloat period) {
	wyIntervalAction* wrapped = action == NULL ? NULL : (wyIntervalAction*)env->GetIntField(action, g_fid_BaseObject_mPointer);
	wyEaseElasticOut* ease = WYNEW wyEaseElasticOut(period, wrapped);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)ease);
	wyObjectLazyRelease(ease);
}
