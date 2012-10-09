#include "common.h"
#include "EaseActionDemos.h"
#include "WiEngine.h"
#include <stdio.h>

namespace Ease_Action {
    class wyEaseTestLayer : public wyLayer{
    protected:
        wySprite* m_Sprite;

    public:
        wyEaseTestLayer() {
            m_Sprite = wySprite::make(wyTexture2D::makePNG(RES("R.drawable.grossini")));
            m_Sprite->retain();
            addChildLocked(m_Sprite);
            m_Sprite->setPosition(60, wyDevice::winHeight/ 2);
        }
        
        virtual ~wyEaseTestLayer(){
            wyObjectRelease(m_Sprite);
            m_Sprite = NULL;
        }
    };
    
    class wyEaseBackInOutTestLayer : public wyEaseTestLayer {
    public:
        wyEaseBackInOutTestLayer(){
            wyIntervalAction* a = wyMoveBy::make(2, wyDevice::winWidth - 120, 0);
            wyIntervalAction* t = wySequence::make(wyEaseBackInOut::make(a),
            		wyEaseBackInOut::make((wyIntervalAction*)a->reverse()),
            		NULL);

            wyAction* action = wyRepeatForever::make(t);
            m_Sprite->runAction(action);
        }
    };

    class wyEaseBackInTestLayer : public wyEaseTestLayer {
    public:
        wyEaseBackInTestLayer() {
            wyIntervalAction* a = wyMoveBy::make(2, wyDevice::winWidth - 120, 0);
            wyIntervalAction* t = wySequence::make(wyEaseBackIn::make(a),
            		wyEaseBackIn::make((wyIntervalAction*)a->reverse()),
            		NULL);

            wyAction* action = wyRepeatForever::make(t);
            m_Sprite->runAction(action);
        }
    };

    class wyEaseBackOutTestLayer : public wyEaseTestLayer {
    public:
        wyEaseBackOutTestLayer() {
            wyIntervalAction* a = wyMoveBy::make(2, wyDevice::winWidth - 120, 0);
            wyIntervalAction* t = wySequence::make(wyEaseBackOut::make(a),
            		wyEaseBackOut::make((wyIntervalAction*)a->reverse()),
            		NULL);

            wyAction* action = wyRepeatForever::make(t);
            m_Sprite->runAction(action);
        }
    };

    class wyEaseBounceInOutTestLayer : public wyEaseTestLayer {
    public:
        wyEaseBounceInOutTestLayer() {
            wyIntervalAction* a = wyMoveBy::make(2, wyDevice::winWidth - 120, 0);
            wyIntervalAction* t = wySequence::make(wyEaseBounceInOut::make(a),
            		wyEaseBounceInOut::make((wyIntervalAction*)a->reverse()),
            		NULL);

            wyAction* action = wyRepeatForever::make(t);
            m_Sprite->runAction(action);
        }
    };

    class wyEaseBounceInTestLayer : public wyEaseTestLayer {
    public:
        wyEaseBounceInTestLayer() {
            wyIntervalAction* a = wyMoveBy::make(2, wyDevice::winWidth - 120, 0);
            wyIntervalAction* t = wySequence::make(wyEaseBounceIn::make(a),
            		wyEaseBounceIn::make((wyIntervalAction*)a->reverse()),
            		NULL);

            wyAction* action = wyRepeatForever::make(t);
            m_Sprite->runAction(action);
        }
    };

    class wyEaseBounceOutTestLayer : public wyEaseTestLayer {
    public:
        wyEaseBounceOutTestLayer() {
            wyIntervalAction* a = wyMoveBy::make(2, wyDevice::winWidth - 120, 0);
            wyIntervalAction* t = wySequence::make(wyEaseBounceOut::make(a),
            		wyEaseBounceOut::make((wyIntervalAction*)a->reverse()),
            		NULL);

            wyAction* action = wyRepeatForever::make(t);
            m_Sprite->runAction(action);
        }
    };

