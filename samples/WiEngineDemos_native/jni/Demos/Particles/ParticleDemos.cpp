#include "common.h"
#include "ParticleDemos.h"

#include "WiEngine.h"
#include <stdio.h>

namespace Particle {

	class ParticleBigFlowerSystem : public wyQuadParticleSystem {
	public:
		ParticleBigFlowerSystem() : wyQuadParticleSystem(50){
	    	// duration
	        setDuration(PARTICLE_DURATION_INFINITY);

	    	// Gravity Mode: speed of particles
	        setSpeedVariance(160, 20);

	    	// Gravity Mode: radial
	        setRadialAccelerationVariance(-120, 0);

	    	// Gravity Mode: tagential
	        setTangentialAccelerationVariance(30, 0);

	    	// angle
	        setDirectionAngleVariance(90, 360);

	    	// life of particles
	        setLifeVariance(4, 1);

	        // color of particles
	        setStartColorVariance(0.5f, 0.5f, 0.5f, 1.0f, 0.5f, 0.5f, 0.5f, 1.0f);
	        setEndColorVariance(0.1f, 0.1f, 0.1f, 0.2f, 0.1f, 0.1f, 0.1f, 0.2f);

	    	// size, in pixels
	        setStartSizeVariance(80.0f, 40.0f);
	        setEndSizeVariance(PARTICLE_START_SIZE_EQUAL_TO_END_SIZE, 0);

	    	// emits per second
	        setEmissionRate(getMaxParticles() / getLife());

	        //set texture
	        setTexture(wyTexture2D::make(RES("R.drawable.stars")));

	    	// additive
	    	setBlendAdditive(true);
		}
	};

	class ParticleExplosionSystem : public wyQuadParticleSystem {
	public:
		ParticleExplosionSystem() : wyQuadParticleSystem(700){
	        // duration
	        setDuration(0.1f);

	        // gravity
	        setParticleGravity(0, -100);

	        // angle
	        setDirectionAngleVariance(90, 360);

	        // speed of particles
	        setSpeedVariance(70, 40);

	        // life of particles
	        setLifeVariance(5.0f, 2.0f);

	        // size, in pixels
	        setStartSizeVariance(15.0f, 10.0f);

	        // emits per second
	        setEmissionRate(getMaxParticles() / getDuration());

	        // color of particles
	        setStartColorVariance(0.7f, 0.1f, 0.2f, 1.0f, 0.5f, 0.5f, 0.5f, 0.0f);
	        setEndColorVariance(0.5f, 0.5f, 0.5f, 0.0f, 0.5f, 0.5f, 0.5f, 0.0f);

	        //set texture
	        setTexture(wyTexture2D::make(RES("R.drawable.stars")));
		}
	};

	class ParticleFireSystem : public wyQuadParticleSystem {
	public:
		ParticleFireSystem() : wyQuadParticleSystem(250){
	        // duration
	        setDuration(PARTICLE_DURATION_INFINITY);

	        // angle
	        setDirectionAngleVariance(90, 10);

	        // life of particles
	        setLifeVariance(3.0f, 0.25f);

	        // speed of particles
	        setSpeedVariance(60, 20);

	        // size, in pixels
	        setStartSizeVariance(100.0f, 10.0f);

	        // emits per frame
	        setEmissionRate(getMaxParticles() / getLife());

	        // color of particles
	        setStartColorVariance(0.76f, 0.25f, 0.12f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
	        setEndColorVariance(0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);

	        //set texture
	        setTexture(wyTexture2D::make(RES("R.drawable.fire")));

	    	// additive
	    	setBlendAdditive(true);
		}
	};

