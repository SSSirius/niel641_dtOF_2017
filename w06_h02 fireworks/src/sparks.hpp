
#pragma once
#include "ofMain.h"

class Spark {
public:
    Spark();
    ~Spark(){}
    Spark(ofVec3f _pos);
  
    void draw();
   
    
    void update(float timeDiff);
     void applyForce(ofVec3f force);
    
    ofVec3f pos,vel,acc;
    
    int lifespan;
    
    
};
