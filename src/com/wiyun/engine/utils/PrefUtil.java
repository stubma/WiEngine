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
