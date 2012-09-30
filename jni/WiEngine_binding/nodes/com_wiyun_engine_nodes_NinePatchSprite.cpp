#include "com_wiyun_engine_nodes_NinePatchSprite.h"
#include "wyNinePatchSprite.h"
#include "wyUtils_android.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_NinePatchSprite_nativeInit
  (JNIEnv * env, jobject thiz, jobject tex, jobject texRect, jobject patchRect) {
	wyTexture2D* t = (wyTexture2D*)env->GetIntField(tex, g_fid_BaseObject_mPointer);
	wyRect r = wyUtils_android::to_wyRect( texRect);
	wyRect p = wyUtils_android::to_wyRect( patchRect);
	wyNinePatchSprite* sprite = wyNinePatchSprite::make(t, r, p);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)sprite);
	sprite->retain();
	sprite->lazyRelease();
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_nodes_NinePatchSprite_nativeGetTexture
  (JNIEnv * env, jobject thiz) {
	wyNinePatchSprite* node = (wyNinePatchSprite*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return (jint)node->getTexture();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_NinePatchSprite_setTexture
  (JNIEnv * env, jobject thiz, jobject tex) {
	wyNinePatchSprite* node = (wyNinePatchSprite*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyTexture2D* texNode = (wyTexture2D*)env->GetIntField(tex, g_fid_BaseObject_mPointer);
	node->setTexture(texNode);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_nodes_NinePatchSprite_getBlendFuncSrc
  (JNIEnv * env, jobject thiz) {
	wyNinePatchSprite* node = (wyNinePatchSprite*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return node->getBlendFunc().src;
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_nodes_NinePatchSprite_getBlendFuncDst
  (JNIEnv * env, jobject thiz) {
	wyNinePatchSprite* node = (wyNinePatchSprite*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return node->getBlendFunc().dst;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_NinePatchSprite_setBlendFunc
  (JNIEnv * env, jobject thiz, jint src, jint dst) {
	wyNinePatchSprite* node = (wyNinePatchSprite*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyBlendFunc func = { src, dst };
	node->setBlendFunc(func);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_nodes_NinePatchSprite_getAlpha
  (JNIEnv * env, jobject thiz) {
	wyNinePatchSprite* node = (wyNinePatchSprite*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return node->getAlpha();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_NinePatchSprite_setAlpha
  (JNIEnv * env, jobject thiz, jint alpha) {
	wyNinePatchSprite* node = (wyNinePatchSprite*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	node->setAlpha(alpha);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_NinePatchSprite_nativeGetColor
  (JNIEnv * env, jobject thiz, jobject color) {
	wyNinePatchSprite* node = (wyNinePatchSprite*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyColor3B c = node->getColor();
	wyUtils_android::to_WYColor3B(c, color);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_NinePatchSprite_nativeSetColor
  (JNIEnv * env, jobject thiz, jint r, jint g, jint b) {
	wyNinePatchSprite* node = (wyNinePatchSprite*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyColor3B c = { r, g, b };
	node->setColor(c);
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_nodes_NinePatchSprite_isBlend
  (JNIEnv * env, jobject thiz) {
	wyNinePatchSprite* node = (wyNinePatchSprite*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return node->isBlend();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_NinePatchSprite_setBlend
(JNIEnv * env, jobject thiz, jboolean flag) {
	wyNinePatchSprite* node = (wyNinePatchSprite*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	node->setBlend(flag);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_NinePatchSprite_setTextureRect
  (JNIEnv* env, jobject thiz, jobject rect) {
	wyRect texRect =  wyUtils_android::to_wyRect( rect);
	wyNinePatchSprite* node = (wyNinePatchSprite*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	node->setTextureRect(texRect);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_NinePatchSprite_nativegetTextureRect
(JNIEnv* env, jobject thiz, jobject rect) {
	wyNinePatchSprite* node = (wyNinePatchSprite*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyRect texRect = node->getTextureRect();
	wyUtils_android::to_WYRect( texRect,rect);
}
