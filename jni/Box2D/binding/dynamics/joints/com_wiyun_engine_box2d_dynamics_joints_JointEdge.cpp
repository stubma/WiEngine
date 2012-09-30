#include "com_wiyun_engine_box2d_dynamics_joints_JointEdge.h"
#include "Box2D.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT jint JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_JointEdge_nativeGetOther
  (JNIEnv * env, jobject thiz) {
	b2JointEdge* d = (b2JointEdge*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return (jint)d->other;
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_JointEdge_nativeGetJoint
  (JNIEnv * env, jobject thiz) {
	b2JointEdge* d = (b2JointEdge*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return (jint)d->joint;
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_JointEdge_nativeGetPrev
  (JNIEnv * env, jobject thiz) {
	b2JointEdge* d = (b2JointEdge*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return (jint)d->prev;
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_box2d_dynamics_joints_JointEdge_nativeGetNext
  (JNIEnv * env, jobject thiz) {
	b2JointEdge* d = (b2JointEdge*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return (jint)d->next;
}
