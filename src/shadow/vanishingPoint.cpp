#include "vanishingPoint.h"

//--------------------------------------------------------------
void vanishingPoint::draw(vector<ofxFFSilhouette> silhouettes, ofPoint point_, int hue_) {
    
    //draw
    /*ofPushStyle();
    ofNoFill();
    ofSetLineWidth(lineWidth_);*/
    for (int i = 0; i < silhouettes.size(); i++) {
        glBegin(GL_TRIANGLES);
        for (int j = 0; j < silhouettes[i].polyline.getVertices().size(); j++) {
            if (j % 2 == 0) {
                glVertex2f(point_.x, point_.y);
                ofColor color;
                color.setHsb(math.loop(hue_ + ofRandom(-16, 16), 0, 256), ofRandom(256), 255);
                glColor3ub(color.r, color.g, color.b);
            }
            glVertex2f(silhouettes[i].polyline.getVertices()[j].x, silhouettes[i].polyline.getVertices()[j].y);
            glColor3ub(0, 0, 0);
        }
        glEnd();
    }
    //ofPopStyle();
}
