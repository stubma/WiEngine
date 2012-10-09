package com.wiyun.engine.events;

/**
 * 加速器事件处理器接口 
 */
public interface IAccelerometerHandler {
	/**
	 * 加速事件的回调. 这里的加速器值分成x, y, z三个维度, 它们的取值采用iOS的规则. Android和iOS
	 * 平台对加速器事件的参数主要有两个差异:
	 * 1. 它们的符号是完全相反的
	 * 2. iOS以1表示一个重力加速度, 而Android以9.81代表一个重力加速度
	 * 因此在Android平台上得到值需要除以9.81并翻转符号.
	 *
	 * 之所以使用iOS规则表示加速器事件, 是因为其取值与OpenGL坐标系相符合.
	 *
	 * @param accelX x轴加速值
	 * @param accelY y轴加速值
	 * @param accelZ z轴加速值
	 */
	public void wyAccelerometerChanged(float accelX, float accelY, float accelZ);
}
