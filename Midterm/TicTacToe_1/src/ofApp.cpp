#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	turnCount = 0;
	currentPlayer = players[0].second;
}

//--------------------------------------------------------------
void ofApp::update(){

	mouseX = ofGetMouseX();
	mouseY = ofGetMouseY();

	hoveredCol = mouseY / GRID_SIZE;
	hoveredRow = mouseX / GRID_SIZE;
	

	std::cout << currentPlayer << endl;
}

//--------------------------------------------------------------
void ofApp::draw(){

	// draw highlight
	if (hoveredCol < 3 && hoveredRow < 3 && !isWinning)
	{
		ofFill();
		ofSetColor(255, 20);
		ofDrawRectangle(GRID_SIZE * hoveredRow, GRID_SIZE * hoveredCol, GRID_SIZE, GRID_SIZE);

		// draw piece
		if (currentPlayer == 'X')
		{
			ofSetColor(255,0,0,30);
			ofSetLineWidth(20);
			ofDrawLine(mouseX - 10,mouseY - 10,mouseX + 50,mouseY + 50);
			ofDrawLine(mouseX + 50, mouseY - 10, mouseX - 10, mouseY + 50);
		}
		else if(currentPlayer == 'O')
		{
			ofNoFill();
			ofSetColor(255, 0, 0, 30);
			ofSetLineWidth(20);
			ofDrawCircle(mouseX, mouseY, 20);
		}
	}
	for (int i = 0; i < board.size(); ++i)
	{
		for (int j = 0; j < board[0].size(); ++j)
		{
			if (board[i][j] == 'X')
			{
				ofFill();
				ofSetColor(ofColor::red);
				ofSetLineWidth(20);
				ofDrawLine(i * GRID_SIZE + 20, j * GRID_SIZE + 20, i * GRID_SIZE + GRID_SIZE - 20, j * GRID_SIZE + GRID_SIZE - 20);
				ofDrawLine((i + 1) * GRID_SIZE - 20, j * GRID_SIZE + 20, i * GRID_SIZE + 20, j * GRID_SIZE + GRID_SIZE - 20);
			}
			if (board[i][j] == 'O')
			{
				ofNoFill();
				ofSetColor(ofColor::red);
				ofSetLineWidth(20);
				ofDrawCircle(i * GRID_SIZE + 50, j * GRID_SIZE + 50, 30.0f);
			}

			ofNoFill();
			ofSetColor(ofColor::white);
			ofSetLineWidth(2);
			ofDrawRectangle(i * GRID_SIZE, j * GRID_SIZE, GRID_SIZE, GRID_SIZE);

		}

	}

	ofSetColor(ofColor::white);
	ofDrawBitmapString("Welcome to Tic Tac Toe!", 400, 200);
	std::string player = std::string("Current Player: ") + currentPlayer;
	ofDrawBitmapString(player, 400, 250);
	if (isWinning)
	{
		ofSetColor(ofColor::yellow);
		std::string winning = std::string(1,currentPlayer) + " Wins! Press R to restart.";
		ofDrawBitmapString(winning, 400, 270);
	}
	if (turnCount == 9 && !isWinning)
	{
		ofSetColor(ofColor::yellow);
		ofDrawBitmapString("Draw! Press R to restart.", 400, 270);
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == 'r' || key == 'R')
	{
		reset();
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
	// stop the game after winning
	if (!isWinning)
	{
		if (hoveredCol < 3 && hoveredRow < 3)
		{
			placePiece(hoveredRow, hoveredCol, currentPlayer);
			if (!isWinning)
			{
				switchPlayer();
			}
		}
	}
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

bool ofApp::checkPiece()
{

	for (int row = 0; row < height; ++row)
	{
		if (std::all_of(board[row].begin(), board[row].end(), [this](char c) { return c == currentPlayer; }))
		{
			return true;
		}
	}
	for (int col = 0; col < width; ++col)
	{
		if (std::all_of(board.begin(), board.end(), [col, this](const std::vector<char>& row){return row[col] == currentPlayer;}))
		{
			return true; 
		}
	}
	if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer)
	{
		return true;
	}
	if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)
	{
		return true;
	}
	return false;
}

void ofApp::placePiece(int row, int col,char currentPlayer)
{
	if (board[row][col] != 0)
	{
		// can't place on occupied places
		return;
	}
	turnCount += 1;
	board[row][col] = currentPlayer;
	isWinning = checkPiece();
}

void ofApp::switchPlayer()
{
	if (currentPlayer == 'X')
	{
		currentPlayer = 'O';
	}
	else
	{
		currentPlayer = 'X';
	}
}

void ofApp::reset()
{
	isWinning = false;
	turnCount = 0;
	switchPlayer();
	for (int i = 0; i < width; ++i)
	{
		for (int j = 0; j < height; ++j)
		{
			board[i][j] = 0;
		}
	}
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
