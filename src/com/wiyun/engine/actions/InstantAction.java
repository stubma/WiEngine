/*
 * Copyright (c) 2010 WiYun Inc.
 * Author: luma(stubma@gmail.com)
 *
 * For all entities this program is free software; you can redistribute
 * it and/or modify it under the terms of the 'WiEngine' license with
 * the additional provision that 'WiEngine' must be credited in a manner
 * that can be be observed by end users, for example, in the credits or during
 * start up. (please find WiEngine logo in sdk's logo folder)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
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

