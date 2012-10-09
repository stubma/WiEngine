package com.wiyun.engine.tests.chipmunk;

import java.util.ArrayList;
import java.util.Random;

import android.view.MotionEvent;

import com.wiyun.engine.R;
import com.wiyun.engine.WiEngineTestActivity;
import com.wiyun.engine.chipmunk.Body;
import com.wiyun.engine.chipmunk.PELoader;
import com.wiyun.engine.chipmunk.Chipmunk;
import com.wiyun.engine.chipmunk.Segment;
import com.wiyun.engine.chipmunk.Shape;
import com.wiyun.engine.chipmunk.Space;
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
    	Chipmunk m_chipmunk;
    	Space m_space;
    	ArrayList<Body> m_bodyList;
    	PELoader m_bodyLoader;
    	Random rand;

    	
		public MyLayer() {
			rand = new Random(10);
			m_bodyList = new ArrayList<Body>();
			setTouchEnabled(true);
			
			WYSize s = Director.getInstance().getWindowSize();
			m_chipmunk = Chipmunk.make();
			m_chipmunk.setDebugDraw(true);
			m_chipmunk.setPosition(0.0f, 0.0f);
			addChild(m_chipmunk);
			
			Shape.resetShapeIdCounter();

			m_space = m_chipmunk.getSpace();
			m_space.setIterations(10);
			m_space.setGravity(0, -100);
			
			Body staticBody = Body.makeStatic();
			
			// Create A ground segment along the border of the screen
			Shape shape = Segment.make(staticBody, 0, 0, s.width, 0, 2);
			shape.setRestitution(1);
			shape.setFriction(1);
			shape.setLayerMask(Chipmunk.NOT_GRABABLE_MASK);
			m_space.addStaticShape(shape);
			
			m_bodyLoader = PELoader.make(R.raw.shapedefs_chipmunk);

			schedule(new TargetSelector(this, "update(float)", new Object[] { 0f }));
		}
		
		public void update(float delta) {
			m_space.step(delta);
			
			ArrayList<Body> bodyListToBeDelete = new ArrayList<Body>();
			for(Body body : m_bodyList) {
				//update sprite
				float posX = body.getPositionX();
				float posY = body.getPositionY();
				float angle = body.getAngle();
				
				Sprite sprite = (Sprite) body.getData();
				sprite.setPosition(posX, posY);
				sprite.setRotation(-Utilities.r2d(angle));
				
				
				
				if(posY < 0) {
					bodyListToBeDelete.add(body);
				}									
			}
			
			for(Body body : bodyListToBeDelete) {
				Sprite sprite = (Sprite) body.getData();
				m_chipmunk.removeChild(sprite, true);
				m_space.removeAndDestroyShapesOfBody(body);
				m_space.removeAndDestroyBody(body);
				m_bodyList.remove(body);				
			}
			bodyListToBeDelete.clear();
		}
		
		private void addNewBody(float x, float y) {
			int i = Math.abs((rand.nextInt() % 7));
			float angle = ((float)(rand.nextLong()) % 360.0f);
			float radian = Utilities.d2r(angle);
			
			Body body = m_bodyLoader.createBodyByName(m_chipmunk, s_names[i]);
			Sprite sprite = Sprite.make(s_resIds[i]);
			sprite.autoRelease();
			m_chipmunk.addChild(sprite);
			WYPoint anchor = m_bodyLoader.getAnchorPercent(s_names[i]);
			sprite.setAnchor(anchor.x, anchor.y);
			
			m_bodyList.add(body);
			
			body.setAngle(radian);
			body.setPosition(x, y);
			sprite.setPosition(x, y);
			sprite.setRotation(-angle);
			body.setData(sprite);
		}

		@Override
		public boolean wyTouchesBegan(MotionEvent event) {
			WYPoint loc = Director.getInstance().convertToGL(event.getX(), event.getY());
			addNewBody(loc.x, loc.y);
			return true;
		}
    }
}
