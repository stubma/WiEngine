package com.wiyun.engine.nodes;

import com.wiyun.engine.BaseWYObject;

/**
 * 定时调度器。 使用类似于Objective C的selector机制，用反射调用指定对象的某个方法。
 */
public class Scheduler extends BaseWYObject {
	/**
	 * 得到时间缩放比例
	 * 
	 * @return 时间缩放比例
	 */
	public native float getTimeScale();

	/**
	 * 设置时间缩放比例，假如原本是2秒后执行的操作，时间缩放比例为2时，会在1秒后
	 * 就执行
	 * 
	 * @param timeScale 时间缩放比例
	 */
	public native void setTimeScale(float timeScale);

	private static Scheduler sInstance = null;

	/**
	 * 获得调度器的单实例
	 * 
	 * @return {@link Scheduler}
	 */
	public static Scheduler getInstance() {
		synchronized(Scheduler.class) {
			if(sInstance == null) {
				sInstance = new Scheduler();
			} else {
				sInstance.setPointer(nativeGetInstance());
			}
			return sInstance;
		}
	}

	private Scheduler() {
		nativeInit();
	}
	
	private native static int nativeGetInstance();
	
	private native void nativeInit();

	/**
	 * 对一个Timer进行调度
	 * 
	 * @param t {@link Timer}
	 */
	public native void schedule(Timer t);

	/**
	 * 去掉对某个timer的调用
	 * 
	 * param t {@link Timer}
	 */
	public native void unschedule(Timer t);
}