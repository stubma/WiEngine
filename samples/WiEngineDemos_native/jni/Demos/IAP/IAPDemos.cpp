#include "IAPDemos.h"
#include "common.h"
#include "WiEngine.h"
#include "WiEngine-IAP.h"

namespace IAP {

	/*
	 * The demo is already tested by WiYun Inc. What you should do is replacing
	 * key value with your public key of android market account and copying code to your
	 * project. For iOS/Mac OS X, nothing need to be changed
	 *
	 * 这些示例已经经过了微云公司的测试, 它可能在你的设备上跑不起来, 因为需要一定的测试环境. 你
	 * 需要做的就是指定你的android market账号公钥(仅android需要), 然后用你的测试账号等进行测试
	 * 即可. 如果是iOS或Mac OS X, 这些代码不需要任何修改. 关于怎么在具体的平台上测试IAP, 每个平台都有
	 * 专门的文档介绍, 请自己查看.
	 */

	#if ANDROID
		#define BACKEND IAP_BACKEND_ANDROID_MARKET
	#elif IOS || MACOSX
		#define BACKEND IAP_BACKEND_APP_STORE
	#endif

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
    
	class wyIAPTestLayer : public wyLayer, public wyIAPListener {
    private:
        wyLabel* m_hint;

	public:
        wyIAPTestLayer() {
			// buy button
			createButton("Buy a Product", this, wyDevice::winWidth / 2, wyDevice::winHeight / 2 + DP(100),
					  wyTargetSelector::make(this, SEL(wyIAPTestLayer::onBuy)));

			// hint label
			m_hint = wyLabel::make("", SP(20));
			m_hint->setLineWidth(wyDevice::winWidth - DP(50));
			m_hint->setPosition(wyDevice::winWidth / 2, wyDevice::winHeight / 2 - DP(40));
			addChildLocked(m_hint);

			// check iap availability
			if(!wyIAP::getInstance()->isBackendAvailable(BACKEND)) {
				wyToast::make("Can't perform In-App Purchase in current device", 3.0f)->show();
			}

			// enable app store iap
			wyIAP::getInstance()->enableBackend(BACKEND);
			wyIAP::getInstance()->addListener(this);

			/*
			* NOTE:
			* set public key, android market need this, you don't need remove the code when port
			* to iOS because app store backend just ignore it.
			*/
			wyIAP::getInstance()->configBackend("public_key",
				"please use your public key of android market account");
		}

		virtual ~wyIAPTestLayer() {
            // remember release singleton wyIAP when your game exit
            wyIAP::getInstance()->release();
		}

        void onBuy(wyTargetSelector* ts) {
            /*
             * NOTE:
             * For android, use your android market test account and ensure product id is correct
             * For iOS, use your iTunesConnect test account and ensure product id is correct
             */
            wyIAP::getInstance()->buy("com.wiyun.engine.iap.consumable");

            // show hint
            m_hint->setText("Purchasing product...");
        }

        virtual void onBuyProductFailed(const char* pid, wyIAPListener::Error code, const char* errorMsg) {
            char buf[512];
            sprintf(buf, "failed to buy product %s, error is: %s", pid, errorMsg == NULL ? "unknown" : errorMsg);
            m_hint->setText(buf);
        }

        virtual void onBuyProductOK(const char* pid, const void* receipt, size_t length) {
            char buf[512];
            sprintf(buf, "Product %s is bought!\nVerify receipt..., wait", pid);
            m_hint->setText(buf);

            /*
             * NOTE: fourth argument is true means verify the receipt in sandbox environment.
             * If a backend doesn't have sandbox mode, then any value is ok
             */
            wyIAP::getInstance()->verifyTransaction(pid, receipt, length, true);
        }

        virtual void onBuyProductRefunded(const char* pid, const void* receipt, size_t length) {
            char buf[512];
            sprintf(buf, "Product %s is refunded!\nVerify receipt..., wait", pid);
            m_hint->setText(buf);

            /*
             * NOTE: fourth argument is true means verify the receipt in sandbox environment.
             * If a backend doesn't have sandbox mode, then any value is ok.
             */
            wyIAP::getInstance()->verifyTransaction(pid, receipt, length, true);
        }

        virtual void onBuyProductRestored(const char* pid, const void* receipt, size_t length) {
            char buf[512];
            sprintf(buf, "Product %s was bought before, restore it", pid);
            m_hint->setText(buf);
        }

        virtual void onVerifyReceiptFailed(const char* pid, wyIAPListener::Error code, const char* errorMsg) {
            char buf[512];
            sprintf(buf, "Transaction failed to be verified, product id: %s", pid);
            m_hint->setText(buf);
        }

        virtual void onVerifyReceiptOK(const char* pid) {
            char buf[512];
            sprintf(buf, "Transaction is verified, product id: %s", pid);
            m_hint->setText(buf);
        }
	};

	/////////////////////////////////////////////////////////////////////////////////
}

using namespace IAP;

DEMO_ENTRY_IMPL(iap, IAPTest);
