package com.wiyun.engine.types;


public class WYSize {
    public float width, height;

    private WYSize() {
        this(0, 0);
    }

    private WYSize(float w, float h) {
        width = w;
        height = h;
    }

    public static WYSize make(float w, float h) {
        return new WYSize(w, h);
    }

    public static WYSize makeZero() {
        return new WYSize(0, 0);
    }
    
    public static boolean isEqual(WYSize s1, WYSize s2) {
        return s1.width == s2.width && s1.height == s2.height;
    }

    @Override
	public String toString() {
        return "<" + width + ", " + height + ">";
    }
}
