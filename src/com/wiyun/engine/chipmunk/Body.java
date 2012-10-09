package com.wiyun.engine.chipmunk;

import static com.wiyun.engine.types.WYPoint.add;
import static com.wiyun.engine.types.WYPoint.rotate;
import static com.wiyun.engine.types.WYPoint.sub;
import static com.wiyun.engine.types.WYPoint.unrotate;

import com.wiyun.engine.types.WYPoint;

/**
 * 代表一个刚体 
 */
public class Body {
	/**
	 * 自定义的刚体速率更新器。如果不设置，chipmunk使用缺省的更新逻辑 
	 */
	public static interface IVelocityUpdater {
		/**
		 * 更新刚体速度
		 * 
		 * @param bodyPointer Body的底层结构指针,通过Body.from()可以或者Body的java对象
		 * @param gravityX x方向的引力
		 * @param gravityY y方向的引力
		 * @param damping 阻尼
		 * @param delta 上一次更新到现在过去的时间，单位秒
		 */
		public void updateVelocity(int bodyPointer, float gravityX, float gravityY, float damping, float delta);
	}
	
	/**
	 * 自定义的刚体位置更新器。如果不设置，chipmunk使用缺省的更新逻辑 
	 */
	public static interface IPositionUpdater {
		/**
		 * 更新刚体位置
		 * 
		 * @param bodyPointer Body的底层结构指针,通过Body.from()可以或者Body的java对象
		 * @param delta 上一次更新到现在过去的时间，单位秒
		 */
		public void updatePosition(int bodyPointer, float delta);
	}
	
	// underlying cpBody struct pointer
	int mPointer;
	
	/**
	 * 创建一个刚体实例
	 * 
	 * @param mass 质量
	 * @param momentOfInertia 转动惯量
	 * @return 刚体实例
	 */
	public static Body make(float mass, float momentOfInertia) {
		return new Body(mass, momentOfInertia);
	}

	/**
	 * 创建一个static刚体实例
	 * 
	 * @return 刚体实例
	 */
	public static Body makeStatic() {
		return new Body(Float.MAX_VALUE, Float.MAX_VALUE);
	}
	
	public static Body from(int pointer) {
		return pointer == 0 ? null : new Body(pointer);
	}
	
	/**
	 * 构造函数
	 * 
	 * @param mass 质量
	 * @param momentOfInertia 转动惯量
	 */
	protected Body(float mass, float momentOfInertia) {
		init(mass, momentOfInertia);
	}
	
	protected Body(int pointer) {
		mPointer = pointer;
	}
	
	public void setPointer(int pointer) {
		mPointer = pointer;
	}
	
	public int getPointer() {
		return mPointer;
	}
	
	/**
	 * 销毁刚体对象
	 */
	public native void destroy();
	
	/**
	 * 设置刚体的位置
	 * 
	 * @param p {@link WYPoint}
	 */
	public void setPosition(WYPoint p) {
		setPosition(p.x, p.y);
	}
	
	/**
	 * 得到刚体的位置，返回的坐标会受到Chipmunk节点位置的影响。
	 * 
	 * @return {@link WYPoint}
	 */
	public WYPoint getPosition() {
		return WYPoint.make(getPositionX(), getPositionY());
	}
	
	/**
	 * 得到刚体的速度
	 * 
	 * @return {@link WYPoint}
	 */
	public WYPoint getVelocity() {
		return WYPoint.make(getVelocityX(), getVelocityY());
	}
	
	/**
	 * 设置刚体的速度
	 * 
	 * @param v {@link WYPoint}
	 */
	public void setVelocity(WYPoint v) {
		setVelocity(v.x, v.y);
	}
	
	/**
	 * 得到刚体上的力
	 * 
	 * @return 施加在刚体上的力
	 */
	public WYPoint getForce() {
		return WYPoint.make(getForceX(), getForceY());
	}
	
	/**
	 * 设置自定义速度更新器
	 * 
	 * @param u {@link IVelocityUpdater}
	 */
	public native void setVelocityUpdater(IVelocityUpdater u);
	
	/**
	 * 设置自定义位置更新器
	 * 
	 * @param u {@link IPositionUpdater}
	 */
	public native void setPositionUpdater(IPositionUpdater u);
	
	/**
	 * 转换一个全局坐标到刚体本地坐标
	 * 
	 * @param v 要转换的坐标
	 * @return 本地坐标
	 */
	public WYPoint convertWorldToLocal(WYPoint v) {
		return unrotate(sub(v, getPosition()), getAngleUnitVector());
	}
	
