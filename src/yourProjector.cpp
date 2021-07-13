#include "yourProjector.h"

//--------------------------------------------------------------
void yourProjector::setup() {
    
    video.load("/Users/tskokmt/Downloads/SKY/sky.mov");
    video.setLoopState(OF_LOOP_NORMAL);
    video.play();
}

//--------------------------------------------------------------
void yourProjector::draw(ofxFFApp &app) {
    
    if (mode == 0) {
        ofColor color;
        color.setHsb(ofNormalize(sin(app.getTimeAngle() / 60.), -1, 1) * 512, abs(sin(app.getTimeAngle() / 43.)) * 256, ofMap(sin(app.getTimeAngle() / 67.), -1, 1, 170, 256));
        ofSetColor(color);
        ofDrawRectangle(app.frame);
        mexicoStripe.draw(app.silhouettes, ofMap(sin(app.getTimeAngle() / 30.), -1, 1, 2, app.getBaseSize() / 10.), 12, 5, color);
        
        if (ofGetElapsedTimef() - lastPlayedTime > 80) {
            sound01.play();
            lastPlayedTime = ofGetElapsedTimef();
        }
    }
    else if (mode == 1) {
        ofSetColor(255);
        ofDrawRectangle(app.frame);
        ofEnableBlendMode(OF_BLENDMODE_MULTIPLY);
        wrappingPaper.draw(app.silhouettes);
        ofDisableBlendMode();
        
        if (ofGetElapsedTimef() - lastPlayedTime > 22) {
            sound01.play();
            lastPlayedTime = ofGetElapsedTimef();
        }
    }
    else if (mode == 2) {
        ofEnableBlendMode(OF_BLENDMODE_ADD);
        
        ofPoint point = ofPoint(cos(app.getTimeAngle() / 60.), sin(-app.getTimeAngle() / 60.)) * (app.frameC.width / 2. + app.frameR.width / 2.) + app.frameC.getCenter();
        if (app.getTouchingNum() > 0) point = app.getPressingTouches()[0].position;
        point = math.easeFilter(point, .3);
        int hue = app.time * 256. / 30.;
        vanishingPoint.draw(app.silhouettes, point, hue);
        
        point = ofPoint(cos(app.getTimeAngle() / 44.), sin(app.getTimeAngle() / 44.)) * (app.frameC.width / 2. + app.frameR.width / 2.) + app.frameC.getCenter();
        if (app.getTouchingNum() >= 2) point = app.getPressingTouches()[1].position;
        point = math2.easeFilter(point, .3);
        hue = -app.time * 256 / 44. - 100;
        vanishingPoint.draw(app.silhouettes, point, hue);
        
        ofDisableBlendMode();
        
        if (ofGetElapsedTimef() - lastPlayedTime > 14) {
            sound01.play();
            lastPlayedTime = ofGetElapsedTimef();
        }
    }
    else if (mode == 3) {
        vector<ofColor> palette;
        palette.push_back(ofColor(132, 239, 230));
        palette.push_back(ofColor(254, 79, 97));
        palette.push_back(ofColor(251, 216, 0));
        palette.push_back(ofColor(149, 0, 254));
        palette.push_back(ofColor(160, 254, 0));
        ofSetColor(palette[(int)(app.time / 10) % palette.size()]);
        ofDrawRectangle(app.frameC);
        ofSetColor(palette[(int)(app.time / 16) % palette.size()]);
        ofDrawRectangle(app.frameL);
        ofSetColor(palette[(int)(app.time / 23) % palette.size()]);
        ofDrawRectangle(app.frameR);
        ofSetColor(255);
        punkHair.draw(app.silhouettes, app.getBaseSize() / 2., 2);
        ofSetColor(0);
        punkHair.draw(app.silhouettes, app.getBaseSize() / 7., 4);
        punkHair.draw(app.silhouettes, app.getBaseSize() / 10., 8);
        punkHair.draw(app.silhouettes, app.getBaseSize() / 20., 16);
        
        if (ofGetElapsedTimef() - lastPlayedTime > 9) {
            sound01.play();
            lastPlayedTime = ofGetElapsedTimef();
        }
    }
    else if (mode == 4) {
        video.update();
        ofSetColor(255);
        video.draw(app.frame);
        ofSetColor(0);
        shiningSun.draw(app.silhouettes, ofMap(ofNoise(app.time), 0, 1, 2, 10));
        
        if (ofGetElapsedTimef() - lastPlayedTime > 60) {
            sound01.play();
            lastPlayedTime = ofGetElapsedTimef();
        }
    }
    
    ofSetColor(0, 255, 0);
    rayThrough.draw(app.silhouettes, app.getBaseSize() / 60.);
}

//--------------------------------------------------------------
void yourProjector::switchShadow() {
    
    /*int previousMode = mode;
    while (previousMode == mode) mode = ofRandom(5);*/
    
    mode = ++mode % 5;
    
    if (mode == 0) {
        sound01.load("/Users/tskokmt/Downloads/FRAME FREE/SOUND/A8.mp3");
        sound01.setMultiPlay(true);
        sound01.setLoop(false);
        sound01.play();
        lastPlayedTime = ofGetElapsedTimef();
    }
    else if (mode == 1) {
        sound01.load("/Users/tskokmt/Downloads/FRAME FREE/SOUND/02/4.mp3");
        sound01.setMultiPlay(true);
        sound01.setLoop(false);
        sound01.play();
        lastPlayedTime = ofGetElapsedTimef();
    }
    else if (mode == 2) {
        sound01.load("/Users/tskokmt/Downloads/FRAME FREE/SOUND/02/3.mp3");
        sound01.setMultiPlay(true);
        sound01.setLoop(false);
        sound01.play();
        lastPlayedTime = ofGetElapsedTimef();
    }
    else if (mode == 3) {
        sound01.load("/Users/tskokmt/Downloads/FRAME FREE/SOUND/02/0.mp3");
        sound01.setMultiPlay(true);
        sound01.setLoop(false);
        sound01.play();
        lastPlayedTime = ofGetElapsedTimef();
    }
    else if (mode == 4) {
        sound01.load("/Users/tskokmt/Downloads/FRAME FREE/SOUND/02/1.mp3");
        sound01.setMultiPlay(true);
        sound01.setLoop(false);
        sound01.play();
        lastPlayedTime = ofGetElapsedTimef();
    }
}

