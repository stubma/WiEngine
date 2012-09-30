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
#ifndef __wyTargetSelector_h__
#define __wyTargetSelector_h__

#include "wyObject.h"
#include <stdbool.h>
#if ANDROID
	#include <jni.h>
#endif

class wyTargetSelector;

/*
 * equals function of target selector
 */

#ifdef __cplusplus
extern "C" {
#endif

WIENGINE_API bool wyTargetSelectorEquals(wyTargetSelector* ts1, wyTargetSelector* ts2);

#ifdef __cplusplus
}
#endif

// Selector method defined
typedef void (wyObject::*wySEL)(wyTargetSelector* ts);
typedef void (wyObject::*wySEL_i)(wyTargetSelector* ts, int);
typedef void (wyObject::*wySEL_f)(wyTargetSelector* ts, float);
typedef void (wyObject::*wySEL_p)(wyTargetSelector* ts, void*);

/*
 * macro used to get selector function pointer, the name describe argument sequence
 * of function, for example, SEL_p means the function has a void* argument. But remember,
 * first argument of callback function must be wyTargetSelector object pointer
 */
#define SEL(f) (wySEL)(&f)
#define SEL_i(f) (wySEL_i)(&f)
#define SEL_f(f) (wySEL_f)(&f)
#define SEL_p(f) (wySEL_p)(&f)

/**
 * @class wyTargetSelector
 *
 * \if English
 * it indicates a callback
 * \else
 * 定时器回调的封装
 * \endif
 */
class WIENGINE_API wyTargetSelector : public wyObject {
private:
	/// callback function prototype
	enum Prototype {
		/// no argument
		NONE,

		/// one int argument
		INT,

		/// one float argument
		FLOAT,

		/// one void* argument
		PVOID
	};

	/// selector
	union Selector {
		wySEL sel;
		wySEL_i sel_i;
		wySEL_f sel_f;
		wySEL_p sel_p;
	};

public:
	/**
	 * @union ArgValue
	 *
	 * \if English
	 * Data set for this target selector
	 * \else
	 * 设置给回调方法的参数
	 * \endif
	 */
	union ArgValue {
		/**
		 * \if English
		 * Integer value
		 * \else
		 * 整数值
		 * \endif
		 */
		int i;

		/**
		 * \if English
		 * Float value
		 * \else
		 * 浮点值
		 * \endif
		 */
		float f;

		/**
		 * \if English
		 * pointer
		 * \else
		 * 指针
		 * \endif
		 */
		void* p;
	};

private:
	/**
	 * \if English
	 * callback target, must be a wyObject subclass
	 * \else
	 * native层回调的\link wyObject wyObject对象指针\endlink
	 * \endif
	 */
	wyObject* m_target;

	/**
	 * \if English
	 * id of this target selector
	 * \else
	 * 标识id
	 * \endif
	 */
	int m_id;

	/**
	 * \if English
	 * the time between last calling and now
	 * \else
	 * 标识距离上次触发所持续的时间，例如如果按三帧刷新一次，则累计三帧消耗的时间
	 * \endif
	 */
	float m_delta;

	/// callback prototype
	Prototype m_prototype;

	/**
	 * \if English
	 * argument of callback
	 * \else
	 * native层回调的参数
	 * \endif
	 */
	ArgValue m_data;

	/**
	 * \if English
	 * callback function of a class
	 * \else
	 * 自定义函数回调
	 * \endif
	 */
	Selector m_sel;

#if ANDROID
	/**
	 * \if English
	 * callback object in java side
	 * \else
	 * java层回调对象
	 * \endif
	 */
	jobject m_jTarget;
#endif

protected:
	/**
	 * constructor
	 *
	 * @param callback native层回调的\link wyObject wyObject对象指针\endlink
	 * @param id 标识id
	 * @param data 额外数据
	 */
	wyTargetSelector(wyObject* callback, int id, ArgValue data);

	/**
	 * constructor
	 *
	 * @param target object of callback function
	 * @param sel pointer to callback function
	 */
	wyTargetSelector(wyObject* target, wySEL sel);

	/**
	 * constructor
	 *
	 * @param target object of callback function
	 * @param sel pointer to callback function
	 * @param data integer data passed to callback function
	 */
	wyTargetSelector(wyObject* target, wySEL_i sel, int data);

	/**
	 * constructor
	 *
	 * @param target object of callback function
	 * @param sel pointer to callback function
	 * @param data float data passed to callback function
	 */
	wyTargetSelector(wyObject* target, wySEL_f sel, float data);

