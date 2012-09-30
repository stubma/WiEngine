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
#ifndef __wyCoverFlow_h__
#define __wyCoverFlow_h__

#include "wyNode.h"

#define DEFAULT_DEGREE_LEFT  -70.0f
#define DEFAULT_DEGREE_RIGHT  70.0f

class wyCoverFlowAction;

/**
 * @class wyCover
 * \if English
 * to represent a single cover in the \link wyCoverFlow cover flow\endlink.
 * \else
 * 表示节点\link wyCoverFlow wyCoverFlow \endlink的一个显示页面，wyCoverFlow
 * 用双向链表维护所有显示页面
 * \endif
 */
class WIENGINE_API wyCover : public wyObject {
	friend class wyCoverFlow;

private:
	/**
	 * \if English
	 * x coordinate of the cover in the wyCoverFlow space, default value is zero.
	 * \else
	 * wyCoverFlow坐标系内的x坐标，默认在原点
	 * \endif
	 */
    float           m_posX;
	
    /**
     * \if English
     * x coordinate of the cover in the wyCoverFlow space, default value is zero.
     * \else
     * wyCoverFlow坐标系内的y坐标，默认在原点
     * \endif
     */
    float           m_posY;

    /**
     * \if English
     * z coordinate of the cover in the wyCoverFlow space, default value is zero.
     * \else
     * wyCoverFlow坐标系内的z坐标，默认在原点
     * \endif
     */
    float           m_posZ;
	
    /**
     * \if English
     * specify how much degree the cover rotates around its center y axis, in degrees
     * \else
     * 绕Y中轴旋转的角度
     * \endif
     */
    float           m_rotateDegreeY;

    /**
     * \if English
     * specify how much the cover will be scaled, the default value is 1.0f
     * \else
     * 缩放系数，默认为1.0f, 表示不缩放
     * \endif
     */
    float           m_scale;
	
    /**
     * \if English
     * \link wyTexture2D wyTexture2D\endlink
     * \else
     * 贴图，\link wyTexture2D wyTexture2D\endlink
     * \endif
     */
    wyTexture2D*    m_tex;
	
    /**
     * \if English
     * pointer of the dual linked list, points to the next element
     * \else
     * 双向链表指针，指向下一个
     * \endif
     */
    wyCover*        m_next;
	
    /**
     * \if English
     * pointer of the dual linked list, points to the previous element
     * \else
     * 双向链表指针，指向前一个
     * \endif
     */
    wyCover*        m_prev;
	
	/**
	 * \if English
	 * flag， true means the cover's displaying will be updated automatically
	 * when methods moveLeft and moveRight of wyCoverFlow were called.
	 * If false, you need to call setters to update this cover manually.
	 * The default value is true.
	 * \else
	 * 标识，默认true，即启用自动更新。如设置为false，表示cover的位置和旋转角度不需要wyCoverFlow自动更新，
	 * 这样开发者在调用moveLeft，moveRight，drawCover方法时，需要自己更新位置和角度。
	 * \endif
	 */
	bool			m_autoUpdate;

private:
	/**
	 * \if English
	 * to do transform operations
	 * \else
	 * 执行cover的平移，旋转和放大
	 * \endif
	 */
    void transform();
	
	/**
	 * \if English
	 * setter
	 *
	 * @param[in] posX x coordinate
	 * @param[in] posY y coordinate
	 * @param[in] posZ z coordinate
	 * \else
	 * 指定新位置
	 *
	 * @param[in] posX 新位置x坐标
	 * @param[in] posY 新位置y坐标
	 * @param[in] posZ 新位置z坐标
	 * \endif
	 */
    void setPosition(float posX, float posY, float posZ) { m_posX = posX; m_posY = posY; m_posZ = posZ; }

protected:
	/**
	 * \if English
	 * constructor
	 * \else
	 * 构造函数
	 * \endif
	 */
    wyCover() {}

public:
	/**
	 * \if English
	 * factory function, used to create a new instance with autoReleased enabled
	 *
	 * @param[in] tex \link wyTexture2D wyTexture2D\endlink
	 * \else
	 * 静态方法，创建一个新的cover对象
	 *
	 * @param[in] tex 新cover对象的贴图
	 * \endif
	 */
	static wyCover* make(wyTexture2D* tex);

	/**
	 * \if English
	 * constructor
	 *
	 * @param[in] tex \link wyTexture2D wyTexture2D\endlink
	 * \else
	 * 构造函数
	 *
	 * @param[in] tex 贴图，为提高性能，建议使用2的n次方大小的正方形图片
	 * \endif
	 */	
    wyCover(wyTexture2D* tex);
	
	/**
	 * \if English
	 * destructor
	 * \else
	 * 析构函数
	 * \endif
	 */
    virtual ~wyCover();

