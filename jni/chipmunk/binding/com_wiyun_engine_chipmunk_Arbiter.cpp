#include <jni.h>
#include "com_wiyun_engine_chipmunk_Arbiter.h"
#include "chipmunk.h"

extern jfieldID g_fid_Arbiter_mPointer;

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_chipmunk_Arbiter_getContactPointX
  (JNIEnv * env, jobject thiz, jint contactIndex) {
	cpArbiter* arb = (cpArbiter*)env->GetIntField(thiz, g_fid_Arbiter_mPointer);
	cpVect v = cpArbiterGetPoint(arb, contactIndex);
	return v.x;
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_chipmunk_Arbiter_getContactPointY
  (JNIEnv * env, jobject thiz, jint contactIndex) {
	cpArbiter* arb = (cpArbiter*)env->GetIntField(thiz, g_fid_Arbiter_mPointer);
	cpVect v = cpArbiterGetPoint(arb, contactIndex);
	return v.y;
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_chipmunk_Arbiter_isFirstContact
  (JNIEnv * env, jobject thiz) {
	cpArbiter* arb = (cpArbiter*)env->GetIntField(thiz, g_fid_Arbiter_mPointer);
	return cpArbiterIsFirstContact(arb) == 1;
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_chipmunk_Arbiter_getTotalImpulseX
  (JNIEnv * env, jobject thiz) {
	cpArbiter* arb = (cpArbiter*)env->GetIntField(thiz, g_fid_Arbiter_mPointer);
	cpVect v = cpArbiterTotalImpulse(arb);
	return v.x;
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_chipmunk_Arbiter_getTotalImpulseY
  (JNIEnv * env, jobject thiz) {
	cpArbiter* arb = (cpArbiter*)env->GetIntField(thiz, g_fid_Arbiter_mPointer);
	cpVect v = cpArbiterTotalImpulse(arb);
	return v.y;
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_chipmunk_Arbiter_getTotalImpulseWithFrictionX
  (JNIEnv * env, jobject thiz) {
	cpArbiter* arb = (cpArbiter*)env->GetIntField(thiz, g_fid_Arbiter_mPointer);
	cpVect v = cpArbiterTotalImpulseWithFriction(arb);
	return v.x;
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_chipmunk_Arbiter_getTotalImpulseWithFrictionY
  (JNIEnv * env, jobject thiz) {
	cpArbiter* arb = (cpArbiter*)env->GetIntField(thiz, g_fid_Arbiter_mPointer);
	cpVect v = cpArbiterTotalImpulseWithFriction(arb);
	return v.y;
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_chipmunk_Arbiter_getContactPointCount
  (JNIEnv * env, jobject thiz) {
	cpArbiter* arb = (cpArbiter*)env->GetIntField(thiz, g_fid_Arbiter_mPointer);
	return arb->numContacts;
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_chipmunk_Arbiter_getNormalX
  (JNIEnv * env, jobject thiz, jint contactIndex) {
	cpArbiter* arb = (cpArbiter*)env->GetIntField(thiz, g_fid_Arbiter_mPointer);
	cpVect v = cpArbiterGetNormal(arb, contactIndex);
	return v.x;
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_chipmunk_Arbiter_getNormalY
  (JNIEnv * env, jobject thiz, jint contactIndex) {
	cpArbiter* arb = (cpArbiter*)env->GetIntField(thiz, g_fid_Arbiter_mPointer);
	cpVect v = cpArbiterGetNormal(arb, contactIndex);
	return v.y;
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_chipmunk_Arbiter_nativeGetShapeA(JNIEnv * env, jobject thiz) {
	cpArbiter* arb = (cpArbiter*)env->GetIntField(thiz, g_fid_Arbiter_mPointer);
	if(arb->swappedColl) {
		return (jint)arb->b;
	} else {
		return (jint)arb->a;
	}
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_chipmunk_Arbiter_nativeGetShapeB(JNIEnv * env, jobject thiz) {
	cpArbiter* arb = (cpArbiter*)env->GetIntField(thiz, g_fid_Arbiter_mPointer);
	if(arb->swappedColl) {
		return (jint)arb->a;
	} else {
		return (jint)arb->b;
	}
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_chipmunk_Arbiter_getTimeStamp
  (JNIEnv * env, jobject thiz) {
	cpArbiter* arb = (cpArbiter*)env->GetIntField(thiz, g_fid_Arbiter_mPointer);
	return arb->stamp;
}
