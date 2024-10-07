#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetLineWidth(200);
	ofSetFrameRate(30);
	speed = 16;
}

//--------------------------------------------------------------
void ofApp::update(){
	elapsedTime += ofGetLastFrameTime();
	std::cout << elapsedTime << endl;
	if (elapsedTime > duration)
	{
		elapsedTime = 0;
	}
	if (modeSelection == 1 || modeSelection == 2)
	{
		currentDeg += step;
	}
	else
	{
		float t1 = elapsedTime / duration;
		currentDeg = ofxeasing::map(elapsedTime, 0, duration, 0, 360, ofxeasing::quad::easeInOut);
	}
	if (currentDeg > 360)
	{
		currentDeg = 0;
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);	
	switch (modeSelection)
	{
	case 1:
		drawRadialLine();
		break;
	case 2:
		drawDot();
		break;
	case 3:
		drawEaseOutDots();
		break;
	case 4:
		drawArc();
		break;
	default:
		break;
	}
	ofDrawBitmapString("Press Left/Right Arrow Keys to Switch Modes.", -150, -200);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == OF_KEY_RIGHT)
	{
		currentDeg = 0;
		modeSelection += 1;
		if (modeSelection > 4)
		{
			modeSelection = 1;
		}
	}
	if (key == OF_KEY_LEFT)
	{
		currentDeg = 0;
		modeSelection -= 1;
		if (modeSelection < 1)
		{
			modeSelection = 4;
		}
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

void ofApp::drawRadialLine()
{
	ofFill();
	ofClear(128);
	for (int i = 0; i < section / 2; ++i)
	{
		float angle = ofDegToRad(currentDeg + (i * step)) * -1;
		float x1 = radius * sin(angle);
		float y1 = radius * cos(angle);
		float x2 = (radius + 50) * sin(angle);
		float y2 = (radius + 50) * cos(angle);
		float opacity = ofMap(i, 0, section / 2, 0, 255);
		ofSetColor(255, opacity);
		ofDrawLine(x1, y1, x2, y2);
	}
	ofDrawBitmapString("Current Mode: Simply Radial Lines", -100, 200);
}

void ofApp::drawDot()
{
	ofFill();
	ofClear(128);
	for (int i = 0; i < section / 2; ++i)
	{
		float angle = ofDegToRad(currentDeg + (i * step)) * -1;
		float x1 = (radius) * sin(angle);
		float y1 = (radius) * cos(angle);
		float opacity = ofMap(i, 0, section / 2, 0, 255);
		ofSetColor(255, opacity);
		ofDrawCircle(x1, y1,10);
	}
	ofDrawBitmapString("Current Mode: Simply Dots", -100, 200);
}

void ofApp::drawEaseOutDots()
{
	ofClear(128);
	ofFill();
	ofSetColor(255);
	float startAngle = currentDeg;
	float endAngle = currentDeg + 180;
	float offsetAngle = offset;
	
	for (int i = 0; i < 6; ++i)
	{
		float offsetTime = elapsedTime - 0.1 * i;
		offsetTime = ofClamp(offsetTime, 0, duration);
		float offsetDeg = ofxeasing::map(offsetTime, 0, duration, 0, 360, ofxeasing::quad::easeInOut);
		float angle = ofDegToRad(offsetDeg) * -1;
		float x1 = (radius)*sin(angle);
		float y1 = (radius)*cos(angle);
		float opacity = ofMap(i, 0, section / 2, 255, 0);
		ofSetColor(255, opacity);
		ofDrawCircle(x1, y1, 10);
	}
	ofSetColor(255);
	ofDrawBitmapString("Current Mode: Ease-In-Out Dots", -100, 200);



}

void ofApp::drawArc()
{
	ofClear(128);
	ofSetColor(255, 10);
	ofSetLineWidth(10);
	ofDrawCircle(0, 0, radius);
	ofSetColor(255);
	ofBeginShape();
	ofNoFill();
	ofPath arc;
	arc.setArcResolution(300);
	float offsetTime = elapsedTime - 0.3; // adjust the decimal value to change arc length
	offsetTime = ofClamp(offsetTime, 0, duration); // make sure the offset time is within the range
	float startDeg = ofxeasing::map(offsetTime, 0, duration, 0, 360, ofxeasing::quad::easeInOut);
	float endDeg = ofxeasing::map(elapsedTime, 0, duration, 0, 360, ofxeasing::quad::easeInOut);
	float angle = ofDegToRad(startDeg) * -1;
	float endAngle = ofDegToRad(endDeg) * -1;
	arc.setStrokeColor(255);
	arc.setStrokeWidth(10);
	arc.setFilled(false);
	if (startDeg != endDeg) // prevent accidentally drawing a full circle
	{
		arc.arc(0, 0, radius, radius, startDeg, endDeg);
	}
	arc.draw();
	ofDrawBitmapString("Current Mode: Ease-In-Out Arc", -100, 200);

}

float ofApp::quradraticEaseInOut(float t)
{
	t /= 0.5f; // Normalize t to a range of 0 to 2
	if (t < 1.0f)
	{
		return change / 2.0f * t * t + start; // Ease-in
	}
	t -= 1.0f; // Adjust t to the second half
	return -change / 2.0f * (t * (t - 2.0f)) + start; // Ease-out
}
float ofApp::Bezier(float t)
{
	return t * t * (3.0f - 2.0f * t);
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
