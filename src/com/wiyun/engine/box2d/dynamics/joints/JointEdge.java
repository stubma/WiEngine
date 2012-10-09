package com.wiyun.engine.box2d.dynamics.joints;

import com.wiyun.engine.BaseObject;
import com.wiyun.engine.box2d.dynamics.Body;

public class JointEdge extends BaseObject {
	public static JointEdge from(int pointer) {
		return pointer == 0 ? null : new JointEdge(pointer);
	}

	protected JointEdge() {
	}

	protected JointEdge(int pointer) {
		super(pointer);
	}
	
	public Body getOther(){
		return Body.from(nativeGetOther());
	}
	
	public int getJoint(){
		return nativeGetJoint();
	}
	
	public JointEdge getPrevJointEdge(){
		return JointEdge.from(nativeGetPrev());
	}

	public JointEdge getNextJointEdge(){
		return JointEdge.from(nativeGetNext());
	}

	public native int nativeGetOther();
	public native int nativeGetJoint();
	public native int nativeGetPrev();
	public native int nativeGetNext();
}
