#include "com_wiyun_engine_actions_Animate.h"
#include "wyAnimate.h"
#include "wyNode.h"
#include "wyLog.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_actions_Animate_nativeInit
  (JNIEnv * env, jobject thiz, jobject animation, jboolean fillAfter) {
	jclass clazz = env->GetObjectClass(animation);
	wyAnimation* anim = (wyAnimation*)env->GetIntField(animation, g_fid_BaseObject_mPointer);
	wyAnimate* a = wyAnimate::make(anim, fillAfter);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)a);
	a->retain();
	a->lazyRelease();
	env->DeleteLocalRef(clazz);
}
