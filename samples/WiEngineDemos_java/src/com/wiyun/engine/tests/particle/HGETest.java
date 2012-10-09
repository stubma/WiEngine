package com.wiyun.engine.tests.particle;

import android.view.MotionEvent;

import com.wiyun.engine.R;
import com.wiyun.engine.WiEngineTestActivity;
import com.wiyun.engine.nodes.ColorLayer;
import com.wiyun.engine.nodes.Director;
import com.wiyun.engine.nodes.Layer;
import com.wiyun.engine.opengl.Texture2D;
import com.wiyun.engine.particle.HGEParticleLoader;
import com.wiyun.engine.particle.ParticleSystem;
import com.wiyun.engine.types.WYColor4B;
import com.wiyun.engine.types.WYPoint;
import com.wiyun.engine.types.WYSize;


public class HGETest extends WiEngineTestActivity {
	@Override
	protected Layer createLayer() {
		return new MyLayer();
	}

	class MyLayer extends ColorLayer {
		private ParticleSystem emitter;

		public MyLayer() {
			super(new WYColor4B(0, 0, 0, 255));
			setTouchEnabled(true);

			// create particle system
			emitter = HGEParticleLoader.load(R.raw.hgeparticle1, 200, Texture2D.makePNG(R.drawable.hgeparticles_8));
			addChild(emitter);

			setEmitterPosition();
		}

		private void setEmitterPosition() {
			WYSize s = Director.getInstance().getWindowSize();
			emitter.setPosition(s.width / 2, s.height / 2);
		}
		
		@Override
		public boolean wyTouchesBegan(MotionEvent event) {
			WYPoint loc = Director.getInstance().convertToGL(event.getX(), event.getY());
			emitter.setPosition(loc.x, loc.y);
			return true;
		}
	}
}