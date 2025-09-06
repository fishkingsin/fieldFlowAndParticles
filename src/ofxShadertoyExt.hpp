//
//  ofxShadertoyExt.hpp
//  fieldFlowAndParticles
//
//  Created by James Kong on 2/9/2025.
//

#ifndef ofxShadertoyExt_hpp
#define ofxShadertoyExt_hpp

#include <stdio.h>
#include "ofxShadertoy.h"


class ofxShadertoyExt: public ofxShadertoy {
public:
	void setup();
	int frame, densityWidth, densityHeight, simulationWidth, simulationHeight, windowWidth, windowHeight;
	ofTexture fboA, fboB, fboC, fboD;
	bool load(string shaderfilename, Buffer buffer);
	void applyTexture(ofxShadertoy::Buffer buffer);
	void drawDebug();
	
	
	bool reloadShaders();
	
	void enableWatchFiles();
	void disableWatchFiles();
		
	void setMillisBetweenFileCheck( int _millis );
	
	void _update(ofEventArgs &e);
	
	void setGeometryInputType(GLenum type);
	void setGeometryOutputType(GLenum type);
	void setGeometryOutputCount(int count);
	
private:
	
	bool bWatchingFiles;
	bool filesChanged();
	
	bool loadShaderNextFrame;
	
	std::time_t getLastModified( ofFile& _file );
	
	int lastTimeCheckMillis;
	int millisBetweenFileCheck;
	
	string fileAFileName, fileBFileName, fileCFileName, fileDFileName, fileImageFileName;
	ofFile fileA, fileB, fileC, fileD, fileImage;
	vector< std::time_t > fileChangedTimes;
	ofxShadertoy::Buffer changeBuffer;
	string openFile(ofFile file, string fileName);
};

#endif /* ofxShadertoyExt_hpp */
