#pragma once

#include "ofMain.h"

#include "ofxFFSilhouette.h"

#include "ofxConvexHull.h"
#include "ofxTskokmtMath.h"

class wrappingPaper {

public:
    void draw(vector<ofxFFSilhouette> silhouettes, float lineWidth_ = 2);
        
private:
    ofxConvexHull convexHull;
    vector<ofxTskokmtMath> mathes;
};
