package com.wiyun.engine.types;

public class WYColor3B {
	public int r;
	public int g;
	public int b;
	
	public static WYColor3B make(int r, int g, int b) {
		return new WYColor3B(r, g, b);
	}

	public WYColor3B() {
		r = 0xff;
		g = 0xff;
		b = 0xff;
	}

	public WYColor3B(int rr, int gg, int bb) {
		r = rr;
		g = gg;
		b = bb;
	}

	public byte[] glFormat() {
		return new byte[] {
				(byte)r, (byte)g, (byte)b
		};
	}
	
	public WYColor4F toColor4F() {
		return new WYColor4F(r / 255f, g / 255f, b / 255f, 1f);
	}

	@Override
	public String toString() {
		return "< r=" + r + ", g=" + g + ", b=" + b + " >";
	}
}
