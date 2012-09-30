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

import com.wiyun.engine.types.WYColor4B;
import com.wiyun.engine.types.WYSize;

/**
 * 提供一个可滚动的层, 类似于Android中的ScrollView. ScrollableLayer支持水平或垂直
 * 或双方向滚动. 创建后应该调用setVertical或setHorizontal设置是否允许滚动. 如果想
 * 往ScrollableLayer中添加子节点, 应该调用addScrollableChild而不是addChild.
 * 因为addChild是直接往ScrollableLayer中添加节点, 是不会被滚动的.
 */
public class ScrollableLayer extends ColorLayer {
	/**
	 * 滚动层回调定义
	 */
	public static interface IScrollableLayerCallback {
		/**
		 * 当滚动层的偏移位置发生变化时被调用, 可以通过getOffsetX, getOffsetY方法获得当前的位置.
		 *
		 * @param layerPointer 底层的对象指针
		 */
		public void onScrollOffsetChanged(int layerPointer);

		/**
		 * 当正要开始抛掷时被调用, 在抛掷结束前, onScrollOffsetChanged会被持续触发. 但是
		 * 要注意onScrollOffsetChanged在没有抛掷时也会发生, 只要偏移改变就会发生
		 *
		 * @param layerPointer 底层的对象指针
		 */
		public void onStartFling(int layerPointer);

		/**
		 * 当抛掷结束时被调用
		 *
		 * @param layerPointer 底层的对象指针
		 */
		public void onEndFling(int layerPointer);
		
		/**
		 * \if English
		 * Invoked for every scrollable child when it is outside of scrollable layer area.
		 * You can do some resource releasing in this method, and it is critical if your
		 * have many many textures in scrollablelayer.
		 *
		 * @param layerPointer ScrollableLayer native pointer
		 * @param childPointer child node which is outside scrollable layer area
		 * \else
		 * 当一个可滚动节点离开了可见滚动区域时被调用, 在这个方法里可以做一些资源释放工作. 如果一个可
		 * 滚动层里非常多的贴图, 则及时的释放那些不可见的贴图是很重要的.
		 *
		 * @param layerPointer ScrollableLayer的底层指针
		 * @param childPointer 离开了可见滚动区域的节点底层指针
		 * \endif
		 */
		public void onScrollableChildNotVisible(int layerPointer, int childPointer);
	}
	
    /**
     * 创建可滚动层, 颜色透明
     * 
     * @return 层实例
     */
    public static ScrollableLayer make() {
        return new ScrollableLayer();
    }
    
    /**
     * 创建可滚动层
     * 
     * @param color 层背景色
     * @return 层实例
     */
    public static ScrollableLayer make(WYColor4B color) {
        return new ScrollableLayer(color);
    }
    
    /**
     * 从底层指针获得一个ScrollableLayer的Java对象
     * 
     * @param pointer 底层指针
     * @return {@link ScrollableLayer}
     */
    public static ScrollableLayer from(int pointer) {
    	return pointer == 0 ? null : new ScrollableLayer(pointer);
    }
    
    protected ScrollableLayer() {
    	nativeInit(WYColor4B.make(0, 0, 0, 0));
    }
    
	protected ScrollableLayer(WYColor4B color) {
		nativeInit(color);
	}

	protected ScrollableLayer(int pointer) {
		super(pointer);
	}
	
    private native void nativeInit(WYColor4B color);
    
    @Override
    protected void doNativeInit() {
    }
	
	/**
	 * 设置是否允许垂直滚动, 缺省是false
	 *
	 * @param flag true表示允许垂直滚动
	 */
	public native void setVertical(boolean flag);

	/**
	 * 是否允许垂直滚动
	 *
	 * @return true表示允许垂直滚动
	 */
	public native boolean isVertical();

	/**
	 * 设置是否允许水平滚动, 缺省是false
	 *
	 * @param flag true表示允许水平滚动
	 */
	public native void setHorizontal(boolean flag);

