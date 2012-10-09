#include "com_wiyun_engine_nodes_Scene.h"
#include "wyScene.h"
#include "wyLog.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Scene_nativeInit
  (JNIEnv * env, jobject thiz) {
	wyScene* scene = WYNEW wyScene();
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)scene);
	wyObjectLazyRelease(scene);
}
