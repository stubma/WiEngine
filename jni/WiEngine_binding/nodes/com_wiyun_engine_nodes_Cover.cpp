#include "com_wiyun_engine_nodes_Cover.h"
#include "wyCoverFlow.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Cover_nativeInit
  (JNIEnv* env, jobject thiz, jobject jTex) {
    wyTexture2D* tex = (wyTexture2D*)env->GetIntField(jTex, g_fid_BaseObject_mPointer);
    wyCover* cover = WYNEW wyCover(tex);
    env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)cover);
    cover->lazyRelease();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Cover_setPosition
  (JNIEnv* env, jobject thiz, jfloat x, jfloat y) {
    wyCover* cover = (wyCover*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
    cover->setPosition(x, y);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_nodes_Cover_getPositionX
  (JNIEnv* env, jobject thiz) {
    wyCover* cover = (wyCover*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
    return cover->getPosition().x;
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_nodes_Cover_getPositionY
  (JNIEnv* env, jobject thiz) {
    wyCover* cover = (wyCover*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
    return cover->getPosition().y;
}


JNIEXPORT jint JNICALL Java_com_wiyun_engine_nodes_Cover_getPositionZ
  (JNIEnv* env, jobject thiz) {
    wyCover* cover = (wyCover*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
    return cover->getPosition().z;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Cover_setRotateY
  (JNIEnv* env, jobject thiz, jfloat degree) {
    wyCover* cover = (wyCover*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
    cover->setRotateY(degree);
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_nodes_Cover_getRotateY
  (JNIEnv* env, jobject thiz) {
    wyCover* cover = (wyCover*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
    return cover->getRotateY();  
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Cover_setScale
  (JNIEnv* env, jobject thiz, jfloat scale) {
    wyCover* cover = (wyCover*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
    return cover->setScale(scale);
}

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_nodes_Cover_getScale
  (JNIEnv* env, jobject thiz) {
    wyCover* cover = (wyCover*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
    return cover->getScale();
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_nodes_Cover_nativeGetTexture
  (JNIEnv* env, jobject thiz) {
    wyCover* cover = (wyCover*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
    return (jint)cover->getTexture();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Cover_setTexture
  (JNIEnv* env, jobject thiz, jobject tex) {
    wyTexture2D* pTex = (wyTexture2D*)env->GetIntField(tex, g_fid_BaseObject_mPointer);
    wyCover* cover = (wyCover*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
    cover->setTexture(pTex);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_nodes_Cover_nativeGetNext
  (JNIEnv* env, jobject thiz) {
    wyCover* cover = (wyCover*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
    return (jint)cover->getNext();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Cover_setNext
  (JNIEnv* env, jobject thiz, jobject cover) {
    wyCover* next = (wyCover*)env->GetIntField(cover, g_fid_BaseObject_mPointer);
    wyCover* pCover = (wyCover*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
    pCover->setNext(next);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_nodes_Cover_nativeGetPrev
  (JNIEnv* env, jobject thiz) {
    wyCover* cover = (wyCover*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
    return (jint)cover->getPrev(); 
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Cover_setPrev
  (JNIEnv* env, jobject thiz, jobject cover) {
    wyCover* prev = (wyCover*)env->GetIntField(cover, g_fid_BaseObject_mPointer);
    wyCover* pCover = (wyCover*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
    pCover->setPrev(prev);
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_nodes_Cover_getAutoUpdate
  (JNIEnv* env, jobject thiz) {
    wyCover* pCover = (wyCover*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
    return pCover->getAutoUpdate();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Cover_setAutoUpdate
  (JNIEnv* env, jobject thiz, jboolean bAutoUpdate) {
    wyCover* pCover = (wyCover*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
    return pCover->setAutoUpdate(bAutoUpdate);
}

