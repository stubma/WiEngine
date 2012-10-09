#include "com_wiyun_engine_filters_CombineColorFilter.h"
#include "wyCombineColorFilter.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_filters_CombineColorFilter_nativeInit
  (JNIEnv * env, jobject thiz, jobject filter1, jobjectArray filters) {
	wyColorFilter* f1 = (wyColorFilter*)env->GetIntField(filter1, g_fid_BaseObject_mPointer);
	wyCombineColorFilter* f = wyCombineColorFilter::make(f1, NULL);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)f);

	int size = filters == NULL ? 0 : env->GetArrayLength(filters);
	for(int i = 0; i < size; i++) {
		jobject filter = env->GetObjectArrayElement(filters, i);
		wyColorFilter* _f = (wyColorFilter*)env->GetIntField(filter, g_fid_BaseObject_mPointer);
		f->addFilter(_f);
		env->DeleteLocalRef(filter);
	}

	f->retain();
	f->lazyRelease();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_filters_CombineColorFilter_addFilter
  (JNIEnv * env, jobject thiz, jobject filter) {
	wyCombineColorFilter* f = (wyCombineColorFilter*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyColorFilter* _f = (wyColorFilter*)env->GetIntField(filter, g_fid_BaseObject_mPointer);
	f->addFilter(_f);
}
