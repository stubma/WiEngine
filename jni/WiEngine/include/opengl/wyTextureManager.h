/*
 * Copyright (c) 2010 WiYun Inc.

 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:

 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.

 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
#ifndef __wyTextureManager_h__
#define __wyTextureManager_h__

#include "wyHashSet.h"
#include "wyArray.h"
#include "wyTexture2D.h"
#include "wyTextureAtlas.h"
#include "wyDirector.h"

class wyGLTexture2D;

/**
 * @class wyTextureManager
 *
 * 贴图管理器，负责管理WiEngine中所有贴图的缓冲，以及释放，重新载入等逻辑.
 */
class WIENGINE_API wyTextureManager : public wyObject {
	friend class wyGLTexture2D;
	friend class wyTexture2D;
	friend class wyDirector;

private:
	/// texture creation type
	enum wyTextureCreationType {
		CT_RESID,
		CT_PATH,
		CT_MFS,
		CT_DATA,
		CT_OPENGL,
		CT_LABEL
	};

	/// hash for texture handle
	struct wyTextureHash {
		/// 资源的创建参数
		union {
			// 通过资源id创建的
			struct {
				int resId;
			} rp;

			// 通过内存文件创建的
			struct {
				const char* mfsName;
			} mp;

			// 通过路径创建的
			struct {
				const char* path;
				bool isFile;
			} pp;

			// 通过内存数据创建的
			struct {
				const char* data;
				size_t length;
				int width;
				int height;
			} dp;
		};

		/// 创建类型
		wyTextureCreationType type;

		/// 贴图类型
		wyTextureSource source;

		/// 贴图格式
		wyTexturePixelFormat pixelFormat;

		/// 透明色, 仅对BMP文件有效
		int transparentColor;

		/// 资源的inDensity
		float inDensity;

		/// 资源的md5字符串, 用来唯一标识贴图
		const char* md5;

		/// 贴图句柄
		size_t handle;

		/// true means this texture is a cloned texture of other
		bool isClone;

		/// source handle, only used for cloned texture
		size_t sourceHandle;

		/// source md5, just a reference, don't release
		const char* sourceMd5;

		/// clone id, only used for cloned texture
		int cloneId;
	};

private:
	/// 所有贴图的指针, 以句柄为访问索引
	wyGLTexture2D** m_textures;

	/// 当前贴图数量
	int m_textureCount;

	/// 所有可以通过某个键值查找的贴图对象哈希表
	map<unsigned int, wyTextureHash>* m_textureHash;

	/// idle gl texture handle list
	vector<int>* m_idleHandles;

	/// 下一个label的id
	int m_nextLabelId;

	/// 下一个opengl贴图的id
	int m_nextGLId;

	/// 缺省贴图格式, 设置合适的贴图格式可以提高渲染速度, 缺省格式是RGBA8888
	wyTexturePixelFormat m_texturePixelFormat;

private:
	wyTextureManager();

	static void releaseTexHash(unsigned int key, wyTextureHash& hash);

	const char* hashForNum(int num);
	const char* hashForStr(const char* str);
	const char* hashForData(const void* data, size_t length);

	/**
	 * 得到下一个可用句柄
	 */
	size_t nextHandle();

	/**
	 * 根据句柄得到\link wyGLTexture2D wyGLTexture2D\endlink对象, 如果对象已经被删除,
	 * 则会被重新载入
	 *
	 * @param t \link wyTexture2D wyTexture2D\endlink
	 * @return \link wyGLTexture2D wyGLTexture2D\endlink
	 */
	wyGLTexture2D* getTexture(wyTexture2D* t);

	// create texture proxy
	wyTexture2D* makeBMP(int resId, int transparentColor, wyTexturePixelFormat format);
	wyTexture2D* makeBMP(const char* assetPath, int transparentColor, wyTexturePixelFormat format, float inDensity);
	wyTexture2D* makeRawBMP(const char* data, size_t length, int transparentColor, wyTexturePixelFormat format, float inDensity);
	wyTexture2D* makeMemoryBMP(const char* mfsName, int transparentColor, wyTexturePixelFormat format, float inDensity);
	wyTexture2D* makeFileBMP(const char* fsPath, int transparentColor, wyTexturePixelFormat format, float inDensity);
	wyTexture2D* makeJPG(int resId, int transparentColor, wyTexturePixelFormat format);
	wyTexture2D* makeJPG(const char* assetPath, int transparentColor, wyTexturePixelFormat format, float inDensity);
	wyTexture2D* makeRawJPG(const char* data, size_t length, int transparentColor, wyTexturePixelFormat format, float inDensity);
	wyTexture2D* makeMemoryJPG(const char* mfsName, int transparentColor, wyTexturePixelFormat format, float inDensity);
	wyTexture2D* makeFileJPG(const char* fsPath, int transparentColor, wyTexturePixelFormat format, float inDensity);
	wyTexture2D* makePNG(int resId, wyTexturePixelFormat format);
	wyTexture2D* makePNG(const char* assetPath, wyTexturePixelFormat format, float inDensity);
	wyTexture2D* makeRawPNG(const char* data, size_t length, wyTexturePixelFormat format, float inDensity);
	wyTexture2D* makeMemoryPNG(const char* mfsName, wyTexturePixelFormat format, float inDensity);
	wyTexture2D* makeFilePNG(const char* fsPath, wyTexturePixelFormat format, float inDensity);
	wyTexture2D* makePVR(int resId);
	wyTexture2D* makePVR(const char* assetPath, float inDensity);
	wyTexture2D* makeRawPVR(const char* data, size_t length, float inDensity);
	wyTexture2D* makeMemoryPVR(const char* mfsName, float inDensity);
	wyTexture2D* makeFilePVR(const char* fsPath, float inDensity);
	wyTexture2D* makeLabel(const char* text, float fontSize, const char* fontPath, bool isFile, float width, wyTexture2D::TextAlignment alignment);
	wyTexture2D* makeLabel(const char* text, float fontSize, wyFontStyle style, const char* fontName, float width, wyTexture2D::TextAlignment alignment);
	wyTexture2D* makeGL(int texture, int w, int h);
	wyTexture2D* makeRaw(const char* data, int width, int height, wyTexturePixelFormat format);

