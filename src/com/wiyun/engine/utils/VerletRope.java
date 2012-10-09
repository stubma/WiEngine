package com.wiyun.engine.utils;

import com.wiyun.engine.BaseWYObject;
import com.wiyun.engine.nodes.Node;
import com.wiyun.engine.opengl.Texture2D;
import com.wiyun.engine.types.WYColor3B;
import com.wiyun.engine.types.WYColor4B;
import com.wiyun.engine.types.WYPoint;

/**
 * \if English
 * Rope simulated by verlet integral
 * \else
 * 使用Verlet积分模拟一条绳子, 可以传入一个贴图对象，以这个贴图渲染绳子。这个类需要一般需要
 * 结合物理引擎使用。
 * \endif
 */
public class VerletRope extends BaseWYObject {
	/**
	 * 构造函数
	 *
	 * @param a 绳子起始点a
	 * @param b 绳子起始点b
	 * @param tex \link Texture2D Texture2D\endlink
	 */
	public static VerletRope make(WYPoint a, WYPoint b, Texture2D tex) {
		return make(a, b, tex, 0);
	}
	
	/**
	 * 构造函数
	 *
	 * @param a 绳子起始点a
	 * @param b 绳子起始点b
	 * @param tex \link Texture2D Texture2D\endlink
	 * @param length 绳子长度，缺省为0，也就是以a和b之间的距离为长度
	 */
	public static VerletRope make(WYPoint a, WYPoint b, Texture2D tex, int length) {
		return new VerletRope(a, b, tex, length);
	}
	
	public static VerletRope from(int pointer) {
		return pointer == 0 ? null : new VerletRope(pointer);
	}
	
	protected VerletRope(WYPoint a, WYPoint b, Texture2D tex, int length) {
		nativeInit(a, b, tex, length);
	}
	
	protected VerletRope(int pointer) {
		super(pointer);
	}
	
	private native void nativeInit(WYPoint a, WYPoint b, Texture2D tex, int length);
	
	/**
	 * 重置这条绳子
	 *
	 * @param a 新的起点
	 * @param b 新的终点
	 */
	public native void reset(WYPoint a, WYPoint b);

	/**
	 * 更新绳子的形态
	 *
	 * @param a 新的起点
	 * @param b 新的终点
	 * @param dt 过去的时间
	 */
	public native void update(WYPoint a, WYPoint b, float dt);

	/**
	 * \if English
	 * Render rope
	 *
	 * @param parent the node who invoked draw method
	 * \else
	 * 绘制绳子
	 *
	 * @param parent 调用draw方法的节点
	 * \endif
	 */
	public native void draw(Node parent);

	/**
	 * 获得所有的\link VerletStick VerletStick\endlink对象指针
	 *
	 * @return 包含所有\link VerletStick VerletStick对象\endlink底层指针的数组
	 */
	public native int[] getSticks();

	/**
	 * 得到指定位置处的\link VerletStick VerletStick\endlink 对象
	 *
	 * @return \link VerletStick VerletStick\endlink 对象, 如果index超出范围, 返回NULL
	 */
	public VerletStick getStickAt(int index) {
		return VerletStick.from(nativeGetStickAt(index));
	}
	
	private native int nativeGetStickAt(int index);

	/**
	 * 得到\link VerletStick VerletStick\endlink 的个数
	 *
	 * @return \link VerletStick VerletStick\endlink 的个数
	 */
	public native int getStickCount();

	/**
	 * 获得所有的点, 没两个相邻的点就构成了一个\link VerletStick VerletStick\endlink
	 *
	 * @return 包含所有\link VerletPoint VerletPoint对象\endlink的底层指针的数组
	 */
	public native int[] getPoints();

	/**
	 * 得到指定位置处的\link VerletPoint VerletPoint\endlink 对象
	 *
	 * @return \link VerletPoint VerletPoint\endlink 对象, 如果index超出范围, 返回NULL
	 */
	public VerletPoint getPointAt(int index) {
		return VerletPoint.from(nativeGetPointAt(index));
	}
	
	private native int nativeGetPointAt(int index);

	/**
	 * 获得点数
	 *
	 * @return 点数
	 */
	public native int getPointCount();

	/**
	 * 得到绳子的当前长度，有可能比实际长度稍大
	 *
	 * @return 当前长度
	 */
	public native float getCurrentLength();

	/**
	 * 光线测试
	 *
	 * @param s 光线的起始点
	 * @param e 光线的结束点
	 * @return 如果光线和某个\link VerletStick VerletStick\endlink 相交,
	 * 		则返回这个\link VerletStick VerletStick\endlink 的索引, 如果没有
	 * 		相交, 返回-1. 如果有两个相交, 则只会返回第一个\link VerletStick VerletStick\endlink
	 * 		的索引.
	 */
	public native int rayCast(WYPoint s, WYPoint e);

	/**
	 * 得到当前颜色
	 *
	 * @return \link WYColor3B WYColor3B\endlink 结构
	 */
	public WYColor3B getColor() {
		WYColor3B c = new WYColor3B();
		nativeGetColor(c);
		return c;
	}
	
	private native void nativeGetColor(WYColor3B c);

	/**
	 * 设置渲染颜色
	 *
	 * @param color \link WYColor3B WYColor3B\endlink 结构
	 */
	public native void setColor(WYColor3B color);

	/**
	 * 设置颜色
	 *
	 * @param color \link WYColor4B WYColor4B结构\endlink
	 */
	public native void setColor(WYColor4B color);

	/**
	 * 得到当前alpha值
	 *
	 * @return alpha值
	 */
	public native int getAlpha();

	/**
	 * 设置alpha值
	 *
	 * @param alpha alpha值
	 */
	public native void setAlpha(int alpha);

	/**
	 * 获得绳子的原始长度，原始长度是绳子创建时的长度，但是绳子可能会有一定的形变导致当前
	 * 长度不等于原始长度
	 *
	 * @return 原始长度
	 */
	public native float getLength();

	/**
	 * 以指定的点索引范围，获得一条绳子的部分，这个部分生成一个新的绳子实例.
	 * 如果指定的索引范围不合法，则返回NULL
	 *
	 * @param startPoint 新绳子的起始点索引
	 * @param endPoint 新绳子的结束点索引, 新绳子包含结束点. 结束点必须比startPoint要大
	 * @return \link VerletRope VerletRope\endlink 对象，已经被autoRelease
	 */
	public VerletRope subRope(int startPoint, int endPoint) {
		return VerletRope.from(nativeSubRope(startPoint, endPoint));
	}
	
	private native int nativeSubRope(int startPoint, int endPoint);

	/**
	 * 检查绳子的当前长度是否已经超过了最大长度
	 *
	 * @return true表示绳子的当前长度已经超过了最大长度, 绳子处于被拉伸状态
	 */
	public native boolean isStretched();

	/**
	 * 动态修改绳子长度
	 *
	 * @param delta 修改值，正值表示加长绳子，负值表示缩短绳子
	 */
	public native void changeLength(float delta);
}
