package com.wiyun.engine.chipmunk;

import java.util.ArrayList;
import java.util.List;

import com.wiyun.engine.types.WYPoint;

/**
 * 空间，可以理解空间是一个世界，是物体的容器，物体在这个空间中运动，
 * 不能跳出这个空间，平行宇宙，就类似这个意思吧。
 */
public class Space {
	/**
	 * 遍历每个刚体，执行某种操作 
	 */
	public static interface IBodyVisitor {
		/**
		 * 对单个刚体进行操作
		 * 
		 * @param bodyPointer Body对象的底层结构指针
		 * @param data 附加数据
		 */
		public void visit(int bodyPointer, Object data);
	}
	
	/**
	 * 提供一种在空间单步后插入操作的接口，如果注册了一个PostStepCallback,
	 * 其将在每次step之后被调用 。单步回调接口是针对单个对象安装的，一般是个
	 * {@link Shape}或者{@link Body}
	 */
	public static interface IPostStepCallback {
		/**
		 * 对某个对象进行单步之后的操作
		 * 
		 * @param obj 相关对象，具体什么类型由callback决定
		 * @param data 附加数据对象
		 */
		public void postStep(Object obj, Object data);
	}
	
	/**
	 * 提供点查询时的回调功能，可以处理所有和该点有碰撞的物体 
	 */
	public static interface IPointQueryCallback {
		/**
		 * 当某个物体匹配时，这个方法会被调用
		 * 
		 * @param shapePointer Shape底层结构指针
		 * @param data 附加数据对象
		 */
		public void onMatch(int shapePointer, Object data);
	}
	
	/**
	 * 提供线段查询时的回调功能，可以处理所有和线段有碰撞的物体 
	 */
	public static interface ISegmentQueryCallback {
		/**
		 * 当某个物体匹配时，这个方法会被调用
		 * 
		 * @param shapePointer Shape底层结构指针
		 * @param distance 物体和线段物体之间的距离
		 * @param normalX 碰撞面法线x方向
		 * @param normalY 碰撞面法线y方向
		 * @param data 附加数据对象
		 */
		public void onMatch(int shapePointer, float distance, float normalX, float normalY, Object data);
	}
	
	/**
	 * Result of segment querying 
	 */
	public static final class SegmentQueryInfo {
		// 和segment发生撞击的物体底层结构指针，如果没有则为null
		public int shapePointer;
		
		// 物体和被查询线段物体之间的距离，值从0到1
		public float distance; 
		
		// 撞击面的法线
		public float normalX; 
		public float normalY; 
	}
	
	// underlying cpSpace struct pointer
	int mPointer;
	
	public static Space from(int pointer) {
		return pointer == 0 ? null : new Space(pointer);
	}
	
	protected Space(int pointer) {
		mPointer = pointer;
	}
	
	public void setPointer(int pointer) {
		mPointer = pointer;
	}
	
	@Override
	public boolean equals(Object o) {
		if(o instanceof Space)
			return ((Space)o).mPointer == mPointer;
		else
			return false;
	}
	
	@Override
	public int hashCode() {
		return mPointer;
	}
	
	/**
	 * 得到所有添加到空间中的刚体的列表
	 * 
	 * @return 刚体的列表
	 */
	public List<Body> getBodies() {
		int[] pointers = new int[getBodyCount()];
		nativeGetBodies(pointers);
		List<Body> bodies = new ArrayList<Body>();
		for(int p : pointers) {
			bodies.add(Body.from(p));
		}
		return bodies;
	}
	
	private native void nativeGetBodies(int[] pointers);
	
	/**
	 * 添加一个单步回调
	 * 
	 * @param callback {@link IPostStepCallback}
	 * @param obj 相关对象，可以为null
	 * @param data 附加数据对象
	 */
	public native void addPostStepCallback(IPostStepCallback callback, Object obj, Object data);
	
	/**
	 * 添加一个碰撞监听器
	 * 
	 * @param collisionType1 碰撞类型1
	 * @param collisionType2 碰撞类型2
	 * @param handler {@link ICollisionHandler}
	 * @param data 附加数据，handler被调用时被传回
	 */
	public native void addCollisionHandler(int collisionType1, int collisionType2, ICollisionHandler handler, Object data);
	
	/**
	 * 删除一个碰撞监听器
	 * 
	 * @param collisionType1 碰撞类型1
	 * @param collisionType2 碰撞类型2
	 */
	public native void removeCollisionHandler(int collisionType1, int collisionType2);
	
	/**
	 * 添加一个形状到空间中
	 * 
	 * @param shape {@link Shape}对象
	 */
	public native void addShape(Shape shape);
	
	/**
	 * 从空间中删除一个物体。这个方法如果在step方法之中调用是不安全的。
	 * 
	 * @param shape {@link Shape}
	 */
	public native void removeShape(Shape shape);
	
	/**
	 * 从空间中删除一个物体，同时释放它的资源。这个方法如果在step方法之中调用是不安全的。
	 * 
	 * @param shape {@link Shape}
	 */
	public void removeAndDestroyShape(Shape shape) {
		removeShape(shape);
		shape.destroy();
	}
	
