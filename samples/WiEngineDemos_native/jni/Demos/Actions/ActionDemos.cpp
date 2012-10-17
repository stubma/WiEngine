#include "common.h"
#include "ActionDemos.h"
#include "WiEngine.h"
#include <stdio.h>

namespace Action {
	class wyActionTestLayer : public wyLayer{
	protected:
		wySprite* m_Sprite;
	public:
		wyActionTestLayer(){
			m_Sprite = wySprite::make(wyTexture2D::makePNG(RES("R.drawable.grossini")));
			m_Sprite->retain();
			addChildLocked(m_Sprite);
			m_Sprite->setPosition(wyDevice::winWidth / 2, wyDevice::winHeight/ 2);
		};

		virtual ~wyActionTestLayer(){
			wyObjectRelease(m_Sprite);
			m_Sprite = NULL;
		};
	};

	/////////////////////////////////////////////////////////////////////////////////////////////////
    
    class wyAnimationTestLayer : public wyActionTestLayer {
    public:
    	wyLabel* m_hint;

    public:
        wyAnimationTestLayer(){
            // create animation
            wyAnimation* anim = wyAnimation::make(0);
            for (int i = 0; i < 14; i++){
                char name[256];
                sprintf(name, "grossini_dance_%.2d", i + 1);
                anim->addFrame(0.2f, wyTexture2D::makePNG(wyUtils::getResId(name, "drawable", NULL)));
            }
            wyAnimationCallback callback = {
            		onAnimationFrameChanged,
            		onAnimationEnded
            };
            anim->setCallback(&callback, this);
        
            wyAnimate* a = wyAnimate::make(anim);
            m_Sprite->runAction(a);

    		// create a hint label
    		m_hint = wyLabel::make("callback display label", SP(20));
    		m_hint->setPosition(wyDevice::winWidth / 2, 100);
    		addChildLocked(m_hint);
        }

    	static void onAnimationFrameChanged(wyAnimation* anim, int index, void* data) {
    		wyAnimationTestLayer* layer = (wyAnimationTestLayer*)data;
    		char buf[64];
    		sprintf(buf, "frame changed: %d", index);
    		layer->m_hint->setText(buf);
    	}

    	static void onAnimationEnded(wyAnimation* anim, void* data) {
    		wyAnimationTestLayer* layer = (wyAnimationTestLayer*)data;
    		layer->m_hint->setText("animation ended");
    	}
    };
    
    /////////////////////////////////////////////////////////////////////////////////////////////////

    class wyAtlasAnimationTestLayer : public wyLayer {
    private:
		int ITEM_WIDTH;
		int ITEM_HEIGHT;

    public:
		wyLabel* m_hint;

    private:
		wyRect frameAt(int x, int y){
		   return wyr(x * ITEM_WIDTH, y * ITEM_HEIGHT, ITEM_WIDTH, ITEM_HEIGHT);
		}

    public:
        wyAtlasAnimationTestLayer(){
            // set width and height
            ITEM_WIDTH = DP(85);
            ITEM_HEIGHT = DP(121);
            
            // add sprite
            wyTexture2D* tex = wyTexture2D::makePNG(RES("R.drawable.grossini_dance_atlas"));
            wySprite* sprite = wySprite::make(tex, wyr(0, 0, ITEM_WIDTH, ITEM_HEIGHT));
            sprite->setPosition(wyDevice::winWidth / 2, wyDevice::winHeight / 2);
            addChildLocked(sprite);
            
            // create animation and add it to atlas sprite
            wyAnimation* anim = wyAnimation::make(0);
            anim->addFrame(0.2f, frameAt(0, 0));
            anim->addFrame(0.2f, frameAt(1, 0));
            anim->addFrame(0.2f, frameAt(2, 0));
            anim->addFrame(0.2f, frameAt(3, 0));
            anim->addFrame(0.2f, frameAt(4, 0));
            anim->addFrame(0.2f, frameAt(0, 1));
            anim->addFrame(0.2f, frameAt(1, 1));
            anim->addFrame(0.2f, frameAt(2, 1));
            anim->addFrame(0.2f, frameAt(3, 1));
            anim->addFrame(0.2f, frameAt(4, 1));
            anim->addFrame(0.2f, frameAt(0, 2));
            anim->addFrame(0.2f, frameAt(1, 2));
            anim->addFrame(0.2f, frameAt(2, 2));
            anim->addFrame(0.2f, frameAt(3, 2));
            wyAnimationCallback callback = {
            		onAnimationFrameChanged,
            		onAnimationEnded
            };
            anim->setCallback(&callback, this);
            
            wyAnimate* a = wyAnimate::make(anim);
            sprite->runAction(a);

    		// create a hint label
    		m_hint = wyLabel::make("callback display label", SP(20));
    		m_hint->setPosition(wyDevice::winWidth / 2, 100);
    		addChildLocked(m_hint);
        };

    	static void onAnimationFrameChanged(wyAnimation* anim, int index, void* data) {
    		wyAtlasAnimationTestLayer* layer = (wyAtlasAnimationTestLayer*)data;
    		char buf[64];
    		sprintf(buf, "frame changed: %d", index);
    		layer->m_hint->setText(buf);
    	}

