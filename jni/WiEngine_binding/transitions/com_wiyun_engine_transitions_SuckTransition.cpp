#include "com_wiyun_engine_transitions_SuckTransition.h"
#include "wySuckTransition.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_transitions_SuckTransition_nativeInit
  (JNIEnv * env, jobject thiz, jfloat duration, jobject inScene, jfloat suckX, jfloat suckY) {
	wyScene* in = inScene == NULL ? NULL : (wyScene*)env->GetIntField(inScene, g_fid_BaseObject_mPointer);
	wySuckTransition* trans = wySuckTransition::make(duration, in, suckX, suckY);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)trans);
	trans->retain();
	trans->lazyRelease();
}
