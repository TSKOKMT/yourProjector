#pragma once

#include "ofMain.h"

#include "ofxFFSilhouette.h"
#include "ofxTskokmtMath.h"

class vanishingPoint {

public:
    void draw(vector<ofxFFSilhouette> silhouettes, ofPoint point_, int hue_ = 0);
        
private:
    ofxTskokmtMath math;
};
