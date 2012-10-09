package com.wiyun.engine.particle;

import com.wiyun.engine.nodes.Director;

/**
 * 用于载入particle designer设计的粒子系统描述文件
 */
public class ParticleLoader {
	/**
	 * 从一个Particle Designer描述文件中载入粒子效果
	 * 
	 * @param resId 粒子效果描述文件资源id
	 * @return {@link QuadParticleSystem}
	 */
	public static QuadParticleSystem load(int resId) {
		return QuadParticleSystem.from(nativeLoad(resId));
	}
	
	/**
	 * 从一个Particle Designer描述文件中载入粒子效果
	 * 
	 * @param path 粒子效果描述文件相对于assets的相对路径
	 * @return {@link QuadParticleSystem}
	 */
	public static QuadParticleSystem load(String path) {
		return load(path, false);
	}
	
	/**
	 * 从一个Particle Designer描述文件中载入粒子效果
	 * 
	 * @param path 粒子效果描述文件相对于assets的相对路径或者在文件系统中的路径
	 * @param isFile true表示path是文件系统的路径, false表示是assets下的路径
	 * @return {@link QuadParticleSystem}
	 */
	public static QuadParticleSystem load(String path, boolean isFile) {
		return load(path, isFile, Director.getDefaultInDensity());
	}
	
	/**
	 * 从一个Particle Designer描述文件中载入粒子效果
	 * 
	 * @param path 粒子效果描述文件相对于assets的相对路径或者在文件系统中的路径
	 * @param isFile true表示path是文件系统的路径, false表示是assets下的路径
	 * @param inDensity 描述文件的密度设置, 这会影响WiEngine自动缩放的行为, 如果为0, 表示使用
	 * 		系统当前的缺省输入密度
	 * @return {@link QuadParticleSystem}
	 */
	public static QuadParticleSystem load(String path, boolean isFile, float inDensity) {
		return QuadParticleSystem.from(nativeLoad(path, isFile, inDensity));
	}
	
	private native static int nativeLoad(int resId);
	private native static int nativeLoad(String path, boolean isFile, float inDensity);
}
