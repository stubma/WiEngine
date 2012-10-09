#include "com_wiyun_engine_box2d_dynamics_joints_RopeJoint.h"
#include "Box2D.h"

extern jfieldID g_fid_BaseObject_mPointer;
extern jfieldID g_fid_WYPoint_x;
extern jfieldID g_fid_WYPoint_y;

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_RopeJoint_nativeGetLocalAnchorA
  (JNIEnv * env, jobject thiz, jobject p) {
	b2RopeJoint* j = (b2RopeJoint*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	env->SetFloatField(p, g_fid_WYPoint_x, j->GetLocalAnchorA().x);
	env->SetFloatField(p, g_fid_WYPoint_y, j->GetLocalAnchorA().y);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_RopeJoint_nativeGetLocalAnchorB
  (JNIEnv * env, jobject thiz, jobject p) {
	b2RopeJoint* j = (b2RopeJoint*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	env->SetFloatField(p, g_fid_WYPoint_x, j->GetLocalAnchorB().x);
	env->SetFloatField(p, g_fid_WYPoint_y, j->GetLocalAnchorB().y);
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_RopeJoint_getMaxLength
  (JNIEnv * env, jobject thiz) {
	b2RopeJoint* j = (b2RopeJoint*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return j->GetMaxLength();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_RopeJoint_setMaxLength
  (JNIEnv * env, jobject thiz, jfloat length) {
	b2RopeJoint* j = (b2RopeJoint*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	j->SetMaxLength(length);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_RopeJoint_getLimitState
  (JNIEnv * env, jobject thiz) {
	b2RopeJoint* j = (b2RopeJoint*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return (jint)j->GetLimitState();
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_RopeJoint_getLength
  (JNIEnv * env, jobject thiz) {
	b2RopeJoint* j = (b2RopeJoint*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return j->GetLength();
}
