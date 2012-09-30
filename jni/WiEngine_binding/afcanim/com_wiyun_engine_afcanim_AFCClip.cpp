#include "com_wiyun_engine_afcanim_AFCClip.h"
#include "wyAFCClip.h"
#include "wyTypes.h"
#include "wyUtils_android.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT jint JNICALL Java_com_wiyun_engine_afcanim_AFCClip_getIndex
  (JNIEnv * env, jobject thiz) {
	wyAFCClip* clip = (wyAFCClip*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return clip->getIndex();
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_afcanim_AFCClip_getType
  (JNIEnv * env, jobject thiz) {
	wyAFCClip* clip = (wyAFCClip*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return clip->getType();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_afcanim_AFCClip_nativeGetClipPos
  (JNIEnv * env, jobject thiz, jobject p) {
	wyAFCClip* clip = (wyAFCClip*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyAFCClipData& data = clip->getData();
	wyUtils_android::to_WYPoint(data.clipPos, p);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_afcanim_AFCClip_getImageIndex
  (JNIEnv * env, jobject thiz) {
	wyAFCClip* clip = (wyAFCClip*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyAFCClipData& data = clip->getData();
	return data.i.imageIndex;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_afcanim_AFCClip_nativeGetImageRect
  (JNIEnv * env, jobject thiz, jobject r) {
	wyAFCClip* clip = (wyAFCClip*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyUtils_android::to_WYRect( clip->getData().i.rect, r);
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_afcanim_AFCClip_isImageFlipX
  (JNIEnv * env, jobject thiz) {
	wyAFCClip* clip = (wyAFCClip*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return clip->getData().i.flipX;
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_afcanim_AFCClip_getImageRotation
(JNIEnv * env, jobject thiz) {
	wyAFCClip* clip = (wyAFCClip*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return clip->getData().i.rotation;
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_afcanim_AFCClip_getEllipseColor
  (JNIEnv * env, jobject thiz) {
	wyAFCClip* clip = (wyAFCClip*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return clip->getData().e.color;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_afcanim_AFCClip_nativeGetEllipseSize
  (JNIEnv * env, jobject thiz, jobject s) {
	wyAFCClip* clip = (wyAFCClip*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyUtils_android::to_WYSize(clip->getData().e.size, s);
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_afcanim_AFCClip_getEllipseStartAngle
  (JNIEnv * env, jobject thiz) {
	wyAFCClip* clip = (wyAFCClip*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return clip->getData().e.startAngle;
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_afcanim_AFCClip_getEllipseEndAngle
  (JNIEnv * env, jobject thiz) {
	wyAFCClip* clip = (wyAFCClip*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return clip->getData().e.endAngle;
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_afcanim_AFCClip_getLineColor
  (JNIEnv * env, jobject thiz) {
	wyAFCClip* clip = (wyAFCClip*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return clip->getData().l.color;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_afcanim_AFCClip_nativeGetLineEndPoint
  (JNIEnv * env, jobject thiz, jobject p) {
	wyAFCClip* clip = (wyAFCClip*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyUtils_android::to_WYPoint(clip->getData().l.endPoint, p);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_afcanim_AFCClip_getRectangleColor
  (JNIEnv * env, jobject thiz) {
	wyAFCClip* clip = (wyAFCClip*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return clip->getData().r.color;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_afcanim_AFCClip_nativeGetRectangleSize
  (JNIEnv * env, jobject thiz, jobject s) {
	wyAFCClip* clip = (wyAFCClip*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyUtils_android::to_WYSize(clip->getData().r.size, s);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_afcanim_AFCClip_getRoundRectColor
  (JNIEnv * env, jobject thiz) {
	wyAFCClip* clip = (wyAFCClip*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return clip->getData().rr.color;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_afcanim_AFCClip_nativeGetRoundRectSize
  (JNIEnv * env, jobject thiz, jobject s) {
	wyAFCClip* clip = (wyAFCClip*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyUtils_android::to_WYSize(clip->getData().rr.size, s);
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_afcanim_AFCClip_getRoundRectArcWidth
  (JNIEnv * env, jobject thiz) {
	wyAFCClip* clip = (wyAFCClip*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return clip->getData().rr.arcWidth;
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_afcanim_AFCClip_getRoundRectArcHeight
  (JNIEnv * env, jobject thiz) {
	wyAFCClip* clip = (wyAFCClip*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return clip->getData().rr.arcHeight;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_afcanim_AFCClip_nativeGetCollisionRectSize
  (JNIEnv * env, jobject thiz, jobject s) {
	wyAFCClip* clip = (wyAFCClip*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyUtils_android::to_WYSize(clip->getData().cr.size, s);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_afcanim_AFCClip_nativeGetTrianglePoint2
  (JNIEnv * env, jobject thiz, jobject p) {
	wyAFCClip* clip = (wyAFCClip*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyUtils_android::to_WYPoint(clip->getData().t.pt2, p);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_afcanim_AFCClip_nativeGetTrianglePoint3
  (JNIEnv * env, jobject thiz, jobject p) {
	wyAFCClip* clip = (wyAFCClip*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyUtils_android::to_WYPoint(clip->getData().t.pt3, p);
}
