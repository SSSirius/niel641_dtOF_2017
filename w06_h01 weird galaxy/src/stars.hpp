#pragma once
#include "ofMain.h"
//#include "Particle.hpp"
#include "planet.hpp"
class Star {
public:
    
    Star(){
        pos.set(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
        //
        mass=10;
//        lifespan = 10.;
        for(int i=0;i<10;i++){
            //        ofVec3f p_pos=ofVec3f(ofRandom(ofGetWidth()),ofRandom(ofGetHeight()));
            Planet planet(pos);
            planets.push_back(planet);
//            cout<< "i" << endl;
            
        }
    }
    
    Star(ofVec3f _pos);
    void applyForce(ofVec3f force);
    void applyDampingForce(float force);
    void update();
    void draw();
    ofVec3f getForce(Planet p);
    ofVec3f pos,acc,vel;
    float startPos,mass;
    vector<Planet> planets;
};