    	static void onAnimationEnded(wyAnimation* anim, void* data) {
    		wyAtlasAnimationTestLayer* layer = (wyAtlasAnimationTestLayer*)data;
    		layer->m_hint->setText("animation ended");
    	}
    };
    
    /////////////////////////////////////////////////////////////////////////////////////////////////

    class wyBlinkTestLayer : public wyActionTestLayer {
    public:
        wyBlinkTestLayer() {
            wyIntervalAction* t = wyBlink::make(1,2);
            wyAction* action = wyRepeatForever::make(t);
            m_Sprite->runAction(action);
        }
    };

    /////////////////////////////////////////////////////////////////////////////////////////////////

    class wyCallFuncTestLayer : public wyLayer {
    public:
        wyCallFuncTestLayer() {
        	wyCallFunc* call1 = wyCallFunc::make(wyTargetSelector::make(this, SEL(wyCallFuncTestLayer::onFunc1)));
        	wyCallFunc* call2 = wyCallFunc::make(wyTargetSelector::make(this, SEL(wyCallFuncTestLayer::onFunc2)));

        	wyAction* seq = wySequence::make(call1, call2, NULL);
        	runAction(seq);
        }

        virtual ~wyCallFuncTestLayer() {
        }

        void onFunc1(wyTargetSelector* ts) {
        	wyToast::make("func1 is called", 3.0f)->show();
        }

        void onFunc2(wyTargetSelector* ts) {
        	wyToast::make("func2 is called", 3.0f)->show();
        }
    };

    /////////////////////////////////////////////////////////////////////////////////////////////////

    class wyClipInOutTestLayer : public wyLayer {
    private:
    	bool m_expanded;
    	bool m_toggling;
    	wyButton* m_button;
    	wySprite* m_sprite;

    public:
    	wyClipInOutTestLayer() : m_expanded(false), m_toggling(false) {
    		wySprite* normal = wySprite::make(wyTexture2D::makePNG(RES("R.drawable.icon")));
    		m_button = wyButton::make(normal, NULL, NULL, NULL, NULL, wyTargetSelector::make(this, SEL(wyClipInOutTestLayer::onToggle)));
    		m_button->setPosition(DP(40), wyDevice::winHeight / 2);
    		addChildLocked(m_button);

    		m_sprite = wySprite::make(wyTexture2D::makeJPG(RES("R.drawable.test_jpg")));
    		m_sprite->setAnchor(0, 0.5f);
    		m_sprite->setPosition(m_button->getOriginX() + m_button->getWidth(), wyDevice::winHeight / 2);
    		m_sprite->setClipRect(wyrZero, true);
    		addChildLocked(m_sprite);
        }

    	virtual ~wyClipInOutTestLayer() {
    	}

    	static void onToggleEnd(wyAction* action, void* data) {
    		wyClipInOutTestLayer* layer = (wyClipInOutTestLayer*)data;
    		layer->m_toggling = false;
    	}

    	void onToggle(wyTargetSelector* ts) {
    		if(m_toggling)
    			return;

    		if(m_expanded) {
    			m_expanded = false;
    			m_toggling = true;

    			m_sprite->runAction(wyClipOut::make(0.5f, wyClipOut::RIGHT_TO_LEFT));
    			wyRotateBy* rotate = wyRotateBy::make(0.5f, -90);
    			wyActionCallback callback = {
    					NULL,
    					onToggleEnd,
    					NULL
    			};
    			rotate->setCallback(&callback, this);
    			m_button->runAction(rotate);
    		} else {
    			m_expanded = true;
    			m_toggling = true;

    			m_sprite->runAction(wyClipIn::make(0.5f, wyClipIn::LEFT_TO_RIGHT));
    			wyRotateBy* rotate = wyRotateBy::make(0.5f, 90);
    			wyActionCallback callback = {
    					NULL,
    					onToggleEnd,
    					NULL
    			};
    			rotate->setCallback(&callback, this);
    			m_button->runAction(rotate);
    		}
    	}
    };

    /////////////////////////////////////////////////////////////////////////////////////////////////

    class wyDelayShowHideTestLayer : public wyActionTestLayer {
    public:
        wyDelayShowHideTestLayer() {
            wyIntervalAction* t = wySequence::make(wyDelayTime::make(1),
												   wyHide::make(),
												   wyDelayTime::make(1),
												   wyShow::make(),
												   NULL);
           
            wyAction* action = wyRepeatForever::make(t);
            m_Sprite->runAction(action);
        };
    };

    /////////////////////////////////////////////////////////////////////////////////////////////////

    class wyFadeInOutTestLayer : public wyActionTestLayer {
    public:
        wyFadeInOutTestLayer() {
            wyIntervalAction* a = wyFadeOut::make(2);
            wyIntervalAction* t = wySequence::make(a, (wyFiniteTimeAction*)a->reverse(), NULL);

            wyAction* action = wyRepeatForever::make(t);
            m_Sprite->runAction(action);        
        }
    };

    /////////////////////////////////////////////////////////////////////////////////////////////////

