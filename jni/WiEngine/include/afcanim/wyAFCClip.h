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
#ifndef __wyAFCClip_h__
#define __wyAFCClip_h__

#include "wyObject.h"
#include "wyArray.h"
#include "wyTypes.h"
#include "wyAFCConstants.h"

class wySpriteBatchNode;

/**
 * @struct wyAFCClipData
 *
 * Additional data of clip
 */
typedef struct WIENGINE_API wyAFCClipData {
	/**
	 * Clip center position in frame
	 */
	wyPoint clipPos;

	union {
		/**
		 * info of image clip
		 */
		struct {
			/**
			 * the batch node related to this clip currently
			 */
			wySpriteBatchNode* sheet;

			/**
			 * Image index of clip, it is the original sheet texture related
			 * to this clip
			 */
			int imageIndex;

			/**
			 * image rect in atlas
			 */
			wyRect rect;

			/**
			 * is image flipped in x axis
			 */
			bool flipX;

			/**
			 * rotation degree of image, positive value is clockwise
			 */
			float rotation;
		} i;

		/**
		 * info of ellipse clip
		 */
		struct {
			/**
			 * fill color in 0xaarrggbb format
			 */
			int color;

			/**
			 * size of ellipse circumscribed rectangle
			 */
			wySize size;

			/**
			 * start angle of ellipse
			 */
			float startAngle;

			/**
			 * end angle of ellipse
			 */
			float endAngle;
		} e;

		/**
		 * info of line clip
		 */
		struct {
			/**
			 * color in 0xaarrggbb format
			 */
			int color;

			/**
			 * end point of line, the start point is \c m_clipPos of \link wyAFCClip wyAFCClip\endlink
			 */
			wyPoint endPoint;
		} l;

		/**
		 * info of rect clip
		 */
		struct {
			/**
			 * fill color in 0xaarrggbb format
			 */
			int color;

			/**
			 * size of rectangle
			 */
			wySize size;
		} r;

		/**
		 * info of roundrect clip
		 */
		struct {
			/**
			 * fill color in 0xaarrggbb format
			 */
			int color;

			/**
			 * size of round rectangle
			 */
			wySize size;

			/**
			 * width of round corner
			 */
			float arcWidth;

			/**
			 * height of round corner
			 */
			float arcHeight;
		} rr;

		/**
		 * info of collision rect clip
		 */
		struct {
			/**
			 * size of collision rectangle
			 */
			wySize size;
		} cr;

		/**
		 * info of collision triangle clip
		 */
		struct {
			/**
			 * second point
			 */
			wyPoint pt2;

			/**
			 * third point
			 */
			wyPoint pt3;
		} t;
	};
} wyAFCClipData;

/**
 * @class wyAFCClip
 *
 * A clip in a frame
 */
class WIENGINE_API wyAFCClip : public wyObject {
private:
	/**
	 * clip type
	 */
	wyAFCClipType m_type;

	/**
	 * Clip index in editor. However, some editor doesn't assign an index to
	 * clip, such as Motion Welder, SpriteX, etc., and the clip index is meaningless
	 * for those editors
	 */
	int m_index;

	/**
	 * additional data of clip
	 */
	wyAFCClipData m_data;

protected:
	wyAFCClip();

public:
	virtual ~wyAFCClip();
	static wyAFCClip* make();

	/**
	 * Get type of clip
	 *
	 * @return type of clip
	 * \see wyAFCClipType
	 */
	wyAFCClipType getType() { return m_type; }

	/**
	 * Set type of clip
	 *
	 * @param type type of clip
	 * \see wyAFCClipType
	 */
	void setType(wyAFCClipType type) { m_type = type; }

	/**
	 * Clip index in editor. However, some editor doesn't assign an index to
	 * clip, such as Motion Welder, SpriteX 3.9.4, etc., and the clip index is meaningless
	 * for those editors. Furthermore, if this clip is a mapped clip of external atlas,
	 * then index is also useless.
	 *
	 * \note
	 * If index is -1, then index field is useless for this clip
	 *
	 * @return clip index, returns -1 if index field is meaningless for this clip
	 */
	int getIndex() { return m_index; }

	/**
	 * Set clip index
	 *
	 * @param i clip index
	 */
	void setIndex(int i) { m_index = i; }

	/**
	 * Get clip data
	 *
	 * @return clip data
	 */
	wyAFCClipData& getData() { return m_data; }
};

#endif // __wyAFCClip_h__
