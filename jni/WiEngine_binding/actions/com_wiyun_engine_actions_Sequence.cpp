#include "com_wiyun_engine_actions_Sequence.h"
#include "wySequence.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_actions_Sequence_nativeInit
  (JNIEnv * env, jobject thiz, jobject one, jobject two) {
	wyFiniteTimeAction* fta1 = (wyFiniteTimeAction*)env->GetIntField(one, g_fid_BaseObject_mPointer);
	wyFiniteTimeAction* fta2 = (wyFiniteTimeAction*)env->GetIntField(two, g_fid_BaseObject_mPointer);
	wySequence* seq = wySequence::make(fta1, fta2, NULL);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)seq);
	seq->retain();
	seq->lazyRelease();
}
