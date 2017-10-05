#pragma once

#include "ofMain.h"


class Ripple {
public:

Ripple(){
    pos.set(0,0);
    prevPos.set(0,0);
    acc=0.0;
    
    
    
    
}
~Ripple(){}

void update(int arr);
void draw();
void restart(int count,int hi, int x);

    ofVec3f pos;
   ofVec3f vel;
   float acc;
    float oldAcc;
     ofVec3f  prevPos;
    float fri=0.8;
    int offset=0;
    int hig=0;
//ofVec3f offset;

//float angle;        // angle in degrees
//
//float size = 10.;;        // speed, 0-1

ofColor color = ofColor(255);

};

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
//    ofVec3f pos;
    ofVec2f rpos;
    ofVec2f rvel;
    ofVec2f racc;
    float size;
    int hi;
    float friction;
    int count;
    vector<Ripple> ripples;
    
		
};
