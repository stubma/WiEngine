package com.wiyun.engine.types;

import java.util.ArrayList;
import java.util.List;

public class WYPointList {
	private List<WYPoint> mPoints;
	
	public WYPointList() {
		mPoints = new ArrayList<WYPoint>();
	}
	
	public void addPoint(float x, float y) {
		mPoints.add(WYPoint.make(x, y));
	}
	
	public void addPoint(WYPoint p) {
		mPoints.add(p);
	}
	
	public void addPoints(WYPointList plist) {
		mPoints.addAll(plist.getPoints());
	}
	
	public void clear() {
		mPoints.clear();
	}
	
	public int getCount() {
		return mPoints.size();
	}
	
	public void deletePointAt(int index) {
		if(index < 0 || index >= mPoints.size())
			return;
		
		mPoints.remove(index);
	}
	
	public List<WYPoint> getPoints() {
		return mPoints;
	}
	
	public WYPoint getPointAt(int index) {
		if(index < 0 || index >= mPoints.size())
			return WYPoint.makeZero();
		else
			return mPoints.get(index);
	}
}
