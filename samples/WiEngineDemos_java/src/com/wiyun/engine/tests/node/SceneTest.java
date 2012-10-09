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
package com.wiyun.engine.tests.node;

import android.view.MotionEvent;

import com.wiyun.engine.WiEngineTestActivity;
import com.wiyun.engine.nodes.ColorLayer;
import com.wiyun.engine.nodes.Director;
import com.wiyun.engine.nodes.Label;
import com.wiyun.engine.nodes.Layer;
import com.wiyun.engine.nodes.Menu;
import com.wiyun.engine.nodes.MenuItemLabel;
import com.wiyun.engine.nodes.Scene;
import com.wiyun.engine.transitions.LeftPushInTransition;
import com.wiyun.engine.transitions.TopPushInTransition;
import com.wiyun.engine.types.WYColor4B;


public class SceneTest extends WiEngineTestActivity {
	@Override
	protected Layer createLayer() {
		return new Layer1();
	}
    
    static class Layer1 extends Layer {
        public Layer1() {
            MenuItemLabel item1 = MenuItemLabel.make("Push Scene", this, "onPushScene");
            MenuItemLabel item2 = MenuItemLabel.make("Push Scene (T)", this, "onPushSceneTran");
            MenuItemLabel item3 = MenuItemLabel.make("Quit", this, "onQuit");

            Menu menu = Menu.make(item1, item2, item3);
            menu.alignItemsVertically();

            addChild(menu);
            
            autoRelease(true);
        }

        public void onPushScene() {
            Scene scene = Scene.make();
            scene.addChild(new Layer2(), 0);
            Director.getInstance().pushScene(scene);
        }

        public void onPushSceneTran() {
            Scene scene = Scene.make();
            scene.addChild(new Layer2(), 0);
            Director.getInstance().pushScene(TopPushInTransition.make(1, scene));
        }

        public void onQuit() {
            Director.getInstance().popScene();
        }
    }

    static class Layer2 extends Layer {
        public Layer2() {
        	MenuItemLabel item1 = MenuItemLabel.make("Replace Scene", this, "onReplaceScene");
            MenuItemLabel item2 = MenuItemLabel.make("Replace Scene (T)", this, "onReplaceSceneTransition");
            MenuItemLabel item3 = MenuItemLabel.make("Go Back", this, "onGoBack");

            Menu menu = Menu.make(item1, item2, item3);
            menu.alignItemsVertically();

            addChild(menu);
            
            autoRelease(true);
        }

        public void onGoBack() {
            Director.getInstance().popScene();
        }

        public void onReplaceScene() {
            Scene scene = Scene.make();
            scene.addChild(new Layer3(), 0);
            Director.getInstance().replaceScene(scene);
        }

        public void onReplaceSceneTransition() {
            Scene s = Scene.make();
            s.addChild(new Layer3(), 0);
            Director.getInstance().replaceScene(LeftPushInTransition.make(1, s));
        }
    }

    static class Layer3 extends ColorLayer {
        public Layer3() {
            super(new WYColor4B(0, 0, 255, 255));

            setTouchEnabled(true);

            Label label = Label.make("Touch to pop scene", 32);
            addChild(label);
            float width = Director.getInstance().getWindowSize().width;
            float height = Director.getInstance().getWindowSize().height;
            label.setPosition(width / 2, height / 2);
            
            autoRelease(true);
        }

        @Override
        public boolean wyTouchesEnded(MotionEvent event) {
            Director.getInstance().popScene();
            return true;
        }
    }
}
