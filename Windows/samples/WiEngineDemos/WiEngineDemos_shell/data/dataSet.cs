using System;
using System.Linq;
using System.Text;
using System.Collections.ObjectModel;
using System.Collections.Generic;
using System.Xml;
using System.Windows;

namespace WiEngineDemos_shell
{
    public class listItem
    {
        private string m_title;
        private string m_description;

        public listItem()
        {
            m_title = null;
            m_description = null;
        }

        public listItem(string title, string description)
        {
            m_title = title;
            m_description = description;
        }

        public override string ToString()
        {
            return m_title.ToString();
        }

        public string Title
        {
            get { return m_title; }
        }

        public string Desc
        {
            get { return m_description; }
        }
    }

    // items in the 1st level listview
    public class list_level_1 : ObservableCollection<listItem>
    {
        public list_level_1()
            : base()
        {
            SortedDictionary<string, string> dict = new SortedDictionary<string, string>();

            value_string stringValue = value_string.Instance;
            XmlDocument androidManifestDoc = androidManifest.Instance;

            XmlElement nodeApplication = androidManifestDoc.GetElementsByTagName("application")[0] as XmlElement;
            XmlNodeList t = nodeApplication.GetElementsByTagName("meta-data", nodeApplication.NamespaceURI);
            
            XmlElement childOfApplicaiton = nodeApplication.FirstChild as XmlElement;
            while (childOfApplicaiton != null)
            {
                if (childOfApplicaiton.Name == "meta-data")
                {
                    string title = childOfApplicaiton.Attributes["android:name"].Value;
                    //remove _desc postfix
                    int index_desc = title.LastIndexOf("_desc");
                    if (-1 != index_desc)
                    {
                        title = title.Substring(0, index_desc);
                    }
                    //replace '_' in title with ' '
                    title = title.Replace('_', ' ');

                    string desc = childOfApplicaiton.Attributes["android:resource"].Value;
                    //got the real string value from strings.xml
                    if (desc.StartsWith("@string"))
                    {
                        int index_backslash = desc.LastIndexOf('/');
                        if (-1 != index_backslash)
                        {
                            desc = stringValue.getString(desc.Substring(index_backslash + 1));
                        }
                    }

                    dict.Add(title, desc);
                }
                childOfApplicaiton = childOfApplicaiton.NextSibling as XmlElement;
            }

            SortedDictionary<string, string>.Enumerator enumerator = dict.GetEnumerator();
            while(enumerator.MoveNext()) {
                Add(new listItem(enumerator.Current.Key, enumerator.Current.Value));
            }
        }
    }

    // items in the 2nd level listview
    public class list_level_2 : ObservableCollection<listItem>
    {
        private string m_class;

        public list_level_2() :base()
        {
            m_class = "Action";
            init(m_class);
        }

        public list_level_2(string clazz)
            : base()
        {
            m_class = clazz;
            init(m_class);
        }

        private void init(string clazz)
        {
            SortedDictionary<string, string> dict = new SortedDictionary<string, string>();
            value_string stringValue = value_string.Instance;
            XmlDocument androidManifestDoc = androidManifest.Instance;

            XmlElement nodeApplication = androidManifestDoc.GetElementsByTagName("application")[0] as XmlElement;
            XmlNodeList t = nodeApplication.GetElementsByTagName("meta-data", nodeApplication.NamespaceURI);

            XmlElement childOfApplicaiton = nodeApplication.FirstChild as XmlElement;
            while (childOfApplicaiton != null)
            {
                if (childOfApplicaiton.Name == "activity")
                {
                    if (childOfApplicaiton.GetElementsByTagName("intent-filter").Count == 0)
                    {
                        childOfApplicaiton = childOfApplicaiton.NextSibling as XmlElement;
                        continue;
                    }

                    // test if it is a qualified 2nd entry
                    XmlElement intent_filter = childOfApplicaiton.GetElementsByTagName("intent-filter")[0] as XmlElement;
                    if (childOfApplicaiton.GetElementsByTagName("category").Count == 0)
                    {
                        childOfApplicaiton = childOfApplicaiton.NextSibling as XmlElement;
                        continue;
                    }

                    XmlElement category = intent_filter.GetElementsByTagName("category")[0] as XmlElement;
                    string category_value = category.Attributes["android:name"].Value;
                    if (category_value.CompareTo("android.intent.category.TEST") == 0)
                    {
                        // get which class it belongs and the title value
                        string label = childOfApplicaiton.Attributes["android:label"].Value;
                        string title = label;
                        int index_backslash = label.IndexOf('/');
                        if (-1 != index_backslash)
                        {
                            string claz = label.Substring(0, index_backslash);
                            if (clazz.CompareTo(claz) != 0)
                            {
                                childOfApplicaiton = childOfApplicaiton.NextSibling as XmlElement;
                                continue;
                            }
                            title = label.Substring(index_backslash + 1);
                        }

                        // get the description
                        string desc = null;
                        XmlNodeList meta_datas = childOfApplicaiton.GetElementsByTagName("meta-data");
                        if(meta_datas.Count == 0) {
                            desc = " ";
                        } else {
                            XmlElement meta_data = meta_datas[0] as XmlElement;
                            desc = meta_data.Attributes["android:resource"].Value;
                            //got the real string value from strings.xml
                            if (desc.StartsWith("@string"))
                            {
                                index_backslash = desc.LastIndexOf('/');
                                if (-1 != index_backslash)
                                {
                                    desc = stringValue.getString(desc.Substring(index_backslash + 1));
                                }
                            }
                        }

                        dict.Add(title, desc);
                    }
                }
                childOfApplicaiton = childOfApplicaiton.NextSibling as XmlElement;
            }

            SortedDictionary<string, string>.Enumerator enumerator = dict.GetEnumerator();
            while (enumerator.MoveNext())
            {
                Add(new listItem(enumerator.Current.Key, enumerator.Current.Value));
            }
        }
    }

    public class list_level_2_proxy
    {
        private static SortedDictionary<string, list_level_2> s_ListDict = null;

        public static void init() {
            s_ListDict = new SortedDictionary<string, list_level_2>();
            MainWindow mWnd = Application.Current.MainWindow as MainWindow;
            list_level_1 ll1 = mWnd.listView_demoEntries_level1.ItemsSource as list_level_1;
            for (int i = 0; i < ll1.Count; ++i)
            {
                list_level_2 ll2 = new list_level_2(ll1[i].Title);
                s_ListDict.Add(ll1[i].Title, ll2);
            }
        }

        public static SortedDictionary<string, list_level_2> ListDictOfLevel2
        {
            get
            {
                return s_ListDict;
            }
        }
    }
}
