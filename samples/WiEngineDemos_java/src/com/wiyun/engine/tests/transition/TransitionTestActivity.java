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
package com.wiyun.engine.tests.transition;

import com.wiyun.engine.WiEngineTestActivity;
import com.wiyun.engine.nodes.ColorLayer;
import com.wiyun.engine.nodes.Director;
import com.wiyun.engine.nodes.Layer;
import com.wiyun.engine.nodes.Menu;
import com.wiyun.engine.nodes.MenuItemLabel;
import com.wiyun.engine.nodes.Scene;
import com.wiyun.engine.transitions.TransitionScene;
import com.wiyun.engine.types.WYColor4B;

abstract class TransitionTestActivity extends WiEngineTestActivity {
	@Override
	protected Layer createLayer() {
		return new Layer1();
	}
	
	protected abstract TransitionScene getTransition(Scene scene);
	
	protected abstract TransitionScene getBackTransition(Scene scene);
	
    class Layer1 extends ColorLayer {
        public Layer1() {
        	super(new WYColor4B(0, 0, 255, 255));
            MenuItemLabel item1 = MenuItemLabel.make("Push Scene", this, "onPushScene");
            MenuItemLabel item2 = MenuItemLabel.make("Replace Scene", this, "onReplaceScene");
            MenuItemLabel item3 = MenuItemLabel.make("Quit", this, "onQuit");

            Menu menu = Menu.make(item1, item2, item3);
            menu.alignItemsVertically();

            addChild(menu);
        }
        
        public void onPushScene() {
        	Scene scene = Scene.make();
        	scene.addChild(new Layer2(false), 0);
        	scene.autoRelease(true);
        	Director.getInstance().pushScene(getTransition(scene));
        }

        public void onReplaceScene() {
            Scene scene = Scene.make();
            scene.addChild(new Layer2(true), 0);
            scene.autoRelease(true);
            Director.getInstance().replaceScene(getTransition(scene));
        }

        public void onQuit() {
            Director.getInstance().popScene();
        }
    }
    
    class Layer2 extends ColorLayer {
        public Layer2(boolean replace) {
        	super(new WYColor4B(replace ? 255 : 0, replace ? 0 : 255, 0, 255));
            MenuItemLabel item = MenuItemLabel.make("Go Back", this, replace ? "onGoBack" : "onGoBack2");

            Menu menu = Menu.make(item);
            menu.alignItemsVertically();

            addChild(menu);
        }

        public void onGoBack() {
            Scene scene = Scene.make();
            scene.addChild(new Layer1(), 0);
            scene.autoRelease(true);
            TransitionScene t = getBackTransition(scene);
            if(t == null)
            	t = getTransition(scene);
            Director.getInstance().replaceScene(t);
        }
        
        public void onGoBack2() {
        	TransitionScene t = getBackTransition(null);
        	if(t == null)
        		t = getTransition(null);
        	Director.getInstance().popSceneWithTransition(t);
        }
    }
}
