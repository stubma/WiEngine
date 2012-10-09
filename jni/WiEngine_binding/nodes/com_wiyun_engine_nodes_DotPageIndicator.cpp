#include "com_wiyun_engine_nodes_DotPageIndicator.h"
#include "wyDotPageIndicator.h"
#include "wyTypes.h"
#include "wyUtils_android.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_DotPageIndicator_nativeInit
  (JNIEnv * env, jobject thiz, jobject dot, jobject dotRect, jobject selectedDot, jobject selectedDotRect) {
	wyRect _dotRect = wyUtils_android::to_wyRect( dotRect);
	wyRect _selectedDotRect = wyUtils_android::to_wyRect( selectedDotRect);
	wyTexture2D* _dot = (wyTexture2D*)env->GetIntField(dot, g_fid_BaseObject_mPointer);
	wyTexture2D* _selectedDot = (wyTexture2D*)env->GetIntField(selectedDot, g_fid_BaseObject_mPointer);
	wyDotPageIndicator* i = wyDotPageIndicator::make(_dot, _dotRect, _selectedDot, _selectedDotRect);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)i);
	i->retain();
	i->lazyRelease();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_DotPageIndicator_setDotSpacing
  (JNIEnv * env, jobject thiz, jfloat spacing) {
	wyDotPageIndicator* i = (wyDotPageIndicator*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	i->setDotSpacing(spacing);
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_nodes_DotPageIndicator_getDotSpacing
  (JNIEnv * env, jobject thiz) {
	wyDotPageIndicator* i = (wyDotPageIndicator*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return i->getDotSpacing();
}
