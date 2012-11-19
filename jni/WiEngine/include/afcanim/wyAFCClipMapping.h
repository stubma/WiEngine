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
#ifndef __wyAFCClipMapping_h__
#define __wyAFCClipMapping_h__

#include "wyObject.h"
#include "wyTypes.h"

class wySpriteBatchNode;
class wyTexture2D;

/**
 * @typedef wyAFCClipMappingRuleType
 *
 * Definition of all clip mapping rule supported by WiEngine AFC feature
 */
typedef enum {
	/**
	 * map a clip to another clip which is in same file data
	 */
	AFC_CMR_INTERNAL_CLIP,

	/**
	 * map a clip to another clip which is not in same file data
	 */
	AFC_CMR_EXTERNAL_CLIP,

	/**
	 * map a clip to an atlas sprite
	 */
	AFC_CMR_EXTERNAL_ATLAS
} wyAFCClipMappingRuleType;

/**
 * @struct wyAFCClipMappingRule
 *
 * mapping rule info structure
 */
typedef struct WIENGINE_API wyAFCClipMappingRule {
	/**
	 * rule type
	 */
	wyAFCClipMappingRuleType type;

	/**
	 * index of clip which need to be mapped
	 */
	int sourceClipIndex;

	union {
		/**
		 * icr means internal clip rule
		 */
		struct {
			/**
			 * dest clip index
			 */
			int destClipIndex;
		} icr;

		/**
		 * ecr means external clip rule
		 */
		struct {
			/**
			 * afc file data id
			 */
			int dataId;

			/**
			 * dest clip index in that file data
			 */
			int destClipIndex;

			/**
			 * the atlas sheet where the dest clip resides in
			 */
			wySpriteBatchNode* sheet;
		} ecr;

		/**
		 * ear means external atlas rule
		 */
		struct {
			/**
			 * the atlas sheet for texture
			 */
			wySpriteBatchNode* sheet;

			/**
			 * texture rect
			 */
			wyRect texRect;

			/**
			 * clip center position
			 */
			wyPoint pos;

			/**
			 * is image flipped in x axis
			 */
			bool flipX;

			/**
			 * rotation degree of image, positive value is clockwise
			 */
			float rotation;
		} ear;
	};
} wyAFCClipMappingRule;

/**
 * @class wyAFCClipMapping
 *
 * Clip mapping defines a set of rules of replacing a clip to another clip. Then
 * you can use clip mapping to change animation easily and dynamically.
 */
class WIENGINE_API wyAFCClipMapping : public wyObject {
private:
	/**
	 * tag for this mapping rule set
	 */
	int m_tag;

	/**
	 * how many mapping rules in buffer
	 */
	int m_count;

	/**
	 * capacity of buffer
	 */
	int m_capacity;

	/**
	 * the clip mapping rules
	 */
	wyAFCClipMappingRule* m_rules;

	/**
	 * indices buffer of source clips
	 */
	int* m_sourceClipIndices;

private:
	/**
	 * ensure buffer capacity is ok
	 */
	void ensureCapacity();

protected:
	wyAFCClipMapping(int tag);

	/**
	 * static constructor
	 *
	 * @param tag tag of this mapping rules
	 * @param data raw data of AuroraGT module mapping file
	 * @param length byte length of \c data
	 * @return \link wyAFCClipMapping wyAFCClipMapping\endlink
	 */
	static wyAFCClipMapping* makeAurora(int tag, const char* data, size_t length);

public:
	virtual ~wyAFCClipMapping();

	/**
	 * static constructor
	 *
	 * @param tag tag of this mapping rules
	 * @return \link wyAFCClipMapping wyAFCClipMapping\endlink
	 */
	static wyAFCClipMapping* make(int tag);

	/**
	 * static constructor
	 *
	 * @param tag tag of this mapping rules
	 * @param ammId resource id of aurora module mapping file
	 * @return \link wyAFCClipMapping wyAFCClipMapping\endlink
	 */
	static wyAFCClipMapping* makeAurora(int tag, int ammId);

	/**
	 * static constructor
	 *
	 * @param tag tag of this mapping rules
	 * @param ammPath path of aurora module mapping file
	 * @param isFile true means \c ammPath is an absolute path in file system, or false means
	 * 		\c ammPath is a relative path under assets
	 * @return \link wyAFCClipMapping wyAFCClipMapping\endlink
	 */
	static wyAFCClipMapping* makeAurora(int tag, const char* ammPath, bool isFile = false);

	/**
	 * static constructor
	 *
	 * @param tag tag of this mapping rules
	 * @param mfsName memory file name of aurora module mapping file
	 * @return \link wyAFCClipMapping wyAFCClipMapping\endlink
	 */
	static wyAFCClipMapping* makeMemoryAurora(int tag, const char* mfsName);

	/**
	 * Map a clip to another clip. Source and dest clip are all in same sheet
	 *
	 * @param fromClipIndex source clip index
	 * @param toClipIndex dest clip index
	 */
	void mapClip(int fromClipIndex, int toClipIndex);

	/**
	 * Map a clip to another clip. Source and dest clip are all in different file data
	 *
	 * @param fromClipIndex source clip index
	 * @param externalFileDataId data id of dest clip file data
	 * @param toClipIndex dest clip index
	 */
	void mapClip(int fromClipIndex, int externalFileDataId, int toClipIndex);

	/**
	 * Map a clip to external atlas texture
	 *
	 * @param fromClipIndex source clip index
	 * @param tex external texture
	 * @param pos clip center position, default is zero
	 * @param texRect texture rect in atlas, default is zero which means use whole texture
	 * @param flipX flip clip in x axis or not
	 * @param rotation is clip rotated, positive value means clockwise
	 */
	void mapClip(int fromClipIndex, wyTexture2D* tex, wyPoint pos = wypZero, wyRect texRect = wyrZero, bool flipX = false, float rotation = 0);

	/**
	 * Get tag
	 *
	 * @return tag
	 */
	int getTag() { return m_tag; }

	/**
	 * Search mapping rule set, and return a matched rule if found
	 *
	 * @param sourceClipIndex index of clip
	 * @return \link wyAFCClipMappingRule wyAFCClipMappingRule\endlink, or NULL if not found
	 */
	wyAFCClipMappingRule* findRule(int sourceClipIndex);
};

#endif // __wyAFCClipMapping_h__
