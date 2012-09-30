#include "com_wiyun_engine_nodes_MenuItemAtlasLabel.h"
#include "wyMenuItemAtlasLabel.h"
#include "wyUtils_android.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_MenuItemAtlasLabel_nativeInit
  (JNIEnv * env, jobject thiz, jobject downSelector, jobject upSelector, jobject l) {
	wyAtlasLabel* label = (wyAtlasLabel*)env->GetIntField(l, g_fid_BaseObject_mPointer);
	wyTargetSelector* down = downSelector == NULL ? NULL : wyTargetSelector::make(downSelector);
	wyTargetSelector* up = upSelector == NULL ? NULL : wyTargetSelector::make(upSelector);
	wyMenuItemAtlasLabel* item = WYNEW wyMenuItemAtlasLabel(down, up, label);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)item);
	wyObjectLazyRelease(item);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_nodes_MenuItemAtlasLabel_getAlpha
  (JNIEnv * env, jobject thiz) {
	wyMenuItemAtlasLabel* item = (wyMenuItemAtlasLabel*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return item->getAlpha();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_MenuItemAtlasLabel_setAlpha
  (JNIEnv * env, jobject thiz, jint alpha) {
	wyMenuItemAtlasLabel* item = (wyMenuItemAtlasLabel*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	item->setAlpha(alpha);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_MenuItemAtlasLabel_nativeGetColor
  (JNIEnv * env, jobject thiz, jobject color) {
	wyMenuItemAtlasLabel* item = (wyMenuItemAtlasLabel*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyColor3B c = item->getColor();
	wyUtils_android::to_WYColor3B(c, color);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_MenuItemAtlasLabel_nativeSetColor
  (JNIEnv * env, jobject thiz, jint r, jint g, jint b) {
	wyMenuItemAtlasLabel* item = (wyMenuItemAtlasLabel*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyColor3B c = { r, g, b };
	item->setColor(c);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_MenuItemAtlasLabel_nativeGetDisabledColor
  (JNIEnv * env, jobject thiz, jobject color) {
	wyMenuItemAtlasLabel* item = (wyMenuItemAtlasLabel*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyColor3B c = item->getDisabledColor();
	wyUtils_android::to_WYColor3B(c, color);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_MenuItemAtlasLabel_nativeSetDisabledColor
  (JNIEnv * env, jobject thiz, jint r, jint g, jint b) {
	wyMenuItemAtlasLabel* item = (wyMenuItemAtlasLabel*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyColor3B c = { r, g, b };
	item->setDisabledColor(c);
}
