#include "com_wiyun_engine_box2d_dynamics_joints_FrictionJoint.h"
#include "Box2D.h"

extern jfieldID g_fid_BaseObject_mPointer;
extern jfieldID g_fid_WYPoint_x;
extern jfieldID g_fid_WYPoint_y;

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_FrictionJoint_nativeGetLocalAnchorA
  (JNIEnv * env, jobject thiz, jobject p) {
	b2FrictionJoint* j = (b2FrictionJoint*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	env->SetFloatField(p, g_fid_WYPoint_x, j->GetLocalAnchorA().x);
	env->SetFloatField(p, g_fid_WYPoint_y, j->GetLocalAnchorA().y);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_FrictionJoint_nativeGetLocalAnchorB
  (JNIEnv * env, jobject thiz, jobject p) {
	b2FrictionJoint* j = (b2FrictionJoint*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	env->SetFloatField(p, g_fid_WYPoint_x, j->GetLocalAnchorB().x);
	env->SetFloatField(p, g_fid_WYPoint_y, j->GetLocalAnchorB().y);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_FrictionJoint_setMaxForce
  (JNIEnv * env, jobject thiz, jfloat force) {
	b2FrictionJoint* j = (b2FrictionJoint*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	j->SetMaxForce(force);
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_FrictionJoint_getMaxForce
  (JNIEnv * env, jobject thiz) {
	b2FrictionJoint* j = (b2FrictionJoint*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return j->GetMaxForce();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_FrictionJoint_setMaxTorque
  (JNIEnv * env, jobject thiz, jfloat torque) {
	b2FrictionJoint* j = (b2FrictionJoint*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	j->SetMaxTorque(torque);
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_FrictionJoint_getMaxTorque
  (JNIEnv * env, jobject thiz) {
	b2FrictionJoint* j = (b2FrictionJoint*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return j->GetMaxTorque();
}
