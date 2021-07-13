#include "shiningSun.h"

//--------------------------------------------------------------
void shiningSun::draw(vector<ofxFFSilhouette> silhouettes, float lineWidth_) {
    
    //update
    vector<vector<float>> angles;
    for (int i = 0; i < silhouettes.size(); i++) {
        angles.push_back(vector<float>());
        for (int j = 0; j < silhouettes[i].polyline.getVertices().size(); j++) {
            int index = ofWrap(j - 1, 0, silhouettes[i].polyline.getVertices().size());
            ofPoint difference = silhouettes[i].polyline.getVertices()[j] - silhouettes[i].polyline.getVertices()[index];
            float angle01 = atan2(difference.y, difference.x) + PI / 2.;
            index = ofWrap(j + 1, 0, silhouettes[i].polyline.getVertices().size());
            difference = silhouettes[i].polyline.getVertices()[index] - silhouettes[i].polyline.getVertices()[j];
            float angle02 = atan2(difference.y, difference.x) + PI / 2.;
            angles.back().push_back((angle01 + angle02) / 2.);
            /*ofPoint difference = silhouettes[i].polyline.getVertices()[j] - silhouettes[i].polyline.getCentroid2D();
            float angle = atan2(difference.y, difference.x);
            angles.back().push_back(angle);*/
        }
    }
    
    //draw
    glLineWidth(lineWidth_);
    glBegin(GL_LINES);
    for (int i = 0; i < silhouettes.size(); i++) {
        for (int j = 0; j < silhouettes[i].polyline.getVertices().size(); j++) {
            ofPoint position = silhouettes[i].polyline.getVertices()[j];
            vector<ofPoint> tangents;
            for (int k = -4; k <= 4; k++) {
                tangents.push_back(silhouettes[i].polyline.getTangentAtIndex((j + k) % (int)silhouettes[i].polyline.getVertices().size()));
            }
            ofPoint tangent = math.mean(tangents);
            float angle = atan2(tangent.y, tangent.x) + PI / 2.;
            for (float x = 32; x < 10000; x += 32) {
                glVertex2f(position.x + cos(angle) * x, position.y + sin(angle) * x);
            }
        }
    }
    glEnd();
}
