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
#ifndef __wyQuad2D_h__
#define __wyQuad2D_h__

#ifdef __cplusplus
extern "C" {
#endif

WIENGINE_API extern const wyQuad2D wyq2Zero;

static inline wyQuad2D wyq2(const float bl_x, const float bl_y, const float br_x, const float br_y,
		const float tl_x, const float tl_y, const float tr_x, const float tr_y) {
	wyQuad2D v = {
		bl_x, bl_y,
		br_x, br_y,
		tl_x, tl_y,
		tr_x, tr_y
	};
	return v;
}

static inline wyQuad2D wyq2Scale(wyQuad2D q, float s) {
	wyQuad2D v = {
		q.tl_x * s, q.tl_y * s,
		q.tr_x * s, q.tr_y * s,
		q.bl_x * s, q.bl_y * s,
		q.br_x * s, q.br_y * s
	};
	return v;
}

static inline void wyq2Set(wyQuad2D& t, const float bl_x, const float bl_y, const float br_x, const float br_y,
		const float tl_x, const float tl_y, const float tr_x, const float tr_y) {
	t.bl_x = bl_x;
	t.bl_y = bl_y;
	t.br_x = br_x;
	t.br_y = br_y;
	t.tl_x = tl_x;
	t.tl_y = tl_y;
	t.tr_x = tr_x;
	t.tr_y = tr_y;
}

#ifdef __cplusplus
}
#endif

#endif // __wyQuad2D_h__