    class wyFadeToTestLayer : public wyActionTestLayer {
    public:
        wyFadeToTestLayer() {
            wyIntervalAction* a = wyFadeTo::make(2, 255, 0);
            wyIntervalAction* r = (wyIntervalAction*)a->reverse();
            wyIntervalAction* t = wySequence::make(a, r, NULL);

            wyAction* action = wyRepeatForever::make(t);
            m_Sprite->runAction(action);
        }
    };

    /////////////////////////////////////////////////////////////////////////////////////////////////

    class wyFollowTestLayer : public wyActionTestLayer {
	public:
    	wyFollowTestLayer(){
    		float startx = DP(60);
    		float y = wyDevice::winHeight / 2;
    		float endx = wyDevice::winWidth + DP(100);

    		m_Sprite->setPosition(startx, y);
			wyIntervalAction* a = wyMoveTo::make(3, startx, y, endx, y);
			wyIntervalAction* t = wySequence::make(a, (wyFiniteTimeAction*)a->reverse(), NULL);

			wyTiledSprite* ts = wyTiledSprite::make(wyTexture2D::makePNG(RES("R.drawable.tiled_bg")));
			ts->setContentSize(wyDevice::winWidth, DP(115));
			ts->setTileDirection(true, false);
			ts->setAnchor(0, 0);
			ts->setPosition(0, 100);
			addChildLocked(ts);

			wyAction* action = wyRepeatForever::make(t);
			m_Sprite->runAction(action);

			wyRect rect = wyr(0, 0, wyDevice::winWidth + DP(160), wyDevice::winHeight);
			wyFollow* f = wyFollow::make(m_Sprite, rect);
			runAction(f);
		}
	};

    /////////////////////////////////////////////////////////////////////////////////////////////////

    class wyJumpByTestLayer : public wyActionTestLayer {
    public:
        wyJumpByTestLayer(){
	        m_Sprite->setPosition(60, wyDevice::winHeight / 2);
    
            wyIntervalAction* a = wyJumpBy::make(3, wyDevice::winWidth - 120, 0, 200, 3);
            wyIntervalAction* t = wySequence::make(a, (wyFiniteTimeAction*)a->reverse(), NULL);

            wyAction* action = wyRepeatForever::make(t);
            m_Sprite->runAction(action);
        }
    };

    /////////////////////////////////////////////////////////////////////////////////////////////////

    class wyJumpToTestLayer : public wyActionTestLayer {
    public:
        wyJumpToTestLayer(){
	        m_Sprite->setPosition(60, wyDevice::winHeight / 2);

            wyIntervalAction* a = wyJumpTo::make(3, m_Sprite->getPositionX(), m_Sprite->getPositionY(),
                                               wyDevice::winWidth - 60, wyDevice::winHeight/2, 200, 3);
            wyIntervalAction* t = wySequence::make(a, (wyFiniteTimeAction*)a->reverse(), NULL);

            wyAction* action = wyRepeatForever::make(t);
            m_Sprite->runAction(action);
        }
    };

    /////////////////////////////////////////////////////////////////////////////////////////////////

    class wyHypotrochoidTestLayer : public wyActionTestLayer {
    private:
    	wyHypotrochoidConfig m_c;
    	wyHypotrochoidConfig m_circle;
    	wyHypotrochoidConfig m_ellipse;

	public:
    	wyHypotrochoidTestLayer() {
    		m_c = wyhcQuad(DP(100), DP(40), DP(100), 0, 720, wyDevice::winWidth / 2, wyDevice::winHeight / 2);
    		addTrace(m_c);

    		m_ellipse = wyhcEllipse(DP(100), DP(30), 0, 360, wyDevice::winWidth / 2, wyDevice::winHeight / 2);
    		addTrace(m_ellipse);

    		m_circle = wyhcCircle(DP(80), 0, 360, wyDevice::winWidth / 2, wyDevice::winHeight / 2);
    		addTrace(m_circle);

    		m_Sprite->setVisible(false);

    		// material and mesh for first curve
            wyMaterial* m = wyMaterial::make(wyShaderManager::PROG_PC);
            wyShape* s = wyShape::make();
            s->buildHypotrochoid(m_c, 100);
            s->updateColor(wyc4bGreen);
            addRenderPair(m, s);

    		// material and mesh for second curve
            s = wyShape::make();
            s->buildHypotrochoid(m_ellipse, 100);
            s->updateColor(wyc4bGreen);
            addRenderPair(m, s);

    		// material and mesh for third curve
            s = wyShape::make();
            s->buildHypotrochoid(m_circle, 100);
            s->updateColor(wyc4bGreen);
            addRenderPair(m, s);
    	}

    	void addTrace(wyHypotrochoidConfig c) {
    		wySprite* r = wySprite::make(wyTexture2D::makePNG(RES("R.drawable.grossini")));
    		r->setScale(0.2f);
			addChildLocked(r);
			r->setPosition(wyDevice::winWidth / 2, wyDevice::winHeight / 2);
			wyHypotrochoid* a = wyHypotrochoid::make(6, c);
			a->setAutoRotate(true, 90);
			/*
			 * 如果不启用auto rotate, 可以指定pin point, 注意pin point只在auto rotate为false的时候生效
			 * 下面两句取消注释时必须把a->setAutoRotate(true, 90);注释掉才行
			 */
//	        a->setPinPoint(DP(100), wyDevice::winHeight - DP(100));
//	        a->setPinAngleDelta(90);
			wyAction* action = wyRepeatForever::make(a);
			r->runAction(action);
    	}

