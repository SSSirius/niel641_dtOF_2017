#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
//    ofSetFrameRate(60); // Limit the speed of our program to 60 frames per second
    
    ofSetFrameRate(50); // Limit the speed of our program to 60 frames per second
    ofSetBackgroundAuto(false);
     Lines templines;							// create the ball object
    
    templines.setup(ofGetWindowWidth()/2,ofGetWindowHeight()/2);	// setup its initial state
    lines.push_back(templines);
//    for (int i=0;i<150;i++){
//    Lines templines;							// create the ball object
////    templines.setup();	// setup its initial state
//        lines.push_back(templines);}
//    
////    ofBackground(0,100);
    

}

//--------------------------------------------------------------
void ofApp::update(){
    for ( int i=0; i<lines.size();i++){
        
        lines[i].update();
    }
//}

}

//--------------------------------------------------------------
void ofApp::draw(){
//    keytime =  ofGetFrameRate();
//    // If the left mouse button is pressed...
//    if (keytime % 100 == 0)
//    {
    
    ofSetColor(0,100);
    ofDrawRectangle(0, 0, ofGetWindowWidth(), ofGetWindowHeight());
    
    
    for ( int i=0; i<lines.size();i++){
        
        lines[i].draw();
    }
    }

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    // From section 1.ii.f, allowing you to save a screenshot by pressing the 's' key:
    }

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    Lines templines;							// create the ball object
    
    templines.setup(x,y);	// setup its initial state
    lines.push_back(templines);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    Lines templines;							// create the ball object
    
    templines.setup(x,y);	// setup its initial state
    lines.push_back(templines);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
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
