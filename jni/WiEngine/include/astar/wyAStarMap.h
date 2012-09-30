#ifndef __wyAStarMap_h__
#define __wyAStarMap_h__

#include "wyAStarTile.h"
#include "wyArray.h"
#include "wyObject.h"
#include <stdlib.h>

/**
 * @class wyAStarMap
 *
 * A*地图状况父类封装
 */
class WIENGINE_API wyAStarMap : public wyObject {
private:
	static bool releaseTile(wyArray* arr, void* ptr, int index, void* data);

protected:
	/// 保存所有tile对象的\link wyArray wyArray\endlink对象指针,封装\link wyAStarTile wyAStarTile\endlink
	wyArray* m_tiles;

public:
	/**
	 * 构造函数
	 */
	wyAStarMap();

	/**
	 * 析构函数
	 */
	virtual ~wyAStarMap();

	/**
	 * 返回tile数量
	 *
	 * @return　tile数量
	 */
	int getTileCount() { return m_tiles->num; }

	/**
	 * 设置tile为block状态
	 *
	 * @param x tile　x值
	 * @param y tile　y值
	 */
	void blockTile(int x, int y);

	/**
	 * 设置tile为free状态
	 *
	 * @param x tile　x值
	 * @param y tile　y值
	 */
	void freeTile(int x, int y);

	/**
	 * 返回tile是否为block状态
	 *
	 * @param x tile　x值
	 * @param y tile　y值
	 * @return　true为block状态
	 */
	bool isBlockedAt(int x, int y);

	/**
	 * 返回\link wyAStarTile wyAStarTile\endlink对象指针
	 *
	 * @param x tile　x值
	 * @param y tile　y值
	 * @return　\link wyAStarTile wyAStarTile\endlink对象指针
	 */
	wyAStarTile* getTileAt(int x, int y);

	/**
	 * 验证tile是否有效,子类需要实现
	 *
	 * @param x tile　x值
	 * @param y tile　y值
	 * @return　true为有效
	 */
	virtual bool isValidTile(int x, int y) = 0;

	/**
	 * 返回两个tile之间的g(实际代价)值,子类需要实现
	 *
	 * @param t1 \link wyAStarTile wyAStarTile\endlink对象指针
	 * @param t2 \link wyAStarTile wyAStarTile\endlink对象指针
	 * @return　g(实际代价)值
	 */
	virtual float getStepG(wyAStarTile* t1, wyAStarTile* t2) = 0;
};

#endif // __wyAStarMap_h__
