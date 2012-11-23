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
#include "CEGUIWiEngineResourceProvider.h"
#include "WiEngine.h"

namespace CEGUI {

WiEngineResourceProvider::WiEngineResourceProvider() {
}

WiEngineResourceProvider::~WiEngineResourceProvider() {
}

void WiEngineResourceProvider::loadRawDataContainer(const String& filename, RawDataContainer& output, const String& resourceGroup) {
	// file name validation
    if (filename.empty())
        CEGUI_THROW(InvalidRequestException("WiEngineResourceProvider::load: Filename supplied for data loading must be valid"));

    // final relative path in assets folder
    const String final_filename(getFinalFilename(filename, resourceGroup));

    // delegate to WiEngine
    size_t len;
    char* raw = wyUtils::loadRaw(final_filename.c_str(), false, &len);

    // set in output
    output.setData((uint8*)raw);
    output.setSize(len);
}

size_t WiEngineResourceProvider::getResourceGroupFileNames(std::vector<String>& out_vec,
                                         const String& file_pattern,
                                         const String& resource_group) {
    // look-up resource group name
    ResourceGroupMap::const_iterator iter = d_resourceGroups.find(
    		resource_group.empty() ? d_defaultResourceGroup : resource_group);

    // get directory that's set for the resource group
    const String dir_name(iter != d_resourceGroups.end() ? (*iter).second : "./");

    // list
    size_t len;
    const char** files = wyUtils::listAssetFiles(dir_name.c_str(), &len, file_pattern.c_str());

    // add to vector
    for(int i = 0; i < len; i++) {
    	out_vec.push_back(files[i]);
    }

    // release
    for(int i = 0; i < len; i++) {
    	free((void*)files[i]);
    }
    free((void*)files);

    // return count
	return len;
}

} // end of namespace CEGUI
