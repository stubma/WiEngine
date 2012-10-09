package com.wiyun.engine.nodes;

import java.util.Locale;

import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

import android.app.Activity;
import android.app.AlertDialog;
import android.app.AlertDialog.Builder;
import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.DialogInterface;
import android.content.DialogInterface.OnClickListener;
import android.content.Intent;
import android.content.IntentFilter;
import android.content.pm.PackageManager;
import android.hardware.SensorManager;
import android.media.MediaPlayer;
import android.media.SoundPool;
import android.net.Uri;
import android.net.wifi.WifiInfo;
import android.net.wifi.WifiManager;
import android.opengl.GLSurfaceView;
import android.os.Environment;
import android.os.Handler;
import android.os.Message;
import android.provider.Settings.Secure;
import android.telephony.TelephonyManager;
import android.util.DisplayMetrics;
import android.view.Display;
import android.view.View;
import android.view.WindowManager;

import com.wiyun.engine.events.Accelerometer;
import com.wiyun.engine.opengl.WYGLSurfaceView;
import com.wiyun.engine.sound.AudioManager;
import com.wiyun.engine.transitions.TransitionScene;
import com.wiyun.engine.types.WYPoint;
import com.wiyun.engine.types.WYRect;
import com.wiyun.engine.types.WYSize;
import com.wiyun.engine.utils.ResourceDecoder;

/**
 * WiEngine的关键入口类。Director负责管理WiEngine的生命周期和渲染过程，同时
 * 提供了一些系统级别的操作接口。 
 */
public class Director implements GLSurfaceView.Renderer {
	/**
	 * \if English
	 * Lifecycle event interface. You can install lifecycle listener thru \c addLifecycleListener method
	 * \else
	 * Director生命周期监听器接口, 通过\c addLifecycleListener方法可以添加生命周期监听器
	 * \endif
	 */
	public static interface IDirectorLifecycleListener {
		/**
		 * \if English
		 * Invoked when surface created.
		 * \else
		 * 在Surface被创建的时候调用
		 * \endif
		 */
		public void onSurfaceCreated();
		
		/**
		 * \if English
		 * Invoked when surface changed. Generally there is always a change event immediately after
		 * surface created. After this, game loop will be started.
		 *
		 * @param w new width of surface
		 * @param h new height of surface
		 * \else
		 * 在Surface改变的时候被调用. 一般这个事件紧跟在surface创建之后. 这个事件发生后, 将开始
		 * 游戏循环
		 *
		 * @param w Surface新的宽度
		 * @param h Surface新的高度
		 * \endif
		 */
		public void onSurfaceChanged(int w, int h);
		
		/**
		 * \if English
		 * Invoked when surface destroyed, usually it is happened when game exited or
		 * switching to other activity
		 * \else
		 * 在Surface销毁的时候调用, 一般这发生在游戏退出或切换到其它activity时
		 * \endif
		 */
		public void onSurfaceDestroyed();
		
		/**
		 * \if English
		 * Invoked when \c pause method is called. \c pause method must be called in
		 * activity onPause
		 * \else
		 * 在Director的\c pause方法被调用后调用. \c pause方法必须在Activity的onPause中调用
		 * \endif
		 */
		public void onDirectorPaused();
		
		/**
		 * \if English
		 * Invoked when \c resume method is called. \c resume method must be called in
		 * activity onResume
		 * \else
		 * 在Director的\c resume方法被调用后调用. \c resume方法必须在activity的onResume中调用.
		 * \endif
		 */
		public void onDirectorResumed();
		
		/**
		 * \if English
		 * Invoked when \c end method is called. \c end method must be called when game exited so
		 * this event means game ended
		 * \else
		 * 在Director中止的时候被调用. Director中止是由于end方法被调用, 一般这意味着游戏已经退出
		 * \endif
		 */
		public void onDirectorEnded();
		
		/**
		 * \if English
		 * Invoked when a screenshot is captured.
		 *
		 * @param path path of screenshot file, maybe png or jpg and it is decided based on extension
		 * 		of file path when calling \c makeScreenshot method
		 * \else
		 * 在一个截屏被保存后调用
		 *
		 * @param path 截屏保存后的图片路径, 可能是png或者jpg, 调用者应该清楚. 这是在调用\c makeScreenshot时
		 * 		通过路径的后缀名自动决定的.
		 * \endif
		 */
		void onDirectorScreenCaptured(String path);
	}
	
	private static Director sInstance;

	/**
	 * 正交投影方式
	 */
	public static final int PROJECTION_2D = 1;