	/**
	 * 转换一个刚体本地坐标到全局坐标
	 * 
	 * @param v 要转换的坐标
	 * @return 全局坐标
	 */
	public WYPoint convertLocalToWorld(WYPoint v) {
		return add(getPosition(), rotate(v, getAngleUnitVector()));
	}
	
	/**
	 * 得到刚体运动方向的单位矢量
	 * 
	 * @return 刚体运动方向的单位矢量
	 */
	public WYPoint getAngleUnitVector() {
		return WYPoint.make(getAngleUnitVectorX(), getAngllUnitVectorY());
	}
	
	/**
	 * 得到速度偏差
	 * 
	 * @return 速度偏差
	 */
	public WYPoint getVelocityBias() {
		return WYPoint.make(getVelocityBiasX(), getVelocityBiasY());
	}

	/**
	 * 在物体上设置一个附加数据对象
	 */
	public native void setData(Object data);
	
	/**
	 * 对刚体施加一个力
	 * 
	 * @param force 力
	 * @param r 支点
	 */
	public void applyForce(WYPoint force, WYPoint r) {
		nativeApplyForce(force.x, force.y, r.x, r.y);
	}
	
	/**
	 * 初始化一个刚体
	 * 
	 * @param mass 质量
	 * @param momentOfInertia 转动惯量
	 */
	private native void init(float mass, float momentOfInertia);
	
	/**
	 * 获得物体上附加的数据对象
	 * 
	 * @return 附加数据对象
	 */
	public native Object getData();
	
	/**
	 * 设置刚体位置
	 * 
	 * @param x x坐标
	 * @param y y坐标
	 */
	public native void setPosition(float x, float y);
	
	/**
	 * 得到刚体位置的x坐标，返回的坐标会受到Chipmunk节点位置的影响。
	 * 
	 * @return x坐标
	 */
	public native float getPositionX();
	
	/**
	 * 得到刚体位置的y坐标，返回的坐标会受到Chipmunk节点位置的影响。
	 * 
	 * @return y坐标
	 */
	public native float getPositionY();
	
	/**
	 * 设置刚体速度
	 * 
	 * @param xVel x方向速度
	 * @param yVel y方向速度
	 */
	public native void setVelocity(float xVel, float yVel);
	
	/**
	 * 得到刚体y向的速度
	 */
	public native float getVelocityX();
	
	/**
	 * 得到刚体x向的速度
	 */
	public native float getVelocityY();
	
	/**
	 * 设置刚体的运动方向
	 * 
	 * @param angle 刚体运动方向，单位是弧度，正值表示逆时针，负值表示顺时针，正上方是0度
	 */
	public native void setAngle(float angle);
	
	/**
	 * 得到刚体的运动方向
	 * 
	 * @return 刚体运动方向，单位是弧度
	 */
	public native float getAngle();
	
	/**
	 * 得到刚体运动方向的单位矢量x值
	 * 
	 * @return 刚体运动方向的单位矢量x值
	 */
	public native float getAngleUnitVectorX();
	
	/**
	 * 得到刚体运动方向的单位矢量y值
	 * 
	 * @return 刚体运动方向的单位矢量y值
	 */
	public native float getAngllUnitVectorY();
	
	/**
	 * 设置角速度
	 * 
	 * @param v 角速度
	 */
	public native void setAngularVelocity(float v);
	
	/**
	 * 得到角速度
	 * 
	 * @return 角速度
	 */
	public native float getAngularVelocity();
	
	/**
	 * 设置力矩
	 * 
	 * @param torque 力矩
	 */
	public native void setTorque(float torque);
	
	/**
	 * 得到力矩
	 * 
	 * @return 力矩
	 */
	public native float getTorque();
	
	/**
	 * Chipmunk缺省的刚体速度更新方法
	 * 
	 * @param gravityX x方向的引力
	 * @param gravityY y方向的引力
	 * @param damping 阻尼
	 * @param delta 上一次更新到现在过去的时间，单位秒
	 */
	public native void updateVelocity(float gravityX, float gravityY, float damping, float delta);
	
	/**
	 * Chipmunk缺省的刚体位置更新方法
	 * 
	 * @param delta 上一次更新到现在过去的时间，单位秒
	 */
	public native void updatePosition(float delta);
	
	/**
	 * 得到质量
	 * 
	 * @return 质量
	 */
	public native float getMass();
	
