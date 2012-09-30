#include "com_wiyun_engine_nodes_Animation.h"
#include "wyAnimation.h"
#include "wyUtils_android.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT jint JNICALL Java_com_wiyun_engine_nodes_Animation_getId
  (JNIEnv * env, jobject thiz) {
	wyAnimation* anim = (wyAnimation*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return anim->getId();
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_nodes_Animation_getFrameCount
  (JNIEnv * env, jobject thiz) {
	wyAnimation* anim = (wyAnimation*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return anim->getFrames()->num;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Animation_nativeGetFrames
  (JNIEnv * env, jobject thiz, jintArray pointers) {
	wyAnimation* anim = (wyAnimation*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	int* p = env->GetIntArrayElements(pointers, NULL);
	for(int i = 0; i < anim->getFrames()->num; i++) {
		p[i] = (jint)wyArrayGet(anim->getFrames(), i);
	}
	env->ReleaseIntArrayElements(pointers, p, JNI_COMMIT);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Animation_nativeInit
  (JNIEnv * env, jobject thiz, jint id) {
	wyAnimation* anim = wyAnimation::make(id);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)anim);
	anim->retain();
	anim->lazyRelease();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Animation_addFrame__FLcom_wiyun_engine_opengl_Texture2D_2
  (JNIEnv * env, jobject thiz, jfloat frameDuration, jobject texture) {
	wyAnimation* anim = (wyAnimation*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyTexture2D* tex = (wyTexture2D*)env->GetIntField(texture, g_fid_BaseObject_mPointer);
	anim->addFrame(frameDuration, tex);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Animation_addFrame__FLcom_wiyun_engine_types_WYRect_2
  (JNIEnv * env, jobject thiz, jfloat frameDuration, jobject rect) {
	wyAnimation* anim = (wyAnimation*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyRect r = wyUtils_android::to_wyRect( rect);
	anim->addFrame(frameDuration, r);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Animation_addFrame__Lcom_wiyun_engine_nodes_Frame_2
  (JNIEnv * env, jobject thiz, jobject frame) {
	wyAnimation* anim = (wyAnimation*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyFrame* f = (wyFrame*)env->GetIntField(frame, g_fid_BaseObject_mPointer);
	anim->addFrame(f);
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_nodes_Animation_getDuration
  (JNIEnv * env, jobject thiz) {
	wyAnimation* anim = (wyAnimation*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return anim->getDuration();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Animation_setCallback
  (JNIEnv * env, jobject thiz, jobject callback) {
	wyAnimation* anim = (wyAnimation*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	anim->setCallback(callback);
}
