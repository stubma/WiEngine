package net.rbgrn.opengl;

import javax.microedition.khronos.egl.EGL10;
import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.egl.EGLDisplay;

import android.opengl.GLSurfaceView;

public class WYConfigChooser implements GLSurfaceView.EGLConfigChooser {
	private boolean mTransparent;
	
	WYConfigChooser(boolean transparent) {
		mTransparent = transparent;
	}
	
	public EGLConfig chooseConfig(EGL10 egl, EGLDisplay display) {
		/*
		 * build a preferred config first
		 */
		
		// color bits
		int r = 5, g = 6, b = 5, a = 0;
		if (mTransparent) {
			r = 8;
			g = 8;
			b = 8;
			a = 8;
		}
		int i = 0;
		int[] config_attribs = new int[32];
		config_attribs[31] = EGL10.EGL_NONE;
    	config_attribs[i++] = EGL10.EGL_RED_SIZE;
		config_attribs[i++] = r;
		config_attribs[i++] = EGL10.EGL_GREEN_SIZE;
		config_attribs[i++] = g;
		config_attribs[i++] = EGL10.EGL_BLUE_SIZE;
		config_attribs[i++] = b;
		config_attribs[i++] = EGL10.EGL_ALPHA_SIZE;
		config_attribs[i++] = a;
		
		// z buffer
		config_attribs[i++] = EGL10.EGL_DEPTH_SIZE;
		config_attribs[i++] = 16;
		
		// stencil buffer
		config_attribs[i++] = EGL10.EGL_STENCIL_SIZE;
		config_attribs[i++] = 8;
		
		// render type
		config_attribs[i++] = EGL10.EGL_RENDERABLE_TYPE;
		config_attribs[i++] = 4; /* EGL_OPENGL_ES2_BIT */
		
		// surface type
		config_attribs[i++] = EGL10.EGL_SURFACE_TYPE;
		config_attribs[i++] = EGL10.EGL_WINDOW_BIT;
		
		// end
        config_attribs[i] = EGL10.EGL_NONE;

        // let system return a matched config
		int[] num_config = new int[1];
		egl.eglChooseConfig(display, config_attribs, null, 0, num_config);
		
		// no matched? throw error
		if(num_config[0] <= 0)
			throw new IllegalArgumentException("Failed to find a suitable config");
		
		// use matched config
		EGLConfig[] configs = new EGLConfig[num_config[0]];
		egl.eglChooseConfig(display, config_attribs, configs, num_config[0], num_config);
		
		// We need to find a suitable config that matches our pixel format
		int[] value = new int[1];
		for(int j = 0; j < num_config[0]; ++j) {
			if((egl.eglGetConfigAttrib(display, configs[j], EGL10.EGL_RED_SIZE,   value) && value[0] == r)
			&& (egl.eglGetConfigAttrib(display, configs[j], EGL10.EGL_GREEN_SIZE, value) && value[0] == g)
			&& (egl.eglGetConfigAttrib(display, configs[j], EGL10.EGL_BLUE_SIZE,  value) && value[0] == b)
			&& (egl.eglGetConfigAttrib(display, configs[j], EGL10.EGL_ALPHA_SIZE, value) && value[0] == a))
				return configs[j];
        }
		return null;
    }
}