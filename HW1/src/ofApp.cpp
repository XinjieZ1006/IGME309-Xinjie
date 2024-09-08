#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	pathLength = -1;
	//gui.setup();
	//gui.add(startButton.setup("Start A* Search"));
	search = AStar();
	grid.resize(MAP_WIDTH/GRID_WIDTH, std::vector<Node>(MAP_HEIGHT/GRID_HEIGHT));
	for (int i = 0; i < grid.size(); ++i)
	{
		for (int j = 0; j < grid[0].size(); ++j)
		{
			grid[i][j] = Node(i * GRID_WIDTH, j * GRID_HEIGHT, nullptr);
			//std::cout << grid[i][j].x <<","<< grid[i][j].y << std::endl;
		}
	}
	start = &grid[4][9];
	target = &grid[0][6];
	start->type = START;
	target->type = TARGET;
	start->gCost = 0;
	start->hCost = search.CalcHCost(*start, *target);
}

//--------------------------------------------------------------
void ofApp::update(){

	// update mouse location
	int mouseX = ofGetMouseX();
	int mouseY = ofGetMouseY();

	hoveredCol = mouseX / GRID_WIDTH;
	hoveredRow = mouseY / GRID_HEIGHT;

	if (hoveredCol >= 0 && hoveredCol < grid.size() && hoveredRow >= 0 && hoveredRow < grid[0].size())
	{
		isMouseOnGrid = true;
	}
	else
	{
		isMouseOnGrid = false;
	}
}

//--------------------------------------------------------------
void ofApp::draw(){

	ofSetBackgroundColor(217, 224, 252);
	for (int i = 0; i < grid.size(); ++i)
	{
		for (int j = 0; j < grid[0].size(); ++j)
		{
			switch (grid[i][j].type)
			{
			case EMPTY:
				ofNoFill();
				ofSetColor(255);
				break;
			case START:
				ofFill();
				ofSetColor(0, 255, 0);
				break;
			case TARGET:
				ofFill();
				ofSetColor(255, 0, 0);
				break;
			case SEARCHED:
				ofFill();
				ofSetColor(200, 0, 200);
				break;
			case PATH:
				ofFill();
				ofSetColor(255, 255, 0);
				break;
			case OBSTACLE:
				ofFill();
				ofSetColor(0);
				break;
			default:
				ofNoFill();
				ofSetColor(255);
				break;
			}
			ofDrawRectangle(GRID_WIDTH * i, GRID_HEIGHT * j, GRID_WIDTH, GRID_HEIGHT);
			ofNoFill();
			ofSetColor(0);
			ofDrawRectangle(GRID_WIDTH * i, GRID_HEIGHT * j, GRID_WIDTH, GRID_HEIGHT);
		}
	}
	if (isMouseOnGrid)
	{
		ofFill();
		ofSetColor(255);
		ofDrawRectangle(GRID_WIDTH * hoveredCol, GRID_HEIGHT * hoveredRow, GRID_WIDTH, GRID_HEIGHT);
	}

	//draw string
	stringstream ss;
	ss << "A* Search Visualizer" << std::endl;
	ss << "Click and drag to set start and end" << std::endl;
	ss << "Drag across the grid to set obstacles" << std::endl;
	ss << "Press S to start search" << std::endl;
	ss << "Press R to reset the grid" << std::endl;
	ss << "Start: (" << 1 + start->x / GRID_WIDTH << "," << 1 + start->y / GRID_HEIGHT << ")" << std::endl;
	ss << "Target: (" << 1 + target->x / GRID_WIDTH << "," << 1 + target->y / GRID_HEIGHT << ")" << std::endl;
	if (pathLength < 0)
	{
		ss << "No Path Found!" << std::endl;
	}
	else
	{
		ss << "Search success! Path length: " << pathLength << std::endl;
	}
	ofSetColor(0);
	ofDrawBitmapString(ss.str().c_str(), 600, 20);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == 'S' || key=='s')
	{
		bool resetObs = false;
		search.ResetGrid(grid, resetObs);
		pathLength = search.Search(*start, *target, grid);
	}
	if (key == 'r' || key == 'R')
	{
		bool resetObs = true;
		search.ResetGrid(grid,resetObs);
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

	if (isMouseOnGrid && (hoveredCol*GRID_WIDTH != dragged->x || hoveredRow * GRID_HEIGHT != dragged->y))
	{
		if (grid[hoveredCol][hoveredRow].type == EMPTY)
		{
			if (isDraggingStart)
			{
				dragged->type = EMPTY;
				dragged = &grid[hoveredCol][hoveredRow];
				dragged->type = START;
			}
			else if (isDraggingTarget)
			{
				dragged->type = EMPTY;
				dragged = &grid[hoveredCol][hoveredRow];
				dragged->type = TARGET;
			}
			else
			{
				dragged->type = OBSTACLE;
				dragged = &grid[hoveredCol][hoveredRow];
			}
		}
	}
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	
	if (isMouseOnGrid)
	{
		if (grid[hoveredCol][hoveredRow].type != TARGET && grid[hoveredCol][hoveredRow].type != START)
		{
			isDraggingTarget = false;
			isDraggingStart = false;
			dragged = &grid[hoveredCol][hoveredRow];
			grid[hoveredCol][hoveredRow].type = OBSTACLE;
		}
		else if (grid[hoveredCol][hoveredRow].type == TARGET)
		{
			isDraggingTarget = true;
			dragged = &grid[hoveredCol][hoveredRow];

		}
		else if (grid[hoveredCol][hoveredRow].type == START)
		{
			isDraggingStart = true;
			dragged = &grid[hoveredCol][hoveredRow];

		}
		
	}
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	if (isMouseOnGrid)
	{
		if (isDraggingStart)
		{
			dragged->type = EMPTY;
			start = &grid[hoveredCol][hoveredRow];
			grid[hoveredCol][hoveredRow].type = START;
		}
		else if (isDraggingTarget)
		{
			dragged->type = EMPTY;
			target = &grid[hoveredCol][hoveredRow];
			grid[hoveredCol][hoveredRow].type = TARGET;
		}
	}
	isDraggingStart = false;
	isDraggingTarget = false;
	dragged = nullptr;
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

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
