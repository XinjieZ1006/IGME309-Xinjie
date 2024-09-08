#include "Astar.h"
#include <iostream>

AStar::AStar()
{
	// four directions
	directions.push_back(std::make_pair(0, 1));
	directions.push_back(std::make_pair(1, 0));
	directions.push_back(std::make_pair(0, -1));
	directions.push_back(std::make_pair(-1, 0));
}
AStar::~AStar()
{

}
float AStar::CalcHCost(Node current, Node target)
{
	// use manhattan distance here
	float h = std::abs(current.x - target.x) + std::abs(current.y - target.y);
	return h;
}

bool AStar::isValid(Node node)
{
	if (node.type == OBSTACLE)
	{
		return false;
	}
	else
	{
		return true;
	}
}

int AStar::Search(Node start, Node target,  std::vector<std::vector<Node>>& grid)
{
	int pathLength = -1;
	if (isBlocked(start) || isBlocked(target))
	{
		// quick exit if objects are completely blocked
		return -1;
	}
	std::priority_queue<Node, std::vector<Node>,std::greater<Node>> openList; // use priority queue for open list because we need to compare the fCost
	std::vector<std::vector<bool>> closedList(grid.size(), std::vector<bool>(grid[0].size(), false));  // Closed nodes
	// no need to compare cost in closed list

	openList.push(start); // add starting node to open list

	while (!openList.empty())
	{
		Node current = openList.top(); // the node with the lowest f cost becomes current
		openList.pop();
		if (current.x == target.x && current.y == target.y) // we reached the target
		{
			pathLength = 0;
			// trace back parents for the path
			while (current.parent != nullptr)
			{
				if (current.type != TARGET)
				{
					grid[current.x / GRID_WIDTH][current.y / GRID_HEIGHT].type = PATH;
					pathLength++;
				}
				current = *current.parent;
			}
			return pathLength;
		}
		// add the node to closed list
		closedList[current.x / GRID_WIDTH][current.y / GRID_HEIGHT] = true;

		// check neighboring nodes
		for (const auto& dir : directions)
		{
			int neighborX = current.x + dir.first * GRID_WIDTH;
			int neighborY = current.y + dir.second * GRID_HEIGHT;
			//
			if (neighborX < 0 || neighborY < 0 || neighborX >= MAP_WIDTH || neighborY >= MAP_HEIGHT || !isValid(grid[neighborX / GRID_WIDTH][neighborY / GRID_HEIGHT]) || closedList[neighborX / GRID_WIDTH][neighborY / GRID_HEIGHT])
			{
				// if neighbor is invalid, skip it
				continue;
			}
			// calc new g cost
			Node* neighbor = &grid[neighborX / GRID_WIDTH][neighborY / GRID_HEIGHT];
			neighbor->gCost = current.gCost + 1;
			neighbor->hCost = CalcHCost(*neighbor, target);
			neighbor->fCost = neighbor->gCost + neighbor->hCost;
			neighbor->parent = new Node(current);
			openList.push(*neighbor);
			closedList[neighborX / GRID_WIDTH][neighborY / GRID_HEIGHT] = true;
			if (neighbor->type == EMPTY)
			{
				neighbor->type = SEARCHED;
			}
			
		}
	}
	return pathLength;
}
void AStar::ResetGrid(std::vector<std::vector<Node>>& grid,bool resetObstacles)
{
	for (int i = 0; i < grid.size(); ++i)
	{
		for (int j = 0; j < grid[0].size(); ++j)
		{
			Node* node = &grid[i][j];
			if (resetObstacles)
			{
				if (node->type != TARGET && node->type != START)
				{
					node->type = EMPTY;
				}
			}
			else
			{
				if (node->type != TARGET && node->type != START && node->type != OBSTACLE)
				{
					node->type = EMPTY;
				}
			}

		}
	}
}

bool AStar::isBlocked(Node n)
{
	for (const auto& dir : directions)
	{
		if (isValid(n))
		{
			return false;
		}
	}
	return true;
}


Node::Node(int _x, int _y, Node* _parent)
{
	x = _x;
	y = _y;
	parent = _parent;
	type = EMPTY;
	gCost = 0;
	hCost = 0;
	fCost = 0;
}
