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

import com.wiyun.engine.R;
import com.wiyun.engine.WiEngineTestActivity;
import com.wiyun.engine.afcanim.SPXSprite;
import com.wiyun.engine.nodes.Director;
import com.wiyun.engine.nodes.Layer;
import com.wiyun.engine.nodes.Sprite;
import com.wiyun.engine.nodes.VirtualJoystick;
import com.wiyun.engine.nodes.VirtualJoystick.IVirtualJoystickCallback;
import com.wiyun.engine.opengl.Texture2D;
import com.wiyun.engine.types.WYSize;
import com.wiyun.engine.utils.ResolutionIndependent;
import com.wiyun.engine.utils.TargetSelector;

public class VirtualJoystickTest extends WiEngineTestActivity {
	@Override
	protected Layer createLayer() {
		return new MyLayer();
	}
	
	static final int IDLE = 0;
	static final int UP = 1;
	static final int DOWN = 2;
	static final int LEFT = 3;
	static final int RIGHT = 4;
	static final int SPEED = 50;
	
	static final int UP_ANIM = 0;
	static final int DOWN_ANIM = 1;
	static final int LEFT_ANIM = 2;
	static final int RIGHT_ANIM = 3;
	static final int IDLE_ANIM = 6;
	
    class MyLayer extends Layer implements IVirtualJoystickCallback {
    	SPXSprite m_spx;
    	
    	// sprite position
    	float m_x;
    	float m_y;
    	
    	// current action
    	int m_action;
    	
    	public MyLayer() {
    		// init action
    		m_action = IDLE;
    		
    		// create joystick
    		Sprite bg = Sprite.make(R.drawable.joystick_bg);
    		bg.setDither(true);
    		Sprite rocker = Sprite.make(R.drawable.joystick_rocker);
    		VirtualJoystick vj = VirtualJoystick.make(bg, rocker);
    		vj.setAnchor(0, 0);
    		vj.setPosition(DP(20), DP(20));
    		vj.setCallback(this);
    		addChild(vj);

    		// red spx
    		WYSize s = Director.getInstance().getWindowSize();
    		Texture2D tex = Texture2D.makePNG(R.drawable.spx_test);
    		tex.autoRelease();
    		m_spx = SPXSprite.make(R.raw.spx_test, tex, IDLE_ANIM);
    		m_spx.setLoopCount(-1);
    		m_spx.setPosition(s.width / 2, s.height / 2);
    		addChild(m_spx);
    		m_x = s.width / 2; 
    		m_y = s.height / 2;
    		
    		schedule(new TargetSelector(this, "tick(float)", new Object[] { 0f }));
    		
    		autoRelease(true);
		}
    	
    	public void tick(float delta) {
    		m_spx.tick(delta);
    		
    		// get sprite position delta
    		float dx = 0;
    		float dy = 0;
    		switch(m_action) {
    			case UP:
    				dy = SPEED * delta;
    				break;
    			case DOWN:
    				dy = -SPEED * delta;
    				break;
    			case LEFT:
    				dx = -SPEED * delta;
    				break;
    			case RIGHT:
    				dx = SPEED * delta;
    				break;
    		}

    		// update sprite position
    		m_x += dx;
    		m_y += dy;
    		m_spx.setPosition(m_x, m_y);
    	}
    	
    	private float DP(float v) {
    		return ResolutionIndependent.resolveDp(v);
    	}

    	@Override
    	public void onVJDirectionChanged(int vjPointer, int newDirection) {
    		// decide action
    		switch(newDirection) {
    			case VirtualJoystick.VJD_CENTER:
    				m_spx.playAnimation(IDLE_ANIM);
    				m_action = IDLE;
    				break;
    			case VirtualJoystick.VJD_EAST:
    				m_spx.playAnimation(RIGHT_ANIM);
    				m_action = RIGHT;
    				break;
    			case VirtualJoystick.VJD_WEST:
    				m_spx.playAnimation(LEFT_ANIM);
    				m_action = LEFT;
    				break;
    			case VirtualJoystick.VJD_NORTH:
    				m_spx.playAnimation(UP_ANIM);
    				m_action = UP;
    				break;
    			case VirtualJoystick.VJD_SOUTH:
    				m_spx.playAnimation(DOWN_ANIM);
    				m_action = DOWN;
    				break;
    		}
    	}

		@Override
		public void onVJNavigationEnded(int vjPointer) {
		}

		@Override
		public void onVJNavigationStarted(int vjPointer) {
		}
    }
}
