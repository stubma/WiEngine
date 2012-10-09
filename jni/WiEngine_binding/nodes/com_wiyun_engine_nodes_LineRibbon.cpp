#include "com_wiyun_engine_nodes_LineRibbon.h"
#include "wyLineRibbon.h"
#include "wyTypes.h"
#include "wyUtils_android.h"

extern jfieldID g_fid_BaseObject_mPointer;
extern jfieldID g_fid_WYPoint_x;
extern jfieldID g_fid_WYPoint_y;

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_LineRibbon_nativeInit
  (JNIEnv * env, jobject thiz, jobject tex, jobject color) {
	wyTexture2D* t = (wyTexture2D*)env->GetIntField(tex, g_fid_BaseObject_mPointer);
	wyColor4B c = wyUtils_android::to_wyColor4B( color);
	wyLineRibbon* r = WYNEW wyLineRibbon(t, c);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)r);
	r->lazyRelease();
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_nodes_LineRibbon_nativeGetTexture
  (JNIEnv * env, jobject thiz) {
	wyLineRibbon* r = (wyLineRibbon*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return (jint)r->getTexture();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_LineRibbon_setTexture
  (JNIEnv * env, jobject thiz, jobject tex) {
	wyTexture2D* t = (wyTexture2D*)env->GetIntField(tex, g_fid_BaseObject_mPointer);
	wyLineRibbon* r = (wyLineRibbon*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	r->setTexture(t);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_nodes_LineRibbon_getAlpha
  (JNIEnv * env, jobject thiz) {
	wyLineRibbon* r = (wyLineRibbon*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return r->getAlpha();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_LineRibbon_setAlpha
  (JNIEnv * env, jobject thiz, jint alpha) {
	wyLineRibbon* r = (wyLineRibbon*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	r->setAlpha(alpha);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_LineRibbon_nativeGetColor
  (JNIEnv * env, jobject thiz, jobject color) {
	wyLineRibbon* r = (wyLineRibbon*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyColor3B c = r->getColor();
	wyUtils_android::to_WYColor3B(c, color);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_LineRibbon_nativeSetColor
  (JNIEnv * env, jobject thiz, jint r, jint g, jint b) {
	wyLineRibbon* ribbon = (wyLineRibbon*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyColor3B c = { r, g, b };
	ribbon->setColor(c);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_LineRibbon_setLineWidth
  (JNIEnv * env, jobject thiz, jfloat width) {
	wyLineRibbon* r = (wyLineRibbon*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	r->setLineWidth(width);
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_nodes_LineRibbon_getLineWidth
  (JNIEnv * env, jobject thiz, jint index) {
	wyLineRibbon* r = (wyLineRibbon*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return r->getLineWidth(index);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_LineRibbon_nativeGetLineColor
  (JNIEnv * env, jobject thiz, jint index, jobject color) {
	wyLineRibbon* r = (wyLineRibbon*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyColor4B c = r->getLineColor(index);
	wyUtils_android::to_WYColor4B(c, color);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_nodes_LineRibbon_getLineCount
  (JNIEnv * env, jobject thiz) {
	wyLineRibbon* r = (wyLineRibbon*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return r->getLineCount();
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_nodes_LineRibbon_getLinePointCount
  (JNIEnv * env, jobject thiz, jint index) {
	wyLineRibbon* r = (wyLineRibbon*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return r->getLinePointCount(index);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_LineRibbon_nativeGetLinePointList
  (JNIEnv * env, jobject thiz, jint index, jobjectArray list) {
	wyLineRibbon* r = (wyLineRibbon*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyPoint* points = r->getLinePointList(index);
	jsize size = env->GetArrayLength(list);
	for(int i = 0; i < size; i++) {
		jobject p = env->GetObjectArrayElement(list, i);
		env->SetFloatField(p, g_fid_WYPoint_x, points[i].x);
		env->SetFloatField(p, g_fid_WYPoint_y, points[i].y);
		env->DeleteLocalRef(p);
	}
}

