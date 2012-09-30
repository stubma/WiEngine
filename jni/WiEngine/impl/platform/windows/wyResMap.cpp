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
#if WINDOWS

#include "wyResMap.h"
#include "wyMemory.h"
#include "wyTypes.h"
#include "wyUtils.h"
#include "wyLog.h"
#include <windows.h>
#include "wyAndroidStrings.h"

// singleton
static wyResMap* s_instance = NULL;

wyResMap::wyResMap() {
	m_moduleDir = (char*)malloc(512 * sizeof(char));
	m_fullPath = (char*)malloc(1024 * sizeof(char));
	m_moduleConfigINI = (char*)malloc(1024 * sizeof(char));
	m_fileList = new vector<const char*>();
	m_fileList->reserve(100);
	m_resMap = new map<unsigned int, int>();
}

wyResMap::~wyResMap() {
	// release
	free(m_moduleDir);
	free(m_fullPath);
	free(m_moduleConfigINI);

	// release file path
	for(vector<const char*>::iterator iter = m_fileList->begin(); iter != m_fileList->end(); iter++) {
		free((void*)*iter);
	}
	delete m_fileList;

	// release map
	delete m_resMap;

	// nullify singleton
	s_instance = NULL;
}

wyResMap* wyResMap::getInstance() {
	if(!s_instance) {
		s_instance = new wyResMap();
		s_instance->setup();
	}
	return s_instance;
}

const char* wyResMap::copy(const char* src) {
	if(src == NULL)
		return NULL;

	size_t len = strlen(src);
	char* c = (char*)calloc(len + 1, sizeof(char));
	memcpy(c, src, len);
	return c;
}

void wyResMap::setup() {
	// update module dir
	updateModuleDir();

	// because resource id 0 is invalid, so we push a placeholder to file list
	m_fileList->push_back(copy("__placeholder__"));

	// collect file list
	char path[1024];
	char relPath[1024];
	sprintf(path, "%s", m_moduleDir);
	relPath[0] = 0;
	collectFileList(NULL, path, relPath);

	// build resource id
	int resId = 0;
	for(vector<const char*>::iterator iter = m_fileList->begin(); iter != m_fileList->end(); ) {
		// get a normalized relative path
		sprintf(path, "%s", *iter);
		wyUtils::deletePathExtensionInSameBuffer(path);

		// get hash of it
		unsigned int hash = wyUtils::strHash(path);

		// if has this entry, remove it
		// if not, add it
		map<unsigned int, int>::iterator found = m_resMap->find(hash);
		if(found != m_resMap->end()) {
			// warning log
			LOGW("Warning: same name (%s) resource in same folder", *iter);

			// remove
			free((void*)*iter);
			iter = m_fileList->erase(iter);
		} else {
			// add
			(*m_resMap)[hash] = resId;
			resId++;

			// next
			iter++;
		}
	}
}

void wyResMap::collectFileList(char* dir, char* path, char* relativePath) {
	// get full path
	if(dir) {
		sprintf(path, "%s\\%s\\*", path, dir);
		if(relativePath[0] == 0)
			sprintf(relativePath, "%s", dir);
		else
			sprintf(relativePath, "%s\\%s", relativePath, dir);
	} else {
		sprintf(path, "%s\\*", path);
	}

	// find first file
	WIN32_FIND_DATA wfd;
	HANDLE hFind = FindFirstFile(path, &wfd);
	bool found = hFind != INVALID_HANDLE_VALUE;

	// find all files
	while(found) {
		// exclude . and ..
		if(!strcmp(wfd.cFileName, ".") || !strcmp(wfd.cFileName, "..")) {
			// skip . and .., so do nothing
		} else {
			// recursively calling or add to file list
			if(wfd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
				// must delete end asterisk, but remember balance it after returns
				wyUtils::deleteLastPathComponentInSameBuffer(path);
				collectFileList((char*)wfd.cFileName, path, relativePath);
				sprintf(path, "%s\\*", path);
			} else {
				char filePath[1024];
				if(dir)
					sprintf(filePath, "%s\\%s", relativePath, wfd.cFileName);
				else
					sprintf(filePath, "%s", wfd.cFileName);
				m_fileList->push_back(copy(filePath));
			}
		}

		// find next file
		found = FindNextFile(hFind, &wfd) != 0;
	}

	// close this find session
	FindClose(hFind);

	// cut current dir from path
	if(dir)
		wyUtils::deleteLastPathComponentInSameBuffer(path);
	wyUtils::deleteLastPathComponentInSameBuffer(path);
	wyUtils::deleteLastPathComponentInSameBuffer(relativePath);
}

void wyResMap::updateModuleDir() {
	GetModuleFileName(NULL, m_moduleDir, 512);
	if(GetLastError() == ERROR_SUCCESS) {
		wyUtils::deleteLastPathComponentInSameBuffer(m_moduleDir);
		sprintf(m_moduleConfigINI, "%s\\config.ini", m_moduleDir);
	}
}

int wyResMap::getResId(const char* name) {
	// null checking
	if(!name)
		return 0;

	// copy the name
	char buf[128];
	sprintf(buf, "%s", name);

	// find parts, must be three parts
	bool threePart = true;
	char* parts[3];
	parts[0] = strtok((char*)buf, ".");
	if(parts[0] == NULL) {
		threePart = false;
	} else {
		for(int i = 1; i < 3; i++) {
			parts[i] = strtok(NULL, ".");
			if(parts[i] == NULL) {
				threePart = false;
				break;
			}
		}
	}

	// if not three part, return
	if(!threePart) {
		LOGE("Invalid res id string: %s", name);
		return 0;
	}

	// special case for string
	if(strcmp(parts[1], "string") == 0) {
		return wyAndroidStrings::getInstance()->getKeyIndex(parts[2]);
	}

	// build resource relative path, and find it in res map
	char path[128];
	sprintf(path, "%s\\%s", parts[1], parts[2]);
	unsigned int hash = wyUtils::strHash(path);
	map<unsigned int, int>::iterator iter = m_resMap->find(hash);
	if(iter != m_resMap->end()) {
		return iter->second + 0x7f000000;
	}

	// then not found
	return 0;
}

const char* wyResMap::getResFilePath(int resId) {
	// we add 0x7f000000 to resId so that it keeps same start value with android, need subtract here
	resId -= 0x7f000000;

	// actually res id is a index of file list, so simple
	if(resId < 0 || resId >= m_fileList->size()) {
		return NULL;
	} else {
		sprintf(m_fullPath, "%s\\%s", m_moduleDir, m_fileList->at(resId));
		return m_fullPath;
	}
}

const char* wyResMap::getAssetFilePath(const char* path) {
	char* bak = (char*)wyUtils::copy(path);
	wyUtils::replaceChar(bak, '/', '\\');
	sprintf(m_fullPath, "%s\\assets\\%s", m_moduleDir, bak);
	wyFree(bak);
	return m_fullPath;
}

const char* wyResMap::getLocalFilePath(const char* path) {
	char* bak = (char*)wyUtils::copy(path);
	wyUtils::replaceChar(bak, '/', '\\');
	sprintf(m_fullPath, "%s%s", m_moduleDir, bak);
	wyFree(bak);
	return m_fullPath;
}

#endif // #if WINDOWS
