#include "common.h"
#include "TransitionDemos.h"
#include "WiEngine.h"
#include <stdio.h>

namespace Transition {

    class wyTransitionTestLayer : public wyColorLayer {
    public:
        wyTransitionTestLayer():wyColorLayer(wyc4b(0, 0, 255, 255)) {
			wyLabel* label1 = wyLabel::make("Push Scene");
			wyLabel* label2 = wyLabel::make("Replace Scene");
			wyLabel* label3 = wyLabel::make("Quit");

            wyMenuItemLabel* item1 = wyMenuItemLabel::make(NULL,
            		wyTargetSelector::make(this, SEL(wyTransitionTestLayer::onPushScene)),
            		label1);
            wyMenuItemLabel* item2 = wyMenuItemLabel::make(NULL,
            		wyTargetSelector::make(this, SEL(wyTransitionTestLayer::onReplaceScene)),
            		label2);
            wyMenuItemLabel* item3 = wyMenuItemLabel::make(NULL,
            		wyTargetSelector::make(this, SEL(wyTransitionTestLayer::onExitScene)),
            		label3);
            wyMenu* menu = wyMenu::make(item1, item2, item3, NULL);

            menu->alignItemsVertically();
            addChildLocked(menu);
        }
        
        wyTransitionTestLayer(bool replace) : wyColorLayer(wyc4b(replace ? 255 : 0, replace ? 0 : 255, 0, 255)) {
			wyLabel* label1 = wyLabel::make("Go Back");
            wyMenuItemLabel* item1 = wyMenuItemLabel::make(NULL,
            		wyTargetSelector::make(this, (replace ? SEL(wyTransitionTestLayer::onPopScene) : SEL(wyTransitionTestLayer::onPopSceneWithTransition))),
            		label1);

            wyMenu* menu = wyMenu::make(item1, NULL);
            menu->alignItemsVertically();
            addChildLocked(menu);
        }

        virtual ~wyTransitionTestLayer() {
        }

		virtual wyTransitionScene* getTransition(wyScene* scene) = 0;

		virtual wyLayer* getNextLayer(bool replace) = 0;

		virtual wyLayer* getPrevLayer() = 0;

		virtual wyTransitionScene* getBackTransition(wyScene* scene) {
			return NULL;
		}
		
		void onPushScene(wyTargetSelector* ts) {
			wyScene* scene = new wyScene();
			scene->addChildLocked(getNextLayer(false));
			wyDirector::getInstance()->pushScene(getTransition(scene));
			wyObjectRelease(scene);
		}

		void onReplaceScene(wyTargetSelector* ts) {
			wyScene* scene = new wyScene();
			scene->addChildLocked(getNextLayer(true));
			wyDirector::getInstance()->replaceScene(getTransition(scene));
			wyObjectRelease(scene);
		}

		void onExitScene(wyTargetSelector* ts) {
			wyDirector::getInstance()->popScene();
		}
		
		void onPopScene(wyTargetSelector* ts) {
			wyScene* scene = new wyScene();
			scene->addChildLocked(getPrevLayer());
			wyScene* tScene = getBackTransition(scene);
			if (tScene == NULL) {
				tScene = getTransition(scene);
			}
			wyDirector::getInstance()->replaceScene(tScene);
			wyObjectRelease(scene);
		}

		void onPopSceneWithTransition(wyTargetSelector* ts) {
            wyTransitionScene* s = getBackTransition(NULL);
			if (s == NULL) {
				s = getTransition(NULL);
			}
			wyDirector::getInstance()->popSceneWithTransition(s);
		}
    };

    //////////////////////////////////////////////////////////////////////////////////////

	static int s_nextDirection = 0;
	class wyClipInOutTestLayer : public wyTransitionTestLayer {
	public:
		wyClipInOutTestLayer() {}
		wyClipInOutTestLayer(bool replace) : wyTransitionTestLayer(replace) {}

		virtual wyTransitionScene* getTransition(wyScene* scene) {
			s_nextDirection++;
			s_nextDirection %= 4;
			return wyClipInTransition::make(1, scene, (wyClipIn::Direction)s_nextDirection);
		}

