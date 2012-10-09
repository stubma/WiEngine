#include "com_wiyun_engine_box2d_dynamics_joints_DistanceJoint.h"
#include "Box2D.h"

extern jfieldID g_fid_BaseObject_mPointer;
extern jfieldID g_fid_WYPoint_x;
extern jfieldID g_fid_WYPoint_y;

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_DistanceJoint_nativeGetLocalAnchorA
  (JNIEnv * env, jobject thiz, jobject p) {
	b2DistanceJoint* j = (b2DistanceJoint*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	env->SetFloatField(p, g_fid_WYPoint_x, j->GetLocalAnchorA().x);
	env->SetFloatField(p, g_fid_WYPoint_y, j->GetLocalAnchorA().y);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_DistanceJoint_nativeGetLocalAnchorB
  (JNIEnv * env, jobject thiz, jobject p) {
	b2DistanceJoint* j = (b2DistanceJoint*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	env->SetFloatField(p, g_fid_WYPoint_x, j->GetLocalAnchorB().x);
	env->SetFloatField(p, g_fid_WYPoint_y, j->GetLocalAnchorB().y);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_DistanceJoint_setLength
  (JNIEnv * env, jobject thiz, jfloat length) {
	b2DistanceJoint* j = (b2DistanceJoint*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	j->SetLength(length);
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_DistanceJoint_getLength
  (JNIEnv * env, jobject thiz) {
	b2DistanceJoint* j = (b2DistanceJoint*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return j->GetLength();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_DistanceJoint_setFrequency
  (JNIEnv * env, jobject thiz, jfloat hz) {
	b2DistanceJoint* j = (b2DistanceJoint*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	j->SetFrequency(hz);
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_DistanceJoint_getFrequency
  (JNIEnv * env, jobject thiz) {
	b2DistanceJoint* j = (b2DistanceJoint*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return j->GetFrequency();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_DistanceJoint_setDampingRatio
  (JNIEnv * env, jobject thiz, jfloat ratio) {
	b2DistanceJoint* j = (b2DistanceJoint*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	j->SetDampingRatio(ratio);
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_DistanceJoint_getDampingRatio
  (JNIEnv * env, jobject thiz) {
	b2DistanceJoint* j = (b2DistanceJoint*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return j->GetDampingRatio();
}
