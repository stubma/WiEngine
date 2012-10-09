#include "com_wiyun_engine_actions_ScaleBy.h"
#include "wyScaleBy.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_actions_ScaleBy_nativeInit
  (JNIEnv * env, jobject thiz, jfloat duration, jfloat scaleX, jfloat scaleY) {
	wyScaleBy* s = wyScaleBy::make(duration, scaleX, scaleY);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)s);
	s->retain();
	s->lazyRelease();
}
