#include "com_wiyun_engine_actions_Repeat.h"
#include "wyRepeat.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_actions_Repeat_nativeInit
  (JNIEnv * env, jobject thiz, jobject other, int times) {
	wyFiniteTimeAction* o = (wyFiniteTimeAction*)env->GetIntField(other, g_fid_BaseObject_mPointer);
	wyRepeat* a = wyRepeat::make(o, times);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)a);
	a->retain();
	a->lazyRelease();
}
