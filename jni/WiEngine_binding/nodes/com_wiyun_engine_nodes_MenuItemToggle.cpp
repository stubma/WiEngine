#include "com_wiyun_engine_nodes_MenuItemToggle.h"
#include "wyMenuItemToggle.h"
#include "wyUtils_android.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_MenuItemToggle_nativeInit
  (JNIEnv * env, jobject thiz, jobject downSelector, jobject upSelector, jobjectArray items) {
	wyTargetSelector* down = downSelector == NULL ? NULL : wyTargetSelector::make(downSelector);
	wyTargetSelector* up = upSelector == NULL ? NULL : wyTargetSelector::make(upSelector);

	// create toggle
	wyMenuItemToggle* toggle = WYNEW wyMenuItemToggle(down, up, NULL);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)toggle);

	// add others
	jsize size = env->GetArrayLength(items);
	for(int i = 0; i < size; i++) {
		jobject item = env->GetObjectArrayElement(items, i);
		wyMenuItem* mi = (wyMenuItem*)env->GetIntField(item, g_fid_BaseObject_mPointer);
		env->DeleteLocalRef(item);

		toggle->addMenuItem(mi);
	}
	toggle->setSelectedIndex(0);

	wyObjectLazyRelease((wyObject*)toggle);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_MenuItemToggle_setSelectedIndex
  (JNIEnv * env, jobject thiz, jint index) {
	wyMenuItemToggle* item = (wyMenuItemToggle*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	item->setSelectedIndex(index);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_nodes_MenuItemToggle_getSelectedIndex
  (JNIEnv * env, jobject thiz) {
	wyMenuItemToggle* item = (wyMenuItemToggle*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return item->getSelectedIndex();
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_nodes_MenuItemToggle_getAlpha
  (JNIEnv * env, jobject thiz) {
	wyMenuItemToggle* item = (wyMenuItemToggle*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	item->getAlpha();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_MenuItemToggle_setAlpha
  (JNIEnv * env, jobject thiz, jint alpha) {
	wyMenuItemToggle* item = (wyMenuItemToggle*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	item->setAlpha(alpha);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_MenuItemToggle_nativeGetColor
  (JNIEnv * env, jobject thiz, jobject color) {
	wyMenuItemToggle* item = (wyMenuItemToggle*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyColor3B c = item->getColor();
	wyUtils_android::to_WYColor3B(c, color);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_MenuItemToggle_nativeSetColor
  (JNIEnv * env, jobject thiz, jint r, jint g, jint b) {
	wyMenuItemToggle* item = (wyMenuItemToggle*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyColor3B c = { r, g, b };
	item->setColor(c);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_MenuItemToggle_nativeAutoReleaseItems
  (JNIEnv * env, jobject thiz) {
	wyMenuItemToggle* item = (wyMenuItemToggle*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyArray* items = item->getMenuItems();
	for(int i = 0; i < items->num; i++) {
		wyMenuItem* mi = (wyMenuItem*)wyArrayGet(items, i);
		mi->javaRelease(true);
	}
}
