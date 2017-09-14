#include "Ball.h"

Ball::Ball(){
};

void Ball::setup(float px, float py, int rad ){
    pos = ofVec2f(px,py);
    ori = ofVec2f(px,py);
    vel = ofVec2f( ofRandom(-2,2), ofRandom(-2,2));
    radius = rad;
   
    ofColor aqua(0, 252, 255, 150);
    ofColor purple(198, 0, 205,200);
    //    ofNoFill();
     color = aqua.getLerped(purple, ofRandom(1.0));

}

void Ball::update(){
     pos+=vel;
    if(pos.x<0+radius||pos.x> ofGetWindowWidth()-radius){

        vel.x *= -1;}
    if(pos.y<0+radius||pos.y> ofGetWindowHeight()-radius){

        vel.y *= -1;
    }

   }

void Ball::draw() {
    ofSetColor(color);
    ofDrawRectangle(pos, radius,radius);

}
