#include "com_wiyun_engine_opengl_Primitives.h"
#include "wyPrimitives.h"
#include <stdlib.h>
#include "wyUtils_android.h"

extern jfieldID g_fid_WYPoint_x;
extern jfieldID g_fid_WYPoint_y;
extern jfieldID g_fid_WYSize_width;
extern jfieldID g_fid_WYSize_height;
extern jfieldID g_fid_WYRect_origin;
extern jfieldID g_fid_WYRect_size;
extern jfieldID g_fid_WYBezierConfig_cubic;
extern jfieldID g_fid_WYBezierConfig_startX;
extern jfieldID g_fid_WYBezierConfig_startY;
extern jfieldID g_fid_WYBezierConfig_endX;
extern jfieldID g_fid_WYBezierConfig_endY;
extern jfieldID g_fid_WYBezierConfig_cp1X;
extern jfieldID g_fid_WYBezierConfig_cp1Y;
extern jfieldID g_fid_WYBezierConfig_cp2X;
extern jfieldID g_fid_WYBezierConfig_cp2Y;
extern jfieldID g_fid_WYLagrangeConfig_cubic;
extern jfieldID g_fid_WYLagrangeConfig_startX;
extern jfieldID g_fid_WYLagrangeConfig_startY;
extern jfieldID g_fid_WYLagrangeConfig_endX;
extern jfieldID g_fid_WYLagrangeConfig_endY;
extern jfieldID g_fid_WYLagrangeConfig_cp1X;
extern jfieldID g_fid_WYLagrangeConfig_cp1Y;
extern jfieldID g_fid_WYLagrangeConfig_cp2X;
extern jfieldID g_fid_WYLagrangeConfig_cp2Y;
extern jfieldID g_fid_WYLagrangeConfig_t0;
extern jfieldID g_fid_WYLagrangeConfig_t1;
extern jfieldID g_fid_WYLagrangeConfig_t2;
extern jfieldID g_fid_WYLagrangeConfig_t3;

// WYHypotrochoidConfig class
extern jfieldID g_fid_WYHypotrochoidConfig_R;
extern jfieldID g_fid_WYHypotrochoidConfig_r;
extern jfieldID g_fid_WYHypotrochoidConfig_d;
extern jfieldID g_fid_WYHypotrochoidConfig_startAngle;
extern jfieldID g_fid_WYHypotrochoidConfig_endAngle;
extern jfieldID g_fid_WYHypotrochoidConfig_centreX;
extern jfieldID g_fid_WYHypotrochoidConfig_centreY;

