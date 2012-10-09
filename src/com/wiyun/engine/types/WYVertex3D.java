package com.wiyun.engine.types;

/**
 * 用于描述一个顶点的3维坐标
 */
public class WYVertex3D {
	/**
	 * byte count of GL format
	 */
	public static final int GL_SIZE = 4 * 3;
	
    public float x;
    public float y;
    public float z;
    
    /**
     * 创建一个实例
     * 
     * @return 值全0的顶点坐标对象
     */
    public static WYVertex3D makeZero() {
    	return WYVertex3D.make(0, 0, 0);
    }
    
    /**
     * 创建一个实例
     * 
     * @param x 顶点的x坐标
     * @param y 顶点的y坐标
     * @param z 顶点的z坐标
     * @return {@link WYVertex3D}
     */
    public static WYVertex3D make(float x, float y, float z) {
    	return new WYVertex3D(x, y, z);
    }

    /**
     * 构造函数
     * 
     * @param x 顶点的x坐标
     * @param y 顶点的y坐标
     * @param z 顶点的z坐标
     */
    protected WYVertex3D(float x, float y, float z) {
        this.x = x;
        this.y = y;
        this.z = z;
    }
    
    @Override
    public String toString() {
    	return "<"  + x + ", " + y + ", " + z + ">";
    }
}
