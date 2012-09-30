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
package com.wiyun.engine.nodes;

/**
 * \par
 * 在三维空间中显示多张图片，一张居中，称为前景cover，两侧可各分列多张，
 * 称后景cover。两侧图片可以以动画方式移动至中间成为前景cover。
 *
 * \par
 * 使用注意：
 * 新创建的CoverFlow对象的默认前景cover大小为（0,0）,开发者需要手动调用set方法来设置
 * 前景大小，前景cover和左右第一个cover间的距离，左右后景cover间的距离，后景z坐标等。
 */
public class CoverFlow extends Node {
	/**
	 * 静态方法，新创建一个wyCoverFlow对象
	 * @return
	 */
	public static CoverFlow make(){
		return new CoverFlow();
	}
	
	public static CoverFlow from(int pointer) {
		return pointer == 0 ? null : new CoverFlow(pointer);
	}
	
	/**
	 * 构造函数
	 */
	protected CoverFlow(){} {
		nativeInit();
	}
	
	protected CoverFlow(int pointer) {
		super(pointer);
	}
	
	@Override
	protected void doNativeInit() {
	}

	private native void nativeInit();
	
	/**
	 * 增加一个cover到链表尾部
	 */
	public native void addCover(Cover cover);
	
	/**
	 * 删除一个cover
	 */
	public native void removeCover(Cover cover);
	
	/**
	 * 在指定位置增加一个cover
	 *
	 * @param cover 待增加的cover
	 * @param after 指定将cover加到哪一个前面
	 */		
	public native void insertCoverBefore(Cover cover, Cover after);
	
	/**
	 * 获得cover在链表中的索引，链表头的索引是0，以后依次加1
	 * 如果链表执行了添加或删除操作，同一个cover可能前后会返回不同的索引值，
	 * 使用时要注意这点。
	 */
	public native int getIndex(Cover cover);
	
	private native int nativeGetCoverAt(int index);
	
	/**
	 * 根据索引返回一个cover指针，链表头的索引是0，以后依次加1。
	 * 如果链表执行了添加或删除操作，相同的索引可能前后会返回不同的cover，
	 * 使用时要注意这点。
	 */
	public Cover getCoverAt(int index) {
		return Cover.from(nativeGetCoverAt(index));
	}

	private native int nativeGetCoverList();

	/**
	 * 获得链表头指针
	 * @return
	 */
	public Cover getCoverList() {
		return Cover.from(nativeGetCoverList());
	}

	private native int nativeGetFrontCover();
	
	/**
	 * 获得当前前景cover
	 * @return
	 */
	public Cover getFrontCover() {
		return Cover.from(nativeGetFrontCover());
	}
	
	/**
	 * 设置前景cover的大小
	 *
	 * @param width 宽度，单位为像素
	 * @param height 高度，单位为像素
	 * @param updateOthers true表示会根据新大小自动调整后景z坐标，左右第一个和前景cover的距离，左右后景cover间的距离				
	 */	
	public native void setFrontCoverSize(float width, float height, boolean updateOthers);
	
	/**
	 * 在当前坐标系中设置前景cover中心位置，默认为原点
	 *
	 * @param centerX x坐标，单位为像素
	 * @param centerY y坐标，单位为像素
	 */		
	public native void setFrontCenterPosition(int centerX, int centerY);
	
	/**
	 * 设置前景cover左边的cover显示数量
	 * 
	 * @param count 前景cover左边的cover显示数量
	 */
	public native void setCountLeftVisible(int count);
	
	/**
	 * 获得前景cover左边的cover显示数量
	 * 
	 * @return 前景cover左边的cover显示数量
	 */
	public native int getCountLeftVisible();
	
	/**
	 * 设置前景cover右边的cover显示数量
	 * 
	 * @param count 前景cover右边的cover显示数量
	 */
	public native void setCountRightVisible(int count);
	
	/**
	 * 获得前景cover右边的cover显示数量
	 * 
	 * @return 前景cover右边的cover显示数量
	 */
	public native int getCountRightVisible();	
	
	/**
	 * 判断是否镜像效果启用，true表示启用
	 * 
	 * @return 镜像效果启用
	 */
	public native boolean isMirrorEnabled();
	
	/**
	 * 设置是否启用镜像效果
	 *
	 * @param bEnable true表示启用
	 */		
	public native void setMirrorEnable(boolean bEnable);
	