	/**
	 * 3D投影方式，fovy=60, znear=0.5f, zfar=1500.
	 * 这是缺省的投影方式
	 */
	public static final int PROJECTION_3D = 2;

	/**
	 * 自定义投影方式，用户需要自己调用OpenGL接口设置投影方式
	 */
	public static final int PROJECTION_CUSTOM = 3;
	
	/**
	 * 按照资源的density和屏幕的density自动进行缩放，这是缺省的适配模式. 这个模式的
	 * 优点是可以自动找到合适的资源，可以为不同的屏幕指定不同的资源，从而保证游戏在不同
	 * 屏幕上的画面品质。缺点是需要开发者自己处理坐标的转换，以及编程时要注意使用DP值和逻辑
	 * 的严谨
	 */
	public static final int SCALE_MODE_BY_DENSITY = 0;

	/**
	 * <p>设定一个基础大小，然后所有的大小都以这个基础大小为参考, 所有的坐标也以这个为参考，比如
	 * 触摸的位置也会以这个基础大小为标准转换。如果屏幕的大小和基础大小不符合，则会在xy方向拉伸
	 * 图像直至填充满.</p><br>
	 *
	 * <p>基础大小适配方式的优点是简单，可以自动适配所有屏幕尺寸，缺点是一旦选定了一个基础大小，
	 * 以后要修改会比较麻烦，而且无法为不同屏幕使用不同贴图，无法保证在不同屏幕上的画面品质。</p><br>
	 *
	 * <p>一旦选择了基础大小适配模式，WiEngine将不再自动缩放贴图. 且性能相对density模式要差一点</p>
	 */
	public static final int SCALE_MODE_BASE_SIZE_FIT_XY = 1;
	
	/**
	 * GL10的java端引用，主要是为了帮助Java开发者可以在Java端
	 * 实现draw方法
	 */
	public GL10 gl;
	
	/**
	 * 加速器事件的产生速度, 常量定义在android的SensorManager类中
	 */
	private int mAccelDelay = SensorManager.SENSOR_DELAY_GAME;
	
	// message
	private static final int MSG_SET_VIEW_VISIBLE = 4;
	private static final int MSG_SET_VIEW_INVISIBLE = 5;
	
	/// handler used to process something in ui thread
	private Handler mHandler = new Handler() {
		@Override
		public void handleMessage(Message msg) {
			switch(msg.what) {
				case MSG_SET_VIEW_VISIBLE:
					((View)msg.obj).setVisibility(View.VISIBLE);
					break;
				case MSG_SET_VIEW_INVISIBLE:
					((View)msg.obj).setVisibility(View.INVISIBLE);
					break;
				default:
					super.handleMessage(msg);
					break;
			}
		}
	};
	
	// screen on/off receiver
	private BroadcastReceiver mReceiver = new BroadcastReceiver() {
		@Override
		public void onReceive(Context arg0, Intent intent) {
			String action = intent.getAction();
			if(Intent.ACTION_SCREEN_OFF.equals(action)) {
				pause();
			}
		}
	};
	
	/**
	 * 获得Director的单例对象
	 * 
	 * @return {@link Director}
	 */
	public static Director getInstance() {
		synchronized(Director.class) {
			if(sInstance == null) {
				sInstance = new Director();
				preloadClasses();
			}
			return sInstance;
		}
	}
	
	public static Director getInstanceNoCreate() {
		return sInstance;
	}
	
	protected Director() {
		// init members
		nativeInit();
	}
	
	/**
	 * 获得WiEngine的版本号
	 * 
	 * @return 版本号字符串, 形式是"x.y.z"
	 */
	public native static String getVersion();
	
	@SuppressWarnings("unused")
	static void preloadClasses() {
		// ensure those classes can be found by native code
		Class<?> klass = AudioManager.class;
		klass = MediaPlayer.class;
		klass = SoundPool.class;
	}
	
	/**
	 * 设置加速器事件的触发速度, 目前有四个级别, 其常量定义在SensorManager类中. 缺省值是
	 * SensorManager.SENSOR_DELAY_GAME
	 * 
	 * @param delay 触发速度, 可以是SensorManager.SENSOR_DELAY_FASTEST(最快), 
	 * 		SensorManager.SENSOR_DELAY_GAME(较快), SensorManager.SENSOR_DELAY_UI(适合UI, 较慢),
	 * 		SensorManager.SENSOR_DELAY_NORMAL(最慢)
	 */
	public void setAccelerometerDelay(int delay) {
		mAccelDelay = delay;
		Accelerometer.getInstance().updateAccelerometerDelay();
	}
	
