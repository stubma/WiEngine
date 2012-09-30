/*
 * Copyright (c) 2010 WiYun Inc.
 * Author: luma(stubma@gmail.com)
 *
 * For all entities this program is free software; you can redistribute
 * it and/or modify it under the terms of the 'WiEngine' license with
 * the additional provision that 'WiEngine' must be credited in a manner
 * that can be be observed by end users, for example, in the credits or during
 * start up. (please find WiEngine logo in sdk's logo folder)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
package com.wiyun.engine.sound;

import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import android.content.Context;
import android.content.res.AssetFileDescriptor;
import android.content.res.AssetManager;
import android.media.AudioTrack;
import android.media.MediaPlayer;
import android.media.SoundPool;
import android.util.Log;

import com.wiyun.engine.nodes.Director;

/**
 * \if English
 * Audio manager
 * \else
 * 音频管理器
 * \endif
 */
public class AudioManager implements AudioTrack.OnPlaybackPositionUpdateListener {
	public final static int FORMAT_MP3 = 1;
	public final static int FORMAT_WAV = 2;
	public final static int FORMAT_OGG = 3;
	
	/*
	 * for mediaplayer backend
	 */
	
	private static MediaPlayer sPlayer;
	private static SoundPool sPool;
	private static Map<Integer, Integer> sResId2SoundIdMap;
	private static Map<Integer, List<Integer>> sSoundId2StreamIdMap;
	private static Map<String, Integer> sPath2SoundIdMap;
	private static int sBgRepeatCount;
	private static boolean sPlaying;
	private static float sBgVolume;
	private static float sEffectVolume;
	private static int sBgResId;
	private static String sBgPath;
	private static boolean sMute;
	private static boolean sCanPlay;
	
	synchronized static void setupMediaPlayerBackend() {
		sPool = new SoundPool(10, android.media.AudioManager.STREAM_MUSIC, 0);
		sResId2SoundIdMap = new HashMap<Integer, Integer>();
		sSoundId2StreamIdMap = new HashMap<Integer, List<Integer>>();
		sPath2SoundIdMap = new HashMap<String, Integer>();
		sBgRepeatCount = -1;
		sPlaying = false;
		sBgVolume = 1.0f;
		sEffectVolume = 1.0f;
		sBgResId = 0;
		sBgPath = null;
		sMute = false;
		sCanPlay = false;
		
		sPlayer = new MediaPlayer();
		sPlayer.setLooping(false);
		sPlayer.setAudioStreamType(android.media.AudioManager.STREAM_MUSIC);
		sPlayer.setOnCompletionListener(new MediaPlayer.OnCompletionListener() {
			public void onCompletion(MediaPlayer player) {
				if(sBgRepeatCount != 0) {
					if(sBgRepeatCount > 0)
						sBgRepeatCount--;
					sPlayer.start();
				} else {
					sPlaying = false;
				}
			}
		});
		sPlayer.setOnPreparedListener(new MediaPlayer.OnPreparedListener() {
			public void onPrepared(MediaPlayer player) {
				sCanPlay = true;
				if(sPlaying) {
					sPlayer.start();
				}
			}
		});
	}
	
	synchronized static void destroyMediaPlayerBackend() {
		if(sPlayer != null) {
			sPlayer.stop();
			sPlayer.release();
			sPlayer = null;
		}
		if(sPool != null) {
			sPool.release();
			sPool = null;
		}
		sResId2SoundIdMap.clear();
		sResId2SoundIdMap = null;
		sPath2SoundIdMap.clear();
		sPath2SoundIdMap = null;
		sSoundId2StreamIdMap.clear();
		sSoundId2StreamIdMap = null;
	}
	
	synchronized static void mpPreloadBackgroundMusic(int resId) {
		if(sPlayer == null)
			return;
		
		Context context = Director.getInstance().getContext();
		AssetFileDescriptor afd = context.getResources().openRawResourceFd(resId);
		try {
			sPlayer.setDataSource(afd.getFileDescriptor(), afd.getStartOffset(), afd.getLength());
			sPlayer.prepareAsync();
			sBgResId = resId;
		} catch (Exception e) {
			Log.w("libwiengine", "Failed to preload background music: " + resId);
		} finally {
			try {
				if(afd != null)
					afd.close();
			} catch (IOException e) {
			}
		}
	}
	
