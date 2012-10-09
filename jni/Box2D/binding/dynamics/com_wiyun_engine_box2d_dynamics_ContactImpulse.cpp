#include "com_wiyun_engine_box2d_dynamics_ContactImpulse.h"
#include "Box2D.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_box2d_dynamics_ContactImpulse_getNormalImpulse
  (JNIEnv * env, jobject thiz, jint index) {
	b2ContactImpulse* i = (b2ContactImpulse*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return i->normalImpulses[index];
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_box2d_dynamics_ContactImpulse_getTangentImpulse
  (JNIEnv * env, jobject thiz, jint index) {
	b2ContactImpulse* i = (b2ContactImpulse*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return i->tangentImpulses[index];
}
