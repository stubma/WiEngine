#include "common.h"
#include "EventDemos.h"
#include "WiEngine.h"
#include <stdio.h>
#if ANDROID
	#include <jni.h>
#endif

namespace Events {
	#define TARGETSELECTOR(id, userData) wyTargetSelector::make(this, id, userData)

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
    class wyEventTestLayer : public wyLayer{
    protected:
        wySprite* m_Sprite;
    public:
        wyEventTestLayer(){
            m_Sprite = wySprite::make(wyTexture2D::makePNG(RES("R.drawable.grossini")));
            m_Sprite->retain();
            addChildLocked(m_Sprite);
            m_Sprite->setPosition(wyDevice::winWidth / 2, wyDevice::winHeight/ 2);
        };
        
        virtual ~wyEventTestLayer(){
            wyObjectRelease(m_Sprite);
            m_Sprite = NULL;
        };
    };

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	class wyCustomBackTestLayer: public wyLayer{
	public:
		wyCustomBackTestLayer() {
			/**
			 * wyScene类缺省是处理back键的，但是我们有很多方式可以自定义处理back键
			 * 1. 继承wyScene，覆盖wyKeyUp事件
			 * 2. 禁止wyScene处理key事件(setKeyEnabled(false))，让其它节点处理
			 * 3. 添加一个优先级比wyScene高的key事件处理器，相当于不让wyScene处理, wyScene缺省的优先级是0，指定一个
			 * 比0大的数就行
			 *
			 * 这个demo用第三种方式
			 */
			setKeyEnabled(true);
			setKeyPriority(1);

			/*
			 * iOS/MacOSX/Windows没有back键, 但是我们用这个demo来演示如何显示一个对话框, 所以点击屏幕
			 * 设置成弹出对话框
			 */
			setTouchEnabled(true);

			// hint label
			wyLabel* label = wyLabel::make("Please back key, OR\nTouch screen if not Android, OR\nPress Enter if not mobile", SP(16), BOLD, WY_DEFAULT_FONT);
			label->setPosition(wyDevice::winWidth / 2, wyDevice::winHeight / 2);
			addChildLocked(label);
		}

		virtual ~wyCustomBackTestLayer() {
		}

		virtual bool keyUp(wyKeyEvent& event) {
			switch(event.keyCode) {
				case KEYCODE_BACK:
					showDialog();
					return true;
			}

			return wyLayer::keyUp(event);
		}

		virtual bool touchesBegan(wyMotionEvent& e) {
			showDialog();
			return wyLayer::touchesBegan(e);
		}

		void showDialog() {
			wyUtils::showSystemConfirmDialog("Confirm",
					"Do you really want to exit current demo?",
					NULL,
					NULL,
					wyTargetSelector::make(this, SEL(wyCustomBackTestLayer::onOK)));
		}

		void onOK(wyTargetSelector* ts) {
			wyDirector::getInstance()->popScene();
		}
	};
	
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	class wyAccelerometerTestLayer: public wyEventTestLayer{
	private:
		float m_accelX;
		float m_accelY;

	public:
		wyAccelerometerTestLayer() :
				m_accelX(0.0f),
				m_accelY(0.0f) {
			setAccelerometerEnabled(true);

	    	wyTimer* timer = wyTimer::make(wyTargetSelector::make(this, SEL(wyAccelerometerTestLayer::onUpdateSprite)));
	    	scheduleLocked(timer);
		}

		virtual ~wyAccelerometerTestLayer(){}
		
		void onUpdateSprite(wyTargetSelector* ts) {
			float dx = m_accelX * DP(320) * ts->getDelta();
			float dy = m_accelY * DP(320) * ts->getDelta();

			float x = m_Sprite->getPositionX();
			float y = m_Sprite->getPositionY();
			m_Sprite->setPosition(x + dx, y + dy);
		}

		virtual void accelerometerChanged(float accelX, float accelY, float accelZ) {
			/*
			 * 请注意Android上的加速器事件是以设备的正向为标准的, 在XOOM上landscape才是正向,
			 * 由于这个demo运行在portrait模式, 所以移动的时候会不正确. 这不是bug, 具体做游戏
			 * 时请根据游戏的朝向自己处理加速器的值.
			 */

			m_accelX = accelX;
			m_accelY = accelY;
		}
	};
	
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	static const int NONE = 0;
	static const int LEFT = 1;
	static const int RIGHT = 2;
	static const int UP = 3;
	static const int DOWN = 4;

