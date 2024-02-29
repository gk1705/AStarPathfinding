#include <iostream>
#include <ostream>

#include "AStarAlgorithm.h"

bool TestEmptyPath()
{
	AStarAlgorithm astar;
	astar.createGrid(5, 5, {});
	const Coordinate source(0, 0);
	const Coordinate target(0, 0);
	const std::vector<Coordinate> path = astar.findPath(source, target, HeuristicMethod::MANHATTAN);
	return path.empty();
}

bool TestSingleStepPath()
{
	AStarAlgorithm astar;
	astar.createGrid(5, 5, {});
	const Coordinate source(0, 0);
	const Coordinate target(1, 1);
	const std::vector<Coordinate> path = astar.findPath(source, target, HeuristicMethod::MANHATTAN);
	const std::vector<Coordinate> expectedSteps = { Coordinate(1, 0), Coordinate(1, 1) };
	return path.size() == 2 && path[0] == expectedSteps[0] && path[1] == expectedSteps[1];
}

bool TestBlockedPath()
{
	AStarAlgorithm astar;
	const std::vector<Coordinate> obstructions = { Coordinate(1, 0), Coordinate(1, 1), Coordinate(0,2), Coordinate(1, 2) };
	astar.createGrid(5, 5, obstructions);
	const Coordinate source(0, 0);
	const Coordinate target(2, 1);
	const std::vector<Coordinate> path = astar.findPath(source, target, HeuristicMethod::MANHATTAN);
	return path.empty();
}

bool TestPathFinding()
{
	AStarAlgorithm astar;
	std::vector<Coordinate> obstructions = { Coordinate(1, 1), Coordinate(3, 2), Coordinate(2, 4) };
	astar.createGrid(5, 5, obstructions);
	const Coordinate source(0, 0);
	const Coordinate target(4, 4);
	const std::vector<Coordinate> path = astar.findPath(source, target, HeuristicMethod::MANHATTAN);

	// checking if the obstructions are being avoided
	bool obstructionAvoided = true;
	for (const Coordinate& coord : path)
	{
		if (std::ranges::find(obstructions, coord) != obstructions.end())
		{
			obstructionAvoided = false;
			break;
		}
	}

	return obstructionAvoided;
}

int TestAStarAlgorithm()
{
	if (TestEmptyPath())
	{
		std::cout << "testEmptyPath has passed" << std::endl;
	}
	else
	{
		std::cout << "testEmptyPath has failed" << std::endl;
	}

	if (TestSingleStepPath())
	{
		std::cout << "testSingleStepPath has passed" << std::endl;
	}
	else
	{
		std::cout << "testSingleStepPath has failed" << std::endl;
	}

	if (TestBlockedPath())
	{
		std::cout << "testBlockedPath has passed" << std::endl;
	}
	else
	{
		std::cout << "testBlockedPath has failed" << std::endl;
	}

	if (TestPathFinding())
	{
		std::cout << "testPathFinding has passed" << std::endl;
	}
	else
	{
		std::cout << "testPathFinding has failed" << std::endl;
	}

	return 0;
}

int main()
{
	TestAStarAlgorithm();
	std::cout << "Program finished executing" << std::endl;
	return 0;
}