        virtual ~wyHypotrochoidTestLayer() {
        }

        virtual bool isGeometry() {
        	return true;
        }
	};

    /////////////////////////////////////////////////////////////////////////////////////////////////

    class wyLagrangeTestLayer : public wyActionTestLayer {
    private:
    	wyLagrangeConfig m_config;

    public:
    	wyLagrangeTestLayer() {
	        m_Sprite->setPosition(60, wyDevice::winHeight / 2);

	        m_config = wylcCubic(m_Sprite->getPositionX(),
	        		m_Sprite->getPositionY(),
	        		wyDevice::winWidth - 60,
	        		wyDevice::winHeight / 2,
	        		wyDevice::winWidth / 2,
	        		wyDevice::winHeight * 3 / 4,
	        		wyDevice::winWidth / 2,
	        		wyDevice::winHeight / 4);
            wyLagrange* a = wyLagrange::make(3, m_config);
			a->setAutoRotate(true, 90);
			/*
			 * 如果不启用auto rotate, 可以指定pin point, 注意pin point只在auto rotate为false的时候生效
			 * 下面两句取消注释时必须把a->setAutoRotate(true, 90);注释掉才行
			 */
//	        a->setPinPoint(DP(100), wyDevice::winHeight - DP(100));
//	        a->setPinAngleDelta(90);
            wyIntervalAction* t = wySequence::make(a,
            		(wyFiniteTimeAction*)a->reverse(),
            		NULL);

            wyAction* action = wyRepeatForever::make(t);
            m_Sprite->runAction(action);

            // material and mesh for lagrange curve drawing
            wyMaterial* m = wyMaterial::make(wyShaderManager::PROG_PC);
            wyShape* s = wyShape::make();
            s->buildLagrange(m_config, 30);
            s->updateColor(wyc4bGreen);
            addRenderPair(m, s);

            // mesh for lagrange control points
            s = wyShape::make();
            s->setPointSize(5);
            float p[] = {
                    m_config.startX, m_config.startY,
                    m_config.cp1X, m_config.cp1Y,
                    m_config.cp2X, m_config.cp2Y,
                    m_config.endX, m_config.endY
            };
            s->buildPoints(p, sizeof(p) / sizeof(float));
            s->updateColor(wyc4bRed);
            addRenderPair(m, s);
        }

        virtual ~wyLagrangeTestLayer() {
        }

        virtual bool isGeometry() {
        	return true;
        }
    };

    /////////////////////////////////////////////////////////////////////////////////////////////////

    class wyMoveByTestLayer : public wyActionTestLayer {
    public:
        wyMoveByTestLayer() {
        	reorderChild(m_Sprite, -1);
	        m_Sprite->setPosition(60, wyDevice::winHeight / 2);

	        wyMoveBy* mv = wyMoveBy::make(2, wyDevice::winWidth - 120, 0);
	        mv->setPinPoint(DP(100), wyDevice::winHeight - DP(100));
	        mv->setPinAngleDelta(90);
            wyIntervalAction* t = wySequence::make(mv, (wyFiniteTimeAction*)mv->reverse(), NULL);

            wyAction* action = wyRepeatForever::make(t);
            m_Sprite->runAction(action);

			// material and mesh for path
            wyMaterial* m = wyMaterial::make(wyShaderManager::PROG_PC);
        	wyPoint anchor = wyp(m_Sprite->getAnchorPointX(), m_Sprite->getAnchorPointY());
        	anchor = m_Sprite->nodeToWorldSpace(anchor);
        	wyShape* s = wyShape::make();
			s->buildDashLine(DP(100), wyDevice::winHeight - DP(100), anchor.x, anchor.y, 5);
			s->updateColor(wyc4bGreen);
			addRenderPair(m, s);

			// mesh for points
			s = wyShape::make();
			s->setPointSize(5);
			s->buildPoint(DP(100), wyDevice::winHeight - DP(100));
			s->updateColor(wyc4bRed);
			addRenderPair(m, s);
        }

        virtual ~wyMoveByTestLayer() {
        }

        virtual bool isGeometry() {
        	return true;
        }

        virtual void beforeRender() {
        	// update dash line
        	wyShape* s = (wyShape*)getMesh();
        	wyPoint anchor = wyp(m_Sprite->getAnchorPointX(), m_Sprite->getAnchorPointY());
        	anchor = m_Sprite->nodeToWorldSpace(anchor);
			s->buildDashLine(DP(100), wyDevice::winHeight - DP(100), anchor.x, anchor.y, 5);
			s->updateColor(wyc4bGreen);
        }
    };

    /////////////////////////////////////////////////////////////////////////////////////////////////

