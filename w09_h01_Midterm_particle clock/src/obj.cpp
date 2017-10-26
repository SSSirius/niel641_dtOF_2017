#include "obj.h"
#include "ofMain.h"

//------------------------------------------------------------
particle::particle(){
    setInitialCondition(0,0,0,0);
    damping =  ofRandom(0.005, 0.01);
    ofColor white(0, 255, 255, 255);
    ofColor gray(150,0, 150,150);
    //    ofNoFill();
    color = gray.getLerped(white, ofRandom(1.0));
    drag  = ofRandom(0.95, 0.998);
    attractPoints = NULL;
    radius=1.5;
     maxdist = sqrt(ofGetWidth()*ofGetWidth()+ofGetHeight()*ofGetHeight());
   
}

//------------------------------------------------------------
void particle::resetForce(){
    // we reset the forces every frame
    frc.set(0,0);
}

//------------------------------------------------------------
void particle::setAttractPoints( vector <ofPoint> * attract ){
    attractPoints = attract;
}
//------------------------------------------------------------
void particle::addForce(float x, float y){
    // add in a force in X and Y for this frame.
    frc.x = frc.x + x;
    frc.y = frc.y + y;
}

//------------------------------------------------------------
void particle::addDampingForce(){
    
    frc.x = frc.x - vel.x * damping;
    frc.y = frc.y - vel.y * damping;
    
}

//------------------------------------------------------------
void particle::setInitialCondition(float px, float py, float vx, float vy){
    pos.set(ofRandom(ofGetWidth()*0,ofGetWidth()),ofRandom(ofGetHeight()*.15,ofGetHeight()*.8));
    vel.set(vx,vy);
}

//------------------------------------------------------------
void particle::update(){
    
    if( attractPoints ){
        ofPoint closestPt;
        int closest = -1;
        float closestDist = 9999999;
        
        for(unsigned int i = 0; i < attractPoints->size(); i++){
            float lenSq = ( attractPoints->at(i)-pos ).lengthSquared();
            if( lenSq < closestDist ){
                closestDist = lenSq;
                closest = i;
            }
        }
        if( closest != -1 ){
            closestPt = attractPoints->at(closest);
            float dist = sqrt(closestDist);
            
            frc = closestPt - pos;
            vel *= drag;
            if( dist < 60 && dist > 10  ){
                vel += frc * 0.06;
                
            }else{
                frc.x = ofSignedNoise(uniqueVal, pos.y * 0.01, ofGetElapsedTimef()*0.2);
                frc.y = ofSignedNoise(uniqueVal, pos.x * 0.01, ofGetElapsedTimef()*0.2);
                vel += frc * 0.04;
               
            }
             radius=ofMap(dist,0,maxdist/4,3,0);
        
        
    } else{
//         radius=1.5;
        ofPoint attractPt(ofGetMouseX(), ofGetMouseY());
        frc = attractPt-pos;
        float dist = frc.length();
         radius=ofMap(dist,0,maxdist/1.5,3,0);
    }
    }
//    if( ofGetMousePressed()){
//        
//        
        ofPoint attractPt(ofGetMouseX(), ofGetMouseY());
        frc = attractPt-pos;
        float dist = frc.length();
        frc.normalize();
        
        vel *= drag;
        if( dist < 50 ){
            radius = ofMap(dist,0,maxdist/4,3,0);
            vel += -frc * 1; //notice the frc is negative
        }else{
            //if the particles are not close to us, lets add a little bit of random movement using noise. this is where uniqueVal comes in handy.
            frc.x = ofSignedNoise(uniqueVal, pos.y * 0.01, ofGetElapsedTimef()*0.2);
            frc.y = ofSignedNoise(uniqueVal, pos.x * 0.01, ofGetElapsedTimef()*0.2);
            vel += frc * 0.04;
//             radius = ofMap(dist,0,maxdist/4,4,0);
        }
//        
//    }
    pos = pos + vel;
    
    if( pos.x > ofGetWidth() ){
        pos.x = ofGetWidth();
        vel.x *= -1.0;
    }else if( pos.x < 0 ){
        pos.x = 0;
        vel.x *= -1.0;
    }
    if( pos.y > ofGetHeight() ){
        pos.y = ofGetHeight();
        vel.y *= -1.0;
    }
    else if( pos.y < 0 ){
        pos.y = 0;
        vel.y *= -1.0;
    }
//     radius=ofMap(dist,0,maxdist/4,4,0);
}
void particle::distory(){
    
   
        
        
        ofPoint attractPt(ofGetMouseX(), ofGetMouseY());
        frc = attractPt-pos;
        float dist = frc.length();
        frc.normalize();
        
        vel *= drag;
        if( dist < 50 ){
            vel += -frc * 1; //notice the frc is negative
        }else{
            //if the particles are not close to us, lets add a little bit of random movement using noise. this is where uniqueVal comes in handy.
            frc.x = ofSignedNoise(uniqueVal, pos.y * 0.01, ofGetElapsedTimef()*0.2);
            frc.y = ofSignedNoise(uniqueVal, pos.x * 0.01, ofGetElapsedTimef()*0.2);
            vel += frc * 0.04;
            
        }
        
    
    pos = pos + vel;
    
    if( pos.x > ofGetWidth() ){
        pos.x = ofGetWidth();
        vel.x *= -1.0;
    }else if( pos.x < 0 ){
        pos.x = 0;
        vel.x *= -1.0;
    }
    if( pos.y > ofGetHeight() ){
        pos.y = ofGetHeight();
        vel.y *= -1.0;
    }
    else if( pos.y < 0 ){
        pos.y = 0;
        vel.y *= -1.0;
    }
    
}
//------------------------------------------------------------
void particle::draw(){
    ofSetColor(color);
    ofDrawCircle(pos.x, pos.y, radius);
    
    
}

