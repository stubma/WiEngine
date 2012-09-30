#include "com_wiyun_engine_actions_grid_Twirl.h"
#include "wyTwirl.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_actions_grid_Twirl_nativeInit
  (JNIEnv * env, jobject thiz, jfloat duration, jint gridX, jint gridY, jfloat centerX, jfloat centerY, jfloat deltaX, jfloat deltaY, jfloat amplitude,
		  jfloat deltaAmplitude, jfloat twirls) {
	wyTwirl* g = WYNEW wyTwirl(duration, gridX, gridY, centerX, centerY, deltaX, deltaY, amplitude,
	        deltaAmplitude, twirls);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)g);
	wyObjectAutoRelease(g);
}
