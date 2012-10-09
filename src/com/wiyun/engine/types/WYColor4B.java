package com.wiyun.engine.types;

public class WYColor4B {
	/**
	 * byte count of GL format
	 */
	public static final int GL_SIZE = 4;

	public int r;
	public int g;
	public int b;
	public int a;
	
	public static WYColor4B make(int r, int g, int b, int a) {
		return new WYColor4B(r, g, b, a);
	}

	public WYColor4B() {
		r = g = b = a = 0xff;
	}

	public WYColor4B(int rr, int gg, int bb, int aa) {
		r = rr;
		g = gg;
		b = bb;
		a = aa;
	}

	public byte[] glFormat() {
		return new byte[] {
				(byte)r, (byte)g, (byte)b, (byte)a
		};
	}

	public int androidColor() {
		return (a << 24) | (r << 16) | (g << 8) | b;
	}

	@Override
	public boolean equals(Object o) {
		if(o instanceof WYColor3B) {
			WYColor3B c = (WYColor3B)o;
			return r == c.r && g == c.g && b == c.b;
		} else if(o instanceof WYColor4B) {
			WYColor4B c = (WYColor4B)o;
			return r == c.r && g == c.g && b == c.b && a == c.b;
		} else if(o instanceof WYColor4F) {
			WYColor4F c = (WYColor4F)o;
			return r == (int)(c.r * 255) && g == (int)(c.g * 255) && b == (int)(c.b * 255) && a == (int)(c.a * 255);
		} else {
			return super.equals(o);
		}
	}

	@Override
	public String toString() {
		return "< r=" + r + ", g=" + g + ", b=" + b + ", a=" + a + " >";
	}
}
