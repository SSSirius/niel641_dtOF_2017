
#include "ofApp.h"

void Ripple::update(int arr){
    
//    ofVec3f offsetTarget = target + offset;
//
    acc=acc*0.98;
    prevPos.x = (arr-1)*2;
    prevPos.y=sin(ofGetElapsedTimef()*10+ofMap(1-arr,0,700,0,80))*ofMap(1-arr,0,-350,hig*0.3,0.001)*acc+ofGetHeight()/2+100;
    pos.x = arr*2;
    //   pos.y = sin(ofGetElapsedTimef()/2 + ofMap(arr,0,200,0,15))* ofMap(arr,0,200,40,10);
    pos.y = sin(ofGetElapsedTimef()*10+ ofMap(-arr,0,700,0,80))*ofMap(-arr,0,-350,hig*0.3,0.001)*acc+ofGetHeight()/2+100;
    
    if (acc<=0.000001){
        acc=0;
    }
    

}

//--------------------------------------------------------------
void Ripple::draw(){
//    ofSetLineWidth(6);
    ofSetColor(102,204,255);
    ofFill();

    ofSetLineWidth(1);
    ofDrawLine(prevPos.x+offset,prevPos.y, pos.x+offset,pos.y);
    ofDrawLine(offset-prevPos.x,prevPos.y,offset-pos.x,pos.y);
    
    
}

void Ripple::restart(int count,int hi,int x){
    if (count==0){
        acc=1;
        oldAcc=1;
    }
   
    acc=oldAcc*0.8;
    oldAcc=acc;
    if (acc<0){
        acc=0;
    };
    hig = hi;
    offset=x;
}

//--------------------------------------------------------------
// ofApp definitions:
//--------------------------------------------------------------


//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    int nRipples = 700;
    for (int i=0; i<nRipples; i++){
        Ripple ripple;
    
    
        ripple.pos = ofVec2f( 0 );
       ripples.push_back(ripple);
    }
    
    friction = 0.99;
    size = 20.0;
    rpos = ofVec2f( 0,-300);
    hi=0;
}

//--------------------------------------------------------------
void ofApp::update(){
    
    
    for(int i=0; i<ripples.size();i++){
        ripples[i].update(i);
    }
    rpos += rvel;
    rvel += racc;
    if (size <0.0001){
        size=0;
        
    }

    

}

//--------------------------------------------------------------
void ofApp::draw(){
//  ofTranslate(ofGetMouseX(), ofGetHeight()/2+100);
    for(int i=0; i< ripples.size();i++){
        ripples[i].draw();
    }
//    if (mouseReleased()){
    if (rpos.y <ofGetHeight()/2+100){
         ofDrawCircle (rpos,size);
       
    } else{
        rvel.y *= -1*0.9;
        size*=0.8;
   
        for(int i=0; i<ripples.size();i++){
            ripples[i].restart(count,hi,rpos.x);
            
        }
         count+=1;
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
//    rpos = ofVec2f(0,y-ofGetHeight()/2-100);
    rpos=ofVec2f(x,y);
    rvel = ofVec2f(0,ofRandom(-3,0));
    hi = 100-y+ofGetHeight()/2;
//    rvel.y=-3;
//    racc.y=0.2;
    racc = ofVec2f(0,0.2);
    count=0;
    size=20;
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