	synchronized static void mpPreloadBackgroundMusic(String path, boolean isFile) {
		if(sPlayer == null)
			return;
		
		AssetFileDescriptor afd = null;
		try {
			if(isFile)
				sPlayer.setDataSource(path);
			else {
				Context context = Director.getInstance().getContext();
				AssetManager am = context.getAssets();
				afd = am.openFd(path);
				sPlayer.setDataSource(afd.getFileDescriptor(), afd.getStartOffset(), afd.getLength());
			}
			sPlayer.prepareAsync();
			sBgPath = path;
		} catch (Exception e) {
			Log.w("libwiengine", "Failed to preload background music: " + path);
		} finally {
			try {
				if(afd != null)
					afd.close();
			} catch (IOException e) {
			}
		}
	}
	
	synchronized static void mpPlayBackgroundMusic(int resId, int format, int repeatCount) {
		if(sPlayer == null)
			return;
		
		if(!sPlaying) {
			sPlaying = true;
			sBgRepeatCount = repeatCount;
			if(sBgResId != resId) {
				sCanPlay = false;
				mpPreloadBackgroundMusic(resId);
			}
			if(sCanPlay)
				sPlayer.start();
		}
	}
	
	synchronized static void mpPlayBackgroundMusic(String path, boolean isFile, int repeatCount) {
		if(sPlayer == null)
			return;
		
		if(!sPlaying) {
			sPlaying = true;
			sBgRepeatCount = repeatCount;
			if(!path.equals(sBgPath)) {
				sCanPlay = false;
				mpPreloadBackgroundMusic(path, isFile);
			}
			if(sCanPlay)
				sPlayer.start();
		}
	}
	
	synchronized static void mpStopBackgroundMusic() {
		if(sPlayer == null)
			return;
		
		if(sPlaying) {
			/*
			 * MediaPlayer.stop has a bug, http://code.google.com/p/android/issues/detail?id=1191
			 * so we have to reset it to ensure next start() works
			 */
			sPlayer.stop();
			sPlayer.reset();
			sBgResId = 0;
			sBgPath = null;
			sPlaying = false;
		}
	}
	
	synchronized static void mpPauseBackgroundMusic() {
		if(sPlayer == null)
			return;
		
		if(sPlaying) {
			sPlayer.pause();
		}
	}
	
	synchronized static void mpResumeBackgroundMusic() {
		if(sPlayer == null)
			return;
		
		if(sPlaying) {
			sPlayer.start();
		}
	}
	
	synchronized static boolean mpIsBackgroundPlaying() {
		if(sPlayer == null)
			return false;
		
		return sPlaying;
	}
	
	synchronized static void mpSetBackgroundVolume(float volume) {
		if(sPlayer == null)
			return;
		
		sBgVolume = volume;
		if(!sMute)
			sPlayer.setVolume(volume, volume);
	}
	
	synchronized static void mpSetEffectVolume(float volume) {
		sEffectVolume = volume;
		
		// change volume of playing effect
		for(Map.Entry<Integer, List<Integer>> entry : sSoundId2StreamIdMap.entrySet()) {
			for(Integer streamId : entry.getValue()) {
				sPool.setVolume(streamId, sEffectVolume, sEffectVolume);
			}
		}
	}
	
	synchronized static void mpPreloadEffect(int resId) {
		if(sPool == null || sResId2SoundIdMap == null)
			return;
		
		if(!sResId2SoundIdMap.containsKey(resId)) {
			int soundId = sPool.load(Director.getInstance().getContext(), resId, 0);
			sResId2SoundIdMap.put(resId, soundId);
		}
	}
	
	synchronized static void mpPreloadEffect(String path, boolean isFile) {
		if(sPool == null || sPath2SoundIdMap == null)
			return;
		
		if(!sPath2SoundIdMap.containsKey(path)) {
			AssetFileDescriptor afd = null;
			int soundId = -1;
			try {
				if(isFile)
					soundId = sPool.load(path, 0);
				else {
					Context context = Director.getInstance().getContext();
					AssetManager am = context.getAssets();
					afd = am.openFd(path);
					soundId = sPool.load(afd, 0);
				}
				if(soundId != -1) {
					sPath2SoundIdMap.put(path, soundId);
				}
			} catch (IOException e) {
			} finally {
				try {
					if(afd != null)
						afd.close();
				} catch (IOException e) {
				}
			}
		}
	}
	
