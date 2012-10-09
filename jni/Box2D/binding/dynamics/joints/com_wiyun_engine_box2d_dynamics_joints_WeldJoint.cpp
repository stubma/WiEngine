#include "com_wiyun_engine_box2d_dynamics_joints_WeldJoint.h"
#include "Box2D.h"

extern jfieldID g_fid_BaseObject_mPointer;
extern jfieldID g_fid_WYPoint_x;
extern jfieldID g_fid_WYPoint_y;

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_WeldJoint_nativeGetLocalAnchorA
  (JNIEnv * env, jobject thiz, jobject p) {
	b2WeldJoint* j = (b2WeldJoint*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	env->SetFloatField(p, g_fid_WYPoint_x, j->GetLocalAnchorA().x);
	env->SetFloatField(p, g_fid_WYPoint_y, j->GetLocalAnchorA().y);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_WeldJoint_nativeGetLocalAnchorB
  (JNIEnv * env, jobject thiz, jobject p) {
	b2WeldJoint* j = (b2WeldJoint*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	env->SetFloatField(p, g_fid_WYPoint_x, j->GetLocalAnchorB().x);
	env->SetFloatField(p, g_fid_WYPoint_y, j->GetLocalAnchorB().y);
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_WeldJoint_getReferenceAngle
  (JNIEnv * env, jobject thiz) {
	b2WeldJoint* j = (b2WeldJoint*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return j->GetReferenceAngle();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_WeldJoint_setFrequency
  (JNIEnv * env, jobject thiz, jfloat freq) {
	b2WeldJoint* j = (b2WeldJoint*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	j->SetFrequency(freq);
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_WeldJoint_getFrequency
  (JNIEnv * env, jobject thiz) {
	b2WeldJoint* j = (b2WeldJoint*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return j->GetFrequency();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_WeldJoint_setDampingRatio
  (JNIEnv * env, jobject thiz, jfloat ratio) {
	b2WeldJoint* j = (b2WeldJoint*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	j->SetDampingRatio(ratio);
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_WeldJoint_getDampingRatio
  (JNIEnv * env, jobject thiz) {
	b2WeldJoint* j = (b2WeldJoint*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	j->GetDampingRatio();
}