    class wyMoveByAngleTestLayer : public wyActionTestLayer {
    public:
    	wyMoveByAngleTestLayer() {
    		reorderChild(m_Sprite, -1);
			m_Sprite->setPosition(60, wyDevice::winHeight / 2);
			int velocity = (int)(wyDevice::winWidth - 60 * 2) / 2;

			wyMoveByAngle* a = wyMoveByAngle::make(2, 0, velocity);
	        a->setPinPoint(DP(100), wyDevice::winHeight - DP(100));
	        a->setPinAngleDelta(90);
			wyIntervalAction* t = wySequence::make(a, (wyMoveByAngle*)a->reverse(), NULL);

			wyAction* action = wyRepeatForever::make(t);
			m_Sprite->runAction(action);

			// material and mesh for path
			wyMaterial* m = wyMaterial::make(wyShaderManager::PROG_PC);
        	wyPoint anchor = wyp(m_Sprite->getAnchorPointX(), m_Sprite->getAnchorPointY());
        	anchor = m_Sprite->nodeToWorldSpace(anchor);
			wyShape* s = wyShape::make();
			s->buildDashLine(DP(100), wyDevice::winHeight - DP(100), anchor.x, anchor.y, 5);
			s->updateColor(wyc4bGreen);
			addRenderPair(m, s);

			// mesh for points
			s = wyShape::make();
			s->setPointSize(5);
			s->buildPoint(DP(100), wyDevice::winHeight - DP(100));
			s->updateColor(wyc4bRed);
			addRenderPair(m, s);
		}

        virtual ~wyMoveByAngleTestLayer() {
        }

        virtual bool isGeometry() {
        	return true;
        }

        virtual void beforeRender() {
        	// update dash line
        	wyShape* s = (wyShape*)getMesh();
        	wyPoint anchor = wyp(m_Sprite->getAnchorPointX(), m_Sprite->getAnchorPointY());
        	anchor = m_Sprite->nodeToWorldSpace(anchor);
			s->buildDashLine(DP(100), wyDevice::winHeight - DP(100), anchor.x, anchor.y, 5);
			s->updateColor(wyc4bGreen);
        }
	};

    /////////////////////////////////////////////////////////////////////////////////////////////////

    class wyMoveByPathTestLayer : public wyActionTestLayer {
    private:
    	wyMoveByPath* m_path;

    public:
    	wyMoveByPathTestLayer() {
    		m_Sprite->setPosition(DP(30), wyDevice::winHeight / 2);

    		wyMoveByPath* a = wyMoveByPath::make();
    		m_path = a;
			a->setAutoRotate(true, 90);
			/*
			 * 如果不启用auto rotate, 可以指定pin point, 注意pin point只在auto rotate为false的时候生效
			 * 下面两句取消注释时必须把a->setAutoRotate(true, 90);注释掉才行
			 */
//	        a->setPinPoint(DP(100), wyDevice::winHeight - DP(100));
//	        a->setPinAngleDelta(90);
			a->addPoint(DP(30), wyDevice::winHeight / 2, 0);
			a->addPoint(wyDevice::winWidth / 2, wyDevice::winHeight / 2, 0.5f);
			a->addPoint(wyDevice::winWidth / 2, wyDevice::winHeight - DP(30), 1.f);
			a->addPoint(wyDevice::winWidth - DP(30), wyDevice::winHeight - DP(30), 2.f);
			a->addPoint(wyDevice::winWidth - DP(30), DP(30), 3.f);
			wyIntervalAction* t = wySequence::make(a,
					(wyFiniteTimeAction*)a->reverse(),
					NULL);

			wyAction* action = wyRepeatForever::make(t);
			m_Sprite->runAction(action);

			// material and mesh for path
			wyMaterial* m = wyMaterial::make(wyShaderManager::PROG_PC);
			float p[] = {
					DP(30), wyDevice::winHeight / 2,
					wyDevice::winWidth / 2, wyDevice::winHeight / 2,
					wyDevice::winWidth / 2, wyDevice::winHeight - DP(30),
					wyDevice::winWidth - DP(30), wyDevice::winHeight - DP(30),
					wyDevice::winWidth - DP(30), DP(30)
			};
			wyShape* s = wyShape::make();
			s->buildDashPath(p, sizeof(p) / sizeof(float), 5);
			s->updateColor(wyc4bGreen);
			addRenderPair(m, s);

			// mesh for points
			s = wyShape::make();
			s->setPointSize(5);
			s->buildPoints(p, sizeof(p) / sizeof(float));
			s->updateColor(wyc4bRed);
			addRenderPair(m, s);
		}

        virtual ~wyMoveByPathTestLayer() {
        }

        virtual bool isGeometry() {
        	return true;
        }
	};

    /////////////////////////////////////////////////////////////////////////////////////////////////

    class wyMoveToTestLayer : public wyActionTestLayer {
    public:
        wyMoveToTestLayer(){
        	reorderChild(m_Sprite, -1);
	        m_Sprite->setPosition(60, wyDevice::winHeight / 2);

	        wyMoveTo* a = wyMoveTo::make(2, m_Sprite->getPositionX(), m_Sprite->getPositionY(),
	        		wyDevice::winWidth - 60, wyDevice::winHeight/2);
	        a->setPinPoint(DP(100), wyDevice::winHeight - DP(100));
	        a->setPinAngleDelta(90);
            wyIntervalAction* t = wySequence::make(a, (wyMoveTo*)a->reverse(), NULL);

            wyAction* action = wyRepeatForever::make(t);
            m_Sprite->runAction(action);
        }

