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
package com.wiyun.engine.actions.grid;

import com.wiyun.engine.types.WYGridSize;
import com.wiyun.engine.types.WYQuad3D;

/**
 * 平铺型网格动作基类。 
 */
public abstract class TiledGrid3DAction extends GridAction {
	protected TiledGrid3DAction(float duration, WYGridSize gSize) {
    }
	
	protected TiledGrid3DAction() {
	}
	
	protected TiledGrid3DAction(int pointer) {
		super(pointer);
	}

	@Override
	public abstract TiledGrid3DAction copy();
	
    public WYQuad3D getTile(WYGridSize pos) {
    	WYQuad3D tile = new WYQuad3D();
    	getTile(pos.x, pos.y, tile);
    	return tile;
    }
    
    private native void getTile(int x, int y, WYQuad3D tile);
	
    public WYQuad3D getOriginalTile(WYGridSize pos) {
    	WYQuad3D tile = new WYQuad3D();
    	getOriginalTile(pos.x, pos.y, tile);
    	return tile;
    }
    
    private native void getOriginalTile(int x, int y, WYQuad3D tile);
	
    public void setTile(WYGridSize pos, WYQuad3D coords) {
    	setTile(pos.x, pos.y, 
    		coords.bl_x, coords.bl_y, coords.bl_z, 
    		coords.br_x, coords.br_y, coords.br_z, 
    		coords.tl_x, coords.tl_y, coords.tl_z, 
    		coords.tr_x, coords.tr_y, coords.tr_z);
    }
    
    private native void setTile(int x, int y, float bl_x, float bl_y, float bl_z, float br_x, float br_y, float br_z, 
    		float tl_x, float tl_y, float tl_z, float tr_x, float tr_y, float tr_z);
}
