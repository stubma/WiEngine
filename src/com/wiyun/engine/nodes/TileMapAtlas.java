package com.wiyun.engine.nodes;

import com.wiyun.engine.opengl.Texture2D;
import com.wiyun.engine.types.WYGridSize;

/**
 * 瓦片地图抽象基类。 
 */
public abstract class TileMapAtlas extends AtlasNode {
	protected TileMapAtlas() {
	}
	
	protected TileMapAtlas(int pointer) {
		super(pointer);
	}
	
    /**
     * 创建瓦片地图
     * 
     * @param texture {@link Texture2D}
     * @param tileWidth 单个瓦片的象素宽度
     * @param tileHeight 单个瓦片的象素高度
     */
    protected TileMapAtlas(Texture2D texture, int tileWidth, int tileHeight) {
    }
    
    /**
     * 检查在指定行列位置是否有瓦片
     * 
     * @param x 行位置
     * @param y 列位置
     * @return true表示有，false表示该位置没有映射到任何瓦片图片上
     */
    public native boolean hasTileAt(int x, int y);
    
    /**
     * 得到水平方向上的瓦片数
     * 
     * @return 水平方向上的瓦片数
     */
    public native int getHorizontalTileCount();
    
    /**
     * 得到垂直方向上的瓦片数
     * 
     * @return 垂直方向上的瓦片数
     */
    public native int getVerticalTileCount();
    
    /**
     * 得到某个行列坐标上的原始瓦片值，瓦片值如何映射到瓦片图片由子类实现决定
     * 
     * @param x 行位置
     * @param y 列位置
     * @return 瓦片原始值
     */
    public native int tileValueAt(int x, int y);
    
    /**
     * returns a tile value from position x,y.
     * Tile value is an integer which should be mapped
     */
    public native final int getTile(int x, int y);
    
    /**
     * 得到某个行列坐标上的原始瓦片值
     */
    public final int getTile(WYGridSize pos) {
    	return getTile(pos.x, pos.y);
    }

    /**
     * 设置某个行列位置的瓦片值
     * 
     * @param tileValue 原始瓦片值，瓦片值如何映射到瓦片图片由子类实现决定
     * @param pos 行列坐标
     */
    public void setTile(int tileValue, WYGridSize pos) {
    	setTile(tileValue, pos.x, pos.y);
    }
    
    /**
     * 设置某个行列位置的瓦片值
     * 
     * @param tileValue 原始瓦片值，瓦片值如何映射到瓦片图片由子类实现决定
     * @param x 行坐标
     * @param y 列坐标
     */
    public native void setTile(int tileValue, int x, int y);
}
