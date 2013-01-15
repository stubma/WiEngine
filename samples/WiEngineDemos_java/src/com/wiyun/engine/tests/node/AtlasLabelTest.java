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

import com.wiyun.engine.R;
import com.wiyun.engine.WiEngineTestActivity;
import com.wiyun.engine.nodes.AtlasLabel;
import com.wiyun.engine.nodes.CharMap;
import com.wiyun.engine.nodes.Layer;
import com.wiyun.engine.opengl.Texture2D;
import com.wiyun.engine.types.WYColor3B;
import com.wiyun.engine.types.WYRect;
import com.wiyun.engine.utils.ResolutionIndependent;
import com.wiyun.engine.utils.TargetSelector;

public class AtlasLabelTest extends WiEngineTestActivity {
	@Override
	protected Layer createLayer() {
		return new MyLayer();
	}

    class MyLayer extends Layer {
        AtlasLabel[] label;
        int count;

        public MyLayer() {
        	label = new AtlasLabel[3];
        	
        	// create charmap
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
        	
        	// The size of the texture should be a power of 2
        	Texture2D texture = Texture2D.make(R.drawable.number);
            label[0] = AtlasLabel.make("1", texture, map);
            label[0].setAnchor(0, 0);
            label[0].setPosition(ResolutionIndependent.resolveDp(10), ResolutionIndependent.resolveDp(100));
            addChild(label[0]);
            
            // The size of the texture should be a power of 2
            label[1] = AtlasLabel.make("1", texture, map);
            label[1].setAnchor(0, 0);
            label[1].setColor(new WYColor3B(255, 0, 0));
            label[1].setPosition(ResolutionIndependent.resolveDp(10), ResolutionIndependent.resolveDp(200));
            addChild(label[1]);
            
            // The size of the texture should be a power of 2
            label[2] = AtlasLabel.make("1", texture, map);
            label[2].setAnchor(0, 0);
            label[2].setColor(new WYColor3B(0, 255, 0));
            label[2].setPosition(ResolutionIndependent.resolveDp(10), ResolutionIndependent.resolveDp(300));
            addChild(label[2]);
            
            // 演示中文映射
            map = CharMap.make();
        	map.autoRelease();
    		map.mapChar(ResolutionIndependent.resolve(WYRect.make(1, 1, 21, 21)), '微', 0, ResolutionIndependent.resolveDp(-1));
        	map.mapChar(ResolutionIndependent.resolve(WYRect.make(23, 1, 18, 21)), '云', ResolutionIndependent.resolveDp(1), ResolutionIndependent.resolveDp(1));
        	map.mapChar(ResolutionIndependent.resolve(WYRect.make(42, 1, 18, 21)), '游', ResolutionIndependent.resolveDp(1), ResolutionIndependent.resolveDp(1));
        	map.mapChar(ResolutionIndependent.resolve(WYRect.make(61, 1, 20, 21)), '戏');
        	map.mapChar(ResolutionIndependent.resolve(WYRect.make(82, 1, 14, 21)), '引', ResolutionIndependent.resolveDp(3), ResolutionIndependent.resolveDp(3));
        	map.mapChar(ResolutionIndependent.resolve(WYRect.make(97, 1, 17, 21)), '擎', ResolutionIndependent.resolveDp(2), ResolutionIndependent.resolveDp(1));
            
            // The size of the texture should be a power of 2
        	texture = Texture2D.make(R.drawable.bitmapfont);
        	AtlasLabel chinese = AtlasLabel.make("微云 游戏\t引擎微\n云游戏引擎", texture, map);
        	chinese.setAnchor(0, 0);
        	chinese.setColor(new WYColor3B(255, 255, 0));
        	chinese.setPosition(ResolutionIndependent.resolveDp(10), ResolutionIndependent.resolveDp(400));
            addChild(chinese);
            
            schedule(new TargetSelector(this, "step(float)", new Object[] { 0f }));
        }

        public void step(float dt) {
        	count++;
            label[0].setText(String.format("%d", count));
            label[1].setText(String.format("%d", count));
            label[2].setText(String.format("%d", count));
        }
    }
}
