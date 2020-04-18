#include "ofApp.h"

void ofApp::setup(){
    ofSetVerticalSync(true);
    ofEnableAlphaBlending();
    ofEnableSmoothing();
    ofBackground(0,0,0);

    sampleRate 	= 44100; /* Sampling Rate */
    bufferSize	= 512; /* Buffer Size. you have to fill this buffer with sound using the for loop in the audioOut method */

    ofxMaxiSettings::setup(sampleRate, 2, bufferSize);

    // the higher the value, the more accurate will be the fft analysis
	fftSize = 1024;
	//fftSize = 512;

    fft.setup(fftSize, fftSize*0.5f, 256);

    ///* this has to happen at the end of setup - it switches on the DAC */
    //ofSoundStreamSetup(2,2,this, sampleRate, bufferSize, 4);

	//mymix.

	ofLogToConsole();
	soundStream.printDeviceList();

	//int dev = 6;//wasapi
	int dev = 4;//ds

	//std::vector<ofSoundDevice> devices = soundStream.getDeviceList(ofSoundDevice::Api::MS_WASAPI);
	std::vector<ofSoundDevice> devices = soundStream.getDeviceList(ofSoundDevice::Api::MS_DS);

	ofSoundStreamSettings settings;
	settings.setInDevice(devices[dev]);
	settings.setInListener(ofGetAppPtr());

	//settings.setApi(ofSoundDevice::Api::MS_WASAPI);
	settings.setApi(ofSoundDevice::Api::MS_DS);

	settings.numInputChannels = 2;
	settings.numOutputChannels = 0;
	settings.sampleRate = sampleRate;
	settings.bufferSize = bufferSize;
	settings.numBuffers = 4;

	soundStream.setup(settings);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255, 255, 255);
    for(int i = 0; i < fftSize ;i++){
        ofDrawRectangle(i * 2, ofGetHeight(), 2, -(fft.magnitudesDB[i]) * 8);
    }
}

//--------------------------------------------------------------
void ofApp::audioOut(float * output, int bufferSize, int nChannels) {
}

//--------------------------------------------------------------
void ofApp::audioIn(float * input, int bufferSize, int nChannels){
    double input0, input1;
    for (int i = 0; i < bufferSize; i++){
        //fft
        input0 = input[i*2    ];
        input1 = input[i*2 + 1];

        if(fft.process(input0)){
            fft.magsToDB();
        }
        if(fft.process(input1)){
            fft.magsToDB();
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){


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
