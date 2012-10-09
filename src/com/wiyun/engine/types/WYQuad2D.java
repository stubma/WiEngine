package com.wiyun.engine.types;

/**
 * A 2D Quad. 8 floats
 */
public class WYQuad2D {
	public static final int GL_SIZE = 4 * 2 * 4;
	
	// bottom left
	public float bl_x, bl_y;
	
	// bottom right
	public float br_x, br_y;

	// top left
	public float tl_x, tl_y;
	
	// top right
	public float tr_x, tr_y;

	public WYQuad2D(float a, float b, float c, float d, float e, float f, float g, float h) {
		bl_x = a;
		bl_y = b;
		br_x = c;
		br_y = d;
		tl_x = e;
		tl_y = f;
		tr_x = g;
		tr_y = h;
	}

	public WYQuad2D() {
		this(new float[] {
				0, 0, 0, 0, 0, 0, 0, 0
		});
	}

	public WYQuad2D(float[] f) {
		this(f[0], f[1], f[2], f[3], f[4], f[5], f[6], f[7]);
	}

	public float[] glFormat() {
		return new float[] {
				bl_x, bl_y, br_x, br_y, tl_x, tl_y, tr_x, tr_y
		};
	}

	@Override
	public String toString() {
		return "CCQuad2: ( " + tl_x + ", " + tl_y + " " + tr_x + ", " + tr_y + " " + bl_x + ", " + bl_y + " " + br_x + ", " + br_y + " )";
	}
}
