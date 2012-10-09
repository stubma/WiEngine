#include "com_wiyun_engine_box2d_dynamics_joints_JointDef.h"
#include "Box2D.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT jint JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_JointDef_getType
  (JNIEnv * env, jobject thiz) {
	b2JointDef* d = (b2JointDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return (jint)d->type;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_JointDef_setBodyA
  (JNIEnv * env, jobject thiz, jobject b) {
	b2JointDef* d = (b2JointDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	b2Body* body = (b2Body*)env->GetIntField(b, g_fid_BaseObject_mPointer);
	d->bodyA = body;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_JointDef_setBodyB
  (JNIEnv * env, jobject thiz, jobject b) {
	b2JointDef* d = (b2JointDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	b2Body* body = (b2Body*)env->GetIntField(b, g_fid_BaseObject_mPointer);
	d->bodyB = body;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_JointDef_setCollideConnected
  (JNIEnv * env, jobject thiz, jboolean flag) {
	b2JointDef* d = (b2JointDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	d->collideConnected = flag;
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_JointDef_isCollideConnected
  (JNIEnv * env, jobject thiz) {
	b2JointDef* d = (b2JointDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return d->collideConnected;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_JointDef_destroy
  (JNIEnv * env, jobject thiz) {
	b2JointDef* d = (b2JointDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	delete d;
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_JointDef_nativeGetBodyA
  (JNIEnv * env, jobject thiz) {
	b2JointDef* d = (b2JointDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return (jint)d->bodyA;
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_JointDef_nativeGetBodyB
  (JNIEnv * env, jobject thiz) {
	b2JointDef* d = (b2JointDef*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return (jint)d->bodyB;
}
