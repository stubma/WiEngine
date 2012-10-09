package com.wiyun.engine.tests.node;

import static android.view.KeyEvent.KEYCODE_BACK;
import android.content.Context;
import android.view.KeyEvent;
import android.view.MotionEvent;
import com.wiyun.engine.WiEngineTestActivity;
import com.wiyun.engine.nodes.Cover;
import com.wiyun.engine.nodes.Director;
import com.wiyun.engine.nodes.Layer;
import com.wiyun.engine.nodes.CoverFlow;
import com.wiyun.engine.opengl.Texture2D;
import com.wiyun.engine.types.WYSize;


public class CoverFlowTest extends WiEngineTestActivity {
	private CoverFlow m_coverFlow;
	
	@Override
	protected Layer createLayer() {
		return new MyLayer();
	}

    class MyLayer extends Layer {
        public MyLayer() {
            WYSize s = Director.getInstance().getWindowSize();
            float width = s.width;
            float height = s.height;        	
        	m_coverFlow = CoverFlow.make();
            m_coverFlow.setAnchor(0.0f, 0.0f);
            m_coverFlow.setPosition(width / 2, height / 2);
            m_coverFlow.setFrontCoverSize(width / 3, width / 3, true);
            
        	Cover[] covers = new Cover[9];
        	Context context = Director.getInstance().getContext();
       		int id1 = context.getResources().getIdentifier("atlastest", "drawable", context.getPackageName());
       		int id2 = context.getResources().getIdentifier("test_jpg", "drawable", context.getPackageName());
        	for(int i = 0; i < 9; ++i) {
        		if(i % 2 == 0) {
        			covers[i] = Cover.make(Texture2D.makePNG(id1));
        		} else {
        			covers[i] = Cover.make(Texture2D.makeJPG(id2));
        		}
        		m_coverFlow.addCover(covers[i]);
        	}

        	covers[4].setRotateY(0.0f);
            m_coverFlow.setBlurredBorderWidth(0.1f);
            m_coverFlow.setFrontCenterPosition(0, 50);

            m_coverFlow.showCover(covers[4], 0.0f);
            addChild(m_coverFlow);        	
        	
            // enable touch
            setTouchEnabled(true);
            setKeyEnabled(true);
        }
        
        @Override
        public boolean wyTouchesBegan(MotionEvent event) {
            Cover c = m_coverFlow.getTouchedCover(event.getX(), event.getY());
            if(c != null) {
                int distance = m_coverFlow.getIndex(c) - m_coverFlow.getIndex(m_coverFlow.getFrontCover());
                
                if(distance < 0)
                	distance = -distance;
                
                m_coverFlow.showCover(c, distance * 0.3f);	
            }
            return true;
        }

		@Override
		public boolean wyKeyDown(KeyEvent event) {
			// don't handle back key
			if(event.getKeyCode() == KEYCODE_BACK)
				return false;
			else
				return true;
		}
		
        @Override
    	public boolean wyKeyUp(KeyEvent event) {
    		switch(event.getKeyCode()) {
    			case KeyEvent.KEYCODE_DPAD_LEFT:
    				m_coverFlow.moveLeft(0.3f);
    				return true;
    			case KeyEvent.KEYCODE_DPAD_RIGHT:
    				m_coverFlow.moveRight(0.3f);
    				return true;
    			default:
    				return super.wyKeyUp(event);
    		}
    	}     
    }
}