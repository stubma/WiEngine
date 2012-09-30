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
 * <p>菜单。菜单也是层的子类，它负责管理{@link MenuItem}的布局和点击事件。使用菜单的正确方式是：
 * 先创建MenuItem的对象，然后用MenuItem创建Menu，再把Menu加入到场景中。</p>
 * 
 * <p>菜单缺省打开了touch enabled设置, 要注意的是: 如果只是想临时禁止触摸事件处理, 使用
 * setEnabled(false)会比较好. 如果使用setTouchEnabled(false), 再使用setTouchEnabled(true)
 * 打开事件, 则会使触摸事件重定向到java层, 这会使Menu点击时无反应.</p>
 */
public class Menu extends Layer {
	/**
	 * 创建菜单
	 * 
	 * @param items 菜单中包含的菜单项
	 * @return 菜单实例
	 */
	public static Menu make(MenuItem... items) {
		return new Menu(items);
	}

	/**
	 * 构造函数
	 * 
	 * @param items 菜单中包含的菜单项
	 */
	protected Menu(MenuItem... items) {
		nativeInit(items);
	}
	
    /**
     * 从底层指针获得一个Menu的Java对象
     * 
     * @param pointer 底层指针
     * @return {@link Menu}
     */
    public static Menu from(int pointer) {
    	return pointer == 0 ? null : new Menu(pointer);
    }
    
    protected Menu(int pointer) {
    	super(pointer);
    }
	
	private native void nativeInit(MenuItem... items);

	@Override
	protected void doNativeInit() {
	}
	
	/**
	 * 垂直排列菜单, 只排一列
	 */
	public native void alignItemsVertically();

	/**
	 * 垂直排列菜单, 只排一列
	 *
	 * @param padding 菜单项垂直间隔
	 */
	public native void alignItemsVertically(float padding);

	/**
	 * 水平排列菜单, 只排一行
	 */
	public native void alignItemsHorizontally();

	/**
	 * 水平排列菜单, 只排一行
	 *
	 * @param padding 菜单项水平间隔
	 */
	public native void alignItemsHorizontally(float padding);
	
	/**
	 * 从第1行开始一直往下排列，每一行的列数通过参数指定
	 *
	 * @param columns 每一行中的列数，比如{3, 2}，那么第一行会排3个，第二行会排2个
	 */
	public native void alignItemsInColumns(int columns[]);
	
	/**
	 * 从第1行开始一直往下排列，每一行的列数通过参数指定. 每一行的列宽度是相等的。
	 *
	 * @param columns 每一行中的列数，比如{3, 2}，那么第一行会排3个，第二行会排2个
	 * @param padding 每行之间的间隔
	 */
	public native void alignItemsInColumns(int columns[], float padding);

	/**
	 * 从第1列开始一直往右排列，每一列的行数通过参数指定
	 *
	 * @param rows 每一列中的行数，比如{3, 2}，那么第一列会排3个，第二列会排2个
	 */
	public native void alignItemsInRows(int rows[]);
	
	/**
	 * 从第1列开始一直往右排列，每一列的行数通过参数指定. 每一列的行的高度是相等的.
	 *
	 * @param rows 每一列中的行数，比如{3, 2}，那么第一列会排3个，第二列会排2个
	 * @param padding 每列之间的间隔
	 */
	public native void alignItemsInRows(int rows[], float padding);
}
