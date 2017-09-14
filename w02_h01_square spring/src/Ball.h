#pragma once
#include "ofMain.h"		// ofMain.h lets our Ball "see" openFrameworks

class Ball {
    
public:		// other classes can access the following functions & variables:
    
    Ball();				// "constructor" function - required for every class
    // this is automatically called whenever we create a new ball
    void setup(float px, float py, int rad);
    void update();
    void draw();
    float radius;
    ofVec2f pos;
    ofVec2f vel;
    ofVec2f ori;
    	ofColor color;
    
};
