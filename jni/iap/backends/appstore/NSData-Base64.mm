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
#if IOS || MACOSX

#import "NSData-Base64.h"
#include "wyGlobal.h"

@implementation NSData (Base64)

const char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/=";

- (NSData*)base64Encode {
	const unsigned char* data = (const unsigned char*)[self bytes];
    int len = [self length];
    
    NSMutableData* target = [NSMutableData dataWithLength: ((len - 1) / 3 + 1) * 4];
    unsigned char* output = (unsigned char*)[target mutableBytes];
    
    unsigned long val;
    int quad, trip;
    
    for(int i = 0, j = 0; i < len; i += 3, j += 4) {
        quad = 0;
        trip = 0;
        
        val = data[i];
        val <<= 8;
        
        if((i + 1) < len) {
            val |= data[i + 1];
            trip = 1;
        }
        val <<= 8;
        
        if((i + 2) < len) {
            val |= data[i + 2];
            quad = 1;
        }
        
        output[j + 3] = alphabet[(quad ? (val & 0x3f) : 64)];
        val >>= 6;
        output[j + 2] = alphabet[(trip ? (val & 0x3f) : 64)];
        val >>= 6;
        output[j + 1] = alphabet[val & 0x3f];
        val >>= 6;
        output[j] = alphabet[val];
    }
    
    return target;
}

- (NSData*)base64Decode {
	const unsigned char* data = (const unsigned char*)[self bytes];
    int len = [self length];
    
    NSMutableData* target = [NSMutableData dataWithLength: (len / 4) * 3];
    unsigned char* out = (unsigned char*)[target mutableBytes];
    
    UInt32 val;
    
    for(int i = 0, j = 0; i + 3 < len; i += 4, j += 3) {
        val = 0;
        for(int k = i; k < i + 4; k++) {
            if(data[k] >= 'A' && data[k] <= 'Z') {
                val <<= 6;
                val += data[k] - 'A';
            } else if(data[k] >= 'a' && data[k] <= 'z') {
                val <<= 6;
                val += data[k] - 'a' + 26;
            } else if(data[k] >= '0' && data[k] <= '9') {
                val <<= 6;
                val += data[k] - '0' + 52;
            } else if(data[k] == '+') {
                val <<= 6;
                val += 62;
            } else if(data[k] == '/') {
                val <<= 6;
                val += 63;
            } else {
                val <<= 6;
            }
        }
		
		val = htobe32(val);
        memcpy(out + j, ((unsigned char*)(&val)) + 1, 3);
    }
	
	data = (const unsigned char*)[target bytes];
	len = 0;
	for(int i = [target length] - 1; i >= 0; i--, len++) {
		if(data[i] != 0)
			break;
	}
	return [NSData dataWithBytes:[target bytes] length:([target length] - len)];
}

@end

#endif // #if IOS || MACOSX