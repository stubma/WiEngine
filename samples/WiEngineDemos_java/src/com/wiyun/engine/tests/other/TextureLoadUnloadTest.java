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
package com.wiyun.engine.tests.other;

import com.wiyun.engine.R;
import com.wiyun.engine.WiEngineTestActivity;
import com.wiyun.engine.nodes.ColorLayer;
import com.wiyun.engine.nodes.Director;
import com.wiyun.engine.nodes.Label;
import com.wiyun.engine.nodes.Layer;
import com.wiyun.engine.nodes.Menu;
import com.wiyun.engine.nodes.MenuItemLabel;
import com.wiyun.engine.nodes.Scene;
import com.wiyun.engine.opengl.Texture2D;
import com.wiyun.engine.opengl.TextureManager;
import com.wiyun.engine.transitions.FlipXTransition;
import com.wiyun.engine.types.WYColor4B;
import com.wiyun.engine.types.WYSize;


public class TextureLoadUnloadTest extends WiEngineTestActivity {
	private Label mHintLabel;
	
	// flag indicating thread is started
	boolean mBusying;
	
	@Override
	protected Layer createLayer() {
		return new Layer1();
	}
    
    class Layer1 extends ColorLayer {
        public Layer1() {
        	super(new WYColor4B(0, 0, 255, 255));
            MenuItemLabel item1 = MenuItemLabel.make("Push Scene", this, "onPushScene");
            MenuItemLabel item3 = MenuItemLabel.make("Quit", this, "onQuit");

            Menu menu = Menu.make(item1, item3);
            menu.alignItemsVertically();
            addChild(menu);
            
            WYSize s = Director.getInstance().getWindowSize();
            mHintLabel = Label.make("texture loaded: 0/20", 20);
            mHintLabel.setPosition(s.width / 2, 100);
            addChild(mHintLabel);
        }
        
        private void updateLoadHintLabel(int index) {
        	mHintLabel.setText("texture loaded: " + index + "/20");
        }

        public void onPushScene() {
        	if(mBusying)
        		return;
        	mBusying = true;
        	
            // start a thread to load texture
        	Director.getInstance().runThread(new Runnable() {
				@Override
				public void run() {
            		// load textures
            		((Texture2D)Texture2D.makePNG(R.drawable.atlastest).autoRelease()).loadTexture();
            		updateLoadHintLabel(1);
            		((Texture2D)Texture2D.makePNG(R.drawable.background).autoRelease()).loadTexture();
            		updateLoadHintLabel(2);
            		((Texture2D)Texture2D.makePNG(R.drawable.bitmapfont).autoRelease()).loadTexture();
            		updateLoadHintLabel(3);
            		((Texture2D)Texture2D.makePNG(R.drawable.powered).autoRelease()).loadTexture();
            		updateLoadHintLabel(4);
            		((Texture2D)Texture2D.makePNG(R.drawable.grossini_dance_01).autoRelease()).loadTexture();
            		updateLoadHintLabel(5);
            		((Texture2D)Texture2D.makePNG(R.drawable.grossini_dance_02).autoRelease()).loadTexture();
            		updateLoadHintLabel(6);
            		((Texture2D)Texture2D.makePNG(R.drawable.grossini_dance_03).autoRelease()).loadTexture();
            		updateLoadHintLabel(7);
            		((Texture2D)Texture2D.makePNG(R.drawable.grossini_dance_04).autoRelease()).loadTexture();
            		updateLoadHintLabel(8);
            		((Texture2D)Texture2D.makePNG(R.drawable.grossini_dance_05).autoRelease()).loadTexture();
            		updateLoadHintLabel(9);
            		((Texture2D)Texture2D.makePNG(R.drawable.grossini_dance_06).autoRelease()).loadTexture();
            		updateLoadHintLabel(10);
            		((Texture2D)Texture2D.makePNG(R.drawable.grossini_dance_07).autoRelease()).loadTexture();
            		updateLoadHintLabel(11);
            		((Texture2D)Texture2D.makePNG(R.drawable.grossini_dance_08).autoRelease()).loadTexture();
            		updateLoadHintLabel(12);
            		((Texture2D)Texture2D.makePNG(R.drawable.grossini_dance_09).autoRelease()).loadTexture();
            		updateLoadHintLabel(13);
            		((Texture2D)Texture2D.makePNG(R.drawable.grossini_dance_10).autoRelease()).loadTexture();
            		updateLoadHintLabel(14);
            		((Texture2D)Texture2D.makePNG(R.drawable.ortho_test1).autoRelease()).loadTexture();
            		updateLoadHintLabel(15);
            		((Texture2D)Texture2D.makePNG(R.drawable.ortho_test1_bw).autoRelease()).loadTexture();
            		updateLoadHintLabel(16);
            		((Texture2D)Texture2D.makeJPG(R.drawable.test_jpg).autoRelease()).loadTexture();
            		updateLoadHintLabel(17);
            		((Texture2D)Texture2D.makePNG(R.drawable.tiles).autoRelease()).loadTexture();
            		updateLoadHintLabel(18);
            		((Texture2D)Texture2D.makePNG(R.drawable.grossini_dance_atlas).autoRelease()).loadTexture();
            		updateLoadHintLabel(19);
            		((Texture2D)Texture2D.makePNG(R.drawable.hexa_tiles).autoRelease()).loadTexture();
            		updateLoadHintLabel(20);
            		
            		Director.getInstance().runOnGLThread(new Runnable() {
						@Override
						public void run() {
							Scene scene = Scene.make();
							scene.addChild(new Layer2(), 0);
							Director.getInstance().replaceScene((FlipXTransition)FlipXTransition.make(1f, scene, true).autoRelease());
							scene.autoRelease(true);
							mBusying = false;
						}
					});
				}
			});
        }