	/**
	 * 设置边缘模糊效果
	 *
	 * @param percent 百分比，取值为0到1
	 */		
	public native void setBlurredBorderWidth(float percent);
	
	/**
	 * 设置边缘模糊效果
	 *
	 * @param width 模糊边缘宽度，单位为像素
	 */		
	public native void setBlurredBorderWidthInPixels(int width);	
	
	/**
	 * 设置后景cover的z坐标
	 *
	 * @param z z坐标，注意，如为正值或过小的负值，可能会不能正常显示
	 */		
	public native void setDepthZ(float z);	
	
	/**
	 * 获得后景cover的z坐标
	 */		
	public native float getDepthZ();
	
	/**
	 * 设置左侧第一个cover的中心点和前景cover中心点的距离
	 *
	 * @param offset 偏移，必须为正值
	 */		
	public native void setFirstLeftOffset(float offset);
	
	/**
	 * 获得左侧第一个cover的中心点和前景cover中心点的距离
	 */		
	public native float getFirstLeftOffset();
	
	/**
	 * 设置右侧第一个cover的中心点和前景cover中心点的距离
	 *
	 * @param offset 偏移，必须为正值
	 */		
	public native void setFirstRightOffset(float offset);
	
	/**
	 * 获得右侧第一个cover的中心点和前景cover中心点的距离
	 */		
	public native float getFirstRightOffset();
	
	/**
	 * 设置左侧第一个cover之后的后景cover之间的距离
	 *
	 * @param offset 偏移, 必须为正值
	 */		
	public native void setLeftCoverCenterDelta(float offset);
	
	/**
	 * 获得左侧第一个cover之后的后景cover之间的距离
	 */		
	public native float getLeftCoverCenterDelta();	
	
	/**
	 * 设置右侧第一个cover之后的后景cover之间的距离
	 *
	 * @param offset 偏移, 必须为正值
	 */		
	public native void setRightCoverCenterDelta(float offset);
	
	/**
	 * 获得右侧第一个cover之后的后景cover之间的距离
	 */		
	public native float getRightCoverCenterDelta();
	
	/**
	 * 设置左侧后景cover绕Y轴旋转的角度
	 *
	 * @param degree 单位为度，右手规则
	 */		
	public native void setRotateDegreeLeft(float degree);
	
	/**
	 * 获得左侧后景cover绕Y轴旋转的角度
	 */		
	public native float getRotateDegreeLeft();
	
	/**
	 * 设置右侧后景cover绕Y轴旋转的角度
	 *
	 * @param degree 单位为度，右手规则
	 */		
	public native void setRotateDegreeRight(float degree);
	
	/**
	 * 获得右侧后景cover绕Y轴旋转的角度
	 */		
	public native float getRotateDegreeRight();
	
	/**
	 * 显示cover为前景cover
	 *
	 * @param cover 要设置为前景cover的cover
	 * @param duration 动画时间，即把cover移动到前景cover的时间
	 */		
	public native void showCover(Cover cover, float duration);
	
	/**
	 * 向左移动一个cover
	 *
	 * @param duration 动画时间
	 */
	public native void moveLeft(float duration);
	
	/**
	 * 向右移动一个cover
	 *
	 * @param duration 动画时间
	 */	
	public native void moveRight(float duration);
	
	private native int nativeGetTouchedCover(float x, float y);
	
	/**
	 * 获得哪个cover被点中
	 *
	 * @param x touch事件的x坐标
	 * @param y touch事件的y坐标
	 *
	 * @return 被点中的cover
	 */			
	public Cover getTouchedCover(float x, float y) {
		return Cover.from(nativeGetTouchedCover(x, y));
	}
	
	/**
	 * 设置镜像和原图的间距
	 *
	 * @param[in] height 间距，单位为像素
	 */
	public native void setHeightFromMirror(float height);

	/**
	 * 获得镜像和原图的间距
	 * @return
	 */
	public native float getHeightFromMirror();

	/**
	 * 设置镜像的明亮度
	 *
	 * @param[in] level 明亮度值，取值为[0,1]
	 */
	public native void setBrightLevelOfMirror(float level);

	/**
	 * 获得镜像的明亮度
	 * @return
	 */
	public native float getBrightLevelOfMirror();
}