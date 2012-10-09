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
