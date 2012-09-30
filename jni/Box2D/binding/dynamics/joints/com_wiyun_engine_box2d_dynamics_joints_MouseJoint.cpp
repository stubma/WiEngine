#include "com_wiyun_engine_box2d_dynamics_joints_MouseJoint.h"
#include "Box2D.h"

extern jfieldID g_fid_BaseObject_mPointer;
extern jfieldID g_fid_WYPoint_x;
extern jfieldID g_fid_WYPoint_y;

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_MouseJoint_setTarget
  (JNIEnv * env, jobject thiz, jfloat x, jfloat y) {
	b2MouseJoint* j = (b2MouseJoint*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	j->SetTarget(b2Vec2(x, y));
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_MouseJoint_nativeGetTarget
  (JNIEnv * env, jobject thiz, jobject p) {
	b2MouseJoint* j = (b2MouseJoint*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	b2Vec2 v = j->GetTarget();
	env->SetFloatField(p, g_fid_WYPoint_x, v.x);
	env->SetFloatField(p, g_fid_WYPoint_y, v.y);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_MouseJoint_setMaxForce
  (JNIEnv * env, jobject thiz, jfloat force) {
	b2MouseJoint* j = (b2MouseJoint*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	j->SetMaxForce(force);
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_MouseJoint_getMaxForce
  (JNIEnv * env, jobject thiz) {
	b2MouseJoint* j = (b2MouseJoint*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return j->GetMaxForce();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_MouseJoint_setFrequency
  (JNIEnv * env, jobject thiz, jfloat hz) {
	b2MouseJoint* j = (b2MouseJoint*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	j->SetFrequency(hz);
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_MouseJoint_getFrequency
  (JNIEnv * env, jobject thiz) {
	b2MouseJoint* j = (b2MouseJoint*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return j->GetFrequency();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_MouseJoint_setDampingRatio
  (JNIEnv * env, jobject thiz, jfloat ratio) {
	b2MouseJoint* j = (b2MouseJoint*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	j->SetDampingRatio(ratio);
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_MouseJoint_getDampingRatio
  (JNIEnv * env, jobject thiz) {
	b2MouseJoint* j = (b2MouseJoint*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return j->GetDampingRatio();
}
