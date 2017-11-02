#include "ofApp.h"
const int nStars        =8;
//const int nPlanets    = 30;
//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofSetBackgroundAuto(false);
    
//    star1.mass = 10.;
    for(int i=0;i<nStars;i++){
        ofVec3f p_pos=ofVec3f(ofRandom(ofGetWidth()),ofRandom(ofGetHeight()),ofGetHeight());
        Star star(p_pos);
        star.startPos= PI *2 /nStars*i;
        stars.push_back(star);
//        cout<< "i" << endl;
        
    }
      cam.setDistance(1200);
//    light.setup();
    light.setPointLight();
    light.setPosition(0,0,ofGetHeight()*.5);
//    light.setSpotConcentration( 400 );
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
    ofSetColor(0, 0, 0, 80);
    ofDrawRectangle(0,0,ofGetWidth(),ofGetHeight());
      ofTranslate(ofGetWidth()/2,ofGetHeight()/2,ofGetElapsedTimef()*20000);
     cam.begin();
       light.enable();
//    light.draw();
//    for(int i=0;i<50;i++){
//        ofSetColor(255,1);
//        ofDrawSphere(0,0,0,ofGetWidth()/50*i);
//
//
//
//    }
    
    for(int i=0;i<stars.size();i++){
        stars[i].draw();
        
    }
       light.disable();
     cam.end();
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
