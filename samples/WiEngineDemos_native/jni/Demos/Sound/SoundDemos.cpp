#include "common.h"
#include "SoundDemos.h"
#include "WiEngine.h"
#include "WiEngine-WiSound.h"
#include <stdio.h>

namespace Sound {

class wyMP3TestLayer : public wyLayer {
public:
	wyLabel* m_hint;
	float m_volume;

public:
	wyMP3TestLayer(){
        wyMenuItemLabel* item1 = new wyMenuItemLabel(NULL,
        		wyTargetSelector::make(this, SEL(wyMP3TestLayer::onPlayBackgroundMusic)),
				 wyLabel::make("Play", SP(32), NORMAL));
        wyMenuItemLabel* item2 = new wyMenuItemLabel(NULL,
        		wyTargetSelector::make(this, SEL(wyMP3TestLayer::onStopBackgroundMusic)),
				 wyLabel::make("Stop", SP(32), NORMAL));
        wyMenuItemLabel* item3 = new wyMenuItemLabel(NULL,
        		wyTargetSelector::make(this, SEL(wyMP3TestLayer::onPlayMonoEffect)),
				 wyLabel::make("Effect(mono)", SP(32), NORMAL));
        wyMenuItemLabel* item4 = new wyMenuItemLabel(NULL,
        		wyTargetSelector::make(this, SEL(wyMP3TestLayer::onPlayStereoEffect)),
				 wyLabel::make("Effect(stereo)", SP(32), NORMAL));
        wyMenuItemLabel* item5 = new wyMenuItemLabel(NULL,
        		wyTargetSelector::make(this, SEL(wyMP3TestLayer::onVolumeDown)),
				 wyLabel::make("Volume Down", SP(32), NORMAL));
        wyMenuItemLabel* item6 = new wyMenuItemLabel(NULL,
        		wyTargetSelector::make(this, SEL(wyMP3TestLayer::onVolumeUp)),
				 wyLabel::make("Volume Up", SP(32), NORMAL));

        wyMenu* menu = new wyMenu((wyMenuItem*)item1->autoRelease(),
									item2->autoRelease(),
									item3->autoRelease(),
									item4->autoRelease(),
									item5->autoRelease(),
									item6->autoRelease(),
									NULL);
        menu->alignItemsVertically();

        addChildLocked(menu);
        wyObjectRelease(menu);

		// create a hint label
        m_volume = 1.0f;
		m_hint = wyLabel::make("background&effect volume: 1.0", SP(20));
		m_hint->setPosition(wyDevice::winWidth / 2, 100);
		addChildLocked(m_hint);

		// 不指定格式, 缺省是mp3
        wyAudioManager::getInstance()->preloadEffect(RES("R.raw.effect_mp3_mono"));
        wyAudioManager::getInstance()->preloadEffect(RES("R.raw.effect_mp3_stereo"));
	}

	virtual ~wyMP3TestLayer() {
	}

	void onPlayBackgroundMusic(wyTargetSelector* ts) {
		wyAudioManager::getInstance()->playBackgroundMusic(RES("R.raw.bg_mp3"), FORMAT_MP3, -1);
	}

	void onStopBackgroundMusic(wyTargetSelector* ts) {
		wyAudioManager::getInstance()->stopBackgroundMusic();
	}

	void onPlayMonoEffect(wyTargetSelector* ts) {
		wyAudioManager::getInstance()->playEffect(RES("R.raw.effect_mp3_mono"));
	}

	void onPlayStereoEffect(wyTargetSelector* ts) {
		wyAudioManager::getInstance()->playEffect(RES("R.raw.effect_mp3_stereo"));
	}

	void onVolumeDown(wyTargetSelector* ts) {
		m_volume -= 0.1f;
		m_volume = MAX(0, m_volume);
		wyAudioManager::getInstance()->setBackgroundVolume(m_volume);
		wyAudioManager::getInstance()->setEffectVolume(m_volume);
		char buf[64];
		sprintf(buf, "background&effect volume: %.1f", m_volume);
		m_hint->setText(buf);
	}

