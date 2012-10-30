#include "common.h"
#include "NodeDemos.h"
#include "WiEngine.h"
#include "WiEngine-Box2D.h"
#include <stdio.h>
#include "wyLog.h"

namespace Node {

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

///////////////////////////////////////////////////////////////////////////////

class wyNodeTestLayer: public wyLayer {
public:
	wyNodeTestLayer() {
		setTouchEnabled(true);
	}

	virtual ~wyNodeTestLayer() {
	}

	wyPoint getLocation(wyMotionEvent event) {
		wyPoint loc = wyp(event.x[0], event.y[0]);
		return loc;
	}
};

///////////////////////////////////////////////////////////////////////////////

class wyTilemapTestLayer: public wyNodeTestLayer {
protected:
	wyNode* m_tilemap;

	float m_LastX;
	float m_LastY;

	bool m_hasViewport;

public:
	wyTilemapTestLayer() : m_hasViewport(false) {
		m_tilemap = NULL;

		// a button used to switch clip
		wyNinePatchSprite* normal = wyNinePatchSprite::make(wyTexture2D::makePNG(RES("R.drawable.btn_normal")), wyr(DP(9), DP(7), DP(22), DP(28)));
		wyNinePatchSprite* pressed = wyNinePatchSprite::make(wyTexture2D::makePNG(RES("R.drawable.btn_pressed")), wyr(DP(9), DP(7), DP(22), DP(28)));
		normal->setContentSize(DP(200), DP(44));
		pressed->setContentSize(DP(200), DP(44));
		wyButton* button = new wyButton(normal, pressed, NULL, NULL, NULL,
				wyTargetSelector::make(this, SEL(wyTilemapTestLayer::onChangeViewport)));
		button->setPosition(wyDevice::winWidth / 2, wyDevice::winHeight - DP(30));
		addChildLocked(button, 1);
		button->release();

		// label for button
		wyBitmapFont* font = wyBitmapFont::loadFont(RES("R.raw.bitmapfont"));
        wyBitmapFontLabel* label = wyBitmapFontLabel::make(font, "Switch Clip");
        label->setColor(wyc3b(255, 255, 0));
        label->setPosition(wyDevice::winWidth / 2, wyDevice::winHeight - DP(30));
		addChildLocked(label, 1);

		// add render pair of clip rect bound
		wyShape* s = wyShape::make();
		s->buildRect(50, 50, wyDevice::winWidth - 100, wyDevice::winWidth - 100);
		s->updateColor(wyc4bGreen);
		wyMaterial* m = wyMaterial::make(wyShaderManager::PROG_PC);
		addRenderPair(m, s);

		// now no viewport, so no draw
		setNoDraw(true);
	}

	virtual ~wyTilemapTestLayer() {
	}

	virtual bool touchesBegan(wyMotionEvent& event) {
		wyPoint location = getLocation(event);
		m_LastX = location.x;
		m_LastY = location.y;
		return true;
	}

	virtual bool touchesMoved(wyMotionEvent& event) {
		wyPoint location = getLocation(event);
		float x = location.x;
		float y = location.y;
		float deltaX = x - m_LastX;
		float deltaY = y - m_LastY;
		m_LastX = x;
		m_LastY = y;

		m_tilemap->translate(deltaX, deltaY);
		return true;
	}

	void onChangeViewport(wyTargetSelector* ts) {
		m_hasViewport = !m_hasViewport;
		if(m_hasViewport) {
			m_tilemap->setClipRect(wyr(50, 50, wyDevice::winWidth - 100, wyDevice::winWidth - 100));
			setNoDraw(false);
		} else {
			m_tilemap->clearClipRect();
			setNoDraw(true);
		}
	}
};

///////////////////////////////////////////////////////////////////////////////

class wyArcticTestLayer: public wyLayer {
private:
	wyArcticSprite* m_sprite1;
	wyArcticSprite* m_sprite2;
	wyArcticSprite* m_sprite3;

public:
	wyArcticTestLayer() {
		// texture
		wyTexture2D* tex1 = wyTexture2D::makePNG(RES("R.drawable.fighterboby001"));
		wyTexture2D* tex2 = wyTexture2D::makePNG(RES("R.drawable.fighterarmor001"));
		wyTexture2D* tex3 = wyTexture2D::makePNG(RES("R.drawable.fighterweapon001"));

		// animation 1
		m_sprite1 = wyArcticSprite::make(RES("R.raw.fighter"), 0, tex1, tex2, tex3, NULL);
		m_sprite1->setLoopCount(-1);
		m_sprite1->setPosition(wyDevice::winWidth / 2, wyDevice::winHeight * 3 / 4);
		m_sprite1->setUnitInterval(0.1f);
		m_sprite1->setDebugDrawFrameRect(true);
		m_sprite1->setDebugDrawCollisionRect(true);
		addChildLocked(m_sprite1);

		// animation 2
		m_sprite2 = wyArcticSprite::make(RES("R.raw.fighter"), 1, tex1, tex2, tex3, NULL);
		m_sprite2->setLoopCount(-1);
		m_sprite2->setPosition(wyDevice::winWidth / 2, wyDevice::winHeight / 2);
		m_sprite2->setUnitInterval(0.1f);
		m_sprite2->setDebugDrawFrameRect(true);
		m_sprite2->setDebugDrawCollisionRect(true);
		addChildLocked(m_sprite2);

		// animation 3
		m_sprite3 = wyArcticSprite::make(RES("R.raw.fighter"), 2, tex1, tex2, tex3, NULL);
		m_sprite3->setLoopCount(-1);
		m_sprite3->setPosition(wyDevice::winWidth / 2, wyDevice::winHeight / 4);
		m_sprite3->setUnitInterval(0.1f);
		m_sprite3->setDebugDrawFrameRect(true);
		m_sprite3->setDebugDrawCollisionRect(true);
		addChildLocked(m_sprite3);

		// start to update
		wyTimer* timer = wyTimer::make(wyTargetSelector::make(this, SEL(wyArcticTestLayer::onUpdateSprite)));
		scheduleLocked(timer);

		setTouchEnabled(true);
	}

	virtual ~wyArcticTestLayer() {
	}

	virtual bool touchesBegan(wyMotionEvent& event) {
		m_sprite1->setPaused(!m_sprite1->isPaused());
		m_sprite2->setPaused(!m_sprite2->isPaused());
		m_sprite3->setPaused(!m_sprite3->isPaused());
		return true;
	}

	void onUpdateSprite(wyTargetSelector* ts) {
		m_sprite1->tick(ts->getDelta());
		m_sprite2->tick(ts->getDelta());
		m_sprite3->tick(ts->getDelta());
	}
};

///////////////////////////////////////////////////////////////////////////////

class wyAuroraGTTestLayer: public wyLayer {
private:
	wyAuroraSprite* m_sprite1;
	wyAuroraSprite* m_sprite2;
	wyAuroraSprite* m_sprite3;

public:
	wyAuroraGTTestLayer() {
		/*
		 * Here we specified a transparent color for this texture
		 */
		wyTexture2D* tex = wyTexture2D::makeBMP(RES("R.drawable.prince"), 0x00ff00ff);

		// animation 1
		m_sprite1 = wyAuroraSprite::make(RES("R.raw.prince"), 78, tex, NULL);
		m_sprite1->setLoopCount(-1);
		m_sprite1->setPosition(wyDevice::winWidth / 2, wyDevice::winHeight * 3 / 4);
		m_sprite1->setUnitInterval(0.1f);
		m_sprite1->setDebugDrawFrameRect(true);
		m_sprite1->setDebugDrawCollisionRect(true);
		addChildLocked(m_sprite1);

		// animation 2
		m_sprite2 = wyAuroraSprite::make(RES("R.raw.prince"), 99, tex, NULL);
		m_sprite2->setLoopCount(-1);
		m_sprite2->setPosition(wyDevice::winWidth / 2, wyDevice::winHeight / 2);
		m_sprite2->setUnitInterval(0.1f);
		m_sprite2->setDebugDrawFrameRect(true);
		m_sprite2->setDebugDrawCollisionRect(true);
		addChildLocked(m_sprite2);

		// animation 3
		m_sprite3 = wyAuroraSprite::make(RES("R.raw.prince"), 66, tex, NULL);
		m_sprite3->setLoopCount(-1);
		m_sprite3->setPosition(wyDevice::winWidth / 2, wyDevice::winHeight / 4);
		m_sprite3->setUnitInterval(0.1f);
		m_sprite3->setDebugDrawFrameRect(true);
		m_sprite3->setDebugDrawCollisionRect(true);
		addChildLocked(m_sprite3);

		// start to update
		wyTimer* timer = wyTimer::make(wyTargetSelector::make(this, SEL(wyAuroraGTTestLayer::onUpdateSprite)));
		scheduleLocked(timer);

		setTouchEnabled(true);
	}

	virtual ~wyAuroraGTTestLayer() {
	}

	virtual bool touchesBegan(wyMotionEvent& event) {
		m_sprite1->setPaused(!m_sprite1->isPaused());
		m_sprite2->setPaused(!m_sprite2->isPaused());
		m_sprite3->setPaused(!m_sprite3->isPaused());
		return true;
	}

	void onUpdateSprite(wyTargetSelector* ts) {
		m_sprite1->tick(ts->getDelta());
		m_sprite2->tick(ts->getDelta());
		m_sprite3->tick(ts->getDelta());
	}
};

///////////////////////////////////////////////////////////////////////////////

class wyClipMappingAuroraGTTestLayer: public wyLayer {
private:
	wyAuroraSprite* m_sprite1;
	int m_nextMapping;

public:
	wyClipMappingAuroraGTTestLayer() {
		m_nextMapping = 1;

		/*
		 * Here we specified a transparent color for this texture
		 */
		wyTexture2D* tex = wyTexture2D::makeBMP(RES("R.drawable.prince"), 0x00ff00ff);

		// animation 1
		m_sprite1 = wyAuroraSprite::make(RES("R.raw.prince"), 78, tex, NULL);
		m_sprite1->setLoopCount(-1);
		m_sprite1->setPosition(wyDevice::winWidth / 2, wyDevice::winHeight / 2);
		m_sprite1->setUnitInterval(0.1f);
		m_sprite1->setDebugDrawFrameRect(true);
		m_sprite1->setDebugDrawCollisionRect(true);
		addChildLocked(m_sprite1);

		// create clip mapping and add them to sprite
		wyAFCClipMapping* mapping = wyAFCClipMapping::makeAurora(1, RES("R.raw.prince_m00"));
		m_sprite1->addClipMapping(mapping);
		mapping = wyAFCClipMapping::makeAurora(2, RES("R.raw.prince_m01"));
		m_sprite1->addClipMapping(mapping);
		mapping = wyAFCClipMapping::makeAurora(3, RES("R.raw.prince_m02"));
		m_sprite1->addClipMapping(mapping);
		mapping = wyAFCClipMapping::makeAurora(4, RES("R.raw.prince_m03"));
		m_sprite1->addClipMapping(mapping);
		mapping = wyAFCClipMapping::makeAurora(5, RES("R.raw.prince_m04"));
		m_sprite1->addClipMapping(mapping);
		mapping = wyAFCClipMapping::makeAurora(6, RES("R.raw.prince_m05"));
		m_sprite1->addClipMapping(mapping);
		mapping = wyAFCClipMapping::makeAurora(7, RES("R.raw.prince_m06"));
		m_sprite1->addClipMapping(mapping);
		mapping = wyAFCClipMapping::makeAurora(8, RES("R.raw.prince_m07"));
		m_sprite1->addClipMapping(mapping);

		// sprite for button
		wyNinePatchSprite* normal = wyNinePatchSprite::make(wyTexture2D::makePNG(RES("R.drawable.btn_normal")), wyr(DP(9), DP(7), DP(22), DP(28)));
		wyNinePatchSprite* pressed = wyNinePatchSprite::make(wyTexture2D::makePNG(RES("R.drawable.btn_pressed")), wyr(DP(9), DP(7), DP(22), DP(28)));
		normal->setContentSize(DP(300), DP(44));
		pressed->setContentSize(DP(300), DP(44));

		// button 1
		wyButton* button = wyButton::make(normal, pressed, NULL, NULL, NULL,
				wyTargetSelector::make(this, SEL(wyClipMappingAuroraGTTestLayer::onSwitchClipMapping)));
		button->setPosition(wyDevice::winWidth / 2, DP(70));

		// label for button 1
		wyBitmapFont* font = wyBitmapFont::loadFont(RES("R.raw.bitmapfont"));
        wyBitmapFontLabel* label = wyBitmapFontLabel::make(font, "Switch Clip Mapping");
        label->setColor(wyc3b(255, 255, 0));
        label->setPosition(wyDevice::winWidth / 2, DP(70));

		// add button
		addChildLocked(button);
        addChildLocked(label);

		// start to update
		wyTimer* timer = wyTimer::make(wyTargetSelector::make(this, SEL(wyClipMappingAuroraGTTestLayer::onUpdateSprite)));
		scheduleLocked(timer);

		setTouchEnabled(true);
	}

	virtual ~wyClipMappingAuroraGTTestLayer() {
	}

	virtual bool touchesBegan(wyMotionEvent& event) {
		m_sprite1->setPaused(!m_sprite1->isPaused());
		return true;
	}

	void onUpdateSprite(wyTargetSelector* ts) {
		m_sprite1->tick(ts->getDelta());
	}

	void onSwitchClipMapping(wyTargetSelector* ts) {
		switch(m_nextMapping) {
			case 0:
				m_sprite1->playAnimation(78);
				break;
			default:
				m_sprite1->playAnimation(78, m_nextMapping);
				break;
		}

		m_nextMapping++;
		m_nextMapping %= 9;
	}
};

///////////////////////////////////////////////////////////////////////////////

class wyArrayTileMapAtlasTestLayer: public wyTilemapTestLayer {
public:
	wyArrayTileMapAtlasTestLayer() {
		// init tile values
		int tiles[20][20];
		memset(&tiles, 0, sizeof(tiles));

		for(int x = 0; x < 20; x++) {
			tiles[x][0] = 1;
			tiles[x][19] = 1;
		}
		for(int y = 0; y < 20; y++) {
			tiles[0][y] = 1;
			tiles[19][y] = 1;
		}
		for(int x = 1; x < 19; x++) {
			tiles[x][1] = 121;
			tiles[x][18] = 121;
		}
		for(int y = 1; y < 19; y++) {
			tiles[1][y] = 121;
			tiles[18][y] = 121;
		}

		// create tile map
		wyArrayTileMapAtlas* tilemap = wyArrayTileMapAtlas::make(wyTexture2D::makePNG(RES("R.drawable.tiles")),
				DP(16), DP(16), 20, 20, &(tiles[0][0]));
		tilemap->getTexture()->setAntiAlias(false);

		// add tile map as child
		addChildLocked(tilemap, -1);
		m_tilemap = tilemap;
	}

