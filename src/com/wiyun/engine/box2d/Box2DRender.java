package com.wiyun.engine.box2d;

import com.wiyun.engine.BaseWYObject;
import com.wiyun.engine.box2d.dynamics.Fixture;
import com.wiyun.engine.opengl.Texture2D;
import com.wiyun.engine.types.WYRect;

/**
 * \if English
 * Renderer of box2d. It can bind texture to fixture and render it. This is a simple
 * way but not a high performance way.
 * \else
 * Box2D的渲染器, 通过这个类可以为物体绑定贴图, 绑定的贴图将被这个渲染器所渲染. 这是一种较为
 * 省事的方式, 但性能并不好.
 * \endif
 */
public class Box2DRender extends BaseWYObject {
	public static Box2DRender make() {
		return new Box2DRender();
	}
	
	public static Box2DRender from(int pointer) {
		return pointer == 0 ? null : new Box2DRender(pointer);
	}
	
	protected Box2DRender() {
		nativeInit();
	}
	
	protected Box2DRender(int pointer) {
		super(pointer);
	}
	
	private native void nativeInit();
	
	/**
	 * 给某个fixture绑定一个贴图
	 *
	 * @param f {@link Fixture}对象
	 * @param tex {@link Texture2D}对象, 如果为NULL， 则是取消之前的绑定
	 */
	public native void bindTexture(Fixture f, Texture2D tex);

	/**
	 * 给某个fixture绑定一个贴图
	 *
	 * @param f {@link Fixture}对象
	 * @param tex {@link Texture2D}对象, 如果为NULL， 则是取消之前的绑定
	 * @param rect {@link WYRect}
	 */
	public native void bindTexture(Fixture f, Texture2D tex, WYRect rect);
}
