#ifndef __wyRectAStarMap_h__
#define __wyRectAStarMap_h__

#include "wyAStarMap.h"
#include "wyAStarTile.h"

/**
 * @class wyRectAStarMap
 *
 * A*矩形地图状况tile封装
 */
class WIENGINE_API wyRectAStarMap : public wyAStarMap {
private:
	/// 横向tile数量
	int m_width;

	/// 纵向tile数量
	int m_height;

	/// true indicating diagonal path will be searched
	bool m_isAllowDiagonal;

public:
	/**
	 * 构造函数
	 *
	 * @param width 横向tile数量
	 * @param height 纵向tile数量
	 * @param isAllowDiagonal 是否允许斜线查找, true为允许
	 */
	wyRectAStarMap(int width, int height, bool isAllowDiagonal);

	/**
	 * 析构函数
	 */
	virtual ~wyRectAStarMap();

	/// @see wyAStarMap::validTile
	virtual bool isValidTile(int x, int y);

	/// @see wyAStarMap::getStepG
	virtual float getStepG(wyAStarTile* t1, wyAStarTile* t2);
};

#endif // __wyRectAStarMap_h__
