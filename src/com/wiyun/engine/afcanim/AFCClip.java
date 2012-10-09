package com.wiyun.engine.afcanim;

import com.wiyun.engine.BaseWYObject;
import com.wiyun.engine.types.WYPoint;
import com.wiyun.engine.types.WYRect;
import com.wiyun.engine.types.WYSize;

/**
 * \if English
 * A clip in a frame
 * \else
 * 代表了一个帧中的分片
 * \endif
 */
public class AFCClip extends BaseWYObject {
	public static AFCClip from(int pointer) {
		return pointer == 0 ? null : new AFCClip(pointer);
	}
	
	protected AFCClip(int pointer) {
		super(pointer);
	}
	
	/**
	 * \if English
	 * Clip index in editor. However, some editor doesn't assign an index to
	 * clip, such as Motion Welder, SpriteX 3.9.4, etc., and the clip index is meaningless
	 * for those editors. Furthermore, if this clip is a mapped clip of external atlas,
	 * then index is also useless.
	 *
	 * \note
	 * If index is -1, then index field is useless for this clip
	 *
	 * @return clip index, returns -1 if index field is meaningless for this clip
	 * \else
	 * 分片在编辑器中的索引. 不过有些编辑器并不会对分片分配一个索引, 比如Motion Welder, SpriteX 3.9.4等,
	 * 那么对于这些编辑器, 这个字段没有意义. 此外, 如果这个分片是映射到了外部的图片集上, 那么索引字段
	 * 也无意义
	 *
	 * \note
	 * 也可能存在其它情况导致索引字段无意义, 总之如果返回的索引是-1, 则说明索引对该分片无意义
	 *
	 * @return 分片索引, 如果返回的是-1, 则说明索引字段对这个分片无意义
	 * \endif
	 */
	public native int getIndex();
	
	/**
	 * \if English
	 * Get type of clip
	 *
	 * @return type of clip
	 * \else
	 * 得到分片类型
	 *
	 * @return 分片类型
	 * \endif
	 */
	public native int getType();

	/**
	 * \if English
	 * Get clip center position in frame
	 *
	 * @return clip center position
	 * \else
	 * 得到分片中心在帧中的位置
	 *
	 * @return 分片中心在帧中的位置
	 * \endif
	 */
	public WYPoint getClipPos() {
		WYPoint p = WYPoint.makeZero();
		nativeGetClipPos(p);
		return p;
	}
	
	private native void nativeGetClipPos(WYPoint p);

	/**
	 * \if English
	 * Get image index of clip
	 *
	 * @return image index
	 * \else
	 * 得到分片所在图片集的索引
	 *
	 * @return 分片所在图片集的索引
	 * \endif
	 */
	public native int getImageIndex();
	
	/**
	 * \if English
	 * Get rect of image, only valid if clip type is \c AFC_CLIP_IMAGE
	 * 
	 * @return {@link WYRect} of image
	 * \else
	 * 得到分片图片在图片集的矩形, 仅对类型\c AFC_CLIP_IMAGE有效
	 * 
	 * @return {@link WYRect}
	 * \endif
	 */
	public WYRect getImageRect() {
		WYRect r = WYRect.makeZero();
		nativeGetImageRect(r);
		return r;
	}
	
	private native void nativeGetImageRect(WYRect r);
	
	/**
	 * \if English
	 * Is image clip flipped in x axis, only valid if clip type is \c AFC_CLIP_IMAGE
	 * 
	 * @return true means image clip is flipped in x axis
	 * \else
	 * 图片分片是否进行x轴翻转, 仅对类型\c AFC_CLIP_IMAGE有效
	 * 
	 * @return true表示图片分片是在x轴翻转的
	 * \endif
	 */
	public native boolean isImageFlipX();
	
	/**
	 * \if English
	 * Return rotation degree of image clip, positive value means clockwise
	 * 
	 * @return degree of rotation
	 * \else
	 * 返回分片的旋转角度, 正值表示顺时针
	 * 
	 * @return 旋转角度
	 * \endif
	 */
	public native float getImageRotation();
	
