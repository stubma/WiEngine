package com.wiyun.engine.tests.node;

import static com.wiyun.engine.utils.Utilities.randZeroToOne;

import java.util.Random;

import android.view.MotionEvent;

import com.wiyun.engine.R;
import com.wiyun.engine.WiEngineTestActivity;
import com.wiyun.engine.nodes.Director;
import com.wiyun.engine.nodes.Layer;
import com.wiyun.engine.nodes.Sprite;
import com.wiyun.engine.opengl.Texture2D;
import com.wiyun.engine.types.WYPoint;
import com.wiyun.engine.types.WYRect;
import com.wiyun.engine.types.WYSize;
import com.wiyun.engine.utils.ResolutionIndependent;

public class AtlasSpriteTest extends WiEngineTestActivity {
	@Override
	protected Layer createLayer() {
		return new MyLayer();
	}

	private static float ITEM_WIDTH = 0;
	private static float ITEM_HEIGHT = 0;
	
    class MyLayer extends Layer {
        Texture2D m_tex;
        
        public MyLayer() {
            float x, y;
            
            // set width and height
            ITEM_WIDTH = ResolutionIndependent.resolveDp(85);
            ITEM_HEIGHT = ResolutionIndependent.resolveDp(121);

            WYSize s = Director.getInstance().getWindowSize();
            x = s.width;
            y = s.height;

            m_tex = Texture2D.makePNG(R.drawable.grossini_dance_atlas);
            m_tex.autoRelease();
            addNewSprite(WYPoint.make(x / 2, y / 2));
            
            // enable touch
            setTouchEnabled(true);
        }
        
        private void addNewSprite(WYPoint pos) {
            Random random = new Random();
            
            float rnd = randZeroToOne() * 1400.0f / 100.0f;
            int idx = (int) rnd;
            float x = (idx % 5) * ITEM_WIDTH;
            float y = (idx / 5) * ITEM_HEIGHT;
            Sprite sprite = Sprite.make(m_tex, WYRect.make(x, y, ITEM_WIDTH, ITEM_HEIGHT));
            sprite.autoRelease();
        	sprite.setFlipX(random.nextBoolean());
        	sprite.setFlipY(random.nextBoolean());
        	sprite.setRotation(random.nextFloat() * 360f);
            addChild(sprite);

            sprite.setPosition(pos.x, pos.y);
        }
        
        @Override
        public boolean wyTouchesBegan(MotionEvent event) {
            WYPoint location = Director.getInstance().convertToGL(event.getX(), event.getY());

            addNewSprite(location);

            return true;
        }
    }
}
