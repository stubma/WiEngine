#include "com_wiyun_engine_transitions_ClipOutTransition.h"
#include "wyClipOutTransition.h"
#include "wyClipOut.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_transitions_ClipOutTransition_nativeInit
  (JNIEnv * env, jobject thiz, jfloat duration, jobject inScene, jint direction) {
	wyScene* in = inScene == NULL ? NULL : (wyScene*)env->GetIntField(inScene, g_fid_BaseObject_mPointer);
	wyClipOutTransition* trans = wyClipOutTransition::make(duration, in, (wyClipOut::Direction)direction);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)trans);
	trans->retain();
	trans->lazyRelease();
}
