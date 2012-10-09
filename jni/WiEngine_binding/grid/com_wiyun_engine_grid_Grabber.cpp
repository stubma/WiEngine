#include <jni.h>
#include "com_wiyun_engine_grid_Grabber.h"

#include "wyGrabber.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_grid_Grabber_nativeInit
  (JNIEnv * env, jobject thiz) {
	wyGrabber* grabber = wyGrabber::make();
	grabber->retain();
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)grabber);
	grabber->lazyRelease();
}
