#ifndef __FirstScene_h__
#define __FirstScene_h__

#include "wyScene.h"
#include "WiEngine-Classes.h"

class FirstScene : public wyScene {
private:
	wyParticleSystem* m_emitter;
	wyParticleSystem* m_clickEmitter;

private:
	void setEmitterPosition();

public:
    FirstScene();
    virtual ~FirstScene();

    virtual bool touchesBegan(wyMotionEvent& e);
};

#endif // __FirstScene_h__
