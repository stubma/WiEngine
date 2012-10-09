package com.wiyun.engine.filters;

/**
 * \if English
 * Combine many color filters together and perform them one by one. Output
 * of previous filter is the input of next.
 * \else
 * 将多个过滤器组合成一个, 先后执行它们, 后一个过滤器以前一个过滤器的输出为输入.
 * 过滤器越多, 速度可能越慢, 因此要谨慎使用.
 * \endif
 */
public class CombineColorFilter extends ColorFilter {
    /**
     * 从底层指针获得一个CombineColorFilter的Java对象
     * 
     * @param pointer 底层指针
     * @return {@link CombineColorFilter}
     */
    public static CombineColorFilter from(int pointer) {
    	return pointer == 0 ? null : new CombineColorFilter(pointer);
    }
    
	/**
	 * \if English
	 * Static constructor
	 *
	 * @param filter1 first filter, more filters can follow filter1
	 * @param filters more filters
	 * \else
	 * 静态构造函数
	 *
	 * @param filter1 第一个过滤器, 如果有更多过滤器可以跟在后面
	 * @param filters 更多过滤器
	 * \endif
	 */
    public static CombineColorFilter make(ColorFilter filter1, ColorFilter... filters) {
    	return new CombineColorFilter(filter1, filters);
    }
    
    protected CombineColorFilter() {
    }
    
    protected CombineColorFilter(ColorFilter filter1, ColorFilter[] filters) {
    	nativeInit(filter1, filters);
    }
    
    private native void nativeInit(ColorFilter filter1, ColorFilter[] filters);

	protected CombineColorFilter(int pointer) {
    	super(pointer);
    }

	/**
	 * \if English
	 * Add a filter to last
	 *
	 * @param filter color filter to be added
	 * \else
	 * 添加一个过滤器到最后
	 *
	 * @param filter 过滤器
	 * \endif
	 */
	public native void addFilter(ColorFilter filter);
}
