package com.wiyun.engine.tests.other;

import java.util.Random;

import android.view.MotionEvent;

import com.wiyun.engine.R;
import com.wiyun.engine.WiEngineTestActivity;
import com.wiyun.engine.nodes.Director;
import com.wiyun.engine.nodes.Layer;
import com.wiyun.engine.nodes.Sprite;
import com.wiyun.engine.opengl.Texture2D;
import com.wiyun.engine.types.WYPoint;
import com.wiyun.engine.types.WYSize;
import com.wiyun.engine.utils.Utilities;
import com.wiyun.engine.utils.ZwoptexManager;

public class ZwoptexTest extends WiEngineTestActivity {
	@Override
	protected Layer createLayer() {
		return new MyLayer();
	}

    class MyLayer extends Layer {
        public MyLayer() {
        	Texture2D tex = Texture2D.makePNG(R.drawable.grossini_dance_atlas);
        	ZwoptexManager.addZwoptex("grossini", R.raw.grossini_dance_atlas, tex);
        	
            float x, y;
            WYSize s = Director.getInstance().getWindowSize();
            x = s.width;
            y = s.height;
            addNewSprite(WYPoint.make(x / 2, y / 2));
            
            // enable touch
            setTouchEnabled(true);
        }
        
        private void addNewSprite(WYPoint pos) {
        	Random random = new Random();
        	int idx = Utilities.rand(14) + 1;
        	Sprite sprite = ZwoptexManager.makeSprite(String.format("grossini_dance_%02d.png", idx));
        	sprite.setFlipX(random.nextBoolean());
        	sprite.setFlipY(random.nextBoolean());
        	sprite.setRotation(random.nextFloat() * 360f);
            sprite.setPosition(pos.x, pos.y);
            addChild(sprite);
        }
        
        @Override
        public boolean wyTouchesBegan(MotionEvent event) {
            WYPoint location = Director.getInstance().convertToGL(event.getX(), event.getY());

            addNewSprite(location);

            return true;
        }
    }
}
