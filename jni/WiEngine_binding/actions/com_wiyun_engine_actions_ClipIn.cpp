#include "com_wiyun_engine_actions_ClipIn.h"
#include "wyClipIn.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_actions_ClipIn_nativeInit
(JNIEnv * env, jobject thiz, jfloat duration, jint direction) {
	wyClipIn* a = wyClipIn::make(duration, (wyClipIn::Direction)direction);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)a);
	a->retain();
	a->lazyRelease();
}
