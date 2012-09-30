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
package com.wiyun.engine.tests.other;

import javax.microedition.khronos.opengles.GL10;

import com.wiyun.engine.R;
import com.wiyun.engine.WiEngineTestActivity;
import com.wiyun.engine.nodes.Director;
import com.wiyun.engine.nodes.INodeVirtualMethods;
import com.wiyun.engine.nodes.Layer;
import com.wiyun.engine.opengl.Texture2D;
import com.wiyun.engine.opengl.TextureAtlas;
import com.wiyun.engine.types.WYColor4B;
import com.wiyun.engine.types.WYQuad2D;
import com.wiyun.engine.types.WYQuad3D;
import com.wiyun.engine.types.WYSize;

public class TextureAtlasTest extends WiEngineTestActivity {
	@Override
	protected Layer createLayer() {
		return new MyLayer();
	}

    class MyLayer extends Layer implements INodeVirtualMethods {
        TextureAtlas mTextureAtlas;

        public MyLayer() {
        	setNoDraw(true);
        	setJavaVirtualMethods(this);
        	
            mTextureAtlas = TextureAtlas.make(Texture2D.makeJPG(R.drawable.test_jpg));
            
            // get window size
            WYSize winSize = Director.getInstance().getWindowSize();
    	    float y = (winSize.height - mTextureAtlas.getHeight()) / 2;
    	    float x = (winSize.width - mTextureAtlas.getWidth()) / 2;

            // specify texture coordination and vertice
            WYQuad2D texCoords = new WYQuad2D(
    	    		0.0f, mTextureAtlas.getHeightScale(), mTextureAtlas.getWidthScale(),
    	    		mTextureAtlas.getHeightScale(), 0.0f, 0.0f, mTextureAtlas.getWidthScale(), 0.0f
            );
            WYQuad3D vertex = new WYQuad3D(
    	            x, y, 0,
    	            x + mTextureAtlas.getWidth(), y, 0,
    	            x, y + mTextureAtlas.getHeight(), 0,
    	            x + mTextureAtlas.getWidth(), y + mTextureAtlas.getHeight(), 0
    	    );

            WYColor4B white = new WYColor4B(255, 255, 255, 255);
            mTextureAtlas.updateQuad(texCoords, vertex, 0);
            mTextureAtlas.updateColor(white, 0);
        }

		public void jDraw() {
			GL10 gl = Director.getInstance().gl;
			
            gl.glEnableClientState(GL10.GL_VERTEX_ARRAY);
            gl.glEnableClientState(GL10.GL_TEXTURE_COORD_ARRAY);
            gl.glEnable(GL10.GL_TEXTURE_2D);

            mTextureAtlas.draw();

            gl.glDisable(GL10.GL_TEXTURE_2D);
            gl.glDisableClientState(GL10.GL_VERTEX_ARRAY);
            gl.glDisableClientState(GL10.GL_TEXTURE_COORD_ARRAY);
		}

		public void jOnEnter() {
		}

		public void jOnExit() {
		}
		
		public void jOnEnterTransitionDidFinish() {
		}
    }
}
