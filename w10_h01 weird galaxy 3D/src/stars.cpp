//
//  stars.cpp
//  W7H1
//
//  Created by earl on 2017/10/11.
//

#include "stars.hpp"


Star::Star(ofVec3f _pos){
    pos = _pos;
    mass=10;
//    lifespan = 10.;
    for(int i=0;i<200;i++){
//        ofVec3f p_pos=ofVec3f(ofRandom(ofGetWidth()),ofRandom(ofGetHeight()));
        Planet planet(pos);
//        cout<< "i" << endl;
        float hue = ofMap(i, 0, 100, 127, 255);        // blue to red
        planet.color = ofColor::fromHsb(hue, 255, 220);
        planets.push_back(planet);
    }
    
}

void Star::update(){ // time elapsed since last frame
     ofVec3f starPos = ofVec3f(sin(ofGetElapsedTimef()/2+startPos)*250, cos(ofGetElapsedTimef()/2+startPos)*250,ofGetHeight()*.5);
     pos= starPos ;
//    float attractionStrength = 0.01;
    float dampingStrength = 0.1;
    // create more particles based on lifespan
//    int nNewParticles = lifespan;
//
    float lerp=0.3;
//
//    lifespan -= timeDiff;
//    if (lifespan < 0) lifespan = 0;
  
    for(int i=0;i<planets.size();i++){
        ofVec3f dir = pos -  planets[i].pos;
        // mouse is target
//       dir = dir * (1.-lerp) + planets[i].pos * lerp;
          float attractionStrength = planets[i].mass* 0.01;
        ofVec3f attraction = dir * attractionStrength + pos*0.02;
        
//        planets[i].applyForce(attraction);
//        planets[i].applyDampingForce(dampingStrength);
        planets[i].update(pos);
//        planets[i].draw();
        
        
    }
    
    
    
}
void Star::applyForce(ofVec3f force){}

void Star::applyDampingForce(float force){}

ofVec3f Star::getForce(Planet p)
{
    // calculate a force of attraction on mover
    
    ofVec3f dir        = pos - p.pos;    // the target is the attractor
    float distance    = dir.length();
    
    
    distance            = ofClamp(distance, 5., 25.);
    
    float strength    = (mass * p.mass) / (distance * distance);
    
    ofVec3f force    = dir.getNormalized() * strength;
    
    return force;
}

void Star::draw(){
    ofPushMatrix();
//    cout << pos << endl;
    ofTranslate(pos);
    
    ofPushStyle();
    
    // interpolate between colors!
    
    
//        float pct        = ofMap(vel.length(), 0., 7., 0., 1., true);    // mix based on speed
//        ofColor cMix        = cSlow.lerp(cFast, pct);    // "lerp" == interpolate
//    
    ofSetColor(255,255,200);
    
    ofDrawSphere(0,0,0, mass);
    
    ofPopStyle();
    
    ofPopMatrix();
    for(int i=0;i<planets.size();i++){
        planets[i].draw();
        
        
    }
}