	class wyCharacterMoveTestLayer: public wyColorLayer, public wyActionCallback {
	private:
		int ITEM_WIDTH;
		int ITEM_HEIGHT;
		wySprite* m_Player;
		wyAnimation *m_AnimUp, *m_AnimDown, *m_AnimLeft, *m_AnimRight;
		wySpriteFrame *m_FaceUp, *m_FaceDown, *m_FaceLeft, *m_FaceRight;
		int m_LastDirection;
		
	private:
		wyRect frameAt(int x, int y) {
			return wyr(x * ITEM_WIDTH, y * ITEM_HEIGHT, ITEM_WIDTH, ITEM_HEIGHT);
		};
		
	public:
		wyCharacterMoveTestLayer() : wyColorLayer(wyc4b(0, 0, 255, 255)) {
			ITEM_WIDTH = DP(24);
			ITEM_HEIGHT = DP(33);
			m_LastDirection = NONE;
			
			// add player
            wyTexture2D* tex = wyTexture2D::makePNG(RES("R.drawable.player"));
            m_Player = new wySprite(tex, wyr(0, ITEM_HEIGHT * 2, ITEM_WIDTH, ITEM_HEIGHT));
			m_Player->setPosition(wyDevice::winWidth / 2, wyDevice::winHeight / 2);
			addChildLocked(m_Player);
			
			// create animation
            m_AnimUp = wyAnimation::make(0);
            m_AnimUp->retain();
            m_AnimUp->addFrame(0.3f, frameAt(0, 0));
            m_AnimUp->addFrame(0.3f, frameAt(2, 0));
			m_AnimDown = wyAnimation::make(1);
			m_AnimDown->retain();
            m_AnimDown->addFrame(0.3f, frameAt(0, 2));
            m_AnimDown->addFrame(0.3f, frameAt(2, 2));
			m_AnimLeft = wyAnimation::make(2);
			m_AnimLeft->retain();
            m_AnimLeft->addFrame(0.2f, frameAt(0, 3));
            m_AnimLeft->addFrame(0.2f, frameAt(1, 3));
            m_AnimLeft->addFrame(0.2f, frameAt(2, 3));
			m_AnimRight = wyAnimation::make(3);
			m_AnimRight->retain();
            m_AnimRight->addFrame(0.2f, frameAt(0, 1));
            m_AnimRight->addFrame(0.2f, frameAt(1, 1));
            m_AnimRight->addFrame(0.2f, frameAt(2, 1));
			
			// create static frame
			m_FaceUp = wySpriteFrame::make(0, frameAt(1, 0));
			m_FaceUp->retain();
			m_FaceDown = wySpriteFrame::make(0, frameAt(1, 2));
			m_FaceDown->retain();
			m_FaceRight = wySpriteFrame::make(0, frameAt(1, 1));
			m_FaceRight->retain();
			m_FaceLeft = wySpriteFrame::make(0, frameAt(1, 3));
			m_FaceLeft->retain();
			
			setTouchEnabled(true);
		};	
		
		virtual ~wyCharacterMoveTestLayer(){
			wyObjectRelease(m_Player);

			wyObjectRelease(m_AnimUp);
			wyObjectRelease(m_AnimDown);
			wyObjectRelease(m_AnimLeft);
			wyObjectRelease(m_AnimRight);

			wyObjectRelease(m_FaceUp);
			wyObjectRelease(m_FaceDown);
			wyObjectRelease(m_FaceLeft);
			wyObjectRelease(m_FaceRight);
		};
		
