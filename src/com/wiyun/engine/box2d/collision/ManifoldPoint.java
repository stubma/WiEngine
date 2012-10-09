package com.wiyun.engine.box2d.collision;

import com.wiyun.engine.types.WYPoint;

public class ManifoldPoint {
	// contact feature
	public static final int TYPE_VERTEX = 0;
	public static final int TYPE_FACE = 1;
	
	/**
	 * local point
	 */
	public WYPoint localPoint;
	
	/**
	 * the non-penetration impulse
	 */
	public float normalImpulse;
	
	/**
	 * the friction impulse
	 */
	public float tangentImpulse;
	
	/**
	 * Feature index on shapeA
	 */
	public int indexA;		
	
	/**
	 * Feature index on shapeB
	 */
	public int indexB;		
	
	/**
	 * The feature type on shapeA
	 */
	public int typeA;		
	
	/**
	 * The feature type on shapeB
	 */
	public int typeB;		
	
	/**
	 * 得到一个唯一标识碰撞点的id
	 * 
	 * @return 碰撞点id
	 */
	public int getContactId() {
		return ((indexA & 0xff) << 24) | ((indexB & 0xff) << 16) | ((typeA & 0xff) << 8) | (typeB & 0xff);
	}
}