	/**
	 * 是否允许水平滚动
	 *
	 * @return true表示允许水平滚动
	 */
	public native boolean isHorizontal();

	/**
	 * 添加可滚动子节点,方法是线程安全的
	 *
	 * @param child 子节点\link wyNode wyNode对象指针\endlink
	 * @param z z轴顺序
	 * @param tag 子节点的标识
	 */
	public native void addScrollableChild(Node child, int z, int tag);
	
	/**
	 * 添加可滚动子节点,方法是线程安全的
	 *
	 * @param child 子节点\link wyNode wyNode对象指针\endlink
	 */
	public void addScrollableChild(Node child) {
		addScrollableChild(child, child.getZOrder(), child.getTag());
	}
	
	/**
	 * 添加可滚动子节点,方法是线程安全的
	 *
	 * @param child 子节点\link wyNode wyNode对象指针\endlink
	 * @param z z轴顺序
	 */
	public void addScrollableChild(Node child, int z) {
		addScrollableChild(child, z, child.getTag());
	}

	/**
	 * 删除某个子节点,方法是线程安全的
	 *
	 * @param child 要删除的节点
	 * @param cleanup true表示重置被删除的节点的状态。一个节点被clean之后将失去一些状态，比如附加在节点
	 * 		上的action，timer等，但是这个节点仍然可以用addChild加回来继续使用。
	 */
	public native void removeScrollableChild(Node child, boolean cleanup);

	/**
	 * 根据tag删除某个子节点,方法是线程安全的
	 *
	 * @param tag 子节点的tag
	 * @param cleanup true表示重置被删除的节点的状态。一个节点被clean之后将失去一些状态，比如附加在节点
	 * 		上的action，timer等，但是这个节点仍然可以用addChild加回来继续使用。
	 */
	public native void removeScrollableChildByTag(int tag, boolean cleanup);
	
	/**
	 * \if English
	 * Remove all scrollable children, method is thread safe
	 *
	 * @param cleanup true means reset state of removed children
	 * \else
	 * 删除所有可滚动节点, 方法是线程安全的
	 *
	 * @param cleanup true表示重置被删除的节点的状态。一个节点被clean之后将失去一些状态，比如附加在节点
	 * 		上的action，timer等，但是这个节点仍然可以用addChild加回来继续使用。
	 * \endif
	 */
	public native void removeAllScrollableChildrenLocked(boolean cleanup);
	
	/**
	 * \if English
	 * Get a scrollable child by tag. This method can only be used to get child which
	 * is added by \c addScrollableChildLocked
	 *
	 * @param tag child tag
	 * @return child node pointer, or NULL if no such child node
	 * \else
	 * 根据tag得到某个可滚动子节点, 这个方法仅能用来得到通过\c addScrollableChildLocked方法添加的
	 * 子节点
	 *
	 * @param tag 子节点tag
	 * @return 子节点的底层指针, 如果没有找到则返回NULL
	 * \endif
	 */
	public native int getScrollableChildByTag(int tag);
	
	/**
	 * 得到当前可滚动区域的大小，这个方法必须在\c addScrollableChildLocked 之后调用，
	 * 因为\c addScrollableChildLocked 会让可滚动区域重新计算, 会导致之前获得的大小
	 * 不再正确
	 *
	 * @return 可滚动区域大小
	 */
	public WYSize getScrollExtent() {
		WYSize s = WYSize.makeZero();
		nativeGetScrollExtent(s);
		return s;
	}
	
	private native void nativeGetScrollExtent(WYSize s);
	
	/**
	 * 设置水平滚动条节点。缺省是没有的，即水平滚动的时候并没有一个可见的滚动条. 可以设置任意\link Node Node\endlink
	 * 的子类为水平滚动条，如果这个节点是一个\link NinePatchSprite NinePatchSprite\endlink对象，则其会根据
	 * 可视范围进行相应的拉伸。
	 *
	 * @param thumb 用作水平滚动条的\link Node Node\endlink对象, NULL表示要去掉水平滚动条
	 */
	public native void setHorizontalThumb(Node thumb);

