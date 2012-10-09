#include "com_wiyun_engine_box2d_Box2DRender.h"
#include "wyBox2DRender.h"
#include "wyUtils_android.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_Box2DRender_nativeInit
  (JNIEnv * env, jobject thiz) {
	wyBox2DRender* r = WYNEW wyBox2DRender();
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)r);
	r->lazyRelease();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_Box2DRender_bindTexture__Lcom_wiyun_engine_box2d_dynamics_Fixture_2Lcom_wiyun_engine_opengl_Texture2D_2
  (JNIEnv * env, jobject thiz, jobject fixture, jobject texture) {
	wyBox2DRender* r = (wyBox2DRender*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyTexture2D* t = texture == NULL ? NULL : (wyTexture2D*)env->GetIntField(texture, g_fid_BaseObject_mPointer);
	b2Fixture* f = (b2Fixture*)env->GetIntField(fixture, g_fid_BaseObject_mPointer);
	r->bindTexture(f, t);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_Box2DRender_bindTexture__Lcom_wiyun_engine_box2d_dynamics_Fixture_2Lcom_wiyun_engine_opengl_Texture2D_2Lcom_wiyun_engine_types_WYRect_2
  (JNIEnv * env, jobject thiz, jobject fixture, jobject texture, jobject rect) {
	wyBox2DRender* render = (wyBox2DRender*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyTexture2D* t = texture == NULL ? NULL : (wyTexture2D*)env->GetIntField(texture, g_fid_BaseObject_mPointer);
	b2Fixture* f = (b2Fixture*)env->GetIntField(fixture, g_fid_BaseObject_mPointer);
	wyRect r = wyUtils_android::to_wyRect( rect);
	render->bindTexture(f, t, r);
}
