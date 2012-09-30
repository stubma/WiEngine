#include "com_wiyun_engine_actions_RepeatForever.h"
#include "wyRepeatForever.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_actions_RepeatForever_nativeInit
  (JNIEnv * env, jobject thiz, jobject other) {
	wyIntervalAction* otherAction = (wyIntervalAction*)env->GetIntField(other, g_fid_BaseObject_mPointer);
	wyRepeatForever* repeat = wyRepeatForever::make(otherAction);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)repeat);
	repeat->retain();
	repeat->lazyRelease();
}
