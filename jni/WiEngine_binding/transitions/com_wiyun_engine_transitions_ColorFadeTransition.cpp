#include "com_wiyun_engine_transitions_ColorFadeTransition.h"
#include "wyColorFadeTransition.h"
#include "wyUtils_android.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_transitions_ColorFadeTransition_nativeInit
  (JNIEnv * env, jobject thiz, jfloat duration, jobject inScene, jobject color) {
	wyScene* in = inScene == NULL ? NULL : (wyScene*)env->GetIntField(inScene, g_fid_BaseObject_mPointer);
	wyColor3B c = wyUtils_android::to_wyColor3B( color);
	wyColorFadeTransition* trans = WYNEW wyColorFadeTransition(duration, in, c);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)trans);
	wyObjectLazyRelease(trans);
}
