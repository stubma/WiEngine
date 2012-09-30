#include "com_wiyun_engine_chipmunk_PELoader.h"
#include "wyChipmunkPELoader.h"
#include "wyUtils_android.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT jint JNICALL Java_com_wiyun_engine_chipmunk_PELoader_nativeNewBodyLoader__Ljava_lang_String_2Z
  (JNIEnv* env, jclass clazz, jstring jFilePath, jboolean isFile) {
	const char* filePath = (const char*)env->GetStringUTFChars(jFilePath, NULL);
	wyChipmunkPELoader* bodyLoader = WYNEW wyChipmunkPELoader(filePath, isFile);
	env->ReleaseStringUTFChars(jFilePath, filePath);
	return (jint)bodyLoader;
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_chipmunk_PELoader_nativeNewBodyLoader__I
  (JNIEnv* env, jclass clazz, jint resId) {
	wyChipmunkPELoader* bodyLoader = WYNEW wyChipmunkPELoader(resId);
	return (jint)bodyLoader;
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_chipmunk_PELoader_nativeCreateBodyByName
  (JNIEnv* env, jobject thiz, jobject jChipmunk, jstring jName) {
	wyChipmunkPELoader* bodyLoader = (wyChipmunkPELoader*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	const char* name = (const char*)env->GetStringUTFChars(jName, NULL);
	wyChipmunk* chipmunk = (wyChipmunk*)env->GetIntField(jChipmunk, g_fid_BaseObject_mPointer);
	jint pointer = (jint)bodyLoader->createBodyByName(chipmunk, name);
	env->ReleaseStringUTFChars(jName, name);
	return pointer;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_PELoader_nativeGetAnchorPercent
  (JNIEnv* env, jobject thiz, jstring jName, jobject jPoint) {
	wyChipmunkPELoader* bodyLoader = (wyChipmunkPELoader*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	const char* name = (const char*)env->GetStringUTFChars(jName, NULL);
	wyPoint point = bodyLoader->getAnchorPercent(name);
	env->ReleaseStringUTFChars(jName, name);
	wyUtils_android::to_WYPoint(point, jPoint);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_chipmunk_PELoader_getPlistFormat
  (JNIEnv* env, jobject thiz) {
	wyChipmunkPELoader* bodyLoader = (wyChipmunkPELoader*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return bodyLoader->getPlistFormat();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_PELoader_destroy
  (JNIEnv* env, jobject thiz) {
	wyChipmunkPELoader* bodyLoader = (wyChipmunkPELoader*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	WYDELETE(bodyLoader);
}
