
#pragma once
#include "ofMain.h"
#include "sparks.hpp"

class Firework {
public:
    
    Firework(){}
    
    Firework(ofVec3f _pos,ofVec3f _rePos,ofVec3f _vel,float _lifespan);
    void update(ofVec3f force, float timeDiff);
    void draw();
    
    vector<Spark> sparks;
    ofVec3f pos,rePos,vel;
    
    float lifespan;
    
};
