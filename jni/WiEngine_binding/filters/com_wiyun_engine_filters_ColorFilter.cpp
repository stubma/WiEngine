#include "com_wiyun_engine_filters_ColorFilter.h"
#include "wyColorFilter.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_filters_ColorFilter_apply
  (JNIEnv * env, jobject thiz, jbyteArray data, jint width, jint height) {
	wyColorFilter* filter = (wyColorFilter*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	char* d = (char*)env->GetByteArrayElements(data, NULL);
	filter->apply(d, width, height);
	env->ReleaseByteArrayElements(data, (jbyte*)d, 0);
}
