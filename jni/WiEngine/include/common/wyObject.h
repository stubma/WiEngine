/*
 * Copyright (c) 2010 WiYun Inc.

 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:

 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.

 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
#ifndef __wyObject_h__
#define __wyObject_h__

#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include "wyArray.h"
#include "wyMemory.h"
#include "wyGlobal.h"
#include "wyDevice.h"
#if ANDROID
	#include <jni.h>
#endif

class wyTargetSelector;

/**
 * @class wyObject
 *
 * 大部分类的基类，封装了引用计数的逻辑和IAnimation接口方法
 */
class WIENGINE_API wyObject {
protected:
	/// retain count of object, if zero, it will be destroyed
	int m_retainCount;

	/// object name, optional
	const char* m_name;

#if ANDROID
	/**
	 * java端的targetselector事件回调, 用来把native端的target selector事件
	 * 推送到java端. 目前主要是为了让lua脚本中创建的targetselector可以回调
	 * 到java端.
	 */
	jobject m_jTSConnector;
#endif

public:
	/**
	 * 构造函数
	 */
	wyObject();

	/**
	 * 虚析构
	 */
	virtual ~wyObject();

	/**
	 * 得到类名的字符串表示
	 *
	 * @return 类型字符串指针, 调用者不需要释放该指针
	 */
	const char* getClassName();

	/**
	 * 使对象的引用计数加1
	 *
	 * @return 当前对象指针
	 */
	wyObject* retain();

	/**
	 * 使对象的引用计数立刻减1，如果对象的引用计数在调用之前为1，会导致
	 * 对象立刻被销毁
	 */
	void release();

	/**
	 * 在渲染下一帧时将对象的引用计数减1，这个方法在主线程中调用也是安全的，底层
	 * 会自动进行处理以避免OpenGL线程提前释放对象
	 *
	 * @return 当前对象指针
	 */
	wyObject* autoRelease();

	/**
	 * 直到Director退出时才将对象引用计数减1，该方法主要为Java层设计，在native
	 * 层应避免使用该方法
	 *
	 * @return 当前对象指针
	 */
	wyObject* lazyRelease();

	/**
	 * 在lazy release pool中查找某个对象, 如果找到了, 则从lazy release
	 * pool中删除并减少引用计数. 这个方法主要的目的是方便java层能够释放native层
	 * 对象, 开发者在任何时候都不需要手动调用此方法.
	 */
	void javaRelease();

	/**
	 * 获得对象的当前引用计数
	 *
	 * @return 当前引用计数
	 */
	int getRetainCount();

	/**
	 * 如果有一个TargetSelector绑定在当前对象上并被触发，则对象的该方法
	 * 将被调用。在这个方法里可以判断是哪个TargetSelector被触发并进行相应
	 * 处理
	 *
	 * \note
	 * 这个方法目前已经不推荐直接使用, 当前它存在的意义只是为了能够在Lua脚本中
	 * 创建选择子. 如果是在C++中使用, 建议使用SEL开头的宏构造选择子.
	 *
	 * @param ts \link wyTargetSelector wyTargetSelector\endlink
	 */
	virtual void onTargetSelectorInvoked(wyTargetSelector* ts);

	/**
	 * 设置对象名
	 */
	virtual void setName(const char* name);

	/**
	 * 获得对象名
	 */
	virtual const char* getName() { return m_name; }

#if ANDROID
	/**
	 * 设置java端的target selector事件处理对象
	 *
	 * @param c java端的target selector事件处理对象
	 */
	void setJavaTSConnector(jobject c);
#endif // #if ANDROID
};

#ifdef __cplusplus
extern "C" {
#endif

/**
 * 增加对象的引用计数，这个方法会检查空指针
 *
 * @param obj 需要增加计数的对象，为NULL则无效果
 * @return 传入的对象指针
 */
WIENGINE_API wyObject* wyObjectRetain(wyObject* obj);

/**
 * 在渲染下一帧时将对象的引用计数减1，这个方法在主线程中调用也是安全的，底层
 * 会自动进行处理以避免OpenGL线程提前释放对象。这个方法会检查空指针
 *
 * @param obj 需要增加计数的对象，为NULL则无效果
 * @return 传入的对象指针
 */
WIENGINE_API wyObject* wyObjectAutoRelease(wyObject* obj);

/**
 * 直到Director退出时才将对象引用计数减1，该方法主要为Java层设计，在native
 * 层应避免使用该方法。这个方法会检查空指针
 *
 * @param obj 需要增加计数的对象，为NULL则无效果
 * @return 传入的对象指针
 */
WIENGINE_API wyObject* wyObjectLazyRelease(wyObject* obj);

/**
 * 使对象的引用计数立刻减1，如果对象的引用计数在调用之前为1，会导致
 * 对象立刻被销毁。这个方法会检查空指针
 *
 * @param obj 需要减少计数的对象，为NULL则无效果
 */
WIENGINE_API void wyObjectRelease(wyObject* obj);

#ifdef __cplusplus
}
#endif

#endif // __wyObject_h__