	/**
	 * 得到当前的加速器事件触发速度
	 * 
	 * @return 加速器事件触发速度
	 */
	public int getAccelerometerDelay() {
		return mAccelDelay;
	}
	
	private native void nativeInit();
	
	/**
	 * 将Director绑定到某个{@link GLSurfaceView}。如果将WiEngine用于动态壁纸，则不需要
	 * 调用此方法。
	 * 
	 * @param view {@link WYGLSurfaceView}
	 */
	public native void attachInView(WYGLSurfaceView view);
	
	/**
	 * 将Director绑定到某个{@link android.content.Context}
	 * 
	 * @param context {@link android.content.Context}
	 */
	public void attachContext(Context context) {
		nativeAttachContext(context);
		
		Context newCtx = getContext();
		if(newCtx != null) {
			IntentFilter filter = new IntentFilter();
			filter.addAction(Intent.ACTION_SCREEN_OFF);
			newCtx.registerReceiver(mReceiver, filter);
		}
	}
	
	private native void nativeAttachContext(Context context);

	/**
	 * 得到director相关联的Context对象, 一般来说这是一个Activity, 但是在
	 * LiveWallpaper时，可能是个Service
	 * 
	 * @return {@link Context}
	 */
	public native Context getContext();

	/**
	 * 将Android坐标转换为OpenGL坐标. 如果当前适配模式是基础大小模式，则这个方法
	 * 将参考基础大小进行坐标转换，这样可以保证您切换适配模式时代码不用修改。
	 * 
	 * @param uiPointX android坐标x
	 * @param uiPointY android坐标y
	 * @return {@link WYPoint}, 包含了OpenGL坐标值
	 */
	public WYPoint convertToGL(float uiPointX, float uiPointY) {
		if(getScaleMode() == SCALE_MODE_BY_DENSITY)
			return WYPoint.make(uiPointX, getSurfaceHeight() - uiPointY);
		else
			return WYPoint.make(uiPointX * getSurfaceWidth() / getRealWidth(), (getRealHeight() - uiPointY) * getSurfaceHeight() / getRealHeight());
	}
	
	/**
	 * 销毁Director, 结束游戏. 如果Director和一个Activity相关联, 这个方法可以
	 * 在Activity的onDestroy中调用, 也可以在其它场合调用, 一旦调用后, 应用的activity将结束, 
	 * Director的单一实例也将被销毁. 如果Director和一个动态壁纸服务相关联，这个方法可以在
	 * 动态壁纸引擎的onDestroy方法中调用。
	 */
	void internalEnd() {
		Context context = getContext();
		if(context != null) {
			// unregister receiver
			if(mReceiver != null) {
				context.unregisterReceiver(mReceiver);
				mReceiver = null;
			}
			
			// if activity, finish it
			if(context instanceof Activity) {
				Activity act = (Activity)context;
				act.finish();
			} else if(sInstance != null) {
				// destroy c layer
				nativeDestroy();
				
				// nullify instance
				sInstance = null;
			}
		}
	}
	
	public void end() {
		Context context = getContext();
		if(context != null) {
			// unregister receiver
			if(mReceiver != null) {
				context.unregisterReceiver(mReceiver);
				mReceiver = null;
			}
			
			// native destroy
			if(sInstance != null) {
				// destroy c layer
				nativeDestroy();
				
				// nullify instance
				sInstance = null;
			}
		}
	}
	
	private native void nativeDestroy();
	
    public boolean isPortrait() {
    	Display display = ((WindowManager)getContext().getSystemService(Context.WINDOW_SERVICE)).getDefaultDisplay();
    	return display.getOrientation() == 0;
    }

	/**
	 * The OpenGL view
	 */
	public native WYGLSurfaceView getOpenGLView();

	/**
	 * 得到当前投影方式
	 * 
	 * @return 当前投影方式常量
	 * @see #PROJECTION_2D
	 * @see #PROJECTION_3D
	 * @see #PROJECTION_CUSTOM
	 */
	public native int getProjection();
	
	/**
	 * 设置图片的缺省density, 缺省值是1.0f，也就是缺省把图片做为
	 * mdpi的处理
	 * 
	 * @param density 0.75表示ldpi, 1.0表示mdpi, 1.5表示hdpi, 也可以是其它值表示是自定义的屏幕类型
	 */
	public static native void setDefaultInDensity(float density);
	
	/**
	 * 得到图片的缺省density, 如果不设置, 缺省值是1.0f, 也就是把缺省图片做为
	 * mdpi处理
	 * 
	 * @return density 0.75表示ldpi, 1.0表示mdpi, 1.5表示hdpi, 也可以是其它值表示是自定义的屏幕类型
	 */
	public static native float getDefaultInDensity();
	
