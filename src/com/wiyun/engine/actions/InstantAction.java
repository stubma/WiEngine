package com.wiyun.engine.actions;


/**
 * \if English
 * Base class for actions who ends immediately. However, its duration is not zero, but very very small.
 * setDuration has no effect for instant actions.
 * \else
 * 瞬间动作的封装, 是所有瞬间动作的基类
 * \endif
 */
public abstract class InstantAction extends FiniteTimeAction {
    protected InstantAction() {
    	// assign a small duration so that it can be composed by sequence
        super(0.001f);
    }
    
	protected InstantAction(int pointer) {
		super(pointer);
	}

    @Override
    public boolean isDone() {
        return true;
    }

    @Override
    public void step(float delta) {
    	// because it is executed immediately, so no need to implement step()
    }

    @Override
	public void update(float input) {
    	// because it is executed immediately, so no need to implement update()
    }

    @Override
    public abstract InstantAction copy();
    
    @Override
    public abstract InstantAction reverse();
}

