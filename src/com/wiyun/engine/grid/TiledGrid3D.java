package com.wiyun.engine.grid;

import com.wiyun.engine.types.WYGridSize;
import com.wiyun.engine.types.WYQuad3D;

/**
 * 平铺式网格。{@link TiledGrid3D}的操作单位是矩形块。假如一个网格的行列是2x2，那么这个网格
 * 就有4个矩形块(也叫做Tile)。由于操作单位是块而不是点，所以用{@link TiledGrid3D}做特效时，
 * 可能会产生破碎的感觉，图象之间不再是严丝合缝，而是可能分裂开来，这是和{@link Grid3D}的不同之处。 
 */
public class TiledGrid3D extends BaseGrid {
	/**
	 * \if English
	 * Create a tiled 3d grid
	 *
	 * @param w pixel width of grid
	 * @param h pixel height of grid
	 * @param c row count of the grid
	 * @param r column count of the grid
	 * \else
	 * 创建一个平铺型3d网格
	 *
	 * @param w 网格总宽度
	 * @param h 网格总高度
	 * @param c 网格列数
	 * @param r 网格行数
	 * \endif
	 */
	public static TiledGrid3D make(float w, float h, int c, int r) {
		return new TiledGrid3D(w, h, c, r);
	}

	protected TiledGrid3D(float w, float h, int c, int r) {
        nativeInit(w, h, c, r);
    }
    
    public TiledGrid3D(int pointer) {
    	super(pointer);
    }
	
	private native void nativeInit(float w, float h, int c, int r);

    /**
     * 设置某位置的矩形块坐标，因为矩形由4个点决定，所以使用的是{@link WYQuad3D}
     * 
     * @param pos 矩形块的行列坐标
     * @param coords {@link WYQuad3D}
     */
    public void setTile(WYGridSize pos, WYQuad3D coords) {
    	setTile(pos.x, pos.y, 
    		coords.bl_x, coords.bl_y, coords.bl_z, 
    		coords.br_x, coords.br_y, coords.br_z, 
    		coords.tl_x, coords.tl_y, coords.tl_z, 
    		coords.tr_x, coords.tr_y, coords.tr_z);
    }
    
    private native void setTile(int x, int y, float bl_x, float bl_y, float bl_z, float br_x, float br_y, float br_z, 
    		float tl_x, float tl_y, float tl_z, float tr_x, float tr_y, float tr_z);

    /**
     * 得到某个位置的矩形块原始坐标
     * 
     * @param pos 矩形块的行列坐标
     * @return {@link WYQuad3D}
     */
    public WYQuad3D getOriginalTile(WYGridSize pos) {
    	WYQuad3D tile = new WYQuad3D();
    	getOriginalTile(pos.x, pos.y, tile);
    	return tile;
    }
    
    private native void getOriginalTile(int x, int y, WYQuad3D tile);

    /**
     * 得到某个位置的矩形块坐标
     * 
     * @param pos 矩形块的行列坐标
     * @return {@link WYQuad3D}
     */
    public WYQuad3D getTile(WYGridSize pos) {
    	WYQuad3D tile = new WYQuad3D();
    	getTile(pos.x, pos.y, tile);
    	return tile;
    }
    
    private native void getTile(int x, int y, WYQuad3D tile);
}