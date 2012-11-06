package com.wiyun.engine.shader;

import com.wiyun.engine.BaseWYObject;

/**
 * Base class for shader variable
 */
public class ShaderVariable extends BaseWYObject {
	/// Type of shader variables
	public enum Type {
		/// boolean
	    BOOLEAN,

	    /// int
	    INT,

	    /// float
	    FLOAT,

	    /// 2d vector
	    VEC2,

	    /// 3d vector
	    VEC3,

	    /// 4d vector
	    VEC4,

	    /// 3d matrix
	    MAT3,

	    /// 4d matrix
	    MAT4,

	    /// float array
	    FLOAT_ARRAY,

	    /// 2d vector array
	    VEC2_ARRAY,

	    /// 3d vector array
	    VEC3_ARRAY,

	    /// 4d vector array
	    VEC4_ARRAY,

	    /// 3d matrix array
	    MAT3_ARRAY,

	    /// 4d matrix array
	    MAT4_ARRAY,

	    /// sampler 2d
	    TEXTURE_2D,

	    /// sampler 3d
	    TEXTURE_3D,

	    /// texture cubemap
	    TEXTURE_CUBEMAP,

	    /// interleaved buffer
	    INTERLEAVED_BUFFER
	};
	
	protected ShaderVariable(int pointer) {
		super(pointer);
	}
	
	public static ShaderVariable from(int pointer) {
		return pointer == 0 ? null : new ShaderVariable(pointer);
	}
	
	/**
	 * Get parameter location in shader
	 *
	 * @return location
	 */
	public native int getLocation();

	/**
	 * Get name of variable
	 *
	 * @return name string, caller should not release it
	 */
	public native String getName();

	/**
	 * Get type of variable
	 *
	 * @return variable type
	 */
	public Type getType() {
		return Type.values()[nativeGetType()];
	}
	
	private native int nativeGetType();

	/**
	 * Reset value to zero
	 */
	public native void clearValue();

	/**
	 * Is this variable set?
	 *
	 * @return true means variable is already set
	 */
	public native boolean isSet();

	/**
	 * True means this variable value should be sync to current program
	 */
	public native boolean isNeedSync();

	/**
	 * Flag variable need to be set to program
	 */
	public native void setNeedSync(boolean flag);
}
