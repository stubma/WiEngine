#include "com_wiyun_engine_utils_ResolutionIndependent.h"
#include "wyTypes.h"
#include "wyUtils_android.h"

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_utils_ResolutionIndependent_resolveSp
  (JNIEnv * env, jclass clazz, jfloat v) {
	return SP(v);
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_utils_ResolutionIndependent_resolveDp
  (JNIEnv * env, jclass clazz, jfloat v) {
	return wyUtils::resolveDp(v);
}
