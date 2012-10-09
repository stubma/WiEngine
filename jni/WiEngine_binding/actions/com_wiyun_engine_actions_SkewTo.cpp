#include "com_wiyun_engine_actions_SkewTo.h"
#include "wySkewTo.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_actions_SkewTo_nativeInit
  (JNIEnv * env, jobject thiz, jfloat duration, jfloat startSkewX, jfloat endSkewX, jfloat startSkewY, jfloat endSkewY) {
	wySkewTo* s = wySkewTo::make(duration, startSkewX, endSkewX, startSkewY, endSkewY);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)s);
	s->retain();
	s->lazyRelease();
}