	virtual ~wyArrayTileMapAtlasTestLayer() {
	}
};

class wyAtlasButtonTestLayer: public wyLayer {
public:
	wyAtlasButtonTestLayer() {
		// create sprites
        wyTexture2D* tex = wyTexture2D::makePNG(RES("R.drawable.menuitemsprite"));
		wySprite* spriteNormal = new wySprite(tex, wyUtils::resolveRect(wyr(0, 23 * 2, 115, 23)));
		wySprite* spriteSelected = new wySprite(tex, wyUtils::resolveRect(wyr(0, 23 * 1, 115, 23)));
		wySprite* spriteDisabled = new wySprite(tex, wyUtils::resolveRect(wyr(0, 23 * 0, 115, 23)));

		// create atlas button
		wyButton* button = new wyButton(spriteNormal, spriteSelected, spriteDisabled, NULL, NULL,
				wyTargetSelector::make(this, SEL(wyAtlasButtonTestLayer::onButtonClicked)));
		button->setPosition(wyDevice::winWidth / 2, wyDevice::winHeight / 2);
		button->setClickScale(1.4f);
		addChildLocked(button);

		wyObjectRelease(button);
		wyObjectRelease(spriteNormal);
		wyObjectRelease(spriteSelected);
		wyObjectRelease(spriteDisabled);
	}

	virtual ~wyAtlasButtonTestLayer() {
	}

	void onButtonClicked(wyTargetSelector* ts) {
		wyToast::make("button clicked", 3.0f)->show();
	}
};

///////////////////////////////////////////////////////////////////////////////

class wyAtlasLabelTestLayer: public wyLayer {
private:
	wyAtlasLabel* label[3];
	int count;

public:
	wyAtlasLabelTestLayer() :
			count(0) {
		wyCharMap* map = new wyCharMap();
		map->autoRelease();
		map->mapChar(wyr(0, 0, DP(20), DP(25)), '0');
		map->mapChar(wyr(DP(20), 0, DP(10), DP(25)), '1');
		map->mapChar(wyr(DP(30), 0, DP(21), DP(25)), '2');
		map->mapChar(wyr(DP(51), 0, DP(21), DP(25)), '3');
		map->mapChar(wyr(DP(72), 0, DP(21), DP(25)), '4');
		map->mapChar(wyr(DP(93), 0, DP(21), DP(25)), '5');
		map->mapChar(wyr(DP(114), 0, DP(21), DP(25)), '6');
		map->mapChar(wyr(DP(135), 0, DP(21), DP(25)), '7');
		map->mapChar(wyr(DP(156), 0, DP(21), DP(25)), '8');
		map->mapChar(wyr(DP(177), 0, DP(21), DP(25)), '9');

		// The size of the texture should be a power of 2
		wyTexture2D* texture = wyTexture2D::makePNG(RES("R.drawable.number"));
		label[0] = new wyAtlasLabel("1", texture, map);
		label[0]->setAnchor(0, 0);
		label[0]->setPosition(10, DP(100));
		addChildLocked(label[0]);

		label[1] = new wyAtlasLabel("1", texture, map);
		label[1]->setColor(wyc3b(255, 0, 0));
		label[1]->setAnchor(0, 0);
		label[1]->setPosition(10, DP(200));
		addChildLocked(label[1]);

		label[2] = new wyAtlasLabel("1", texture, map);	
		label[2]->setColor(wyc3b(0, 255, 0));
		label[2]->setAnchor(0, 0);
		label[2]->setPosition(10, DP(300));
		addChildLocked(label[2]);

		/*
		 * 演示中文映射, 这里直接用中文字符的utf-8编码进行映射.
		 * 如果不用utf-8编码的数字, 直接就写中文字符, 其实编译也可以通过!!! 只不过会有
		 * "multi-character character constant"的警告, 但是编译后还是可以正常使用.
		 *
		 * 根据c标准的解释, 使用如下的形式:
		 * int c = '微';
		 * 其实是可以的, 只不过这个是实现相关的, 不能保证在所有编译器上都能用. 但是至少
		 * android ndk看起来支持这样用. 不过为了减少警告, 还是用utf-8编码直接代替了.
		 */
		map = new wyCharMap();
		map->autoRelease();
		map->mapChar(wyr(DP(1), DP(1), DP(21), DP(21)), 0xe5beae /* '微' */, 0, DP(-1));
    	map->mapChar(wyr(DP(23), DP(1), DP(18), DP(21)), 0xe4ba91 /* '云' */, DP(1), DP(1));
    	map->mapChar(wyr(DP(42), DP(1), DP(18), DP(21)), 0xe6b8b8 /* '游' */, DP(1), DP(1));
    	map->mapChar(wyr(DP(61), DP(1), DP(20), DP(21)), 0xe6888f /* '戏' */);
    	map->mapChar(wyr(DP(82), DP(1), DP(14), DP(21)), 0xe5bc95 /* '引' */, DP(3), DP(3));
    	map->mapChar(wyr(DP(97), DP(1), DP(17), DP(21)), 0xe6938e /* '擎' */, DP(2), DP(1));
		texture = wyTexture2D::makePNG(RES("R.drawable.bitmapfont"));
		const char* s = wyUtils::wctoutf8(L"微云 游戏\t引擎微\n云游戏引擎");
		wyAtlasLabel* chinese = new wyAtlasLabel(s, texture, map);
		chinese->setAnchor(0, 0);
		chinese->setPosition(10, DP(350));
		chinese->setAlignment(wyAtlasLabel::RIGHT);
		addChildLocked(chinese);
		chinese->release();
		wyFree((void*)s);

		wyTimer* timer = new wyTimer(wyTargetSelector::make(this, SEL(wyAtlasLabelTestLayer::onUpdateLabel)));
		scheduleLocked(timer);
		wyObjectRelease(timer);
	}

	virtual ~wyAtlasLabelTestLayer() {
		wyObjectRelease(label[0]);
		wyObjectRelease(label[1]);
		wyObjectRelease(label[2]);
	}

	void onUpdateLabel(wyTargetSelector* ts) {
		step(ts->getDelta());
	}

	void step(float dt) {
		count++;
		char buf[32];
		sprintf(buf, "%d", count);
		label[0]->setText(buf);
		label[1]->setText(buf);
		label[2]->setText(buf);
	}
};

///////////////////////////////////////////////////////////////////////////////

class wyAtlasSpriteTestLayer: public wyNodeTestLayer {
private:
	float ITEM_WIDTH;
	float ITEM_HEIGHT;
    wyTexture2D* m_tex;
public:
	wyAtlasSpriteTestLayer() {
		// set width and height
		ITEM_WIDTH = 85;
		ITEM_HEIGHT = 121;

        m_tex = wyTexture2D::makePNG(RES("R.drawable.grossini_dance_atlas"));
		addNewSprite(wyDevice::winWidth / 2, wyDevice::winHeight / 2);
		m_tex->retain();
	}

	virtual ~wyAtlasSpriteTestLayer() {
		m_tex->release();
	}

	virtual bool touchesBegan(wyMotionEvent& event) {
		wyPoint location = getLocation(event);
		addNewSprite(location.x, location.y);
		return true;
	}

	void addNewSprite(float posx, float posy) {
		int idx = rand() % 14;
		float x = (idx % 5) * ITEM_WIDTH;
		float y = (idx / 5) * ITEM_HEIGHT;
		wySprite* sprite = new wySprite(m_tex, wyUtils::resolveRect(wyr(x, y, ITEM_WIDTH, ITEM_HEIGHT)));
		sprite->setFlipX(rand() % 2);
		sprite->setFlipY(rand() % 2);
		sprite->setRotation(rand() % 360);
		sprite->setPosition(posx, posy);
		addChildLocked(sprite);
		wyObjectRelease(sprite);
	}
};

///////////////////////////////////////////////////////////////////////////////

class wyButtonTestLayer: public wyLayer {
public:
	wyButtonTestLayer() {
		wySprite* normal = wySprite::make(wyTexture2D::makePNG(RES("R.drawable.btn_send_score_normal")));
		wySprite* pressed = wySprite::make(wyTexture2D::makePNG(RES("R.drawable.btn_send_score_pressed")));

		/*
		 * targetselector也是可以指定一个类的任意方法的, 用法如下, 用SEL宏, 传入这个方法的指针, targetselector第一次
		 * 参数this说明了onButton方法定义在this中.
		 */
		wyButton* button = wyButton::make(normal, pressed, NULL, NULL, NULL, wyTargetSelector::make(this, SEL(wyButtonTestLayer::onButton)));

		button->setClickScale(1.4f);
		button->setPosition(wyDevice::winWidth / 2, wyDevice::winHeight / 2);
		addChildLocked(button);
	}

	virtual ~wyButtonTestLayer() {
	}
	
	void onButton(wyTargetSelector* ts) {
		const char* s = wyUtils::wctoutf8(L"button clicked test, test test longl long long test is ok? h奥的的的digi的哥底粉底");
		wyToast::make(s, 3.0f)->show();
		wyFree((void*)s);
	}
};

///////////////////////////////////////////////////////////////////////////////

class wyNinePatchButtonTestLayer: public wyLayer {
public:
	wyNinePatchButtonTestLayer() {
		// sprite for button1
		wyNinePatchSprite* normal1 = wyNinePatchSprite::make(wyTexture2D::makePNG(RES("R.drawable.btn_normal")), wyr(DP(9), DP(7), DP(22), DP(28)));
		wyNinePatchSprite* pressed1 = wyNinePatchSprite::make(wyTexture2D::makePNG(RES("R.drawable.btn_pressed")), wyr(DP(9), DP(7), DP(22), DP(28)));
		normal1->setContentSize(DP(300), DP(44));
		pressed1->setContentSize(DP(300), DP(44));

		// sprite for button2
		wyNinePatchSprite* normal2 = wyNinePatchSprite::make(wyTexture2D::makePNG(RES("R.drawable.btn_normal")), wyr(DP(9), DP(7), DP(22), DP(28)));
		wyNinePatchSprite* pressed2 = wyNinePatchSprite::make(wyTexture2D::makePNG(RES("R.drawable.btn_pressed")), wyr(DP(9), DP(7), DP(22), DP(28)));
		normal2->setContentSize(DP(100), DP(44));
		pressed2->setContentSize(DP(100), DP(44));

		// button 1
		wyButton* button1 = wyButton::make(normal1, pressed1, NULL, NULL, NULL,
				wyTargetSelector::make(this, SEL(wyNinePatchButtonTestLayer::onButtonClicked)));
		button1->setPosition(wyDevice::winWidth / 2, wyDevice::winHeight / 2 + DP(40));

		// button 2
		wyButton* button2 = wyButton::make(normal2, pressed2, NULL, NULL, NULL,
				wyTargetSelector::make(this, SEL(wyNinePatchButtonTestLayer::onButtonClicked)));
		button2->setPosition(wyDevice::winWidth / 2, wyDevice::winHeight / 2 - DP(40));

		// label for button 1
		wyBitmapFont* font = wyBitmapFont::loadFont(RES("R.raw.bitmapfont"));
        wyBitmapFontLabel* label1 = wyBitmapFontLabel::make(font, "Long Long Long Long");
        label1->setColor(wyc3b(255, 255, 0));
        label1->setPosition(wyDevice::winWidth / 2, wyDevice::winHeight / 2 + DP(40));

		// label for button 2
        wyBitmapFontLabel* label2 = wyBitmapFontLabel::make(font, "Short");
        label2->setPosition(wyDevice::winWidth / 2, wyDevice::winHeight / 2 - DP(40));
        label2->setColor(wyc3b(255, 0, 255));

		// add
		addChildLocked(button1);
		addChildLocked(button2);
        addChildLocked(label1);
        addChildLocked(label2);
	}

	virtual ~wyNinePatchButtonTestLayer() {
	}

	void onButtonClicked(wyTargetSelector* ts) {
		wyToast::make("button clicked", 3.0f)->show();
	}
};

///////////////////////////////////////////////////////////////////////////////

class wyImageSpriteTestLayer: public wyNodeTestLayer {
public:
	wyImageSpriteTestLayer() {
		addNewSprite(wyDevice::winWidth / 2, wyDevice::winHeight / 2);
	}

	virtual ~wyImageSpriteTestLayer() {
	}

	virtual bool touchesBegan(wyMotionEvent& event) {
		wyPoint location = getLocation(event);
		addNewSprite(location.x, location.y);
		return true;
	}

