package com.wiyun.engine.types;

public class WYColor3F {
	public float r;
	public float g;
	public float b;
	
	public static WYColor3F make(float r, float g, float b) {
		return new WYColor3F(r, g, b);
	}

	public WYColor3F() {
		r = g = b = 1.0f;
	}

	public WYColor3F(float rr, float gg, float bb) {
		r = rr;
		g = gg;
		b = bb;
	}

	public WYColor3F(WYColor3F c) {
		r = c.r;
		g = c.g;
		b = c.b;
	}
	
	public WYColor3F(WYColor4F c) {
		r = c.r;
		g = c.g;
		b = c.b;
	}

	public WYColor3F(WYColor4B c) {
		r = c.r / 0xFF;
		g = c.g / 0xFF;
		b = c.b / 0xFF;
	}

	public WYColor3F(WYColor3B c) {
		r = c.r / 0xFF;
		g = c.g / 0xFF;
		b = c.b / 0xFF;
	}

	public float[] glFormat() {
		return new float[] {
				r, g, b
		};
	}

	@Override
	public String toString() {
		return "< r=" + r + ", g=" + g + ", b=" + b;
	}
}
