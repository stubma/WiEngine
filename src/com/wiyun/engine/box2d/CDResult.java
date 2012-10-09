package com.wiyun.engine.box2d;

import com.wiyun.engine.types.WYPoint;

/**
 * \if English
 * Result of collision detection
 * \else
 * 碰撞检测的结果
 * \endif
 */
public class CDResult {
	/**
	 * \if English
	 * collision point count
	 * \else
	 * 碰撞点个数
	 * \endif
	 */
	public int pointCount = 0;

	/**
	 * \if English
	 * collision points, max is two and they are in world coordinates
	 * \else
	 * 碰撞点数组, 最多两个且用的是全局坐标
	 * \endif
	 */
	public WYPoint[] points = new WYPoint[] {
		WYPoint.makeZero(),
		WYPoint.makeZero()
	};

	/**
	 * \if English
	 * normal of collision, in world coordinate. It points from first node
	 * to second node.
	 * \else
	 * 碰撞方向, 以全局坐标表示. 总是从第一个节点指向第二个节点.
	 * \endif
	 */
	public WYPoint normal = WYPoint.makeZero();
	
	/**
	 * \if English
	 * reset result object to all zero
	 * \else
	 * 重置所有数据为0
	 * \endif
	 */
	public void clear() {
		pointCount = 0;
		points[0].x = points[0].y = points[1].x = points[1].y = 0;
		normal.x = normal.y = 0;
	}
	
	/**
	 * \if English
	 * Get float array of collision points
	 * 
	 * @return float array of collision points
	 * \else
	 * 得到碰撞点的浮点数组表示形式
	 * 
	 * @return 碰撞点的浮点数组
	 * \endif
	 */
	public float[] getPoints() {
		if(pointCount == 1)
			return new float[] { points[0].x, points[0].y };
		else if(pointCount == 2)
			return new float[] { points[0].x, points[0].y, points[1].x, points[1].y };
		else
			return new float[0];
	}
}
