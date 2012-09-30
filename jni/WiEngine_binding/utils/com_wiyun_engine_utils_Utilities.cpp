#include "com_wiyun_engine_utils_Utilities.h"
#include "wyGlobal.h"
#include "wyTypes.h"
#include "wyUtils_android.h"
#include <stdlib.h>

extern jfieldID g_fid_BitmapRawData_width;
extern jfieldID g_fid_BitmapRawData_height;
extern jfieldID g_fid_BitmapRawData_data;

JNIEXPORT void JNICALL Java_com_wiyun_engine_utils_Utilities_nativeLoadPNG__ILcom_wiyun_engine_utils_BitmapRawData_2
  (JNIEnv * env, jclass clazz, jint resId, jobject data) {
	size_t w, h;
	char* rgba = wyUtils::loadPNG(resId, &w, &h, false);
	size_t len = w * h * 4;
	env->SetIntField(data, g_fid_BitmapRawData_width, w);
	env->SetIntField(data, g_fid_BitmapRawData_height, h);
	jbyteArray array = env->NewByteArray(len);
	env->SetByteArrayRegion(array, 0, len, (const jbyte*)rgba);
	wyFree(rgba);
	env->SetObjectField(data, g_fid_BitmapRawData_data, array);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_utils_Utilities_nativeLoadPNG__Ljava_lang_String_2ZLcom_wiyun_engine_utils_BitmapRawData_2
  (JNIEnv * env, jclass clazz, jstring path, jboolean isFile, jobject data) {
	size_t w, h;
	const char* p = (const char*)env->GetStringUTFChars(path, NULL);
	float scale = wyDevice::scaleMode == SCALE_MODE_BY_DENSITY ? (wyDevice::density / wyDevice::defaultInDensity) : 1.f;
	char* rgba = wyUtils::loadPNG(p, (bool)isFile, &w, &h, false, scale, scale);
	env->ReleaseStringUTFChars(path, p);
	size_t len = w * h * 4;
	env->SetIntField(data, g_fid_BitmapRawData_width, w);
	env->SetIntField(data, g_fid_BitmapRawData_height, h);
	jbyteArray array = env->NewByteArray(len);
	env->SetByteArrayRegion(array, 0, len, (const jbyte*)rgba);
	wyFree(rgba);
	env->SetObjectField(data, g_fid_BitmapRawData_data, array);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_utils_Utilities_nativeLoadJPG__ILcom_wiyun_engine_utils_BitmapRawData_2
  (JNIEnv * env, jclass clazz, jint resId, jobject data) {
	size_t w, h;
	char* rgba = wyUtils::loadJPG(resId, &w, &h, false);
	size_t len = w * h * 4;
	env->SetIntField(data, g_fid_BitmapRawData_width, w);
	env->SetIntField(data, g_fid_BitmapRawData_height, h);
	jbyteArray array = env->NewByteArray(len);
	env->SetByteArrayRegion(array, 0, len, (const jbyte*)rgba);
	wyFree(rgba);
	env->SetObjectField(data, g_fid_BitmapRawData_data, array);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_utils_Utilities_nativeLoadJPG__Ljava_lang_String_2ZLcom_wiyun_engine_utils_BitmapRawData_2
  (JNIEnv * env, jclass clazz, jstring path, jboolean isFile, jobject data) {
	size_t w, h;
	const char* p = (const char*)env->GetStringUTFChars(path, NULL);
	float scale = wyDevice::scaleMode == SCALE_MODE_BY_DENSITY ? (wyDevice::density / wyDevice::defaultInDensity) : 1.f;
	char* rgba = wyUtils::loadJPG(p, (bool)isFile, &w, &h, false, scale, scale);
	env->ReleaseStringUTFChars(path, p);
	size_t len = w * h * 4;
	env->SetIntField(data, g_fid_BitmapRawData_width, w);
	env->SetIntField(data, g_fid_BitmapRawData_height, h);
	jbyteArray array = env->NewByteArray(len);
	env->SetByteArrayRegion(array, 0, len, (const jbyte*)rgba);
	wyFree(rgba);
	env->SetObjectField(data, g_fid_BitmapRawData_data, array);
}
