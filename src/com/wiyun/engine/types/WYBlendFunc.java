package com.wiyun.engine.types;

/**
 * Blend Function used for textures
 */
public class WYBlendFunc {
    //! source blend function
    public int src;
    
    //! destination blend function
    public int dst;

    public WYBlendFunc(int s, int d) {
        src = s;
        dst = d;
    }

    public int getSrc() {
        return src;
    }

    public int getDst() {
        return dst;
    }
}
