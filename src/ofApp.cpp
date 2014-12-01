#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetFrameRate(60);
    
    ofEnableAlphaBlending();
    
    srcImg.loadImage("A.jpg");
    dstImg.loadImage("B.jpg");
    
    int width = srcImg.getWidth();
    int height = srcImg.getHeight();
    
    maskTool.setup(width, height);

}

//--------------------------------------------------------------
void ofApp::update(){
    
    maskTool.update(srcImg.getTextureReference());
}

//--------------------------------------------------------------
void ofApp::draw(){

    maskTool.draw(dstImg.getTextureReference());
    ofDrawBitmapString(ofToString(ofGetFrameRate()) + " fps", 15, 15);
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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