    class wyEaseElasticInOutTestLayer : public wyEaseTestLayer {
    public:
        wyEaseElasticInOutTestLayer() {
            wyIntervalAction* a = wyMoveBy::make(2, wyDevice::winWidth - 120, 0);
            wyIntervalAction* t = wySequence::make(wyEaseElasticInOut::make(0.3f, a),
            		wyEaseElasticInOut::make(0.3f, (wyIntervalAction*)a->reverse()),
            		NULL);

            wyAction* action = wyRepeatForever::make(t);
            m_Sprite->runAction(action);
        }
    };

    class wyEaseElasticInTestLayer : public wyEaseTestLayer {
    public:
        wyEaseElasticInTestLayer() {
            wyIntervalAction* a = wyMoveBy::make(2, wyDevice::winWidth - 120, 0);
            wyIntervalAction* t = wySequence::make(wyEaseElasticIn::make(0.3f, a),
            		wyEaseElasticIn::make(0.3f, (wyIntervalAction*)a->reverse()),
            		NULL);

            wyAction* action = wyRepeatForever::make(t);
            m_Sprite->runAction(action);
        }
    };
    
   class wyEaseElasticOutTestLayer : public wyEaseTestLayer {
    public:
        wyEaseElasticOutTestLayer() {
            wyIntervalAction* a = wyMoveBy::make(2, wyDevice::winWidth - 120, 0);
            wyIntervalAction* t = wySequence::make(wyEaseElasticOut::make(0.3f, a),
            		wyEaseElasticOut::make(0.3f, (wyIntervalAction*)a->reverse()),
            		NULL);

            wyAction* action = wyRepeatForever::make(t);
            m_Sprite->runAction(action);
        }
    };

  class wyEaseExponentialInOutTestLayer : public wyEaseTestLayer {
    public:
        wyEaseExponentialInOutTestLayer() {
            wyIntervalAction* a = wyMoveBy::make(2, wyDevice::winWidth - 120, 0);
            wyIntervalAction* t = wySequence::make(wyEaseExponentialInOut::make(a),
            		wyEaseExponentialInOut::make((wyIntervalAction*)a->reverse()),
            		NULL);

            wyAction* action = wyRepeatForever::make(t);
            m_Sprite->runAction(action);
        }
    };

    class wyEaseExponentialInTestLayer : public wyEaseTestLayer {
    public:
        wyEaseExponentialInTestLayer() {
            wyIntervalAction* a = wyMoveBy::make(2, wyDevice::winWidth - 120, 0);
            wyIntervalAction* t = wySequence::make(wyEaseExponentialIn::make(a),
            		wyEaseExponentialIn::make((wyIntervalAction*)a->reverse()),
            		NULL);

            wyAction* action = wyRepeatForever::make(t);
            m_Sprite->runAction(action);
        }
    };

   class wyEaseExponentialOutTestLayer : public wyEaseTestLayer {
    public:
        wyEaseExponentialOutTestLayer() {
            wyIntervalAction* a = wyMoveBy::make(2, wyDevice::winWidth - 120, 0);
            wyIntervalAction* t = wySequence::make(wyEaseExponentialOut::make(a),
            		wyEaseExponentialOut::make((wyIntervalAction*)a->reverse()),
            		NULL);

            wyAction* action = wyRepeatForever::make(t);
            m_Sprite->runAction(action);
        }
    };

 class wyEaseInOutTestLayer : public wyEaseTestLayer {
    public:
        wyEaseInOutTestLayer() {
            wyIntervalAction* a = wyMoveBy::make(2, wyDevice::winWidth - 120, 0);
            wyIntervalAction* t = wySequence::make(wyEaseInOut::make(2, a),
            		wyEaseInOut::make(2, (wyIntervalAction*)a->reverse()),
            		NULL);

            wyAction* action = wyRepeatForever::make(t);
            m_Sprite->runAction(action);
        }
    };

    class wyEaseInTestLayer : public wyEaseTestLayer {
    public:
        wyEaseInTestLayer() {
            wyIntervalAction* a = wyMoveBy::make(2, wyDevice::winWidth - 120, 0);
            wyIntervalAction* t = wySequence::make(wyEaseIn::make(2, a),
            		wyEaseIn::make(2, (wyIntervalAction*)a->reverse()),
            		NULL);

            wyAction* action = wyRepeatForever::make(t);
            m_Sprite->runAction(action);
        }
    };

