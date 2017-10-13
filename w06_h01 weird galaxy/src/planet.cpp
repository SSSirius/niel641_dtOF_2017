//
//  Mover.cpp
//  Attraction
//
//  Created by Tyler on 10/5/17.
//
//

#include "planet.hpp"

//Planet::Planet()
//{
//    pos.set(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
//    
//    mass = ofRandom(1,5);
//    
//}

Planet::Planet(ofVec3f _pos){
//    pos = _pos;
    pos.x = ofRandom(ofGetWidth());
    pos.y = ofRandom(ofGetHeight());
    mass= ofRandom(1.,5.);
    randir= ofVec3f (ofRandom(ofGetWidth()),ofRandom(ofGetHeight()));
  
}

void Planet::applyForce(ofVec3f force)
{
    // force = mass * acceleration
    // acc = force / mass
    acc += force/mass;
    //     cout << acc << endl;
}


void Planet::applyDampingForce(float force)
{
    acc -= vel.getNormalized() *2* force;
    
}

//void Mover::checkEdges() {
//    // keep mover on screen
//
//    if (pos.x < 0) {
//        pos.x = 0;
//        vel.x *= -1;
//    }
//
//    if (pos.x > ofGetWidth()) {
//        pos.x = ofGetWidth();
//        vel.x *= -1;
//    }
//
//    if (pos.y < 0) {
//        pos.y = 0;
//        vel.y *= -1;
//    }
//
//    if (pos.y > ofGetHeight()) {
//        pos.y = ofGetHeight();
//        vel.y *= -1;
//    }
//}

void Planet::update(ofVec3f star)
{
    float lerp = 0.2;
//    vel += acc;
//    pos += vel;

//    ofVec3f
//    acc *= 0;
    ofVec3f direction = randir.getNormalized() + star;
//  ofVec3f direction = randir.getNormalized() * (ofMap(mass,1,5,20,50))+ star;
//  direction=direction.getNormalized() *180;
    
    
    randir.x=star.x+sin(ofGetElapsedTimef()*ofMap(mass,1,5,0.5,5))*(ofMap(mass,1.,5.,20.,300.));
    randir.y=star.y+cos(ofGetElapsedTimef()* ofMap(mass,1,5,0.5,5))*(ofMap(mass,1.,5.,20.,300.));
    pos = pos * (1.-lerp) + randir * lerp;// move "lerp" % to target
//    ofVec3f dir = star - pos;
//    pos=star;
//    float radians = atan2(randir.y, randir.x);    // atan2 returns angle in radians
//
//    angle = ofRadToDeg(radians);
}

void Planet::draw()
{
    ofPushMatrix();
    ofTranslate(pos);
//    ofRotate(angle);
    ofPushStyle();
    
    // interpolate between colors!
//    ofColor cSlow    = ofColor::fromHex(0xC1D5FF);    // hex format: 0xRRGGBB
//    ofColor cFast    = ofColor::fromHex(0xFF4831);
    
//    float pct        = ofMap(vel.length(), 0., 7., 0., 1., true);    // mix based on speed
//    ofColor cMix        = cSlow.lerp(cFast, pct);    // "lerp" == interpolate
//
    float hue = ofMap(mass, 1, 5, 100, 150);
     float bright = ofMap(mass, 1, 5, 150, 250);
    ofSetColor( ofColor::fromHsb(hue, 255, 250,bright) );
    
    ofDrawCircle(0,0, mass);
    
    ofPopStyle();
    
    ofPopMatrix();
}






