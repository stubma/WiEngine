#include "com_wiyun_engine_actions_ProgressTo.h"
#include "wyProgressTo.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_actions_ProgressTo_nativeInit
  (JNIEnv * env, jobject thiz, jfloat duration, jfloat from, jfloat to) {
	wyProgressTo* a = wyProgressTo::make(duration, from, to);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)a);
	a->retain();
	a->lazyRelease();
}
