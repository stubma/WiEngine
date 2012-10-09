package com.wiyun.engine.nodes;

import com.wiyun.engine.opengl.Texture2D;
import com.wiyun.engine.types.WYRect;

/**
 * \par
 * 对一个贴图进行平铺, 可以用来做游戏背景。wyTiledSprite支持在水平和垂直方向进行贴图平铺，
 * 适合于构建平铺式背景。并且还提供了滚动和fling的方法，因此也适合于构建超大重复滚轴式背景。
 * wyTiledSprite的初始大小是和SurfaceView的大小一样.
 *
 * \par
 * 缺省情况下wyTiledSprite将在水平和垂直方向都平铺贴图，如果设置在两个方向上都不平铺，则
 * 贴图会居中显示。平铺的方向也会影响到滚动时的处理，如果只设置了水平平铺，则垂直方向上不会
 * 发生滚动，如果设置了垂直平铺，则水平方向上不会发生滚动，如果两个方向都设置了平铺，则两个
 * 方向都可以滚动。
 */
public class TiledSprite extends Node {
	public static TiledSprite make(Texture2D tex) {
		return new TiledSprite(tex);
	}
	
	public static TiledSprite from(int pointer) {
		return pointer == 0 ? null : new TiledSprite(pointer);
	}
	
    protected TiledSprite(int pointer) {
    	super(pointer);
    }
    
	protected TiledSprite() {
	}
	
	protected TiledSprite(Texture2D tex) {
		nativeInit(tex);
	}
	
    @Override
    protected void doNativeInit() {
    }
    
    private native void nativeInit(Texture2D tex);
    
	/**
	 * 得到是否垂直平铺标志
	 *
	 * @return true表示垂直方向进行平铺
	 */
	public native boolean isTileVertical();

	/**
	 * 得到是否水平平铺标志
	 *
	 * @return true表示水平方向进行平铺
	 */
	public native boolean isTileHorizontal();

	/**
	 * 设置平铺方向
	 *
	 * @param horizontal true表示水平方向进行平铺
	 * @param vertical true表示垂直方向进行平铺
	 */
	public native void setTileDirection(boolean horizontal, boolean vertical);

	/**
	 * 如果贴图代表了一个图片集，则可以设置要平铺的贴图在图片集中的矩形位置
	 *
	 * @param r 要平铺的贴图在图片集中的矩形位置，(x, y)代表贴图的左上角坐标
	 */
	public native void setTextureRect(WYRect r);

	/**
	 * 是否正在惯性移动中
	 *
	 * @return true表示正在惯性移动中
	 */
	public native boolean isFlinging();
	
	/**
	 * 设置最大的x方向偏移量
	 *
	 * @param max 最大x方向偏移量
	 */
	public native void setMaxOffsetX(float max);

	/**
	 * 得到最大x方向偏移量
	 *
	 * @return 最大x方向偏移量
	 */
	public native float getMaxOffsetX();

	/**
	 * 设置最小的x方向偏移量
	 *
	 * @param min 最小x方向偏移量
	 */
	public native void setMinOffsetX(float min);

	/**
	 * 得到最小x方向偏移量
	 *
	 * @return 最小x方向偏移量
	 */
	public native float getMinOffsetX();

	/**
	 * 设置最大的y方向偏移量
	 *
	 * @param max 最大y方向偏移量
	 */
	public native void setMaxOffsetY(float max);

	/**
	 * 得到最大y方向偏移量
	 *
	 * @return 最大y方向偏移量
	 */
	public native float getMaxOffsetY();

	/**
	 * 设置最小的y方向偏移量
	 *
	 * @param min 最小y方向偏移量
	 */
	public native void setMinOffsetY(float min);

	/**
	 * 得到最小y方向偏移量
	 *
	 * @return 最小y方向偏移量
	 */
	public native float getMinOffsetY();
	
	/**
	 * 设置X方向的偏移量，为正时相当于把贴图向左移动，为负时相当于向右移动
	 *
	 * @param offset 偏移量
	 */
	public native void setOffsetX(float offset);

	/**
	 * 设置Y方向的偏移量，为正时相当于把贴图向上移动，为负时相当于向下移动
	 *
	 * @param offset 偏移量
	 */
	public native void setOffsetY(float offset);

	/**
	 * 调整偏移量
	 *
	 * @param dx X偏移量的调整值，会添加到现有偏移量上
	 * @param dy Y偏移量的调整值，会添加到现有偏移量上
	 */
	public native void offsetBy(float dx, float dy);
	
	/**
	 * 中止fling，如果当前没有在fling，则不做任何事
	 */
	public native void stopFling();

	/**
	 * 开始fling, 如果当前正在fling，则不做任何事.
	 *
	 * @param velocityX x方向的fling速度, 如果没有设置水平平铺，则被忽略
	 * @param velocityY y方向的fling速度, 如果没有设置垂直平铺，则被忽略
	 */
	public native void fling(float velocityX, float velocityY);
	
	/**
	 * 设置是否在不平铺的方向上拉伸贴图, 比如贴图在水平方向上平铺, 垂直方向上不平铺,
	 * 则设置此标志为true可以让贴图在垂直方向上充满节点大小
	 *
	 * @param flag true表示在不平铺的方向上拉伸贴图
	 */
	public native void setStretch(boolean flag);

	/**
	 * 是否在不平铺的方向上拉伸贴图
	 *
	 * @return true表示在不平铺的方向上拉伸贴图
	 */
	public native boolean isStretch();
	
	/**
	 * 设置平铺的间隔
	 *
	 * @param x 水平方向间隔, 如果没有设置在水平方向上平铺则不起作用
	 * @param y 垂直方向间隔, 如果没有设置在水平方向上平铺则不起作用
	 */
	public native void setSpacing(float x, float y);

	/**
	 * 得到水平方向平铺间隔
	 *
	 * @return 水平方向平铺间隔
	 */
	public native float getSpacingX();

	/**
	 * 得到垂直方向平铺间隔
	 *
	 * @return 垂直方向平铺间隔
	 */
	public native float getSpacingY();
}
