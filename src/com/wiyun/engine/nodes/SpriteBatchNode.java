package com.wiyun.engine.nodes;

import com.wiyun.engine.opengl.Texture2D;

/**
 * 用于图像节点的批处理，仅接受 \link SpriteEx SpriteEx \endlink 作为子节点。
 * 所有子节点共享一张贴图，所有节点的绘制一次完成，可提高性能。
 */
public class SpriteBatchNode extends Node {
	protected SpriteBatchNode() { 
	}
	
	protected SpriteBatchNode(int pointer) {
		super(pointer);
	}
	
	/**
	 * 构造函数
	 *
	 * @param tex 贴图
	 */
	public SpriteBatchNode(Texture2D tex) {
		nativeInit(tex);
	}
	
	@Override
	protected void doNativeInit() {
	}
	
	/**
	 * 创建一个wySpriteBatchNode类型的节点
	 *
	 * @param tex 贴图
	 */	
	public static SpriteBatchNode make(Texture2D tex) {
		return new SpriteBatchNode(tex);
	}
	
	public static SpriteBatchNode from(int pointer) {
		return pointer == 0 ? null : new SpriteBatchNode(pointer);
	}
	
	//native methods declare
	private native void nativeInit(Texture2D tex);
}