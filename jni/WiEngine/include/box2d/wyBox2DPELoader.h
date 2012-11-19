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
#ifndef __wyBox2DPELoader_H__
#define __wyBox2DPELoader_H__

#include "wyArray.h"
#include "wyHashSet.h"
#include "wyBox2D.h"

typedef unsigned char xmlChar;

class wyBox2DPELoader;

/**
 * @class wyB2BodyMeta
 *
 * meta data of b2Body
 */
class BOX2D_API wyB2BodyMeta : public wyObject {
	friend class wyBox2DPELoader;

private:
	/**
	 * all fixtures of a body
	 */
	wyArray* m_arrayFixturedef;

	/**
	 * anchor point of body
	 */
	wyPoint	 m_anchorPoint;

	/**
	 * add a fixture
	 */
	void addFixtureDef(b2FixtureDef* def);

public:
	/**
	 * constructor
	 *
	 * @param name body name
	 */
	wyB2BodyMeta(const char* name);

	virtual ~wyB2BodyMeta();

	/**
	 * create a new body in world
	 *
	 * @param box2d \link wyBox2D wyBox2D\endlink
	 */
	b2Body* createBody(wyBox2D* box2d);
};

/**
 * @class wyBox2DPELoader
 *
 * loader of Physics Editor file
 */
class BOX2D_API wyBox2DPELoader : public wyObject {
private:
	/**
	 * hash set of body meta data
	 */
	wyHashSet*	m_bodyMetas;

	/**
	 * parsing state
	 */
	void*  		m_parseState;

	/**
	 * format of plist file
	 */
	int			m_plistFormat;

	/**
	 * ratio of meter to pixel
	 */
	float		m_PTMRatio;

	/**
	 * the scale value used in parsing plist resource
	 */
	float m_resScale;

private:
	void parse(char* data, int dataLen);
	void createFixturesInfo();
	wyPoint parsePoint(const char* v, bool withScale = true);

    static bool releaseHashElm(void* elt, void* data);
    static int  hashElemEqual(void* ptr, void* elt);
    static void*  hashElemTrans(void* ptr, void* data);

	static void startElement(void* ctx, const xmlChar *name, const xmlChar **atts);
	static void endElement(void* ctx, const xmlChar *name);
	static void characters(void* ctx, const xmlChar *ch, int len);
	static void warning(void* ctx, const char* msg, ...);
	static void error(void* ctx, const char* msg, ...);	

public:
	wyBox2DPELoader();

	/**
	 * constructor
	 *
	 * @param filePath path of Physics Editor file
	 * @param isFile true means \c filePath is an absolute path in file system, false means \c filePath is a
	 * 		relative path in assets folder
	 */
	wyBox2DPELoader(const char* filePath, bool isFile);

	/**
	 * constructor
	 *
	 * @param resId resource id of Physics Editor file
	 */
	wyBox2DPELoader(int resId);

	virtual ~wyBox2DPELoader();
	
	/**
	 * entry of load function
	 *
	 * @param filePath path of Physics Editor file
	 * @param isFile true means \c filePath is an absolute path in file system, false means \c filePath is a
	 * 		relative path in assets folder
	 */
	void loadBodies(const char* filePath, bool isFile);

	/**
	 * entry of load function
	 *
	 * @param resId resource id of Physics Editor file
	 */
	void loadBodies(int resId);

	/**
	 * create a body by name
	 *
	 * @param box2d \link wyBox2D wyBox2D\endlink
	 * @param name body name, must exist in Physics Editor file
	 */
	b2Body* createBodyByName(wyBox2D* box2d, const char* name);

	/**
	 * get anchor percentage of a body specified by name
	 *
	 * @param name body name, must exist in Physics Editor file
	 */
	wyPoint getAnchorPercent(const char* name);

	/**
	 * get how many pixels one meter stands for
	 *
	 * @return pixels for one meter
	 */
	float getMeterPixels() { return m_PTMRatio; }

	/**
	 * get format of Physics Editor file
	 *
	 * @return format
	 */
	int getPlistFormat() { return m_plistFormat; }
};

#endif
