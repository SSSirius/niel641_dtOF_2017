#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofEnableAntiAliasing();
    ofSetCircleResolution(200);
    path.setCircleResolution(200);
    pct=0.9;
    flower.load("img/rose.png");
    chicken.load("img/chicken.png");
    pos.x=100;
    pos.y=100;
    
    ofColor skin(47,38,41);
    color=skin;

    mouth.curveTo(ofGetWidth()/2-10, ofGetHeight()/2+10);
    mouth.curveTo(ofGetWidth()/2-10, ofGetHeight()/2+10);
    mouth.curveTo(ofGetWidth()/2+15, ofGetHeight()/2+15);
    mouth.curveTo(ofGetWidth()/2+40, ofGetHeight()/2+8);
    mouth.curveTo(ofGetWidth()/2+40, ofGetHeight()/2+8); // etc...

    nose.curveTo(ofGetWidth()/2-10, ofGetHeight()/2-120);
    nose.curveTo(ofGetWidth()/2-10, ofGetHeight()/2-120);
    nose.curveTo(ofGetWidth()/2-10, ofGetHeight()/2-40);
    nose.curveTo(ofGetWidth()/2, ofGetHeight()/2-30);
    nose.curveTo(ofGetWidth()/2, ofGetHeight()/2-30);

    path.moveTo(ofGetWidth()/2-80, ofGetHeight()/2-280);

    path.arc( ofGetWidth()/2-110, ofGetHeight()/2-250, 120, 120, -20, 115);
    path.close();
    path.moveTo(ofGetWidth()/2+80, ofGetHeight()/2-280);
    path.arc( ofGetWidth()/2+110, ofGetHeight()/2-250, 120, 120, 60, 200);
    path.close();
//    path.moveTo(ofGetWidth()/2+80, ofGetHeight()/2-280);
    
    
   
}

//--------------------------------------------------------------
void ofApp::update(){
        pos.x = (1-pct) * mouseX + (pct) * pos.x;
        pos.y = (1-pct) * mouseY + (pct) * pos.y;
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackground(208,218,219);
    ofSetColor(47,38,41);
    ofDrawEllipse(ofGetWidth()/2, ofGetHeight()/2-100, 400, 400);
    ofSetLineWidth(2.0);  // Line widths apply to polylines
    ofSetColor(251,229,203);
    ofDrawEllipse(ofGetWidth()/2, ofGetHeight()/2-100, 280, 350);
    ofDrawRectangle(ofGetWidth()/2-20, ofGetHeight()/2+50,60, 60);
    ofDrawEllipse(ofGetWidth()/2, ofGetHeight()/2+210, 330, 230);
    ofSetColor(208,218,219);
    ofDrawRectangle(ofGetWidth()/2-170, ofGetHeight()/2+160,340, 180);

    path.setFillColor(color);
    path.draw();
    ofSetColor(47,38,41);
    nose.draw();
    mouth.draw();
    ofDrawEllipse(ofGetWidth()/2, ofGetHeight()/2-240, 40, 80);
   
    ofSetColor(251,229,203);
    ofDrawEllipse(ofGetWidth()/2-150, ofGetHeight()/2-70, 60, 60);
    ofDrawEllipse(ofGetWidth()/2+150, ofGetHeight()/2-70, 60, 60);
    ofSetColor(255);
    
    ofDrawEllipse(ofGetWidth()/2-60, ofGetHeight()/2-90, 50, 40);
    ofDrawEllipse(ofGetWidth()/2+60, ofGetHeight()/2-90, 50, 40);
    ofSetColor(0);


    ofDrawEllipse(ofGetWidth()/2-ofMap(pos.x,0,ofGetWidth(),65,55), ofGetHeight()/2-ofMap(pos.y,0,ofGetHeight(),95,85), 20, 30);
    ofDrawEllipse(ofGetWidth()/2+ ofMap(pos.x,0,ofGetWidth(),55,65), ofGetHeight()/2-ofMap(pos.y,0,ofGetHeight(),95,85), 20, 30);
    
    ofSetLineWidth(6);

    ofDrawLine(ofGetWidth()/2-ofMap(mouseX,0,ofGetWidth(),95,85), ofGetHeight()/2-ofMap(mouseY,0,ofGetHeight(),130,140), ofGetWidth()/2-ofMap(mouseX,0,ofGetWidth(),35,25), ofGetHeight()/2-ofMap(mouseY,0,ofGetHeight(),125,120));
    ofDrawLine(ofGetWidth()/2+ofMap(mouseX,0,ofGetWidth(),85,95), ofGetHeight()/2-ofMap(mouseY,0,ofGetHeight(),130,140), ofGetWidth()/2+ofMap(mouseX,0,ofGetWidth(),25,35), ofGetHeight()/2-ofMap(mouseY,0,ofGetHeight(),125,120));

   ofSetLineWidth(2);
   
    if(mouseY>300){
        ofSetColor(180,255,255);
        ofDrawRectangle(ofGetWidth()/2+15, ofGetHeight()/2+10,10,ofMap(mouseY,300,ofGetHeight(),0,50));
        ofSetColor(0);
        ofDrawEllipse(ofGetWidth()/2+15, ofGetHeight()/2+10, 50, ofMap(mouseY,300,ofGetHeight(),10,40));
        
        
       ofSetColor(255);
        chicken.draw(pos, 220, 160);
    } else{
        //        ofSetLineWidth(6);
        ofSetColor(252,181,200,ofMap(mouseY,300,0,150,255));
        ofDrawEllipse(ofGetWidth()/2+80, ofGetHeight()/2-30, 50, 25);
        ofDrawEllipse(ofGetWidth()/2-80, ofGetHeight()/2-30, 50, 25);
        ofSetColor(255);
        flower.draw(pos, 80, 150);
        //        ofSetLineWidth(2);
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
