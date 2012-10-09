#include "wyCoverFlowAction.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_actions_CoverFlowAction_nativeInit
  (JNIEnv* env, jobject thiz, jfloat duration, jobject cover) {
    wyCover* targetCover = (wyCover*) env->GetIntField(cover, g_fid_BaseObject_mPointer);
    wyCoverFlowAction* cfa = wyCoverFlowAction::make(duration, targetCover);
    env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)cfa);
    cfa->retain();
    cfa->lazyRelease();
}

