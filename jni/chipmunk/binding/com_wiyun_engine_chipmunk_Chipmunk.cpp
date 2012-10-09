#include <jni.h>
#include "com_wiyun_engine_chipmunk_Chipmunk.h"
#include "chipmunk.h"
#include "wyChipmunk.h"

extern jfieldID g_fid_BaseObject_mPointer;
extern jfieldID g_fid_Body_mPointer;
extern jfieldID g_fid_WYPoint_x;
extern jfieldID g_fid_WYPoint_y;

JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_Chipmunk_nativeInit(JNIEnv* env, jobject thiz) {
	wyChipmunk* chipmunk = WYNEW wyChipmunk();
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)chipmunk);
    chipmunk->lazyRelease();
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_chipmunk_Chipmunk_nativeGetSpace
  (JNIEnv * env, jobject thiz) {
	wyChipmunk* chipmunk = (wyChipmunk*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return (jint)chipmunk->getSpace();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_Chipmunk_setDebugDraw
  (JNIEnv * env, jobject thiz, jboolean debugDraw) {
	wyChipmunk* chipmunk = (wyChipmunk*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	chipmunk->setDebugDraw(debugDraw);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_Chipmunk_applyDampedSpring
  (JNIEnv * env, jclass clazz, jobject a, jobject b, jobject anchor1, jobject anchor2, jfloat rLen, jfloat k, jfloat dmp, jfloat dt) {
	cpBody* bodyA = (cpBody*)env->GetIntField(a, g_fid_Body_mPointer);
	cpBody* bodyB = (cpBody*)env->GetIntField(b, g_fid_Body_mPointer);
	cpVect ach1 = cpv(env->GetFloatField(anchor1, g_fid_WYPoint_x),
			env->GetFloatField(anchor1, g_fid_WYPoint_y));
	cpVect ach2 = cpv(env->GetFloatField(anchor2, g_fid_WYPoint_x),
			env->GetFloatField(anchor2, g_fid_WYPoint_y));
	cpApplyDampedSpring(bodyA, bodyB, ach1, ach2, rLen, k, dmp, dt);
}
