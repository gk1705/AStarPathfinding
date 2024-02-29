#pragma once

#include <vector>

#include "Coordinate.h"
#include "Grid.h"
#include "Heuristics.h"

class AStarAlgorithm
{
public:
	AStarAlgorithm() = default;
	void createGrid(int width, int height, const std::vector<Coordinate>& obstructions);
	std::vector<Coordinate> findPath(const Coordinate& source, const Coordinate& target, HeuristicMethod heuristicMethod) const;

private:
	Grid grid;
};