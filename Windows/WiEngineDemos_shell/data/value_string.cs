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
﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Xml;
using System.Globalization;

namespace WiEngineDemos_shell
{
   
    public class value_string
    {
        private static value_string s_thiz = null;
        private SortedDictionary<string, string> m_dict;

        protected value_string()
        {
        }

        protected value_string(string xmlPath)
        {
            XmlDocument xmlDoc = new XmlDocument();
            xmlDoc.Load(xmlPath);

            m_dict = new SortedDictionary<string, string>();
            XmlNodeList nodes = xmlDoc.GetElementsByTagName("string");
            for (int i = 0; i < nodes.Count; ++i)
            {
                m_dict.Add(nodes[i].Attributes["name"].Value, nodes[i].InnerText);
            }
        }

        public string getString(string key)
        {
            return m_dict[key];
        }

        public static value_string Instance
        {
            get
            {
                if (s_thiz == null)
                {
                    CultureInfo ci = CultureInfo.CurrentUICulture;
                    if(ci.TwoLetterISOLanguageName.Equals("zh"))
                        s_thiz = new value_string(".\\values\\strings-zh.xml");
                    else
                        s_thiz = new value_string(".\\values\\strings-en.xml");
                }
                return s_thiz;
            }
        }
    }
}