        virtual void draw() {
			// TODO gles2
        	//// draw pin point
        	//glColor4f(1, 0, 0, 1);
        	//glPointSize(5);
        	//wyDrawPoint(DP(100), wyDevice::winHeight - DP(100));

        	//// draw anchor point
        	//wyPoint anchor = wyp(m_Sprite->getAnchorPointX(), m_Sprite->getAnchorPointY());
        	//anchor = m_Sprite->nodeToWorldSpace(anchor);
        	//wyDrawPoint(anchor.x, anchor.y);

        	//// draw line between pin point and anchor point
        	//glColor4f(0, 1, 0, 1);
        	//wyDrawDashLine(DP(100), wyDevice::winHeight - DP(100), anchor.x, anchor.y, 5);
        }
    };

    /////////////////////////////////////////////////////////////////////////////////////////////////

    class wyScaleByTestLayer : public wyActionTestLayer {
    public:
        wyScaleByTestLayer(){
            wyIntervalAction* a = wyScaleBy::make(2, 2);
            wyIntervalAction* t = wySequence::make(a,
            		(wyFiniteTimeAction*)a->reverse(),
            		NULL);

            wyAction* action = wyRepeatForever::make(t);
            m_Sprite->runAction(action);
        }
    };

    /////////////////////////////////////////////////////////////////////////////////////////////////

    class wyScaleToTestLayer : public wyActionTestLayer {
    public:
        wyScaleToTestLayer(){
            wyIntervalAction* a = wyScaleTo::make(2, 1.0f, 0.0f);
            wyIntervalAction* t = wySequence::make(a,
            		(wyFiniteTimeAction*)a->reverse(),
            		NULL);

            wyAction* action = wyRepeatForever::make(t);
            m_Sprite->runAction(action);
        }
    };

    /////////////////////////////////////////////////////////////////////////////////////////////////

    class wyShakeTestLayer : public wyActionTestLayer {
    public:
    	wyShakeTestLayer() {
            wyIntervalAction* a = wyShake::make(5, 10);
            m_Sprite->runAction(a);
        }
    };

    /////////////////////////////////////////////////////////////////////////////////////////////////

    class wySkewByTestLayer : public wyActionTestLayer {
    public:
    	wySkewByTestLayer() {
    		wySkewBy* a1 = wySkewBy::make(2, 90, 0);
            wySkewBy* a2 = (wySkewBy*)a1->reverse();
            wySkewBy* a3 = wySkewBy::make(2, 0, 90);
            wySkewBy* a4 = (wySkewBy*)a3->reverse();
            m_Sprite->runAction(wyRepeatForever::make(wySequence::make(a1, a2, a3, a4, NULL)));
        }
    };

    /////////////////////////////////////////////////////////////////////////////////////////////////

    class wySkewToTestLayer : public wyActionTestLayer {
    public:
    	wySkewToTestLayer() {
            wySkewTo* a1 = wySkewTo::make(2, 0, 90, 0, 0);
            wySkewTo* a2 = (wySkewTo*)a1->reverse();
            wySkewTo* a3 = wySkewTo::make(2, 0, 0, 0, 90);
            wySkewTo* a4 = (wySkewTo*)a3->reverse();
            m_Sprite->runAction(wyRepeatForever::make(wySequence::make(a1, a2, a3, a4, NULL)));
        }
    };

    /////////////////////////////////////////////////////////////////////////////////////////////////

    class wyRotateByTestLayer : public wyActionTestLayer {
    public:
        wyRotateByTestLayer() {
            wyIntervalAction* rotate = wyRotateBy::make(2, 360);
            wyAction* action = wyRepeatForever::make(rotate);
            m_Sprite->runAction(action);
        }
    };

    /////////////////////////////////////////////////////////////////////////////////////////////////

    class wyRotateToTestLayer : public wyActionTestLayer {
    public:
        wyRotateToTestLayer() {
            wyIntervalAction* rotate = wyRotateTo::make(2, 0, 360);
            wyAction* action = wyRepeatForever::make(rotate);
            m_Sprite->runAction(action);
        }
    };

    /////////////////////////////////////////////////////////////////////////////////////////////////

    class wyPauseResumeActionTestLayer : public wyActionTestLayer {
    public:
    	wyPauseResumeActionTestLayer() {
    		/*
    		 * 我们同时在sprite上运行两个动作, 点击屏幕时暂停旋转动作, 再点击恢复
    		 * 为什么不用wySpawn来包装两个动作呢? 因为暂停动作对于组合类中的动作
    		 * 是无效的
    		 */

    		// run a rotate action
            wyIntervalAction* rotate = wyRotateBy::make(2, 360);
            wyAction* action1 = wyRepeatForever::make(rotate);
			action1->setTag(100); // for pause action, assign a tag to action
            m_Sprite->runAction(action1);

            // run a move action
	        wyMoveBy* m = wyMoveBy::make(2, wyDevice::winWidth - 120, 0);
            wyIntervalAction* t = wySequence::make(m, (wyMoveBy*)m->reverse(), NULL);
            wyAction* action2 = wyRepeatForever::make(t);
	        m_Sprite->setPosition(60, wyDevice::winHeight / 2);
            m_Sprite->runAction(action2);

            // enable touch
            setTouchEnabled(true);
        }

