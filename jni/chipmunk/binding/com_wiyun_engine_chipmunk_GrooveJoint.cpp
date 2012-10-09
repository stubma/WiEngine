#include <jni.h>
#include "com_wiyun_engine_chipmunk_GrooveJoint.h"
#include "chipmunk.h"

extern jfieldID g_fid_Body_mPointer;
extern jfieldID g_fid_Constraint_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_GrooveJoint_init
  (JNIEnv * env, jobject thiz, jobject b1, jobject b2, jfloat grooveAX, jfloat grooveAY, jfloat grooveBX, jfloat grooveBY, jfloat anchorX, jfloat anchorY) {
	cpBody* body1 = (cpBody*)env->GetIntField(b1, g_fid_Body_mPointer);
	cpBody* body2 = (cpBody*)env->GetIntField(b2, g_fid_Body_mPointer);
	cpConstraint* constraint = cpGrooveJointNew(body1, body2, cpv(grooveAX, grooveAY), cpv(grooveBX, grooveBY), cpv(anchorX, anchorY));
	env->SetIntField(thiz, g_fid_Constraint_mPointer, (jint)constraint);
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_chipmunk_GrooveJoint_getAnchor2X
  (JNIEnv * env, jobject thiz) {
	cpGrooveJoint* j = (cpGrooveJoint*)env->GetIntField(thiz, g_fid_Constraint_mPointer);
	return j->anchr2.x;
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_chipmunk_GrooveJoint_getAnchor2Y
  (JNIEnv * env, jobject thiz) {
	cpGrooveJoint* j = (cpGrooveJoint*)env->GetIntField(thiz, g_fid_Constraint_mPointer);
	return j->anchr2.y;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_GrooveJoint_setAnchor2
  (JNIEnv * env, jobject thiz, jfloat x, jfloat y) {
	cpGrooveJoint* j = (cpGrooveJoint*)env->GetIntField(thiz, g_fid_Constraint_mPointer);
	j->anchr2 = cpv(x, y);
}
