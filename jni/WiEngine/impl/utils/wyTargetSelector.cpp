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
#include "wyTargetSelector.h"
#include "wyLog.h"

#ifdef __cplusplus
extern "C" {
#endif
	
bool wyTargetSelectorEquals(wyTargetSelector* ts1, wyTargetSelector* ts2) {
	return *ts1 == *ts2;
}
	
#ifdef __cplusplus
}
#endif

wyTargetSelector::~wyTargetSelector() {
	m_target = NULL;
}

wyTargetSelector::wyTargetSelector(wyObject* callback, int id, ArgValue data) :
		m_target(callback),
		m_id(id) {
	memcpy(&m_data, &data, sizeof(ArgValue));
	memset(&m_sel, 0, sizeof(Selector));
}

wyTargetSelector::wyTargetSelector(wyObject* target, wySEL sel) :
		m_target(target),
		m_id(0) {
	m_prototype = NONE;
	memset(&m_data, 0, sizeof(ArgValue));
	memset(&m_sel, 0, sizeof(Selector));
	m_sel.sel = sel;
}

wyTargetSelector::wyTargetSelector(wyObject* target, wySEL_i sel, int data) :
		m_target(target),
		m_id(0) {
	m_prototype = INT;
	memset(&m_data, 0, sizeof(ArgValue));
	memset(&m_sel, 0, sizeof(Selector));
	m_sel.sel_i = sel;
	m_data.i = data;
}

wyTargetSelector::wyTargetSelector(wyObject* target, wySEL_f sel, float data) :
		m_target(target),
		m_id(0) {
	m_prototype = FLOAT;
	memset(&m_data, 0, sizeof(ArgValue));
	memset(&m_sel, 0, sizeof(Selector));
	m_sel.sel_f = sel;
	m_data.f = data;
}

wyTargetSelector::wyTargetSelector(wyObject* target, wySEL_p sel, void* data) :
		m_target(target),
		m_id(0) {
	m_prototype = PVOID;
	memset(&m_data, 0, sizeof(ArgValue));
	memset(&m_sel, 0, sizeof(Selector));
	m_sel.sel_p = sel;
	m_data.p = data;
}

wyTargetSelector* wyTargetSelector::makeId(wyObject* callback, int id) {
	ArgValue v;
	memset(&v, 0, sizeof(ArgValue));
	wyTargetSelector* ts = WYNEW wyTargetSelector(callback, id, v);
	return (wyTargetSelector*)ts->autoRelease();
}

wyTargetSelector* wyTargetSelector::makeId(wyObject* callback, int id, int data) {
	ArgValue v;
	memset(&v, 0, sizeof(ArgValue));
	v.i = data;
	wyTargetSelector* ts = WYNEW wyTargetSelector(callback, id, v);
	return (wyTargetSelector*)ts->autoRelease();
}

wyTargetSelector* wyTargetSelector::makeId(wyObject* callback, int id, float data) {
	ArgValue v;
	memset(&v, 0, sizeof(ArgValue));
	v.f = data;
	wyTargetSelector* ts = WYNEW wyTargetSelector(callback, id, v);
	return (wyTargetSelector*)ts->autoRelease();
}

wyTargetSelector* wyTargetSelector::makeId(wyObject* callback, int id, void* data) {
	ArgValue v;
	memset(&v, 0, sizeof(ArgValue));
	v.p = data;
	wyTargetSelector* ts = WYNEW wyTargetSelector(callback, id, v);
	return (wyTargetSelector*)ts->autoRelease();
}

wyTargetSelector* wyTargetSelector::make(wyObject* target, wySEL sel) {
	wyTargetSelector* ts = WYNEW wyTargetSelector(target, sel);
	return (wyTargetSelector*)ts->autoRelease();
}

wyTargetSelector* wyTargetSelector::make(wyObject* target, wySEL_i sel, int data) {
	wyTargetSelector* ts = WYNEW wyTargetSelector(target, sel, data);
	return (wyTargetSelector*)ts->autoRelease();
}

wyTargetSelector* wyTargetSelector::make(wyObject* target, wySEL_f sel, float data) {
	wyTargetSelector* ts = WYNEW wyTargetSelector(target, sel, data);
	return (wyTargetSelector*)ts->autoRelease();
}

wyTargetSelector* wyTargetSelector::make(wyObject* target, wySEL_p sel, void* data) {
	wyTargetSelector* ts = WYNEW wyTargetSelector(target, sel, data);
	return (wyTargetSelector*)ts->autoRelease();
}

bool wyTargetSelector::operator==(wyTargetSelector& ts) {
	if(this == &ts)
		return true;

	if(getTarget() != NULL && getTarget() == ts.getTarget()) {
		if(m_sel.sel != NULL && m_sel.sel == ts.m_sel.sel)
			return true;

		if(m_sel.sel == NULL && m_id == ts.getId())
			return true;
	}

	return false;
}

void wyTargetSelector::setDelta(float delta) {
	if(m_target != NULL) {
		m_delta = delta;
	}
}

void wyTargetSelector::invoke() {
	if(m_target != NULL) {
		if(m_sel.sel != NULL) {
			switch(m_prototype) {
				case NONE:
					(m_target->*m_sel.sel)(this);
					break;
				case INT:
					(m_target->*m_sel.sel_i)(this, m_data.i);
					break;
				case FLOAT:
					(m_target->*m_sel.sel_f)(this, m_data.f);
					break;
				case PVOID:
					(m_target->*m_sel.sel_p)(this, m_data.p);
					break;
			}
		} else {
			m_target->onTargetSelectorInvoked(this);
		}
	} 
}
