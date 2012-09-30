#include "com_wiyun_engine_box2d_dynamics_joints_RopeJointDef.h"
#include "Box2D.h"

extern jfieldID g_fid_BaseObject_mPointer;
extern jfieldID g_fid_WYPoint_x;
extern jfieldID g_fid_WYPoint_y;

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_RopeJointDef_nativeNew
  (JNIEnv * env, jobject thiz) {
	b2RopeJointDef* jd = new b2RopeJointDef();
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)jd);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_RopeJointDef_setLocalAnchorA
  (JNIEnv* env, jobject thiz, jobject a) {
	b2RopeJointDef* jd = (b2RopeJointDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	float x = env->GetFloatField(a, g_fid_WYPoint_x);
	float y = env->GetFloatField(a, g_fid_WYPoint_y);
	jd->localAnchorA = b2Vec2(x, y);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_RopeJointDef_setLocalAnchorB
  (JNIEnv* env, jobject thiz, jobject a) {
	b2RopeJointDef* jd = (b2RopeJointDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	float x = env->GetFloatField(a, g_fid_WYPoint_x);
	float y = env->GetFloatField(a, g_fid_WYPoint_y);
	jd->localAnchorB = b2Vec2(x, y);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_RopeJointDef_nativeGetLocalAnchorA
  (JNIEnv * env, jobject thiz, jobject a) {
	b2RopeJointDef* jd = (b2RopeJointDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	env->SetFloatField(a, g_fid_WYPoint_x, jd->localAnchorA.x);
	env->SetFloatField(a, g_fid_WYPoint_y, jd->localAnchorA.y);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_RopeJointDef_nativeGetLocalAnchorB
  (JNIEnv * env, jobject thiz, jobject a) {
	b2RopeJointDef* jd = (b2RopeJointDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	env->SetFloatField(a, g_fid_WYPoint_x, jd->localAnchorB.x);
	env->SetFloatField(a, g_fid_WYPoint_y, jd->localAnchorB.y);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_RopeJointDef_setMaxLength
  (JNIEnv* env, jobject thiz, jfloat maxLen) {
	b2RopeJointDef* jd = (b2RopeJointDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	jd->maxLength = maxLen;
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_RopeJointDef_getMaxLength
  (JNIEnv * env, jobject thiz) {
	b2RopeJointDef* jd = (b2RopeJointDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return jd->maxLength;
}
