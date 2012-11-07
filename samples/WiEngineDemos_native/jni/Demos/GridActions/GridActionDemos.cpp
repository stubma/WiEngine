#include "GridActionDemos.h"
#include "common.h"
#include "WiEngine.h"
#include <stdio.h>

namespace Grid_Action {
    class wyActionTestLayer : public wyLayer {
    protected:
        wySprite* m_Sprite;

    public:
        wyActionTestLayer() {
            m_Sprite = wySprite::make(wyTexture2D::makePNG(RES("R.drawable.grossini")));
            m_Sprite->retain();
            addChildLocked(m_Sprite, 2);
            m_Sprite->setPosition(wyDevice::winWidth / 2, wyDevice::winHeight/ 2);
			m_Sprite->setScale(4);

        	wySprite* bg = wySprite::make(wyTexture2D::makePNG(RES("R.drawable.background")));
        	bg->setPosition(wyDevice::winWidth / 2, wyDevice::winHeight / 2);
        	addChildLocked(bg, -1);
        }

        virtual ~wyActionTestLayer(){
            wyObjectRelease(m_Sprite);
            m_Sprite = NULL;
        }
    };

    class wyGridFlipXTestLayer : public wyActionTestLayer {
    public:
        wyGridFlipXTestLayer() {
            wyIntervalAction* action = wySequence::make(
            		wyGridFlipX::make(4.0f),
            		wyStopGrid::make(),
            		NULL);
            m_Sprite->runAction(action);
        }
    };

    class wyGridFlipYTestLayer : public wyActionTestLayer {
    public:
        wyGridFlipYTestLayer() {
            wyIntervalAction* action = wySequence::make(
            		wyGridFlipY::make(4.0f),
            		wyStopGrid::make(),
            		NULL);
            m_Sprite->runAction(action);
        }
    };

    class wyJumpTiles3DTestLayer : public wyActionTestLayer {
    public:
        wyJumpTiles3DTestLayer() {
            wyIntervalAction* t = wySequence::make(
            		wyJumpTiles3D::make(4, 12, 20, 20.0f, 3),
            		wyReuseGrid::make(1),
            		NULL);
  			wyAction* action = wyRepeatForever::make(t);
  			m_Sprite->runAction(action);
        }
    };

    class wyLens3DTestLayer : public wyActionTestLayer {
    public:
        wyLens3DTestLayer() {
			wyIntervalAction* a = wyLens3D::make(6, 12, 20, 100, 100, getWidth() - 100, getHeight() - 100, 200, 200, 0.7f);
            wyIntervalAction* t = wySequence::make(a,
            		wyReuseGrid::make(1),
            		(wyFiniteTimeAction*)a->reverse(),
            		wyReuseGrid::make(1),
            		NULL);
  			wyAction* action = wyRepeatForever::make(t);
  			runAction(action);
        }
    };

    class wyLineShrinkOutTestLayer : public wyActionTestLayer {
    public:
        wyLineShrinkOutTestLayer() {
            wyIntervalAction* t = wySequence::make(
            		wyBottomLineShrinkOut::make(4, 12, 20),
            		wyReuseGrid::make(3),
            		wyTopLineShrinkOut::make(4, 12, 20),
            		wyLeftLineShrinkOut::make(4, 12, 20),
            		wyRightLineShrinkOut::make(4, 12, 20),
            		wyStopGrid::make(),
            		NULL);
            m_Sprite->runAction(t);
        }
    };

    class wyLiquidTestLayer : public wyActionTestLayer {
    public:
        wyLiquidTestLayer() {
            wyIntervalAction* t = wySequence::make(
            		wyLiquid::make(12, 12, 20, 5, -5, 10),
            		wyStopGrid::make(),
            		NULL);
            runAction(t);
        }
    };