	class ParticleFireworkSystem : public wyQuadParticleSystem {
	public:
		ParticleFireworkSystem() : wyQuadParticleSystem(300){
			// duration
			setDuration(PARTICLE_DURATION_INFINITY);

			// gravity
			setParticleGravity(0, -90);

			// angle
			setDirectionAngleVariance(90, 20);

			// speed of particles
			setSpeedVariance(180, 50);

			// life of particles
			setLifeVariance(3.5f, 1.0f);

			// emits per frame
			setEmissionRate(getMaxParticles() / getLife());

			// color of particles
			setStartColorVariance(0.5f, 0.5f, 0.5f, 1.0f, 0.5f, 0.5f, 0.5f, 1.0f);
			setEndColorVariance(0.1f, 0.1f, 0.1f, 0.2f, 0.1f, 0.1f, 0.1f, 0.2f);

			// size, in pixels
			setStartSizeVariance(8.0f, 2.0f);
			setEndSizeVariance(PARTICLE_START_SIZE_EQUAL_TO_END_SIZE, 0);

	    	// emits per second
	        setEmissionRate(getMaxParticles() / getLife());

	        //set texture
	        setTexture(wyTexture2D::make(RES("R.drawable.fire")));

	    	// additive
	    	setBlendAdditive(false);
		}
	};

	class ParticleFlowerSystem : public wyQuadParticleSystem {
	public:
		ParticleFlowerSystem() : wyQuadParticleSystem(250){
	        // duration
	        setDuration(PARTICLE_DURATION_INFINITY);

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
	        setTexture(wyTexture2D::make(RES("R.drawable.stars")));

	    	// additive
	    	setBlendAdditive(true);
		}
	};

	class ParticleGalaxySystem : public wyQuadParticleSystem {
	public:
		ParticleGalaxySystem() : wyQuadParticleSystem(200){
	        // duration
	        setDuration(PARTICLE_DURATION_INFINITY);

	        // angle
	        setDirectionAngleVariance(90, 360);

	        // speed of particles
	        setSpeedVariance(60, 10);

	        // radial
	        setRadialAccelerationVariance(-80, 0);

	        // tagential
	        setTangentialAccelerationVariance(80, 0);

	        // life of particles
	        setLifeVariance(4, 1);

	        // size, in pixels
	        setStartSizeVariance(37.0f, 10.0f);

	        // emits per second
	        setEmissionRate(getMaxParticles() / getLife());

	        // color of particles
	        setStartColorVariance(0.12f, 0.25f, 0.76f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
	        setEndColorVariance(0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);

	        //set texture
	        setTexture(wyTexture2D::make(RES("R.drawable.fire")));

	    	// additive
	    	setBlendAdditive(true);
		}
	};

	class ParticleMeteorSystem : public wyQuadParticleSystem {
	public:
		ParticleMeteorSystem() : wyQuadParticleSystem(150) {
	        // duration
	        setDuration(PARTICLE_DURATION_INFINITY);

	        // gravity
	        setParticleGravity(DP(-133.33f), DP(133.33f));

	        // angle
	        setDirectionAngleVariance(90, 360);

	        // speed of particles
	        setSpeedVariance(DP(10), DP(3.33f));

	        // life of particles
	        setLifeVariance(2, 1);

	        // size, in pixels
	        setStartSizeVariance(DP(40.0f), DP(6.6f));

	        // emits per second
	        setEmissionRate(getMaxParticles() / getLife());

	        // color of particles
	        setStartColorVariance(0.2f, 0.4f, 0.7f, 1.0f, 0.0f, 0.0f, 0.2f, 0.1f);
	        setEndColorVariance(0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);

	        //set texture
	        setTexture(wyTexture2D::make(RES("R.drawable.fire")));

	    	// additive
	    	setBlendAdditive(true);
		}
	};

	class ParticleModernArtSystem : public wyQuadParticleSystem {
	public:
		ParticleModernArtSystem() : wyQuadParticleSystem(1000){
			// duration
	        setDuration(PARTICLE_DURATION_INFINITY);

			// Gravity mode: radial
	        setRadialAccelerationVariance(70, 10);

			// Gravity mode: tangential
	        setTangentialAccelerationVariance(80, 0);

			// Gravity mode: speed of particles
	        setSpeedVariance(50, 10);

			// angle
	        setDirectionAngleVariance(0, 360);

			// life of particles
	        setLifeVariance(2.0f, 0.3f);

			// emits per frame
	        setEmissionRate(getMaxParticles() / getLife());

	        // color of particles
	        setStartColorVariance(0.5f, 0.5f, 0.5f, 1.0f, 0.5f, 0.5f, 0.5f, 1.0f);
	        setEndColorVariance(0.1f, 0.1f, 0.1f, 0.2f, 0.1f, 0.1f, 0.1f, 0.2f);

			// size, in pixels
	        setStartSizeVariance(1.0f, 1.0f);
	        setEndSizeVariance(32.0f, 8.0f);

	        //set texture
	        setTexture(wyTexture2D::make(RES("R.drawable.fire")));

	    	// additive
	    	setBlendAdditive(false);
		}
	};

