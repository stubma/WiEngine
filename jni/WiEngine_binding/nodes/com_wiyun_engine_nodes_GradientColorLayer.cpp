#include "com_wiyun_engine_nodes_GradientColorLayer.h"
#include "wyGradientColorLayer.h"
#include "wyUtils_android.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_GradientColorLayer_nativeInit
  (JNIEnv * env, jobject thiz, jobject fromColor, jobject toColor, jint degree) {
	wyColor4B from = wyUtils_android::to_wyColor4B( fromColor);
	wyColor4B to = wyUtils_android::to_wyColor4B( toColor);
	wyGradientColorLayer* layer = WYNEW wyGradientColorLayer(from, to, degree);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)layer);
	layer->lazyRelease();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_GradientColorLayer_setDegree
  (JNIEnv * env, jobject thiz, jint degree) {
	wyGradientColorLayer* node = (wyGradientColorLayer*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	node->setDegree(degree);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_nodes_GradientColorLayer_getDegree
  (JNIEnv * env, jobject thiz) {
	wyGradientColorLayer* node = (wyGradientColorLayer*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return node->getDegree();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_GradientColorLayer_getFromColor
  (JNIEnv * env, jobject thiz, jobject color) {
	wyGradientColorLayer* node = (wyGradientColorLayer*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyColor3B c = node->getFromColor();
	wyUtils_android::to_WYColor3B(c, color);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_GradientColorLayer_setFromColor
  (JNIEnv * env, jobject thiz, jint r, jint g, jint b) {
	wyGradientColorLayer* node = (wyGradientColorLayer*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyColor3B c = { r, g, b };
	node->setFromColor(c);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_GradientColorLayer_getToColor
  (JNIEnv * env, jobject thiz, jobject color) {
	wyGradientColorLayer* node = (wyGradientColorLayer*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyColor3B c = node->getToColor();
	wyUtils_android::to_WYColor3B(c, color);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_GradientColorLayer_setToColor
  (JNIEnv * env, jobject thiz, jint r, jint g, jint b) {
	wyGradientColorLayer* node = (wyGradientColorLayer*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyColor3B c = { r, g, b };
	node->setToColor(c);
}
