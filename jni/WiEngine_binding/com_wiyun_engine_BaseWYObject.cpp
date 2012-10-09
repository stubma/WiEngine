#include "com_wiyun_engine_BaseWYObject.h"
#include "wyObject.h"
#include "wyLog.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_BaseWYObject_nativeAutoRelease
  (JNIEnv * env, jobject thiz) {
	wyObject* obj = (wyObject*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	if(obj != NULL)
		obj->javaRelease();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_BaseWYObject_setName
  (JNIEnv * env, jobject thiz, jstring jName) {
    wyObject* object = (wyObject*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);  
    const char* name = (const char*)env->GetStringUTFChars(jName, NULL);
    object->setName(name);
    env->ReleaseStringUTFChars(jName, name);
}

JNIEXPORT jstring JNICALL Java_com_wiyun_engine_BaseWYObject_getName
  (JNIEnv * env, jobject thiz) {
    wyObject* object = (wyObject*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);  
    const char* name = object->getName();
    return env->NewStringUTF(name);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_BaseWYObject_connectNativeTargetSelector
  (JNIEnv * env, jobject thiz) {
	wyObject* obj = (wyObject*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	obj->setJavaTSConnector(thiz);
}
