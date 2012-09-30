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

import com.wiyun.engine.nodes.Node.IColorable;
import com.wiyun.engine.types.WYColor3B;
import com.wiyun.engine.utils.TargetSelector;

/**
 * Toggle菜单项，用于集成多个菜单项，每点击一次就切换到下一个菜单项，如果是最后一个菜单项，则
 * 切会第一个菜单项。 
 */
public class MenuItemToggle extends MenuItem implements IColorable {
    /**
     * 创建菜单项实例
     * 
     * @param downSelector {@link TargetSelector}对象，将在ACTION_DOWN发生时被调用。回调方法必须是public方法，参数不限。
     * @param upSelector {@link TargetSelector}对象，将在ACTION_UP发生时被调用。回调方法必须是public方法，参数不限。
     * @param items 包含的菜单项，可变参数
     * @return {@link MenuItemToggle}
     */
    public static MenuItemToggle make(TargetSelector downSelector, TargetSelector upSelector, MenuItem... items) {
    	return new MenuItemToggle(downSelector, upSelector, items);
    }

    /**
     * 构造函数
     * 
     * @param downSelector {@link TargetSelector}对象，将在ACTION_DOWN发生时被调用。回调方法必须是public方法，参数不限。
     * @param upSelector {@link TargetSelector}对象，将在ACTION_UP发生时被调用。回调方法必须是public方法，参数不限。
     * @param items 包含的菜单项，可变参数
     */
    protected MenuItemToggle(TargetSelector downSelector, TargetSelector upSelector, MenuItem... items) {
    	nativeInit(downSelector, upSelector, items);
    }
    
    /**
     * 从底层指针获得一个MenuItemToggle的Java对象
     * 
     * @param pointer 底层指针
     * @return {@link MenuItemToggle}
     */
    public static MenuItemToggle from(int pointer) {
    	return pointer == 0 ? null : new MenuItemToggle(pointer);
    }
    
    protected MenuItemToggle(int pointer) {
    	super(pointer);
    }
    
    private native void nativeInit(TargetSelector downSelector, TargetSelector upSelector, MenuItem... items);

    /**
     * 设置当前菜单项
     * 
     * @param index 菜单项索引，第一个添加的菜单项是0，依此类推
     */
    public native void setSelectedIndex(int index);

    /**
     * 得到当前菜单项索引
     * 
     * @return 当前菜单项索引
     */
    public native int getSelectedIndex();

    public native int getAlpha();

    public native void setAlpha(int alpha);
    
	public WYColor3B getColor() {
		WYColor3B color = new WYColor3B();
		nativeGetColor(color);
		return color;
	}
	
	private native void nativeGetColor(WYColor3B color);
	
	public void setColor(WYColor3B color) {
		nativeSetColor(color.r, color.g, color.b);
	}
	
	private native void nativeSetColor(int r, int g, int b);
	
    @Override
    public Node autoRelease(boolean includeChildren) {
    	super.autoRelease(includeChildren);
    	if(includeChildren)
    		nativeAutoReleaseItems();
    	return this;
    }

	private native void nativeAutoReleaseItems();
}
