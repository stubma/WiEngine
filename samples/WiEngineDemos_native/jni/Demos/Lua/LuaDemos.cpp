#include "LuaDemos.h"
#include "common.h"
#include "WiEngine.h"
#include "WiEngine-Lua.h"
#include <stdio.h>

namespace Lua {
    class wySplitWordsTestLayer : public wyLayer {
    public:
    	wySplitWordsTestLayer() {
        	wyLua::init();
        	wyLua::setGlobal("line", "this is a test");
        	wyLua::setGlobal("layer", this, "wyLayer");
        	wyLua::execute(RES("R.raw.splitwords"));
        	wyLua::destroy();
        }

        virtual ~wySplitWordsTestLayer() {
        }
    };

    class wyCreateLabelTestLayer : public wyLayer {
    public:
    	wyCreateLabelTestLayer() {
        	wyLua::init();
        	wyLua::setGlobal("layer", this, "wyLayer");
        	wyLua::execute(RES("R.raw.create_label"));
        	wyLua::destroy();
    	}

        virtual ~wyCreateLabelTestLayer() {
        }
    };

    class wyCreateAnimationTestLayer : public wyLayer {
    public:
    	wyCreateAnimationTestLayer() {
            wyAnimationCallback callback = {
            		onAnimationFrameChanged,
            		onAnimationEnded
            };

        	wyLua::init();
        	wyLua::setGlobal("layer", this, "wyLayer");
        	wyLua::setGlobal("callback", &callback, "wyAnimationCallback");
        	wyLua::execute(RES("R.raw.create_animation"));
        }

        virtual ~wyCreateAnimationTestLayer() {
			wyLua::destroy();
        }

    	static void onAnimationFrameChanged(wyAnimation* anim, int index, void* data) {
    		wyLabel* hint = (wyLabel*)wyLua::getGlobalObject("hint");
    		char buf[64];
    		sprintf(buf, "frame changed: %d", index);
    		hint->setText(buf);
    	}

    	static void onAnimationEnded(wyAnimation* anim, void* data) {
    		wyLabel* hint = (wyLabel*)wyLua::getGlobalObject("hint");
    		hint->setText("animation ended");
    	}
    };

    class wyCreateButtonTestLayer : public wyLayer {
    public:
    	wyCreateButtonTestLayer() {
        	wyLua::init();
        	wyLua::setGlobal("layer", this, "wyLayer");
        	wyLua::execute(RES("R.raw.create_button"));
        	wyLua::destroy();
        }

        virtual ~wyCreateButtonTestLayer() {
        }

        virtual void onTargetSelectorInvoked(wyTargetSelector* ts) {
			wyToast::make("button clicked", 3.0f)->show();
    	}
    };
}

using namespace Lua;

DEMO_ENTRY_IMPL(lua, CreateAnimationTest);
DEMO_ENTRY_IMPL(lua, CreateButtonTest);
DEMO_ENTRY_IMPL(lua, CreateLabelTest);
DEMO_ENTRY_IMPL(lua, SplitWordsTest);