	synchronized static void mpPlayEffect(int resId) {
		if(sPool == null || sResId2SoundIdMap == null)
			return;
		
		mpPreloadEffect(resId);
		Integer soundId = sResId2SoundIdMap.get(resId);
		if(soundId != null) {
			int streamId = sPool.play(soundId, sMute ? 0 : sEffectVolume, sMute ? 0 : sEffectVolume, 0, 0, 1);
			if(streamId == 0) {
				Log.w("libwiengine", "Failed to play sound resId: " + resId);
				return;
			}
			
			List<Integer> streamIds = sSoundId2StreamIdMap.get(soundId);
			if(streamIds == null) {
				streamIds = new ArrayList<Integer>();
				sSoundId2StreamIdMap.put(soundId, streamIds);
			}
			streamIds.add(streamId);
		}
	}
	
	synchronized static void mpPlayEffect(String path, boolean isFile) {
		if(sPool == null || sPath2SoundIdMap == null)
			return;
		
		mpPreloadEffect(path, isFile);
		Integer soundId = sPath2SoundIdMap.get(path);
		if(soundId != null) {
			int streamId = sPool.play(soundId, sMute ? 0 : sEffectVolume, sMute ? 0 : sEffectVolume, 0, 0, 1);
			if(streamId == 0) {
				Log.w("libwiengine", "Failed to play sound path: " + path);
				return;
			}
			
			List<Integer> streamIds = sSoundId2StreamIdMap.get(soundId);
			if(streamIds == null) {
				streamIds = new ArrayList<Integer>();
				sSoundId2StreamIdMap.put(soundId, streamIds);
			}
			streamIds.add(streamId);
		}
	}
	
	synchronized static void mpStopEffect(int resId) {
		if(sPool == null || sResId2SoundIdMap == null)
			return;
		
		if(sResId2SoundIdMap.containsKey(resId)) {
			Integer soundId = sResId2SoundIdMap.get(resId);
			if(soundId != null) {
				List<Integer> streamIds = sSoundId2StreamIdMap.get(soundId);
				if(streamIds != null) {
					for(int streamId : streamIds)
						sPool.stop(streamId);
					sSoundId2StreamIdMap.remove(soundId);
				}
			}
		}
	}
	
	synchronized static void mpStopEffect(String path) {
		if(sPool == null || sPath2SoundIdMap == null)
			return;
		
		if(sPath2SoundIdMap.containsKey(path)) {
			Integer soundId = sPath2SoundIdMap.get(path);
			if(soundId != null) {
				List<Integer> streamIds = sSoundId2StreamIdMap.get(soundId);
				if(streamIds != null) {
					for(int streamId : streamIds)
						sPool.stop(streamId);
					sSoundId2StreamIdMap.remove(soundId);
				}
			}
		}
	}
	
	synchronized static void mpRemoveAllEffects() {
		if(sPool == null || sResId2SoundIdMap == null)
			return;
		
		for(Map.Entry<Integer, Integer> entry : sResId2SoundIdMap.entrySet()) {
			int soundId = entry.getValue();
			List<Integer> streamIds = sSoundId2StreamIdMap.get(soundId);
			if(streamIds != null) {
				for(int streamId : streamIds)
					sPool.stop(streamId);
			}
			sPool.unload(soundId);
		}
		for(Map.Entry<String, Integer> entry : sPath2SoundIdMap.entrySet()) {
			int soundId = entry.getValue();
			List<Integer> streamIds = sSoundId2StreamIdMap.get(soundId);
			if(streamIds != null) {
				for(int streamId : streamIds)
					sPool.stop(streamId);
			}
			sPool.unload(soundId);
		}
		sSoundId2StreamIdMap.clear();
		sResId2SoundIdMap.clear();
		sPath2SoundIdMap.clear();
	}
	