	/**
	 * 抓取当前帧, 保存为png图片. 这个方法会将图片保存到指定路径，由于牵涉到文件
	 * 写操作, 因此速度较慢, 另外使用的OpenGL接口可能在低版本Android系统上没有
	 * 实现. 如果保存的路径在sd卡上, 则应用需要有写sd卡的权限.
	 *
	 * @param path 截图保存的目标路径, 如果为空或者为null, 则不做任何事. 如果指定的路径不存在, 则
	 * 		会自动创建目录
	 */
	public native void makeScreenshot(String path);
	
	/**
	 * 抓取当前帧的一部分, 保存为png图片. 这个方法会将图片保存到指定路径，由于牵涉到文件
	 * 写操作, 因此速度较慢, 另外使用的OpenGL接口可能在低版本Android系统上没有
	 * 实现. 如果保存的路径在sd卡上, 则应用需要有写sd卡的权限.
	 *
	 * 在iOS平台上截图时, 传入的路径会被认为是相对于应用沙箱的Documents目录.
	 *
	 * @param path 截图保存的目标路径, 如果指定的路径不存在, 则会自动创建目录. 如果为NULL, 则不做任何事
	 * @param rect 需要截取的屏幕矩形范围
	 */
	public native void makeScreenshot(String path, WYRect rect);

	/**
	 * 单独抓取某个节点范围内的内容, 节点范围会考虑到节点的缩放和旋转, 因此实际上是获得节点的
	 * getBoundingBoxRelativeToWorld的范围进行抓取.
	 *
	 * \note
	 * \c node的状态并不影响截图的结果, 因为只是获取\c node的矩形范围, 其它并无作用, 这个调用
	 * 实际上等同于makeScreenshot(path, node->getBoundingBoxRelativeToWorld())
	 *
	 * @param path 截图保存的目标路径, 如果指定的路径不存在, 则会自动创建目录. 如果为NULL, 则不做任何事
	 * @param node 需要抓取的节点
	 */
	public native void makeScreenshot(String path, Node node);
	
	static void showConfirmDialog(final String title, final String text, final String positiveButton, final String negativeButton, 
			final int okSelectorPointer, final int cancelSelectorPointer) {
		final Activity act = (Activity)getInstance().getContext();
		act.runOnUiThread(new Runnable() {
			public void run() {
				AlertDialog.Builder builder = new Builder(act);
				if(title != null)
					builder.setTitle(title);
				if(text != null)
					builder.setMessage(text);
				if(positiveButton != null) {
					builder.setPositiveButton(positiveButton, new OnClickListener() {
						public void onClick(DialogInterface dialog, int which) {
							Director.getInstance().runOnGLThread(new Runnable() {
								@Override
								public void run() {
									invokeNativeTargetSelector(okSelectorPointer);
								}
							});
						}
					});
				}
				if(negativeButton != null) {
					builder.setNegativeButton(negativeButton, new OnClickListener() {
						public void onClick(DialogInterface dialog, int which) {
							Director.getInstance().runOnGLThread(new Runnable() {
								@Override
								public void run() {
									invokeNativeTargetSelector(cancelSelectorPointer);
								}
							});
						}
					});
				}
				
				builder.show();
			}
		});
	}
	
	static void showAlertDialog(final String title, final String text, final String positiveButton, 
			final int okSelectorPointer) {
		final Activity act = (Activity)getInstance().getContext();
		act.runOnUiThread(new Runnable() {
			public void run() {
				AlertDialog.Builder builder = new Builder(act);
				if(title != null)
					builder.setTitle(title);
				if(text != null)
					builder.setMessage(text);
				if(positiveButton != null) {
					builder.setPositiveButton(positiveButton, new OnClickListener() {
						public void onClick(DialogInterface dialog, int which) {
							Director.getInstance().runOnGLThread(new Runnable() {
								@Override
								public void run() {
									invokeNativeTargetSelector(okSelectorPointer);
								}
							});
						}
					});
				}
				builder.show();
			}
		});
	}
	
	/**
	 * \if English
	 * Invoke a native target selector, it is a static method you don't need create a java
	 * counterpart for it
	 * 
	 * @param pointer pointer of native target selector
	 * \else
	 * 调用一个native端的选择子, 这是一个静态方法所以并不需要创建java端的对象
	 * 
	 * @param pointer 底层选择子的指针
	 * \endif
	 */
	static native void invokeNativeTargetSelector(int pointer);
	
	static String getLanguage() {
		return Locale.getDefault().getLanguage();
	}
	