	void addNewSprite(float posx, float posy) {
		char buf[128];
		int idx = rand() % 14 + 1;
		sprintf(buf, "grossini_dance_%02d", idx);
		wySprite* sprite = wySprite::make(wyTexture2D::makePNG(wyUtils::getResId(buf, "drawable", NULL)));

		// can set flip
		sprite->setFlipX(rand() % 2);
		sprite->setFlipY(rand() % 2);

		// can set rotation
		sprite->setRotation(rand() % 360);

		// can set sprite size, texture will be stretched automatically if texture size is different with sprite
		sprite->setAutoFit(true);
		sprite->setContentSize(rand() % 200 + 50, rand() % 200 + 50);

		// place sprite at specfied position
		sprite->setPosition(posx, posy);
		addChildLocked(sprite);
	}
};

///////////////////////////////////////////////////////////////////////////////

class wyLabelTestLayer: public wyLayer {
public:
	wyLabelTestLayer() {
		// add labels
		float y = wyDevice::winHeight - DP(30);
		float x = wyDevice::winWidth / 2;

		wyLabel* label = wyLabel::make("Label Size 12", SP(12), BOLD, WY_DEFAULT_FONT);
		y -= label->getHeight() / 2;
		label->setPosition(x, y);
		addChildLocked(label);
		y -= label->getHeight() / 2 + DP(20);
		
		label = wyLabel::make("Label Size 16", SP(16), ITALIC, WY_DEFAULT_FONT);
		y -= label->getHeight() / 2;
		label->setPosition(x, y);
		addChildLocked(label);
		y -= label->getHeight() / 2 + DP(20);
		
		label = wyLabel::make(RES("R.string.test_string"), SP(24), BOLD_ITALIC, WY_DEFAULT_FONT, wyDevice::winWidth / 2);
		y -= label->getHeight() / 2;
		label->setPosition(x, y);
		addChildLocked(label);
		y -= label->getHeight() / 2 + DP(20);

		label = wyLabel::make("Custom Font 36\nTest\nAlign Right", SP(36), "samplefont.ttf", false, 0, wyTexture2D::RIGHT);
		y -= label->getHeight() / 2;
		label->setPosition(x, y);
		addChildLocked(label);
	}

	virtual ~wyLabelTestLayer() {
	}
};

///////////////////////////////////////////////////////////////////////////////

class wyMenuTestLayer: public wyLayer {
public:
	wyMenuItem* disabledItem;

	wyMenuTestLayer() {
		// Font Item
		// AtlasSprite Item
        wyTexture2D* tex = wyTexture2D::makePNG(RES("R.drawable.menuitemsprite"));
		wySprite* spriteNormal = wySprite::make(tex, wyUtils::resolveRect(wyr(0, 23 * 2, 115, 23)));
		wySprite* spriteSelected = wySprite::make(tex, wyUtils::resolveRect(wyr(0, 23 * 1, 115, 23)));
		wySprite* spriteDisabled = wySprite::make(tex, wyUtils::resolveRect(wyr(0, 23 * 0, 115, 23)));

		wyMenuItemSprite* item1 = wyMenuItemSprite::make(NULL,
				wyTargetSelector::make(this, SEL(wyMenuTestLayer::onAtlasSpriteMenuItemClicked)),
				spriteNormal, spriteSelected, spriteDisabled);

		// Image Item
		wyMenuItem* item2 = wyMenuItemSprite::make(NULL,
				wyTargetSelector::make(this, SEL(wyMenuTestLayer::onSpriteMenuItemClicked)),
				wySprite::make(wyTexture2D::makePNG(RES("R.drawable.btn_send_score_normal"))),
				wySprite::make(wyTexture2D::makePNG(RES("R.drawable.btn_send_score_pressed"))),
				NULL);

		// Label Item (AtlasLabel)
		wyCharMap* map = wyCharMap::make();
		map->mapChar(wyr(0, 0, DP(20), DP(25)), '0');
		map->mapChar(wyr(DP(20), 0, DP(10), DP(25)), '1');
		map->mapChar(wyr(DP(30), 0, DP(21), DP(25)), '2');
		map->mapChar(wyr(DP(51), 0, DP(21), DP(25)), '3');
		map->mapChar(wyr(DP(72), 0, DP(21), DP(25)), '4');
		map->mapChar(wyr(DP(93), 0, DP(21), DP(25)), '5');
		map->mapChar(wyr(DP(114), 0, DP(21), DP(25)), '6');
		map->mapChar(wyr(DP(135), 0, DP(21), DP(25)), '7');
		map->mapChar(wyr(DP(156), 0, DP(21), DP(25)), '8');
		map->mapChar(wyr(DP(177), 0, DP(21), DP(25)), '9');
		wyAtlasLabel* labelAtlas = wyAtlasLabel::make("0123456789", wyTexture2D::makePNG(RES("R.drawable.number")), map);
		wyMenuItemAtlasLabel* item3 = wyMenuItemAtlasLabel::make(NULL,
				wyTargetSelector::make(this, SEL(wyMenuTestLayer::onLabelMenuItemClicked)), labelAtlas);

		// Font Item
		wyMenuItemLabel* item4 = wyMenuItemLabel::make(NULL,
				wyTargetSelector::make(this, SEL(wyMenuTestLayer::onSwitchMenuItemClicked)),
				wyLabel::make("I toggle enable items", SP(32), NORMAL));

		// Font Item
		wyMenuItemLabel* item5 = wyMenuItemLabel::make(NULL,
				wyTargetSelector::make(this, SEL(wyMenuTestLayer::onQuitMenuItemClicked)),
				wyLabel::make("Quit", SP(32), NORMAL));
		item5->setDisabledColor(wyc3b(32, 32, 0));
		item5->setColor(wyc3b(255, 255, 0));

		// toggle items
		wyMenuItemLabel* toggle1 = wyMenuItemLabel::make(NULL, NULL,
				wyLabel::make("This", SP(32), NORMAL));
		wyMenuItemLabel* toggle2 = wyMenuItemLabel::make(NULL, NULL,
				wyLabel::make("is a", SP(32), NORMAL));
		wyMenuItemLabel* toggle3 = wyMenuItemLabel::make(NULL, NULL, wyLabel::make("toggle", SP(32), NORMAL));
		wyMenuItemLabel* toggle4 = wyMenuItemLabel::make(NULL, NULL, wyLabel::make("menu item", SP(32), NORMAL));
		wyMenuItemToggle* item6 = wyMenuItemToggle::make(NULL,
				wyTargetSelector::make(this, SEL(wyMenuTestLayer::onToggleMenuItemClicked)),
				toggle1, toggle2, toggle3, toggle4, NULL);

		wyMenu* menu = wyMenu::make(item1, item2, item3, item4, item5, item6, NULL);
		menu->alignItemsVertically();

		disabledItem = (wyMenuItem*) item5->retain();
		disabledItem->setEnabled(false);

		addChildLocked(menu);
	}

	virtual ~wyMenuTestLayer() {
		wyObjectRelease(disabledItem);
	}

	void onAtlasSpriteMenuItemClicked(wyTargetSelector* ts) {
		wyToast::make("you click atlas sprite menu item", 3.0f)->show();
	}

	void onSpriteMenuItemClicked(wyTargetSelector* ts) {
		wyToast::make("you click sprite menu item", 3.0f)->show();
	}

	void onLabelMenuItemClicked(wyTargetSelector* ts) {
		wyToast::make("you click label menu item", 3.0f)->show();
	}

	void onSwitchMenuItemClicked(wyTargetSelector* ts) {
		disabledItem->setEnabled(!disabledItem->isEnabled());
	}

	void onToggleMenuItemClicked(wyTargetSelector* ts) {
		wyToast::make("you click toggle menu item", 3.0f)->show();
	}

	void onQuitMenuItemClicked(wyTargetSelector* ts) {
		wyDirector::getInstance()->popScene();
	}
};

///////////////////////////////////////////////////////////////////////////////

class wyMotionStreakTestLayer: public wyLayer {
	wySprite* m_root;
	wySprite* m_target;
	wyMotionStreak* m_streak1;
	wyMotionStreak* m_streak2;
	wyMotionStreak* m_streak3;
	wyMotionStreak* m_streak4;
	wyBox2D* m_box2d;
	b2Body* m_ball;

	// pid for streak 3 & 4
	int m_streak3Pid;
	int m_streak4Pid;

public:
	wyMotionStreakTestLayer() :
			m_streak3Pid(-1),
			m_streak4Pid(-1) {
		/*
		 * first streak is a continuous motion tracker
		 */

		// the root object just rotates around
		m_root = wySprite::make(wyTexture2D::makePNG(RES("R.drawable.r1")));
		m_root->setPosition(wyDevice::winWidth / 2, wyDevice::winHeight / 2);
		addChildLocked(m_root, 1);

		// the target object is offset from root, and the streak is moved to follow it
		m_target = wySprite::make(wyTexture2D::makePNG(RES("R.drawable.r1")));
		m_target->setPosition(DP(100), 0);
		m_root->addChildLocked(m_target);

		// create the streak object and add it to the scene
		m_streak1 = wyMotionStreak::make(2, wyTexture2D::makePNG(RES("R.drawable.icon")), wyc4b(0, 255, 0, 255));
		addChildLocked(m_streak1);

		// schedule an update on each frame so we can synchronize the streak with the target
		wyTimer* timer = wyTimer::make(wyTargetSelector::make(this, SEL(wyMotionStreakTestLayer::onAddPoint)));
		scheduleLocked(timer);

		// start run action
		wyIntervalAction* rotate = wyRotateBy::make(2, 360);
		wyIntervalAction* motion = wyMoveBy::make(2, DP(100), 0);
		wyIntervalAction* rmotion = (wyIntervalAction*) motion->reverse();
		m_root->runAction(wyRepeatForever::make(wySequence::make(motion, rmotion, NULL)));
		m_root->runAction(wyRepeatForever::make(rotate));

		/*
		 * second streak is combined with box2d to show route of a body, it is incontinuous
		 */

		// create second streak, fade time is 0 so it doesn't disappear until you call reset
		m_streak2 = wyMotionStreak::make(0, wyTexture2D::makePNG(RES("R.drawable.track")), wyc4b(55, 66, 200, 255), MS_STYLE_SPOT);
		((wySpotRibbon*)m_streak2->getRibbon())->setDistance(DP(20));
		addChildLocked(m_streak2);

		// create box2d
		m_box2d = wyBox2D::make();
		m_box2d->setDebugDraw(true);
		addChildLocked(m_box2d);

		// set gravity
		b2World* world = m_box2d->getWorld();
		world->SetGravity(b2Vec2(0, -10));

		// create ground
		b2Body* ground = NULL;
		{
			b2BodyDef bd;
			ground = world->CreateBody(&bd);
		}

		// create bottom edge
		{
			b2EdgeShape* es = new b2EdgeShape();
			b2FixtureDef fixDef;
			fixDef.shape = es;
			fixDef.density = 0.0f;
			fixDef.restitution = 0.5f;
			es->Set(b2Vec2(0, 0), b2Vec2(m_box2d->pixel2Meter(wyDevice::winWidth), 0));
			ground->CreateFixture(&fixDef);
		}

		// create circle body
		{
			b2BodyDef bd;
			bd.type = b2_dynamicBody;
			bd.position.Set(0, m_box2d->pixel2Meter(wyDevice::winHeight));
			bd.linearVelocity = b2Vec2(2, 0);
			m_ball = world->CreateBody(&bd);
		}

		// create circle shape for ball
		{
			b2CircleShape* cs = new b2CircleShape();
			b2FixtureDef fixDef;
			fixDef.shape = cs;
			fixDef.restitution = 0.85f;
			fixDef.density = 1.0f;
			cs->m_radius = 0.5f;
			m_ball->CreateFixture(&fixDef);
		}

		/*
		 * create third streak with blade style
		 */
		m_streak3 = wyMotionStreak::make(0.01f, wyTexture2D::makePNG(RES("R.drawable.streak")), wyc4bWhite, MS_STYLE_BLADE);
		addChildLocked(m_streak3);

		/*
		 * create fourth streak with line style
		 */
		m_streak4 = wyMotionStreak::make(0, wyTexture2D::makePNG(RES("R.drawable.line")), wyc4bRed, MS_STYLE_LINE);
		((wyLineRibbon*)m_streak4->getRibbon())->setLineWidth(8);
		addChildLocked(m_streak4);

		// enable touch
		setTouchEnabled(true);

		// update world
		startUpdateWorld();
	}

	virtual ~wyMotionStreakTestLayer() {
	}

	void startUpdateWorld() {
		wyTargetSelector* ts = wyTargetSelector::make(this, SEL(wyMotionStreakTestLayer::onUpdateWorld));
		wyTimer* t = wyTimer::make(ts);
		scheduleLocked(t);
	}

	void updateWorld(float delta) {
		m_box2d->getWorld()->Step(1.f / 60.f, 10, 10);
		m_box2d->getWorld()->ClearForces();

		// add point to streak
		const b2Vec2& ballPos = m_ball->GetPosition();
		wyPoint pos = wyp(m_box2d->meter2Pixel(ballPos.x), m_box2d->meter2Pixel(ballPos.y));

		// if outside of screen, reset it
		if(pos.x > wyDevice::winWidth)
			m_streak2->reset();
		else
			m_streak2->addPoint(pos.x, pos.y);
	}

	void onUpdateWorld(wyTargetSelector* ts) {
		updateWorld(ts->getDelta());
	}

	void onAddPoint(wyTargetSelector* ts) {
		wyPoint p = m_target->nodeToWorldSpace(wyp(m_target->getAnchorPointX(), m_target->getAnchorPointY()));
		m_streak1->addPoint(p.x, p.y);
	}

	virtual bool touchesBegan(wyMotionEvent& e) {
		LOGD("touchesBegan: %f, %f, pid: %d", e.x[0], e.y[0], e.pid[0]);

		m_streak3->addPoint(e.x[0], e.y[0], true);
		m_streak3Pid = e.pid[0];
    	return true;
    }

	virtual bool touchesPointerBegan(wyMotionEvent& e) {
		LOGD("touchesPointerBegan: %f, %f, pid: %d", e.x[e.index], e.y[e.index], e.pid[e.index]);

		if(m_streak4Pid == -1) {
			m_streak4->addPoint(e.x[e.index], e.y[e.index], true);
			m_streak4Pid = e.pid[e.index];
		} else if(m_streak3Pid == -1) {
			m_streak3->addPoint(e.x[e.index], e.y[e.index], true);
			m_streak3Pid = e.pid[e.index];
		}
    	return true;
	}

	virtual bool touchesPointerEnded(wyMotionEvent& e) {
		LOGD("touchesPointerEnded: %f, %f, pid: %d", e.x[e.index], e.y[e.index], e.pid[e.index]);

		if(e.pid[e.index] == m_streak3Pid)
			m_streak3Pid = -1;
		else if(e.pid[e.index] == m_streak4Pid)
			m_streak4Pid = -1;
		return true;
	}