	class ParticleRainSystem : public wyQuadParticleSystem {
	public:
		ParticleRainSystem() : wyQuadParticleSystem(1000){
	        // duration
	        setDuration(PARTICLE_DURATION_INFINITY);

	        // gravity
	        setParticleGravity(10, -10);

	        // angle
	        setDirectionAngleVariance(-90, 5);

	        // speed of particles
	        setSpeedVariance(130, 30);

	        // radial
	        setRadialAccelerationVariance(0, 1);

	        // tagential
	        setTangentialAccelerationVariance(0, 1);

	        setParticlePositionVariance(0, 0, wyDevice::winWidth/2, 0);

	        // life of particles
	        setLifeVariance(4.5f, 0);

	        // size, in pixels
	        setStartSizeVariance(4.0f, 2.0f);

	        // emits per second
	        setEmissionRate(20);

	        // color of particles
	        setStartColorVariance(0.7f, 0.8f, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
	        setEndColorVariance(0.7f, 0.8f, 1.0f, 0.5f, 0.0f, 0.0f, 0.0f, 0.0f);

	        //set texture
	        setTexture(wyTexture2D::make(RES("R.drawable.stars")));

	    	// additive
	    	setBlendAdditive(false);
		}
	};

	class ParticleRingSystem : public wyQuadParticleSystem {
	public:
		ParticleRingSystem() : wyQuadParticleSystem(250){
	        // duration
	        setDuration(PARTICLE_DURATION_INFINITY);

	        // angle
	        setDirectionAngleVariance(90, 360);

	        // speed of particles
	        setSpeedVariance(100, 0);

	        // radial
	        setRadialAccelerationVariance(-60, 0);

	        // tagential
	        setTangentialAccelerationVariance(15, 0);

	        // life of particles
	        setLifeVariance(10, 0);

	        // size, in pixels
	        setStartSizeVariance(30.0f, 10.0f);

	        // emits per second
	        setEmissionRate(10000);

	        // color of particles
	        setStartColorVariance(0.5f, 0.5f, 0.5f, 1.0f, 0.5f, 0.5f, 0.5f, 0.5f);
	        setEndColorVariance(0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);

	        //set texture
	        setTexture(wyTexture2D::make(RES("R.drawable.stars")));

	    	// additive
	    	setBlendAdditive(true);
		}
	};

	class ParticleRotateFlowerSystem : public wyQuadParticleSystem {
	public:
		ParticleRotateFlowerSystem() : wyQuadParticleSystem(50){
	    	// duration
	        setDuration(PARTICLE_DURATION_INFINITY);

	    	// Gravity mode: speed of particles
	        setSpeedVariance(160, 20);

	    	// Gravity mode: radial
	        setRadialAccelerationVariance(-120, 0);

	    	// Gravity mode: tagential
	        setTangentialAccelerationVariance(30, 0);

	    	// angle
	        setDirectionAngleVariance(90, 360);

	    	// life of particles
	        setLifeVariance(3, 1);

	    	// spin of particles
	        setEndSpinVariance(0, 2000);

	        // color of particles
	        setStartColorVariance(0.5f, 0.5f, 0.5f, 1.0f, 0.5f, 0.5f, 0.5f, 1.0f);
	        setEndColorVariance(0.1f, 0.1f, 0.1f, 0.2f, 0.1f, 0.1f, 0.1f, 0.2f);

	    	// size, in pixels
	        setStartSizeVariance(30, 0);
	        setEndSizeVariance(PARTICLE_START_SIZE_EQUAL_TO_END_SIZE, 0);

	    	// emits per second
	        setEmissionRate(getMaxParticles() / getLife());

	        //set texture
	        setTexture(wyTexture2D::make(RES("R.drawable.stars2")));

	    	// additive
	    	setBlendAdditive(false);
		}
	};