	void onVolumeUp(wyTargetSelector* ts) {
		m_volume += 0.1f;
		m_volume = MIN(1.0f, m_volume);
		wyAudioManager::getInstance()->setBackgroundVolume(m_volume);
		wyAudioManager::getInstance()->setEffectVolume(m_volume);
		char buf[64];
		sprintf(buf, "background&effect volume: %.1f", m_volume);
		m_hint->setText(buf);
	}
};

class wyOGGTestLayer : public wyLayer {
public:
	wyLabel* m_hint;
	float m_volume;

public:
	wyOGGTestLayer(){
        wyMenuItemLabel* item1 = new wyMenuItemLabel(NULL,
        		wyTargetSelector::make(this, SEL(wyOGGTestLayer::onPlayBackgroundMusic)),
				 wyLabel::make("Play", SP(32), NORMAL));
        wyMenuItemLabel* item2 = new wyMenuItemLabel(NULL,
        		wyTargetSelector::make(this, SEL(wyOGGTestLayer::onStopBackgroundMusic)),
				 wyLabel::make("Stop", SP(32), NORMAL));
        wyMenuItemLabel* item3 = new wyMenuItemLabel(NULL,
        		wyTargetSelector::make(this, SEL(wyOGGTestLayer::onPlayMonoEffect)),
				 wyLabel::make("Effect(mono)", SP(32), NORMAL));
        wyMenuItemLabel* item4 = new wyMenuItemLabel(NULL,
        		wyTargetSelector::make(this, SEL(wyOGGTestLayer::onPlayStereoEffect)),
				 wyLabel::make("Effect(stereo)", SP(32), NORMAL));
        wyMenuItemLabel* item5 = new wyMenuItemLabel(NULL,
        		wyTargetSelector::make(this, SEL(wyOGGTestLayer::onVolumeDown)),
				 wyLabel::make("Volume Down", SP(32), NORMAL));
        wyMenuItemLabel* item6 = new wyMenuItemLabel(NULL,
        		wyTargetSelector::make(this, SEL(wyOGGTestLayer::onVolumeUp)),
				 wyLabel::make("Volume Up", SP(32), NORMAL));

        wyMenu* menu = new wyMenu((wyMenuItem*)item1->autoRelease(),
									item2->autoRelease(),
									item3->autoRelease(),
									item4->autoRelease(),
									item5->autoRelease(),
									item6->autoRelease(),
									NULL);
        menu->alignItemsVertically();

        addChildLocked(menu);
        wyObjectRelease(menu);

		// create a hint label
        m_volume = 1.0f;
		m_hint = wyLabel::make("background&effect volume: 1.0", SP(20));
		m_hint->setPosition(wyDevice::winWidth / 2, 100);
		addChildLocked(m_hint);

		// 不指定格式, 缺省是mp3
        wyAudioManager::getInstance()->preloadEffect(RES("R.raw.effect_ogg_mono"), FORMAT_OGG);
        wyAudioManager::getInstance()->preloadEffect(RES("R.raw.effect_ogg_stereo"), FORMAT_OGG);
	}

	virtual ~wyOGGTestLayer() {
	}

	void onPlayBackgroundMusic(wyTargetSelector* ts) {
		wyAudioManager::getInstance()->playBackgroundMusic(RES("R.raw.bg_ogg"), FORMAT_OGG, -1);
	}

	void onStopBackgroundMusic(wyTargetSelector* ts) {
		wyAudioManager::getInstance()->stopBackgroundMusic();
	}

	void onPlayMonoEffect(wyTargetSelector* ts) {
		wyAudioManager::getInstance()->playEffect(RES("R.raw.effect_ogg_mono"), FORMAT_OGG);
	}

	void onPlayStereoEffect(wyTargetSelector* ts) {
		wyAudioManager::getInstance()->playEffect(RES("R.raw.effect_ogg_stereo"), FORMAT_OGG);
	}

	void onVolumeDown(wyTargetSelector* ts) {
		m_volume -= 0.1f;
		m_volume = MAX(0, m_volume);
		wyAudioManager::getInstance()->setBackgroundVolume(m_volume);
		wyAudioManager::getInstance()->setEffectVolume(m_volume);
		char buf[64];
		sprintf(buf, "background&effect volume: %.1f", m_volume);
		m_hint->setText(buf);
	}

