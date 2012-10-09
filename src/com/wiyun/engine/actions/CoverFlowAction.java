package com.wiyun.engine.actions;

import com.wiyun.engine.nodes.Cover;

/**
 * \if English
 * Action to move a cover in \link CoverFlow CoverFlow\endlink, it brings target cover
 * to front with an animation
 * \else
 * 节点\link CoverFlow CoverFlow\endlink 的action, 把目标封面移动到最前
 * \endif
 */
public class CoverFlowAction extends IntervalAction {
	/**
	 * \if English
	 * CoverFlowAction doesn't support cloning
	 * \else
	 * CoverFlowAction不支持拷贝方法
	 * \endif
	 */
	@Override
	public IntervalAction copy() {
		throw new UnsupportedOperationException("CoverFlowAction doesn't have reverse action");
	}
	
	/**
	 * \if English
	 * CoverFlowAction doesn't have reverse action
	 * \else
	 * CoverFlowAction不支持逆向动作
	 * \endif
	 */
	@Override
	public IntervalAction reverse() {
		throw new UnsupportedOperationException("CoverFlowAction doesn't have reverse action");
	}
	
	protected CoverFlowAction(){};

	protected CoverFlowAction(int pointer) {
		super(pointer);
	}
	
	private native void nativeInit(float duration, Cover targetCover);

	protected CoverFlowAction(float duration, Cover targetCover) {
		nativeInit(duration, targetCover);
	}

	/**
	 * \if English
	 * static constructor
	 *
	 * @param duration action duration in seconds
	 * @param targetCover target \link Cover Cover\endlink object which should be moved to front
	 * @return \link CoverFlowAction CoverFlowAction\endlink
	 * \else
	 * 静态构造函数
	 *
	 * @param duration 动画执行时间
	 * @param targetCover 指定下一个当前cover
	 * @return \link CoverFlowAction CoverFlowAction\endlink
	 * \endif
	 */
	public static CoverFlowAction make(float duration, Cover targetCover) {
		return new CoverFlowAction(duration, targetCover);
	}

	public static CoverFlowAction from(int pointer) {
		return pointer == 0 ? null : new CoverFlowAction(pointer);
	}
}