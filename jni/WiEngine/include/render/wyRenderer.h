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
#ifndef __wyRenderer_h__
#define __wyRenderer_h__

#include "wyObject.h"
#include "wyTypes.h"
#include "wyShaderProgram.h"
#include "wyTexture2D.h"
#include "wyMesh.h"
#include "wyRenderState.h"

/**
 * @class wyRenderer
 *
 * \if English
 * \c wyRenderer is a virtual class which abstract necessary operation need to be
 * implemented for rendering. It is the interface which connects WiEngine core to
 * specific render technology.
 * \else
 * \c wyRenderer是一个抽象的渲染方法定义接口, 定义了完成渲染需要实现的所有方法, 它将WiEngine和
 * 具体的渲染技术隔离开来.
 * \endif
 */
class WIENGINE_API wyRenderer : public wyObject {
protected:
	wyRenderer();

public:
	virtual ~wyRenderer();

	/**
	 * \if English
	 * Set background color used to clear buffer
	 *
	 * @param color background color
	 * \else
	 * 设置用来清除颜色缓冲区的缺省颜色
	 *
	 * @param color 背景色
	 * \endif
	 */
	virtual void setBackgroundColor(wyColor4B color) = 0;

	/**
	 * Get current clear color
	 *
	 * @return \link wyColor4B wyColor4B\endlink
	 */
	virtual wyColor4B getBackgroundColor() = 0;

	/**
	 * \if English
	 * Clear buffer
	 *
	 * @param color true means color buffer should be cleared
	 * @param depth true means depth buffer should be cleared
	 * @param stencil true means stencil buffer should be cleared
	 * \else
	 * 清除缓冲区
	 *
	 * @param color true表示需要清除颜色缓冲区
	 * @param depth true表示需要清除深度缓冲区
	 * @param stencil true表示需要清除蒙版缓冲区
	 * \endif
	 */
	virtual void clearBuffers(bool color, bool depth, bool stencil) = 0;

	/**
	 * \if English
	 * Set viewport range
	 *
	 * @param x x position of viewport
	 * @param y y position of viewport
	 * @param w width of viewport
	 * @param h height of viewport
	 * \else
	 * 设置视口范围
	 *
	 * @param x 视口x位置
	 * @param y 视口y位置
	 * @param w 视口宽度
	 * @param h 视口高度
	 * \endif
	 */
	virtual void setViewport(float x, float y, float w, float h) = 0;

	/**
	 * \if English
	 * Push a clip rect to clip rect stack top and enable it
	 *
	 * @param r clip rectangle
	 * \else
	 * 设置矩形裁剪区域
	 *
	 * @param r 裁剪区域矩形
	 * \endif
	 */
	virtual void pushClipRect(wyRect& r) = 0;

	/**
	 * \if English
	 * Pop current clip rect, if no more clip rect in stack, disable clip rect.
	 * If has other clip rect, enable new top clip rect
	 * \else
	 * 弹出当前裁剪区域, 切换栈顶和剪裁区域为第二个矩形, 如果没有更多矩形, 取消剪裁
	 * \endif
	 */
	virtual void popClipRect() = 0;

    /**
     * \if English
     * Set the range of the depth values for objects. All rendered
     * objects will have their depth clamped to this range.
     *
     * @param start The range start
     * @param end The range end
     * \else
     * 设置深度范围
     *
     * @param start 起始深度
     * @param end 结束深度
     * \endif
     */
	virtual void setDepthRange(float start, float end) = 0;

	/**
	 * \if English
	 * Set active shader program
	 *
	 * @param program \link wyShaderProgram wyShaderProgram\endlink, or NULL
	 * 		if you want to remove current shader
	 * \else
	 * 设置当前shader程序
	 *
	 * @param program \link wyShaderProgram wyShaderProgram\endlink, 或者NULL表示取消当前的shader程序
	 * \endif
	 */
	virtual void setShaderProgram(wyShaderProgram* program) = 0;

	/**
	 * Set using a texture
	 *
	 * @param unit texture unit
	 * @param tex texture object
	 */
	virtual void setTexture(int unit, wyTexture2D* tex) = 0;

	/// Invoked when surface is created
	virtual void onSurfaceCreated() = 0;

	/// Invoked when surface is destroyed
	virtual void onSurfaceDestroyed() = 0;

	/**
	 * \if English
	 * Render a mesh with current material and technique
	 *
	 * @param mesh \link wyMesh wyMesh\endlink
	 * @param lodLevel level of detail of mesh
	 * \else
	 * 以当前材质和技术渲染一个mesh网络
	 *
	 * @param mesh \link wyMesh wyMesh\endlink
	 * @param lodLevel 需要渲染的模型精细度级别
	 * \endif
	 */
	virtual void renderMesh(wyMesh* mesh, int lodLevel) = 0;

	/**
	 * \if English
	 * Apply render state
	 *
	 * @param rs \link wyRenderState wyRenderState\endlink
	 * \else
	 * 使渲染状态生效
	 *
	 * @param rs \link wyRenderState wyRenderState\endlink
	 * \endif
	 */
	virtual void applyRenderState(wyRenderState* rs) = 0;

	/**
	 * Create a frame buffer and returns related texture
	 *
	 * @param desiredWidth pixel width of frame buffer
	 * @param desiredHeight pixel height of frame buffer
	 * @return frame buffer id, or -1 means creation failed
	 */
	virtual int createFrameBuffer(int desiredWidth, int desiredHeight) = 0;

	/**
	 * Get underlying texture of frame buffer
	 *
	 * @param fid frame buffer id
	 * @return texture id
	 */
	virtual int getFrameBufferTexture(int fid) = 0;

	/**
	 * Change render target to a frame buffer
	 *
	 * @param fid the frame buffer id to which render will switch
	 */
	virtual void setFrameBuffer(int fid) = 0;

	/**
	 * Restore to old frame buffer related with a frame buffer
	 *
	 * @param fid the id is NOT the frame buffer we want to restore to, it is the frame buffer
	 * 		whose oldFBO property should be checked
	 */
	virtual void restoreFrameBuffer(int fid) = 0;

	/**
	 * Destroy frame buffer and release related resources
	 *
	 * @param fid id of frame buffer will be released
	 * @param releaseTexture true means the base texture should also be released
	 */
	virtual void releaseFrameBuffer(int fid, bool releaseTexture) = 0;
};

#endif // __wyRenderer_h__
