#pragma once

#include "ofMain.h"
#include "ofxMaxim.h"

class ofApp : public ofBaseApp{

public:
    void setup();
    void update();
    void draw();

    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);

    // Audio output method
    void audioOut(float * output, int bufferSize, int nChannels);

    double  outputs[2];
    int		bufferSize;
    int		sampleRate;

    ofxMaxiOsc myOscill,myCounter,mySwitchableOsc;
    ofxMaxiFilter myFilter;
    maxiEnv myEnvelope;
    int CurrentCount;
    double myOscOutput,myCurrentVolume, myFilteredOutput;
};