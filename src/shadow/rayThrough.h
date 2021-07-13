#pragma once

#include "ofMain.h"

#include "ofxFFSilhouette.h"

#include "ofxClipper.h"

class rayThrough {

public:
    void draw(vector<ofxFFSilhouette> silhouettes, float offset_ = 30);
        
private:
    ofx::Clipper clipper;
};
