#include "com_wiyun_engine_opengl_Texture2D.h"
#include "wyUtils_android.h"
#include "wyColorFilter.h"
#include "wyGLTexture2D.h"
#include "wyTexture2D.h"
#include <stdlib.h>
#include "wyLog.h"

extern jfieldID g_fid_BaseObject_mPointer;
extern jfieldID g_fid_BitmapRawData_width;
extern jfieldID g_fid_BitmapRawData_height;
extern jfieldID g_fid_BitmapRawData_data;

JNIEXPORT void JNICALL Java_com_wiyun_engine_opengl_Texture2D_setAntiAlias
  (JNIEnv * env, jobject thiz, jboolean flag) {
	wyTexture2D* tex = (wyTexture2D*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	tex->setAntiAlias(flag);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_opengl_Texture2D_setRepeat
  (JNIEnv * env, jobject thiz, jboolean flag) {
	wyTexture2D* tex = (wyTexture2D*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	tex->setRepeat(flag);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_opengl_Texture2D_setTexParameters
  (JNIEnv * env, jobject thiz, jint min, jint mag, jint wrapS, jint wrapT) {
	wyTexture2D* tex = (wyTexture2D*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	tex->setParameters(min, mag, wrapS, wrapT);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_opengl_Texture2D_nativeInitBitmap
  (JNIEnv * env, jobject thiz, jobject raw, jint format) {
	jbyteArray bytes = (jbyteArray)env->GetObjectField(raw, g_fid_BitmapRawData_data);
	char* data = (char*)env->GetByteArrayElements(bytes, NULL);
	int width = env->GetIntField(raw, g_fid_BitmapRawData_width);
	int height = env->GetIntField(raw, g_fid_BitmapRawData_height);
	wyTexture2D* tex = wyTexture2D::makeRaw8888(data, width, height, (wyTexturePixelFormat)format);
	env->ReleaseByteArrayElements(bytes, (jbyte*)data, 0);
	tex->retain();
	tex->lazyRelease();
	return (jint)tex;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_opengl_Texture2D_updateRaw
  (JNIEnv * env, jobject thiz, jobject raw) {
	jbyteArray bytes = (jbyteArray)env->GetObjectField(raw, g_fid_BitmapRawData_data);
	char* data = (char*)env->GetByteArrayElements(bytes, NULL);
	wyTexture2D* tex = (wyTexture2D*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	tex->updateRaw(data);
	env->ReleaseByteArrayElements(bytes, (jbyte*)data, 0);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_opengl_Texture2D_nativeInitGL
  (JNIEnv * env, jobject thiz, jint t, jint w, jint h) {
	wyTexture2D* tex = wyTexture2D::makeGL(t, w, h);
	tex->retain();
	tex->lazyRelease();
	return (jint)tex;
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_opengl_Texture2D_nativeInit__III
(JNIEnv * env, jobject thiz, jint resId, jint transparentColor, jint format) {
	wyTexture2D* tex = wyTexture2D::make(resId, transparentColor, (wyTexturePixelFormat)format);
	tex->retain();
	tex->lazyRelease();
	return (jint)tex;
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_opengl_Texture2D_nativeInit__Ljava_lang_String_2IIF
(JNIEnv * env, jobject thiz, jstring path, jint transparentColor, jint format, jfloat inDensity) {
	const char* p = (const char*)env->GetStringUTFChars(path, NULL);
	wyTexture2D* tex = wyTexture2D::make(p, transparentColor, (wyTexturePixelFormat)format, inDensity);
	env->ReleaseStringUTFChars(path, p);
	tex->retain();
	tex->lazyRelease();
	return (jint)tex;
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_opengl_Texture2D_nativeInitLabel__Ljava_lang_String_2FLjava_lang_String_2ZFI
(JNIEnv * env, jobject thiz, jstring text, jfloat fontSize, jstring fontPath, jboolean isFile, jfloat width, jint alignment) {
	const char* t = (const char*)env->GetStringUTFChars(text, NULL);
	const char* p = fontPath == NULL ? NULL : (const char*)env->GetStringUTFChars(fontPath, NULL);
	wyTexture2D* tex = wyTexture2D::makeLabel(t, fontSize, p, isFile, width, (wyTexture2D::TextAlignment)alignment);
	env->ReleaseStringUTFChars(text, t);
	env->ReleaseStringUTFChars(fontPath, p);
	tex->retain();
	tex->lazyRelease();
	return (jint)tex;
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_opengl_Texture2D_nativeInitLabel__Ljava_lang_String_2FILjava_lang_String_2FI
(JNIEnv * env, jobject thiz, jstring text, jfloat fontSize, jint style, jstring fontName, jfloat width, jint alignment) {
	const char* t = (const char*)env->GetStringUTFChars(text, NULL);
	const char* n = fontName == NULL ? NULL : (const char*)env->GetStringUTFChars(fontName, NULL);
	wyTexture2D* tex = wyTexture2D::makeLabel(t, fontSize, (wyFontStyle)style, n, width, (wyTexture2D::TextAlignment)alignment);
	env->ReleaseStringUTFChars(text, t);
	env->ReleaseStringUTFChars(fontName, n);
	tex->retain();
	tex->lazyRelease();
	return (jint)tex;
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_opengl_Texture2D_nativeInitFile
(JNIEnv * env, jobject thiz, jstring path, jint transparentColor, jint format, jfloat inDensity) {
	const char* p = (const char*)env->GetStringUTFChars(path, NULL);
	wyTexture2D* tex = wyTexture2D::makeFile(p, transparentColor, (wyTexturePixelFormat)format, inDensity);
	env->ReleaseStringUTFChars(path, p);
	tex->retain();
	tex->lazyRelease();
	return (jint)tex;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_opengl_Texture2D_applyTexParameters
  (JNIEnv * env, jobject thiz) {
	wyTexture2D* tex = (wyTexture2D*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	tex->applyParameters();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_opengl_Texture2D_nativeDrawAtPoint__FF
  (JNIEnv * env, jobject thiz, jfloat x, jfloat y) {
	wyTexture2D* tex = (wyTexture2D*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	tex->draw(x, y);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_opengl_Texture2D_nativeDrawAtPoint__FFZZ
  (JNIEnv * env, jobject thiz, jfloat x, jfloat y, jboolean flipX, jboolean flipY) {
	wyTexture2D* tex = (wyTexture2D*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	tex->draw(x, y, (bool)flipX, (bool)flipY);
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_opengl_Texture2D_getHeight
  (JNIEnv * env, jobject thiz) {
	wyTexture2D* tex = (wyTexture2D*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return tex->getHeight();
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_opengl_Texture2D_getWidth
  (JNIEnv * env, jobject thiz) {
	wyTexture2D* tex = (wyTexture2D*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return tex->getWidth();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_opengl_Texture2D_loadTexture
  (JNIEnv * env, jobject thiz) {
	wyTexture2D* tex = (wyTexture2D*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	tex->load();
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_opengl_Texture2D_getWidthScale
  (JNIEnv * env, jobject thiz) {
	wyTexture2D* tex = (wyTexture2D*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return tex->getWidthScale();
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_opengl_Texture2D_getHeightScale
  (JNIEnv * env, jobject thiz) {
	wyTexture2D* tex = (wyTexture2D*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return tex->getHeightScale();
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_opengl_Texture2D_getPixelHeight
  (JNIEnv * env, jobject thiz) {
	wyTexture2D* tex = (wyTexture2D*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return tex->getPixelHeight();
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_opengl_Texture2D_getPixelWidth
  (JNIEnv * env, jobject thiz) {
	wyTexture2D* tex = (wyTexture2D*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return tex->getPixelWidth();
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_opengl_Texture2D_isFlipX
  (JNIEnv * env, jobject thiz) {
	wyTexture2D* tex = (wyTexture2D*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return tex->isFlipX();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_opengl_Texture2D_setFlipX
  (JNIEnv * env, jobject thiz, jboolean flipX) {
	wyTexture2D* tex = (wyTexture2D*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return tex->setFlipX(flipX);
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_opengl_Texture2D_isFlipY
  (JNIEnv * env, jobject thiz) {
	wyTexture2D* tex = (wyTexture2D*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return tex->isFlipY();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_opengl_Texture2D_setFlipY
  (JNIEnv * env, jobject thiz, jboolean flipY) {
	wyTexture2D* tex = (wyTexture2D*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return tex->setFlipY(flipY);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_opengl_Texture2D_setColorFilter
  (JNIEnv * env, jobject thiz, jobject filter) {
	wyTexture2D* tex = (wyTexture2D*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyColorFilter* f = filter == NULL ? NULL : (wyColorFilter*)env->GetIntField(filter, g_fid_BaseObject_mPointer);
	tex->setColorFilter(f);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_opengl_Texture2D_applyFilter
  (JNIEnv * env, jobject thiz) {
	wyTexture2D* tex = (wyTexture2D*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	tex->applyFilter();
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_opengl_Texture2D_nativeClone
  (JNIEnv * env, jobject thiz, jint cloneId) {
	wyTexture2D* tex = (wyTexture2D*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return (jint)tex->clone(cloneId);
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_opengl_Texture2D_switchToClone
  (JNIEnv * env, jobject thiz, jint cloneId) {
	wyTexture2D* tex = (wyTexture2D*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return tex->switchToClone(cloneId);
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_opengl_Texture2D_deleteClone
  (JNIEnv * env, jobject thiz, jint cloneId) {
	wyTexture2D* tex = (wyTexture2D*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return tex->deleteClone(cloneId);
}
