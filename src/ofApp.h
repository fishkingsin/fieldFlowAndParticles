#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "ofxShadertoy.h"
#include "ofxShadertoyExt.hpp"
class ofApp : public ofBaseApp {

public:
	void setup() override;
	void update() override;
	void draw() override;
	void exit() override;

	void keyPressed(int key) override;
	void keyReleased(int key) override;
	void mouseMoved(int x, int y) override;
	void mouseDragged(int x, int y, int button) override;
	void mousePressed(int x, int y, int button) override;
	void mouseReleased(int x, int y, int button) override;
	void mouseScrolled(int x, int y, float scrollX, float scrollY) override;
	void mouseEntered(int x, int y) override;
	void mouseExited(int x, int y) override;
	void windowResized(int w, int h) override;
	void dragEvent(ofDragInfo dragInfo) override;
	void gotMessage(ofMessage msg) override;
	ofxPanel gui;
	ofParameter<bool> debug;

	// Shader control parameters
	ofParameter<float> arrowDensity;
	ofParameter<float> arrowLength;
	ofParameter<int> iter1;
	ofParameter<int> iter2;
	ofParameter<int> vectorFieldMode;
	ofParameter<float> scaleParam;
	ofParameter<float> velocityX;
	ofParameter<float> velocityY;
	ofParameter<float> mode2Speed;
	ofParameter<float> mode1Detail;
	ofParameter<float> mode1Twist;
	ofParameter<bool> showArrows;

	ofxShadertoyExt shadertoy;
	int frame, densityWidth, densityHeight, simulationWidth, simulationHeight, windowWidth, windowHeight;
};