	static String getCountry() {
		return Locale.getDefault().getCountry();
	}
	
	static void setViewVisible(View v) {
		if(sInstance != null) {
			Message msg = Message.obtain(sInstance.mHandler, MSG_SET_VIEW_VISIBLE, v);
			sInstance.mHandler.sendMessage(msg);
		}
	}
	
	static void setViewInvisible(View v) {
		if(sInstance != null) {
			Message msg = Message.obtain(sInstance.mHandler, MSG_SET_VIEW_INVISIBLE, v);
			sInstance.mHandler.sendMessage(msg);
		}
	}
	
	static void openUrl(String url) {
		try {
			if(sInstance != null) {
				Context context = sInstance.getContext();
				Intent intent = new Intent(Intent.ACTION_VIEW);
				intent.setData(Uri.parse(url));
				context.startActivity(intent);
			}
		} catch (Exception e) {
		}
	}
	
	public void onDrawFrame(GL10 gl) {
		nativeOnDrawFrame();
	}

	private native void nativeOnDrawFrame();

	public void onSurfaceChanged(GL10 gl, int width, int height) {
		nativeOnSurfaceChanged(width, height);
	}

	public void onSurfaceCreated(GL10 gl, EGLConfig config) {
		Director.getInstance().gl = gl;
		nativeOnSurfaceCreated();
	}
	
	public void onSurfaceDestroyed() {
		Director.getInstance().gl = null;
		nativeOnSurfaceDestroyed();
	}
	
	private native void nativeOnSurfaceDestroyed();

	/**
	 * 通知底层surface改变了
	 */
	private native void nativeOnSurfaceChanged(int width, int height);
	
	/**
	 * 通知底层surface创建了
	 */
	private native void nativeOnSurfaceCreated();

	/**
	 * 结束当前场景
	 */
	public native void popScene();
	
	/**
	 * 弹出栈顶的场景, 同时附带一个转场效果
	 *
	 * @param trans \link wyTransitionScene wyTransitionScene\endlink
	 */
	public native void popSceneWithTransition(TransitionScene trans);
	
	/**
	 * 得到栈中第二个场景， 如果当前栈中的场景少于2个，则返回null
	 * 
	 * @return 得到栈中第二个场景， 如果当前栈中的场景少于2个，则返回null
	 */
	public Scene getPreviousScene() {
		return new Scene(nativeGetPreviousScene());
	}
	
	private native int nativeGetPreviousScene();
	
	/**
	 * 推入一个新场景作为当前场景
	 * 
	 * @param scene {@link Scene}
	 */
	public native void pushScene(Scene scene);

	/**
	 * 替换当前场景为一个新的场景
	 * 
	 * @param scene {@link Scene}
	 */
	public native void replaceScene(Scene scene);

	/**
	 * 暂停游戏，渲染和动作都会被暂停
	 */
	public native void pause();
	
	/**
	 * 获得当前是否被UI设置为暂停状态,true为暂停
	 *
	 * @return 当前暂停状态
	 */
	public native boolean isUIPaused();
	
	/**
	 * 暂停游戏，此方法只负责暂停游戏的调度器调度和动作管理，事件需要游戏实现者自行判断
	 */
	public native void pauseUI();

	/**
	 * 恢复游戏，此方法只负责恢复游戏的调度器调度和动作管理，事件需要游戏实现者自行判断
	 */
	public native void resumeUI();
	
	/**
	 * 恢复游戏
	 */
	public native void resume();

	/**
	 * 得到当前场景
	 */
	public Scene getRunningScene() {
		return new Scene(nativeGetRunningScene());
	}
	
	private native int nativeGetRunningScene();

	/**
	 * 运行某个场景，调用此方法时，当前不能有场景正在运行。所以这个场景一般是第一个场景。
	 * 
	 * @param scene 要运行的场景
	 */
	public native void runWithScene(Scene scene);

	/**
	 * 设置是否在左下角显示帧率，缺省是不显示，正式发布时建议不显示。
	 * 
	 * @param value true表示打开，false表示不打开
	 */
	public native void setDisplayFPS(boolean value);
	
	/**
	 * \if English
	 * Set flag indicating fps should be calculated or not, if true, you
	 * can retrieve current frame rate by \c getCurrentFrameRate. However,
	 * enable this feature will introduce a little cpu cost, but may be not
	 * much
	 *
	 * \note
	 * if you call setDisplayFPS(true), then it implied fps will be calculated
	 * \else
	 * 设置是否打开fps计算功能, 如果为true, 则可以通过\c getCurrentFrameRate获得当前
	 * 帧率. 但是打开这个功能肯定会消耗一些cpu资源, 但是应该不大.
	 *
	 * \note
	 * 如果调用了\c setDisplayFPS(true), 则fps计算也将打开
	 * \endif
	 */
	public native void setCalculateFPS(boolean flag);

