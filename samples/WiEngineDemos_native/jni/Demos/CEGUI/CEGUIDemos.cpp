#include "CEGUIDemos.h"
#include "common.h"
#include "WiEngine.h"
#include "WiEngine-CEGUI.h"

namespace CEGUI {
    
    /*
     * default skin, however, if you want to change skin in .layout file, you
     * must modify them manually
     */
    #define SKIN "TaharezLook"

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

    static const char* PageText [] = {
        "This is page three",
        "And this is page four, it's not too different from page three, isn't it?",
        "Yep, you guessed, this is page five",
        "And this is page six",
        "Seven",
        "Eight",
        "Nine. Quite boring, isn't it?",
        "Ten",
        "Eleven",
        "Twelve",
        "Thirteen",
        "Fourteen",
        "Fifteen",
        "And, finally, sixteen. Congrats, you found the last page!",
    };
    
	class wyTabControlTestLayer : public wyLayer {
	public:
		wyTabControlTestLayer() {
            // bootstrapSystem must be called at the very beginning
            wyCEGUINode::bootstrapSystem("cegui");
            
            // load scheme 
            SchemeManager::getSingleton().create(SKIN ".scheme");
            
            // load an image to use as a background
            ImagesetManager::getSingleton().createFromImageFile("BackgroundImage", "GPN-2000-001437.png");
            
            /*
             * here we will use a StaticImage as the root, then we can use it 
             * to place a background image. we need set some property to enable
             * background and disable frame. the "Image" property needs more
             * explain: full_image is the default name for the whole image area
             */
            WindowManager& winMgr = WindowManager::getSingleton();
            Window* background = winMgr.createWindow (SKIN "/StaticImage");
            background->setArea (URect (cegui_reldim (0), cegui_reldim (0),
                                        cegui_reldim (1), cegui_reldim (1)));
            background->setProperty ("FrameEnabled", "false");
            background->setProperty ("BackgroundEnabled", "false");
            background->setProperty ("Image", "set:BackgroundImage image:full_image");
            
            // load some demo windows and attach to the background 'root'
            // because of the 2nd parameter, all windows get prefixed with "TabControlDemo/"
            CEGUI::String prefix = "TabControlDemo/";
            background->addChildWindow(winMgr.loadWindowLayout("TabControlDemo.layout", prefix));
            
            // get TabControl by name, you should find the name in .layout, and don't forget prefix we set before
            TabControl *tc = (TabControl*)winMgr.getWindow("TabControlDemo/Frame/TabControl");
            
            // Add some pages to tab control
            tc->addTab(winMgr.loadWindowLayout("TabPage1.layout", prefix));
            tc->addTab(winMgr.loadWindowLayout("TabPage2.layout", prefix));
            
            // update tab name to list box
            refreshPageList();
            
            // add event processer for add tab button
            ((PushButton*)winMgr.getWindow("TabControlDemo/Page1/AddTab"))->subscribeEvent(PushButton::EventClicked,
                                                                                           Event::Subscriber(&wyTabControlTestLayer::handleAddTab, this));
            
            // add event for goto button
            ((PushButton*)winMgr.getWindow("TabControlDemo/Page1/Go"))->subscribeEvent(PushButton::EventClicked,
                                                                                           Event::Subscriber(&wyTabControlTestLayer::handleGoto, this));

            // add event for show button
            ((PushButton*)winMgr.getWindow("TabControlDemo/Page1/Show"))->subscribeEvent(PushButton::EventClicked,
                                                                                           Event::Subscriber(&wyTabControlTestLayer::handleShow, this));

            // add event for del button
            ((PushButton*)winMgr.getWindow("TabControlDemo/Page1/Del"))->subscribeEvent(PushButton::EventClicked,
                                                                                           Event::Subscriber(&wyTabControlTestLayer::handleDel, this));

            // add event for radio button, it can change tab pane position
            RadioButton* rb = (RadioButton*)winMgr.getWindow("TabControlDemo/Page1/TabPaneTop");
            rb->setSelected(tc->getTabPanePosition() == TabControl::Top);
            rb->subscribeEvent(RadioButton::EventSelectStateChanged,
            		Event::Subscriber(&wyTabControlTestLayer::handleTabPanePos, this));

            // add event for radio button, it can change tab pane position
            rb = (RadioButton*)winMgr.getWindow("TabControlDemo/Page1/TabPaneBottom");
            rb->setSelected(tc->getTabPanePosition() == TabControl::Bottom);
            rb->subscribeEvent(RadioButton::EventSelectStateChanged,
            		Event::Subscriber(&wyTabControlTestLayer::handleTabPanePos, this));

            // add event to scrollbar, it controls tab pane height
            Scrollbar* sb = (Scrollbar*)winMgr.getWindow("TabControlDemo/Page1/TabHeight");
            sb->setScrollPosition(tc->getTabHeight().d_offset);
            sb->subscribeEvent(Scrollbar::EventScrollPositionChanged,
            		Event::Subscriber(&wyTabControlTestLayer::handleTabHeight, this));

            // add event to scrollbar, it controls tab padding
            sb = (Scrollbar*)winMgr.getWindow("TabControlDemo/Page1/TabPadding");
            sb->setScrollPosition(tc->getTabTextPadding().d_offset);
            sb->subscribeEvent(Scrollbar::EventScrollPositionChanged,
            		Event::Subscriber(&wyTabControlTestLayer::handleTabPadding, this));

            // add cegui node
            wyCEGUINode* node = wyCEGUINode::make(background);
            addChildLocked(node);
            
            // enable event for cegui node
            node->setTouchEnabled(true);
		}

