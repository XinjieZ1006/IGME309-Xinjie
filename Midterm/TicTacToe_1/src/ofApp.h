#pragma once

#include "ofMain.h"
//#include <vector>
//#include <algorithm>

#define GRID_SIZE 100

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
		const int width = 3;
		const int height = 3;

		const std::vector<std::pair<std::string, char>> players = { { "Player 1", 'X' }, { "Player 2", 'O' } };
		char currentPlayer;

		bool isWinning;

		int mouseX, mouseY;
		std::vector<std::vector<char>> board{width, std::vector<char>(height)};
		int turnCount;

		int hoveredRow;
		int hoveredCol;


		// check all 8 directions
		//const std::vector<std::pair<int, int>> directions = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 }, { 1, 1 }, { 1, -1 }, { -1, 1 }, { -1, -1 } }; 

		bool checkPiece();

		void placePiece(int row, int col, char currentPlayer);
		void switchPlayer();
		void reset();
};
