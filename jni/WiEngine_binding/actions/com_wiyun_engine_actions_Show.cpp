#include "com_wiyun_engine_actions_Show.h"
#include "wyShow.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_actions_Show_nativeInit
  (JNIEnv * env, jobject thiz) {
	wyShow* show = wyShow::make();
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)show);
	show->retain();
	show->lazyRelease();
}
