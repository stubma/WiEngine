#include "com_wiyun_engine_grid_BaseGrid.h"
#include "wyBaseGrid.h"

#include <stdlib.h>
#include "wyNode.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_grid_BaseGrid_beforeDraw
  (JNIEnv * env, jobject thiz) {
	wyBaseGrid* grid = (wyBaseGrid*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	grid->beforeDraw();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_grid_BaseGrid_nativeAfterDraw
  (JNIEnv * env, jobject thiz, jint pointer) {
	wyBaseGrid* grid = (wyBaseGrid*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	grid->afterDraw((wyNode*)pointer);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_grid_BaseGrid_getGridHeight
  (JNIEnv * env, jobject thiz) {
	wyBaseGrid* grid = (wyBaseGrid*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return grid->getGridY();
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_grid_BaseGrid_getGridWidth
  (JNIEnv * env, jobject thiz) {
	wyBaseGrid* grid = (wyBaseGrid*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return grid->getGridX();
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_grid_BaseGrid_getStepWidth
  (JNIEnv * env, jobject thiz) {
	wyBaseGrid* grid = (wyBaseGrid*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return grid->getStepWidth();
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_grid_BaseGrid_getStepHeight
  (JNIEnv * env, jobject thiz) {
	wyBaseGrid* grid = (wyBaseGrid*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return grid->getStepHeight();
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_grid_BaseGrid_isActive
  (JNIEnv * env, jobject thiz) {
	wyBaseGrid* grid = (wyBaseGrid*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return grid->isActive();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_grid_BaseGrid_setActive
  (JNIEnv * env, jobject thiz, jboolean flag) {
	wyBaseGrid* grid = (wyBaseGrid*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	grid->setActive(flag);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_grid_BaseGrid_addReuseCount
  (JNIEnv * env, jobject thiz, jint add) {
	wyBaseGrid* grid = (wyBaseGrid*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	grid->addReuseCount(add);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_grid_BaseGrid_blit
  (JNIEnv * env, jobject thiz) {
	wyBaseGrid* grid = (wyBaseGrid*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	grid->blit();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_grid_BaseGrid_reuse
  (JNIEnv * env, jobject thiz) {
	wyBaseGrid* grid = (wyBaseGrid*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	grid->reuse();
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_grid_BaseGrid_isReuseGrid
  (JNIEnv * env, jobject thiz) {
	wyBaseGrid* grid = (wyBaseGrid*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return grid->isReuseGrid();
}
