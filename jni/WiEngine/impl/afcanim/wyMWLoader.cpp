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
#include "wyMWLoader.h"
#include "wyMWFileData.h"
#include "wyTypes.h"
#include "wyUtils.h"
#include "wyGlobal.h"

wyMWFileData* wyMWLoader::load(const char* data, size_t length, float resScale) {
	// create return object
	wyMWFileData* returnAnimeData = WYNEW wyMWFileData();

	// save scale
	returnAnimeData->m_resScale = resScale;

	// temporary variable
	short* animationTable;
	short* frameTable;
	short* framePoolTable;
	short* imageClipPool;
	int*   ellipseClipPool;
	int*   lineClipPool;
	int*   rectangleClipPool;
	int*   roundedRectangleClipPool;
	short* positionerRectangleClipPool;
	short* frameTableIndex;
	short* imageIndex;

	// may change in other version of motion welder
	int startByteIndex = 7;
	int curByteIndex = startByteIndex;

	// read animation table
	int numOfAnimation = data[curByteIndex];
	curByteIndex++;
	animationTable = (short*)wyMalloc((numOfAnimation << 1) * sizeof(short));
	for (int i = 0; i < numOfAnimation; i++) {
		animationTable[2 * i] = betoh16(*(unsigned short*)(&data[curByteIndex]));
		curByteIndex += 2;

		animationTable[2 * i + 1] = betoh16(*(unsigned short*)(&data[curByteIndex]));
		curByteIndex += 2;
	}

	// read frame table
	int numOfFrame = betoh16(*(unsigned short*) (&data[curByteIndex]));
	curByteIndex += 2;
	frameTable = (short*)wyMalloc(numOfFrame * 4 * sizeof(short));
	for (int i = 0; i < numOfFrame; i++) {
		frameTable[4 * i] = betoh16(*(unsigned short*)(&data[curByteIndex]));
		curByteIndex += 2;

		frameTable[4 * i + 1] = data[curByteIndex];
		curByteIndex++;

		frameTable[4 * i + 2] = betoh16(*(unsigned short*)(&data[curByteIndex]));
		curByteIndex += 2;

		frameTable[4 * i + 3] = betoh16(*(unsigned short*)(&data[curByteIndex]));
		curByteIndex += 2;
	}

	// read frame pool table
	unsigned short len = betoh16(*(unsigned short*)(&data[curByteIndex]));
	curByteIndex +=2;
	framePoolTable = (short*)wyMalloc(len * sizeof(short));
	int noOfFrameInPool = betoh16(*(unsigned short*)(&data[curByteIndex]));
	curByteIndex += 2;
	short index = 0;
	frameTableIndex = (short*)wyMalloc((noOfFrameInPool << 1) * sizeof(short));
	for (int i = 0; i < noOfFrameInPool; i++) {
		frameTableIndex[2 * i] = index;
		short noOfClips = betoh16(*(unsigned short*) (&data[curByteIndex]));
		curByteIndex += 2;

		for (int j = 0; j < noOfClips; j++) {
			// index
			framePoolTable[index++] = betoh16(*(unsigned short*)(&data[curByteIndex]));
			curByteIndex += 2;

			// xpos
			framePoolTable[index++] = betoh16(*(unsigned short*)(&data[curByteIndex]));
			curByteIndex += 2;

			// ypos
			framePoolTable[index++] = betoh16(*(unsigned short*)(&data[curByteIndex]));
			curByteIndex += 2;

			// flag, flag % 2 == 0 means it is a image clip, only support 32 image
			framePoolTable[index++] = data[curByteIndex];
			curByteIndex++;
		}
		frameTableIndex[2 * i + 1] = (short) (index - 1);
	}

	// read clip pool
	int noOfImagesClips = betoh16(*(unsigned short*) (&data[curByteIndex]));
	curByteIndex += 2;
	int noOfImages = data[curByteIndex];
	curByteIndex++;
	imageClipPool = (short*)wyMalloc((noOfImagesClips << 2) * sizeof(short));
	index = 0;
	imageIndex = (short*)wyMalloc(noOfImages * sizeof(short));
	short noOfClipsRead = 0;
	for (int i = 0; i < noOfImages; i++) {
		imageIndex[i] = noOfClipsRead;
		int noOfClipsInThisImage = betoh16(*(unsigned short*) (&data[curByteIndex]));
		curByteIndex += 2;
		for (int j = 0; j < noOfClipsInThisImage; j++) {
			// x
			imageClipPool[index++] = betoh16(*(unsigned short*) (&data[curByteIndex]));
			curByteIndex += 2;

			// y
			imageClipPool[index++] = betoh16(*(unsigned short*) (&data[curByteIndex]));
			curByteIndex += 2;

			// w
			imageClipPool[index++] = betoh16(*(unsigned short*) (&data[curByteIndex]));
			curByteIndex += 2;

			// h
			imageClipPool[index++] = betoh16(*(unsigned short*) (&data[curByteIndex]));
			curByteIndex += 2;
		}
		noOfClipsRead += noOfClipsInThisImage;
	}

	// ellipse
	int noOfEllipseClip = betoh16(*(unsigned short*) (&data[curByteIndex]));
	curByteIndex += 2;
	ellipseClipPool = (int*)wyMalloc(noOfEllipseClip * 5 * sizeof(int));
	for (int i = 0; i < noOfEllipseClip; i++) {
		// w
		ellipseClipPool[5 * i] = betoh16(*(unsigned short*) (&data[curByteIndex]));
		curByteIndex += 2;

		// h
		ellipseClipPool[5 * i + 1] = betoh16(*(unsigned short*) (&data[curByteIndex]));
		curByteIndex += 2;

		// start angle
		ellipseClipPool[5 * i + 2] = betoh16(*(unsigned short*) (&data[curByteIndex]));
		curByteIndex += 2;

		// end angle
		ellipseClipPool[5 * i + 3] = betoh16(*(unsigned short*) (&data[curByteIndex]));
		curByteIndex += 2;

		// color
		ellipseClipPool[5 * i + 4] = *(unsigned int*)(&data[curByteIndex]);
		curByteIndex += 4;
	}

	// Line
	int noOfLineClip = betoh16(*(unsigned short*) (&data[curByteIndex]));
	curByteIndex += 2;
	lineClipPool = (int*)wyMalloc(noOfLineClip * 3 * sizeof(int));
	for (int i = 0; i < noOfLineClip; i++) {
		// x
		lineClipPool[3 * i] = betoh16(*(unsigned short*) (&data[curByteIndex]));
		curByteIndex += 2;

		// y
		lineClipPool[3 * i + 1] = betoh16(*(unsigned short*) (&data[curByteIndex]));
		curByteIndex += 2;

		// color
		lineClipPool[3 * i + 2] = betoh32(*(unsigned int*) (&data[curByteIndex]));
		curByteIndex += 4;
	}

	// Rectangle
	int noOfRectangleClip = betoh16(*(unsigned short*) (&data[curByteIndex]));
	curByteIndex += 2;
	rectangleClipPool = (int*)wyMalloc(noOfRectangleClip * 3 * sizeof(int));
	for (int i = 0; i < noOfRectangleClip; i++) {
		// w
		rectangleClipPool[3 * i] = betoh16(*(unsigned short*) (&data[curByteIndex]));
		curByteIndex += 2;

		// h
		rectangleClipPool[3 * i + 1] = betoh16(*(unsigned short*) (&data[curByteIndex]));
		curByteIndex += 2;

		// color
		rectangleClipPool[3 * i + 2] = betoh32(*(unsigned int*) (&data[curByteIndex]));
		curByteIndex += 4;
	}

	// rounded Rect
	int noOfRoundedRectangleClip = betoh16(*(unsigned short*) (&data[curByteIndex]));
	curByteIndex += 2;
	roundedRectangleClipPool = (int*)wyMalloc(noOfRoundedRectangleClip * 5 * sizeof(int));
	for (int i = 0; i < noOfRoundedRectangleClip; i++) {
		// w
		roundedRectangleClipPool[5 * i] = betoh16(*(unsigned short*) (&data[curByteIndex]));
		curByteIndex += 2;

		// h
		roundedRectangleClipPool[5 * i + 1] = betoh16(*(unsigned short*) (&data[curByteIndex]));
		curByteIndex += 2;

		// arc width
		roundedRectangleClipPool[5 * i + 2] = betoh16(*(unsigned short*) (&data[curByteIndex]));
		curByteIndex += 2;

		// arc height
		roundedRectangleClipPool[5 * i + 3] = betoh16(*(unsigned short*) (&data[curByteIndex]));
		curByteIndex += 2;

		// color
		roundedRectangleClipPool[5 * i + 4] = betoh32(*(unsigned int*) (&data[curByteIndex]));
		curByteIndex += 4;
	}

	// positioner rounded Rect
	int noOfPositionerRectangleClip = betoh16(*(unsigned short*) (&data[curByteIndex]));
	curByteIndex += 2;
	positionerRectangleClipPool = (short*)wyMalloc((noOfPositionerRectangleClip << 1) * sizeof(short));
	for (int i = 0; i < noOfPositionerRectangleClip; i++) {
		// w
		positionerRectangleClipPool[2 * i] = betoh16(*(unsigned short*) (&data[curByteIndex]));
		curByteIndex += 2;

		// h
		positionerRectangleClipPool[2 * i + 1] = betoh16(*(unsigned short*) (&data[curByteIndex]));
		curByteIndex += 2;
	}

	// assign
	returnAnimeData->m_numOfImage = noOfImages;
	returnAnimeData->m_numOfAnimation = numOfAnimation;
	returnAnimeData->m_animationTable = animationTable;
	returnAnimeData->m_frameTable = frameTable;
	returnAnimeData->m_framePoolTable = framePoolTable;
	returnAnimeData->m_imageClipPool = imageClipPool;
	returnAnimeData->m_ellipseClipPool = ellipseClipPool;
	returnAnimeData->m_lineClipPool = lineClipPool;
	returnAnimeData->m_rectangleClipPool = rectangleClipPool;
	returnAnimeData->m_roundedRectangleClipPool = roundedRectangleClipPool;
	returnAnimeData->m_positionerRectangleClipPool = positionerRectangleClipPool;
	returnAnimeData->m_frameTableIndex = frameTableIndex;
	returnAnimeData->m_imageIndex = imageIndex;
	returnAnimeData->autoRelease();
	return returnAnimeData;
}

wyMWFileData* wyMWLoader::load(int mwResId) {
	// load data and call other method to parse anu file
	size_t len;
	float scale;
	char* raw = wyUtils::loadRaw(mwResId, &len, &scale);
	wyMWFileData* data = load(raw, len, scale);
	data->m_dataId = mwResId;
	wyFree(raw);

	// return
	return data;
}

wyMWFileData* wyMWLoader::load(const char* path, bool isFile) {
	// load data and call other method to parse anu file
	size_t len;
	char* raw = wyUtils::loadRaw(path, isFile, &len);
	wyMWFileData* data = load(raw, len, wyDevice::density / wyDevice::defaultInDensity);
	data->m_dataId = wyUtils::strHash(path);
	wyFree(raw);

	// return
	return data;
}

wyMWFileData* wyMWLoader::loadMemory(const char* mfsName) {
	// get data from memory file system
	const char* mfsData = NULL;
	size_t length = 0;
	wyUtils::getFile(mfsName, &mfsData, &length);
	wyMWFileData* data = load(mfsData, length, wyDevice::density / wyDevice::defaultInDensity);
	data->m_dataId = wyUtils::strHash(mfsName);

	// return
	return data;
}
