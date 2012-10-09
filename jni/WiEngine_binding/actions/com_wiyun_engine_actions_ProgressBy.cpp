#include "com_wiyun_engine_actions_ProgressBy.h"
#include "wyProgressBy.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_actions_ProgressBy_nativeInit
  (JNIEnv * env, jobject thiz, jfloat duration, jfloat deltaPercent) {
	wyProgressBy* a = wyProgressBy::make(duration, deltaPercent);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)a);
	a->retain();
	a->lazyRelease();
}
