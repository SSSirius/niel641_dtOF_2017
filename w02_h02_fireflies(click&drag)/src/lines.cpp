//
//  lines.cpp
//  w02_h02
//
//  Created by earl on 2017/9/14.
//
//
#include "lines.h"

Lines::Lines (){
    
};

void Lines::setup(float px, float py ){
    ofColor aqua(255, 252, 0, 150);
    ofColor purple(255,255, 255,200);
    //    ofNoFill();
    color = aqua.getLerped(purple, ofRandom(1.0));
    radius = ofRandom(25,35);
    pos1 =ofVec2f(px,py);
    
//    pos1 = ofVec2f(ofRandom(radius,ofGetWindowWidth()-radius),ofRandom(radius,ofGetWindowHeight()-radius));
    //    ori = ofVec2f(px,py);
    vel = ofVec2f( ofRandom(-2,2), ofRandom(-2,2));
    
    


}

void Lines::update(){
    pos1+=vel;
    if(pos1.x<0+radius||pos1.x> ofGetWindowWidth()-radius){
        
        vel.x *= -1;
    }
    if(pos1.y<0+radius||pos1.y> ofGetWindowHeight()-radius){
        
        vel.y *= -1;
    }
    
}

void Lines::draw() {


        int numLines = 160;

        for (int i=0; i<numLines; i++) {
            
          
                   float angle = ofRandom(ofDegToRad(360.0));

            pos2= ofVec2f(cos(angle) * radius,sin(angle) * radius)+pos1;
            float alpha = ofMap(radius, 25, 35, 5, 0); // Make shorter lines more opaque
            ofSetColor(color, alpha);
            
            ofSetLineWidth(ofRandom(1.0, 5.0)); // Remember, this doesn't work on all graphics cards
            ofDrawLine(pos1,pos2);
//        }
    }
    
    // If the right mouse button is pressed...


}
