#ifndef __wyAStarStep_h__
#define __wyAStarStep_h__

#include "wyObject.h"

/**
 * @class wyAStarStep
 *
 * A*查找路径返回的节点封装
 */
class WIENGINE_API wyAStarStep : public wyObject {
private:
	/// tile x
	int m_x;

	/// tile y
	int m_y;

	/// 节点 f
	float m_f;

	/// 节点 g
	float m_g;

	/// 节点 h
	float m_h;

	/// 父节点 \link wyAStarStep wyAStarStep\endlink对象指针
	wyAStarStep* m_parent;

public:
	/**
	 * 构造函数
	 *
	 * @param x tile x值
	 * @param y tile y值
	 */
	wyAStarStep(int x, int y);

	/**
	 * 析构函数
	 */
	virtual ~wyAStarStep();

	/**
	 * 设置tile x值
	 *
	 * @param x tile x值
	 */
	void setX(int x) { m_x = x; }

	/**
	 * 返回tile x值
	 *
	 * @return tile x值
	 */
	int getX() { return m_x; }

	/**
	 * 设置tile y值
	 *
	 * @param y tile y值
	 */
	void setY(int y) { m_y = y; }

	/**
	 * 返回tile y值
	 *
	 * @return tile y值
	 */
	int getY() { return m_y; }

	/**
	 * 设置节点f值
	 *
	 * @param f 节点f值
	 */
	void setF(float f) { m_f = f; }

	/**
	 * 返回节点f值
	 *
	 * @return 节点f值
	 */
	float getF() { return m_f; }

	/**
	 * 设置节点 h值
	 *
	 * @param h 节点h值
	 */
	void setH(float h) { m_h = h; }

	/**
	 * 返回节点h值
	 *
	 * @return 节点h值
	 */
	float getH() { return m_h; }

	/**
	 * 设置节点 g值
	 *
	 * @param g 节点g值
	 */
	void setG(float g) { m_g = g; }

	/**
	 * 返回节点h值
	 *
	 * @return 节点g值
	 */
	float getG() { return m_g; }

	/**
	 * 设置父节点\link wyAStarStep wyAStarStep\endlink对象指针
	 *
	 * @param node 父节点\link wyAStarStep wyAStarStep\endlink对象指针
	 */
	void setParent(wyAStarStep* node);

	/**
	 * 返回父节点\link wyAStarStep wyAStarStep\endlink对象指针
	 *
	 * @return 父节点\link wyAStarStep wyAStarStep\endlink对象指针
	 */
	wyAStarStep* getParent() { return m_parent; }
};

#endif // __wyAStarStep_h__
