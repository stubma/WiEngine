#include "com_wiyun_engine_astar_AStar.h"
#include "wyAStar.h"
#include "wyAStarMap.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_astar_AStar_nativeInit
  (JNIEnv * env, jobject thiz, jobject map) {
	wyAStarMap* astarMap = (wyAStarMap*)env->GetIntField(map, g_fid_BaseObject_mPointer);
	wyAStar* astar = WYNEW wyAStar(astarMap);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)astar);
	astar->lazyRelease();
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_astar_AStar_nativeFindPath
  (JNIEnv * env, jobject thiz, jint startx, jint starty, jint endx, jint endy, jboolean ignoreBlock) {
	wyAStar* astar = (wyAStar*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return astar->findPath(startx, starty, endx, endy, ignoreBlock);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_astar_AStar_nativeGetStep
  (JNIEnv * env, jobject thiz, jintArray array) {
	wyAStar* astar = (wyAStar*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	int* steps = env->GetIntArrayElements(array, NULL);
	wyArray* path = astar->getPath();
	if (path != NULL) {
		for(int i = 0; i < path->num; i++) {
			steps[i] = (jint)wyArrayGet(path , i);
		}
	}
	env->ReleaseIntArrayElements(array, steps, 0);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_astar_AStar_nativeGetStarMap
  (JNIEnv * env, jobject thiz) {
	wyAStar* astar = (wyAStar*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return (jint)astar->getAStarMap();
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_astar_AStar_nativeHeuristic
  (JNIEnv * env, jobject thiz, jint startx, jint starty, jint endx, jint endy) {
	wyAStar* astar = (wyAStar*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return astar->heuristic(startx, starty, endx, endy);
}

