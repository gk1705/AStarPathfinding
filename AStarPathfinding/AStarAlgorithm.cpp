#include "AStarAlgorithm.h"
#include "Grid.h"
#include "Heuristics.h"
#include "Node.h"
#include <algorithm>
#include <queue>
#include <vector>

void AStarAlgorithm::createGrid(int width, int height, const std::vector<Coordinate>& obstructions)
{
	grid = Grid(width, height);
	for (const Coordinate& obstruction : obstructions)
	{
		grid.addObstruction(obstruction);
	}
}

std::vector<Coordinate> AStarAlgorithm::findPath(const Coordinate& source, const Coordinate& target, HeuristicMethod heuristicMethod) const
{
	std::vector<std::vector<Node>> nodes(grid.getHeight(), std::vector<Node>(grid.getWidth()));

	// initialize nodes with given position
	for (int y = 0; y < grid.getHeight(); ++y)
	{
		for (int x = 0; x < grid.getWidth(); ++x)
		{
			nodes[y][x].position = Coordinate(x, y); // set position to match the coordinate
			nodes[y][x].visited = false;
			nodes[y][x].g_cost = std::numeric_limits<float>::infinity();
			nodes[y][x].h_cost = std::numeric_limits<float>::infinity();
			nodes[y][x].parent = nullptr;
		}
	}

	std::priority_queue<Node, std::vector<Node>, std::greater<>> openSet;

	nodes[source.y][source.x].g_cost = 0; // set g_cost for the source node
	nodes[source.y][source.x].h_cost = Heuristics::calculateHeuristic(source, target, heuristicMethod);
	openSet.push(nodes[source.y][source.x]);

	while (!openSet.empty())
	{
		Node currentNode = openSet.top();
		openSet.pop();

		if (currentNode.visited)
		{
			continue;
		}

		nodes[currentNode.position.y][currentNode.position.x].visited = true;

		if (currentNode.position == target)
		{
			std::vector<Coordinate> path;
			while (currentNode.parent != nullptr)
			{
				path.push_back(currentNode.position);
				currentNode = *currentNode.parent;
			}
			std::ranges::reverse(path);
			return path;
		}

		for (const Coordinate& neighborCoordinate : grid.getNeighbors(currentNode.position)) // change to getNeighborsDiagonally for diagonal pathfinding
		{
			Node& neighborNode = nodes[neighborCoordinate.y][neighborCoordinate.x];

			if (neighborNode.visited || grid.isObstructed(neighborCoordinate.x, neighborCoordinate.y))
			{
				continue;
			}

			const float tentativeGCost = currentNode.g_cost + 1;
			if (tentativeGCost < neighborNode.g_cost)
			{
				neighborNode.g_cost = tentativeGCost;
				neighborNode.h_cost = Heuristics::calculateHeuristic(neighborCoordinate, target, heuristicMethod);
				neighborNode.parent = &nodes[currentNode.position.y][currentNode.position.x];
				openSet.push(neighborNode);
			}
		}
	}

	return {};
}