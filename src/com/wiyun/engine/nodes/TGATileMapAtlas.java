package com.wiyun.engine.nodes;

import com.wiyun.engine.opengl.Texture2D;

/**
 * TGA格式的瓦片地图。通过把图片中象素的R值映射到瓦片图片集中，形成地图。 
 */
public class TGATileMapAtlas extends TileMapAtlas {
    /**
     * 创建瓦片地图
     * 
     * @param texture {@link Texture2D}
     * @param mapResId TGA文件资源id
     * @param tileWidth 单个瓦片图片的象素宽度
     * @param tileHeight 单个瓦片图片的象素高度
     * @return 瓦片地图
     */
    public static TGATileMapAtlas make(Texture2D texture, int mapResId, int tileWidth, int tileHeight) {
    	return new TGATileMapAtlas(texture, mapResId, tileWidth, tileHeight);
    }
    
	/**
     * 构造函数
     * 
     * @param texture {@link Texture2D}
     * @param mapResId TGA文件资源id
     * @param tileWidth 单个瓦片图片的象素宽度
     * @param tileHeight 单个瓦片图片的象素高度
	 */
	protected TGATileMapAtlas(Texture2D texture, int mapResId, int tileWidth, int tileHeight) {
		nativeInit(texture, mapResId, tileWidth, tileHeight);
	}
	
    /**
     * 从底层指针获得一个TGATileMapAtlas的Java对象
     * 
     * @param pointer 底层指针
     * @return {@link TGATileMapAtlas}
     */
    public static TGATileMapAtlas from(int pointer) {
    	return pointer == 0 ? null : new TGATileMapAtlas(pointer);
    }
    
	protected TGATileMapAtlas(int pointer) {
		super(pointer);
	}
	
	private native void nativeInit(Texture2D texture, int mapResId, int tileWidth, int tileHeight);
}
