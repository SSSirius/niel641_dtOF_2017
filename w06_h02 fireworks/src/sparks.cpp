
#include "sparks.hpp"


Spark::Spark()
{
    lifespan = 3.;
}

Spark::Spark(ofVec3f _pos)
{
    pos = _pos;
    
    vel.x = ofRandom(-6, 6);
    vel.y = ofRandom(-6, 7);
    lifespan = 3.;
}

void Spark::applyForce(ofVec3f force){
    acc += force;
}

void Spark::update(float timeDiff){
    vel += acc;
    pos += vel;
    acc *= 0;
    
    lifespan -= timeDiff/3;
    if (lifespan < 0.) lifespan = 0.;
}

void Spark::draw(){
    
    
    
    ofPushStyle();
    float hue = ofMap(lifespan, 0., 3.,200, 255);
    ofSetColor(255,255,200,hue);
    ofDrawCircle(pos, 2);
    ofPopStyle();
}


