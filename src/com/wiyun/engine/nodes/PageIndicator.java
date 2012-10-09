package com.wiyun.engine.nodes;

/**
 * \link PageControl PageControl\endlink中的页面指示组件, 它是一个虚类, 可以通过
 * 继承实现不同风格的页面指示组件. 如果一个\link PageControl PageControl\endlink指定
 * 了一个页面指示组件, 则页面指示节点会是\link PageControl PageControl\endlink的子
 * 节点
 */
public class PageIndicator extends Node {
	public static PageIndicator from(int pointer) {
		return pointer == 0 ? null : new PageIndicator(pointer);
	}
	
	protected PageIndicator() {
	}
	
	protected PageIndicator(int pointer) {
		super(pointer); 
	}
	
	@Override
	protected void doNativeInit() {
	}
}