    class wyEaseOutTestLayer : public wyEaseTestLayer {
    public:
        wyEaseOutTestLayer() {
            wyIntervalAction* a = wyMoveBy::make(2, wyDevice::winWidth - 120, 0);
            wyIntervalAction* t = wySequence::make(wyEaseOut::make(2, a),
            		wyEaseOut::make(2, (wyIntervalAction*)a->reverse()),
            		NULL);

            wyAction* action = wyRepeatForever::make(t);
            m_Sprite->runAction(action);
        }
    };

    class wyEaseSineInOutTestLayer : public wyEaseTestLayer {
    public:
        wyEaseSineInOutTestLayer() {
            wyIntervalAction* a = wyMoveBy::make(2, wyDevice::winWidth - 120, 0);
            wyIntervalAction* t = wySequence::make(wyEaseSineInOut::make(a),
            		wyEaseSineInOut::make((wyIntervalAction*)a->reverse()),
            		NULL);

            wyAction* action = wyRepeatForever::make(t);
            m_Sprite->runAction(action);
        }
    };

    class wyEaseSineInTestLayer : public wyEaseTestLayer {
    public:
        wyEaseSineInTestLayer() {
            wyIntervalAction* a = wyMoveBy::make(2, wyDevice::winWidth - 120, 0);
            wyIntervalAction* t = wySequence::make(wyEaseSineIn::make(a),
            		wyEaseSineIn::make((wyIntervalAction*)a->reverse()),
            		NULL);

            wyAction* action = wyRepeatForever::make(t);
            m_Sprite->runAction(action);
        }
    };

    class wyEaseSineOutTestLayer : public wyEaseTestLayer {
    public:
        wyEaseSineOutTestLayer() {
            wyIntervalAction* a = wyMoveBy::make(2, wyDevice::winWidth - 120, 0);
            wyIntervalAction* t = wySequence::make(wyEaseSineOut::make(a),
            		wyEaseSineOut::make((wyIntervalAction*)a->reverse()),
            		NULL);

            wyAction* action = wyRepeatForever::make(t);
            m_Sprite->runAction(action);
        }
    };
}

using namespace Ease_Action;

#if ANDROID
	#define DEMO_ENTRY_IMPL(CLASSNAME) JNIEXPORT void JNICALL Java_com_wiyun_engine_tests_ease_##CLASSNAME##_nativeStart \
	(JNIEnv *, jobject){ \
		wyLayer* layer = new wy##CLASSNAME##Layer(); \
		runDemo(layer, NULL); \
		wyObjectRelease(layer); \
	}
#elif IOS || MACOSX || WINDOWS
	#define DEMO_ENTRY_IMPL(CLASSNAME) void _ease_##CLASSNAME##Launcher() { \
			wyLayer* layer = new wy##CLASSNAME##Layer(); \
			runDemo(layer, NULL); \
			wyObjectRelease(layer); \
		}
#endif

DEMO_ENTRY_IMPL(EaseBackInOutTest);
DEMO_ENTRY_IMPL(EaseBackInTest);
DEMO_ENTRY_IMPL(EaseBackOutTest);
DEMO_ENTRY_IMPL(EaseBounceInOutTest);
DEMO_ENTRY_IMPL(EaseBounceInTest);
DEMO_ENTRY_IMPL(EaseBounceOutTest);
DEMO_ENTRY_IMPL(EaseElasticInOutTest);
DEMO_ENTRY_IMPL(EaseElasticInTest);
DEMO_ENTRY_IMPL(EaseElasticOutTest);
DEMO_ENTRY_IMPL(EaseExponentialInOutTest);
DEMO_ENTRY_IMPL(EaseExponentialInTest);
DEMO_ENTRY_IMPL(EaseExponentialOutTest);
DEMO_ENTRY_IMPL(EaseInOutTest);
DEMO_ENTRY_IMPL(EaseInTest);
DEMO_ENTRY_IMPL(EaseOutTest);
DEMO_ENTRY_IMPL(EaseSineInOutTest);
DEMO_ENTRY_IMPL(EaseSineInTest);
DEMO_ENTRY_IMPL(EaseSineOutTest);
