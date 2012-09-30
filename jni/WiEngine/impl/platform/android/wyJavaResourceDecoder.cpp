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
#if ANDROID

#include "wyJavaResourceDecoder.h"
#include "wyTypes.h"
#include "wyUtils.h"

extern jmethodID g_mid_ResourceDecoder_decode;

wyJavaResourceDecoder::wyJavaResourceDecoder(jobject decoder) :
		m_jDecoder(NULL) {
	JNIEnv* env = wyUtils::getJNIEnv();
	if(decoder)
		m_jDecoder = env->NewGlobalRef(decoder);
}

wyJavaResourceDecoder::~wyJavaResourceDecoder() {
	if(m_jDecoder) {
		JNIEnv* env = wyUtils::getJNIEnv();
		env->DeleteGlobalRef(m_jDecoder);
		m_jDecoder = NULL;
	}
}

wyJavaResourceDecoder* wyJavaResourceDecoder::make(jobject decoder) {
	return new wyJavaResourceDecoder(decoder);
}

const char* wyJavaResourceDecoder::decode(const char* data, size_t length, size_t* outLen) {
	if(m_jDecoder) {
		// create source array
		JNIEnv* env = wyUtils::getJNIEnv();
		jbyteArray src = env->NewByteArray(length);
		env->SetByteArrayRegion(src, 0, length, (const jbyte*)data);

		// call java side method
		jbyteArray ret = (jbyteArray)env->CallObjectMethod(m_jDecoder, g_mid_ResourceDecoder_decode, src);

		// save out length
		jsize retLen = env->GetArrayLength(ret);
		if(outLen)
			*outLen = retLen;

		// copy returned data
		char* decoded = (char*)wyMalloc(length * sizeof(char));
		jbyte* retData = env->GetByteArrayElements(ret, NULL);
		memcpy(decoded, retData, retLen * sizeof(char));

		// release
		env->ReleaseByteArrayElements(ret, retData, 0);
		env->DeleteLocalRef(src);
		env->DeleteLocalRef(ret);

		// return
		return decoded;
	} else {
		if(outLen)
			*outLen = length;
		return data;
	}
}

#endif // #if ANDROID
