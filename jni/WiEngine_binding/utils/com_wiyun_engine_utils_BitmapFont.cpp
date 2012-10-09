#include "com_wiyun_engine_utils_BitmapFont.h"
#include "wyBitmapFont.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_utils_BitmapFont_nativeInit__II
  (JNIEnv* env, jobject thiz, jint resId, jint format) {
    wyBitmapFont* font = wyBitmapFont::loadFont(resId, (wyBitmapFontFormat)format);
    env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)font);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_utils_BitmapFont_nativeInit__Ljava_lang_String_2ZIF
  (JNIEnv* env, jobject thiz, jstring jPath, jboolean isFile, jint format, jfloat inDensity) {
    const char* path = (const char*)env->GetStringUTFChars(jPath, NULL);
    wyBitmapFont* font = wyBitmapFont::loadFont(path, isFile, (wyBitmapFontFormat)format, inDensity);
    env->ReleaseStringUTFChars(jPath, path);
    env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)font);    
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_utils_BitmapFont_unloadFont
  (JNIEnv* env, jclass clazz, jobject jFont) {
    wyBitmapFont* font = (wyBitmapFont*)env->GetIntField(jFont, g_fid_BaseObject_mPointer);
    wyBitmapFont::unloadFont(font);
}