	/**
	 * 添加一个固定的物体到空间中
	 *
	 * @param shape {@link Shape}
	 */
	public native void addStaticShape(Shape shape);
	
	/**
	 * 删除一个静态物体。这个方法如果在step方法之中调用是不安全的。
	 * 
	 * @param shape {@link Shape}
	 */
	public native void removeStaticShape(Shape shape);
	
	/**
	 * 添加一个刚体到空间中
	 * 
	 * @param body {@link Body}对象
	 */
	public native void addBody(Body body);
	
	/**
	 * 从空间中删除一个刚体。这个方法如果在step方法之中调用是不安全的。
	 * 如果一个刚体被删除了，这个body上的shape也会从空间中删除
	 * 
	 * @param body {@link Body}
	 */
	public native void removeBody(Body body);
	
	
	/**
	 * 得到刚体上附着的一个物体，如果没有，返回null。如果刚体上有多个物体，这个方法
	 * 并不能保证获得的是哪个物体
	 * 
	 * @return {@link Shape}
	 */
	public Shape getAnyShapeOfBody(Body body) {
		return Shape.from(nativeGetAnyShape(body));
	}
	
	/**
	 * 获得某个刚体上的所有物体
	 * 
	 * @param body {@link Body}
	 * @return 物体对象列表
	 */
	public ArrayList<Shape> getShapesOfBody(Body body) {
		ArrayList<Shape> shapes = new ArrayList<Shape>();
		int count = prepareShapesOfBody(body);
		for(int i = 0; i < count; i++) {
			int pointer = getShapeOfBody(i);
			shapes.add(Shape.from(pointer));
		}
		cleanShapesOfBody(body);
		return shapes;
	}
	
	private native int prepareShapesOfBody(Body body);
	private native void cleanShapesOfBody(Body body);
	private native int getShapeOfBody(int index);
	
	private native int nativeGetAnyShape(Body body);
	
	/**
	 * 从空间中删除一个刚体，同时释放它的资源。这个方法如果在step方法之中调用是不安全的。
	 * 如果一个刚体被销毁了，这个刚体上的shape也会被销毁
	 * 
	 * @param body {@link Body}
	 */
	public native void removeAndDestroyBody(Body body);
	
	/**
	 * 把某个刚体上的物体都删除并销毁
	 * 
	 * @param body {@link Body}
	 */
	public native void removeAndDestroyShapesOfBody(Body body);

	/**
	 * XXX: 这个方法调用时出错，很奇怪
	 * 设置在安全的时候删除一个物体和它的刚体，一般会在每次step完成后调用
	 * 
	 * @param shape {@link Shape}
	 */
	protected native void scheduleRemoveAndDestroyShapeAndBody(Shape shape);
	
	/**
	 * 添加了一个关联
	 * 
	 * @param constraint {@link Constraint}
	 */
	public native void addConstraint(Constraint constraint);
	
	/**
	 * 去除了一个关联
	 * 
	 * @param constraint {@link Constraint}
	 */
	public native void removeConstraint(Constraint constraint);
	
	/**
	 * 得到空间中刚体的数量
	 * 
	 * @return 空间中刚体的数量，没有通过addBody添加到空间中的不算
	 */
	public native int getBodyCount();
	
	/**
	 * 销毁space所占的资源，包括所有孩子占据的资源
	 */
	public native void destroy();
	
	/**
	 * 遍历每个刚体进行操作
	 * 
	 * @param visitor {@link IBodyVisitor}
	 * @param data 附加数据对象
	 */
	public native void visitBody(IBodyVisitor visitor, Object data);
	
	/**
	 * 修改活动物体的哈希表容量
	 */
	public native void resizeActiveHash(float dim, int count);
	
	/**
	 * 修改静态刚体的哈希表容量
	 */
	public native void resizeStaticHash(float dim, int count);
	
	/**
	 * 设置计算刚性碰撞冲量时的迭代次数
	 * 
	 * @param iterations 迭代次数
	 */
	public native void setIterations(int iterations);
	
	/**
	 * 设置计算弹性碰撞冲量时的迭代次数
	 * 
	 * @param iterations 迭代次数
	 */
	public native void setElasticIterations(int iterations);
	
	/**
	 * 更新空间状态
	 * 
	 * @param delta 自上一次过去的秒数
	 */
	public native void step(float delta);
	
	/**
	 * 设置引力方向和大小
	 *  
	 * @param x 正表示引力向右，负表示向左
	 * @param y 正表示引力向上，负表示向下
	 */
	public native void setGravity(float x, float y);
	
	/**
	 * 获得引力大小的x分量
	 * 
	 * @return 引力大小的x分量
	 */
	public native float getGravityX();
	
	/**
	 * 获得引力大小的y分量
	 * 
	 * @return 引力大小的y分量
	 */
	public native float getGravityY();
	
	/**
	 * 获得引力大小
	 * 
	 * @return {@link WYPoint}
	 */
	public WYPoint getGravity() {
		return WYPoint.make(getGravityX(), getGravityY());
	}
	
