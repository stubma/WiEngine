#ifndef __wyBox2DPELoader_H__
#define __wyBox2DPELoader_H__

#include "wyArray.h"
#include "wyHashSet.h"
#include "wyBox2D.h"

typedef unsigned char xmlChar;

class wyBox2DPELoader;

/**
 * @class wyB2BodyMeta
 *
 * \if English
 * meta data of b2Body
 * \else
 * 用来保存box2d的body描述信息
 * \endif
 */
class BOX2D_API wyB2BodyMeta : public wyObject {
	friend class wyBox2DPELoader;

private:
	/**
	 * \if English
	 * all fixtures of a body
	 * \else
	 * 数组，保存box2d body的所有fixture信息
	 * \endif
	 */
	wyArray* m_arrayFixturedef;

	/**
	 * \if English
	 * anchor point of body
	 * \else
	 * box2d body的锚点
	 * \endif
	 */
	wyPoint	 m_anchorPoint;

	/**
	 * \if English
	 * add a fixture
	 * \else
	 * 向数组中添加一个fixture信息
	 * \endif
	 */
	void addFixtureDef(b2FixtureDef* def);

public:
	/**
	 * \if English
	 * constructor
	 *
	 * @param name body name
	 * \else
	 * 构造函数
	 *
	 * @param name body名
	 * \endif
	 */
	wyB2BodyMeta(const char* name);

	virtual ~wyB2BodyMeta();

	/**
	 * \if English
	 * create a new body in world
	 *
	 * @param box2d \link wyBox2D wyBox2D\endlink
	 * \else
	 * 在box2d的world内创建一个新body
	 *
	 * @param box2d \link wyBox2D wyBox2D\endlink
	 * \endif
	 */
	b2Body* createBody(wyBox2D* box2d);
};

/**
 * @class wyBox2DPELoader
 *
 * \if English
 * loader of Physics Editor file
 * \else
 * 从工具PhysicsEditor的导出文件加载box2d物体信息
 * \endif
 */
class BOX2D_API wyBox2DPELoader : public wyObject {
private:
	/**
	 * \if English
	 * hash set of body meta data
	 * \else
	 * 哈希表，保存box2d物体的描述信息
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
	 * ratio of meter to pixel
	 * \else
	 * box2d pixel / meter，每米所对应的像素数
	 * \endif
	 */
	float		m_PTMRatio;

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
	void createFixturesInfo();
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
	wyBox2DPELoader();

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
	wyBox2DPELoader(const char* filePath, bool isFile);

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
	wyBox2DPELoader(int resId);

	virtual ~wyBox2DPELoader();
	
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
	 * @param box2d \link wyBox2D wyBox2D\endlink
	 * @param name body name, must exist in Physics Editor file
	 * \else
	 * 根据名字创建一个box2d物体
	 *
	 * @param box2d wyBox2D类型的节点
	 * @param name 物体名字，不能任意指定，必须是导出文件中存在的物体名
	 * \endif
	 */
	b2Body* createBodyByName(wyBox2D* box2d, const char* name);

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
	 * get how many pixels one meter stands for
	 *
	 * @return pixels for one meter
	 * \else
	 * 获得每米所对应的像素数
	 *
	 * @return 每米的像素数
	 * \endif
	 */
	float getMeterPixels() { return m_PTMRatio; }

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
