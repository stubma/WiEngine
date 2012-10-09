#include "com_wiyun_engine_skeleton_Skeleton.h"
#include "WiEngine.h"
#include "FirstScene.h"

JNIEXPORT void JNICALL Java_com_wiyun_engine_skeleton_Skeleton_nativeStart
  (JNIEnv * env, jobject thiz) {
	wyDirector* director = wyDirector::getInstance();
	director->setShowFPS(true);

	// run with first scene
	FirstScene* scene = new FirstScene();
	director->runWithScene(scene);
	scene->release();
}
