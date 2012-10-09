using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Xml;

namespace WiEngineDemos_shell
{
    class androidManifest
    {
        private static XmlDocument s_xmlDoc = null;

        public static XmlDocument Instance
        {
            get
            {
                if (s_xmlDoc == null)
                {
                    s_xmlDoc = new XmlDocument();
                    s_xmlDoc.Load(".\\values\\AndroidManifest.xml");
                }
                return s_xmlDoc;
            }
        }
    }
}
