#include "CEGUIDemos.h"
#include "common.h"
#include "WiEngine.h"
#include "WiEngine-CEGUI.h"

namespace CEGUI {

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
    
	/////////////////////////////////////////////////////////////////////////////////

	class wyWindowTestLayer : public wyLayer {
	public:
		wyWindowTestLayer() {
            // bootstrapSystem must be called at the very beginning
            wyCEGUINode::bootstrapSystem("cegui");
            
            // create root and add a window to root
            SchemeManager::getSingleton().create("TaharezLook.scheme");
            WindowManager& winMgr = WindowManager::getSingleton();
            DefaultWindow* root = (DefaultWindow*)winMgr.createWindow("DefaultWindow", "Root");
            FrameWindow* wnd = (FrameWindow*)winMgr.createWindow("TaharezLook/FrameWindow", "Demo Window");
            root->addChildWindow(wnd);
            
            /*
             * Init window
             * NOTE: the origin of CEGUI is at top-left of screen
             */
            wnd->setPosition(UVector2(cegui_absdim(100), cegui_absdim(100)));
            wnd->setSize(UVector2(cegui_absdim(wyDevice::winWidth / 3), cegui_absdim(wyDevice::winHeight / 3)));
            wnd->setMaxSize(UVector2(cegui_absdim(wyDevice::winWidth), cegui_absdim(wyDevice::winHeight)));
            wnd->setMinSize(UVector2(cegui_absdim(wyDevice::winWidth / 4), cegui_absdim(wyDevice::winHeight / 4)));
            wnd->setText("Hello World!");
            
            // add cegui node
            wyCEGUINode* node = wyCEGUINode::make(wnd);
            addChildLocked(node);
            
            // enable event for cegui node
            node->setTouchEnabled(true);
		}

		virtual ~wyWindowTestLayer() {
		}
	};

	//////////////////////////////////////////////////////////////////////////////////////////
}

using namespace CEGUI;

DEMO_ENTRY_IMPL(cegui, WindowTest);
