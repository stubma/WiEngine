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

public class MP3Test extends WiEngineTestActivity {
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
			MenuItemLabel item3 = MenuItemLabel.make("Effect(mono)", this, "onEffect1");
			MenuItemLabel item4 = MenuItemLabel.make("Effect(stereo)", this, "onEffect2");
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

			AudioManager.preloadEffect(R.raw.effect_mp3_mono, AudioManager.FORMAT_MP3);
			AudioManager.preloadEffect(R.raw.effect_mp3_stereo, AudioManager.FORMAT_MP3);
		}

		public void onPlay() {
			AudioManager.playBackgroundMusic(R.raw.bg_mp3, AudioManager.FORMAT_MP3, -1);
		}

		public void onStop() {
			AudioManager.stopBackgroundMusic();
		}

		public void onEffect1() {
			AudioManager.playEffect(R.raw.effect_mp3_mono);
		}

		public void onEffect2() {
			AudioManager.playEffect(R.raw.effect_mp3_stereo);
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