	/**
	 * \if English
	 * setter
	 *
	 * @param[in] posX x coordinate
	 * @param[in] posY y coordinate
	 * \else
	 * 指定新位置
	 *
	 * @param[in] posX 新位置x坐标
	 * @param[in] posY 新位置y坐标
	 * \endif
	 */
    void setPosition(float posX, float posY) { m_posX = posX; m_posY = posY;}

	/**
	 * \if English
	 * to get the position of the cover.
	 * Notice, the cover should be a visible cover, or else the value returned is undetermined.
	 * \else
	 * 获得当前位置, 调用此函数时应保证当前cover在显示状态
	 * \endif
	 */	
    wyVertex3D getPosition();
	
	/**
	 * \if English
	 * to specify how much the cover will be scaled
	 *
	 * @param[in] degree in degrees, right hand rule applies
	 * \else
	 * 设置绕Y中轴旋转的角度
	 *
	 * @param[in] degree 角度，单位为度，右手规则
	 * \endif
	 */
    void setRotateY(float degree) { m_rotateDegreeY = degree; }
	
	/**
	 * \if English
	 * getter
	 * \else
	 * 获得绕Y中轴旋转的角度
	 * \endif
	 */
    float getRotateY() { return m_rotateDegreeY; }	
	
	/**
	 * \if English
	 * to specify how much the cover will be scaled
	 *
	 * @param[in] scale <1.0f means scale down, >1.0f means scale up
	 * \else
	 * 设置缩放
	 *
	 * @param[in] scale 缩放系数
	 * \endif
	 */	
    void setScale(float scale) { m_scale = scale; }

	/**
	 * \if English
	 * getter
	 * \else
	 * 获得缩放系数
	 * \endif
	 */	
    float getScale() { return m_scale; }	
	
	/**
	 * \if English
	 * getter, to get the texture being used currently
	 * \else
	 * 获得当前所用贴图
	 * \endif
	 */		
    wyTexture2D* getTexture() { return m_tex; }
	
	/**
	 * \if English
	 * setter
	 *
	 * @param[in] tex \link wyTexture2D wyTexture2D\endlink
	 * \else
	 * 设置贴图
	 *
	 * @param[in] tex 新贴图
	 * \endif
	 */			
    void setTexture(wyTexture2D* tex);
	
	/**
	 * \if English
	 * to get the next linked cover
	 * \else
	 * 获得链表中的下一个cover
	 * \endif
	 */	
    wyCover* getNext() { return m_next; }
	
	/**
	 * \if English
	 * to set the next linked cover
	 *
	 * @param[in] next the next cover
	 * \else
	 * 设置链表中的下一个cover
	 *
	 * @param[in] next 下一个cover
	 * \endif
	 */		
    void setNext(wyCover* next) { m_next = next; }
	
	/**
	 * \if English
	 * to get the previous linked cover
	 * \else
	 * 获得链表中的前一个cover
	 * \endif
	 */	
    wyCover* getPrev() { return m_prev; }

	/**
	 * \if English
	 * to set the previous linked cover
	 *
	 * @param[in] prev the previous cover
	 * \else
	 * 设置链表中的前一个cover
	 *
	 * @param[in] prev 前一个cover
	 * \endif
	 */		
    void setPrev(wyCover* prev) { m_prev = prev; }

	/**
	 * \if English
	 * to get the auto update flag
	 * \else
	 * 获得是否自动更新
	 * \endif
	 */	
    bool getAutoUpdate() { return m_autoUpdate; }

	/**
	 * \if English
	 * to set the auto update flag
	 *
	 * @param[in] bEnable
	 * \else
	 * 设置是否自动更新
	 *
	 * @param[in] bEnable false表示关闭自动更新
	 * \endif
	 */		
    void setAutoUpdate(bool bEnable) { m_autoUpdate = bEnable; }	
};

/**
 * @class wyCoverFlow
 * \if English
 * \par
 * to represent a cover flow animation effect. The centered cover is named as front cover, and
 * the non-centered ones are named as back covers.
 *
 * \par
 * Notice:
 * A newly created wyCoverFlow object's cover size is unspecified, by default the value is (0,0).
 * You should set the cover size manually by calling setFrontCoverSize
 * \else
 * \par
 * 在三维空间中显示多张图片，一张居中，称为前景cover，两侧可各分列多张，
 * 称后景cover。两侧图片可以以动画方式移动至中间成为前景cover。
 *
 * \par
 * 使用注意：
 * 新创建的wyCoverFlow对象的默认前景cover大小为（0,0）,开发者需要手动调用set方法来设置
 * 前景大小，前景cover和左右第一个cover间的距离，左右后景cover间的距离，后景z坐标等。
 * \endif
 */