	class ParticleSmokeSystem : public wyQuadParticleSystem {
	public:
		ParticleSmokeSystem() : wyQuadParticleSystem(200){
	        // duration
	        setDuration(PARTICLE_DURATION_INFINITY);

	        // angle
	        setDirectionAngleVariance(90, 5);

	        // position var
	        setParticlePositionVariance(0, 0, 20, 0);

	        // life of particles
	        setLifeVariance(4, 1);

	        // speed of particles
	        setSpeedVariance(25, 10);

	        // size, in pixels
	        setStartSizeVariance(60, 10);

	        // emits per frame
	        setEmissionRate(getMaxParticles() / getLife());

	        // color of particles
	        setStartColorVariance(0.8f, 0.8f, 0.8f, 1.0f, 0.02f, 0.02f, 0.02f, 0.0f);
	        setEndColorVariance(0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);

	        //set texture
	        setTexture(wyTexture2D::make(RES("R.drawable.fire")));

	    	// additive
	    	setBlendAdditive(false);
		}
	};

	class ParticleSnowSystem : public wyQuadParticleSystem {
	public:
		ParticleSnowSystem() : wyQuadParticleSystem(700){
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
	        setTexture(wyTexture2D::make(RES("R.drawable.snow")));

	    	// additive
	    	setBlendAdditive(false);
		}
	};

	class ParticleSpiralSystem : public wyQuadParticleSystem {
	public:
		ParticleSpiralSystem() : wyQuadParticleSystem(500){
	        // duration
	        setDuration(PARTICLE_DURATION_INFINITY);

	        // angle
	        setDirectionAngleVariance(90, 0);

	        // speed of particles
	        setSpeedVariance(150, 0);

	        // radial
	        setRadialAccelerationVariance(-380, 0);

	        // tagential
	        setTangentialAccelerationVariance(45, 0);

	        // life of particles
	        setLifeVariance(12, 0);

	        // size, in pixels
	        setStartSizeVariance(20, 0);

	        // emits per second
	        setEmissionRate(getMaxParticles() / getLife());

	        // color of particles
	        setStartColorVariance(0.5f, 0.5f, 0.5f, 1.0f, 0.5f, 0.5f, 0.5f, 0.0f);
	        setEndColorVariance(0.5f, 0.5f, 0.5f, 1.0f, 0.5f, 0.5f, 0.5f, 0.0f);

	        //set texture
	        setTexture(wyTexture2D::make(RES("R.drawable.fire")));

	    	// additive
	    	setBlendAdditive(false);
		}
	};

	class ParticleSunSystem : public wyQuadParticleSystem {
	public:
		ParticleSunSystem() : wyQuadParticleSystem(350){
	        // additive
	        setBlendAdditive(true);

	        // duration
	        setDuration(PARTICLE_DURATION_INFINITY);

	        // angle
	        setDirectionAngleVariance(90, 360);

	        // life of particles
	        setLifeVariance(1.0f, 0.5f);

	        // speed of particles
	        setSpeedVariance(20, 5);

	        // size, in pixels
	        setStartSizeVariance(30, 10);

	        // emits per seconds
	        setEmissionRate(getMaxParticles() / getLife());

	        // color of particles
	        setStartColorVariance(0.76f, 0.25f, 0.12f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
	        setEndColorVariance(0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);

	        //set texture
	        setTexture(wyTexture2D::make(RES("R.drawable.fire")));
		}
	};

	class wyParticleTestLayer: public wyLayer {
	protected:
		wyParticleSystem* m_Emitter;

	public:
		wyParticleTestLayer() {};
		virtual ~wyParticleTestLayer() {}

		void setEmitterPosition(){
			m_Emitter->setPosition(wyDevice::winWidth / 2, wyDevice::winHeight / 2);
		}

