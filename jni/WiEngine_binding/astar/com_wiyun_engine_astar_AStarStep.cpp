#include "com_wiyun_engine_astar_AStarStep.h"
#include "wyAStarStep.h"
#include "wyArray.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_astar_AStarStep_nativeInit
  (JNIEnv * env, jobject thiz, jint x, jint y) {
	wyAStarStep* step = WYNEW wyAStarStep(x, y);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)step);
	step->lazyRelease();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_astar_AStarStep_setX
  (JNIEnv * env, jobject thiz, jint x) {
	wyAStarStep* step = (wyAStarStep*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	step->setX(x);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_astar_AStarStep_getX
  (JNIEnv * env, jobject thiz) {
	wyAStarStep* step = (wyAStarStep*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return step->getX();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_astar_AStarStep_setY
  (JNIEnv * env, jobject thiz, jint y) {
	wyAStarStep* step = (wyAStarStep*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	step->setY(y);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_astar_AStarStep_getY
  (JNIEnv * env, jobject thiz) {
	wyAStarStep* step = (wyAStarStep*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return step->getY();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_astar_AStarStep_setF
  (JNIEnv * env, jobject thiz, jfloat f) {
	wyAStarStep* step = (wyAStarStep*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	step->setF(f);
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_astar_AStarStep_getF
  (JNIEnv * env, jobject thiz) {
	wyAStarStep* step = (wyAStarStep*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return step->getF();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_astar_AStarStep_setH
  (JNIEnv * env, jobject thiz, jfloat h) {
	wyAStarStep* step = (wyAStarStep*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	step->setH(h);
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_astar_AStarStep_getH
  (JNIEnv * env, jobject thiz) {
	wyAStarStep* step = (wyAStarStep*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return step->getH();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_astar_AStarStep_setG
  (JNIEnv * env, jobject thiz, jfloat g) {
	wyAStarStep* step = (wyAStarStep*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	step->setH(g);
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_astar_AStarStep_getG
  (JNIEnv * env, jobject thiz) {
	wyAStarStep* step = (wyAStarStep*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return step->getG();
}
