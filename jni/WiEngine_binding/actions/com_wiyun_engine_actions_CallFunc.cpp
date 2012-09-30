#include "com_wiyun_engine_actions_CallFunc.h"
#include "wyCallFunc.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_actions_CallFunc_nativeInit
  (JNIEnv * env, jobject thiz, jobject ts) {
	wyTargetSelector* selector = wyTargetSelector::make(ts);
	wyCallFunc* call = wyCallFunc::make(selector);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)call);
	call->retain();
	call->lazyRelease();
}
