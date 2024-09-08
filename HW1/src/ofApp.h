#pragma once

#include "ofMain.h"
#include "Astar.h"
//#include "ofxGui.h"

class ofApp : public ofBaseApp{

	public:
		std::vector<std::vector<int>> test;
		std::vector<std::vector<Node>> grid;

		int hoveredRow = -1;
		int hoveredCol = -1;

		bool isMouseOnGrid; // check if mouse is within the grid
		bool isDraggingStart;
		bool isDraggingTarget;
		bool isSearched;
		Node* dragged;

		// GUI components
		//ofxPanel gui;
		//ofxButton startButton;

		Node* start;
		Node* target;

		AStar search;
		int pathLength;

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
		
};
