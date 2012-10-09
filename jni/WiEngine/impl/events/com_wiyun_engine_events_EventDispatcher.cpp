/*
 * Copyright (c) 2010 WiYun Inc.
 * Author: luma(stubma@gmail.com)
 *
 * For all entities this program is free software; you can redistribute
 * it and/or modify it under the terms of the 'WiEngine' license with
 * the additional provision that 'WiEngine' must be credited in a manner
 * that can be be observed by end users, for example, in the credits or during
 * start up. (please find WiEngine logo in sdk's logo folder)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
#if ANDROID

#include "com_wiyun_engine_events_EventDispatcher.h"
#include "wyNode.h"
#include "wyEventDispatcher_android.h"
#include "wyUtils_android.h"

extern jfieldID g_fid_BaseObject_mPointer;
extern wyEventDispatcher_android* gEventDispatcher;

JNIEXPORT jint JNICALL Java_com_wiyun_engine_events_EventDispatcher_nativeGetInstance
  (JNIEnv * env, jclass clazz) {
	return (jint)gEventDispatcher;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_events_EventDispatcher_nativeInit
  (JNIEnv * env, jobject thiz) {
	wyEventDispatcher* ed = wyEventDispatcher::getInstance();
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)ed);
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_events_EventDispatcher_getDispatchEvents
  (JNIEnv * env, jobject thiz) {
	wyEventDispatcher* ed = (wyEventDispatcher*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return ed->getDispatchEvent();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_events_EventDispatcher_setDispatchEvents
  (JNIEnv * env, jobject thiz, jboolean flag) {
	wyEventDispatcher* ed = (wyEventDispatcher*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	ed->setDispatchEvent(flag);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_events_EventDispatcher_addDoubleTapHandler
  (JNIEnv * env, jobject thiz, jobject handler, jint priority) {
	wyNode* node = (wyNode*)env->GetIntField(handler, g_fid_BaseObject_mPointer);
	wyEventDispatcher* ed = (wyEventDispatcher*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	ed->addDoubleTapHandlerLocked(node, priority);
	node->setJavaDoubleTapHandler(handler);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_events_EventDispatcher_addGestureHandler
  (JNIEnv * env, jobject thiz, jobject handler, jint priority) {
	wyNode* node = (wyNode*)env->GetIntField(handler, g_fid_BaseObject_mPointer);
	wyEventDispatcher* ed = (wyEventDispatcher*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	ed->addGestureHandlerLocked(node, priority);
	node->setJavaGestureHandler(handler);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_events_EventDispatcher_addTouchHandler
  (JNIEnv * env, jobject thiz, jobject handler, jint priority) {
	wyNode* node = (wyNode*)env->GetIntField(handler, g_fid_BaseObject_mPointer);
	wyEventDispatcher* ed = (wyEventDispatcher*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	ed->addTouchHandlerLocked(node, priority);
	node->setJavaTouchHandler(handler);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_events_EventDispatcher_addKeyHandler
  (JNIEnv * env, jobject thiz, jobject handler, jint priority) {
	wyNode* node = (wyNode*)env->GetIntField(handler, g_fid_BaseObject_mPointer);
	wyEventDispatcher* ed = (wyEventDispatcher*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	ed->addKeyHandlerLocked(node, priority);
	node->setJavaKeyHandler(handler);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_events_EventDispatcher_addAccelHandler
  (JNIEnv * env, jobject thiz, jobject handler, jint priority) {
	wyNode* node = (wyNode*)env->GetIntField(handler, g_fid_BaseObject_mPointer);
	wyEventDispatcher* ed = (wyEventDispatcher*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	ed->addAccelHandlerLocked(node, priority);
	node->setJavaAccelHandler(handler);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_events_EventDispatcher_removeDoubleTapHandler
  (JNIEnv * env, jobject thiz, jobject handler) {
	wyNode* node = (wyNode*)env->GetIntField(handler, g_fid_BaseObject_mPointer);
	wyEventDispatcher* ed = (wyEventDispatcher*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	ed->removeDoubleTapHandlerLocked(node);
	node->setJavaDoubleTapHandler(NULL);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_events_EventDispatcher_removeGestureHandler
  (JNIEnv * env, jobject thiz, jobject handler) {
	wyNode* node = (wyNode*)env->GetIntField(handler, g_fid_BaseObject_mPointer);
	wyEventDispatcher* ed = (wyEventDispatcher*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	ed->removeGestureHandlerLocked(node);
	node->setJavaGestureHandler(NULL);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_events_EventDispatcher_removeTouchHandler
  (JNIEnv * env, jobject thiz, jobject handler) {
	wyNode* node = (wyNode*)env->GetIntField(handler, g_fid_BaseObject_mPointer);
	wyEventDispatcher* ed = (wyEventDispatcher*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	ed->removeTouchHandlerLocked(node);
	node->setJavaTouchHandler(NULL);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_events_EventDispatcher_removeKeyHandler
  (JNIEnv * env, jobject thiz, jobject handler) {
	wyNode* node = (wyNode*)env->GetIntField(handler, g_fid_BaseObject_mPointer);
	wyEventDispatcher* ed = (wyEventDispatcher*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	ed->removeKeyHandlerLocked(node);
	node->setJavaKeyHandler(NULL);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_events_EventDispatcher_removeAccelHandler
  (JNIEnv * env, jobject thiz, jobject handler) {
	wyNode* node = (wyNode*)env->GetIntField(handler, g_fid_BaseObject_mPointer);
	wyEventDispatcher* ed = (wyEventDispatcher*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	ed->removeAccelHandlerLocked(node);
	node->setJavaAccelHandler(NULL);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_events_EventDispatcher_removeAllHandlers
  (JNIEnv * env, jobject thiz) {
	wyEventDispatcher* ed = (wyEventDispatcher*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	ed->removeAllHandlersLocked();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_events_EventDispatcher_setDoubleTapPriority
  (JNIEnv * env, jobject thiz, jobject handler, jint priority) {
	wyNode* node = (wyNode*)env->GetIntField(handler, g_fid_BaseObject_mPointer);
	wyEventDispatcher* ed = (wyEventDispatcher*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	ed->setDoubleTapHandlerPriorityLocked(node, priority);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_events_EventDispatcher_setGesturePriority
  (JNIEnv * env, jobject thiz, jobject handler, jint priority) {
	wyNode* node = (wyNode*)env->GetIntField(handler, g_fid_BaseObject_mPointer);
	wyEventDispatcher* ed = (wyEventDispatcher*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	ed->setGestureHandlerPriorityLocked(node, priority);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_events_EventDispatcher_setTouchPriority
  (JNIEnv * env, jobject thiz, jobject handler, jint priority) {
	wyNode* node = (wyNode*)env->GetIntField(handler, g_fid_BaseObject_mPointer);
	wyEventDispatcher* ed = (wyEventDispatcher*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	ed->setTouchHandlerPriorityLocked(node, priority);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_events_EventDispatcher_setKeyPriority
  (JNIEnv * env, jobject thiz, jobject handler, jint priority) {
	wyNode* node = (wyNode*)env->GetIntField(handler, g_fid_BaseObject_mPointer);
	wyEventDispatcher* ed = (wyEventDispatcher*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	ed->setKeyHandlerPriorityLocked(node, priority);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_events_EventDispatcher_setAccelerometerPriority
  (JNIEnv * env, jobject thiz, jobject handler, jint priority) {
	wyNode* node = (wyNode*)env->GetIntField(handler, g_fid_BaseObject_mPointer);
	wyEventDispatcher* ed = (wyEventDispatcher*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	ed->setAccelHandlerPriorityLocked(node, priority);
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_events_EventDispatcher_keyDown
  (JNIEnv * env, jobject thiz, jobject event) {
	if(gEventDispatcher != NULL)
		gEventDispatcher->queueKeyEventLocked(ET_KEY_DOWN, event);
	return true;
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_events_EventDispatcher_keyUp
  (JNIEnv * env, jobject thiz, jobject event) {
	if(gEventDispatcher != NULL)
		gEventDispatcher->queueKeyEventLocked(ET_KEY_UP, event);
	return true;
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_events_EventDispatcher_keyMultiple
  (JNIEnv * env, jobject thiz, jobject event) {
	if(gEventDispatcher != NULL)
		gEventDispatcher->queueKeyEventLocked(ET_KEY_MULTIPLE, event);
	return true;
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_events_EventDispatcher_touchesBegan
  (JNIEnv * env, jobject thiz, jobject event) {
	if(gEventDispatcher != NULL)
		gEventDispatcher->queueEventLocked(ET_TOUCH_BEGAN, event);
	return true;
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_events_EventDispatcher_touchesMoved
  (JNIEnv * env, jobject thiz, jobject event) {
	if(gEventDispatcher != NULL)
		gEventDispatcher->queueEventLocked(ET_TOUCH_MOVED, event);
	return true;
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_events_EventDispatcher_touchesEnded
  (JNIEnv * env, jobject thiz, jobject event) {
	if(gEventDispatcher != NULL)
		gEventDispatcher->queueEventLocked(ET_TOUCH_ENDED, event);
	return true;
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_events_EventDispatcher_touchesPointerBegan
  (JNIEnv * env, jobject thiz, jobject event) {
	if(gEventDispatcher != NULL)
		gEventDispatcher->queueEventLocked(ET_TOUCH_POINTER_BEGAN, event);
	return true;
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_events_EventDispatcher_touchesPointerEnded
  (JNIEnv * env, jobject thiz, jobject event) {
	if(gEventDispatcher != NULL)
		gEventDispatcher->queueEventLocked(ET_TOUCH_POINTER_END, event);
	return true;
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_events_EventDispatcher_touchesCancelled
  (JNIEnv * env, jobject thiz, jobject event) {
	if(gEventDispatcher != NULL)
		gEventDispatcher->queueEventLocked(ET_TOUCH_CANCELLED, event);
	return true;
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_events_EventDispatcher_onDoubleTap
  (JNIEnv * env, jobject thiz, jobject event) {
	if(gEventDispatcher != NULL)
		gEventDispatcher->queueEventLocked(ET_DOUBLE_TAP, event);
	return true;
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_events_EventDispatcher_onDoubleTapEvent
  (JNIEnv * env, jobject thiz, jobject event) {
	if(gEventDispatcher != NULL)
		gEventDispatcher->queueEventLocked(ET_DOUBLE_TAP_EVENT, event);
	return true;
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_events_EventDispatcher_onSingleTapConfirmed
  (JNIEnv * env, jobject thiz, jobject event) {
	if(gEventDispatcher != NULL)
		gEventDispatcher->queueEventLocked(ET_SINGLE_TAP_CONFIRMED, event);
	return true;
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_events_EventDispatcher_onDown
  (JNIEnv * env, jobject thiz, jobject event) {
	if(gEventDispatcher != NULL)
		gEventDispatcher->queueEventLocked(ET_ON_DOWN, event, NULL, 0, 0);
	return true;
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_events_EventDispatcher_onFling
  (JNIEnv * env, jobject thiz, jobject e1, jobject e2, jfloat velocityX, jfloat velocityY) {
	if(gEventDispatcher != NULL)
		gEventDispatcher->queueEventLocked(ET_ON_FLING, e1, e2, velocityX, velocityY);
	return true;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_events_EventDispatcher_onLongPress
  (JNIEnv * env, jobject thiz, jobject event) {
	if(gEventDispatcher != NULL)
		gEventDispatcher->queueEventLocked(ET_ON_LONG_PRESS, event, NULL, 0, 0);
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_events_EventDispatcher_onScroll
  (JNIEnv * env, jobject thiz, jobject e1, jobject e2, jfloat distanceX, jfloat distanceY) {
	if(gEventDispatcher != NULL)
		gEventDispatcher->queueEventLocked(ET_ON_SCROLL, e1, e2, distanceX, distanceY);
	return true;
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_events_EventDispatcher_onShowPress
  (JNIEnv * env, jobject thiz, jobject event) {
	if(gEventDispatcher != NULL)
		gEventDispatcher->queueEventLocked(ET_ON_SHOW_PRESS, event, NULL, 0, 0);
}

JNIEXPORT jboolean JNICALL Java_com_wiyun_engine_events_EventDispatcher_onSingleTapUp
  (JNIEnv * env, jobject thiz, jobject event) {
	if(gEventDispatcher != NULL)
		gEventDispatcher->queueEventLocked(ET_ON_SINGLE_TAP_UP, event, NULL, 0, 0);
	return true;
}

#endif // #if ANDROID