	synchronized static void mpRemoveEffect(int resId) {
		if(sPool == null || sResId2SoundIdMap == null)
			return;
		
		Integer soundId = sResId2SoundIdMap.remove(resId);
		if(soundId != null) {
			List<Integer> streamIds = sSoundId2StreamIdMap.remove(soundId);
			if(streamIds != null) {
				for(int streamId : streamIds)
					sPool.stop(streamId);
			}
			sPool.unload(soundId);
		}
	}
	
	synchronized static void mpRemoveEffect(String path) {
		if(sPool == null || sPath2SoundIdMap == null)
			return;
		
		Integer soundId = sPath2SoundIdMap.remove(path);
		if(soundId != null) {
			List<Integer> streamIds = sSoundId2StreamIdMap.remove(soundId);
			if(streamIds != null) {
				for(int streamId : streamIds)
					sPool.stop(streamId);
			}
			sPool.unload(soundId);
		}
	}
	
	synchronized static void mpSetMute(boolean mute) {
		if(sPool == null)
			return;
		if(sPlayer == null)
			return;
		
		if(sMute != mute) {
			sMute = mute;
			if(mute) {
				sPlayer.setVolume(0, 0);
				for(Map.Entry<Integer, List<Integer>> entry : sSoundId2StreamIdMap.entrySet()) {
					List<Integer> streamIds = entry.getValue();
					for(int streamId : streamIds) {
						sPool.setVolume(streamId, 0, 0);
					}
				}
			} else {
				sPlayer.setVolume(sBgVolume, sBgVolume);
				for(Map.Entry<Integer, List<Integer>> entry : sSoundId2StreamIdMap.entrySet()) {
					List<Integer> streamIds = entry.getValue();
					for(int streamId : streamIds) {
						sPool.setVolume(streamId, sEffectVolume, sEffectVolume);
					}
				}
			}
		}
	}
	
	synchronized static boolean mpIsMute() {
		return sMute;
	}
	
	/**
	 * 根据音频资源id预载入MP3背景音乐
	 *
	 * @param resId 音频文件的资源id
	 */
	public static native void preloadBackgroundMusic(int resId);
	
	/**
	 * 根据音频资源id预载入背景音乐
	 *
	 * @param resId 音频文件的资源id
	 * @param type 音频文件类型, 缺省是MP3
	 */
	public static native void preloadBackgroundMusic(int resId, int type);

	/**
	 * 根据音频资源路径预载入背景音乐
	 *
	 * @param path 音频文件路径
	 * @param isFile true表示path是一个文件系统路径, false表示path是一个asset下的路径, 缺省是false
	 */
	public static native void preloadBackgroundMusic(String path, boolean isFile);
	
	/**
	 * 根据资源id播放一个mp3背景音乐, 无限循环播放
	 *
	 * @param resId 音频文件的资源id
	 */
	public native static void playBackgroundMusic(int resId);
	
	/**
	 * 根据资源id播放
	 *
	 * @param resId 音频文件的资源id
	 * @param format 音频文件类型
	 * @param repeatCount 循环播放次数，0表示不循环, -1表示无限循环, 大于0表示循环次数，默认是0
	 */
	public native static void playBackgroundMusic(int resId, int format, int repeatCount);

	/**
	 * 根据文件名播放, 音频文件的类型通过路径中的扩展名判断. 所以可以是wav, mp3和ogg, 大小写没有关系.
	 *
	 * @param path 音频文件路径
	 * @param isFile true表示path是一个文件系统路径, false表示path是一个asset下的路径
	 * @param repeatCount 循环播放次数，0表示不循环, -1表示无限循环, 大于0表示循环次数，默认是0
	 */
	public native static void playBackgroundMusic(String path, boolean isFile, int repeatCount);
	
	/**
	 * 停止播放背景音乐并释放音频流
	 */
	public native static void stopBackgroundMusic();
	
	/**
	 * 返回当前是否暂停播放背景
	 */
	public native static boolean isBackgroundMusicPaused();

	/**
	 * 暂停播放背景
	 */
	public native static void pauseBackgroundMusic();

	/**
	 * 继续播放背景
	 */
	public native static void resumeBackgroundMusic();
	