		virtual ~wyTabControlTestLayer() {
		}
        
        void refreshPageList() {
            // get window manager
            WindowManager& winMgr = WindowManager::getSingleton ();
            
            // get tab control and list box
            Listbox* lbox = NULL;
            TabControl* tc = NULL;
            if(winMgr.isWindowPresent("TabControlDemo/Page1/PageList")) {
                lbox = (Listbox*)winMgr.getWindow("TabControlDemo/Page1/PageList");
            }
            if(winMgr.isWindowPresent("TabControlDemo/Frame/TabControl")) {
                tc = (TabControl*)winMgr.getWindow("TabControlDemo/Frame/TabControl");
            }
            
            // add tab name to list box
            if(lbox && tc) {
                lbox->resetList ();
                for(size_t i = 0; i < tc->getTabCount (); i++) {
                    // create list item and set selection background, then add
                    ListboxTextItem* li = new ListboxTextItem(tc->getTabContentsAtIndex(i)->getName());
                    li->setSelectionBrushImage(SKIN, "MultiListSelectionBrush");
                    lbox->addItem(li);
                }
            }
        }
        
        bool handleTabPadding(const EventArgs& e) {
			Scrollbar* sb = (Scrollbar*)((const WindowEventArgs&)e).window;

			// Check if the window exists
			WindowManager& winMgr = WindowManager::getSingleton();
			if(winMgr.isWindowPresent("TabControlDemo/Frame/TabControl")) {
				((TabControl*)WindowManager::getSingleton().getWindow("TabControlDemo/Frame/TabControl"))->setTabTextPadding(
						UDim(0, sb->getScrollPosition()));
			}

			return true;
		}

        bool handleTabHeight(const EventArgs& e) {
			Scrollbar* sb = (Scrollbar*)((const WindowEventArgs&)e).window;

			// Check if the window exists
			WindowManager& winMgr = WindowManager::getSingleton();
			if(winMgr.isWindowPresent("TabControlDemo/Frame/TabControl")) {
				((TabControl*)WindowManager::getSingleton().getWindow("TabControlDemo/Frame/TabControl"))->setTabHeight(
						UDim(0, sb->getScrollPosition()));
			}

			// The return value mainly sais that we handled it, not if something failed.
			return true;
		}

        bool handleTabPanePos(const EventArgs& e) {
			TabControl::TabPanePosition tpp;
			switch(((const WindowEventArgs&)e).window->getID()) {
				case 0:
					tpp = TabControl::Top;
					break;
				case 1:
					tpp = TabControl::Bottom;
					break;
				default:
					return false;
			}

			// Check if the window exists
			WindowManager& winMgr = WindowManager::getSingleton();
			if(winMgr.isWindowPresent("TabControlDemo/Frame/TabControl")) {
				((TabControl*)winMgr.getWindow("TabControlDemo/Frame/TabControl"))->setTabPanePosition(tpp);
			}

			return true;
		}

