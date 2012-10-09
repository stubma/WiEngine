package com.wiyun.engine.box2d;

/**
 * Box2D的一些全局参数
 */
public class Settings {
	/**
	 * The radius of the polygon/edge shape skin. This should not be modified. Making
	 * this smaller means polygons will have an insufficient buffer for continuous collision.
	 * Making it larger may create artifacts for vertex collision.
	 */
	public static final float linearSlop = 0.005f;
}
