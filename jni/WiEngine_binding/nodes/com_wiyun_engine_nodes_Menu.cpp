#include "com_wiyun_engine_nodes_Menu.h"
#include "wyMenu.h"
#include "wyLog.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Menu_nativeInit
  (JNIEnv * env, jobject thiz, jobjectArray items) {
	// create menu
	wyMenu* menu = WYNEW wyMenu();
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)menu);

	// add others
	jsize size = env->GetArrayLength(items);
	for(int i = 0; i < size; i++) {
		jobject item = env->GetObjectArrayElement(items, i);
		wyMenuItem* mi = (wyMenuItem*)env->GetIntField(item, g_fid_BaseObject_mPointer);
		env->DeleteLocalRef(item);

		menu->addMenuItem(mi);
	}

	wyObjectLazyRelease(menu);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Menu_alignItemsVertically__
  (JNIEnv * env, jobject thiz) {
	wyMenu* menu = (wyMenu*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	menu->alignItemsVertically();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Menu_alignItemsVertically__F
  (JNIEnv * env, jobject thiz, jfloat padding) {
	wyMenu* menu = (wyMenu*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	menu->alignItemsVertically(padding);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Menu_alignItemsHorizontally__
  (JNIEnv * env, jobject thiz) {
	wyMenu* menu = (wyMenu*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	menu->alignItemsHorizontally();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Menu_alignItemsHorizontally__F
  (JNIEnv * env, jobject thiz, jfloat padding) {
	wyMenu* menu = (wyMenu*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	menu->alignItemsHorizontally(padding);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Menu_alignItemsInColumns___3I
  (JNIEnv * env, jobject thiz, jintArray columns) {
	wyMenu* menu = (wyMenu*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	int* cols = env->GetIntArrayElements(columns, NULL);
	int size = env->GetArrayLength(columns);
	menu->alignItemsInColumns(size, cols);
	env->ReleaseIntArrayElements(columns, cols, JNI_ABORT);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Menu_alignItemsInColumns___3IF
  (JNIEnv * env, jobject thiz, jintArray columns, jfloat padding) {
	wyMenu* menu = (wyMenu*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	int* cols = env->GetIntArrayElements(columns, NULL);
	int size = env->GetArrayLength(columns);
	menu->alignItemsInColumns(size, cols, padding);
	env->ReleaseIntArrayElements(columns, cols, JNI_ABORT);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Menu_alignItemsInRows___3I
  (JNIEnv * env, jobject thiz, jintArray rows) {
	wyMenu* menu = (wyMenu*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	int* r = env->GetIntArrayElements(rows, NULL);
	int size = env->GetArrayLength(rows);
	menu->alignItemsInRows(size, r);
	env->ReleaseIntArrayElements(rows, r, JNI_ABORT);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Menu_alignItemsInRows___3IF
  (JNIEnv * env, jobject thiz, jintArray rows, jfloat padding) {
	wyMenu* menu = (wyMenu*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	int* r = env->GetIntArrayElements(rows, NULL);
	int size = env->GetArrayLength(rows);
	menu->alignItemsInRows(size, r, padding);
	env->ReleaseIntArrayElements(rows, r, JNI_ABORT);
}