	/**
	 * constructor
	 *
	 * @param target object of callback function
	 * @param sel pointer to callback function
	 * @param data void pointer passed to callback function
	 */
	wyTargetSelector(wyObject* target, wySEL_p sel, void* data);

#if ANDROID
	/**
	 * \if English
	 * constructor
	 *
	 * @param target java layer callback
	 * \else
	 * 构造函数
	 *
	 * @param target java层回调对象
	 * \endif
	 */
	wyTargetSelector(jobject target);
#endif

public:
	/**
	 * \if English
	 * static constructor
	 *
	 * \note
	 * This method still can be used but not recommended, actually it is only designed
	 * for Lua script. Because it is difficult to use function pointer in Lua, so invoking
	 * target selector by an id is still needed
	 *
	 * @param callback callback target, must be a wyObject subclass
	 * @param id id of this target selector
	 * @return \link wyTargetSelector wyTargetSelector\endlink
	 * \else
	 * 静态构造函数
	 *
	 * \note
	 * 这个方法虽然可以使用但是不再推荐. 实际上这个方法是为了Lua脚本而继续存在的, 由于Lua脚本中
	 * 传递函数指针比较麻烦, 所以通过id调用一个选择子仍然有存在的必要.
	 *
	 * @param callback native层回调的\link wyObject wyObject对象指针\endlink
	 * @param id 标识id
	 * @return \link wyTargetSelector wyTargetSelector\endlink
	 * \endif
	 */
	static wyTargetSelector* makeId(wyObject* callback, int id);

	/**
	 * \if English
	 * static constructor
	 *
	 * \note
	 * This method still can be used but not recommended, actually it is only designed
	 * for Lua script. Because it is difficult to use function pointer in Lua, so invoking
	 * target selector by an id is still needed
	 *
	 * @param callback callback target, must be a wyObject subclass
	 * @param id id of this target selector
	 * @param data integer custom data
	 * @return \link wyTargetSelector wyTargetSelector\endlink
	 * \else
	 * 静态构造函数
	 *
	 * \note
	 * 这个方法虽然可以使用但是不再推荐. 实际上这个方法是为了Lua脚本而继续存在的, 由于Lua脚本中
	 * 传递函数指针比较麻烦, 所以通过id调用一个选择子仍然有存在的必要.
	 *
	 * @param callback native层回调的\link wyObject wyObject对象指针\endlink
	 * @param id 标识id
	 * @param data 整数类型的参数
	 * @return \link wyTargetSelector wyTargetSelector\endlink
	 * \endif
	 */
	static wyTargetSelector* makeId(wyObject* callback, int id, int data);

	/**
	 * \if English
	 * static constructor
	 *
	 * \note
	 * This method still can be used but not recommended, actually it is only designed
	 * for Lua script. Because it is difficult to use function pointer in Lua, so invoking
	 * target selector by an id is still needed
	 *
	 * @param callback callback target, must be a wyObject subclass
	 * @param id id of this target selector
	 * @param data float custom data
	 * @return \link wyTargetSelector wyTargetSelector\endlink
	 * \else
	 * 静态构造函数
	 *
	 * \note
	 * 这个方法虽然可以使用但是不再推荐. 实际上这个方法是为了Lua脚本而继续存在的, 由于Lua脚本中
	 * 传递函数指针比较麻烦, 所以通过id调用一个选择子仍然有存在的必要.
	 *
	 * @param callback native层回调的\link wyObject wyObject对象指针\endlink
	 * @param id 标识id
	 * @param data 浮点类型的参数
	 * @return \link wyTargetSelector wyTargetSelector\endlink
	 * \endif
	 */
	static wyTargetSelector* makeId(wyObject* callback, int id, float data);

	/**
	 * \if English
	 * static constructor
	 *
	 * \note
	 * This method still can be used but not recommended, actually it is only designed
	 * for Lua script. Because it is difficult to use function pointer in Lua, so invoking
	 * target selector by an id is still needed
	 *
	 * @param callback callback target, must be a wyObject subclass
	 * @param id id of this target selector
	 * @param data pointer custom data
	 * @return \link wyTargetSelector wyTargetSelector\endlink
	 * \else
	 * 静态构造函数
	 *
	 * \note
	 * 这个方法虽然可以使用但是不再推荐. 实际上这个方法是为了Lua脚本而继续存在的, 由于Lua脚本中
	 * 传递函数指针比较麻烦, 所以通过id调用一个选择子仍然有存在的必要.
	 *
	 * @param callback native层回调的\link wyObject wyObject对象指针\endlink
	 * @param id 标识id
	 * @param data 指针类型的参数
	 * @return \link wyTargetSelector wyTargetSelector\endlink
	 * \endif
	 */
	static wyTargetSelector* makeId(wyObject* callback, int id, void* data);

	/**
	 * \if English
	 * static constructor
	 *
	 * @param target object of callback function
	 * @param sel pointer to callback function
	 * @return \link wyTargetSelector wyTargetSelector\endlink
	 * \else
	 * 静态构造函数
	 *
	 * @param target 回调函数所在的类实例
	 * @param sel 指向回调函数的指针
	 * @return \link wyTargetSelector wyTargetSelector\endlink
	 * \endif
	 */
	static wyTargetSelector* make(wyObject* target, wySEL sel);

