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
import com.wiyun.engine.opengl.Texture2D;
import com.wiyun.engine.types.WYColor3B;
import com.wiyun.engine.types.WYRect;
import com.wiyun.engine.utils.TargetSelector;

/**
 * <p>按钮节点</p>
 * 
 * <p>按钮缺省打开了touch enabled设置, 要注意的是: 如果只是想临时禁止触摸事件处理, 使用
 * setEnabled(false)会比较好. 如果使用setTouchEnabled(false), 再使用setTouchEnabled(true)
 * 打开事件, 则会使触摸事件重定向到java层, 这会使Button点击时无反应.</p>
 * 
 * <p>一个按钮有三个状态: 普通, 按下和禁止. 普通状态是必须要指定的, 其它
 * 两个状态可以没有. 这三个状态分别由三个\link Node Node\endlink 节点对象代表,
 * 因此按钮可以很灵活的由各种节点组成. 三个状态节点和按钮之间没有父子关系, 但是不影响
 * 这三个状态节点接收事件, 因为按钮在onEnter和onExit发生时也会调用它们的相应方法</p>
 */
public class Button extends Node implements IColorable {
	/**
     * 创建按钮实例
     * 
     * @param normalSprite 正常状态图片，不能为null
     * @param selectedSprite 选择状态图片，为null表示不渲染选择状态
     * @param disabledSprite 禁止状态图片，为null表示不渲染禁止状态
     * @param focusedSprite 焦点状态图片，为null表示不渲染焦点状态
     * @return 按钮实例
     */
    public static Button make(Node normalSprite, Node selectedSprite, Node disabledSprite, Node focusedSprite) {
        return new Button(normalSprite, selectedSprite, disabledSprite, focusedSprite, null);
    }
    
    /**
     * 创建按钮实例
     * 
     * @param normalSprite 正常状态图片，不能为null
     * @param selectedSprite 选择状态图片，为null表示不渲染选择状态
     * @param disabledSprite 禁止状态图片，为null表示不渲染禁止状态
     * @param focusedSprite 焦点状态图片，为null表示不渲染焦点状态
     * @param target 回调函数所属对象。可以是null，表示不处理ACTION_UP
     * @param selector 回调函数名称，通过这种方式指定的回调函数必须是public，且无参数。可以是null，表示不处理ACTION_UP
     * @return 按钮实例
     */
    public static Button make(Node normalSprite, Node selectedSprite, Node disabledSprite, Node focusedSprite, Node target, String selector) {
        return new Button(normalSprite, selectedSprite, disabledSprite, focusedSprite, new TargetSelector(target, selector, null));
    }
    
    /**
     * 创建按钮实例
     * 
     * @param normalSprite 正常状态图片，不能为null
     * @param selectedSprite 选择状态图片，为null表示不渲染选择状态
     * @param disabledSprite 禁止状态图片，为null表示不渲染禁止状态
     * @param focusedSprite 焦点状态图片，为null表示不渲染焦点状态
     * @param selector ACTION_UP时的回调函数选择子，必须是public方法，参数不限。可以是null，表示不处理ACTION_UP
     * @return 按钮实例
     */
    public static Button make(Node normalSprite, Node selectedSprite, Node disabledSprite, Node focusedSprite, TargetSelector selector) {
    	return new Button(normalSprite, selectedSprite, disabledSprite, focusedSprite, selector);
    }
    
    /**
     * 创建按钮实例
     * 
     * @param normalSprite 正常状态图片，不能为null
     * @param selectedSprite 选择状态图片，为null表示不渲染选择状态
     * @param disabledSprite 禁止状态图片，为null表示不渲染禁止状态
     * @param focusedSprite 焦点状态图片，为null表示不渲染焦点状态
     * @param downSelector ACTION_DOWN时的回调函数选择子，必须是public方法，参数不限。可以是null，表示不处理ACTION_DOWN
     * @param upSelector ACTION_UP时的回调函数选择子，必须是public方法，参数不限。可以是null，表示不处理ACTION_UP
     * @return 按钮实例
     */
    public static Button make(Node normalSprite, Node selectedSprite, Node disabledSprite, Node focusedSprite, TargetSelector downSelector, TargetSelector upSelector) {
    	return new Button(normalSprite, selectedSprite, disabledSprite, focusedSprite, downSelector, upSelector);
    }
    
