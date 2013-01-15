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

import android.view.MotionEvent;

import com.wiyun.engine.R;
import com.wiyun.engine.WiEngineTestActivity;
import com.wiyun.engine.actions.Action;
import com.wiyun.engine.actions.FiniteTimeAction;
import com.wiyun.engine.actions.IntervalAction;
import com.wiyun.engine.actions.MoveBy;
import com.wiyun.engine.actions.RepeatForever;
import com.wiyun.engine.actions.RotateBy;
import com.wiyun.engine.actions.Sequence;
import com.wiyun.engine.box2d.Box2D;
import com.wiyun.engine.box2d.collision.CircleShape;
import com.wiyun.engine.box2d.collision.EdgeShape;
import com.wiyun.engine.box2d.dynamics.Body;
import com.wiyun.engine.box2d.dynamics.BodyDef;
import com.wiyun.engine.box2d.dynamics.FixtureDef;
import com.wiyun.engine.box2d.dynamics.World;
import com.wiyun.engine.nodes.Director;
import com.wiyun.engine.nodes.Layer;
import com.wiyun.engine.nodes.LineRibbon;
import com.wiyun.engine.nodes.MotionStreak;
import com.wiyun.engine.nodes.Node;
import com.wiyun.engine.nodes.SpotRibbon;
import com.wiyun.engine.nodes.Sprite;
import com.wiyun.engine.opengl.Texture2D;
import com.wiyun.engine.types.WYColor4B;
import com.wiyun.engine.types.WYPoint;
import com.wiyun.engine.types.WYSize;
import com.wiyun.engine.utils.ResolutionIndependent;
import com.wiyun.engine.utils.TargetSelector;

public class MotionStreakTest extends WiEngineTestActivity {
	@Override
	protected Layer createLayer() {
		return new MyLayer();
	}

    class MyLayer extends Layer {
        Node mRoot;
        Node mTarget;
        MotionStreak mStreak1;
        MotionStreak mStreak2;
        MotionStreak mStreak3;
        MotionStreak mStreak4;
    	Box2D mBox2D;
    	World mWorld;
    	Body mBall;
    	
    	// pid for streak 3 & 4
    	int m_streak3Pid = -1;
    	int m_streak4Pid = -1;
        
        public MyLayer() {
        	/*
        	 * part 1: create first streak
        	 */
        	
            WYSize s = Director.getInstance().getWindowSize();

            // the root object just rotates around
            mRoot = Sprite.make(R.drawable.r1);
            addChild(mRoot, 1);
            mRoot.setPosition(s.width / 2, s.height / 2);

            // the target object is offset from root, and the streak is moved to follow it
            mTarget = Sprite.make(R.drawable.r1);
            mRoot.addChild(mTarget);
            mTarget.setPosition(100, 0);

            // create the streak object and add it to the scene
            mStreak1 = MotionStreak.make(2, Texture2D.make(R.drawable.icon), new WYColor4B(0, 255, 0, 255));
            addChild(mStreak1);
            
            // run actions
            IntervalAction rotate = (IntervalAction)RotateBy.make(2, 360).autoRelease();
            Action a = (Action)RepeatForever.make(rotate).autoRelease();
            IntervalAction motion = (IntervalAction)MoveBy.make(2, 100, 0).autoRelease();
            mRoot.runAction((Action)RepeatForever.make(
            		Sequence.make(motion, (FiniteTimeAction)motion.reverse().autoRelease())).autoRelease());
            mRoot.runAction(a);
            
            /*
             * part 2: create second streak
             */
            
    		// create second streak, fade time is 0 so it doesn't disappear until you call reset
    		mStreak2 = MotionStreak.make(0, Texture2D.make(R.drawable.track), new WYColor4B(55, 66, 200, 255), MotionStreak.STYLE_SPOT);
    		SpotRibbon.from(mStreak2.getRibbon()).setDistance(ResolutionIndependent.resolveDp(20));
    		addChild(mStreak2);
            
            // create box2d
    		mBox2D = Box2D.make();
    		mBox2D.setDebugDraw(true);
    		mWorld = mBox2D.getWorld();
    		addChild(mBox2D);
    		
			// set gravity
			mWorld.setGravity(0, -10);
			
    		// create ground
    		BodyDef bd = BodyDef.make();
    		Body ground = mBox2D.getWorld().createBody(bd);
    		bd.destroy();
    		
			// create bottom edge
			EdgeShape es = EdgeShape.make();
			FixtureDef fixDef = FixtureDef.make();
			fixDef.setShape(es);
			fixDef.setDensity(0.0f);
			fixDef.setRestitution(0.5f);
			es.setEndpoints(0, 0, mBox2D.pixel2Meter(s.width), 0);
			ground.createFixture(fixDef);
			fixDef.destroy();
			
			// create circle body
			bd = BodyDef.make();
			bd.setType(Body.TYPE_DYNAMIC);
			bd.setPosition(0, mBox2D.pixel2Meter(s.height));
			bd.setLinearVelocity(2, 0);
			mBall = mWorld.createBody(bd);
			bd.destroy();
			
			// create circle shape for ball
			CircleShape cs = CircleShape.make();
			fixDef = FixtureDef.make();
			fixDef.setShape(cs);
			fixDef.setRestitution(0.85f);
			fixDef.setDensity(1.0f);
			cs.setRadius(0.5f);
			mBall.createFixture(fixDef);
			fixDef.destroy();
			
            // create thrid streak object and add it to the scene
            mStreak3 = MotionStreak.make(0.01f, Texture2D.make(R.drawable.streak), new WYColor4B(255, 255, 255, 255), MotionStreak.STYLE_BLADE);
            addChild(mStreak3);
            
            // create fourth streak object in line style
            mStreak4 = MotionStreak.make(0, Texture2D.make(R.drawable.line), new WYColor4B(255, 0, 0, 255), MotionStreak.STYLE_LINE);
            LineRibbon.from(mStreak4.getRibbon()).setLineWidth(8);
            addChild(mStreak4);
            
            // enable touch for streak 3
            setTouchEnabled(true);
            
            // schedule an update on each frame so we can synchronize the streak with the target
            schedule(new TargetSelector(this, "onUpdate(float)", new Object[] { 0f }));
        }

