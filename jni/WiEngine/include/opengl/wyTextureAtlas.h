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
#ifndef __wyTextureAtlas_h__
#define __wyTextureAtlas_h__

#include "wyObject.h"
#include "wyGlobal.h"
#include <stdbool.h>
#include "wyTypes.h"
#include "wyArray.h"

#define ATLAS_DEFAULT_CAPACITY 29

class wyTexture2D;
class wyTextureAtlas;

/**
 * @typedef iterateQuad3DFunc
 *
 * 用来遍历所有\link wyQuad3D wyQuad3D\endlink 的回调原型, 返回true表示继续遍历,
 * 返回false表示结束遍历
 */
typedef bool (*iterateQuad3DFunc)(wyTextureAtlas*, wyQuad3D*, void*);

/**
 * @class wyTextureAtlas
 *
 * 图片集的封装
 */
class WIENGINE_API wyTextureAtlas : public wyObject {

protected:
	/// 图片资源\link wyTexture2D wyTexture2D对象指针\endlink
	wyTexture2D* m_tex;

	/// 缓存中使用的总数
	int m_totalQuads;

	/// 缓存中的块数,标识缓存中可以存放的数量
	int m_capacity;

	/// 标识是否用自己的颜色缓存
	bool m_withColorArray;

	// buffers
	/// 缓存openGL顶点
	GLfloat* m_vertices;

	/// 缓存openGL纹理
	GLfloat* m_texCoords;

	/// 缓存openGL颜色
	GLubyte* m_colors;

	/// 缓存openGL索引
	GLushort* m_indices;

	/// texture atlas渲染时用的颜色, 如果不设置, 则不打开颜色数组, 而由外部的glColor决定
	wyColor4B m_color;

private:
	/**
	 * 更新缓存中的颜色
	 *
	 * @param color 动作的\link wyColor4B wyColor4B结构\endlink
	 * @param index 缓存中的位置
	 */
	void putColor(wyColor4B* color, int index);

	/**
	 * 更新缓存中的顶点
	 *
	 * @param quadV 动作的\link wyQuad3D wyQuad3D结构\endlink
	 * @param index 缓存中的位置
	 */
	void putVertex(wyQuad3D* quadV, int index);

	/**
	 * 更新缓存中的纹理
	 *
	 * @param quadT 动作的\link wyQuad2D wyQuad2D结构\endlink
	 * @param index 缓存中的位置
	 */
	void putTexCoords(wyQuad2D* quadT, int index);

	/**
	 * 初始化颜色数组
	 */
	void initColorArray();

	/**
	 * 初始化索引
	 */
	void initIndices();

public:
	/**
	 * 获得图片集\link wyTextureAtlas wyTextureAtlas对象\endlink 指针，
	 * 这个方法始终创建新的\link wyTextureAtlas wyTextureAtlas对象\endlink
	 *
	 * @param tex 图片资源\link wyTexture2D wyTexture2D对象指针\endlink
	 * @return 图片集\link wyTextureAtlas wyTextureAtlas对象指针\endlink
	 */
	static wyTextureAtlas* make(wyTexture2D* tex);

	/**
	 * 构造函数
	 *
	 * @param tex 图片资源\link wyTexture2D wyTexture2D对象指针\endlink
	 * @param capacity 缓存尺寸,默认ATLAS_DEFAULT_CAPACITY
	 */
	wyTextureAtlas(wyTexture2D* tex, int capacity = ATLAS_DEFAULT_CAPACITY);

	/**
	 * 析构函数
	 */
	virtual ~wyTextureAtlas();

	/**
	 * 设置图片资源\link wyTexture2D wyTexture2D对象指针\endlink
	 *
	 * @param tex 图片资源\link wyTexture2D wyTexture2D对象指针\endlink
	 */
	void setTexture(wyTexture2D* tex);

	/**
	 * 获得图片资源\link wyTexture2D wyTexture2D对象指针\endlink
	 *
	 * @return 图片资源\link wyTexture2D wyTexture2D对象指针\endlink
	 */
	wyTexture2D* getTexture() { return m_tex; }

	/**
	 * 重新计算缓存,如果小于当前数则返回
	 *
	 * @param newCapacity 缓存数
	 */
	void resizeCapacity(int newCapacity);

	/**
	 * 删除所有矩形
	 */
	void removeAllQuads() { m_totalQuads = 0; }

	/**
	 * 获得下一个可用的矩形索引
	 *
	 * @return 下一个可用的矩形索引
	 */
	int getNextAvailableIndex();

	/**
	 * 更新缓存中的顶点和纹理
	 *
	 * @param quadT 纹理\link wyQuad2D wyQuad2D结构\endlink
	 * @param quadV 顶点\link wyQuad3D wyQuad3D结构\endlink
	 * @param index 缓存中的索引
	 */
	void updateQuad(wyQuad2D& quadT, wyQuad3D& quadV, int index);

	/**
	 * 更新缓存中的颜色
	 *
	 * @param color 颜色\link wyColor4B wyColor4B结构\endlink
	 * @param index 缓存中的索引
	 */
	void updateColor(wyColor4B color, int index);

	/**
	 * \if English
	 * Update color for all quads
	 *
	 * @param color color to be set
	 * \else
	 * 统一设置所有的四边形为某一颜色
	 *
	 * @param color 要设置的颜色
	 * \endif
	 */
	void updateColor(wyColor4B color);

	/**
	 * 在缓存中添加顶点和纹理,放到队列中最后
	 *
	 * @param quadT 纹理\link wyQuad2D wyQuad2D结构\endlink
	 * @param quadV 顶点\link wyQuad3D wyQuad3D结构\endlink
	 * @return 新添加的四边形在atlas中的索引
	 */
	int appendQuad(wyQuad2D& quadT, wyQuad3D& quadV);

