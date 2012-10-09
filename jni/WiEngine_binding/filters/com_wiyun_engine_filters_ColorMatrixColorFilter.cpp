#include "com_wiyun_engine_filters_ColorMatrixColorFilter.h"
#include "wyColorMatrix.h"
#include "wyColorMatrixColorFilter.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_filters_ColorMatrixColorFilter_nativeInit
  (JNIEnv * env, jobject thiz, jobject matrix) {
	wyColorMatrix* m = (wyColorMatrix*)env->GetIntField(matrix, g_fid_BaseObject_mPointer);
	wyColorMatrixColorFilter* f = wyColorMatrixColorFilter::make(m);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)f);
	f->retain();
	f->lazyRelease();
}
