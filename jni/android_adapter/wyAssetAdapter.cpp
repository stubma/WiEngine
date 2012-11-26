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
#include "wyAssetAdapter.h"
#include <string.h>
#include <endian.h>
#include "utils/AssetManager.h"
#include "utils/ResourceTypes.h"
#include <jni.h>
#include "wyLog.h"
#include <fnmatch.h>

typedef enum {
	SCALE_MODE_BY_DENSITY,
	SCALE_MODE_BASE_SIZE_FIT_XY
} wyScaleMode;

#define CLASS_ASSETMANAGER "android/content/res/AssetManager"

#ifdef __cplusplus
extern "C" {
#endif

// utils lib is in android namespace
using namespace android;

extern JNIEnv* getEnv();
extern JavaVM* gVM;
static jobject jobject_Context = NULL;
static jmethodID jmethodID_Context_getAssets;
static jclass jclass_AssetManager = NULL;
static jmethodID jmethodID_AssetManager_list;
static jfieldID jfieldID_AssetManager_mObject;
static wyScaleMode sScaleMode = SCALE_MODE_BY_DENSITY;
static float sDensity = 1.0f;

static AssetManager* assetManagerForJavaObject(JNIEnv* env, jobject obj) {
	AssetManager* am = (AssetManager*)env->GetIntField(obj, jfieldID_AssetManager_mObject);
	return am;
}

void deinit() {
	JNIEnv* env = getEnv();
	if(jclass_AssetManager) {
		env->DeleteGlobalRef(jclass_AssetManager);
		jclass_AssetManager = NULL;
	}
	if(jobject_Context) {
		env->DeleteGlobalRef(jobject_Context);
		jobject_Context = NULL;
	}
	gVM = NULL;
}

void setEnv(void* env) {
	JNIEnv* je = (JNIEnv*)env;
	je->GetJavaVM(&gVM);
	jclass c = je->FindClass(CLASS_ASSETMANAGER);
	jclass_AssetManager = (jclass)je->NewGlobalRef(c);
	jmethodID_AssetManager_list = je->GetMethodID(jclass_AssetManager, "list", "(Ljava/lang/String;)[Ljava/lang/String;");
	jfieldID_AssetManager_mObject = je->GetFieldID(jclass_AssetManager, "mObject", "I");
}

void setContext(void* context) {
	JNIEnv* env = getEnv();
	if(jobject_Context) {
		env->DeleteGlobalRef(jobject_Context);
		jobject_Context = NULL;
	}
	if(context) {
		jobject_Context = env->NewGlobalRef((jobject)context);
		jclass clazz = env->GetObjectClass(jobject_Context);
		jmethodID_Context_getAssets = env->GetMethodID(clazz, "getAssets", "()Landroid/content/res/AssetManager;");
		env->DeleteLocalRef(clazz);
	}
}

void setDensity(float density) {
	sDensity = density;
}

void setScaleMode(int mode) {
	sScaleMode = (wyScaleMode)mode;
}

void* getAsset(const char* path) {
	// get env
	JNIEnv* env = getEnv();

	// get asset manager
	jobject amObj = env->CallObjectMethod(jobject_Context, jmethodID_Context_getAssets);

	// get asset manager c++ class
	AssetManager* am = assetManagerForJavaObject(env, amObj);
	env->DeleteLocalRef(amObj);

	// open asset and return
	Asset* a = am->open(path, Asset::ACCESS_RANDOM);
	return (void*)a;
}

void* getAssetByResId(int id, float* scale) {
	// get env
	JNIEnv* env = getEnv();

	// get asset manager
	jobject amObj = env->CallObjectMethod(jobject_Context, jmethodID_Context_getAssets);

	// get asset manager c++ class
	AssetManager* am = assetManagerForJavaObject(env, amObj);
	env->DeleteLocalRef(amObj);

	// get resource
	const ResTable& res(am->getResources());

	/*
	 * XXX: 这段神奇的代码可以解决华为机型上获取不到资源id的相关信息
	 * 的问题, 这个问题导致了所有的资源id都只能得到第一个图片. 如果资源
	 * 是放在assets下的, 没有这个问题. 经过调查, 发现不管什么资源id, 在
	 * 经过res.getResource调用后, 返回的相关信息全是0, 这个现象比较奇怪,
	 * 原因也不知道.
	 *
	 * 而更神奇的地方是这两行代码看上去和其它代码没有任何交互关系, 可以说
	 * 是无用的代码, 但是加上之后, res.getResource返回的信息再也不是0了.
	 * 问天问地问爹娘, 这个问题伤不起.
	 *
	 * 我只能猜测是华为修改过Asset的底层实现, 而getResourceName神奇的帮助
	 * 了某个问题, 虽然从c代码层面上看不到任何关联.
	 */
	ResTable::resource_name rn;
	res.getResourceName(id, &rn);

	// get resource info
	Res_value value;
	ResTable_config config;
	uint32_t typeSpecFlags;
	ssize_t block = res.getResource(id, &value, false,
#if HONEYCOMB
			0,
#endif
			&typeSpecFlags, &config);
	uint32_t ref = id;
	block = res.resolveReference(&value, block, &ref);
	void* cookie = 0;
	char string[128];
	String8* s8 = NULL;
	if(block >= 0) {
		// get cookie
		cookie = res.getTableCookie(block);

		/**
		 * obtain resource string if it is TYPE_STRING
		 * XXX: comment data type checking, because we found in some model, such as
		 * lephone 1.0(based on android 1.6), the data type is 0 so that the resource
		 * string can't be loaded. Have to disable this checking for lephone compatibility
		 */
//		if(value.dataType == Res_value::TYPE_STRING) {
			size_t len;
			ResStringPool* rsp = (ResStringPool*)res.getTableStringBlock(block);
			const char16_t* s16 = rsp->stringAt(value.data, &len);
			if(s16 != NULL) {
				// we need convert utf16 to utf8
				s8 = new String8(s16);
				strcpy(string, s8->string());
			} else {
				string[0] = 0;
			}
//		}
	}
	Asset* a = cookie != NULL
		? am->openNonAsset(cookie, string, Asset::ACCESS_RANDOM)
		: am->openNonAsset(string, Asset::ACCESS_RANDOM);

	// decide scale, if not density mode, always 1
	if(sScaleMode == SCALE_MODE_BY_DENSITY) {
		if(scale != NULL) {
			switch(config.density) {
				case ResTable_config::DENSITY_LOW:
				case ResTable_config::DENSITY_MEDIUM:
				case ResTable_config::DENSITY_HIGH:
					*scale = sDensity * 160 / config.density;
					break;
				default:
					if(config.density > 0 && config.density != 0xffff)
						*scale = sDensity * 160 / config.density;
					else
						*scale = sDensity * 160 / ResTable_config::DENSITY_MEDIUM;
					break;
			}
		}
	} else {
		if(scale)
			*scale = 1;
	}

	// free s8
	if(s8 != NULL)
		delete s8;

	return (void*)a;
}

void* getAssetBuffer(void* asset) {
	return asset == NULL ? NULL : (void*)((Asset*)asset)->getBuffer(false);
}

int getAssetLength(void* asset) {
	return asset == NULL ? 0 : ((Asset*)asset)->getLength();
}

int getAssetRemainingLength(void* asset) {
	return asset == NULL ? 0 : ((Asset*)asset)->getRemainingLength();
}

ssize_t readAsset(void* asset, char* buffer, size_t length) {
	return asset == NULL ? -1 : ((Asset*)asset)->read(buffer, length);
}

typedef int64_t (android::Asset::*seek64)(int64_t offset, int whence);
int seekAsset(void* asset, int offset, int mode) {
	if(asset) {
		/**
		 * Android 3.x中Asset::seek方法的参数变成了一个64位整数, 因此为了
		 * 兼容3.x, 做了以下workaround
		 * 1. 首先按照Asset.h定义的seek原型调用
		 * 2. 如果上一步返回值和我们预期的不一致, 我们认为这是不正常的, 因此
		 *    强行把seek的指针cast成64位版本再调用一次
		 */
		Asset* a = (Asset*)asset;
		int expected = getAssetLength(asset) - getAssetRemainingLength(asset);
		switch(mode) {
			case SEEK_CUR:
				expected += offset;
				break;
			case SEEK_SET:
				expected = offset;
				break;
			case SEEK_END:
				expected = a->getLength() + offset;
				break;
			default:
				expected = -1;
				break;
		}
		int ret = a->seek(offset, mode);
		if(ret != expected) {
			seek64 f64 = (seek64)&android::Asset::seek;
			ret = (a->*f64)(offset, mode);
		}
		return ret;
	}

	return -1;
}

void closeAsset(void* asset) {
	if(asset) {
		Asset* a = (Asset*)asset;
		a->close();
		delete a;
	}
}

void getResFD(int resId, size_t* outFD, size_t* outOffset, size_t* outLength, float* outScale) {
	// open asset
	Asset* a = (android::Asset*)getAssetByResId(resId, outScale);

	// get file descriptor
    off_t offset, length;
    int fd = a->openFileDescriptor(&offset, &length);

	// save fd info
	*outFD = dup(fd);
	*outOffset = offset;
	*outLength = length;
	close(fd);
	delete a;
}

void getAssetFD(const char* path, size_t* outFD, size_t* outOffset, size_t* outLength) {
	// open asset
	Asset* a = (android::Asset*)getAsset(path);

	// get file descriptor
    off_t offset, length;
    int fd = a->openFileDescriptor(&offset, &length);

	// save fd info
	*outFD = dup(fd);
	*outOffset = offset;
	*outLength = length;
	close(fd);
	delete a;
}

const char* utf16toutf8(const char16_t* s16) {
	String8* str = new String8(s16);
	char* s8 = (char*)calloc(str->size() + 1, sizeof(char));
	strcpy(s8, str->string());
	delete str;
	return s8;
}

const char16_t* toUTF16(const char* s8) {
	String16* str = new String16(s8);
	char16_t* s16 = (char16_t*)calloc(str->size() + 1, sizeof(char16_t));
	memcpy(s16, str->string(), sizeof(char16_t) * str->size());
	delete str;

	return (const char16_t*)s16;
}

const char* wctoutf8(const wchar_t* ws) {
	String8* str = new String8((const char32_t*)ws);
	char* s8 = (char*)calloc(str->size() + 1, sizeof(char));
	strcpy(s8, str->string());
	delete str;
	return s8;
}

const char** listAssetFiles(const char* path, size_t* outLen, const char* pattern) {
	// get env
	JNIEnv* env = getEnv();

	// get asset manager
	jobject amObj = env->CallObjectMethod(jobject_Context, jmethodID_Context_getAssets);

	// get list
	jstring jPath = env->NewStringUTF(path == NULL ? "" : path);
	jobjectArray jFiles = (jobjectArray)env->CallObjectMethod(amObj, jmethodID_AssetManager_list, jPath);
	jsize len = env->GetArrayLength(jFiles);

	// get c string list, copy java string content to c string
	int count = 0;
	char** files = (char**)malloc(sizeof(char*) * len);
	for(int i = 0; i < len; i++) {
		jstring jFile = (jstring)env->GetObjectArrayElement(jFiles, i);
		jsize size = env->GetStringUTFLength(jFile);
		const char* jFileStr = (const char*)env->GetStringUTFChars(jFile, NULL);
		if(!pattern || fnmatch(pattern, jFileStr, 0) == 0) {
			files[count] = (char*)calloc(sizeof(char), size + 1);
			memcpy(files[count], jFileStr, size);
			count++;
		}
		env->ReleaseStringUTFChars(jFile, jFileStr);
		env->DeleteLocalRef(jFile);
	}

	// return len
	if(outLen)
		*outLen = count;

	// release
	env->DeleteLocalRef(jPath);
	env->DeleteLocalRef(jFiles);

	// return
	return (const char**)files;
}

#ifdef __cplusplus
}
#endif
