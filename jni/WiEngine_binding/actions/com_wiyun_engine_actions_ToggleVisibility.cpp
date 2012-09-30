#include "com_wiyun_engine_actions_ToggleVisibility.h"
#include "wyToggleVisibility.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_actions_ToggleVisibility_nativeInit
  (JNIEnv * env, jobject thiz) {
	wyToggleVisibility* t = wyToggleVisibility::make();
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)t);
	t->retain();
	t->lazyRelease();
}
