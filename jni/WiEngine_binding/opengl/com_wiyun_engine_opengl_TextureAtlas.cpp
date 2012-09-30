#include "com_wiyun_engine_opengl_TextureAtlas.h"
#include "wyTexture2D.h"
#include "wyTextureAtlas.h"
#include "wyUtils_android.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT jint JNICALL Java_com_wiyun_engine_opengl_TextureAtlas_getTotalQuads
  (JNIEnv * env, jobject thiz) {
	wyTextureAtlas* atlas = (wyTextureAtlas*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return atlas->getTotalQuads();
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_opengl_TextureAtlas_getCapacity
  (JNIEnv * env, jobject thiz) {
	wyTextureAtlas* atlas = (wyTextureAtlas*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return atlas->getCapacity();
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_opengl_TextureAtlas_getHeight
  (JNIEnv * env, jobject thiz) {
	wyTextureAtlas* atlas = (wyTextureAtlas*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return atlas->getTexture()->getHeight();
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_opengl_TextureAtlas_getWidth
  (JNIEnv * env, jobject thiz) {
	wyTextureAtlas* atlas = (wyTextureAtlas*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return atlas->getTexture()->getWidth();
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_opengl_TextureAtlas_getHeightScale
  (JNIEnv * env, jobject thiz) {
	wyTextureAtlas* atlas = (wyTextureAtlas*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return atlas->getHeightScale();
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_opengl_TextureAtlas_getWidthScale
  (JNIEnv * env, jobject thiz) {
	wyTextureAtlas* atlas = (wyTextureAtlas*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return atlas->getWidthScale();
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_opengl_TextureAtlas_getNextAvailableIndex
  (JNIEnv * env, jobject thiz) {
	wyTextureAtlas* atlas = (wyTextureAtlas*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return atlas->getNextAvailableIndex();
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_opengl_TextureAtlas_nativeGetTexture
  (JNIEnv * env, jobject thiz) {
	wyTextureAtlas* atlas = (wyTextureAtlas*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return (jint)atlas->getTexture();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_opengl_TextureAtlas_setTexture
  (JNIEnv * env, jobject thiz, jobject tex) {
	wyTextureAtlas* atlas = (wyTextureAtlas*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	atlas->setTexture((wyTexture2D*)env->GetIntField(tex, g_fid_BaseObject_mPointer));
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_opengl_TextureAtlas_isWithColorArray
  (JNIEnv * env, jobject thiz) {
	wyTextureAtlas* atlas = (wyTextureAtlas*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return atlas->isWithColorArray();
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_opengl_TextureAtlas_nativeNew
  (JNIEnv * env, jobject thiz, jobject tex, jint capacity) {
	wyTexture2D* t = (wyTexture2D*)env->GetIntField(tex, g_fid_BaseObject_mPointer);
	wyTextureAtlas* atlas = WYNEW wyTextureAtlas(t, capacity);
	wyObjectLazyRelease(atlas);
	return (jint)atlas;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_opengl_TextureAtlas_removeAllQuads
  (JNIEnv * env, jobject thiz) {
	wyTextureAtlas* atlas = (wyTextureAtlas*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	atlas->removeAllQuads();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_opengl_TextureAtlas_updateQuad
  (JNIEnv * env, jobject thiz, jobject quadT, jobject quadV, jint index) {
	wyTextureAtlas* atlas = (wyTextureAtlas*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyQuad2D q2 = wyUtils_android::to_wyQuad2D( quadT);
	wyQuad3D q3 = wyUtils_android::to_wyQuad3D( quadV);
	atlas->updateQuad(q2, q3, index);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_opengl_TextureAtlas_appendQuad
  (JNIEnv * env, jobject thiz, jobject quadT, jobject quadV) {
	wyTextureAtlas* atlas = (wyTextureAtlas*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyQuad2D q2 = wyUtils_android::to_wyQuad2D( quadT);
	wyQuad3D q3 = wyUtils_android::to_wyQuad3D( quadV);
	return atlas->appendQuad(q2, q3);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_opengl_TextureAtlas_insertQuad
  (JNIEnv * env, jobject thiz, jobject quadT, jobject quadV, jint index) {
	wyTextureAtlas* atlas = (wyTextureAtlas*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyQuad2D q2 = wyUtils_android::to_wyQuad2D( quadT);
	wyQuad3D q3 = wyUtils_android::to_wyQuad3D( quadV);
	atlas->insertQuad(q2, q3, index);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_opengl_TextureAtlas_removeQuad
  (JNIEnv * env, jobject thiz, jint index) {
	wyTextureAtlas* atlas = (wyTextureAtlas*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	atlas->removeQuad(index);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_opengl_TextureAtlas_removeQuads
  (JNIEnv * env, jobject thiz, jint start, jint count) {
	wyTextureAtlas* atlas = (wyTextureAtlas*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	atlas->removeQuads(start, count);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_opengl_TextureAtlas_setColor
  (JNIEnv * env, jobject thiz, jobject color) {
	wyTextureAtlas* atlas = (wyTextureAtlas*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyColor4B c = wyUtils_android::to_wyColor4B( color);
	atlas->setColor(c);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_opengl_TextureAtlas_nativeGetColor
  (JNIEnv * env, jobject thiz, jobject color) {
	wyTextureAtlas* atlas = (wyTextureAtlas*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyColor4B c = atlas->getColor();
	wyUtils_android::to_WYColor4B(c, color);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_opengl_TextureAtlas_setAlpha
  (JNIEnv * env, jobject thiz, jint alpha) {
	wyTextureAtlas* atlas = (wyTextureAtlas*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	atlas->setAlpha(alpha);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_opengl_TextureAtlas_updateColor
  (JNIEnv * env, jobject thiz, jobject color, jint index) {
	wyTextureAtlas* atlas = (wyTextureAtlas*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyColor4B c4 = wyUtils_android::to_wyColor4B( color);
	atlas->updateColor(c4, index);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_opengl_TextureAtlas_resizeCapacity
  (JNIEnv * env, jobject thiz, jint newCapacity) {
	wyTextureAtlas* atlas = (wyTextureAtlas*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	atlas->resizeCapacity(newCapacity);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_opengl_TextureAtlas_getPixelHeight
  (JNIEnv * env, jobject thiz) {
	wyTextureAtlas* atlas = (wyTextureAtlas*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return atlas->getTexture()->getPixelHeight();
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_opengl_TextureAtlas_getPixelWidth
  (JNIEnv * env, jobject thiz) {
	wyTextureAtlas* atlas = (wyTextureAtlas*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return atlas->getTexture()->getPixelWidth();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_opengl_TextureAtlas_draw__
  (JNIEnv * env, jobject thiz) {
	wyTextureAtlas* atlas = (wyTextureAtlas*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	atlas->drawAll();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_opengl_TextureAtlas_drawOne
  (JNIEnv * env, jobject thiz, jint index) {
	wyTextureAtlas* atlas = (wyTextureAtlas*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	atlas->drawOne(index);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_opengl_TextureAtlas_draw__I
  (JNIEnv * env, jobject thiz, jint numOfQuads) {
	wyTextureAtlas* atlas = (wyTextureAtlas*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	atlas->draw(numOfQuads);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_opengl_TextureAtlas_copyTo__ILcom_wiyun_engine_opengl_TextureAtlas_2
  (JNIEnv * env, jobject thiz, jint from, jobject destAtlas) {
	wyTextureAtlas* atlas = (wyTextureAtlas*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyTextureAtlas* dest = (wyTextureAtlas*)env->GetIntField(destAtlas, g_fid_BaseObject_mPointer);
	atlas->copyTo(from, dest);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_opengl_TextureAtlas_copyTo__ILcom_wiyun_engine_types_WYQuad2D_2Lcom_wiyun_engine_types_WYQuad3D_2
  (JNIEnv * env, jobject thiz, jint from, jobject quadT, jobject quadV) {
	wyTextureAtlas* atlas = (wyTextureAtlas*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyQuad2D t;
	wyQuad3D v;
	atlas->copyTo(from, &t, &v);
	if(quadT != NULL)
		wyUtils_android::to_WYQuad2D( t, quadT);
	if(quadV != NULL)
		wyUtils_android::to_WYQuad3D( v, quadV);
}