	/**
	 * 设置垂直滚动条节点。缺省是没有的，即垂直滚动的时候并没有一个可见的滚动条. 可以设置任意\link Node Node\endlink
	 * 的子类为垂直滚动条，如果这个节点是一个\link NinePatchSprite NinePatchSprite\endlink对象，则其会根据
	 * 可视范围进行相应的拉伸。
	 *
	 * @param thumb 用作垂直滚动条的\link Node Node\endlink对象, NULL表示要去掉垂直滚动条
	 */
	public native void setVerticalThumb(Node thumb);
	
	/**
	 * 设置如果多久无滚动就淡出滚动条，缺省是0. 0值表示不淡出滚动条。
	 *
	 * @param time 淡出之前的无滚动时间, 单位秒
	 */
	public native void setThumbFadeOutTime(float time);

	/**
	 * 得到淡出之前的无滚动时间
	 *
	 * @return 淡出之前的无滚动时间
	 */
	public native float getThumbFadeOutTime();
	
	/**
	 * 设置可滚动区域右边的留白大小
	 *
	 * @param m 可滚动区域右边的留白大小
	 */
	public native void setRightMargin(float m);

	/**
	 * 设置可滚动区域左边的留白大小
	 *
	 * @param m 可滚动区域左边的留白大小
	 */
	public native void setLeftMargin(float m);

	/**
	 * 获得可滚动区域左边的留白大小
	 *
	 * @return 可滚动区域左边的留白大小
	 */
	public native float getLeftMargin();
	
	/**
	 * 获得可滚动区域右边的留白大小
	 *
	 * @return 可滚动区域右边的留白大小
	 */
	public native float getRightMargin();

	/**
	 * 设置可滚动区域上边的留白大小
	 *
	 * @param m 可滚动区域上边的留白大小
	 */
	public native void setTopMargin(float m);

	/**
	 * 获得可滚动区域上边的留白大小
	 *
	 * @return 可滚动区域上边的留白大小
	 */
	public native float getTopMargin();

	/**
	 * 设置可滚动区域下边的留白大小
	 *
	 * @param m 可滚动区域下边的留白大小
	 */
	public native void setBottomMargin(float m);

	/**
	 * 获得可滚动区域下边的留白大小
	 *
	 * @return 可滚动区域下边的留白大小
	 */
	public native float getBottomMargin();
	
	/**
	 * 获得当前的x方向滚动位置, 这个值的范围是从0到最大可滚动位置
	 *
	 * @return 当前的x方向滚动位置
	 */
	public native float getOffsetX();

	/**
	 * 获得当前的y方向滚动位置, 这个值的范围是从0到最大可滚动位置
	 *
	 * @return 当前的y方向滚动位置
	 */
	public native float getOffsetY();
	
	/**
	 * 设置当前的x方向位置，这个值的范围从0到最大可滚动位置
	 *
	 * @param x x位置，如果值不合法则不做任何事
	 */
	public native void setOffsetX(float x);

	/**
	 * 设置当前的y方向位置，这个值的范围从0到最大可滚动位置
	 *
	 * @param y y位置，如果值不合法则不做任何事
	 */
	public native void setOffsetY(float y);
	
	/**
	 * 判断当前x方向滚动位置是否已经是最右
	 *
	 * @return true表示x方向已经滚到了最右边
	 */
	public native boolean isAtXEnd();

	/**
	 * 判断当前y方向是否已经滚动到底部
	 *
	 * @return true表示y方向已经滚动到底部
	 */
	public native boolean isAtYEnd();
	
	/**
	 * 设置java端的回调
	 *
	 * @param callback java端实现了回调接口的类
	 */
	public native void setCallback(IScrollableLayerCallback callback);
}
