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
	gui.add(debug.set("debug", false));
	
	// Shader GUI parameters (defaults match original shader constants)
	gui.add(arrowDensity.set("Arrow Density", 4.5f, 0.5f, 20.0f));
	gui.add(arrowLength.set("Arrow Length", 0.45f, 0.05f, 2.0f));
	gui.add(iter1.set("Iter1", 10, 1, 64));
	gui.add(iter2.set("Iter2", 10, 1, 64));
	gui.add(vectorFieldMode.set("Vector Field Mode", 0, 0, 1));
	gui.add(scaleParam.set("Scale", 5.0f, 0.1f, 20.0f));
	gui.add(velocityX.set("Velocity X", 0.1f, -5.0f, 5.0f));
	gui.add(velocityY.set("Velocity Y", 0.2f, -5.0f, 5.0f));
	gui.add(mode2Speed.set("Mode2 Speed", 2.5f, 0.0f, 10.0f));
	gui.add(mode1Detail.set("Mode1 Detail", 200.0f, 1.0f, 500.0f));
	gui.add(mode1Twist.set("Mode1 Twist", 50.0f, 0.0f, 200.0f));
	gui.add(showArrows.set("Show Arrows", false));
	
	
	
	gui.loadFromFile("settings.xml");
}


//--------------------------------------------------------------
void ofApp::update(){
	
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(255,255,255);
	
	shadertoy.begin();
	
	// Upload uniforms
	shadertoy.setUniform1f("uArrowDensity", arrowDensity);
	shadertoy.setUniform1f("uArrowLength", arrowLength);
	shadertoy.setUniform1i("uIter1", iter1);
	shadertoy.setUniform1i("uIter2", iter2);
	shadertoy.setUniform1i("uVectorFieldMode", vectorFieldMode);
	shadertoy.setUniform1f("uScale", scaleParam);
	shadertoy.setUniform1f("uVelocityX", velocityX);
	shadertoy.setUniform1f("uVelocityY", velocityY);
	shadertoy.setUniform1f("uMode2Speed", mode2Speed);
	shadertoy.setUniform1f("uMode1Detail", mode1Detail);
	shadertoy.setUniform1f("uMode1Twist", mode1Twist);
	shadertoy.setUniform1i("uShowArrows", (int)showArrows);
	
	ofDrawRectangle(0, 0, ofGetWindowWidth(), ofGetWindowHeight());
	shadertoy.end();
	if (debug) {
		shadertoy.drawDebug();
		
		gui.draw();
	}
}

//--------------------------------------------------------------
void ofApp::exit(){
	
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	switch (key) {
		case 'g':
			debug = !debug;
			break;
			
		default:
			break;
	}
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
