#include "com_wiyun_engine_box2d_DebugDraw.h"
#include "wyBox2D.h"

extern jfieldID g_fid_BaseObject_mPointer;
extern jfieldID g_fid_WYPoint_x;
extern jfieldID g_fid_WYPoint_y;
extern jfieldID g_fid_WYColor3F_r;
extern jfieldID g_fid_WYColor3F_g;
extern jfieldID g_fid_WYColor3F_b;
extern jfieldID g_fid_Transform_q;
extern jfieldID g_fid_Transform_p;
extern jfieldID g_fid_Rotation_s;
extern jfieldID g_fid_Rotation_c;

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_DebugDraw_drawPolygon
  (JNIEnv * env, jobject thiz, jobjectArray vertices, jobject color) {
	b2Draw* dd = (b2Draw*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	float r = env->GetFloatField(color, g_fid_WYColor3F_r);
	float g = env->GetFloatField(color, g_fid_WYColor3F_g);
	float b = env->GetFloatField(color, g_fid_WYColor3F_b);
	jsize len = env->GetArrayLength(vertices);
	b2Vec2 v[len];
	for(int i = 0; i < len; i++) {
		jobject vert = env->GetObjectArrayElement(vertices, i);
		float x = env->GetFloatField(vert, g_fid_WYPoint_x);
		float y = env->GetFloatField(vert, g_fid_WYPoint_y);
		v[i] = b2Vec2(x, y);
		env->DeleteLocalRef(vert);
	}
	dd->DrawPolygon(v, len, b2Color(r, g, b));
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_DebugDraw_drawSolidPolygon
  (JNIEnv * env, jobject thiz, jobjectArray vertices, jobject color) {
	b2Draw* dd = (b2Draw*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	float r = env->GetFloatField(color, g_fid_WYColor3F_r);
	float g = env->GetFloatField(color, g_fid_WYColor3F_g);
	float b = env->GetFloatField(color, g_fid_WYColor3F_b);
	jsize len = env->GetArrayLength(vertices);
	b2Vec2 v[len];
	for(int i = 0; i < len; i++) {
		jobject vert = env->GetObjectArrayElement(vertices, i);
		float x = env->GetFloatField(vert, g_fid_WYPoint_x);
		float y = env->GetFloatField(vert, g_fid_WYPoint_y);
		v[i] = b2Vec2(x, y);
		env->DeleteLocalRef(vert);
	}
	dd->DrawSolidPolygon(v, len, b2Color(r, g, b));
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_DebugDraw_drawCircle
  (JNIEnv * env, jobject thiz, jobject center, jfloat radius, jobject color) {
	b2Draw* dd = (b2Draw*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	float r = env->GetFloatField(color, g_fid_WYColor3F_r);
	float g = env->GetFloatField(color, g_fid_WYColor3F_g);
	float b = env->GetFloatField(color, g_fid_WYColor3F_b);
	float x = env->GetFloatField(center, g_fid_WYPoint_x);
	float y = env->GetFloatField(center, g_fid_WYPoint_y);
	dd->DrawCircle(b2Vec2(x, y), radius, b2Color(r, g, b));
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_DebugDraw_drawSolidCircle
  (JNIEnv * env, jobject thiz, jobject center, jfloat radius, jobject axis, jobject color) {
	b2Draw* dd = (b2Draw*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	float r = env->GetFloatField(color, g_fid_WYColor3F_r);
	float g = env->GetFloatField(color, g_fid_WYColor3F_g);
	float b = env->GetFloatField(color, g_fid_WYColor3F_b);
	float x = env->GetFloatField(center, g_fid_WYPoint_x);
	float y = env->GetFloatField(center, g_fid_WYPoint_y);
	float ax = env->GetFloatField(axis, g_fid_WYPoint_x);
	float ay = env->GetFloatField(axis, g_fid_WYPoint_y);
	dd->DrawSolidCircle(b2Vec2(x, y), radius, b2Vec2(ax, ay), b2Color(r, g, b));
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_DebugDraw_drawSegment
  (JNIEnv * env, jobject thiz, jobject p1, jobject p2, jobject color) {
	b2Draw* dd = (b2Draw*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	float r = env->GetFloatField(color, g_fid_WYColor3F_r);
	float g = env->GetFloatField(color, g_fid_WYColor3F_g);
	float b = env->GetFloatField(color, g_fid_WYColor3F_b);
	float x1 = env->GetFloatField(p1, g_fid_WYPoint_x);
	float y1 = env->GetFloatField(p1, g_fid_WYPoint_y);
	float x2 = env->GetFloatField(p2, g_fid_WYPoint_x);
	float y2 = env->GetFloatField(p2, g_fid_WYPoint_y);
	dd->DrawSegment(b2Vec2(x1, y1), b2Vec2(x2, y2), b2Color(r, g, b));
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_DebugDraw_drawTransform
  (JNIEnv * env, jobject thiz, jobject transform) {
	b2Draw* dd = (b2Draw*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	b2Transform t;
	jobject q = env->GetObjectField(transform, g_fid_Transform_q);
	jobject p = env->GetObjectField(transform, g_fid_Transform_p);
	float x = env->GetFloatField(p, g_fid_WYPoint_x);
	float y = env->GetFloatField(p, g_fid_WYPoint_y);
	float s = env->GetFloatField(q, g_fid_Rotation_s);
	float c = env->GetFloatField(q, g_fid_Rotation_c);
	t.p = b2Vec2(x, y);
	t.q.s = s;
	t.q.c = c;
	env->DeleteLocalRef(q);
	env->DeleteLocalRef(p);
	dd->DrawTransform(t);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_box2d_DebugDraw_drawPoint
  (JNIEnv * env, jobject thiz, jobject p, jfloat size, jobject color) {
	b2Draw* dd = (b2Draw*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	float r = env->GetFloatField(color, g_fid_WYColor3F_r);
	float g = env->GetFloatField(color, g_fid_WYColor3F_g);
	float b = env->GetFloatField(color, g_fid_WYColor3F_b);
	float x = env->GetFloatField(p, g_fid_WYPoint_x);
	float y = env->GetFloatField(p, g_fid_WYPoint_y);
	dd->DrawPoint(b2Vec2(x, y), size, b2Color(r, g, b));
}