		virtual wyTransitionScene* getBackTransition(wyScene* scene) {
			s_nextDirection++;
			s_nextDirection %= 4;
			return wyClipOutTransition::make(1, scene, (wyClipOut::Direction)s_nextDirection);
		}

		virtual wyLayer* getNextLayer(bool replace) {
			return (wyLayer*) (new wyClipInOutTestLayer(replace))->autoRelease();
		}

		virtual wyLayer* getPrevLayer() {
			return (wyLayer*) (new wyClipInOutTestLayer())->autoRelease();
		}
	};

    //////////////////////////////////////////////////////////////////////////////////////

	class wyColorFadeTestLayer : public wyTransitionTestLayer {
	public:
		wyColorFadeTestLayer() {}
		wyColorFadeTestLayer(bool replace):wyTransitionTestLayer(replace) {}
		
		virtual wyTransitionScene* getTransition(wyScene* scene) {
			return (wyTransitionScene*) (new wyColorFadeTransition(2, scene, wyc3b(255, 255, 0)))->autoRelease();
		}

		virtual wyTransitionScene* getBackTransition(wyScene* scene) {
			return (wyTransitionScene*) (new wyColorFadeTransition(2, scene, wyc3b(0, 255, 255)))->autoRelease();
		}

		virtual wyLayer* getNextLayer(bool replace) {
			return (wyLayer*) (new wyColorFadeTestLayer(replace))->autoRelease();
		}
		
		virtual wyLayer* getPrevLayer() {
			return (wyLayer*) (new wyColorFadeTestLayer())->autoRelease();
		}
	};
	
	//////////////////////////////////////////////////////////////////////////////////////

	class wyCrossFadeTestLayer : public wyTransitionTestLayer {
	public:
		wyCrossFadeTestLayer() {}
		wyCrossFadeTestLayer(bool replace):wyTransitionTestLayer(replace) {}
		
		virtual wyTransitionScene* getTransition(wyScene* scene) {
			return (wyTransitionScene*) (new wyCrossFadeTransition(2, scene))->autoRelease();
		}

		virtual wyLayer* getNextLayer(bool replace) {
			return (wyLayer*) (new wyCrossFadeTestLayer(replace))->autoRelease();
		}
		
		virtual wyLayer* getPrevLayer() {
			return (wyLayer*) (new wyCrossFadeTestLayer())->autoRelease();
		}
	};

	//////////////////////////////////////////////////////////////////////////////////////

	class wyFlipAngularTestLayer : public wyTransitionTestLayer {
	public:
		wyFlipAngularTestLayer() {}
		wyFlipAngularTestLayer(bool replace):wyTransitionTestLayer(replace) {}
		
		virtual wyTransitionScene* getTransition(wyScene* scene) {
			return (wyTransitionScene*) (new wyFlipAngularTransition(1.0f, scene, true))->autoRelease();
		}

		virtual wyTransitionScene* getBackTransition(wyScene* scene) {
			return (wyTransitionScene*) (new wyFlipAngularTransition(1.0f, scene, false))->autoRelease();
		}

		virtual wyLayer* getNextLayer(bool replace) {
			return (wyLayer*) (new wyFlipAngularTestLayer(replace))->autoRelease();
		}
		
		virtual wyLayer* getPrevLayer() {
			return (wyLayer*) (new wyFlipAngularTestLayer())->autoRelease();
		}
	};

	//////////////////////////////////////////////////////////////////////////////////////

	class wyFlipXTestLayer : public wyTransitionTestLayer {
	public:
		wyFlipXTestLayer() {}
		wyFlipXTestLayer(bool replace):wyTransitionTestLayer(replace) {}
		
		virtual wyTransitionScene* getTransition(wyScene* scene) {
			return (wyTransitionScene*) (new wyFlipXTransition(1.0f, scene, true))->autoRelease();
		}

		virtual wyTransitionScene* getBackTransition(wyScene* scene) {
			return (wyTransitionScene*) (new wyFlipXTransition(1.0f, scene, false))->autoRelease();
		}

		virtual wyLayer* getNextLayer(bool replace) {
			return (wyLayer*) (new wyFlipXTestLayer(replace))->autoRelease();
		}
		
