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

import com.wiyun.engine.nodes.Node.IBlendable;
import com.wiyun.engine.types.WYBlendFunc;
import com.wiyun.engine.types.WYColor3B;
import com.wiyun.engine.utils.TargetSelector;

/**
 * 图片式菜单。 
 */
public class MenuItemSprite extends MenuItem implements Node.IColorable, IBlendable {
    protected Sprite mNormalState;
    protected Sprite mSelectedState;
    protected Sprite mDisabledState;

    /**
     * 创建图片菜单实例
     * 
     * @param normalSprite 正常状态图片
     * @param selectedSprite 选择状态图片，为null表示不渲染选择状态
     * @param disabledSprite 禁止状态图片，为null表示不渲染禁止状态
     * @return 菜单项实例
     */
    public static MenuItemSprite make(Sprite normalSprite, Sprite selectedSprite, Sprite disabledSprite) {
        return new MenuItemSprite(normalSprite, selectedSprite, disabledSprite, null, null);
    }

    /**
     * 创建图片菜单实例
     * 
     * @param normalSprite 正常状态图片
     * @param selectedSprite 选择状态图片，为null表示不渲染选择状态
     * @param disabledSprite 禁止状态图片，为null表示不渲染禁止状态
     * @param target 回调函数所属对象
     * @param selector 回调函数名称，必须是public，且无参数
     * @return 菜单项实例
     */
    public static MenuItemSprite make(Sprite normalSprite, Sprite selectedSprite, Sprite disabledSprite, Node target, String selector) {
        return make(normalSprite, selectedSprite, disabledSprite, new TargetSelector(target, selector, null));
    }
    
    /**
     * 创建图片菜单实例
     * 
     * @param normalSprite 正常状态图片
     * @param selectedSprite 选择状态图片，为null表示不渲染选择状态
     * @param disabledSprite 禁止状态图片，为null表示不渲染禁止状态
     * @param selector {@link TargetSelector}，必须是public方法，参数不限
     * @return 菜单项实例
     */
    public static MenuItemSprite make(Sprite normalSprite, Sprite selectedSprite, Sprite disabledSprite, TargetSelector selector) {
    	return new MenuItemSprite(normalSprite, selectedSprite, disabledSprite, null, selector);
    }
    
    /**
     * 创建图片菜单实例
     * 
     * @param normalSprite 正常状态图片
     * @param selectedSprite 选择状态图片，为null表示不渲染选择状态
     * @param disabledSprite 禁止状态图片，为null表示不渲染禁止状态
     * @param downSelector {@link TargetSelector}对象，将在ACTION_DOWN发生时被调用。回调方法必须是public方法，参数不限。
     * @param upSelector {@link TargetSelector}对象，将在ACTION_UP发生时被调用。回调方法必须是public方法，参数不限。
     * @return 菜单项实例
     */
    public static MenuItemSprite make(Sprite normalSprite, Sprite selectedSprite, Sprite disabledSprite, TargetSelector downSelector, TargetSelector upSelector) {
    	return new MenuItemSprite(normalSprite, selectedSprite, disabledSprite, downSelector, upSelector);
    }
    
    /**
     * 创建图片菜单实例
     * 
     * @param normalResId 正常状态图片资源id，该参数不能为0
     * @param selectedResId 选择状态图片资源id，可以为0，为0表示不渲染选择状态
     * @param target 回调函数所属对象
     * @param selector 回调函数名称，必须是public，且无参数
     * @return 菜单项实例
     */
    public static MenuItemSprite make(int normalResId, int selectedResId, Node target, String selector) {
        return make(normalResId, selectedResId, 0, new TargetSelector(target, selector, null));
    }
    
    /**
     * 创建图片菜单实例
     * 
     * @param normalResId 正常状态图片资源id，该参数不能为0
     * @param selectedResId 选择状态图片资源id，可以为0，为0表示不渲染选择状态
     * @param selector {@link TargetSelector}，必须是public方法，参数不限
     * @return 菜单项实例
     */
    public static MenuItemSprite make(int normalResId, int selectedResId, TargetSelector selector) {
    	return make(normalResId, selectedResId, 0, selector);
    }
    
    /**
     * 创建图片菜单实例
     * 
     * @param normalResId 正常状态图片资源id，该参数不能为0
     * @param selectedResId 选择状态图片资源id，可以为0，为0表示不渲染选择状态
     * @param downSelector {@link TargetSelector}对象，将在ACTION_DOWN发生时被调用。回调方法必须是public方法，参数不限。
     * @param upSelector {@link TargetSelector}对象，将在ACTION_UP发生时被调用。回调方法必须是public方法，参数不限。
     * @return 菜单项实例
     */
    public static MenuItemSprite make(int normalResId, int selectedResId, TargetSelector downSelector, TargetSelector upSelector) {
    	return make(normalResId, selectedResId, 0, downSelector, upSelector);
    }

    /**
     * 创建图片菜单实例，通过资源id的方式，为0表示没有相关状态
     * 
     * @param normalResId 正常状态图片资源id，该参数不能为0
     * @param selectedResId 选择状态图片资源id，可以为0，为0表示不渲染选择状态
     * @param disabledResId 禁止状态图片资源id，可以为0，为0表示不渲染禁止状态
     * @return 菜单项实例
     */
    public static MenuItemSprite make(int normalResId, int selectedResId, int disabledResId) {
        return make(normalResId, selectedResId, disabledResId, null);
    }
    
