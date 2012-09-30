/*
 * Copyright (c) 2010 WiYun Inc.
 * Author: luma(stubma@gmail.com)
 *
 * For all entities this program is free software; you can redistribute
 * it and/or modify it under the terms of the 'WiEngine' license with
 * the additional provision that 'WiEngine' must be credited in a manner
 * that can be be observed by end users, for example, in the credits or during
 * start up. (please find WiEngine logo in sdk's logo folder)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
package com.wiyun.engine.events;

import android.content.Context;
import android.hardware.Sensor;
import android.hardware.SensorEvent;
import android.hardware.SensorEventListener;
import android.hardware.SensorManager;
import android.os.Looper;

import com.wiyun.engine.nodes.Director;

/**
 * 加速器值分成x, y, z三个维度, 它们的取值采用iOS的规则. Android和iOS
 * 平台对加速器事件的参数主要有两个差异:
 * 1. 它们的符号是完全相反的
 * 2. iOS以1表示一个重力加速度, 而Android以9.81代表一个重力加速度
 * 因此在Android平台上得到的值需要除以9.81并翻转符号.
 */
public class Accelerometer implements SensorEventListener {
	private SensorManager mSM;
	private Sensor mAccelerometer;
	
	// flag indicating sensor event listener is registered
	private boolean mSensorRegistered;
	
	// singleton
	private static Accelerometer sInstance;
	
	public static Accelerometer getInstance() {
		if(sInstance == null)
			sInstance = new Accelerometer();
		return sInstance;
	}
	
	private Accelerometer() {
		// need prepare looper because it is created in gl thread
		if(Looper.getMainLooper() != Looper.myLooper())
			Looper.prepare();
		
		// get the SensorManager from the Activity
		mSM = (SensorManager)Director.getInstance().getContext().getSystemService(Context.SENSOR_SERVICE);

		// if we have a SensorManager then get the accelerometer Sensor
		if(mSM != null)
			mAccelerometer = mSM.getDefaultSensor(Sensor.TYPE_ACCELEROMETER);
		else
			mAccelerometer = null;
	}
	
	private native boolean hasAccelHandlers();
	
	void checkAccelHandlers() {
		if(hasAccelHandlers()) {
			if(!mSensorRegistered)
				mSensorRegistered = mSM.registerListener(this, mAccelerometer, Director.getInstance().getAccelerometerDelay());
		} else {
			if(mSensorRegistered) {
				mSM.unregisterListener(this);
				mSensorRegistered = false;
			}
		}
	}
	
	public void updateAccelerometerDelay() {
		if(mSensorRegistered) {
			mSM.unregisterListener(this);
			mSensorRegistered = mSM.registerListener(this, mAccelerometer, Director.getInstance().getAccelerometerDelay());
		}
	}
	
	public native void accelerometerChanged(float accelX, float accelY, float accelZ);
	
	public void onAccuracyChanged(Sensor sensor, int accuracy) {
		// Override to process sensor accuracy changes (for any registered sensors).
	}

	public void onSensorChanged(SensorEvent event) {
		if(event.sensor.getType() == Sensor.TYPE_ACCELEROMETER) {
			accelerometerChanged(-event.values[0] / 9.81f, -event.values[1] / 9.81f, -event.values[2] / 9.81f);
		}
	}
}
