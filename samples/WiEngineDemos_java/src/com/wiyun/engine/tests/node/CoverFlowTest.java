/*
 * Copyright (c) 2010 WiYun Inc.

 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:

 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.

 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
/*
 * Copyright (c) 2010 WiYun Inc.
 * Author: luma(stubma@gmail.com)
 *
 * For all entities this program is free software; you can redistribute
 * it and/or modify it under the terms of the 'WiEngine' license with
 * the additional provision that 'WiEngine' must be credited in a manner
 * that can be be observed by end users, for example, in the credits or during
 * start up. (please find WiEngine logo in sdk's logo folder)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
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