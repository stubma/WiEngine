#include "com_wiyun_engine_nodes_ArrayTileMapAtlas.h"
#include "wyArrayTileMapAtlas.h"
#include <stdlib.h>
#include "wyLog.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_ArrayTileMapAtlas_nativeInit
  (JNIEnv * env, jobject thiz, jobject texture, jint tileWidth, jint tileHeight, jint xTiles, jint yTiles) {
	wyTexture2D* tex = (wyTexture2D*)env->GetIntField(texture, g_fid_BaseObject_mPointer);
	wyArrayTileMapAtlas* map = WYNEW wyArrayTileMapAtlas(tex, tileWidth, tileHeight, xTiles, yTiles, NULL);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)map);
	map->lazyRelease();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_ArrayTileMapAtlas_setTiles
  (JNIEnv * env, jobject thiz, jobjectArray t) {
	wyArrayTileMapAtlas* map = (wyArrayTileMapAtlas*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	jsize w = env->GetArrayLength(t);
	for(int x = 0; x < w; x++) {
		jintArray row = (jintArray)env->GetObjectArrayElement(t, x);
		jsize h = env->GetArrayLength(row);
		int* v = env->GetIntArrayElements(row, NULL);
		for(int y = 0; y < h; y++) {
			map->getTiles()[x + y * map->getHorizontalTileCount()] = v[y];
		}
		env->ReleaseIntArrayElements(row, v, JNI_ABORT);
		env->DeleteLocalRef(row);
	}

	map->refreshTileValues();
}
