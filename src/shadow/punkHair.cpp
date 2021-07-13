#include "punkHair.h"

//--------------------------------------------------------------
void punkHair::draw(vector<ofxFFSilhouette> silhouettes, float amount_, float lineWidth_) {
    
    //draw
    ofPushStyle();
    ofNoFill();
    ofSetLineWidth(lineWidth_);
    for (int i = 0; i < silhouettes.size(); i++) {
        ofBeginShape();
        for (int j = 0; j < silhouettes[i].polyline.getVertices().size(); j++) {
            ofCurveVertex(silhouettes[i].polyline.getVertices()[j] + ofPoint(ofRandom(-amount_, amount_), ofRandom(-amount_, amount_)));
        }
        ofEndShape(true);
    }
    ofPopStyle();
}
