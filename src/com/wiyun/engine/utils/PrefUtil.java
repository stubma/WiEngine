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
package com.wiyun.engine.utils;

import android.content.SharedPreferences;
import android.content.SharedPreferences.Editor;
import android.preference.PreferenceManager;

import com.wiyun.engine.nodes.Director;

public class PrefUtil {
    public static int getIntPref(String name, int def) {
    	SharedPreferences p = PreferenceManager.getDefaultSharedPreferences(Director.getInstance().getContext());
        return p.getInt(name, def);
    }
    
    public static void setIntPref(String name, int value) {
    	SharedPreferences p = PreferenceManager.getDefaultSharedPreferences(Director.getInstance().getContext());
        Editor ed = p.edit();
        ed.putInt(name, value);
        ed.commit();
    }
    
    public static long getLongPref(String name, long def) {
    	SharedPreferences p = PreferenceManager.getDefaultSharedPreferences(Director.getInstance().getContext());
        return p.getLong(name, def);
    }
    
    public static void setLongPref(String name, long value) {
    	SharedPreferences p = PreferenceManager.getDefaultSharedPreferences(Director.getInstance().getContext());
        Editor ed = p.edit();
        ed.putLong(name, value);
        ed.commit();
    }
    
    public static String getStringPref(String name, String def) {
    	SharedPreferences p = PreferenceManager.getDefaultSharedPreferences(Director.getInstance().getContext());
    	return p.getString(name, def);
    }
    
    public static void setStringPref(String name, String value) {
    	SharedPreferences p = PreferenceManager.getDefaultSharedPreferences(Director.getInstance().getContext());
    	Editor ed = p.edit();
    	ed.putString(name, value);
    	ed.commit();
    }
    
    public static boolean getBoolPref(String name, boolean def) {
    	SharedPreferences p = PreferenceManager.getDefaultSharedPreferences(Director.getInstance().getContext());
    	return p.getBoolean(name, def);
    }
    
    public static void setBoolPref(String name, boolean value) {
    	SharedPreferences p = PreferenceManager.getDefaultSharedPreferences(Director.getInstance().getContext());
    	Editor ed = p.edit();
    	ed.putBoolean(name, value);
    	ed.commit();
    }
    
    public static void clear() {
    	SharedPreferences p = PreferenceManager.getDefaultSharedPreferences(Director.getInstance().getContext());
    	Editor ed = p.edit();
    	ed.clear();
    	ed.commit();
    }
    
    public static void remove(String name) {
    	SharedPreferences p = PreferenceManager.getDefaultSharedPreferences(Director.getInstance().getContext());
    	Editor ed = p.edit();
    	ed.remove(name);
    	ed.commit();
    }
}