        bool handleDel(const EventArgs&) {
			WindowManager& winMgr = WindowManager::getSingleton();
			Listbox* lbox = NULL;
			TabControl* tc = NULL;
			if(winMgr.isWindowPresent("TabControlDemo/Page1/PageList")) {
				lbox = (Listbox*)winMgr.getWindow("TabControlDemo/Page1/PageList");
			}
			if(winMgr.isWindowPresent("TabControlDemo/Frame/TabControl")) {
				tc = (TabControl*)winMgr.getWindow("TabControlDemo/Frame/TabControl");
			}
			if(lbox && tc) {
				ListboxItem* lbi = lbox->getFirstSelectedItem();
				if(lbi) {
					// remove tab
					tc->removeTab(lbi->getText());

					// Remove the actual window from Cegui
					winMgr.destroyWindow(lbi->getText());

					// update list box
					refreshPageList();
				}
			}

			return true;
		}

        bool handleShow(const EventArgs&) {
			WindowManager& winMgr = WindowManager::getSingleton();
			Listbox* lbox = NULL;
			TabControl* tc = NULL;
			if(winMgr.isWindowPresent("TabControlDemo/Page1/PageList")) {
				lbox = (Listbox*)winMgr.getWindow("TabControlDemo/Page1/PageList");
			}
			if(winMgr.isWindowPresent("TabControlDemo/Frame/TabControl")) {
				tc = (TabControl*)winMgr.getWindow("TabControlDemo/Frame/TabControl");
			}
			if(lbox && tc) {
				ListboxItem *lbi = lbox->getFirstSelectedItem();
				if(lbi) {
					tc->makeTabVisible(lbi->getText());
				}
			}

			return true;
		}

        bool handleGoto(const EventArgs&) {
			WindowManager& winMgr = WindowManager::getSingleton();
			Listbox* lbox = NULL;
			TabControl* tc = NULL;
			if(winMgr.isWindowPresent("TabControlDemo/Page1/PageList")) {
				lbox = (Listbox*)winMgr.getWindow("TabControlDemo/Page1/PageList");
			}
			if(winMgr.isWindowPresent("TabControlDemo/Frame/TabControl")) {
				tc = (TabControl*)winMgr.getWindow("TabControlDemo/Frame/TabControl");
			}
			if(lbox && tc) {
				ListboxItem* lbi = lbox->getFirstSelectedItem();
				if(lbi) {
					tc->setSelectedTab(lbi->getText());
				}
			}

			return true;
		}

        bool handleAddTab(const EventArgs&) {
        	// get window manager
			WindowManager& winMgr = WindowManager::getSingleton();

			if(winMgr.isWindowPresent("TabControlDemo/Frame/TabControl")) {
				// get tab control
				TabControl *tc = (TabControl*)winMgr.getWindow("TabControlDemo/Frame/TabControl");

				// Add some tab buttons once
				for(int num = 3; num <= 16; num++) {
					std::stringstream prefix;
					prefix << "TabControlDemo/Page" << num;
					if(winMgr.isWindowPresent(prefix.str()))
						// Next
						continue;

					// load layout for new tab page
					Window* pg = NULL;
					pg = winMgr.loadWindowLayout("TabPage.layout", CEGUI::String(prefix.str()));

					// This window has just been created while loading the layout
					// update a Text control to set page name on it
					// then, update list box to refill tab page names
					prefix << "Text";
					if(winMgr.isWindowPresent(prefix.str())) {
						Window* txt = winMgr.getWindow(prefix.str());
						txt->setText(PageText[num - 3]);

						std::stringstream pgname;
						pgname << "Page " << num;
						pg->setText(pgname.str());
						tc->addTab(pg);

						refreshPageList();
						break;
					}
				}
			}

			return true;
        }
	};

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

DEMO_ENTRY_IMPL(cegui, TabControlTest);
DEMO_ENTRY_IMPL(cegui, WindowTest);
