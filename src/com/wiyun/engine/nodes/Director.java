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

/**
 * WiEngine的关键入口类。Director负责管理WiEngine的生命周期和渲染过程，同时
 * 提供了一些系统级别的操作接口。 
 */
public class Director implements GLSurfaceView.Renderer {
	private static Director sInstance;

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
		nativeOnSurfaceCreated();
	}
	
	public void onSurfaceDestroyed() {
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
	 * 暂停游戏，渲染和动作都会被暂停
	 */
	public native void pause();
	
	/**
	 * 恢复游戏
	 */
	public native void resume();

	/**
	 * 检查是否Director正在结束中. 这个方法可以用来在某些不确定的情况下, 检查进行某个操作是否安全. 
	 * 比如, 正准备调用一个方法, 但是这个时候可能程序正在退出, 正在退出意味着底层的对象可能正在处于
	 * 释放过程中或者已经释放, 如果不做检查就调用, 则可能因为调用一个已销毁对象而导致程序崩溃.
	 * 
	 * @return true表示Director正在销毁, 在此期间最好不要再做任何事. 
	 */
	public static native boolean isEnding();
	
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
}