		virtual wyLayer* getPrevLayer() {
			return (wyLayer*) (new wyFlipXTestLayer())->autoRelease();
		}
	};

	//////////////////////////////////////////////////////////////////////////////////////

	class wyFlipYTestLayer : public wyTransitionTestLayer {
	public:
		wyFlipYTestLayer() {}
		wyFlipYTestLayer(bool replace):wyTransitionTestLayer(replace) {}
		
		virtual wyTransitionScene* getTransition(wyScene* scene) {
			return (wyTransitionScene*) (new wyFlipYTransition(1.0f, scene, true))->autoRelease();
		}

		virtual wyTransitionScene* getBackTransition(wyScene* scene) {
			return (wyTransitionScene*) (new wyFlipYTransition(1.0f, scene, false))->autoRelease();
		}

		virtual wyLayer* getNextLayer(bool replace) {
			return (wyLayer*) (new wyFlipYTestLayer(replace))->autoRelease();
		}
		
		virtual wyLayer* getPrevLayer() {
			return (wyLayer*) (new wyFlipYTestLayer())->autoRelease();
		}
	};

	//////////////////////////////////////////////////////////////////////////////////////

	class wyJumpZoomTestLayer : public wyTransitionTestLayer {
	public:
		wyJumpZoomTestLayer() {}
		wyJumpZoomTestLayer(bool replace):wyTransitionTestLayer(replace) {}
		
		virtual wyTransitionScene* getTransition(wyScene* scene) {
			return (wyTransitionScene*) (new wyJumpZoomTransition(1, scene))->autoRelease();
		}

		virtual wyLayer* getNextLayer(bool replace) {
			return (wyLayer*) (new wyJumpZoomTestLayer(replace))->autoRelease();
		}
		
		virtual wyLayer* getPrevLayer() {
			return (wyLayer*) (new wyJumpZoomTestLayer())->autoRelease();
		}
	};

	//////////////////////////////////////////////////////////////////////////////////////

	class wyLeftRightPushTestLayer : public wyTransitionTestLayer {
	public:
		wyLeftRightPushTestLayer() {}
		wyLeftRightPushTestLayer(bool replace):wyTransitionTestLayer(replace) {}
		
		virtual wyTransitionScene* getTransition(wyScene* scene) {
			return (wyTransitionScene*) (new wyRightPushInTransition(1, scene))->autoRelease();
		}

		virtual wyTransitionScene* getBackTransition(wyScene* scene) {
			return (wyTransitionScene*) (new wyLeftPushInTransition(1, scene))->autoRelease();
		}

		virtual wyLayer* getNextLayer(bool replace) {
			return (wyLayer*) (new wyLeftRightPushTestLayer(replace))->autoRelease();
		}
		
		virtual wyLayer* getPrevLayer() {
			return (wyLayer*) (new wyLeftRightPushTestLayer())->autoRelease();
		}
	};

	//////////////////////////////////////////////////////////////////////////////////////

	class wyLeftRightSlideTestLayer : public wyTransitionTestLayer {
	public:
		wyLeftRightSlideTestLayer() {}
		wyLeftRightSlideTestLayer(bool replace):wyTransitionTestLayer(replace) {}
		
		virtual wyTransitionScene* getTransition(wyScene* scene) {
			return (wyTransitionScene*) (new wyRightSlideInTransition(1, scene))->autoRelease();
		}

		virtual wyTransitionScene* getBackTransition(wyScene* scene) {
			return (wyTransitionScene*) (new wyLeftSlideInTransition(1, scene))->autoRelease();
		}

		virtual wyLayer* getNextLayer(bool replace) {
			return (wyLayer*) (new wyLeftRightSlideTestLayer(replace))->autoRelease();
		}
		
		virtual wyLayer* getPrevLayer() {
			return (wyLayer*) (new wyLeftRightSlideTestLayer())->autoRelease();
		}
	};

	//////////////////////////////////////////////////////////////////////////////////////

	class wyPageTurn3DTestLayer : public wyTransitionTestLayer {
	public:
		wyPageTurn3DTestLayer() {}
		wyPageTurn3DTestLayer(bool replace):wyTransitionTestLayer(replace) {}
		
