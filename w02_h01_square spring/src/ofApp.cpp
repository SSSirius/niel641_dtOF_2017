#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(50); // Limit the speed of our program to 60 frames per second
    Ball tempBall;							// create the ball object

    tempBall.setup(ofGetWindowWidth()/2,ofGetWindowHeight()/2, ofRandom(10,40));	// setup its initial state
    balls.push_back(tempBall);

    ofBackground(0);
    
    }

//--------------------------------------------------------------
void ofApp::update(){
    for (int i = 0; i < balls.size(); i++) {	// one way to loop through a whole vector
        
        balls[i].update();
    }
    
    count+=1;
    if (count % 50 == 0){
        Ball tempBall;
        tempBall.setup(ofRandom(ofGetWindowWidth()),ofRandom(ofGetWindowHeight()), ofRandom(10,40));
        balls.push_back(tempBall);
    
    
    }
}

//--------------------------------------------------------------
void ofApp::draw(){

        for (int i = 0; i < balls.size(); i++) {
            
            balls[i].draw();
        }

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
