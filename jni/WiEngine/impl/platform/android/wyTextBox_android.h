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

#ifndef __wyTextBox_android_h__
#define __wyTextBox_android_h__

#if ANDROID

#include "wyTextBox.h"
#include <jni.h>

/**
 * @class wyTextBox_android
 *
 * \if English
 * Single line text edit for Android
 * \else
 * 特定于android平台的单行编辑器实现
 * \endif
 */
class wyTextBox_android : public wyTextBox {
	friend class wyTextBox;

private:
	/**
	 * \if English
	 * edit text callback, but it is defined in java layer so it is a java object
	 * \else
	 * 文本编辑框的java端回调对象
	 * \endif
	 */
	jobject m_jCallback;

protected:
	/**
	 * \if English
	 * Constructor
	 *
	 * @param normal normal state node, can not be NULL
	 * @param selected selected state node, can be NULL
	 * @param disabled disabled state node, can be NULL
	 * @param focused focused state node, can be NULL
	 * @param label label node used to display text, can be any label node such as \link wyLabel wyLabel\endlink,
	 * 		\link wyAtlasLabel wyAtlasLabel\endlink, \link wyBitmapFontLabel wyBitmapFontLabel\endlink
	 * \else
	 * 构造函数
	 *
	 * @param normal 正常状态的\link wyNode wyNode对象指针 \endlink, 不能为NULL
	 * @param selected 被选中状态的\link wyNode wyNode对象指针 \endlink，可以为NULL
	 * @param disabled 禁用状态的\link wyNode wyNode对象指针 \endlink，可以为NULL
	 * @param focused  获得焦点状态的\link wyNode wyNode对象指针 \endlink，可以为NULL
	 * @param label 文字标签节点，只要是WiEngine中支持的标签节点都可以，比如\link wyLabel wyLabel\endlink,
	 * 		\link wyAtlasLabel wyAtlasLabel\endlink, \link wyBitmapFontLabel wyBitmapFontLabel\endlink等
	 * \endif
	 */
	wyTextBox_android(wyNode* normal, wyNode* selected, wyNode* disabled, wyNode* focused, wyNode* label);

	/*
	 * callback trigger
	 */

	virtual void notifyOnTextChanged();
	virtual void notifyOnBeginEditing();
	virtual void notifyOnEndEditing();

	/// @see wyTextBox::showInputDialog
	virtual void showInputDialog();

public:
	virtual ~wyTextBox_android();

	/**
	 * \if English
	 * Set java layer callback
	 *
	 * @param jcallback java side callback object, NULL means clear current callback
	 * \else
	 * 设置文本框的java回调对象
	 *
	 * @param jcallback java回调函数对象, 如果为NULL，表示清除现有的callback
	 * \endif
	 */
	void setCallback(jobject jcallback);

	/**
	 * \if English
	 * Get java side callback object
	 *
	 * @return java side callback object
	 * \else
	 * 获得文本框java回调函数对象
	 *
	 * @return java回调函数对象
	 * \endif
	 */
	jobject getCallback();
};

#endif // #if ANDROID

#endif // __wyTextBox_android_h__