    /**
     * 构造函数
     * 
     * @param normalSprite 正常状态图片
     * @param selectedSprite 选择状态图片，可以为null
     * @param disabledSprite 禁止状态图片，可以为null
     * @param focusedSprite 焦点状态图片, 可以为null
     * @param selector ACTION_UP时的回调函数选择子，必须是public方法，参数不限。可以是null，表示不处理ACTION_UP
     */
    protected Button(Node normalSprite, Node selectedSprite, Node disabledSprite, Node focusedSprite, TargetSelector selector) {
    	nativeInit(normalSprite, selectedSprite, disabledSprite, focusedSprite, null, selector);
	}
    
    /**
     * 构造函数
     * 
     * @param normalSprite 正常状态图片
     * @param selectedSprite 选择状态图片，可以为null
     * @param disabledSprite 禁止状态图片，可以为null
     * @param focusedSprite 焦点状态图片, 可以为null
     * @param downSelector ACTION_DOWN时的回调函数选择子，必须是public方法，参数不限。可以是null，表示不处理ACTION_DOWN
     * @param upSelector ACTION_UP时的回调函数选择子，必须是public方法，参数不限。可以是null，表示不处理ACTION_UP
     */
    protected Button(Node normalSprite, Node selectedSprite, Node disabledSprite, Node focusedSprite, TargetSelector downSelector, TargetSelector upSelector) {
    	nativeInit(normalSprite, selectedSprite, disabledSprite, focusedSprite, downSelector, upSelector);
	}
    
    /**
     * 从底层指针获得一个Button的Java对象
     * 
     * @param pointer 底层指针
     * @return {@link Button}
     */
    public static Button from(int pointer) {
    	return pointer == 0 ? null : new Button(pointer);
    }
    
    protected Button(int pointer) {
    	super(pointer);
    }
    
    @Override
    protected void doNativeInit() {
    }
    
    private native void nativeInit(Node normalSprite, Node selectedSprite, Node disabledSprite, Node focusedSprite, TargetSelector downSelector, TargetSelector upSelector);
    
    public native int getAlpha();

    public native void setAlpha(int alpha);
    
	/**
	 * \if English
	 * to set the corresponding state's texture through one single call
	 *
	 * @param normal \link Texture2D Texture2D\endlink, the normal state won't change if this value is NULL
	 * @param selected \link Texture2D Texture2D\endlink, the selected state won't change if this value is NULL
	 * @param disabled \link Texture2D Texture2D\endlink, the disabled state won't change if this value is NULL
	 * @param focused \link Texture2D Texture2D\endlink, the focused state won't change if this value is NULL
	 * \else
	 * 改变按钮的图片, 方便于一次修改按钮的图片
	 *
	 * @param normal 正常状态的贴图, 为NULL则不更新贴图
	 * @param selected 按下状态的贴图, 为NULL则不更新贴图
	 * @param disabled 禁止状态的贴图, 为NULL则不更新贴图
	 * @param focused  获得焦点状态的贴图, 为NULL则不更新贴图
	 * \endif
	 */
    public native void setTexture(Texture2D normal, Texture2D selected, Texture2D disabled, Texture2D focused);
    
	/**
	 * \if English
	 * Set texture rect of button state node. But not all node has setTextureRect method so only
	 * \link wyTextureNode wyTextureNode\endlink and \link wySpriteEx wySpriteEx\endlink support this usage.
	 *
	 * @param normalRect texture rect of normal state
	 * @param selectedRect texture rect of selected state
	 * @param disabledRect texture rect of disabled state
	 * @param focusedRect texture rect of focused state
	 * \else
	 * 修改按钮节点的贴图矩形, 如果按钮的贴图来自于一个图片集, 则可以使用这个方法修改按钮贴图. 但是并不是所有的节点都有
	 * setTextureRect方法, 因此这个用法只对\link wyTextureNode wyTextureNode\endlink和\link wySpriteEx wySpriteEx\endlink
	 * 有效
	 *
	 * @param normalRect 正常态的贴图矩形
	 * @param selectedRect 选择态的贴图矩形
	 * @param disabledRect 禁止态的贴图矩形
	 * @param focusedRect 焦点态的贴图矩形
	 * \endif
	 */
	public native void setTextureRect(WYRect normalRect, WYRect selectedRect, WYRect disabledRect, WYRect focusedRect);
	
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
	
	/**
	 * 设置被点击时候的缩放比
	 *
	 * @param scale 被点击时候的缩放比
	 */
	public native void setClickScale(float scale);

	/**
	 * 得到被点击时候的缩放比
	 *
	 * @return 被点击时候的缩放比
	 */
	public native float getClickScale();
}
