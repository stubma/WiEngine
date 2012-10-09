package com.wiyun.engine.box2d.common;

import com.wiyun.engine.types.WYPoint;

public class Matrix22 {
	public float col1X;
	public float col1Y;
	public float col2X;
	public float col2Y;
	
	public static Matrix22 makeZero() {
		return new Matrix22(0, 0, 0, 0);
	}
	
	public static Matrix22 make(float col1X, float col1Y, float col2X, float col2Y) {
		return new Matrix22(col1X, col1Y, col2X, col2Y);
	}
	
	protected Matrix22(float col1X, float col1Y, float col2X, float col2Y) {
		this.col1X = col1X;
		this.col1Y = col1Y;
		this.col2X = col2X;
		this.col2Y = col2Y;
	}
	
	public void set(float angle) {
		float c = (float)Math.cos(angle);
		float s = (float)Math.sin(angle);
		col1X = c; 
		col2X = -s;
		col1Y = s;
		col2Y = c;
	}
	
	public WYPoint mul(WYPoint v) {
		return WYPoint.make(col1X * v.x + col2X * v.y, col1Y * v.x + col2Y * v.y);
	}
}