	/**
	 * <p>得到当前窗口大小。</p><br/>
	 * 
	 * <p>如果当前适配模式是密度适配，则这个大小是surface view的大小，但是要注意，
	 * surface view的大小要在surface被创建时才能知道，因此这个大小在一开始会被初始
	 * 化成屏幕大小。如果最终的surface大小和屏幕大小不匹配，则在得到surface正确大小
	 * 之前创建的场景都可能出现坐标的偏差。因此在最新的demo中，已经把创建第一个场景挪
	 * 到了surface创建之后进行。</p><br/>
	 * 
	 * <p>如果当前模式是基础大小适配，则这个大小是用户设置的基础大小</p>
	 * 
	 * @return {@link WYSize}
	 */
	public WYSize getWindowSize() {
		return WYSize.make(getSurfaceWidth(), getSurfaceHeight());
	}
	
	private native int getSurfaceWidth();
	private native int getSurfaceHeight();
	
	private native int getRealWidth();
	private native int getRealHeight();
	
	private native int getScaleMode();
	
	/**
	 * 得到最大帧率
	 * 
	 * @return 最大帧率
	 */
	public native int getMaxFrameRate();

	/**
	 * 设置最大帧率
	 * 
	 * @param maxFrameRate 最大帧率，如果为0表示不限制帧率
	 */
	public native void setMaxFrameRate(int maxFrameRate);

	/**
	 * 得到最大贴图大小
	 * 
	 * @return 最大贴图大小
	 */
	public native int getMaxTextureSize();
	
	/**
	 * 添加一个生命周期监听器
	 * 
	 * @param listener {@link IDirectorLifecycleListener}
	 */
	public native void addLifecycleListener(IDirectorLifecycleListener listener);
	
	/**
	 * 检查某个OpenGL扩展是否支持
	 * 
	 * @param ext 扩展名
	 * @return true表示这个扩展支持, false表示不支持
	 */
	public native boolean isExtensionSupported(String ext);
	
	/**
	 * 检查是否Director正在结束中. 这个方法可以用来在某些不确定的情况下, 检查进行某个操作是否安全. 
	 * 比如, 正准备调用一个方法, 但是这个时候可能程序正在退出, 正在退出意味着底层的对象可能正在处于
	 * 释放过程中或者已经释放, 如果不做检查就调用, 则可能因为调用一个已销毁对象而导致程序崩溃.
	 * 
	 * @return true表示Director正在销毁, 在此期间最好不要再做任何事. 
	 */
	public static native boolean isEnding();
	
	/**
	 * 得到当前的帧率, 这个帧率其实是最近一次计算出的帧率, 因此不能说完全是当前的帧率. 不过基本和当前帧率是一致的.
	 *
	 * @return 最近的帧率
	 */
	public native float getCurrentFrameRate();
	
	/**
	 * 检查节点是否具有焦点态
	 *
	 * @return true为可用
	 */
	public native boolean isFocusEnabled();
	
	/**
	 * 设置节点是否具有焦点态, true为有, 缺省为false. 如果一个节点具有焦点态, 则其可以在获得输入焦点时
	 * 显示不同的样子. 这比较适合于某些需要通过实体键盘操作的游戏, 这样的话显示焦点态是有意义的. 对于无
	 * 实体键盘的机型, 焦点态的用处不明显, 因此可以根据您的需要设置是否打开这个功能. 如果这个标志是false,
	 * 则Node.setFocused方法没有任何效果. 如果是true, 则Node.setFocused会修改节点的焦点标志.
	 *
	 * @param flag 设置节点是否具有焦点态, true为可用
	 */
	public native void setFocusEnabled(boolean flag);
	
	/**
	 * 设置下一个delta时间是否为0. 这个方法会在每个场景载入后自动调用, 因此通常情况下您不需要调用此方法.
	 *
	 * @param flag true表示下一个delta时间设为0, 这主要用来避免因为资源载入导致的游戏体验不连续问题. 例如有一个场景中一开始就要执行动画,
	 * 			但是由于场景载入需要耗费一定时间, 因此可能导致动画的前面几帧被跳过. 那么可以设置这个标志强制使下一个delta时间为0, 这样
	 * 			动画将从第一帧开始.
	 */
	public native void setNextDeltaTimeZero(boolean flag);
	
