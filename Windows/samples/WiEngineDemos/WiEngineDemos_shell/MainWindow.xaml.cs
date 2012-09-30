using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using System.Runtime.InteropServices;

namespace WiEngineDemos_shell
{
    /// <summary>
    /// MainWindow.xaml 的交互逻辑
    /// </summary>
    public partial class MainWindow : Window
    {
        [DllImport("Demo.dll")]
        private static extern void startWiEngineDemos(int clazz, int demoId);

        private list_level_1 m_list1_itemsource;
        private int m_seletectedIndex_list1;

        public MainWindow()
        {
            m_seletectedIndex_list1 = 0;
            InitializeComponent();
            
            list_level_2_proxy.init();
            m_list1_itemsource = listView_demoEntries_level1.ItemsSource as list_level_1;
        }

        private void listView_demoEntries_level1_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            ListView lv = sender as ListView;
            m_seletectedIndex_list1 = lv.SelectedIndex;
            list_level_2 list2_datasource = list_level_2_proxy.ListDictOfLevel2[m_list1_itemsource[lv.SelectedIndex].Title];
            listView_demoEntries_level2.ItemsSource = list2_datasource;
        }

        private void listView_demoEntries_level2_MouseDoubleClick(object sender, MouseButtonEventArgs e)
        {
            ListView lv = sender as ListView;
            MainWindow.startWiEngineDemos(m_seletectedIndex_list1, lv.SelectedIndex);
        }
    }
}
