#include "com_wiyun_engine_actions_grid_GridAction.h"
#include "wyGridAction.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_actions_grid_GridAction_getAmplitude
  (JNIEnv * env, jobject thiz) {
	wyGridAction* g = (wyGridAction*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return g->getAmplitude();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_actions_grid_GridAction_setAmplitude
  (JNIEnv * env, jobject thiz, jfloat amplitude) {
	wyGridAction* g = (wyGridAction*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	g->setAmplitude(amplitude);
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_actions_grid_GridAction_getAmplitudeRate
  (JNIEnv * env, jobject thiz) {
	wyGridAction* g = (wyGridAction*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return g->getAmplitudeRate();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_actions_grid_GridAction_setAmplitudeRate
  (JNIEnv * env, jobject thiz, jfloat amplitudeRate) {
	wyGridAction* g = (wyGridAction*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	g->setAmplitudeRate(amplitudeRate);
}

JNIEXPORT jobject JNICALL Java_com_wiyun_engine_actions_grid_GridAction_makeGrid
  (JNIEnv * env, jobject thiz) {
	wyGridAction* g = (wyGridAction*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return (jobject)g->makeGrid();
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_actions_grid_GridAction_getGridWidth
  (JNIEnv * env, jobject thiz) {
	wyGridAction* g = (wyGridAction*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return g->getGridX();
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_actions_grid_GridAction_getGridHeight
  (JNIEnv * env, jobject thiz) {
	wyGridAction* g = (wyGridAction*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return g->getGridY();
}
