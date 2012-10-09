#include "com_wiyun_engine_transitions_TopSlideInTransition.h"
#include "wyTopSlideInTransition.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_transitions_TopSlideInTransition_nativeInit
  (JNIEnv * env, jobject thiz, jfloat duration, jobject inScene) {
	wyScene* in = inScene == NULL ? NULL : (wyScene*)env->GetIntField(inScene, g_fid_BaseObject_mPointer);
	wyTopSlideInTransition* trans = WYNEW wyTopSlideInTransition(duration, in);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)trans);
	wyObjectLazyRelease(trans);
}
