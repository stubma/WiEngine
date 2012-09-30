#ifndef __wyChipmunkPELoader_H__
#define __wyChipmunkPELoader_H__

#include "wyArray.h"
#include "wyHashSet.h"
#include "wyChipmunk.h"

typedef unsigned char xmlChar;

class wyChipmunkPELoader;

/**
 * @struct wyCPShapeInfo
 *
 * \if English
 * hold chipmunk shape info
 * \else
 * 用来保存chipmunk的polyshape的信息
 * \endif
 */
typedef struct CHIPMUNK_API wyCPShapeInfo {
	/**
	 * \if English
	 * momentum
	 * \else
	 * 冲量大小
	 * \endif
	 */
	float momentum;

	/**
	 * \if English
	 * area of shape
	 * \else
	 * 面积
	 * \endif
	 */
	float area;

	/**
	 * \if English
	 * offset to centroid
	 * \else
	 * 距离重心的偏移
	 * \endif
	 */
	cpVect offset;

	/**
	 * \if English
	 * radius of circle shape
	 * \else
	 * 半径大小
	 * \endif
	 */
    float radius;
    
	/**
	 * \if English
	 * vertex count
	 * \else
	 * 顶点个数
	 * \endif
	 */
	int vertexCount;

	/**
	 * \if English
	 * vertices of convex
	 * \else
	 * 构成凸多边形的顶点数组
	 * \endif
	 */
	cpVect vertices[];
} wyCPShapeInfo;


typedef cpShapeType enumFixtureType ;

/**
 * @class wyCPFixtureInfo
 *
 * \if English
 * save info of chipmunk shapes
 * \else
 * 保存chipmunk的一组polyshape的共同信息
 * \endif
 */
class CHIPMUNK_API wyCPFixtureInfo : public wyObject {
	friend class wyChipmunkPELoader;
	friend class wyCPBodyMeta;

private:
	/**
	 * \if English
	 * array of shape info
	 * \else
	 * 保存一组polyshape的信息，每个元素为\link wyCPShapeInfo wyCPShapeInfo\endlink类型
	 * \endif
	 */
	wyArray* m_arrayShapes;

	/**
	 * \if English
	 * total mass of shapes
	 * \else
	 * m_arrayShapes内所有shape的质量之和
	 * \endif
	 */
	float m_mass;

	/**
	 * \if English
	 * total momentum of shapes
	 * \else
	 * m_arrayShapes内所有shape的冲量之和
	 * \endif
	 */
	float m_momentum;

	/**
	 * \if English
	 * elasticity of shapes
	 * \else
	 * m_arrayShapes内shape的弹性系数
	 * \endif
	 */
    float m_elasticity;

    /**
     * \if English
     * friction of shapes
     * \else
     * m_arrayShapes内shape的摩擦系数
     * \endif
     */
    float m_friction;

    /**
     * \if English
     * surface velocity of shapes
     * \else
     * m_arrayShapes内shape的surface velocity
     * \endif
     */
    cpVect m_surface_velocity;

    /**
     * \if English
     * group of shapes
     * \else
     * m_arrayShapes内shape所属的group
     * \endif
     */
	cpGroup m_group;

	/**
	 * \if English
	 * layer of shapes
	 * \else
	 * m_arrayShapes内shape所属的layers
	 * \endif
	 */
	cpLayers m_layers;

	/**
	 * \if English
	 * collision type of shapes
	 * \else
	 * m_arrayShapes内shape所的collisionType
	 * \endif
	 */
	cpCollisionType m_collisionType;

	/**
	 * \if English
	 * are shapes sensor?
	 * \else
	 * m_arrayShapes内shape是否是一个sensor
	 * \endif
	 */
	bool m_isSensor;

	/**
	 * \if English
	 * fixture type of shapes
	 * \else
	 * m_arrayShapes内shape的类型
	 * \endif
	 */
	enumFixtureType m_fixture_type;

protected:
	/**
	 * \if English
	 * initialize shapes
	 * \else
	 * 初始化m_arrayShapes数组内的每个shape，计算shape的质量，冲量，面积，重心偏移
	 * \endif
	 */
	void initialize();

public:
	wyCPFixtureInfo();

	virtual ~wyCPFixtureInfo();

	/**
	 * \if English
	 * add a shape
	 * \else
	 * 向数组内添加一个shape信息
	 * \endif
	 */
	void addShapeInfo(wyCPShapeInfo* si);
};

/**
 * @class wyCPBodyMeta
 *
 * \if English
 * meta data of chipmunk body
 * \else
 * 用来保存chipmunk的body描述信息
 * \endif
 */
class CHIPMUNK_API wyCPBodyMeta : public wyObject {
friend class wyChipmunkPELoader;

private:
	/**
	 * \if English
	 * array of fixture info
	 * \else
	 * 数组，保存chipmunk body的所有fixture信息
	 * \endif
	 */
	wyArray* m_arrayFixtureInfo;

	/**
	 * \if English
	 * anchor point of body
	 * \else
	 * chipmunk 刚体的锚点
	 * \endif
	 */
	wyPoint	 m_anchorPoint;

	/**
	 * \if English
	 * mass of body
	 * \else
	 * 刚体质量
	 * \endif
	 */
	float 	 m_mass;

	/**
	 * \if English
	 * momentum of body
	 * \else
	 * 刚体冲量
	 * \endif
	 */
	float 	 m_momentum;

