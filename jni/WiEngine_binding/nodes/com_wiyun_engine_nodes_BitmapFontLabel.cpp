#include "com_wiyun_engine_nodes_BitmapFontLabel.h"
#include "wyBitmapFontLabel.h"
#include "wyUtils_android.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_BitmapFontLabel_nativeInit
  (JNIEnv* env, jobject thiz, jobject jFont, jstring jText) {
    wyBitmapFont* font = (wyBitmapFont*)env->GetIntField(jFont, g_fid_BaseObject_mPointer);
    const char* text = env->GetStringUTFChars(jText, NULL);
    wyBitmapFontLabel* fontLabel = WYNEW wyBitmapFontLabel(font, text);
    env->ReleaseStringUTFChars(jText, text);
    env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)fontLabel);
    fontLabel->lazyRelease();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_BitmapFontLabel_setFont
  (JNIEnv* env, jobject thiz, jobject jFont) {
    wyBitmapFont* font = (wyBitmapFont*)env->GetIntField(jFont, g_fid_BaseObject_mPointer);
    wyBitmapFontLabel* fontLabel = (wyBitmapFontLabel*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);  
    fontLabel->setFont(font);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_BitmapFontLabel_nativeGetFont
  (JNIEnv* env, jobject thiz, jobject jFont) {
    wyBitmapFontLabel* fontLabel = (wyBitmapFontLabel*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);  
    wyBitmapFont* font = fontLabel->getFont();
    env->SetIntField(jFont, g_fid_BaseObject_mPointer, (jint)font);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_BitmapFontLabel_setText
  (JNIEnv* env, jobject thiz, jstring jText) {
    wyBitmapFontLabel* fontLabel = (wyBitmapFontLabel*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);  
    const char* text = (const char*)env->GetStringUTFChars(jText, NULL);
    fontLabel->setText(text);
    env->ReleaseStringUTFChars(jText, text);
}

JNIEXPORT jstring JNICALL Java_com_wiyun_engine_nodes_BitmapFontLabel_getText
  (JNIEnv* env, jobject thiz){
    wyBitmapFontLabel* fontLabel = (wyBitmapFontLabel*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);  
    const char* text = fontLabel->getText();
    return env->NewStringUTF(text);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_BitmapFontLabel_setColor
  (JNIEnv* env, jobject thiz , jobject jColor) {
    wyBitmapFontLabel* fontLabel = (wyBitmapFontLabel*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);  
    fontLabel->setColor(wyUtils_android::to_wyColor3B( jColor));
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_BitmapFontLabel_nativeGetColor
  (JNIEnv* env, jobject thiz, jobject jColor) {
    wyBitmapFontLabel* fontLabel = (wyBitmapFontLabel*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);  
    wyUtils_android::to_WYColor3B(fontLabel->getColor(), jColor);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_nodes_BitmapFontLabel_getAlpha
  (JNIEnv * env, jobject thiz) {
    wyBitmapFontLabel* fontLabel = (wyBitmapFontLabel*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);  
    return fontLabel->getAlpha();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_BitmapFontLabel_setAlpha
  (JNIEnv * env, jobject thiz, jint alpha) {
    wyBitmapFontLabel* fontLabel = (wyBitmapFontLabel*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);  
	fontLabel->setAlpha(alpha);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_BitmapFontLabel_setSpaceWidth
  (JNIEnv* env, jobject thiz, jfloat w) {
	wyBitmapFontLabel* fontLabel = (wyBitmapFontLabel*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	fontLabel->setSpaceWidth(w);
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_nodes_BitmapFontLabel_getSpaceWidth
  (JNIEnv* env, jobject thiz) {
	wyBitmapFontLabel* fontLabel = (wyBitmapFontLabel*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return fontLabel->getSpaceWidth();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_BitmapFontLabel_setTabSize
  (JNIEnv* env, jobject thiz, jint tabSize) {
	wyBitmapFontLabel* fontLabel = (wyBitmapFontLabel*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	fontLabel->setTabSize(tabSize);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_nodes_BitmapFontLabel_getTabSize
  (JNIEnv* env, jobject thiz) {
	wyBitmapFontLabel* fontLabel = (wyBitmapFontLabel*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return fontLabel->getTabSize();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_BitmapFontLabel_setLineWidth
  (JNIEnv* env, jobject thiz, jfloat jWidth) {
	wyBitmapFontLabel* fontLabel = (wyBitmapFontLabel*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	fontLabel->setLineWidth(jWidth);
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_nodes_BitmapFontLabel_getLineWidth
  (JNIEnv* env, jobject thiz) {
	wyBitmapFontLabel* fontLabel = (wyBitmapFontLabel*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return fontLabel->getLineWidth();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_BitmapFontLabel_setAlignment
  (JNIEnv * env, jobject thiz, jint alignment) {
	wyBitmapFontLabel* fontLabel = (wyBitmapFontLabel*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	fontLabel->setAlignment((wyBitmapFontLabel::Alignment)alignment);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_nodes_BitmapFontLabel_getAlignment
  (JNIEnv * env, jobject thiz) {
	wyBitmapFontLabel* fontLabel = (wyBitmapFontLabel*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return fontLabel->getAlignment();
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_nodes_BitmapFontLabel_getLineSpacing
  (JNIEnv * env, jobject thiz) {
	wyBitmapFontLabel* fontLabel = (wyBitmapFontLabel*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return fontLabel->getLineSpacing();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_BitmapFontLabel_setLineSpacing
  (JNIEnv * env, jobject thiz, jfloat spacing) {
	wyBitmapFontLabel* fontLabel = (wyBitmapFontLabel*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	fontLabel->setLineSpacing(spacing);
}
