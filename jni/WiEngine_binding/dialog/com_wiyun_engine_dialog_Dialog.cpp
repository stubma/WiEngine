#include "com_wiyun_engine_dialog_Dialog.h"
#include "wyDialog.h"

extern jfieldID g_fid_BaseObject_mPointer;

JNIEXPORT void JNICALL Java_com_wiyun_engine_dialog_Dialog_nativeInit
  (JNIEnv * env, jobject thiz) {
	wyDialog* d = wyDialog::make();
	env->SetIntField(thiz, g_fid_BaseObject_mPointer, (jint)d);
	d->retain();
	d->lazyRelease();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_dialog_Dialog_nativeCreate
  (JNIEnv * env, jobject thiz) {
	wyDialog* d = (wyDialog*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	d->create();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_dialog_Dialog_nativeShow
  (JNIEnv * env, jobject thiz, jboolean withAnimation) {
	wyDialog* d = (wyDialog*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	d->show(withAnimation);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_dialog_Dialog_dismiss
  (JNIEnv * env, jobject thiz, jboolean withAnimation) {
	wyDialog* d = (wyDialog*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	d->dismiss(withAnimation);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_dialog_Dialog_nativeSetBackground
  (JNIEnv * env, jobject thiz, jobject bg) {
	wyDialog* d = (wyDialog*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyNode* bgNode = (wyNode*)env->GetIntField(bg, g_fid_BaseObject_mPointer);
	d->setBackground(bgNode);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_dialog_Dialog_getBackground
  (JNIEnv * env, jobject thiz) {
	wyDialog* d = (wyDialog*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	return (jint)d->getBackground();
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_dialog_Dialog_nativeSetBackgroundPadding
  (JNIEnv * env, jobject thiz, jfloat left, jfloat top, jfloat right, jfloat bottom) {
	wyDialog* d = (wyDialog*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	d->setBackgroundPadding(left, top, right, bottom);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_dialog_Dialog_nativeSetTitle
  (JNIEnv * env, jobject thiz, jobject title) {
	wyDialog* d = (wyDialog*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyNode* t = (wyNode*)env->GetIntField(title, g_fid_BaseObject_mPointer);
	d->setTitle(t);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_dialog_Dialog_nativeSetContent
  (JNIEnv * env, jobject thiz, jobject content) {
	wyDialog* d = (wyDialog*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyNode* c = (wyNode*)env->GetIntField(content, g_fid_BaseObject_mPointer);
	d->setContent(c);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_dialog_Dialog_nativeAddButton
  (JNIEnv * env, jobject thiz, jobject button, jobject label, jobject sel) {
	wyDialog* d = (wyDialog*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyNode* b = (wyNode*)env->GetIntField(button, g_fid_BaseObject_mPointer);
	wyNode* l = label == NULL ? NULL : (wyNode*)env->GetIntField(label, g_fid_BaseObject_mPointer);
	wyTargetSelector* s = sel == NULL ? NULL : wyTargetSelector::make(sel);
	d->addButton(b, l, s);
}

JNIEXPORT jint JNICALL Java_com_wiyun_engine_dialog_Dialog_nativeAddTwoColumnsButton
  (JNIEnv * env, jobject thiz, jobject button1, jobject label1, jobject sel1, jobject button2, jobject label2, jobject sel2) {
	wyDialog* d = (wyDialog*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyNode* b1 = (wyNode*)env->GetIntField(button1, g_fid_BaseObject_mPointer);
	wyNode* l1 = (wyNode*)env->GetIntField(label1, g_fid_BaseObject_mPointer);
	wyTargetSelector* s1 = sel1 == NULL ? NULL : wyTargetSelector::make(sel1);
	wyNode* b2 = (wyNode*)env->GetIntField(button2, g_fid_BaseObject_mPointer);
	wyNode* l2 = (wyNode*)env->GetIntField(label2, g_fid_BaseObject_mPointer);
	wyTargetSelector* s2 = sel2 == NULL ? NULL : wyTargetSelector::make(sel2);
	d->addTwoColumnsButton(b1, l1, s1, b2, l2, s2);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_dialog_Dialog_nativeSetTransition
  (JNIEnv * env, jobject thiz, jobject t) {
	wyDialog* d = (wyDialog*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	wyDialogTransition* trans = (wyDialogTransition*)env->GetIntField(t, g_fid_BaseObject_mPointer);
	d->setTransition(trans);
}

JNIEXPORT void JNICALL Java_com_wiyun_engine_dialog_Dialog_nativeSetBackKeyEquivalentButtonIndex
  (JNIEnv * env, jobject thiz, jint index) {
	wyDialog* d = (wyDialog*)env->GetIntField(thiz, g_fid_BaseObject_mPointer);
	d->setBackKeyEquivalentButtonIndex(index);
}