class WIENGINE_API wyCoverFlow : public wyNode {
	friend class wyCoverFlowAction;

private:
	/// vertex of cover
	struct SVertex {
		wyVertex3D p;
		wyVertex3D n;
		wyColor4F c;
		wyPoint	t;
	};

private:
	/**
	 * \if English
	 * flag, to identify whether VBO is supported
	 * \else
	 * 标识是否支持VBO
	 * \endif
	 */
    bool        m_fVBOSupported;
	
    /**
     * \if English
     * flag, to identify whether the opengl version is retrieved
     * \else
     * 版本号获得标志，true表示已经获得
     * \endif
     */
	bool		m_fVersionGot;

	/**
	 * \if English
	 * point to the head of the dual linked list
	 * \else
	 * 双向链表头
	 * \endif
	 */
    wyCover*    m_coverListHead;
	
    /**
     * \if English
     * point to the tail of the dual linked list
     * \else
     * 双向链表尾
     * \endif
     */
    wyCover*    m_coverListTail;
	
    /**
     * \if English
     * the front cover
     * \else
     * 前景cover, 即居中最前显示的cover
     * \endif
     */
    wyCover*    m_frontCover;

    /**
     * \if English
     * x coordinate of the position where to put the front cover, by default it is at the original point
     * \else
     * 前景cover中心位置x坐标，默认在原点
     * \endif
     */
    float       m_frontCenterX;
	
    /**
     * \if English
     * y coordinate of the position where to put the front cover, by default it is at the original point
     * \else
     * 前景cover中心位置x坐标，默认在原点
     * \endif
     */
    float       m_frontCenterY;
	
    /**
     * \if English
     * the width of the front cover
     * \else
     * 前景cover宽度
     * \endif
     */
    float       m_frontWidth;
	
    /**
     * \if English
     * the height of the front cover
     * \else
     * 前景cover高度
     * \endif
     */
    float       m_frontHeight;
	
    /**
     * \if English
     * the count of visible covers on the left of the front cover
     * \else
     * 前景cover左侧可见的cover数量
     * \endif
     */
    int         m_countLeftVisible;
	
    /**
     * \if English
     * the count of visible covers on the right of the front cover
     * \else
     * 前景cover右侧可见的cover数量
     * \endif
     */
    int         m_countRightVisible;
	
    /**
     * \if English
     * the space between the left back covers
     * \else
     * 左侧后景cover在x轴上的间距
     * \endif
     */
    float       m_leftCoverCenterDelta;

    /**
     * \if English
     * the space between the right back covers
     * \else
     * 右侧后景cover在x轴上的间距
     * \endif
     */
    float       m_rightCoverCenterDelta;
	
    /**
     * \if English
     * the space between the first left back cover and the front cover
     * \else
     * 左侧第一张后景cover和前景cover在x轴上的距离
     * \endif
     */
    float       m_firstLeftCoverCenterOffset;

    /**
     * \if English
     * the space between the first right back cover and the front cover
     * \else
     * 右侧第一张后景cover和前景cover在x轴上的距离
     * \endif
     */
    float       m_firstRightCoverCenterOffset;
	
    /**
     * \if English
     * the degree the left back covers will rotate by around the Y axis
     * \else
     * 左侧后景cover绕Y轴旋转的角度
     * \endif
     */
	float		m_rotateDegreeLeft;
	
	/**
	 * \if English
	 * the degree the right back covers will rotate by around the Y axis
	 * \else
	 * 右侧后景cover绕Y轴旋转的角度
	 * \endif
	 */
	float		m_rotateDegreeRight;
	
	/**
	 * \if English
	 * flag, identify whether to enable mirror effect
	 * \else
	 * 镜像启用标识
	 * \endif
	 */
    bool        m_bMirrorEnabled;
	
    /**
     * \if English
     * the z position of the back covers
     * \else
     * 后景cover的z轴坐标
     * \endif
     */
    float       m_depthZ;

    /**
     * \if English
     * flag, identify whether the moving animation is running
     * \else
     * 动画播放标识，true表示正在播放动画
     * \endif
     */
    bool            m_bIsShowing;

    /**
     * \if English
     * flag, identify whether the vertices are initialized
     * \else
     * 标识顶点数组是否已被初始化
     * \endif
     */
    bool            m_bVerticeInited;
	
    /**
     * \if English
     * to store vertices info
     * \else
     * 顶点数组
     * \endif
     */
    struct SVertex  m_coverPoints[32];
	
    /**
     * \if English
     * to store the texture coordinates
     * \else
     * 贴图坐标数组，当图片实际小与在opengl中的贴图大小不一样时启用
     * \endif
     */
    wyPoint         m_texCoordsReal[32];

	/**
	 * \if English
	 * flag, identify how the blurred width is calculated
	 * \else
	 * 模糊边缘设置方式选择，是按照百分比还是像素
	 * \endif
	 */
	bool 			m_borderUsePercent;
	
