package com.wiyun.engine.tests.box2d;

import java.util.ArrayList;
import java.util.Random;

import android.view.MotionEvent;

import com.wiyun.engine.R;
import com.wiyun.engine.WiEngineTestActivity;
import com.wiyun.engine.box2d.PELoader;
import com.wiyun.engine.box2d.Box2D;
import com.wiyun.engine.box2d.collision.EdgeShape;
import com.wiyun.engine.box2d.dynamics.Body;
import com.wiyun.engine.box2d.dynamics.BodyDef;
import com.wiyun.engine.box2d.dynamics.FixtureDef;
import com.wiyun.engine.box2d.dynamics.World;
import com.wiyun.engine.nodes.Director;
import com.wiyun.engine.nodes.Layer;
import com.wiyun.engine.nodes.Sprite;
import com.wiyun.engine.types.WYPoint;
import com.wiyun.engine.types.WYSize;
import com.wiyun.engine.utils.TargetSelector;
import com.wiyun.engine.utils.Utilities;

public class PhysicsEditorTest extends WiEngineTestActivity {
	@Override
	protected Layer createLayer() {
		return new MyLayer();
	}
		
	static String s_names[] = {
		"hotdog",
		"icecream",
		"icecream2",
		"icecream3",
		"hamburger",
		"drink",
		"orange"
	}; 
	
	static int s_resIds[] = {
		R.drawable.hotdog,
		R.drawable.icecream,
		R.drawable.icecream2,
		R.drawable.icecream3,
		R.drawable.hamburger,
		R.drawable.drink,
		R.drawable.orange
	};
    	
    class MyLayer extends Layer {
    	Box2D m_box2d;
    	World m_world;
    	ArrayList<Body> m_bodyList;
    	PELoader m_bodyLoader;
    	Random rand;

    	
		public MyLayer() {
			rand = new Random(10);
			m_bodyList = new ArrayList<Body>();
			setTouchEnabled(true);
			
			WYSize s = Director.getInstance().getWindowSize();
			m_box2d = Box2D.make();
			m_box2d.setDebugDraw(true);
			m_box2d.setPosition(0.0f, 0.0f);
			addChild(m_box2d);
			m_world = m_box2d.getWorld();
			m_world.setGravity(0, -10);
			
			m_bodyLoader = PELoader.make(R.raw.shapedefs_box2d);
			m_box2d.setMeterPixels(m_bodyLoader.getMeterPixels());
			
			float meterWidth = m_box2d.pixel2Meter(s.width);
			
			Body ground = null;
			BodyDef bd = BodyDef.make();
			ground = m_world.createBody(bd);
			bd.destroy();
			// bottom edge
			EdgeShape bottom = EdgeShape.make();
			bottom.setEndpoints(0, 0, meterWidth, 0);
			FixtureDef fd = FixtureDef.make();
			fd.setShape(bottom);
			ground.createFixture(fd);
			fd.destroy();

			schedule(new TargetSelector(this, "update(float)", new Object[] { 0f }));
		}
		
		public void update(float delta) {
			m_world.step(delta, 10, 10);
			m_world.clearForces();
			
			ArrayList<Body> bodyListToBeDelete = new ArrayList<Body>();
			for(Body body : m_bodyList) {
				//update sprite
				WYPoint pos = body.getPosition();
				float angle = body.getAngle();
				
				Sprite sprite = (Sprite) body.getUserData();
				sprite.setPosition(m_box2d.meter2Pixel(pos.x), m_box2d.meter2Pixel(pos.y));
				sprite.setRotation(-Utilities.r2d(angle));
			
				if(pos.y < 0) {
					bodyListToBeDelete.add(body);
				}									
			}
			
			for(Body body : bodyListToBeDelete) {
				Sprite sprite = (Sprite) body.getUserData();
				m_box2d.removeChild(sprite, true);
				m_world.destroyBody(body);
				m_bodyList.remove(body);
			}
			bodyListToBeDelete.clear();
		}
		
		private void addNewBody(float x, float y) {
			int i = Math.abs((rand.nextInt() % 7));
			float angle = ((float)(rand.nextLong()) % 360.0f);
			float radian = Utilities.d2r(angle);
			
			Body body = m_bodyLoader.createBodyByName(m_box2d, s_names[i]);
			
			m_bodyList.add(body);
			
			body.setTransform(m_box2d.pixel2Meter(x),m_box2d.pixel2Meter(y), radian);
			
			Sprite sprite = Sprite.make(s_resIds[i]);
			sprite.autoRelease();
			
			WYPoint anchor = m_bodyLoader.getAnchorPercent(s_names[i]);
			sprite.setAnchor(anchor.x, anchor.y);
			sprite.setPosition(x, y);
			sprite.setRotation(-angle);
			body.setUserData(sprite);
			m_box2d.addChild(sprite);
		}

		@Override
		public boolean wyTouchesBegan(MotionEvent event) {
			WYPoint loc = Director.getInstance().convertToGL(event.getX(), event.getY());
			addNewBody(loc.x, loc.y);
			return true;
		}
    }
}
