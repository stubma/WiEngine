package com.wiyun.engine.nodes;


/**
 * 复合式层。可以用来包含多个层，但任何时刻只有一个层是可见的。
 */
public class MultiplexLayer extends Layer {
    /**
     * 创建复合层
     * 
     * @param params 要包含的层，可变参数
     * @return 复合层实例
     */
    public static MultiplexLayer make(Layer... params) {
        return new MultiplexLayer(params);
    }

    /**
     * 构造函数
     * 
     * @param params 要包含的层，可变参数
     */
    protected MultiplexLayer(Layer... params) {
    	nativeInit();
    	for(Layer layer : params)
    		addLayer(layer);
    }
    
    /**
     * 从底层指针获得一个MultiplexLayer的Java对象
     * 
     * @param pointer 底层指针
     * @return {@link MultiplexLayer}
     */
    public static MultiplexLayer from(int pointer) {
    	return pointer == 0 ? null : new MultiplexLayer(pointer);
    }
    
    protected MultiplexLayer(int pointer) {
    	super(pointer);
    }
    
    @Override
    protected void doNativeInit() {
    }
    
    private native void nativeInit();
    
    /**
     * 添加一个层
     * 
     * @param layer {@link Layer}
     */
    public native void addLayer(Layer layer);
    
    /**
     * 得到当前层，-1表示没有当前层
     */
    public native int getCurrentLayerIndex();

    /**
     * 切换到某个层，通过层的索引，第一个添加的层索引是0，依此类推
     * 
     * @param n 层索引，如果小于0，没有效果。如果大于层的个数，会取余数。
     */
    public native void switchTo(int n);
}