	/**
	 * 在缓存指定索引中添加顶点和纹理, 如果插入在最后，则不需要额外操作，
	 * 如果插入在中间，则会把插入位置处的Quad移动到最后一个
	 *
	 * @param quadT 纹理\link wyQuad2D wyQuad2D结构\endlink
	 * @param quadV 顶点\link wyQuad3D wyQuad3D结构\endlink
	 * @param index 缓存索引
	 */
	void insertQuad(wyQuad2D& quadT, wyQuad3D& quadV, int index);

	/**
	 * 删除指定位置的Quad, 如果删除的是最后一个，则不需要额外操作，
	 * 如果删除的是中间的，则最后一个Quad会被移动到被删除的位置
	 *
	 * @param index 缓存索引
	 */
	void removeQuad(int index);

	/**
	 * 删除一定范围内的四边形
	 *
	 * @param start 删除的起始索引
	 * @param count 删除的四边形个数
	 */
	void removeQuads(int start, int count);

	/**
	 * 把自己的一个四边形拷贝到另外一个\link wyTextureAtlas wyTextureAtlas\endlink 节点中
	 *
	 * @param from 要拷贝的四边形索引位置，如果范围不合法，则什么也不做
	 * @param destAtlas 目标\link wyTextureAtlas wyTextureAtlas\endlink
	 */
	void copyTo(int from, wyTextureAtlas* destAtlas);

	/**
	 * 把自己的一个四边形拷贝到传入的指针中
	 *
	 * @param from 要拷贝的四边形索引位置，如果范围不合法，则什么也不做
	 * @param quadT 保存贴图坐标，一个\link wyQuad2D wyQuad2D\endlink 结构指针
	 * @param quadV 保存顶点坐标，一个\link wyQuad3D wyQuad3D\endlink 结构指针
	 */
	void copyTo(int from, wyQuad2D* quadT, wyQuad3D* quadV);

	/**
	 * 画缓存中的某一索引图像
	 *
	 * @param index 缓存索引
	 */
	void drawOne(int index);

	/**
	 * 画缓存中指定数值的图像
	 *
	 * @param numOfQuads 缓存索引
	 */
	void draw(int numOfQuads);

	/**
	 * \if English
	 * Draw quads in specified range, do nothing if there is not
	 * enough quads to be drawn
	 *
	 * @param start start drawing position
	 * @param numOfQuads max number of quads to be drawn
	 * @return if drawing is performed, returns true, or false if not
	 * \else
	 * 画缓存指定位置开始，指定数量的图像. 如果从指定位置开始不足\c numOfQuads个四边形,
	 * 则不做任何事
	 *
	 * @param start 起始渲染的四边形位置
	 * @param numOfQuads 最多画多少个四边形
	 * @return 如果渲染操作成功执行, 返回true, 否则返回false
	 * \endif
	 */
	bool drawRange(int start, int numOfQuads);

	/**
	 * 画缓存中所有使用的图像
	 */
	void drawAll();

	/**
	 * 获得缓存中使用的总数
	 *
	 * @return 缓存中使用的总数
	 */
	int getTotalQuads() { return m_totalQuads; }

	/**
	 * 获得是否启动自定义的颜色缓存
	 *
	 * @return 是否启动自定义的颜色缓存
	 */
	bool isWithColorArray() { return m_withColorArray; }

	/**
	 * 获得缓存空间大小
	 *
	 * @return 缓存空间大小
	 */
	int getCapacity() { return m_capacity; }

	/**
	 * 获得图片集像素高度
	 *
	 * @return 图片集像素高度
	 */
	int getPixelHeight() { return m_tex->getPixelHeight(); }

	/**
	 * 获得图片集像素宽度
	 *
	 * @return 图片集像素宽度
	 */
	int getPixelWidth() { return m_tex->getPixelWidth(); }

	/**
	 * 获得图片集宽度
	 *
	 * @return 图片集宽度
	 */
	float getWidth() { return m_tex->getWidth(); }

	/**
	 * 获得图片集高度
	 *
	 * @return 图片集高度
	 */
	float getHeight() { return m_tex->getHeight(); }

	/**
	 * 获得图片集宽度缩放比
	 *
	 * @return 图片集宽度缩放比
	 */
	float getWidthScale() { return m_tex->getWidthScale(); }

	/**
	 * 获得图片集高度缩放比
	 *
	 * @return 图片集高度缩放比
	 */
	float getHeightScale() { return m_tex->getHeightScale(); }

	/**
	 * 设置atlas的缺省颜色, 调用这个方法将会打开atlas的颜色数组
	 *
	 * @param color \link wyColor4B wyColor4B\endlink
	 */
	void setColor(wyColor4B color);

	/**
	 * \if English
	 * Set atlas alpha
	 * \else
	 * 设置atlas的透明度
	 * \endif
	 */
	void setAlpha(int alpha);

	/**
	 * \if English
	 * Get color of texture atlas
	 * \else
	 * 得到当前颜色
	 * \endif
	 */
	wyColor4B getColor() { return m_color; }

	/**
	 * 所有顶点的alpha都减去一个指定值, 该方法仅当颜色数组启用时有效. alpha
	 * 小于等于0的四边形将被删除
	 *
	 * @param delta 需要减去的alpha值
	 */
	void reduceAlpha(float delta);

	/**
	 * 对atlas中所有的顶点四边形进行遍历，这个方法可以方便其它人批量查看或者修改atlas中的
	 * 顶点数据
	 *
	 * @param func 遍历的回调函数指针
	 * @param data 附加数据指针
	 */
	void iterateQuad3D(iterateQuad3DFunc func, void* data);
};

#endif // __wyTextureAtlas_h__
