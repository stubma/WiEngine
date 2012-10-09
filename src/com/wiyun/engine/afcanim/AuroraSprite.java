package com.wiyun.engine.afcanim;

import com.wiyun.engine.opengl.Texture2D;

/**
 * \if English
 * AuroraGT is designed by gameloft and it names exported file as BSprite format. Actually
 * AuroraGT is not only an animation designer, but also a map designer and game element manager.
 * \else
 * AuroraGT编辑器是gameloft设计的游戏编辑器， 其实它不仅限于动画编辑， 还能支持编辑地图和管理游戏元素.
 * 其使用的导出文件格式叫做BSprite
 * \endif
 */
public class AuroraSprite extends AFCSprite {
	/**
	 * \if English
	 * Create aurora sprite from resource id
	 *
	 * @param bsResId resource id of anu file
	 * @param animIndex animation index
	 * @param tex related textures, if more than one, can follow this argument
	 * \else
	 * 从一个anu资源文件中创建\link AuroraSprite AuroraSprite\endlink
	 *
	 * @param bsResId anu文件的资源id
	 * @param animIndex 动画索引
	 * @param tex 相关联的\link Texture2D Texture2D\endlink, 后面可以跟可变参数, 方便指定
	 * 		更多关联的\link Texture2D Texture2D\endlink. 
	 * \endif
	 */
	public static AuroraSprite make(int bsResId, int animIndex, Texture2D... tex) {
		return new AuroraSprite(bsResId, animIndex, tex);
	}
	
	/**
	 * \if English
	 * Create aurora sprite from path
	 *
	 * @param path path of anu file
	 * @param isFile true means \c path is an absolute path in file system, false means \c path
	 * 		is relative path under assets
	 * @param animIndex animation index
	 * @param tex related textures, if more than one, can follow this argument
	 * \else
	 * 从一个asset文件或者文件系统中的文件创建\link AuroraSprite AuroraSprite\endlink
	 *
	 * @param path anu文件的路径
	 * @param isFile true表示path是一个文件系统路径, 而false表示path是一个assets下的路径
	 * @param animIndex 动画索引
	 * @param tex 相关联的\link Texture2D Texture2D\endlink, 后面可以跟可变参数, 方便指定
	 * 		更多关联的\link Texture2D Texture2D\endlink.
	 * \endif
	 */
	public static AuroraSprite make(String path, boolean isFile, int animIndex, Texture2D... tex) {
		return new AuroraSprite(path, isFile, animIndex, tex);
	}
	
	public static AuroraSprite from(int pointer) {
		return pointer == 0 ? null : new AuroraSprite(pointer);
	}
	
	protected AuroraSprite(int bsResId, int animIndex, Texture2D[] tex) {
		nativeInit(bsResId, animIndex, tex);
	}
	
	protected AuroraSprite(String path, boolean isFile, int animIndex, Texture2D[] tex) {
		nativeInit(path, isFile, animIndex, tex);
	}
	
	protected AuroraSprite(int pointer) {
		super(pointer);
	}
	
	private native void nativeInit(int bsResId, int animIndex, Texture2D[] tex);
	
	private native void nativeInit(String path, boolean isFile, int animIndex, Texture2D[] tex);
}