	/**
	 * 当前是否有背景音乐在播放
	 */
	public native static boolean isBackgroundPlaying();
	
	/**
	 * 清除所有预加载音效
	 */
	public native static void removeAllEffects();

	/**
	 * \if English
	 * remove one effect by resource id
	 *
	 * @param resId resource id of effect file
	 * \else
	 * 根据资源id删除一个音效
	 *
	 * @param resId 音效文件的资源id
	 * \endif
	 */
	public native static void removeEffect(int resId);

	/**
	 * \if English
	 * Remove one effect by effect path
	 *
	 * @param path of effect file
	 * \else
	 * 根据音效路径删除一个音效
	 *
	 * @param path 音效文件路径
	 * \endif
	 */
	public native static void removeEffect(String path);
	
	/**
	 * 播放一个声音资源文件
	 * 
	 * @param resId 声音文件资源id
	 */
	public native static void playEffect(int resId);
	
	/**
	 * 播放一个声音资源文件
	 *
	 * @param resId 音频文件的资源id
	 * @param type 音频文件类型, 如果相关的音频资源已经预载入过, 则这个参数可以不传
	 */
	public native static void playEffect(int resId, int type);

	/**
	 * 根据文件名播放, 音频文件的类型通过路径中的扩展名判断. 所以可以是wav, mp3和ogg, 大小写没有关系.
	 *
	 * @param path 音频文件路径
	 */
	public static void playEffect(String path) {
		playEffect(path, false);
	}
	
	/**
	 * 根据文件名播放, 音频文件的类型通过路径中的扩展名判断. 所以可以是wav, mp3和ogg, 大小写没有关系.
	 *
	 * @param path 音频文件路径
	 * @param isFile true表示path是一个文件系统路径, false表示path是一个asset下的路径. 缺省是false.
	 */
	public native static void playEffect(String path, boolean isFile);
	
	/**
	 * 停止某个音频
	 *
	 * @param resId 音频文件的资源id
	 */
	public native static void stopEffect(int resId);

	/**
	 * 根据assets下的音频文件路径停止一个音频流
	 *
	 * @param path 音频文件在assets下的路径
	 */
	public static void stopEffect(String path){
		stopEffect(path, false);
	}
	
	/**
	 * 根据文件名停止
	 *
	 * @param path 音频文件路径
	 * @param isFile true表示path是一个文件系统路径, false表示path是一个asset下的路径. 缺省是false.
	 */
	public native static void stopEffect(String path, boolean isFile);
	
	/**
	 * 根据资源id加载一个mp3音频文件
	 *
	 * @param resId 音频文件的资源id
	 */
	public native static void preloadEffect(int resId);
	
	/**
	 * 根据资源id加载
	 *
	 * @param resId 音频文件的资源id
	 * @param type 音频文件类型
	 */
	public native static void preloadEffect(int resId, int type);

	/**
	 * 预先载入assets下的声音
	 * 
	 * @param path 声音文件在assets下的路径
	 */
	public static void preloadEffect(String path) {
		preloadEffect(path, false);
	}
	
	/**
	 * 预先载入声音
	 * 
	 * @param path 声音文件的路径
	 * @param isFile 如果为true, 表示path是一个文件系统路径, 否则path是一个assets下的相对路径
	 */
	public native static void preloadEffect(String path, boolean isFile);
	
	/**
	 * 设置特效声音的音量
	 *
	 * @param volume 特效声音音量，从0到1.0
	 */
	public native static void setEffectVolume(float volume);
	
	/**
	 * 设置背景音乐的音量
	 *
	 * @param volume 背景音乐音量，从0到1.0
	 */
	public native static void setBackgroundVolume(float volume);
	
	private native static void onPeriodicNotification();
	
	/**
	 * \if English
	 * set mute on or off
	 * \else
	 * 设置静音
	 * \endif
	 */
	public native static void setMute(boolean mute);
	
	/**
	 * \if English
	 * is mute on or off?
	 * \else
	 * 判断是否处于静音状态
	 * \endif
	 */
	public native static boolean isMuted();

	@Override
    public void onMarkerReached(AudioTrack track) {
    }

	@Override
    public void onPeriodicNotification(AudioTrack track) {
		onPeriodicNotification();
    }
}