	/**
	 * <p>设置是否允许游戏在后台运行. 缺省情况下, 游戏退到后台后, surface被销毁, 游戏主循环也将停止, 所以
	 * 游戏通常是不会在后台运行的. 不过可以设置这个标志让游戏在后台仍然保持运行, 当然这个运行只是指游戏
	 * 的逻辑继续在运行, 渲染是肯定不会继续的, 声音也不会继续播放. 好吧, 这功能有啥用呢? 如果您的游戏有
	 * 类似于挂机这样的概念, 那也许就用的上了. 不过, 如果在后台游戏还跑着, 那是肯定会加大电量消耗的, 所以
	 * 要慎重.<br></p>
	 * 
	 * <p>在Android上, 一般按Home键就可以让应用退到后台, iOS则需要是4.0以上才有后台这个概念.</p>
	 *
	 * @param flag true表示允许游戏在后台运行
	 */
	public native void setAllowBackgroundRunning(boolean flag);

	/**
	 * 是否允许游戏在后台运行
	 *
	 * @return true表示允许游戏在后台运行
	 */
	public native boolean isAllowBackgroundRunning();
	
	/**
	 * 设置屏幕适配模式. 这个方法必须要在surface创建之前调用.
	 *
	 * @param mode 屏幕适配模式
	 */
	public native void setScaleMode(int mode);

	/**
	 * 设置基础大小，仅当屏幕适配模式是基础大小适配模式时有效. 这个方法必须要在surface创建之前调用.
	 *
	 * @param w 游戏画面基础宽度
	 * @param h 游戏画面基础高度
	 */
	public native void setBaseSize(int w, int h);
	
	/**
	 * \if English
	 * Change the base size during game running. If current mode is not base size mode,
	 * this method will switch to it.
	 *
	 * @param w new base width pixel
	 * @param h new base height pixel
	 * \else
	 * 改变基础大小, 如果当前模式不是是基础大小模式, 则该方法会切换至基础大小模式. 这个方法可以让你在
	 * 游戏运行中动态的改变基础大小, 但必须以场景为单位.
	 *
	 * @param w 新的基础宽度像素
	 * @param h 新的基础高度像素
	 * \endif
	 */
	public native void changeBaseSize(int w, int h);
	
	/**
	 * 在OpenGL线程中调度一个{@link Runnable}实现类, 这个道理和非UI线程中不能操作Android的View一样,
	 * 在非OpenGL线程中也不能操作WiEngine的Node, 因此当需要在UI线程中操作节点时, 一般是通过这样的方式
	 * 放到OpenGL线程中去执行
	 * 
	 * @param runnable {@link Runnable}
	 */
	public native void runOnGLThread(Runnable runnable);
	
	/**
	 * 调度一个子线程. 从WiEngine 3.10之后, 不能直接new一个Thread类并运行, 必须通过
	 * runThread方法启动一个java线程
	 * 
	 * @param runnable {@link Runnable}
	 */
	public void runThread(final Runnable runnable) {
		new Thread() {
			public void run() {
				runnable.run();
				drainAutoReleasePool();
			}
		}.start();
	}
	
	/// drain auto release pool of current thread
	private native void drainAutoReleasePool();
	
	/**
	 * \if English
	 * Set a resource decoder used to decode obfuscated resource file
	 *
	 * @param decoder \link wyResourceDecoder wyResourceDecoder\endlink implementation, NULL
	 * 		will disable resource decoding
	 * \else
	 * 设置一个资源解码器
	 *
	 * @param decoder \link wyResourceDecoder wyResourceDecoder\endlink的具体实现, NULL
	 * 		表示取消资源解码器
	 * \endif
	 */
	public static native void setResourceDecoder(ResourceDecoder decoder);
	
	/**
	 * \if English
	 * Set flags of decode, can control what should be decoded
	 * 
	 * @param flags flags
	 * \else
	 * 设置解码器标志, 控制哪些资源需要解码
	 * 
	 * @param flags 标志
	 * \endif
	 * @see ResourceDecoder#DECODE_RES
	 * @see ResourceDecoder#DECODE_ASSETS
	 * @see ResourceDecoder#DECODE_FILE
	 * @see ResourceDecoder#DECODE_ALL
	 */
	public static native void setResourceDecoderFlag(int flags);
	
	static boolean hasPermission(String permission) {
		Context context = getInstance().getContext();
		if(context == null)
			return false;
		else
			return context.checkCallingOrSelfPermission(permission) == PackageManager.PERMISSION_DENIED;
	}
	
