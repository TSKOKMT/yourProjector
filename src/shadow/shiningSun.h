#pragma once

#include "ofMain.h"

#include "ofxFFSilhouette.h"

#include "ofxClipper.h"
#include "ofxTskokmtTool.h"
#include "ofxTskokmtMath.h"

class shiningSun {

public:
    void draw(vector<ofxFFSilhouette> silhouettes, float lineWidth_ = 4);
        
private:
    ofx::Clipper clipper;
    
    vector<vector<ofPolyline>> polylinesLog;
    
    ofxTskokmtTool tool;
    ofxTskokmtMath math;
};
