#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(30);
//    ofSetVerticalSync(true);
    ofDisableArbTex(); //video show
//   vio.listDevices();
//    vio.setup(640,480);
//    fbo.allocate(640,480);
    lineNum=0;
    mesh = ofMesh::plane(800,800, 128, 128);
        ofBackground(0);
           ofDisableArbTex();
        image.load("full.jpg");
    image.resize(800,800);
//        mesh=ofMesh::plane(1024,1024,50,50);
        gui.setup();
        gui.add(scale.setup("scale",1,0,3));
    gui.add( showimg.setup("show image", true) );
    gui.add( bWires.setup("draw wireframe",true) );
//    gui.add( bAxis.setup("draw axis", false) );
}

//--------------------------------------------------------------
void ofApp::update(){
    float time = ofGetElapsedTimef();
    vector<ofVec3f> & vertices = mesh.getVertices();
    
//    vio.update();
//    fbo.begin();
//    if (vio.isFrameNew())    // only update if a new webcam frame has arrived
//    {
    for(int i =0; i<vertices.size();i++){
        
        float noise = ofSignedNoise(vertices[i].x*0.1,vertices[i].y*0.1,time*0.1);
       
        float imgX = ofMap(vertices[i].x, -400, 400, 0, image.getWidth()-1);
        float imgY = ofMap(vertices[i].y, -400, 400, 0, image.getHeight()-1);
        
        ofColor color = image.getPixels().getColor(imgX, imgY);
        
        float brightness = color.getBrightness();
         vertices[i].z= brightness * scale*0.4;
        mesh.setVertex(i,vertices[i]);
        mesh.addColor(color);
   
//    ofTexture tex=cam.getTexture();
    
    
//    tex.drawSubsection(0, lineNum, 640, 1, 0, lineNum,640,1);
//    fbo.end();
//    lineNum=(lineNum+1)%480;
    }
    
//}
}

//--------------------------------------------------------------
void ofApp::draw(){
        ofEnableDepthTest();
       cam.begin();
    if(showimg){
         image.bind();
    }
//        image.bind();
//    vio.bind();
//    fbo.draw(0,0,ofGetWidth(),ofGetHeight());
//        ofScale(scale,scale,scale);
//        mesh.draw();
    if(bWires){
    mesh.drawWireframe();
}
    else{
        mesh.draw();
    }
//    vio.unbind();
    //
    if(showimg){
   image.unbind();
}
       ofDisableDepthTest();
    
    //
        cam.end();
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
