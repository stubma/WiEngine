#include "com_wiyun_engine_nodes_Frame.h"
#include "wyFrame.h"


extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT jfloat JNICALL Java_com_wiyun_engine_nodes_Frame_getDuration
  (JNIEnv * env, jobject thiz) {
	wyFrame* f = (wyFrame*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return f->getDuration();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Frame_setDuration
  (JNIEnv * env, jobject thiz, jfloat duration) {
	wyFrame* f = (wyFrame*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	f->setDuration(duration);
}
