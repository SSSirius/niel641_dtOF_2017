#pragma once
#include "ofMain.h"
//#include "Particle.hpp"

class Planet {
public:
    
    Planet(){}
    
    Planet(ofVec3f _pos);
    void applyForce(ofVec3f force);
    void applyDampingForce(float force);
    void update(ofVec3f star);
    void draw();
    
    
    ofVec3f pos, vel, acc,randir;
    
//    ofVec3f origPos, pos, vel, acc;    // store original pos
    float mass,angle;
    
    float lifespan;
    ofColor color;
};
