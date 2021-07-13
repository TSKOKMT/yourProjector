#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    //setup app
    app.setup("yourProjector", 50011, true, true, true);
    
    yourProjector.setup();
}

//--------------------------------------------------------------
void ofApp::update(){

    //update app
    app.update();
    
    if (!app.bActive) return;
    
    if (app.time - lastShuffleTime > 10 && app.getSocialDistance() > .4) {
        yourProjector.switchShadow();
        lastShuffleTime = app.time;
    }
    
    //draw
    app.begin();
    
    yourProjector.draw(app);
    
    app.end();
}

//--------------------------------------------------------------
void ofApp::draw(){

    //draw app
    app.draw();
}

//--------------------------------------------------------------
void ofApp::exit(){
    
    //exit app
    app.exit();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    if (key == 'm') yourProjector.switchShadow();
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
