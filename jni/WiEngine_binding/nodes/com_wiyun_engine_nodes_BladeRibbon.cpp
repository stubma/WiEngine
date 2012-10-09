#include "com_wiyun_engine_nodes_BladeRibbon.h"
#include "wyBladeRibbon.h"
#include "wyUtils_android.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_BladeRibbon_nativeInit
  (JNIEnv * env, jobject thiz, jobject texture, jobject color, jfloat fade) {
	wyTexture2D* tex = (wyTexture2D*)env->GetIntField(texture, g_fid_BaseObject_mPointer);
	wyColor4B c = wyUtils_android::to_wyColor4B( color);
	wyBladeRibbon* ribbon = WYNEW wyBladeRibbon(tex, c, fade);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)ribbon);
	wyObjectLazyRelease(ribbon);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_BladeRibbon_setMaxPointCount
  (JNIEnv * env, jobject thiz, jint max) {
	wyBladeRibbon* node = (wyBladeRibbon*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	node->setMaxPointCount(max);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_nodes_BladeRibbon_nativeGetTexture
(JNIEnv * env, jobject thiz) {
	wyBladeRibbon* node = (wyBladeRibbon*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return (jint)node->getTexture();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_BladeRibbon_setTexture
(JNIEnv * env, jobject thiz, jobject tex) {
	wyBladeRibbon* node = (wyBladeRibbon*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyTexture2D* texNode = (wyTexture2D*)env->GetIntField(tex, g_fid_BaseObject_mPointer);
	node->setTexture(texNode);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_nodes_BladeRibbon_getAlpha
(JNIEnv * env, jobject thiz) {
	wyBladeRibbon* node = (wyBladeRibbon*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return node->getAlpha();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_BladeRibbon_setAlpha
(JNIEnv * env, jobject thiz, jint alpha) {
	wyBladeRibbon* node = (wyBladeRibbon*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	node->setAlpha(alpha);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_BladeRibbon_nativeGetColor
(JNIEnv * env, jobject thiz, jobject color) {
	wyBladeRibbon* node = (wyBladeRibbon*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyColor3B c = node->getColor();
	wyUtils_android::to_WYColor3B(c, color);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_BladeRibbon_nativeSetColor
(JNIEnv * env, jobject thiz, jint r, jint g, jint b) {
	wyBladeRibbon* node = (wyBladeRibbon*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyColor3B c = { r, g, b };
	node->setColor(c);
}