	/**
	 * \if English
	 * static constructor
	 *
	 * @param target object of callback function
	 * @param sel pointer to callback function
	 * @param data integer argument for callback function
	 * @return \link wyTargetSelector wyTargetSelector\endlink
	 * \else
	 * 静态构造函数
	 *
	 * @param target 回调函数所在的类实例
	 * @param sel 指向回调函数的指针
	 * @param data 传递给回调函数的整数参数
	 * @return \link wyTargetSelector wyTargetSelector\endlink
	 * \endif
	 */
	static wyTargetSelector* make(wyObject* target, wySEL_i sel, int data);

	/**
	 * \if English
	 * static constructor
	 *
	 * @param target object of callback function
	 * @param sel pointer to callback function
	 * @param data float argument for callback function
	 * @return \link wyTargetSelector wyTargetSelector\endlink
	 * \else
	 * 静态构造函数
	 *
	 * @param target 回调函数所在的类实例
	 * @param sel 指向回调函数的指针
	 * @param data 传递给回调函数的浮点参数
	 * @return \link wyTargetSelector wyTargetSelector\endlink
	 * \endif
	 */
	static wyTargetSelector* make(wyObject* target, wySEL_f sel, float data);

	/**
	 * \if English
	 * static constructor
	 *
	 * @param target object of callback function
	 * @param sel pointer to callback function
	 * @param data pointer argument for callback function
	 * @return \link wyTargetSelector wyTargetSelector\endlink
	 * \else
	 * 静态构造函数
	 *
	 * @param target 回调函数所在的类实例
	 * @param sel 指向回调函数的指针
	 * @param data 传递给回调函数的指针参数
	 * @return \link wyTargetSelector wyTargetSelector\endlink
	 * \endif
	 */
	static wyTargetSelector* make(wyObject* target, wySEL_p sel, void* data);

#if ANDROID
	/**
	 * \if English
	 * static constructor
	 *
	 * @param target java layer callback
	 * \else
	 * 静态构造函数
	 *
	 * @param target java层回调对象
	 * \endif
	 */
	static wyTargetSelector* make(jobject target);
#endif

	virtual ~wyTargetSelector();
	
	/**
	 * \if English
	 * overload of ==
	 * \else
	 * ==操作符的重载
	 * \endif
	 */
	bool operator==(wyTargetSelector& ts);

	/**
	 * \if English
	 * set time between last calling and now
	 *
	 * @param delta time between last calling and now
	 * \else
	 * 设置距离上次触发所持续的时间，例如如果按三帧刷新一次，则累计三帧消耗的时间
	 *
	 * @param delta 时间
	 * \endif
	 */
	void setDelta(float delta);

	/**
	 * \if English
	 * invoke callback function
	 * \else
	 * 触发回调
	 * \endif
	 */
	void invoke();

	/**
	 * \if English
	 * get callback target, must be a wyObject subclass
	 *
	 * @return callback target, must be a wyObject subclass
	 * \else
	 * 获得native层回调的\link wyObject wyObject对象指针\endlink
	 *
	 * @return native层回调的\link wyObject wyObject对象指针\endlink
	 * \endif
	 */
	wyObject* getTarget() { return m_target; }

#if ANDROID
	/**
	 * \if English
	 * get callback object in java side
	 *
	 * @return callback object in java side
	 * \else
	 * 获得java层回调对象
	 *
	 * @return java层回调对象
	 * \endif
	 */
	jobject getJavaTarget() { return m_jTarget; }
#endif

	/**
	 * \if English
	 * get id of target selector
	 *
	 * @return id of target selector
	 * \else
	 * 获得标识id
	 *
	 * @return 标识id
	 * \endif
	 */
	int getId() { return m_id; }

	/**
	 * \if English
	 * set id of target selector
	 *
	 * @param id id of target selector
	 * \else
	 * 设置标识id
	 *
	 * @param id 标识id
	 * \endif
	 */
	void setId(int id) { m_id = id; }

	/**
	 * \if English
	 * get time between last calling and now
	 *
	 * @return time between last calling and now
	 * \else
	 * 获得距离上次触发所持续的时间，例如如果按三帧刷新一次，则累计三帧消耗的时间
	 *
	 * @return 时间
	 * \endif
	 */
	float getDelta() { return m_delta; }

	/**
	 * \if English
	 * Get data set in selector, it is a union so you need get proper value
	 * based on the argument you set
	 *
	 * @return ArgValue union
	 * \else
	 * 得到选择子的数据字段
	 *
	 * @return ArgValue联合结构
	 * \endif
	 */
	ArgValue& getData() { return m_data; }
};

#endif // __wyTargetSelector_h__
