package com.wiyun.engine.types;

public class Mat4 {
	public float mat[];
	
	protected Mat4() {
		mat = new float[16];
	}
	
	public static Mat4 make() {
		return new Mat4();
	}
}