		virtual wyTransitionScene* getTransition(wyScene* scene) {
			return (wyTransitionScene*) (new wyPageTurn3DTransition(1.0f, scene))->autoRelease();
		}

		virtual wyLayer* getNextLayer(bool replace) {
			return (wyLayer*) (new wyPageTurn3DTestLayer(replace))->autoRelease();
		}
		
		virtual wyLayer* getPrevLayer() {
			return (wyLayer*) (new wyPageTurn3DTestLayer())->autoRelease();
		}
	};

	//////////////////////////////////////////////////////////////////////////////////////

	class wyRotateZoomTestLayer : public wyTransitionTestLayer {
	public:
		wyRotateZoomTestLayer() {}
		wyRotateZoomTestLayer(bool replace):wyTransitionTestLayer(replace) {}
		
		virtual wyTransitionScene* getTransition(wyScene* scene) {
			return (wyTransitionScene*) (new wyRotateZoomTransition(1.0f, scene))->autoRelease();
		}

		virtual wyLayer* getNextLayer(bool replace) {
			return (wyLayer*) (new wyRotateZoomTestLayer(replace))->autoRelease();
		}
		
		virtual wyLayer* getPrevLayer() {
			return (wyLayer*) (new wyRotateZoomTestLayer())->autoRelease();
		}
	};

	//////////////////////////////////////////////////////////////////////////////////////

	class wyShrinkGrowTestLayer : public wyTransitionTestLayer {
	public:
		wyShrinkGrowTestLayer() {}
		wyShrinkGrowTestLayer(bool replace):wyTransitionTestLayer(replace) {}
		
		virtual wyTransitionScene* getTransition(wyScene* scene) {
			return (wyTransitionScene*) (new wyShrinkGrowTransition(1.0f, scene))->autoRelease();
		}

		virtual wyLayer* getNextLayer(bool replace) {
			return (wyLayer*) (new wyShrinkGrowTestLayer(replace))->autoRelease();
		}
		
		virtual wyLayer* getPrevLayer() {
			return (wyLayer*) (new wyShrinkGrowTestLayer())->autoRelease();
		}
	};

	//////////////////////////////////////////////////////////////////////////////////////

	class wyShrinkOutTilesTestLayer : public wyTransitionTestLayer {
	private:
		bool m_FromTop;
	public:
		wyShrinkOutTilesTestLayer():wyTransitionTestLayer(), m_FromTop(false) {}
		wyShrinkOutTilesTestLayer(bool fromTop):wyTransitionTestLayer(), m_FromTop(fromTop) {}
		wyShrinkOutTilesTestLayer(bool fromTop, bool replace):wyTransitionTestLayer(replace), m_FromTop(fromTop) {}
		
		virtual wyTransitionScene* getTransition(wyScene* scene) {
        	if (m_FromTop) {
				return (wyTransitionScene*) (new wyTopTilesShrinkOutTransition(2.0f, scene, 0, 0))->autoRelease();
			}else{
				return (wyTransitionScene*) (new wyRightTopTilesShrinkOutTransition(2.0f, scene, 0, 0))->autoRelease();
			}
		}

		virtual wyTransitionScene* getBackTransition(wyScene* scene) {
        	if (m_FromTop) {
				return (wyTransitionScene*) (new wyBottomTilesShrinkOutTransition(2.0f, scene, 0, 0))->autoRelease();
			}else{
				return (wyTransitionScene*) (new wyLeftBottomTilesShrinkOutTransition(2.0f, scene, 0, 0))->autoRelease();
			}
		}

		virtual wyLayer* getNextLayer(bool replace) {
			return (wyLayer*) (new wyShrinkOutTilesTestLayer(m_FromTop, replace))->autoRelease();
		}
		
		virtual wyLayer* getPrevLayer() {
			return (wyLayer*) (new wyShrinkOutTilesTestLayer(!m_FromTop))->autoRelease();
		}
	};

	//////////////////////////////////////////////////////////////////////////////////////

	class wySplitRowsColsTestLayer : public wyTransitionTestLayer {
	public:
		wySplitRowsColsTestLayer() {}
		wySplitRowsColsTestLayer(bool replace):wyTransitionTestLayer(replace) {}
		
