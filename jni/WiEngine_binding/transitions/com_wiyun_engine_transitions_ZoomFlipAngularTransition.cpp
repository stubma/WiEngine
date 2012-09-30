#include "com_wiyun_engine_transitions_ZoomFlipAngularTransition.h"
#include "wyZoomFlipAngularTransition.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_transitions_ZoomFlipAngularTransition_nativeInit
  (JNIEnv * env, jobject thiz, jfloat duration, jobject inScene, jboolean toLeft, jfloat scale) {
	wyScene* in = inScene == NULL ? NULL : (wyScene*)env->GetIntField(inScene, g_fid_BaseObject_mPointer);
	wyZoomFlipAngularTransition* trans = WYNEW wyZoomFlipAngularTransition(duration, in, toLeft, scale);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)trans);
	wyObjectLazyRelease(trans);
}