	/**
	 * \if English
	 * specify the blurred edge width using percent
	 * \else
	 * 模糊边缘，为百分比
	 * \endif
	 */
    float           m_fBorderPercent;
	
    /**
     * \if English
     * the width of blurred border
     * \else
     * 模糊边缘，为像素宽度
     * \endif
     */
    float           m_fBorderWidth;
	
    /**
     * \if English
     * to store the indexing info
     * \else
     * 索引数组
     * \endif
     */
	unsigned short  m_indicesAll[108];
	
	/**
	 * \if English
	 * VBO name in opengl
	 * \else
	 * VBO名字
	 * \endif
	 */
    GLuint	        m_uiVbo;

    /**
     * \if English
     * VBO array name in opengl
     * \else
     * VBO array名字
     * \endif
     */
    GLuint	        m_uiAllIndexVbo;

    /**
     * \if English
     * the projection matrix of this node
     * \else
     * 透视投影矩阵
     * \endif
     */
	Matrix44		m_projectionMatrix;
	
	/**
	 * \if English
	 * the modelview matrix of this node
	 * \else
	 * 当前node坐标系所用的模式视图矩阵
	 * \endif
	 */
	Matrix44		m_modelViewMatrix;
	
	/**
	 * \if English
	 * to mark whether the matrix is valid
	 * \else
	 * 标识当前视图和投影矩阵是否可用
	 * \endif
	 */
	bool			m_isMatrixValid;

	/**
	 * \if English
	 * to mark whether the underlying graphic chip supports matrix query.
	 * If the running device does't support this, the hit test behavior may not work
	 * \else
	 * 标示当前设备是否支持矩阵查询操作，如果不支持，cover的点击行为可能不正常
	 * \endif
	 */
	bool 			m_isMartixQuerySupported;

	/**
	 * \if English
	 * the height between the mirror and the original image
	 * \else
	 * 镜像和原图的间距
	 * \endif
	 */
	float m_heightFromMirror;

	/**
	 * \if English
	 * the brightness of the mirror
	 * \else
	 * 设置镜像的明亮度
	 * \endif
	 */
	float m_brightLevelOfMirror;

	/**
	 * \if English
	 * to store the current view port being used
	 * \else
	 * 保存当前视口
	 * \endif
	 */
	wyRect m_viewPort;

private:
	/**
	 * \if English
	 * draw the mesh
	 * \else
	 * 以原点为中心绘制cover
	 * \endif
	 */
    void drawMesh(float ratioX, float ratioY);
	
	/**
	 * \if English
	 * to initialize the vertices array
	 * \else
	 * 初始化顶点数组
	 * \endif
	 */	
    void initVertices();

	/**
	 * \if English
	 * draw one cover
	 * \else
	 * 绘制cover
	 * \endif
	 */		
    void drawCover(wyCover* cover);

	/**
	 * \if English
	 * draw the front cover
	 * \else
	 * 绘制前景cover
	 * \endif
	 */	
    void drawFrontCover() { drawCover(m_frontCover); }

	/**
	 * \if English
	 * draw the left back covers
	 * \else
	 * 绘制左侧的后景cover
	 * \endif
	 */		
    void drawLeftCovers();
	
	/**
	 * \if English
	 * draw the right back covers
	 * \else
	 * 绘制右侧的后景cover
	 * \endif
	 */		
    void drawRightCovers();
	
	/**
	 * \if English
	 * get the most left visible cover
	 * \else
	 * 获得最左侧可显示的cover
	 * \endif
	 */		
    wyCover* getMostLeftToShow();

	/**
	 * \if English
	 * get the most right visible cover
	 * \else
	 * 获得最右侧可显示的cover
	 * \endif
	 */			
    wyCover* getMostRightToShow();
	
	/**
	 * \if English
	 * set the front cover
	 * \else
	 * 设置前景cover
	 * \endif
	 */		
    void setFrontCover(wyCover* frontCover) { m_frontCover = frontCover; }

	/**
	 * \if English
	 * to update covers while moving left
	 *
	 * @param[in] t the value falls between 0 and 1, 0 means begin and 1 means end
	 * \else
	 * 根据t值更新cover的位置，以动画方式朝左移动一个cover
	 *
	 * @param[in] t t取值为0到1，0表示开始，1表示结束
	 * \endif
	 */
    void stepLeftUpdate(float t);
	
	/**
	 * \if English
	 * to update covers while moving right
	 *
	 * @param[in] t the value falls between 0 and 1, 0 means begin and 1 means end
	 * \else
	 * 根据t值更新cover的位置，以动画方式朝右移动一个cover
	 *
	 * @param[in] t t取值为0到1，0表示开始，1表示结束
	 * \endif
	 */	
    void stepRightUpdate(float t);

