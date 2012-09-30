#include "com_wiyun_engine_nodes_MenuItemSprite.h"
#include "wyMenuItemSprite.h"
#include "wyUtils_android.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_MenuItemSprite_nativeInit
  (JNIEnv * env, jobject thiz, jobject downSelector, jobject upSelector, jobject normalSprite, jobject selectedSprite, jobject disabledSprite) {
	wySprite* normal = (wySprite*)env->GetIntField(normalSprite, g_fid_BaseObject_mPointer);
	wySprite* selected = selectedSprite == NULL ? NULL : (wySprite*)env->GetIntField(selectedSprite, g_fid_BaseObject_mPointer);
	wySprite* disabled = disabledSprite == NULL ? NULL : (wySprite*)env->GetIntField(disabledSprite, g_fid_BaseObject_mPointer);
	wyTargetSelector* down = downSelector == NULL ? NULL : wyTargetSelector::make(downSelector);
	wyTargetSelector* up = upSelector == NULL ? NULL : wyTargetSelector::make(upSelector);
	wyMenuItemSprite* item = WYNEW wyMenuItemSprite(down, up, normal, selected, disabled);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)item);
	wyObjectLazyRelease(item);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_nodes_MenuItemSprite_getAlpha
  (JNIEnv * env, jobject thiz) {
	wyMenuItemSprite* item = (wyMenuItemSprite*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	item->getAlpha();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_MenuItemSprite_setAlpha
  (JNIEnv * env, jobject thiz, jint alpha) {
	wyMenuItemSprite* item = (wyMenuItemSprite*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	item->setAlpha(alpha);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_MenuItemSprite_nativeGetColor
  (JNIEnv * env, jobject thiz, jobject color) {
	wyMenuItemSprite* item = (wyMenuItemSprite*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyColor3B c = item->getColor();
	wyUtils_android::to_WYColor3B(c, color);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_MenuItemSprite_nativeSetColor
  (JNIEnv * env, jobject thiz, jint r, jint g, jint b) {
	wyMenuItemSprite* item = (wyMenuItemSprite*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyColor3B c = { r, g, b };
	item->setColor(c);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_nodes_MenuItemSprite_getBlendFuncSrc
  (JNIEnv * env, jobject thiz) {
	wyMenuItemSprite* item = (wyMenuItemSprite*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return item->getBlendFunc().src;
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_nodes_MenuItemSprite_getBlendFuncDst
  (JNIEnv * env, jobject thiz) {
	wyMenuItemSprite* item = (wyMenuItemSprite*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return item->getBlendFunc().dst;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_MenuItemSprite_setBlendFunc
  (JNIEnv * env, jobject thiz, jint src, jint dst) {
	wyMenuItemSprite* item = (wyMenuItemSprite*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyBlendFunc func = { src, dst };
	item->setBlendFunc(func);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_MenuItemSprite_nativeAutoReleaseStateSprites
  (JNIEnv * env, jobject thiz) {
	wyMenuItemSprite* item = (wyMenuItemSprite*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wySprite* sprite = item->getNormalSprite();
	if(sprite != NULL)
		sprite->javaRelease(true);
	sprite = item->getSelectedSprite();
	if(sprite != NULL)
		sprite->javaRelease(true);
	sprite = item->getDisabledSprite();
	if(sprite != NULL)
		sprite->javaRelease(true);
}
