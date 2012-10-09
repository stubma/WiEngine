#include "com_wiyun_engine_astar_RectAStarMap.h"
#include "wyRectAStarMap.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_astar_RectAStarMap_nativeInit
  (JNIEnv * env, jobject thiz, jint width, jint height, jboolean isAllowDiagonal) {
	wyRectAStarMap* map = WYNEW wyRectAStarMap(width, height, isAllowDiagonal);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)map);
	map->lazyRelease();
}
