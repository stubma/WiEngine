
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
package com.wiyun.engine;

import java.text.Collator;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import android.app.ListActivity;
import android.content.Intent;
import android.content.pm.PackageInfo;
import android.content.pm.PackageManager;
import android.content.pm.ResolveInfo;
import android.content.pm.PackageManager.NameNotFoundException;
import android.os.Bundle;
import android.text.TextUtils;
import android.view.View;
import android.view.Window;
import android.view.WindowManager;
import android.widget.ListView;
import android.widget.SimpleAdapter;
import android.widget.TextView;

public class WiEngineDemos extends ListActivity {
	@Override
	public void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		getWindow().addFlags(WindowManager.LayoutParams.FLAG_FULLSCREEN);
		requestWindowFeature(Window.FEATURE_NO_TITLE);
		setContentView(R.layout.main);

		Intent intent = getIntent();
		String path = intent.getStringExtra("com.wiyun.engine.tests.Path");
		if(path == null) {
			path = "";
		}

		setListAdapter(new SimpleAdapter(this, 
			getData(path), 
			android.R.layout.simple_list_item_2, 
			new String[] {
				"title",
				"desc"
			}, 
			new int[] {
				android.R.id.text1,
				android.R.id.text2
			}));
		getListView().setTextFilterEnabled(true);
		
        try {
        	TextView tv = (TextView)findViewById(R.id.tv_version);
	        PackageManager pm = getPackageManager();
	        PackageInfo pi = pm.getPackageInfo(getPackageName(), 0);
	        tv.setText(pi.versionName);
        } catch (NameNotFoundException e) {
        }
	}

	protected List<Map<String, Object>> getData(String prefix) {
		List<Map<String, Object>> myData = new ArrayList<Map<String, Object>>();

		Intent mainIntent = new Intent(Intent.ACTION_MAIN, null);
		mainIntent.addCategory(Intent.CATEGORY_TEST);

		PackageManager pm = getPackageManager();
		List<ResolveInfo> list = pm.queryIntentActivities(mainIntent, PackageManager.GET_META_DATA);

		if(null == list)
			return myData;

		String[] prefixPath;

		if(prefix.equals("")) {
			prefixPath = null;
		} else {
			prefixPath = prefix.split("/");
		}

		int len = list.size();

		Map<String, Boolean> entries = new HashMap<String, Boolean>();

		String pkg = getPackageName();
		for(int i = 0; i < len; i++) {
			ResolveInfo info = list.get(i);
			if(!info.activityInfo.applicationInfo.packageName.startsWith(pkg))
				continue;
			
			CharSequence labelSeq = info.loadLabel(pm);
			if(TextUtils.isEmpty(labelSeq))
				continue;
			String label = labelSeq.toString();

			if(prefix.length() == 0 || label.startsWith(prefix)) {
				String[] labelPath = label.split("/");
				String nextLabel = prefixPath == null ? labelPath[0] : labelPath[prefixPath.length];
				if((prefixPath != null ? prefixPath.length : 0) == labelPath.length - 1) {
					// special check for no_android meta data
					boolean no_android = info.activityInfo.metaData == null ? false : info.activityInfo.metaData.getBoolean("no_android");
					if(no_android)
						continue;
					
					int id = info.activityInfo.metaData == null ? 0 : info.activityInfo.metaData.getInt("desc");
					String desc = id == 0 ? "" : getString(id);
					addItem(myData, nextLabel, desc, activityIntent(info.activityInfo.applicationInfo.packageName, info.activityInfo.name));
				} else {
					if(entries.get(nextLabel) == null) {
						int id = info.activityInfo.applicationInfo.metaData == null ? 0 : info.activityInfo.applicationInfo.metaData.getInt(nextLabel.replace(' ', '_') + "_desc");
						String desc = id == 0 ? "" : getString(id);
						addItem(myData, nextLabel, desc, browseIntent(prefix.equals("") ? nextLabel : prefix + "/" + nextLabel));
						entries.put(nextLabel, true);
					}
				}
			}
		}

		Collections.sort(myData, sDisplayNameComparator);

		return myData;
	}

	private final static Comparator<Map<String, Object>> sDisplayNameComparator = new Comparator<Map<String, Object>>() {
		private final Collator collator = Collator.getInstance();

		public int compare(Map<String, Object> map1, Map<String, Object> map2) {
			return collator.compare(map1.get("title"), map2.get("title"));
		}
	};

	protected Intent activityIntent(String pkg, String componentName) {
		Intent result = new Intent();
		result.setClassName(pkg, componentName);
		return result;
	}

	protected Intent browseIntent(String path) {
		Intent result = new Intent();
		result.setClass(this, WiEngineDemos.class);
		result.putExtra("com.wiyun.engine.tests.Path", path);
		return result;
	}

	protected void addItem(List<Map<String, Object>> data, String title, String desc, Intent intent) {
		Map<String, Object> temp = new HashMap<String, Object>();
		temp.put("title", title);
		temp.put("desc", desc);
		temp.put("intent", intent);
		data.add(temp);
	}

	@Override
	@SuppressWarnings("unchecked")
	protected void onListItemClick(ListView l, View v, int position, long id) {
		Map<String, Object> map = (Map<String, Object>)l.getItemAtPosition(position);
		Intent intent = (Intent)map.get("intent");
		startActivity(intent);
	}
}