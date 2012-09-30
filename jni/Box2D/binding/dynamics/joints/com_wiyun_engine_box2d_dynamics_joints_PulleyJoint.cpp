#include "com_wiyun_engine_box2d_dynamics_joints_PulleyJoint.h"
#include "Box2D.h"

extern jfieldID g_fid_BaseObject_mPointer;
extern jfieldID g_fid_WYPoint_x;
extern jfieldID g_fid_WYPoint_y;

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_PulleyJoint_nativeGetGroundAnchorA
  (JNIEnv * env, jobject thiz, jobject a) {
	b2PulleyJoint* j = (b2PulleyJoint*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	b2Vec2 v = j->GetGroundAnchorA();
	env->SetFloatField(a, g_fid_WYPoint_x, v.x);
	env->SetFloatField(a, g_fid_WYPoint_y, v.y);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_PulleyJoint_nativeGetGroundAnchorB
  (JNIEnv * env, jobject thiz, jobject a) {
	b2PulleyJoint* j = (b2PulleyJoint*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	b2Vec2 v = j->GetGroundAnchorB();
	env->SetFloatField(a, g_fid_WYPoint_x, v.x);
	env->SetFloatField(a, g_fid_WYPoint_y, v.y);
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_PulleyJoint_getLengthA
  (JNIEnv * env, jobject thiz) {
	b2PulleyJoint* j = (b2PulleyJoint*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return j->GetLengthA();
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_PulleyJoint_getLengthB
  (JNIEnv * env, jobject thiz) {
	b2PulleyJoint* j = (b2PulleyJoint*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return j->GetLengthB();
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_PulleyJoint_getRatio
  (JNIEnv * env, jobject thiz) {
	b2PulleyJoint* j = (b2PulleyJoint*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return j->GetRatio();
}