	/**
	 * 设置质量
	 * 
	 * @param mass 质量
	 */
	public native void setMass(float mass);
	
	/**
	 * 得到质量的倒数
	 * 
	 * @return 质量的倒数
	 */
	public native float getMassInverse();
	
	/**
	 * 设置转动惯量
	 * 
	 * @param moment 转动惯量
	 */
	public native void setMomentOfInertia(float moment);
	
	/**
	 * 获得转动惯量
	 * 
	 * @return 转动惯量
	 */
	public native float getMomentOfInertia();
	
	/**
	 * 获得转动惯量的倒数
	 * 
	 * @return 转动惯量的倒数
	 */
	public native float getMomentOfInertiaInverse();
	
	/**
	 * 设置刚体上的作用力大小
	 * 
	 * @param f 作用力
	 */
	public void setForce(WYPoint f) {
		setForce(f.x, f.y);
	}
	
	/**
	 * 设置刚体上的作用力大小
	 * 
	 * @param fx x方向作用力
	 * @param fy y方向作用力
	 */
	public native void setForce(float fx, float fy);
	
	/**
	 * 得到刚体上的x方向作用力大小
	 * 
	 * @return x方向作用力
	 */
	public native float getForceX();
	
	/**
	 * 得到刚体上的y方向作用力大小
	 * 
	 * @return y方向作用力
	 */
	public native float getForceY();
	
	/**
	 * 对刚体施加一个力
	 * 
	 * @param forceX 力的x分量
	 * @param forceY 力的y分量
	 * @param radiusX 支点x位置
	 * @param radiusY 支点y位置
	 */
	private native void nativeApplyForce(float forceX, float forceY, float radiusX, float radiusY);
	
	/**
	 * 把刚体上的力和力矩置0
	 */
	public native void resetForces();
	
	/**
	 * 设置速度偏差
	 * 
	 * @param biasX 速度偏差的x值
	 * @param biasY 速度偏差的y值
	 */
	public native void setVelocityBias(float biasX, float biasY);
	
	/**
	 * 得到速度偏差的x值
	 * 
	 * @return 速度偏差的x值
	 */
	public native float getVelocityBiasX();
	
	/**
	 * 得到速度偏差的y值
	 * 
	 * @return 速度偏差的y值
	 */
	public native float getVelocityBiasY();
	
	/**
	 * 设置角速度偏差
	 * 
	 * @param bias 角速度偏差
	 */
	public native void setAngularVelocityBias(float bias);
	
	/**
	 * 得到角速度偏差
	 * 
	 * @return 角速度偏差
	 */
	public native float getAngularVelocityBias();
	
	/**
	 * 得到最大速度
	 * 
	 * @return 最大速度
	 */
	public native float getMaxVelocity();
	
	/**
	 * 设置最大速度
	 * 
	 * @param max 最大速度
	 */
	public native void setMaxVelocity(float max);
	
	/**
	 * 得到最大角速度
	 * 
	 * @return 最大角速度
	 */
	public native float getMaxAngularVelocity();
	
	/**
	 * 设置最大角速度
	 * 
	 * @param max 最大角速度
	 */
	public native void setMaxAngularVelocity(float max);
	
	/**
	 * 使刚体在指定的时间内运动到某个位置
	 * 
	 * @param pos 目标位置
	 * @param delta 期望运动花的时间
	 */
	public void slew(WYPoint pos, float delta) {
		slew(pos.x, pos.y, delta);
	}
	
	/**
	 * 使刚体在指定的时间内运动到某个位置
	 * 
	 * @param x 目标位置x位置
	 * @param y 目标位置y位置 
	 * @param delta 期望运动花的时间
	 */
	private native void slew(float x, float y, float delta);
	
	/**
	 * 对刚体施加一个瞬间冲力
	 * 
	 * @param impulse 力大小
	 * @param direction 力的方向，相对于刚体自身坐标系
	 */
	public void applyImpulse(WYPoint impulse, WYPoint direction) {
		applyImpulse(impulse.x, impulse.y, direction.x, direction.y);
	}
	
	/**
	 * 对刚体施加一个瞬间冲力
	 * 
	 * @param impulseX x方向力大小
	 * @param impulseY y方向力大小
	 * @param directionX 力的方向x分量，相对于刚体自身坐标系
	 * @param directionY 力的方向y分量，相对于刚体自身坐标系
	 */
	public native void applyImpulse(float impulseX, float impulseY, float directionX, float directionY);
}
