#include "FirstScene.h"
#include "WiEngine.h"

class ParticleSnowSystem : public wyQuadParticleSystem {
public:
	ParticleSnowSystem() : wyQuadParticleSystem(700) {
		// duration
		setDuration(PARTICLE_DURATION_INFINITY);

		// gravity
		setParticleGravity(0, -10);

		// angle
		setDirectionAngleVariance(-90, 5);

		// speed of particles
		setSpeedVariance(130, 30);

		// radial
		setRadialAccelerationVariance(0, 1);

		// tagential
		setTangentialAccelerationVariance(0, 1);

		// emitter position
		setParticlePositionVariance(0, 0, wyDevice::winWidth / 2, 0);

		// life of particles
		setLifeVariance(3, 1);

		// size, in pixels
		setStartSizeVariance(10, 5);

		// emits per second
		setEmissionRate(getMaxParticles() / getLife());

		// color of particles
		setStartColorVariance(0.9f, 0.9f, 0.9f, 1.0f, 0.0f, 0.0f, 0.1f, 0.0f);
		setEndColorVariance(1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);

		//set texture
		setTexture(wyTexture2D::makePNG(RES("R.drawable.snow")));
	}
};

class ParticleFlowerSystem : public wyQuadParticleSystem {
public:
	ParticleFlowerSystem() : wyQuadParticleSystem(250){
        // duration
        setDuration(1.0f);

        // angle
        setDirectionAngleVariance(90, 360);

        // speed of particles
        setSpeedVariance(80, 10);

        // radial
        setRadialAccelerationVariance(-60, 0);

        // tagential
        setTangentialAccelerationVariance(15, 0);

        // life of particles
        setLifeVariance(4, 1);

        // size, in pixels
        setStartSizeVariance(30.0f, 10.0f);

        // emits per second
        setEmissionRate(getMaxParticles() / getLife());

        // color of particles
        setStartColorVariance(0.5f, 0.5f, 0.5f, 1.0f, 0.5f, 0.5f, 0.5f, 0.5f);
        setEndColorVariance(0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);

        //set texture
        setTexture(wyTexture2D::makePNG(RES("R.drawable.stars")));

    	// additive
    	setBlendMode(wyRenderState::ALPHA_ADDITIVE);
	}
};

static void onSurfaceChanged(int w, int h, void* data) {
	wyParticleSystem* emitter = (wyParticleSystem*)data;
	emitter->setPosition(w / 2, h);
}

// life cycle listener
static const wyDirectorLifecycleListener s_surfaceLifeCycleListener = {
	NULL,
	onSurfaceChanged,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL
};

FirstScene::FirstScene() {
	// create particle system
	m_emitter = new ParticleSnowSystem();
	addChildLocked(m_emitter);
	m_emitter->release();

	// create click emitter
	m_clickEmitter = new ParticleFlowerSystem();
	m_clickEmitter->stopSystem();
	addChildLocked(m_clickEmitter);
	m_clickEmitter->release();

	// set emitter position
	setEmitterPosition();

	// add life cycle listener
	wyDirector* director = wyDirector::getInstance();
	director->addLifecycleListener(&s_surfaceLifeCycleListener, m_emitter);

	// enable touch
	setTouchEnabled(true);
}

FirstScene::~FirstScene() {
}

void FirstScene::setEmitterPosition() {
	wyPoint c = m_emitter->getCenterOfGravity();
	if(c.x == 0 && c.y == 0) {
		m_emitter->setPosition(wyDevice::winWidth / 2, wyDevice::winHeight);
	}
}

bool FirstScene::touchesBegan(wyMotionEvent& e) {
	m_clickEmitter->setPosition(e.x[0], e.y[0]);
	m_clickEmitter->resetSystem();
	return false;
}
