#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetLogLevel(ofLogLevel::OF_LOG_VERBOSE);
	densityWidth = 1920;
	densityHeight = 1080;
	// process all but the density on 16th resolution
	simulationWidth = densityWidth / 2;
	simulationHeight = densityHeight / 2;
	windowWidth = ofGetWindowWidth();
	windowHeight = ofGetWindowHeight();
	
	ofDisableArbTex();
	ofSetFrameRate(60);
	shadertoy.setup();
	shadertoy.setDimensions(densityWidth, densityHeight);
	shadertoy.load("shaders/bufferA.frag", ofxShadertoy::Buffer::BufferA);
	shadertoy.load("shaders/bufferB.frag", ofxShadertoy::Buffer::BufferB);
	shadertoy.load("shaders/bufferC.frag", ofxShadertoy::Buffer::BufferC);
	shadertoy.load("shaders/bufferD.frag", ofxShadertoy::Buffer::BufferD);
	shadertoy.load("shaders/image.frag", ofxShadertoy::Buffer::Image);
	shadertoy.applyTexture(ofxShadertoy::Buffer::BufferA);
	shadertoy.applyTexture(ofxShadertoy::Buffer::BufferB);
	shadertoy.applyTexture(ofxShadertoy::Buffer::BufferC);
	shadertoy.applyTexture(ofxShadertoy::Buffer::BufferD);
	shadertoy.applyTexture(ofxShadertoy::Buffer::Image);
	

	shadertoy.setAdvanceTime(true);
	gui.setup();
	
	gui.loadFromFile("settings.xml");
}


//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(255,255,255);

	shadertoy.begin();
	
	ofDrawRectangle(0, 0, ofGetWindowWidth(), ofGetWindowHeight());
	shadertoy.end();
	shadertoy.drawDebug();
	gui.draw();
}

//--------------------------------------------------------------
void ofApp::exit(){

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
void ofApp::mouseScrolled(int x, int y, float scrollX, float scrollY){

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
