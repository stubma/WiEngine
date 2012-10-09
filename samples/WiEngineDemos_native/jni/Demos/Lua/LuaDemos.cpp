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

#if ANDROID
	#define DEMO_ENTRY_IMPL(testname) JNIEXPORT void JNICALL Java_com_wiyun_engine_tests_lua_##testname##_nativeStart \
		(JNIEnv *, jobject){ \
			wyLayer* layer = new wy##testname##Layer(); \
			runDemo(layer, NULL); \
			wyObjectRelease(layer); \
		}
#elif IOS || MACOSX || WINDOWS
	#define DEMO_ENTRY_IMPL(CLASSNAME) void _lua_##CLASSNAME##Launcher() { \
			wyLayer* layer = new wy##CLASSNAME##Layer(); \
			runDemo(layer, NULL); \
			wyObjectRelease(layer); \
		}
#endif

DEMO_ENTRY_IMPL(CreateAnimationTest);
DEMO_ENTRY_IMPL(CreateButtonTest);
DEMO_ENTRY_IMPL(CreateLabelTest);
DEMO_ENTRY_IMPL(SplitWordsTest);