	/**
	 * \if English
	 * Get fill color of ellipse, only valid if clip type is \c AFC_CLIP_ELLIPSE
	 * 
	 * @return fill color ellipse, in 0xaarrggbb format
	 * \else
	 * 得到椭圆的填充色, 仅对分片类型\c AFC_CLIP_ELLIPSE有效
	 * 
	 * @return 椭圆的填充色, 0xaarrggbb格式
	 * \endif
	 */
	public native int getEllipseColor();
	
	/**
	 * \if English
	 * Get size of ellipse, only valid if clip type is \c AFC_CLIP_ELLIPSE
	 * 
	 * @return {@link WYSize}
	 * \else
	 * 得到椭圆的大小, 仅对分片类型\c AFC_CLIP_ELLIPSE有效
	 * 
	 * @return {@link WYSize}
	 * \endif
	 */
	public WYSize getEllipseSize() {
		WYSize s = WYSize.makeZero();
		nativeGetEllipseSize(s);
		return s;
	}

	private native void nativeGetEllipseSize(WYSize s);
	
	/**
	 * \if English
	 * Get start angle of ellipse, only valid if clip type is \c AFC_CLIP_ELLIPSE
	 * 
	 * @return start angle
	 * \else
	 * 得到椭圆的起始角度, 仅对分片类型\c AFC_CLIP_ELLIPSE有效
	 * 
	 * @return 起始角度
	 * \endif
	 */
	public native float getEllipseStartAngle();
	
	/**
	 * \if English
	 * Get end angle of ellipse, only valid if clip type is \c AFC_CLIP_ELLIPSE
	 * 
	 * @return end angle
	 * \else
	 * 得到椭圆的结束角度, 仅对分片类型\c AFC_CLIP_ELLIPSE有效
	 * 
	 * @return 结束角度
	 * \endif
	 */
	public native float getEllipseEndAngle();
	
	/**
	 * \if English
	 * Get color of line, only valid if clip type is \c AFC_CLIP_LINE
	 * 
	 * @return color of line, in 0xaarrggbb format
	 * \else
	 * 得到线段的颜色, 仅对分片类型\c AFC_CLIP_LINE有效
	 * 
	 * @return 线段的颜色, 0xaarrggbb格式
	 * \endif
	 */
	public native int getLineColor();
	
	/**
	 * \if English
	 * Get end point of line, only valid if clip type is \c AFC_CLIP_LINE
	 * 
	 * @return {@link WYPoint}
	 * \else
	 * 得到线段的结束点, 仅对分片类型\c AFC_CLIP_LINE有效
	 * 
	 * @return {@link WYPoint}
	 * \endif
	 */
	public WYPoint getLineEndPoint() {
		WYPoint p = WYPoint.makeZero();
		nativeGetLineEndPoint(p);
		return p;
	}
	
	private native void nativeGetLineEndPoint(WYPoint p);
	
	/**
	 * \if English
	 * Get color of rectangle, only valid if clip type is \c AFC_CLIP_RECT
	 * 
	 * @return color of rectangle, in 0xaarrggbb format
	 * \else
	 * 得到矩形的颜色, 仅对分片类型\c AFC_CLIP_RECT有效
	 * 
	 * @return 矩形的颜色, 0xaarrggbb格式
	 * \endif
	 */
	public native int getRectangleColor();
	
	/**
	 * \if English
	 * Get size of rectangle clip, only valid if clip type is \c AFC_CLIP_RECT
	 * 
	 * @return {@link WYSize}
	 * \else
	 * 得到矩形分片的大小, 仅对分片类型\c AFC_CLIP_RECT有效
	 * 
	 * @return {@link WYSize}
	 * \endif
	 */
	public WYSize getRectangleSize() {
		WYSize s = WYSize.makeZero();
		nativeGetRectangleSize(s);
		return s;
	}
	
	private native void nativeGetRectangleSize(WYSize s);
	
	/**
	 * \if English
	 * Get color of round rectangle, only valid if clip type is \c AFC_CLIP_ROUNDRECT
	 * 
	 * @return color of round rectangle, in 0xaarrggbb format
	 * \else
	 * 得到圆角矩形的颜色, 仅对分片类型\c AFC_CLIP_ROUNDRECT有效
	 * 
	 * @return 圆角矩形的颜色, 0xaarrggbb格式
	 * \endif
	 */
	public native int getRoundRectColor();
	