	virtual bool touchesEnded(wyMotionEvent& e) {
		LOGD("touchesEnded: %f, %f, pid: %d", e.x[0], e.y[0], e.pid[0]);

		if(e.pid[0] == m_streak3Pid)
			m_streak3Pid = -1;
		else if(e.pid[0] == m_streak4Pid)
			m_streak4Pid = -1;

		return true;
	}

	virtual bool touchesMoved(wyMotionEvent& e) {
		for(int i = 0; i < e.pointerCount; i++) {
			if(e.pid[i] == m_streak3Pid)
				m_streak3->addPoint(e.x[i], e.y[i]);
			else if(e.pid[i] == m_streak4Pid)
				m_streak4->addPoint(e.x[i], e.y[i]);
		}
    	return true;
    }
};

///////////////////////////////////////////////////////////////////////////////

class wyMotionWelderTestLayer : public wyLayer {
private:
	wyMWSprite* m_sprite1;
	wyMWSprite* m_sprite2;
	wyMWSprite* m_sprite3;
	wyMWSprite* m_sprite4;
	wyMWSprite* m_sprite5;

public:
	wyMotionWelderTestLayer() {
		// texture
		wyTexture2D* tex1 = wyTexture2D::makePNG(RES("R.drawable.mongo"));

		// animation 1
		m_sprite1 = wyMWSprite::make(RES("R.raw.test_motion_welder"), 0, tex1, NULL);
		m_sprite1->setLoopCount(-1);
		m_sprite1->setPosition(wyDevice::winWidth / 2, wyDevice::winHeight * 5 / 6);
		m_sprite1->setUnitInterval(0.1f);
		m_sprite1->setDebugDrawFrameRect(true);
		m_sprite1->setDebugDrawCollisionRect(true);
		addChildLocked(m_sprite1);

		// animation 2
		m_sprite2 = wyMWSprite::make(RES("R.raw.test_motion_welder"), 1, tex1, NULL);
		m_sprite2->setLoopCount(-1);
		m_sprite2->setPosition(wyDevice::winWidth / 2, wyDevice::winHeight * 4 / 6);
		m_sprite2->setUnitInterval(0.1f);
		m_sprite2->setDebugDrawFrameRect(true);
		m_sprite2->setDebugDrawCollisionRect(true);
		addChildLocked(m_sprite2);

		// animation 2 but flip x
		m_sprite3 = wyMWSprite::make(RES("R.raw.test_motion_welder"), 1, tex1, NULL);
		m_sprite3->setLoopCount(-1);
		m_sprite3->setFlipX(true);
		m_sprite3->setPosition(wyDevice::winWidth / 2, wyDevice::winHeight * 3 / 6);
		m_sprite3->setUnitInterval(0.1f);
		m_sprite3->setDebugDrawFrameRect(true);
		m_sprite3->setDebugDrawCollisionRect(true);
		addChildLocked(m_sprite3);

		// animation 2 but ignore frame offset
		m_sprite4 = wyMWSprite::make(RES("R.raw.test_motion_welder"), 1, tex1, NULL);
		m_sprite4->setLoopCount(-1);
		m_sprite4->setIgnoreFrameOffset(true);
		m_sprite4->setPosition(wyDevice::winWidth / 2, wyDevice::winHeight * 2 / 6);
		m_sprite4->setUnitInterval(0.1f);
		m_sprite4->setDebugDrawFrameRect(true);
		m_sprite4->setDebugDrawCollisionRect(true);
		addChildLocked(m_sprite4);

		// animation 2 but ignore frame offset and flip x
		m_sprite5 = wyMWSprite::make(RES("R.raw.test_motion_welder"), 1, tex1, NULL);
		m_sprite5->setLoopCount(-1);
		m_sprite5->setIgnoreFrameOffset(true);
		m_sprite5->setFlipX(true);
		m_sprite5->setPosition(wyDevice::winWidth / 2, wyDevice::winHeight / 6);
		m_sprite5->setUnitInterval(0.1f);
		m_sprite5->setDebugDrawFrameRect(true);
		m_sprite5->setDebugDrawCollisionRect(true);
		addChildLocked(m_sprite5);

		// start to update
		wyTimer* timer = new wyTimer(wyTargetSelector::make(this, SEL(wyMotionWelderTestLayer::onUpdateSprite)));
		scheduleLocked(timer);
		wyObjectRelease(timer);

		setTouchEnabled(true);
	}

	virtual ~wyMotionWelderTestLayer() {
	}

	virtual bool touchesBegan(wyMotionEvent& event) {
		m_sprite1->setPaused(!m_sprite1->isPaused());
		m_sprite2->setPaused(!m_sprite2->isPaused());
		m_sprite3->setPaused(!m_sprite3->isPaused());
		m_sprite4->setPaused(!m_sprite4->isPaused());
		m_sprite5->setPaused(!m_sprite5->isPaused());
		return true;
	}

	void onUpdateSprite(wyTargetSelector* ts) {
		m_sprite1->tick(ts->getDelta());
		m_sprite2->tick(ts->getDelta());
		m_sprite3->tick(ts->getDelta());
		m_sprite4->tick(ts->getDelta());
		m_sprite5->tick(ts->getDelta());
	}
};

///////////////////////////////////////////////////////////////////////////////

class wyMultiplexLayerTestLayer: public wyMultiplexLayer {
public:
	wyMultiplexLayerTestLayer() {
		wyColorLayer* layer = new wyColorLayer(wyc4b(255, 0, 0, 255));
		addLayer((wyLayer*) layer->autoRelease());
		layer = new wyColorLayer(wyc4b(0, 255, 0, 255));
		addLayer((wyLayer*) layer->autoRelease());
		layer = new wyColorLayer(wyc4b(0, 0, 255, 255));
		addLayer((wyLayer*) layer->autoRelease());

		wyIntervalAction* a = wySequence::make(wyDelayTime::make(1),
											   wyCallFunc::make(wyTargetSelector::make(this, SEL(wyMultiplexLayerTestLayer::onSwitchLayer))),
											   NULL);
		wyRepeatForever* repeat = wyRepeatForever::make(a);
		runAction(repeat);
	}

	virtual ~wyMultiplexLayerTestLayer() {
	}

	void onSwitchLayer(wyTargetSelector* ts) {
		switchTo(getEnabledLayer() + 1);
	}
};

///////////////////////////////////////////////////////////////////////////////

class wyPageControlTestLayer: public wyLayer {
private:
	wyLabel* m_hint;

public:
	wyPageControlTestLayer() {
		// create pages
		wySprite* page1 = wySprite::make(wyTexture2D::makePNG(RES("R.drawable.grossini_dance_05")));
		wySprite* page2 = wySprite::make(wyTexture2D::makePNG(RES("R.drawable.grossini_dance_09")));
		wySprite* page3 = wySprite::make(wyTexture2D::makePNG(RES("R.drawable.grossini_dance_04")));

		// page control
		// call setCallback first so that you won't miss some callback
		wyPageControl* pageControl = new wyPageControl();
		wyPageControlCallback callback = {
				onPageClicked,
				onPageChanged,
				onPagePositionChanged
		};
		pageControl->setCallback(&callback, this);
		pageControl->setPageSpacing(DP(80));
		pageControl->addPage(page1);
		pageControl->addPage(page2);
		pageControl->addPage(page3);
		pageControl->setInitialPage(1);
		// 可以设置排列方式为垂直
		// pageControl->setVertical(true);
		addChildLocked(pageControl);
		pageControl->release();

		// set page indicator
		wyDotPageIndicator* indicator = wyDotPageIndicator::make(
				wyTexture2D::makePNG(RES("R.drawable.thumb")),
				wyTexture2D::makePNG(RES("R.drawable.joystick_rocker")));
		indicator->setPosition(wyDevice::winWidth / 2, wyDevice::winHeight - DP(60));
		pageControl->setPageIndicator(indicator);

		// create a hint label
		m_hint = wyLabel::make("try scroll and click");
		m_hint->setPosition(wyDevice::winWidth / 2, 100);
		addChildLocked(m_hint);
	}

	virtual ~wyPageControlTestLayer() {
	}

	static void onPageClicked(wyPageControl* pageControl, int index, void* data) {
		wyPageControlTestLayer* layer = (wyPageControlTestLayer*)data;
		char buf[64];
		sprintf(buf, "page clicked: %d", index);
		layer->m_hint->setText(buf);
	}

	static void onPageChanged(wyPageControl* pageControl, int index, void* data) {
		wyPageControlTestLayer* layer = (wyPageControlTestLayer*)data;
		char buf[64];
		sprintf(buf, "page changed: %d", index);
		layer->m_hint->setText(buf);
	}

	static void onPagePositionChanged(wyPageControl* pageControl, wyNode* page, float offset, void* data) {
		float rate = fabs(offset) / (pageControl->getHeight() / 2); // change to wyDevice::winHeight if vertical
		page->setScale(1 + 1.0f * (1 - MIN(1, rate)));
		page->setPosition(page->getPositionX(), pageControl->getHeight() / 2 + DP(80) * (1 - MIN(1, rate)));
	}
};

///////////////////////////////////////////////////////////////////////////////

class wyGradientColorLayerTestLayer: public wyGradientColorLayer {
public:
	wyGradientColorLayerTestLayer() : wyGradientColorLayer(wyc4b(0, 255, 0, 255), wyc4b(0, 0, 255, 255), 0) {
		wyIntervalAction* a = wySequence::make(wyDelayTime::make(0.03f),
											   wyCallFunc::make(wyTargetSelector::make(this, SEL(wyGradientColorLayerTestLayer::onSetDegree))),
											   NULL);
		wyRepeatForever* repeat = wyRepeatForever::make(a);
		runAction(repeat);
	}

	virtual ~wyGradientColorLayerTestLayer() {
	}

	void onSetDegree(wyTargetSelector* ts) {
		setDegree(m_degree + 1);
	}
};

///////////////////////////////////////////////////////////////////////////////

class wyParallaxTestLayer: public wyNodeTestLayer {
private:
	wyPoint previousLocation;
	wyParallaxNode* m_Node;
public:
	wyParallaxTestLayer() {
		// Top Layer, a simple image
		wySprite* image = wySprite::make(wyTexture2D::makePNG(RES("R.drawable.powered")));
		image->setAnchor(0, 0);
		image->setPosition(wyDevice::winWidth, 100);

		wyTiledSprite* ts = wyTiledSprite::make(wyTexture2D::makePNG(RES("R.drawable.tiled_bg")));
		ts->setContentSize(wyDevice::winWidth, DP(115));
		ts->setTileDirection(true, false);
		ts->setAnchor(0, 0);
		ts->setPosition(0, 100);

		/*
		 * 我们要允许整个场景能往右移动，最开始场景在最左边
		 * 假设场景有3个屏幕宽，场景的基准点在左下角, 那么当场景移动到最右边的时候，
		 * 场景的左下角应该是在屏幕左侧两个屏幕宽的位置。在左边，我们规定为负值，所以
		 * 场景的偏移合法访问是-2个屏幕到0, 不是正2个屏幕，要分清
		 */
		wyParallaxNode* parallax = wyParallaxNode::make();
		parallax->setMaxX(0);
		parallax->setMinX(-wyDevice::winWidth * 2);
		parallax->setMinY(0);
		parallax->setMaxY(0);

		// background image
		parallax->addChild(ts, -1, 1.0f, 1.0f);

		// top image is moved
		parallax->addChild(image, 2, 2.0f, 2.0f);
		addChildLocked(parallax);

		m_Node = parallax;

		setGestureEnabled(true);
	}

	virtual ~wyParallaxTestLayer() {
	}

	virtual bool touchesBegan(wyMotionEvent& event) {
		previousLocation = getLocation(event);
		m_Node->stopFling();
		return true;
	}

	virtual bool touchesEnded(wyMotionEvent& event) {
		return true;
	}

	virtual bool touchesCancelled(wyMotionEvent& event) {
		return false;
	}

	virtual bool touchesMoved(wyMotionEvent& event) {
		wyPoint location = getLocation(event);
		wyPoint diff = { 0, 0 };

		diff.x = location.x - previousLocation.x;
		diff.y = location.y - previousLocation.y;

		m_Node->offsetBy(diff.x, 0);

		previousLocation = location;
		return true;
	}

	virtual bool onFling(wyMotionEvent& e1, wyMotionEvent& e2, float velocityX, float velocityY) {
		// we don't scroll in y axis, so neglect y velocity
		m_Node->fling(velocityX, 0);
		return true;
	}
};

///////////////////////////////////////////////////////////////////////////////

class wyProgressTimerTestLayer: public wyLayer {
private:
	float ITEM_WIDTH;
	float ITEM_HEIGHT;

public:
	wyProgressTimerTestLayer() {
		// 逆时针进度条
		wyProgressTimer* pt1 = wyProgressTimer::make(
				wyTexture2D::makePNG(RES("R.drawable.grossini")));
		pt1->setStyle(wyProgress::RADIAL_CCW);
		pt1->setPercentage(75);
		pt1->setAnchor(0, 0);
		pt1->setPosition(wyDevice::winWidth / 2 + 30, wyDevice::winHeight / 2);
		addChildLocked(pt1);

		// 使用atlas sprite构造进度条, 顺时针进度条
		ITEM_WIDTH = 85;
		ITEM_HEIGHT = 121;
		int idx = rand() % 14;
		float x = (idx % 5) * ITEM_WIDTH;
		float y = (idx / 5) * ITEM_HEIGHT;
		wyTexture2D* tex = wyTexture2D::makePNG(RES("R.drawable.grossini_dance_atlas"));
		wySprite* sprite = wySprite::make(tex, wyUtils::resolveRect(wyr(x, y, ITEM_WIDTH, ITEM_HEIGHT)));
		wyProgressTimer* pt2 = wyProgressTimer::make(sprite);
		pt2->setStyle(wyProgress::RADIAL_CW);
		pt2->setPercentage(75);
		pt2->setAnchor(0, 1);
		pt2->setPosition(wyDevice::winWidth / 2 + 30, wyDevice::winHeight / 2);
		addChildLocked(pt2);

		// 水平形式的进度条
		wyProgressTimer* pt3 = wyProgressTimer::make(
				wyTexture2D::makePNG(RES("R.drawable.grossini")));
		pt3->setStyle(wyProgress::HORIZONTAL_BAR_LR);
		pt3->setPercentage(60);
		pt3->setAnchor(1, 1);
		pt3->setPosition(wyDevice::winWidth / 2 - 30, wyDevice::winHeight / 2);
		addChildLocked(pt3);

		// 使用atlas sprite构造进度条, 样式为垂直
		wyProgressTimer* pt4 = wyProgressTimer::make(sprite);
		pt4->setStyle(wyProgress::VERTICAL_BAR_BT);
		pt4->setPercentage(75);
		pt4->setAnchor(1, 0);
		pt4->setPosition(wyDevice::winWidth / 2 - 30, wyDevice::winHeight / 2);
		addChildLocked(pt4);
	}

