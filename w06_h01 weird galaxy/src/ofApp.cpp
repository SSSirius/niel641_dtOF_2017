#include "ofApp.h"
const int nStars        =8;
//const int nPlanets    = 30;
//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    
//    star1.mass = 10.;
    for(int i=0;i<nStars;i++){
        ofVec3f p_pos=ofVec3f(ofRandom(ofGetWidth()),ofRandom(ofGetHeight()));
        Star star(p_pos);
        star.startPos= PI *2 /nStars*i;
        stars.push_back(star);
//        cout<< "i" << endl;
        
    }
}

//--------------------------------------------------------------
void ofApp::update(){
//    ofVec3f starPos = ofVec3f(sin(ofGetElapsedTimef())*100, cos(ofGetElapsedTimef())*100);
//    star1.pos= starPos ;
   
    for(int i=0;i<stars.size();i++){
         stars[i].update();
        
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
      ofTranslate(ofGetWidth()/2,ofGetHeight()/2);
    for(int i=0;i<50;i++){
        ofSetColor(255,1);
        ofDrawCircle(0,0,ofGetWidth()/50*i);
        
        
        
    }
    
    for(int i=0;i<stars.size();i++){
        stars[i].draw();
        
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
