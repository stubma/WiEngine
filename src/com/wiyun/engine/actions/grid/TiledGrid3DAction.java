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
