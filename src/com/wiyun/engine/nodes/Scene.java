package com.wiyun.engine.nodes;


/**
 * 场景是一个全屏的节点，一般只用作顶层容器。 
 */
public class Scene extends Node {
    /**
     * 创建场景
     * 
     * @return 场景实例
     */
    public static Scene make() {
        return new Scene();
    }
    
    protected Scene() {
    	/*
    	 * 这里需要检查mPointer是否为0，对于TransitionScene以及他们的子类来说，
    	 * 我们不需要打开key事件处理，而且我们也打不开，因为TransitionScene以及
    	 * 它们的子类此时还没有生成底层实例，会导致setKeyEnabled失败，因此必须
    	 * 要做一个空指针检查
    	 */
    	if(mPointer != 0)
    		setKeyEnabled(true);
    }
    
    /**
     * 从底层指针获得一个Scene的Java对象
     * 
     * @param pointer 底层指针
     * @return {@link Scene}
     */
    public static Scene from(int pointer) {
    	return pointer == 0 ? null : new Scene(pointer);
    }
    
    protected Scene(int pointer) {
    	super(pointer);
    }
    
	protected void doNativeInit() {
		nativeInit();
	}
    
    private native void nativeInit();
    
    @Override
    protected boolean onBackButton() {
    	Director.getInstance().popScene();
    	return true;
    }
}