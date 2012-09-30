#include "com_wiyun_engine_actions_DelayTime.h"
#include "wyDelayTime.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_actions_DelayTime_nativeInit
  (JNIEnv * env, jobject thiz, jfloat duration) {
	wyDelayTime* delay = wyDelayTime::make(duration);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)delay);
	delay->retain();
	delay->lazyRelease();
}