    /**
     * 创建图片菜单实例，通过资源id的方式，为0表示没有相关状态
     * 
     * @param normalResId 正常状态图片资源id，该参数不能为0
     * @param selectedResId 选择状态图片资源id，可以为0，为0表示不渲染选择状态
     * @param disabledResId 禁止状态图片资源id，可以为0，为0表示不渲染禁止状态
     * @param target 回调函数所属对象
     * @param selector 回调函数名称，必须是public，且无参数
     * @return 菜单项实例
     */
    public static MenuItemSprite make(int normalResId, int selectedResId, int disabledResId, Node target, String selector) {
    	return make(normalResId, selectedResId, disabledResId, new TargetSelector(target, selector, null));
    }
    
    /**
     * 创建图片菜单实例，通过资源id的方式，为0表示没有相关状态
     * 
     * @param normalResId 正常状态图片资源id，该参数不能为0
     * @param selectedResId 选择状态图片资源id，可以为0，为0表示不渲染选择状态
     * @param disabledResId 禁止状态图片资源id，可以为0，为0表示不渲染禁止状态
     * @param selector {@link TargetSelector}，将在ACTION_UP发生时被调用。回调方法必须是public方法，参数不限。
     * @return 菜单项实例
     */
    public static MenuItemSprite make(int normalResId, int selectedResId, int disabledResId, TargetSelector selector) {
    	return new MenuItemSprite((Sprite)Sprite.make(normalResId).autoRelease(), 
    		(selectedResId == 0) ? null : (Sprite)Sprite.make(selectedResId).autoRelease(),
			(disabledResId == 0) ? null : (Sprite)Sprite.make(disabledResId).autoRelease(), 
			null, 
			selector);
    }
    
    /**
     * 创建图片菜单实例，通过资源id的方式，为0表示没有相关状态
     * 
     * @param normalResId 正常状态图片资源id，该参数不能为0
     * @param selectedResId 选择状态图片资源id，可以为0，为0表示不渲染选择状态
     * @param disabledResId 禁止状态图片资源id，可以为0，为0表示不渲染禁止状态
     * @param downSelector {@link TargetSelector}对象，将在ACTION_DOWN发生时被调用。回调方法必须是public方法，参数不限。
     * @param upSelector {@link TargetSelector}对象，将在ACTION_UP发生时被调用。回调方法必须是public方法，参数不限。
     * @return 菜单项实例
     */
    public static MenuItemSprite make(int normalResId, int selectedResId, int disabledResId, TargetSelector downSelector, TargetSelector upSelector) {
    	return new MenuItemSprite((Sprite)Sprite.make(normalResId).autoRelease(), 
    		(selectedResId == 0) ? null : (Sprite)Sprite.make(selectedResId).autoRelease(),
			(disabledResId == 0) ? null : (Sprite)Sprite.make(disabledResId).autoRelease(),
			downSelector,
			upSelector);
    }

    /**
     * 构造函数
     * 
     * @param normalSprite 正常状态图片
     * @param selectedSprite 选择状态图片，为null表示不渲染选择状态
     * @param disabledSprite 禁止状态图片，为null表示不渲染禁止状态
     * @param downSelector {@link TargetSelector}对象，将在ACTION_DOWN发生时被调用。回调方法必须是public方法，参数不限。
     * @param upSelector {@link TargetSelector}对象，将在ACTION_UP发生时被调用。回调方法必须是public方法，参数不限。
     */
    protected MenuItemSprite(Sprite normalSprite, Sprite selectedSprite, Sprite disabledSprite, TargetSelector downSelector, TargetSelector upSelector) {
    	nativeInit(downSelector, upSelector, normalSprite, selectedSprite, disabledSprite);
    }
    
    /**
     * 从底层指针获得一个MenuItemSprite的Java对象
     * 
     * @param pointer 底层指针
     * @return {@link MenuItemSprite}
     */
    public static MenuItemSprite from(int pointer) {
    	return pointer == 0 ? null : new MenuItemSprite(pointer);
    }
    
    protected MenuItemSprite(int pointer) {
    	super(pointer);
    }
    
    private native void nativeInit(TargetSelector downSelector, TargetSelector upSelector, Sprite normalSprite, Sprite selectedSprite, Sprite disabledSprite);

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
	
    public WYBlendFunc getBlendFunc() {
    	return new WYBlendFunc(getBlendFuncSrc(), getBlendFuncDst());
    }
    
    private native int getBlendFuncSrc();
    private native int getBlendFuncDst();
    
    public void setBlendFunc(WYBlendFunc blendFunc) {
    	setBlendFunc(blendFunc.src, blendFunc.dst);
    }
    
    private native void setBlendFunc(int src, int dst);
    
    @Override
    public Node autoRelease(boolean includeChildren) {
    	super.autoRelease(includeChildren);
    	if(includeChildren)
    		nativeAutoReleaseStateSprites();
    	return this;
    }

	private native void nativeAutoReleaseStateSprites();
}