		virtual void onActionStart(wyAction* action) {
		}

		virtual void onActionStop(wyAction* action) {
			m_Player->stopAllActions(false);

			switch(m_LastDirection) {
				case UP:
					m_Player->setDisplayFrame(m_FaceUp);
					break;
				case DOWN:
					m_Player->setDisplayFrame(m_FaceDown);
					break;
				case LEFT:
					m_Player->setDisplayFrame(m_FaceLeft);
					break;
				case RIGHT:
					m_Player->setDisplayFrame(m_FaceRight);
					break;
			}

			m_LastDirection = NONE;
		}

		virtual void onActionUpdate(wyAction* action, float t) {
		}

		virtual bool touchesBegan(wyMotionEvent& event) {
			wyPoint loc = wyp(event.x[0], event.y[0]);
			
			// get delta between touch location and player position
			float deltaX = loc.x - m_Player->getPositionX();
			float deltaY = loc.y - m_Player->getPositionY();
			
			// move horizontal or vertical?
			bool horizontal = fabs(deltaX) > fabs(deltaY);
			
			// decide direction
			int direction = NONE;
			if(horizontal) {
				deltaY = 0.0f;
				if(deltaX != 0)
					direction = deltaX > 0 ? RIGHT : LEFT;
			} else {
				deltaX = 0.0f;
				if(deltaY != 0)
					direction = deltaY > 0 ? UP : DOWN;
			}
			
			// get moving velocity
			float velocityX = 0.0f;
			float velocityY = 0.0f;
			float duration = 0.0f;
			wyAnimation* animation = NULL;
			switch(direction) {
				case LEFT:
					velocityX = -100.0f;
					duration = deltaX / velocityX;
					animation = m_AnimLeft;
					break;
				case RIGHT:
					velocityX = 100.0f;
					duration = deltaX / velocityX;
					animation = m_AnimRight;
					break;
				case UP:
					velocityY = 100.0f;
					duration = deltaY / velocityY;
					animation = m_AnimUp;
					break;
				case DOWN:
					velocityY = -100.0f;
					duration = deltaY / velocityY;
					animation = m_AnimDown;
					break;
			}
			
			// if same as last direction
			if(direction != m_LastDirection) {
				m_LastDirection = direction;
				
				// stop old actions
				m_Player->stopAllActions(false);
				
				// create action
				wyIntervalAction* move = wyMoveBy::make(duration, deltaX, deltaY);
				wyIntervalAction* anim = wyAnimate::make(animation, true);
				move->setCallback(this);
				m_Player->runAction(move);
				wyRepeatForever* r = wyRepeatForever::make(anim);
				m_Player->runAction(r);
			}
			
			return true;
		}
	};
	
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	class wyClickAndMoveTestLayer: public wyEventTestLayer{
	public:
		wyClickAndMoveTestLayer(){
			m_Sprite->setPosition(20, 150);
			
			wyAction* action = wyJumpTo::make(4, m_Sprite->getPositionX(), m_Sprite->getPositionY(), 300, 48, 100, 4);
			m_Sprite->runAction(action);

			setTouchEnabled(true);
		};	
		
		virtual bool touchesBegan(wyMotionEvent& event) {
				wyPoint loc = wyp(event.x[0], event.y[0]);
				
				m_Sprite->stopAllActions(false);
				
				wyAction* action = wyMoveTo::make(1.0f, m_Sprite->getPositionX(), m_Sprite->getPositionY(), loc.x, loc.y);
				m_Sprite->runAction(action);

				float o = loc.x - m_Sprite->getPositionX();
				float a = loc.y - m_Sprite->getPositionY();
				float at = wyMath::r2d((float)atan(o / a));

				if(a < 0) {
					if(o < 0)
						at = 180 + fabs(at);
					else
						at = 180 - fabs(at);
				}

				action = wyRotateTo::make(1, m_Sprite->getRotation(), at);
				m_Sprite->runAction(action);

				return true;
		}
	};
	
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	class wyDoubleTapTestLayer: public wyEventTestLayer{
	private:
		wyLabel* m_hint;

	public:
		wyDoubleTapTestLayer() {
			setDoubleTapEnabled(true);

    		// create a hint label
    		m_hint = wyLabel::make("double tap to scale", SP(20));
    		m_hint->setPosition(wyDevice::winWidth / 2, 100);
    		addChildLocked(m_hint);
		};	
		
		virtual bool onDoubleTap(wyMotionEvent& e) {
			m_hint->setText("onDoubleTap");

			if(m_Sprite->getScale() == 2.0f)
				m_Sprite->setScale(1.0f);
			else
				m_Sprite->setScale(2.0f);
			
			return true;
		}
		
		virtual bool onDoubleTapEvent(wyMotionEvent& e) {
			m_hint->setText("onDoubleTapEvent");
			return true;
		}

		virtual bool onSingleTapConfirmed(wyMotionEvent& e) {
			m_hint->setText("onSingleTapConfirmed");
			return true;
		}
	};
	
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	class wyGestureTestLayer: public wyLayer{
	private:
		wyLabel* m_hint;

	public:
		wyGestureTestLayer(){
    		// create a hint label
    		m_hint = wyLabel::make("touch screen", SP(20));
    		m_hint->setPosition(wyDevice::winWidth / 2, 100);
    		addChildLocked(m_hint);

    		setDoubleTapEnabled(true);
			setGestureEnabled(true);
		};	
		
		virtual bool onDoubleTap(wyMotionEvent& e) {
			m_hint->setText("onDoubleTap");
			return true;
		}

		virtual bool onDoubleTapEvent(wyMotionEvent& e) {
			m_hint->setText("onDoubleTapEvent");
			return true;
		}

		virtual bool onSingleTapConfirmed(wyMotionEvent& e) {
			m_hint->setText("onSingleTapConfirmed");
			return true;
		}

		virtual bool onDown(wyMotionEvent& e) {
			m_hint->setText("onDown");
			return true;
		}
		
		virtual void onLongPress(wyMotionEvent& e) {
			m_hint->setText("onLongPress");
		}
		
		virtual bool onScroll(wyMotionEvent& e1, wyMotionEvent& e2, float distanceX, float distanceY) {
			char buf[128];
			sprintf(buf, "onScroll, dX: %.2f, dY: %.2f", distanceX, distanceY);
			m_hint->setText(buf);
			return true;
		}
		
		virtual bool onFling(wyMotionEvent& e1, wyMotionEvent& e2, float velocityX, float velocityY) {
			char buf[128];
			sprintf(buf, "onFling, vX: %.2f, vY: %.2f", velocityX, velocityY);
			m_hint->setText(buf);
			return true;
		}
		
		virtual void onShowPress(wyMotionEvent& e) {
			m_hint->setText("onShowPress");
		}

		virtual bool onSingleTapUp(wyMotionEvent& e) {
			m_hint->setText("onSingleTapUp");
			return true;
		}
	};
	
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	class wyKeyTestLayer: public wyLayer{
		wyLabel* m_Label;
	public:
		wyKeyTestLayer(){
			m_Label = new wyLabel();
			m_Label->setText("KeyEvent Test");
			m_Label->setPosition(wyDevice::winWidth / 2, wyDevice::winHeight / 2);
			addChildLocked(m_Label);

			setKeyEnabled(true);
		};	
		
		virtual ~wyKeyTestLayer(){
			wyObjectRelease(m_Label);
		};
		
		virtual bool keyDown(wyKeyEvent& event) {
			char keyStr[256], buf[256];
			getKeyCodeString(event, keyStr);
			sprintf(buf, "%s Event Down", keyStr);
			m_Label->setText(buf);
			
			// don't handle back key
			if(event.keyCode == KEYCODE_BACK)
				return false;
			else
				return true;
		}
		
		virtual bool keyUp(wyKeyEvent& event) {
			char keyStr[256], buf[256];
			getKeyCodeString(event, keyStr);
			sprintf(buf, "%s Event Up", keyStr);
			m_Label->setText(buf);
			return wyNode::keyUp(event);
		}
		
		void getKeyCodeString(wyKeyEvent event, char* buf) {
			int kc = event.keyCode;
			switch(kc) {
				case KEYCODE_BACK:
					sprintf(buf, "Back");
					break;
				case KEYCODE_MENU:
					sprintf(buf, "Menu");
					break;
				case KEYCODE_SEARCH:
					sprintf(buf, "Search");
					break;
				case KEYCODE_DPAD_DOWN:
					sprintf(buf, "Down");
					break;
				case KEYCODE_DPAD_UP:
					sprintf(buf, "Up");
					break;
				case KEYCODE_DPAD_LEFT:
					sprintf(buf, "Left");
					break;
				case KEYCODE_DPAD_RIGHT:
					sprintf(buf, "Right");
					break;
				case KEYCODE_DPAD_CENTER:
					sprintf(buf, "Center");
					break;
				default:
					if(kc >= KEYCODE_0 && kc <= KEYCODE_9)
						sprintf(buf, "%d", kc - KEYCODE_0);
					else if(kc >= KEYCODE_A && kc <= KEYCODE_Z)
						sprintf(buf, "%c", 'A' + kc - KEYCODE_A);
					else
						sprintf(buf, "Key");
					break;
			}
		}
	};
	
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	class wyMultiTouchTestLayer: public wyEventTestLayer {
		bool m_Scaling;
		float m_InitScale;
		float m_InitDistance;
		
	public:
		wyMultiTouchTestLayer() : 
				m_Scaling(false), 
				m_InitScale(1),
				m_InitDistance(0){
			setTouchEnabled(true);
		};	

		virtual bool touchesBegan(wyMotionEvent& e) {			
			return true;
		}

		virtual bool touchesPointerBegan(wyMotionEvent& e) {
			if(e.pointerCount == 2) {
				m_Scaling = true;
				m_InitScale = m_Sprite->getScale();
				
				// remember init distance
				wyPoint loc1 = wyp(e.x[0], e.y[0]);
				wyUtils::convertToGL(&loc1);
				wyPoint loc2 = wyp(e.x[1], e.y[1]);
				wyUtils::convertToGL(&loc2);
				m_InitDistance =  wypLength(wypSub(loc1, loc2));
			} else {
				m_Scaling = false;
			}
			
			return true;
		}
		
		virtual bool touchesPointerEnded(wyMotionEvent& e) {
			m_Scaling = e.pointerCount == 3;
			return true;
		}
		
		virtual bool touchesMoved(wyMotionEvent& e) {
			if(m_Scaling) {
				// get distance
				wyPoint loc1 = wyp(e.x[0], e.y[0]);
				wyUtils::convertToGL(&loc1);
				wyPoint loc2 = wyp(e.x[1], e.y[1]);
				wyUtils::convertToGL(&loc2);
				float distance = wypLength(wypSub(loc1, loc2));
				
				// set scale factor
				m_Sprite->setScale(m_InitScale * distance / m_InitDistance);
			}
			
			return true;
		}
		
		virtual bool touchesEnded(wyMotionEvent& e) {
			m_Scaling = e.pointerCount == 3;
			return true;
		}
		
		virtual bool touchesCancelled(wyMotionEvent& e) {
			m_Scaling = e.pointerCount == 3;
			return true;
		}
	};
	
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
}

using namespace Events;

DEMO_ENTRY_IMPL(event, AccelerometerTest);
DEMO_ENTRY_IMPL(event, CharacterMoveTest);
DEMO_ENTRY_IMPL(event, ClickAndMoveTest);
DEMO_ENTRY_IMPL(event, CustomBackTest);
DEMO_ENTRY_IMPL(event, DoubleTapTest);
DEMO_ENTRY_IMPL(event, GestureTest);
DEMO_ENTRY_IMPL(event, KeyTest);
DEMO_ENTRY_IMPL(event, MultiTouchTest);