		virtual wyTransitionScene* getTransition(wyScene* scene) {
			return (wyTransitionScene*) (new wySplitRowsTransition(1.0f, scene, 3))->autoRelease();
		}

		virtual wyTransitionScene* getBackTransition(wyScene* scene) {
			return (wyTransitionScene*) (new wySplitColsTransition(1.0f, scene, 3))->autoRelease();
		}

		virtual wyLayer* getNextLayer(bool replace) {
			return (wyLayer*) (new wySplitRowsColsTestLayer(replace))->autoRelease();
		}
		
		virtual wyLayer* getPrevLayer() {
			return (wyLayer*) (new wySplitRowsColsTestLayer())->autoRelease();
		}
	};

	//////////////////////////////////////////////////////////////////////////////////////

	class wySuckTestLayer : public wyTransitionTestLayer {
	public:
		wySuckTestLayer() {}
		wySuckTestLayer(bool replace) : wyTransitionTestLayer(replace) {}

		virtual wyTransitionScene* getTransition(wyScene* scene) {
			return wySuckTransition::make(0.6f, scene, wyDevice::winWidth * 2 / 3, 0);
		}

		virtual wyTransitionScene* getBackTransition(wyScene* scene) {
			return wySuckTransition::make(0.6f, scene, wyDevice::winWidth * 2 / 3, 0);
		}

		virtual wyLayer* getNextLayer(bool replace) {
			return (wyLayer*) (new wySuckTestLayer(replace))->autoRelease();
		}

		virtual wyLayer* getPrevLayer() {
			return (wyLayer*) (new wySuckTestLayer())->autoRelease();
		}
	};

	//////////////////////////////////////////////////////////////////////////////////////

	class wyTopBottomPushTestLayer : public wyTransitionTestLayer {
	public:
		wyTopBottomPushTestLayer() {}
		wyTopBottomPushTestLayer(bool replace):wyTransitionTestLayer(replace) {}
		
		virtual wyTransitionScene* getTransition(wyScene* scene) {
			return (wyTransitionScene*) (new wyTopPushInTransition(1, scene))->autoRelease();
		}

		virtual wyTransitionScene* getBackTransition(wyScene* scene) {
			return (wyTransitionScene*) (new wyBottomPushInTransition(1, scene))->autoRelease();
		}

		virtual wyLayer* getNextLayer(bool replace) {
			return (wyLayer*) (new wyTopBottomPushTestLayer(replace))->autoRelease();
		}
		
		virtual wyLayer* getPrevLayer() {
			return (wyLayer*) (new wyTopBottomPushTestLayer())->autoRelease();
		}
	};

	//////////////////////////////////////////////////////////////////////////////////////

	class wyTopBottomSlideTestLayer : public wyTransitionTestLayer {
	public:
		wyTopBottomSlideTestLayer() {}
		wyTopBottomSlideTestLayer(bool replace):wyTransitionTestLayer(replace) {}
		
		virtual wyTransitionScene* getTransition(wyScene* scene) {
			return (wyTransitionScene*) (new wyTopSlideInTransition(1, scene))->autoRelease();
		}

		virtual wyTransitionScene* getBackTransition(wyScene* scene) {
			return (wyTransitionScene*) (new wyBottomSlideInTransition(1, scene))->autoRelease();
		}

		virtual wyLayer* getNextLayer(bool replace) {
			return (wyLayer*) (new wyTopBottomSlideTestLayer(replace))->autoRelease();
		}

		virtual wyLayer* getPrevLayer() {
			return (wyLayer*) (new wyTopBottomSlideTestLayer())->autoRelease();
		}
	};

	//////////////////////////////////////////////////////////////////////////////////////

	class wyTopBottomSlideBounceTestLayer : public wyTransitionTestLayer {
	public:
		wyTopBottomSlideBounceTestLayer() {}
		wyTopBottomSlideBounceTestLayer(bool replace) : wyTransitionTestLayer(replace) {}

		virtual wyTransitionScene* getTransition(wyScene* scene) {
			wyTransitionScene* trans = new wyTopSlideInTransition(1, scene);
			trans->setInEaseAction(wyEaseBounceIn::make());
			return (wyTransitionScene*)trans->autoRelease();
		}

