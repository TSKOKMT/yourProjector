#pragma once

#include "ofMain.h"

#include "ofxFFSilhouette.h"

#include "ofxFboBlur.h"

class foolBorder {

public:
    void draw(ofFbo silhouetteFbo_, float offset_ = 30);
        
private:
    ofxFboBlur blur;
};
