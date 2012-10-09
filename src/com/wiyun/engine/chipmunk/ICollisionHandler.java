package com.wiyun.engine.chipmunk;

/**
 * 碰撞事件处理器
 */
public interface ICollisionHandler {
	/**
	 * 在两个物体开始接触之前调用，返回0表示要chipmunk忽略这次碰撞，且preSolve和postSolve
	 * 都不会再被调用，但是separate仍然会被调用。
	 * 
	 * @param arbiterPointer Arbiter底层结构指针
	 * @param spacePointer Space底层结构指针
	 * @param data 附加数据
	 * @return 返回0表示要chipmunk忽略这次碰撞，非0表示计算这次碰撞
	 */
	public int begin(int arbiterPointer, int spacePointer, Object data);
	
	/**
	 * 两个物体正在接触，但是它们产生的这次碰撞参数还没有被计算出来，返回0表示要chipmunk忽略这次碰撞。
	 * 
	 * @param arbiterPointer Arbiter底层结构指针
	 * @param spacePointer Space底层结构指针
	 * @param data 附加数据
	 * @return 返回0表示要chipmunk忽略这次碰撞，非0表示计算这次碰撞
	 */
	public int preSolve(int arbiterPointer, int spacePointer, Object data);
	
	/**
	 * 两个物体正在接触，它们产生的这次碰撞已经被处理，在postSolve时，你可以得到这次
	 * 碰撞的力度。
	 * 
	 * @param arbiterPointer Arbiter底层结构指针
	 * @param spacePointer Space底层结构指针
	 * @param data 附加数据
	 */
	public void postSolve(int arbiterPointer, int spacePointer, Object data);
	
	/**
	 * 两个物体刚开始分离。如果一个物体从空间中被删除，则这个方法也会被调用。
	 * 
	 * @param arbiterPointer Arbiter底层结构指针
	 * @param spacePointer Space底层结构指针
	 * @param data 附加数据
	 */
	public void separate(int arbiterPointer, int spacePointer, Object data);
}
