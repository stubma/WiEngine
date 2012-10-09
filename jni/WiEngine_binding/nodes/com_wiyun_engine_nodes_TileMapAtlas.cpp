#include "com_wiyun_engine_nodes_TileMapAtlas.h"
#include "wyTileMapAtlas.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_nodes_TileMapAtlas_hasTileAt
  (JNIEnv * env, jobject thiz, jint x, jint y) {
	wyTileMapAtlas* map = (wyTileMapAtlas*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return map->hasTileAt(x, y);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_nodes_TileMapAtlas_getHorizontalTileCount
  (JNIEnv * env, jobject thiz) {
	wyTileMapAtlas* map = (wyTileMapAtlas*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return map->getHorizontalTileCount();
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_nodes_TileMapAtlas_getVerticalTileCount
  (JNIEnv * env, jobject thiz) {
	wyTileMapAtlas* map = (wyTileMapAtlas*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return map->getVerticalTileCount();
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_nodes_TileMapAtlas_tileValueAt
  (JNIEnv * env, jobject thiz, jint x, jint y) {
	wyTileMapAtlas* map = (wyTileMapAtlas*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return map->tileValueAt(x, y);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_nodes_TileMapAtlas_getTile
  (JNIEnv * env, jobject thiz, jint x, jint y) {
	wyTileMapAtlas* map = (wyTileMapAtlas*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return map->getTile(x, y);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_TileMapAtlas_setTile
  (JNIEnv * env, jobject thiz, jint tileValue, jint x, jint y) {
	wyTileMapAtlas* map = (wyTileMapAtlas*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	map->setTile(tileValue, x, y);
}