    	virtual ~wyPauseResumeActionTestLayer() {
    	}

    	virtual bool touchesBegan(wyMotionEvent& e) {
    		wyAction* action = m_Sprite->getAction(100);
    		if(action->isPaused())
    			m_Sprite->resumeAction(100);
    		else
    			m_Sprite->pauseAction(100);

    		return true;
    	}
    };

    /////////////////////////////////////////////////////////////////////////////////////////////////

    class wyProgressByTestLayer : public wyLayer {
    private:
    	float ITEM_WIDTH;
    	float ITEM_HEIGHT;

    public:
        wyProgressByTestLayer(){
        	wyProgressTimer* left = wyProgressTimer::make(wyTexture2D::makePNG(RES("R.drawable.grossini")));
            left->setStyle(RADIAL_CW);
        	left->setPosition(100, wyDevice::winHeight / 2);
        	wyProgressBy* action = wyProgressBy::make(2, 100);
        	addChildLocked(left);
        	left->runAction(action);

    		ITEM_WIDTH = 85;
    		ITEM_HEIGHT = 121;
    		int idx = rand() % 14;
    		float x = (idx % 5) * ITEM_WIDTH;
    		float y = (idx / 5) * ITEM_HEIGHT;
    		wyTexture2D* tex = wyTexture2D::makePNG(RES("R.drawable.grossini_dance_atlas"));
    		wySprite* sprite = wySprite::make(tex, wyUtils::resolveRect(wyr(x, y, ITEM_WIDTH, ITEM_HEIGHT)));
    		wyProgressTimer* right = wyProgressTimer::make(sprite);
            right->setStyle(VERTICAL_BAR_BT);
        	right->setPosition(wyDevice::winWidth - 100, wyDevice::winHeight / 2);
        	action = wyProgressBy::make(2, 100);
        	addChildLocked(right);
        	right->runAction(action);
        }
    };

    /////////////////////////////////////////////////////////////////////////////////////////////////

    class wyProgressToTestLayer : public wyLayer {
    private:
    	float ITEM_WIDTH;
    	float ITEM_HEIGHT;

    public:
        wyProgressToTestLayer(){
        	wyProgressTimer* left = wyProgressTimer::make(wyTexture2D::makePNG(RES("R.drawable.grossini")));
            left->setStyle(RADIAL_CW);
        	left->setPosition(100, wyDevice::winHeight / 2);
        	wyProgressTo* action = wyProgressTo::make(2, 0, 100);
        	wyRepeatForever* r = wyRepeatForever::make(action);
        	left->runAction(r);
        	addChildLocked(left);
            
    		ITEM_WIDTH = 85;
    		ITEM_HEIGHT = 121;
    		int idx = rand() % 14;
    		float x = (idx % 5) * ITEM_WIDTH;
    		float y = (idx / 5) * ITEM_HEIGHT;
    		wyTexture2D* tex = wyTexture2D::makePNG(RES("R.drawable.grossini_dance_atlas"));
    		wySprite* sprite = wySprite::make(tex, wyUtils::resolveRect(wyr(x, y, ITEM_WIDTH, ITEM_HEIGHT)));
    		wyProgressTimer* right = wyProgressTimer::make(sprite);
            right->setStyle(VERTICAL_BAR_BT);
        	right->setPosition(wyDevice::winWidth - 100, wyDevice::winHeight / 2);
        	action = wyProgressTo::make(2, 0, 100);
        	r = wyRepeatForever::make(action);
        	addChildLocked(right);
        	right->runAction(action);
        };
    };

    /////////////////////////////////////////////////////////////////////////////////////////////////

    class wyTintByTestLayer : public wyActionTestLayer {
    public:
        wyTintByTestLayer(){
            wyIntervalAction* a = wyTintBy::make(2, 255, 0, 0);
            wyIntervalAction* t = wySequence::make(a,
            		(wyFiniteTimeAction*)a->reverse(),
            		NULL);

            wyAction* action = wyRepeatForever::make(t);
            m_Sprite->runAction(action);
        };
    };

    /////////////////////////////////////////////////////////////////////////////////////////////////

    class wyTintToTestLayer : public wyActionTestLayer {
    public:
        wyTintToTestLayer(){
            wyIntervalAction* a = wyTintTo::make(2, 255, 0, 0, 0, 0, 255);
            wyIntervalAction* t = wySequence::make(a,
            		(wyFiniteTimeAction*)a->reverse(),
            		NULL);

            wyAction* action = wyRepeatForever::make(t);
            m_Sprite->runAction(action);
        };
    };

    /////////////////////////////////////////////////////////////////////////////////////////////////

    class wyOrbitCameraFlipXTestLayer : public wyActionTestLayer {
    public:
        wyOrbitCameraFlipXTestLayer() {
        	m_Sprite->setScale(4);

            wyIntervalAction* action = wyOrbitCamera::make(3, 1, 0, 0, 360, 0, 0);
            m_Sprite->runAction(action);

        	wySprite* bg = wySprite::make(wyTexture2D::makePNG(RES("R.drawable.background")));
        	bg->setPosition(wyDevice::winWidth / 2, wyDevice::winHeight / 2);
        	addChildLocked(bg, -1);
        };
    };