        bool touchesBegan(wyMotionEvent& event) {
        	m_Emitter->setPosition(event.x[0], event.y[0]);
        	return true;
        }
        
        void setup() {
			m_Emitter = createParticleSystem();
			addChildLocked(m_Emitter);
			setEmitterPosition();
			setTouchEnabled(true);
        }

        virtual wyParticleSystem* createParticleSystem() = 0;
	};
	
	class wyParticleDesignerTestLayer : public wyParticleTestLayer {
	public:
		wyParticleDesignerTestLayer() {}
		virtual ~wyParticleDesignerTestLayer() {}

		virtual wyParticleSystem* createParticleSystem() {
			return wyParticleLoader::load(RES("R.raw.test_particle_designer"));
		}
	};

	class wyHGETestLayer : public wyParticleTestLayer {
	public:
		wyHGETestLayer() {}
		virtual ~wyHGETestLayer() {}

		virtual wyParticleSystem* createParticleSystem() {
			return wyHGEParticleLoader::load(RES("R.raw.hgeparticle1"), 200, wyTexture2D::make(RES("R.drawable.hgeparticles_8")));
		}
	};

	#define DEMO_LAYER(classname) \
		class wy##classname##TestLayer : public wyParticleTestLayer { \
		public: \
			wy##classname##TestLayer() {} \
			virtual ~wy##classname##TestLayer() {} \
			\
			virtual wyParticleSystem* createParticleSystem() { \
				wyParticleSystem* system = new Particle##classname##System(); \
				return (wyParticleSystem*)system->autoRelease(); \
			} \
		};

	DEMO_LAYER(BigFlower);
	DEMO_LAYER(Explosion);
	DEMO_LAYER(Fire);
	DEMO_LAYER(Firework);
	DEMO_LAYER(Flower);
	DEMO_LAYER(Galaxy);
	DEMO_LAYER(Meteor);
	DEMO_LAYER(ModernArt);
	DEMO_LAYER(Rain);
	DEMO_LAYER(Ring);
	DEMO_LAYER(RotateFlower);
	DEMO_LAYER(Smoke);
	DEMO_LAYER(Snow);
	DEMO_LAYER(Spiral);
	DEMO_LAYER(Sun);
}

using namespace Particle;

#if ANDROID
	#define DEMO_ENTRY_IMPL(CLASSNAME) JNIEXPORT void JNICALL Java_com_wiyun_engine_tests_particle_##CLASSNAME##_nativeStart \
		(JNIEnv *env, jobject thiz){ \
			wyParticleTestLayer* layer = new wy##CLASSNAME##Layer(); \
			layer->setup(); \
			runDemo(layer, NULL); \
			wyObjectRelease(layer); \
		}
#elif IOS || MACOSX || WINDOWS
	#define DEMO_ENTRY_IMPL(CLASSNAME) void _particle_##CLASSNAME##Launcher() { \
			wyParticleTestLayer* layer = new wy##CLASSNAME##Layer(); \
			layer->setup(); \
			runDemo(layer, NULL); \
			wyObjectRelease(layer); \
		}
#endif

DEMO_ENTRY_IMPL(BigFlowerTest);
DEMO_ENTRY_IMPL(ExplosionTest);
DEMO_ENTRY_IMPL(FireTest);
DEMO_ENTRY_IMPL(FireworkTest);
DEMO_ENTRY_IMPL(FlowerTest);
DEMO_ENTRY_IMPL(GalaxyTest);
DEMO_ENTRY_IMPL(HGETest);
DEMO_ENTRY_IMPL(MeteorTest);
DEMO_ENTRY_IMPL(ModernArtTest);
DEMO_ENTRY_IMPL(ParticleDesignerTest);
DEMO_ENTRY_IMPL(RainTest);
DEMO_ENTRY_IMPL(RingTest);
DEMO_ENTRY_IMPL(RotateFlowerTest);
DEMO_ENTRY_IMPL(SmokeTest);
DEMO_ENTRY_IMPL(SnowTest);
DEMO_ENTRY_IMPL(SpiralTest);
DEMO_ENTRY_IMPL(SunTest);