	/**
	 * \if English
	 * multiplication of two matrixes, result = m1 * m2
	 *
	 * @param[in] m1 matrix of 4x4
	 * @param[in] m2 matrix of 4x4
	 * @param[out] result matrix of 4x4
	 * \else
	 * 矩阵相乘， result = m1 * m2
	 * 
	 * @param[in] m1 4乘4矩阵
	 * @param[in] m2 4乘4矩阵
	 * @param[out] result 4乘4矩阵，用来保存返回结果
	 * \endif
	 */
	void matrixMulti(Matrix44 m1, Matrix44 m2, Matrix44 result);

	/**
	 * \if English
	 * multiplication of two matrixes, result = m1 * m2
	 *
	 * @param[in] m1 matrix of 1x4
	 * @param[in] m2 matrix of 4x4
	 * @param[out] result matrix of 1x4
	 * \else
	 * 矩阵相乘， result = m1 * m2
	 * 
	 * @param[in] m1 1乘4矩阵
	 * @param[in] m2 4乘4矩阵
	 * @param[out] result 1乘4矩阵，用来保存返回结果
	 * \endif
	 */
	void matrixMulti2(Matrix14 m1, Matrix44 m2, Matrix14 result);

	/**
	 * \if English
	 * to perform matrix translation, result = transform matrix * curMatrix
	 *
	 * @param[in] curMatrix matrix of 4x4
	 * @param[out] result matrix of 4x4
	 * @param[in] v to specify the transformation
	 * \else
	 * 执行平移，当前矩阵乘以平移矩阵，即result = 平移矩阵 * curMatrix
	 * 
	 * @param[in] curMatrix 4乘4矩阵， 当前modelview矩阵
	 * @param[out] result 4乘4矩阵，用来保存返回结果
	 * @param[in] v 其x, y, z指定平移坐标
	 * \endif
	 */
	void matrixTranslate(Matrix44 curMatrix, Matrix44 result, wyVertex3D v);

	/**
	 * \if English
	 * to perform matrix translation, result = rotation matrix * curMatrix
	 *
	 * @param[in] curMatrix matrix of 4x4
	 * @param[out] result matrix of 4x4
	 * @param[in] degree the degree of rotation
	 * \else
	 * 执行绕Y轴旋转，当前矩阵乘以旋转矩阵，即result = 旋转矩阵 * curMatrix
	 * 
	 * @param[in] curMatrix 4乘4矩阵，当前modelview矩阵
	 * @param[out] result 4乘4矩阵，用来保存返回结果
	 * @param[in] degree 绕Y轴旋转角度
	 * \endif
	 */
	void matrixRotateY(Matrix44 curMatrix, Matrix44 result, float degree);

	/**
	 * \if English
	 * to perform matrix translation, result = scale matrix * curMatrix
	 *
	 * @param[in] curMatrix matrix of 4x4
	 * @param[out] result matrix of 4x4
	 * @param[in] scale scale
	 * \else
	 * 执行放大，当前矩阵乘以放大矩阵，即result = 放大矩阵 * curMatrix
	 * 
	 * @param[in] curMatrix 4乘4矩阵， 当前modelview矩阵
	 * @param[out] result 4乘4矩阵，用来保存返回结果
	 * @param[in] scale 放大系数
	 * \endif
	 */
	void matrixScale(Matrix44 curMatrix, Matrix44 result, float scale);

	/**
	 * \if English
	 * convert clip coordinates to Normalized Device Coordinates
	 *
	 * @param[in,out] vertex the vertex to be converted
	 * \else
	 * 将投影变换后的clip coordinates转换为NDC（normalized device coordinates）
	 * 
	 * @param[in,out] vertex 1乘4矩阵，待转换的4D点
	 * \endif
	 */
	void convertToNDC(Matrix14 vertex);

	/**
	 * \if English
	 * to get the 2 dimension area of the cover on the screen
	 *
	 * @param[in] cover \link wyCover wyCover\endlink
	 * @param[in,out] quad \link wyQuad2D wyQuad2D\endlink
	 * @return true means success, or else failure
	 * \else
	 *
	 * 获得cover在屏幕上的显示区域
	 * 
	 * @param[in] cover 指定要获得哪一个cover的矩形显示区域
	 * @param[in,out] quad 矩形区域
	 * @return true表示成功，否则失败
	 * \endif
	 */
	bool getCoverWindowQuad(wyCover* cover, wyQuad2D* quad);

	/**
	 * \if English
	 * test whether a point is inside a quad
	 *
	 * @param[in] x x coordinate of the point
	 * @param[in] y y coordinate of the point
	 * @param[in] quad \link wyQuad2D wyQuad2D\endlink
	 * @return true means the point is inside the quad
	 * \else
	 * 判断点(x,y)是否在quad内部
	 * 
	 * @param[in] x 点x坐标
	 * @param[in] y 点y坐标
	 * @param[in] quad 2D区域
	 * 
	 * @return true表示在quad的内部，否则不在内部
	 * \endif
	 */	
	bool isPointInsideQuad(float x, float y, wyQuad2D* quad);

