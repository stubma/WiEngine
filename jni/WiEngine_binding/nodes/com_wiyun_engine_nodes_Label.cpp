#include "com_wiyun_engine_nodes_Label.h"
#include "wyLabel.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Label_nativeInit__Ljava_lang_String_2FLjava_lang_String_2ZFI
  (JNIEnv * env, jobject thiz, jstring text, jfloat fontSize, jstring fontPath, jboolean isFile, jfloat width, jint alignment) {
	const char* t = (const char*)env->GetStringUTFChars(text, NULL);
	const char* p = fontPath == NULL ? NULL : (const char*)env->GetStringUTFChars(fontPath, NULL);
	wyLabel* label = wyLabel::make(t, fontSize, p, isFile, width, (wyTexture2D::TextAlignment)alignment);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)label);
	env->ReleaseStringUTFChars(text, t);
	if(p != NULL)
		env->ReleaseStringUTFChars(fontPath, p);
	label->retain();
	label->lazyRelease();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Label_nativeInit__Ljava_lang_String_2FILjava_lang_String_2FI
  (JNIEnv * env, jobject thiz, jstring text, jfloat fontSize, jint style, jstring fontName, jfloat width, jint alignment) {
	const char* t = (const char*)env->GetStringUTFChars(text, NULL);
	const char* n = fontName == NULL ? NULL : (const char*)env->GetStringUTFChars(fontName, NULL);
	wyLabel* label = wyLabel::make(t, fontSize, (wyFontStyle)style, n, width, (wyTexture2D::TextAlignment)alignment);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)label);
	env->ReleaseStringUTFChars(text, t);
	if(n != NULL)
		env->ReleaseStringUTFChars(fontName, n);
	label->retain();
	label->lazyRelease();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Label_setText
  (JNIEnv * env, jobject thiz, jstring text) {
	wyLabel* label = (wyLabel*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	const char* t = (const char*)env->GetStringUTFChars(text, NULL);
	label->setString(t);
	env->ReleaseStringUTFChars(text, t);
}

JNIEXPORT jstring JNICALL Java_com_wiyun_engine_nodes_Label_getText
  (JNIEnv * env, jobject thiz) {
	wyLabel* label = (wyLabel*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	const char* text = label->getText();
	jstring s = env->NewStringUTF(text);
	return s;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Label_setFontSize
  (JNIEnv * env, jobject thiz, jfloat fontSize) {
	wyLabel* label = (wyLabel*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	label->setFontSize(fontSize);
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_nodes_Label_getFontSize
  (JNIEnv * env, jobject thiz) {
	wyLabel* label = (wyLabel*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return label->getFontSize();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Label_setFontStyle
  (JNIEnv * env, jobject thiz, jint fontStyle) {
	wyLabel* label = (wyLabel*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	label->setFontStyle((wyFontStyle)fontStyle);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_nodes_Label_getFontStyle
  (JNIEnv * env, jobject thiz) {
	wyLabel* label = (wyLabel*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return (jint)label->getFontStyle();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Label_setFontName
  (JNIEnv * env, jobject thiz, jstring jFontName) {
	wyLabel* label = (wyLabel*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	const char* fontName = (const char*)env->GetStringUTFChars(jFontName, NULL);
	label->setFontName(fontName);
	env->ReleaseStringUTFChars(jFontName, fontName);
}

JNIEXPORT jstring JNICALL Java_com_wiyun_engine_nodes_Label_getFontName
  (JNIEnv * env, jobject thiz) {
	wyLabel* label = (wyLabel*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	const char* text = label->getFontName();
	jstring s = env->NewStringUTF(text);
	return s;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Label_setFontPath
  (JNIEnv * env, jobject thiz, jstring jFontPath, jboolean isFile) {
	wyLabel* label = (wyLabel*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	const char* fontPath = (const char*)env->GetStringUTFChars(jFontPath, NULL);
	label->setFontPath(fontPath, isFile);
	env->ReleaseStringUTFChars(jFontPath, fontPath);
}

JNIEXPORT jstring JNICALL Java_com_wiyun_engine_nodes_Label_getFontPath
  (JNIEnv * env, jobject thiz) {
	wyLabel* label = (wyLabel*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	const char* text = label->getFontPath();
	jstring s = env->NewStringUTF(text);
	return s;
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_nodes_Label_isFileFontPath
  (JNIEnv * env, jobject thiz) {
	wyLabel* label = (wyLabel*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return label->isFileFontPath();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Label_setLineWidth
  (JNIEnv * env, jobject thiz, jfloat width) {
	wyLabel* label = (wyLabel*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	label->setLineWidth(width);
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_nodes_Label_getLineWidth
  (JNIEnv * env, jobject thiz) {
	wyLabel* label = (wyLabel*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return label->getLineWidth();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Label_setAlignment
  (JNIEnv * env, jobject thiz, jint alignment) {
	wyLabel* label = (wyLabel*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	label->setAlignment((wyTexture2D::TextAlignment)alignment);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_nodes_Label_getAlignment
  (JNIEnv * env, jobject thiz) {
	wyLabel* label = (wyLabel*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return label->getAlignment();
}
