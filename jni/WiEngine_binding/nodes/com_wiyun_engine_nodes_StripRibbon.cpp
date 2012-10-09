#include "com_wiyun_engine_nodes_StripRibbon.h"
#include "wyStripRibbon.h"

extern jfieldID g_fid_BaseObject_mPointer;
extern jfieldID g_fid_WYColor4B_r;
extern jfieldID g_fid_WYColor4B_g;
extern jfieldID g_fid_WYColor4B_b;
extern jfieldID g_fid_WYColor4B_a;

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_StripRibbon_nativeInit
  (JNIEnv * env, jobject thiz, jobject texture, jobject color, jfloat fade) {
	wyTexture2D* tex = (wyTexture2D*)env->GetIntField(texture, g_fid_BaseObject_mPointer);
	wyColor4B c = {
		env->GetIntField(color, g_fid_WYColor4B_r),
		env->GetIntField(color, g_fid_WYColor4B_g),
		env->GetIntField(color, g_fid_WYColor4B_b),
		env->GetIntField(color, g_fid_WYColor4B_a)
	};
	wyStripRibbon* ribbon = WYNEW wyStripRibbon(tex, c, fade);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)ribbon);
	wyObjectLazyRelease(ribbon);
}
