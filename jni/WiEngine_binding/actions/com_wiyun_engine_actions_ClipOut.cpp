#include "com_wiyun_engine_actions_ClipOut.h"
#include "wyClipOut.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_actions_ClipOut_nativeInit
(JNIEnv * env, jobject thiz, jfloat duration, jint direction) {
	wyClipOut* a = wyClipOut::make(duration, (wyClipOut::Direction)direction);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)a);
	a->retain();
	a->lazyRelease();
}
