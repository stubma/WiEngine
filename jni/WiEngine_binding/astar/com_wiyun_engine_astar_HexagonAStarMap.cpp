#include "com_wiyun_engine_astar_HexagonAStarMap.h"
#include "wyHexagonAStarMap.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_astar_HexagonAStarMap_nativeInit
  (JNIEnv * env, jobject thiz, jint width, jint height) {
	wyHexagonAStarMap* map = WYNEW wyHexagonAStarMap(width, height);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)map);
	map->lazyRelease();
}
