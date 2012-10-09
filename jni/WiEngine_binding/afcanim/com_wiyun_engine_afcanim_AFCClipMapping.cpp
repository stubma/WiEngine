#include "com_wiyun_engine_afcanim_AFCClipMapping.h"
#include "wyAFCClipMapping.h"
#include "wyUtils_android.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_afcanim_AFCClipMapping_nativeInit__ILjava_lang_String_2
  (JNIEnv * env, jobject thiz, jint tag, jstring mfsName) {
	const char* n = (const char*)env->GetStringUTFChars(mfsName, NULL);
	wyAFCClipMapping* m = wyAFCClipMapping::makeAurora(tag, n);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)m);
	env->ReleaseStringUTFChars(mfsName, n);
	m->retain();
	m->lazyRelease();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_afcanim_AFCClipMapping_nativeInit__ILjava_lang_String_2Z
  (JNIEnv * env, jobject thiz, jint tag, jstring path, jboolean isFile) {
	const char* p = (const char*)env->GetStringUTFChars(path, NULL);
	wyAFCClipMapping* m = wyAFCClipMapping::makeAurora(tag, p, (bool)isFile);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)m);
	env->ReleaseStringUTFChars(path, p);
	m->retain();
	m->lazyRelease();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_afcanim_AFCClipMapping_nativeInit__II
  (JNIEnv * env, jobject thiz, jint tag, jint ammId) {
	wyAFCClipMapping* m = wyAFCClipMapping::makeAurora(tag, ammId);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)m);
	m->retain();
	m->lazyRelease();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_afcanim_AFCClipMapping_nativeInit__I
  (JNIEnv * env, jobject thiz, jint tag) {
	wyAFCClipMapping* m = wyAFCClipMapping::make(tag);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)m);
	m->retain();
	m->lazyRelease();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_afcanim_AFCClipMapping_mapClip__II
  (JNIEnv * env, jobject thiz, jint fromClipIndex, jint toClipIndex) {
	wyAFCClipMapping* m = (wyAFCClipMapping*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	m->mapClip(fromClipIndex, toClipIndex);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_afcanim_AFCClipMapping_mapClip__III
  (JNIEnv * env, jobject thiz, jint fromClipIndex, jint externalFileDataId, jint toClipIndex) {
	wyAFCClipMapping* m = (wyAFCClipMapping*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	m->mapClip(fromClipIndex, externalFileDataId, toClipIndex);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_afcanim_AFCClipMapping_mapClip__ILcom_wiyun_engine_opengl_Texture2D_2Lcom_wiyun_engine_types_WYPoint_2Lcom_wiyun_engine_types_WYRect_2ZF
  (JNIEnv * env, jobject thiz, jint fromClipIndex, jobject tex, jobject pos, jobject texRect, jboolean flipX, jfloat rotation) {
	wyAFCClipMapping* m = (wyAFCClipMapping*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyTexture2D* t = (wyTexture2D*)env->GetIntField(tex, g_fid_BaseObject_mPointer);
	m->mapClip(fromClipIndex, t, wyUtils_android::to_wyPoint( pos), wyUtils_android::to_wyRect( texRect), flipX, rotation);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_afcanim_AFCClipMapping_getTag
  (JNIEnv * env, jobject thiz) {
	wyAFCClipMapping* m = (wyAFCClipMapping*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return m->getTag();
}
