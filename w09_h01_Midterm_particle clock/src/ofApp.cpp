#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
   // an array of chars
    space=true;
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    ofBackground(0,0,51);
    bg.load("bg.png");
//    myfont.loadFont("arial.ttf", 32);
    
    if(ofGetMinutes()>9){
        min  =ofToString( ofGetMinutes());
        
    }else{
       min  = "0"+ ofToString(ofGetMinutes());
    };
//    min = ofGetMinutes();
    if(ofGetHours()>9){
        hour =ofToString( ofGetHours());
    }else{
        hour = "0"+ ofToString(ofGetHours());
    };
    Minutes = ofGetMinutes();
    if(ofGetSeconds()>9){
        sec = ofToString(ofGetSeconds());
        
    }else{
        sec = "0"+ ofToString(ofGetSeconds());
    };
    
    
    offset.x=ofGetWidth()/4.8;
    offset.y=ofGetHeight()/1.7;
    myfont.load("vag.ttf", 200, false, false, true);
    for (int i = 0; i < 5000; i++){
        particle myParticle;
        float vx = ofRandom(-2,2);
        float vy = ofRandom(-2,2);//sin(vx);//ofRandom(-1,1);
        myParticle.setInitialCondition(ofGetWidth()/2,ofGetHeight()/2,vx, vy);
        particles.push_back(myParticle);
    }
    
    
   
//  paths = myfont.getStringAsPoints(hour+":"+ min+":"+sec);
  paths = myfont.getStringAsPoints(hour+":"+ min);
        
  
    for (int i = 0; i < paths.size(); i++){

        // for every character break it out to polylines

    polylines = paths[i].getOutline();

        for (int j = 0; j < polylines.size(); j++){
            
            polylines[j].close();
//            float count = polylines[j].size();
            polylines[j] = polylines[j].getResampledBySpacing(5);
            for (int k = 0; k < polylines[j].size(); k++){         // draw every "fifth" point
                attractPoints.push_back(ofPoint(polylines[j][k].x+offset.x,polylines[j][k].y+offset.y));
            }
            
        }}
}

//--------------------------------------------------------------
void ofApp::update(){
//   sprintf(fpsStr, "frame rate: %f", ofGetFrameRate());
    for (int i = 0; i < particles.size(); i++){
        particles[i].resetForce();
        particles[i].addDampingForce();
        particles[i].update();
    }
    
//    char tempString[255];
//    ofRectangle rect = myfont.getStringBoundingBox(fpsStr, 0,0);
    if(space){
    
    if( Minutes==ofGetMinutes())
    
       { }
    else{
        Minutes = ofGetMinutes();
        min=ofGetMinutes();
        resetAttract();
         hour=ofGetHours();
        
       
        
        if(ofGetMinutes()>9){
            min  = ofToString(ofGetMinutes());
            
        }else{
            min  = "0"+ ofToString(ofGetMinutes());
        };
        //    min = ofGetMinutes();
        if(ofGetHours()>9){
            hour = ofToString(ofGetHours());
        }else{
            hour = "0"+ ofToString(ofGetHours());
        };
//        second = ofGetSeconds();
        if(ofGetSeconds()>9){
            sec = ofToString(ofGetSeconds());
            
        }else{
            sec = "0"+ ofToString(ofGetSeconds());
        };
//        paths = myfont.getStringAsPoints(hour+":"+ min+":"+sec);
          paths = myfont.getStringAsPoints(hour+":"+ min);
        
        for (int i = 0; i < paths.size(); i++){
            
            // for every character break it out to polylines
            
          
//            line.draw();
//            ofTranslate(400, 0);
             polylines = paths[i].getOutline();
            for (int j = 0; j < polylines.size(); j++){
                
                polylines[j].close();
              
                polylines[j] = polylines[j].getResampledBySpacing(5);
                for (int k = 0; k < polylines[j].size(); k++){         // draw every "fifth" point
                    attractPoints.push_back(ofPoint(polylines[j][k].x+offset.x,polylines[j][k].y+offset.y));
                }
                
            }}
        
        
    }
    
    
    }
    
    
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){
//    ofSetColor(0);
//
   
//
    bg.draw(0,0, ofGetWidth(), ofGetHeight());
    ofSetColor(255,100);
//    resetAttract();
//        myfont.drawString(fpsStr, 100,100);
    ofDrawRectangle(rect.x, rect.y, rect.width, rect.height);
//    drawStringAsShapes(const string &s, float x, float y);
//    ofSetColor(255,255,102);
//    myfont.drawString("hi!!", 100,100);
//    ofPushMatrix();
//        ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    for (int i = 0; i <  attractPoints.size(); i++){
//        ofDrawCircle(attractPoints[i], 10);
    }
