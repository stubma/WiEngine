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

#include "wyDevice.h"
#include "wyMD5.h"
#include "wyLog.h"
#include "wyMemory.h"
#include <winsock2.h>
#include <iphlpapi.h>
#include <stdio.h>

// language code
static char sLanguage[3];

// country code
static char sCountry[3];

// uuid
static char sIMEI[64];

const char* wyDevice::getLanguage() {
	GetLocaleInfo(LOCALE_USER_DEFAULT, LOCALE_SISO639LANGNAME, sLanguage, 3);
	return sLanguage;
}

const char* wyDevice::getCountry() {
	GetLocaleInfo(LOCALE_USER_DEFAULT, LOCALE_SISO3166CTRYNAME, sCountry, 3);
	return sCountry;
}

const char* wyDevice::getDeviceId() {
	// Get the buffer length required for IP_ADAPTER_INFO.
	ULONG bufLen = 0;
	BYTE* buffer = 0;
	if(GetAdaptersInfo(0, &bufLen) == ERROR_BUFFER_OVERFLOW) {
		// Now the BufferLength contain the required buffer length.
		// Allocate necessary buffer.
		buffer = new BYTE[bufLen];

		// Get the Adapter Information.
		PIP_ADAPTER_INFO adapterInfo = reinterpret_cast<PIP_ADAPTER_INFO>(buffer);
		GetAdaptersInfo(adapterInfo, &bufLen);

		// Iterate the network adapters and print their MAC address.
		if(adapterInfo) {
			// Assuming pAdapterInfo->AddressLength is 6.
			sprintf(sIMEI, "%02x:%02x:%02x:%02x:%02x:%02x",
				adapterInfo->Address[0],
				adapterInfo->Address[1],
				adapterInfo->Address[2],
				adapterInfo->Address[3],
				adapterInfo->Address[4],
				adapterInfo->Address[5]);
		}

		// make md5 for mac address
		const char* md5 = wyMD5::md5(sIMEI);
		memcpy(sIMEI, md5, strlen(md5));
		wyFree((void*)md5);

		// release buffer
		delete[] buffer;

		// return
		return sIMEI;
	} else {
		return NULL;
	}
}

bool wyDevice::hasExternalStorage() {
	// for windows, always return false
	return false;
}

#endif // #if WINDOWS
