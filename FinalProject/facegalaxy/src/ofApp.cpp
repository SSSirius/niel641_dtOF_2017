#include "ofApp.h"
#include<vector>
//#include "iostream.h"
//#include "Params.hpp"
//--------------------------------------------------------------
//Params param;
//Params param;
void ofApp::setup(){
    grabber.setup(1280,720);
     param.setup(); 
    // Setup tracker
    tracker.setup();
    ofSetFrameRate(15);
    ofBackground(0);
      ofSetCircleResolution(200);
    for( int i=0; i<200; i++){
        dis.push_back(ofRandom(200-i));
//        cout <<ofRandom(1) <<endl;
    }
    gui.setup();
    gui.add(showface.setup("Face", false));
     gui.add(showdata.setup("Data", false));
//        gui.add(ini_z.setup("ini_Z",20,0,50));
//        gui.add(colr.setup("color_r",255,0,255));
//        gui.add(colb.setup("color_b",150,0,255));
//      gui.add(colg.setup("color_g",150,0,255));
    //    gui.add(lifes.setup("lifespan",370,200,400));
    //      setInitialCondition(0,0,0);
}


//--------------------------------------------------------------
void ofApp::update(){
    grabber.update();
    mouth=0;
    mouthup=0;
    nose=0;
    eyesize=0;
    eyedist=0;
    face=0;
  
    if(grabber.isFrameNew()){
        tracker.update(grabber);
    }
       mouths = tracker.mouthdist();
     mouthups = tracker.mouthvertidist();
     noses = tracker.nosedist();
    eyesizes = tracker.eyesize();
     eyedists = tracker.eyedist();
     faces= tracker.facedist();

    int i = 0;
    for(int i = 0; i < mouths.size(); i++){
       mouth+=mouths[i]/mouths.size();;
        mouthup+=mouthups[i]/mouths.size();;
        nose+= noses[i]/mouths.size();;
        eyesize+= eyesizes[i]/mouths.size();;
        eyedist+= eyedists[i]/mouths.size();;
        face+= faces[i]/mouths.size();;
    }
    calculat.update(mouth, mouthup, nose, eyedist, eyesize, face);
    

    float pct=0.1;
    
    if(ofToString(param.colr)=="nan"){
//
  
    param.colr= 0;
    param.colg =0;
    param.colb = 0;
    param.degree= 0;
    param.size=0;
    param.dens=0;
    }else{colr =param.colr;
        param.colr = param.colr * (1.-pct) + ofMap(calculat.eyedistr,25,33,150,255)*pct;//

            param.colg = param.colg * (1.-pct) + ofMap(calculat.noser,34,43,80,255) * pct;
            param.colb =param.colb * (1.-pct) + ofMap(calculat.mouthr,35,43,100,255) * pct;
            param.degree= param.degree * (1.-pct)+ ofMap(calculat.mouthupr,30,150,5,15)* pct;
            param.size=param.size* (1.-pct) +ofMap(calculat.facer,50,100,40,80)* pct;
            param.dens=param.dens* (1.-pct)+ofMap(calculat.eyesizer,10,25,50,200)* pct;
//
    }
//
}

//--------------------------------------------------------------
void ofApp::draw(){
     gui.draw();
    
    if(showdata){
        ofDrawBitmapString("nose:"+ofToString(calculat.noser),10,90);
    ofDrawBitmapString("eyedist:"+ofToString(calculat.eyedistr),10,120);
    ofDrawBitmapString("mouthwidth:"+ofToString( calculat.mouthr),10,150);
    ofDrawBitmapString("mouthup:"+ofToString(calculat.mouthupr),10,180);
      ofDrawBitmapString("face:"+ofToString(calculat.facer),10,210);
      ofDrawBitmapString("eyelengh:"+ofToString(calculat.eyesizer),10,240);
    ofDrawBitmapString("color_H:"+ofToString(param.colg),10,270);
    ofDrawBitmapString("Color_S:"+ofToString(param.colb),10,300);
     ofDrawBitmapString("color_B:"+ofToString( param.colr),10,330);
    ofDrawBitmapString("convergence:"+ofToString(param.degree),10,360);
    ofDrawBitmapString("scale:"+ofToString( param.size),10,390);
        ofDrawBitmapString("density:"+ofToString( param.dens),10,410);
        
    }

    
    
    
    count++;
    ofPushMatrix;

    ofTranslate(ofGetWidth(),0);
    ofScale(-1,1,1);
    if(showface) tracker.drawMesh();
    ofPopMatrix;
 
    
    ofPushMatrix;
      cam.begin();

    for(int i = 0; i < param.size; i++){
        star newstar;
        newstar.setInitialCondition(i*param.ew,i*param.eh,i,param.size,param.degree,dis);
        stars.push_back(newstar);
        
    }

    for(int i = 0; i < stars.size(); i++){
        stars[i].draw();
        
    }
        cam.end();
    ofPopMatrix;
    stars.clear();
//    cam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

    param.colr =0;
    param.colb = 0;
    param.degree= 0;
    param.size= 0;
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
