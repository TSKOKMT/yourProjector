#pragma once

#include "ofMain.h"

#include "ofxFFSilhouette.h"

#include "ofxClipper.h"
#include "ofxTskokmtTool.h"

class mexicoStripe {

public:
    void draw(vector<ofxFFSilhouette> silhouettes, float offset_, int num_, int delay_ = 5, ofColor color_ = ofColor(255));
        
private:
    ofx::Clipper clipper;
    
    vector<vector<ofPolyline>> polylinesLog;
    
    ofxTskokmtTool tool;
};