//    ofPopMatrix();
    
   
    
    paths = myfont.getStringAsPoints(hour+":"+ min+":"+sec);
    
//  cout <<min <<endl;

    for (int i = 0; i < paths.size(); i++){
//
//        // for every character break it out to polylines
//
       polylines = paths[i].getOutline();

        ofVec3f ori ;
        // for every polyline, draw every fifth point

        for (int j = 0; j < polylines.size(); j++){
             ori = polylines[j][0];
            polylines[j].close();
            float count = polylines[j].size();
            polylines[j] = polylines[j].getResampledBySpacing(5);
            for (int k = 0; k < polylines[j].size(); k++){         // draw every
//                if(j+1< polylines.size()&& k+1 < polylines[j].size()){
//
                
                
//ofDrawLine(polylines[j][k].x+offset.x,polylines[j][k].y+offset.y,ori.x+offset.x,ori.y+offset.y);
                
                    ori=polylines[j][k];
//
//                ofDrawCircle( polylines[j][k].x+offset.x,polylines[j][k].y+offset.y, 2);
//                attractPoints.push_back( polylines[j][k]);
            }
//
        }


}
//    ofPopMatrix();
    for( int i = 0; i < particles.size(); i++){
        particles[i].setAttractPoints(&attractPoints);;
        
    }
    for (int i = 0; i < particles.size(); i++){
        particles[i].draw();
    }
//
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
        if(space){
        resetAttract();
            space=false;
        }
        else{
            space=true;
            
        
            
            min=ofGetMinutes();
            resetAttract();
            hour=ofGetHours();
            
            
            if(ofGetMinutes()>9){
                min  = ofToString(ofGetMinutes());
                
            }else{
                min  = "0"+ ofToString(ofGetMinutes());
            };
            //    min = ofGetMinutes();
            if(ofGetHours()>9){
                hour = ofToString(ofGetHours());
            }else{
                hour = "0"+ ofToString(ofGetHours());
            };
            Minutes = ofGetMinutes();
            if(ofGetSeconds()>9){
                sec =ofToString( ofGetSeconds());
                
            }else{
                sec = "0"+ ofToString(ofGetSeconds());
            };
//            paths = myfont.getStringAsPoints(hour+":"+ min+":"+sec);
             paths = myfont.getStringAsPoints(hour+":"+ min);
            for (int i = 0; i < paths.size(); i++){
                
                // for every character break it out to polylines
                
               polylines = paths[i].getOutline();
                
                for (int j = 0; j < polylines.size(); j++){
                    polylines[j].close();
//                    float count = polylines[j].size();
                    
                    polylines[j] = polylines[j].getResampledBySpacing(5);
                    for (int k = 0; k < polylines[j].size(); k+=6){         // draw every "fifth" point
//                        ofDrawCircle( polylines[j][k], 2);
                        attractPoints.push_back(ofPoint(polylines[j][k].x+offset.x,polylines[j][k].y+offset.y));
                    }
                    
                }}
            
            
            
            
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
//    for( int i = 0; i < particles.size(); i++){
//        particles[i].distory();
//
//    }
//    for (int i = 0; i < particles.size(); i++){
//        particles[i].draw();
//    }
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
//    attractPoints.push_back( ofPoint( mouseX , mouseY) );
//    for( int i = 0; i < particles.size(); i++){
//        particles[i].setAttractPoints(&attractPoints);;
//
//    }
    
   
    
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
