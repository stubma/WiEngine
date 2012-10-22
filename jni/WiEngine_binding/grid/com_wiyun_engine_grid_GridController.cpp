#include "com_wiyun_engine_grid_GridController.h"
#include "wyGridController.h"

#include <stdlib.h>
#include "wyNode.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_grid_GridController_beforeDraw
  (JNIEnv * env, jobject thiz) {
	wyGridController* grid = (wyGridController*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	grid->beforeDraw();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_grid_GridController_nativeAfterDraw
  (JNIEnv * env, jobject thiz, jint pointer) {
	wyGridController* grid = (wyGridController*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	grid->afterDraw((wyNode*)pointer);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_grid_GridController_getGridHeight
  (JNIEnv * env, jobject thiz) {
	wyGridController* grid = (wyGridController*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return grid->getGridY();
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_grid_GridController_getGridWidth
  (JNIEnv * env, jobject thiz) {
	wyGridController* grid = (wyGridController*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return grid->getGridX();
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_grid_GridController_getStepWidth
  (JNIEnv * env, jobject thiz) {
	wyGridController* grid = (wyGridController*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return grid->getStepWidth();
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_grid_GridController_getStepHeight
  (JNIEnv * env, jobject thiz) {
	wyGridController* grid = (wyGridController*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return grid->getStepHeight();
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_grid_GridController_isActive
  (JNIEnv * env, jobject thiz) {
	wyGridController* grid = (wyGridController*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return grid->isActive();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_grid_GridController_setActive
  (JNIEnv * env, jobject thiz, jboolean flag) {
	wyGridController* grid = (wyGridController*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	grid->setActive(flag);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_grid_GridController_addReuseCount
  (JNIEnv * env, jobject thiz, jint add) {
	wyGridController* grid = (wyGridController*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	grid->addReuseCount(add);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_grid_GridController_reuse
  (JNIEnv * env, jobject thiz) {
	wyGridController* grid = (wyGridController*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	grid->reuse();
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_grid_GridController_isReuseGrid
  (JNIEnv * env, jobject thiz) {
	wyGridController* grid = (wyGridController*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return grid->isReuseGrid();
}
