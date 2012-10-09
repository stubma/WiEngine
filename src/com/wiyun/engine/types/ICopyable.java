package com.wiyun.engine.types;

/**
 * 实现该接口表示对象支持拷贝自身 
 */
public interface ICopyable {
    /**
     * 对自身做一个拷贝
     * 
     * @return 自身的拷贝对象
     */
    public Object copy();
}
