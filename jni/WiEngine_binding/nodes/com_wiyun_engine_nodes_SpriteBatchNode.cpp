#include "com_wiyun_engine_nodes_SpriteBatchNode.h"
#include "wySpriteBatchNode.h"
#include "wyUtils_android.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_nodes_SpriteBatchNode_nativeInit
  (JNIEnv* env, jobject thiz, jobject tex) {
	wyTexture2D* texNode = (wyTexture2D*)env->GetIntField(tex, g_fid_BaseObject_mPointer);
	wySpriteBatchNode* batchNode = WYNEW wySpriteBatchNode(texNode);
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)batchNode);
	wyObjectLazyRelease(batchNode);
}
