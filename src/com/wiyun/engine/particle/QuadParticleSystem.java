package com.wiyun.engine.particle;

import com.wiyun.engine.opengl.Texture2D;
import com.wiyun.engine.types.WYRect;

/**
 * 四边形粒子系统，每个粒子其实是由一个四边形进行描述的，因此它的表现能力更丰富，
 * 可以做更多变形。 
 */
public class QuadParticleSystem extends ParticleSystem {
	public QuadParticleSystem(int numberOfParticles) {
		nativeInit(numberOfParticles);
	}
	
    /**
     * 从底层指针获得一个QuadParticleSystem的Java对象
     * 
     * @param pointer 底层指针
     * @return {@link QuadParticleSystem}
     */
    public static QuadParticleSystem from(int pointer) {
    	return pointer == 0 ? null : new QuadParticleSystem(0, pointer);
    }
    
    protected QuadParticleSystem(int dummy, int pointer) {
    	super(0, pointer);
    }
	
	private native void nativeInit(int numberOfParticles);

	/**
	 * 设置粒子贴图为某个图片集的一部分
	 * 
	 * @param texture 图片集贴图对象
	 * @param rect 粒子图片在图片集中的位置，由于Android的坐标系和OpenGL相反，所以origin表示图片的左上角位置
	 */
	public native void setTexture(Texture2D texture, WYRect rect);
}
