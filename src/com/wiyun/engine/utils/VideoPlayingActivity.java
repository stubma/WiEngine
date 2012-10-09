package com.wiyun.engine.utils;

import java.io.IOException;
import java.util.HashMap;
import java.util.Map;

import android.app.Activity;
import android.app.AlertDialog;
import android.app.Dialog;
import android.content.ActivityNotFoundException;
import android.content.ComponentName;
import android.content.DialogInterface;
import android.content.DialogInterface.OnClickListener;
import android.content.Intent;
import android.content.res.AssetFileDescriptor;
import android.media.AudioManager;
import android.media.MediaPlayer;
import android.media.MediaPlayer.OnBufferingUpdateListener;
import android.media.MediaPlayer.OnCompletionListener;
import android.media.MediaPlayer.OnVideoSizeChangedListener;
import android.os.Bundle;
import android.text.TextUtils;
import android.util.Log;
import android.view.KeyEvent;
import android.view.MotionEvent;
import android.view.SurfaceHolder;
import android.view.SurfaceView;
import android.view.View;
import android.view.View.OnTouchListener;
import android.view.Window;
import android.view.WindowManager;

import com.wiyun.engine.WiEngine;

/**
 * <pre>
 * <p>提供视频播放功能的Activity，属于WiEngine的附加功能，开发者可以快速利用现成的VideoPlayingActivity实现
 * 一个视频播放功能。为了使用该功能，首先需要在AndroidManifest.xml中注册这个Activity：</p>
 * <p>
 * &lt;activity android:name=&quot;.utils.VideoPlayingActivity&quot;&gt;&lt;/activity&gt;
 * </p>
 * <p>其次可以通过以下的代码启动VideoPlayingActivity:</p>
 * <p>
 * Intent i = new Intent(Director.getInstance().context, VideoPlayingActivity.class);
 * i.putExtra(VideoPlayingActivity.EXTRA_IN_VIDEO_RES_ID, R.raw.test_video);
 * Director.getInstance().context.startActivity(i);
 * </p>
 * <p>Intent可以包含的参数如下：</p>
 * <ul>
 * <li>EXTRA_IN_VIDEO_RES_ID: 视频文件的资源id</li>
 * <li>EXTRA_IN_VIDEO_ASSET_PATH: 视频文件如果是放在assets下，可以通过这个参数指定，如果同时也指定了资源id，会优先使用本参数。如果assets下找不到相关文件，会再尝试资源id</li>
 * <li>EXTRA_IN_VIDEO_URL: 视频文件如果是在线的，则通过这个参数传入URL。如果指定了这个参数，则资源id和assets路径会被忽略</li>
 * <li>EXTRA_IN_COMPLETION_INTENT: 可以指定一个Intent在VideoPlayingActivity结束后触发，这个Intent如果是一个Activity的Intent(即包含ComponentName)，则WiEngine会调用startActivity，否则调用sendBroadcast</li>
 * <li>EXTRA_IN_END_ON_TOUCH: 可以指定一个boolean标志，true表示点击屏幕则直接退出视频播放, 如果为false，则点击屏幕会弹出一个暂停对话框。缺省是false</li>
 * <li>EXTRA_IN_NO_COMPLETION_DIALOG: 可以指定一个boolean标志，true表示不显示完成对话框，这样的话在播放结束后视频播放activity会立刻退出。缺省为false。</li>
 * </ul>
 * 
 * <p>当Activity返回时，会设置结果码，如果为Activity.RESULT_OK, 表示视频正常播放完毕，如果为Activity.RESULT_CANCELED，表示视频没有播放完成，用户中止了视频播放</p>
 * </pre>
 * 
 * @author Mark Wen
 */
