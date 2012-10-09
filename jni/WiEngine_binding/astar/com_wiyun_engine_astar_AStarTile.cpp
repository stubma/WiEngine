#include "com_wiyun_engine_astar_AStarTile.h"
#include "wyAStarTile.h"
#include "wyArray.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_astar_AStarTile_nativeInit
  (JNIEnv * env, jobject thiz, jint type, jint x, jint y) {
	wyAStarTile* tile = WYNEW wyAStarTile(type, x, y);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)tile);
	tile->lazyRelease();
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_astar_AStarTile_getGRate
  (JNIEnv * env, jobject thiz) {
	wyAStarTile* tile = (wyAStarTile*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return tile->getGRate();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_astar_AStarTile_setGRate
  (JNIEnv * env, jobject thiz, jfloat gRate) {
	wyAStarTile* tile = (wyAStarTile*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	tile->setGRate(gRate);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_astar_AStarTile_getX
  (JNIEnv * env, jobject thiz) {
	wyAStarTile* tile = (wyAStarTile*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return tile->getX();
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_astar_AStarTile_getY
  (JNIEnv * env, jobject thiz) {
	wyAStarTile* tile = (wyAStarTile*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return tile->getY();
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_astar_AStarTile_getType
  (JNIEnv * env, jobject thiz) {
	wyAStarTile* tile = (wyAStarTile*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return tile->getType();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_astar_AStarTile_setType
  (JNIEnv * env, jobject thiz, jint type) {
	wyAStarTile* tile = (wyAStarTile*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	tile->setType(type);
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_astar_AStarTile_isBlocked
  (JNIEnv * env, jobject thiz) {
	wyAStarTile* tile = (wyAStarTile*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return tile->isBlocked();
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_astar_AStarTile_isFree
  (JNIEnv * env, jobject thiz) {
	wyAStarTile* tile = (wyAStarTile*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return tile->isFree();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_astar_AStarTile_pushChild
  (JNIEnv * env, jobject thiz, jobject child) {
	wyAStarTile* tile = (wyAStarTile*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyAStarTile* childTile = (wyAStarTile*)env->GetIntField(child, g_fid_BaseObject_mPointer);
	tile->pushChild(childTile);

}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_astar_AStarTile_getChildCount
  (JNIEnv * env, jobject thiz) {
	wyAStarTile* tile = (wyAStarTile*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyArray* childs = tile->getChilds();
	return childs->num;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_astar_AStarTile_nativeGetChildren
  (JNIEnv * env, jobject thiz, jintArray array) {
	wyAStarTile* tile = (wyAStarTile*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	int* ret = env->GetIntArrayElements(array, NULL);
	wyArray* childs = tile->getChilds();
	for(int i = 0; i < childs->num; i++) {
		ret[i] = (jint)wyArrayGet(childs , i);
	}
	env->ReleaseIntArrayElements(array, ret, 0);
}

