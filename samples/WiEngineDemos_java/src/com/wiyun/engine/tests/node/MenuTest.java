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

import android.widget.Toast;

import com.wiyun.engine.R;
import com.wiyun.engine.WiEngineTestActivity;
import com.wiyun.engine.nodes.AtlasLabel;
import com.wiyun.engine.nodes.CharMap;
import com.wiyun.engine.nodes.Director;
import com.wiyun.engine.nodes.Layer;
import com.wiyun.engine.nodes.Menu;
import com.wiyun.engine.nodes.MenuItem;
import com.wiyun.engine.nodes.MenuItemAtlasLabel;
import com.wiyun.engine.nodes.MenuItemLabel;
import com.wiyun.engine.nodes.MenuItemSprite;
import com.wiyun.engine.nodes.MenuItemToggle;
import com.wiyun.engine.nodes.Sprite;
import com.wiyun.engine.opengl.Texture2D;
import com.wiyun.engine.types.WYColor3B;
import com.wiyun.engine.types.WYRect;
import com.wiyun.engine.utils.ResolutionIndependent;
import com.wiyun.engine.utils.TargetSelector;

public class MenuTest extends WiEngineTestActivity {
	@Override
	protected Layer createLayer() {
		return new MyLayer();
	}

    class MyLayer extends Layer {
    	MenuItem disabledItem;
    	
        public MyLayer() {
            // Font Item
            // AtlasSprite Item
			Texture2D tex = Texture2D.makePNG(R.drawable.menuitemsprite);

            Sprite spriteNormal = Sprite.make(tex,
            		ResolutionIndependent.resolve(WYRect.make(0, 23 * 2, 115, 23)));
            Sprite spriteSelected = Sprite.make(tex,
            		ResolutionIndependent.resolve(WYRect.make(0, 23 * 1, 115, 23)));
            Sprite spriteDisabled = Sprite.make(tex,
            		ResolutionIndependent.resolve(WYRect.make(0, 23 * 0, 115, 23)));
            MenuItemSprite item1 = MenuItemSprite.make(spriteNormal, spriteSelected, spriteDisabled, 
            	new TargetSelector(this, "onOtherMenuItemClicked(Object)", new Object[] { "you click atlas sprite menu item" }));

            // Image Item
            MenuItem item2 = MenuItemSprite.make(R.drawable.btn_send_score_normal, R.drawable.btn_send_score_pressed, 
            		new TargetSelector(this, "onOtherMenuItemClicked(Object)", new Object[] { "you click sprite menu item" }));

            // Label Item (LabelAtlas)
        	CharMap map = CharMap.make();
        	map.autoRelease();
    		map.mapChar(WYRect.make(0, 0, ResolutionIndependent.resolveDp(20), ResolutionIndependent.resolveDp(25)), '0');
    		map.mapChar(WYRect.make(ResolutionIndependent.resolveDp(20), 0, ResolutionIndependent.resolveDp(10), ResolutionIndependent.resolveDp(25)), '1');
    		map.mapChar(WYRect.make(ResolutionIndependent.resolveDp(30), 0, ResolutionIndependent.resolveDp(21), ResolutionIndependent.resolveDp(25)), '2');
    		map.mapChar(WYRect.make(ResolutionIndependent.resolveDp(51), 0, ResolutionIndependent.resolveDp(21), ResolutionIndependent.resolveDp(25)), '3');
    		map.mapChar(WYRect.make(ResolutionIndependent.resolveDp(72), 0, ResolutionIndependent.resolveDp(21), ResolutionIndependent.resolveDp(25)), '4');
    		map.mapChar(WYRect.make(ResolutionIndependent.resolveDp(93), 0, ResolutionIndependent.resolveDp(21), ResolutionIndependent.resolveDp(25)), '5');
    		map.mapChar(WYRect.make(ResolutionIndependent.resolveDp(114), 0, ResolutionIndependent.resolveDp(21), ResolutionIndependent.resolveDp(25)), '6');
    		map.mapChar(WYRect.make(ResolutionIndependent.resolveDp(135), 0, ResolutionIndependent.resolveDp(21), ResolutionIndependent.resolveDp(25)), '7');
    		map.mapChar(WYRect.make(ResolutionIndependent.resolveDp(156), 0, ResolutionIndependent.resolveDp(21), ResolutionIndependent.resolveDp(25)), '8');
    		map.mapChar(WYRect.make(ResolutionIndependent.resolveDp(177), 0, ResolutionIndependent.resolveDp(21), ResolutionIndependent.resolveDp(25)), '9');
            AtlasLabel labelAtlas = AtlasLabel.make("0123456789", Texture2D.makePNG(R.drawable.number), map);
            MenuItemAtlasLabel item3 = MenuItemAtlasLabel.make(labelAtlas, 
            	null,
            	new TargetSelector(this, "onOtherMenuItemClicked(Object)", new Object[] { "you click label menu item" }));
            
            // Font Item
            MenuItemLabel item4 = MenuItemLabel.make("I toggle enable items", this, "onFontMenuItemClicked");
            
            // Font Item
            MenuItemLabel item5 = MenuItemLabel.make("Quit", "DroidSans", 24, this, "onQuit");
            item5.setDisabledColor(new WYColor3B(32, 32, 0));
            item5.setColor(new WYColor3B(255, 255, 0));
            
            // toggle items
            MenuItemLabel toggle1 = MenuItemLabel.make("This", "DroidSans", 24);
            MenuItemLabel toggle2 = MenuItemLabel.make("is a", "DroidSans", 24);
            MenuItemLabel toggle3 = MenuItemLabel.make("toggle", "DroidSans", 24);
            MenuItemLabel toggle4 = MenuItemLabel.make("menu item", "DroidSans", 24);
            MenuItem item6 = MenuItemToggle.make(null, 
            	new TargetSelector(this, "onToggleMenuItemClicked", null), 
            	toggle1, toggle2, toggle3, toggle4);

            Menu menu = Menu.make(item1, item2, item3, item4, item5, item6);
            menu.alignItemsVertically();

            disabledItem = item5;
            disabledItem.setEnabled(false);

            addChild(menu);
        }
        
        public void onToggleMenuItemClicked() {
        }

        public void onFontMenuItemClicked() {
            disabledItem.setEnabled(!disabledItem.isEnabled());
        }

        public void onQuit() {
            Director.getInstance().end();
        }
        
        public void onOtherMenuItemClicked(final Object arg) {
        	runOnUiThread(new Runnable() {
				public void run() {
					Toast.makeText(Director.getInstance().getContext(), (String)arg, Toast.LENGTH_SHORT).show();
				}
			});
        }
    }
}