		virtual wyTransitionScene* getBackTransition(wyScene* scene) {
			wyTransitionScene* trans = new wyBottomSlideInTransition(1, scene);
			trans->setInEaseAction(wyEaseBounceIn::make());
			return (wyTransitionScene*)trans->autoRelease();
		}

		virtual wyLayer* getNextLayer(bool replace) {
			return (wyLayer*) (new wyTopBottomSlideBounceTestLayer(replace))->autoRelease();
		}
		
		virtual wyLayer* getPrevLayer() {
			return (wyLayer*) (new wyTopBottomSlideBounceTestLayer())->autoRelease();
		}
	};
	
	//////////////////////////////////////////////////////////////////////////////////////

	class wyTurnOffTilesTestLayer : public wyTransitionTestLayer {
	public:
		wyTurnOffTilesTestLayer() {}
		wyTurnOffTilesTestLayer(bool replace):wyTransitionTestLayer(replace) {}
		
		virtual wyTransitionScene* getTransition(wyScene* scene) {
			return (wyTransitionScene*) (new wyTurnOffTilesTransition(1.0f, scene, 0, 0))->autoRelease();
		}

		virtual wyTransitionScene* getBackTransition(wyScene* scene) {
			return (wyTransitionScene*) (new wyTurnOffTilesTransition(1.0f, scene, 20, 12))->autoRelease();
		}

		virtual wyLayer* getNextLayer(bool replace) {
			return (wyLayer*) (new wyTurnOffTilesTestLayer(replace))->autoRelease();
		}
		
		virtual wyLayer* getPrevLayer() {
			return (wyLayer*) (new wyTurnOffTilesTestLayer())->autoRelease();
		}
	};
	
	//////////////////////////////////////////////////////////////////////////////////////

	class wyZoomFlipAngularTestLayer : public wyTransitionTestLayer {
	public:
		wyZoomFlipAngularTestLayer() {}
		wyZoomFlipAngularTestLayer(bool replace):wyTransitionTestLayer(replace) {}
		
		virtual wyTransitionScene* getTransition(wyScene* scene) {
			return (wyTransitionScene*) (new wyZoomFlipAngularTransition(1.0f, scene, true, 0.5f))->autoRelease();
		}

		virtual wyTransitionScene* getBackTransition(wyScene* scene) {
			return (wyTransitionScene*) (new wyZoomFlipAngularTransition(1.0f, scene, false, 0.5f))->autoRelease();
		}

		virtual wyLayer* getNextLayer(bool replace) {
			return (wyLayer*) (new wyZoomFlipAngularTestLayer(replace))->autoRelease();
		}
		
		virtual wyLayer* getPrevLayer() {
			return (wyLayer*) (new wyZoomFlipAngularTestLayer())->autoRelease();
		}
	};
	
	//////////////////////////////////////////////////////////////////////////////////////

	class wyZoomFlipXTestLayer : public wyTransitionTestLayer {
	public:
		wyZoomFlipXTestLayer() {}
		wyZoomFlipXTestLayer(bool replace):wyTransitionTestLayer(replace) {}
		
		virtual wyTransitionScene* getTransition(wyScene* scene) {
			return (wyTransitionScene*) (new wyZoomFlipXTransition(1.0f, scene, true, 0.5f))->autoRelease();
		}

		virtual wyTransitionScene* getBackTransition(wyScene* scene) {
			return (wyTransitionScene*) (new wyZoomFlipXTransition(1.0f, scene, false, 0.5f))->autoRelease();
		}

		virtual wyLayer* getNextLayer(bool replace) {
			return (wyLayer*) (new wyZoomFlipXTestLayer(replace))->autoRelease();
		}
		
		virtual wyLayer* getPrevLayer() {
			return (wyLayer*) (new wyZoomFlipXTestLayer())->autoRelease();
		}
	};
	
	//////////////////////////////////////////////////////////////////////////////////////

	class wyZoomFlipYTestLayer : public wyTransitionTestLayer {
	public:
		wyZoomFlipYTestLayer() {}
		wyZoomFlipYTestLayer(bool replace):wyTransitionTestLayer(replace) {}
		
