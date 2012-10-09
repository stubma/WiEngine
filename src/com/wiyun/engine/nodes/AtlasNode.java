package com.wiyun.engine.nodes;

import com.wiyun.engine.opengl.Texture2D;

/**
 * \if English
 * Base class of \link wyTileMapAtlas wyTileMapAtlas\endlink
 * \else
 * 图片集节点的封装,是图片集节点的基类
 * \endif
 */
public abstract class AtlasNode extends Node {
	protected AtlasNode() {
	}
	
	protected AtlasNode(Texture2D texture, int itemWidth, int itemHeight, int capacity) {
    	// no need to implement because it is abstract and ndkized
	}
    
    protected AtlasNode(int pointer) {
    	super(pointer);
    }

	@Override
    protected void doNativeInit() {
    }
}
