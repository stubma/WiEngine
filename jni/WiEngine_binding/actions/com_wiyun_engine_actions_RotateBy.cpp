#include "com_wiyun_engine_actions_RotateBy.h"
#include "wyRotateBy.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_actions_RotateBy_nativeInit
  (JNIEnv * env, jobject thiz, jfloat duration, jfloat angle) {
	wyRotateBy* rb = wyRotateBy::make(duration, angle);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)rb);
	rb->retain();
	rb->lazyRelease();
}