	virtual ~wyProgressTimerTestLayer() {
	}
};

///////////////////////////////////////////////////////////////////////////////

class wyPVRSpriteTestLayer: public wyNodeTestLayer {
public:
	wyPVRSpriteTestLayer() {
		addNewSprite(wyDevice::winWidth / 2, wyDevice::winHeight / 2);
	}

	virtual ~wyPVRSpriteTestLayer() {
	}

	void addNewSprite(float posx, float posy) {
#if ANDROID || MACOSX || WINDOWS
		int index = rand() % 7;
#elif IOS
		int index = rand() % 9;
#endif
		char buf[128];
		switch(index) {
			case 0:
				sprintf(buf, "grossini_rgba_8888");
				break;
			case 1:
				sprintf(buf, "grossini_rgba_5551");
				break;
			case 2:
				sprintf(buf, "grossini_rgba_4444");
				break;
			case 3:
				sprintf(buf, "grossini_rgb_565");
				break;
			case 4:
				sprintf(buf, "grossini_i_8");
				break;
			case 5:
				sprintf(buf, "grossini_a_8");
				break;
			case 6:
				sprintf(buf, "grossini_ai_8");
				break;
#if IOS
			case 7:
				sprintf(buf, "grossini_pvrtc_2");
				break;
			case 8:
				sprintf(buf, "grossini_pvrtc_4");
				break;
#endif
		}
		wySprite* sprite = wySprite::make(wyTexture2D::makePVR(wyUtils::getResId(buf, "raw", NULL)));
		addChildLocked(sprite);
		sprite->setPosition(posx, posy);
	}

	virtual bool touchesBegan(wyMotionEvent& event) {
		wyPoint loc = getLocation(event);

		addNewSprite(loc.x, loc.y);

		return true;
	}
};

///////////////////////////////////////////////////////////////////////////////

class wyRenderTextureTestLayer: public wyNodeTestLayer {
public:
	wyRenderTextureTestLayer() {
		wyLabel* label = wyLabel::make("Click to add a masked sprite", SP(14));
		label->setPosition(wyDevice::winWidth / 2, DP(70));
		addChildLocked(label);

		setTouchEnabled(true);
	}

	virtual ~wyRenderTextureTestLayer() {
	}

	virtual bool touchesBegan(wyMotionEvent& event) {
		// prepare src image and mask image, blend function must be set
		// correctly
		wySprite* src = wySprite::make(wyTexture2D::makePNG(RES("R.drawable.grossini")));
		src->setAnchor(0, 0);
		src->setBlendMode(wyRenderState::MODULATE);
		wySprite* mask = wySprite::make(wyTexture2D::makePNG(RES("R.drawable.mask")));
		mask->setAnchor(0, 0);

		// get render manager
		wyRenderManager* rm = wyDirector::getInstance()->getRenderManager();

		// use a rendertexture to combine two images, mask first
		wyRenderTexture* rt = wyRenderTexture::make((int)DP(85), (int)DP(121));
		rt->beginRender();
		rm->renderNodeRecursively(mask);
		rm->renderNodeRecursively(src);
		rt->endRender();

		// add render texture
		rt->setPosition(wyDevice::winWidth / 2, wyDevice::winHeight / 2);
		addChildLocked(rt);

		return false;
	}
};

///////////////////////////////////////////////////////////////////////////////

class wySpriteX2011TestLayer: public wyLayer {
private:
	wySPX3Sprite* m_sprite1;
	wySPX3Sprite* m_sprite2;
	wySPX3Sprite* m_sprite3;
	wySPX3Sprite* m_sprite4;
	wySPX3Sprite* m_sprite5;
	wySPX3Sprite* m_sprite6;
	wySPX3Sprite* m_sprite7;

public:
	wySpriteX2011TestLayer() {
		// texture
		wyTexture2D* tex = wyTexture2D::makePNG(RES("R.drawable.spx3_test"));

		// animation 1
		// SpriteX是不支持tick模式播放的, 但是可以使用setForceTickMode强行设置使用tick模式
		// 为了看效果, 把unit interval设置的比较大, 这样可以看到动画变慢了
		m_sprite1 = wySPX3Sprite::make(RES("R.raw.spx3_test"), 0, tex, NULL);
		m_sprite1->setLoopCount(-1);
		m_sprite1->setPosition(wyDevice::winWidth / 2, wyDevice::winHeight * 7 / 8);
		m_sprite1->setForceTickMode(true);
		m_sprite1->setUnitInterval(0.5f);
		addChildLocked(m_sprite1);

		// animation 2
		m_sprite2 = wySPX3Sprite::make(RES("R.raw.spx3_test"), 1, tex, NULL);
		m_sprite2->setLoopCount(-1);
		m_sprite2->setPosition(wyDevice::winWidth / 2, wyDevice::winHeight * 6 / 8);
		addChildLocked(m_sprite2);

		// animation 3, 反着放
		m_sprite3 = wySPX3Sprite::make(RES("R.raw.spx3_test"), 2, tex, NULL);
		m_sprite3->setLoopCount(-1);
		m_sprite3->setPosition(wyDevice::winWidth / 2, wyDevice::winHeight * 5 / 8);
		m_sprite3->setReverse(true);
		addChildLocked(m_sprite3);

		// animation 4
		m_sprite4 = wySPX3Sprite::make(RES("R.raw.spx3_test"), 3, tex, NULL);
		m_sprite4->setLoopCount(-1);
		m_sprite4->setPosition(wyDevice::winWidth / 2, wyDevice::winHeight * 4 / 8);
		addChildLocked(m_sprite4);

		// animation 5, y轴倒转播放
		m_sprite5 = wySPX3Sprite::make(RES("R.raw.spx3_test"), 4, tex, NULL);
		m_sprite5->setLoopCount(-1);
		m_sprite5->setPosition(wyDevice::winWidth / 2, wyDevice::winHeight * 3 / 8);
		m_sprite5->setFlipY(true);
		addChildLocked(m_sprite5);

		// animation 6
		m_sprite6 = wySPX3Sprite::make(RES("R.raw.spx3_test"), 5, tex, NULL);
		m_sprite6->setLoopCount(-1);
		m_sprite6->setPosition(wyDevice::winWidth / 2, wyDevice::winHeight * 2 / 8);
		addChildLocked(m_sprite6);

		// animation 7
		m_sprite7 = wySPX3Sprite::make(RES("R.raw.spx3_test"), 6, tex, NULL);
		m_sprite7->setLoopCount(-1);
		m_sprite7->setPosition(wyDevice::winWidth / 2, wyDevice::winHeight / 8);
		addChildLocked(m_sprite7);

		// start to update
		wyTimer* timer = wyTimer::make(wyTargetSelector::make(this, SEL(wySpriteX2011TestLayer::onUpdateSprite)));
		scheduleLocked(timer);

		setTouchEnabled(true);
	}

	virtual ~wySpriteX2011TestLayer() {
	}

	virtual bool touchesBegan(wyMotionEvent& event) {
		m_sprite1->setPaused(!m_sprite1->isPaused());
		m_sprite2->setPaused(!m_sprite2->isPaused());
		m_sprite3->setPaused(!m_sprite3->isPaused());
		m_sprite4->setPaused(!m_sprite4->isPaused());
		m_sprite5->setPaused(!m_sprite5->isPaused());
		m_sprite6->setPaused(!m_sprite6->isPaused());
		m_sprite7->setPaused(!m_sprite7->isPaused());
		return true;
	}

	void onUpdateSprite(wyTargetSelector* ts) {
		m_sprite1->tick(ts->getDelta());
		m_sprite2->tick(ts->getDelta());
		m_sprite3->tick(ts->getDelta());
		m_sprite4->tick(ts->getDelta());
		m_sprite5->tick(ts->getDelta());
		m_sprite6->tick(ts->getDelta());
		m_sprite7->tick(ts->getDelta());
	}
};

///////////////////////////////////////////////////////////////////////////////

class wySpriteXTestLayer: public wyLayer {
private:
	wySPXSprite* m_sprite1;
	wySPXSprite* m_sprite2;
	wySPXSprite* m_sprite3;
	wySPXSprite* m_sprite4;
	wySPXSprite* m_sprite5;
	wySPXSprite* m_sprite6;
	wySPXSprite* m_sprite7;

public:
	wySpriteXTestLayer() {
		// texture
		wyTexture2D* tex = wyTexture2D::makePNG(RES("R.drawable.spx_test"));

		// animation 1
		// SpriteX是不支持tick模式播放的, 但是可以使用setForceTickMode强行设置使用tick模式
		// 为了看效果, 把unit interval设置的比较大, 这样可以看到动画变慢了
		m_sprite1 = wySPXSprite::make(RES("R.raw.spx_test"), tex, 0);
		m_sprite1->setLoopCount(-1);
		m_sprite1->setPosition(wyDevice::winWidth / 2, wyDevice::winHeight * 7 / 8);
		m_sprite1->setForceTickMode(true);
		m_sprite1->setUnitInterval(0.5f);
		addChildLocked(m_sprite1);

		// animation 2
		m_sprite2 = wySPXSprite::make(RES("R.raw.spx_test"), tex, 1);
		m_sprite2->setLoopCount(-1);
		m_sprite2->setPosition(wyDevice::winWidth / 2, wyDevice::winHeight * 6 / 8);
		addChildLocked(m_sprite2);

		// animation 3, 反着放
		m_sprite3 = wySPXSprite::make(RES("R.raw.spx_test"), tex, 2);
		m_sprite3->setLoopCount(-1);
		m_sprite3->setPosition(wyDevice::winWidth / 2, wyDevice::winHeight * 5 / 8);
		m_sprite3->setReverse(true);
		addChildLocked(m_sprite3);

		// animation 4
		m_sprite4 = wySPXSprite::make(RES("R.raw.spx_test"), tex, 3);
		m_sprite4->setLoopCount(-1);
		m_sprite4->setPosition(wyDevice::winWidth / 2, wyDevice::winHeight * 4 / 8);
		addChildLocked(m_sprite4);

		// animation 5, y轴倒转播放
		m_sprite5 = wySPXSprite::make(RES("R.raw.spx_test"), tex, 4);
		m_sprite5->setLoopCount(-1);
		m_sprite5->setPosition(wyDevice::winWidth / 2, wyDevice::winHeight * 3 / 8);
		m_sprite5->setFlipY(true);
		addChildLocked(m_sprite5);

		// animation 6
		m_sprite6 = wySPXSprite::make(RES("R.raw.spx_test"), tex, 5);
		m_sprite6->setLoopCount(-1);
		m_sprite6->setPosition(wyDevice::winWidth / 2, wyDevice::winHeight * 2 / 8);
		addChildLocked(m_sprite6);

		// animation 7
		m_sprite7 = wySPXSprite::make(RES("R.raw.spx_test"), tex, 6);
		m_sprite7->setLoopCount(-1);
		m_sprite7->setPosition(wyDevice::winWidth / 2, wyDevice::winHeight / 8);
		addChildLocked(m_sprite7);

		// start to update
		wyTimer* timer = wyTimer::make(wyTargetSelector::make(this, SEL(wySpriteXTestLayer::onUpdateSprite)));
		scheduleLocked(timer);

		setTouchEnabled(true);
	}

	virtual ~wySpriteXTestLayer() {
	}

	virtual bool touchesBegan(wyMotionEvent& event) {
		m_sprite1->setPaused(!m_sprite1->isPaused());
		m_sprite2->setPaused(!m_sprite2->isPaused());
		m_sprite3->setPaused(!m_sprite3->isPaused());
		m_sprite4->setPaused(!m_sprite4->isPaused());
		m_sprite5->setPaused(!m_sprite5->isPaused());
		m_sprite6->setPaused(!m_sprite6->isPaused());
		m_sprite7->setPaused(!m_sprite7->isPaused());
		return true;
	}

	void onUpdateSprite(wyTargetSelector* ts) {
		m_sprite1->tick(ts->getDelta());
		m_sprite2->tick(ts->getDelta());
		m_sprite3->tick(ts->getDelta());
		m_sprite4->tick(ts->getDelta());
		m_sprite5->tick(ts->getDelta());
		m_sprite6->tick(ts->getDelta());
		m_sprite7->tick(ts->getDelta());
	}
};

///////////////////////////////////////////////////////////////////////////////

class wyTextBoxTestLayer: public wyLayer {
public:
	wyTextBoxTestLayer() {
		wyLabel* label = wyLabel::make("", SP(22), BOLD, WY_DEFAULT_FONT);
		label->setColor(wyc3bBlack);

        // create state sprite for text box
		wyNinePatchSprite* normal = wyNinePatchSprite::make(wyTexture2D::makePNG(RES("R.drawable.textbox_normal")), wyr(DP(11), DP(21), DP(1), DP(1)));
		wyNinePatchSprite* pressed = wyNinePatchSprite::make(wyTexture2D::makePNG(RES("R.drawable.textbox_pressed")), wyr(DP(11), DP(21), DP(1), DP(1)));
		wyNinePatchSprite* focused = wyNinePatchSprite::make(wyTexture2D::makePNG(RES("R.drawable.textbox_focused")), wyr(DP(11), DP(21), DP(1), DP(1)));
		normal->setContentSize(DP(280), DP(42));
		pressed->setContentSize(DP(280), DP(42));
		focused->setContentSize(DP(280), DP(42));

		// create text box
        wyTextBox* box = wyTextBox::make(normal, pressed, NULL, focused, label);
        box->setPosition(wyDevice::winWidth / 2, wyDevice::winHeight / 2);
        box->setTitle("Input something!");
        box->setMessage("试试中文的提示怎么样");
        box->setPositiveButton("想修改就点我");
        box->setNegativeButton("Oh No!");
        box->setPadding(DP(10), DP(3), DP(10), DP(6));
        // you can set password style
//        box->setPassword(true);
        static wyTextBoxCallback callback = {
        		onBeginEditing,
        		onTextChanged,
        		onEndEditing
        };
        box->setCallback(&callback, this);
        addChildLocked(box);
	}

