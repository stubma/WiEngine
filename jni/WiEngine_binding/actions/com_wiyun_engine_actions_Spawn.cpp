#include "com_wiyun_engine_actions_Spawn.h"
#include "wySpawn.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_actions_Spawn_nativeInit
  (JNIEnv * env, jobject thiz, jobject one, jobject two) {
	wyFiniteTimeAction* o = (wyFiniteTimeAction*)env->GetIntField(one, g_fid_BaseObject_mPointer);
	wyFiniteTimeAction* t = (wyFiniteTimeAction*)env->GetIntField(two, g_fid_BaseObject_mPointer);
	wySpawn* a = wySpawn::make(o, t);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)a);
	a->retain();
	a->lazyRelease();
}
