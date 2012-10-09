#include "com_wiyun_engine_transitions_CrossFadeTransition.h"
#include "wyCrossFadeTransition.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_transitions_CrossFadeTransition_nativeInit
  (JNIEnv * env, jobject thiz, jfloat duration, jobject inScene) {
	wyScene* in = inScene == NULL ? NULL : (wyScene*)env->GetIntField(inScene, g_fid_BaseObject_mPointer);
	wyCrossFadeTransition* trans = WYNEW wyCrossFadeTransition(duration, in);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)trans);
	wyObjectLazyRelease(trans);
}