	/**
	 * \if English
	 * Get a cover's model view matrix
	 *
	 * @param[in] cover \link wyCover wyCover\endlink
	 * @param[out] ret matrix of 4x4
	 *
	 * @return true means success, or else failure
	 * \else
	 * 获得cover的模型视图矩阵
	 *
	 * @param[in] cover 指定哪个cover
	 * @param[out] ret 4乘4矩阵，用来保存返回结果
	 *
	 * @return true表示成功，否则失败
	 * \endif
	 */		
	bool getModelviewMatrix(wyCover* cover, Matrix44 ret);

	/**
	 * \if English
	 * to get the projection matrix of this node
	 *
	 * @param[out] ret matrix of 4x4
	 * @return true means success, or else failure
	 * \else
	 * 获得当前coverflow节点的投影矩阵
	 *
	 * @param[out] ret 4乘4矩阵，用来保存返回结果
	 *
	 * @return true表示成功，否则失败
	 * \endif
	 */			
	bool getProjectionMatrix(Matrix44 ret);	
	
public:
	/**
	 * \if English
	 * factory function, used to create a new instance with autoRelease enabled
	 * \else
	 * 静态方法，新创建一个wyCoverFlow对象
	 * \endif
	 */
	static wyCoverFlow* make();

	/**
	 * \if English
	 * constructor
	 * \else
	 * 构造函数
	 * \endif
	 */
    wyCoverFlow();

    /**
     * \if English
     * destructor
     * \else
     * 析构函数
     * \endif
     */
    virtual ~ wyCoverFlow();

    /**
     * \if English
     * to add a cover to the tail of the list
     * \else
     * 增加一个cover到链表尾部
     * \endif
     */
    void addCover(wyCover* cover);
	
    /**
     * \if English
     * to remove a cover from the list
     * \else
     * 删除一个cover
     * \endif
     */
    void removeCover(wyCover* cover);
	
	/**
	 * \if English
	 * to insert a cover
	 *
	 * @param[in] cover the cover to be inserted
	 * @param[in] after the cover after which the new cover will be inserted
	 * \else
	 * 在指定位置增加一个cover
	 *
	 * @param[in] cover 待增加的cover
	 * @param[in] after 指定将cover加到哪一个前面
	 * \endif
	 */		
    void insertCoverBefore(wyCover* cover, wyCover* after);

	/**
	 * \if English
	 * to get the cover's index in the list, the head's index is zero
	 * \else
	 * 获得cover在链表中的索引，链表头的索引是0，以后依次加1
	 * 如果链表执行了添加或删除操作，同一个cover可能前后会返回不同的索引值，
	 * 使用时要注意这点。
	 * \endif
	 */
    int getIndex(wyCover* cover);
	
	/**
	 * \if English
	 * to get the cover according to the index
	 * \else
	 * 根据索引返回一个cover指针，链表头的索引是0，以后依次加1。
	 * 如果链表执行了添加或删除操作，相同的索引可能前后会返回不同的cover，
	 * 使用时要注意这点。
	 * \endif
	 */
	wyCover* getCoverAt(int index);
	
	/**
	 * \if English
	 * to get the list head
	 * \else
	 * 获得链表头指针
	 * \endif
	 */
    wyCover* getCoverList() { return m_coverListHead; }

    /**
     * \if English
     * to get the front cover
     * \else
     * 获得当前前景cover
     * \endif
     */
    wyCover* getFrontCover() { return m_frontCover; }

	/**
	 * \if English
	 * to set the front cover size
	 *
	 * @param[in] width width, in pixels
	 * @param[in] height height, in pixels
	 * @param[in] updateOthers true means m_depthZ, m_firstLeftCoverCenterOffset, m_firstRightCoverCenterOffset
	 * m_leftCoverCenterDelta, m_rightCoverCenterDelta will be recalculated.
	 * \else
	 * 设置前景cover的大小
	 *
	 * @param[in] width 宽度，单位为像素
	 * @param[in] height 高度，单位为像素
	 * @param[in] updateOthers true表示会根据新大小自动调整后景z坐标，左右第一个和前景cover的距离，左右后景cover间的距离				
	 * \endif
	 */	
    void setFrontCoverSize(float width, float height, bool updateOthers = true);
	
