#include "com_wiyun_engine_nodes_Layer.h"
#include "wyLayer.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Layer_nativeInit
  (JNIEnv * env, jobject thiz) {
	wyLayer* layer = WYNEW wyLayer();
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)layer);
	layer->lazyRelease();
}