        public void onQuit() {
        	if(mBusying)
        		return;
        	
            Director.getInstance().popScene();
        }
    }

    class Layer2 extends ColorLayer {
        public Layer2() {
        	super(new WYColor4B(255, 0, 0, 255));
            MenuItemLabel item3 = MenuItemLabel.make("Go Back", this, "onGoBack");

            Menu menu = Menu.make(item3);
            menu.alignItemsVertically();
            addChild(menu);
            
            WYSize s = Director.getInstance().getWindowSize();
            mHintLabel = Label.make("texture unloaded: 0/20", 20);
            mHintLabel.setPosition(s.width / 2, 100);
            addChild(mHintLabel);
        }

        private void updateUnloadHintLabel(int index) {
        	mHintLabel.setText("texture unloaded: " + index + "/20");
        }
        
        public void onGoBack() {
        	if(mBusying)
        		return;
        	mBusying = true;
        	
            // start a thread to load texture
        	Director.getInstance().runThread(new Runnable() {
				@Override
            	public void run() {
            		// unload textures
            		TextureManager tm = TextureManager.getInstance();
            		tm.removeTexture(R.drawable.atlastest);
            		updateUnloadHintLabel(1);
            		tm.removeTexture(R.drawable.background);
            		updateUnloadHintLabel(2);
            		tm.removeTexture(R.drawable.bitmapfont);
            		updateUnloadHintLabel(3);
            		tm.removeTexture(R.drawable.powered);
            		updateUnloadHintLabel(4);
            		tm.removeTexture(R.drawable.grossini_dance_01);
            		updateUnloadHintLabel(5);
            		tm.removeTexture(R.drawable.grossini_dance_02);
            		updateUnloadHintLabel(6);
            		tm.removeTexture(R.drawable.grossini_dance_03);
            		updateUnloadHintLabel(7);
            		tm.removeTexture(R.drawable.grossini_dance_04);
            		updateUnloadHintLabel(8);
            		tm.removeTexture(R.drawable.grossini_dance_05);
            		updateUnloadHintLabel(9);
            		tm.removeTexture(R.drawable.grossini_dance_06);
            		updateUnloadHintLabel(10);
            		tm.removeTexture(R.drawable.grossini_dance_07);
            		updateUnloadHintLabel(11);
            		tm.removeTexture(R.drawable.grossini_dance_08);
            		updateUnloadHintLabel(12);
            		tm.removeTexture(R.drawable.grossini_dance_09);
            		updateUnloadHintLabel(13);
            		tm.removeTexture(R.drawable.grossini_dance_10);
            		updateUnloadHintLabel(14);
            		tm.removeTexture(R.drawable.ortho_test1);
            		updateUnloadHintLabel(15);
            		tm.removeTexture(R.drawable.ortho_test1_bw);
            		updateUnloadHintLabel(16);
            		tm.removeTexture(R.drawable.test_jpg);
            		updateUnloadHintLabel(17);
            		tm.removeTexture(R.drawable.tiles);
            		updateUnloadHintLabel(18);
            		tm.removeTexture(R.drawable.grossini_dance_atlas);
            		updateUnloadHintLabel(19);
            		tm.removeTexture(R.drawable.hexa_tiles);
            		updateUnloadHintLabel(20);
            		
            		Director.getInstance().runOnGLThread(new Runnable() {
						@Override
						public void run() {
		                    Scene scene = Scene.make();
		                    scene.addChild(new Layer1(), 0);
		                    Director.getInstance().replaceScene((FlipXTransition)FlipXTransition.make(1f, scene, false).autoRelease());
		                    scene.autoRelease(true);
		                    mBusying = false;
						}
            		});
            	}
			});
        }
    }
}