	/**
	 * \if English
	 * Get size of round rectangle clip, only valid if clip type is \c AFC_CLIP_ROUNDRECT
	 * 
	 * @return {@link WYSize}
	 * \else
	 * 得到圆角矩形分片的大小, 仅对分片类型\c AFC_CLIP_ROUNDRECT有效
	 * 
	 * @return {@link WYSize}
	 * \endif
	 */
	public WYSize getRoundRectSize() {
		WYSize s = WYSize.makeZero();
		nativeGetRoundRectSize(s);
		return s;
	}
	
	private native void nativeGetRoundRectSize(WYSize s);
	
	/**
	 * \if English
	 * Get arc width of round rectangle corner, only valid if clip type is \c AFC_CLIP_ROUNDRECT
	 * 
	 * @return arc width of round rectangle corner
	 * \else
	 * 得到圆角矩形边角的弧宽, 仅对分片类型\c AFC_CLIP_ROUNDRECT有效
	 * 
	 * @return 圆角矩形边角的弧宽
	 * \endif
	 */
	public native float getRoundRectArcWidth();
	
	/**
	 * \if English
	 * Get arc height of round rectangle corner, only valid if clip type is \c AFC_CLIP_ROUNDRECT
	 * 
	 * @return arc height of round rectangle corner
	 * \else
	 * 得到圆角矩形边角的弧高, 仅对分片类型\c AFC_CLIP_ROUNDRECT有效
	 * 
	 * @return 圆角矩形边角的弧高
	 * \endif
	 */
	public native float getRoundRectArcHeight();
	
	/**
	 * \if English
	 * Get size of collision rectangle clip, only valid if clip type is \c AFC_CLIP_COLLISION_RECT
	 * 
	 * @return {@link WYSize}
	 * \else
	 * 得到碰撞矩形分片的大小, 仅对分片类型\c AFC_CLIP_COLLISION_RECT有效
	 * 
	 * @return {@link WYSize}
	 * \endif
	 */
	public WYSize getCollisionRectSize() {
		WYSize s = WYSize.makeZero();
		nativeGetCollisionRectSize(s);
		return s;
	}
	
	private native void nativeGetCollisionRectSize(WYSize s);
	
	/**
	 * \if English
	 * Get collision rect, only valid if clip type is \c AFC_CLIP_COLLISION_RECT
	 * 
	 * @return {@link WYRect}
	 * \else
	 * 得到碰撞矩形分片的大小, 仅对分片类型\c AFC_CLIP_COLLISION_RECT有效
	 * 
	 * @return {@link WYRect}
	 * \endif
	 */
	public WYRect getCollisionRect() {
		WYSize s = getCollisionRectSize();
		WYPoint c = getClipPos();
		return WYRect.make(c.x - s.width / 2, c.y - s.height / 2, s.width, s.height);
	}
	
	/**
	 * \if English
	 * Get second point of triangle, only valid if clip type is \c AFC_CLIP_TRIANGLE
	 * 
	 * @return {@link WYPoint}
	 * \else
	 * 得到三角分片的第二个点, 仅对分片类型\c AFC_CLIP_TRIANGLE有效
	 * 
	 * @return {@link WYPoint}
	 * \endif
	 */
	public WYPoint getTrianglePoint2() {
		WYPoint p = WYPoint.makeZero();
		nativeGetTrianglePoint2(p);
		return p;
	}
	
	/**
	 * \if English
	 * Get third point of triangle, only valid if clip type is \c AFC_CLIP_TRIANGLE
	 * 
	 * @return {@link WYPoint}
	 * \else
	 * 得到三角分片的第三个点, 仅对分片类型\c AFC_CLIP_TRIANGLE有效
	 * 
	 * @return {@link WYPoint}
	 * \endif
	 */
	public WYPoint getTrianglePoint3() {
		WYPoint p = WYPoint.makeZero();
		nativeGetTrianglePoint3(p);
		return p;
	}
	
	private native void nativeGetTrianglePoint2(WYPoint p);	
	private native void nativeGetTrianglePoint3(WYPoint p);	
}
