#include "com_wiyun_engine_utils_Utilities.h"
#include "wyGlobal.h"
#include "wyTypes.h"
#include "wyUtils_android.h"
#include <stdlib.h>

extern jfieldID g_fid_BitmapRawData_width;
extern jfieldID g_fid_BitmapRawData_height;
extern jfieldID g_fid_BitmapRawData_data;

JNIEXPORT void JNICALL Java_com_wiyun_engine_utils_Utilities_nativeloadImage__ILcom_wiyun_engine_utils_BitmapRawData_2
  (JNIEnv * env, jclass clazz, jint resId, jobject data) {
	float w, h;
	char* rgba = wyUtils::loadImage(resId, &w, &h, false);
	int iw = w + 0.5f;
	int ih = h + 0.5f;
	size_t len = iw * ih * 4;
	env->SetIntField(data, g_fid_BitmapRawData_width, iw);
	env->SetIntField(data, g_fid_BitmapRawData_height, ih);
	jbyteArray array = env->NewByteArray(len);
	env->SetByteArrayRegion(array, 0, len, (const jbyte*)rgba);
	wyFree(rgba);
	env->SetObjectField(data, g_fid_BitmapRawData_data, array);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_utils_Utilities_nativeloadImage__Ljava_lang_String_2ZLcom_wiyun_engine_utils_BitmapRawData_2
  (JNIEnv * env, jclass clazz, jstring path, jboolean isFile, jobject data) {
	float w, h;
	const char* p = (const char*)env->GetStringUTFChars(path, NULL);
	float scale = wyDevice::scaleMode == SCALE_MODE_BY_DENSITY ? (wyDevice::density / wyDevice::defaultInDensity) : 1.f;
	char* rgba = wyUtils::loadImage(p, (bool)isFile, &w, &h, false, scale, scale);
	env->ReleaseStringUTFChars(path, p);
	int iw = w + 0.5f;
	int ih = h + 0.5f;
	size_t len = iw * ih * 4;
	env->SetIntField(data, g_fid_BitmapRawData_width, iw);
	env->SetIntField(data, g_fid_BitmapRawData_height, ih);
	jbyteArray array = env->NewByteArray(len);
	env->SetByteArrayRegion(array, 0, len, (const jbyte*)rgba);
	wyFree(rgba);
	env->SetObjectField(data, g_fid_BitmapRawData_data, array);
}
