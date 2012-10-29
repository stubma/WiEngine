package com.wiyun.engine.particle;

import com.wiyun.engine.nodes.Node;
import com.wiyun.engine.types.WYPoint;

/**
 * 粒子系统基类。 
 */
public abstract class ParticleSystem extends Node {
	/** The Particle emitter lives forever */
	public static final int PARTICLE_DURATION_INFINITY = -1;

	/** The starting size of the particle is equal to the ending size */
	public static final int PARTICLE_START_SIZE_EQUAL_TO_END_SIZE = -1;

	/** The starting radius of the particle is equal to the ending radius */
	public static final int PARTICLE_START_RADIUS_EQUAL_TO_END_RADIUS = -1;

	/**
	 * 粒子系统模式 
	 */
	/** Gravity mode (A mode) */
	public static final int GRAVITY = 1;

	/** Radius mode (B mode) */
	public static final int RADIUS = 2;

	/** If the emitter is repositioned, the living particles won't be repositioned */
	public static final int FREE = 1;

	/** If the emitter is repositioned, the living particles will be repositioned too */
	public static final int GROUPED = 2;
	
	protected ParticleSystem() {
	}
	
	protected ParticleSystem(int numberOfParticles) {
	}
	
    protected ParticleSystem(int dummy, int pointer) {
    	super(pointer);
    }
	
	@Override
	protected void doNativeInit() {
	}
	
	public native void setDuration(float duration);
	
	public native float getDuration();
	
	public WYPoint getCenterOfGravity() {
		return WYPoint.make(getCenterOfGravityX(), getCenterOfGravityY());
	}
	
	private native float getCenterOfGravityX(); 
	private native float getCenterOfGravityY(); 
	
	public native void setParticlePositionVariance(float baseX, float baseY, float varianceX, float varianceY);
	
	public native void setDirectionAngleVariance(float base, float variance);
	
	public native void setStartSizeVariance(float base, float variance);
	
	public native void setEndSizeVariance(float base, float variance);
	
	public native void setLifeVariance(float base, float variance);
	
	public native void setStartColorVariance(float baseR, float baseG, float baseB, float baseA, float varR, float varG, float varB, float varA);
	
	public native void setEndColorVariance(float baseR, float baseG, float baseB, float baseA, float varR, float varG, float varB, float varA);
	
	public native void setStartSpinVariance(float base, float variance);
	
	public native void setEndSpinVariance(float base, float variance);
	
	public native void setSpeedVariance(float base, float variance);
	
	public native void setParticleGravity(float gravityX, float gravityY);
	
	public native void setTangentialAccelerationVariance(float base, float variance);
	
	public native void setRadialAccelerationVariance(float base, float variance);
	
	public native void setStartRadiusVariance(float base, float variance);
	
	public native void setEndRadiusVariance(float base, float variance);
	
	public native void setRotationVariance(float base, float variance);

	public native int getParticleCount();
	
	public native int getMaxParticleCount();

	public native void stopSystem();

	public native void resetSystem();
	
	public native int getPositionType();

	public native void setPositionType(int positionType);
	
	public native int getEmitterMode();

	public native void setEmitterMode(int emitterMode);

	public native float getEmissionRate();

	public native void setEmissionRate(float emissionRate);

	public native boolean isAutoRemoveOnFinish();

	public native void setAutoRemoveOnFinish(boolean autoRemoveOnFinish);
	
	public native float getLife();
}