		virtual wyTransitionScene* getTransition(wyScene* scene) {
			return (wyTransitionScene*) (new wyZoomFlipYTransition(1.0f, scene, true, 0.5f))->autoRelease();
		}

		virtual wyTransitionScene* getBackTransition(wyScene* scene) {
			return (wyTransitionScene*) (new wyZoomFlipYTransition(1.0f, scene, false, 0.5f))->autoRelease();
		}

		virtual wyLayer* getNextLayer(bool replace) {
			return (wyLayer*) (new wyZoomFlipYTestLayer(replace))->autoRelease();
		}
		
		virtual wyLayer* getPrevLayer() {
			return (wyLayer*) (new wyZoomFlipYTestLayer())->autoRelease();
		}
	};

	//////////////////////////////////////////////////////////////////////////////////////

	class wyRadialCWCCWTestLayer : public wyTransitionTestLayer {
	public:
		wyRadialCWCCWTestLayer() {}
		wyRadialCWCCWTestLayer(bool replace) : wyTransitionTestLayer(replace) {}

		virtual wyTransitionScene* getTransition(wyScene* scene) {
			return (wyTransitionScene*) (new wyRadialCCWTransition(1.0f, scene))->autoRelease();
		}

		virtual wyTransitionScene* getBackTransition(wyScene* scene) {
			return (wyTransitionScene*) (new wyRadialCWTransition(1.0f, scene))->autoRelease();
		}

		virtual wyLayer* getNextLayer(bool replace) {
			return (wyLayer*) (new wyRadialCWCCWTestLayer(replace))->autoRelease();
		}

		virtual wyLayer* getPrevLayer() {
			return (wyLayer*) (new wyRadialCWCCWTestLayer())->autoRelease();
		}
	};

	//////////////////////////////////////////////////////////////////////////////////////

}

using namespace Transition;

#if ANDROID
	#define DEMO_ENTRY_IMPL(CLASSNAME) JNIEXPORT void JNICALL Java_com_wiyun_engine_tests_transition_##CLASSNAME##_nativeStart \
		(JNIEnv *, jobject) { \
			wyLayer* layer = new wy##CLASSNAME##Layer(); \
			runDemo(layer, NULL); \
			wyObjectRelease(layer); \
		}
#elif IOS || MACOSX || WINDOWS
	#define DEMO_ENTRY_IMPL(CLASSNAME) void _transition_##CLASSNAME##Launcher() { \
			wyLayer* layer = new wy##CLASSNAME##Layer(); \
			runDemo(layer, NULL); \
			wyObjectRelease(layer); \
		}
#endif

DEMO_ENTRY_IMPL(ClipInOutTest);
DEMO_ENTRY_IMPL(ColorFadeTest);
DEMO_ENTRY_IMPL(CrossFadeTest);
DEMO_ENTRY_IMPL(FlipAngularTest);
DEMO_ENTRY_IMPL(FlipXTest);
DEMO_ENTRY_IMPL(FlipYTest);
DEMO_ENTRY_IMPL(JumpZoomTest);
DEMO_ENTRY_IMPL(LeftRightPushTest);
DEMO_ENTRY_IMPL(LeftRightSlideTest);
DEMO_ENTRY_IMPL(PageTurn3DTest);
DEMO_ENTRY_IMPL(RadialCWCCWTest);
DEMO_ENTRY_IMPL(RotateZoomTest);
DEMO_ENTRY_IMPL(ShrinkGrowTest);
DEMO_ENTRY_IMPL(ShrinkOutTilesTest);
DEMO_ENTRY_IMPL(SplitRowsColsTest);
DEMO_ENTRY_IMPL(SuckTest);
DEMO_ENTRY_IMPL(TopBottomPushTest);
DEMO_ENTRY_IMPL(TopBottomSlideTest);
DEMO_ENTRY_IMPL(TopBottomSlideBounceTest);
DEMO_ENTRY_IMPL(TurnOffTilesTest);
DEMO_ENTRY_IMPL(ZoomFlipAngularTest);
DEMO_ENTRY_IMPL(ZoomFlipXTest);
DEMO_ENTRY_IMPL(ZoomFlipYTest);
