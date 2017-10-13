//
//  firework.cpp
//  W7H2
//
//  Created by earl on 2017/10/12.
//

#include "firework.hpp"


Firework::Firework(ofVec3f _pos,ofVec3f _rePos,ofVec3f _vel,float _lifespan){
    pos = _pos;
    lifespan = _lifespan;

    rePos=_rePos;
    
    if(rePos.y< 50){
        rePos.y=50;
        }
    vel=(rePos-pos).getNormalized();
    vel*=3;
      
    for (int i=0; i<lifespan; i++){
        Spark spark(rePos);
        sparks.push_back(spark);
    }
}

void Firework::update(ofVec3f force, float timeDiff){ // time elapsed since last frame
    
    // create more sparks based on lifespan
    int nNewSparks = lifespan;
    
 
    if(pos.y < rePos.y){
        if(pos.y<50){
            pos.y=50;
        }
      

    for (int i=0; i<sparks.size(); i++){
    
        sparks[i].applyForce(force);
        sparks[i].update(timeDiff);
    }
    
    // erase sparks until we have a manageable size
    while (sparks.size() > 100){
        sparks.erase(sparks.begin());
    }
    
    lifespan -= timeDiff;
        if (lifespan < 0) {
            
            lifespan = 0;

        };
  
    }else{
        pos+=vel;
    }
    
}

void Firework::draw(){
    
    if(pos.y > rePos.y){
        ofDrawCircle(pos,5);
    }
    else{
    
    for (int i=0; i<sparks.size(); i++){
        sparks[i].draw();
    }}
}
