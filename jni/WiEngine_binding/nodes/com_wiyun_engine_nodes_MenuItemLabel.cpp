#include "com_wiyun_engine_nodes_MenuItemLabel.h"
#include "wyMenuItemLabel.h"
#include "wyLog.h"
#include "wyUtils_android.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_MenuItemLabel_nativeInit
  (JNIEnv * env, jobject thiz, jobject downSelector, jobject upSelector, jobject l) {
	wyLabel* label = (wyLabel*)env->GetIntField(l, g_fid_BaseObject_mPointer);
	wyTargetSelector* down = downSelector == NULL ? NULL : wyTargetSelector::make(downSelector);
	wyTargetSelector* up = upSelector == NULL ? NULL : wyTargetSelector::make(upSelector);
	wyMenuItemLabel* item = WYNEW wyMenuItemLabel(down, up, label);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)item);
	wyObjectLazyRelease(item);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_nodes_MenuItemLabel_getAlpha
  (JNIEnv * env, jobject thiz) {
	wyMenuItemLabel* item = (wyMenuItemLabel*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return item->getAlpha();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_MenuItemLabel_setAlpha
  (JNIEnv * env, jobject thiz, jint alpha) {
	wyMenuItemLabel* item = (wyMenuItemLabel*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	item->setAlpha(alpha);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_MenuItemLabel_nativeGetColor
  (JNIEnv * env, jobject thiz, jobject color) {
	wyMenuItemLabel* item = (wyMenuItemLabel*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyColor3B c = item->getColor();
	wyUtils_android::to_WYColor3B(c, color);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_MenuItemLabel_nativeSetColor
  (JNIEnv * env, jobject thiz, jint r, jint g, jint b) {
	wyMenuItemLabel* item = (wyMenuItemLabel*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyColor3B c = { r, g, b };
	item->setColor(c);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_MenuItemLabel_nativeGetDisabledColor
  (JNIEnv * env, jobject thiz, jobject color) {
	wyMenuItemLabel* item = (wyMenuItemLabel*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyColor3B c = item->getDisabledColor();
	wyUtils_android::to_WYColor3B(c, color);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_MenuItemLabel_nativeSetDisabledColor
  (JNIEnv * env, jobject thiz, jint r, jint g, jint b) {
	wyMenuItemLabel* item = (wyMenuItemLabel*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyColor3B c = { r, g, b };
	item->setDisabledColor(c);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_MenuItemLabel_setString
  (JNIEnv * env, jobject thiz, jstring text) {
	wyMenuItemLabel* item = (wyMenuItemLabel*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	const char* t = (const char*)env->GetStringUTFChars(text, NULL);
	item->setString(t);
	env->ReleaseStringUTFChars(text, t);
}
