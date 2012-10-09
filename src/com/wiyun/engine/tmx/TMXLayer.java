package com.wiyun.engine.tmx;

import com.wiyun.engine.nodes.SpriteBatchNode;
import com.wiyun.engine.nodes.SpriteEx;
import com.wiyun.engine.types.WYColor3B;
import com.wiyun.engine.types.WYDimension;
import com.wiyun.engine.types.WYPoint;

/**
 * 代表TMX中的一层，包含了一个TextureAtlas对象。 
 */
public class TMXLayer extends SpriteBatchNode {
    /**
     * 从底层指针获得一个TMXLayer的Java对象
     * 
     * @param pointer 底层指针
     * @return {@link TMXLayer}
     */
    public static TMXLayer from(int pointer) {
    	return pointer == 0 ? null : new TMXLayer(pointer);
    }
    
	/**
	 * 构造函数
	 */
	protected TMXLayer(int pointer) {
		super(pointer);
	}
	
	/**
	 * 得到层水平方向上的瓦片个数
	 *
	 * @return 层水平方向上的瓦片个数
	 */
	public native int getLayerWidth();

	/**
	 * 得到层垂直方向上的瓦片个数
	 *
	 * @return 层垂直方向上的瓦片个数
	 */
	public native int getLayerHeight();

	/**
	 * 得到瓦片的像素宽度
	 *
	 * @return 瓦片的像素宽度
	 */
	public native int getTileWidth();

	/**
	 * 得到瓦片的像素高度
	 *
	 * @return 瓦片的像素高度
	 */
	public native int getTileHeight();
	
	/**
	 * 得到某个位置的瓦片id
	 * 
	 * @param x 行位置，从左往右数
	 * @param y 列位置，从上往下数
	 * @return 瓦片id
	 */
	public native int getGidAt(int x, int y);
	
	/**
	 * 得到该层所有的瓦片id数组
	 *
	 * @return 瓦片id数组, 数组的长度是layerWidth * layerHeight.
	 * 		如果想得到某行列的瓦片id, 位置的计算方式是: pos = x + layerWidth * y.
	 */
	public native int[] getGids();
	
	/**
	 * \if English
	 * returns the tile (SpriteEx) at a given a tile coordinate.
	 * The returned SpriteEx will be already added to the TMXLayer. Don't add it again.
	 * The SpriteEx can be treated like any other SpriteEx: rotated, scaled, translated, opacity, color, etc.
	 * You can remove either by calling:
	 * 		layer.removeChild(sprite, true);
	 * 	 or layer.removeTileAt(x, y);
	 *
	 * Tag of returned sprite is set to x + y * layerWidth, don't modify it.
	 *
	 * @param x x coordinate of tile
	 * @param y y coordinate of tile
	 * @return \link SpriteEx SpriteEx\endlink object, or NULL if no tile at location
	 * \else
	 * 得到某个瓦片位置的SpriteEx对象, 并且被加到了TMXLayer中. 返回的对象可以进行普通的旋转, 放缩, 移动,
	 * 透明度和颜色等操作. 你可以通过removeTileAt或者removeChild方法删除掉它. 返回的sprite的tag被设置成了
	 * x + y * layerWidth, 不要修改这个tag否则可能造成程序逻辑混乱.
	 *
	 * 对于比较大的地图, 比如100x100, 如果预先创建这些sprite, 则最多可能有10000个, 这在资源上也是不太好的. 因此
	 * 返回的sprite实际上是即时创建的, 如果不需要使用的时候可以考虑删除掉. 删掉sprite的时候可以选择是否保留瓦片.
	 *
	 * @param x 行位置，从左往右数
	 * @param y 列位置，从上往下数
	 * @return \link SpriteEx SpriteEx\endlink 对象, 如果瓦片坐标处没有瓦片图片, 则返回NULL
	 * \endif
	 */
	public SpriteEx tileAt(int x, int y) {
		return SpriteEx.from(nativeTileAt(x, y));
	}
	
	private native int nativeTileAt(int x, int y);
	
	/**
	 * \if English
	 * Remove a tile from a sprite which is got from \c tileAt method. If the sprite
	 * is not a tile sprite, do nothing
	 *
	 * @param sprite sprite which is got from \c tileAt
	 * \else
	 * 通过\link wySpriteEx wySpriteEx\endlink对象删除一个瓦片, 这个sprite对象必须是
	 * 通过\c tileAt方法得到的, 如果不是, 则这个方法不做任何事
	 *
	 * @param sprite 从\c tileAt方法得到的瓦片精灵对象
	 * \endif
	 */
	public native void removeTile(SpriteEx sprite);
	
	/**
	 * 删除某行某列的瓦片
	 * 
	 * @param x 行位置，从左往右数
	 * @param y 列位置，从上往下数
	 */
	public native void removeTileAt(int x, int y);
	
	/**
	 * 在指定行列位置设置瓦片id, 如果指定位置上已经存在瓦片, 则这个方法
	 * 和updateTileAt的功能相同
	 *
	 * @param gid 瓦片id
	 * @param x 行位置，从左往右数
	 * @param y 列位置，从上往下数
	 */
	public native void setTileAt(int gid, int x, int y);
	
	/**
	 * 修改某行某列的瓦片id
	 * 
	 * @param gid 新瓦片id
	 * @param x 行位置，从左往右数
	 * @param y 列位置，从上往下数
	 */
	public native void updateTileAt(int gid, int x, int y);
	
	/**
	 * 得到这个层的属性
	 * 
	 * @param key 属性关键字
	 * @return 属性值
	 */
	public native String getProperty(String key);

	/**
	 * 根据瓦片坐标, 得到这个瓦片的左下角像素坐标, 该坐标是以layer左下角为原点的
	 *
	 * @param x 行位置
	 * @param y 列位置
	 * @return 瓦片相对于layer左下角的左下角像素坐标
	 */
	public WYPoint getPositionAt(int x, int y) {
		WYPoint p = WYPoint.makeZero();
		nativeGetPositionAt(x, y, p);
		return p;
	}

	private native void nativeGetPositionAt(int x, int y, WYPoint p);
	
	/**
	 * 根据一个相对于节点自身的坐标, 找到对应的瓦片坐标
	 *
	 * @param x x坐标, 以TMX layer的左下角为原点
	 * @param y y坐标, 以TMX layer的左下角为原点
	 * @return 瓦片坐标, 以一个\link WYDimension WYDimension\endlink 的形式返回, 如果点击位置处没有对应的瓦片,
	 * 		则会返回(-1, -1)
	 */
	public WYDimension getTileCoordinateAt(float x, float y) {
		WYDimension d = WYDimension.makeZero();
		nativeGetTileCoordinateAt(x, y, d);
		return d;
	}

	private native void nativeGetTileCoordinateAt(float x, float y, WYDimension d);
	
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
}
