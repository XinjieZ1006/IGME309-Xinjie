#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	for (int i = 0; i < imgWidth; ++i) {
		for (int j = 0; j < imgHeight; ++j) {
			colors[i][j] = ofColor::red.getLerped(ofColor::cyan, i / static_cast<float>(imgWidth));
		}
	}
	imageColored.allocate(imgWidth, imgHeight, OF_IMAGE_COLOR);
	for (int i = 0; i < imgWidth; ++i) {
		for (int j = 0; j < imgHeight; ++j) {
			imageColored.setColor(i, j, colors[i][j]);
		}
	}
	imageColored.update();
	imageGrayscale.allocate(imgWidth, imgHeight, OF_IMAGE_COLOR);
	for (int i = 0; i < imgWidth; ++i) {
		for (int j = 0; j < imgHeight; ++j) {
			ofColor c = colors[i][j];
			ofColor grayscale = ofColor(c.r * 0.299 + c.g * 0.587  + c.b * 0.114);
			imageGrayscale.setColor(i, j, grayscale);
		}
	}
	imageGrayscale.update();
	imageColored.resize(108, 72);
	imageGrayscale.resize(108, 72);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	imageColored.draw(0, 0);
	imageGrayscale.draw(imgWidth, 0);
	ofSetColor(255);
	drawCurve();
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

void ofApp::drawCurve()
{
	ofSetPolyMode(ofPolyWindingMode::OF_POLY_WINDING_NONZERO);
	ofNoFill();
	ofSetLineWidth(20);
	ofBeginShape();
	ofCurveVertex(400, 135);
	ofCurveVertex(200, 400);
	ofCurveVertex(300, 200);
	ofCurveVertex(365, 25);
	//ofVertex(305, 200);
	//ofVertex(250, 25);
	ofEndShape();
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
