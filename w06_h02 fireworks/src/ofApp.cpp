#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetBackgroundAuto(false);
    gravity = ofVec2f(0,.05);
    bg.load("bg.JPG");
    
    lastUpdateTime = ofGetElapsedTimef();
    firework.lifespan=0;
    firework.pos=ofVec3f(0,0);
    hiCount=0;
}

//--------------------------------------------------------------
void ofApp::update(){
    
    
    float timeDiff = ofGetElapsedTimef() - lastUpdateTime;

    
    for (int i=0; i<fireworks.size(); i++)
    {
        fireworks[i].update(gravity, timeDiff);    // update
    }
    
    lastUpdateTime = ofGetElapsedTimef();
    
    if(ofGetMousePressed){
        firework.lifespan+=2;
        
        hiCount-=5;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    bg.draw(0,0, ofGetWidth(),ofGetHeight());

    for (int i=0; i<fireworks.size(); i++)
    { ofSetColor(255); //
        fireworks[i].draw();
    }
    ofColor black = ofColor(0);
    ofDrawBitmapStringHighlight("drag to make an angle", ofVec2f(20,ofGetHeight()-60), black);
        ofDrawBitmapStringHighlight("mouse press to make distance", ofVec2f(20,ofGetHeight()-40), black);
}


//--------------------------------------------------------------

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
   
//    firework.rePos=ofVec3f(x,y);
 
    startPos=ofVec3f(x,y);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    firework.pos=ofVec3f(x,y);
    
    
    ofVec3f vel;
    if(startPos==firework.pos){
        vel=ofVec3f(0,-1);
    }else{
        vel=startPos-firework.pos;
    }
    
    firework.rePos=firework.pos+vel*4;
    cout<<  firework.rePos<<endl;
    fireworks.push_back(Firework(firework.pos,firework.rePos,vel,firework.lifespan));
    firework.lifespan=0;
    hiCount=0;

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