	/**
	 * \if English
	 * to set the position of the front cover, by default it is at the original point
	 *
	 * @param[in] centerX x coordinate, in pixels
	 * @param[in] centerY y coordinate, in pixels
	 * \else
	 * 在当前坐标系中设置前景cover中心位置，默认为原点
	 *
	 * @param[in] centerX x坐标，单位为像素
	 * @param[in] centerY y坐标，单位为像素
	 * \endif
	 */		
    void setFrontCenterPosition(int centerX, int centerY) { m_frontCenterX = centerX; m_frontCenterY = centerY; }
	
    /**
     * \if English
     * the set the count of visible covers on the left wing
     * \else
     * 设置前景cover左边的cover显示数量
     * \endif
     */
    void setCountLeftVisible(int count) { m_countLeftVisible = count; } 
	
    /**
     * \if English
     * getter
     * \else
     * 获得前景cover左边的cover显示数量
     * \endif
     */
    int getCountLeftVisible() { return m_countLeftVisible; } 
	
    /**
     * \if English
     * to set the count of visible covers on the right wing
     * \else
     * 设置前景cover右边的cover显示数量
     * \endif
     */
    void setCountRightVisible(int count) { m_countRightVisible = count; } 
	
    /**
     * \if English
     * getter
     * \else
     * 获得前景cover右边的cover显示数量
     * \endif
     */
    int getCountRightVisible() { return m_countRightVisible; } 	
	
    /**
     * \if English
     * to get whether the mirror is enabled
     * \else
     * 判断是否镜像效果启用，true表示启用
     * \endif
     */
    bool isMirrorEnabled() { return m_bMirrorEnabled; }
	
	/**
	 * \if English
	 * to set whether to enable the mirror effect
	 *
	 * @param[in] bEnbale true meas enabled
	 * \else
	 * 设置是否启用镜像效果
	 *
	 * @param[in] bEnable true表示启用
	 * \endif
	 */		
    void setMirrorEnable(bool bEnable) { m_bMirrorEnabled = bEnable; }

	/**
	 * \if English
	 * set the width of the blurred border
	 *
	 * @param[in] percent a percent value which is between 0 and 1.
	 * \else
	 * 设置边缘模糊效果
	 *
	 * @param[in] percent 百分比，取值为0到1
	 * \endif
	 */		
    void setBlurredBorderWidth(float percent) { m_fBorderPercent = percent; m_borderUsePercent = true; m_bVerticeInited = false; }

	/**
	 * \if English
	 * set the width of the blurred border
	 *
	 * @param[in] width in pixels
	 * \else
	 * 设置边缘模糊效果
	 *
	 * @param[in] width 模糊边缘宽度，单位为像素
	 * \endif
	 */		
    void setBlurredBorderWidthInPixels(int width) { m_fBorderWidth = width; m_borderUsePercent = false; m_bVerticeInited = false; }	
	
	/**
	 * \if English
	 * to set the z depth of the back covers
	 * \@param[in] z
	 * \else
	 * 设置后景cover的z坐标
	 *
	 * @param[in] z z坐标，注意，如为正值或过小的负值，可能会不能正常显示
	 * \endif
	 */		
    void setDepthZ(float z) { m_depthZ = z; }		

	/**
	 * \if English
	 * getter
	 * \else
	 * 获得后景cover的z坐标
	 * \endif
	 */		
    float getDepthZ() { return m_depthZ; }

	/**
	 * \if English
	 * set the distance between the front cover and the first left cover
	 *
	 * @param[in] offset must be positive
	 * \else
	 * 设置左侧第一个cover的中心点和前景cover中心点的距离
	 *
	 * @param[in] offset 必须为正值
	 * \endif
	 */		
    void setFirstLeftOffset(float offset) { m_firstLeftCoverCenterOffset = offset; }		

	/**
	 * \if English
	 * getter
	 * \else
	 * 获得左侧第一个cover的中心点和前景cover中心点的距离
	 * \endif
	 */		
    float getFirstLeftOffset() { return m_firstLeftCoverCenterOffset; }	

	/**
	 * \if English
	 * set the distance between the front cover and the first right cover
	 *
	 * @param[in] offset must be positive
	 * \else
	 * 设置右侧第一个cover的中心点和前景cover中心点的距离
	 *
	 * @param[in] offset 必须为正值
	 * \endif
	 */		
    void setFirstRightOffset(float offset) { m_firstRightCoverCenterOffset = offset; }		

	/**
	 * \if English
	 * getter
	 * \else
	 * 获得右侧第一个cover的中心点和前景cover中心点的距离
	 * \endif
	 */		
    float getFirstRightOffset() { return m_firstRightCoverCenterOffset; }	

	/**
	 * \if English
	 * set the space between the left back covers
	 *
	 * @para[in] delta must be positive
	 * \else
	 * 设置左侧第一个cover之后的后景cover之间的距离
	 *
	 * @param[in] delta 必须为正值
	 * \endif
	 */		
    void setLeftCoverCenterDelta(float delta) { m_leftCoverCenterDelta = delta; }		