    /////////////////////////////////////////////////////////////////////////////////////////////////

    class wyBezierTestLayer : public wyActionTestLayer {
    private:
    	wyBezierConfig m_config;

    public:
        wyBezierTestLayer() {
	        m_Sprite->setPosition(60, wyDevice::winHeight / 2);

	        m_config = wybcCubic(m_Sprite->getPositionX(),
	        		m_Sprite->getPositionY(),
	        		wyDevice::winWidth - 60,
	        		wyDevice::winHeight / 2,
	        		wyDevice::winWidth / 2,
	        		wyDevice::winHeight * 3 / 4,
	        		wyDevice::winWidth / 2,
	        		wyDevice::winHeight / 4);
	        wyBezier* a = wyBezier::make(3, m_config);
	        a->setAutoRotate(true, 90);
			/*
			 * 如果不启用auto rotate, 可以指定pin point, 注意pin point只在auto rotate为false的时候生效
			 * 下面两句取消注释时必须把a->setAutoRotate(true, 90);注释掉才行
			 */
//	        a->setPinPoint(DP(100), wyDevice::winHeight - DP(100));
//	        a->setPinAngleDelta(90);
            wyIntervalAction* t = wySequence::make(a,
            		(wyFiniteTimeAction*)a->reverse(),
            		NULL);
    
            wyAction* action = wyRepeatForever::make(t);
            m_Sprite->runAction(action);

            // material and mesh for bezier curve drawing
            wyMaterial* m = wyMaterial::make(wyShaderManager::PROG_PC);
            wyShape* s = wyShape::make();
            s->buildBezier(m_config, 30);
            s->updateColor(wyc4bGreen);
            addRenderPair(m, s);

            // mesh for bezier control points
            s = wyShape::make();
            s->setPointSize(5);
            float p[] = {
                    m_config.startX, m_config.startY,
                    m_config.cp1X, m_config.cp1Y,
                    m_config.cp2X, m_config.cp2Y,
                    m_config.endX, m_config.endY
            };
            s->buildPoints(p, sizeof(p) / sizeof(float));
            s->updateColor(wyc4bRed);
            addRenderPair(m, s);
        }

        virtual ~wyBezierTestLayer() {
        }

        virtual bool isGeometry() {
        	return true;
        }
    };
    
    /////////////////////////////////////////////////////////////////////////////////////////////////
}

using namespace Action;

#if ANDROID
	#define DEMO_ENTRY_IMPL(CLASSNAME) JNIEXPORT void JNICALL Java_com_wiyun_engine_tests_action_##CLASSNAME##_nativeStart \
		(JNIEnv *env, jobject thiz){ \
			wyLayer* layer = new wy##CLASSNAME##Layer(); \
			runDemo(layer, NULL); \
			wyObjectRelease(layer); \
		}
#elif IOS || MACOSX || WINDOWS
	#define DEMO_ENTRY_IMPL(CLASSNAME) void _action_##CLASSNAME##Launcher() { \
			wyLayer* layer = new wy##CLASSNAME##Layer(); \
			runDemo(layer, NULL); \
			wyObjectRelease(layer); \
		}
#endif

DEMO_ENTRY_IMPL(AnimationTest);
DEMO_ENTRY_IMPL(AtlasAnimationTest);
DEMO_ENTRY_IMPL(BezierTest);
DEMO_ENTRY_IMPL(BlinkTest);
DEMO_ENTRY_IMPL(CallFuncTest);
DEMO_ENTRY_IMPL(ClipInOutTest);
DEMO_ENTRY_IMPL(DelayShowHideTest);
DEMO_ENTRY_IMPL(FadeInOutTest);
DEMO_ENTRY_IMPL(FadeToTest);
DEMO_ENTRY_IMPL(FollowTest);
DEMO_ENTRY_IMPL(JumpByTest);
DEMO_ENTRY_IMPL(JumpToTest);
DEMO_ENTRY_IMPL(HypotrochoidTest);
DEMO_ENTRY_IMPL(LagrangeTest);
DEMO_ENTRY_IMPL(MoveByTest);
DEMO_ENTRY_IMPL(MoveByAngleTest);
DEMO_ENTRY_IMPL(MoveByPathTest);
DEMO_ENTRY_IMPL(MoveToTest);
DEMO_ENTRY_IMPL(OrbitCameraFlipXTest);
DEMO_ENTRY_IMPL(PauseResumeActionTest);
DEMO_ENTRY_IMPL(ProgressByTest);
DEMO_ENTRY_IMPL(ProgressToTest);
DEMO_ENTRY_IMPL(RotateByTest);
DEMO_ENTRY_IMPL(RotateToTest);
DEMO_ENTRY_IMPL(ScaleByTest);
DEMO_ENTRY_IMPL(ScaleToTest);
DEMO_ENTRY_IMPL(ShakeTest);
DEMO_ENTRY_IMPL(SkewByTest);
DEMO_ENTRY_IMPL(SkewToTest);
DEMO_ENTRY_IMPL(TintByTest);
DEMO_ENTRY_IMPL(TintToTest);