	virtual ~wyTextBoxTestLayer() {
	}

	static void onTextChanged(wyTextBox* box, void* data) {
		LOGD("onTextChanged: %s", box->getText());
	}

	static void onBeginEditing(wyTextBox* box, void* data) {
		LOGD("onBeginEditing");
	}

	static void onEndEditing(wyTextBox* box, void* data) {
		LOGD("onEndEditing: %s", box->getText());
	}
};

///////////////////////////////////////////////////////////////////////////////

class wyTGATileMapAtlasTestLayer: public wyTilemapTestLayer {
public:
	wyTGATileMapAtlasTestLayer() {
		wyTGATileMapAtlas* tilemap = wyTGATileMapAtlas::make(wyTexture2D::makePNG(RES("R.drawable.tiles")),
														   RES("R.drawable.levelmap"), 
														   DP(16),
														   DP(16));
		tilemap->getTexture()->setAntiAlias(false);

		// add tile map as child
		addChildLocked(tilemap, -1);
		m_tilemap = tilemap;
	}

	virtual ~wyTGATileMapAtlasTestLayer() {
	}
};

///////////////////////////////////////////////////////////////////////////////

class wyTMXHexagonalTestLayer: public wyTilemapTestLayer {
private:
	wySprite* m_sprite;
	
public:
	wyTMXHexagonalTestLayer() {
		// add tile map as child
		m_tilemap = createTMXMap();
		addChildLocked(m_tilemap);

		// add click feedback sprite
		wyTexture2D* tex = wyTexture2D::makePNG(RES("R.drawable.blocks"));
		m_sprite = wySprite::make(tex, wyr(0, 0, DP(32), DP(32)));
		m_sprite->setVisible(false);
		m_tilemap->addChildLocked(m_sprite, 10);
	}

	virtual ~wyTMXHexagonalTestLayer() {
	}

	wyTMXTileMap* createTMXMap() {
		wyTexture2D* tex = wyTexture2D::makePNG(RES("R.drawable.hexa_tiles"));
		return wyTMXTileMap::make(RES("R.raw.hexa_test"), tex, NULL);
	}

	virtual bool touchesBegan(wyMotionEvent& e) {
		wyTMXLayer* layer = ((wyTMXTileMap*)m_tilemap)->getLayerAt(0);
		wyPoint loc = wyp(e.x[0], e.y[0]);
		loc = layer->worldToNodeSpace(loc);
		wyDimension d = layer->getTileCoordinateAt(loc.x, loc.y);
		
		// place sprite
		wyPoint pos = layer->getPositionAt(d.x, d.y);
		if(d.x != -1) {
			m_sprite->setVisible(true);
			m_sprite->setPosition(pos.x + layer->getTileWidth() / 2, pos.y + layer->getTileHeight() / 2);
		} else {
			m_sprite->setVisible(false);
		}
		
		// perform rotation
		wySpriteEx* sprite = layer->tileAt(d.x, d.y);
		if(sprite && !sprite->hasRunningAction()) {
			wyRotateBy* rotate = wyRotateBy::make(2.f, 360);
			sprite->runAction(rotate);
		}
		
		return wyTilemapTestLayer::touchesBegan(e);
	}
};

///////////////////////////////////////////////////////////////////////////////

class wyTMXIsometricTestLayer: public wyTilemapTestLayer {
private:
	wySprite* m_sprite;
	
public:
	wyTMXIsometricTestLayer() {
		// add tile map as child
		m_tilemap = createTMXMap();
		addChildLocked(m_tilemap);
		
		// add click feedback sprite
		wyTexture2D* tex = wyTexture2D::makePNG(RES("R.drawable.blocks"));
		m_sprite = wySprite::make(tex, wyr(0, 0, DP(32), DP(32)));
		m_sprite->setVisible(false);
		m_tilemap->addChildLocked(m_sprite, 10);
		
		// print some properties
		wyTMXObjectGroup* og = ((wyTMXTileMap*)m_tilemap)->getObjectGroup("Object Layer 1");
		LOGD("object group property: weather: %s", og->getProperty("weather"));
		LOGD("object count: %d", og->getObjectCount());
		wyTMXObject* obj = og->getObjectAt(0);
		LOGD("first object name: %s, type: %s, favorite: %s",
				obj->getProperty("name"),
				obj->getProperty("type"),
				obj->getProperty("favorite"));
	}

	virtual ~wyTMXIsometricTestLayer() {
	}

	wyTMXTileMap* createTMXMap() {
		wyTexture2D* tex = wyTexture2D::makePNG(RES("R.drawable.iso"));
		wyTMXTileMap* map = wyTMXTileMap::make(RES("R.raw.iso_test1"), tex, NULL);
		map->setDebugDrawObjects(true);
		return map;
	}
	
	virtual bool touchesBegan(wyMotionEvent& e) {
		wyTMXLayer* layer = ((wyTMXTileMap*)m_tilemap)->getLayerAt(0);
		wyPoint loc = wyp(e.x[0], e.y[0]);
		loc = layer->worldToNodeSpace(loc);
		wyDimension d = layer->getTileCoordinateAt(loc.x, loc.y);
		wyPoint pos = layer->getPositionAt(d.x, d.y);
		if(d.x != -1) {
			m_sprite->setVisible(true);
			m_sprite->setPosition(pos.x + layer->getTileWidth() / 2, pos.y + layer->getTileHeight() / 2);
		} else {
			m_sprite->setVisible(false);
		}
		
		return wyTilemapTestLayer::touchesBegan(e);
	}
};

///////////////////////////////////////////////////////////////////////////////

class wyTMXOrthogonalTestLayer: public wyTilemapTestLayer {
private:
	wySprite* m_sprite;
	
public:
	wyTMXOrthogonalTestLayer() {
		// add tile map as child
		m_tilemap = createTMXMap();
		addChildLocked(m_tilemap);
		
		// add click feedback sprite
		wyTexture2D* tex = wyTexture2D::makePNG(RES("R.drawable.blocks"));
		m_sprite = wySprite::make(tex, wyr(0, 0, DP(32), DP(32)));
		m_sprite->setVisible(false);
		m_tilemap->addChildLocked(m_sprite, 10);
	}

	virtual ~wyTMXOrthogonalTestLayer() {
	}

	wyTMXTileMap* createTMXMap() {
		wyTexture2D* tex1 = wyTexture2D::makePNG(RES("R.drawable.ortho_test1"));
		wyTexture2D* tex2 = wyTexture2D::makePNG(RES("R.drawable.ortho_test1_bw"));
		return wyTMXTileMap::make(RES("R.raw.orthogonal_test5"), tex1, tex2, NULL);
	}
	
	virtual bool touchesBegan(wyMotionEvent& e) {
		wyTMXLayer* layer = ((wyTMXTileMap*)m_tilemap)->getLayerAt(0);
		wyPoint loc = wyp(e.x[0], e.y[0]);
		loc = layer->worldToNodeSpace(loc);
		wyDimension d = layer->getTileCoordinateAt(loc.x, loc.y);
		wyPoint pos = layer->getPositionAt(d.x, d.y);
		if(d.x != -1) {
			m_sprite->setVisible(true);
			m_sprite->setPosition(pos.x + layer->getTileWidth() / 2, pos.y + layer->getTileHeight() / 2);
		} else {
			m_sprite->setVisible(false);
		}
		
		return wyTilemapTestLayer::touchesBegan(e);
	}
};

///////////////////////////////////////////////////////////////////////////////

class wySceneTestLayer: public wyLayer {
public:
	wySceneTestLayer() {
		wyMenuItemLabel* item1 = new wyMenuItemLabel(NULL,
				wyTargetSelector::make(this, SEL(wySceneTestLayer::onPushScene)),
				wyLabel::make("Push Scene",
				SP(32), NORMAL));
		wyMenuItemLabel* item2 = new wyMenuItemLabel(NULL,
				wyTargetSelector::make(this, SEL(wySceneTestLayer::onPushSceneTran)),
				wyLabel::make("Push Scene (T)",
				SP(32), NORMAL));
		wyMenuItemLabel* item3 = new wyMenuItemLabel(NULL,
				wyTargetSelector::make(this, SEL(wySceneTestLayer::onQuit)),
				wyLabel::make("Quit",
				SP(32), NORMAL));

		wyMenu* menu = new wyMenu((wyMenuItem*) item1->autoRelease(), (wyMenuItem*) item2->autoRelease(),
				(wyMenuItem*) item3->autoRelease(), NULL);
		menu->setPosition(wyDevice::winWidth / 2, wyDevice::winHeight / 2);
		menu->alignItemsVertically();
		addChildLocked(menu);
		wyObjectRelease(menu);
	}

	wySceneTestLayer(int index) {
		if(index == 0) {
		} else if(index == 2) {
			wyMenuItemLabel* item1 = new wyMenuItemLabel(NULL,
					wyTargetSelector::make(this, SEL(wySceneTestLayer::onReplaceScene)),
					wyLabel::make("Replace Scene", SP(32), NORMAL));
			wyMenuItemLabel* item2 = new wyMenuItemLabel(NULL,
					wyTargetSelector::make(this, SEL(wySceneTestLayer::onReplaceSceneTransition)),
					wyLabel::make("Replace Scene (T)", SP(32), NORMAL));
			wyMenuItemLabel* item3 = new wyMenuItemLabel(NULL,
					wyTargetSelector::make(this, SEL(wySceneTestLayer::onGoBack)),
					wyLabel::make("Go Back", SP(32), NORMAL));

			wyMenu* menu = new wyMenu((wyMenuItem*) item1->autoRelease(), (wyMenuItem*) item2->autoRelease(),
					(wyMenuItem*) item3->autoRelease(), NULL);
			menu->alignItemsVertically();
			menu->setPosition(wyDevice::winWidth / 2, wyDevice::winHeight / 2);
			addChildLocked(menu);
			wyObjectRelease(menu);
		} else if(index == 3) {
			setTouchEnabled(true);

			wyLayer* bg = new wyColorLayer(wyc4b(0, 0, 255, 255));
			addChildLocked((wyLayer*) bg->autoRelease());

			wyLabel* label = wyLabel::make("Touch to pop scene", SP(32), NORMAL);
			label->setPosition(wyDevice::winWidth / 2, wyDevice::winHeight / 2);
			addChildLocked(label);
			setTouchEnabled(true);
		}

	}

	void onPushScene(wyTargetSelector* ts) {
		wyScene* scene = new wyScene();
		wyLayer* layer = new wySceneTestLayer(2);
		scene->addChildLocked(layer, 0);
		wyDirector::getInstance()->pushScene(scene);
		wyObjectRelease(scene);
		wyObjectRelease(layer);
	}

	void onPushSceneTran(wyTargetSelector* ts) {
		wyScene* scene = new wyScene();
		wyLayer* layer = new wySceneTestLayer(2);
		scene->addChildLocked(layer, 0);
		wyScene* tran = new wyTopPushInTransition(1, scene);
		wyDirector::getInstance()->pushScene(tran);
		wyObjectRelease(scene);
		wyObjectRelease(layer);
		wyObjectRelease(tran);
	}

	void onQuit(wyTargetSelector* ts) {
		wyDirector::getInstance()->popScene();
	}

	void onGoBack(wyTargetSelector* ts) {
		wyDirector::getInstance()->popScene();
	}

	void onReplaceScene(wyTargetSelector* ts) {
		wyScene* scene = new wyScene();
		wyLayer* layer = new wySceneTestLayer(3);
		scene->addChildLocked(layer, 0);
		wyDirector::getInstance()->replaceScene(scene);
		wyObjectRelease(scene);
		wyObjectRelease(layer);
	}

	void onReplaceSceneTransition(wyTargetSelector* ts) {
		wyScene* scene = new wyScene();
		wyLayer* layer = new wySceneTestLayer(3);
		scene->addChildLocked(layer, 0);
		wyScene* tran = new wyLeftPushInTransition(1, scene);
		wyDirector::getInstance()->replaceScene(tran);
		wyObjectRelease(scene);
		wyObjectRelease(layer);
		wyObjectRelease(tran);
	}

	virtual bool touchesEnded(wyMotionEvent& event) {
		wyDirector::getInstance()->popScene();
		return true;
	}
};

///////////////////////////////////////////////////////////////////////////////

class wySliderTestLayer: public wyLayer {
private:
	wyLabel* m_hint;

public:
	wySliderTestLayer() {
		wySliderCallback callback = {
				onValueChanged
		};

		// slider 1
		wySprite* bar = wySprite::make(wyTexture2D::makePNG(RES("R.drawable.bar")));
		wySprite* thumb1 = wySprite::make(wyTexture2D::makePNG(RES("R.drawable.thumb")));
		wySlider* slider1 = new wySlider(NULL, bar, thumb1);
		slider1->setValue(50);
		slider1->setShowFullBar(true);
		slider1->setAnchor(0, 0);
		slider1->setPosition(DP(20), wyDevice::winHeight * 2 / 3);
		slider1->setCallback(&callback, this);
		addChildLocked(slider1);
		slider1->release();

		// slider2
		wySprite* thumb2 = wySprite::make(wyTexture2D::makePNG(RES("R.drawable.thumb")));
		wySlider* slider2 = new wySlider(NULL, bar, thumb2);
		slider2->setValue(50);
		slider2->setAnchor(0, 0);
		slider2->setPosition(DP(20), wyDevice::winHeight / 3);
		slider2->setCallback(&callback, this);
		addChildLocked(slider2);
		slider2->release();

		// slider3
		wySprite* vbar = wySprite::make(wyTexture2D::makePNG(RES("R.drawable.vbar")));
		wySprite* thumb3 = wySprite::make(wyTexture2D::makePNG(RES("R.drawable.thumb")));
		wySlider* slider3 = new wySlider(NULL, vbar, thumb3, true);
		slider3->setValue(50);
		slider3->setShowFullBar(true);
		slider3->setPosition(wyDevice::winWidth - DP(50), wyDevice::winHeight * 3 / 4);
		slider3->setCallback(&callback, this);
		addChildLocked(slider3);
		slider3->release();

		// slider4
		wySprite* thumb4 = wySprite::make(wyTexture2D::makePNG(RES("R.drawable.thumb")));
		wySlider* slider4 = new wySlider(NULL, vbar, thumb4, true);
		slider4->setValue(50);
		slider4->setPosition(wyDevice::winWidth - DP(50), wyDevice::winHeight / 4);
		slider4->setCallback(&callback, this);
		addChildLocked(slider4);
		slider4->release();

		// create a label
		m_hint = wyLabel::make("hint label");
		m_hint->setPosition(wyDevice::winWidth / 2, wyDevice::winHeight / 2);
		addChildLocked(m_hint);
	}

