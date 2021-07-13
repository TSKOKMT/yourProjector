#include "mexicoStripe.h"

//--------------------------------------------------------------
void mexicoStripe::draw(vector<ofxFFSilhouette> silhouettes, float offset_, int num_, int delay_, ofColor color_) {
    
    //prepare polylines
    vector<ofPolyline> polylines;
    for (int i = 0; i < silhouettes.size(); i++) {
        polylines.push_back(silhouettes[i].polyline);
    }
    clipper.Clear();
    polylines = clipper.simplifyPolylines(polylines);
    
    //update polylinesLog
    polylinesLog.push_back(polylines);
    while (polylinesLog.size() > num_ * delay_) {
        polylinesLog.erase(polylinesLog.begin());
    }
    
    int count = 0;
    for (int i = delay_ - 1; i < polylinesLog.size(); i += delay_) {
        //offset
        clipper.Clear();
        vector<ofPolyline> offsetPolylines = clipper.getOffsets(polylinesLog[i], offset_ * (num_ - count), ClipperLib::JoinType::jtRound, ClipperLib::EndType::etClosedLine);
        
        //draw
        float ratio = ofMap(i, 0, polylinesLog.size() - 1, 1, 0);
        ofSetColor(tool.gradientColor(ofColor::black, color_, ratio, true));
        for (int j = 0; j < offsetPolylines.size(); j++) {
            ofBeginShape();
            for (int k = 0; k < offsetPolylines[j].getVertices().size(); k++) {
                ofCurveVertex(offsetPolylines[j].getVertices()[k % (int)offsetPolylines[j].getVertices().size()]);
            }
            ofEndShape(true);
        }
        
        count++;
    }
}
