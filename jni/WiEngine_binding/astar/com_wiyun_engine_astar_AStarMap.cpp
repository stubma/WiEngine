#include "com_wiyun_engine_astar_AStarMap.h"
#include "wyAStarMap.h"
#include "wyAStarTile.h"
extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_astar_AStarMap_blockTile
  (JNIEnv * env, jobject thiz, jint x, jint y) {
	wyAStarMap* map = (wyAStarMap*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	map->blockTile(x, y);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_astar_AStarMap_freeTile
  (JNIEnv * env, jobject thiz, jint x, jint y) {
	wyAStarMap* map = (wyAStarMap*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	map->freeTile(x, y);
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_astar_AStarMap_isBlockedAt
  (JNIEnv * env, jobject thiz, jint x, jint y) {
	wyAStarMap* map = (wyAStarMap*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return map->isBlockedAt(x, y);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_astar_AStarMap_nativeGetTileAt
  (JNIEnv * env, jobject thiz, jint x, jint y) {
	wyAStarMap* map = (wyAStarMap*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return (jint)map->getTileAt(x, y);
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_astar_AStarMap_isValidTile
  (JNIEnv * env, jobject thiz, jint x, jint y) {
	wyAStarMap* map = (wyAStarMap*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return map->isValidTile(x, y);
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_astar_AStarMap_getStepG
  (JNIEnv * env, jobject thiz, jobject t1, jobject t2) {
	wyAStarTile* tile1 = (wyAStarTile*)env->GetIntField(t1, g_fid_BaseObject_mPointer);
	wyAStarTile* tile2 = (wyAStarTile*)env->GetIntField(t2, g_fid_BaseObject_mPointer);
	wyAStarMap* map = (wyAStarMap*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return map->getStepG(tile1, tile2);
}

