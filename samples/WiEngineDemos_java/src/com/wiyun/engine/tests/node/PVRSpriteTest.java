package com.wiyun.engine.tests.node;

import android.os.SystemClock;
import android.view.MotionEvent;

import com.wiyun.engine.R;
import com.wiyun.engine.WiEngineTestActivity;
import com.wiyun.engine.nodes.Director;
import com.wiyun.engine.nodes.Layer;
import com.wiyun.engine.nodes.Sprite;
import com.wiyun.engine.opengl.Texture2D;
import com.wiyun.engine.types.WYPoint;
import com.wiyun.engine.types.WYSize;

public class PVRSpriteTest extends WiEngineTestActivity {
	@Override
	protected Layer createLayer() {
		return new MyLayer();
	}

    class MyLayer extends Layer {
    	int[] IDS = {
    		R.raw.grossini_rgba_8888,	
    		R.raw.grossini_rgba_5551,
    		R.raw.grossini_rgba_4444,
    		R.raw.grossini_rgb_565,
    		R.raw.grossini_i_8,	
    		R.raw.grossini_a_8,	
    		R.raw.grossini_ai_8	
    	};
    	
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
        	int index = (int)SystemClock.uptimeMillis() % IDS.length;
        	Sprite sprite = Sprite.make(Texture2D.makePVR(IDS[index]));
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