    class wyPageTurn3DTestLayer : public wyActionTestLayer {
    public:
        wyPageTurn3DTestLayer() {
			// TODO gles2
        	//wyDirector::getInstance()->setCullFace(true);
			wyIntervalAction* a = wyPageTurn3D::make(2.0f, 12, 20);
            wyIntervalAction* t = wySequence::make(
            		a,
            		wyReuseGrid::make(2),
            		(wyFiniteTimeAction*)a->reverse(),
            		NULL);
  			wyAction* action = wyRepeatForever::make(t);
  			m_Sprite->runAction(action);
        }
    };

    class wyRipple3DTestLayer : public wyActionTestLayer {
    public:
        wyRipple3DTestLayer() {
            wyIntervalAction* t = wySequence::make(
            		wyRipple3D::make(4, 12, 20, m_Sprite->getWidth() / 2, m_Sprite->getHeight() / 2, 0, 0, 400, 0, 200, -200, 2),
            		wyStopGrid::make(),
            		NULL);
            m_Sprite->runAction(t);
        }
    };

    class wyShaky3DTestLayer : public wyActionTestLayer {
    public:
        wyShaky3DTestLayer() {
            wyIntervalAction* t = wySequence::make(
            		wyShaky3D::make(1200, 12, 20, 5, 0, false),
            		wyReuseGrid::make(1),
            		NULL);
  			wyAction* action = wyRepeatForever::make(t);
  			m_Sprite->runAction(action);
        }
    };

    class wyShakyTiles3DTestLayer : public wyActionTestLayer {
    public:
        wyShakyTiles3DTestLayer() {
            wyIntervalAction* t = wySequence::make(
            		wyShakyTiles3D::make(4, 12, 20, 5, 0, false),
            		wyReuseGrid::make(1),
            		NULL);
  			wyAction* action = wyRepeatForever::make(t);
  			m_Sprite->runAction(action);
        }
    };

    class wyShatterTiles3DTestLayer : public wyActionTestLayer {
    public:
        wyShatterTiles3DTestLayer() {
            wyIntervalAction* t = wySequence::make(
            		wyShatteredTiles3D::make(4, 12, 20, 20, false),
            		wyReuseGrid::make(1),
            		NULL);
            m_Sprite->runAction(t);
        }
    };

    class wyShuffleTilesTestLayer : public wyActionTestLayer {
    public:
        wyShuffleTilesTestLayer() {
			wyIntervalAction* t = wyShuffleTiles::make(4, 12, 20);
			m_Sprite->runAction(t);
        }
    };

    class wySplitRowsColsTestLayer : public wyActionTestLayer {
    public:
        wySplitRowsColsTestLayer() {
			wyIntervalAction* ar = wySplitRows::make(2, 4, 8);
			wyIntervalAction* ac = wySplitCols::make(2, 4, 8);
            wyIntervalAction* t = wySequence::make(
            		ar,
            		wyReuseGrid::make(4),
            		(wyFiniteTimeAction*)ar->reverse(),
            		ac,
            		(wyFiniteTimeAction*)ac->reverse(),
            		NULL);
  			wyAction* action = wyRepeatForever::make(t);
  			m_Sprite->runAction(action);
        }
    };

    class wyTilesShrinkOutTestLayer : public wyActionTestLayer {
    public:
        wyTilesShrinkOutTestLayer() {
            wyIntervalAction* t = wySequence::make(
            		wyLeftBottomTilesShrinkOut::make(4, 12, 20),
            		wyReuseGrid::make(3),
            		wyRightTopTilesShrinkOut::make(4, 12, 20),
            		wyBottomTilesShrinkOut::make(4, 12, 20),
            		wyTopTilesShrinkOut::make(4, 12, 20),
            		wyStopGrid::make(),
            		NULL);
            m_Sprite->runAction(t);
        }
    };

    class wyTurnOffTilesTestLayer : public wyActionTestLayer {
    public:
        wyTurnOffTilesTestLayer() {
            wyIntervalAction* t = wySequence::make(
            		wyTurnOffTiles::make(4, 12, 20),
            		wyStopGrid::make(),
            		NULL);
            m_Sprite->runAction(t);
        }
    };

