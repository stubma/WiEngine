#include "NetworkDemos.h"
#include "common.h"
#include "WiEngine.h"
#include "WiEngine-Network.h"
#include "WiEngine-JSON.h"

namespace Network {
	class wyDownloadImageTestLayer : public wyLayer, public wyHttpListener {
    private:
        wyProgressTimer* m_progressTimer;
        wySprite* m_bg;
        wyTexture2D* m_bgTex;
        
        // total length
        int m_totalBytes;
        int m_downloadedBytes;

        // asset output stream
        wyAssetOutputStream* m_output;

	public:
		wyDownloadImageTestLayer() :
                m_progressTimer(NULL),
                m_output(NULL),
                m_bg(NULL),
                m_bgTex(NULL) {
            // create button
            wyNinePatchSprite* normal = wyNinePatchSprite::make(wyTexture2D::makePNG(RES("R.drawable.btn_normal")), wyr(DP(9), DP(7), DP(22), DP(28)));
            wyNinePatchSprite* pressed = wyNinePatchSprite::make(wyTexture2D::makePNG(RES("R.drawable.btn_pressed")), wyr(DP(9), DP(7), DP(22), DP(28)));
            normal->setContentSize(DP(150), DP(44));
            pressed->setContentSize(DP(150), DP(44));
            wyButton* button = new wyButton(normal, pressed, NULL, NULL, NULL, wyTargetSelector::make(this, SEL(wyDownloadImageTestLayer::onDownloadStyle1)));
            button->setPosition(DP(80), wyDevice::winHeight - DP(30));
            addChildLocked(button, 1);
            button->release();
            
            // label for create button
            wyBitmapFont* font = wyBitmapFont::loadFont(RES("R.raw.bitmapfont"));
            wyBitmapFontLabel* label = wyBitmapFontLabel::make(font, "Style 1 BG");
            label->setColor(wyc3b(255, 255, 0));
            label->setPosition(DP(80), wyDevice::winHeight - DP(30));
            addChildLocked(label, 1);
            
            // destroy button
            button = new wyButton(normal, pressed, NULL, NULL, NULL, wyTargetSelector::make(this, SEL(wyDownloadImageTestLayer::onDownloadStyle2)));
            button->setPosition(DP(240), wyDevice::winHeight - DP(30));
            addChildLocked(button, 1);
            button->release();
            
            // label for destroy button
            label = wyBitmapFontLabel::make(font, "Style 2 BG");
            label->setColor(wyc3b(255, 255, 0));
            label->setPosition(DP(240), wyDevice::winHeight - DP(30));
            addChildLocked(label, 1);
            
            // init network, must be called
			wyNetwork::init();
		}

		virtual ~wyDownloadImageTestLayer() {
			// release stream
			if(m_output) {
				m_output->release();
				m_output = NULL;
			}

			// release texture
			if(m_bgTex)
				m_bgTex->release();

            // cleanup, must be called
			wyNetwork::cleanup();
		}
        
        void createProgressTimer() {
            m_progressTimer = wyProgressTimer::make(wyTexture2D::makePNG(RES("R.drawable.bar")));
            m_progressTimer->setPosition(wyDevice::winWidth / 2, wyDevice::winHeight / 2);
            m_progressTimer->setStyle(wyProgress::HORIZONTAL_BAR_LR);
            addChildLocked(m_progressTimer);
        }
        
        void deleteProgressTimer() {
            removeChildLocked(m_progressTimer, true);
            m_progressTimer = NULL;
        }
        
        void onDownloadStyle1(wyTargetSelector* ts) {
            if(m_progressTimer == NULL) {
                createProgressTimer();
                wyHttpRequest* request = wyHttpRequest::make("http://wiengine.wiyun.com/bg_style1.png");
                request->asyncExec(this);

                m_output = wyAssetOutputStream::make("/sdcard/WiEngine/bg_style1.png");
                m_output->retain();
            } else {
                wyToast::make("Already downloading, please wait...", 3.0f)->show();
            }
        }

