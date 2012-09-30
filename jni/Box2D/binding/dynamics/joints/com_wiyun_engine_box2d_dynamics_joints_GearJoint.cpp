#include "com_wiyun_engine_box2d_dynamics_joints_GearJoint.h"
#include "Box2D.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT jint JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_GearJoint_getJoint1
  (JNIEnv * env, jobject thiz) {
	b2GearJoint* j = (b2GearJoint*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return (jint)j->GetJoint1();
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_GearJoint_getJoint2
  (JNIEnv * env, jobject thiz) {
	b2GearJoint* j = (b2GearJoint*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return (jint)j->GetJoint2();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_GearJoint_setRatio
  (JNIEnv * env, jobject thiz, jfloat ratio) {
	b2GearJoint* j = (b2GearJoint*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	j->SetRatio(ratio);
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_GearJoint_getRatio
  (JNIEnv * env, jobject thiz) {
	b2GearJoint* j = (b2GearJoint*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return j->GetRatio();
}
