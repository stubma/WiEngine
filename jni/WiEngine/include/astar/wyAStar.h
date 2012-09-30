#ifndef __wyAStar_h__
#define __wyAStar_h__

#include "wyAStarMap.h"
#include "wyAStarStep.h"
#include "wyArray.h"
#include "wyObject.h"
#include <stdlib.h>
#include <stdbool.h>

/**
 * @class wyAStar
 *
 * A*算法封装,根据把地图划分成静态的网格寻找两个点之间的最短路径
 * 算法根据所有点的f(n) = h(n) + g(n)查找最短路径
 * 参考资料 http://baike.baidu.com/view/7850.html
 */
class WIENGINE_API wyAStar : public wyObject {
private:
	/// A* 地图状况封装
	wyAStarMap* m_mapdata;

	wyArray* m_steps;

	wyAStarStep* nodeInArray(wyArray* arr, int x, int y);

	wyAStarStep* findLowestCostNode(wyArray* arr);

	static bool releaseNode(wyArray* arr, void* ptr, int index, void* data);

public:
	/**
	 * 构造函数
	 *
	 * @param mapdata A* 地图状况\link wyAStarMap wyAStarMap\endlink对象指针指针,在AStar析构中会释放该资源
	 */
	wyAStar(wyAStarMap* mapdata);

	/**
	 * 析构函数
	 */
	virtual ~wyAStar();

	/**
	 * 返回路径\link wyArray wyArray\endlink对象指针, 保存路径\link wyAStarStep wyAStarStep\endlink节点集合
	 *
	 * @return 路径\link wyArray wyArray\endlink对象指针
	 */
	wyArray* getPath() { return m_steps; }

	/**
	 * 路径查询,返回路径步骤数,0表示没有路径
	 *
	 * @param startx 起始tile　x值
	 * @param starty 起始tile　y值
	 * @param endx   目标tile　x值
	 * @param endy   目标tile　y值
	 * @param ignoreBlock   是否忽略block tile,true为忽略
	 * @return 路径步骤数,0表示没有路径
	 */
	int findPath(int startx, int starty, int endx, int endy, bool ignoreBlock);

	/**
	 * 返回地图状况\link wyAStarMap wyAStarMap\endlink对象指针
	 *
	 * @return mapdata A* 地图状况\link wyAStarMap wyAStarMap\endlink对象指针
	 */
	wyAStarMap* getAStarMap() { return m_mapdata; }

	/**
	 * 计算两个tile之间的h值,默认取两节点间欧几理德距离（直线距离）做为估价值，可被子类重载
	 *
	 * @param startx 起始tile　x值
	 * @param starty 起始tile　y值
	 * @param endx   目标tile　x值
	 * @param endy   目标tile　y值
	 * @return 两个tile的h值
	 */
	virtual float heuristic(int startx, int starty, int endx, int endy);
};

#endif // __wyAStar_h__
