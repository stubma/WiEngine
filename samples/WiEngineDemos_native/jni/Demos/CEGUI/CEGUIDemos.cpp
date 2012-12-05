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

    static struct {
        utf8* Language;
        utf8* Font;
    	utf8* Text;
    } LangList[] = {
    	// A list of strings in different languages
    	// Feel free to add your own language here (UTF-8 ONLY!)...
        { (utf8 *)"English",
          (utf8*)"DejaVuSans-10",
    	  (utf8 *)"THIS IS SOME TEXT IN UPPERCASE\n"
                  "and this is lowercase...\n"
                  "Try Catching The Brown Fox While It's Jumping Over The Lazy Dog" },
        { (utf8 *)"Русский",
          (utf8*)"DejaVuSans-10",
    	  (utf8 *)"Всё ускоряющаяся эволюция компьютерных технологий предъявила жёсткие требования к производителям как собственно вычислительной техники, так и периферийных устройств.\n"
                  "\nЗавершён ежегодный съезд эрудированных школьников, мечтающих глубоко проникнуть в тайны физических явлений и химических реакций.\n"
                  "\nавтор панграмм -- Андрей Николаев\n" },
        { (utf8 *)"Română",
          (utf8*)"DejaVuSans-10",
          (utf8 *)"CEI PATRU APOSTOLI\n"
                  "au fost trei:\n"
                  "Luca şi Matfei\n" },
        { (utf8 *)"Dansk",
          (utf8*)"DejaVuSans-10",
          (utf8 *)"FARLIGE STORE BOGSTAVER\n"
                  "og flere men små...\n"
                  "Quizdeltagerne spiste jordbær med fløde, mens cirkusklovnen Walther spillede på xylofon\n" },
    	{ (utf8 *)"Japanese",
          (utf8*)"Sword-26",
          (utf8 *)"日本語を選択\n"
                  "トリガー検知\n"
                  "鉱石備蓄不足\n" },
    	{ (utf8 *)"Korean",
          (utf8*)"Batang-26",
          (utf8 *)"한국어를 선택\n"
                  "트리거 검지\n"
                  "광석 비축부족\n" },
        { (utf8 *)"Việt",
          (utf8*)"DejaVuSans-10",
          (utf8 *)"Chào CrazyEddie !\n"
                  "Mình rất hạnh phúc khi nghe bạn nói điều đó\n"
                  "Hy vọng sớm được thấy CEGUI hỗ trợ đầy đủ tiếng Việt\n"
                  "Cám ơn bạn rất nhiều\n"
                  "Chúc bạn sức khoẻ\n"
                  "Tạm biệt !\n" }
    };

	#define MIN_POINT_SIZE 6.0f

    class wyFontTestLayer : public wyLayer {
    public:
    	wyFontTestLayer() {
            // bootstrapSystem must be called at the very beginning
            wyCEGUINode::bootstrapSystem("cegui");

            // load scheme
            SchemeManager::getSingleton().create("TaharezLook.scheme");

    		// Create a custom font which we use to draw the list items. This custom
    		// font won't get effected by the scaler and such. we set it as default font
    		FontManager::getSingleton().createFreeTypeFont("DefaultFont", 10/*pt*/, true, "DejaVuSans.ttf");
    		System::getSingleton().setDefaultFont("DefaultFont");

            // load all the fonts (if they are not loaded yet)
            FontManager::getSingleton().createAll("*.font", "fonts");

            // load an image to use as a background
            ImagesetManager::getSingleton().createFromImageFile("BackgroundImage", "GPN-2000-001437.png");

            // here we will use a StaticImage as the root, then we can use it to place a background image
            // full_image is the default name for the whole image area
            WindowManager& winMgr = WindowManager::getSingleton();
            Window* background = winMgr.createWindow ("TaharezLook/StaticImage");
            background->setArea (URect (cegui_reldim (0), cegui_reldim (0),
            		cegui_reldim (1), cegui_reldim (1)));
            background->setProperty ("FrameEnabled", "false");
            background->setProperty ("BackgroundEnabled", "false");
            background->setProperty ("Image", "set:BackgroundImage image:full_image");

            // load some demo windows and attach to the background 'root'
            background->addChildWindow (winMgr.loadWindowLayout ("FontDemo.layout"));

            // Add the font names to the listbox
            Listbox* lbox = (Listbox*)winMgr.getWindow ("FontDemo/FontList");
    		lbox->setFont("DefaultFont");

    		// check current loaded font, add them to font list box
            // but exclude the special DefaultFont
            FontManager::FontIterator fi = FontManager::getSingleton().getIterator();
            while (!fi.isAtEnd()) {
                if (fi.getCurrentKey() != String("DefaultFont")) {
                    ListboxTextItem* li = new ListboxTextItem(fi.getCurrentKey());
                    li->setSelectionBrushImage(SKIN, "MultiListSelectionBrush");
                	lbox->addItem(li);
                }
                ++fi;
            }

            // set up the font listbox callback
            lbox->subscribeEvent(Listbox::EventSelectionChanged,
            		Event::Subscriber(&wyFontTestLayer::handleFontSelection, this));

            // select the first font by default
            lbox->setItemSelectState (size_t (0), true);

            // Add language list to the listbox
            lbox = (Listbox*)winMgr.getWindow ("FontDemo/LangList");
    		lbox->setFont("DefaultFont");
            for (size_t i = 0; i < (sizeof(LangList) / sizeof (LangList [0])); i++) {
                // only add a language if 'preferred' font is available
                if (FontManager::getSingleton().isDefined(String(LangList[i].Font))) {
                    ListboxTextItem* li = new ListboxTextItem(LangList[i].Language, i);
                    li->setSelectionBrushImage(SKIN, "MultiListSelectionBrush");
                	lbox->addItem(li);
                }
            }

            // set up the language listbox callback
            lbox->subscribeEvent(Listbox::EventSelectionChanged,
            		Event::Subscriber(&wyFontTestLayer::handleLangSelection, this));

            // select the first language by default
            lbox->setItemSelectState(size_t (0), true);

            // install event for other control
            winMgr.getWindow("FontDemo/AutoScaled")->subscribeEvent(Checkbox::EventCheckStateChanged,
            		Event::Subscriber(&wyFontTestLayer::handleAutoScaled, this));
			winMgr.getWindow("FontDemo/Antialiased")->subscribeEvent(Checkbox::EventCheckStateChanged,
					Event::Subscriber(&wyFontTestLayer::handleAntialiased, this));
			winMgr.getWindow("FontDemo/PointSize")->subscribeEvent(Scrollbar::EventScrollPositionChanged,
					Event::Subscriber(&wyFontTestLayer::handlePointSize, this));

            // add cegui node
            wyCEGUINode* node = wyCEGUINode::make(background);
            addChildLocked(node);

            // enable event for cegui node
            node->setTouchEnabled(true);
    	}

    	virtual ~wyFontTestLayer() {
    	}

        void setFontDesc() {
        	// get edit box
			WindowManager& winMgr = WindowManager::getSingleton();
			MultiLineEditbox* mle = (MultiLineEditbox*)winMgr.getWindow("FontDemo/FontSample");

			// Query the font from the textbox
			Font* f = mle->getFont();

			// Build up the font name...
			String s = f->getProperty("Name");
			if(f->isPropertyPresent("PointSize")) {
				s += "." + f->getProperty("PointSize");
			}

			// ...and set it
			winMgr.getWindow("FontDemo/FontDesc")->setText(s);
		}

        void updateTextWindows() {
			WindowManager& winMgr(WindowManager::getSingleton());
			MultiLineEditbox* eb = static_cast<MultiLineEditbox*>(winMgr.getWindow("FontDemo/FontSample"));

			// this is a hack to force the editbox to update it's state, and is
			// needed because no facility currently exists for a font to notify that
			// it's internal size or state has changed (ideally all affected windows
			// should receive EventFontChanged - this should be a TODO item!)
			eb->setWordWrapping(false);
			eb->setWordWrapping(true);

			// inform lists of updated data too
			Listbox* lb = (Listbox*)winMgr.getWindow("FontDemo/LangList");
			lb->handleUpdatedItemData();
			lb = (Listbox*)winMgr.getWindow("FontDemo/FontList");
			lb->handleUpdatedItemData();
		}

    	bool handleFontSelection(const EventArgs& e) {
    		// Access the listbox which sent the event
			Listbox* lbox = (Listbox*)((const WindowEventArgs&)e).window;

			if(lbox->getFirstSelectedItem()) {
				// Read the fontname and get the font by that name
				Font* font = &FontManager::getSingleton().get(lbox->getFirstSelectedItem()->getText());

				// Tell the textbox to use the newly selected font
				WindowManager& winMgr = WindowManager::getSingleton();
				winMgr.getWindow("FontDemo/FontSample")->setFont(font);

				// set font auto scale property
				bool b = font->isPropertyPresent("AutoScaled");
				Checkbox* cb = (Checkbox*)winMgr.getWindow("FontDemo/AutoScaled");
				cb->setEnabled(b);
				if(b) {
					cb->setSelected(PropertyHelper::stringToBool(font->getProperty("AutoScaled")));
				}

				// set font antialias property
				b = font->isPropertyPresent("Antialiased");
				cb = (Checkbox*)winMgr.getWindow("FontDemo/Antialiased");
				cb->setEnabled(b);
				if(b) {
					cb->setSelected(PropertyHelper::stringToBool(font->getProperty("Antialiased")));
				}

				// set font size
				b = font->isPropertyPresent("PointSize");
				Scrollbar *sb = (Scrollbar*)winMgr.getWindow("FontDemo/PointSize");
				sb->setEnabled(b);
				if(font->isPropertyPresent("PointSize")) {
					font->setProperty("PointSize", PropertyHelper::intToString(int(MIN_POINT_SIZE + sb->getScrollPosition())));
				}

				// update font name label
				setFontDesc();
			}

			return true;
    	}

    	bool handleLangSelection(const EventArgs& e) {
			// Access the listbox which sent the event
			Listbox* lbox = (Listbox*)((const WindowEventArgs&)e).window;

			if(lbox->getFirstSelectedItem()) {
				// get font name in language list
				ListboxItem* sel_item = lbox->getFirstSelectedItem();
				size_t idx = sel_item ? sel_item->getID() : 0;
				const String fontName(LangList[idx].Font);

				// select the font in font list box
				WindowManager& winMgr = WindowManager::getSingleton();
				Listbox *fontList = (Listbox*)winMgr.getWindow("FontDemo/FontList");
				ListboxItem* lbi = fontList->findItemWithText(fontName, 0);
				if(lbi && !lbi->isSelected()) {
					// This will cause 'handleFontSelection' to get called(!)
					fontList->setItemSelectState(lbi, true);
				}

				// Finally, set the sample text for the selected language
				winMgr.getWindow("FontDemo/FontSample")->setText((utf8*) LangList[idx].Text);
			}

			return true;
    	}

    	bool handleAutoScaled(const EventArgs& e) {
            WindowManager& winMgr = WindowManager::getSingleton();
			Checkbox *cb = (Checkbox*) ((const WindowEventArgs&) e).window;

			MultiLineEditbox* mle = (MultiLineEditbox*) winMgr.getWindow("FontDemo/FontSample");

			Font* f = mle->getFont();
			f->setProperty("AutoScaled", PropertyHelper::boolToString(cb->isSelected()));

			updateTextWindows();
			return true;
    	}

    	bool handleAntialiased(const EventArgs& e) {
            WindowManager& winMgr = WindowManager::getSingleton ();
            Checkbox *cb = (Checkbox*) ((const WindowEventArgs&) e).window;

			MultiLineEditbox* mle = (MultiLineEditbox*) winMgr.getWindow("FontDemo/FontSample");

			Font *f = mle->getFont();
			f->setProperty("Antialiased", PropertyHelper::boolToString(cb->isSelected()));

			updateTextWindows();
			return true;
    	}

    	bool handlePointSize(const EventArgs& e) {
            WindowManager& winMgr = WindowManager::getSingleton ();
            Scrollbar* sb = (Scrollbar*)((const WindowEventArgs&)e).window;

            Font* f = winMgr.getWindow("FontDemo/FontSample")->getFont();

			f->setProperty("PointSize", PropertyHelper::intToString(int(MIN_POINT_SIZE + sb->getScrollPosition())));

			setFontDesc();
			updateTextWindows();

			return true;
    	}
    };

	/////////////////////////////////////////////////////////////////////////////////

	class wyScrollablePaneTestLayer : public wyLayer {
	public:
		wyScrollablePaneTestLayer() {
            // bootstrapSystem must be called at the very beginning
            wyCEGUINode::bootstrapSystem("cegui");
            
            // this sample will use WindowsLook
            SchemeManager::getSingleton().create("WindowsLook.scheme");
            
            // load the default font because WindowsLook.scheme doesn't specify font
            Font* font = &FontManager::getSingleton().create("DejaVuSans-10.font");
            
            // create a root window
            // this will be a static, to give a nice app'ish background
            WindowManager& winMgr = WindowManager::getSingleton();
            Window* root = winMgr.createWindow("WindowsLook/Static");
            root->setProperty("FrameEnabled", "false");
            
            // create a menubar.
            // this will fit in the top of the screen and have options for the demo
            UDim bar_bottom(0, font->getLineSpacing(2));
            Window* bar = winMgr.createWindow("WindowsLook/Menubar");
            bar->setArea(UDim(0, 0), UDim(0, 0), UDim(1, 0), bar_bottom);
            bar->setAlwaysOnTop(true);
            root->addChildWindow(bar);
            
            // fill out the menubar
            createMenu(bar);
            
            // create a scrollable pane for our demo content
            // this scrollable pane will be a kind of virtual desktop in the sense that it's bigger than
            // the screen. 3000 x 3000 pixels
            ScrollablePane* pane = (ScrollablePane*)winMgr.createWindow("WindowsLook/ScrollablePane");
            pane->setArea(URect(UDim(0, 0), bar_bottom, UDim(1, 0), UDim(1, 0)));
            pane->setContentPaneAutoSized(false);
            pane->setContentPaneArea(CEGUI::Rect(0, 0, 3000, 3000));
            root->addChildWindow(pane);
            
            // add a dialog to this pane so we have something to drag around :)
            Window* dlg = winMgr.createWindow("WindowsLook/FrameWindow");
            dlg->setMinSize(UVector2(UDim(0, 250), UDim(0, 100)));
            dlg->setSize(UVector2(UDim(0, 250), UDim(0, 100)));
            dlg->setText("Drag me around");
            pane->addChildWindow(dlg);
            
            // add cegui node
            wyCEGUINode* node = wyCEGUINode::make(root);
            addChildLocked(node);
            
            // enable event for cegui node
            node->setTouchEnabled(true);
		}

		virtual ~wyScrollablePaneTestLayer() {
		}
        
        void createMenu(Window* bar) {
            // file menu item
            WindowManager& winMgr = WindowManager::getSingleton();
            Window* file = winMgr.createWindow("WindowsLook/MenuItem");
            file->setText("File");
            bar->addChildWindow(file);
            
            // file popup
            Window* popup = winMgr.createWindow("WindowsLook/PopupMenu");
            file->addChildWindow(popup);
            
            // quit item in file menu
            Window* item = winMgr.createWindow("WindowsLook/MenuItem");
            item->setText("Quit");
            item->subscribeEvent("Clicked",
                                 Event::Subscriber(&wyScrollablePaneTestLayer::fileQuit, this));
            popup->addChildWindow(item);
        }
        
        bool fileQuit(const EventArgs&) {
            wyDirector::getInstance()->popScene();
            return true;
        }
	};

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
            wnd->setPosition(UVector2(cegui_reldim(0.25f), cegui_reldim(0.25f)));
            wnd->setSize(UVector2(cegui_absdim(wyDevice::winWidth / 2), cegui_absdim(wyDevice::winHeight / 2)));
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

DEMO_ENTRY_IMPL(cegui, FontTest);
DEMO_ENTRY_IMPL(cegui, ScrollablePaneTest);
DEMO_ENTRY_IMPL(cegui, TabControlTest);
DEMO_ENTRY_IMPL(cegui, WindowTest);
