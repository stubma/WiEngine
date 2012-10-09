package com.wiyun.engine.types;

public class WYColor4F {
	public float r;
	public float g;
	public float b;
	public float a;
	
	public static WYColor4F make(float r, float g, float b, float a) {
		return new WYColor4F(r, g, b, a);
	}

	public WYColor4F() {
		r = g = b = a = 1.0f;
	}

	public WYColor4F(float rr, float gg, float bb, float aa) {
		r = rr;
		g = gg;
		b = bb;
		a = aa;
	}

	public WYColor4F(WYColor4F c) {
		r = c.r;
		g = c.g;
		b = c.b;
		a = c.a;
	}

	public WYColor4F(WYColor4B c) {
		r = c.r / 0xFF;
		g = c.g / 0xFF;
		b = c.b / 0xFF;
		a = c.a / 0xFF;
	}

	public WYColor4F(WYColor3B c) {
		r = c.r / 0xFF;
		g = c.g / 0xFF;
		b = c.b / 0xFF;
		a = 1.0f;
	}

	public float[] glFormat() {
		return new float[] {
				r, g, b, a
		};
	}

	@Override
	public String toString() {
		return "< r=" + r + ", g=" + g + ", b=" + b + ", a=" + a + " >";
	}
}
