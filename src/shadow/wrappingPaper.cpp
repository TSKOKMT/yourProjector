#include "wrappingPaper.h"

//--------------------------------------------------------------
void wrappingPaper::draw(vector<ofxFFSilhouette> silhouettes, float lineWidth_) {
    
    //update
    vector<vector<ofPoint>> points;
    for (int i = 0; i < silhouettes.size(); i++) {
        vector<ofPoint> silhouette;
        for (int j = 0; j < silhouettes[i].polyline.getVertices().size(); j += 8) {
            silhouette.push_back(silhouettes[i].polyline.getVertices()[j]);
        }
        points.push_back(vector<ofPoint>());
        points.back() = convexHull.getConvexHull(silhouette);
    }
    /*mathes.resize(points.size());
    for (int i = 0; i < points.size(); i++) {
        points[i] = mathes[i].easeFilter(points[i], .01);
    }*/
    
    //draw
    ofPushStyle();
    for (int i = 0; i < points.size(); i++) {
        for (int k = 0; k < 4; k++) {
            if (points[i].empty()) continue;
            ofColor color;
            color.setHsb(ofWrap(ofMap(k, 0, 4, 0, 256) + 15, 0, 256), 250, 250);
            ofSetColor(color);
            ofBeginShape();
            for (int j = 0; j < points[i].size() + 3; j++) {
                ofCurveVertex(points[i][j % points[i].size()] + ofPoint(ofRandom(-16, 16), ofRandom(-16, 16)));
            }
            ofEndShape(true);
        }
    }
    ofPopStyle();
}
