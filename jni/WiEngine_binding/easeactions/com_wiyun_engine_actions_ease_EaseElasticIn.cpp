#include "com_wiyun_engine_actions_ease_EaseElasticIn.h"
#include "wyEaseElasticIn.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_actions_ease_EaseElasticIn_nativeInit
  (JNIEnv * env, jobject thiz, jobject action, jfloat period) {
	wyIntervalAction* wrapped = action == NULL ? NULL : (wyIntervalAction*)env->GetIntField(action, g_fid_BaseObject_mPointer);
	wyEaseElasticIn* ease = WYNEW wyEaseElasticIn(period, wrapped);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)ease);
	wyObjectLazyRelease(ease);
}
