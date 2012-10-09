#include "com_wiyun_engine_actions_Place.h"
#include "wyPlace.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_actions_Place_nativeInit
  (JNIEnv * env, jobject thiz, jfloat x, jfloat y) {
	wyPlace* p = wyPlace::make(x, y);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)p);
	p->retain();
	p->lazyRelease();
}
