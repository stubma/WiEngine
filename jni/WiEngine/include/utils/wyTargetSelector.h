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
 * it indicates a callback
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
	 * Data set for this target selector
	 */
	union ArgValue {
		/**
		 * Integer value
		 */
		int i;

		/**
		 * Float value
		 */
		float f;

		/**
		 * pointer
		 */
		void* p;
	};

private:
	/**
	 * callback target, must be a wyObject subclass
	 */
	wyObject* m_target;

	/**
	 * id of this target selector
	 */
	int m_id;

	/**
	 * the time between last calling and now
	 */
	float m_delta;

	/// callback prototype
	Prototype m_prototype;

	/**
	 * argument of callback
	 */
	ArgValue m_data;

	/**
	 * callback function of a class
	 */
	Selector m_sel;

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

public:
	/**
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
	 */
	static wyTargetSelector* makeId(wyObject* callback, int id);

	/**
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
	 */
	static wyTargetSelector* makeId(wyObject* callback, int id, int data);

	/**
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
	 */
	static wyTargetSelector* makeId(wyObject* callback, int id, float data);

	/**
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
	 */
	static wyTargetSelector* makeId(wyObject* callback, int id, void* data);

	/**
	 * static constructor
	 *
	 * @param target object of callback function
	 * @param sel pointer to callback function
	 * @return \link wyTargetSelector wyTargetSelector\endlink
	 */
	static wyTargetSelector* make(wyObject* target, wySEL sel);

	/**
	 * static constructor
	 *
	 * @param target object of callback function
	 * @param sel pointer to callback function
	 * @param data integer argument for callback function
	 * @return \link wyTargetSelector wyTargetSelector\endlink
	 */
	static wyTargetSelector* make(wyObject* target, wySEL_i sel, int data);

	/**
	 * static constructor
	 *
	 * @param target object of callback function
	 * @param sel pointer to callback function
	 * @param data float argument for callback function
	 * @return \link wyTargetSelector wyTargetSelector\endlink
	 */
	static wyTargetSelector* make(wyObject* target, wySEL_f sel, float data);

	/**
	 * static constructor
	 *
	 * @param target object of callback function
	 * @param sel pointer to callback function
	 * @param data pointer argument for callback function
	 * @return \link wyTargetSelector wyTargetSelector\endlink
	 */
	static wyTargetSelector* make(wyObject* target, wySEL_p sel, void* data);

	virtual ~wyTargetSelector();
	
	/**
	 * overload of ==
	 */
	bool operator==(wyTargetSelector& ts);

	/**
	 * set time between last calling and now
	 *
	 * @param delta time between last calling and now
	 */
	void setDelta(float delta);

	/**
	 * invoke callback function
	 */
	void invoke();

	/**
	 * get callback target, must be a wyObject subclass
	 *
	 * @return callback target, must be a wyObject subclass
	 */
	wyObject* getTarget() { return m_target; }

	/**
	 * get id of target selector
	 *
	 * @return id of target selector
	 */
	int getId() { return m_id; }

	/**
	 * set id of target selector
	 *
	 * @param id id of target selector
	 */
	void setId(int id) { m_id = id; }

	/**
	 * get time between last calling and now
	 *
	 * @return time between last calling and now
	 */
	float getDelta() { return m_delta; }

	/**
	 * Get data set in selector, it is a union so you need get proper value
	 * based on the argument you set
	 *
	 * @return ArgValue union
	 */
	ArgValue& getData() { return m_data; }
};

#endif // __wyTargetSelector_h__
