#include "PerformanceDemos.h"
#include "common.h"
#include "WiEngine.h"

namespace Performance {

    static void createButton(const char* label, wyLayer* layer, float x, float y, wyTargetSelector* ts) {
		wyNinePatchSprite* normal1 = wyNinePatchSprite::make(wyTexture2D::make(RES("R.drawable.btn_normal")), wyr(DP(9), DP(7), DP(22), DP(28)));
		wyNinePatchSprite* pressed1 = wyNinePatchSprite::make(wyTexture2D::make(RES("R.drawable.btn_pressed")), wyr(DP(9), DP(7), DP(22), DP(28)));
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
    
	class wyBatchRenderSpriteTestLayer : public wyLayer {
	private:
		wyLabel* m_countLabel;
		int m_count;
		wySpriteBatchNode* m_batchNode;

	public:
		wyBatchRenderSpriteTestLayer() {
			// add sprite button
			createButton("Add 50 Sprites", this, wyDevice::winWidth / 2, wyDevice::winHeight - DP(40),
					  wyTargetSelector::make(this, SEL(wyBatchRenderSpriteTestLayer::onAddSprite)));

			// count label
			m_countLabel = wyLabel::make("0 Sprites", SP(16));
			m_countLabel->setPosition(wyDevice::winWidth / 2, wyDevice::winHeight - DP(80));
			m_countLabel->setColor(wyc3bRed);
			addChildLocked(m_countLabel);
			m_count = 0;

			// batch node
			m_batchNode = wySpriteBatchNode::make(wyTexture2D::make(RES("R.drawable.blocks")));
			m_batchNode->setPosition(0, 0);
			addChildLocked(m_batchNode, -1);
		}

		virtual ~wyBatchRenderSpriteTestLayer() {
		}

		void onAddSprite(wyTargetSelector* ts) {
			float size = DP(32.0f);
			for(int i = 0; i < 50; i++) {
				wySpriteEx* s = wySpriteEx::make(m_batchNode, wyr(wyMath::randMax(1) * size, wyMath::randMax(1) * size, size, size));
				s->setPosition(wyMath::randMax(wyDevice::winWidth), wyMath::randMax(wyDevice::winHeight));
			}

			// update count label
			m_count += 50;
			char buf[32];
			sprintf(buf, "%d Sprites", m_count);
			m_countLabel->setText(buf);
		}
	};

	/////////////////////////////////////////////////////////////////////////////////

	class wyRenderSpriteTestLayer : public wyLayer {
	private:
		wyLabel* m_countLabel;
		int m_count;

	public:
		wyRenderSpriteTestLayer() {
			// add sprite button
			createButton("Add 50 Sprites", this, wyDevice::winWidth / 2, wyDevice::winHeight - DP(40),
					  wyTargetSelector::make(this, SEL(wyRenderSpriteTestLayer::onAddSprite)));

			// count label
			m_countLabel = wyLabel::make("0 Sprites", SP(16));
			m_countLabel->setPosition(wyDevice::winWidth / 2, wyDevice::winHeight - DP(80));
			m_countLabel->setColor(wyc3bRed);
			addChildLocked(m_countLabel);
			m_count = 0;
		}

		virtual ~wyRenderSpriteTestLayer() {
		}

		void onAddSprite(wyTargetSelector* ts) {
			wyTexture2D* tex = wyTexture2D::make(RES("R.drawable.blocks"));
			float size = DP(32.0f);
			for(int i = 0; i < 50; i++) {
				wySprite* s = wySprite::make(tex, wyr(wyMath::randMax(1) * size, wyMath::randMax(1) * size, size, size));
				s->setPosition(wyMath::randMax(wyDevice::winWidth), wyMath::randMax(wyDevice::winHeight));
				addChildLocked(s, -1);
			}

			// update count label
			m_count += 50;
			char buf[32];
			sprintf(buf, "%d Sprites", m_count);
			m_countLabel->setText(buf);
		}
	};

	/////////////////////////////////////////////////////////////////////////////////

	class wyRunActionTestLayer : public wyLayer {
	private:
		wyLabel* m_countLabel;
		int m_count;

	public:
		wyRunActionTestLayer() {
			// add sprite button
			createButton("Add 50 Sprites", this, wyDevice::winWidth / 2, wyDevice::winHeight - DP(40),
					  wyTargetSelector::make(this, SEL(wyRunActionTestLayer::onAddSprite)));

			// count label
			m_countLabel = wyLabel::make("0 Sprites", SP(16));
			m_countLabel->setPosition(wyDevice::winWidth / 2, wyDevice::winHeight - DP(80));
			m_countLabel->setColor(wyc3bRed);
			addChildLocked(m_countLabel);
			m_count = 0;
		}

		virtual ~wyRunActionTestLayer() {
		}

		void onAddSprite(wyTargetSelector* ts) {
			wyTexture2D* tex = wyTexture2D::make(RES("R.drawable.blocks"));
			float size = DP(32.0f);
			for(int i = 0; i < 50; i++) {
				wySprite* s = wySprite::make(tex, wyr(wyMath::randMax(1) * size, wyMath::randMax(1) * size, size, size));
				s->setPosition(wyMath::randMax(wyDevice::winWidth), wyMath::randMax(wyDevice::winHeight));
				s->runAction(wyRepeatForever::make(wyRotateBy::make(wyMath::randMax(10), 360)));
				addChildLocked(s, -1);
			}

			// update count label
			m_count += 50;
			char buf[32];
			sprintf(buf, "%d Sprites", m_count);
			m_countLabel->setText(buf);
		}
	};

	/////////////////////////////////////////////////////////////////////////////////

	class wyBigTMXTestLayer : public wyLayer {
	private:
		wyTMXTileMap* m_map;
		float m_lastX;
		float m_lastY;

	public:
		wyBigTMXTestLayer() {
			wyTexture2D* tex = wyTexture2D::make(RES("R.drawable.tileset0"));
			m_map = wyTMXTileMap::make(RES("R.raw.b0"), tex, NULL);
			addChildLocked(m_map);

			setTouchEnabled(true);
		}

		virtual ~wyBigTMXTestLayer() {
		}

		wyPoint getLocation(wyMotionEvent event) {
			wyPoint loc = wyp(event.x[0], event.y[0]);
			return loc;
		}

		virtual bool touchesBegan(wyMotionEvent& event) {
			wyPoint location = getLocation(event);
			m_lastX = location.x;
			m_lastY = location.y;
			return true;
		}

		virtual bool touchesMoved(wyMotionEvent& event) {
			wyPoint location = getLocation(event);
			float x = location.x;
			float y = location.y;
			float deltaX = x - m_lastX;
			float deltaY = y - m_lastY;
			m_lastX = x;
			m_lastY = y;

			m_map->translate(deltaX, deltaY);
			return true;
		}
	};

	/////////////////////////////////////////////////////////////////////////////////
}

using namespace Performance;

#if ANDROID
	#define DEMO_ENTRY_IMPL(testname) JNIEXPORT void JNICALL Java_com_wiyun_engine_tests_performance_##testname##_nativeStart \
		(JNIEnv *, jobject){ \
			wyLayer* layer = new wy##testname##Layer(); \
			runDemo(layer, NULL); \
			wyObjectRelease(layer); \
		}
#elif IOS || MACOSX || WINDOWS
	#define DEMO_ENTRY_IMPL(CLASSNAME) void _performance_##CLASSNAME##Launcher() { \
			wyLayer* layer = new wy##CLASSNAME##Layer(); \
			runDemo(layer, NULL); \
			wyObjectRelease(layer); \
		}
#endif

DEMO_ENTRY_IMPL(BatchRenderSpriteTest);
DEMO_ENTRY_IMPL(BigTMXTest);
DEMO_ENTRY_IMPL(RenderSpriteTest);
DEMO_ENTRY_IMPL(RunActionTest);
