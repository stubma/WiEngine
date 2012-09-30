#include "com_wiyun_engine_nodes_CharMap.h"
#include "wyAtlasLabel.h"
#include "wyUtils_android.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_CharMap_nativeInit
  (JNIEnv * env, jobject thiz) {
	wyCharMap* map = WYNEW wyCharMap();
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)map);
	map->lazyRelease();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_CharMap_mapChar__Lcom_wiyun_engine_types_WYRect_2I
  (JNIEnv * env, jobject thiz, jobject rect, jint c) {
	wyCharMap* map = (wyCharMap*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyRect r = wyUtils_android::to_wyRect( rect);
	map->mapChar(r, wyUtils::utf32toutf8((char32_t)c));
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_CharMap_mapChar__Lcom_wiyun_engine_types_WYRect_2IFF
  (JNIEnv * env, jobject thiz, jobject rect, jint c, jfloat leftPadding, jfloat rightPadding) {
	wyCharMap* map = (wyCharMap*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyRect r = wyUtils_android::to_wyRect(rect);
	map->mapChar(r, wyUtils::utf32toutf8((char32_t)c), leftPadding, rightPadding);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_CharMap_mapChar__Ljava_lang_String_2I
  (JNIEnv * env, jobject thiz, jstring frameName, jint c) {
	wyCharMap* map = (wyCharMap*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	const char* fn = (const char*)env->GetStringUTFChars(frameName, NULL);
	map->mapChar(fn, wyUtils::utf32toutf8((char32_t)c));
	env->ReleaseStringUTFChars(frameName, fn);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_CharMap_mapChar__Ljava_lang_String_2IFF
  (JNIEnv * env, jobject thiz, jstring frameName, jint c, jfloat leftPadding, jfloat rightPadding) {
	wyCharMap* map = (wyCharMap*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	const char* fn = (const char*)env->GetStringUTFChars(frameName, NULL);
	map->mapChar(fn, wyUtils::utf32toutf8((char32_t)c), leftPadding, rightPadding);
	env->ReleaseStringUTFChars(frameName, fn);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_CharMap_mapChar__Ljava_lang_String_2Ljava_lang_String_2I
  (JNIEnv * env, jobject thiz, jstring zwoptexName, jstring frameName, jint c) {
	wyCharMap* map = (wyCharMap*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	const char* zn = (const char*)env->GetStringUTFChars(zwoptexName, NULL);
	const char* fn = (const char*)env->GetStringUTFChars(frameName, NULL);
	map->mapChar(zn, fn, wyUtils::utf32toutf8((char32_t)c));
	env->ReleaseStringUTFChars(zwoptexName, zn);
	env->ReleaseStringUTFChars(frameName, fn);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_CharMap_mapChar__Ljava_lang_String_2Ljava_lang_String_2IFF
  (JNIEnv * env, jobject thiz, jstring zwoptexName, jstring frameName, jint c, jfloat leftPadding, jfloat rightPadding) {
	wyCharMap* map = (wyCharMap*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	const char* zn = (const char*)env->GetStringUTFChars(zwoptexName, NULL);
	const char* fn = (const char*)env->GetStringUTFChars(frameName, NULL);
	map->mapChar(zn, fn, wyUtils::utf32toutf8((char32_t)c), leftPadding, rightPadding);
	env->ReleaseStringUTFChars(zwoptexName, zn);
	env->ReleaseStringUTFChars(frameName, fn);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_CharMap_setSpaceWidth
  (JNIEnv* env, jobject thiz, jfloat w) {
	wyCharMap* map = (wyCharMap*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	map->setSpaceWidth(w);
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_nodes_CharMap_getSpaceWidth
  (JNIEnv * env, jobject thiz) {
	wyCharMap* map = (wyCharMap*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return map->getSpaceWidth();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_CharMap_setTabSize
  (JNIEnv* env, jobject thiz, jint tabSize) {
	wyCharMap* map = (wyCharMap*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	map->setTabSize(tabSize);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_nodes_CharMap_getTabSize
  (JNIEnv * env, jobject thiz) {
	wyCharMap* map = (wyCharMap*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return map->getTabSize();
}
