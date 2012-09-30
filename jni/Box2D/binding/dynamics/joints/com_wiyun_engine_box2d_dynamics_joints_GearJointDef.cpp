#include "com_wiyun_engine_box2d_dynamics_joints_GearJointDef.h"
#include "Box2D.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_GearJointDef_nativeNew
  (JNIEnv * env, jobject thiz) {
	b2GearJointDef* jd = new b2GearJointDef();
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)jd);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_GearJointDef_setJoint1
  (JNIEnv * env, jobject thiz, jobject joint) {
	b2GearJointDef* jd = (b2GearJointDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	b2Joint* j = (b2Joint*)env->GetIntField(joint, g_fid_BaseObject_mPointer);
	jd->joint1 = j;
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_GearJointDef_getJoint1
  (JNIEnv * env, jobject thiz) {
	b2GearJointDef* jd = (b2GearJointDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return (jint)jd->joint1;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_GearJointDef_setJoint2
  (JNIEnv * env, jobject thiz, jobject joint) {
	b2GearJointDef* jd = (b2GearJointDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	b2Joint* j = (b2Joint*)env->GetIntField(joint, g_fid_BaseObject_mPointer);
	jd->joint2 = j;
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_GearJointDef_getJoint2
  (JNIEnv * env, jobject thiz) {
	b2GearJointDef* jd = (b2GearJointDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return (jint)jd->joint2;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_GearJointDef_setRatio
  (JNIEnv * env, jobject thiz, jfloat ratio) {
	b2GearJointDef* jd = (b2GearJointDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	jd->ratio = ratio;
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_GearJointDef_getRatio
  (JNIEnv * env, jobject thiz) {
	b2GearJointDef* jd = (b2GearJointDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return jd->ratio;
}