public class VideoPlayingActivity extends Activity implements OnBufferingUpdateListener, OnCompletionListener, OnVideoSizeChangedListener,
		MediaPlayer.OnPreparedListener, SurfaceHolder.Callback, OnTouchListener, OnClickListener {
	/**
	 * 视频文件如果是放在assets下，可以通过这个参数指定，如果同时也指定了资源id，会优先使用本参数。如果assets下找不到相关文件，会再尝试资源id
	 */
	public static final String EXTRA_IN_VIDEO_ASSET_PATH = "EXTRA_IN_VIDEO_ASSET_PATH";
	
	/**
	 * 布尔型数据, 如果为true表示视频路径是一个文件系统的绝对路径, 如果为false表示视频路径是一个assets下的相对路径
	 */
	public static final String EXTRA_IN_VIDEO_IS_FILE = "EXTRA_IN_VIDEO_IS_FILE";
	
	/**
	 * 视频文件的资源id
	 */
	public static final String EXTRA_IN_VIDEO_RES_ID = "EXTRA_IN_VIDEO_RES_ID";
	
	/**
	 * 视频文件如果是在线的，则通过这个参数传入URL
	 */
	public static final String EXTRA_IN_VIDEO_URL = "EXTRA_IN_VIDEO_URL";
	
	/**
	 * 可以指定一个Intent在VideoPlayingActivity结束后触发，这个Intent如果是一个Activity的Intent(即包含ComponentName)，则WiEngine会调用startActivity，否则调用sendBroadcast
	 */
	public static final String EXTRA_IN_COMPLETION_INTENT = "EXTRA_IN_COMPLETION_INTENT";
	
	/**
	 * 可以指定一个boolean标志，true表示点击屏幕则直接退出视频播放, 如果为false，则点击屏幕会弹出一个暂停对话框。缺省是false
	 */
	public static final String EXTRA_IN_END_ON_TOUCH = "EXTRA_IN_END_ON_TOUCH";
	
	/**
	 * 可以指定一个boolean标志，true表示不显示完成对话框，这样的话在播放结束后视频播放activity会立刻退出。缺省为false。
	 */
	public static final String EXTRA_IN_NO_COMPLETION_DIALOG = "EXTRA_IN_NO_COMPLETION_DIALOG";
	
	// button labels
	private Map<String, Map<Integer, String>> mLabels;
	
	public static final int REPLAY = 0;
	public static final int EXIT = 1;
	public static final int CONTINUE = 2;
	
	private static final int DIALOG_COMPLETION = 1;
	private static final int DIALOG_PAUSE = 2;

	private SurfaceView mPreview;
	private SurfaceHolder mHolder;
	private AssetFileDescriptor mFD;
	private MediaPlayer mMediaPlayer;
	
	// video url
	private String mVideoUrl;
	
	// video is file or not
	private String mAssetPath;
	private boolean mIsFile;
	
	// completion intent
	private Intent mCompletionIntent;
	
	// show completion dialog or not
	private boolean mNoCompletionDialog;
	
	// end on touch flag
	private boolean mEndOnTouch;
	
	// for 2.0 back key compatibility
	private boolean mBackKeyTracking;
	
	private boolean mIsVideoReadyToBePlayed = false;
	private boolean mIsVideoSizeKnown = false;
	private int mVideoWidth;
	private int mVideoHeight;

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		requestWindowFeature(Window.FEATURE_NO_TITLE);
		getWindow().setFlags(WindowManager.LayoutParams.FLAG_FULLSCREEN,
				WindowManager.LayoutParams.FLAG_FULLSCREEN);
		mPreview = new SurfaceView(this);
		setContentView(mPreview);
		
		init();
		
		initViews();
	}
	
	private void initViews() {
		mPreview.setFocusable(true);
		mPreview.setFocusableInTouchMode(true);
		mPreview.setOnTouchListener(this);
		
		/* 得到SurfaceHolder对象 */
		mHolder = mPreview.getHolder();
		
		/* 设置回调函数 */
		mHolder.addCallback(this);
		
		/* 设置风格 */
		mHolder.setType(SurfaceHolder.SURFACE_TYPE_PUSH_BUFFERS);
	}

	@Override
	protected void onDestroy() {
		// close file descriptor
		try {
			if(mFD != null) {
				mFD.close();
				mFD = null;
			}
		} catch(IOException e) {
		}
		
		// remove callback
		mHolder.removeCallback(this);
		
		super.onDestroy();
	}
	
	private void init() {
		// init members
		mLabels = new HashMap<String, Map<Integer,String>>();
		Map<Integer, String> en = new HashMap<Integer, String>();
		en.put(REPLAY, "Replay");
		en.put(EXIT, "Exit");
		en.put(CONTINUE, "Continue");
		mLabels.put("en", en);
		Map<Integer, String> zh = new HashMap<Integer, String>();
		zh.put(REPLAY, "重新播放");
		zh.put(EXIT, "退出视频");
		zh.put(CONTINUE, "继续播放");
		mLabels.put("zh", zh);
		
		// get extras
		Intent intent = getIntent();
		mVideoUrl = intent.getStringExtra(EXTRA_IN_VIDEO_URL);
		mAssetPath = intent.getStringExtra(EXTRA_IN_VIDEO_ASSET_PATH);
		mIsFile = intent.getBooleanExtra(EXTRA_IN_VIDEO_IS_FILE, false);
		int id = intent.getIntExtra(EXTRA_IN_VIDEO_RES_ID, 0);
		mCompletionIntent = (Intent)intent.getParcelableExtra(EXTRA_IN_COMPLETION_INTENT);
		mNoCompletionDialog = intent.getBooleanExtra(EXTRA_IN_NO_COMPLETION_DIALOG, false);
		mEndOnTouch = intent.getBooleanExtra(EXTRA_IN_END_ON_TOUCH, false);
		
		// 得到文件描述符
		if(TextUtils.isEmpty(mVideoUrl)) {
			try {
				if (mAssetPath != null) {
					if(!mIsFile)
						mFD = getAssets().openFd(mAssetPath);
				} else {
					mFD = getResources().openRawResourceFd(
						id);
				}
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
	}
	
	@Override
	protected Dialog onCreateDialog(int id) {
		switch(id) {
			case DIALOG_COMPLETION:
				return new AlertDialog.Builder(this)
					.setPositiveButton(getLabel(REPLAY), this)
					.setNegativeButton(getLabel(EXIT), this)
					.create();
			case DIALOG_PAUSE:
				return new AlertDialog.Builder(this)
					.setPositiveButton(getLabel(REPLAY), this)
					.setNegativeButton(getLabel(EXIT), this)
					.setNeutralButton(getLabel(CONTINUE), this)
					.create();
			default:
				return super.onCreateDialog(id);
		}
	}
	
	private String getLabel(int id) {
		String lan = getResources().getConfiguration().locale.getLanguage();
		if(lan.length() > 2)
			lan = lan.substring(0, 2);
		Map<Integer, String> map = mLabels.get(lan);
		if(map == null)
			return "";
		else
			return map.get(id);
	}
	
	@Override
	public boolean onKeyDown(int keyCode, KeyEvent event) {
		switch(event.getKeyCode()) {
			case KeyEvent.KEYCODE_BACK:
				mBackKeyTracking = true;
				return true;
			default:
				return false;
		}
	}
	
	@Override
	public boolean onKeyUp(int keyCode, KeyEvent event) {
		switch(event.getKeyCode()) {
			case KeyEvent.KEYCODE_BACK:
				if(mBackKeyTracking) {
					mBackKeyTracking = false;
					finish();
					return true;
				} else {
					return false;
				}
			default:
				return false;
		}
	}
	
	public boolean onTouch(View v, MotionEvent e) {
		if(mMediaPlayer != null){
			mMediaPlayer.pause();
			
			if(mEndOnTouch)
				end();
			else
				showPauseDialog();
		}
		return true;
	}

	public void surfaceChanged(SurfaceHolder holder, int format, int width,
			int height) {
        
	}

	public void surfaceCreated(SurfaceHolder holder) {
		playVideo();
	}

	public void surfaceDestroyed(SurfaceHolder holder) {
		if (mMediaPlayer != null) {
			mMediaPlayer.stop();
			mMediaPlayer.release();
			mMediaPlayer = null;
		}
	}
	
	private void start() {
		/* 设置视频的宽度和高度 */
		mHolder.setFixedSize(mVideoWidth, mVideoHeight);
		/* 开始播放 */
		mMediaPlayer.start();
	}
	
	public void onVideoSizeChanged(MediaPlayer mp, int width, int height) {
		if (width == 0 || height == 0) {
            return;
        }
        mIsVideoSizeKnown = true;
        mVideoWidth = width;
        mVideoHeight = height;
        if (mIsVideoReadyToBePlayed && mIsVideoSizeKnown) {
        	start();
        }
	}

	public void onPrepared(MediaPlayer mp) {
		mIsVideoReadyToBePlayed = true;
        if (mIsVideoReadyToBePlayed && mIsVideoSizeKnown) {
            start();
        }
	}
	
	public void onClick(DialogInterface arg0, int which) {
		switch(which) {
			case DialogInterface.BUTTON_POSITIVE:
				if (mMediaPlayer != null ) {
					mMediaPlayer.seekTo(0);
					mMediaPlayer.start();
				}
				break;
			case DialogInterface.BUTTON_NEUTRAL:
				if (mMediaPlayer != null ) {
					mMediaPlayer.start();
				}
				break;
			case DialogInterface.BUTTON_NEGATIVE:
				end();
				break;
		}
	}
	
	private void end() {
		if(mCompletionIntent != null) {
			ComponentName comp = mCompletionIntent.getComponent();
			if(comp == null) {
				sendBroadcast(mCompletionIntent);
			} else {
				try {
					startActivity(mCompletionIntent);
				} catch(ActivityNotFoundException e) {
				}
			}
			
			// clear intent
			mCompletionIntent = null;
		}
		
		finish();
	}

	public void onCompletion(MediaPlayer mp) {
		showCompletionDialog();
	}

	private void showPauseDialog() {
		setResult(RESULT_CANCELED);
		showDialog(DIALOG_PAUSE);
	}

	private void showCompletionDialog() {
		setResult(RESULT_OK);
		if(mNoCompletionDialog)
			end();
		else
			showDialog(DIALOG_COMPLETION);
	}

	public void onBufferingUpdate(MediaPlayer mp, int percent) {
	}

	private void playVideo() {
		try {
			/* 构建MediaPlayer对象 */
			if (mMediaPlayer == null ) {
				mMediaPlayer = new MediaPlayer();
			}
			mMediaPlayer.reset();
			
			/* 设置媒体文件路径 */
			if(TextUtils.isEmpty(mVideoUrl)) {
				if(mIsFile)
					mMediaPlayer.setDataSource(mAssetPath);
				else
					mMediaPlayer.setDataSource(mFD.getFileDescriptor(), mFD.getStartOffset(), mFD.getLength());
			} else {
				mMediaPlayer.setDataSource(mVideoUrl);
			}
			
			/* 设置通过SurfaceView来显示画面 */
			mMediaPlayer.setDisplay(mHolder);
			
			/* 准备 */
			mMediaPlayer.prepareAsync();
			
			/* 设置事件监听 */
			mMediaPlayer.setOnBufferingUpdateListener(this);
			mMediaPlayer.setOnCompletionListener(this);
			mMediaPlayer.setOnPreparedListener(this);
			mMediaPlayer.setOnVideoSizeChangedListener(this);
			mMediaPlayer.setAudioStreamType(AudioManager.STREAM_MUSIC);
		} catch (Exception e) {
			Log.e(WiEngine.LOG, "error: " + e.getMessage(), e);
		}
	}
}
