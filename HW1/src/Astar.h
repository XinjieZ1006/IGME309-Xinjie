#pragma once
#pragma once
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>

#define MAP_WIDTH 500
#define MAP_HEIGHT 500
#define GRID_WIDTH 25
#define GRID_HEIGHT 25
enum TypeOfNode
{
	START,
	TARGET,
	EMPTY,
	OBSTACLE,
	SEARCHED,
	PATH
};
struct Node
{
public:
	// x and y location
	int x, y;

	Node* parent; // parent node
	TypeOfNode type;


	float gCost; // g is the cost from the start node to current node
	float hCost; // heuristic cost from current node to target node
	float fCost; // f = g+h

	// constructor
	Node(int _x = 0, int _y = 0, Node* _parent = nullptr);

	// overload the < to put it in priority queue
	bool operator > (const Node& other) const
	{
		return fCost > other.fCost;  // Compare based on fCost
	}

};
class AStar
{
public:
	std::vector<std::pair<int, int>> directions;
	AStar();
	~AStar();
	float CalcHCost(Node current, Node target);
	bool isValid(Node node);
	bool isValid(int x, int y);
	int Search(Node start, Node target, std::vector<std::vector<Node>>& grid);
	void ResetGrid(std::vector<std::vector<Node>>& grid, bool isSearched);
	bool isBlocked(Node n);
};