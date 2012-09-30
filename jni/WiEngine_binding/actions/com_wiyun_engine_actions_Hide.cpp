#include "com_wiyun_engine_actions_Hide.h"
#include "wyHide.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_actions_Hide_nativeInit
  (JNIEnv * env, jobject thiz) {
	wyHide* hide = wyHide::make();
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)hide);
	hide->retain();
	hide->lazyRelease();
}
