#pragma once

#include "ofMain.h"
#include "obj.h"
#include <string>// 注意是<string>，不是<string.h>，带.h的是C语言中的头文件

using  std::string;


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
        void resetAttract();
        vector <particle> particles;
        vector <ofPoint> attractPoints;
       ofImage bg;
        ofTrueTypeFont myfont;
         char fpsStr[255];
        ofRectangle rect;
      int Minutes;
        bool space;
        string min,hour,sec;
    
        vector<ofPolyline> polylines;
        vector < ofTTFCharacter > paths;
        ofVec3f offset;
   
   
};
