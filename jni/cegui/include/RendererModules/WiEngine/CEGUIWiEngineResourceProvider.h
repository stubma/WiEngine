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
#ifndef __CEGUIWiEngineResourceProvider_h__
#define __CEGUIWiEngineResourceProvider_h__

#include "CEGUI.h"

namespace CEGUI {

/**
 * Resource provider which is based on WiEngine framework, it loads resource
 * thru WiEngine mechanism. However, it doesn't support access resource saved
 * in res folder because CEGUI doesn't has such concept. All resource files will
 * be mapped to assets folder.
 */
class CEGUIEXPORT WiEngineResourceProvider : public DefaultResourceProvider {
public:
	WiEngineResourceProvider();
	virtual ~WiEngineResourceProvider();

	/// @see CEGUI::ResourceProvider::loadRawDataContainer
	virtual void loadRawDataContainer(const String& filename, RawDataContainer& output, const String& resourceGroup);

	/// @see CEGUI::ResourceProvider::getResourceGroupFileNames
    virtual size_t getResourceGroupFileNames(std::vector<String>& out_vec,
                                             const String& file_pattern,
                                             const String& resource_group);
};

} // end of namespace CEGUI

#endif // __CEGUIWiEngineResourceProvider_h__
