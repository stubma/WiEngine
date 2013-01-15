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
package com.wiyun.engine.tests.action;

import com.wiyun.engine.R;
import com.wiyun.engine.WiEngineTestActivity;
import com.wiyun.engine.actions.Action.Callback;
import com.wiyun.engine.actions.ClipIn;
import com.wiyun.engine.actions.ClipOut;
import com.wiyun.engine.actions.RotateBy;
import com.wiyun.engine.nodes.Button;
import com.wiyun.engine.nodes.Director;
import com.wiyun.engine.nodes.Layer;
import com.wiyun.engine.nodes.Sprite;
import com.wiyun.engine.opengl.Texture2D;
import com.wiyun.engine.types.WYRect;
import com.wiyun.engine.types.WYSize;
import com.wiyun.engine.utils.ResolutionIndependent;
import com.wiyun.engine.utils.TargetSelector;

public class ClipInOutTest extends WiEngineTestActivity {
	@Override
	protected Layer createLayer() {
	    return new MyLayer();
	}
	
    class MyLayer extends Layer implements Callback {
    	boolean m_expanded;
    	boolean m_toggling;
    	Button m_button;
    	Sprite m_sprite;
    	
        public MyLayer() {
        	WYSize s = Director.getInstance().getWindowSize();
    		Sprite normal = Sprite.make(Texture2D.make(R.drawable.icon));
    		m_button = Button.make(normal, null, null, null, null, new TargetSelector(this, "onToggle(float)", new Object[] { 0f }));
    		m_button.setPosition(DP(40), s.height / 2);
    		addChild(m_button);

    		m_sprite = Sprite.make(Texture2D.make(R.drawable.test_jpg));
    		m_sprite.setAnchor(0, 0.5f);
    		m_sprite.setPosition(m_button.getOriginX() + m_button.getWidth(), s.height / 2);
    		m_sprite.setClipRect(WYRect.makeZero(), true);
    		addChild(m_sprite);
        }
        
        float DP(float v) {
        	return ResolutionIndependent.resolveDp(v);
        }
        
        public void onToggle(float delta) {
    		if(m_toggling)
    			return;

    		if(m_expanded) {
    			m_expanded = false;
    			m_toggling = true;

    			ClipOut clip = ClipOut.make(0.5f, ClipOut.RIGHT_TO_LEFT);
    			clip.autoRelease();
    			m_sprite.runAction(clip);
    			RotateBy rotate = RotateBy.make(0.5f, -90);
    			rotate.setCallback(this);
    			rotate.autoRelease();
    			m_button.runAction(rotate);
    		} else {
    			m_expanded = true;
    			m_toggling = true;

    			ClipIn clip = ClipIn.make(0.5f, ClipIn.LEFT_TO_RIGHT);
    			clip.autoRelease();
    			m_sprite.runAction(clip);
    			RotateBy rotate = RotateBy.make(0.5f, 90);
    			rotate.setCallback(this);
    			rotate.autoRelease();
    			m_button.runAction(rotate);
    		}
        }

		@Override
		public void onStart(int actionPointer) {
		}

		@Override
		public void onStop(int actionPointer) {
			m_toggling = false;
		}

		@Override
		public void onUpdate(int actionPointer, float t) {
		}
    }
}
