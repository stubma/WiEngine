#include "com_wiyun_engine_nodes_AtlasLabel.h"
#include "wyAtlasLabel.h"
#include "wyUtils_android.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_AtlasLabel_nativeInit
  (JNIEnv * env, jobject thiz, jstring text, jobject tex, jobject charMap) {
	const char* s = (const char*)env->GetStringUTFChars(text, NULL);
	wyTexture2D* t = (wyTexture2D*)env->GetIntField(tex, g_fid_BaseObject_mPointer);
	wyCharMap* map = (wyCharMap*)env->GetIntField(charMap, g_fid_BaseObject_mPointer);
	wyAtlasLabel* label = WYNEW wyAtlasLabel(s, t, map);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)label);
	env->ReleaseStringUTFChars(text, s);
	label->lazyRelease();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_AtlasLabel_setText
  (JNIEnv * env, jobject thiz, jstring text) {
	wyAtlasLabel* label = (wyAtlasLabel*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	const char* t = (const char*)env->GetStringUTFChars(text, NULL);
	label->setText(t);
	env->ReleaseStringUTFChars(text, t);
}

JNIEXPORT jstring JNICALL Java_com_wiyun_engine_nodes_AtlasLabel_getText
  (JNIEnv * env, jobject thiz) {
	wyAtlasLabel* label = (wyAtlasLabel*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	const char* text = label->getText();
	jstring s = env->NewStringUTF(text);
	return s;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_AtlasLabel_setLineWidth
  (JNIEnv* env, jobject thiz, jfloat jWidth) {
	wyAtlasLabel* fontLabel = (wyAtlasLabel*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	fontLabel->setLineWidth(jWidth);
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_nodes_AtlasLabel_getLineWidth
  (JNIEnv * env, jobject thiz) {
	wyAtlasLabel* fontLabel = (wyAtlasLabel*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return fontLabel->getLineWidth();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_AtlasLabel_setAlignment
  (JNIEnv * env, jobject thiz, jint alignment) {
	wyAtlasLabel* fontLabel = (wyAtlasLabel*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	fontLabel->setAlignment((wyAtlasLabel::Alignment)alignment);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_nodes_AtlasLabel_getAlignment
  (JNIEnv * env, jobject thiz) {
	wyAtlasLabel* fontLabel = (wyAtlasLabel*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return fontLabel->getAlignment();
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_nodes_AtlasLabel_getLineSpacing
  (JNIEnv * env, jobject thiz) {
	wyAtlasLabel* fontLabel = (wyAtlasLabel*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return fontLabel->getLineSpacing();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_AtlasLabel_setLineSpacing
  (JNIEnv * env, jobject thiz, jfloat spacing) {
	wyAtlasLabel* fontLabel = (wyAtlasLabel*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	fontLabel->setLineSpacing(spacing);
}
