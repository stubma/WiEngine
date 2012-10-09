package com.wiyun.engine.tests.node;

import java.util.Random;

import android.content.Context;
import android.view.MotionEvent;

import com.wiyun.engine.WiEngineTestActivity;
import com.wiyun.engine.nodes.Director;
import com.wiyun.engine.nodes.Layer;
import com.wiyun.engine.nodes.Sprite;
import com.wiyun.engine.types.WYPoint;
import com.wiyun.engine.types.WYSize;
import com.wiyun.engine.utils.Utilities;

public class ImageSpriteTest extends WiEngineTestActivity {
	@Override
	protected Layer createLayer() {
		return new MyLayer();
	}

    class MyLayer extends Layer {
        public MyLayer() {
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
        	Context context = Director.getInstance().getContext();
        	int id = context.getResources().getIdentifier(String.format("grossini_dance_%02d", idx), "drawable", context.getPackageName());
        	Sprite sprite = Sprite.make(id);
        	sprite.setFlipX(random.nextBoolean());
        	sprite.setFlipY(random.nextBoolean());
        	sprite.setRotation(random.nextFloat() * 360f);
        	sprite.setAutoFit(true);
        	sprite.setContentSize(random.nextFloat() * 200 + 50, random.nextFloat() * 200 + 50);
            addChild(sprite);
            sprite.setPosition(pos.x, pos.y);
            sprite.autoRelease();
        }
        
        @Override
        public boolean wyTouchesBegan(MotionEvent event) {
            WYPoint location = Director.getInstance().convertToGL(event.getX(), event.getY());

            addNewSprite(location);

            return true;
        }
    }
}
