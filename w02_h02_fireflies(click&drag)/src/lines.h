#pragma once
#include "ofMain.h"		// ofMain.h lets our Ball "see" openFrameworks

class Lines {
    
public:		// other classes can access the following functions & variables:
    
    Lines();				// "constructor" function - required for every class
    // this is automatically called whenever we create a new ball
    void setup(float px, float py);
    void update();
    void draw();
    float radius;
    ofVec2f pos1;
    ofVec2f vel;
    ofVec2f pos2;
    ofColor color;
    
};
