#ifndef __wyHexagonAStarMap_h__
#define __wyHexagonAStarMap_h__

#include "wyAStarMap.h"
#include "wyAStarTile.h"

/**
 * @class wyHexagonAStarMap
 *
 * A*六边形地图状况tile封装
 */
class WIENGINE_API wyHexagonAStarMap : public wyAStarMap {
private:
	/// 横向tile数量
	int m_width;

	/// 纵向tile数量
	int m_height;

public:
	/**
	 * 构造函数
	 *
	 * @param width 横向tile数量
	 * @param height 纵向tile数量
	 */
	wyHexagonAStarMap(int width, int height);

	/**
	 * 析构函数
	 */
	virtual ~wyHexagonAStarMap();

	/// @see wyAStarMap::validTile
	virtual bool isValidTile(int x, int y);

	/// @see wyAStarMap::getStepG
	virtual float getStepG(wyAStarTile* t1, wyAStarTile* t2);
};

#endif // __wyHexagonAStarMap_h__