	static String getDeviceIMEI() {
		// check context first
		Context context = getInstance().getContext();
		if(context == null)
			return null;
		
		// get device id
		String deviceId = null;
		if (context.checkCallingOrSelfPermission(android.Manifest.permission.READ_PHONE_STATE) == PackageManager.PERMISSION_GRANTED) {
			// Get the IMEI number of the phone.
			TelephonyManager manager = (TelephonyManager)context.getSystemService(Context.TELEPHONY_SERVICE);
			if (manager != null) {
				deviceId = manager.getDeviceId();
			}
		}	
		
		return deviceId;
	}
	
	/**
	 * Get a device unique string but not md5 hashed, returns null if failed
	 */
	static String getDeviceUniqueString() {
		// check context first
		Context context = getInstance().getContext();
		if(context == null)
			return null;
		
		// get device id
		String deviceId = getDeviceIMEI();
		if(deviceId == null)
			return null;
		
		// append device id
		StringBuilder buf = new StringBuilder();
		buf.append(deviceId);
		
		// append android id
		String androidId = Secure.getString(context.getContentResolver(), Secure.ANDROID_ID);
		buf.append(androidId);
		
		// append screen resolution
		DisplayMetrics dm = context.getResources().getDisplayMetrics();
		buf.append(dm.density);
		
		// append mac address
		WifiManager wm = (WifiManager)context.getSystemService(Context.WIFI_SERVICE);
		if(wm != null) { 
			WifiInfo info = wm.getConnectionInfo();
			if(info != null)
				buf.append(info.getMacAddress());
		}
		
		return buf.toString();
	}
	
	public Handler getHandler() {
		return mHandler; 
	}

	static boolean hasExternalStorage() {
	     String t = android.os.Environment.getExternalStorageState();
	     return Environment.MEDIA_MOUNTED.equals(t);
	}
	
	/**
	 * \if English
	 * Print all objects which is not released yet. It it a way to check
	 * possible object leak. For example, call it in a scene onEnter to check
	 * objects of previous scene are leaked or not.
	 * \else
	 * 打印当前还没有被释放的所有对象, 这可以用来检查内存泄露. 一般可以在一个场景的
	 * onEnter方法里调用这个方法查看前一个场景的对象是否都已经被释放
	 * \endif
	 */
	public native static void printUnreleasedObjects();
	
	/**
	 * \if English
	 * Print all memory blocks which is not released yet. The memory block
	 * must be allocated by WiEngine custom macro, such as wyMalloc, WYNEW etc.
	 * Otherwise the memory block can not be tracked.
	 *
	 * \note
	 * this method is only available for memory debug version. It just print a
	 * warning in release version
	 *
	 * @param fullLog true means including memory log in WiEngine, or false means just
	 * 		print memory log in app layer. 
	 * \else
	 * 打印所有还未分配的内存. 分配内存时必须使用WiEngine定义的宏, 如wyMalloc, WYNEW等.
	 * 否则分配的内存无法被跟踪
	 *
	 * \note
	 * 这个方法仅在内存调试版本中有效, 如果是正式发布的WiEngine版本, 仅打印一条警告
	 *
	 * @param fullLog true表示把WiEngine底层的未释放内存也都打印出来, false表示只打印
	 * 		应用层的未释放内存. 
	 * \endif
	 */
	public native static void printUnreleasedMemory(boolean fullLog);

	/**
	 * \if English
	 * Print memory usage summary. The memory block
	 * must be allocated by WiEngine custom macro, such as wyMalloc, WYNEW etc.
	 * Otherwise the memory block can not be tracked.
	 *
	 * \note
	 * this method is only available for memory debug version. It just print a
	 * warning in release version
	 * \else
	 * 打印出内存使用情况. 分配内存时必须使用WiEngine定义的宏, 如wyMalloc, WYNEW等.
	 * 否则分配的内存无法被跟踪
	 *
	 * \note
	 * 这个方法仅在内存调试版本中有效, 如果是正式发布的WiEngine版本, 仅打印一条警告
	 * \endif
	 */
	public native static void printMemoryUsage();
	
	/**
	 * \if English
	 * Set frame tick delta scaling factor, this can be used to control game
	 * total behavior. A smaller value than 1 will slow down game
	 * speed, or a larger value than one will speed up.
	 * \else
	 * 设置帧间隔的缩放因子, 这个方法可以用来控制游戏的整体运行速度. 如果该值比1小, 则
	 * 游戏整体上会呈现慢动作的状态, 如果比1大, 则整体呈现快动作. 1表示正常速度.
	 * \endif
	 */
	public native void setTickFactor(float r);

	/**
	 * \if English
	 * Get frame tick scaling factor
	 * \else
	 * 得到帧间隔缩放因子
	 * \endif
	 */
	public native float getTickFactor();
}
