using System;
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
