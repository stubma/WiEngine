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
 * 类似于iPhone中的PageControl, 提供一个水平或垂直滚动的列表. 里面的每一项
 * 是一个\link Node Node\endlink 的子类
 */
public class PageControl extends Node {
	/**
	 * PageControl的回调事件接口
	 */
	public static interface IPageControlCallback {
		/**
		 * \if English
		 * Invoked when a page is clicked. Clicked page must be current page
		 *
		 * @param pageControlPointer \link PageControl PageControl\endlink的底层指针
		 * @param index index of current page, in page list
		 * \else
		 * 当某页被点击时该方法被调用
		 *
		 * @param pageControlPointer 相关的\link PageControl PageControl\endlink对象的底层指针
		 * @param index 被选中页的索引
		 * \endif
		 */
		public void onPageClicked(int pageControlPointer, int index);

		/**
		 * \if English
		 * Invoked when current page is changed
		 *
		 * @param pageControlPointer \link PageControl PageControl\endlink的底层指针
		 * @param index index of current page in page list
		 * \else
		 * 当前页变化时，该方法被调用
		 *
		 * @param pageControlPointer 相关的\link PageControl PageControl\endlink对象的底层指针
		 * @param index 当前被显示页的索引
		 * \endif
		 */
		public void onPageChanged(int pageControlPointer, int index);
		
		/**
		 * \if English
		 * Invoked for every page when page control is scrolling
		 *
		 * @param pageControlPointer native pointer of \link PageControl PageControl\endlink
		 * @param pagePointer pointer of page node
		 * @param offset offset of page center, the offset is relative to page control node center.
		 * 		Generally page control's size is same as screen. If you change page control position and size,
		 * 		pay attention to what this \c offset means
		 * \else
		 * 当pagecontrol在滚动时, 这个方法会为每一个page调用一次
		 *
		 * @param pageControlPointer \link PageControl PageControl\endlink的底层指针
		 * @param pagePointer 页的节点对象的底层指针
		 * @param offset \c page的中心相对于pagecontrol中心的位置, 负值表示在pagecontrol中心的左边(水平布局时)或者
		 * 		pagecontrol中心的下边(垂直布局时). 缺省情况下, pagecontrol的大小和屏幕相同, 所以pagecontrol的中心
		 * 		也就是屏幕的中心. 但是你可能会修改pagecontrol的大小, 这种情况下要注意\c offset的含义.
		 * \endif
		 */
		public void onPagePositionChanged(int pageControlPointer, int pagePointer, float offset);
	}
	
	public static PageControl make() {
		return new PageControl();
	}
	
	public static PageControl from(int pointer) {
		return pointer == 0 ? null : new PageControl(pointer);
	}
	
	protected PageControl() {
		nativeInit();
	}
	
	@Override
	protected void doNativeInit() {
	}
	
	protected PageControl(int pointer) {
		super(pointer); 
	}
	
	private native void nativeInit();
	
	/**
	 * 添加一页
	 *
	 * @param page {@link Node}
	 */
	public native void addPage(Node page);
	
	/**
	 * 在指定位置添加一页
	 *
	 * @param page \link Node Node\endlink
	 * @param index 指定要添加到的位置
	 */
	public native void addPageAt(Node page, int index);

	/**
	 * 删除一页
	 *
	 * @param page {@link Node}
	 */
	public native void removePage(Node page);

	/**
	 * 删除指定位置的页
	 *
	 * @param index 页索引，如果超出范围则无效果
	 */
	public native void removePageAt(int index);
	
	/**
	 * 设置初始页，该方法可用来初始化当前显示的页。这个方法不会触发page
	 * changed回调。使用这个方法设置页没有滚动的动画效果，因此只适合
	 * 在创建时期初始化page control.
	 */
	public native void setInitialPage(int index);

	/**
	 * 切换到某页. 瞬间切换, 没有动画效果.
	 *
	 * @param index 要切换到的页
	 */
	public native void gotoPage(int index);

	/**
	 * 切换到某页, 切换时有动画效果.
	 *
	 * @param index 要切换到的页
	 * @param duration 切换动画效果的持续时间, 缺省值是1秒.
	 */
	public native void gotoPage(int index, float duration);
	
	/**
	 * 设置页间的间隔
	 *
	 * @param spacing 页之间的间隔
	 */
	public native void setPageSpacing(float spacing);

	/**
	 * 获得页间的间隔
	 *
	 * @return 页之间的间隔
	 */
	public native float getPageSpacing();

	/**
	 * 获得页在垂直位置的中心, 仅适用于水平型布局
	 *
	 * @return 垂直位置的中心
	 */
	public native float getCenterY();

	/**
	 * 设置垂直位置的中心, 仅适用于水平型布局
	 *
	 * @param y 垂直位置的中心
	 */
	public native void setCenterY(float y);

	/**
	 * 获得页在水平位置的中心, 仅适用于垂直型布局
	 *
	 * @return 水平位置的中心
	 */
	public native float getCenterX();

	/**
	 * 设置水平位置的中心, 仅适用于垂直型布局
	 *
	 * @param x 水平位置的中心
	 */
	public native void setCenterX(float x);
	
	/**
	 * 得到页数
	 *
	 * @return 页数
	 */
	public native int getPageCount();
	
	/**
	 * 设置回调
	 *
	 * @param callback IPageControlCallback实现类
	 */
	public native void setCallback(IPageControlCallback callback);
	
	/**
	 * 是否垂直排列页
	 *
	 * @return true表示垂直排列页
	 */
	public native boolean isVertical();

	/**
	 * 设置是否垂直排列页
	 *
	 * @param flag true表示垂直排列页
	 */
	public native void setVertical(boolean flag);
	
	/**
	 * 删除所有页
	 */
	public native void removeAllPages();
	
	/**
	 * 设置一个页面指示节点, 必须是\link PageIndicator PageIndicator\endlink的子类. 页面指示节点将被
	 * 加为\link PageControl PageControl\endlink的子节点
	 *
	 * @param indicator \link PageIndicator PageIndicator\endlink的子类, 如果为NULL表示去掉页面指示节点
	 */
	public native void setPageIndicator(PageIndicator indicator);

	/**
	 * 获得当前的页面指示节点
	 *
	 * @return 底层页面指示节点的指针
	 */
	public native int getPageIndicatorPointer();
}
