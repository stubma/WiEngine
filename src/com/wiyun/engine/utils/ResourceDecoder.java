package com.wiyun.engine.utils;

/**
 * \if English
 * Decoder of resource, it will be called before WiEngine parses raw
 * data of a resource. You can install your decoder to protect your game
 * design from decompiling app package. To set a decoder, check \link Director Director\endlink
 * API doc.
 * \else
 * 资源解码器, 它会在WiEngine开始解析一个资源的数据之前调用. 这是一个虚基类, 如果你需要
 * 保护自己游戏的资源, 你可以对资源文件进行处理, 然后实现自己的解码器将资源解密出来. 可以
 * 通过\link Director Director\endlink设置解码器
 * \endif
 */
public interface ResourceDecoder {
	/**
	 * \if English
	 * resource file saved in res folder will be decoded
	 * \else
	 * 存放在res目录下的资源会被解码
	 * \endif
	 */
	public static final int DECODE_RES = 1;

	/**
	 * \if English
	 * resource file saved in assets folder will be decoded
	 * \else
	 * 存放在assets目录下的资源会被解码
	 * \endif
	 */
	public static final int DECODE_ASSETS = 1 << 1;

	/**
	 * \if English
	 * resource file saved in file system will be decoded
	 * \else
	 * 存放在文件系统上的资源会被解码
	 * \endif
	 */
	public static final int DECODE_FILE = 1 << 2;

	/**
	 * \if English
	 * all resource file will be decoded
	 * \else
	 * 不管资源文件保存在什么地方都要解码
	 * \endif
	 */
	public static final int DECODE_ALL = DECODE_RES | DECODE_ASSETS | DECODE_FILE;
	
	/**
	 * \if English
	 * Decode a resource data
	 *
	 * @param data encoded data
	 * @return decoded data, WiEngine will be responsible for releasing it
	 * \else
	 * 解码一个资源数据
	 *
	 * @param data 被编码的数据
	 * @return 解码后的数据, WiEngine会负责释放
	 * \endif
	 */
	public byte[] decode(byte[] data);
}
