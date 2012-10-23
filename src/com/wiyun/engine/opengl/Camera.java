package com.wiyun.engine.opengl;

import com.wiyun.engine.BaseWYObject;
import com.wiyun.engine.types.Mat4;
import com.wiyun.engine.types.WYRect;


/**
 * 相机逻辑封装。通过修改镜头位置，可以产生不同的视图。 
 */
public class Camera extends BaseWYObject {
	public static Camera make() {
		return new Camera();
	}
	
	/**
	 * 构造函数
	 */
	protected Camera() {
		nativeInit();
	}
	
	private native int nativeInit();
	
	public static Camera from(int pointer) {
		return pointer == 0 ? null : new Camera(pointer);
	}
	
	/**
	 * 构造函数，该方法仅有WiEngine内部调用，开发者不应该使用
	 * 
	 * @param pointer 内部结构指针
	 */
	protected Camera(int pointer) {
		super(pointer);
		restoreCamera();
	}
	
	/**
	 * \if English
	 * Restore camera to default position
	 * \else
	 * 回复到缺省的镜头设置
	 * \endif
	 */
	public native void restoreCamera();

	/**
	 * \if English
	 * Restore to default projection matrix
	 * \else
	 * 回复到缺省的投影矩阵
	 * \endif
	 */
	public native void restoreProjection();

	/**
	 * \if English
	 * Restore to default viewport range
	 * \else
	 * 回复到缺省的视口大小
	 * \endif
	 */
	public native void restoreViewport();

	/**
	 * \if English
	 * Get current view matrix
	 * \else
	 * 得到当前相机矩阵
	 * \endif
	 */
	public Mat4 getViewMatrix() {
		Mat4 m = Mat4.make();
		nativeGetViewMatrix(m);
		return m;
	}
	
	private native Mat4 nativeGetViewMatrix(Mat4 m);

	/**
	 * \if English
	 * Get current projection matrix
	 * \else
	 * 得到当前投影矩阵
	 * \endif
	 */
	public Mat4 getProjectionMatrix() {
		Mat4 m = Mat4.make();
		nativeGetProjectionMatrix(m);
		return m;
	}
	
	private native void nativeGetProjectionMatrix(Mat4 m);

	/**
	 * \if English
	 * Get viewport bound
	 *
	 * @return viewport rectangle
	 * \else
	 * 得到视口矩形
	 *
	 * @return 视口矩形
	 * \endif
	 */
	public WYRect getViewportRect() {
		WYRect r = WYRect.makeZero();
		nativeGetViewportRect(r);
		return r;
	}
	
	private native void nativeGetViewportRect(WYRect r);

	/**
	 * \if English
	 * Set orthogonal projection
	 *
	 * @param l left bound of ortho
	 * @param r right bound of ortho
	 * @param b bottom bound of ortho
	 * @param t top bound of ortho
	 * @param near near end of cylinder
	 * @param far far end of cylinder
	 * \else
	 * 使用正交投影
	 *
	 * @param l 柱体作边界
	 * @param r 柱体右边界
	 * @param b 柱体下边界
	 * @param t 柱体上边界
	 * @param near 柱体近端
	 * @param far 柱体远端
	 * \endif
	 */
	public native void setOrtho(float l, float r, float b, float t, float near, float far);

	/**
	 * \if English
	 * Set perspective projection
	 *
	 * @param fovy the angle of the field of view in the x-z plane; its value must be in the range [0.0,180.0]
	 * @param widthRatio the relative width to viewport width
	 * @param heightRatio the relative height to viewport height
	 * @param near near distances between the viewpoint and the clipping planes, along the negative z-axis. it should always be positive
	 * @param far far distances between the viewpoint and the clipping planes, along the negative z-axis. it should always be positive
	 * \else
	 * 设置梯形投影参数
	 *
	 * @param fovy 视图范围和x-z平面的夹角, 必须在[0, 180]度范围内
	 * @param widthRatio 梯形宽相对于视口宽的比例
	 * @param heightRatio 梯形高相对于视口高的比例
	 * @param near 视点和最近的clip平面距离
	 * @param far 视点和最远的clip平面距离
	 * \endif
	 */
	public native void setPerspective(float fovy, float widthRatio, float heightRatio, float near, float far);

	/**
	 * \if English
	 * Get z location of eye
	 * \else
	 * 得到相机的z位置
	 * \endif
	 */
	public native float getZEye();

	/**
	 * \if English
	 * Get eye location
	 *
	 * @param e float array to hold returned eye location, length must be at least 3
	 * \else
	 * 得到相机位置
	 *
	 * @param e 返回相机位置的浮点数据, 长度至少要为3
	 * \endif
	 */
	public native void getEye(float[] e);

	/**
	 * \if English
	 * Set position of camera location
	 *
	 * @param x position of camera x location
	 * @param y position of camera y location
	 * @param z position of camera z location
	 * \else
	 * 设置当前镜头位置
	 *
	 * @param x 当前镜头x位置
	 * @param y 当前镜头y位置
	 * @param z 当前镜头z位置
	 * \endif
	 */
	public native void setEye(float x, float y, float z);

	/**
	 * \if English
	 * Get camera center location
	 *
	 * @param e float array to hold returned camera center location, length must be at least 3
	 * \else
	 * 得到相机对准的中心位置
	 *
	 * @param c 返回相机对准的中心位置的浮点数据, 长度至少要为3
	 * \endif
	 */
	public native void getCenter(float[] c);

	/**
	 * \if English
	 * Set position of camera center, it will multiply viewport size
	 * to get final position
	 *
	 * @param x position of camera x center
	 * @param y position of camera y center
	 * @param z position of camera z center
	 * \else
	 * 设置当前视线中心位置
	 *
	 * @param x 当前视线中心x位置
	 * @param y 当前视线中心y位置
	 * @param z 当前视线中心z位置
	 * \endif
	 */
	public native void setCenter(float x, float y, float z);

	/**
	 * \if English
	 * Get camera up location
	 *
	 * @param e float array to hold returned camera up location, length must be at least 3
	 * \else
	 * 得到相机正方向
	 *
	 * @param c 返回相机正方向, 长度至少要为3
	 * \endif
	 */
	public native void getUp(float[] u);

	/**
	 * \if English
	 * Set camera positive vector
	 *
	 * @param x x value of up vector
	 * @param y y value of up vector
	 * @param z z value of up vector
	 * \else
	 * 设置当前正方向位置
	 *
	 * @param x 正方向位置的x值
	 * @param y 正方向位置的y值
	 * @param z 正方向位置的z值
	 * \endif
	 */
	public native void setUp(float x, float y, float z);

	/**
	 * \if English
	 * Set camera position and center are relative value of window
	 *
	 * @param flag true means camera position and center are relative value of window
	 * \else
	 * 设置摄像机的位置和中心是否是一个相对于窗口的相对值, 如果窗口宽400, 而center的x值是0.5, 则
	 * 实际的摄像机x位置是200
	 *
	 * @param true表示摄像机的位置和中心是一个相对于窗口的相对值
	 * \endif
	 */
	public native void setUseRelativeValue(boolean flag);

	/**
	 * Set viewport relative size
	 *
	 * @param relative true means the size is a relative value to real screen size, 0.5 means half size
	 * @param x relative x value
	 * @param y relative y value
	 * @param w relative width
	 * @param h relative height
	 */
	public native void setViewport(boolean relative, float x, float y, float w, float h);
}