	/**
	 * \if English
	 * add a fixture info
	 *
	 * @param fi \link wyCPFixtureInfo wyCPFixtureInfo\endlink
	 * \else
	 * 向数组中添加一个fixture信息
	 *
	 * @param fi \link wyCPFixtureInfo wyCPFixtureInfo\endlink
	 * \endif
	 */
	void addFixtureInfo(wyCPFixtureInfo* fi);

public:
	/**
	 * \if English
	 * constructor
	 *
	 * @param name body name
	 * \else
	 * 构造函数
	 *
	 * @param name 刚体名
	 * \endif
	 */
	wyCPBodyMeta(const char* name);

	virtual ~wyCPBodyMeta();

	/**
	 * \if English
	 * create a body in chipmunk space
	 *
	 * @param chipmunk \link wyChipmunk wyChipmunk\endlink
	 * \else
	 * 在chipmunk的space内创建一个新刚体
	 *
	 * @param chipmunk wyChipmunk类型的节点
	 * \endif
	 */
	cpBody* createBody(wyChipmunk* chipmunk);
};

/**
 * @class wyChipmunkPELoader
 *
 * \if English
 * loader of Physics Editor file
 * \else
 * 从工具PhysicsEditor的导出文件加载chipmunk刚体信息
 * \endif
 */
class CHIPMUNK_API wyChipmunkPELoader : public wyObject {
private:
	/**
	 * \if English
	 * hash set for body meta data
	 * \else
	 * 哈希表，保存chipmunk物体的描述信息
	 * \endif
	 */
	wyHashSet*	m_bodyMetas;

	/**
	 * \if English
	 * parsing state
	 * \else
	 * plist文件的解析状态
	 * \endif
	 */
	void*  		m_parseState;

	/**
	 * \if English
	 * format of plist file
	 * \else
	 * plist的format
	 * \endif
	 */
	int			m_plistFormat;

	/**
	 * \if English
	 * the scale value used in parsing plist resource
	 * \else
	 * 解析时用到的scale值
	 * \endif
	 */
	float m_resScale;

private:	
	void parse(char* data, int dataLen);
	void createShape();
	void createFixtureInfo();
	wyPoint parsePoint(const char* v, bool withScale = true);
	
    static bool releaseHashElm(void* elt, void* data);
    static int  hashElemEqual(void* ptr, void* elt);
    static void*  hashElemTrans(void* ptr, void* data);

	static void startElement(void* ctx, const xmlChar *name, const xmlChar **atts);
	static void endElement(void* ctx, const xmlChar *name);
	static void characters(void* ctx, const xmlChar *ch, int len);
	static void warning(void* ctx, const char* msg, ...);
	static void error(void* ctx, const char* msg, ...);	

public:
	wyChipmunkPELoader();

	/**
	 * \if English
	 * constructor
	 *
	 * @param filePath path of Physics Editor file
	 * @param isFile true means \c filePath is an absolute path in file system, false means \c filePath is a
	 * 		relative path in assets folder
	 * \else
	 * 构造函数，根据文件路径加载
	 *
	 * @param filePath 工具PhysicsEditor导出文件的路径
	 * @param isFile true表示filePaht为系统路径，false表示asset路径
	 * \endif
	 */
	wyChipmunkPELoader(const char* filePath, bool isFile);

	/**
	 * \if English
	 * constructor
	 *
	 * @param resId resource id of Physics Editor file
	 * \else
	 * 构造函数，根据资源id加载
	 *
	 * @param resId 资源id
	 * \endif
	 */
	wyChipmunkPELoader( int resId);

	virtual ~wyChipmunkPELoader();

	/**
	 * \if English
	 * entry of load function
	 *
	 * @param filePath path of Physics Editor file
	 * @param isFile true means \c filePath is an absolute path in file system, false means \c filePath is a
	 * 		relative path in assets folder
	 * \else
	 * 加载函数，根据文件路径加载
	 *
	 * @param filePath 工具PhysicsEditor导出文件的路径
	 * @param isFile true表示filePaht为系统路径，false表示asset路径
	 * \endif
	 */
	void loadBodies(const char* filePath, bool isFile);
	
	/**
	 * \if English
	 * entry of load function
	 *
	 * @param resId resource id of Physics Editor file
	 * \else
	 * 加载函数，根据资源id加载
	 *
	 * @param resId 资源id
	 * \endif
	 */
	void loadBodies(int resId);

	/**
	 * \if English
	 * create a body by name
	 *
	 * @param chipmunk \link wyChipmunk wyChipmunk\endlink
	 * @param name body name, must exist in Physics Editor file
	 * \else
	 * 根据名字创建一个chipmunk物体
	 *
	 * @param chipmunk wyChipmunk类型的节点
	 * @param name 物体名字，不能任意指定，必须是导出文件中存在的物体名
	 * \endif
	 */
	cpBody* createBodyByName(wyChipmunk* chipmunk, const char* name);

	/**
	 * \if English
	 * get anchor percentage of a body specified by name
	 *
	 * @param name body name, must exist in Physics Editor file
	 * \else
	 * 获得name所指定的物体对应的图片的锚点
	 *
	 * @param name 物体名字，不能任意指定，必须是导出文件中存在的物体名
	 * \endif
	 */
	wyPoint getAnchorPercent(const char* name);	

	/**
	 * \if English
	 * get format of Physics Editor file
	 *
	 * @return format
	 * \else
	 * 获得PhysicsEditor导出文件的格式
	 *
	 * @return 格式
	 * \endif
	 */
	int getPlistFormat() { return m_plistFormat; }
};

#endif
