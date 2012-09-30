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
package com.wiyun.engine.tests.sound;

import android.os.Bundle;

import com.wiyun.engine.R;
import com.wiyun.engine.WiEngineTestActivity;
import com.wiyun.engine.nodes.Director;
import com.wiyun.engine.nodes.Label;
import com.wiyun.engine.nodes.Layer;
import com.wiyun.engine.nodes.Menu;
import com.wiyun.engine.nodes.MenuItemLabel;
import com.wiyun.engine.sound.AudioManager;
import com.wiyun.engine.types.WYSize;

public class WAVTest extends WiEngineTestActivity {
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		
		// demo controls music stream
		setVolumeControlStream(android.media.AudioManager.STREAM_MUSIC);
	}
	
	@Override
	protected Layer createLayer() {
		return new MyLayer();
	}

	class MyLayer extends Layer {
		private Label mLabel;
		private float mVolume;
		
		public MyLayer() {
			MenuItemLabel item1 = MenuItemLabel.make("Play", this, "onPlay");
			MenuItemLabel item2 = MenuItemLabel.make("Stop", this, "onStop");
			MenuItemLabel item3 = MenuItemLabel.make("Effect(16bit,mono)", this, "onEffect1");
			MenuItemLabel item4 = MenuItemLabel.make("Effect(16bit,stereo)", this, "onEffect2");
			MenuItemLabel item5 = MenuItemLabel.make("Volumn Up", this, "onVolumnUp");
			MenuItemLabel item6 = MenuItemLabel.make("Volumn Down", this, "onVolumnDown");

			Menu menu = Menu.make(item1, item2, item3, item4, item5, item6);
			menu.alignItemsVertically();

			addChild(menu);
			
			mVolume = 1.0f;
			WYSize s = Director.getInstance().getWindowSize();
            mLabel = Label.make("background&effect volumn: 1.0", 20);
            mLabel.setPosition(s.width / 2, 100);
            addChild(mLabel);

			AudioManager.preloadEffect(R.raw.effect_wav_mono_16, AudioManager.FORMAT_WAV);
			AudioManager.preloadEffect(R.raw.effect_wav_stereo_16, AudioManager.FORMAT_WAV);
		}

		public void onPlay() {
			AudioManager.playBackgroundMusic(R.raw.bg_wav_mono_16, AudioManager.FORMAT_WAV, -1);
		}

		public void onStop() {
			AudioManager.stopBackgroundMusic();
		}

		public void onEffect1() {
			AudioManager.playEffect(R.raw.effect_wav_mono_16);
		}

		public void onEffect2() {
			AudioManager.playEffect(R.raw.effect_wav_stereo_16);
		}

		public void onVolumnUp() {
			mVolume += 0.1f;
			mVolume = Math.min(1.0f, mVolume);
			AudioManager.setBackgroundVolume(mVolume);
			AudioManager.setEffectVolume(mVolume);
			mLabel.setText(String.format("background&effect volumn: %.1f", mVolume));
		}
		
		public void onVolumnDown() {
			mVolume -= 0.1f;
			mVolume = Math.max(0.0f, mVolume);
			AudioManager.setBackgroundVolume(mVolume);
			AudioManager.setEffectVolume(mVolume);
			mLabel.setText(String.format("background&effect volumn: %.1f", mVolume));
		}
	}
}
