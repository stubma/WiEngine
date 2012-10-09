package com.wiyun.engine.afcanim;

/**
 * \if English
 * Constants used by AFC module
 * \else
 * AFC模块使用的一些常量
 * \endif
 */
public class AFCConstants {
	/**
	 * \if English
	 * clip is a image
	 * \else
	 * 分片是一个图片
	 * \endif
	 */
	public static final int AFC_CLIP_IMAGE = 0;
	
	/**
	 * \if English
	 * clip is a ellipse
	 * \else
	 * 分片是一个椭圆
	 * \endif
	 */
	public static final int AFC_CLIP_ELLIPSE = 1;
	
	/**
	 * \if English
	 * clip is a line
	 * \else
	 * 分片是一条线
	 * \endif
	 */
	public static final int AFC_CLIP_LINE = 2;
	
	/**
	 * \if English
	 * clip is a rectangle
	 * \else
	 * 分片是一个矩形
	 * \endif
	 */
	public static final int AFC_CLIP_RECT = 3;
	
	/**
	 * \if English
	 * clip is a round corner rectangle
	 * \else
	 * 分片是一个圆角矩形
	 * \endif
	 */
	public static final int AFC_CLIP_ROUNDRECT = 4;
	
	/**
	 * \if English
	 * clip is a collision rect. Collision rectangle only has size property, it
	 * can't have a fill color, etc.
	 * \else
	 * 分片是一个碰撞矩形, 碰撞矩形和矩形的区别是: 碰撞矩形只是一个大小, 没有填充色等信息
	 * \endif
	 */
	public static final int AFC_CLIP_COLLISION_RECT = 5;
	
	/**
	 * \if English
	 * clip is a reference point
	 * \else
	 * 分片是一个点
	 * \endif
	 */
	public static final int AFC_CLIP_POINT = 6;
	
	/**
	 * \if English
	 * clip is a triangle
	 * \else
	 * 分片是一个三角形
	 * \endif
	 */
	public static final int AFC_CLIP_TRIANGLE = 7;
}
