package com.example.earthquakeupdater;

// An EarthQuake object contains information about a single  earthquake.

public class EarthQuake {

    private double mMagnitude;

    private String mLocation;

    private long mTimeInMilliseconds;

    private String mUrl;

    //constructor to create a earthquake object
    public EarthQuake(double magnitude, String location, long timeInMilliseconds, String url) {
        mMagnitude = magnitude;
        mLocation = location;
        mTimeInMilliseconds = timeInMilliseconds;
        mUrl = url;
    }

    public double getMagnitude() {
        return mMagnitude;
    }

    public String getLocation() {
        return mLocation;
    }

    public long getTimeInMilliseconds() {
        return mTimeInMilliseconds;
    }

    public String getUrl() {
        return mUrl;
    }
}