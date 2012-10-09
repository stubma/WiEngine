package com.wiyun.engine.nodes;

import com.wiyun.engine.opengl.Texture2D;
import com.wiyun.engine.types.WYRect;

/**
 * 点状页面指示节点, 最传统的一种页面指示节点. 创建这个节点时, 指定两个图片分别表示页面没选中和
 * 选中的状态.
 */
public class DotPageIndicator extends PageIndicator {
	/**
	 * 静态构造函数
	 *
	 * @param dot 页面没有被选中时的图片, 不能为NULL
	 * @param dotRect 如果dot是一个图片集, 则表示点图片在图片集中的位置
	 * @param selectedDot 页面被选中时的图片, 不能为NULL
	 * @param selectedDotRect 如果selectedDot是一个图片集, 则表示选中的点图片在图片集中的位置
	 * @return {@link DotPageIndicator}
	 */
	public static DotPageIndicator make(Texture2D dot, WYRect dotRect, Texture2D selectedDot, WYRect selectedDotRect) {
		return new DotPageIndicator(dot, dotRect, selectedDot, selectedDotRect);
	}
	
	/**
	 * 静态构造函数
	 *
	 * @param dot 页面没有被选中时的图片, 不能为NULL
	 * @param selectedDot 页面被选中时的图片, 不能为NULL
	 * @return {@link DotPageIndicator}
	 */
	public static DotPageIndicator make(Texture2D dot, Texture2D selectedDot) {
		return new DotPageIndicator(dot, 
				WYRect.make(0, 0, dot.getWidth(), dot.getHeight()),
				selectedDot, 
				WYRect.make(0, 0, selectedDot.getWidth(), selectedDot.getHeight()));
	}
	
	public static DotPageIndicator from(int pointer) {
		return pointer == 0 ? null : new DotPageIndicator(pointer);
	}
	
	protected DotPageIndicator() {
	}
	
	protected DotPageIndicator(Texture2D dot, WYRect dotRect, Texture2D selectedDot, WYRect selectedDotRect) {
		nativeInit(dot, dotRect, selectedDot, selectedDotRect);
	}
	
	protected DotPageIndicator(int pointer) {
		super(pointer); 
	}
	
	private native void nativeInit(Texture2D dot, WYRect dotRect, Texture2D selectedDot, WYRect selectedDotRect);
	
	public native void setDotSpacing(float spacing);
	
	public native float getDotSpacing();
}
