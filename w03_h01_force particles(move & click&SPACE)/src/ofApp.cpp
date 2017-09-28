#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    ofBackground(255);
    
    for (int i = 0; i < 3000; i++){
        particle myParticle;
        float vx = ofRandom(-4,4);
        float vy = ofRandom(-4,4);
        myParticle.setInitialCondition(ofGetWidth()/2,ofGetHeight()/2,vx, vy);
        particles.push_back(myParticle);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
   
    for (int i = 0; i < particles.size(); i++){
        particles[i].resetForce();
        particles[i].addDampingForce();
        particles[i].update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(0);
    
    for (int i = 0; i < particles.size(); i++){
        particles[i].draw();
    }

    ofSetColor(255,255,102);
    for (int i = 0; i <  attractPoints.size(); i++){
        ofDrawCircle(attractPoints[i], 10);
    }
}
void ofApp::resetAttract(){
    attractPoints.clear();
    for( int i = 0; i < particles.size(); i++){
        particles[i].setAttractPoints(NULL);;
        particles[i].update();
    }
}
//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    if( key == ' ' ){
        resetAttract();
    }
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
    attractPoints.push_back( ofPoint( mouseX , mouseY) );
    for( int i = 0; i < particles.size(); i++){
        particles[i].setAttractPoints(&attractPoints);;

    }
    
   
    
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
