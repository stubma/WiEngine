package com.wiyun.engine.box2d;

import com.wiyun.engine.BaseObject;
import com.wiyun.engine.box2d.common.Transform;
import com.wiyun.engine.types.WYColor3F;
import com.wiyun.engine.types.WYPoint;

/**
 * 调试渲染模式对象，可以通过Box2D得到这个对象，其用处只限于调试性的绘制物体。
 */
public class DebugDraw extends BaseObject {
	public static DebugDraw from(int pointer) {
		return pointer == 0 ? null : new DebugDraw(pointer);
	}

	protected DebugDraw() {
	}

	protected DebugDraw(int pointer) {
		super(pointer);
	}
	
	/**
	 * Draw a closed polygon provided in CCW order.
	 */
	public native void drawPolygon(WYPoint[] vertices, WYColor3F color);

	/**
	 * Draw a solid closed polygon provided in CCW order.
	 */
	public native void drawSolidPolygon(WYPoint[] vertices, WYColor3F color);

	/**
	 * Draw a circle.
	 */
	public native void drawCircle(WYPoint center, float radius, WYColor3F color);
	
	/**
	 * Draw a solid circle.
	 */
	public native void drawSolidCircle(WYPoint center, float radius, WYPoint axis, WYColor3F color);
	
	/**
	 * Draw a line segment.
	 */
	public native void drawSegment(WYPoint p1, WYPoint p2, WYColor3F color);

	/**
	 * Draw a transform. Choose your own length scale.
	 */
	public native void drawTransform(Transform xf);

	/**
	 * Draw a point
	 */
	public native void drawPoint(WYPoint p, float size, WYColor3F color);
}