        void onDownloadStyle2(wyTargetSelector* ts) {
            if(m_progressTimer == NULL) {
                createProgressTimer();
                wyHttpRequest* request = wyHttpRequest::make("http://wiengine.wiyun.com/bg_style2.png");
                request->asyncExec(this);

                m_output = wyAssetOutputStream::make("/sdcard/WiEngine/bg_style2.png");
                m_output->retain();
            } else {
                wyToast::make("Already downloading, please wait...", 3.0f)->show();
            }
        }

        virtual void onHttpReceiveResponse(wyHttpResponse* response) {
        	const char* contentLength = response->getHeader("Content-Length");
        	m_totalBytes = atoi(contentLength);
        	m_downloadedBytes = 0;
        	wyFree((void*)contentLength);
        }

        virtual void onHttpReceiveData(const char* buffer, size_t length) {
        	m_downloadedBytes += length;
            m_progressTimer->setPercentage(m_totalBytes == 0 ? 0 : (m_downloadedBytes * 100 / m_totalBytes));
            m_output->write(buffer, length);
        }

        virtual void onHttpFinishLoading(wyHttpResponse* response) {
        	deleteProgressTimer();

            // remove old bg
            if(m_bg != NULL) {
                removeChildLocked(m_bg, true);
                m_bg = NULL;
            }
            
            // remove old bg texture
            if(m_bgTex != NULL) {
                wyTextureManager::getInstance()->removeTexture(m_bgTex);
				m_bgTex->release();
                m_bgTex = NULL;
            }
            
            // create new bg
            m_bgTex = wyTexture2D::makeFilePNG(m_output->getPath());
			m_bgTex->retain();
            m_bg = wySprite::make(m_bgTex);
            m_bg->setPosition(wyDevice::winWidth / 2, wyDevice::winHeight / 2);
            m_bg->setContentSize(wyDevice::winWidth, wyDevice::winHeight);
            m_bg->setAutoFit(true);
            addChildLocked(m_bg, -1);

			// release stream
			if(m_output) {
				m_output->release();
				m_output = NULL;
			}
        }

        virtual void onHttpLoadingFailed(wyHttpResponse* response) {
			// release stream
			if(m_output) {
				m_output->release();
				m_output = NULL;
			}

        	deleteProgressTimer();
        }
	};

	///////////////////////////////////////////////////////////////////////////////////////////

	class wyIPQueryTestLayer : public wyLayer, public wyHttpListener {
	private:
        // asset output stream
        wyMemoryOutputStream* m_output;

	public:
		wyIPQueryTestLayer() : m_output(NULL) {
            // init network, must be called
			wyNetwork::init();

			// init member
			m_output = wyMemoryOutputStream::make();
			m_output->retain();

            // create button
            wyNinePatchSprite* normal = wyNinePatchSprite::make(wyTexture2D::makePNG(RES("R.drawable.btn_normal")), wyr(DP(9), DP(7), DP(22), DP(28)));
            wyNinePatchSprite* pressed = wyNinePatchSprite::make(wyTexture2D::makePNG(RES("R.drawable.btn_pressed")), wyr(DP(9), DP(7), DP(22), DP(28)));
            normal->setContentSize(DP(300), DP(44));
            pressed->setContentSize(DP(300), DP(44));
            wyButton* button = new wyButton(normal, pressed, NULL, NULL, NULL, wyTargetSelector::make(this, SEL(wyIPQueryTestLayer::onQueryIP)));
            button->setPosition(wyDevice::winWidth / 2, wyDevice::winHeight / 2 + DP(80));
            addChildLocked(button, 1);
            button->release();

            // label for create button
            wyBitmapFont* font = wyBitmapFont::loadFont(RES("R.raw.bitmapfont"));
            wyBitmapFontLabel* label = wyBitmapFontLabel::make(font, "Query IP: 202 111 23 3");
            label->setColor(wyc3b(255, 255, 0));
            label->setPosition(wyDevice::winWidth / 2, wyDevice::winHeight / 2 + DP(80));
            addChildLocked(label, 1);
		}

		virtual ~wyIPQueryTestLayer() {
			// release stream
			if(m_output) {
				m_output->release();
				m_output = NULL;
			}

			// cleanup, must be called when not using libcurl
			wyNetwork::cleanup();
		}

