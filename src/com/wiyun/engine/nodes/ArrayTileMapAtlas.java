package com.wiyun.engine.nodes;

import com.wiyun.engine.opengl.Texture2D;

/**
 * {@link TileMapAtlas}的子类，实现了一个通过整型数组生成瓦片地图的机制。
 * 如果一个图片集包含3x3个单幅图片，则整数4会映射到第二行第二列的图片。因为
 * 4 / 3 = 1, 4 % 3 = 1。
 */
public class ArrayTileMapAtlas extends TileMapAtlas {
	/**
	 * 创建数组式瓦片地图
	 * 
	 * @param texture {@link Texture2D}
	 * @param tileWidth 单个瓦片图片的宽度
	 * @param tileHeight 单个瓦片图片的高度
	 * @param xTiles x方向瓦片个数
	 * @param yTiles y方向瓦片个数
	 * @return 瓦片地图实例
	 */
	public static ArrayTileMapAtlas make(Texture2D texture, int tileWidth, int tileHeight, int xTiles, int yTiles) {
		return new ArrayTileMapAtlas(texture, tileWidth, tileHeight, xTiles, yTiles);
	}
	
	/**
	 * 构造函数
	 * 
	 * @param texture {@link Texture2D}
	 * @param tileWidth 单个瓦片图片的宽度
	 * @param tileHeight 单个瓦片图片的高度
	 * @param xTiles x方向瓦片个数
	 * @param yTiles y方向瓦片个数
	 */
	protected ArrayTileMapAtlas(Texture2D texture, int tileWidth, int tileHeight, int xTiles, int yTiles) {
		nativeInit(texture, tileWidth, tileHeight, xTiles, yTiles);
    }
	
    /**
     * 从底层指针获得一个ArrayTileMapAtlas的Java对象
     * 
     * @param pointer 底层指针
     * @return {@link ArrayTileMapAtlas}
     */
    public static ArrayTileMapAtlas from(int pointer) {
    	return pointer == 0 ? null : new ArrayTileMapAtlas(pointer);
    }
    
	protected ArrayTileMapAtlas(int pointer) {
		super(pointer);
	}
	
	private native void nativeInit(Texture2D texture, int tileWidth, int tileHeight, int xTiles, int yTiles);
	
	public native void setTiles(int[][] tiles);
}