	void onVolumeUp(wyTargetSelector* ts) {
		m_volume += 0.1f;
		m_volume = MIN(1.0f, m_volume);
		wyAudioManager::getInstance()->setBackgroundVolume(m_volume);
		wyAudioManager::getInstance()->setEffectVolume(m_volume);
		char buf[64];
		sprintf(buf, "background&effect volume: %.1f", m_volume);
		m_hint->setText(buf);
	}
};

class wyWAVTestLayer : public wyLayer {
public:
	wyLabel* m_hint;
	float m_volume;

public:
	wyWAVTestLayer(){
        wyMenuItemLabel* item1 = new wyMenuItemLabel(NULL,
        		wyTargetSelector::make(this, SEL(wyWAVTestLayer::onPlayBackgroundMusic)),
        		wyLabel::make("Play", SP(32), NORMAL));
        wyMenuItemLabel* item2 = new wyMenuItemLabel(NULL,
        		wyTargetSelector::make(this, SEL(wyWAVTestLayer::onStopBackgroundMusic)),
        		wyLabel::make("Stop", SP(32), NORMAL));
        wyMenuItemLabel* item3 = new wyMenuItemLabel(NULL,
        		wyTargetSelector::make(this, SEL(wyWAVTestLayer::onPlayMonoEffect)),
        		wyLabel::make("Effect(16bit, mono)", SP(32), NORMAL));
        wyMenuItemLabel* item4 = new wyMenuItemLabel(NULL,
        		wyTargetSelector::make(this, SEL(wyWAVTestLayer::onPlayStereoEffect)),
        		wyLabel::make("Effect(16bit, stereo)", SP(32), NORMAL));
        wyMenuItemLabel* item5 = new wyMenuItemLabel(NULL,
        		wyTargetSelector::make(this, SEL(wyWAVTestLayer::onVolumeDown)),
        		wyLabel::make("Volume Down", SP(32), NORMAL));
        wyMenuItemLabel* item6 = new wyMenuItemLabel(NULL,
        		wyTargetSelector::make(this, SEL(wyWAVTestLayer::onVolumeUp)),
        		wyLabel::make("Volume Up", SP(32), NORMAL));

        wyMenu* menu = new wyMenu((wyMenuItem*)item1->autoRelease(),
									item2->autoRelease(),
									item3->autoRelease(),
									item4->autoRelease(),
									item5->autoRelease(),
									item6->autoRelease(),
									NULL);
        menu->alignItemsVertically();

        addChildLocked(menu);
        wyObjectRelease(menu);

		// create a hint label
        m_volume = 1.0f;
		m_hint = wyLabel::make("background&effect volume: 1.0", SP(20));
		m_hint->setPosition(wyDevice::winWidth / 2, 100);
		addChildLocked(m_hint);

        wyAudioManager::getInstance()->preloadEffect(RES("R.raw.effect_wav_mono_16"), FORMAT_WAV);
        wyAudioManager::getInstance()->preloadEffect(RES("R.raw.effect_wav_stereo_16"), FORMAT_WAV);
	}

	virtual ~wyWAVTestLayer() {
	}

	void onPlayBackgroundMusic(wyTargetSelector* ts) {
		wyAudioManager::getInstance()->playBackgroundMusic(RES("R.raw.bg_wav_mono_16"), FORMAT_WAV, -1);
	}

	void onStopBackgroundMusic(wyTargetSelector* ts) {
		wyAudioManager::getInstance()->stopBackgroundMusic();
	}

	void onPlayMonoEffect(wyTargetSelector* ts) {
		wyAudioManager::getInstance()->playEffect(RES("R.raw.effect_wav_mono_16"), FORMAT_WAV);
	}

	void onPlayStereoEffect(wyTargetSelector* ts) {
		wyAudioManager::getInstance()->playEffect(RES("R.raw.effect_wav_stereo_16"), FORMAT_WAV);
	}

	void onVolumeDown(wyTargetSelector* ts) {
		m_volume -= 0.1f;
		m_volume = MAX(0, m_volume);
		wyAudioManager::getInstance()->setBackgroundVolume(m_volume);
		wyAudioManager::getInstance()->setEffectVolume(m_volume);
		char buf[64];
		sprintf(buf, "background&effect volume: %.1f", m_volume);
		m_hint->setText(buf);
	}

	void onVolumeUp(wyTargetSelector* ts) {
		m_volume += 0.1f;
		m_volume = MIN(1.0f, m_volume);
		wyAudioManager::getInstance()->setBackgroundVolume(m_volume);
		wyAudioManager::getInstance()->setEffectVolume(m_volume);
		char buf[64];
		sprintf(buf, "background&effect volume: %.1f", m_volume);
		m_hint->setText(buf);
	}
};

}

using namespace Sound;

DEMO_ENTRY_IMPL(sound, MP3Test);
DEMO_ENTRY_IMPL(sound, OGGTest);
DEMO_ENTRY_IMPL(sound, WAVTest);
