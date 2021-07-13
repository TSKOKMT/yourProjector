#include "rayThrough.h"

//--------------------------------------------------------------
void rayThrough::draw(vector<ofxFFSilhouette> silhouettes, float offset_) {
    
    //draw
    for (int i = 0; i < silhouettes.size(); i++) {
        if (silhouettes[i].bHole) {
            vector<ofPolyline> polylines;
            polylines.push_back(silhouettes[i].polyline);
            clipper.Clear();
            polylines = clipper.getOffsets(polylines, offset_, ClipperLib::JoinType::jtRound, ClipperLib::EndType::etClosedLine);
            glBegin(GL_POLYGON);
            for (int j = 0; j < polylines[0].getVertices().size(); j++) {
                glVertex2f(polylines[0].getVertices()[j].x, polylines[0].getVertices()[j].y);
            }
            glEnd();
        }
    }
}
