package com.wiyun.engine.nodes;

import com.wiyun.engine.BaseWYObject;
import com.wiyun.engine.utils.TargetSelector;

/**
 * 定时器的封装
 */
public class Timer extends BaseWYObject {
	/**
	 * 创建一个调度器timer
	 * 
	 * @param target 需要触发的方法所属的对象
	 * @param selector 方法字符串，这里有一个特殊要求，即方法的第一个参数必须是float，表示从上一次调用
	 * 		到现在过去的时间。
	 */
	public Timer(Object target, String selector) {
		this(target, selector, 0f);
	}
	
	/**
	 * 创建一个调度器timer
	 * 
	 * @param target 需要触发的方法所属的对象
	 * @param selector 方法字符串，这里有一个特殊要求，即方法的第一个参数必须是float，表示从上一次调用
	 * 		到现在过去的时间。
	 * @param interval 触发时间间隔，为0表示每帧都运行
	 */
	public Timer(Object target, String selector, float interval) {
		this(new TargetSelector(target, selector, new Object[] { 0f }), interval);
	}

	/**
	 * 创建一个调度器timer
	 * 
	 * @param selector 方法选择子对象，这里有一个特殊要求，即方法的第一个参数必须是float，表示从上一次调用
	 * 		到现在过去的时间。由于在创建selector时这个参数无法确定，因此传入0值就可以，调度器会自动维护的。
	 * @param interval 触发时间间隔，为0表示每帧都运行
	 */
	public Timer(TargetSelector selector, float interval) {
		nativeInit(selector, interval);
	}
	
	/**
	 * 创建一个调度器timer，按帧调用
	 * 
	 * @param selector 方法选择子对象，这里有一个特殊要求，即方法的第一个参数必须是float，表示从上一次调用
	 * 		到现在过去的时间。由于在创建selector时这个参数无法确定，因此传入0值就可以，调度器会自动维护的。
	 * @param frame 触发的帧间隔，如果为2，表示每2帧调用方法一次，必须大于0
	 */
	public Timer(TargetSelector selector, int frame) {
		nativeInit(selector, frame);
	}
	
	private native void nativeInit(TargetSelector selector, float interval);
	private native void nativeInit(TargetSelector selector, int frame);

	/**
	 * 设置间隔时间
	 * 
	 * @param i 间隔时间，为0表示每帧都运行
	 */
	public native void setInterval(float i);

	/**
	 * 获得当前的时间间隔
	 * 
	 * @return 当前时间间隔
	 */
	public native float getInterval();
	
	/**
	 * 设置帧调度间隔
	 * 
	 * @param frame 多少帧调用一次
	 */
	public native void setFrame(int frame);
	
	/**
	 * 得到帧调度间隔
	 * 
	 * @return 多少帧调用一次
	 */
	public native int getFrame();
	
	/**
	 * \if English
	 * Set trigger this timer only once or not
	 *
	 * \deprecated use \c setMaxInvocation(1) instead
	 * \else
	 * 设置此定时器是否只调用一次
	 *
	 * \deprecated 用\c setMaxInvocation(1)可以达到同样效果
	 * \endif
	 */
	public native void setOneShot(boolean flag);

	/**
	 * \if English
	 * Will this timer be trigger only once?
	 * \else
	 * 返回此定时器是否只调用一次
	 * \endif
	 */
	public native boolean isOneShot();
	
	/**
	 * \if English
	 * Set max invocation count of this timer. If you set to 1, then
	 * it is same as \c setOneShot(true). Zero means no limitation
	 * \else
	 * 设置这个定时器最大的触发次数, 设置成1和\c setOneShot(true)的作用是相同的.
	 * 0表示不限制触发次数
	 * \endif
	 */
	public native void setMaxInvocation(int max);

	/**
	 * \if English
	 * Get max invocation count of this timer. For a one shot timer, it returns 1.
	 * Zero means no limitation
	 * \else
	 * 得到定时器的最大触发次数, 对于one shot是true的定时器, 返回1. 0表示没有限制
	 * \endif
	 */
	public native int getMaxInvocation();

	/**
	 * \if English
	 * Get current invocation count
	 * \else
	 * 得到当前已经触发的次数
	 * \endif
	 */
	public native int getCurrentInvocationCount();

	/**
	 * 调用选择子指定的方法
	 * 
	 * @param delta 上一次调用到现在过去的时间
	 */
	public native void fire(float delta);
}