	/**
	 * \if English
	 * getter
	 * \else
	 * 获得左侧第一个cover之后的后景cover之间的距离
	 * \endif
	 */		
    float getLeftCoverCenterDelta() { return m_leftCoverCenterDelta; }

	/**
	 * \if English
	 * set the space between the right back covers
	 *
	 * @param[in] delta must be positive
	 * \else
	 * 设置右侧第一个cover之后的后景cover之间的距离
	 *
	 * @param[in] delta 必须为正值
	 * \endif
	 */		
    void setRightCoverCenterDelta(float delta) { m_rightCoverCenterDelta = delta; }

	/**
	 * \if English
	 * getter
	 * \else
	 * 获得右侧第一个cover之后的后景cover之间的距离
	 * \endif
	 */		
    float getRightCoverCenterDelta() { return m_rightCoverCenterDelta; }

	/**
	 * \if English
	 * set the rotation degree of the left back cover
	 *
	 * @param[in] degree in degrees, right hand rule applies
	 * \else
	 * 设置左侧后景cover绕Y轴旋转的角度
	 *
	 * @param[in] degree 单位为度，右手规则
	 * \endif
	 */		
    void setRotateDegreeLeft(float degree) { m_rotateDegreeLeft = degree; }		

	/**
	 * \if English
	 * getter
	 * \else
	 * 获得左侧后景cover绕Y轴旋转的角度
	 * \endif
	 */		
    float getRotateDegreeLeft() { return m_rotateDegreeLeft; }		
	
	/**
	 * \if English
	 * set the rotation degree of the right back covers
	 *
	 * @param[in] degree in degrees, right hand rule applies
	 * \else
	 * 设置右侧后景cover绕Y轴旋转的角度
	 *
	 * @param[in] degree 单位为度，右手规则
	 * \endif
	 */		
    void setRotateDegreeRight(float degree) { m_rotateDegreeRight = degree; }		

	/**
	 * \if English
	 * getter
	 * \else
	 * 获得右侧后景cover绕Y轴旋转的角度
	 * \endif
	 */		
    float getRotateDegreeRight() { return m_rotateDegreeRight; }	
	
	/**
	 * \if English
	 * to set the cover to be the front cover by running an animation
	 *
	 * @param[in] cover the cover to be the front cover
	 * @param[in] duration duration of the animation, in seconds
	 * \else
	 * 显示cover为前景cover
	 *
	 * @param[in] cover 要设置为前景cover的cover
	 * @param[in] duration 动画时间，即把cover移动到前景cover的时间
	 * \endif
	 */		
    void showCover(wyCover* cover, float duration = 0.0f);
	
	/**
	 * \if English
	 * move left by one cover
	 *
	 * @param [in] duration in seconds
	 * \else
	 * 向左移动一个cover
	 *
	 * @param[in] duration 动画时间
	 * \endif
	 */
    void moveLeft(float duration = 0.0f);

	/**
	 * \if English
	 * move right by one cover
	 *
	 * @param[in] duration in seconds
	 * \else
	 * 向右移动一个cover
	 *
	 * @param[in] duration 动画时间
	 * \endif
	 */	
    void moveRight(float duration = 0.0f);
	
	/**
	 * \if English
	 * get which cover is hit
	 *
	 * @param[in] x x coordinate of touch event
	 * @param[in] y y coordinate of touch event
	 * \else
	 * 获得哪个cover被点中
	 *
	 * @param[in] x touch事件的x坐标
	 * @param[in] y touch事件的y坐标
	 *
	 * @return 被点中的cover
	 * \endif
	 */			
	wyCover* getTouchedCover(float x, float y);

	/**
	 * \if English
	 * set the distance between the mirror image and the original image
	 *
	 * @param[in] height in pixels
	 * \else
	 * 设置镜像和原图的间距
	 *
	 * @param[in] height 间距，单位为像素
	 * \endif
	 */
	void setHeightFromMirror(float height);

	/**
	 * \if English
	 * getter
	 * \else
	 * 获得镜像和原图的间距
	 * \endif
	 */
	float getHeightFromMirror() { return m_heightFromMirror; };

	/**
	 * \if English
	 * set the brightness of the mirror
	 *
	 * @param[in] level brightness, the value is between 0 and 1
	 * \else
	 * 设置镜像的明亮度
	 *
	 * @param[in] level 明亮度值，取值为[0,1]
	 * \endif
	 */
	void setBrightLevelOfMirror(float level);

	/**
	 * \if English
	 * getter
	 * \else
	 * 获得镜像的明亮度
	 * \endif
	 */
	float getBrightLevelOfMirror() { return m_brightLevelOfMirror; }

	/// @see wyNode::draw()
    virtual void draw();
};

#endif