JNIEXPORT void JNICALL Java_com_wiyun_engine_opengl_Primitives_drawPoint
  (JNIEnv * env, jclass clazz, jfloat x, jfloat y) {
	wyDrawPoint(x, y);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_opengl_Primitives_drawPoints___3Lcom_wiyun_engine_types_WYPoint_2
  (JNIEnv * env, jclass clazz, jobjectArray points) {
	// build buffer
	jsize len = env->GetArrayLength(points);
	float* p = (float*)wyMalloc(sizeof(float) * len * 2);
	for(int i = 0; i < len; i++) {
		jobject point = env->GetObjectArrayElement(points, i);
		p[i * 2] = env->GetFloatField(point, g_fid_WYPoint_x);
		p[i * 2 + 1] = env->GetFloatField(point, g_fid_WYPoint_y);
		env->DeleteLocalRef(point);
	}

	// draw
	wyDrawPoints(p, len * 2);

	// free
	wyFree(p);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_opengl_Primitives_drawPoints___3F
  (JNIEnv * env, jclass clazz, jfloatArray points) {
	jsize len = env->GetArrayLength(points);
	float* array = env->GetFloatArrayElements(points, NULL);
	wyDrawPoints(array, len);
	env->ReleaseFloatArrayElements(points, array, 0);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_opengl_Primitives_drawLine
  (JNIEnv * env, jclass clazz, jfloat x1, jfloat y1, jfloat x2, jfloat y2) {
	wyDrawLine(x1, y1, x2, y2);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_opengl_Primitives_drawDashLine
  (JNIEnv * env, jclass clazz, jfloat x1, jfloat y1, jfloat x2, jfloat y2, jfloat dashLength) {
	wyDrawDashLine(x1, y1, x2, y2, dashLength);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_opengl_Primitives_drawPath
  (JNIEnv * env, jclass clazz, jfloatArray points) {
	jsize len = env->GetArrayLength(points);
	float* array = env->GetFloatArrayElements(points, NULL);
	wyDrawPath(array, len);
	env->ReleaseFloatArrayElements(points, array, 0);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_opengl_Primitives_drawDashPath
  (JNIEnv * env, jclass clazz, jfloatArray points, jfloat dashLength) {
	jsize len = env->GetArrayLength(points);
	float* array = env->GetFloatArrayElements(points, NULL);
	wyDrawDashPath(array, len, dashLength);
	env->ReleaseFloatArrayElements(points, array, 0);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_opengl_Primitives_drawRect
  (JNIEnv * env, jclass clazz, jobject rect) {
	// get object fields
	jobject origin = env->GetObjectField(rect, g_fid_WYRect_origin);
	jobject size = env->GetObjectField(rect, g_fid_WYRect_size);
	float x = env->GetFloatField(origin, g_fid_WYPoint_x);
	float y = env->GetFloatField(origin, g_fid_WYPoint_y);
	float w = env->GetFloatField(size, g_fid_WYSize_width);
	float h = env->GetFloatField(size, g_fid_WYSize_height);
	env->DeleteLocalRef(origin);
	env->DeleteLocalRef(size);

	// build buffer
	float* p = (float*)wyMalloc(sizeof(float) * 4 * 2);
	p[0] = x;
	p[1] = y;
	p[2] = x + w;
	p[3] = y;
	p[4] = x + w;
	p[5] = y + h;
	p[6] = x;
	p[7] = y + h;

	// draw
	wyDrawRect(p);

	// free
	wyFree(p);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_opengl_Primitives_drawPoly
  (JNIEnv * env, jclass clazz, jobjectArray poli, jboolean closePolygon) {
	// build buffer
	jsize len = env->GetArrayLength(poli);
	float* p = (float*)wyMalloc(sizeof(float) * len * 2);
	for(int i = 0; i < len; i++) {
		jobject point = env->GetObjectArrayElement(poli, i);
		p[i * 2] = env->GetFloatField(point, g_fid_WYPoint_x);
		p[i * 2 + 1] = env->GetFloatField(point, g_fid_WYPoint_y);
		env->DeleteLocalRef(point);
	}

	// draw
	wyDrawPoly(p, len * 2, closePolygon);

	// free
	wyFree(p);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_opengl_Primitives_drawCircle
  (JNIEnv * env, jclass clazz, jfloat centerX, jfloat centerY, jfloat r, jfloat radiusLineAngle, jint segments, jboolean drawLineToCenter) {
	wyDrawCircle(centerX, centerY, r, radiusLineAngle, segments, drawLineToCenter);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_opengl_Primitives_drawSolidCircle
  (JNIEnv * env, jclass clazz, jfloat centerX, jfloat centerY, jfloat r, jint segments, jobject color) {
	wyDrawSolidCircle(centerX, centerY, r, segments, wyUtils_android::to_wyColor4B( color));
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_opengl_Primitives_drawBezier
  (JNIEnv * env, jclass clazz, jobject c, jint segments) {
	bool cubic = env->GetBooleanField(c, g_fid_WYBezierConfig_cubic);
	if(cubic) {
		wyBezierConfig config = wybcCubic(env->GetFloatField(c, g_fid_WYBezierConfig_startX),
				env->GetFloatField(c, g_fid_WYBezierConfig_startY),
				env->GetFloatField(c, g_fid_WYBezierConfig_endX),
				env->GetFloatField(c, g_fid_WYBezierConfig_endY),
				env->GetFloatField(c, g_fid_WYBezierConfig_cp1X),
				env->GetFloatField(c, g_fid_WYBezierConfig_cp1Y),
				env->GetFloatField(c, g_fid_WYBezierConfig_cp2X),
				env->GetFloatField(c, g_fid_WYBezierConfig_cp2Y));
		wyDrawBezier(config, segments);
	} else {
		wyBezierConfig config = wybcQuad(env->GetFloatField(c, g_fid_WYBezierConfig_startX),
				env->GetFloatField(c, g_fid_WYBezierConfig_startY),
				env->GetFloatField(c, g_fid_WYBezierConfig_endX),
				env->GetFloatField(c, g_fid_WYBezierConfig_endY),
				env->GetFloatField(c, g_fid_WYBezierConfig_cp1X),
				env->GetFloatField(c, g_fid_WYBezierConfig_cp1Y));
		wyDrawBezier(config, segments);
	}
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_opengl_Primitives_drawHypotrochoid
  (JNIEnv * env, jclass clazz, jobject c, jint segments) {
	wyHypotrochoidConfig config = wyhcQuad(env->GetFloatField(c, g_fid_WYHypotrochoidConfig_R),
			env->GetFloatField(c, g_fid_WYHypotrochoidConfig_r),
			env->GetFloatField(c, g_fid_WYHypotrochoidConfig_d),
			env->GetFloatField(c, g_fid_WYHypotrochoidConfig_startAngle),
			env->GetFloatField(c, g_fid_WYHypotrochoidConfig_endAngle),
			env->GetFloatField(c, g_fid_WYHypotrochoidConfig_centreX),
			env->GetFloatField(c, g_fid_WYHypotrochoidConfig_centreY));
	wyDrawHypotrochoid(config, segments);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_opengl_Primitives_drawLagrange
  (JNIEnv * env, jclass clazz, jobject c, jint segments) {
	bool cubic = env->GetBooleanField(c, g_fid_WYLagrangeConfig_cubic);
	if(cubic) {
		wyLagrangeConfig config = wylcCubic(env->GetFloatField(c, g_fid_WYLagrangeConfig_startX),
				env->GetFloatField(c, g_fid_WYLagrangeConfig_startY),
				env->GetFloatField(c, g_fid_WYLagrangeConfig_endX),
				env->GetFloatField(c, g_fid_WYLagrangeConfig_endY),
				env->GetFloatField(c, g_fid_WYLagrangeConfig_cp1X),
				env->GetFloatField(c, g_fid_WYLagrangeConfig_cp1Y),
				env->GetFloatField(c, g_fid_WYLagrangeConfig_cp2X),
				env->GetFloatField(c, g_fid_WYLagrangeConfig_cp2Y));
		config.t0 = env->GetFloatField(c, g_fid_WYLagrangeConfig_t0);
		config.t1 = env->GetFloatField(c, g_fid_WYLagrangeConfig_t1);
		config.t2 = env->GetFloatField(c, g_fid_WYLagrangeConfig_t2);
		config.t3 = env->GetFloatField(c, g_fid_WYLagrangeConfig_t3);
		wyDrawLagrange(config, segments);
	} else {
		wyLagrangeConfig config = wylcQuad(env->GetFloatField(c, g_fid_WYLagrangeConfig_startX),
				env->GetFloatField(c, g_fid_WYLagrangeConfig_startY),
				env->GetFloatField(c, g_fid_WYLagrangeConfig_endX),
				env->GetFloatField(c, g_fid_WYLagrangeConfig_endY),
				env->GetFloatField(c, g_fid_WYLagrangeConfig_cp1X),
				env->GetFloatField(c, g_fid_WYLagrangeConfig_cp1Y));
		config.t0 = env->GetFloatField(c, g_fid_WYLagrangeConfig_t0);
		config.t1 = env->GetFloatField(c, g_fid_WYLagrangeConfig_t1);
		config.t2 = env->GetFloatField(c, g_fid_WYLagrangeConfig_t2);
		config.t3 = env->GetFloatField(c, g_fid_WYLagrangeConfig_t3);
		wyDrawLagrange(config, segments);
	}
}


JNIEXPORT void JNICALL Java_com_wiyun_engine_opengl_Primitives_drawSolidRect
  (JNIEnv * env, jclass clazz, jobject rect, jobject color) {
	// get object fields
	jobject origin = env->GetObjectField(rect, g_fid_WYRect_origin);
	jobject size = env->GetObjectField(rect, g_fid_WYRect_size);
	float x = env->GetFloatField(origin, g_fid_WYPoint_x);
	float y = env->GetFloatField(origin, g_fid_WYPoint_y);
	float w = env->GetFloatField(size, g_fid_WYSize_width);
	float h = env->GetFloatField(size, g_fid_WYSize_height);
	env->DeleteLocalRef(origin);
	env->DeleteLocalRef(size);

	// build buffer
	float* p = (float*)wyMalloc(sizeof(float) * 4 * 2);
	p[0] = x;
	p[1] = y;
	p[2] = x + w;
	p[3] = y;
	p[4] = x + w;
	p[5] = y + h;
	p[6] = x;
	p[7] = y + h;

	wyColor4B c = wyUtils_android::to_wyColor4B( color);

	// draw
	wyDrawSolidRect(p, c);

	// free
	wyFree(p);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_opengl_Primitives_drawSolidPoly
  (JNIEnv * env, jclass clazz, jobjectArray poli, jobject color) {
	// build buffer
	jsize len = env->GetArrayLength(poli);
	float* p = (float*)wyMalloc(sizeof(float) * len * 2);
	for(int i = 0; i < len; i++) {
		jobject point = env->GetObjectArrayElement(poli, i);
		p[i * 2] = env->GetFloatField(point, g_fid_WYPoint_x);
		p[i * 2 + 1] = env->GetFloatField(point, g_fid_WYPoint_y);
		env->DeleteLocalRef(point);
	}

	wyColor4B c = wyUtils_android::to_wyColor4B( color);

	// draw
	wyDrawSolidPoly(p, len * 2, c);

	// free
	wyFree(p);
}
