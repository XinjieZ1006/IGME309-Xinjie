#pragma once

#include "ofMain.h"
#include "ofxEasing.h"
#include <vector>

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
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		int modeSelection = 1;

		float section = 12.0;
		float currentDeg = 0;
		float currentDegEnd = 0;
		float radius = 50.0;
		float step = 360 / section;
		float speed = 5;
		float maxSpeed = 5;
		float start = 0;
		float change = 360;

		float duration = 2;
		float elapsedTime = 0;
		float offset = 0.5;

		float acceleration = (180 - speed) / 2;

		void drawRadialLine();
		void drawDot();
		void drawEaseOutDots();
		void drawArc();
		float quradraticEaseInOut(float t);
		float Bezier(float t);



		
};
