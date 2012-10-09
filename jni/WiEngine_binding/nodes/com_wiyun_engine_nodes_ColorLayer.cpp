#include "com_wiyun_engine_nodes_ColorLayer.h"
#include "wyColorLayer.h"
#include "wyUtils_android.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_ColorLayer_nativeInit
  (JNIEnv * env, jobject thiz, jobject color) {
	wyColor4B c = wyUtils_android::to_wyColor4B( color);
	wyColorLayer* layer = WYNEW wyColorLayer(c);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)layer);
	layer->lazyRelease();
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_nodes_ColorLayer_getAlpha
  (JNIEnv * env, jobject thiz) {
	wyColorLayer* node = (wyColorLayer*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return node->getAlpha();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_ColorLayer_setAlpha
  (JNIEnv * env, jobject thiz, jint alpha) {
	wyColorLayer* node = (wyColorLayer*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	node->setAlpha(alpha);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_ColorLayer_nativeGetColor
  (JNIEnv * env, jobject thiz, jobject color) {
	wyColorLayer* node = (wyColorLayer*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyColor3B c = node->getColor();
	wyUtils_android::to_WYColor3B(c, color);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_ColorLayer_nativeSetColor
  (JNIEnv * env, jobject thiz, jint r, jint g, jint b) {
	wyColorLayer* node = (wyColorLayer*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyColor3B c = { r, g, b };
	node->setColor(c);
}