	virtual ~wySliderTestLayer() {
	}

	static void onValueChanged(wySlider* slider, void* data) {
		wySliderTestLayer* layer = (wySliderTestLayer*)data;
		char buf[32];
		sprintf(buf, "%.2f", slider->getValue());
		layer->m_hint->setText(buf);
	}
};

///////////////////////////////////////////////////////////////////////////////

class wyTiledSpriteTestLayer: public wyLayer {
private:
	wyTiledSprite* ts;

	/// 记录上一次touch事件的x位置
	float m_lastX;

	/// 记录上一次touch事件的y位置
	float m_lastY;

public:
	wyTiledSpriteTestLayer() {
		ts = new wyTiledSprite(wyTexture2D::makeJPG(RES("R.drawable.test_jpg")));
		ts->setTileDirection(true, true); // 可以设置平铺的方向, 缺省就是x, y方向都平铺S
		ts->setSpacing(DP(10), DP(20));
		addChildLocked(ts);
		ts->release();

		setTouchEnabled(true);
		setGestureEnabled(true);
	}

	virtual ~wyTiledSpriteTestLayer() {
	}

	virtual bool touchesBegan(wyMotionEvent& e) {
		ts->stopFling();
		m_lastX = e.x[0];
		m_lastY = e.y[0];
		return true;
	}

	virtual bool touchesMoved(wyMotionEvent& e) {
		float dx = e.x[0] - m_lastX;
		float dy = e.y[0] - m_lastY;
		ts->offsetBy(dx, dy);
		m_lastX = e.x[0];
		m_lastY = e.y[0];
		return true;
	}

	virtual bool touchesEnded(wyMotionEvent& e) {
		return true;
	}

	virtual bool touchesCancelled(wyMotionEvent& e) {
		return true;
	}

	virtual bool onFling(wyMotionEvent& e1, wyMotionEvent& e2, float velocityX, float velocityY) {
		ts->fling(velocityX, velocityY);
		return true;
	}
};

///////////////////////////////////////////////////////////////////////////////

class wySpriteExBatchNodeTestLayer: public wyNodeTestLayer {
private:
	float ITEM_WIDTH;
	float ITEM_HEIGHT;
	wySpriteBatchNode* m_batchNode;

public:
	wySpriteExBatchNodeTestLayer() {
		// set width and height
		ITEM_WIDTH = 85;
		ITEM_HEIGHT = 121;

		m_batchNode = wySpriteBatchNode::make(wyTexture2D::makePNG(RES("R.drawable.grossini_dance_atlas")));
		m_batchNode->setPosition(0, 0);

		addChildLocked(m_batchNode);

		addNewSprite(wyDevice::winWidth / 2, wyDevice::winHeight / 2);
	}

	virtual ~wySpriteExBatchNodeTestLayer() {
	}

	virtual bool touchesBegan(wyMotionEvent& event) {
		wyPoint location = getLocation(event);
		addNewSprite(location.x, location.y);
		return true;
	}

	void addNewSprite(float posx, float posy) {
		int idx = rand() % 15;
		float x = (idx % 5) * ITEM_WIDTH;
		float y = (idx / 5) * ITEM_HEIGHT;
		wyRect rt = wyUtils::resolveRect(wyr(x, y, ITEM_WIDTH, ITEM_HEIGHT));
		wySpriteEx* spriteEx = wySpriteEx::make(m_batchNode, rt);

		// can set flip
		spriteEx->setFlipX(rand() % 2);
		spriteEx->setFlipY(rand() % 2);

		// can set rotation
		spriteEx->setRotation(rand() % 360);

		// can set sprite size, texture will be stretched automatically if texture size is different with sprite
		spriteEx->setAutoFit(true);
		spriteEx->setContentSize(rand() % 200 + 50, rand() % 200 + 50);

		spriteEx->setPosition(posx, posy);
	}
};

///////////////////////////////////////////////////////////////////////////////

class wySpriteExSelfRenderTestLayer: public wyNodeTestLayer {
public:
	wySpriteExSelfRenderTestLayer() {
		addNewSprite(wyDevice::winWidth / 2, wyDevice::winHeight / 2);
	}

	virtual ~wySpriteExSelfRenderTestLayer() {
	}

	virtual bool touchesBegan(wyMotionEvent& event) {
		wyPoint location = getLocation(event);
		addNewSprite(location.x, location.y);
		return true;
	}

	void addNewSprite(float posx, float posy) {
		char buf[128];
		int idx = rand() % 14 + 1;
		sprintf(buf, "grossini_dance_%02d", idx);
		wyTexture2D* tex = wyTexture2D::makePNG(wyUtils::getResId(buf, "drawable", NULL));
		wySpriteEx* spriteEx = wySpriteEx::make(tex);

		// can set flip
		spriteEx->setFlipX(rand() % 2);
		spriteEx->setFlipY(rand() % 2);

		// can set rotation
		spriteEx->setRotation(rand() % 360);

		// can set sprite size, texture will be stretched automatically if texture size is different with sprite
		spriteEx->setAutoFit(true);
		spriteEx->setContentSize(rand() % 200 + 50, rand() % 200 + 50);

		spriteEx->setPosition(posx, posy);
		addChildLocked(spriteEx);
	}
};

///////////////////////////////////////////////////////////////////////////////

class wyCoverFlowTestLayer : public wyNodeTestLayer {
private:
    wyCoverFlow* m_coverFlow;
    wyCover*     m_covers[9];

public:
	wyCoverFlowTestLayer() {
		setTouchEnabled(true);
#if ANDROID
		setKeyEnabled(true);
#endif

        int id1 = RES("R.drawable.atlastest");
        int id2 = RES("R.drawable.test_jpg");

        m_coverFlow = wyCoverFlow::make();
        m_coverFlow->setAnchor(0.0f, 0.0f);
        m_coverFlow->setPosition(wyDevice::winWidth / 2, wyDevice::winHeight / 2);

        for(int i = 0; i < 9; ++i) {
        	if(i % 2 == 0) {
        		m_covers[i] = wyCover::make(wyTexture2D::makePNG(id1));
        	} else {
        		m_covers[i] = wyCover::make(wyTexture2D::makeJPG(id2));
        	}
            m_coverFlow->addCover(m_covers[i]);
        }

        m_covers[4]->setRotateY(0.0f);
        m_coverFlow->setBlurredBorderWidth(0.1f);
        m_coverFlow->setFrontCoverSize(wyDevice::winWidth / 3,  wyDevice::winWidth / 3);
        m_coverFlow->setFrontCenterPosition(0, 50);

        m_coverFlow->showCover(m_covers[4]);
        addChildLocked(m_coverFlow);
	}

	virtual ~wyCoverFlowTestLayer() {
	}

	virtual bool touchesBegan(wyMotionEvent& event) {
        wyCover* touchedCover = m_coverFlow->getTouchedCover(event.x[0], event.y[0]);
        if(touchedCover) {
            int step = abs(m_coverFlow->getIndex(touchedCover) - m_coverFlow->getIndex(m_coverFlow->getFrontCover()));
            m_coverFlow->showCover(touchedCover, step * 0.3f);
        }
		return true;
	}

	virtual bool keyUp(wyKeyEvent& event) {
		switch(event.keyCode) {
			case KEYCODE_DPAD_LEFT:
				m_coverFlow->moveLeft(0.3f);
				return true;
			case KEYCODE_DPAD_RIGHT:
				m_coverFlow->moveRight(0.3f);
				return true;
			default:
				return false;
		}
	}
};

///////////////////////////////////////////////////////////////////////////////

class wyDialogTestLayer : public wyNodeTestLayer {
public:
	wyDialogTestLayer() {
		createButton("Alert Dialog", this, wyDevice::winWidth / 2, wyDevice::winHeight / 2,
				wyTargetSelector::make(this, SEL(wyDialogTestLayer::onAlertDialog)));
	}

	virtual ~wyDialogTestLayer() {
	}

	void onAlertDialog(wyTargetSelector* ts) {
		// title and message node for dialog
		wyBitmapFontLabel* title = wyBitmapFontLabel::make(wyBitmapFont::loadFont(RES("R.raw.bitmapfont2_angelcode_xml"), BFF_ANGELCODE_XML), "Alert");
		wyBitmapFontLabel* content = wyBitmapFontLabel::make(wyBitmapFont::loadFont(RES("R.raw.bitmapfont")), "Hello this is a dialog demo\n\nHave fun!");
		content->setColor(wyc3bBlack);
		content->setAlignment(wyBitmapFontLabel::CENTER);

		// background of dialog
		wyNinePatchSprite* bg = wyNinePatchSprite::make(wyTexture2D::makePNG(RES("R.drawable.dialog_bg")), wyr(DP(130), DP(20), DP(1), DP(1)));

		// ok button
		wySprite* okBtnNormal = wySprite::make(wyTexture2D::makePNG(RES("R.drawable.dialog_btn")));
		wyButton* okBtn = wyButton::make(okBtnNormal, NULL, NULL, NULL, NULL, NULL);
		wyLabel* okLabel = wyLabel::make("OK", SP(20));
		okLabel->setColor(wyc3b(96, 56, 19));

		// cancel button
		wySprite* cancelBtnNormal = wySprite::make(wyTexture2D::makePNG(RES("R.drawable.dialog_btn")));
		wyButton* cancelBtn = wyButton::make(cancelBtnNormal, NULL, NULL, NULL, NULL, NULL);
		wyLabel* cancelLabel = wyLabel::make("Cancel", SP(20));
		cancelLabel->setColor(wyc3b(96, 56, 19));

		// create dialog and show
		wyDialog* dialog = wyDialog::make();
		dialog->setBackground(bg)
				->setBackgroundPadding(DP(20), DP(20), DP(20), DP(15))
				->setTitle(title)
				->setContent(content)
				// Button can be layouted in one column or two columns, you must ensure button size is fine
//				->addButton(okBtn, okLabel, wyTargetSelector::make(this, SEL_p(wyDialogTestLayer::onOKButton), dialog))
//				->addButton(cancelBtn, cancelLabel, NULL)
				->addTwoColumnsButton(okBtn, okLabel, wyTargetSelector::make(this, SEL_p(wyDialogTestLayer::onOKButton), dialog),
						cancelBtn, cancelLabel, NULL)
				->setTransition(wyDialogPopupTransition::make())
				->setBackKeyEquivalentButtonIndex(1)
				->show();
	}

	void onOKButton(wyTargetSelector* ts, void* data) {
		wyDialog* dialog = (wyDialog*)data;
		wyToast::make("OK button clicked", 3.0f)->show();
		dialog->dismiss();
	}
};

///////////////////////////////////////////////////////////////////////////////

class wyBitmapFontHGETestLayer : public wyNodeTestLayer {
public:
    wyBitmapFontHGETestLayer() {
    	wyBitmapFont* font = wyBitmapFont::loadFont(RES("R.raw.bitmapfont"), BFF_HGE);

        const char* pText = STR("R.string.BitmapFontText");
        wyBitmapFontLabel* pLabel = wyBitmapFontLabel::make(font, pText);
        wyFree((void*)pText);
        pLabel->setPosition(wyDevice::winWidth / 2, wyDevice::winHeight / 2);
        pLabel->setLineWidth(wyDevice::winWidth / 2);
        pLabel->setColor(wyc3bRed);
        addChildLocked(pLabel);

        const char* s = wyUtils::wctoutf8(L"微云 游戏\t引擎微\n云游戏引擎");
        wyBitmapFontLabel* label2 = wyBitmapFontLabel::make(font, s);
        label2->setPosition(wyDevice::winWidth / 2, wyDevice::winHeight / 2 - pLabel->getHeight() / 2 - DP(30));
        addChildLocked(label2);
        wyFree((void*)s);
	}

	virtual ~wyBitmapFontHGETestLayer() {
	}
};

///////////////////////////////////////////////////////////////////////////////

class wyBitmapFontAngelCodeTestLayer : public wyNodeTestLayer {
public:
	wyBitmapFontAngelCodeTestLayer() {
		// 首先我们用angelcode txt的格式创建一个label
		wyBitmapFont* font = wyBitmapFont::loadFont(RES("R.raw.bitmapfont2_angelcode_txt"), BFF_ANGELCODE_TXT);
		const char* s = wyUtils::wctoutf8(L"微 云\t游戏\n引擎");
        wyBitmapFontLabel* label = wyBitmapFontLabel::make(font, s);
        label->setPosition(wyDevice::winWidth / 2, wyDevice::winHeight * 3 / 4);
        addChildLocked(label);
		wyFree((void*)s);

        // 然后用angelcode xml格式创建一个label, 两个图片字体的描述文件格式不同, 但是贴图是一样的
		wyBitmapFont* font2 = wyBitmapFont::loadFont(RES("R.raw.bitmapfont2_angelcode_xml"), BFF_ANGELCODE_XML);
        const char* s2 = "Test Label";
        wyBitmapFontLabel* label2 = wyBitmapFontLabel::make(font2, s2);
        label2->setPosition(wyDevice::winWidth / 2, wyDevice::winHeight / 2);
        addChildLocked(label2);

        // 然后用angelcode xml格式创建一个label, 只不过这个是由Bitmap Font Generator生成的
		wyBitmapFont* font3 = wyBitmapFont::loadFont(RES("R.raw.bitmapfont3"), BFF_ANGELCODE_XML);
		const char* s3 = wyUtils::wctoutf8(L"微云游戏引擎Test");
        wyBitmapFontLabel* label3 = wyBitmapFontLabel::make(font3, s3);
        label3->setPosition(wyDevice::winWidth / 2, wyDevice::winHeight / 4);
        addChildLocked(label3);
		wyFree((void*)s3);
	}

