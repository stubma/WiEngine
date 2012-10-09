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

import android.content.Intent;

import com.wiyun.engine.R;
import com.wiyun.engine.WiEngineTestActivity;
import com.wiyun.engine.nodes.Director;
import com.wiyun.engine.nodes.Layer;
import com.wiyun.engine.nodes.Menu;
import com.wiyun.engine.nodes.MenuItemLabel;
import com.wiyun.engine.utils.VideoPlayingActivity;

public class VideoPlayingTest extends WiEngineTestActivity {
	@Override
	protected Layer createLayer() {
		return new MyLayer();
	}

    class MyLayer extends Layer {
        public MyLayer() {
            MenuItemLabel item = MenuItemLabel.make("Play Video", this, "onPlayVideo");

            Menu menu = Menu.make(item);
            menu.alignItemsVertically();

            addChild(menu);
        }
        
        public void onPlayVideo() {
        	// 要记得在AndroidManifest.xml中注册VideoPlayingActivity
        	Intent i = new Intent(Director.getInstance().getContext(), VideoPlayingActivity.class);
        	i.putExtra(VideoPlayingActivity.EXTRA_IN_VIDEO_RES_ID, R.raw.test_video);
        	i.putExtra(VideoPlayingActivity.EXTRA_IN_END_ON_TOUCH, true);
        	i.putExtra(VideoPlayingActivity.EXTRA_IN_NO_COMPLETION_DIALOG, true);
        	Director.getInstance().getContext().startActivity(i);
        }
    }
}