	/**
	 * 查询和某个线段相撞的第一个物体
	 * 
	 * @param start 线段物体的起始点
	 * @param end 线段物体的结束点
	 * @param layer 物体所在的层
	 * @param group 物体所在的组
	 * @param info 查询结果bean
	 */
	public void querySegmentFirst(WYPoint start, WYPoint end, int layer, int group, SegmentQueryInfo info) {
		querySegmentFirst(start.x, start.y, end.x, end.y, layer, group, info);
	}
	
	/**
	 * 查询和某个线段相撞的第一个物体
	 * 
	 * @param startX 线段物体的起始点x位置
	 * @param startY 线段物体的起始点y位置
	 * @param endX 线段物体的结束点x位置
	 * @param endY 线段物体的结束点y位置
	 * @param layer 物体所在的层
	 * @param group 物体所在的组
	 * @param info 查询结果bean
	 */
	public native void querySegmentFirst(float startX, float startY, float endX, float endY, int layer, int group, SegmentQueryInfo info);
	
	/**
	 * 如果静态物体有任何变化，可以调用这个方法对静态物体进行重新哈希
	 */
	public native void rehashStatic();
	
	/**
	 * 单步计数，每次调用step()方法后这个值都会增加1
	 * 
	 * @return 单步计数
	 */
	public native int getStamp();
	
	/**
	 * 当前空间是否被锁定，空间被锁定时不要尝试删除或添加对象
	 * 
	 * @return 空间是否被锁定
	 */
	public native boolean isLocked();
	
	/**
	 * 得到空间中的阻力
	 * 
	 * @return 空间中的阻力
	 */
	public native float getDamping();
	
	/**
	 * 设置空间中的阻力
	 * 
	 * @param damping 空间中的阻力
	 */
	public native void setDamping(float damping);
	
	/**
	 * 查询和某个点碰撞的物体
	 * 
	 * @param x 点的x位置
	 * @param y 点的y位置
	 * @param layer 物体所在层
	 * @param group 物体所在组
	 * @return 底层物体的结构指针
	 */
	private native int nativeQueryPointFirst(float x, float y, int layer, int group);
	
	/**
	 * 查询和某个点碰撞的物体
	 * 
	 * @param p 点的位置
	 * @param layer 物体所在层
	 * @param group 物体所在组
	 * @return 底层物体的结构指针
	 */
	public Shape queryPointFirst(WYPoint p, int layer, int group) {
		return queryPointFirst(p.x, p.y, layer, group);
	}
	
	/**
	 * 查询和某个点碰撞的物体
	 * 
	 * @param x 点的x位置
	 * @param y 点的y位置
	 * @param layer 物体所在层
	 * @param group 物体所在组
	 * @return 底层物体的结构指针
	 */
	public Shape queryPointFirst(float x, float y, int layer, int group) {
		int pointer = nativeQueryPointFirst(x, y, layer, group);
		if(pointer == 0)
			return null;
		else
			return Shape.from(pointer);
	}
	
	/**
	 * 查询和某个点碰撞的物体，对每个碰撞的物体调用IPointQueryCallback的onMatch方法
	 * 
	 * @param p 点
	 * @param layer 物体所在层
	 * @param group 物体所在组
	 * @param callback {@link IPointQueryCallback}
	 * @param data 附加数据对象
	 */
	public void queryPoint(WYPoint p, int layer, int group, IPointQueryCallback callback, Object data) {
		queryPoint(p.x, p.y, layer, group, callback, data);
	}
	
	/**
	 * 查询和某个点碰撞的物体，对每个碰撞的物体调用IPointQueryCallback的onMatch方法
	 * 
	 * @param x 点的x坐标
	 * @param y 点的y坐标
	 * @param layer 物体所在层
	 * @param group 物体所在组
	 * @param callback {@link IPointQueryCallback}
	 * @param data 附加数据对象
	 */
	public native void queryPoint(float x, float y, int layer, int group, IPointQueryCallback callback, Object data);

	/**
	 * 查询和某个线段碰撞的物体，对每个碰撞的物体调用ISegmentQueryCallback的onMatch方法
	 * 
	 * @param start 线段起始点
	 * @param end 线段结束点
	 * @param layer 物体所在层
	 * @param group 物体所在组
	 * @param callback {@link ISegmentQueryCallback}
	 * @param data 附加数据对象
	 */
	public void querySegment(WYPoint start, WYPoint end, int layer, int group, ISegmentQueryCallback callback, Object data) {
		querySegment(start.x, start.y, end.x, end.y, layer, group, callback, data);
	}
	
	/**
	 * 查询和某个线段碰撞的物体，对每个碰撞的物体调用ISegmentQueryCallback的onMatch方法
	 * 
	 * @param startX 线段起始点x位置
	 * @param startY 线段起始点y位置
	 * @param endX 线段结束点x位置
	 * @param endY 线段结束点y位置
	 * @param layer 物体所在层
	 * @param group 物体所在组
	 * @param callback {@link ISegmentQueryCallback}
	 * @param data 附加数据对象
	 */
	public native void querySegment(float startX, float startY, float endX, float endY, int layer, int group, ISegmentQueryCallback callback, Object data);
}
