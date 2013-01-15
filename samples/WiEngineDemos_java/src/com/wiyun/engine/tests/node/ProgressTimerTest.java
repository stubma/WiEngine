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

import static com.wiyun.engine.utils.Utilities.*;

import com.wiyun.engine.R;
import com.wiyun.engine.WiEngineTestActivity;
import com.wiyun.engine.nodes.Director;
import com.wiyun.engine.nodes.Layer;
import com.wiyun.engine.nodes.ProgressTimer;
import com.wiyun.engine.nodes.Sprite;
import com.wiyun.engine.opengl.Texture2D;
import com.wiyun.engine.types.WYSize;
import com.wiyun.engine.utils.ZwoptexManager;

public class ProgressTimerTest extends WiEngineTestActivity {
	@Override
	protected Layer createLayer() {
		return new MyLayer();
	}
	
    class MyLayer extends Layer {
    	public MyLayer() {
    		// 逆时针进度条
            WYSize s = Director.getInstance().getWindowSize();
            ProgressTimer pt1 = ProgressTimer.make(R.drawable.grossini);
            pt1.setStyle(ProgressTimer.RADIAL_CCW);
            pt1.setPercentage(75);
            pt1.setAnchor(0, 0);
            pt1.setPosition(s.width / 2 + 30, s.height / 2);
            addChild(pt1);
            
            // 使用atlas sprite构造进度条, 顺时针进度条
            int idx = rand(14) + 1;
            ZwoptexManager.addZwoptex("grossini", R.raw.grossini_dance_atlas, Texture2D.make(R.drawable.grossini_dance_atlas));
            Sprite sprite = ZwoptexManager.makeSprite(String.format("grossini_dance_%02d.png", idx));
            sprite.autoRelease();
            ProgressTimer pt2 = ProgressTimer.make(sprite);
            pt2.setStyle(ProgressTimer.RADIAL_CW);
            pt2.setPercentage(75);
            pt2.setAnchor(0, 1);
            pt2.setPosition(s.width / 2 + 30, s.height / 2);
            addChild(pt2);
            
            // 水平形式的进度条
            ProgressTimer pt3 = ProgressTimer.make(R.drawable.grossini);
            pt3.setStyle(ProgressTimer.HORIZONTAL_BAR_LR);
            pt3.setPercentage(60);
            pt3.setAnchor(1, 1);
            pt3.setPosition(s.width / 2 - 30, s.height / 2);
            addChild(pt3);
            
            // 使用atlas sprite构造进度条, 样式为垂直
            ProgressTimer pt4 = ProgressTimer.make(sprite);
            pt4.setStyle(ProgressTimer.VERTICAL_BAR_BT);
            pt4.setPercentage(75);
            pt4.setAnchor(1, 0);
            pt4.setPosition(s.width / 2 - 30, s.height / 2);
            addChild(pt4);
		}
    }
}