	virtual ~wyBitmapFontAngelCodeTestLayer() {
	}
};

///////////////////////////////////////////////////////////////////////////////

class wyScrollableLayerTestLayer : public wyLayer, public wyScrollableLayerListener {
public:
	wyLabel* m_hint;

public:
	wyScrollableLayerTestLayer() {
		// create scrollable layer
		wyScrollableLayer* layer = wyScrollableLayer::make(wyc4b(255, 0, 0, 60));
		layer->setContentSize(wyDevice::winWidth - DP(60), wyDevice::winHeight - DP(60));
		layer->setRelativeAnchorPoint(true);
		layer->setPosition(wyDevice::winWidth / 2, wyDevice::winHeight / 2);
		layer->setVertical(true);
		layer->setHorizontal(true);
		layer->setLeftMargin(DP(30));
		layer->setRightMargin(DP(30));
		layer->setTopMargin(DP(20));
		layer->setBottomMargin(DP(20));
		layer->setCallback(this);
		addChildLocked(layer);

		// create thumb bar
		wyNinePatchSprite* hThumb = wyNinePatchSprite::make(wyTexture2D::makePNG(RES("R.drawable.horizontal_thumb")), wyr(DP(7), DP(5), DP(1), DP(1)));
		wyNinePatchSprite* vThumb = wyNinePatchSprite::make(wyTexture2D::makePNG(RES("R.drawable.vertical_thumb")), wyr(DP(5), DP(7), DP(1), DP(1)));

		// set thumb bar
		layer->setHorizontalThumb(hThumb);
		layer->setVerticalThumb(vThumb);
		layer->setThumbFadeOutTime(2.f);

		// add scrollable item to layer, you can't use addChildLocked
		char buf[32];
		wyBitmapFont* font = wyBitmapFont::loadFont(RES("R.raw.bitmapfont"));
		wyNinePatchSprite* normal1 = wyNinePatchSprite::make(wyTexture2D::makePNG(RES("R.drawable.btn_normal")), wyr(DP(9), DP(7), DP(22), DP(28)));
		wyNinePatchSprite* pressed1 = wyNinePatchSprite::make(wyTexture2D::makePNG(RES("R.drawable.btn_pressed")), wyr(DP(9), DP(7), DP(22), DP(28)));
		normal1->setContentSize(DP(300), DP(44));
		pressed1->setContentSize(DP(300), DP(44));
		for(int i = 0; i < 100; i++) {
			// button
			wyButton* button = wyButton::make(normal1, pressed1, NULL, NULL, NULL,
					wyTargetSelector::make(this, SEL_i(wyScrollableLayerTestLayer::onButtonClicked), 100 - i));
			button->setPosition(0, DP(60) * i);

			// label for button 1
			sprintf(buf, "Button %d", 100 - i);
	        wyBitmapFontLabel* label = wyBitmapFontLabel::make(font, buf);
	        label->setColor(wyc3b(255, 255, 0));
	        label->setPosition(0, DP(60) * i);

			// add
			layer->addScrollableChildLocked(button);
			layer->addScrollableChildLocked(label);
		}

		// create a hint label
		m_hint = wyLabel::make("callback display label", SP(20));
		m_hint->setPosition(wyDevice::winWidth / 2, 100);
		addChildLocked(m_hint);
	}

	virtual ~wyScrollableLayerTestLayer() {
	}

	void onButtonClicked(wyTargetSelector* ts, int data) {
		char buf[32];
		sprintf(buf, "button %d clicked", data);
		wyToast::make(buf, 3.0f)->show();
	}

	virtual void onScrollOffsetChanged(wyScrollableLayer* layer) {
		char buf[64];
		sprintf(buf, "Offset changed: %.1f, %.1f", layer->getOffsetX(), layer->getOffsetY());
		m_hint->setText(buf);
	}

	virtual void onStartFling(wyScrollableLayer* layer) {
		m_hint->setText("onStartFling");
	}

	virtual void onEndFling(wyScrollableLayer* layer) {
		m_hint->setText("onEndFling");
	}

	virtual void onScrollableChildNotVisible(wyScrollableLayer* layer, wyNode* child) {
		// you can do some resource releasing here, if needed
	}
};

///////////////////////////////////////////////////////////////////////////////

class wyToastTestLayer : public wyLayer {
public:
	wyToastTestLayer() {
		createButton("Default Style Toast", this, wyDevice::winWidth / 2, wyDevice::winHeight - DP(60),
				  wyTargetSelector::make(this, SEL(wyToastTestLayer::onDefault)));

		createButton("Custom Style Toast", this, wyDevice::winWidth / 2, wyDevice::winHeight - DP(120),
				  wyTargetSelector::make(this, SEL(wyToastTestLayer::onCustom)));

		createButton("Custom Style Toast 2", this, wyDevice::winWidth / 2, wyDevice::winHeight - DP(180),
				  wyTargetSelector::make(this, SEL(wyToastTestLayer::onCustom2)));
	}

	virtual ~wyToastTestLayer() {
	}

	void onDefault(wyTargetSelector* ts) {
		wyToast::make("Haha, this is a default style toast, just like Android Toast", 4.0f)->show();
	}

	void onCustom(wyTargetSelector* ts) {
		wyNinePatchSprite* bg = wyNinePatchSprite::make(wyTexture2D::makePNG(RES("R.drawable.btn_normal")), wyr(DP(9), DP(7), DP(22), DP(28)));
		wyToast* t = wyToast::make(bg, "Now the background is customized, but text is still default", 2.0f);
		t->setMargin(DP(10), DP(10), DP(10), DP(10));
		t->show();
	}

	void onCustom2(wyTargetSelector* ts) {
		wyNinePatchSprite* bg = wyNinePatchSprite::make(wyTexture2D::makePNG(RES("R.drawable.btn_normal")), wyr(DP(9), DP(7), DP(22), DP(28)));
		wySprite* s = wySprite::make(wyTexture2D::makePNG(RES("R.drawable.grossini")));
		s->setScale(0.4f);
		s->setRotation(90);
		wyToast* t = wyToast::make(bg, s, 5.0f);
		t->setMargin(DP(10), DP(10), DP(10), DP(10));
		// you can also change the position
//		t->setToastPosition(x, y);
		t->show();
	}
};

///////////////////////////////////////////////////////////////////////////////

class wyVirtualJoystickTestLayer : public wyLayer {
private:
	static const int IDLE = 0;
	static const int UP = 1;
	static const int DOWN = 2;
	static const int LEFT = 3;
	static const int RIGHT = 4;
	static const int SPEED = 50;
	
	static const int UP_ANIM = 0;
	static const int DOWN_ANIM = 1;
	static const int LEFT_ANIM = 2;
	static const int RIGHT_ANIM = 3;
	static const int IDLE_ANIM = 6;

	wySPXSprite* m_spx;
	
	// sprite position
	float m_x;
	float m_y;
	
	// current action
	int m_action;

public:
	wyVirtualJoystickTestLayer() {
		// init action
		m_action = IDLE;
		
		// create joystick
		wySprite* bg = wySprite::make(wyTexture2D::makePNG(RES("R.drawable.joystick_bg")));
		bg->setDither(true);
		wySprite* rocker = wySprite::make(wyTexture2D::makePNG(RES("R.drawable.joystick_rocker")));
		wyVirtualJoystick* vj = wyVirtualJoystick::make(bg, rocker);
		vj->setAnchor(0, 0);
		vj->setPosition(DP(20), DP(20));
		static wyVirtualJoystickCallback callback = {
			onVJNavigationStarted,
			onVJNavigationEnded,
			onVJDirectionChanged
		};
		vj->setCallback(&callback, this);
		addChildLocked(vj);

		// texture
		wyTexture2D* tex = wyTexture2D::makePNG(RES("R.drawable.spx_test"));

		// up animation
		m_spx = wySPXSprite::make(RES("R.raw.spx_test"), tex, IDLE_ANIM);
		m_spx->setLoopCount(-1);
		m_spx->setPosition(wyDevice::winWidth / 2, wyDevice::winHeight / 2);
		addChildLocked(m_spx);
		m_x = wyDevice::winWidth / 2;
		m_y = wyDevice::winHeight / 2;

		// start to update
		wyTimer* timer = wyTimer::make(wyTargetSelector::make(this, SEL(wyVirtualJoystickTestLayer::onUpdateSprite)));
		scheduleLocked(timer);
	}

	virtual ~wyVirtualJoystickTestLayer() {
	}

	void onUpdateSprite(wyTargetSelector* ts) {
		// tick the animation
		m_spx->tick(ts->getDelta());

		// get sprite position delta
		float dx = 0;
		float dy = 0;
		switch(m_action) {
			case UP:
				dy = SPEED * ts->getDelta();
				break;
			case DOWN:
				dy = -SPEED * ts->getDelta();
				break;
			case LEFT:
				dx = -SPEED * ts->getDelta();
				break;
			case RIGHT:
				dx = SPEED * ts->getDelta();
				break;
		}

		// update sprite position
		m_x += dx;
		m_y += dy;
		m_spx->setPosition(m_x, m_y);
	}
	
	static void onVJNavigationStarted(wyVirtualJoystick* vj, void* data) {
		
	}
		
	static void onVJNavigationEnded(wyVirtualJoystick* vj, void* data) {
		
	}
	
	static void onVJDirectionChanged(wyVirtualJoystick* vj, int newDirection, void* data) {
		// decide action
		wyVirtualJoystickTestLayer* layer = (wyVirtualJoystickTestLayer*)data;
		switch(newDirection) {
			case VJD_CENTER:
				layer->m_action = IDLE;
				layer->m_spx->playAnimation(IDLE_ANIM);
				break;
			case VJD_EAST:
				layer->m_action = RIGHT;
				layer->m_spx->playAnimation(RIGHT_ANIM);
				break;
			case VJD_WEST:
				layer->m_action = LEFT;
				layer->m_spx->playAnimation(LEFT_ANIM);
				break;
			case VJD_NORTH:
				layer->m_action = UP;
				layer->m_spx->playAnimation(UP_ANIM);
				break;
			case VJD_SOUTH:
				layer->m_action = DOWN;
				layer->m_spx->playAnimation(DOWN_ANIM);
				break;
		}
	}
};

}

using namespace Node;

#if ANDROID
	#define DEMO_ENTRY_IMPL(CLASSNAME) JNIEXPORT void JNICALL Java_com_wiyun_engine_tests_node_##CLASSNAME##_nativeStart \
		(JNIEnv *env, jobject thiz){ \
			wyLayer* layer = new wy##CLASSNAME##Layer(); \
			runDemo(layer, NULL); \
			wyObjectRelease(layer); \
		}
#elif IOS || MACOSX || WINDOWS
	#define DEMO_ENTRY_IMPL(CLASSNAME) void _node_##CLASSNAME##Launcher() { \
			wyLayer* layer = new wy##CLASSNAME##Layer(); \
			runDemo(layer, NULL); \
			wyObjectRelease(layer); \
		}
#endif

DEMO_ENTRY_IMPL(ArcticTest);
DEMO_ENTRY_IMPL(ArrayTileMapAtlasTest);
DEMO_ENTRY_IMPL(AtlasButtonTest);
DEMO_ENTRY_IMPL(AtlasLabelTest);
DEMO_ENTRY_IMPL(AtlasSpriteTest);
DEMO_ENTRY_IMPL(AuroraGTTest);
DEMO_ENTRY_IMPL(BitmapFontHGETest);
DEMO_ENTRY_IMPL(BitmapFontAngelCodeTest);
DEMO_ENTRY_IMPL(ButtonTest);
DEMO_ENTRY_IMPL(ClipMappingAuroraGTTest);
DEMO_ENTRY_IMPL(CoverFlowTest);
DEMO_ENTRY_IMPL(DialogTest);
DEMO_ENTRY_IMPL(GradientColorLayerTest);
DEMO_ENTRY_IMPL(ImageSpriteTest);
DEMO_ENTRY_IMPL(LabelTest);
DEMO_ENTRY_IMPL(MenuTest);
DEMO_ENTRY_IMPL(MotionStreakTest);
DEMO_ENTRY_IMPL(MotionWelderTest);
DEMO_ENTRY_IMPL(MultiplexLayerTest);
DEMO_ENTRY_IMPL(NinePatchButtonTest);
DEMO_ENTRY_IMPL(PageControlTest);
DEMO_ENTRY_IMPL(ParallaxTest);
DEMO_ENTRY_IMPL(ProgressTimerTest);
DEMO_ENTRY_IMPL(PVRSpriteTest);
DEMO_ENTRY_IMPL(RenderTextureTest);
DEMO_ENTRY_IMPL(SceneTest);
DEMO_ENTRY_IMPL(ScrollableLayerTest);
DEMO_ENTRY_IMPL(SliderTest);
DEMO_ENTRY_IMPL(SpriteExBatchNodeTest);
DEMO_ENTRY_IMPL(SpriteExSelfRenderTest);
DEMO_ENTRY_IMPL(SpriteX2011Test);
DEMO_ENTRY_IMPL(SpriteXTest);
DEMO_ENTRY_IMPL(TextBoxTest);
DEMO_ENTRY_IMPL(TGATileMapAtlasTest);
DEMO_ENTRY_IMPL(TiledSpriteTest);
DEMO_ENTRY_IMPL(TMXHexagonalTest);
DEMO_ENTRY_IMPL(TMXIsometricTest);
DEMO_ENTRY_IMPL(TMXOrthogonalTest);
DEMO_ENTRY_IMPL(ToastTest);
DEMO_ENTRY_IMPL(VirtualJoystickTest);