	/// clone a texture, with a given clone id
	wyTexture2D* cloneTexture(wyTexture2D* t, int cloneId);

	/// clone a texture, but hash is given
	wyTexture2D* cloneTexture(wyTexture2D* t, int sourceHandle, const char* md5, int cloneId);

	/// switch a proxy texture to a cloned proxy
	void switchToClonedTexture(wyTexture2D* t, int cloneId);

	/**
	 * create wyGLTexture2D for a md5 hash
	 *
	 * @param md5 md5 for this texture
	 * @param t only used for create a label texture because label info is saved in wyTexture2D,
	 * 		may refactor this
	 */
	wyGLTexture2D* createGLTexture(const char* md5, wyTexture2D* t);

	/// clear cloned textures
	void releaseClonedTexture(int sourceHandle, bool removeHandle = false);

protected:
	/**
	 * 作废所有贴图对象, 不会在OpenGL中删除, 只是设置贴图无效, 这样在下次访问贴图时, 这个贴图
	 * 会被重新载入.
	 */
	void invalidateAllTextures();

public:
	static wyTextureManager* getInstance();
	static wyTextureManager* getInstanceNoCreate();
	virtual ~wyTextureManager();

	/**
	 * \if English
	 * Get currently cached texture count
	 *
	 * @return total number of cached texture
	 * \else
	 * 得到当前缓存的贴图数量
	 *
	 * @return 当前缓存的贴图数量
	 * \endif
	 */
	int getTextureCount();

	/**
	 * 清除所有贴图对象。这会导致所有的OpenGL贴图立刻全部被释放. 但是如果某个贴图在之后又被
	 * 访问了, 则贴图会被重新载入.
	 */
	void removeAllTextures();

	/**
	 * 根据资源id删除一个关联的OpenGL贴图, 这个方法调用后, OpenGL的贴图被立刻释放.
	 * 如果在删除之后这个贴图又被某处访问, 则这个贴图将被重新载入.
	 *
	 * @param resId 图片的资源id
	 */
	void removeTexture(int resId);

	/**
	 * 根据名称删除一个关联的OpenGL贴图, 这个方法调用后, OpenGL的贴图被立刻释放.
	 * 如果在删除之后这个贴图又被某处访问, 则这个贴图将被重新载入.
	 *
	 * @param name 图片的名称, 这个名称可以是路径名或者内存文件系统名
	 */
	void removeTexture(const char* name);

	/**
	 * 删除贴图代理管理的OpenGL贴图, 同时可以指定是否删除相关的贴图句柄信息. 句柄信息可以认为是
	 * 贴图的元数据，一旦被删除，则其它还在引用这个贴图的\link wyTexture2D wyTexture2D\endlink都将
	 * 无法显示贴图。所以删除句柄要谨慎，确认确实无其它\link wyTexture2D wyTexture2D\endlink引用该
	 * 句柄才是一个安全的删除。如果不删除句柄，则其它还在引用这个贴图的\link wyTexture2D wyTexture2D\endlink
	 * 对象尝试再次访问该贴图时，贴图会被重新载入。
	 *
	 * @param tex \link wyTexture2D wyTexture2D\endlink
	 * @param removeHandle true表示释放句柄, 相关的句柄可以在下次被重用
	 */
	void removeTexture(wyTexture2D* tex, bool removeHandle = false);

	/**
	 * 设置缺省贴图格式, 后续创建的贴图将使用这个贴图格式, 除非创建贴图时指定了一个另外的贴图格式.
	 * 缺省的贴图格式是RGBA8888. 适当的使用贴图格式可以提高渲染的效率, 比如RGBA4444的贴图就比
	 * RGBA8888的贴图渲染速度快很多, 当然这是通过损失颜色精度达到的.
	 *
	 * @param pixelFormat 贴图格式
	 */
	void setTexturePixelFormat(wyTexturePixelFormat pixelFormat) { m_texturePixelFormat = pixelFormat; }

	/**
	 * 获得当前缺省贴图格式
	 *
	 * @return 贴图格式
	 */
	wyTexturePixelFormat getTexturePixelFormat() { return m_texturePixelFormat; }
};

#endif // __wyTextureManager_h__
