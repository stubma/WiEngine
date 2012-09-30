#include "com_wiyun_engine_utils_ZwoptexManager.h"
#include "wyZwoptexManager.h"
#include "wyTypes.h"
#include "wyTextureAtlas.h"
#include "wyUtils_android.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_utils_ZwoptexManager_addZwoptex__Ljava_lang_String_2ILcom_wiyun_engine_opengl_Texture2D_2
  (JNIEnv * env, jclass clazz, jstring name, jint resId, jobject tex) {
	wyZwoptexManager* zm = wyZwoptexManager::getInstance();
	const char* n = (const char*)env->GetStringUTFChars(name, NULL);
	wyTexture2D* t = tex == NULL ? NULL : (wyTexture2D*)env->GetIntField(tex, g_fid_BaseObject_mPointer);
	zm->addZwoptex(n, resId, t);
	env->ReleaseStringUTFChars(name, n);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_utils_ZwoptexManager_addZwoptex__Ljava_lang_String_2Ljava_lang_String_2ZLcom_wiyun_engine_opengl_Texture2D_2
  (JNIEnv * env, jclass clazz, jstring name, jstring path, jboolean isFile, jobject tex) {
	wyZwoptexManager* zm = wyZwoptexManager::getInstance();
	const char* n = (const char*)env->GetStringUTFChars(name, NULL);
	const char* p = (const char*)env->GetStringUTFChars(path, NULL);
	wyTexture2D* t = tex == NULL ? NULL : (wyTexture2D*)env->GetIntField(tex, g_fid_BaseObject_mPointer);
	zm->addZwoptex(n, p, isFile, t);
	env->ReleaseStringUTFChars(name, n);
	env->ReleaseStringUTFChars(path, p);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_utils_ZwoptexManager_addZwoptex__Ljava_lang_String_2Ljava_lang_String_2ZLcom_wiyun_engine_opengl_Texture2D_2F
  (JNIEnv * env, jclass clazz, jstring name, jstring path, jboolean isFile, jobject tex, jfloat inDensity) {
	wyZwoptexManager* zm = wyZwoptexManager::getInstance();
	const char* n = (const char*)env->GetStringUTFChars(name, NULL);
	const char* p = (const char*)env->GetStringUTFChars(path, NULL);
	wyTexture2D* t = tex == NULL ? NULL : (wyTexture2D*)env->GetIntField(tex, g_fid_BaseObject_mPointer);
	zm->addZwoptex(n, p, isFile, t, inDensity);
	env->ReleaseStringUTFChars(name, n);
	env->ReleaseStringUTFChars(path, p);
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_utils_ZwoptexManager_hasZwoptex
  (JNIEnv * env, jclass c, jstring name) {
	wyZwoptexManager* zm = wyZwoptexManager::getInstance();
	const char* n = (const char*)env->GetStringUTFChars(name, NULL);
	bool ret = zm->hasZwoptex(n);
	env->ReleaseStringUTFChars(name, n);
	return ret;
}

JNIEXPORT jobjectArray JNICALL Java_com_wiyun_engine_utils_ZwoptexManager_getFrameNames
  (JNIEnv * env, jclass c, jstring name) {
	wyZwoptexManager* zm = wyZwoptexManager::getInstance();
	const char* n = (const char*)env->GetStringUTFChars(name, NULL);
	size_t count;
	const char** names = zm->getFrameNames(n, &count);
	env->ReleaseStringUTFChars(name, n);

	// create string array
	if(count == 0)
		return NULL;
	else {
		jclass clazz = env->FindClass("java/lang/String");
		jobjectArray ret = env->NewObjectArray(count, clazz, NULL);
		for(int i = 0; i < count; i++) {
			jstring s = env->NewStringUTF(names[i]);
			env->SetObjectArrayElement(ret, i, s);
		}
		env->DeleteLocalRef(clazz);

		// release c strings
		for(int i = 0; i < count; i++) {
			wyFree((void*)names[i]);
		}
		wyFree((void*)names);

		return ret;
	}
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_utils_ZwoptexManager_nativeGetFrameRect__Ljava_lang_String_2Ljava_lang_String_2Lcom_wiyun_engine_types_WYRect_2
  (JNIEnv * env, jclass clazz, jstring zwoptexName, jstring frameName, jobject rect) {
	wyZwoptexManager* zm = wyZwoptexManager::getInstance();
	const char* zn = (const char*)env->GetStringUTFChars(zwoptexName, NULL);
	const char* fn = (const char*)env->GetStringUTFChars(frameName, NULL);
	wyZwoptex* z = zm->getZwoptex(zn);
	wyRect r = z->getFrameRect(fn);
	env->ReleaseStringUTFChars(zwoptexName, zn);
	env->ReleaseStringUTFChars(frameName, fn);
	wyUtils_android::to_WYRect( r, rect);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_utils_ZwoptexManager_nativeGetFrameRect__Ljava_lang_String_2Lcom_wiyun_engine_types_WYRect_2
  (JNIEnv * env, jclass clazz, jstring frameName, jobject rect) {
	wyZwoptexManager* zm = wyZwoptexManager::getInstance();
	const char* fn = (const char*)env->GetStringUTFChars(frameName, NULL);
	wyRect r = zm->getFrameRect(fn);
	env->ReleaseStringUTFChars(frameName, fn);
	wyUtils_android::to_WYRect( r, rect);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_utils_ZwoptexManager_getFrameCount
  (JNIEnv * env, jclass clazz, jstring zwoptexName) {
	wyZwoptexManager* zm = wyZwoptexManager::getInstance();
	const char* zn = (const char*)env->GetStringUTFChars(zwoptexName, NULL);
	int ret = zm->getFrameCount(zn);
	env->ReleaseStringUTFChars(zwoptexName, zn);
	return ret;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_utils_ZwoptexManager_nativeGetFrameRects
  (JNIEnv * env, jclass clazz, jstring zwoptexName, jobjectArray ret) {
	// get c string zwoptex name
	wyZwoptexManager* zm = wyZwoptexManager::getInstance();
	const char* zn = (const char*)env->GetStringUTFChars(zwoptexName, NULL);

	// get frame rects
	size_t count;
	wyRect* rects = zm->getFrameRects(zn, &count);

	// save to java WYRect array
	int size = env->GetArrayLength(ret);
	for(int i = 0; i < size; i++) {
		jobject r = env->GetObjectArrayElement(ret, i);
		wyUtils_android::to_WYRect(rects[i], r);
	}

	// release
	wyFree(rects);
	env->ReleaseStringUTFChars(zwoptexName, zn);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_utils_ZwoptexManager_nativeGetSpriteFrame__Ljava_lang_String_2Ljava_lang_String_2
  (JNIEnv * env, jclass clazz, jstring zwoptexName, jstring frameName) {
	wyZwoptexManager* zm = wyZwoptexManager::getInstance();
	const char* zn = (const char*)env->GetStringUTFChars(zwoptexName, NULL);
	const char* fn = (const char*)env->GetStringUTFChars(frameName, NULL);

	wySpriteFrame* f = zm->getSpriteFrame(zn, fn);;
	if (f != NULL){
		f->retain();
		f->lazyRelease();
	}

	env->ReleaseStringUTFChars(zwoptexName, zn);
	env->ReleaseStringUTFChars(frameName, fn);
	return (jint)f;
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_utils_ZwoptexManager_nativeGetSpriteFrame__Ljava_lang_String_2
  (JNIEnv * env, jclass clazz, jstring frameName) {
	wyZwoptexManager* zm = wyZwoptexManager::getInstance();
	const char* fn = (const char*)env->GetStringUTFChars(frameName, NULL);

	wySpriteFrame* f = zm->getSpriteFrame(fn);
	if (f != NULL){
		f->retain();
		f->lazyRelease();
	}

	env->ReleaseStringUTFChars(frameName, fn);
	return (jint)f;
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_utils_ZwoptexManager_nativeMakeSprite__Ljava_lang_String_2Ljava_lang_String_2Lcom_wiyun_engine_opengl_Texture2D_2
  (JNIEnv * env, jclass clazz, jstring zwoptexName, jstring frameName, jobject tex) {
	wyZwoptexManager* zm = wyZwoptexManager::getInstance();
	const char* zn = (const char*)env->GetStringUTFChars(zwoptexName, NULL);
	const char* fn = (const char*)env->GetStringUTFChars(frameName, NULL);
	wyTexture2D* texture = tex == NULL ? NULL : (wyTexture2D*)env->GetIntField(tex, g_fid_BaseObject_mPointer);
	wySprite* sprite = zm->makeSprite(zn, fn, texture);
	if (sprite != NULL){
		sprite->retain();
		sprite->lazyRelease();
	}
	env->ReleaseStringUTFChars(zwoptexName, zn);
	env->ReleaseStringUTFChars(frameName, fn);
	return (jint)sprite;
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_utils_ZwoptexManager_nativeMakeButton__Ljava_lang_String_2Ljava_lang_String_2Lcom_wiyun_engine_utils_TargetSelector_2Lcom_wiyun_engine_opengl_Texture2D_2
  (JNIEnv * env, jclass clazz, jstring zwoptexName, jstring frameName, jobject ts, jobject tex) {
	wyZwoptexManager* zm = wyZwoptexManager::getInstance();
	const char* zn = (const char*)env->GetStringUTFChars(zwoptexName, NULL);
	const char* fn = (const char*)env->GetStringUTFChars(frameName, NULL);
	wyTexture2D* texture = tex == NULL ? NULL : (wyTexture2D*)env->GetIntField(tex, g_fid_BaseObject_mPointer);
	wyTargetSelector* selector = wyTargetSelector::make(ts);
	wyButton* button = zm->makeButton(zn, fn, selector, texture);
	if (button != NULL){
		button->retain();
		button->lazyRelease();
	}
	env->ReleaseStringUTFChars(zwoptexName, zn);
	env->ReleaseStringUTFChars(frameName, fn);
	return (jint)button;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_utils_ZwoptexManager_setZwoptexTexture
  (JNIEnv * env, jclass clazz, jstring zwoptexName, jobject tex) {
	wyZwoptexManager* zm = wyZwoptexManager::getInstance();
	const char* zn = (const char*)env->GetStringUTFChars(zwoptexName, NULL);
	wyZwoptex* z = zm->getZwoptex(zn);
	if(z != NULL) {
		wyTexture2D* t = tex == NULL ? NULL : (wyTexture2D*)env->GetIntField(tex, g_fid_BaseObject_mPointer);
		z->setTexture(t);
	}
	env->ReleaseStringUTFChars(zwoptexName, zn);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_utils_ZwoptexManager_removeZwoptex
  (JNIEnv * env, jclass clazz, jstring zwoptexName) {
	wyZwoptexManager* zm = wyZwoptexManager::getInstance();
	const char* zn = (const char*)env->GetStringUTFChars(zwoptexName, NULL);
	zm->removeZwoptex(zn);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_utils_ZwoptexManager_removeAllZwoptex
  (JNIEnv * env, jclass clazz) {
	wyZwoptexManager* zm = wyZwoptexManager::getInstance();
	zm->removeAllZwoptex();
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_utils_ZwoptexManager_nativeMakeSprite__Ljava_lang_String_2
  (JNIEnv * env, jclass clazz, jstring frameName) {
	wyZwoptexManager* zm = wyZwoptexManager::getInstance();
	const char* fn = (const char*)env->GetStringUTFChars(frameName, NULL);
	wySprite* sprite = zm->makeSprite(fn);
	if (sprite != NULL){
		sprite->retain();
		sprite->lazyRelease();
	}
	env->ReleaseStringUTFChars(frameName, fn);
	return (jint)sprite;
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_utils_ZwoptexManager_nativeMakeButton__Ljava_lang_String_2Lcom_wiyun_engine_utils_TargetSelector_2
  (JNIEnv * env, jclass clazz, jstring frameName, jobject ts) {
	wyZwoptexManager* zm = wyZwoptexManager::getInstance();
	const char* fn = (const char*)env->GetStringUTFChars(frameName, NULL);
	wyTargetSelector* selector = wyTargetSelector::make(ts);
	wyButton* button = zm->makeButton(fn, selector);
	if (button != NULL){
		button->retain();
		button->lazyRelease();
	}
	env->ReleaseStringUTFChars(frameName, fn);
	return (jint)button;
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_utils_ZwoptexManager_nativeMakeSpriteEx__Ljava_lang_String_2Ljava_lang_String_2Lcom_wiyun_engine_opengl_Texture2D_2
  (JNIEnv * env, jclass clazz, jstring zwoptexName, jstring frameName, jobject tex) {
	wyZwoptexManager* zm = wyZwoptexManager::getInstance();
	const char* zn = (const char*)env->GetStringUTFChars(zwoptexName, NULL);
	const char* fn = (const char*)env->GetStringUTFChars(frameName, NULL);
	wyTexture2D* texture = tex == NULL ? NULL : (wyTexture2D*)env->GetIntField(tex, g_fid_BaseObject_mPointer);
	wySpriteEx* sprite = zm->makeSpriteEx(zn, fn, texture);
	if (sprite != NULL){
		sprite->retain();
		sprite->lazyRelease();
	}
	env->ReleaseStringUTFChars(zwoptexName, zn);
	env->ReleaseStringUTFChars(frameName, fn);
	return (jint)sprite;
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_utils_ZwoptexManager_nativeMakeSpriteEx__Ljava_lang_String_2
  (JNIEnv * env, jclass clazz, jstring frameName) {
	wyZwoptexManager* zm = wyZwoptexManager::getInstance();
	const char* fn = (const char*)env->GetStringUTFChars(frameName, NULL);
	wySpriteEx* sprite = zm->makeSpriteEx(fn);
	if (sprite != NULL){
		sprite->retain();
		sprite->lazyRelease();
	}
	env->ReleaseStringUTFChars(frameName, fn);
	return (jint)sprite;
}
