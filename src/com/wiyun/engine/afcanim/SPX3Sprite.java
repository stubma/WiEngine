package com.wiyun.engine.afcanim;

import com.wiyun.engine.opengl.Texture2D;

/**
 * \if English
 * \par
 * SpriteX 2011 is a tool of animation, exported file has *.sprite name. The structure of sprite
 * file is similar with anu file but different terms used.
 *
 * \par
 * This class supports exported file of SpriteX 2011 2011. SpriteX 2011 uses an incompatible file format with
 * 3.9.4, so WiEngine creates \link SPX3Sprite SPX3Sprite\endlink.
 * 
 * \note
 * \link wySPX3Sprite wySPX3Sprite\endlink doesn't support clip mapping
 * \else
 * \par
 * SpriteX 2011是一个和Motion Welder类似的
 * 动画编辑软件。 其动画的组织结构很像Motion Welder, 其导出的文件一般是*.sprite文件, 可以认为其对应于Motion Welder
 * 的*.anu文件. 但是SpriteX 2011对一些术语的叫法和Motion Welder不同，不过基本只是名字不同， 其概念是类似的。比如：
 * 1. 动画， 在Motion Welder称为Animation, SpriteX 2011中叫做Action
 * 2. 帧都是叫Frame
 * 3. Motion Welder中的Clip在SpriteX 2011中叫做Tile
 * 4. 图片集在Motion Welder中就是Image, WiEngine一般称之为Atlas, SpriteX 2011称之为Patch
 *
 * \par
 * 这个类用于支持SpriteX 2011版本的导出文件. SpriteX 2011的导出文件格式和3.9.4是不兼容的, 因此WiEngine新增了
 * \link SPX3Sprite SPX3Sprite\endlink来处理2011的动画. 但是2011仍然是一个AFC架构编辑器, 因此仍然是
 * \link AFCSprite AFCSprite\endlink的子类
 * 
 * \note
 * \link wySPX3Sprite wySPX3Sprite\endlink不支持分片映射
 * \endif
 */
public class SPX3Sprite extends AFCSprite {
	/**
	 * \if English
	 * Create a \link SPX3Sprite SPX3Sprite\endlink from a SpriteX 2011 resource file
	 *
	 * @param spxResId resource id of sprite file
	 * @param animIndex animation index
	 * @param tex related textures, if more than one, can follow this argument
	 * @return \link SPX3Sprite SPX3Sprite\endlink
	 * \else
	 * 通过一个SpriteX 2011文件的资源id创建一个\link SPX3Sprite SPX3Sprite\endlink对象
	 *
	 * @param spxResId sprite文件的资源id
	 * @param animIndex 动画索引
	 * @param tex 相关联的\link Texture2D Texture2D\endlink, 后面可以跟可变参数, 方便指定
	 * 		更多关联的\link Texture2D Texture2D\endlink.
	 * @return \link SPX3Sprite SPX3Sprite\endlink
	 * \endif
	 */
	public static SPX3Sprite make(int spxResId, int animIndex, Texture2D... tex) {
		return new SPX3Sprite(spxResId, animIndex, tex);
	}
	
	/**
	 * \if English
	 * Create a \link SPX3Sprite SPX3Sprite\endlink from a SpriteX 2011 file path
	 *
	 * @param spxPath path of sprite file
	 * @param isFile true means \c spxPath is an absolute path in file system, false if
	 * 		\c spxPath is relative path under assets
	 * @param animIndex animation index
	 * @param tex related textures, if more than one, can follow this argument
	 * @return \link SPX3Sprite SPX3Sprite\endlink
	 * \else
	 * 通过一个SpriteX 2011文件路径创建一个\link SPX3Sprite SPX3Sprite\endlink对象
	 *
	 * @param spxPath sprite文件的路径
	 * @param isFile true表示\c spxPath是一个文件系统的绝对路径, false表示\c spxPath是一个assets
	 * 		下的相对路径
	 * @param animIndex 动画索引
	 * @param tex 相关联的\link Texture2D Texture2D\endlink, 后面可以跟可变参数, 方便指定
	 * 		更多关联的\link Texture2D Texture2D\endlink
	 * @return \link SPX3Sprite SPX3Sprite\endlink
	 * \endif
	 */
	public static SPX3Sprite make(String spxPath, boolean isFile, int animIndex, Texture2D... tex) {
		return new SPX3Sprite(spxPath, isFile, animIndex, tex);
	}
	
	public static SPX3Sprite from(int pointer) {
		return pointer == 0 ? null : new SPX3Sprite(pointer);
	}
	
	protected SPX3Sprite(int spxResId, int animIndex, Texture2D[] tex) {
		nativeInit(spxResId, animIndex, tex);
	}
	
	protected SPX3Sprite(String spxPath, boolean isFile, int animIndex, Texture2D[] tex) {
		nativeInit(spxPath, isFile, animIndex, tex);
	}
	
	protected SPX3Sprite(int pointer) {
		super(pointer);
	}
	
	private native void nativeInit(int spxResId, int animIndex, Texture2D[] tex);
	
	private native void nativeInit(String spxPath, boolean isFile, int animIndex, Texture2D[] tex);
}
