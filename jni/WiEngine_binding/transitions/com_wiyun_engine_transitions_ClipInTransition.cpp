#include "com_wiyun_engine_transitions_ClipInTransition.h"
#include "wyClipInTransition.h"
#include "wyClipIn.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_transitions_ClipInTransition_nativeInit
  (JNIEnv * env, jobject thiz, jfloat duration, jobject inScene, jint direction) {
	wyScene* in = inScene == NULL ? NULL : (wyScene*)env->GetIntField(inScene, g_fid_BaseObject_mPointer);
	wyClipInTransition* trans = wyClipInTransition::make(duration, in, (wyClipIn::Direction)direction);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)trans);
	trans->retain();
	trans->lazyRelease();
}
