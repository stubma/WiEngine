#include "com_wiyun_engine_actions_Speed.h"
#include "wySpeed.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_actions_Speed_nativeInit
  (JNIEnv * env, jobject thiz, jobject other, jfloat speed) {
	wyAction* otherAction = (wyAction*)env->GetIntField(other, g_fid_BaseObject_mPointer);
	wySpeed* s = wySpeed::make(otherAction, speed);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)s);
	s->retain();
	s->lazyRelease();
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_actions_Speed_getSpeed
  (JNIEnv * env, jobject thiz) {
	wySpeed* s = (wySpeed*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return s->getSpeed();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_actions_Speed_setSpeed
  (JNIEnv * env, jobject thiz, jfloat speed) {
	wySpeed* s = (wySpeed*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	s->setSpeed(speed);
}