		void onQueryIP(wyTargetSelector* ts) {
			wyHttpRequest* request = wyHttpRequest::make("http://opendata.baidu.com/api.php");
			request->addParameter("query", "202.111.23.3");
			request->addParameter("resource_id", "6006");
			request->addParameter("ie", "utf-8");
			request->addParameter("oe", "utf-8");
			request->addParameter("format", "json");
			request->asyncExec(this);
		}

		virtual void onHttpReceiveResponse(wyHttpResponse* response) {
			m_output->reset();
		}

        virtual void onHttpReceiveData(const char* buffer, size_t length) {
        	m_output->write(buffer, length);
        }

        virtual void onHttpFinishLoading(wyHttpResponse* response) {
        	wyJSONObject* jo = wyJSONObject::make(m_output->getBuffer(), m_output->getLength());
        	wyJSONArray* ja = jo->optJSONArray("data");
        	jo = ja->optJSONObject(0);
        	wyToast::make(jo->optString("location"), 3.0f)->show();
        }

        virtual void onHttpLoadingFailed(wyHttpResponse* response) {
        	wyToast::make("failed to query IP address", 3.0f)->show();
        }
	};

	///////////////////////////////////////////////////////////////////////////////////////////

	class wyHttpPostTestLayer : public wyLayer, public wyHttpListener {
	private:
        // asset output stream
        wyMemoryOutputStream* m_output;

	public:
        wyHttpPostTestLayer() : m_output(NULL) {
            // init network, must be called
			wyNetwork::init();

			// init member
			m_output = wyMemoryOutputStream::make();
			m_output->retain();

            // create button
            wyNinePatchSprite* normal = wyNinePatchSprite::make(wyTexture2D::makePNG(RES("R.drawable.btn_normal")), wyr(DP(9), DP(7), DP(22), DP(28)));
            wyNinePatchSprite* pressed = wyNinePatchSprite::make(wyTexture2D::makePNG(RES("R.drawable.btn_pressed")), wyr(DP(9), DP(7), DP(22), DP(28)));
            normal->setContentSize(DP(300), DP(44));
            pressed->setContentSize(DP(300), DP(44));
            wyButton* button = new wyButton(normal, pressed, NULL, NULL, NULL, wyTargetSelector::make(this, SEL(wyHttpPostTestLayer::onPost)));
            button->setPosition(wyDevice::winWidth / 2, wyDevice::winHeight / 2 + DP(80));
            addChildLocked(button, 1);
            button->release();

            // label for create button
            wyBitmapFont* font = wyBitmapFont::loadFont(RES("R.raw.bitmapfont"));
            wyBitmapFontLabel* label = wyBitmapFontLabel::make(font, "Do POST Operation");
            label->setColor(wyc3b(255, 255, 0));
            label->setPosition(wyDevice::winWidth / 2, wyDevice::winHeight / 2 + DP(80));
            addChildLocked(label, 1);
		}

		virtual ~wyHttpPostTestLayer() {
			// release stream
			if(m_output) {
				m_output->release();
				m_output = NULL;
			}

			// cleanup, must be called when not using libcurl
			wyNetwork::cleanup();
		}

		void onPost(wyTargetSelector* ts) {
			wyHttpRequest* request = wyHttpRequest::make("http://www.snee.com/xml/crud/posttest.cgi", wyHttpRequest::POST);
			request->addParameter("fname", "a");
			request->addParameter("lname", "b");
			request->asyncExec(this);
		}

		virtual void onHttpReceiveResponse(wyHttpResponse* response) {
			m_output->reset();
		}

        virtual void onHttpReceiveData(const char* buffer, size_t length) {
        	m_output->write(buffer, length);
        }

        virtual void onHttpFinishLoading(wyHttpResponse* response) {
        	wyToast::make("Finish loading, response body is output to log", 3.0f)->show();
        	LOGD("%s", m_output->getBuffer());
        }

        virtual void onHttpLoadingFailed(wyHttpResponse* response) {
        	wyToast::make("failed to perform post operation", 3.0f)->show();
        }
	};

	///////////////////////////////////////////////////////////////////////////////////////////
}

using namespace Network;

DEMO_ENTRY_IMPL(network, DownloadImageTest);
DEMO_ENTRY_IMPL(network, HttpPostTest);
DEMO_ENTRY_IMPL(network, IPQueryTest);
