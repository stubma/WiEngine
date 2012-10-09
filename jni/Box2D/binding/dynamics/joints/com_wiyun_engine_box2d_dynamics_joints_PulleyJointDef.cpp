#include "com_wiyun_engine_box2d_dynamics_joints_PulleyJointDef.h"
#include "Box2D.h"

extern jfieldID g_fid_BaseObject_mPointer;
extern jfieldID g_fid_WYPoint_x;
extern jfieldID g_fid_WYPoint_y;

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_PulleyJointDef_nativeNew
  (JNIEnv * env, jobject thiz) {
	b2PulleyJointDef* jd = new b2PulleyJointDef();
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)jd);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_PulleyJointDef_initialize
  (JNIEnv* env, jobject thiz, jobject bodyA, jobject bodyB, jobject groundAnchorA, jobject groundAnchorB,
		  jobject anchorA, jobject anchorB, jfloat ratio) {
	b2PulleyJointDef* jd = (b2PulleyJointDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	b2Body* ba = (b2Body*)env->GetIntField(bodyA, g_fid_BaseObject_mPointer);
	b2Body* bb = (b2Body*)env->GetIntField(bodyB, g_fid_BaseObject_mPointer);
	float gaX = env->GetFloatField(groundAnchorA, g_fid_WYPoint_x);
	float gaY = env->GetFloatField(groundAnchorA, g_fid_WYPoint_y);
	float gbX = env->GetFloatField(groundAnchorB, g_fid_WYPoint_x);
	float gbY = env->GetFloatField(groundAnchorB, g_fid_WYPoint_y);
	float aX = env->GetFloatField(anchorA, g_fid_WYPoint_x);
	float aY = env->GetFloatField(anchorA, g_fid_WYPoint_y);
	float bX = env->GetFloatField(anchorB, g_fid_WYPoint_x);
	float bY = env->GetFloatField(anchorB, g_fid_WYPoint_y);
	jd->Initialize(ba, bb, b2Vec2(gaX, gaY), b2Vec2(gbX, gbY), b2Vec2(aX, aY), b2Vec2(bX, bY), ratio);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_PulleyJointDef_setGroundAnchorA
  (JNIEnv* env, jobject thiz, jobject a) {
	b2PulleyJointDef* jd = (b2PulleyJointDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	float x = env->GetFloatField(a, g_fid_WYPoint_x);
	float y = env->GetFloatField(a, g_fid_WYPoint_y);
	jd->groundAnchorA = b2Vec2(x, y);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_PulleyJointDef_setGroundAnchorB
  (JNIEnv* env, jobject thiz, jobject a) {
	b2PulleyJointDef* jd = (b2PulleyJointDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	float x = env->GetFloatField(a, g_fid_WYPoint_x);
	float y = env->GetFloatField(a, g_fid_WYPoint_y);
	jd->groundAnchorB = b2Vec2(x, y);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_PulleyJointDef_setLocalAnchorA
  (JNIEnv* env, jobject thiz, jobject a) {
	b2PulleyJointDef* jd = (b2PulleyJointDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	float x = env->GetFloatField(a, g_fid_WYPoint_x);
	float y = env->GetFloatField(a, g_fid_WYPoint_y);
	jd->localAnchorA = b2Vec2(x, y);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_PulleyJointDef_setLocalAnchorB
  (JNIEnv* env, jobject thiz, jobject a) {
	b2PulleyJointDef* jd = (b2PulleyJointDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	float x = env->GetFloatField(a, g_fid_WYPoint_x);
	float y = env->GetFloatField(a, g_fid_WYPoint_y);
	jd->localAnchorB = b2Vec2(x, y);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_PulleyJointDef_setLengthA
  (JNIEnv* env, jobject thiz, jfloat len) {
	b2PulleyJointDef* jd = (b2PulleyJointDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	jd->lengthA = len;
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_PulleyJointDef_getLengthA
  (JNIEnv * env, jobject thiz) {
	b2PulleyJointDef* jd = (b2PulleyJointDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return jd->lengthA;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_PulleyJointDef_setLengthB
  (JNIEnv* env, jobject thiz, jfloat len) {
	b2PulleyJointDef* jd = (b2PulleyJointDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	jd->lengthB = len;
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_PulleyJointDef_getLengthB
  (JNIEnv * env, jobject thiz) {
	b2PulleyJointDef* jd = (b2PulleyJointDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return jd->lengthB;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_PulleyJointDef_setRatio
  (JNIEnv* env, jobject thiz, jfloat ratio) {
	b2PulleyJointDef* jd = (b2PulleyJointDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	jd->ratio = ratio;
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_PulleyJointDef_getRatio
  (JNIEnv * env, jobject thiz) {
	b2PulleyJointDef* jd = (b2PulleyJointDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return jd->ratio;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_PulleyJointDef_nativeGetGroundAnchorA
  (JNIEnv * env, jobject thiz, jobject a) {
	b2PulleyJointDef* jd = (b2PulleyJointDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	env->SetFloatField(a, g_fid_WYPoint_x, jd->groundAnchorA.x);
	env->SetFloatField(a, g_fid_WYPoint_y, jd->groundAnchorA.y);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_PulleyJointDef_nativeGetGroundAnchorB
  (JNIEnv * env, jobject thiz, jobject a) {
	b2PulleyJointDef* jd = (b2PulleyJointDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	env->SetFloatField(a, g_fid_WYPoint_x, jd->groundAnchorB.x);
	env->SetFloatField(a, g_fid_WYPoint_y, jd->groundAnchorB.y);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_PulleyJointDef_nativeGetLocalAnchorA
  (JNIEnv * env, jobject thiz, jobject a) {
	b2PulleyJointDef* jd = (b2PulleyJointDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	env->SetFloatField(a, g_fid_WYPoint_x, jd->localAnchorA.x);
	env->SetFloatField(a, g_fid_WYPoint_y, jd->localAnchorA.y);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_PulleyJointDef_nativeGetLocalAnchorB
  (JNIEnv * env, jobject thiz, jobject a) {
	b2PulleyJointDef* jd = (b2PulleyJointDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	env->SetFloatField(a, g_fid_WYPoint_x, jd->localAnchorB.x);
	env->SetFloatField(a, g_fid_WYPoint_y, jd->localAnchorB.y);
}
