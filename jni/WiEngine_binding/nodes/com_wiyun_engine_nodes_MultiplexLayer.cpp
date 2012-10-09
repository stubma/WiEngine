#include "com_wiyun_engine_nodes_MultiplexLayer.h"
#include "wyMultiplexLayer.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_MultiplexLayer_nativeInit
  (JNIEnv * env, jobject thiz) {
	wyMultiplexLayer* layer = WYNEW wyMultiplexLayer();
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)layer);
	wyObjectLazyRelease(layer);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_MultiplexLayer_addLayer
  (JNIEnv * env, jobject thiz, jobject layer) {
	wyMultiplexLayer* multi = (wyMultiplexLayer*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyLayer* l = (wyLayer*)env->GetIntField(layer, g_fid_BaseObject_mPointer);
	multi->addLayer(l);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_nodes_MultiplexLayer_getCurrentLayerIndex
  (JNIEnv * env, jobject thiz) {
	wyMultiplexLayer* multi = (wyMultiplexLayer*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return multi->getEnabledLayer();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_MultiplexLayer_switchTo
  (JNIEnv * env, jobject thiz, jint index) {
	wyMultiplexLayer* multi = (wyMultiplexLayer*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	multi->switchTo(index);
}
