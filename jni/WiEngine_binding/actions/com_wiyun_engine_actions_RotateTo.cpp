#include "com_wiyun_engine_actions_RotateTo.h"
#include "wyRotateTo.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_actions_RotateTo_nativeInit
  (JNIEnv * env, jobject thiz, jfloat duration, jfloat startAngle, jfloat endAngle) {
	wyRotateTo* rb = wyRotateTo::make(duration, startAngle, endAngle);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)rb);
	rb->retain();
	rb->lazyRelease();
}