        public void onUpdate(float delta) {
        	// add point to stream 1
            WYPoint p = mTarget.convertToWorldSpace(mTarget.getAnchorPointX(), mTarget.getAnchorPointY());
            mStreak1.addPoint(p.x, p.y);
            
            // update box2d
    		mWorld.step(1.f / 60.f, 10, 10);
    		mWorld.clearForces();
    		
    		// add point to streak2 or reset it if ball is outside of screen
    		WYPoint pos = mBall.getPosition();
    		pos.x = mBox2D.meter2Pixel(pos.x);
    		pos.y = mBox2D.meter2Pixel(pos.y);
    		if(pos.x > Director.getInstance().getWindowSize().width)
    			mStreak2.reset();
    		else
    			mStreak2.addPoint(pos.x, pos.y);
        }
        
        @Override
        public boolean wyTouchesBegan(MotionEvent event) {
        	WYPoint loc = Director.getInstance().convertToGL(event.getX(), event.getY());
        	mStreak3.addPoint(loc.x, loc.y, true);
        	m_streak3Pid = event.getPointerId(0);
        	return true;
        }
        
        @Override
        public boolean wyTouchesPointerBegan(MotionEvent event) {
        	int index = event.getActionIndex();
    		if(m_streak4Pid == -1) {
    			WYPoint loc = Director.getInstance().convertToGL(event.getX(index), event.getY(index));
    			mStreak4.addPoint(loc.x, loc.y, true);
    			m_streak4Pid = event.getPointerId(index);
    		} else if(m_streak3Pid == -1) {
    			WYPoint loc = Director.getInstance().convertToGL(event.getX(index), event.getY(index));
    			mStreak3.addPoint(loc.x, loc.y, true);
    			m_streak3Pid = event.getPointerId(index);
    		}
        	return true;
        }
        
        @Override
        public boolean wyTouchesPointerEnded(MotionEvent event) {
        	int index = event.getActionIndex();
        	int pid = event.getPointerId(index);
    		if(pid == m_streak3Pid)
    			m_streak3Pid = -1;
    		else if(pid == m_streak4Pid)
    			m_streak4Pid = -1;
    		return true;
        }
        
        @Override
        public boolean wyTouchesMoved(MotionEvent event) {
    		for(int i = 0; i < event.getPointerCount(); i++) {
    			WYPoint loc = Director.getInstance().convertToGL(event.getX(i), event.getY(i));
    			if(event.getPointerId(i) == m_streak3Pid)
    				mStreak3.addPoint(loc.x, loc.y);
    			else if(event.getPointerId(i) == m_streak4Pid)
    				mStreak4.addPoint(loc.x, loc.y);
    		}
        	return true;
        }
    }
}
