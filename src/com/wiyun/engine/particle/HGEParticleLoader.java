package com.wiyun.engine.particle;

import com.wiyun.engine.nodes.Director;
import com.wiyun.engine.opengl.Texture2D;

/**
 * 用于载入HGE(HAFF'S GAME ENGINE)的粒子系统描述文件
 */
public class HGEParticleLoader {
	/**
	 * 从一个HGE描述文件中载入粒子效果
	 * 
	 * @param resId .psi描述文件的资源id
	 * @param particleCount 指定粒子系统的粒子数量
	 * @param tex 指定粒子系统的粒子贴图
	 * 
	 * @return {@link QuadParticleSystem}
	 */
	public static QuadParticleSystem load(int resId, int particleCount, Texture2D tex) {
		return QuadParticleSystem.from(nativeLoad(resId, particleCount, tex));
	}
	
	/**
	 * 从一个Particle Designer描述文件中载入粒子效果
	 * 
	 * @param path 粒子效果描述文件相对于assets的相对路径
	 * @param particleCount 指定粒子系统的粒子数量
	 * @param tex 指定粒子系统的粒子贴图
	 * @return {@link QuadParticleSystem}
	 */
	public static QuadParticleSystem load(String path, int particleCount, Texture2D tex) {
		return load(path, particleCount, tex, false);
	}
	
	/**
	 * 从一个Particle Designer描述文件中载入粒子效果
	 * 
	 * @param path 粒子效果描述文件相对于assets的相对路径或者在文件系统中的路径
	 * @param particleCount 指定粒子系统的粒子数量
	 * @param tex 指定粒子系统的粒子贴图
	 * @param isFile true表示path是文件系统的路径, false表示是assets下的路径
	 * @return {@link QuadParticleSystem}
	 */
	public static QuadParticleSystem load(String path, int particleCount, Texture2D tex, boolean isFile) {
		return load(path, particleCount, tex, isFile, Director.getDefaultInDensity());
	}
	
	/**
	 * 从一个Particle Designer描述文件中载入粒子效果
	 * 
	 * @param path 粒子效果描述文件相对于assets的相对路径或者在文件系统中的路径
	 * @param particleCount 指定粒子系统的粒子数量
	 * @param tex 指定粒子系统的粒子贴图
	 * @param isFile true表示path是文件系统的路径, false表示是assets下的路径
	 * @param inDensity 密度, 缺省为0, 表示使用系统缺省的输入密度
	 * @return {@link QuadParticleSystem}
	 */
	public static QuadParticleSystem load(String path, int particleCount, Texture2D tex, boolean isFile, float inDensity) {
		return QuadParticleSystem.from(nativeLoad(path, particleCount, tex, isFile, inDensity));
	}
	
	private native static int nativeLoad(int resId, int particleCount, Texture2D tex);
	private native static int nativeLoad(String path, int particleCount, Texture2D tex, boolean isFile, float inDensity);
}