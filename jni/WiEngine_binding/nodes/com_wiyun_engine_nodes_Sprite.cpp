#include "com_wiyun_engine_nodes_Sprite.h"
#include "wySprite.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_Sprite_nativeInit
  (JNIEnv * env, jobject thiz, jobject tex) {
	wyTexture2D* texNode = (wyTexture2D*)env->GetIntField(tex, g_fid_BaseObject_mPointer);
	wySprite* sprite = WYNEW wySprite(texNode);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)sprite);
	wyObjectLazyRelease(sprite);
}