    class wyTwirlTestLayer : public wyActionTestLayer {
    public:
        wyTwirlTestLayer() {
            wyIntervalAction* t = wySequence::make(
            		wyTwirl::make(12, 12, 20, m_Sprite->getWidth() / 2, m_Sprite->getHeight() / 2, 0, 0, 3, 0, 1),
            		wyStopGrid::make(),
            		NULL);
            m_Sprite->runAction(t);
        }
    };

    class wyWaves3DTestLayer : public wyActionTestLayer {
    public:
        wyWaves3DTestLayer() {
            wyIntervalAction* t = wySequence::make(
            		wyWaves3D::make(4, 12, 20, 20, 3),
            		wyStopGrid::make(),
            		NULL);
            m_Sprite->runAction(t);
        }
    };

    class wyWavesTestLayer : public wyActionTestLayer {
    public:
        wyWavesTestLayer() {
            wyIntervalAction* t = wySequence::make(
            		wyWaves::make(4, 12, 20, 20, 3, false, true),
            		wyStopGrid::make(),
            		NULL);
            m_Sprite->runAction(t);
        }
    };

    class wyWavesTiles3DTestLayer : public wyActionTestLayer {
    public:
        wyWavesTiles3DTestLayer() {
            wyIntervalAction* t = wySequence::make(
            		wyWavesTiles3D::make(4, 12, 20, 20, 3),
            		wyReuseGrid::make(1),
            		NULL);
  			wyAction* action = wyRepeatForever::make(t);
  			m_Sprite->runAction(action);
        }
    };

    class wySuckTestLayer : public wyActionTestLayer {
	public:
    	wySuckTestLayer() {
			setTouchEnabled(true);
		}

    	virtual bool touchesBegan(wyMotionEvent& event) {
    		// powered
    		if (m_Sprite->getGrid() == NULL || !m_Sprite->getGrid()->isActive()) {
				wyPoint loc = m_Sprite->worldToNodeSpace(wyp(event.x[0], event.y[0]));
				wyIntervalAction* t = wySequence::make(
						wySuck::make(0.6f, 20, 20, loc.x, loc.y),
						wyStopGrid::make(),
						NULL);
				m_Sprite->runAction(t);
    		}
			return true;
		}
	};

}

using namespace Grid_Action;

DEMO_ENTRY_IMPL(gridaction, SuckTest);
DEMO_ENTRY_IMPL(gridaction, GridFlipXTest);
DEMO_ENTRY_IMPL(gridaction, GridFlipYTest);
DEMO_ENTRY_IMPL(gridaction, JumpTiles3DTest);
DEMO_ENTRY_IMPL(gridaction, Lens3DTest);
DEMO_ENTRY_IMPL(gridaction, LineShrinkOutTest);
DEMO_ENTRY_IMPL(gridaction, LiquidTest);
DEMO_ENTRY_IMPL(gridaction, PageTurn3DTest);
DEMO_ENTRY_IMPL(gridaction, Ripple3DTest);
DEMO_ENTRY_IMPL(gridaction, Shaky3DTest);
DEMO_ENTRY_IMPL(gridaction, ShakyTiles3DTest);
DEMO_ENTRY_IMPL(gridaction, ShatterTiles3DTest);
DEMO_ENTRY_IMPL(gridaction, ShuffleTilesTest);
DEMO_ENTRY_IMPL(gridaction, SplitRowsColsTest);
DEMO_ENTRY_IMPL(gridaction, TilesShrinkOutTest);
DEMO_ENTRY_IMPL(gridaction, TurnOffTilesTest);
DEMO_ENTRY_IMPL(gridaction, TwirlTest);
DEMO_ENTRY_IMPL(gridaction, Waves3DTest);
DEMO_ENTRY_IMPL(gridaction, WavesTest);
DEMO_ENTRY_IMPL(gridaction, WavesTiles3DTest);
