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
package com.wiyun.engine.tests.lua;

import com.wiyun.engine.R;
import com.wiyun.engine.WiEngineTestActivity;
import com.wiyun.engine.lua.Lua;
import com.wiyun.engine.nodes.Layer;

public class CreateButtonTest extends WiEngineTestActivity {
	@Override
	protected Layer createLayer() {
		return new MyLayer();
	}

    class MyLayer extends Layer {
        public MyLayer() {
        	/*
        	 * 脚本中创建了button, 这个button绑定了一个native端的target selector, 因此正常情况下java端是收不到
        	 * 事件的. 所以WiEngine 3.3.0开始在BaseWYObject中增加了onTargetSelectorInvoked方法, 用于接收lua
        	 * 脚本中创建的target selector事件. 必须调用connectNativeTargetSelector使onTargetSelectorInvoked
        	 * 能够收到事件
        	 */
//        	connectNativeTargetSelector();
        	Lua.init();
        	Lua.setGlobal("layer", this, "wyLayer");
        	Lua.execute(R.raw.create_button);
        	Lua.destroy();
        }
        
//        @Override
//        public void onTargetSelectorInvoked(int id, float delta) {
//        	switch(id) {
//        		case 1:
//        			runOnUiThread(new Runnable() {
//						public void run() {
//							Toast.makeText(CreateButtonTest.this, "Button clicked", Toast.LENGTH_SHORT).show();
//						}
//					});
//        			break;
//        	}
//        }
    }
}
