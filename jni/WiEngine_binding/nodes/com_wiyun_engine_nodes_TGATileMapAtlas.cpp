#include "com_wiyun_engine_nodes_TGATileMapAtlas.h"
#include "wyTGATileMapAtlas.h"
#include <stdlib.h>
#include "wyLog.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_TGATileMapAtlas_nativeInit
  (JNIEnv * env, jobject thiz, jobject texture, jint mapResId, jint tileWidth, jint tileHeight) {
	wyTexture2D* tex = (wyTexture2D*)env->GetIntField(texture, g_fid_BaseObject_mPointer);
	wyTGATileMapAtlas* map = WYNEW wyTGATileMapAtlas(tex, mapResId, tileWidth, tileHeight);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)map);
	wyObjectLazyRelease(map);
}
