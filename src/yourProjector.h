#pragma once

#include "ofMain.h"

#include "ofxFFApp.h"

#include "mexicoStripe.h"
#include "wrappingPaper.h"
#include "rayThrough.h"
#include "vanishingPoint.h"
#include "punkHair.h"
#include "shiningSun.h"
#include "foolBorder.h"

#include "ofxTskokmtMath.h"

class yourProjector {

public:
    void setup();
    void draw(ofxFFApp &app);
    void switchShadow();
        
    int mode = 0;
    
    //filter
    mexicoStripe mexicoStripe;
    wrappingPaper wrappingPaper;
    rayThrough rayThrough;
    vanishingPoint vanishingPoint;
    punkHair punkHair;
    shiningSun shiningSun;
    
    
    foolBorder foolBorder;
    
    ofSoundPlayer sound01;
    float lastPlayedTime = 0;
    
    ofVideoPlayer video;
    
    ofxTskokmtMath math;
    ofxTskokmtMath math2;
};
