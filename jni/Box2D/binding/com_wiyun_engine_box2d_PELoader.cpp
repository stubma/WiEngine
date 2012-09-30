#include "com_wiyun_engine_box2d_PELoader.h"
#include "wyBox2DPELoader.h"
#include "wyUtils_android.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT jint JNICALL Java_com_wiyun_engine_box2d_PELoader_nativeNewBodyLoader__Ljava_lang_String_2Z
  (JNIEnv* env, jclass clazz, jstring jFilePath, jboolean isFile) {
	const char* filePath = (const char*)env->GetStringUTFChars(jFilePath, NULL);;
	wyBox2DPELoader* bodyLoader = WYNEW wyBox2DPELoader(filePath, isFile);
	env->ReleaseStringUTFChars(jFilePath, filePath);
	return (jint)bodyLoader;
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_box2d_PELoader_nativeNewBodyLoader__I
 (JNIEnv* env, jclass clazz, jint resId) {
	wyBox2DPELoader* bodyLoader = WYNEW wyBox2DPELoader(resId);
	return (jint)bodyLoader;
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_box2d_PELoader_nativeCreateBodyByName
 (JNIEnv* env, jobject thiz, jobject jBox2d, jstring jName) {
	wyBox2DPELoader* bodyLoader = (wyBox2DPELoader*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	const char* name = (const char*)env->GetStringUTFChars(jName, NULL);
	wyBox2D* box2d = (wyBox2D*)env->GetIntField(jBox2d, g_fid_BaseObject_mPointer);
	jint pointer = (jint)bodyLoader->createBodyByName(box2d, name);
	env->ReleaseStringUTFChars(jName, name);
	return pointer;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_PELoader_nativeGetAnchorPercent
 (JNIEnv* env, jobject thiz, jstring jName, jobject jPoint) {
	wyBox2DPELoader* bodyLoader = (wyBox2DPELoader*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	const char* name = (const char*)env->GetStringUTFChars(jName, NULL);
	wyPoint point = bodyLoader->getAnchorPercent(name);
	env->ReleaseStringUTFChars(jName, name);
	wyUtils_android::to_WYPoint(point, jPoint);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_box2d_PELoader_getPlistFormat
(JNIEnv* env, jobject thiz) {
	wyBox2DPELoader* bodyLoader = (wyBox2DPELoader*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return bodyLoader->getPlistFormat();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_PELoader_destroy
 (JNIEnv* env, jobject thiz) {
	wyBox2DPELoader* bodyLoader = (wyBox2DPELoader*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	WYDELETE(bodyLoader);
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_box2d_PELoader_getMeterPixels
  (JNIEnv* env, jobject thiz) {
	wyBox2DPELoader* bodyLoader = (wyBox2DPELoader*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return bodyLoader->getMeterPixels();
}
