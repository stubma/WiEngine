#include "com_wiyun_engine_chipmunk_ShapeAnimation.h"
#include "wyShapeAnimation.h"

extern jfieldID g_fid_Shape_mPointer;
extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_ShapeAnimation_nativeInit
  (JNIEnv * env, jobject thiz) {
	wyShapeAnimation* anim = WYNEW wyShapeAnimation();
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)anim);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_ShapeAnimation_nativeAddFrame
  (JNIEnv * env, jobject thiz, jfloat duration, jobject texture) {
	wyShapeAnimation* anim = (wyShapeAnimation*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyTexture2D* tex = (wyTexture2D*)env->GetIntField(texture, g_fid_BaseObject_mPointer);
	anim->addFrame(duration, tex);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_ShapeAnimation_start
  (JNIEnv * env, jobject thiz, jobject shape) {
	wyShapeAnimation* anim = (wyShapeAnimation*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	cpShape* shapeStruct = (cpShape*)env->GetIntField(shape, g_fid_Shape_mPointer);
	anim->start(shapeStruct);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_ShapeAnimation_stop
  (JNIEnv * env, jobject thiz) {
	wyShapeAnimation* anim = (wyShapeAnimation*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	anim->stop();
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_chipmunk_ShapeAnimation_isLoop
  (JNIEnv * env, jobject thiz) {
	wyShapeAnimation* anim = (wyShapeAnimation*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return anim->isLoop();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_ShapeAnimation_setLoop
  (JNIEnv * env, jobject thiz, jboolean loop) {
	wyShapeAnimation* anim = (wyShapeAnimation*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	anim->setLoop(loop);
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_chipmunk_ShapeAnimation_getDuration
  (JNIEnv * env, jobject thiz) {
	wyShapeAnimation* anim = (wyShapeAnimation*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return anim->getDuration();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_ShapeAnimation_setDuration
  (JNIEnv * env, jobject thiz, jfloat duration) {
	wyShapeAnimation* anim = (wyShapeAnimation*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	anim->setDuration(duration);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_ShapeAnimation_setCallback
  (JNIEnv * env, jobject thiz, jobject callback) {
	wyShapeAnimation* anim = (wyShapeAnimation*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	anim->setJavaCallback(callback);
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_chipmunk_ShapeAnimation_isAutoSize
  (JNIEnv * env, jobject thiz) {
	wyShapeAnimation* anim = (wyShapeAnimation*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return anim->isAutoSize();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_chipmunk_ShapeAnimation_setAutoSize
  (JNIEnv * env, jobject thiz, jboolean autoSize) {
	wyShapeAnimation* anim = (wyShapeAnimation*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	anim->setAutoSize(autoSize);
}
