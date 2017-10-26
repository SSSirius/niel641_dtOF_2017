#include "ofMain.h"

class particle
{
public:
    ofVec2f pos;
    ofVec2f vel;
    ofVec2f frc;
    
    particle();
    virtual ~particle(){};
    
    void resetForce();
    void setAttractPoints( vector <ofPoint> * attract );
    
    void addForce(float x, float y);
    void addDampingForce();
    void distory();
    void setInitialCondition(float px, float py, float vx, float vy);
    void update();
    void draw();
    float drag;
    float uniqueVal;
    float scale;
    float radius;
    float damping;
    float maxdist;
    ofColor color;
    vector <ofPoint> * attractPoints;
protected:
private:
    
};
