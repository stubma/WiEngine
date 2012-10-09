#include "com_wiyun_engine_actions_SkewBy.h"
#include "wySkewBy.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_actions_SkewBy_nativeInit
  (JNIEnv * env, jobject thiz, jfloat duration, jfloat skewX, jfloat skewY) {
	wySkewBy* s = wySkewBy::make(duration, skewX, skewY);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)s);
	s->retain();
	s->lazyRelease();
}
