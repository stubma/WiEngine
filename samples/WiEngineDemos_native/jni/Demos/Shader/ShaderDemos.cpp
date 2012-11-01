#include "ShaderDemos.h"
#include "common.h"
#include "WiEngine.h"

namespace Shader {

    static void createButton(const char* label, wyLayer* layer, float x, float y, wyTargetSelector* ts) {
		wyNinePatchSprite* normal1 = wyNinePatchSprite::make(wyTexture2D::makePNG(RES("R.drawable.btn_normal")), wyr(DP(9), DP(7), DP(22), DP(28)));
		wyNinePatchSprite* pressed1 = wyNinePatchSprite::make(wyTexture2D::makePNG(RES("R.drawable.btn_pressed")), wyr(DP(9), DP(7), DP(22), DP(28)));
		normal1->setContentSize(DP(300), DP(44));
		pressed1->setContentSize(DP(300), DP(44));
        
		wyButton* button1 = wyButton::make(normal1, pressed1, NULL, NULL, NULL, ts);
		button1->setPosition(x, y);
        
		wyBitmapFont* font = wyBitmapFont::loadFont(RES("R.raw.bitmapfont"));
		wyBitmapFontLabel* label1 = wyBitmapFontLabel::make(font, label);
		label1->setColor(wyc3b(255, 255, 0));
		label1->setPosition(x, y);
        
		layer->addChildLocked(button1);
		layer->addChildLocked(label1);
	}
    
	/////////////////////////////////////////////////////////////////////////////////

	static const GLenum ALPHA_FUNC[] = {
		GL_NEVER,
		GL_LESS,
		GL_LEQUAL,
		GL_EQUAL,
		GL_GEQUAL,
		GL_GREATER,
		GL_NOTEQUAL
	};

	static const char* ALPHA_FUNC_TEXT[] = {
		"NEVER",
		"LESS",
		"LEQUAL",
		"EQUAL",
		"GEQUAL",
		"GREATER",
		"NOTEQUAL"
	};

	class wyAlphaTestTestLayer : public wyLayer {
	private:
		wySprite* m_sprite;
		wySlider* m_slider;
		wyLabel* m_hint;
		wyBitmapFontLabel* m_funcLabel;
		GLenum m_alphaFunc;

		int m_currentFunc;

	public:
		wyAlphaTestTestLayer() {
			// init member
			m_currentFunc = 4;
			m_alphaFunc = ALPHA_FUNC[m_currentFunc];

			// create
			m_sprite = wySprite::make(wyTexture2D::makePNG(RES("R.drawable.alpha_test")));
			m_sprite->setPosition(wyDevice::winWidth / 2, wyDevice::winHeight / 2 + DP(80));
			addChildLocked(m_sprite);

			// create a hint label
			m_hint = wyLabel::make("drag slider", SP(18));
			m_hint->setPosition(wyDevice::winWidth / 2, DP(80));
			addChildLocked(m_hint);

			// alpha value slider
			wySprite* bar = wySprite::make(wyTexture2D::makePNG(RES("R.drawable.bar")));
			wySprite* thumb = wySprite::make(wyTexture2D::makePNG(RES("R.drawable.thumb")));
			m_slider = wySlider::make(NULL, bar, thumb);
			m_slider->setValue(0);
			m_slider->setMax(255);
			m_slider->setShowFullBar(true);
			m_slider->setPosition(wyDevice::winWidth / 2, DP(50));
			wySliderCallback callback = {
				onValueChanged
			};
			m_slider->setCallback(&callback, this);
			addChildLocked(m_slider);

			// alpha func button
			wyNinePatchSprite* normal = wyNinePatchSprite::make(wyTexture2D::makePNG(RES("R.drawable.btn_normal")), wyr(DP(9), DP(7), DP(22), DP(28)));
			wyNinePatchSprite* pressed = wyNinePatchSprite::make(wyTexture2D::makePNG(RES("R.drawable.btn_pressed")), wyr(DP(9), DP(7), DP(22), DP(28)));
			normal->setContentSize(DP(280), DP(44));
			pressed->setContentSize(DP(280), DP(44));
			wyButton* button = wyButton::make(normal, pressed, NULL, NULL, NULL,
											  wyTargetSelector::make(this, SEL(wyAlphaTestTestLayer::onSelectAlphaFunc)));
			button->setPosition(wyDevice::winWidth / 2, wyDevice::winHeight - DP(30));
			addChildLocked(button, 1);

			// label for alpha func button
			wyBitmapFont* font = wyBitmapFont::loadFont(RES("R.raw.bitmapfont"));
			m_funcLabel = wyBitmapFontLabel::make(font, ALPHA_FUNC_TEXT[4]);
			m_funcLabel->setColor(wyc3b(255, 255, 0));
			m_funcLabel->setPosition(wyDevice::winWidth / 2, wyDevice::winHeight - DP(30));
			addChildLocked(m_funcLabel, 1);
		}

		virtual ~wyAlphaTestTestLayer() {
		}

		void onSelectAlphaFunc(wyTargetSelector* ts) {
			// TODO gles2
			//m_currentFunc++;
			//m_currentFunc %= 7;
			//m_alphaFunc = ALPHA_FUNC[m_currentFunc];
			//m_funcLabel->setText(ALPHA_FUNC_TEXT[m_currentFunc]);
			//m_sprite->setAlphaFunc(m_alphaFunc, m_slider->getValue() / 255.f);
		}

		static void onValueChanged(wySlider* slider, void* data) {
			// TODO gles2
			//wyAlphaTestTestLayer* layer = (wyAlphaTestTestLayer*)data;
			//layer->m_sprite->setAlphaFunc(layer->m_alphaFunc, slider->getValue() / 255.f);
			//
			//char buf[8];
			//sprintf(buf, "%d", (int)slider->getValue());
			//layer->m_hint->setText(buf);
		}
	};

	//////////////////////////////////////////////////////////////////////////////////////////
}

using namespace Shader;

#if ANDROID
	#define DEMO_ENTRY_IMPL(testname) JNIEXPORT void JNICALL Java_com_wiyun_engine_tests_shader_##testname##_nativeStart \
		(JNIEnv *, jobject){ \
			wyLayer* layer = new wy##testname##Layer(); \
			runDemo(layer, NULL); \
			wyObjectRelease(layer); \
		}
#elif IOS || MACOSX || WINDOWS
	#define DEMO_ENTRY_IMPL(CLASSNAME) void _shader_##CLASSNAME##Launcher() { \
			wyLayer* layer = new wy##CLASSNAME##Layer(); \
			runDemo(layer, NULL); \
			wyObjectRelease(layer); \
		}
#endif

DEMO_ENTRY_IMPL(AlphaTestTest);
