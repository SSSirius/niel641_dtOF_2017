#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundAuto(false);
    for(int i=0;i<80;i+=1){
        ofVec3f num;
        num.x= i ;
        num.y= 90 + i*3;
        num.z=ofRandom(100);
        nums.push_back(num);
    }
    sphere= ofSpherePrimitive(250,60);
    
    box = ofBoxPrimitive(20,20,100);
    box.setPosition(0, 0, -100);
    //    light.setDirectional();
    light.setPointLight();
    light.setSpecularColor(ofColor(255, 255, 255));
    light.setPosition(0,0,100);
    gui.setup();
    gui.add(scale.setup("scale",1,0,5));
    gui.add(flow.setup("flow",0,0,3));
     gui.add(rotate.setup("rotete",false));
//    gui.add( showimg.setup("show image", true) );
//    gui.add( bWires.setup("draw wireframe",true) );
    
    ofVec3f vertice;
   
    
    
    for(int i=0;i<80;i+=1){
        for(int j=0;j<nums[i].y;j++){
            
            float posx,posy;
            posx=sin(PI*2/nums[i].y*j)*10*i;
            posy=cos(PI*2/nums[i].y*j)*10*i;
            
            //            posx=i;
            //            posy=j;
            float hue = ofMap(i, 0, 80, 100, 150);
            float bright = ofMap(i, 0, 80, 150, 250);
            ofColor color= ofColor::fromHsb(hue, 255, 250,bright) ;
            //            ofDrawSphere(posx,posy,nums[i].z,ofMap(i,0.,60,0.5,3.));
            vertice.x= posx;
            vertice.y= posy;
            vertice.z= nums[i].z;
            mesh.addIndex(alln);
            mesh.addVertex(vertice);
            verz.push_back(vertice);
            mesh.addColor(color);
            alln++;
            //        mesh.addColor(color);
        }
        
        
    }
      mesh.setMode(OF_PRIMITIVE_POINTS);
        mesh.disableIndices();
    
   
}

//--------------------------------------------------------------
void ofApp::update(){
    float time = ofGetElapsedTimef();
    ////        nums[i].z-=0.5;
    vector<ofVec3f> & vertices = mesh.getVertices();
//    vector<ofVec3f> verz = vertices;
    //    }
    for(int i =0; i<vertices.size();i++){
        
        float noise = ofSignedNoise(vertices[i].z*0.1,vertices[i].z*0.1,time);
        vertices[i].x= scale *verz[i].x;
         vertices[i].y= scale *verz[i].y;
        vertices[i].z = noise *20* flow +  verz[i].z;
        mesh.setVertex(i,vertices[i]);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(0, 0, 0, 200);
    ofDrawRectangle(0,0,ofGetWidth(),ofGetHeight());
    ofPushMatrix();
    //     ofTranslate(0,0,ofGetElapsedTimef()*50);
    ofTranslate(ofGetWidth()/2,ofGetHeight()/2);
    //     cam.setDistance(ofGetElapsedTimef()*50+600);
    cam.begin();
    //   light.enable();
    //    light.draw();
    if(rotate){
        ofRotate(ofGetElapsedTimef()*200);}
    mesh.drawWireframe();
    mesh.draw();
    //     box.draw();
    cam.end();
    
    ofPopMatrix();
    gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
