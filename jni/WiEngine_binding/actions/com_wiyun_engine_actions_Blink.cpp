#include "com_wiyun_engine_actions_Blink.h"
#include "wyBlink.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_actions_Blink_nativeInit
  (JNIEnv * env, jobject thiz, jfloat duration, jint times) {
	wyBlink* blink = wyBlink::make(duration, times);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)blink);
	blink->retain();
	blink->lazyRelease();
}
