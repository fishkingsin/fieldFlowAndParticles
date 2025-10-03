#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){
	ofGLFWWindowSettings settings;
	settings.glVersionMajor = 4;
	settings.glVersionMinor = 1;
	settings.windowMode = OF_WINDOW;
	
	settings.setSize(1280, 720);
	
	shared_ptr<ofAppBaseWindow> mainWindow = ofCreateWindow(settings);
	mainWindow->setWindowTitle("field flow and particles");
	shared_ptr<ofApp> mainApp(new ofApp);
	
	ofRunApp(mainWindow, mainApp);
	ofRunMainLoop();
}
