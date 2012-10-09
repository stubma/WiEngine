package com.wiyun.engine.particle;

/**
 * 点粒子系统，每个粒子是由一个点描述的，因此不能实现复杂的效果，但是性能上会比四边形
 * 粒子系统快。
 */
public class PointParticleSystem extends ParticleSystem {
	public PointParticleSystem(int numberOfParticles) {
		nativeInit(numberOfParticles);
	}
	
    /**
     * 从底层指针获得一个PointParticleSystem的Java对象
     * 
     * @param pointer 底层指针
     * @return {@link PointParticleSystem}
     */
    public static PointParticleSystem from(int pointer) {
    	return pointer == 0 ? null : new PointParticleSystem(0, pointer);
    }
    
    protected PointParticleSystem(int dummy, int pointer) {
    	super(0, pointer);
    }
    
	private native void nativeInit(int numberOfParticles);
}
