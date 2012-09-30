#include "com_wiyun_engine_filters_ColorMatrix.h"
#include "wyColorMatrix.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_filters_ColorMatrix_nativeInit
  (JNIEnv * env, jobject thiz, jfloatArray m) {
	float* _m = m == NULL ? NULL : (float*)env->GetFloatArrayElements(m, NULL);
	wyColorMatrix* cm = wyColorMatrix::make(_m);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)cm);
	cm->retain();
	cm->lazyRelease();
	if(m)
		env->ReleaseFloatArrayElements(m, (jfloat*)_m, 0);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_filters_ColorMatrix_reset
  (JNIEnv * env, jobject thiz) {
	wyColorMatrix* m = (wyColorMatrix*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	m->reset();
}

JNIEXPORT jfloatArray JNICALL Java_com_wiyun_engine_filters_ColorMatrix_getMatrix
  (JNIEnv * env, jobject thiz) {
	wyColorMatrix* m = (wyColorMatrix*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	float* v = m->getMatrix();
	jfloatArray ret = env->NewFloatArray(20);
	env->SetFloatArrayRegion(ret, 0, 20, v);
	return ret;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_filters_ColorMatrix_setMatrix__Lcom_wiyun_engine_filters_ColorMatrix_2
  (JNIEnv * env, jobject thiz, jobject colorMatrix) {
	wyColorMatrix* m = (wyColorMatrix*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyColorMatrix* m2 = colorMatrix == NULL ? NULL : (wyColorMatrix*)env->GetIntField(colorMatrix, g_fid_BaseObject_mPointer);
	if(m2)
		m->setMatrix(m2);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_filters_ColorMatrix_setMatrix___3F
  (JNIEnv * env, jobject thiz, jfloatArray m) {
	wyColorMatrix* cm = (wyColorMatrix*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	float* _m = m == NULL ? NULL : (float*)env->GetFloatArrayElements(m, NULL);
	if(_m)
		cm->setMatrix(_m);
	env->ReleaseFloatArrayElements(m, (jfloat*)_m, 0);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_filters_ColorMatrix_setScale
  (JNIEnv * env, jobject thiz, jfloat rScale, jfloat gScale, jfloat bScale, jfloat aScale) {
	wyColorMatrix* m = (wyColorMatrix*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	m->setScale(rScale, gScale, bScale, aScale);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_filters_ColorMatrix_setRotate
  (JNIEnv * env, jobject thiz, jint axis, jfloat degrees) {
	wyColorMatrix* m = (wyColorMatrix*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	m->setRotate(axis, degrees);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_filters_ColorMatrix_setConcat
  (JNIEnv * env, jobject thiz, jobject matA, jobject matB) {
	wyColorMatrix* m = (wyColorMatrix*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyColorMatrix* mA = (wyColorMatrix*)env->GetIntField(matA, g_fid_BaseObject_mPointer);
	wyColorMatrix* mB = (wyColorMatrix*)env->GetIntField(matB, g_fid_BaseObject_mPointer);
	m->setConcat(mA, mB);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_filters_ColorMatrix_preConcat
  (JNIEnv * env, jobject thiz, jobject prematrix) {
	wyColorMatrix* m = (wyColorMatrix*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyColorMatrix* m2 = (wyColorMatrix*)env->GetIntField(prematrix, g_fid_BaseObject_mPointer);
	m->preConcat(m2);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_filters_ColorMatrix_postConcat
  (JNIEnv * env, jobject thiz, jobject postmatrix) {
	wyColorMatrix* m = (wyColorMatrix*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyColorMatrix* m2 = (wyColorMatrix*)env->GetIntField(postmatrix, g_fid_BaseObject_mPointer);
	m->postConcat(m2);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_filters_ColorMatrix_setSaturation
  (JNIEnv * env, jobject thiz, jfloat sat) {
	wyColorMatrix* m = (wyColorMatrix*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	m->setSaturation(sat);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_filters_ColorMatrix_setRGB2YUV
  (JNIEnv * env, jobject thiz) {
	wyColorMatrix* m = (wyColorMatrix*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	m->setRGB2YUV();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_filters_ColorMatrix_setYUV2RGB
  (JNIEnv * env, jobject thiz) {
	wyColorMatrix* m = (wyColorMatrix*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	m->setYUV2RGB();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_filters_ColorMatrix_setNegative
  (JNIEnv * env, jobject thiz) {
	wyColorMatrix* m = (wyColorMatrix*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	m->setNegative();
}
