#include "com_wiyun_engine_dialog_DialogPopupTransition.h"
#include "wyDialogPopupTransition.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_dialog_DialogPopupTransition_nativeInit
  (JNIEnv * env, jobject thiz) {
	wyDialogPopupTransition* t = wyDialogPopupTransition::make();
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)t);
	t->retain();
	t->lazyRelease();
}
